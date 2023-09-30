#pragma once
#include <ctype.h>  /* is space */
#include <stdio.h>     /* printf */
#include <stdlib.h>  
#include <time.h>  
#include <functional>
#include <algorithm> 
#include <unordered_map> 
#include <unordered_set> 
#include <map> 
#include <numeric>
#include <stack>
#include <set>
#include <queue> 
#include <vector>
#include <iostream>
#include <fstream>
#include "LeetcodeGraph.h"

#pragma region Graph
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
UndirectedGraphNode * LeetCodeGraph::cloneGraph(UndirectedGraphNode *node)
{
    UndirectedGraphNode* head = nullptr;
    unordered_map<int, UndirectedGraphNode*> graph_map;
    queue<UndirectedGraphNode*> search_queue;
    unordered_set<int> visited_set;
    search_queue.push(node);
    while (!search_queue.empty())
    {
        UndirectedGraphNode* node = search_queue.front();
        search_queue.pop();
        if (node == nullptr) continue;
        UndirectedGraphNode* new_node = nullptr;
        if (visited_set.find(node->label) != visited_set.end())
        {
            continue;
        }
        visited_set.insert(node->label);
        if (graph_map.find(node->label) == graph_map.end())
        {
            new_node = new UndirectedGraphNode(node->label);
            graph_map[node->label] = new_node;
        }
        else
        {
            new_node = graph_map[node->label];
        }
        if (head == nullptr) head = new_node;

        for (UndirectedGraphNode * neighbor : node->neighbors)
        {
            UndirectedGraphNode * new_neighbor;
            if (graph_map.find(neighbor->label) == graph_map.end())
            {
                new_neighbor = new UndirectedGraphNode(neighbor->label);
                graph_map[neighbor->label] = new_neighbor;
            }
            else
            {
                new_neighbor = graph_map[neighbor->label];
            }
            new_node->neighbors.push_back(new_neighbor);
            search_queue.push(neighbor);
        }
    }
    return head;
}

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
bool LeetCodeGraph::canFinishCourse(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> degree(numCourses);
    vector<unordered_set<int>> dependency(numCourses);
    queue<int> search;

    // remember which course dependes on others and which ones depends on me
    for (size_t i = 0; i <  prerequisites.size(); i++)
    {
         degree[prerequisites[i][0]]++;
         dependency[prerequisites[i][1]].insert(prerequisites[i][0]);
    }
    int result = 0;
    // get all the course not depends on others, this is our starting search scope
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0)
        {
            search.push(i);
            result++;
        }
    }

    // Using queue to manage BFS and get every free course and clear the 
    // dependency with a free course, i.e. you depend on a free course, 
    // then such dependency
    // does not matter. If all dependencies are clear, we got a new 
    // free course
    while (!search.empty())
    {
        int free_course = search.front();
        search.pop();
        for (int next_course : dependency[free_course])
        {
            degree[next_course]--;
            if (degree[next_course] == 0)
            {
                search.push(next_course);
                result++;
            }
        }
    }
    // if number of free courses equals to the total course, we can finish 
    // all courses
    return result == numCourses;
}

/// <summary>
/// LeetCode #210. Course Schedule II  
/// 
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
vector<int> LeetCodeGraph::findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<int> degree(numCourses);
    vector<unordered_set<int>> dependency(numCourses);
    queue<int> search;

    // remember which course dependes on others and which ones depends on me
    for (size_t i = 0; i < prerequisites.size(); i++)
    {
        degree[prerequisites[i][0]]++;
        dependency[prerequisites[i][1]].insert(prerequisites[i][0]);
    }
    // get all the course not depends on others, this is our starting search scope
    vector<int> result;
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0)
        {
            search.push(i);
            result.push_back(i);
        }
    }
    while (!search.empty())
    {
        int free_course = search.front();
        search.pop();
        for (int next_course : dependency[free_course])
        {
            degree[next_course]--;
            if (degree[next_course] == 0)
            {
                search.push(next_course);
                result.push_back(next_course);
            }
        }
    }
    if (result.size() == numCourses)
    {
        return result;
    }
    else
    {
        return vector<int>();
    }
}

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
vector<int> LeetCodeGraph::findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
    vector<unordered_set<int>> route_set(n);
    vector<int> result;
    for (size_t i = 0; i < edges.size(); i++)
    {
        route_set[edges[i].first].insert(edges[i].second);
        route_set[edges[i].second].insert(edges[i].first);
    }
    set<int> leaves, new_leaves;
    for (int i = 0; i < n; i++)
    {
        if (route_set[i].size() <= 1) leaves.insert(i);
    }
    while (true)
    {
        n = n - leaves.size();
        if ((n == 0) || leaves.empty()) break;
        for (int leaf : leaves)
        {
            int target = *route_set[leaf].begin();
            route_set[leaf].erase(target);
            route_set[target].erase(leaf);
            if (route_set[target].size() <= 1) new_leaves.insert(target);
        }
        leaves = new_leaves;
        new_leaves.clear();
    }

    for (int leaf : leaves)
    {
        result.push_back(leaf);
    }
    return result;
}

/// <summary>
/// Leet code #332. Reconstruct Itinerary 
/// </summary>
void LeetCodeGraph::findItinerary(vector<string> &path, unordered_map<string, map<string, int>>& tickets,
    unordered_map<string, map<string, int>>& visited, int &count)
{
    if (count == 0) return;
    string city = path.back();
    for (map<string, int>::iterator itr = tickets[city].begin(); itr != tickets[city].end(); itr++)
    {
        // The visited map is to count how many times, the city is visited
        //  which should not go beyond the count from the input
        if (visited[city][itr->first] == itr->second) continue;
        visited[city][itr->first]++;
        path.push_back(itr->first);
        count--;
        findItinerary(path, tickets, visited, count);
        if (count != 0)
        {
            count++;
            visited[city][itr->first]--;
            path.pop_back();
        }
        else
        {
            break;
        }
    }
    return;
}

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
vector<string> LeetCodeGraph::findItinerary(vector<pair<string, string>> tickets)
{
    vector<string> result = { "JFK" };
    unordered_map<string, map<string, int>> route_map, visited;
    int count = 0;
    for (size_t i = 0; i < tickets.size(); i++)
    {
        route_map[tickets[i].first][tickets[i].second]++;
        count++;
    }
    findItinerary(result, route_map, visited, count);
    return result;
}

/// <summary>
/// Leet code #399. Evaluate Division  
/// </summary>
double LeetCodeGraph::calcEquation(pair<string, string> equation,
    unordered_map<string, unordered_map<string, double>>& equations_map)
{
    double result = -1.0;
    queue<string> process_queue;
    string dividend = equation.first;
    string divisor = equation.second;
    for (auto itr : equations_map[equation.first])
    {
        process_queue.push(itr.first);
    }
    while (!process_queue.empty())
    {
        string target = process_queue.front();
        process_queue.pop();
        if (target == divisor)
        {
            return equations_map[dividend][divisor];
        }
        for (auto itr : equations_map[target])
        {
            if (equations_map[dividend].find(itr.first) == equations_map[dividend].end())
            {
                process_queue.push(itr.first);
                equations_map[dividend][itr.first] = equations_map[dividend][target] *
                    equations_map[target][itr.first];
                equations_map[itr.first][dividend] = 1.0 / equations_map[dividend][itr.first];
            }
        }
    }
    return result;
}

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
vector<double> LeetCodeGraph::calcEquation(vector<pair<string, string>> equations, vector<double>& values,
    vector<pair<string, string>> queries)
{
    vector<double> result;
    unordered_map<string, unordered_map<string, double>> equations_map;
    for (size_t i = 0; i < equations.size(); i++)
    {
        equations_map[equations[i].first][equations[i].second] = values[i];
        equations_map[equations[i].second][equations[i].first] = 1 / values[i];
        equations_map[equations[i].first][equations[i].first] = 1;
        equations_map[equations[i].second][equations[i].second] = 1;
    }
    for (auto x : queries)
    {
        result.push_back(calcEquation(x, equations_map));
    }
    return result;
}

/// <summary>
/// Leet Code 323. Number of Connected Components in an Undirected Graph
///                                                                 
/// Medium
///
/// You have a graph of n nodes. You are given an integer n and an array 
/// edges where edges[i] = [ai, bi] indicates that there is an edge 
/// between ai and bi in the graph.
///
/// Return the number of connected components in the graph.
///
/// Example 1: 
/// Input: n = 5, edges = [[0,1],[1,2],[3,4]]
/// Output: 2
///
/// Example 2:
/// Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
/// Output: 1
/// Constraints:
/// 1. 1 <= n <= 2000
/// 2. 1 <= edges.length <= 5000
/// 3. edges[i].length == 2
/// 4. 0 <= ai <= bi < n
/// 5. ai != bi
/// 6. There are no repeated edges.
/// </summary>
int LeetCodeGraph::countComponents(int n, vector<pair<int, int>>& edges)
{
    vector<vector<int>> neighbors(n);
    vector<int> visited(n);
    queue<int> process_queue;
    int count = 0;

    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i].first].push_back(edges[i].second);
        neighbors[edges[i].second].push_back(edges[i].first);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            process_queue.push(i);
            visited[i] = 1;
            while (!process_queue.empty())
            {
                int current = process_queue.front();
                process_queue.pop();
                for (int target : neighbors[current])
                {
                    if (visited[target] == 0)
                    {
                        process_queue.push(target);
                        visited[target] = 1;
                    }
                }
            }
            count++;
        }
    }
    return count;
}

/// <summary>
/// Leet code #277. Find the Celebrity  
/// 
/// Suppose you are at a party with n people (labeled from 0 to n - 1) and 
/// among them, there may exist one celebrity. The definition of a celebrity 
/// is that all the other n - 1 people know him/her but he/she does not know 
/// any of them. 
/// Now you want to find out who the celebrity is or verify that there is 
/// not one. 
/// The only thing you are allowed to do is to ask questions like: 
/// "Hi, A. Do you know B?" 
/// to get information of whether A knows B. You need to find out the 
/// celebrity (or verify there is not one) by asking as few questions as 
/// possible (in the asymptotic sense). 
/// You are given a helper function bool knows(a, b) which tells you whether 
/// A knows B. 
/// Implement a function int findCelebrity(n), your function should minimize 
/// the number of calls to knows. 
/// Note: There will be exactly one celebrity if he/she is in the party. 
/// Return the celebrity's label if there is a celebrity in the party. 
/// If there is no celebrity, return -1. 
/// </summary>
int LeetCodeGraph::findCelebrity(int n, vector<vector<bool>>& relation_map)
{
    int first = 0, last = first + 1;
    int temp = -1;
    // the first pass will catch one person he does not know any one behind him
    while (last < n)
    {
        if (first == last)
        {
            last++;
        }
        else if (relation_map[first][last])
        {
            temp = first;
            first = last;
        }
        else
        {
            last++;
        }
    }
    // the second pass check if anyone in front of him knows him.
    for (int i = 0; i < first; i++)
    {
        if (relation_map[first][i]) return -1;
    }
    // The third pass check if anyone does not know him
    for (int i = 0; i < n; i++)
    {
        if (i == temp) continue;
        if (!relation_map[i][first]) return -1;
    }
    return first;
}

/// <summary>
/// Leet code #286. Walls and Gates 
/// </summary>
void LeetCodeGraph::wallsAndGatesDFS(vector<vector<int>>& rooms, int row, int col, int distance)
{
    if (row < 0 || col < 0 || row >= (int)rooms.size() || col >= (int)rooms[0].size())
    {
        return;
    }
    if (rooms[row][col] <= distance && distance != 0)
    {
        return;
    }
    rooms[row][col] = distance;
    wallsAndGatesDFS(rooms, row - 1, col, distance + 1);
    wallsAndGatesDFS(rooms, row, col - 1, distance + 1);
    wallsAndGatesDFS(rooms, row + 1, col, distance + 1);
    wallsAndGatesDFS(rooms, row, col + 1, distance + 1);
}

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
void LeetCodeGraph::wallsAndGatesDFS(vector<vector<int>>& rooms)
{
    for (size_t i = 0; i < rooms.size(); i++)
    {
        for (size_t j = 0; j < rooms[0].size(); j++)
        {
            if (rooms[i][j] == 0)
            {
                wallsAndGatesDFS(rooms, i, j, 0);
            }
        }
    }
}

/// <summary>
/// Leet Code 286. Walls and Gates
///                                                                 
/// Medium
///
/// You are given an m x n grid rooms initialized with these three 
/// possible values.
///
/// -1 A wall or an obstacle.
/// 0 A gate.
/// INF Infinity means an empty room. We use the value 
/// 2^31 - 1 = 2147483647 to represent INF as you may assume that the 
/// distance to a gate is less than 2147483647.
/// Fill each empty room with the distance to its nearest gate. If it 
/// is impossible to reach a gate, it should be filled with INF.
/// 
/// Example 1:
/// Input: rooms = [[2147483647,-1,0,2147483647],
/// [2147483647,2147483647,2147483647,-1], [2147483647,-1,2147483647,-1], 
/// [0,-1,2147483647,2147483647]]
/// Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
///
/// Example 2:
/// Input: rooms = [[-1]]
/// Output: [[-1]]
/// 
/// Constraints:
/// 1. m == rooms.length
/// 2. n == rooms[i].length
/// 3. 1 <= m, n <= 250
/// 4. rooms[i][j] is -1, 0, or 2^31 - 1.
/// </summary>
void LeetCodeGraph::wallsAndGates(vector<vector<int>>& rooms)
{
    int n = rooms.size();
    int m = rooms[0].size();
    queue<vector<int>> process_queue;
    for (int i = 0; i < (int)rooms.size(); i++)
    {
        for (int j = 0; j < (int)rooms[i].size(); j++)
        {
            if (rooms[i][j] == 0)
            {
                process_queue.push({ i, j });
            }
        }
    }
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!process_queue.empty())
    {
        vector<int> pos = process_queue.front();
        process_queue.pop();

        for (size_t d = 0; d < directions.size(); d++)
        {
            vector<int> next = pos;
            next[0] += directions[d][0];
            next[1] += directions[d][1];
            if (next[0] < 0 || next[0] >= n || next[1] < 0 || next[1] >= m)
            {
                continue;
            }
            if (rooms[next[0]][next[1]] == -1 || rooms[next[0]][next[1]] != INT_MAX)
            {
                continue;
            }
            rooms[next[0]][next[1]] = rooms[pos[0]][pos[1]] + 1;
            process_queue.push(next);
        }
    }
}

/// <summary>
/// Leet code #296. Best Meeting Point       
/// </summary>
int LeetCodeGraph::minTotalDistance(vector<int> & nums)
{
    if (nums.empty()) return 0;
    int i = 0, j = nums.size() - 1;
    // Here the left and right are the sum of people considered as weight, 
    // which has nothing to do with distance.
    int left = nums[i], right = nums[j], sum = 0;
    while (i < j)
    {
        if (left < right)
        {
            sum += left;
            i++;
            left += nums[i];
        }
        else
        {
            sum += right;
            j--;
            right += nums[j];
        }
    }
    return sum;
}

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
/// The point (0,2) is an ideal meeting point, as the total travel distance of 
/// 2+2+2=6 is minimal. So return 6.
///
///        Hint:
/// 1.Try to solve it in one dimension first. How can this solution apply to 
/// the two dimension case?
/// </summary>
int LeetCodeGraph::minTotalDistance(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) return 0;
    vector<int> row(grid.size());
    vector<int> col(grid[0].size());
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    return minTotalDistance(row) + minTotalDistance(col);
}

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
///   1
///  / \
/// 2 - 3
///
/// Example 2:
/// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
/// Output: [1,4]
/// Explanation: The given undirected graph will be like this:
/// 5 - 1 - 2
///     |   |
///     4 - 3
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
vector<int> LeetCodeGraph::findRedundantConnection(vector<vector<int>>& edges)
{
    vector<int> result;
    unordered_map<int, unordered_set<int>> edge_map;
    unordered_set<int> start_set;

    // first build two way mapping
    for (size_t i = 0; i < edges.size(); i++)
    {
        for (size_t j = 0; j < edges[i].size(); j++)
        {
            edge_map[edges[i][j]].insert(edges[i][1 - j]);
        }
    }
    for (auto itr : edge_map)
    {
        if (itr.second.size() == 1)
        {
            start_set.insert(itr.first);
        }
    }
    while (!start_set.empty())
    {
        int source = *start_set.begin();
        start_set.erase(start_set.begin());
        for (int target : edge_map[source])
        {
            edge_map[target].erase(source);
            if (edge_map[target].size() == 1) start_set.insert(target);
        }
        edge_map.erase(source);
    }

    for (int i = edges.size() - 1; i >= 0; i--)
    {
        if (edge_map.count(edges[i][0]) > 0 && edge_map.count(edges[i][1]) > 0)
        {
            result.push_back(edges[i][0]);
            result.push_back(edges[i][1]);
            break;
        }
    }
    return result;
}

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
vector<int> LeetCodeGraph::findRedundantDirectedConnection(vector<vector<int>>& edges)
{
    vector<int> result;
    unordered_map<int, unordered_set<int>> parent;
    unordered_map<int, unordered_set<int>> child;
    unordered_set<int> start_set;

    for (size_t i = 0; i < edges.size(); i++)
    {
        parent[edges[i][1]].insert(edges[i][0]);
        child[edges[i][0]].insert(edges[i][1]);
    }

    // find all leaves 
    for (auto itr : parent)
    {
        // one parent, no child
        if ((itr.second.size() == 1) && (child.count(itr.first) == 0))
        {
            start_set.insert(itr.first);
        }
    }

    // remove all leaves recursively
    while (!start_set.empty())
    {
        int id = *start_set.begin();
        start_set.erase(id);
        for (int parent_id : parent[id])
        {
            // remove current id
            child[parent_id].erase(id);
            if (child[parent_id].empty()) child.erase(parent_id);
            // one parent, no child 
            if ((parent.count(parent_id) == 0 || parent[parent_id].size() == 1) && (child.count(parent_id) == 0))
            {
                start_set.insert(parent_id);
            }
        }
        parent.erase(id);
    }

    // find all roots 
    for (auto itr : child)
    {
        // no parents
        if (parent.count(itr.first) == 0)
        {
            start_set.insert(itr.first);
        }
    }

    // remove all roots
    while (!start_set.empty())
    {
        int id = *start_set.begin();
        start_set.erase(id);
        for (int child_id : child[id])
        {
            // remove current id
            if (parent[child_id].size() == 1) parent[child_id].erase(id);
            else if (child.count(child_id) > 0)
            {
                parent[child_id].erase(id);
                result.push_back(*parent[child_id].begin());
                result.push_back(child_id);
            }
            if (parent[child_id].empty()) parent.erase(child_id);
            // no parent 
            if (parent.count(child_id) == 0)
            {
                start_set.insert(child_id);
            }
        }
        child.erase(id);
    }

    // no answer yet, it is a loop
    if (result.empty())
    {
        for (int i = edges.size() - 1; i >= 0; i--)
        {
            if ((parent.count(edges[i][1]) > 0) && (parent[edges[i][1]].count(edges[i][0]) > 0))
            {
                result.push_back(edges[i][0]);
                result.push_back(edges[i][1]);
                break;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #902. Truck delivery 
/// 
/// There are a number of houses in a line, the distance between two houses
/// are given in an array.
/// for example the distance between house(0) and house(1) is in distance[0] 
/// and the distance between house(n-2) and house(n-1) is given in 
/// distance[n-2]. A delivery truck stops in front of the houses, and the 
/// driver has a number of packages to deliver, each with a weight[i], 
/// if no package for this house it is 0.
/// The truck can only stop in front of one house, the driver should minimize 
/// the total cost of the delivery. 
/// 
/// Note:
/// 1. The cost is defined by multiply the distance the driver should walk 
///     with the weight of package in hand, i.e.
///     It is weight[i] * distance[i]. 
/// 2. If the driver walk back with empty hand the cost is zero. 
/// 3. The driver is only allowed to carry one package at a time.
/// </summary>
int LeetCodeGraph::minDeliveryCost(vector<int> distances, vector<int> weight)
{
    // at very beginning, we assume the truck stops at house0, so the 
    // weight of total packages on left is 0 and the total weight 
    // on right is from 1 to n-1.
    int weight_left = 0, weight_right = 0;
    int distance = 0, sum = 0, min_cost = INT_MAX;
    for (size_t i = 1; i < weight.size(); i++)
    {
        weight_right += weight[i];
        distance += distances[i];
        sum += weight[i] * distance;
    }
    min_cost = sum;
    for (size_t i = 1; i < weight.size(); i++)
    {
        // assume truck is at house i, house[i-1] is moved to left
        weight_left += weight[i - 1];
        // on the right side, the cost to each house deduct the cost of weight * distance[i-1];
        sum -= weight_right * distances[i];
        // on the left side, the cost to each house add (weight * distance[i-1]
        sum += weight_left * distances[i];
        // house[i] is no longer on right, it is in front of track
        weight_right -= weight[i];
        // calculate min_cost
        min_cost = min(sum, min_cost);
    }
    return min_cost;
}

/// <summary>
/// Leet code #317. Shortest Distance from All Buildings        
/// </summary>
bool LeetCodeGraph::addDistance(int row, int col, int building_index, int step, vector<vector<int>>& grid, vector<vector<unordered_map<int, int>>>& distance_map)
{
    if ((row < 0) || (col < 0) || (row >= (int)grid.size()) || (col >= (int)grid[0].size()))
    {
        return false;
    }

    if ((distance_map[row][col].count(building_index) == 0) && (grid[row][col] == 0) && (distance_map[row][col].size() == building_index))
    {
        distance_map[row][col][building_index] = step;
        return true;
    }
    else
    {
        return false;
    }
}

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
int LeetCodeGraph::shortestDistance(vector<vector<int>>& grid)
{
    if ((grid.size() == 0) || (grid[0].size() == 0)) return 0;
    vector<vector<unordered_map<int, int>>> distance_map;
    vector<pair<int, int>> process_list;
    for (size_t i = 0; i < grid.size(); i++)
    {
        distance_map.push_back(vector<unordered_map<int, int>>(grid[i].size(), unordered_map<int, int>()));
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                distance_map[i][j][process_list.size()] = 0;
                process_list.push_back(make_pair(i, j));
            }
        }
    }
    for (size_t i = 0; i < process_list.size(); i++)
    {
        queue<pair<int, int>> process_queue;
        process_queue.push(process_list[i]);
        int step = 0;
        while (!process_queue.empty())
        {
            pair<int, int> pos = process_queue.front();
            process_queue.pop();
            step = distance_map[pos.first][pos.second][i];
            if (addDistance(pos.first - 1, pos.second, i, step + 1, grid, distance_map))
            {
                process_queue.push(make_pair(pos.first - 1, pos.second));
            }

            if (addDistance(pos.first + 1, pos.second, i, step + 1, grid, distance_map))
            {
                process_queue.push(make_pair(pos.first + 1, pos.second));
            }

            if (addDistance(pos.first, pos.second - 1, i, step + 1, grid, distance_map))
            {
                process_queue.push(make_pair(pos.first, pos.second - 1));
            }

            if (addDistance(pos.first, pos.second + 1, i, step + 1, grid, distance_map))
            {
                process_queue.push(make_pair(pos.first, pos.second + 1));
            }
        }
    }

    int min_distance = INT_MAX;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if ((grid[i][j] != 0) || (distance_map[i][j].size() < process_list.size())) continue;
            int sum = 0;
            for (auto itr : distance_map[i][j])
            {
                sum += itr.second;
            }
            min_distance = min(sum, min_distance);
        }
    }
    return min_distance == INT_MAX ? -1 : min_distance;
}

/// <summary>
/// Leet code #261. Graph Valid Tree  
/// 
/// Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
/// (each edge is a pair of nodes), write a function to check whether these 
/// edges make up a valid tree. 
/// For example: 
/// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true. 
/// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], 
/// return false. 
/// Hint:
/// 1.Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your 
///   return? 
///   Is this case a valid tree? 
/// 2.According to the definition of tree on Wikipedia: "a tree is an 
///   undirected graph in which any two vertices are connected by exactly 
///   one path. In other words, any connected graph without simple 
///   cycles is a tree."
/// </summary>
bool LeetCodeGraph::validTree(int n, vector<pair<int, int>>& edges)
{
    unordered_map<int, unordered_set<int>> tree_map;
    queue<int> process_queue;
    for (size_t i = 0; i < edges.size(); i++)
    {
        tree_map[edges[i].first].insert(edges[i].second);
        tree_map[edges[i].second].insert(edges[i].first);
    }
    for (auto itr : tree_map)
    {
        if (itr.second.size() == 1)
        {
            process_queue.push(itr.first);
        }
    }
    int count = 0;
    while (!process_queue.empty())
    {
        int node = process_queue.front();
        process_queue.pop();
        if (tree_map[node].size() == 0) continue;
        int parent = *tree_map[node].begin();
        tree_map[parent].erase(node);
        tree_map.erase(node);
        if (tree_map[parent].size() == 1)
        {
            process_queue.push(parent);
        }
        count++;
    }
    if (count == n - 1) return true;
    else return false;
}

/// <summary>
/// Leet code #269. Alien Dictionary
/// There is a new alien language which uses the latin alphabet. However, the 
/// order among letters are unknown to you. You receive a list of words from 
/// the dictionary, where words are sorted lexicographically by the rules of 
/// this new language. Derive the order of letters in this language. 
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
/// 3.There may be multiple valid order of letters, return any one of them is 
/// fine.
/// </summary>
string LeetCodeGraph::alienOrder(vector<string>& words)
{
    string result;
    vector<unordered_set<int>> next_set(26);
    vector<int> degree(26, -1);
    queue<int> search_queue;

    for (size_t i = 0; i < words.size(); i++)
    {
        for (char ch : words[i])
        {
            if (degree[ch - 'a'] == -1) degree[ch - 'a'] = 0;
        }

        if (i > 0)
        {
            string prev_word = words[i - 1];
            string curr_word = words[i];

            for (size_t i = 0; i < max(prev_word.size(), curr_word.size()); i++)
            {
                if (i == prev_word.size()) break;
                else if (i == curr_word.size()) return "";
                else
                {
                    int prev = prev_word[i] - 'a';
                    int curr = curr_word[i] - 'a';
                    if (prev_word[i] != curr_word[i])
                    {
                        // this is required otherwise degree will be non-zero.
                        if (next_set[prev].count(curr) == 0)
                        {
                            next_set[prev].insert(curr);
                            degree[curr]++;
                        }
                        // when we hit one character difference, no point compare remaing.
                        break;
                    }
                }
            }
        }
    }

    // remove all characters has predecessor
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0)
        {
            search_queue.push(i);
        }
    }

    while (!search_queue.empty())
    {
        int index = search_queue.front();
        search_queue.pop();
        for (char next : next_set[index])
        {
            degree[next]--;
            if (degree[next] == 0)
            {
                search_queue.push(next);
            }
        }
        result.push_back(index + 'a');
    }
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] > 0) return "";
    }
    return result;
}

/// <summary>
/// Leet Code 444. Sequence Reconstruction
///                                                                 
/// Medium
///
/// You are given an integer array nums of length n where nums is a 
/// permutation of the integers in the range [1, n]. You are also 
/// given a 2D integer array sequences where sequences[i] is a 
/// subsequence of nums.
///
/// Check if nums is the shortest possible and the only supersequence. 
/// The shortest supersequence is a sequence with the shortest length 
/// and has all sequences[i] as subsequences. There could be multiple 
/// valid supersequences for the given array sequences.
///
/// For example, for sequences = [[1,2],[1,3]], there are two shortest 
/// supersequences, [1,2,3] and [1,3,2].
/// While for sequences = [[1,2],[1,3],[1,2,3]], the only shortest 
/// supersequence possible is [1,2,3]. [1,2,3,4] is a possible 
/// supersequence but not the shortest.
/// Return true if nums is the only shortest supersequence for 
/// sequences, or false otherwise.
///
/// A subsequence is a sequence that can be derived from another sequence 
/// by deleting some or no elements without changing the order of the 
/// remaining elements.
/// 
/// Example 1:
/// Input: nums = [1,2,3], sequences = [[1,2],[1,3]]
/// Output: false
/// Explanation: There are two possible supersequences: [1,2,3] and 
/// [1,3,2].
/// The sequence [1,2] is a subsequence of both: [1,2,3] and [1,3,2].
/// The sequence [1,3] is a subsequence of both: [1,2,3] and [1,3,2].
/// Since nums is not the only shortest supersequence, we return false.
///
/// Example 2:
/// Input: nums = [1,2,3], sequences = [[1,2]]
/// Output: false
/// Explanation: The shortest possible supersequence is [1,2].
/// The sequence [1,2] is a subsequence of it: [1,2].
/// Since nums is not the shortest supersequence, we return false.
///
/// Example 3:
/// Input: nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
/// Output: true
/// Explanation: The shortest possible supersequence is [1,2,3].
/// The sequence [1,2] is a subsequence of it: [1,2,3].
/// The sequence [1,3] is a subsequence of it: [1,2,3].
/// The sequence [2,3] is a subsequence of it: [1,2,3].
/// Since nums is the only shortest supersequence, we return true.
///
/// Constraints:
/// 1. n == nums.length
/// 2. 1 <= n <= 10^4
/// 3. nums is a permutation of all the integers in the range [1, n].
/// 4. 1 <= sequences.length <= 10^4 
/// 5. 1 <= sequences[i].length <= 10^4
/// 6. 1 <= sum(sequences[i].length) <= 10^5
/// 7. 1 <= sequences[i][j] <= n
/// 8. All the arrays of sequences are unique.
/// 9. sequences[i] is a subsequence of nums.
/// </summary>
bool LeetCodeGraph::sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences)
{
    vector<int> degree(nums.size() + 1);
    vector<vector<int>> dependencies(nums.size() + 1);

    for (size_t i = 0; i < sequences.size(); i++)
    {
        for (int j = sequences[i].size() - 1; j > 0; j--)
        {
            if (sequences[i][j] > (int)nums.size()) return false;
            degree[sequences[i][j]]++;
            dependencies[sequences[i][j - 1]].push_back(sequences[i][j]);
        }
    }
    queue<int> queue;
    vector<int> result;
    for (size_t i = 1; i < degree.size(); i++)
    {
        if (degree[i] == 0) queue.push(i);
    }
    while (!queue.empty())
    {
        if (queue.size() > 1) return false;
        int node = queue.front();
        queue.pop();
        if (node != nums[result.size()]) return false;
        result.push_back(node);
        for (size_t i = 0; i < dependencies[node].size(); i++)
        {
            degree[dependencies[node][i]]--;
            if (degree[dependencies[node][i]] == 0)
            {
                queue.push(dependencies[node][i]);
            }
        }
    } 
    if (result.size() != nums.size()) return false;
    else return true;
}

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
int LeetCodeGraph::minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts)
{
    int distance = 0;
    int distance_gap = INT_MIN;
    for (size_t i = 0; i < nuts.size(); i++)
    {
        distance += 2 * (abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]));
        distance_gap = max(distance_gap,
            abs(nuts[i][0] - tree[0]) + abs(nuts[i][1] - tree[1]) -
            abs(nuts[i][0] - squirrel[0]) - abs(nuts[i][1] - squirrel[1]));
    }
    distance -= distance_gap;
    return distance;
}

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
vector<int> LeetCodeGraph::killProcess(vector<int>& pid, vector<int>& ppid, int kill)
{
    unordered_map<int, set<int>> process_map;
    queue<int> process_queue;
    vector<int> result;
    for (size_t i = 0; i < pid.size(); i++)
    {
        process_map[ppid[i]].insert(pid[i]);
    }

    process_queue.push(kill);
    while (!process_queue.empty())
    {
        int process_id = process_queue.front();
        process_queue.pop();
        result.push_back(process_id);
        for (int p : process_map[process_id])
        {
            process_queue.push(p);
        }
    }
    return result;
}

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
/// N and K are positive integers, which are in the range of [1, 100].
/// In the matrix flights, all the values are integers in the range of [0, 1].
/// In the matrix days, all the values are integers in the range [0, 7].
/// You could stay at a city beyond the number of vacation days, but you should
/// work on the extra days, which won't be counted as vacation days.
/// If you fly from the city A to the city B and take the vacation on that day, 
/// the deduction towards vacation days will count towards the vacation days 
/// of city B in that week.
/// We don't consider the impact of flight hours towards the calculation of 
/// vacation days.
/// </summary>
int LeetCodeGraph::maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days)
{
    if (flights.empty() || flights[0].empty()) return 0;
    vector<int> vacation(flights[0].size());
    unordered_set<int> cities = { 0 };
    int max_vacation = 0;
    for (size_t i = 0; i < days[0].size(); i++)
    {
        unordered_set<int> next_cities;
        vector<int> next_vacation(flights[0].size());
        for (int city : cities)
        {
            for (size_t k = 0; k < flights[city].size(); k++)
            {
                if (flights[city][k] == 1)
                {
                    next_cities.insert(k);
                    next_vacation[k] = max(next_vacation[k], vacation[city] + days[k][i]);
                    max_vacation = max(max_vacation, next_vacation[k]);
                }
            }
            next_cities.insert(city);
            next_vacation[city] = max(next_vacation[city], vacation[city] + days[city][i]);
            max_vacation = max(max_vacation, next_vacation[city]);
        }

        cities = next_cities;
        vacation = next_vacation;
    }
    return max_vacation;
}

/// <summary>
/// Leet code #694. Number of Distinct Islands
/// discover the island by DFS
/// </summary>
void LeetCodeGraph::getDistinctIslands(vector<vector<int>>& grid, vector<vector<int>> &visited, set<pair<int, int>>& island,
    int row, int col, int start_row, int start_col)
{
    // out of boundary
    if ((row < 0) || (row >= (int)grid.size()) || (col < 0) || (col >= (int)grid[row].size()))
    {
        return;
    }
    // this is water 
    if (grid[row][col] == 0) return;

    // this is visited
    if (visited[row][col] == 1) return;

    pair<int, int> position = make_pair(row - start_row, col - start_col);

    island.insert(position);
    visited[row][col] = 1;

    getDistinctIslands(grid, visited, island, row - 1, col, start_row, start_col);
    getDistinctIslands(grid, visited, island, row + 1, col, start_row, start_col);
    getDistinctIslands(grid, visited, island, row, col - 1, start_row, start_col);
    getDistinctIslands(grid, visited, island, row, col + 1, start_row, start_col);
}

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
int LeetCodeGraph::numDistinctIslands(vector<vector<int>>& grid)
{
    set<set<pair<int, int>>> distinct_islands;
    // empty grid?
    if (grid.empty() || grid[0].empty()) return 0;

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if ((grid[i][j] == 1) && (visited[i][j] == 0))
            {
                set<pair<int, int>> island;
                // we need to deduct the offset for the island, because we are
                // scaning from top to down, from left to right, we can assume
                // first point is the proper offset
                getDistinctIslands(grid, visited, island, i, j, i, j);
                distinct_islands.insert(island);
            }
        }
    }
    return distinct_islands.size();
}

/// <summary>
/// Leet code #711. Number of Distinct Islands II
/// Get reflect island;
/// </summary>
void LeetCodeGraph::getReflectIslands(set<pair<int, int>>& island, set<pair<int, int>>& new_island)
{
    new_island.clear();
    for (pair<int, int> point : island)
    {
        new_island.insert(make_pair(point.second, point.first));
    }
}

/// <summary>
/// Leet code #711. Number of Distinct Islands II
/// Get reflect island;
/// </summary>
void LeetCodeGraph::adjustIslands(set<pair<int, int>>& island, set<pair<int, int>>& new_island)
{
    new_island.clear();
    int mx = INT_MAX, my = INT_MAX;
    for (auto point : island)
    {
        mx = min(point.first, mx);
        my = min(point.second, my);
    }
    for (auto point : island)
    {
        new_island.insert(make_pair(point.first - mx, point.second - my));
    }
}

/// <summary>
/// Leet code #711. Number of Distinct Islands II
/// Get rotated island;
/// </summary>
bool LeetCodeGraph::getRotateIslands(set<pair<int, int>>& island, set<set<pair<int, int>>> &result)
{
    // 4 rotation choice
    vector<pair<int, int>> rotation = { { 1, 1 },{ -1, 1 },{ 1, -1 },{ -1, -1 } };
    for (size_t i = 0; i < rotation.size(); i++)
    {
        set<pair<int, int>> new_island, adjust_island;

        int mx = INT_MAX, my = INT_MAX;
        for (auto point : island)
        {
            int x = point.first * rotation[i].first;
            int y = point.second * rotation[i].second;
            new_island.insert(make_pair(x, y));
        }
        adjustIslands(new_island, adjust_island);
        if (result.count(adjust_island) > 0) return true;
    }
    return false;
}

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
int LeetCodeGraph::numDistinctIslands2(vector<vector<int>>& grid)
{
    set<set<pair<int, int>>> distinct_islands;
    // empty grid?
    if (grid.empty() || grid[0].empty()) return 0;

    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if ((grid[i][j] == 1) && (visited[i][j] == 0))
            {
                set<pair<int, int>> island;
                // we need to deduct the offset for the island, because we are
                // scaning from top to down, from left to right, we can assume
                // first point is the proper offset
                getDistinctIslands(grid, visited, island, i, j, i, j);
                // if duplicate island, skip it
                if (getRotateIslands(island, distinct_islands)) continue;
                set<pair<int, int>> new_island;
                getReflectIslands(island, new_island);
                // if duplicate island, skip it
                if (getRotateIslands(new_island, distinct_islands)) continue;
                adjustIslands(island, new_island);
                distinct_islands.insert(new_island);
            }
        }
    }
    return distinct_islands.size();
}

/// <summary>
/// Leet code #749. Contain Virus
/// </summary>
int LeetCodeGraph::searchVirus(vector<vector<int>>& grid, vector<vector<int>>& visited,
    set<pair<int, int>>&to_infected, int row, int col)
{
    vector<vector<int>> directions = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    int wall = 0;
    queue<pair<int, int>> search_queue;
    search_queue.push(make_pair(row, col));
    visited[row][col] = 1;
    while (!search_queue.empty())
    {
        pair<int, int> position = search_queue.front();
        search_queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            pair<int, int> next = make_pair(position.first + directions[i][0], position.second + directions[i][1]);
            // invalid position
            if ((next.first < 0) || (next.second < 0) || (next.first >= (int)grid.size()) || (next.second >= (int)grid[0].size()))
            {
                continue;
            }
            if (visited[next.first][next.second] == 1) continue;
            if (grid[next.first][next.second] == 1)
            {
                visited[next.first][next.second] = 1;
                search_queue.push(next);
            }
            else if (grid[next.first][next.second] == 0)
            {
                wall++;
                to_infected.insert(next);
            }
        }
    }
    return wall;
}

/// <summary>
/// Leet code #749. Contain Virus
/// </summary>
void LeetCodeGraph::spreadVirus(vector<vector<int>>& grid, vector<set<pair<int, int>>>& to_infect_cells, size_t exception)
{
    for (size_t i = 0; i < to_infect_cells.size(); i++)
    {
        if (i == exception) continue;
        for (auto cell : to_infect_cells[i])
        {
            grid[cell.first][cell.second] = 1;
        }
    }
}

/// <summary>
/// Leet code #749. Contain Virus
/// </summary>
void LeetCodeGraph::buildWall(vector<vector<int>>& grid, int row, int col)
{
    vector<vector<int>> directions = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    int wall = 0;
    queue<pair<int, int>> search_queue;
    search_queue.push(make_pair(row, col));
    grid[row][col] = -1;
    while (!search_queue.empty())
    {
        pair<int, int> position = search_queue.front();
        search_queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            pair<int, int> next = make_pair(position.first + directions[i][0], position.second + directions[i][1]);
            // invalid position
            if ((next.first < 0) || (next.second < 0) || (next.first >= (int)grid.size()) || (next.second >= (int)grid[0].size()))
            {
                continue;
            }
            if (grid[next.first][next.second] == 1)
            {
                search_queue.push(next);
                grid[next.first][next.second] = -1;
            }
        }
    }
}

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
int LeetCodeGraph::containVirus(vector<vector<int>>& grid)
{
    int result = 0;
    while (true)
    {
        int max_index = 0, max_cells = 0, max_walls = 0;
        pair<int, int> max_pos;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        vector<set<pair<int, int>>> to_infect_group;

        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[i].size(); j++)
            {
                if ((grid[i][j] == 1) && (visited[i][j] == 0))
                {
                    set<pair<int, int>> to_infect;
                    int walls = searchVirus(grid, visited, to_infect, i, j);
                    if (to_infect.size() >= (size_t)max_cells)
                    {
                        max_cells = to_infect.size();
                        max_index = to_infect_group.size();
                        max_walls = walls;
                        max_pos.first = i;
                        max_pos.second = j;
                    }
                    to_infect_group.push_back(to_infect);
                }
            }
        }
        if (max_cells == 0) break;
        result += max_walls;
        buildWall(grid, max_pos.first, max_pos.second);
        spreadVirus(grid, to_infect_group, max_index);
    }
    return result;
}

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
int LeetCodeGraph::minSwapsCouples(vector<int>& row)
{
    int result = 0;
    unordered_map<int, set<int>> bench_map;
    map<int, int> person_map;
    for (size_t i = 0; i < row.size(); i += 2)
    {
        // already sit together
        if (row[i] / 2 == row[i + 1] / 2) continue;
        else
        {
            // remember in each bench who is sitting 
            bench_map[i / 2].insert(row[i]);
            bench_map[i / 2].insert(row[i + 1]);
            // remeber where every one is sitting
            person_map[row[i]] = i / 2;
            person_map[row[i + 1]] = i / 2;
        }
    }
    while (!person_map.empty())
    {
        int husband = person_map.begin()->first;
        int husband_bench = person_map.begin()->second;
        int wife = husband + 1;
        int wife_bench = person_map[wife];

        if (husband_bench != wife_bench)
        {
            for (auto person : bench_map[husband_bench])
            {
                if (person != husband)
                {
                    bench_map[wife_bench].erase(wife);
                    bench_map[wife_bench].insert(person);
                    person_map[person] = wife_bench;
                }
            }
            result++;
        }
        bench_map.erase(husband_bench);
        person_map.erase(husband);
        person_map.erase(wife);
    }
    return result;
}

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
vector<int> LeetCodeGraph::eventualSafeNodes(vector<vector<int>>& graph)
{
    unordered_map<int, unordered_set<int>> next_map;
    unordered_map<int, unordered_set<int>> prev_map;

    vector<int> result;
    queue<int> search;
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            next_map[i].insert(graph[i][j]);
            prev_map[graph[i][j]].insert(i);
        }
        if (graph[i].empty()) search.push(i);
    }

    while (!search.empty())
    {
        int front = search.front();
        search.pop();
        result.push_back(front);
        for (int prev : prev_map[front])
        {
            next_map[prev].erase(front);
            if (next_map[prev].empty()) search.push(prev);
        }
        prev_map.erase(front);
    }
    sort(result.begin(), result.end());

    return result;
}

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
int LeetCodeGraph::numBusesToDestination(vector<vector<int>>& routes, int S, int T)
{
    unordered_map<int, set<int>> stop_map;
    unordered_set<int> visited;

    for (size_t i = 0; i < routes.size(); i++)
    {
        for (size_t j = 0; j < routes[i].size(); j++)
        {
            stop_map[routes[i][j]].insert(i);
        }
    }
    queue<int> stop_queue;
    stop_queue.push(S);
    visited.insert(S);
    int result = 0;
    while (!stop_queue.empty())
    {
        size_t size = stop_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            int stop = stop_queue.front();
            stop_queue.pop();
            if (stop == T) return result;

            for (int bus : stop_map[stop])
            {
                for (int next : routes[bus])
                {
                    if (visited.count(next) > 0) 
                    {
                        continue;
                    }
                    stop_queue.push(next);
                    visited.insert(next);
                    stop_map[next].erase(bus);
                }
            }
            stop_map[stop].clear();
        }
        result++;
    }
    return -1;
}

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
bool LeetCodeGraph::canVisitAllRooms(vector<vector<int>>& rooms)
{
    int result = 0;
    vector<int> visited(rooms.size());
    queue<int> search;
    search.push(0);
    visited[0] = 1;
    while (!search.empty())
    {
        int room = search.front();
        search.pop();
        result++;
        for (size_t i = 0; i < rooms[room].size(); i++)
        {
            int v = rooms[room][i];
            if (visited[v] == 1) continue;
            search.push(v);
            visited[v] = 1;
        }
    }
    return (result == rooms.size());
}

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
int LeetCodeGraph::shortestPathLength(vector<vector<int>>& graph)
{
    size_t size = graph.size();
    vector<vector<int>> dp(1 << size, vector<int>(size, -1));
    queue<pair<int, int>> search;
    // we start from each node
    for (size_t i = 0; i < size; i++)
    {
        int cover = 1 << i;
        dp[cover][i] = 0;
        // make the current node as last node
        search.push(make_pair(cover, i));
    }
    while (!search.empty())
    {
        pair<int, int> route = search.front();
        search.pop();
        // we check from current last node what are next nodes to travel
        for (size_t i = 0; i < graph[route.second].size(); i++)
        {
            int next = graph[route.second][i];
            // Normally we need to check if we have already visited the 
            // next node, however the distance check will save us this  
            // effort, if the node is already visited, visit again will  
            // give us no chance to shorten the path
            int cover = route.first | (1 << next);
            if (dp[cover][next] == -1 || 
                dp[cover][next] > dp[route.first][route.second] + 1)
            {
                dp[cover][next] = dp[route.first][route.second] + 1;
                search.push(make_pair(cover, next));
            }
        }
    }

    int full = (1 << size) - 1;
    int result = dp[full][0];
    // starting from every node, look for shortest path
    for (size_t i = 1; i < size; i++)
    {
        result = min(result, dp[full][i]);
    }
    return result;
}

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
vector<int> LeetCodeGraph::loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
{
    vector<int> result(quiet.size());
    for (size_t i = 0; i < result.size(); i++) result[i] = i;
    vector<unordered_set<int>> relation_map(quiet.size());
    vector<int> count_map(quiet.size());

    for (size_t i = 0; i < richer.size(); i++)
    {
        relation_map[richer[i][0]].insert(richer[i][1]);
        count_map[richer[i][1]]++;
    }

    queue<int> search;
    for (size_t i = 0; i < count_map.size(); i++)
    {
        if (count_map[i] == 0) search.push(i);
    }
    while (!search.empty())
    {
        int person = search.front();
        search.pop();
        if (quiet[person] < quiet[result[person]])
        {
            result[person] = person;
        }
        for (auto next : relation_map[person])
        {
            if (quiet[result[person]] < quiet[result[next]])
            {
                result[next] = result[person];
            }
            count_map[next]--;
            if (count_map[next] == 0) search.push(next);
        }
    }
    return result;
}

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
int LeetCodeGraph::minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
{
    priority_queue<int> fuel_heap;
    size_t index = 0;
    int result = 0;
    long long sum = startFuel;
    while (sum < target)
    {
        if (index < stations.size() && sum >= (long long)stations[index][0])
        {
            // add a new station with fuel.
            fuel_heap.push(stations[index][1]);
            index++;
        }
        else
        {
            if (fuel_heap.empty()) return -1;
            sum += fuel_heap.top();
            fuel_heap.pop();
            result++;
        }
    }
    return result;
}

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
int LeetCodeGraph::catMouseGame(vector<vector<int>>& graph)
{
    int N = graph.size();
    vector<vector<vector<int>>> color(N, vector<vector<int>>(N, vector<int>(2)));
    vector<vector<vector<int>>> degree(N, vector<vector<int>>(N, vector<int>(2)));
    enum COLOR { DRAW = 0, MOUSE = 1, CAT = 2 };

    // For every mouse and cat locations, it is N^2
    for (int m = 0; m < N; ++m)
    {
        for (int c = 1; c < N; ++c) 
        {
            // initialize all possible path count for mouse
            degree[m][c][0] = graph[m].size();
            // initialize all possible path count for cat
            degree[m][c][1] = graph[c].size();
            for (int x : graph[c])
            {
                // because CAT can not go to hole, deduct path to zero
                if (x == 0)
                {
                    degree[m][c][1]--;
                    break;
                }
            }
        }
    }

    // Initialize all the scenarios where mouse will win or cat will win
    queue<vector<int>> search;
    for (int i = 1; i < N; ++i)
    {
        // for all the move
        for (int t = 0; t < 2; ++t)
        {
            // mark mouse win
            color[0][i][t] = MOUSE;
            search.push({ 0, i, t });
            cout << 0 << i << t << MOUSE << endl;
            // mark CAT win
            if (i > 0) 
            {
                color[i][i][t] = CAT;
                search.push({i, i, t});
                cout << i << i << t << CAT << endl;
            }
        }
    }

    // This is a BFS search, we initialize some sure win state for one party 
    // in the queue, and reversly search more sure win state and mark them.
    // After the search complete, we may have some undetermined state, this 
    // means DRAW state.
    while (!search.empty()) 
    {
        vector<int> node = search.front();
        search.pop();		
        // for nodes that are colored :
        int m = node[0], c = node[1], t = node[2];
        int state = color[m][c][t];
        // The children contains all the possible path coming to current state.
        vector<vector<int>> children;
        // mouse step, iterate all possible cat paths coming here
        if (t == 0)
        {
            for (int c1 : graph[c])
            {
                if (c1 > 0)
                {
                    children.push_back({ m, c1,  1 - t });
                }
            }
        }
        // cat step, iterate all possible cat paths coming here
        else
        {
            for (int m1 : graph[m])
            {
                children.push_back({ m1, c, 1 - t });
            }
        }

        for (auto child : children)
        {
            int m = child[0], c = child[1], t = child[2];
            // by default it is all DRAW state.
            // when it is not decide, it is also DRAW state
            // so this is to resolve everything not resolved yet
            // remeber we only add a sure win state to the BFS search queue
            if (color[m][c][t] == DRAW)
            {
                // This means current move is me and next state is my
                //  win, Then current state is my win, for example if
                // state == 1, which is mouse win and previous move t = 0 
                // which is mouse move, mouse will definitely choose this path
                // same applies when state == 2 and t = 1 when it is cat's turn.
                if (state == t + 1)
                {
                    color[m][c][t] = state;
                    search.push({ m, c, t });
                }
                // Otherwise if current winning state and previous move are 
                // different, which is to say the rival should avoid this path,
                // This means it should cut this path from choice, but if
                // all the paths are dead, then means the previous state is a
                // dead state for the rival, we can mark it.
                // But iff there are remaing paths, leave it for DRAW.
                else 
                {
                    degree[m][c][t]--;
                    if (degree[m][c][t] == 0) 
                    {
                        color[m][c][t] = state;
                        search.push({ m, c, t });
                    }
                }
            }
        }
    }

    return color[1][2][0];
}

/// <summary>
/// Leet code #943. Find the Shortest Superstring
/// </summary>
string LeetCodeGraph::calculateOverlapString(string& string1, string& string2)
{
    int prefix = min(string1.size(), string2.size());
    string result = string1 + string2;
    while (prefix > 0)
    {
        if (string1.substr(string1.size() - prefix) == string2.substr(0, prefix))
        {
            result = string1 + string2.substr(prefix);
            break;
        }
        else if (string2.substr(string2.size() - prefix) == string1.substr(0, prefix))
        {
            result = string2 + string1.substr(prefix);
            break;
        }
        prefix--;
    }
    return result;
}

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
string LeetCodeGraph::shortestSuperstring(vector<string>& A)
{
    vector<string> dp(1 << A.size());
    int bit_full = (1 << A.size()) - 1;
    queue<int> search;
    search.push(0);
    while (!search.empty())
    {
        int bit = search.front();
        search.pop();
        for (size_t i = 0; i < A.size(); i++)
        {
            int bit_set = 1 << i;
            if ((bit & bit_set) == 0)
            {
                bit_set = bit | bit_set;
                if (dp[bit_set].empty()) search.push(bit_set);
                string cand = calculateOverlapString(dp[bit], A[i]);				
                if (dp[bit_set].empty() || dp[bit_set].size() > cand.size())
                {
                    dp[bit_set] = cand;
                }
            }
        }
    }
    return dp[bit_full];
}

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
int LeetCodeGraph::regionsBySlashes(vector<string>& grid)
{
    vector<vector<int>> matrix(grid.size() * 3, vector<int>(grid.size() * 3));
    int result = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == '/')
            {
                matrix[i * 3][j * 3 + 2] = 1;
                matrix[i * 3 + 1][j * 3 + 1] = 1;
                matrix[i * 3 + 2][j * 3] = 1;
            }
            else if (grid[i][j] == '\\')
            {
                matrix[i * 3][j * 3] = 1;
                matrix[i * 3 + 1][j * 3 + 1] = 1;
                matrix[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }

    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 1) continue;
            queue<pair<int, int>> search;
            matrix[i][j] = 1;
            search.push({ i, j });
            vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
            while (!search.empty())
            {
                pair<int, int> pos = search.front();
                search.pop();
                for (size_t k = 0; k < 4; k++)
                {
                    pair<int, int> next = pos;
                    next.first += directions[k][0];
                    next.second += directions[k][1];
                    if (next.first < 0 || next.first >= (int)matrix.size() ||
                        next.second < 0 || next.second >= (int)matrix.size())
                    {
                        continue;
                    }
                    if (matrix[next.first][next.second] == 1) continue;
                    matrix[next.first][next.second] = 1;
                    search.push(next);
                }
            }
            result++;
        }
    }
    return result;
}

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
vector<int> LeetCodeGraph::assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes)
{
    vector<int> bike_visited(bikes.size());
    map<int, map<int, set<int>>> distance_map;
    vector<int> result(workers.size(), -1);
    for (size_t i = 0; i < workers.size(); i++)
    {
        for (size_t j = 0; j < bikes.size(); j++)
        {
            int distance = std::abs(workers[i][0] - bikes[j][0]) + 
                std::abs(workers[i][1] - bikes[j][1]);
            distance_map[distance][i].insert(j);
        }
    }
    while (!distance_map.empty())
    {
        auto itr = distance_map.begin()->second.begin();
        int worker = itr->first;
        int bike = *itr->second.begin();
        itr->second.erase(itr->second.begin());
        if (itr->second.empty()) distance_map.begin()->second.erase(itr);
        if (distance_map.begin()->second.empty())
        {
            distance_map.erase(distance_map.begin());
        }
        if (result[worker] != -1 || bike_visited[bike] == 1) continue;
        result[worker] = bike;
        bike_visited[bike] = 1;
    }
    return result;
}

/// <summary>
/// Leet code 1059. All Paths from Source Lead to Destination
/// </summary>
bool LeetCodeGraph::leadsToDestination(vector<vector<int>>& edges, vector<int> &visited, 
                                  int source, int destination)
{
    if (source == destination)
    {
        if (edges[destination].empty()) return true;
        else return false;
    }
    else if (edges[source].empty())
    {
        return false;
    }
    else
    {
        for (auto next : edges[source])
        {
            if (visited[next] == 1) return false;
            visited[next] = 1;
            if (leadsToDestination(edges, visited, next, destination) == false) return false;
            visited[next] = 0;
        }
        edges[source].clear();
        edges[source].push_back(destination);
        return true;
    }
}

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
bool LeetCodeGraph::leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination)
{
    vector<vector<int>> new_edges(n, vector<int>());
    vector<int> visited(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        new_edges[edges[i][0]].push_back(edges[i][1]);
    }
    return leadsToDestination(new_edges, visited, source, destination);
}

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
int LeetCodeGraph::maximumMinimumPath(vector<vector<int>>& A)
{
    priority_queue<vector<int>> pq;
    pq.push({ A[0][0], 0, 0 });
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int R = A.size();
    int C = A[0].size();
    vector<vector<int>> result(R, vector<int>(C, -1));
    while (!pq.empty())
    {
        vector<int> pos = pq.top();
        pq.pop();
        
        if (pos[1] == R - 1 && pos[2] == C - 1)
        {
            return pos[0];
        }
        for (size_t i = 0; i < directions.size(); i++)
        {
            int r = pos[1];
            int c = pos[2];
            r += directions[i][0];
            c += directions[i][1];
            if (r < 0 || r >= R || c < 0 || c >= C)
            {
                continue;
            }
            int v = min(A[r][c], pos[0]);
            if (v > result[r][c])
            {
                result[r][c] = v;
                pq.push({ v, r, c });
            }
        }
    }
    return -1;
}

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
int LeetCodeGraph::minimumCost(int N, vector<vector<int>>& connections)
{
    priority_queue<vector<int>> paths;
    vector<int> parent(N + 1);
    int result = 0;
    for (size_t i = 0; i < connections.size(); i++)
    {
        int x = connections[i][0] - 1;
        int y = connections[i][1] - 1;
        int d = connections[i][2];
        paths.push({ -d, x, y });
    }
    int n = N;
    while (!paths.empty())
    {
        vector<int> pos = paths.top();
        paths.pop();

        int x = pos[1];
        int y = pos[2];
        while (parent[x] != 0) x = parent[x];
        while (parent[y] != 0) y = parent[y];
        if (x != y)
        {
            result += -pos[0];
            parent[x] = y;
            n--;
        }
    }
    if (n == 1) return result;
    else return -1;
}

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
int LeetCodeGraph::minimumSemesters(int N, vector<vector<int>>& relations)
{
    vector<int> degree(N);
    vector<vector<int>> dependency(N);

    for (size_t i = 0; i < relations.size(); i++)
    {
        int x = relations[i][0] - 1;
        int y = relations[i][1] - 1;
        degree[y]++;
        dependency[x].push_back(y);
    }

    queue<int> search;
    int result = 0;
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0) search.push(i);
    }
    int count = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            int course = search.front();
            search.pop();
            count++;
            for (size_t j = 0; j < dependency[course].size(); j++)
            {
                int next = dependency[course][j];
                degree[next]--;
                if (degree[next] == 0) search.push(next);
            }
        }
        result++;
    }
    if (count == N) return result;
    else return -1;
}

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
///
/// Constraints:
/// 1. 1 <= n <= 100
/// 2. red_edges.length <= 400
/// 3. blue_edges.length <= 400
/// 4. red_edges[i].length == blue_edges[i].length == 2
/// 5. 0 <= red_edges[i][j], blue_edges[i][j] < n
/// </summary>
vector<int> LeetCodeGraph::shortestAlternatingPaths(int n, vector<vector<int>>& red_edges,
    vector<vector<int>>& blue_edges)
{
    vector<int> result(n, -1);
    vector<int> visited(n);
    vector<vector<int>> edges(n, vector<int>(n));
    for (size_t i = 0; i < red_edges.size(); i++)
    {
        edges[red_edges[i][0]][red_edges[i][1]] |= 1;
    }
    for (size_t i = 0; i < blue_edges.size(); i++)
    {
        edges[blue_edges[i][0]][blue_edges[i][1]] |= 2;
    }

    queue<pair<int, int>> search;
    visited[0] = 3;
    result[0] = 0;
    search.push({ 0, 3 });
    int step = 0;
    while (!search.empty())
    {
        step++;
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> source = search.front();
            search.pop();

            for (int i = 1; i < n; i++)
            {
                int color = ((source.second >> 1) & (edges[source.first][i] & 1)) |
                    ((source.second << 1) & (edges[source.first][i] & 2));
                if (color == 0) continue;
                if ((color | visited[i]) != visited[i])
                {
                    visited[i] |= color;
                    search.push(make_pair(i, color));
                    if (result[i] == -1) result[i] = step;
                }
            }
        }
    }
    return result;
}

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
bool LeetCodeGraph::canConvert(string str1, string str2)
{
    if (str1 == str2) return true;
    vector<int> match1(26, -1), match2(26, -1);
    for (size_t i = 0; i < str1.size(); i++)
    {
        int d1 = str1[i] - 'a';
        int d2 = str2[i] - 'a';
        if (match1[d1] == -1) match1[d1] = d2;
        else if (match1[d1] != d2) return false;
        match2[d2] = d1;
    }
    for (size_t i = 0; i < 26; i++)
    {
        if (match2[i] == -1) return true;
    }
    return false;
}

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
int LeetCodeGraph::minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes)
{
    vector<vector<pair<int, int>>> house_pipe(n);
    priority_queue<pair<int, int>> heap;
    vector<int> cost(n, INT_MAX);
    for (size_t i = 0; i < wells.size(); i++)
    {
        heap.push(make_pair(-wells[i], i));
    }
    for (size_t i = 0; i < pipes.size(); i++)
    {
        house_pipe[pipes[i][0] - 1].push_back(make_pair(pipes[i][1] - 1, pipes[i][2]));
        house_pipe[pipes[i][1] - 1].push_back(make_pair(pipes[i][0] - 1, pipes[i][2]));
    }
    while (!heap.empty())
    {
        pair<int, int> well = heap.top();
        heap.pop();
        int village = well.second;
        if (cost[village] == INT_MAX)
        {
            cost[village] = -well.first;
            for (size_t i = 0; i < house_pipe[village].size(); i++)
            {
                pair<int, int> pipe = house_pipe[village][i];
                if (pipe.second < wells[pipe.first] && 
                    cost[pipe.first] == INT_MAX)
                {
                    wells[pipe.first] = pipe.second;
                    heap.push(make_pair(-pipe.second, pipe.first));
                }
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < cost.size(); i++)
    {
        result += cost[i];
    }
    return result;
}

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
int LeetCodeGraph::swimInWater(vector<vector<int>>& grid)
{
    vector<vector<int>> direction = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    vector<vector<int>> time(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    priority_queue<vector<int>> search;

    // vector[0] = time, vector[1] = row, vector[2] = col
    vector<int> start = { -grid[0][0], 0, 0 };
    time[0][0] = grid[0][0];
    search.push(start);
    while (!search.empty())
    {
        vector<int> current = search.top();
        current[0] = 0 - current[0];
        search.pop();
        // we already visit this node
        if (current[0] > time[current[1]][current[2]]) continue;

        for (size_t i = 0; i < direction.size(); i++)
        {
            vector<int> next = current;
            next[1] += direction[i][0];
            next[2] += direction[i][1];
            // out of boundary
            if ((next[1] < 0) || (next[1] == grid.size()) ||
                (next[2] < 0) || (next[2] == grid[0].size()))
            {
                continue;
            }
            next[0] = max(current[0], grid[next[1]][next[2]]);
            if (next[0] < time[next[1]][next[2]])
            {
                time[next[1]][next[2]] = next[0];
                next[0] = 0 - next[0];
                search.push(next);
            }
        }
    }
    if (time[grid.size() - 1][grid[0].size() - 1] == INT_MAX)
    {
        return -1;
    }
    else
    {
        return time[grid.size() - 1][grid[0].size() - 1];
    }
}

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
bool LeetCodeGraph::possibleBipartition(int N, vector<vector<int>>& dislikes)
{
    vector<int> group(N + 1, -1);
    vector<vector<int>> dislike_list(N + 1);

    for (size_t i = 0; i < dislikes.size(); i++)
    {
        int a = dislikes[i][0];
        int b = dislikes[i][1];
        dislike_list[a].push_back(b);
        dislike_list[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        if (group[i] != -1) continue;
        queue<int> search;
        group[i] = 0;
        search.push(i);
        while (!search.empty())
        {
            int person = search.front();
            search.pop();
            for (auto dislike : dislike_list[person])
            {
                if (group[dislike] == group[person]) return false;
                else if (group[dislike] == -1)
                {
                    group[dislike] = 1 - group[person];
                    search.push(dislike);
                }
            }
        }
    }
    return true;
}

/// <summary>
/// Leet code #1192. Critical Connections in a Network
/// </summary>
int LeetCodeGraph::criticalConnections(int prev, int curr, int& rank, unordered_map<int, unordered_map<int, int>>& graph, vector<int>& dp)
{
    int result = dp[curr];
    for (auto itr : graph[curr])
    {
        int child_rank;
        if (itr.first == prev) continue;
        // not visited
        if (dp[itr.first] == 0)
        {
            rank++;
            dp[itr.first] = rank;
            child_rank = criticalConnections(curr, itr.first, rank, graph, dp);
            // if it is in loop mark the path non-critical
            if (child_rank < dp[itr.first])
            {
                graph[curr][itr.first] = 1;
                graph[itr.first][curr] = 1;
            }
        }
        else
        {
            child_rank = dp[itr.first];
            graph[curr][itr.first] = 1;
            graph[itr.first][curr] = 1;
        }
        result = min(result, child_rank);
    }
    return result;
}


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
vector<vector<int>> LeetCodeGraph::criticalConnections(int n, vector<vector<int>>& connections)
{
    vector<vector<int>> result;
    unordered_map<int, unordered_map<int, int>> graph;
    vector<int> dp(n);
    for (size_t i = 0; i < connections.size(); i++)
    {
        graph[connections[i][0]][connections[i][1]] = 0;
        graph[connections[i][1]][connections[i][0]] = 0;
    }
    int rank = 1;
    dp[0] = 1;
    criticalConnections(-1, 0, rank, graph, dp);
    
    for (auto itr : graph)
    {
        for (auto path : itr.second)
        {
            if ((path.second == 0) && (itr.first < path.first))
            {
                result.push_back({ itr.first, path.first });
            }

        }
    }
    return result;
}

/// <summary>
/// Helper function which generate an undirected graph node
/// </summary>
UndirectedGraphNode* LeetCodeGraph::generateGraphNode(vector<pair<int, vector<int>>>& graph_list)
{
    unordered_map<int, UndirectedGraphNode*> graph_map;
    for (size_t i = 0; i < graph_list.size(); i++)
    {
        pair<int, vector<int>>& pair = graph_list[i];
        vector<int>& neighbors = pair.second;
        UndirectedGraphNode* node;
        if (graph_map.find(pair.first) == graph_map.end())
        {
            node = new UndirectedGraphNode(pair.first);
            graph_map[pair.first] = node;
        }
        else
        {
            node = graph_map[pair.first];
        }
        UndirectedGraphNode* neighbor_node;
        for (int neighbor_id : neighbors)
        {
            if (graph_map.find(neighbor_id) == graph_map.end())
            {
                neighbor_node = new UndirectedGraphNode(neighbor_id);
                graph_map[neighbor_id] = neighbor_node;
            }
            else
            {
                neighbor_node = graph_map[neighbor_id];
            }
            node->neighbors.push_back(neighbor_node);
        }
    }
    if (graph_map.size() == 0)
    {
        return nullptr;
    }
    else
    {
        return graph_map.begin()->second;
    }
}

/// <summary>
/// Free graph nodes
/// </summary>
void LeetCodeGraph::freeGraphNodes(UndirectedGraphNode* root)
{
    unordered_set<UndirectedGraphNode*> node_set;
    queue<UndirectedGraphNode*> search_queue;
    search_queue.push(root);

    while (!search_queue.empty())
    {
        UndirectedGraphNode* node = search_queue.front();
        search_queue.pop();
        if (node == nullptr) continue;
        if (node_set.find(node) != node_set.end()) continue;
        node_set.insert(node);
        for (UndirectedGraphNode* neighbor : node->neighbors)
        {
            search_queue.push(neighbor);
        }
    }

    for (UndirectedGraphNode* node : node_set)
    {
        delete node;
    }
}


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
vector<int> LeetCodeGraph::sortItems(int n, int m, vector<int>& group, 
    vector<vector<int>>& beforeItems)
{
    int index = m;
    vector<int> item_group = group;
    vector<vector<int>> group_items(2 * n);
    vector<int> group_free(2 * n);
    vector<int> visited(n);
    for (size_t i = 0; i < group.size(); i++)
    {
        if (group[i] == -1)
        {
            item_group[i] = index;
            group_items[index].push_back(i);
            index++;
        }
        else
        {
            item_group[i] = group[i];
            group_items[group[i]].push_back(i);
        }
    }

    // build dependency map
    vector<vector<int>> next(n);
    vector<int> degree(n);
    for (size_t i = 0; i < beforeItems.size(); i++)
    {
        if (beforeItems[i].empty()) continue;
        int this_item = i;
        for (size_t j = 0; j < beforeItems[i].size(); j++)
        {
            int before_item = beforeItems[i][j];
            degree[this_item]++;
            next[before_item].push_back(this_item);
        }
    }
    // topology sort
    queue<int> search;
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0) search.push(i);
    }
    vector<int> result;
    index = 0;
    while (!search.empty())
    {
        int item = search.front();
        search.pop();
        visited[item] = index;
        index++;
        int g = item_group[item];
        group_free[g]++;
        if (group_free[g] == group_items[g].size())
        {
            priority_queue<pair<int, int>> order;
            for (size_t i = 0; i < group_items[g].size(); i++)
            {
                int item = group_items[g][i];
                order.push(make_pair(-visited[item], item));
                for (size_t i = 0; i < next[item].size(); i++)
                {
                    int next_item = next[item][i];
                    degree[next_item]--;
                    if (degree[next_item] == 0) search.push(next_item);
                }
            }
            while (!order.empty())
            {
                pair<int, int> pos = order.top();
                order.pop();
                result.push_back(pos.second);
            }
        }
        else
        {
            for (size_t i = 0; i < next[item].size(); i++)
            {
                int next_item = next[item][i];
                // Do not unlock different group
                if (item_group[item] != item_group[next_item]) continue;
                degree[next_item]--;
                if (degree[next_item] == 0) search.push(next_item);
            }
        }
    }
    if (result.size() < (size_t)n)
    {
        result.clear();
    }
    return result;
}

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
int LeetCodeGraph::minimumMoves(vector<vector<int>>& grid)
{
    vector<pair<int, int>> snake(2);
    set <vector<pair<int, int>>> visited;
    snake[0] = { 0, 0 };
    snake[1] = { 0, 1 }; 
    queue<vector<pair<int, int>>> search;
    visited.insert(snake);
    search.push(snake);
    int result = 0;
    int n = grid.size();
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            snake = search.front();
            search.pop();
            if (snake[0].first == n - 1 && snake[0].second == n - 2 &&
                snake[1].first == n - 1 && snake[1].second == n - 1)
            {
                return result;
            }

            vector<pair<int, int>> next;
            for (size_t j = 0; j < 4; j++)
            {
                next = snake;
                // move right
                if (j == 0)
                {
                    next[0].second++;
                    next[1].second++;
                    if (next[1].second >= n) continue;
                    if (grid[next[0].first][next[0].second] == 1 ||
                        grid[next[1].first][next[1].second] == 1)
                    {
                        continue;
                    }
                    if (visited.count(next) > 0) continue;
                }
                // down
                else if (j == 1)
                {
                    next[0].first++;
                    next[1].first++;
                    if (next[1].first >= n) continue;
                    if (grid[next[0].first][next[0].second] == 1 ||
                        grid[next[1].first][next[1].second] == 1)
                    {
                        continue;
                    }
                    if (visited.count(next) > 0) continue;
                }
                // clock
                else if (j == 2)
                {
                    if (next[0].first != next[1].first) continue;
                    if (next[1].first + 1 >= n) continue;
                    if (grid[next[0].first+1][next[0].second] == 1 ||
                        grid[next[1].first+1][next[1].second] == 1)
                    {
                        continue;
                    }

                    next[1].first = next[0].first + 1;
                    next[1].second = next[0].second;
                    if (visited.count(next) > 0) continue;
                }
                // count clock
                else 
                {
                    if (next[0].second != next[1].second) continue;
                    if (next[1].second + 1 >= n) continue;
                    if (grid[next[0].first][next[0].second + 1] == 1 ||
                        grid[next[1].first][next[1].second + 1] == 1)
                    {
                        continue;
                    }

                    next[1].second = next[0].second + 1;
                    next[1].first = next[0].first;
                    if (visited.count(next) > 0) continue;
                }
                search.push(next);
                visited.insert(next);
            }
        }
        result++;
    }
    return -1;
}

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
int LeetCodeGraph::treeDiameter(vector<vector<int>>& edges)
{
    unordered_map<int, set<int>> node_map;

    for (size_t i = 0; i < edges.size(); i++)
    {
        node_map[edges[i][0]].insert(edges[i][1]);
        node_map[edges[i][1]].insert(edges[i][0]);
    }
    
    queue<int> search;
    for (auto itr : node_map)
    {
        if (itr.second.size() == 1)
        {
            search.push(itr.first);
        }
    }
    int result = 0;
    int count = node_map.size();
    while (!search.empty())
    {
        size_t size = search.size();
        if (count > 2) result += 2;
        else if (count == 2) result += 1;
        for (size_t i = 0; i < size; i++)
        {
            int node = search.front();
            search.pop();
            count--;

            for (auto target : node_map[node])
            {
                node_map[target].erase(node);
                if (node_map[target].size() == 1)
                {
                    search.push(target);
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1254. Number of Closed Islands
/// </summary>
bool LeetCodeGraph::closedIsland(vector<vector<int>>& grid, int row, int col)
{
    if (row < 0 || col < 0 || row >= (int)grid.size() || col >= (int)grid[row].size())
    {
        return false;
    }
    if (grid[row][col] == 1) return true;
    else
    {
        grid[row][col] = 1;
        bool result = closedIsland(grid, row - 1, col);
        // You must put result at the end
        result = closedIsland(grid, row + 1, col) && result;
        result = closedIsland(grid, row, col - 1) && result;
        result = closedIsland(grid, row, col + 1) && result;
        return result;
    }
}

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
int LeetCodeGraph::closedIsland(vector<vector<int>>& grid)
{
    vector<vector<int>> visited = grid;
    int result = 0;
    for (size_t i = 0; i < visited.size(); i++)
    {
        for (size_t j = 0; j < visited[i].size(); j++)
        {
            if (visited[i][j] == 0)               
            {
                if (closedIsland(visited, i, j)) 
                {
                    result++;
                }
            }
        }
    }
    return result;
}

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
vector<vector<char>> LeetCodeGraph::updateBoard(vector<vector<char>>& board, vector<int>& click)
{
    vector<vector<int>> directions =
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    vector<int> curr = click;
    if (board.empty() || board[0].empty() || curr.size() < 2) return board;
    queue<vector<int>> process_queue;
    if (board[curr[0]][curr[1]] == 'M')
    {
        board[curr[0]][curr[1]] = 'X';
        return board;
    }
    process_queue.push(curr);
    while (!process_queue.empty())
    {
        curr = process_queue.front();
        process_queue.pop();
        int count = 0;
        vector<vector<int>> result;
        if (board[curr[0]][curr[1]] == 'E')
        {
            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = curr;
                next[0] = curr[0] + directions[d][0];
                next[1] = curr[1] + directions[d][1];

                if (next[0] < 0 || next[0] >= (int)board.size() ||
                    next[1] < 0 || next[1] >= (int)board[0].size())
                {
                    continue;
                }
                if (board[next[0]][next[1]] == 'M') count++;
                else result.push_back(next);
            }
            if (count == 0)
            {
                board[curr[0]][curr[1]] = 'B';
                for (size_t i = 0; i < result.size(); i++)
                {
                    process_queue.push(result[i]);
                }
            }
            else board[curr[0]][curr[1]] = '0' + count;
        }
    }
    return board;
}

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
vector<string> LeetCodeGraph::generateSentences(vector<vector<string>>& synonyms, string text)
{
    vector<string> words;
    size_t index = 0;
    while (index != string::npos)
    {
        size_t next = text.find(' ', index);
        if (next == string::npos)
        {
            words.push_back(text.substr(index));
            index = next;
        }
        else
        {
            words.push_back(text.substr(index, next - index));
            index = next + 1;
        }
    }
    unordered_map<string, string> word_links;
    unordered_map<string, set<string>> word_group;
    for (size_t i = 0; i < synonyms.size(); i++)
    {
        string str1 = synonyms[i][0];
        if (word_links.count(str1) == 0) word_links[str1] = str1;
        while (word_links[str1] != str1) str1 = word_links[str1];

        string str2 = synonyms[i][1];
        if (word_links.count(str2) == 0) word_links[str2] = str2;
        while (word_links[str2] != str2) str2 = word_links[str2];

        if (str1 != str2) word_links[str1] = str2;
    }
    for (auto itr : word_links)
    {
        string str = itr.first;
        while (word_links[str] != str) str = word_links[str];
        word_group[str].insert(itr.first);
        word_links[itr.first] = str;
    }

    queue<string> search;
    search.push("");
    for (size_t i = 0; i < words.size(); i++)
    {
        string word = words[i];
        size_t size = search.size();
        for (size_t j = 0; j < size; j++)
        {
            string str = search.front();
            search.pop();

            if (word_links.count(word) == 0)
            {
                search.push(str + " " + word);
            }
            else
            {
                word = word_links[word];
                for (string synonym : word_group[word])
                {
                    search.push(str + " " + synonym);
                }
            }
        }
    }
    vector<string> result;
    while (!search.empty())
    {
        result.push_back(search.front().substr(1));
        search.pop();
    }
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1263. Minimum Moves to Move a Box to Their Target Location
/// </summary>
int LeetCodeGraph::minPushBox(vector<vector<char>>& grid, int sx, int sy, int tx, int ty)
{
    queue<vector<int>> search;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m));

    vector<int> pos = { sy, sx};
    search.push(pos);
    visited[sy][sx] = 1;
    while (!search.empty())
    {
        pos = search.front();
        search.pop();
        sy = pos[0];
        sx = pos[1];
        if (sx == tx && sy == ty) return 1;
        for (size_t d = 0; d < directions.size(); d++)
        {
            int n_sx = sx + directions[d][0];
            int n_sy = sy + directions[d][1];
            if (n_sy < 0 || n_sy >= n || n_sx < 0 || n_sx >= m || grid[n_sy][n_sx] == '#')
            {
                continue;
            }
            if (visited[n_sy][n_sx] == 1) continue;
            visited[n_sy][n_sx] = 1;
            search.push({ n_sy, n_sx });
        }
    }
    return 0;
}

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
int LeetCodeGraph::minPushBox(vector<vector<char>>& grid)
{
    int px = 0, py = 0, bx = 0, by = 0, tx = 0, ty = 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'S')
            {
                py = i;
                px = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'B')
            {
                by = i;
                bx = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'T')
            {
                ty = i;
                tx = j;
                grid[i][j] = '.';
            }
        }
    }
    queue<vector<int>> search;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<vector<int>>>> visited(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m))));
    visited[py][px][by][bx] = 1;
    vector<int> pos = { py, px, by, bx };
    int result = 0;
    search.push(pos);
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pos = search.front();
            search.pop();
            py = pos[0];
            px = pos[1];
            by = pos[2];
            bx = pos[3];
            if (bx == tx && by == ty) return result;
            grid[by][bx] = '#';
            for (size_t d = 0; d < directions.size(); d++)
            {
                int n_bx = bx + directions[d][0];
                int n_by = by + directions[d][1];
                int n_px = bx - directions[d][0];
                int n_py = by - directions[d][1];
                if (n_by < 0 || n_by >= n || n_bx < 0 || n_bx >= m || 
                    grid[n_by][n_bx] == '#')
                {
                    continue;
                }
                if (n_py < 0 || n_py >= n || n_px < 0 || n_px >= m ||
                    grid[n_py][n_px] == '#')
                {
                    continue;
                }
                if (minPushBox(grid, px, py, n_px, n_py) == 1)
                {
                    pos = { by, bx, n_by, n_bx };
                    if (visited[by][bx][n_by][n_bx] == 1)
                    {
                        continue;
                    }
                    visited[by][bx][n_by][n_bx] = 1;
                    search.push(pos);
                }
            }
            grid[by][bx] = '.';
        }
        result++;
    }
    return -1;
}

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
int LeetCodeGraph::islandPerimeter(vector<vector<int>>& grid)
{
    int perimeter = 0;
    vector<pair<int, int>> directions = { { -1, 0 } ,{ 0, -1 },{ 1, 0 },{ 0, 1 } };
    for (int i = 0; i < (int)grid.size(); i++)
    {
        for (int j = 0; j < (int)grid[0].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            for (int d = 0; d < (int)directions.size(); d++)
            {
                int x = i + directions[d].first;
                int y = j + directions[d].second;
                if ((x < 0) || (y < 0) || (x == grid.size()) || (y == grid[0].size()))
                {
                    perimeter++;
                }
                else if (grid[x][y] == 0)
                {
                    perimeter++;
                }
            }
        }
    }
    return perimeter;
}

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
int LeetCodeGraph::deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value)
{
    vector<int> degree(nodes);
    vector<int> sum(nodes), count(nodes);

    for (size_t i = 1; i < parent.size(); i++)
    {
        degree[parent[i]]++;
    }
    queue<int> search;
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0) search.push(i);
    }

    while (!search.empty())
    {
        int node = search.front();
        search.pop();
        sum[node] += value[node];
        if (sum[node] != 0) count[node]++;
        else count[node] = 0;
        int parent_node = parent[node];
        if (parent_node == -1) continue;
        sum[parent_node] += sum[node];
        count[parent_node] += count[node];
        degree[parent_node]--;
        if (degree[parent_node] == 0)
        {
            search.push(parent_node);
        }
    }
    return count[0];
}

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
int LeetCodeGraph::shortestPath(vector<vector<int>>& grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> stones(m, vector<int>(n, INT_MAX));

    queue<vector<int>> pq;
    pq.push({ 0, 0, 0 });
    stones[0][0] = 0;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int result = 0;
    while (!pq.empty())
    {
        size_t size = pq.size();
        for (size_t i = 0; i < size; i++)
        {
            vector<int> pos = pq.front();
            pq.pop();

            if ((pos[0] == m - 1) && (pos[1] == n - 1))
            {
                return result;
            }
            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = pos;
                next[0] += directions[d][0];
                next[1] += directions[d][1];
                if (next[0] < 0 || next[0] >= m || next[1] < 0 || next[1] >= n)
                {
                    continue;
                }
                if (grid[next[0]][next[1]] == 1)
                {
                    next[2]++;
                }
                // push it only if we have less stones removed
                if (next[2] <= k && next[2] < stones[next[0]][next[1]])
                {
                    stones[next[0]][next[1]] = next[2];
                    pq.push(next);
                }
            }
        }
        result++;
    }
    return -1;
}

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
int LeetCodeGraph::maxCandies(vector<int>& status, vector<int>& candies,
    vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
    vector<int>& initialBoxes)
{
    queue<int> search;
    set<int> closed_boxes;

    for (size_t i = 0; i < initialBoxes.size(); i++)
    {
        search.push(initialBoxes[i]);
    }
    int result = 0;
    while (!search.empty())
    {
        int box = search.front();
        search.pop();
        if (status[box] == 0) closed_boxes.insert(box);
        else
        {
            result += candies[box];
            candies[box] = 0;
            for (auto b : containedBoxes[box])
            {
                search.push(b);
            }
            for (auto k : keys[box])
            {
                status[k] = 1;
                if (closed_boxes.count(k) > 0)
                {
                    search.push(k);
                    closed_boxes.erase(k);
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #505. The Maze II   
/// </summary>
void LeetCodeGraph::shortestDistance(vector<vector<int>>& maze, vector<vector<int>>& visited,
    vector<int>& start, priority_queue<pair<int, vector<int>>>& process_queue)
{
    vector<vector<int>> next_list;
    int distance = visited[start[0]][start[1]];
    vector<vector<int>> directions = { {-1, 0}, {1,0}, {0, -1}, {0,1} };
    for (size_t i = 0; i < 4; i++)
    {
        int step = 0;
        vector<int> pos = start;
        while (true)
        {
            pos[0] += directions[i][0];
            pos[1] += directions[i][1];
            if ((pos[0] >= 0) && (pos[0] < (int)maze.size()) &&
                (pos[1] >= 0) && (pos[1] < (int)maze[0].size()) &&
                (maze[pos[0]][pos[1]] == 0))
            {
                step++;
            }
            else
            {
                pos[0] -= directions[i][0];
                pos[1] -= directions[i][1];
                break;
            }
        }
        if (pos == start) continue;
        if (visited[pos[0]][pos[1]] > distance + step)
        {
            visited[pos[0]][pos[1]] = distance + step;
            process_queue.push(make_pair(-visited[pos[0]][pos[1]], pos));
        }
    }
}

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
/// The maze is represented by a binary 2D array. 1 means the wall and 0 means 
/// the empty space. You may assume that the borders of the maze are all walls. 
/// The start and destination coordinates are represented by row and column 
/// indexes.
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
/// 3.The given maze does not contain border (like the red rectangle in the 
///   example pictures), but you could assume the border of the maze are all 
///   walls.
/// 4.The maze contains at least 2 empty spaces, and both the width and height 
///   of the maze won't exceed 100.
/// </summary>
int LeetCodeGraph::shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    if (maze.empty() || maze[0].empty()) return -1;
    vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), INT_MAX));
    visited[start[0]][start[1]] = 0;
    priority_queue<pair<int, vector<int>>> process_queue;
    process_queue.push(make_pair(0, start));
    while (!process_queue.empty())
    {
        start = process_queue.top().second;
        process_queue.pop();
        if (start == destination) break;
        shortestDistance(maze, visited, start, process_queue);
    }
    int shortest_distance = visited[destination[0]][destination[1]];
    if (shortest_distance == INT_MAX) return -1;
    else return shortest_distance;
}

/// <summary>
/// Leet code #499. The Maze III   
/// </summary>
void LeetCodeGraph::findShortestWay(vector<vector<int>>& maze, vector<vector<pair<int, string>>>& visited,
    vector<int>& ball, vector<int>& hole, priority_queue<pair<int, vector<int>>>& process_queue)
{
    vector<vector<int>> next_list;
    int distance = visited[ball[0]][ball[1]].first;
    for (size_t i = 0; i < 4; i++)
    {
        int step = 0;
        vector<int> pos = ball;
        if (i == 0)
        {
            while ((pos != hole) && (pos[0] > 0) && (maze[pos[0] - 1][pos[1]] == 0))
            {
                step++;
                pos[0]--;
            }
        }
        else if (i == 1)
        {
            while ((pos != hole) && (pos[0] < (int)maze.size() - 1) && (maze[pos[0] + 1][pos[1]] == 0))
            {
                step++;
                pos[0]++;
            }
        }
        else if (i == 2)
        {
            while ((pos != hole) && (pos[1] > 0) && (maze[pos[0]][pos[1] - 1] == 0))
            {
                step++;
                pos[1]--;
            }
        }
        else
        {
            while ((pos != hole) && (pos[1] < (int)maze[0].size() - 1) && (maze[pos[0]][pos[1] + 1] == 0))
            {
                step++;
                pos[1]++;
            }
        }
        if (pos == ball) continue;
        if (visited[pos[0]][pos[1]].first >= distance + step)
        {
            visited[pos[0]][pos[1]].first = distance + step;
            string path = visited[ball[0]][ball[1]].second;
            if (i == 0) path.push_back('u');
            else if (i == 1) path.push_back('d');
            else if (i == 2) path.push_back('l');
            else path.push_back('r');
            if (visited[pos[0]][pos[1]].second.empty())
            {
                visited[pos[0]][pos[1]].second = path;
            }
            else
            {
                visited[pos[0]][pos[1]].second = min(path, visited[pos[0]][pos[1]].second);
            }
            process_queue.push(make_pair(-(distance + step), pos));
        }
    }
}

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
string LeetCodeGraph::findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole)
{
    int shortest_distance = INT_MAX;
    string shortest_path = "impossible";
    if (maze.empty() || maze[0].empty()) return shortest_path;
    vector<vector<pair<int, string>>> visited(maze.size(), vector<pair<int, string>>(maze[0].size(), make_pair(INT_MAX, "")));
    visited[ball[0]][ball[1]] = make_pair(0, "");
    priority_queue<pair<int, vector<int>>> process_queue;
    process_queue.push(make_pair(0, ball));
    while (!process_queue.empty())
    {
        int distance = 0 - process_queue.top().first;
        if (shortest_distance < distance) break;
        ball = process_queue.top().second;
        process_queue.pop();
        if (ball == hole)
        {
            if (distance < shortest_distance)
            {
                shortest_distance = distance;
                shortest_path = visited[ball[0]][ball[1]].second;
            }
            else if (distance == shortest_distance)
            {
                shortest_path = min(shortest_path, visited[ball[0]][ball[1]].second);
            }
        }
        else
        {
            findShortestWay(maze, visited, ball, hole, process_queue);
        }
    }
    return shortest_path;
}

/// <summary>
/// Leet code #490. The Maze  
/// </summary>
bool LeetCodeGraph::hasPath(vector<vector<int>>& maze, vector<vector<int>>& visited, vector<int>& start, vector<int>& destination)
{
    vector<vector<int>> next_list;
    for (size_t i = 0; i < 4; i++)
    {
        vector<int> pos = start;
        if (i == 0)
        {
            while ((pos[0] > 0) && (maze[pos[0] - 1][pos[1]] == 0))
            {
                pos[0]--;
            }
        }
        else if (i == 1)
        {
            while ((pos[0] < (int)maze.size() - 1) && (maze[pos[0] + 1][pos[1]] == 0)) pos[0]++;
        }
        else if (i == 2)
        {
            while ((pos[1] > 0) && (maze[pos[0]][pos[1] - 1] == 0)) pos[1]--;
        }
        else
        {
            while ((pos[1] < (int)maze[0].size() - 1) && (maze[pos[0]][pos[1] + 1] == 0)) pos[1]++;
        }
        if (visited[pos[0]][pos[1]] == 1) continue;
        if (pos == destination) return true;
        if (pos != start) next_list.push_back(pos);
        visited[pos[0]][pos[1]] = 1;
    }
    for (size_t i = 0; i < next_list.size(); i++)
    {
        if (hasPath(maze, visited, next_list[i], destination))
        {
            return true;
        }
    }
    return false;
}

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
bool LeetCodeGraph::hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    if (maze.empty() || maze[0].empty()) return false;
    vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size()));
    return hasPath(maze, visited, start, destination);
}

/// <summary>
/// Leet code #675. Cut Off Trees for Golf Event
/// </summary>
int LeetCodeGraph::calculateShortestDistance(vector<vector<int>>& forest, pair<int, int> &source, pair<int, int> &target)
{
    int result = 0;
    if (source == target) return result;
    queue<pair<int, int>> search_queue;
    search_queue.push(source);
    vector<vector<int>> visited = vector<vector<int>>(forest.size(), vector<int>(forest[0].size()));
    visited[source.first][source.second] = 1;
    vector<pair<int, int>> steps = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
    while (!search_queue.empty())
    {
        result++;
        size_t size = search_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = search_queue.front();
            search_queue.pop();
            for (size_t j = 0; j < steps.size(); j++)
            {
                // calculate next position
                pair<int, int> next = make_pair(pos.first + steps[j].first, pos.second + steps[j].second);
                // if out of boundary
                if ((next.first < 0) || (next.first >= (int)forest.size()) ||
                    (next.second < 0) || (next.second >= (int)forest[0].size()))
                {
                    continue;
                }
                // if obstacle
                if (forest[next.first][next.second] == 0) continue;

                // if reach target, result always reflect steps to next position 
                if (next == target) return result;
                // if visited already
                if (visited[next.first][next.second] == 1) continue;
                // set flag
                visited[next.first][next.second] = 1;
                // add to queue
                search_queue.push(next);
            }
        }
    }
    return -1;
}

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
int LeetCodeGraph::trapRainWater(vector<vector<int>>& heightMap)
{
    int result = 0;
    if (heightMap.empty() || heightMap[0].empty()) return 0;

    priority_queue<vector<int>> search;
    vector<vector<int>> visited(heightMap.size(), vector<int>(heightMap[0].size()));

    for (size_t i = 0; i < heightMap.size(); i++)
    {
        vector<int> pos = { -heightMap[i][0], (int)i, 0 };
        search.push(pos);
        visited[i][0] = 1;
        int max_col = heightMap[i].size() - 1;
        if (max_col > 0)
        {
            pos = { -heightMap[i][max_col], (int)i, max_col };
            search.push(pos);
            visited[i][max_col] = 1;
        }
    }

    for (size_t i = 0; i < heightMap[0].size(); i++)
    {
        vector<int> pos = { -heightMap[0][i], 0, (int)i };
        search.push(pos);
        visited[0][i] = 1;
        int max_row = heightMap.size() - 1;
        if (max_row > 0)
        {
            pos = { -heightMap[max_row][i], max_row, (int)i };
            search.push(pos);
            visited[max_row][i] = 1;
        }
    }
    while (!search.empty())
    {
        vector<int> pos = search.top();
        search.pop();
        int floor_level = -pos[0];
        vector<vector<int>> directions = { {-1, 0 }, {1, 0}, {0, -1}, {0, 1} };
        for (size_t i = 0; i < directions.size(); i++)
        {
            int row = pos[1] + directions[i][0];
            int col = pos[2] + directions[i][1];
            if ((row < 0) || (row >= (int)heightMap.size()) ||
                (col < 0) || (col >= (int)heightMap[0].size()))
            {
                continue;
            }
            if (visited[row][col] == 1)
            {
                continue;
            }
            if (heightMap[row][col] < floor_level)
            {
                result += floor_level - heightMap[row][col];
                search.push({ -floor_level, row, col });
            }
            else
            {
                search.push({ -heightMap[row][col], row, col });
            }
            visited[row][col] = 1;
        }
    }
    return result;
}

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
int LeetCodeGraph::cutOffTree(vector<vector<int>>& forest)
{
    int result = 0;
    if (forest.empty() || forest[0].empty()) return result;

    // store the tree in order
    priority_queue<pair<int, pair<int, int>>> tree_order;

    for (size_t i = 0; i < forest.size(); i++)
    {
        for (size_t j = 0; j < forest[i].size(); j++)
        {
            // only remember trees
            if (forest[i][j] > 1)
            {
                tree_order.push(make_pair(-forest[i][j], make_pair(i, j)));
            }
        }
    }
    // calcualte any to any shortest distance using Floyd-Warshal algorithm
    pair<int, int> start = make_pair(0, 0);
    while (!tree_order.empty())
    {
        pair<int, int> next = tree_order.top().second;
        tree_order.pop();
        int steps = calculateShortestDistance(forest, start, next);
        if (steps == -1) return -1;
        else result += steps;
        start = next;
    }
    return result;
}

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
bool LeetCodeGraph::isBipartite(vector<vector<int>>& graph)
{
    unordered_map<int, int> node_set;

    for (size_t i = 0; i < graph.size(); i++)
    {
        if (node_set.count(i) != 0) continue;
        queue<int> search_queue;
        node_set[i] = 0;
        search_queue.push(i);
        while (!search_queue.empty())
        {
            int node = search_queue.front();
            search_queue.pop();
            for (int next : graph[node])
            {
                if (node_set.count(next) > 0)
                {
                    if (node_set[next] == node_set[node]) return false;
                }
                else
                {
                    node_set[next] = 1 - node_set[node];
                    search_queue.push(next);
                }
            }
        }
    }
    return true;
}

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
int LeetCodeGraph::findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    vector<vector<pair<int, int>>> tickets (n);
    for (size_t i = 0; i < flights.size(); i++)
    {
        tickets[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
    }
    queue<pair<int, int>> search;
    search.push(make_pair(src, 0));
    int result = INT_MAX;
    for (int i = 0; i <= K; i++)
    {
        size_t size = search.size();
        vector<int> cost(n, INT_MAX);
        for (size_t j = 0; j < size; j++)
        {
            pair<int, int> stop = search.front();
            search.pop();
            for (auto itr : tickets[stop.first])
            {
                cost[itr.first] = min(cost[itr.first], stop.second + itr.second);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (cost[j] != INT_MAX)
            {
                search.push(make_pair(j, cost[j]));
                if (j == dst) result = min(result, cost[j]);
            }
        }
    }
    if (result == INT_MAX) return -1;
    else return result;
}

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
///
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
vector<string> LeetCodeGraph::watchedVideosByFriends(
    vector<vector<string>>& watchedVideos,
    vector<vector<int>>& friends,
    int id, int level)
{
    vector<int> visited(friends.size());
    queue<int> search;
    visited[id] = 1;
    search.push(id);
    for (int i = 0; i < level; i++)
    {
        size_t size = search.size();
        for (size_t j = 0; j < size; j++)
        {
            int id = search.front();
            search.pop();

            for (auto f : friends[id])
            {
                if (visited[f] == 1) continue;
                visited[f] = 1;
                search.push(f);
            }
        }
    }
    unordered_map<string, int> videos;
    while (!search.empty())
    {
        int id = search.front();
        search.pop();
        for (auto v : watchedVideos[id])
        {
            videos[v]++;
        }
    }
    map<int, set<string>> pq;
    for (auto itr : videos)
    {
        pq[itr.second].insert(itr.first);
    }
    vector<string> result;
    for (auto p : pq)
    {
        for (auto v : p.second) result.push_back(v);
    }
    return result;
}

/// <summary>
/// Leet code #1340. Jump Game V
/// </summary>
int LeetCodeGraph::maxJumps(vector<int>& arr, vector<int> &path, int index, int d)
{
    if (path[index] != 0) return path[index];
    int left = INT_MIN;
    int right = INT_MIN;
    int result = 1;
    for (int i = 1; i <= d; i++)
    {
        int left_index = index - i;
        if (left_index < 0) break;
        if (arr[left_index] >= arr[index]) break;
        if (arr[left_index] >= left)
        {
            left = arr[left_index];
            result = max(result, maxJumps(arr, path, left_index, d) + 1);
        }
    }
    for (int i = 1; i <= d; i++)
    {
        int right_index = index + i;
        if (right_index >= (int)path.size()) break;
        if (arr[right_index] >= arr[index]) break;
        if (arr[right_index] >= right)
        {
            right = arr[right_index];
            result = max(result, maxJumps(arr, path, right_index, d) + 1);
        }
    }
    path[index] = result;
    return result;
}

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
int LeetCodeGraph::maxJumps(vector<int>& arr, int d)
{
    int result = 0;
    vector<int> path(arr.size());
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (path[i] == 0)
        {
            path[i] = maxJumps(arr, path, i, d);
            result = max(result, path[i]);
        }
    }
    return result;
}

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
int LeetCodeGraph::minJumps(vector<int>& arr)
{
    unordered_map<int, vector<int>> val_map;
    vector<int> visited(arr.size());
    queue<int> search;
    for (size_t i = 0; i < arr.size(); i++)
    {
        val_map[arr[i]].push_back(i);
    }

    search.push(0);
    visited[0] = 1;
    int result = 0;
    int pos = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t j = 0; j < size; j++)
        {
            pos = search.front();
            search.pop();
            if (pos == arr.size() - 1) return result;

            if ((pos - 1 >= 0) && (visited[pos - 1] == 0))
            {
                visited[pos - 1] = 1;
                search.push(pos - 1);
            }
            if ((pos + 1 < (int)arr.size()) && (visited[pos + 1] == 0))
            {
                visited[pos + 1] = 1;
                search.push(pos + 1);
            }
            if (val_map.count(arr[pos]) > 0)
            {
                for (size_t i = 0; i < val_map[arr[pos]].size(); i++)
                {
                    if (visited[val_map[arr[pos]][i]] == 1)
                    {
                        continue;
                    }
                    visited[val_map[arr[pos]][i]] = 1;
                    search.push(val_map[arr[pos]][i]);
                }
                val_map.erase(arr[pos]);
            }
        }
        result++;
    }
    if (pos == arr.size() - 1) return result;
    else return 0;
}

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
bool LeetCodeGraph::validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
{
    vector<int> visited(n);
    queue<int> search;
    for (int i = 0; i < n; i++)
    {
        if ((visited[i] & 0x01) == 0)
        {
            search.push(i);
            while (!search.empty())
            {
                int node = search.front();
                search.pop();
                visited[node] |= 0x01;
                if (leftChild[node] != -1)
                {
                    int child = leftChild[node];
                    // some one claim this node as child
                    if ((visited[child] & 0x10) != 0) return false;
                    visited[child] |= 0x10;
                    // the children has been visited
                    if ((visited[child] & 0x01) == 0)
                    {
                        search.push(child);
                    }
                }
                if (rightChild[node] != -1)
                {
                    int child = rightChild[node];
                    // some one claim this node as child
                    if ((visited[child] & 0x10) != 0) return false;
                    visited[child] |= 0x10;
                    // the children of this node has been visited
                    if ((visited[child] & 0x01) == 0)
                    {
                        search.push(child);
                    }
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((visited[i] & 0x10) == 0) count++;
    }
    return (count == 1);
}

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
int LeetCodeGraph::minCost(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> directions = 
    { 
        {0, 1}, {0, -1}, {1, 0}, {-1, 0} 
    };
    
    vector<vector<int>> cost(n, vector<int>(m, INT_MIN));
    priority_queue<vector<int>> pq;
    pq.push({ 0, 0, 0 });
    cost[0][0] = 0;
    int result = -1;
    while (!pq.empty())
    {
        vector<int> pos = pq.top();
        pq.pop();
        if (pos[1] == n - 1 && pos[2] == m - 1)
        {
            result = 0 - pos[0];
            break;
        }
        vector<int> next(3);
        for (int i = 0; i < 4; i++)
        {
            if (i == grid[pos[1]][pos[2]] - 1)
            {
                next[0] = pos[0];
            }
            else
            {
                next[0] = pos[0] - 1;
            }
            next[1] = pos[1] + directions[i].first;
            next[2] = pos[2] + directions[i].second;
            if (next[1] < 0 || next[1] >= n || next[2] < 0 || next[2] >= m)
            {
                continue;
            }
            if (next[0] <= cost[next[1]][next[2]]) continue;
            cost[next[1]][next[2]] = next[0];
            pq.push(next);
        }
    }
    return result;
}


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
int LeetCodeGraph::numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
{
    unordered_map<int, vector<int>> org;

    for (size_t i = 0; i < manager.size(); i++)
    {
        org[manager[i]].push_back(i);
    }

    queue<pair<int, int>> queue;
    int result = 0;
    queue.push(make_pair(headID, 0));

    while (!queue.empty())
    {
        pair<int, int> person = queue.front();
        queue.pop();
        result = max(result, person.second);
        for (size_t i = 0; i < org[person.first].size(); i++)
        {
            queue.push(make_pair(org[person.first][i], person.second + informTime[person.first]));
        }
    }
    return result;
}

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
double LeetCodeGraph::frogPosition(int n, vector<vector<int>>& edges, int t, int target)
{
    unordered_map<int, set<int>> edge_map;
    for (size_t i = 0; i < edges.size(); i++)
    {
        edge_map[edges[i][0]].insert(edges[i][1]);
        edge_map[edges[i][1]].insert(edges[i][0]);
    }
    queue<pair<int, double>> queue;
    queue.push(make_pair(1, 1));
    for (int i = 0; i <= t; i++)
    {
        size_t size = queue.size();
        for (size_t j = 0; j < size; j++)
        {
            pair<int, double> node = queue.front();
            queue.pop();
            int from = node.first;
            if (from == target)
            {
                if (edge_map[from].empty() || i == t)
                {
                    return node.second;
                }
                else
                {
                    return 0.0;
                }
            }
            if (!edge_map[from].empty())
            {
                double probability = node.second / edge_map[node.first].size();
                for (int to : edge_map[from])
                {
                    edge_map[to].erase(from);
                    queue.push(make_pair(to, probability));
                }
            }
        }
    }
    return 0.0;
}

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
string LeetCodeGraph::destCity(vector<vector<string>>& paths)
{
    unordered_map<string, int> source;
    for (size_t i = 0; i < paths.size(); i++)
    {
        source[paths[i][0]] += 1;
        source[paths[i][1]] += 0;
    }
    string result;
    for (auto itr : source)
    {
        if (itr.second == 0)
        {
            result = itr.first;
            break;
        }
    }
    return result;
}

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
int LeetCodeGraph::minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple)
{
    vector<int> degrees(n), directions(n), times(n);
    int result = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        degrees[edges[i][0]]++;
        directions[edges[i][1]] = edges[i][0];
    }
    queue<int> search;
    for (int i = 0; i < n; i++)
    {
        if (degrees[i] == 0) search.push(i);
    }
    while (!search.empty())
    {
        int node = search.front();
        search.pop();
        if (node == 0) break;
        if (hasApple[node] == true || times[node] != 0)
        {
            times[directions[node]] += 2;
            times[directions[node]] += times[node];
        }
        degrees[directions[node]]--;
        if (degrees[directions[node]] == 0)
        {
            search.push(directions[node]);
        }
    }
    return times[0];
}

#pragma endregion

#pragma region UnionFind

/// <summary>
/// Leet Code 305. Number of Islands II
///                                                                 
/// Hard
///
/// You are given an empty 2D binary grid grid of size m x n. The grid 
/// represents a map where 0's represent water and 1's represent land. 
/// Initially, all the cells of grid are water cells (i.e., all the 
/// cells are 0's).
///  
/// We may perform an add land operation which turns the water at 
/// position into a land. You are given an array positions where 
/// positions[i] = [ri, ci] is the position (ri, ci) at which we 
/// should operate the ith operation.
///
/// Return an array of integers answer where answer[i] is the 
/// number of islands after turning the cell (ri, ci) into a land.
///
/// An island is surrounded by water and is formed by connecting 
/// adjacent lands horizontally or vertically. You may assume all 
/// four edges of the grid are all surrounded by water.
/// Example 1: 
/// Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
/// Output: [1,1,2,3]
/// Explanation:
/// Initially, the 2d grid is filled with water. 
/// - Operation #1: addLand(0, 0) turns the water at grid[0][0] into a 
///   land. We have 1 island.
/// - Operation #2: addLand(0, 1) turns the water at grid[0][1] into a 
///   land. We still have 1 island.
/// - Operation #3: addLand(1, 2) turns the water at grid[1][2] into a 
///   land. We have 2 islands.
/// - Operation #4: addLand(2, 1) turns the water at grid[2][1] into a 
///   land. We have 3 islands.
///
/// Example 2:
/// Input: m = 1, n = 1, positions = [[0,0]]
/// Output: [1]
///
/// Constraints:
/// 1. 1 <= m, n, positions.length <= 10^4
/// 2. 1 <= m * n <= 10^4
/// 3. positions[i].length == 2
/// 4. 0 <= ri < m
/// 5. 0 <= ci < n
/// 
/// Follow up: Could you solve it in time complexity O(k log(mn)), where 
/// k == positions.length?
/// </summary>
vector<int> LeetCodeGraph::numIslands2(int m, int n, vector<vector<int>>& positions)
{
    vector<int> result;
    vector<int> parent(m * n + 1);
    for (size_t i = 0; i < parent.size(); i++) parent[i] = i;
    vector<vector<int>> grid_map(m, vector<int>(n));
    int count = 0;
    for (size_t i = 0; i < positions.size(); i++)
    {
        vector<int> pos = positions[i];
        // already set before
        if (grid_map[pos[0]][pos[1]] == 0)
        {
            int island_id = i + 1;
            grid_map[pos[0]][pos[1]] = island_id;
            count++;

            vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = pos;
                next[0] += directions[d][0];
                next[1] += directions[d][1];
                if ((next[0] < 0) || (next[0] >= (int)grid_map.size()) ||
                    (next[1] < 0) || (next[1] >= (int)grid_map[0].size()))
                {
                    continue;
                }
                int neighbor = grid_map[next[0]][next[1]];
                // water
                if (neighbor == 0)
                {
                    continue;
                }
                while (parent[parent[neighbor]] != parent[neighbor]) parent[neighbor] = parent[parent[neighbor]];
                if (parent[neighbor] != island_id)
                {
                    parent[parent[neighbor]] = island_id;
                    count--;
                }
            }
        }
        result.push_back(count);
    }
    return result;
}

/// <summary>
/// Leet Code 547. Number of Provinces
///                                                                 
/// Medium
///
/// There are n cities. Some of them are connected, while some are not. If
/// city a is connected directly with city b, and city b is connected 
/// directly with city c, then city a is connected indirectly with city c.
///
/// A province is a group of directly or indirectly connected cities and 
/// no other cities outside of the group.
///
/// You are given an n x n matrix isConnected where isConnected[i][j] = 1 
/// if the ith city and the jth city are directly connected, and 
/// isConnected[i][j] = 0 otherwise.
///
/// Return the total number of provinces.
///
/// Example 1:
/// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
/// Output: 2
///
/// Example 2:
/// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
/// Output: 3
///
/// Constraints:
/// 1. 1 <= n <= 200
/// 2. n == isConnected.length
/// 3. n == isConnected[i].length
/// 4. isConnected[i][j] is 1 or 0.
/// 5. isConnected[i][i] == 1
/// 6. isConnected[i][j] == isConnected[j][i]
/// </summary>
int LeetCodeGraph::findCircleNum(vector<vector<int>>& M)
{
    vector<int> parent(M.size());
    for (size_t i = 0; i < M.size(); i++)
    {
        parent[i] = i;
    }
    for (size_t i = 0; i < M.size(); i++)
    {
        for (size_t j = 0; j < M[i].size(); j++)
        {
            if (i == j) continue;
            if (M[i][j] == 1)
            {
                // fine the root of both source and target and union them by 
                // pointing target to the source
                int source = i;
                int target = j;
                while (parent[parent[source]] != parent[source]) parent[source] = parent[parent[source]];
                while (parent[target] != parent[parent[target]]) parent[target] = parent[parent[target]];
                parent[parent[target]] = parent[source];
            }
        }
    }

    int count = 0;
    for (size_t i = 0; i < parent.size(); i++)
    {
        if (parent[i] == i) count++;
    }

    return count;
}

/// <summary>
/// Leet code #695. Max Area of Island
/// </summary>
int LeetCodeGraph::mergeIsland(vector<vector<pair<int, int>>>& grid_map, vector<vector<int>>& grid_count,
    pair<int, int>& source, pair<int, int>& target)
{
    while (source != grid_map[source.first][source.second])
    {
        source = grid_map[source.first][source.second];
    }
    while (target != grid_map[target.first][target.second])
    {
        target = grid_map[target.first][target.second];
    }
    if (source != target)
    {
        grid_map[source.first][source.second] = target;
        grid_count[target.first][target.second] += grid_count[source.first][source.second];
    }
    return grid_count[target.first][target.second];
}

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
int LeetCodeGraph::maxAreaOfIsland(vector<vector<int>>& grid)
{
    int max_area = 0;
    if (grid.empty() || grid[0].empty()) return max_area;
    vector<vector<pair<int, int>>> grid_map(grid.size(), vector<pair<int, int>>(grid[0].size()));
    vector<vector<int>> grid_count(grid.size(), vector<int>(grid[0].size()));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            grid_map[i][j] = make_pair(i, j);
            pair<int, int> source;
            pair<int, int> target = grid_map[i][j];
            grid_count[i][j] = 1;
            if (i > 0 && grid[i - 1][j] == 1)
            {
                source = make_pair(i - 1, j);
                mergeIsland(grid_map, grid_count, source, target);
            }
            if (j > 0 && grid[i][j - 1] == 1)
            {
                source = make_pair(i, j - 1);
                mergeIsland(grid_map, grid_count, source, target);
            }
            max_area = max(max_area, grid_count[i][j]);
        }
    }
    return max_area;
}

/// <summary>
/// Leet code #803. Bricks Falling When Hit
/// </summary>
int LeetCodeGraph::unionBricks(int source, int target, int size, unordered_map<int, pair<int, int>>& union_map)
{
    while (union_map[source].first != source) source = union_map[source].first;
    while (union_map[target].first != target) target = union_map[target].first;

    if (source == target) return 0;
    if (source < target) swap(source, target);
    union_map[source].first = target;
    union_map[target].second += union_map[source].second;

    if (source >= size && target < size) return union_map[source].second;
    else return 0;
}

/// <summary>
/// Leet code #803. Bricks Falling When Hit
/// </summary>
int LeetCodeGraph::unionNeighbors(int row, int col, vector<vector<int>>& grid, unordered_map<int, pair<int, int>>& union_map)
{
    int result = 0;
    if (grid[row][col] != 1) return 0;
    int source = row * grid[0].size() + col;
    if (union_map.count(source) == 0)
    {
        union_map[source].first = source;
        union_map[source].second = 1;
    }
    vector<vector<int>> directions = { { 0, -1 },{ 0, 1 },{ -1, 0 },{ 1, 0 } };
    for (size_t i = 0; i < directions.size(); i++)
    {
        int next_row = row + directions[i][0];
        int next_col = col + directions[i][1];
        // skip invalid positions
        if (next_row < 0 || next_row >= (int)grid.size() || next_col < 0 || next_col >= (int)grid[0].size()) continue;
        // no bricks
        if (grid[next_row][next_col] != 1) continue;
        // new position
        int target = next_row * grid[0].size() + next_col;
        if (union_map.count(target) == 0)
        {
            union_map[target].first = target;
            union_map[target].second = 1;
        }
        result += unionBricks(source, target, grid[0].size(), union_map);
    }
    return result;
}

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
vector<int> LeetCodeGraph::hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits)
{
    vector<int> result(hits.size());
    unordered_map<int, pair<int, int>> union_map;
    for (size_t i = 0; i < hits.size(); i++)
    {
        grid[hits[i][0]][hits[i][1]] = -grid[hits[i][0]][hits[i][1]];
    }
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                unionNeighbors(i, j, grid, union_map);
            }
        }
    }
    for (int i = hits.size() - 1; i >= 0; i--)
    {
        if (grid[hits[i][0]][hits[i][1]] == -1)
        {
            grid[hits[i][0]][hits[i][1]] = 1;
            result[i] = unionNeighbors(hits[i][0], hits[i][1], grid, union_map);
            // if hit is not top line deduct it
            if (hits[i][0] > 0 && result[i] > 0) result[i] -= 1;
        }
    }
    return result;
}

/// <summary>
/// Leet code #827. Making A Large Island
/// </summary>
int LeetCodeGraph::mergeIsland(int source, int target, unordered_map<int, pair<int, int>>& union_map)
{
    // search to root
    while (union_map[source].first != source) source = union_map[source].first;
    while (union_map[target].first != target) target = union_map[target].first;

    if (source != target)
    {
        if (source < target) swap(source, target);
        union_map[source].first = target;
        union_map[target].second += union_map[source].second;
    }

    return union_map[target].second;
}

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
int LeetCodeGraph::largestIsland(vector<vector<int>>& grid)
{
    int result = 0;
    unordered_map<int, pair<int, int>> union_map;

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            int curr = i * grid[0].size() + j;
            union_map[curr].first = curr;
            union_map[curr].second = 1;

            if ((i > 0) && (grid[i - 1][j] == 1))
            {
                int up = curr - grid[0].size();
                result = max(result, mergeIsland(curr, up, union_map));
            }
            if ((j > 0) && (grid[i][j - 1] == 1))
            {
                int left = curr - 1;
                result = max(result, mergeIsland(curr, left, union_map));
            }
            result = max(result, 1);
        }
    }

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            // skip land
            if (grid[i][j] == 1) continue;
            set<int> neighbour;
            int area = 1;
            vector<vector<int>> directions = { { 0, -1 },{ 0, 1 },{ -1, 0 },{ 1, 0 } };
            for (size_t d = 0; d < directions.size(); d++)
            {
                int next_row = i + directions[d][0];
                int next_col = j + directions[d][1];
                // skip invalid positions
                if (next_row < 0 || next_row >= (int)grid.size() || next_col < 0 || next_col >= (int)grid[0].size()) continue;
                // no bricks
                if (grid[next_row][next_col] != 1) continue;
                // new position
                int target = next_row * grid[0].size() + next_col;
                while (union_map[target].first != target) target = union_map[target].first;
                if (neighbour.count(target) == 0)
                {
                    neighbour.insert(target);
                    area += union_map[target].second;
                }
            }
            result = max(result, area);
        }
    }
    return result;
}

/// <summary>
/// Leet code #9903. Check Radar 
/// </summary>
bool LeetCodeGraph::checkOverlap(vector<double>radar1, vector<double>radar2)
{
    double distance =
        sqrt(((radar1[0] - radar2[0]) * (radar1[0] - radar2[0]) +
            (radar1[1] - radar2[1]) * (radar1[1] - radar2[1])));
    if (distance <= radar1[2] + radar2[2]) return true;
    else return false;
}

/// <summary>
/// Leet code #9903. Check Radar 
/// </summary>
bool LeetCodeGraph::checkBlock(int width, double y_min, double y_max)
{
    if ((y_min <= 0) && (y_max >= width))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #9903. Check Radar 
/// 
/// Give a road, with width in Y axis, and a list of radar, with x, y, and r which indicates  
/// the position and radius, assume your car move from left (with x = 0) to right (x = INT_MAX)
/// and your car can move on any curve as you wish, can you avoid any radar in this road?
/// The road is assumed with position from 0 to width in Y axis.
/// </summary>
bool LeetCodeGraph::canAvoidRadar(int width, vector<vector<double>>& radars)
{
    double y_min = 0, y_max = 0;
    set<vector<double>> radarSet(radars.begin(), radars.end());
    set<vector<double>>::iterator itr;
    set<vector<double>> checkSet;
    while (!radarSet.empty())
    {
        for (vector<double> radar : radarSet)
        {
            if (checkSet.empty())
            {
                checkSet.insert(radar);
                y_min = radar[1] - radar[2];
                y_max = radar[1] + radar[2];
                itr = checkSet.begin();
            }
            else if (checkSet.count(radar) == 0)
            {
                if (checkOverlap(*itr, radar))
                {
                    y_min = min(y_min, radar[1] - radar[2]);
                    y_max = max(y_max, radar[1] + radar[2]);
                    checkSet.insert(radar);
                }
            }
        }
        itr++;
        for (auto itr : checkSet)
        {
            radarSet.erase(itr);
        }
        if (itr == checkSet.end())
        {
            if (checkBlock(width, y_min, y_max)) return false;
            checkSet.clear();
        }
    }
    return true;
}

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
vector<vector<string>> LeetCodeGraph::accountsMergeII(vector<vector<string>>& accounts)
{
    unordered_map<string, int> email_map;
    unordered_map<int, int> parent_map;
    unordered_map<int, set<string>> merged_account;
    vector<vector<string>> result;

    for (size_t i = 0; i < accounts.size(); i++)
    {
        string name = accounts[i][0];
        int self = i;
        parent_map[i] = i;
        for (size_t j = 1; j < accounts[i].size(); j++)
        {
            string email = accounts[i][j];
            if (email_map.count(email) == 0)
            {
                email_map[email] = i;
            }
            else
            {
                // union merge with root
                int parent = email_map[email];
                while (parent_map[parent] != parent) parent = parent_map[parent];
                if (parent != self)
                {
                    parent_map[self] = parent;
                    self = parent;
                }
            }
        }
    }
    for (auto itr : parent_map)
    {
        for (size_t j = 1; j < accounts[itr.first].size(); j++)
        {
            int parent = itr.second;
            while (parent_map[parent] != parent) parent = parent_map[parent];
            merged_account[parent].insert(accounts[itr.first][j]);
        }
    }

    for (auto itr : merged_account)
    {
        vector<string> account;
        account.push_back(accounts[itr.first][0]);
        for (string str : itr.second) account.push_back(str);
        result.push_back(account);
    }
    return result;
}

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
bool LeetCodeGraph::areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
    vector<pair<string, string>> pairs)
{
    if (words1.size() != words2.size()) return false;
    unordered_map<string, string> similar_words;
    for (auto itr : pairs)
    {
        string first = itr.first;
        // insert the first word if not exist
        if (similar_words.count(first) == 0) similar_words[first] = first;
        // find the root of the first word
        while (similar_words[first] != first) first = similar_words[first];
        string second = itr.second;
        // insert the second word if not exist
        if (similar_words.count(second) == 0) similar_words[second] = second;
        // find the root of the second word
        while (similar_words[second] != second) second = similar_words[second];
        // point the second word to the first
        similar_words[second] = first;
    }
    for (size_t i = 0; i < words1.size(); i++)
    {
        string first = words1[i];
        // find the root of first word
        while (similar_words[first] != first) first = similar_words[first];
        string second = words2[i];
        // find the root of second word
        while (similar_words[second] != second) second = similar_words[second];
        if (first != second) return false;
    }
    return true;
}

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
int LeetCodeGraph::removeStones(vector<vector<int>>& stones)
{
    unordered_map<int, int> row_map;
    unordered_map<int, int> col_map;
    unordered_map<int, int> union_map;
    for (size_t i = 0; i < stones.size(); i++)
    {
        int index = i;
        int row = stones[i][0];
        int col = stones[i][1];
        if (row_map.count(row) == 0) row_map[row] = index;
        if (col_map.count(col) == 0) col_map[col] = index;
        int source = row_map[row];
        int target = col_map[col];
        if (union_map.count(source) == 0) union_map[source] = source;
        if (union_map.count(target) == 0) union_map[target] = target;
        while (source != union_map[source]) source = union_map[source];
        while (union_map.count(target) > 0 && target != union_map[target]) target = union_map[target];
        union_map[source] = target;
    }
    int result = 0;
    for (auto r : union_map)
    {
        if (r.first == r.second) result++;
    }
    return stones.size() - result;
}

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
int LeetCodeGraph::largestComponentSize(vector<int>& A)
{
    vector<vector<int>> factors(A.size());
    unordered_map<int, int> prime_map;
    vector<int> union_map(A.size());
    vector<int> count(A.size(), 1);

    for (size_t i = 0; i < A.size(); i++)
    {
        int x = A[i];
        for (size_t d = 2; d <= sqrt(x); d++)
        {
            if (x % d == 0)
            {
                while (x % d == 0) x /= d;
                factors[i].push_back(d);
            }
        }
        if (x > 1) factors[i].push_back(x);
    }

    int result = 1;
    for (size_t i = 0; i < A.size(); i++)
    {
        union_map[i] = i;
        count[i] = 1;
        for (auto p : factors[i])
        {
            if (prime_map.count(p) == 0)
            {
                prime_map[p] = i;
            }
            else
            {
                int source = i;
                int target = prime_map[p];
                while (union_map[source] != source) source = union_map[source];
                while (union_map[target] != target) target = union_map[target];
                if (source != target)
                {
                    union_map[source] = target;
                    count[target] += count[source];
                    result = max(count[target], result);
                }
            }
        }
    }
    return result;
}

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
bool LeetCodeGraph::equationsPossible(vector<string>& equations)
{
    unordered_map<char, char> same;
    vector<pair<char, char>> diff;

    for (size_t i = 0; i < equations.size(); i++)
    {
        char a = equations[i][0];
        char b = equations[i][3];
        if (equations[i][1] == '!')
        {
            diff.push_back(make_pair(a, b));
        }
        else
        {
            if (same.count(a) == 0) same[a] = a;
            if (same.count(b) == 0) same[b] = b;

            while (same[a] != a) a = same[a];
            while (same[b] != b) b = same[b];
            if (a != b) same[a] = b;
        }
    }

    for (size_t i = 0; i < diff.size(); i++)
    {
        char a = diff[i].first;
        char b = diff[i].second;
        if (same.count(a) == 0) same[a] = a;
        if (same.count(b) == 0) same[b] = b;
        while (same[a] != a) a = same[a];
        while (same[b] != b) b = same[b];

        if (a == b) return false;
    }
    return true;
}

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
string LeetCodeGraph::smallestEquivalentString(string A, string B, string S)
{
    vector<int> letters(26);
    for (size_t i = 0; i < 26; i++) letters[i] = i;

    for (size_t i = 0; i < A.size(); i++)
    {
        int a = A[i] - 'a';
        int b = B[i] - 'a';
        while (letters[a] != a)
        {
            letters[a] = letters[letters[a]];
            a = letters[a];
        }
        while (letters[b] != b)
        {
            letters[b] = letters[letters[b]];
            b = letters[b];
        }
        if (a < b) letters[b] = a;
        else letters[a] = b;
    }

    string result = S;
    for (size_t i = 0; i < result.size(); i++)
    {
        int a = result[i] - 'a';
        while (letters[a] != a) a = letters[a];
        result[i] = a + 'a';
    }
    return result;
}

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
int LeetCodeGraph::earliestAcq(vector<vector<int>>& logs, int N)
{
    vector<int> count(N, 1);
    vector<int> parent(N, -1);
    sort(logs.begin(), logs.end());

    for (size_t i = 0; i < logs.size(); i++)
    {
        int first = logs[i][1];
        int second = logs[i][2];
        if (parent[first] == -1) parent[first] = first;
        if (parent[second] == -1) parent[second] = second;
        while (parent[first] != first)
        {
            parent[first] = parent[parent[first]];
            first = parent[first];
        }
        while (parent[second] != second)
        {
            parent[second] = parent[parent[second]];
            second = parent[second];
        }
        if (first != second)
        {
            parent[second] = first;
            count[first] += count[second];
            if (count[first] == N) return logs[i][0];
        }
    }
    return -1;
}

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
int LeetCodeGraph::numSimilarGroups(vector<string>& A)
{
    vector<int> visited(A.size());
    int result = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (visited[i] == 1) continue;
        queue<string> search;
        search.push(A[i]);
        visited[i] = 1;
        result++;
        while (!search.empty())
        {
            string str = search.front();
            search.pop();
            for (size_t j = 0; j < A.size(); j++)
            {
                if (visited[j] == 1) continue;
                int diff_count = 0;
                for (size_t k = 0; k < str.size(); k++)
                {
                    if (str[k] != A[j][k]) diff_count++;
                    if (diff_count > 2) break;
                }
                if (diff_count == 2)
                {
                    search.push(A[j]);
                    visited[j] = 1;
                }
            }
        }
    }
    return result;
}

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
string LeetCodeGraph::smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
    vector<int> parent(s.size());
    unordered_map<int, priority_queue<char>> char_set;

    for (size_t i = 0; i < parent.size(); i++) parent[i] = i;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        int a = pairs[i][0];
        int b = pairs[i][1];
        while (parent[a] != a)
        {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        while (parent[b] != b)
        {
            parent[b] = parent[parent[b]];
            b = parent[b];
        }
        parent[a] = b;
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        int a = i;
        while (parent[a] != a)
        {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        char_set[a].push('z' - s[i]);
    }
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        int a = i;
        while (parent[a] != a) a = parent[a];
        if (!char_set.empty())
        {
            result.push_back('z' - char_set[a].top());
            char_set[a].pop();
        }
    }
    return result;
}

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
int LeetCodeGraph::makeConnected(int n, vector<vector<int>>& connections)
{
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    int cables = 0;
    for (size_t i = 0; i < connections.size(); i++)
    {
        int a = connections[i][0];
        int b = connections[i][1];

        while (p[a] != a)
        {
            p[a] = p[p[a]];
            a = p[a];
        }
        while (p[b] != b)
        {
            p[b] = p[p[b]];
            b = p[b];
        }
        if (a == b) cables++;
        else p[a] = b;
    }
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == i) result++;
    }
    if (cables < result) return -1;
    else return result;
}

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
vector<bool> LeetCodeGraph::checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
{
    vector<unordered_set<int>> next(n);
    vector<int> degree(n);
    vector<unordered_set<int>> pre_course(n);
    for (size_t i = 0; i < prerequisites.size(); i++)
    {
        degree[prerequisites[i][1]]++;
        next[prerequisites[i][0]].insert(prerequisites[i][1]);
    }
    queue<int> search;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0) search.push(i);
    }
    while (!search.empty())
    {
        int course = search.front();
        search.pop();

        for (auto c : next[course])
        {
            pre_course[c].insert(pre_course[course].begin(), pre_course[course].end());
            pre_course[c].insert(course);
            degree[c]--;
            if (degree[c] == 0) search.push(c);
        }
    }

    vector<bool> result;
    for (size_t i = 0; i < queries.size(); i++)
    {
        if (pre_course[queries[i][1]].count(queries[i][0]) > 0)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }
    return result;
}

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
int LeetCodeGraph::minReorder(int n, vector<vector<int>>& connections)
{
    vector<unordered_map<int, int>> road(n);
    for (size_t i = 0; i < connections.size(); i++)
    {
        road[connections[i][0]][connections[i][1]] = 1;
        road[connections[i][1]][connections[i][0]] = -1;
    }

    queue<int> search;
    int result = 0;
    search.push(0);
    while (!search.empty())
    {
        int city = search.front();
        search.pop();

        for (auto itr : road[city])
        {
            if (itr.second == 0) continue;
            if (itr.second == 1) result++;
            road[city][itr.first] = 0;
            road[itr.first][city] = 0;
            search.push(itr.first);
        }
    }
    return result;
}

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
int LeetCodeGraph::findJudge(int N, vector<vector<int>>& trust)
{
    vector<int> result(N);
    for (size_t i = 0; i < trust.size(); i++)
    {
        if (trust[i][0] != trust[i][1])
        {
            result[trust[i][0] - 1]--;
            result[trust[i][1] - 1]++;
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] == N - 1) return i + 1;
    }
    return -1;
}

/// <summary>
/// Leet code #1489. Find Critical and Pseudo-Critical Edges in Minimum 
///                  Spanning Tree
/// </summary>
int LeetCodeGraph::get_mst(int n, vector<vector<int>>& edges, int start_edge, int ignore_edge)
{
    vector<int> parents(n);
    for (int i = 0; i < n; i++) parents[i] = i;
    int result = 0;
    if (start_edge != -1)
    {
        parents[edges[start_edge][0]] = parents[edges[start_edge][1]];
        result += edges[start_edge][2];
    }
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (i == ignore_edge) continue;
        int start = edges[i][0];
        int end = edges[i][1];
        while (parents[start] != start) start = parents[start];
        while (parents[end] != end) end = parents[end];
        if (start == end) continue;
        result += edges[i][2];
        parents[start] = parents[end];
    }
    unordered_set<int> root;
    for (int i = 0; i < n; i++)
    {
        int node = i;
        while (parents[node] != node) node = parents[node];
        root.insert(node);
    }
    if (root.size() > 1) return INT_MAX;
    else return result;
}

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
vector<vector<int>> LeetCodeGraph::findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> result(2, vector<int>());
    for (size_t i = 0; i < edges.size(); i++)
    {
        edges[i].push_back(i);
    }
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {return (a[2] < b[2]); });
    int min_dist = get_mst(n, edges, -1, -1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        int dist = get_mst(n, edges, i, -1);
        if (dist > min_dist) continue;
        dist = get_mst(n, edges, -1, i);
        if (dist > min_dist)
        {
            result[0].push_back(edges[i][3]);
        }
        else
        {
            result[1].push_back(edges[i][3]);
        }
    }
    return result;
}

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
int LeetCodeGraph::minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k)
{
    vector<queue<int>> matrix1(n + 1), matrix2(n + 1);
    vector<int> degree1(n + 1), degree2(n+1);
    vector<int> depths(n + 1);
    for (size_t i = 0; i < dependencies.size(); i++)
    {
        degree1[dependencies[i][0]]++;
        degree2[dependencies[i][1]]++;
        matrix1[dependencies[i][1]].push(dependencies[i][0]);
        matrix2[dependencies[i][0]].push(dependencies[i][1]);
    }
    queue<int> search;
    for (int i = 1; i <= n; i++)
    {
        if (degree1[i] == 0) search.push(i);
    }
    int depth = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            int course = search.front();
            search.pop();
            while (!matrix1[course].empty())
            {
                int next = matrix1[course].front();
                matrix1[course].pop();
                degree1[next]--;
                if (degree1[next] == 0) search.push(next);
            }
            depths[course] = depth;
        }
        depth++;
    }
    int result = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (degree2[i] == 0) pq.push(make_pair(depths[i], i));
    }
    while (!pq.empty())
    {
        result++;
        queue<pair<int, int>> next_queue;
        for (int i = 0; i < k; i++)
        {
            if (pq.empty()) break;
            pair<int, int> pos = pq.top();
            pq.pop();
            while (!matrix2[pos.second].empty())
            {
                int next = matrix2[pos.second].front();
                matrix2[pos.second].pop();
                degree2[next]--;
                if (degree2[next] == 0) next_queue.push(make_pair(depths[next], next));
            }
        }
        while (!next_queue.empty())
        {
            pair<int, int> pos = next_queue.front();
            next_queue.pop();
            pq.push(pos);
        }
    }
    return result;
}


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
double LeetCodeGraph::maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
{
    vector<vector<pair<int, double>>> next(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        next[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
        next[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
    }
    vector<double> probability(n);
    priority_queue<pair<double, int>> pq;
    probability[start] = 1;
    pq.push(make_pair(1, start));

    while (!pq.empty())
    {
        pair<double, int> pr = pq.top();
        pq.pop();
        if (pr.second == end) break;
        if (pr.first < probability[pr.second]) continue;
        for (size_t i = 0; i < next[pr.second].size(); i++)
        {
            pair<int, double> node = next[pr.second][i];
            if (pr.first * node.second <= probability[node.first]) continue;
            probability[node.first] = pr.first * node.second;
            pq.push(make_pair(pr.first * node.second, node.first));
        }
    }
    return probability[end];
}

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
vector<int> LeetCodeGraph::mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath)
{
    vector<vector<int>> links(n, vector<int>());
    for (size_t i = 0; i < roads.size(); i++)
    {
        links[roads[i][0]].push_back(roads[i][1]);
        links[roads[i][1]].push_back(roads[i][0]);
    }
    int size = targetPath.size();
    vector<vector<int>> prev(size, vector<int>(n, -1));
    vector<vector<int>> dp(size, vector<int>(n, INT_MAX));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                int cost = 0;
                if (names[j] == targetPath[0])
                {
                    cost = 0;
                }
                else
                {
                    cost = 1;
                }
                dp[i][j] = cost;
            }
            else
            {
                for (size_t k = 0; k < links[j].size(); k++)
                {
                    int next_city = links[j][k];
                    int cost = dp[i-1][j];
                    if (names[next_city] != targetPath[i])
                    {
                        cost++;
                    }
                    if (cost < dp[i][next_city])
                    {
                        dp[i][next_city] = cost;
                        prev[i][next_city] = j;
                    }
                }
            }
        }
    }
    vector<int> result(size);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[size-1][i] < dp[size - 1][index])
        {
            index = i;
        }
    }
    result[size - 1] = index;
    for (int i = (int)size - 1; i > 0; i--)
    {
        result[i - 1] = prev[i][index];
        index = prev[i][index];
    }
    return result;
}


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
vector<int> LeetCodeGraph::findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
{
    vector<int> degree(n);
    vector<int> result;
    for (size_t i = 0; i < edges.size(); i++)
    {
        degree[edges[i][1]]++;
    }
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0)
        {
            result.push_back(i);
        }
    }
    return result;
}

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
bool LeetCodeGraph::containsCycle(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector <vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<pair<int, int>> directions =
    {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (prev[i][j].first == -1)
            {
                queue<pair<int, int>> search;
                char ch = grid[i][j];
                search.push(make_pair(i, j));
                prev[i][j] = make_pair(i, j);
                while (!search.empty())
                {
                    pair<int, int> pos = search.front();
                    search.pop();
                    for (size_t d = 0; d < directions.size(); d++)
                    {
                        pair<int, int> next = pos;
                        next.first += directions[d].first;
                        next.second += directions[d].second;
                        if (next.first < 0 || next.second < 0 || next.first >= n || next.second >= m)
                        {
                            continue;
                        }
                        if (grid[next.first][next.second] != ch) continue;
                        if (next == prev[pos.first][pos.second]) continue;
                        if (prev[next.first][next.second].first == -1)
                        {
                            prev[next.first][next.second] = pos;
                            search.push(next);
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

/// <summary>
/// Leet code #1568. Minimum Number of Days to Disconnect Island
/// </summary>
int LeetCodeGraph::minDays_CountIsland(vector<vector<int>> grid)
{
    int result = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0) continue;
            result++;
            queue<pair<int, int>> search;
            search.push(make_pair(i, j));
            while (!search.empty())
            {
                pair<int, int> pos = search.front();
                search.pop();
                for (size_t d = 0; d < directions.size(); d++)
                {
                    pair<int, int> next = pos;
                    next.first += directions[d].first;
                    next.second += directions[d].second;
                    if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m)
                    {
                        continue;
                    }
                    if (grid[next.first][next.second] == 0) continue;
                    grid[next.first][next.second] = 0;
                    search.push(next);
                }
            }
        }
    }
    return result;
}

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
int LeetCodeGraph::minDays(vector<vector<int>>& grid)
{
    if (minDays_CountIsland(grid) != 1) return 0;
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            grid[i][j] = 0;
            if (minDays_CountIsland(grid) != 1) return 1;
            grid[i][j] = 1;
        }
    }
    return 2;
}

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
int LeetCodeGraph::minCostConnectPoints(vector<vector<int>>& points)
{
    int n = points.size();
    priority_queue<pair<int, int>> pq;
    vector<int> visited(n);
    visited[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int distance =
            std::abs(points[0][0] - points[i][0]) +
            std::abs(points[0][1] - points[i][1]);
        pair<int, int> edge = { -distance, i };
        pq.push(edge);
    }
    int count = n - 1;
    int result = 0;
    while (!pq.empty() && count > 0)
    {
        pair<int, int> edge = pq.top();
        pq.pop();
        int a = edge.second;
        if (visited[a] == 1) continue;
        result -= edge.first;
        visited[a] = 1;
        count--;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1) continue;
            int distance =
                std::abs(points[a][0] - points[i][0]) +
                std::abs(points[a][1] - points[i][1]);
            pair<int, int> edge = { -distance, i };
            pq.push(edge);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1579. Remove Max Number of Edges to Keep Graph Fully 
///                  Traversable
/// </summary>
int LeetCodeGraph::maxNumEdgesToRemove(vector<vector<int>>& edges, vector<int>& parent, int& count, int id)
{
    int result = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (edges[i][0] == id)
        {
            int a = edges[i][1] - 1;
            int b = edges[i][2] - 1;
            while (parent[a] != a)
            {
                parent[a] = parent[parent[a]];
                a = parent[a];
            }
            while (parent[b] != b)
            {
                parent[b] = parent[parent[b]];
                b = parent[b];
            }
            if (a == b) result++;
            else
            {
                parent[a] = b;
                count++;
            }
        }
    }
    return result;
}

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
int LeetCodeGraph::countRoutes(vector<int>& locations, int start, int finish, int fuel)
{
    int M = 1000000007;
    int n = locations.size();
    vector<pair<int, int>> positions(n);
    for (size_t i = 0; i < locations.size(); i++)
    {
        positions[i] = make_pair(locations[i], i);
    }
    sort(positions.begin(), positions.end());
    vector<vector<int>> stops(fuel + 1, vector<int>(n));
    stops[fuel][start] = 1;
    int result = 0;
    for (int i = fuel; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (stops[i][j] == 0) continue;
            if (j == finish) result = (result + stops[i][j]) % M;
            int first = lower_bound(positions.begin(), positions.end(), make_pair(locations[j] - i, 0)) - positions.begin();
            int last = upper_bound(positions.begin(), positions.end(), make_pair(locations[j] + i, n)) - positions.begin();
            for (int k = first; k < last; k++)
            {
                // can not stat at same place
                if (positions[k].second == j) continue;
                int new_fuel = (i - abs(positions[k].first - locations[j]));
                // can not move too far
                if (abs(positions[k].first - locations[finish]) > new_fuel) continue;
                stops[new_fuel][positions[k].second] = (stops[new_fuel][positions[k].second] + stops[i][j]) % M;
            }
        }
    }
    return result;
}


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
bool LeetCodeGraph::isPrintable(vector<vector<int>>& targetGrid)
{
    vector<vector<int>> areas(60, {INT_MAX, INT_MIN, INT_MAX, INT_MIN});
    vector<unordered_set<int>> covers(60);
    for (int i = 0; i < (int)targetGrid.size(); i++)
    {
        for (int j = 0; j < (int)targetGrid[i].size(); j++)
        {
            int color = targetGrid[i][j] - 1;
            areas[color][0] = min(areas[color][0], i);
            areas[color][1] = max(areas[color][1], i);
            areas[color][2] = min(areas[color][2], j);
            areas[color][3] = max(areas[color][3], j);
        }
    }
    queue<int> search;
    for (int i = 0; i < 60; i++)
    {
        if (areas[i][0] == INT_MAX) continue;
        for (int j = areas[i][0]; j <= areas[i][1]; j++)
        {
            for (int k = areas[i][2]; k <= areas[i][3]; k++)
            {
                int color = targetGrid[j][k] - 1;
                if (i != color) covers[i].insert(color);
            }
        }
        if (covers[i].empty()) search.push(i);
    }
    while (!search.empty())
    {
        int color = search.front();
        search.pop();
        for (int i = 0; i < 60; i++)
        {
            if (covers[i].count(color) > 0)
            {
                covers[i].erase(color);
                if (covers[i].empty()) search.push(i);
            }
        }
    }

    for (int i = 0; i < 60; i++)
    {
        if (!covers[i].empty()) return false;
    }
    return true;
}
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
int LeetCodeGraph::maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
{
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    int result = 0;
    int e3 = 0;
    result = maxNumEdgesToRemove(edges, parent, e3, 3);
    vector<int> parent1 = parent;
    int e1 = 0;
    result += maxNumEdgesToRemove(edges, parent1, e1, 1);
    vector<int> parent2 = parent;
    int e2 = 0;
    result += maxNumEdgesToRemove(edges, parent2, e2, 2);
    if (e1 + e3 == n - 1 && e2 + e3 == n - 1) return result;
    else return -1;
}

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
int LeetCodeGraph::maximalNetworkRank(int n, vector<vector<int>>& roads)
{
    vector<vector<int>> net(n, vector<int>(n));
    vector<int> connections(n);
    for (size_t i = 0; i < roads.size(); i++)
    {
        net[roads[i][0]][roads[i][1]] = 1;
        net[roads[i][1]][roads[i][0]] = 1;
        connections[roads[i][0]]++;
        connections[roads[i][1]]++;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int count = connections[i] + connections[j];
            if (net[i][j] == 1) count--;
            result = max(result, count);
        }
    }
    return result;
}

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
vector<int> LeetCodeGraph::countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> connected(n);
    vector<int> result(n-1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        connected[edges[i][0] - 1].push_back(edges[i][1] - 1);
        connected[edges[i][1] - 1].push_back(edges[i][0] - 1);
    }
    int num = 1 << n;
    for (int i = 0; i < num; i++)
    {
        int max_dist = 0;
        for (int j = 0; j < n; j++)
        {
            queue<int> queue;
            int visited = 1 << j;
            if (((1 << j) & i) == 0) continue;
            queue.push(j);
            int dist = -1;
            while (!queue.empty())
            {
                dist++;
                int size = queue.size();
                for (int s = 0; s < size; s++)
                {
                    int node = queue.front();
                    queue.pop();
                    for (size_t k = 0; k < connected[node].size(); k++)
                    {
                        if (((1 << connected[node][k]) & i) == 0) continue;
                        if (((1 << connected[node][k]) & visited) != 0) continue;
                        queue.push(connected[node][k]);
                        visited = visited | (1 << connected[node][k]);
                    }
                }
            }
            if (i != visited)
            {
                max_dist = 0;
                break;
            }
            else
            {
                max_dist = max(max_dist, dist);
            }
        }
        if (max_dist > 0)
        {
            result[max_dist - 1]++;
        }
    }
    return result;
}


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
vector<bool> LeetCodeGraph::areConnected(int n, int threshold, vector<vector<int>>& queries)
{
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;

    for (int i = threshold + 1; i <= n ; i++)
    {
        if (parent[i] != i) continue;
        for (int j = i; j <= n; j+=i)
        {
            while (parent[i] != parent[parent[i]])
            {
                parent[i] = parent[parent[i]];
            }
            while (parent[j] != parent[parent[j]])
            {
                parent[j] = parent[parent[j]];
            }
            if (parent[i] < parent[j])
            {
                parent[parent[j]] = parent[i];
            }
            else
            {
                parent[parent[i]] = parent[j];
            }
        }
    }
    vector<bool> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        while (parent[a] != parent[parent[a]]) parent[a] = parent[parent[a]];
        while (parent[b] != parent[parent[b]]) parent[b] = parent[parent[b]];
        if (parent[a] == parent[b]) result[i] = true;
        else result[i] = false;
    }
    return result;
}

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
int LeetCodeGraph::minimumEffortPath(vector<vector<int>>& heights)
{
    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>> pq;
    effort[0][0] = 0;
    pq.push({ 0, 0, 0 });
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!pq.empty())
    {
        vector<int> node = pq.top();
        pq.pop();
        int r = node[1];
        int c = node[2];
        if (r == n - 1 && c == m - 1) break;
        if (0 - node[0] > effort[r][c]) continue;
        for (size_t d = 0; d < directions.size(); d++)
        {
            int next_r = r + directions[d][0];
            int next_c = c + directions[d][1];
            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m)
            {
                continue;
            }
            int gap = abs(heights[next_r][next_c] - heights[r][c]);
            gap = max(gap, effort[r][c]);
            if (gap < effort[next_r][next_c])
            {
                effort[next_r][next_c] = gap;
                pq.push({ -gap, next_r, next_c});
            }
        } 
    }
    return effort[n - 1][m - 1];
}

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
int LeetCodeGraph::minimumJumps(vector<int>& forbidden, int a, int b, int x)
{
    // if you just beyond 4000, should be able to jump back on non-forbidden
    // test case f = [1998], a = 1999, b = 2000, x = 2000
    vector<vector<int>> visited(6000, vector<int>(2));
    for (size_t i = 0; i < forbidden.size(); i++)
    {
        visited[forbidden[i]][0] = 1;
        visited[forbidden[i]][1] = 1;
    }
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    visited[0][0] = 1;
    visited[0][1] = 1;
    int result = 0;
    while (!queue.empty())
    {
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = queue.front();
            queue.pop();
            if (pos.first == x) return result;
            int next = pos.first + a;
            if (next < 6000)
            {
                if (visited[next][0] == 0)
                {
                    visited[next][0] = 1;
                    queue.push(make_pair(next, 0));
                }
            }
            if (pos.second == 0)
            {
                next = pos.first - b;
                if (next > 0)
                {
                    if (visited[next][1] == 0)
                    {
                        visited[next][1] = 1;
                        queue.push(make_pair(next, 1));
                    }
                }
            }
        }
        result++;
    }
    return -1;
}

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
vector<bool> LeetCodeGraph::distanceLimitedPathsExist(int n, 
    vector<vector<int>>& edgeList, vector<vector<int>>& queries)
{
    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    vector<vector<int>> queryList(queries.size(), vector<int>(2));
    // sort edge length
    for (size_t i = 0; i < edgeList.size(); i++)
    {
        swap(edgeList[i][0], edgeList[i][2]);
    }
    // sort query limit
    for (size_t i = 0; i < queries.size(); i++)
    {
        queryList[i][0] = queries[i][2];
        queryList[i][1] = i;
    }
    sort(edgeList.begin(), edgeList.end());
    sort(queryList.begin(), queryList.end());
    vector<bool> result(queries.size());
    size_t index = 0; 
    for (size_t i = 0; i < queryList.size(); i++)
    {
        while (index < edgeList.size() && edgeList[index][0] < queryList[i][0])
        {
            int a = edgeList[index][1];
            int b = edgeList[index][2];

            while (parent[parent[a]] != parent[a]) parent[a] = parent[parent[a]];
            while (parent[parent[b]] != parent[b]) parent[b] = parent[parent[b]];
            if (parent[a] != parent[b]) parent[parent[a]] = parent[parent[b]];
            index++;
        }
        int a = queries[queryList[i][1]][0];
        int b = queries[queryList[i][1]][1];
        while (parent[parent[a]] != parent[a]) parent[a] = parent[parent[a]];
        while (parent[parent[b]] != parent[b]) parent[b] = parent[parent[b]];
        if (parent[a] != parent[b]) result[queryList[i][1]] = false;
        else result[queryList[i][1]] = true;
    }
    for (size_t i = 0; i < edgeList.size(); i++)
    {
        swap(edgeList[i][0], edgeList[i][2]);
    }
    return result;
}

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
int LeetCodeGraph::minimumHammingDistance(vector<int>& source,
    vector<int>& target, vector<vector<int>>& allowedSwaps)
{
    vector<int> parent(source.size());
    for (size_t i = 0; i < parent.size(); i++) parent[i] = i;
    for (size_t i = 0; i < allowedSwaps.size(); i++)
    {
        int a = allowedSwaps[i][0];
        int b = allowedSwaps[i][1];
        while (parent[parent[a]] != parent[a]) parent[a] = parent[parent[a]];
        while (parent[parent[b]] != parent[b]) parent[b] = parent[parent[b]];
        parent[parent[a]]  = parent[parent[b]];
    }
    unordered_map<int, unordered_map<int, int>> exch_grp;
    for (size_t i = 0; i < source.size(); i++)
    {
        while (parent[parent[i]] != parent[i]) parent[i] = parent[parent[i]];
        exch_grp[parent[i]][source[i]]++;
    }

    int result = 0;
    for (size_t i = 0; i < target.size(); i++)
    {
        if (exch_grp[parent[i]].count(target[i]) > 0)
        {
            exch_grp[parent[i]][target[i]]--;
            if (exch_grp[parent[i]][target[i]] == 0)
            {
                exch_grp[parent[i]].erase(target[i]);
            }
        }
        else
        {
            result++;
        }
    }
    return result;
}

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
/// 1. 1 <= pairs.length <= 10^5
/// 2. 1 <= xi < yi <= 500
/// 3. The elements in pairs are unique.
/// </summary>
int LeetCodeGraph::checkWays(vector<vector<int>>& pairs)
{
    unordered_map<int, unordered_set<int>> neighbors;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        neighbors[pairs[i][0]].emplace(pairs[i][1]);
        neighbors[pairs[i][1]].emplace(pairs[i][0]);
    }
    priority_queue<pair<int, int>> pq;
    for (auto& itr : neighbors)
    {
        pq.push(make_pair(itr.second.size(), itr.first));
    }

    int result = 1;
    unordered_set<int> parents;
    while (!pq.empty())
    {
        pair<int, int> pair = pq.top();
        pq.pop();
        // root
        if (parents.empty())
        {
            if (pair.first != neighbors.size() - 1)
            {
                return 0;
            }
        }
        else
        {
            int parent = 0;
            int degree = neighbors.size();
            // select the smallest degree of my ancestors, 
            // it is my direct parent
            for (auto peer : neighbors[pair.second])
            {
                if (parents.count(peer) && (int)neighbors[peer].size() < degree)
                {
                    parent = peer;
                    degree = neighbors[peer].size();
                }
            }

            // verify my children are also my parent grand children
            for (auto peer : neighbors[pair.second])
            {
                if (peer != parent && neighbors[parent].count(peer) == 0)
                {
                    return 0;
                }
            }
            // my parent and me have same number of children, so we can exchange
            if (neighbors[parent].size() == neighbors[pair.second].size())
            {
                result = 2;
            }
        }
        parents.emplace(pair.second);
    }
    return result;
}

/// <summary>
/// Leet code 1730. Shortest Path to Get Food
/// 
/// Medium
/// 
/// You are starving and you want to eat food as quickly as possible. 
/// You want to find the shortest path to arrive at any food cell.
///
/// You are given an m x n character matrix, grid, of these different 
/// types of cells:
///
/// '*' is your location. There is exactly one '*' cell.
/// '#' is a food cell. There may be multiple food cells.
/// 'O' is free space, and you can travel through these cells.
/// 'X' is an obstacle, and you cannot travel through these cells.
/// You can travel to any adjacent cell north, east, south, or west of 
/// your current location if there is not an obstacle.
///
/// Return the length of the shortest path for you to reach any food cell. 
/// If there is no path for you to reach food, return -1.
/// Example 1:
/// Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"]
/// ,["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
/// Output: 3
/// Explanation: It takes 3 steps to reach the food.
///
/// Example 2:
/// Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],
/// ["X","O","X","#","X"],["X","X","X","X","X"]]
/// Output: -1
/// Explanation: It is not possible to reach the food.
///
/// Example 3:
/// Input: grid =
/// [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],
/// ["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],
/// ["X","X","X","X","X","X","X","X"]]
/// Output: 6
/// Explanation: There can be multiple food cells. It only takes 6 
/// steps to reach the bottom food.
///
/// Example 4:
/// Input: grid = [["O","*"],["#","O"]]
/// Output: 2
///
/// Example 5:
/// Input: grid = [["X","*"],["#","X"]]
/// Output: -1
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 200
/// 4. grid[row][col] is '*', 'X', 'O', or '#'.
/// 5. The grid contains exactly one '*'.
/// </summary>
int LeetCodeGraph::getFood(vector<vector<char>>& grid)
{
    vector<int> pos = { -1, -1 };
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                pos = { i, j };
                break;
            }
        }
        if (pos[0] != -1) break;
    }
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    queue<vector<int>> queue;
    visited[pos[0]][pos[1]] = 1;
    queue.push(pos);
    int result = 0;
    while (!queue.empty())
    {
        result++;
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            pos = queue.front();
            queue.pop();
            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = pos;
                next[0] += directions[d][0];
                next[1] += directions[d][1];
                if (next[0] < 0 || next[0] >= m ||
                    next[1] < 0 || next[1] >= n) continue;
                if (grid[next[0]][next[1]] == 'X') continue;
                if (visited[next[0]][next[1]] == 1) continue;
                if (grid[next[0]][next[1]] == '#')
                {
                    return result;
                }
                visited[next[0]][next[1]] = 1;
                queue.push(next);
            }
        }
    }
    return -1;
}

/// <summary>
/// Leet code 1743. Restore the Array From Adjacent Pairs
/// 
/// Medium
/// 
/// There is an integer array nums that consists of n unique elements, 
/// but you have forgotten it. However, you do remember every pair of 
/// adjacent elements in nums.
///
/// You are given a 2D integer array adjacentPairs of size n - 1 where 
/// each adjacentPairs[i] = [ui, vi] indicates that the elements ui and 
/// vi are adjacent in nums.
///
/// It is guaranteed that every adjacent pair of elements nums[i] and 
/// nums[i+1] will exist in adjacentPairs, either as [nums[i], 
/// nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.
///
/// Return the original array nums. If there are multiple solutions, 
/// return any of them.
/// 
/// Example 1:
/// Input: adjacentPairs = [[2,1],[3,4],[3,2]]
/// Output: [1,2,3,4]
/// Explanation: This array has all its adjacent pairs in adjacentPairs.
/// Notice that adjacentPairs[i] may not be in left-to-right order.
///
/// Example 2:
/// Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
/// Output: [-2,4,1,-3]
/// Explanation: There can be negative numbers.
/// Another solution is [-3,1,4,-2], which would also be accepted.
///
/// Example 3:
/// Input: adjacentPairs = [[100000,-100000]]
/// Output: [100000,-100000]
///  
/// Constraints:
/// 1. nums.length == n
/// 2. adjacentPairs.length == n - 1
/// 3. adjacentPairs[i].length == 2
/// 4. 2 <= n <= 10^5
/// 5. -10^5 <= nums[i], ui, vi <= 10^5
/// 6. There exists some nums that has adjacentPairs as its pairs.
/// </summary>
vector<int> LeetCodeGraph::restoreArray(vector<vector<int>>& adjacentPairs)
{
    unordered_set<int> head;
    unordered_map<int, unordered_set<int>> adjacent;

    for (size_t i = 0; i < adjacentPairs.size(); i++)
    {
        int a = adjacentPairs[i][0];
        int b = adjacentPairs[i][1];
        if (head.count(a) > 0) head.erase(a);
        else head.insert(a);
        if (head.count(b) > 0) head.erase(b);
        else head.insert(b);
        adjacent[a].insert(b);
        adjacent[b].insert(a);
    }
    vector<int> result;
    int start = *head.begin();
    result.push_back(start); 
    while (!adjacent.empty())
    {
        int next = *adjacent[start].begin();
        adjacent[next].erase(start);
        if (adjacent[next].empty()) adjacent.erase(next);
        adjacent.erase(start);
        start = next;
        result.push_back(start);
    }
    return result;
}

/// <summary>
/// Leet code 1765. Map of Highest Peak
/// 
/// Medium
/// 
/// You are given an integer matrix isWater of size m x n that represents 
/// a map of land and water cells.
///
/// If isWater[i][j] == 0, cell (i, j) is a land cell.
/// If isWater[i][j] == 1, cell (i, j) is a water cell.
/// You must assign each cell a height in a way that follows these rules:
///
/// The height of each cell must be non-negative.
/// If the cell is a water cell, its height must be 0.
/// Any two adjacent cells must have an absolute height difference of at 
/// most 1. A cell is adjacent to another cell if the former is directly 
/// north, east, south, or west of the latter (i.e., their sides are 
/// touching).
/// Find an assignment of heights such that the maximum height in the 
/// matrix is maximized.
///
/// Return an integer matrix height of size m x n where height[i][j] is 
/// cell (i, j)'s height. If there are multiple solutions, return any of 
/// them.
/// 
/// Example 1:
/// Input: isWater = [[0,1],[0,0]]
/// Output: [[1,0],[2,1]]
/// Explanation: The image shows the assigned heights of each cell.
/// The blue cell is the water cell, and the green cells are the land 
/// cells.
///
/// Example 2:
/// Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
/// Output: [[1,1,0],[0,1,1],[1,2,2]]
/// Explanation: A height of 2 is the maximum possible height of any 
/// assignment.
/// Any height assignment that has a maximum height of 2 while still meeting 
/// the rules will also be accepted.
///
/// Constraints:
/// 1. m == isWater.length
/// 2. n == isWater[i].length
/// 3. 1 <= m, n <= 1000
/// 4. isWater[i][j] is 0 or 1.
/// 5. There is at least one water cell.
/// </summary>
vector<vector<int>> LeetCodeGraph::highestPeak(vector<vector<int>>& isWater)
{
    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>> result(n, vector<int>(m, INT_MAX));

    queue<pair<int, int>> queue;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isWater[i][j] == 1)
            {
                result[i][j] = 0;
                queue.push(make_pair(i, j));
            }
        }
    }
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!queue.empty())
    {
        pair<int, int> pos = queue.front();
        queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            pair<int, int> next = pos;
            next.first += directions[i][0];
            next.second += directions[i][1];
            if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m)
            {
                continue;
            }
            if (result[next.first][next.second] != INT_MAX) continue;
            result[next.first][next.second] = result[pos.first][pos.second] + 1;
            queue.push(next);
        }
    }
    return result;
}

/// <summary>
/// Leet code 1786. Number of Restricted Paths From First to Last Node
/// 
/// Medium
/// 
/// There is an undirected weighted connected graph. You are given a 
/// positive integer n which denotes that the graph has n nodes 
/// labeled from 1 to n, and an array edges where each edges[i] = 
/// [ui, vi, weighti] denotes that there is an edge between nodes ui 
/// and vi with weight equal to weighti.
///
/// A path from node start to node end is a sequence of nodes 
/// [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is 
/// an edge between zi and zi+1 where 0 <= i <= k-1.
///
/// The distance of a path is the sum of the weights on the edges of the 
/// path. Let distanceToLastNode(x) denote the shortest distance of a path 
/// between node n and node x. A restricted path is a path that also 
/// satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) 
/// where 0 <= i <= k-1.
///
/// Return the number of restricted paths from node 1 to node n. Since 
/// that number may be too large, return it modulo 10^9 + 7.
///
/// Example 1:
/// 1. Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],
///    [3,5,1],[5,4,10]]
/// Output: 3
/// Explanation: Each circle contains the node number in black and 
/// its distanceToLastNode value in blue. The three restricted paths are:
/// 1) 1 --> 2 --> 5
/// 2) 1 --> 2 --> 3 --> 5
/// 3) 1 --> 3 --> 5
///
/// Example 2:
/// Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],
/// [5,6,1],[6,7,2],[7,5,3],[2,6,4]]
/// Output: 1
/// Explanation: Each circle contains the node number in black and its 
/// distanceToLastNode value in blue. The only restricted path 
/// is 1 --> 3 --> 7.
///     
/// Constraints:
/// 1. 1 <= n <= 2 * 10^4
/// 2. n - 1 <= edges.length <= 4 * 10^4
/// 3. edges[i].length == 3
/// 4. 1 <= ui, vi <= n
/// 5. ui != vi
/// 6. 1 <= weighti <= 10^5
/// 7. There is at most one edge between any two nodes.
/// 8. There is at least one path between any two nodes.
/// </summary>
int LeetCodeGraph::countRestrictedPaths(int n, vector<vector<int>>& edges)
{
    unordered_map<int, unordered_map<int, int>> neighbours;
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbours[edges[i][0]][edges[i][1]] = edges[i][2];
        neighbours[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    unordered_map<int, int> shortest_path;
    for (int i = 1; i <= n; i++) shortest_path[i] = INT_MAX;
    priority_queue<pair<int, int>> pq;
    shortest_path[n] = 0;
    pq.push(make_pair(0, n));
    while (!pq.empty())
    {
        pair<int, int> pos = pq.top();
        pq.pop();
        int distance = 0 - pos.first;
        if (distance > shortest_path[pos.second]) continue;
        for (auto next : neighbours[pos.second])
        {
            if (next.second + distance < shortest_path[next.first])
            {
                pq.push(make_pair(0 - (next.second + distance), next.first));
                shortest_path[next.first] = next.second + distance;
            }
        }
    }
    int M = 1000000007;
    vector<int> paths(n + 1);
    paths[n] = 1;
    for (auto itr : shortest_path)
    {
        pq.push(make_pair(0 - itr.second, itr.first));

    }
    while (!pq.empty())
    {
        pair<int, int> pos = pq.top();
        pq.pop();
        int distance = 0 - pos.first;
        for (auto next : neighbours[pos.second])
        {
            if (distance >= shortest_path[next.first]) continue;
            paths[next.first] = (paths[next.first] + paths[pos.second]) % M;
        }
    }
    return paths[1];
}


/// <summary>
/// Leet code 1782. Count Pairs Of Nodes
/// 
/// Hard
/// 
/// You are given an undirected graph represented by an integer n, 
/// which is the number of nodes, and edges, where edges[i] = [ui, vi] 
/// which indicates that there is an undirected edge between ui and vi. 
/// You are also given an integer array queries.
///
/// The answer to the jth query is the number of pairs of nodes (a, b) 
/// that satisfy the following conditions:
///
/// a < b
/// cnt is strictly greater than queries[j], where cnt is the number 
/// of edges incident to a or b.
/// Return an array answers such that answers.length == queries.length 
/// and answers[j] is the answer of the jth query.
/// 
/// Note that there can be repeated edges.
/// 
/// Example 1:
/// Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
/// Output: [6,5]
/// Explanation: The number of edges incident to at least one of each pair 
/// is shown above.
///
/// Example 2:
/// Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],
/// [2,3],[2,5]], queries = [1,2,3,4,5]
/// Output: [10,10,9,8,6]
/// 
/// Constraints:
/// 1. 2 <= n <= 2 * 10^4
/// 2. 1 <= edges.length <= 10^5
/// 3. 1 <= ui, vi <= n
/// 4. ui != vi
/// 5. 1 <= queries.length <= 20
/// 6. 0 <= queries[j] < edges.length
/// </summary>
vector<int> LeetCodeGraph::countPairs(int n, vector<vector<int>>& edges, vector<int>& queries)
{
    vector<int> cnt(n+1), sort_cnt(n+1);

    vector<unordered_map<int, int>>paths(n + 1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        cnt[edges[i][0]]++;
        cnt[edges[i][1]]++;
        sort_cnt[edges[i][0]]++;
        sort_cnt[edges[i][1]]++;
        if (edges[i][0] < edges[i][1]) paths[edges[i][0]][edges[i][1]] ++;
        else paths[edges[i][1]][edges[i][0]] ++;
    }
    sort(sort_cnt.begin(), sort_cnt.end());
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        int first = 1;
        int last = n;
        while (first < last)
        {
            if (sort_cnt[first] + sort_cnt[last] > queries[i])
            {
                result[i] += last - first;
                last--;
            }
            else
            {
                first++;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            for (auto itr : paths[j])
            {
                if (cnt[j] + cnt[itr.first] > queries[i] &&
                    cnt[j] + cnt[itr.first] - itr.second <= queries[i])
                {
                    result[i]--;
                }
            }
        }
    }
    return result;
}


/// <summary>
/// Leet code 1761. Minimum Degree of a Connected Trio in a Graph
/// 
/// Hard
/// 
/// You are given an undirected graph. You are given an integer n which 
/// is the number of nodes in the graph and an array edges, where each 
/// edges[i] = [ui, vi] indicates that there is an undirected edge 
/// between ui and vi.
///
/// A connected trio is a set of three nodes where there is an edge 
/// between every pair of them.
///
/// The degree of a connected trio is the number of edges where one 
/// endpoint is in the trio, and the other is not.
///
/// Return the minimum degree of a connected trio in the graph, or -1 
/// if the graph has no connected trios.
///
/// Example 1:
/// Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
/// Output: 3
/// Explanation: There is exactly one trio, which is [1,2,3]. The edges 
/// that form its degree are bolded in the figure above.
///
/// Example 2:
/// Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
/// Output: 0
/// Explanation: There are exactly three trios:
/// 1) [1,4,3] with degree 0.
/// 2) [2,5,6] with degree 2.
/// 3) [5,6,7] with degree 2.
/// 
/// Constraints:
/// 1. 2 <= n <= 400
/// 2. edges[i].length == 2
/// 3. 1 <= edges.length <= n * (n-1) / 2
/// 4. 1 <= ui, vi <= n
/// 5. ui != vi
/// 6. There are no repeated edges.
/// </summary>
int LeetCodeGraph::minTrioDegree(int n, vector<vector<int>>& edges)
{
    vector<unordered_set<int>> neighbours(n+1);
    vector<int> degree(n + 1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
        if (edges[i][0] < edges[i][1])
        {
            neighbours[edges[i][0]].insert(edges[i][1]);
        }
        else
        {
            neighbours[edges[i][1]].insert(edges[i][0]);
        }
    }
    int result = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        for (auto j : neighbours[i])
        {
            for (auto k : neighbours[j])
            {
                if (neighbours[i].count(k) > 0)
                {
                    result = min(degree[i] + degree[j] + degree[k] - 6, result);
                }
            }
        }
    }
    if (result == INT_MAX) result = -1;
    return result;
}

/// <summary>
/// Leet code 1791. Find Center of Star Graph
/// 
/// Medium
/// 
/// There is an undirected star graph consisting of n nodes labeled from 1 
/// to n. A star graph is a graph where there is one center node and 
/// exactly n - 1 edges that connect the center node with every other node.
///
/// You are given a 2D integer array edges where each edges[i] = [ui, vi] 
/// indicates that there is an edge between the nodes ui and vi. Return 
/// the center of the given star graph.
/// 
/// Example 1:
/// Input: edges = [[1,2],[2,3],[4,2]]
/// Output: 2
/// Explanation: As shown in the figure above, node 2 is connected to 
/// every other node, so 2 is the center.
///
/// Example 2:
/// Input: edges = [[1,2],[5,1],[1,3],[1,4]]
/// Output: 1
///
/// Constraints:
/// 1. 3 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 1 <= ui, vi <= n
/// 5. ui != vi
/// 6. The given edges represent a valid star graph.
/// </summary>
int LeetCodeGraph::findCenter(vector<vector<int>>& edges)
{
    unordered_map<int, int> nodes;
    int result = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        nodes[edges[i][0]]++;
        if (nodes[edges[i][0]] > 1)
        {
            result = edges[i][0];
            break;
        }
        nodes[edges[i][1]]++;
        if (nodes[edges[i][1]] > 1)
        {
            result = edges[i][1];
            break;
        }
    }
    if (result == 0) result = nodes.begin()->first;
    return result;
}

/// <summary>
/// Leet code 1820. Maximum Number of Accepted Invitations
/// </summary>
int LeetCodeGraph::maximumInvitations(int boy, vector<vector<int>>& invitations, vector<int>& match, vector<bool>& visited)
{
    for (int girl : invitations[boy])
    {
        if (visited[girl]) continue;
        visited[girl] = true;
        if (match[girl] == -1 || maximumInvitations(match[girl], invitations, match, visited) == 1)
        {
            match[girl] = boy;
            return 1;
        }
    }
    return 0;
}

/// <summary>
/// Leet code 1820. Maximum Number of Accepted Invitations
/// 
/// Medium
/// 
/// There are m boys and n girls in a class attending an upcoming party.
///
/// You are given an m x n integer matrix grid, where grid[i][j] 
/// equals 0 or 1. If grid[i][j] == 1, then that means the ith boy can 
/// invite the jth girl to the party. A boy can invite at most one girl, 
/// and a girl can accept at most one invitation from a boy.
///
/// Return the maximum possible number of accepted invitations.
/// Example 1:
/// Input: grid = [[1,1,1],
///                [1,0,1],
///                [0,0,1]] 
/// Output: 3
/// Explanation: The invitations are sent as follows:
/// - The 1st boy invites the 2nd girl.
/// - The 2nd boy invites the 1st girl.
/// - The 3rd boy invites the 3rd girl.
///
/// Example 2:
///
/// Input: grid = [[1,0,1,0],
///           [1,0,0,0],
///           [0,0,1,0],
///           [1,1,1,0]]
/// Output: 3
/// Explanation: The invitations are sent as follows:
/// -The 1st boy invites the 3rd girl.
/// -The 2nd boy invites the 1st girl.
/// -The 3rd boy invites no one.
/// -The 4th boy invites the 2nd girl.
///
/// Constraints:
/// 1. grid.length == m
/// 2. grid[i].length == n
/// 3. 1 <= m, n <= 200
/// 4. grid[i][j] is either 0 or 1.
///    calculateMKAverage.
/// </summary>
int LeetCodeGraph::maximumInvitations(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> match(n, -1);
    vector<vector<int>> invitations(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                invitations[i].push_back(j);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        vector<bool> visited(n);
        result += maximumInvitations(i, invitations, match, visited);
    }
    return result;
}

/// <summary>
/// Leet code 1857. Largest Color Value in a Directed Graph
/// 
/// Hard
/// 
/// There is a directed graph of n colored nodes and m edges. The nodes 
/// are numbered from 0 to n - 1.
///
/// You are given a string colors where colors[i] is a lowercase English 
/// letter representing the color of the ith node in this graph 
/// (0-indexed). You are also given a 2D array edges where edges[j] = 
/// [aj, bj] indicates that there is a directed edge from node aj to node 
/// bj.
///
/// A valid path in the graph is a sequence of nodes x1 -> x2 -> 
/// x3 -> ... -> xk such that there is a directed edge from xi to xi+1 
/// for every 1 <= i < k. The color value of the path is the number of 
/// nodes that are colored the most frequently occurring color along that 
/// path.
///
/// Return the largest color value of any valid path in the given graph, 
/// or -1 if the graph contains a cycle.
/// 
/// Example 1:
/// Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
/// Output: 3
/// Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are 
/// colored "a" (red in the above image).
///
/// Example 2:
/// Input: colors = "a", edges = [[0,0]]
/// Output: -1
/// Explanation: There is a cycle from 0 to 0.
///
/// Constraints:
/// 1. n == colors.length
/// 2. m == edges.length
/// 3. 1 <= n <= 10^5
/// 4. 0 <= m <= 10^5
/// 5. colors consists of lowercase English letters.
/// 6. 0 <= aj, bj < n
/// </summary>
int LeetCodeGraph::largestPathValue(string colors, vector<vector<int>>& edges)
{
    int n = colors.size();
    vector<vector<int>> neighbors(n);
    vector<vector<int>> max_colors(n, vector<int>(26));
    vector<int> degree(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        degree[edges[i][1]] ++;
    }
    queue<int> queue;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0) queue.push(i);
    }
    int result = 0;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        count++;
        max_colors[node][colors[node] - 'a']++;
        result = max(result, max_colors[node][colors[node] - 'a']);
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next = neighbors[node][i];
            degree[next]--;
            if (degree[next] == 0)
            {
                queue.push(next);
            }
            for (size_t j = 0; j < 26; j++)
            {
                max_colors[next][j] = max(max_colors[next][j], max_colors[node][j]);
            }
        }
    }
    if (count < n) return -1;
    else return result;
}


/// <summary>
/// Leet code 1928. Minimum Cost to Reach Destination in Time
///                                  
/// Hard
/// 
/// There is a country of n cities numbered from 0 to n - 1 where all the 
/// cities are connected by bi-directional roads. The roads are 
/// represented as a 2D integer array edges where edges[i] = [xi, yi, 
/// timei] denotes a road between cities xi and yi that takes timei 
/// minutes to travel. There may be multiple roads of differing travel 
/// times connecting the same two cities, but no road connects a city 
/// to itself.
/// Each time you pass through a city, you must pay a passing fee. 
/// This is represented as a 0-indexed integer array passingFees of 
/// length n where passingFees[j] is the amount of dollars you must 
/// pay when you pass through city j.
///
/// In the beginning, you are at city 0 and want to reach city n - 1 
/// in maxTime minutes or less. The cost of your journey is the 
/// summation of passing fees for each city that you passed through 
/// at some moment of your journey (including the source and 
/// destination cities).
///
/// Given maxTime, edges, and passingFees, return the minimum cost 
/// to complete your journey, or -1 if you cannot complete it 
/// within maxTime minutes.
///
/// Example 1:
/// Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],
/// [3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
/// Output: 11
/// Explanation: The path to take is 0 -> 1 -> 2 -> 5, which takes 30 
/// minutes and has $11 worth of passing fees.
///
/// Example 2:
/// Input: maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],
/// [3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
/// Output: 48
/// Explanation: The path to take is 0 -> 3 -> 4 -> 5, which takes 
/// 26 minutes and has $48 worth of passing fees.
/// You cannot take path 0 -> 1 -> 2 -> 5 since it would take too long.
///
/// Example 3:
/// Input: maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],
/// [3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
/// Output: -1
/// Explanation: There is no way to reach city 5 from city 0 within 
/// 25 minutes.
///  
/// Constraints:
/// 1. 1 <= maxTime <= 1000
/// 2. n == passingFees.length
/// 3. 2 <= n <= 1000
/// 4. n - 1 <= edges.length <= 1000
/// 5. 0 <= xi, yi <= n - 1
/// 6. 1 <= timei <= 1000
/// 7. 1 <= passingFees[j] <= 1000 
/// 8. The graph may contain multiple edges between two nodes.
/// 9. The graph does not contain self loops.
/// </summary>
int LeetCodeGraph::minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees)
{
    int n = passingFees.size();
    vector <vector<pair<int, int>>> adjacent(n, vector<pair<int, int>>());
    vector<int> city_cost(n, { INT_MAX });
    vector<int> city_time(n, { INT_MAX });
    for (size_t i = 0; i < edges.size(); i++)
    {
        adjacent[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
        adjacent[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
    }
    set<vector<int>> pq;
    pq.insert({ passingFees[0], 0, 0 });
    while (!pq.empty())
    {
        vector<int> destination = *pq.begin();
        pq.erase(pq.begin());
        int cost = destination[0];
        int time = destination[1];
        int city = destination[2];
        if (city == n - 1) return cost;
        for (size_t i = 0; i < adjacent[city].size(); i++)
        {
            int next_city = adjacent[city][i].first;
            int next_cost = cost + passingFees[next_city];
            int next_time = time + adjacent[city][i].second;
            if (next_time > maxTime) continue;
            if (city_cost[next_city] <= next_cost && city_time[next_city] <= next_time)
            {
                continue;
            }
            city_cost[next_city] = min(city_cost[next_city], next_cost);
            city_time[next_city] = min(city_time[next_city], next_time);
            pq.insert({ next_cost, next_time, next_city });
        }
    }
    return -1;
}

/// <summary>
/// Leet code 1952. Three Divisors
///                                                
/// Medium
/// 
/// A peak element in a 2D grid is an element that is strictly greater 
/// than all of its adjacent neighbors to the left, right, top, and bottom.
///
/// Given a 0-indexed m x n matrix mat where no two adjacent cells are 
/// equal, find any peak element mat[i][j] and return the length 2 
/// array [i,j].
///
/// You may assume that the entire matrix is surrounded by an outer 
/// perimeter with the value -1 in each cell.
///
/// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) 
/// time.
/// 
/// Example 1:
/// Input: mat = [[1,4],[3,2]]
/// Output: [0,1]
/// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are 
/// both acceptable answers.
///
/// Example 2:
/// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
/// Output: [1,1]
/// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] 
/// are both acceptable answers.
///
/// Constraints:
/// 1. m == mat.length
/// 2. n == mat[i].length
/// 3. 1 <= m, n <= 500
/// 4. 1 <= mat[i][j] <= 10^5
/// 5. No two adjacent cells are equal.
/// </summary>
vector<int> LeetCodeGraph::findPeakGrid(vector<vector<int>>& mat)
{
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector<int> peak = { 0, 0 };
    queue<vector<int>> pq;
    pq.push(peak);
    while (!pq.empty())
    {
        vector<int> curr = pq.front();
        pq.pop();
        peak = curr;
        for (size_t d = 0; d < directions.size(); d++)
        {
            vector<int> next = curr;
            next[0] += directions[d][0];
            next[1] += directions[d][1];

            if (next[0] < 0 || next[0] >= (int)mat.size() ||
                next[1] < 0 || next[1] >= (int)mat[0].size())
            {
                continue;
            }
            if (mat[next[0]][next[1]] > mat[peak[0]][peak[1]])
            {
                peak = next;
            }
        }
        if (peak == curr) break;
        pq.push(peak);
    }
    return peak;
}

/// <summary>
/// Leet code 1905. Count Sub Islands
///                                                
/// Medium
/// 
/// You are given two m x n binary matrices grid1 and grid2 containing 
/// only 0's (representing water) and 1's (representing land). An 
/// island is a group of 1's connected 4-directionally (horizontal or 
/// vertical). Any cells outside of the grid are considered water cells.
///
/// An island in grid2 is considered a sub-island if there is an island 
/// in grid1 that contains all the cells that make up this island in grid2.
/// 
/// Return the number of islands in grid2 that are considered sub-islands.
///
/// Example 1:
/// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],
/// [1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],
/// [0,1,0,1,0]]
/// Output: 3
/// Explanation: In the picture above, the grid on the left is grid1 and 
/// the grid on the right is grid2.
/// The 1s colored red in grid2 are those considered to be part of a 
/// sub-island. There are three sub-islands.
///
/// Example 2:
/// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],
/// [1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],
/// [1,0,0,0,1]]
/// Output: 2 
/// Explanation: In the picture above, the grid on the left is grid1 and 
/// the grid on the right is grid2.
/// The 1s colored red in grid2 are those considered to be part of a 
/// sub-island. There are two sub-islands.
///
/// Constraints:
/// 1. m == grid1.length == grid2.length
/// 2. n == grid1[i].length == grid2[i].length
/// 3. 1 <= m, n <= 500
/// 4. grid1[i][j] and grid2[i][j] are either 0 or 1.
/// </summary>
int LeetCodeGraph::countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
{
    vector<vector<int>> grid = grid2;
    int n = grid1.size();
    int m = grid1[0].size();
    int result = 0;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0) continue;
            queue<pair<int, int>> queue;
            queue.push(make_pair(i, j));
            int count = 1;
            while (!queue.empty())
            {
                pair<int, int> pos = queue.front();
                queue.pop();
                if (grid1[pos.first][pos.second] == 0) count = 0;
                for (size_t d = 0; d < directions.size(); d++)
                {
                    pair<int, int> next = pos;
                    next.first += directions[d][0];
                    next.second += directions[d][1];
                    if (next.first < 0 || next.first >= n ||
                        next.second < 0 || next.second >= m)
                    {
                        continue;
                    }
                    if (grid[next.first][next.second] == 1)
                    {
                        grid[next.first][next.second] = 0;
                        queue.push(next);
                    }
                }
            }
            result += count;
        }
    }
    return result;
}


/// <summary>
/// Leet code 1926. Nearest Exit from Entrance in Maze
///                                                                 
/// Medium
/// 
/// You are given an m x n matrix maze (0-indexed) with empty cells 
/// (represented as '.') and walls (represented as '+'). You are also 
/// given the entrance of the maze, where entrance = [entrancerow, 
/// entrancecol] denotes the row and column of the cell you are 
/// initially standing at.
///
/// In one step, you can move one cell up, down, left, or right. You 
/// cannot step into a cell with a wall, and you cannot step outside 
/// the maze. Your goal is to find the nearest exit from the entrance. 
/// An exit is defined as an empty cell that is at the border of the 
/// maze. The entrance does not count as an exit.
/// 
/// Return the number of steps in the shortest path from the 
/// entrance to the nearest exit, or -1 if no such path exists.
/// 
/// Example 1:
/// Input: maze = [["+","+",".","+"],[".",".",".","+"],
/// ["+","+","+","."]], entrance = [1,2]
/// Output: 1
/// Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
/// Initially, you are at the entrance cell [1,2].
/// - You can reach [1,0] by moving 2 steps left.
/// - You can reach [0,2] by moving 1 step up.
/// It is impossible to reach [2,3] from the entrance.
/// Thus, the nearest exit is [0,2], which is 1 step away.
///
/// Example 2:
/// Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], 
/// entrance = [1,0]
/// Output: 2
/// Explanation: There is 1 exit in this maze at [1,2].
/// [1,0] does not count as an exit since it is the entrance cell.
/// Initially, you are at the entrance cell [1,0].
/// - You can reach [1,2] by moving 2 steps right.
/// Thus, the nearest exit is [1,2], which is 2 steps away.
///
/// Example 3:
/// Input: maze = [[".","+"]], entrance = [0,0]
/// Output: -1
/// Explanation: There are no exits in this maze.
///
/// Constraints:
/// 1. maze.length == m
/// 2. maze[i].length == n
/// 3. 1 <= m, n <= 100
/// 4. maze[i][j] is either '.' or '+'.
/// 5. entrance.length == 2
/// 6. 0 <= entrancerow < m
/// 7. 0 <= entrancecol < n
/// 8. entrance will always be an empty cell.
/// </summary>
int LeetCodeGraph::nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
{
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> visited(m, vector<int>(n));

    queue<vector<int>> queue;
    queue.push(entrance);
    visited[entrance[0]][entrance[1]] = 1;

    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int result = 0;
    while (!queue.empty())
    {
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            vector<int> pos = queue.front();
            queue.pop();

            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = pos;
                next[0] += directions[d][0];
                next[1] += directions[d][1];
                if (next[0] < 0 || next[0] >= m || next[1] < 0 || next[1] >= n)
                {
                    if (result > 0) return result;
                    else continue;
                }
                if (visited[next[0]][next[1]] == 1) continue;
                if (maze[next[0]][next[1]] == '+') continue;
                visited[next[0]][next[1]] = 1;
                queue.push(next);
            }
        }
        result++;
    }
    return -1;
}

/// <summary>
/// Leet code 1970. Last Day Where You Can Still Cross
///                                                                 
/// Hard
/// 
/// There is a 1-based binary matrix where 0 represents land and 1 
/// represents water. You are given integers row and col representing 
/// the number of rows and columns in the matrix, respectively.
///
/// Initially on day 0, the entire matrix is land. However, each day a 
/// new cell becomes flooded with water. You are given a 1-based 2D 
/// array cells, where cells[i] = [ri, ci] represents that on the ith 
/// day, the cell on the rith row and cith column (1-based coordinates) 
/// will be covered with water (i.e., changed to 1).
///
/// You want to find the last day that it is possible to walk from the 
/// top to the bottom by only walking on land cells. You can start from 
/// any cell in the top row and end at any cell in the bottom row. You 
/// can only travel in the four cardinal directions (left, right, up, 
/// and down).
///
/// Return the last day where it is possible to walk from the top to 
/// the bottom by only walking on land cells.
/// 
/// Example 1:
/// Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
/// Output: 2
/// Explanation: The above image depicts how the matrix changes each day 
/// starting from day 0.
/// The last day where it is possible to cross from top to bottom is on 
/// day 2.
///
/// Example 2:
/// Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
/// Output: 1
/// Explanation: The above image depicts how the matrix changes each day 
/// starting from day 0.
/// The last day where it is possible to cross from top to bottom is on 
/// day 1.
///
/// Example 3:
/// Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],
/// [1,3],[2,3],[3,2],[3,1]]
/// Output: 3
/// Explanation: The above image depicts how the matrix changes each day 
/// starting from day 0.
/// The last day where it is possible to cross from top to bottom is on day 3.
///	
/// Constraints:
/// 1. 2 <= row, col <= 2 * 10^4
/// 2. 4 <= row * col <= 2 * 10^4
/// 3. cells.length == row * col
/// 4. 1 <= ri <= row
/// 5. 1 <= ci <= col
/// 6. All the values of cells are unique.
/// </summary>
int LeetCodeGraph::latestDayToCross(int row, int col, vector<vector<int>>& cells)
{
    int n = row * col;
    vector<int> parent(n);
    vector<pair<int, int>> range(n);
    vector<vector<int>> grid(row, vector<int>(col));
    for (int i = 0; i < n; i++) parent[i] = i;
    for (size_t i = 0; i < cells.size(); i++)
    {
        grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        range[i].first = range[i].second = i / col;
    }

    queue<int> queue;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = cells.size() - 1; i >= 0; i--)
    {
        int r = cells[i][0] - 1;
        int c = cells[i][1] - 1;
        grid[r][c] = 2;
        queue.push(r * col + c);
        for (int d = 0; d < 4; d++)
        {
            int next_r = r + directions[d][0];
            int next_c = c + directions[d][1];
            if (next_r < 0 || next_r == row || next_c < 0 || next_c == col)
            {
                continue;
            }
            if (grid[next_r][next_c] != 2)
            {
                continue;
            }
            queue.push(next_r * col + next_c);
        }

        int x = -1;
        while (!queue.empty())
        {
             int y = queue.front();
             queue.pop();
             if (x != -1)
             {
                 while (parent[parent[x]] != parent[x]) parent[x] = parent[parent[x]];
                 while (parent[parent[y]] != parent[y]) parent[y] = parent[parent[y]];
                 x = parent[x];
                 y = parent[y];
                 if (x != y)
                 {
                     range[y].first = min(range[x].first, range[y].first);
                     range[y].second = max(range[x].second, range[y].second);
                     parent[x] = y;
                     if ((range[y].first == 0) && (range[y].second == row - 1))
                     {
                         return i;
                     }
                 }
             }
             x = y;
        }
    }
    return 0;
}

/// <summary>
/// Leet code 1998. GCD Sort of an Array
///                                                                 
/// Hard
/// 
/// You are given an integer array nums, and you can perform the following 
/// operation any number of times on nums:
///
/// Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], 
/// nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common 
/// divisor of nums[i] and nums[j].
/// Return true if it is possible to sort nums in non-decreasing order 
/// using the above swap method, or false otherwise.
/// 
/// Example 1:
///  
/// Input: nums = [7,21,3]
/// Output: true
/// Explanation: We can sort [7,21,3] by performing the following 
/// operations:
/// - Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
/// - Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
///
/// Example 2:
/// Input: nums = [5,2,6,2]
/// Output: false
/// Explanation: It is impossible to sort the array because 5 cannot 
/// be swapped with any other element.
///
/// Example 3:
/// Input: nums = [10,5,9,3,15]
/// Output: true
/// We can sort [10,5,9,3,15] by performing the following operations:
/// - Swap 10 and 15 because gcd(10,15) = 5. nums = [15,5,9,3,10]
/// - Swap 15 and 3 because gcd(15,3) = 3. nums = [3,5,9,15,10]
/// - Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,10,15]
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 3 * 10^4
/// 2. 2 <= nums[i] <= 10^5
/// </summary>
bool LeetCodeGraph::gcdSort(vector<int>& nums)
{
    int n = *max_element(nums.begin(), nums.end()) + 1;
    vector<int> spf(n);
    vector<int> parent(n);
    vector<int> sortedArr = nums;
    sort(sortedArr.begin(), sortedArr.end());
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (size_t i = 2; i < spf.size(); i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;
            if (i * i >= spf.size()) continue;
            for (int j = (int)(i * i); j < (int)spf.size(); j += i)
            {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    for (size_t i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        int y = nums[i];
        while (parent[x] != parent[parent[x]]) parent[x] = parent[parent[x]];
        while (y > 1)
        {
             int r = spf[y];
             while (y % r == 0) y /= r;
             while (parent[r] != parent[parent[r]]) parent[r] = parent[parent[r]];
             parent[parent[x]] = parent[r];
        }
    }
    
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == sortedArr[i]) continue;
        int x = nums[i];
        int y = sortedArr[i];
        while (parent[x] != parent[parent[x]]) parent[x] = parent[parent[x]];
        while (parent[y] != parent[parent[y]]) parent[y] = parent[parent[y]];
        if (parent[x] != parent[y]) return false;
    }
    return true;
}


/// <summary>
/// Leet 1958. Check if Move is Legal
///                                                                 
/// Medium
/// 
/// You are given a 0-indexed 8 x 8 grid board, where board[r][c] 
/// represents the cell (r, c) on a game board. On the board, free 
/// cells are represented by '.', white cells are represented by 'W', 
/// and black cells are represented by 'B'.
///
/// Each move in this game consists of choosing a free cell and 
/// changing it to the color you are playing as (either white or black). 
/// However, a move is only legal if, after changing it, the cell becomes 
/// the endpoint of a good line (horizontal, vertical, or diagonal).
///
/// A good line is a line of three or more cells (including the endpoints) 
/// where the endpoints of the line are one color, and the remaining cells 
/// in the middle are the opposite color (no cells in the line are free). 
/// You can find examples for good lines in the figure below:
/// 
/// Given two integers rMove and cMove and a character color representing 
/// the color you are playing as (white or black), return true if changing 
/// cell (rMove, cMove) to color color is a legal move, or false if it is 
/// not legal.
/// 
/// Example 1:
/// Input: board = [[".",".",".","B",".",".",".","."],
/// [".",".",".","W",".",".",".","."], [".",".",".","W",".",".",".","."], 
/// [".",".",".","W",".",".",".","."], ["W","B","B",".","W","W","W","B"], 
/// [".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],
/// [".",".",".","W",".",".",".","."]], rMove = 4, cMove = 3, color = "B"
/// Output: true
/// Explanation: '.', 'W', and 'B' are represented by the colors blue, 
/// white, and black respectively, and cell (rMove, cMove) is marked with 
/// an 'X'.
/// The two good lines with the chosen cell as an endpoint are annotated 
/// above with the red rectangles.
///
/// Example 2:
/// Input: board =
///	[[".",".",".",".",".",".",".","."], [".","B",".",".","W",".",".","."], 
/// [".",".","W",".",".",".",".","."], [".",".",".","W","B",".",".","."], 
/// [".",".",".",".",".",".",".","."],[".",".",".",".","B","W",".","."],
/// [".",".",".",".",".",".","W","."],[".",".",".",".",".",".",".","B"]], 
/// rMove = 4, cMove = 4, color = "W"
/// Output: false
/// Explanation: While there are good lines with the chosen cell as a 
/// middle cell, there are no good lines with the chosen cell as an 
/// endpoint.
/// 
/// Constraints:
/// 1. board.length == board[r].length == 8
/// 2. 0 <= rMove, cMove < 8
/// 3. board[rMove][cMove] == '.'
/// 4. color is either 'B' or 'W'.
/// </summary>
bool LeetCodeGraph::checkMove(vector<vector<char>>& board, int rMove, int cMove, char color)
{
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
    board[rMove][cMove] = color;
    for (size_t i = 0; i < directions.size(); i++)
    {
        int r = rMove;
        int c = cMove;
        int state = 0;
        for (int j = 0; j < (int)board.size(); j++)
        {
            r += directions[i][0];
            c += directions[i][1];
            if (r < 0 || r == board.size() || c < 0 || c == board[0].size())
            {
                break;
            }
            if (board[r][c] == '.') break;
            if (board[r][c] == color)
            {
                state++;
                break;
            }
            if (board[r][c] != color)
            {
                state = 1;
            }
        }
        if (state == 2)
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet Code 2045. Second Minimum Time to Reach Destination 
///                                                                 
/// Hard
/// 
/// A city is represented as a bi-directional connected graph with n 
/// vertices where each vertex is labeled from 1 to n (inclusive). The 
/// edges in the graph are represented as a 2D integer array edges, 
/// where each edges[i] = [ui, vi] denotes a bi-directional edge between 
/// vertex ui and vertex vi. Every vertex pair is connected by at most 
/// one edge, and no vertex has an edge to itself. The time taken to 
/// traverse any edge is time minutes.
///
/// Each vertex has a traffic signal which changes its color from green 
/// to red and vice versa every change minutes. All signals change at 
/// the same time. You can enter a vertex at any time, but can leave a 
/// vertex only when the signal is green. You cannot wait at a vertex if 
/// the signal is green.
///
/// The second minimum value is defined as the smallest value strictly 
/// larger than the minimum value.
///
/// For example the second minimum value of [2, 3, 4] is 3, and the 
/// second minimum value of [2, 2, 4] is 4.
/// Given n, edges, time, and change, return the second minimum time it 
/// will take to go from vertex 1 to vertex n.
///
/// Notes:
/// You can go through any vertex any number of times, including 1 and n.
/// You can assume that when the journey starts, all signals have just 
/// turned green.
/// 
/// Example 1:
/// Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, 
/// change = 5
/// Output: 13
/// Explanation:
/// The figure on the left shows the given graph.
/// The blue path in the figure on the right is the minimum time path.
/// The time taken is:
/// - Start at 1, time elapsed=0
/// - 1 -> 4: 3 minutes, time elapsed=3
/// - 4 -> 5: 3 minutes, time elapsed=6
/// Hence the minimum time needed is 6 minutes.
///
/// The red path shows the path to get the second minimum time.
/// - Start at 1, time elapsed=0
/// - 1 -> 3: 3 minutes, time elapsed=3
/// - 3 -> 4: 3 minutes, time elapsed=6
/// - Wait at 4 for 4 minutes, time elapsed=10
/// - 4 -> 5: 3 minutes, time elapsed=13
/// Hence the second minimum time is 13 minutes.      
///
/// Example 2:
/// 
/// Input: n = 2, edges = [[1,2]], time = 3, change = 2
/// Output: 11
/// Explanation:
/// The minimum time path is 1 -> 2 with time = 3 minutes.
/// The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 
/// minutes.
/// 
/// Constraints:
/// 1. 2 <= n <= 10^4
/// 2. n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
/// 3. edges[i].length == 2
/// 4. 1 <= ui, vi <= n
/// 5. ui != vi
/// 6. There are no duplicate edges.
/// 7. Each vertex can be reached directly or indirectly from every other 
///   vertex.
/// 8. 1 <= time, change <= 10^3
/// </summary>
int LeetCodeGraph::secondMinimum(int n, vector<vector<int>>& edges, int time, int change)
{
    vector<vector<int>> neighbors(n+1);
    vector<priority_queue<int>> destination(n+1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    destination[1].push(0);
    while (!pq.empty())
    {
        pair<int, int> pos = pq.top();
        pq.pop();
        int curr_time = 0 - pos.first;
        if (pos.second == n)
        {
            if (destination[n].size() == 2)
            {
                return destination[n].top();
            }
        }
        if (pos.first > destination[pos.second].top())
        {
            continue;
        }
        if ((curr_time / change) % 2 == 1)
        {
            curr_time += change - curr_time % change;
        }
        int next_time = curr_time + time;
        for (size_t i = 0; i < neighbors[pos.second].size(); i++)
        {
            if (destination[neighbors[pos.second][i]].empty())
            {
                destination[neighbors[pos.second][i]].push(next_time);
                pq.push(make_pair(-next_time, neighbors[pos.second][i]));
            }
            else if (destination[neighbors[pos.second][i]].size() == 1)
            {
                if (next_time != destination[neighbors[pos.second][i]].top())
                {
                    destination[neighbors[pos.second][i]].push(next_time);
                    pq.push(make_pair(-next_time, neighbors[pos.second][i]));
                }
            }
            else if (next_time < destination[neighbors[pos.second][i]].top())
            {
                destination[neighbors[pos.second][i]].pop();
                pq.push(make_pair(-next_time, neighbors[pos.second][i]));
            } 
        }
    }
    return 0;
}

/// <summary>
/// Leet Code 2065. Maximum Path Quality of a Graph
/// </summary>
void LeetCodeGraph::maximalPathQuality(vector<int>& values, vector<vector<pair<int, int>>>& neighbors,
    vector<int>& visited, int curr_time, int curr_score, int curr_node, int maxTime, int& result)
{
    if (visited[curr_node] == 0)
    {
        curr_score += values[curr_node];
    }
    visited[curr_node]++;
    if (curr_node == 0) result = max(result, curr_score);
    for (size_t i = 0; i < neighbors[curr_node].size(); i++)
    {
        int next_time = curr_time + neighbors[curr_node][i].second;
        if (next_time > maxTime) continue;

        maximalPathQuality(values, neighbors, visited, next_time, curr_score,
            neighbors[curr_node][i].first, maxTime, result);
    }
    visited[curr_node]--;
}

/// <summary>
/// Leet Code 2065. Maximum Path Quality of a Graph
///                                                                 
/// Hard
/// 
/// There is an undirected graph with n nodes numbered from 0 to n - 1 
/// (inclusive). You are given a 0-indexed integer array values where 
/// values[i] is the value of the ith node. You are also given a 0-indexed 
/// 2D integer array edges, where each edges[j] = [uj, vj, timej] 
/// indicates that there is an undirected edge between the nodes uj and 
/// vj, and it takes timej seconds to travel between the two nodes. 
/// Finally, you are given an integer maxTime.
///
/// A valid path in the graph is any path that starts at node 0, ends at 
/// node 0, and takes at most maxTime seconds to complete. You may visit 
/// the same node multiple times. The quality of a valid path is the sum 
/// of the values of the unique nodes visited in the path (each node's 
/// value is added at most once to the sum).
///
/// Return the maximum quality of a valid path.
///
/// Note: There are at most four edges connected to each node.
///
/// Example 1:
/// Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], 
/// maxTime = 49
/// Output: 75
/// Explanation:
/// One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 
/// 10 + 10 + 10 + 10 = 40 <= 49.
/// The nodes visited are 0, 1, and 3, giving a maximal path quality 
/// of 0 + 32 + 43 = 75.
///
/// Example 2:
/// Input: values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], 
/// maxTime = 30
/// Output: 25
/// Explanation:
/// One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 
/// 20 <= 30.
/// The nodes visited are 0 and 3, giving a maximal path quality of 5 + 
/// 20 = 25.
///
/// Example 3:
/// Input: values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],
/// [1,3,13]], maxTime = 50
/// Output: 7
/// Explanation:
/// One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken 
/// is 10 + 13 + 13 + 10 = 46 <= 50.
/// The nodes visited are 0, 1, and 3, giving a maximal path quality 
/// of 1 + 2 + 4 = 7.
///
/// Example 4:
/// Input: values = [0,1,2], edges = [[1,2,10]], maxTime = 10
/// Output: 0
/// Explanation: 
/// The only path is 0. The total time taken is 0.
/// The only node visited is 0, giving a maximal path quality of 0.
///
/// Constraints:
/// 1. n == values.length
/// 2. 1 <= n <= 1000
/// 3. 0 <= values[i] <= 10^8
/// 4. 0 <= edges.length <= 2000
/// 5. edges[j].length == 3
/// 6. 0 <= uj < vj <= n - 1
/// 7. 10 <= timej, maxTime <= 100
/// 8. All the pairs [uj, vj] are unique.
/// 9. There are at most four edges connected to each node.
/// 10. The graph may not be connected.
/// </summary>
int LeetCodeGraph::maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, 
    int maxTime)
{
    int n = values.size();
    vector<vector<pair<int, int>>> neighbors(n);
    vector<int> visited(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        neighbors[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    int result = 0;
    maximalPathQuality(values, neighbors, visited, 0, 0, 0, maxTime, result);
    
    return result;
}

/// <summary>
/// Leet Code 2076. Process Restricted Friend Requests
///                                                                 
/// Hard
/// 
/// You are given an integer n indicating the number of people in a 
/// network. Each person is labeled from 0 to n - 1.
///
/// You are also given a 0-indexed 2D integer array restrictions, where 
/// restrictions[i] = [xi, yi] means that person xi and person yi cannot 
/// become friends, either directly or indirectly through other people.
///
/// Initially, no one is friends with each other. You are given a list 
/// of friend requests as a 0-indexed 2D integer array requests, where 
/// requests[j] = [uj, vj] is a friend request between person uj and 
/// person vj.
///
/// A friend request is successful if uj and vj can be friends. Each 
/// friend request is processed in the given order (i.e., requests[j] 
/// occurs before requests[j + 1]), and upon a successful request, 
/// uj and vj become direct friends for all future friend requests.
///
/// Return a boolean array result, where each result[j] is true if 
/// the jth friend request is successful or false if it is not.
///
/// Note: If uj and vj are already direct friends, the request is 
/// still successful.
/// 
/// Example 1:
/// Input: n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
/// Output: [true,false]
/// Explanation:
/// Request 0: Person 0 and person 2 can be friends, so they become 
/// direct friends. 
/// Request 1: Person 2 and person 1 cannot be friends since person 0 
/// and person 1 would be indirect friends (1--2--0).
///
/// Example 2:
/// Input: n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]
/// Output: [true,false]
/// Explanation:
/// Request 0: Person 1 and person 2 can be friends, so they become 
/// direct friends.
/// Request 1: Person 0 and person 2 cannot be friends since person 0 
/// and person 1 would be indirect friends (0--2--1).
///
/// Example 3:
/// Input: n = 5, restrictions = [[0,1],[1,2],[2,3]], 
/// requests = [[0,4],[1,2],[3,1],[3,4]]
/// Output: [true,false,true,false]
/// Explanation:
/// Request 0: Person 0 and person 4 can be friends, so they become 
/// direct friends.
/// Request 1: Person 1 and person 2 cannot be friends since they are 
/// directly restricted.
/// Request 2: Person 3 and person 1 can be friends, so they become 
/// direct friends.
/// Request 3: Person 3 and person 4 cannot be friends since person 0 
/// and person 1 would be indirect friends (0--4--3--1).
///
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. 0 <= restrictions.length <= 1000
/// 3. restrictions[i].length == 2
/// 4. 0 <= xi, yi <= n - 1
/// 5. xi != yi
/// 6. 1 <= requests.length <= 1000
/// 7. requests[j].length == 2
/// 8. 0 <= uj, vj <= n - 1
/// 9. uj != vj
/// </summary>
vector<bool> LeetCodeGraph::friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests)
{
    vector<int> parents(n);
    vector<bool> result(requests.size());
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
    }

    for (size_t i = 0; i < requests.size(); i++)
    {
        int x = requests[i][0];
        int y = requests[i][1];
        while (parents[parents[x]] != parents[x]) parents[x] = parents[parents[x]];      
        while (parents[parents[y]] != parents[y]) parents[y] = parents[parents[y]];
        x = parents[x];
        y = parents[y];
        if (x > y) swap(x, y);

        bool b_friend = true;
        for (size_t j = 0; j < restrictions.size(); j++)
        {
            int p = restrictions[j][0];
            int q = restrictions[j][1];
            while (p != parents[p]) p = parents[p];
            while (q != parents[q]) q = parents[q];
            if (p > q) swap(p, q);
            if (x == p && y == q)
            {
                b_friend = false;
                break;
            }
        }
        result[i] = b_friend;
        if (b_friend)
        {
            parents[y] = parents[x];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2050. Parallel Courses III
///                                                                 
/// Hard
/// 
/// You are given an integer n, which indicates that there are n courses 
/// labeled from 1 to n. You are also given a 2D integer array relations 
/// where relations[j] = [prevCoursej, nextCoursej] denotes that course 
/// prevCoursej has to be completed before course nextCoursej 
/// (prerequisite relationship). Furthermore, you are given a 0-indexed 
/// integer array time where time[i] denotes how many months it takes 
/// to complete the (i+1)th course.
///
/// You must find the minimum number of months needed to complete all 
/// the courses following these rules:
///
/// You may start taking a course at any time if the prerequisites are met.
///
/// Any number of courses can be taken at the same time.
/// Return the minimum number of months needed to complete all the courses.
///
/// Note: The test cases are generated such that it is possible to complete 
/// every course (i.e., the graph is a directed acyclic graph).
///  
/// Example 1:
/// Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
/// Output: 8
/// Explanation: The figure above represents the given graph and the time 
/// required to complete each course. 
/// We start course 1 and course 2 simultaneously at month 0.
/// Course 1 takes 3 months and course 2 takes 2 months to complete 
/// respectively.
/// Thus, the earliest time we can start course 3 is at month 3, and the 
/// total time required is 3 + 5 = 8 months.
///
/// Example 2:
/// Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], 
/// time = [1,2,3,4,5]
/// Output: 12
/// Explanation: The figure above represents the given graph and the time 
/// required to complete each course.
/// You can start courses 1, 2, and 3 at month 0.
/// You can complete them after 1, 2, and 3 months respectively.
/// Course 4 can be taken only after course 3 is completed, i.e., after 3 
/// months. It is completed after 3 + 4 = 7 months.
/// Course 5 can be taken only after courses 1, 2, 3, and 4 have been 
/// completed, i.e., after max(1,2,3,7) = 7 months.
/// Thus, the minimum time needed to complete all the courses 
/// is 7 + 5 = 12 months.
/// Constraints:
/// 1. 1 <= n <= 5 * 10^4
/// 2. 0 <= relations.length <= min(n * (n - 1) / 2, 5 * 10^4)
/// 3. relations[j].length == 2
/// 4. 1 <= prevCoursej, nextCoursej <= n
/// 5. prevCoursej != nextCoursej
/// 6. All the pairs [prevCoursej, nextCoursej] are unique.
/// 7. time.length == n
/// 8. 1 <= time[i] <= 10^4
/// 9. The given graph is a directed acyclic graph.
/// </summary>
int LeetCodeGraph::minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
{
    vector<int> degree(n);
    vector<int> start_time(n);
    vector<vector<int>> next_courses(n);

    for (size_t i = 0; i < relations.size(); i++)
    {
        int prev = relations[i][0] - 1;
        int next = relations[i][1] - 1;
        next_courses[prev].push_back(next);

        degree[next]++;
    }

    queue<int> waiting;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0) waiting.push(i);
    }

    int result = 0;
    while (!waiting.empty())
    {
        int course = waiting.front();
        waiting.pop();
        int finish_time = start_time[course] + time[course];
        result = max(result, finish_time);
        for (size_t j = 0; j < next_courses[course].size(); j++)
        {
            int next_course = next_courses[course][j];
            degree[next_course]--;
            start_time[next_course] = max(start_time[next_course], finish_time);
            if (degree[next_course] == 0)
            {
                waiting.push(next_course);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1992. Find All Groups of Farmland
///                                                                 
/// Medium
/// 
/// You are given a 0-indexed m x n binary matrix land where a 0 
/// represents a hectare of forested land and a 1 represents a 
/// hectare of farmland.
///
/// To keep the land organized, there are designated rectangular 
/// areas of hectares that consist entirely of farmland. These 
/// rectangular areas are called groups. No two groups are adjacent, 
/// meaning farmland in one group is not four-directionally adjacent 
/// to another farmland in a different group.
///
/// land can be represented by a coordinate system where the top 
/// left corner of land is (0, 0) and the bottom right corner of land 
/// is (m-1, n-1). Find the coordinates of the top left and bottom right 
/// corner of each group of farmland. A group of farmland with a top 
/// left corner at (r1, c1) and a bottom right corner at (r2, c2) is 
/// represented by the 4-length array [r1, c1, r2, c2].
/// 
/// Return a 2D array containing the 4-length arrays described above 
/// for each group of farmland in land. If there are no groups of 
/// farmland, return an empty array. You may return the answer in 
/// any order.
/// 
/// Example 1:
/// Input: land = [[1,0,0],[0,1,1],[0,1,1]]
/// Output: [[0,0,0,0],[1,1,2,2]]
/// Explanation:
/// The first group has a top left corner at land[0][0] and a bottom 
/// right corner at land[0][0].
/// The second group has a top left corner at land[1][1] and a bottom 
/// right corner at land[2][2].
///
/// Example 2:
/// Input: land = [[1,1],[1,1]]
/// Output: [[0,0,1,1]]
/// Explanation:
/// The first group has a top left corner at land[0][0] and a bottom right 
/// corner at land[1][1].
///
/// Example 3:
/// Input: land = [[0]]
/// Output: []
/// Explanation:
/// There are no groups of farmland.
///
/// Constraints:
/// 1. m == land.length
/// 2. n == land[i].length
/// 3. 1 <= m, n <= 300
/// 4. land consists of only 0's and 1's.
/// 5. Groups of farmland are rectangular in shape.
/// </summary>
vector<vector<int>> LeetCodeGraph::findFarmland(vector<vector<int>>& land)
{
    vector<vector<int>> result;
    vector<vector<int>> grid = land;
    int m = land.size();
    int n = land[0].size();
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 0;
                vector<int> coordination(4);
                queue<vector<int>> queue;
                queue.push({ i, j });
                coordination[0] = i;
                coordination[1] = j;
                coordination[2] = i;
                coordination[3] = j;

                while (!queue.empty())
                {
                    vector<int> pos = queue.front();
                    queue.pop();
                    for (int d = 0; d < 4; d++)
                    {
                        vector<int> next_pos = pos;
                        next_pos[0] += directions[d][0];
                        next_pos[1] += directions[d][1];
                        if (next_pos[0] < 0 || next_pos[0] >= m ||
                            next_pos[1] < 0 || next_pos[1] >= n)
                        {
                            continue;
                        }
                        if (grid[next_pos[0]][next_pos[1]] == 1)
                        {
                            grid[next_pos[0]][next_pos[1]] = 0;
                            coordination[2] = max(coordination[2], next_pos[0]);
                            coordination[3] = max(coordination[3], next_pos[1]);
                            queue.push({ next_pos[0],  next_pos[1] });
                        }
                    }
                }
                result.push_back(coordination);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1956. Minimum Time For K Virus Variants to Spread
///                                                                 
/// Hard
/// 
/// There are n unique virus variants in an infinite 2D grid. You are 
/// given a 2D array points, where points[i] = [xi, yi] represents a 
/// virus originating at (xi, yi) on day 0. Note that it is possible 
/// for multiple virus variants to originate at the same point.
///
/// Every day, each cell infected with a virus variant will spread the 
/// virus to all neighboring points in the four cardinal directions 
/// (i.e. up, down, left, and right). If a cell has multiple variants, 
/// all the variants will spread without interfering with each other.
///
/// Given an integer k, return the minimum integer number of days for 
/// any point to contain at least k of the unique virus variants.
/// 
/// Example 1:
/// Input: points = [[1,1],[6,1]], k = 2
/// Output: 3
/// Explanation: On day 3, points (3,1) and (4,1) will contain both virus 
/// variants. Note that these are not the only points that will contain 
/// both virus variants.
///
/// Example 2:
/// Input: points = [[3,3],[1,2],[9,2]], k = 2
/// Output: 2
/// Explanation: On day 2, points (1,3), (2,3), (2,2), and (3,2) will 
/// contain the first two viruses. Note that these are not the only points 
/// that will contain both virus variants.
///
/// Example 3:
/// Input: points = [[3,3],[1,2],[9,2]], k = 3
/// Output: 4
/// Explanation: On day 4, the point (5,2) will contain all 3 viruses. 
/// Note that this is not the only point that will contain all 3 virus 
/// variants.
///
/// Constraints:
/// 1. n == points.length
/// 2. 2 <= n <= 50
/// 3. points[i].length == 2
/// 4. 1 <= xi, yi <= 100
/// 5. 2 <= k <= n
/// </summary>
int LeetCodeGraph::minDayskVariants(vector<vector<int>>& points, int k)
{
    vector<vector<vector<int>>> grid(101, vector<vector<int>>(101, vector<int>(100)));
    int result = 100;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            for (int p = 0; p < (int)points.size(); p++)
            {
                int d = abs(i - points[p][0]) + abs(j - points[p][1]);
                if (d >= 100) continue;
                grid[i][j][d]++;
            }
            int count = 0;
            int day = 0;
            for (int d = 0; d < 100; d++)
            {
                count += grid[i][j][d];
                if (count >= k)
                {
                    result = min(result, d);
                    break;
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2092. Find All People With Secret
///                                                                 
/// Hard
/// 
/// You are given an integer n indicating there are n people numbered 
/// from 0 to n - 1. You are also given a 0-indexed 2D integer array 
/// meetings where meetings[i] = [xi, yi, timei] indicates that person 
/// xi and person yi have a meeting at timei. A person may attend 
/// multiple meetings at the same time. Finally, you are given an integer
/// firstPerson.
///
/// Person 0 has a secret and initially shares the secret with a person 
/// firstPerson at time 0. This secret is then shared every time a meeting 
/// takes place with a person that has the secret. More formally, for 
/// every meeting, if a person xi has the secret at timei, then they will 
/// share the secret with person yi, and vice versa.
///
/// The secrets are shared instantaneously. That is, a person may receive 
/// the secret and share it with people in other meetings within the same 
/// time frame.
///
/// Return a list of all the people that have the secret after all the 
/// meetings have taken place. You may return the answer in any order.
///
/// Example 1:
/// Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
/// Output: [0,1,2,3,5]
/// Explanation:
/// At time 0, person 0 shares the secret with person 1.
/// At time 5, person 1 shares the secret with person 2.
/// At time 8, person 2 shares the secret with person 3.
/// At time 10, person 1 shares the secret with person 5.
/// Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
///
/// Example 2:
///
/// Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
/// Output: [0,1,3]
/// Explanation:
/// At time 0, person 0 shares the secret with person 3.
/// At time 2, neither person 1 nor person 2 know the secret.
/// At time 3, person 3 shares the secret with person 0 and person 1.
/// Thus, people 0, 1, and 3 know the secret after all the meetings.
///
/// Example 3:
/// Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
/// Output: [0,1,2,3,4]
/// Explanation:
/// At time 0, person 0 shares the secret with person 1.
/// At time 1, person 1 shares the secret with person 2, and person 2 
/// shares the secret with person 3.
/// Note that person 2 can share the secret at the same time as receiving 
/// it.
/// At time 2, person 3 shares the secret with person 4.
/// Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
///
/// Example 4:
/// Input: n = 6, meetings = [[0,2,1],[1,3,1],[4,5,1]], firstPerson = 1
/// Output: [0,1,2,3]
/// Explanation:
/// At time 0, person 0 shares the secret with person 1.
/// At time 1, person 0 shares the secret with person 2, and person 1 
/// shares the secret with person 3.
/// Thus, people 0, 1, 2, and 3 know the secret after all the meetings.
/// Constraints:
/// 1. 2 <= n <= 10^5
/// 2. 1 <= meetings.length <= 10^5
/// 3. meetings[i].length == 3
/// 4. 0 <= xi, yi <= n - 1
/// 5. xi != yi
/// 6. 1 <= timei <= 10^5
/// 7. 1 <= firstPerson <= n - 1
/// </summary>
vector<int> LeetCodeGraph::findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
{
    vector<int> meeting_times(n, INT_MAX);
    priority_queue<pair<int, int>> pq;
    vector<vector<pair<int, int>>> neighbors(n);
    for (size_t i = 0; i < meetings.size(); i++)
    {
        neighbors[meetings[i][0]].push_back(make_pair(meetings[i][1], meetings[i][2]));
        neighbors[meetings[i][1]].push_back(make_pair(meetings[i][0], meetings[i][2]));
    }
    pq.push(make_pair(0, 0));
    pq.push(make_pair(0, firstPerson));
    meeting_times[0] = 0;
    meeting_times[firstPerson] = 0;
    vector<int>result;
    while (!pq.empty())
    {
        pair<int, int> pos = pq.top();
        pq.pop();
        int time = 0 - pos.first;
        int person = pos.second;
        if (time > meeting_times[person])
        {
            continue;
        }
        result.push_back(person);
        for (size_t i = 0; i < neighbors[person].size(); i++)
        {
            int next_person = neighbors[person][i].first;
            int next_meeting = neighbors[person][i].second;
            // this meeting is too early
            if (next_meeting < time)
            {
                continue;
            }
            // we already have a meeting
            if (meeting_times[next_person] <= next_meeting)
            {
                continue;
            }

            if (meeting_times[next_person] = next_meeting)
            {
                pq.push(make_pair(0 - next_meeting, next_person));
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1971. Find if Path Exists in Graph
///                                                                 
/// Easy
///
/// There is a bi-directional graph with n vertices, where each vertex is 
/// labeled from 0 to n - 1 (inclusive). The edges in the graph are 
/// represented as a 2D integer array edges, where each edges[i] = [ui, vi]
/// denotes a bi-directional edge between vertex ui and vertex vi. Every 
/// vertex pair is connected by at most one edge, and no vertex has an edge 
/// to itself.
/// 
/// You want to determine if there is a valid path that exists from vertex 
/// start to vertex end.
/// Given edges and the integers n, start, and end, return true if there is 
/// a valid path from start to end, or false otherwise.
/// 
/// Example 1:
/// nput: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
/// Output: true
/// Explanation: There are two paths from vertex 0 to vertex 2:
/// 0 -> 1 -> 2
/// 0 -> 2
///
/// Example 2:
/// Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, 
/// end = 5
/// Output: false
/// Explanation: There is no path from vertex 0 to vertex 5.
///
/// Constraints:
/// 1. 1 <= n <= 2 * 10^5
/// 2. 0 <= edges.length <= 2 * 10^5
/// 3. edges[i].length == 2
/// 4. 0 <= ui, vi <= n - 1
/// 5. ui != vi
/// 6. 0 <= start, end <= n - 1
/// 7. There are no duplicate edges.
/// 8. There are no self edges.
/// </summary>
bool LeetCodeGraph::validPath(int n, vector<vector<int>>& edges, int start, int end)
{
    vector<vector<int>> neighbors(n);
    vector<int> visited(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> queue;
    queue.push(start);
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        if (node == end) return true;
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next = neighbors[node][i];
            if (visited[next] == 1) continue;
            queue.push(next);
            visited[next] = 1;
        }
    }
    return false;
}

/// <summary>
/// Leet Code 2077. Paths in Maze That Lead to Same Room
/// </summary>
int LeetCodeGraph::numberOfPaths(int start, int curr, int depth, vector<unordered_set<int>>& neighbors)
{
    int result = 0;
    if (depth == 2)
    {
        if (neighbors[start].count(curr) > 0)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
        return result;
    }
    for (int x : neighbors[curr])
    {
        result += numberOfPaths(start, x, depth + 1, neighbors);
    }
    return result;
}

/// <summary>
/// Leet Code 2077. Paths in Maze That Lead to Same Room
///                                                                 
/// Medium
///
/// A maze consists of n rooms numbered from 1 to n, and some rooms are 
/// connected by corridors. You are given a 2D integer array corridors 
/// where corridors[i] = [room1i, room2i] indicates that there is a 
/// corridor connecting room1i and room2i, allowing a person in the 
/// maze to go from room1i to room2i and vice versa.
///
/// The designer of the maze wants to know how confusing the maze is. 
/// The confusion score of the maze is the number of different cycles 
/// of length 3.
///
/// For example, 1 -> 2 -> 3 -> 1 is a cycle of length 3, 
/// but 1 -> 2 -> 3 -> 4 and 1 -> 2 -> 3 -> 2 -> 1 are not.
/// Two cycles are considered to be different if one or more of the 
/// rooms visited in the first cycle is not in the second cycle.
///
/// Return the confusion score of the maze.
/// Example 1:
/// Input: n = 5, corridors = [[1,2],[5,2],[4,1],[2,4],[3,1],[3,4]]
/// Output: 2
/// Explanation:
/// One cycle of length 3 is 4 -> 1 -> 3 -> 4, denoted in red.
/// Note that this is the same cycle as 3 -> 4 -> 1 -> 3 
/// or 1 -> 3 -> 4 -> 1 because the rooms are the same.
/// Another cycle of length 3 is 1 -> 2 -> 4 -> 1, denoted in blue.
/// Thus, there are two different cycles of length 3.
///
/// Example 2:
/// Input: n = 4, corridors = [[1,2],[3,4]]
/// Output: 0
/// Explanation:
/// There are no cycles of length 3.
///
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. 1 <= corridors.length <= 5 * 10^4
/// 3. corridors[i].length == 2
/// 4. 1 <= room1i, room2i <= n
/// 5. room1i != room2i
/// 6. There are no duplicate corridors.
/// </summary>
int LeetCodeGraph::numberOfPaths(int n, vector<vector<int>>& corridors)
{
    vector<unordered_set<int>> neighbors(n + 1);
    for (size_t i = 0; i < corridors.size(); i++)
    {
        if (corridors[i][0] > corridors[i][1]) 
        { 
            swap(corridors[i][0], corridors[i][1]);
        }
        neighbors[corridors[i][0]].insert(corridors[i][1]);
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += numberOfPaths(i, i, 0, neighbors);
    }
    return result;
}

/// <summary>
/// Leet Code 2061. Number of Spaces Cleaning Robot Cleaned
///                                                                 
/// Medium
///
/// A room is represented by a 0-indexed 2D binary matrix room where 
/// a 0 represents an empty space and a 1 represents a space with an 
/// object. The top left corner of the room will be empty in all test 
/// cases.
///
/// A cleaning robot starts at the top left corner of the room and is 
/// facing right. The robot will continue heading straight until it 
/// reaches the edge of the room or it hits an object, after which it 
/// will turn 90 degrees clockwise and repeat this process. The starting 
/// space and all spaces that the robot visits are cleaned by it.
///
/// Return the number of clean spaces in the room if the robot runs 
/// indefinetely.
/// 
/// Example 1:
/// Input: room = [[0,0,0],[1,1,0],[0,0,0]]
/// Output: 7
/// Explanation:
/// The robot cleans the spaces at (0, 0), (0, 1), and (0, 2).
/// The robot is at the edge of the room, so it turns 90 degrees clockwise 
/// and now faces down.
/// The robot cleans the spaces at (1, 2), and (2, 2).
/// The robot is at the edge of the room, so it turns 90 degrees clockwise 
/// and now faces left.
/// The robot cleans the spaces at (2, 1), and (2, 0).
/// The robot has cleaned all 7 empty spaces, so return 7.
///
/// Example 2:
/// Input: room = [[0,1,0],[1,0,0],[0,0,0]]
/// Output: 1
/// Explanation:
/// The robot cleans the space at (0, 0).
/// The robot hits an object, so it turns 90 degrees clockwise and now 
/// faces down.
/// The robot hits an object, so it turns 90 degrees clockwise and now 
/// faces left.
/// The robot is at the edge of the room, so it turns 90 degrees clockwise 
/// and now faces up.
/// The robot is at the edge of the room, so it turns 90 degrees clockwise 
/// and now faces right.
/// The robot is back at its starting position.
/// The robot has cleaned 1 space, so return 1.
///
/// Constraints:
/// 1. m == room.length
/// 2. n == room[r].length
/// 3. 1 <= m, n <= 300
/// 4. room[r][c] is either 0 or 1.
/// 5. room[0][0] == 0
/// </summary>
int LeetCodeGraph::numberOfCleanRooms(vector<vector<int>>& room)
{
    int m = room.size();
    int n = room[0].size();
    vector<vector<int>> visited(m, vector<int>(n));
    vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int direction = 0;
    int result = 0;
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    while (!queue.empty())
    {
        pair<int, int> pos = queue.front();
        queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            if (visited[pos.first][pos.second] == 0)
            {
                result++;
            }
            if ((visited[pos.first][pos.second] & (1 << direction)) != 0)
            {
                return result;
            }
            visited[pos.first][pos.second] |= (1 << direction);
            pair<int, int> next_pos = pos;
            next_pos.first += directions[direction][0];
            next_pos.second += directions[direction][1];
            if (next_pos.first < 0 || next_pos.second < 0 || next_pos.first >= m || next_pos.second >= n)
            {
                direction = (direction + 1) % 4;
                continue;
            }
            if (room[next_pos.first][next_pos.second] == 1)
            {
                direction = (direction + 1) % 4;
                continue;
            }
            queue.push(next_pos);
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2097. Valid Arrangement of Pairs
/// </summary>
void LeetCodeGraph::validArrangement(int node, unordered_map<int, vector<int>>& neighbors,
    vector<vector<int>>& result)
{
    while (neighbors[node].size()) 
    {
        int next = neighbors[node].back();
        neighbors[node].pop_back();
        validArrangement(next, neighbors, result);
        result.push_back({ node, next });
    }
}

/// <summary>
/// Leet Code 2097. Valid Arrangement of Pairs
///                                                                 
/// Hard
///
/// You are given a 0-indexed 2D integer array pairs where pairs[i] = 
/// [starti, endi]. An arrangement of pairs is valid if for every index i 
/// where 1 <= i < pairs.length, we have endi-1 == starti.
///
/// Return any valid arrangement of pairs.
///
/// Note: The inputs will be generated such that there exists a valid 
/// arrangement of pairs.
/// 
/// Example 1:
/// Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
/// Output: [[11,9],[9,4],[4,5],[5,1]]
/// Explanation:
/// This is a valid arrangement since endi-1 always equals starti.
/// end0 = 9 == 9 = start1 
/// end1 = 4 == 4 = start2
/// end2 = 5 == 5 = start3
///
/// Example 2:
/// Input: pairs = [[1,3],[3,2],[2,1]]
/// Output: [[1,3],[3,2],[2,1]]
/// Explanation:
/// This is a valid arrangement since endi-1 always equals starti.
/// end0 = 3 == 3 = start1
/// end1 = 2 == 2 = start2
/// The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
///
/// Example 3:
/// Input: pairs = [[1,2],[1,3],[2,1]]
/// Output: [[1,2],[2,1],[1,3]]
/// Explanation:
/// This is a valid arrangement since endi-1 always equals starti.
/// end0 = 2 == 2 = start1
/// end1 = 1 == 1 = start2
/// Constraints:
/// 1. 1 <= pairs.length <= 10^5
/// 2. pairs[i].length == 2
/// 3. 0 <= starti, endi <= 10^9
/// 4. starti != endi
/// 5. No two pairs are exactly the same.
/// 6. There exists a valid arrangement of pairs.
/// </summary>
vector<vector<int>> LeetCodeGraph::validArrangement(vector<vector<int>>& pairs)
{
    unordered_map<int, vector<int>> neighbors;
    map<int, int> degree;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        neighbors[pairs[i][0]].push_back(pairs[i][1]);
        degree[pairs[i][0]]++;
        degree[pairs[i][1]]--;
    }
    vector<vector<int>> result;
    int start = pairs[0][0];
    for (auto itr : degree)
    {
        if (itr.second > 0)
        {
            start = itr.first;
            break;
        }
    }
    validArrangement(start, neighbors, result);
    reverse(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet Code 1976. Number of Ways to Arrive at Destination
///                                                                 
/// Medium
///
/// You are in a city that consists of n intersections numbered from 0 to 
/// n - 1 with bi-directional roads between some intersections. The inputs 
/// are generated such that you can reach any intersection from any other 
/// intersection and that there is at most one road between any two 
/// intersections.
/// You are given an integer n and a 2D integer array roads where roads[i] 
/// = [ui, vi, timei] means that there is a road between intersections ui 
/// and vi that takes timei minutes to travel. You want to know in how 
/// many ways you can travel from intersection 0 to intersection n - 1 in 
/// the shortest amount of time.
/// Return the number of ways you can arrive at your destination in the 
/// shortest amount of time. Since the answer may be large, return it 
/// modulo 10^9 + 7.
///
/// Example 1:
/// Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],
/// [3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
/// Output: 4
/// Explanation: The shortest amount of time it takes to go from 
/// intersection 0 to intersection 6 is 7 minutes.
/// The four ways to get there in 7 minutes are:
/// - 0 -> 6
/// - 0 -> 4 -> 6
/// - 0 -> 1 -> 2 -> 5 -> 6
/// - 0 -> 1 -> 3 -> 5 -> 6
///
/// Example 2:
/// Input: n = 2, roads = [[1,0,10]]
/// Output: 1
/// Explanation: There is only one way to go from intersection 0 to 
/// intersection 1, and it takes 10 minutes.
/// 
/// Constraints:
/// 1. 1 <= n <= 200
/// 2. n - 1 <= roads.length <= n * (n - 1) / 2
/// 3. roads[i].length == 3
/// 4. 0 <= ui, vi <= n - 1
/// 5. 1 <= timei <= 10^9
/// 6. ui != vi
/// 7. There is at most one road connecting any two intersections.
/// 8. You can reach any intersection from any other intersection.
/// </summary>
int LeetCodeGraph::countPaths(int n, vector<vector<int>>& roads)
{
    vector<pair<long long, int>> dist(n, make_pair(LLONG_MAX, 0));
    vector<vector<pair<int, int>>> neighbors(n);
    for (size_t i = 0; i < roads.size(); i++)
    {
        neighbors[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
        neighbors[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
    }
    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, 0));
    dist[0] = make_pair(0, 1);
    int M = 1000000007;
    while (!pq.empty())
    {
        pair<long long, int> pos = pq.top();
        pq.pop();
        int node = pos.second;
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next = neighbors[node][i].first;
            long long d = (long long)(0 - pos.first) + (long long)neighbors[node][i].second;
            if (dist[next].first > d)
            {
                dist[next].first = d;
                dist[next].second = dist[node].second;
                pq.push(make_pair(0 - d, next));
            }
            else if (dist[next].first == d)
            {
                dist[next].second = (dist[next].second + dist[node].second) % M;
            }
        }
    }
    return dist[n - 1].second;
}

/// <summary>
/// Leet Code 2087. Minimum Cost Homecoming of a Robot in a Grid
///                                                                 
/// Medium
///
/// There is an m x n grid, where (0, 0) is the top-left cell and 
/// (m - 1, n - 1) is the bottom-right cell. You are given an integer 
/// array startPos where startPos = [startrow, startcol] indicates that 
/// initially, a robot is at the cell (startrow, startcol). You are also 
/// given an integer array homePos where homePos = [homerow, homecol] 
/// indicates that its home is at the cell (homerow, homecol).
/// The robot needs to go to its home. It can move one cell in four 
/// directions: left, right, up, or down, and it can not move outside the 
/// boundary. Every move incurs some cost. You are further given two 
/// 0-indexed integer arrays: rowCosts of length m and colCosts of length n.
///
/// If the robot moves up or down into a cell whose row is r, then this move 
/// costs rowCosts[r].
/// If the robot moves left or right into a cell whose column is c, then 
/// this move costs colCosts[c].
/// Return the minimum total cost for this robot to return home.
/// 
/// Example 1:
/// Input: startPos = [1, 0], homePos = [2, 3], rowCosts = [5, 4, 3], 
/// colCosts = [8, 2, 6, 7]
/// Output: 18
/// Explanation: One optimal path is that:
/// Starting from (1, 0)
/// -> It goes down to (2, 0). This move costs rowCosts[2] = 3.
/// -> It goes right to (2, 1). This move costs colCosts[1] = 2.
/// -> It goes right to (2, 2). This move costs colCosts[2] = 6.
/// -> It goes right to (2, 3). This move costs colCosts[3] = 7.
/// The total cost is 3 + 2 + 6 + 7 = 18
///
/// Example 2:
/// Input: startPos = [0, 0], homePos = [0, 0], rowCosts = [5], 
/// colCosts = [26]
/// Output: 0
/// Explanation: The robot is already at its home. Since no moves occur, 
/// the total cost is 0.
///
/// Constraints:
/// 1. m == rowCosts.length
/// 2. n == colCosts.length
/// 3. 1 <= m, n <= 10^5
/// 4. 0 <= rowCosts[r], colCosts[c] <= 10^4
/// 5. startPos.length == 2
/// 6. homePos.length == 2
/// 7. 0 <= startrow, homerow < m
/// 8. 0 <= startcol, homecol < n
/// </summary>
int LeetCodeGraph::minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
{
    int start = startPos[0];
    int end = homePos[0];
    int step = 1;
    if (start > end) step = -1;
    int result = 0;
    while (start != end)
    {
        start += step;
        result += rowCosts[start];
    }

    start = startPos[1];
    end = homePos[1];
    step = 1;
    if (start > end) step = -1;
    while (start != end)
    {
        start += step;
        result += colCosts[start];
    }
    return result;
}

/// <summary>
/// Leet Code 2039. The Time When the Network Becomes Idle
///                                                                 
/// Medium
///
/// There is a network of n servers, labeled from 0 to n - 1. You are 
/// given a 2D integer array edges, where edges[i] = [ui, vi] indicates 
/// there is a message channel between servers ui and vi, and they can 
/// pass any number of messages to each other directly in one second. 
/// You are also given a 0-indexed integer array patience of length n.
/// All servers are connected, i.e., a message can be passed from one 
/// server to any other server(s) directly or indirectly through the 
/// message channels.
/// The server labeled 0 is the master server. The rest are data servers. 
/// Each data server needs to send its message to the master server for 
/// processing and wait for a reply. Messages move between servers 
/// optimally, so every message takes the least amount of time to arrive 
/// at the master server. The master server will process all newly 
/// arrived messages instantly and send a reply to the originating server 
/// via the reversed path the message had gone through.
///
/// At the beginning of second 0, each data server sends its message to 
/// be processed. Starting from second 1, at the beginning of every 
/// second, each data server will check if it has received a reply to 
/// the message it sent (including any newly arrived replies) from the 
/// master server:
///
/// If it has not, it will resend the message periodically. The data 
/// server i will resend the message every patience[i] second(s), i.e., 
/// the data server i will resend the message if patience[i] second(s) 
/// have elapsed since the last time the message was sent from this server.
/// Otherwise, no more resending will occur from this server.
/// The network becomes idle when there are no messages passing between 
/// servers or arriving at servers.
/// Return the earliest second starting from which the network becomes 
/// idle.
/// 
/// Example 1:
/// Input: edges = [[0,1],[1,2]], patience = [0,2,1]
/// Output: 8
/// Explanation:
/// At (the beginning of) second 0,
/// - Data server 1 sends its message (denoted 1A) to the master server.
/// - Data server 2 sends its message (denoted 2A) to the master server.
///
/// At second 1,
/// - Message 1A arrives at the master server. Master server processes 
///   message 1A instantly and sends a reply 1A back. 
/// - Server 1 has not received any reply. 1 second (1 < patience[1] = 2) 
///   elapsed since this server has sent the message, therefore it does 
///   not resend the message.
/// - Server 2 has not received any reply. 1 second (1 == patience[2] = 1)
///    elapsed since this server has sent the message, therefore it resends
///    the message (denoted 2B).
///
/// At second 2,
/// - The reply 1A arrives at server 1. No more resending will occur from 
///   server 1.
/// - Message 2A arrives at the master server. Master server processes 
///   message 2A instantly and sends a reply 2A back.
/// - Server 2 resends the message (denoted 2C).
/// ...
/// At second 4,
/// - The reply 2A arrives at server 2. No more resending will occur from 
///   server 2.
/// ...
/// At second 7, reply 2D arrives at server 2.
/// Starting from the beginning of the second 8, there are no messages 
/// passing between servers or arriving at servers.
/// This is the time when the network becomes idle.
///
/// Example 2:
/// Input: edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
/// Output: 3
/// Explanation: Data servers 1 and 2 receive a reply back at the 
/// beginning of second 2.
/// From the beginning of the second 3, the network becomes idle.
///  
/// Constraints:
/// 1. n == patience.length
/// 2. 2 <= n <= 10^5
/// 3. patience[0] == 0
/// 4. 1 <= patience[i] <= 10^5 for 1 <= i < n
/// 5. 1 <= edges.length <= min(10^5, n * (n - 1) / 2)
/// 6. edges[i].length == 2
/// 7. 0 <= ui, vi < n
/// 8. ui != vi
/// 9. There are no duplicate edges.
/// 10. Each server can directly or indirectly reach another server.
/// </summary>
int LeetCodeGraph::networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience)
{
    vector<vector<int>> neighbor(patience.size());
    vector<int> dist(patience.size(), 0);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbor[edges[i][0]].push_back(edges[i][1]);
        neighbor[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> queue;
    queue.push(0);
    int d = 0;
    while (!queue.empty())
    {
        d++;
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            int node = queue.front();
            queue.pop();
            for (size_t j = 0; j < neighbor[node].size(); j++)
            {
                if (neighbor[node][j] == 0 || dist[neighbor[node][j]] != 0)
                {
                    continue;
                }
                dist[neighbor[node][j]] = d;
                queue.push(neighbor[node][j]);
            }
        }
    }
    int result = 0;
    for (size_t i = 1; i < dist.size(); i++)
    {
        int last = (dist[i] * 2 - 1) / patience[i] * patience[i];
        result = max(result, last + 2 * dist[i]);
    }
    return result + 1;
}

/// <summary>
/// Leet Code 2049. Count Nodes With the Highest Score
///                                                                 
/// Medium
///
/// There is a binary tree rooted at 0 consisting of n nodes. The nodes 
/// are labeled from 0 to n - 1. You are given a 0-indexed integer 
/// array parents representing the tree, where parents[i] is 
/// the parent of node i. Since node 0 is the root, parents[0] == -1.
///
/// Each node has a score. To find the score of a node, consider if 
/// the node and the edges connected to it were removed. The tree would 
/// become one or more non-empty subtrees. The size of a subtree is the 
/// number of the nodes in it. The score of the node is the product of 
/// the sizes of all those subtrees.
///
/// Return the number of nodes that have the highest score.
/// 
/// Example 1:
/// Input: parents = [-1,2,0,2,0]
/// Output: 3
/// Explanation:
/// - The score of node 0 is: 3 * 1 = 3
/// - The score of node 1 is: 4 = 4
/// - The score of node 2 is: 1 * 1 * 2 = 2
/// - The score of node 3 is: 4 = 4
/// - The score of node 4 is: 4 = 4
/// The highest score is 4, and three nodes (node 1, node 3, and node 4) 
/// have the highest score.
///
/// Example 2:
/// Input: parents = [-1,2,0]
/// Output: 2
/// Explanation:
/// - The score of node 0 is: 2 = 2
/// - The score of node 1 is: 2 = 2
/// - The score of node 2 is: 1 * 1 = 1
/// The highest score is 2, and two nodes (node 0 and node 1) have the 
/// highest score.
/// 
/// Constraints:
/// 1. n == parents.length
/// 2. 2 <= n <= 10^5
/// 3. parents[0] == -1
/// 4. 0 <= parents[i] <= n - 1 for i != 0
/// 5. parents represents a valid binary tree.
/// </summary>
int LeetCodeGraph::countHighestScoreNodes(vector<int>& parents)
{
    vector<int> degree(parents.size());
    vector<long long> score(parents.size(), 1);
    vector<int> count(parents.size(), 1);
    int result = 0;
    long long max_score = 0;
    for (size_t i = 1; i < parents.size(); i++)
    {
        degree[parents[i]]++;
    }
    queue<int> queue;
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0) queue.push(i);
    }
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        if(node != 0) score[node] = ((long long)parents.size() - (long long)count[node]) * score[node];
        if (score[node] > max_score)
        {
            result = 1;
            max_score = score[node];
        }
        else if (score[node] == max_score)
        {
            result++;
        }
        if (node == 0) break;
        int parent = parents[node];
        score[parent] = score[parent] * (long long)count[node];
        count[parent] += count[node];
        degree[parent]--;
        if (degree[parent] == 0)
        {
            queue.push(parent);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2059. Minimum Operations to Convert Number
///                                                                 
/// Medium
///
/// You are given a 0-indexed integer array nums containing distinct 
/// numbers, an integer start, and an integer goal. There is an integer 
/// x that is initially set to start, and you want to perform operations 
/// on x such that it is converted to goal. You can perform the following 
/// operation repeatedly on the number x:
///
/// If 0 <= x <= 1000, then for any index i in the array 
/// (0 <= i < nums.length), you can set x to any of the following:
///
/// x + nums[i]
/// x - nums[i]
/// x ^ nums[i] (bitwise-XOR)
/// Note that you can use each nums[i] any number of times in any order. 
/// Operations that set x to be out of the range 0 <= x <= 1000 are valid, 
/// but no more operations can be done afterward.
///
/// Return the minimum number of operations needed to convert x = start 
/// into goal, and -1 if it is not possible.
///
/// Example 1:
/// Input: nums = [2,4,12], start = 2, goal = 12
/// Output: 2
/// Explanation: We can go from 2 → 14 → 12 with the following 2 
/// operations.
/// - 2 + 12 = 14
/// - 14 - 2 = 12
///
/// Example 2:
/// Input: nums = [3,5,7], start = 0, goal = -4
/// Output: 2
/// Explanation: We can go from 0 -> 3 -> -4 with the following 2 
/// operations. 
/// - 0 + 3 = 3
/// - 3 - 7 = -4
/// Note that the last operation sets x out of the range 0 <= x <= 1000, 
/// which is valid.
///
/// Example 3:
/// Input: nums = [2,8,16], start = 0, goal = 1
/// Output: -1
/// Explanation: There is no way to convert 0 into 1.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 1000
/// 2. -10^9 <= nums[i], goal <= 10^9
/// 3. 0 <= start <= 1000
/// 4. start != goal
/// 5. All the integers in nums are distinct.
/// </summary>
int LeetCodeGraph::minimumOperations(vector<int>& nums, int start, int goal)
{
    vector<int> visited(1001);
    queue<int> queue;
    queue.push(start);
    int result = 0;
    if (start == goal) return 0;
    while (!queue.empty())
    {
        result++;
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            int node = queue.front();
            queue.pop();
            for (int i = 0; i < (int)nums.size(); i++)
            {
                long long next = (long long)node + (long long)nums[i];
                if (next == goal) return result;
                if (next >= 0 && next <= 1000 && visited[(int)next] == 0)
                {
                    visited[(int)next] = 1;
                    queue.push((int)next);
                }
                next = (long long)node - (long long)nums[i];
                if (next == goal) return result;
                if (next >= 0 && next <= 1000 && visited[(int)next] == 0)
                {
                    visited[(int)next] = 1;
                    queue.push((int)next);
                }
                next = (long long)node ^ (long long)nums[i];
                if (next == goal) return result;
                if (next >= 0 && next <= 1000 && visited[(int)next] == 0)
                {
                    visited[(int)next] = 1;
                    queue.push((int)next);
                }
            }
        }
    }
    return -1;
}

/// <summary>
/// Leet Code 2115. Find All Possible Recipes from Given Supplies
///                                                                 
/// Medium
///
/// You have information about n different recipes. You are given a string 
/// array recipes and a 2D string array ingredients. The ith recipe has 
/// the name recipes[i], and you can create it if you have all the needed 
/// ingredients from ingredients[i]. Ingredients to a recipe may need to 
/// be created from other recipes, i.e., ingredients[i] may contain a 
/// string that is in recipes.
///
/// You are also given a string array supplies containing all the 
/// ingredients that you initially have, and you have an infinite supply 
/// of all of them.
///
/// Return a list of all the recipes that you can create. You may return 
/// the answer in any order.
///
/// Note that two recipes may contain each other in their ingredients.
/// 
/// Example 1:
/// Input: recipes = ["bread"], ingredients = [["yeast","flour"]], 
/// supplies = ["yeast","flour","corn"]
/// Output: ["bread"]
/// Explanation:
/// We can create "bread" since we have the ingredients "yeast" and 
/// "flour".
///
/// Example 2:
/// Input: recipes = ["bread","sandwich"], ingredients = [["yeast",
/// "flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
/// Output: ["bread","sandwich"]
/// Explanation:
/// We can create "bread" since we have the ingredients "yeast" and 
/// "flour".
/// We can create "sandwich" since we have the ingredient "meat" and 
/// can create the ingredient "bread".
///
/// Example 3:
/// Input: recipes = ["bread","sandwich","burger"], ingredients = 
/// [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], 
/// supplies = ["yeast","flour","meat"]
/// Output: ["bread","sandwich","burger"]
///
/// Explanation:
/// We can create "bread" since we have the ingredients "yeast" and 
/// "flour".
/// We can create "sandwich" since we have the ingredient "meat" and 
/// can create the ingredient "bread".
/// We can create "burger" since we have the ingredient "meat" and 
/// can create the ingredients "bread" and "sandwich".
///
/// Constraints:
/// 1. n == recipes.length == ingredients.length
/// 2. 1 <= n <= 100
/// 3. 1 <= ingredients[i].length, supplies.length <= 100
/// 4. 1 <= recipes[i].length, ingredients[i][j].length, 
///    supplies[k].length <= 10
/// 5. recipes[i], ingredients[i][j], and supplies[k] consist only 
///    of lowercase English letters.
/// 6. All the values of recipes and supplies combined are unique.
/// 7. Each ingredients[i] does not contain any duplicate values.
/// </summary>
vector<string> LeetCodeGraph::findAllRecipes(vector<string>& recipes,
    vector<vector<string>>& ingredients,
    vector<string>& supplies)
{
    vector<int> degree(recipes.size());
    unordered_map<string, vector<int>> dependencies;
    for (size_t i = 0; i < ingredients.size(); i++)
    {
        degree[i] = ingredients[i].size();
        for (size_t j = 0; j < ingredients[i].size(); j++)
        {
            dependencies[ingredients[i][j]].push_back(i);
        }
    }
    queue<string> queue;
    for (size_t i = 0; i < supplies.size(); i++)
    {
        queue.push(supplies[i]);
    }
    vector<string> result;
    while (!queue.empty())
    {
        string ingredient = queue.front();
        queue.pop();
        for (size_t i = 0; i < dependencies[ingredient].size(); i++)
        {
            int recipe_id = dependencies[ingredient][i];
            degree[recipe_id]--;
            if (degree[recipe_id] == 0)
            {
                queue.push(recipes[recipe_id]);
                result.push_back(recipes[recipe_id]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2101. Detonate the Maximum Bombs
///                                                                 
/// Medium
///
/// You are given a list of bombs. The range of a bomb is defined as the 
/// area where its effect can be felt. This area is in the shape of a 
/// circle with the center as the location of the bomb.
///
/// The bombs are represented by a 0-indexed 2D integer array bombs where 
/// bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and 
/// Y-coordinate of the location of the ith bomb, whereas ri denotes the 
/// radius of its range.
///
/// You may choose to detonate a single bomb. When a bomb is detonated, 
/// it will detonate all bombs that lie in its range. These bombs will 
/// further detonate the bombs that lie in their ranges.
///
/// Given the list of bombs, return the maximum number of bombs that can 
/// be detonated if you are allowed to detonate only one bomb.
/// 
/// Example 1:
/// 
/// Input: bombs = [[2,1,3],[6,1,4]]
/// Output: 2
/// Explanation:
/// The above figure shows the positions and ranges of the 2 bombs.
/// If we detonate the left bomb, the right bomb will not be affected.
/// But if we detonate the right bomb, both bombs will be detonated.
/// So the maximum bombs that can be detonated is max(1, 2) = 2.
///
/// Example 2:
/// Input: bombs = [[1,1,5],[10,10,5]]
/// Output: 1
/// Explanation:
/// Detonating either bomb will not detonate the other bomb, so the 
/// maximum number of bombs that can be detonated is 1.
///
/// Example 3:
/// Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
/// Output: 5
/// Explanation:
/// The best bomb to detonate is bomb 0 because:
/// - Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of 
///   bomb 0.
/// - Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
/// - Bomb 3 detonates bomb 4. The green circle denotes the range of 
///   bomb 3.
/// Thus all 5 bombs are detonated.
/// Constraints:
/// 1. 1 <= bombs.length <= 100
/// 2. bombs[i].length == 3
/// 3. 1 <= xi, yi, ri <= 10^5
/// </summary>
int LeetCodeGraph::maximumDetonation(vector<vector<int>>& bombs)
{
    vector<vector<int>> neighbors(bombs.size());
    for (size_t i = 0; i < bombs.size(); i++)
    {
        for (size_t j = 0; j < bombs.size(); j++)
        {
            double distance =
                sqrt(((double)bombs[i][0] - (double)bombs[j][0]) * ((double)bombs[i][0] - (double)bombs[j][0]) +
                     ((double)bombs[i][1] - (double)bombs[j][1]) * ((double)bombs[i][1] - (double)bombs[j][1]));
            if (distance <= (double)bombs[i][2])
            {
                neighbors[i].push_back(j);
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < neighbors.size(); i++)
    {
        vector<int> visited(neighbors.size());
        visited[i] = 1;
        queue<int> queue;
        queue.push(i);
        int count = 1;
        while (!queue.empty())
        {
            int node = queue.front();
            queue.pop();
            for (size_t j = 0; j < neighbors[node].size(); j++)
            {
                int next = neighbors[node][j];
                if (visited[next] == 1)
                {
                    continue;
                }
                visited[next] = 1;
                queue.push(next);
                count++;
            }
        }
        result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet Code 2093. Minimum Cost to Reach City With Discounts
///                                                                 
/// Medium
///
/// A series of highways connect n cities numbered from 0 to n - 1. You 
/// are given a 2D integer array highways where highways[i] = [city1i, 
/// city2i, tolli] indicates that there is a highway that connects city1i 
/// and city2i, allowing a car to go from city1i to city2i and vice versa
/// for a cost of tolli.
///
/// You are also given an integer discounts which represents the number of 
/// discounts you have. You can use a discount to travel across the ith 
/// highway for a cost of tolli / 2 (integer division). Each discount may 
/// only be used once, and you can only use at most one discount per 
/// highway.
/// 
/// Return the minimum total cost to go from city 0 to city n - 1, or -1 
/// if it is not possible to go from city 0 to city n - 1.
/// 
/// Example 1:
/// Input: n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], 
/// discounts = 1
/// Output: 9
/// Explanation:
/// Go from 0 to 1 for a cost of 4.
/// Go from 1 to 4 and use a discount for a cost of 11 / 2 = 5.
/// The minimum cost to go from 0 to 4 is 4 + 5 = 9.
///
/// Example 2:
/// Input: n = 4, highways = [[1,3,17],[1,2,7],[3,2,5],[0,1,6],[3,0,20]], 
/// discounts = 20
/// Output: 8
/// Explanation:
/// Go from 0 to 1 and use a discount for a cost of 6 / 2 = 3.
/// Go from 1 to 2 and use a discount for a cost of 7 / 2 = 3.
/// Go from 2 to 3 and use a discount for a cost of 5 / 2 = 2.
/// The minimum cost to go from 0 to 3 is 3 + 3 + 2 = 8.
///
/// Example 3:
/// Input: n = 4, highways = [[0,1,3],[2,3,2]], discounts = 0
/// Output: -1
/// Explanation:
/// It is impossible to go from 0 to 3 so return -1.
/// 
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. 1 <= highways.length <= 1000
/// 3. highways[i].length == 3
/// 4. 0 <= city1i, city2i <= n - 1
/// 5. city1i != city2i
/// 6. 0 <= tolli <= 10^5
/// 7. 0 <= discounts <= 500
/// 8. There are no duplicate highways.
/// </summary>
int LeetCodeGraph::minimumCost(int n, vector<vector<int>>& highways, int discounts)
{
    vector<vector<int>> costs(n, vector<int>(discounts + 1, INT_MAX));
    costs[0][0] = 0;
    priority_queue<vector<int>> pq;
    vector<vector<pair<int, int>>> neighbors(n);
    // build adjacent neighbors
    for (size_t i = 0; i < highways.size(); i++)
    {
        neighbors[highways[i][0]].push_back(make_pair(highways[i][1], highways[i][2]));
        neighbors[highways[i][1]].push_back(make_pair(highways[i][0], highways[i][2]));
    }
    pq.push({ 0, 0, 0 });
    while (!pq.empty())
    {
        int cost = 0 - pq.top()[0];
        int node = pq.top()[1];
        int discount = pq.top()[2];
        pq.pop();
        if (node == n - 1) return cost;
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next_node = neighbors[node][i].first;
            int next_cost = cost + neighbors[node][i].second;
            if (costs[next_node][discount] > next_cost)
            {
                costs[next_node][discount] = next_cost;
                pq.push({ (0 - next_cost), next_node,  discount });
            }
            if (discount < discounts)
            {
                next_cost = cost + neighbors[node][i].second / 2;
                if (costs[next_node][discount+1] > next_cost)
                {
                    costs[next_node][discount+1] = next_cost;
                    pq.push({ (0 - next_cost), next_node,  discount + 1});
                }
            }
        }
    }
    return -1;
}

/// <summary>
/// Leet Code 743. Network Delay Time
///                                                                 
/// Medium
///
/// You are given a network of n nodes, labeled from 1 to n. You are also 
/// given times, a list of travel times as directed edges times[i] = 
/// (ui, vi, wi), where ui is the source node, vi is the target node, and 
/// wi is the time it takes for a signal to travel from source to target.
///
/// We will send a signal from a given node k. Return the time it takes 
/// for all the n nodes to receive the signal. If it is impossible for 
/// all the n nodes to receive the signal, return -1.
///
/// Example 1:
/// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
/// Output: 2
///
/// Example 2:
/// Input: times = [[1,2,1]], n = 2, k = 1
/// Output: 1
///
/// Example 3:
/// Input: times = [[1,2,1]], n = 2, k = 2
/// Output: -1
///
/// Constraints:
/// 1. 1 <= k <= n <= 100
/// 2. 1 <= times.length <= 6000
/// 3. times[i].length == 3
/// 4. 1 <= ui, vi <= n
/// 5. ui != vi
/// 6. 0 <= wi <= 100
/// 7. All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
/// </summary>
int LeetCodeGraph::networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    vector<int> node_times(n+1, INT_MAX);
    priority_queue<pair<int, int>> pq;
    vector<vector<pair<int, int>>> neighbors(n+1);
    for (size_t i = 0; i < times.size(); i++)
    {
        neighbors[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
    }
    pq.push(make_pair(0, k));
    node_times[k] = 0;
    while (!pq.empty())
    {
        pair<int, int> pair = pq.top();
        pq.pop();
        int time = -pair.first;
        int node = pair.second;
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next_node = neighbors[node][i].first;
            int next_time = neighbors[node][i].second;
            if (time + next_time < node_times[next_node])
            {
                node_times[next_node] = time + next_time;
                pq.push(make_pair(-node_times[next_node], next_node));
            }
        }
    }
    int result = 0;
    for (size_t i = 1; i < node_times.size(); i++)
    {
        if (node_times[i] == INT_MAX) return -1;
        result = max(result, node_times[i]);
    }
    return result;
}

/// <summary>
/// Leet Code 2123. Minimum Operations to Remove Adjacent Ones in Matrix
///                                                                 
/// Hard
///
/// You are given a 0-indexed binary matrix grid. In one operation, you 
/// can flip any 1 in grid to be 0.
///
/// A binary matrix is well-isolated if there is no 1 in the matrix 
/// that is 4-directionally connected (i.e., horizontal and vertical) 
/// to another 1.
///
/// Return the minimum number of operations to make grid well-isolated.
///
/// Example 1:
/// Input: grid = [[1,1,0],[0,1,1],[1,1,1]]
/// Output: 3
/// Explanation: Use 3 operations to change grid[0][1], grid[1][2], 
/// and grid[2][1] to 0.
/// After, no more 1's are 4-directionally connected and grid is 
/// well-isolated.
///
/// Example 2:
/// Input: grid = [[0,0,0],[0,0,0],[0,0,0]]
/// Output: 0
/// Explanation: There are no 1's in grid and it is well-isolated.
/// No operations were done so return 0.
///
/// Example 3:
/// Input: grid = [[0,1],[1,0]]
 /// Output: 0
/// Explanation: None of the 1's are 4-directionally connected and grid 
/// is well-isolated.
/// No operations were done so return 0.
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 300
/// 4. grid[i][j] is either 0 or 1.
/// </summary>
int LeetCodeGraph::minimumOperations(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size(), cnt = 0;
    vector<pair<int, int> > D = { {-1,0},{1,0},{0,-1},{0,1} };
    vector<vector<int> > match(m, vector<int>(n, -1));
    vector<vector<int> > vis(m, vector<int>(n, -1));

    function<int(int, int, int)> dfs = [&](int i, int j, int v) 
    {
        for (size_t d = 0; d < D.size(); d++)
        {
            int x = i + D[d].first, y = j + D[d].second;
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] && vis[x][y] != v) 
            {
                vis[x][y] = v;
                // found an augment path
                if (match[x][y] == -1 || dfs(match[x][y] / n, match[x][y] % n, v)) 
                {
                    match[x][y] = i * n + j;
                    match[i][j] = x * n + y;
                    return 1;
                }
            }
        }
        return 0;
    };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] && match[i][j] == -1)
            {
                cnt += dfs(i, j, vis[i][j] = i * n + j);
            }
        }
    }
    return cnt;
}

/// <summary>
/// Leet Code 2127. Maximum Employees to Be Invited to a Meeting
/// </summary>
int LeetCodeGraph::maximumInvitations(vector<vector<int>>& reverse, vector<int>& visited, int node)
{
    queue<int> queue;
    int result = 0;
    queue.push(node);
    while (!queue.empty())
    { 
        result++;
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            int node = queue.front();
            queue.pop();
            for (size_t j = 0; j < reverse[node].size(); j++)
            {
                if (visited[reverse[node][j]] == 0)
                {
                    visited[reverse[node][j]] = 1;
                    queue.push(reverse[node][j]);
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2127. Maximum Employees to Be Invited to a Meeting
/// </summary>
int LeetCodeGraph::maximumInvitations(vector<int>& favorite, vector<int>& visited, int node)
{
    queue<int> queue;
    while (visited[node] == 0)
    {
        visited[node] = 1;
        queue.push(node);
        node = favorite[node];
    }
    while (!queue.empty() && queue.front() != node)
    {
        queue.pop();
    }
    return queue.size();
}

/// <summary>
/// Leet Code 2127. Maximum Employees to Be Invited to a Meeting
///                                                                 
/// Hard
///
/// A company is organizing a meeting and has a list of n employees, 
/// waiting to be invited. They have arranged for a large circular table, 
/// capable of seating any number of employees.
///
/// The employees are numbered from 0 to n - 1. Each employee has a 
/// favorite person and they will attend the meeting only if they can 
/// sit next to their favorite person at the table. The favorite person 
/// of an employee is not themself.
///
/// Given a 0-indexed integer array favorite, where favorite[i] denotes 
/// the favorite person of the ith employee, return the maximum number 
/// of employees that can be invited to the meeting.
///
/// Example 1:
/// Input: favorite = [2,2,1,2]
/// Output: 3
/// Explanation:
/// The above figure shows how the company can invite employees 0, 1, 
/// and 2, and seat them at the round table.
/// All employees cannot be invited because employee 2 cannot sit beside 
/// employees 0, 1, and 3, simultaneously.
/// Note that the company can also invite employees 1, 2, and 3, and 
/// give them their desired seats.
/// The maximum number of employees that can be invited to the meeting is 3. 
///
/// Example 2:
/// Input: favorite = [1,2,0]
/// Output: 3
/// Explanation: 
/// Each employee is the favorite person of at least one other employee, 
/// and the only way the company can invite them is if they invite every 
/// employee.
/// The seating arrangement will be the same as that in the figure given 
/// in example 1:
/// - Employee 0 will sit between employees 2 and 1.
/// - Employee 1 will sit between employees 0 and 2.
/// - Employee 2 will sit between employees 1 and 0.
/// The maximum number of employees that can be invited to the meeting 
/// is 3.
///
/// Example 3:
/// Input: favorite = [3,0,1,4,1]
/// Output: 4
/// Explanation:
/// The above figure shows how the company will invite employees 0, 1, 3, 
/// and 4, and seat them at the round table.
/// Employee 2 cannot be invited because the two spots next to their 
/// favorite employee 1 are taken.
/// So the company leaves them out of the meeting.
/// The maximum number of employees that can be invited to the meeting 
/// is 4.
/// 
/// Constraints:
/// 1. n == favorite.length
/// 2. 2 <= n <= 10^5
/// 3. 0 <= favorite[i] <= n - 1
/// 4. favorite[i] != i
/// </summary>
int LeetCodeGraph::maximumInvitations(vector<int>& favorite)
{
    vector<vector<int>> reverse(favorite.size());
    vector<int> visited(favorite.size());

    for (size_t i = 0; i < favorite.size(); i++)
    {
        if (favorite[favorite[i]] != i)
        {
            reverse[favorite[i]].push_back(i);
        }
    }
    int loop1 = 0;
    int loop2 = 0;
    for (size_t i = 0; i < favorite.size(); i++)
    {
        if (favorite[favorite[i]] == i && visited[i] == 0)
        {
            visited[i] = 1;
            visited[favorite[i]] = 1;
            int sum = maximumInvitations(reverse, visited, i);
            sum += maximumInvitations(reverse, visited, favorite[i]);
            loop1 += sum;
        }
    }
    for (size_t i = 0; i < favorite.size(); i++)
    {
        if (visited[i] == 0)
        {
            loop2 = max(loop2, maximumInvitations(favorite, visited, i));
        }
    }
    return max(loop1, loop2);
}

/// <summary>
/// Leet Code 2146. K Highest Ranked Items Within a Price Range
///                                                                 
/// Medium
///
/// You are given a 0-indexed 2D integer array grid of size m x n that 
/// represents a map of the items in a shop. The integers in the grid 
/// represent the following:
///
/// 0 represents a wall that you cannot pass through.
/// 1 represents an empty cell that you can freely move to and from.
/// All other positive integers represent the price of an item in that 
/// cell. You may also freely move to and from these item cells.
/// It takes 1 step to travel between adjacent grid cells.
///
/// You are also given integer arrays pricing and start where 
/// pricing = [low, high] and start = [row, col] indicates that you 
/// start at the position (row, col) and are interested only in items 
/// with a price in the range of [low, high] (inclusive). You are further 
/// given an integer k.
///
/// You are interested in the positions of the k highest-ranked items 
/// whose prices are within the given price range. The rank is determined 
/// by the first of these criteria that is different:
///
/// Distance, defined as the length of the shortest path from the start 
/// (shorter distance has a higher rank).
/// Price (lower price has a higher rank, but it must be in the price 
/// range).
/// The row number (smaller row number has a higher rank).
/// The column number (smaller column number has a higher rank).
/// Return the k highest-ranked items within the price range sorted by 
/// their rank (highest to lowest). If there are fewer than k reachable 
/// items within the price range, return all of them.
/// 
/// Example 1:
/// Input: grid = [[1,2,0,1],[1,3,0,1],[0,2,5,1]], pricing = [2,5], 
/// start = [0,0], k = 3
/// Output: [[0,1],[1,1],[2,1]]
/// Explanation: You start at (0,0).
/// With a price range of [2,5], we can take items from (0,1), (1,1), 
/// (2,1) and (2,2).
/// The ranks of these items are:
/// - (0,1) with distance 1
/// - (1,1) with distance 2
/// - (2,1) with distance 3
/// - (2,2) with distance 4
/// Thus, the 3 highest ranked items in the price range are (0,1), (1,1), 
/// and (2,1).
///
/// Example 2:
/// Input: grid = [[1,2,0,1],[1,3,3,1],[0,2,5,1]], pricing = [2,3], 
/// start = [2,3], k = 2
/// Output: [[2,1],[1,2]]
/// Explanation: You start at (2,3).
/// With a price range of [2,3], we can take items from (0,1), (1,1), 
/// (1,2) and (2,1).
/// The ranks of these items are:
/// - (2,1) with distance 2, price 2
/// - (1,2) with distance 2, price 3
/// - (1,1) with distance 3
/// - (0,1) with distance 4
/// Thus, the 2 highest ranked items in the price range are (2,1) and 
/// (1,2).
///
/// Example 3:
/// Input: grid = [[1,1,1],[0,0,1],[2,3,4]], pricing = [2,3], 
/// start = [0,0], k = 3
/// Output: [[2,1],[2,0]]
/// Explanation: You start at (0,0).
/// With a price range of [2,3], we can take items from (2,0) and (2,1). 
/// The ranks of these items are: 
/// - (2,1) with distance 5
/// - (2,0) with distance 6
/// Thus, the 2 highest ranked items in the price range are (2,1) 
/// and (2,0). 
/// Note that k = 3 but there are only 2 reachable items within the price 
/// range.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 10^5
/// 4. 1 <= m * n <= 10^5
/// 5. 0 <= grid[i][j] <= 10^5
/// 6. pricing.length == 2
/// 7. 2 <= low <= high <= 10^5
/// 8. start.length == 2
/// 9. 0 <= row <= m - 1
/// 10. 0 <= col <= n - 1
/// 11. grid[row][col] > 0
/// 12. 1 <= k <= m * n
/// </summary>
vector<vector<int>> LeetCodeGraph::highestRankedKItems(vector<vector<int>>& grid,
    vector<int>& pricing, vector<int>& start, int k)
{
    priority_queue<vector<int>> pq;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    vector<vector<int>> visited(m, vector<int>(n));
    queue<vector<int>> queue;
    queue.push(start);
    int distance = 0;
    vector<vector<int>> result;
    if (grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1])
    {
        result.push_back({ start[0], start[1] });
    }
    visited[start[0]][start[1]] = 1;
    while (!queue.empty())
    {
        size_t size = queue.size();
        distance++;
        for (size_t i = 0; i < size; i++)
        {
            vector<int> pos = queue.front();
            queue.pop();
            for (size_t d = 0; d < directions.size(); d++)
            {
                int dy = pos[0];
                int dx = pos[1];
                dy += directions[d][0];
                dx += directions[d][1];
                if (dy < 0 || dy >= m || dx < 0 || dx >= n)
                {
                    continue;
                }
                if (visited[dy][dx] == 1)
                {
                    continue;
                }
                if (grid[dy][dx] == 0)
                {
                    continue;
                }
                if (grid[dy][dx] >= pricing[0] && grid[dy][dx] <= pricing[1])
                {
                    pq.push({-distance, -grid[dy][dx],  -dy,  -dx });
                }
                visited[dy][dx] = 1;
                queue.push({dy, dx});
            }
        }
        while (result.size() < (size_t)k)
        {
            if (pq.empty()) break;
            vector<int>  pos = pq.top();
            pq.pop();
            result.push_back({ -pos[2], -pos[3] });
        }
        if (result.size() >= (size_t)k) break;
    }
    return result;
}

/// <summary>
/// Leet Code 2192. All Ancestors of a Node in a Directed Acyclic Graph
///                                                                                   
/// Medium
///
/// You are given a positive integer n representing the number of nodes 
/// of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to 
/// n - 1 (inclusive).
///
/// You are also given a 2D integer array edges, where edges[i] = 
/// [fromi, toi] denotes that there is a unidirectional edge from fromi 
/// to toi in the graph.
///
/// Return a list answer, where answer[i] is the list of ancestors of 
/// the ith node, sorted in ascending order.
///
/// A node u is an ancestor of another node v if u can reach v via a 
/// set of edges.
/// 
/// Example 1:
/// 
/// Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],
/// [3,6],[3,7],[4,6]] 
/// Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
/// Explanation:
/// The above diagram represents the input graph.
/// - Nodes 0, 1, and 2 do not have any ancestors.
/// - Node 3 has two ancestors 0 and 1.
/// - Node 4 has two ancestors 0 and 2.
/// - Node 5 has three ancestors 0, 1, and 3.
/// - Node 6 has five ancestors 0, 1, 2, 3, and 4.
/// - Node 7 has four ancestors 0, 1, 2, and 3.
///
/// Example 2:
/// Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],
/// [1,3],[1,4],[2,3],[2,4],[3,4]]
/// Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
/// Explanation:
/// The above diagram represents the input graph.
/// - Node 0 does not have any ancestor.
/// - Node 1 has one ancestor 0.
/// - Node 2 has two ancestors 0 and 1.
/// - Node 3 has three ancestors 0, 1, and 2.
/// - Node 4 has four ancestors 0, 1, 2, and 3.
/// Constraints:
/// 1. 1 <= n <= 1000
/// 2. 0 <= edges.length <= min(2000, n * (n - 1) / 2)
/// 3. edges[i].length == 2
/// 4. 0 <= fromi, toi <= n - 1
/// 5. fromi != toi
/// 6. There are no duplicate edges.
/// 7. The graph is directed and acyclic.
/// </summary>
vector<vector<int>> LeetCodeGraph::getAncestors(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> neighbors(n);
    vector<int> degree(n);
    vector<set<int>> parents(n);
    vector<vector<int>> result(n);

    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        degree[edges[i][1]]++;
    }
    queue<int> queue;
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0) queue.push(i);
    }
    while (!queue.empty())
    {
        int x = queue.front();
        queue.pop();
        for (size_t i = 0; i < neighbors[x].size(); i++)
        {
            parents[neighbors[x][i]].insert(parents[x].begin(), parents[x].end());
            parents[neighbors[x][i]].insert(x);
            degree[neighbors[x][i]]--;
            if (degree[neighbors[x][i]] == 0)
            {
                queue.push(neighbors[x][i]);
                result[neighbors[x][i]] = vector<int>(parents[neighbors[x][i]].begin(), parents[neighbors[x][i]].end());
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2201. Count Artifacts That Can Be Extracted
///                                                                                   
/// Medium
///
/// There is an n x n 0-indexed grid with some artifacts buried in it. 
/// You are given the integer n and a 0-indexed 2D integer array 
/// artifacts describing the positions of the rectangular artifacts 
/// where artifacts[i] = [r1i, c1i, r2i, c2i] denotes that the ith 
/// artifact is buried in the subgrid where:
///
/// (r1i, c1i) is the coordinate of the top-left cell of the ith artifact 
/// and
/// (r2i, c2i) is the coordinate of the bottom-right cell of the ith 
/// artifact.
/// You will excavate some cells of the grid and remove all the mud from 
/// them. If the cell has a part of an artifact buried underneath, it 
/// will be uncovered. If all the parts of an artifact are uncovered, you 
/// can extract it.
///
/// Given a 0-indexed 2D integer array dig where dig[i] = [ri, ci] 
/// indicates that you will excavate the cell (ri, ci), return the number 
/// of artifacts that you can extract.
///
/// The test cases are generated such that:
/// No two artifacts overlap.
/// Each artifact only covers at most 4 cells.
/// The entries of dig are unique.
///
/// Example 1:
/// Input: n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], dig = [[0,0],[0,1]]
/// Output: 1
/// Explanation: 
/// The different colors represent different artifacts. Excavated cells 
/// are labeled with a 'D' in the grid.
/// There is 1 artifact that can be extracted, namely the red artifact.
/// The blue artifact has one part in cell (1,1) which remains uncovered, 
/// so we cannot extract it.
/// Thus, we return 1.
///
/// Example 2:
/// Input: n = 2, artifacts = [[0,0,0,0],[0,1,1,1]], 
/// dig = [[0,0],[0,1],[1,1]]
/// Output: 2
/// Explanation: Both the red and blue artifacts have all parts uncovered 
/// (labeled with a 'D') and can be extracted, so we return 2. 
///  
/// Constraints:
/// 1. 1 <= n <= 1000
/// 2. 1 <= artifacts.length, dig.length <= min(n^2, 10^5)
/// 3. artifacts[i].length == 4
/// 4. dig[i].length == 2
/// 5. 0 <= r1i, c1i, r2i, c2i, ri, ci <= n - 1
/// 6. r1i <= r2i
/// 7. c1i <= c2i
/// 8. No two artifacts will overlap.
/// 9. The number of cells covered by an artifact is at most 4.
/// 10. The entries of dig are unique.
/// </summary>
int LeetCodeGraph::digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
{
    vector<int> arr(artifacts.size());
    vector<vector<int>> grid(n, vector<int>(n));
    for (size_t i = 0; i < artifacts.size(); i++)
    {
        for (int r = artifacts[i][0]; r <= artifacts[i][2]; r++)
        {
            for (int c = artifacts[i][1]; c <= artifacts[i][3]; c++)
            {
                grid[r][c] = i + 1;
            }
        }
    }
    for (size_t i = 0; i < dig.size(); i++)
    {
        grid[dig[i][0]][dig[i][1]] = 0;
    }
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] > 0)
            {
                arr[grid[r][c] - 1] = 1;
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i < artifacts.size(); i++)
    {
        if (arr[i] == 0) result++;
    }
    return result;
}

/// <summary>
/// Leet Code 2203. Minimum Weighted Subgraph With the Required Paths
///                                                                                   
/// Hard
///
/// You are given an integer n denoting the number of nodes of a weighted 
/// directed graph. The nodes are numbered from 0 to n - 1.
///
/// You are also given a 2D integer array edges where edges[i] = [fromi, 
/// toi, weighti] denotes that there exists a directed edge from fromi to 
/// toi with weight weighti.
///
/// Lastly, you are given three distinct integers src1, src2, and dest 
/// denoting three distinct nodes of the graph.
///
/// Return the minimum weight of a subgraph of the graph such that it is 
/// possible to reach dest from both src1 and src2 via a set of edges of 
/// this subgraph. In case such a subgraph does not exist, return -1.
///
/// A subgraph is a graph whose vertices and edges are subsets of the 
/// original graph. The weight of a subgraph is the sum of weights of 
/// its constituent edges.
/// 
/// Example 1:
/// Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],
/// [2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
/// Output: 9
/// Explanation: 
/// The above figure represents the input graph.
/// The blue edges represent one of the subgraphs that yield the optimal 
/// answer.
/// Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal 
/// answer. It is not possible to get a subgraph with less weight 
/// satisfying all the constraints.
///
/// Example 2:
/// Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
/// Output: -1
/// Explanation:
/// The above figure represents the input graph.
/// It can be seen that there does not exist any path from node 1 to 
/// node 2, hence there are no subgraphs satisfying all the constraints.
///
/// Constraints:
/// 1. 3 <= n <= 10^5
/// 2. 0 <= edges.length <= 10^5
/// 3. edges[i].length == 3
/// 4. 0 <= fromi, toi, src1, src2, dest <= n - 1
/// 5. fromi != toi
/// 6. src1, src2, and dest are pairwise distinct.
/// 7. 1 <= weight[i] <= 10^5
/// </summary>
long long LeetCodeGraph::minimumWeight(vector<vector<pair<int, int>>>& neighbors, int src, vector<long long>& distances)
{
    priority_queue<pair<long long, int>> pq;
    for (size_t i = 0; i < neighbors[src].size(); i++)
    {
        pq.push(make_pair(0 - neighbors[src][i].second, neighbors[src][i].first));
        distances[neighbors[src][i].first] = min(distances[neighbors[src][i].first], (long long)neighbors[src][i].second);
    }
    while (!pq.empty())
    {
        auto pos = pq.top();
        pq.pop();
        pos.first = 0 - pos.first;
        int next = pos.second;
        if (pos.first > distances[next]) continue;
        for (size_t j = 0; j < neighbors[next].size(); j++)
        {
            long long distance = pos.first + neighbors[next][j].second;
            int target = neighbors[next][j].first;
            if (distances[target] > distance)
            {
                distances[target] = distance;
                pq.push(make_pair(0 - distance, target));
            }
        }
    }
    return LLONG_MAX;
}


/// <summary>
/// Leet Code 2203. Minimum Weighted Subgraph With the Required Paths
///                                                                                   
/// Hard
///
/// You are given an integer n denoting the number of nodes of a weighted 
/// directed graph. The nodes are numbered from 0 to n - 1.
///
/// You are also given a 2D integer array edges where edges[i] = [fromi, 
/// toi, weighti] denotes that there exists a directed edge from fromi to 
/// toi with weight weighti.
///
/// Lastly, you are given three distinct integers src1, src2, and dest 
/// denoting three distinct nodes of the graph.
///
/// Return the minimum weight of a subgraph of the graph such that it is 
/// possible to reach dest from both src1 and src2 via a set of edges of 
/// this subgraph. In case such a subgraph does not exist, return -1.
///
/// A subgraph is a graph whose vertices and edges are subsets of the 
/// original graph. The weight of a subgraph is the sum of weights of 
/// its constituent edges.
/// 
/// Example 1:
/// Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],
/// [2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
/// Output: 9
/// Explanation: 
/// The above figure represents the input graph.
/// The blue edges represent one of the subgraphs that yield the optimal 
/// answer.
/// Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal 
/// answer. It is not possible to get a subgraph with less weight 
/// satisfying all the constraints.
///
/// Example 2:
/// Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
/// Output: -1
/// Explanation:
/// The above figure represents the input graph.
/// It can be seen that there does not exist any path from node 1 to 
/// node 2, hence there are no subgraphs satisfying all the constraints.
///
/// Constraints:
/// 1. 3 <= n <= 10^5
/// 2. 0 <= edges.length <= 10^5
/// 3. edges[i].length == 3
/// 4. 0 <= fromi, toi, src1, src2, dest <= n - 1
/// 5. fromi != toi
/// 6. src1, src2, and dest are pairwise distinct.
/// 7. 1 <= weight[i] <= 10^5
/// </summary>
long long LeetCodeGraph::minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest)
{
    vector<vector<pair<int, int>>> neighbors(n), neighbors_r(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        neighbors_r[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    vector<long long> dist1(n, LLONG_MAX), dist2(n, LLONG_MAX), distd(n, LLONG_MAX);
    dist1[src1] = 0;
    dist2[src2] = 0;
    distd[dest] = 0;
    minimumWeight(neighbors, src1, dist1);
    minimumWeight(neighbors, src2, dist2);
    minimumWeight(neighbors_r, dest, distd);
    long long result = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] == LLONG_MAX || dist2[i] == LLONG_MAX ||
            distd[i] == LLONG_MAX)
        {
            continue;
        }
        result = min(result, dist1[i] + dist2[i] + distd[i]);
    }
    if (result == LLONG_MAX) result = -1;
    return result;
}

/// <summary>
/// Leet Code 2204. Distance to a Cycle in Undirected Graph
/// </summary>
int LeetCodeGraph::distanceToCycle(vector<vector<int>>& neighbors, vector<int>& path, vector<int>& visited)
{
    if (path.empty())
    {
        path.push_back(0);
        visited[0] = 1;
        return distanceToCycle(neighbors, path, visited);
    }
    int prev = path.back();
    for (size_t i = 0; i < neighbors[prev].size(); i++)
    {
        int next = neighbors[prev][i];
        if (visited[next] != 0)
        {
            if (visited[next] == (int)path.size() - 1) continue;
            else
            {
                return visited[next];
            }
        }
        path.push_back(next);
        visited[next] = path.size();
        int ret = distanceToCycle(neighbors, path, visited);
        if (ret != 0) return ret;
        visited[next] = 0;
        path.pop_back();
    }
    return 0;
}


/// <summary>
/// Leet Code 2204. Distance to a Cycle in Undirected Graph
///                                                                                   
/// Hard
///
/// You are given a positive integer n representing the number of nodes 
/// in a connected undirected graph containing exactly one cycle. The 
/// nodes are numbered from 0 to n - 1 (inclusive).
///
/// You are also given a 2D integer array edges, where edges[i] = 
/// [node1i, node2i] denotes that there is a bidirectional edge 
/// connecting node1i and node2i in the graph.
///
/// The distance between two nodes a and b is defined to be the minimum 
/// number of edges that are needed to go from a to b.
/// 
/// Return an integer array answer of size n, where answer[i] is the 
/// minimum distance between the ith node and any node in the cycle.
/// 
/// Example 1:
/// Input: n = 7, edges = [[1,2],[2,3],[3,4],[4,1],[0,1],[5,2],[6,5]]
/// Output: [1,0,0,0,0,1,2]
/// Explanation:
/// The nodes 1, 2, 3, and 4 form the cycle.
/// The distance from 0 to 1 is 1.
/// The distance from 1 to 1 is 0.
/// The distance from 2 to 2 is 0.
/// The distance from 3 to 3 is 0.
/// The distance from 4 to 4 is 0.
/// The distance from 5 to 2 is 1.
/// The distance from 6 to 2 is 2.
///
/// Example 2:
/// Input: n = 9, edges = [[0,1],[1,2],[0,2],[2,6],[6,7],[6,8],[1,3],
/// [3,4],[3,5]]
/// Output: [0,0,0,1,2,2,1,2,2]
/// Explanation:
/// The nodes 0, 1, and 2 form the cycle.
/// The distance from 0 to 0 is 0.
/// The distance from 1 to 1 is 0.
/// The distance from 2 to 2 is 0.
/// The distance from 3 to 1 is 1.
/// The distance from 4 to 1 is 2.
/// The distance from 5 to 1 is 2.
/// The distance from 6 to 2 is 1.
/// The distance from 7 to 2 is 2.
/// The distance from 8 to 2 is 2.
/// 
/// Constraints:
/// 1. 3 <= n <= 10^5
/// 2. edges.length == n
/// 3. edges[i].length == 2
/// 4. 0 <= node1i, node2i <= n - 1
/// 5. node1i != node2i
/// 6. The graph is connected.
/// 7. The graph has exactly one cycle.
/// 8. There is at most one edge between any pair of vertices.
/// </summary>
vector<int> LeetCodeGraph::distanceToCycle(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> path;
    vector<int> visited(n);
    int loop = distanceToCycle(neighbors, path, visited);
    vector<int> result(n, -1);
    queue<int> queue;
    for (int i = loop - 1; i < (int)path.size(); i++)
    {
        queue.push(path[i]);
        result[path[i]] = 0;
    }
    int distance = 0;
    while (!queue.empty())
    {
        distance++;
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            int node = queue.front();
            queue.pop();
            for (size_t j = 0; j < neighbors[node].size(); j++)
            {
                int next = neighbors[node][j];
                if (result[next] == -1)
                {
                    result[next] = distance;
                    queue.push(next);
                }
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2242. Maximum Score of a Node Sequence
///                                                                                      
/// Hard
/// 
/// There is an undirected graph with n nodes, numbered from 0 to n - 1.
///
/// You are given a 0-indexed integer array scores of length n where 
/// scores[i] denotes the score of node i. You are also given a 2D 
/// integer array edges where edges[i] = [ai, bi] denotes that there 
/// exists an undirected edge connecting nodes ai and bi.
///
/// A node sequence is valid if it meets the following conditions:
///
/// There is an edge connecting every pair of adjacent nodes in the 
/// sequence.
/// No node appears more than once in the sequence.
/// The score of a node sequence is defined as the sum of the scores of 
/// the nodes in the sequence.
///
/// Return the maximum score of a valid node sequence with a length of 4. 
/// If no such sequence exists, return -1.
/// 
/// Example 1:
/// Input: scores = [5,2,9,8,4], 
/// edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
/// Output: 24
/// Explanation: The figure above shows the graph and the chosen node 
/// sequence [0,1,2,3].
/// The score of the node sequence is 5 + 2 + 9 + 8 = 24.
/// It can be shown that no other node sequence has a score of more 
/// than 24.
/// Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and 
/// have a score of 24.
/// The sequence [0,3,2,4] is not valid since no edge connects 
/// nodes 0 and 3.
///
/// Example 2:
/// Input: scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
/// Output: -1
/// Explanation: The figure above shows the graph.
/// There are no valid node sequences of length 4, so we return -1.
/// 
/// Constraints:
/// 1. n == scores.length
/// 2. 4 <= n <= 5 * 10^4
/// 3. 1 <= scores[i] <= 10^8
/// 4. 0 <= edges.length <= 5 * 10^4
/// 5. edges[i].length == 2
/// 6. 0 <= ai, bi <= n - 1
/// 7. ai != bi
/// 8. There are no duplicate edges.
/// </summary>
int LeetCodeGraph::maximumScore(vector<int>& scores, vector<vector<int>>& edges)
{
    vector<set<pair<int, int>>> neighbors(scores.size());
    for (size_t i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int z = edges[i][1];
        neighbors[a].insert(make_pair(scores[z], z));
        neighbors[z].insert(make_pair(scores[a], a));
        if (neighbors[a].size() > 3) neighbors[a].erase(neighbors[a].begin());
        if (neighbors[z].size() > 3) neighbors[z].erase(neighbors[z].begin());
    }

    int result = -1;
    for (size_t i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int z = edges[i][1];
        for (auto itr1 : neighbors[a])
        {
            for (auto itr2 : neighbors[z])
            {
                if (itr1.second == z || itr1.second == itr2.second || itr2.second == a)
                {
                    continue;
                }
                result = max(result, scores[a] + scores[z] + itr1.first + itr2.first);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2247. Maximum Cost of Trip With K Highways
/// </summary>
int LeetCodeGraph::maximumCost(int city, vector<vector<pair<int, int>>>& neighbors, vector<vector<int>>& cache, int bit_mask, int remaining)
{
    int max_cost = -1;
    if (remaining == 0) return 0;
    if (cache[city][bit_mask] != 0) return cache[city][bit_mask];
    for (size_t i = 0; i < neighbors[city].size(); i++)
    {
        int next_city = neighbors[city][i].first;
        int cost = neighbors[city][i].second;
        if ((bit_mask & (1 << next_city)) != 0)
        {
            continue;
        }
        int next_cost = maximumCost(next_city, neighbors, cache, bit_mask | (1 << next_city), remaining - 1);
        if (next_cost == -1) continue;
        max_cost = max(max_cost, cost + next_cost);
    }
    cache[city][bit_mask] = max_cost;
    return max_cost;
}

/// <summary>
/// Leet Code 2247. Maximum Cost of Trip With K Highways
///                                                                                      
/// Hard
/// 
/// A series of highways connect n cities numbered from 0 to n - 1. You 
/// are given a 2D integer array highways where highways[i] = [city1i, 
/// city2i, tolli] indicates that there is a highway that connects city1i 
/// and city2i, allowing a car to go from city1i to city2i and vice versa 
/// for a cost of tolli.
///
/// You are also given an integer k. You are going on a trip that crosses 
/// exactly k highways. You may start at any city, but you may only visit 
/// each city at most once during your trip.
///
/// Return the maximum cost of your trip. If there is no trip that meets 
/// the requirements, return -1.
/// 
/// Example 1:
/// Input: n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], 
/// k = 3
/// Output: 17
/// Explanation:
/// One possible trip is to go from 0 -> 1 -> 4 -> 3. The cost of this 
/// trip is 4 + 11 + 2 = 17.
/// Another possible trip is to go from 4 -> 1 -> 2 -> 3. The cost of 
/// this trip is 11 + 3 + 3 = 17.
/// It can be proven that 17 is the maximum possible cost of any valid 
/// trip.
///
/// Note that the trip 4 -> 1 -> 0 -> 1 is not allowed because you visit 
/// the city 1 twice.
///
/// Example 2:
/// Input: n = 4, highways = [[0,1,3],[2,3,2]], k = 2
/// Output: -1
/// Explanation: There are no valid trips of length 2, so return -1.
///
/// Constraints:
/// 1. 2 <= n <= 15
/// 2. 1 <= highways.length <= 50
/// 3. highways[i].length == 3
/// 4. 0 <= city1i, city2i <= n - 1
/// 5. city1i != city2i
/// 6. 0 <= tolli <= 100
/// 7. 1 <= k <= 50
/// 8. There are no duplicate highways.
/// </summary>
int LeetCodeGraph::maximumCost(int n, vector<vector<int>>& highways, int k)
{
    vector<vector<pair<int, int>>> neighbors(n);
    for (size_t i = 0; i < highways.size(); i++)
    {
        neighbors[highways[i][0]].push_back(make_pair(highways[i][1], highways[i][2]));
        neighbors[highways[i][1]].push_back(make_pair(highways[i][0], highways[i][2]));
    }
    vector<vector<int>> cache(n, vector<int>(1 << n));
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        result = max(result, maximumCost(i, neighbors, cache, 1 << i, k));
    }
    return result;
}

/// <summary>
/// Leet Code 2258. Escape the Spreading Fire
/// </summary>
void LeetCodeGraph::maximumMinutes(queue<vector<int>>& queue, vector<vector<int>>& map)
{
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int step = 0;
    int m = map.size();
    int n = map[0].size();
    while (!queue.empty())
    {
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            vector<int> pos = queue.front();
            queue.pop();
            map[pos[0]][pos[1]] = step;
            for (size_t d = 0; d < directions.size(); d++)
            {
                vector<int> next = pos;
                next[0] += directions[d][0];
                next[1] += directions[d][1];
                if (next[0] < 0 || next[0] >= m || next[1] < 0 || next[1] >= n)
                {
                    continue;
                }
                if (map[next[0]][next[1]] != 1000000000)
                {
                    continue;
                }
                map[next[0]][next[1]] = step;
                queue.push(next);
            }
        }
        step++;
    }
}

/// <summary>
/// Leet Code 2258. Escape the Spreading Fire
///                                                           
/// Hard
/// 
/// You are given a 0-indexed 2D integer array grid of size m x n which 
/// represents a field. Each cell has one of three values:
///
/// 0 represents grass,
/// 1 represents fire,
/// 2 represents a wall that you and fire cannot pass through.
/// You are situated in the top-left cell, (0, 0), and you want to travel 
/// to the safehouse at the bottom-right cell, (m - 1, n - 1). Every 
/// minute, you may move to an adjacent grass cell. After your move, 
/// every fire cell will spread to all adjacent cells that are not walls.
///
/// Return the maximum number of minutes that you can stay in your initial 
/// position before moving while still safely reaching the safehouse. 
/// If this is impossible, return -1. If you can always reach the 
/// safehouse regardless of the minutes stayed, return 10^9.
///
/// Note that even if the fire spreads to the safehouse immediately after 
/// you have reached it, it will be counted as safely reaching the 
/// safehouse.
///
/// A cell is adjacent to another cell if the former is directly north, 
/// east, south, or west of the latter (i.e., their sides are touching).
///
/// Example 1:
/// Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],
/// [0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
/// Output: 3
/// Explanation: The figure above shows the scenario where you stay 
/// in the initial position for 3 minutes.
/// You will still be able to safely reach the safehouse.
/// Staying for more than 3 minutes will not allow you to safely reach 
/// the safehouse.
///
/// Example 2:
/// Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
/// Output: -1
/// Explanation: The figure above shows the scenario where you 
/// immediately move towards the safehouse.
/// Fire will spread to any cell you move towards and it is impossible 
/// to safely reach the safehouse.
/// Thus, -1 is returned.
///
/// Example 3:
/// Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
/// Output: 1000000000
/// Explanation: The figure above shows the initial grid.
/// Notice that the fire is contained by walls and you will always 
/// be able to safely reach the safehouse.
/// Thus, 109 is returned.
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 2 <= m, n <= 300
/// 4. 4 <= m * n <= 2 * 10^4
/// 5. grid[i][j] is either 0, 1, or 2.
/// 6. grid[0][0] == grid[m - 1][n - 1] == 0
/// </summary>
int LeetCodeGraph::maximumMinutes(vector<vector<int>>& grid)
{
    const int inf = 1000000000;
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> fire_map(m, vector<int>(n, inf));
    vector<vector<int>> person_map(m, vector<int>(n, inf));
    queue<vector<int>> fire_queue;
    queue<vector<int>> person_queue;
    person_queue.push(vector<int>({ 0, 0 }));
    person_map[0][0] = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                fire_map[i][j] = 0;
                person_map[i][j] = -1;
                fire_queue.push(vector<int>({ i, j }));
            }
            else if (grid[i][j] == 2)
            {
                fire_map[i][j] = -1;
                person_map[i][j] = -1;
            }
        }
    }
    maximumMinutes(fire_queue, fire_map);
    maximumMinutes(person_queue, person_map);
    int result = 0;
    if (person_map[m - 1][n - 1] == inf)
    {
        result = -1;
    }
    else if (fire_map[m - 1][n - 1] < person_map[m - 1][n - 1])
    {
        result = -1;
    }
    else if (fire_map[m - 1][n - 1] == inf)
    {
        result = inf;
    }
    else
    {
        result = fire_map[m - 1][n - 1] - person_map[m - 1][n - 1];
        if (fire_map[m - 2][n - 1] - person_map[m - 2][n - 1] > result ||
            fire_map[m - 1][n - 2] - person_map[m - 1][n - 2] > result)
        {
            result++;
        }
        result--;
    }
    return result;
}

/// <summary>
/// Leet Code 2257. Count Unguarded Cells in the Grid
///                                                           
/// Medium
/// 
/// You are given two integers m and n representing a 0-indexed m x n 
/// grid. You are also given two 2D integer arrays guards and walls 
/// where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent 
/// the positions of the ith guard and jth wall respectively.
///
/// A guard can see every cell in the four cardinal directions (north, 
/// east, south, or west) starting from their position unless obstructed 
/// by a wall or another guard. A cell is guarded if there is at least 
/// one guard that can see it.
///
/// Return the number of unoccupied cells that are not guarded.
/// Example 1:
/// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], 
/// walls = [[0,1],[2,2],[1,4]]
/// Output: 7
/// Explanation: The guarded and unguarded cells are shown in red and 
/// green respectively in the above diagram.
/// There are a total of 7 unguarded cells, so we return 7.
///
/// Example 2:
/// Input: m = 3, n = 3, guards = [[1,1]], 
///        walls = [[0,1],[1,0],[2,1],[1,2]]
/// Output: 4
/// Explanation: The unguarded cells are shown in green in the above 
/// diagram.
/// There are a total of 4 unguarded cells, so we return 4.
/// 
/// Constraints:
/// 1. 1 <= m, n <= 10^5
/// 2. 2 <= m * n <= 10^5
/// 3. 1 <= guards.length, walls.length <= 5 * 10^4
/// 4. 2 <= guards.length + walls.length <= m * n
/// 5. guards[i].length == walls[j].length == 2
/// 6. 0 <= rowi, rowj < m
/// 7. 0 <= coli, colj < n
/// 8. All the positions in guards and walls are unique.
/// </summary>
int LeetCodeGraph::countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
{
    vector<vector<int>> grid(m, vector<int>(n));
    for (size_t i = 0; i < guards.size(); i++)
    {
        grid[guards[i][0]][guards[i][1]] = 0x10;
    }
    for (size_t i = 0; i < walls.size(); i++)
    {
        grid[walls[i][0]][walls[i][1]] = 0x20;
    }
    vector<vector<int>> directions = { { 0, m, 0, n }, {m - 1, -1, n - 1, -1} };
    for (size_t i = 0; i < directions.size(); i++)
    {
        int start_y = directions[i][0];
        int end_y = directions[i][1];
        int step_y = (directions[i][1] - directions[i][0]) / abs((directions[i][1] - directions[i][0]));
        int start_x = directions[i][2];
        int end_x = directions[i][3];
        int step_x = (directions[i][3] - directions[i][2]) / abs((directions[i][3] - directions[i][2]));
        for (int y = start_y; y != end_y; y += step_y)
        {
            for (int x = start_x; x != end_x; x += step_x)
            {
                if ((grid[y][x] & 0x30) != 0) continue;
                if (i == 0)
                {
                    if (y > 0)
                    {
                        if (((grid[y - 1][x] & 0x10) != 0) || ((grid[y - 1][x] & 1) != 0))
                        {
                            grid[y][x] |= 1;
                        }
                    }
                    if (x > 0)
                    {
                        if (((grid[y][x - 1] & 0x10) != 0) || ((grid[y][x - 1] & 2) != 0))
                        {
                            grid[y][x] |= 2;
                        }
                    }
                }
                else
                {
                    if (y < m - 1)
                    {
                        if (((grid[y + 1][x] & 0x10) != 0) || ((grid[y + 1][x] & 4) != 0))
                        {
                            grid[y][x] |= 4;
                        }
                    }
                    if (x < n - 1)
                    {
                        if (((grid[y][x + 1] & 0x10) != 0) || ((grid[y][x + 1] & 8) != 0))
                        {
                            grid[y][x] |= 8;
                        }
                    }
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0) result++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2290. Minimum Obstacle Removal to Reach Corner
///                                                           
/// Hard
/// 
/// You are given a 0-indexed 2D integer array grid of size m x n. Each 
/// cell has one of two values:
///
/// 0 represents an empty cell,
/// 1 represents an obstacle that may be removed.
/// You can move up, down, left, or right from and to an empty cell.
///
/// Return the minimum number of obstacles to remove so you can move from 
/// the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).
/// 
/// Example 1:
/// Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
/// Output: 2
/// Explanation: We can remove the obstacles at (0, 1) and (0, 2) to 
/// create a path from (0, 0) to (2, 2).
/// It can be shown that we need to remove at least 2 obstacles, so we 
/// return 2.
/// Note that there may be other ways to remove 2 obstacles to create a 
/// path.
///
/// Example 2:
/// Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
/// Output: 0
/// Explanation: We can move from (0, 0) to (2, 4) without removing any 
/// obstacles, so we return 0.
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 10^5
/// 4. 2 <= m * n <= 10^5
/// 5. grid[i][j] is either 0 or 1.
/// 6. grid[0][0] == grid[m - 1][n - 1] == 0
/// </summary>
int LeetCodeGraph::minimumObstacles(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    deque<vector<int>> pq;
    distance[0][0] = 0;
    vector<int> node = { 0, 0 };
    pq.push_back(node);
    while (!pq.empty())
    {
        node = pq.front();
        pq.pop_front();
        if (node[0] == n - 1 && node[1] == m - 1)
        {
            break;
        }
        for (size_t d = 0; d < directions.size(); d++)
        {
            int x = node[0];
            int y = node[1];
            int dis = distance[x][y];
            x += directions[d][0];
            y += directions[d][1];
            if (x < 0 || x >= n || y < 0 || y >= m)
            {
                continue;
            }
            if (distance[x][y] != INT_MAX)
            {
                continue;
            }
            if (grid[x][y] == 1)
            {
                dis--;
                pq.push_back({ x, y });
            }
            else
            {
                pq.push_front({ x, y });
            }
            distance[x][y] = dis;
        }
    }
    return distance[n-1][m-1];
}

/// <summary>
/// Leet Code 2307. Check for Contradictions in Equations
///                                                           
/// Hard
/// 
/// You are given a 2D array of strings equations and an array of real 
/// numbers values, where equations[i] = [Ai, Bi] and values[i] means 
/// that Ai / Bi = values[i].
/// Determine if there exists a contradiction in the equations. Return 
/// true if there is a contradiction, or false otherwise.
///
/// Note: When checking if two numbers are equal, check that their 
/// absolute difference is less than 10^-5.
///
/// Example 1:
/// Input: equations = [["a","b"],["b","c"],["a","c"]], 
/// values = [3,0.5,1.5]
/// Output: false
/// Explanation:
/// The given equations are: a / b = 3, b / c = 0.5, a / c = 1.5
/// There are no contradictions in the equations. One possible assignment 
/// to satisfy all equations is:
/// a = 3, b = 1 and c = 2.
///
/// Example 2:
/// Input: equations = [["le","et"],["le","code"],["code","et"]], 
/// values = [2,5,0.5]
/// Output: true
/// Explanation:
/// The given equations are: le / et = 2, le / code = 5, code / et = 0.5
/// Based on the first two equations, we get code / et = 0.4.
/// Since the third equation is code / et = 0.5, we get a contradiction.
/// 
/// Constraints:
/// 1. 1 <= equations.length <= 500
/// 2. equations[i].length == 2 
/// 3. 1 <= Ai.length, Bi.length <= 5
/// 4. Ai, Bi consist of lower case English letters.
/// 5. equations.length == values.length
/// 6. 0.0 < values[i] <= 20.0
/// </summary>
bool LeetCodeGraph::checkContradictions(vector<vector<string>>& equations, vector<double>& values)
{
    unordered_map<string, vector<int>> edges;
    double diff = 0.00001;
    unordered_map<string, double> variables;
    vector<int> visited(equations.size());

    for (size_t i = 0; i < equations.size(); i++)
    {
        string a = equations[i][0];
        string b = equations[i][1];
        edges[a].push_back(i);
        edges[b].push_back(i);
    }

    queue<int> queue;
    for (size_t i = 0; i < equations.size(); i++)
    {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        queue.push(i);
        while (!queue.empty())
        {
            int e = queue.front();
            queue.pop();
            string a = equations[e][0];
            string b = equations[e][1];
            if ((variables.count(a) == 0) && (variables.count(b) == 0))
            {
                variables[a] = 1.0;
                if (a == b && (values[e] -  1) > diff) return true;
                variables[b] = variables[a] / values[e];
            }
            else if (variables.count(a) == 0)
            {
                variables[a] = variables[b] * values[e];
            }
            else if (variables.count(b) == 0)
            {
                variables[b] = variables[a] / values[e];
            }
            else
            {
                if (abs(variables[a] / variables[b] - values[e]) > diff)
                {
                    return true;
                }
            }
            for (auto e : edges[a])
            {
                if (visited[e] == 0)
                {
                    visited[e] = 1;
                    queue.push(e);
                }
            }
            for (auto e : edges[b])
            {
                if (visited[e] == 0)
                {
                    visited[e] = 1;
                    queue.push(e);
                }
            }
        }
    }
    return false;
}

/// <summary>
/// Leet Code 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
///                                                           
/// Medium
///
/// You are given an integer n. There is an undirected graph with n nodes, 
/// numbered from 0 to n - 1. You are given a 2D integer array edges where 
/// edges[i] = [ai, bi] denotes that there exists an undirected edge 
/// connecting nodes ai and bi.
///
/// Return the number of pairs of different nodes that are unreachable 
/// from each other.
///
/// Example 1:
/// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
/// Output: 0
/// Explanation: There are no pairs of nodes that are unreachable from 
/// each other. Therefore, we return 0.
///
/// Example 2:
/// 
/// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
/// Output: 14
/// Explanation: There are 14 pairs of nodes that are unreachable from 
/// each other:
/// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],
/// [3,6], [4,6],[5,6]].
/// Therefore, we return 14.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 0 <= edges.length <= 2 * 10^5
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. ai != bi
/// 6. There are no repeated edges.
/// </summary>
long long LeetCodeGraph::countPairs(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> neighbors(n);
    vector<int> visited(n);
    vector<int> group;
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1) continue;
        queue<int> queue;
        queue.push(i);
        visited[i] = 1;
        int count = 0;
        int parent = i;
        while (!queue.empty())
        {
            int x = queue.front();
            queue.pop();
            count++;
            for (size_t j = 0; j < neighbors[x].size(); j++)
            {
                int y = neighbors[x][j];
                if (visited[y] == 0)
                {
                    visited[y] = 1;
                    queue.push(y);
                }
            }
        }
        group.push_back(count);
    }
    int remaining = n;
    long long result = 0;
    for (size_t i = 0; i < group.size(); i++)
    {
        remaining -= group[i];
        result += ((long long)group[i] * (long long)remaining);
    }
    return result;
}

/// <summary>
/// Leet Code 2322. Minimum Score After Removals on a Tree
/// </summary>
int LeetCodeGraph::minimumScore(int node, vector<int>& nums, vector<vector<int>>& children, vector<int>&xor_vals, 
    vector<unordered_set<int>>& allchildren)
{
    int result = nums[node];
    for (auto child : children[node])
    {
        result = result ^ minimumScore(child, nums, children, xor_vals, allchildren);
        allchildren[node].insert(allchildren[child].begin(), allchildren[child].end());
        allchildren[node].insert(child);
    }
    xor_vals[node] = result;
    return result;
}

/// <summary>
/// Leet Code 2322. Minimum Score After Removals on a Tree
///                                                           
/// Hard
///
/// There is an undirected connected tree with n nodes labeled from 0 to 
/// n - 1 and n - 1 edges.
///
/// You are given a 0-indexed integer array nums of length n where nums[i] 
/// represents the value of the ith node. You are also given a 2D integer 
/// array edges of length n - 1 where edges[i] = [ai, bi] indicates that 
/// there is an edge between nodes ai and bi in the tree.
///
/// Remove two distinct edges of the tree to form three connected 
/// components. For a pair of removed edges, the following steps are 
/// defined:
///
/// Get the XOR of all the values of the nodes for each of the three 
/// components respectively.
/// The difference between the largest XOR value and the smallest XOR 
/// value is the score of the pair.
/// For example, say the three components have the node values: [4,5,7], 
/// [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, 
/// and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR 
/// value is 3. The score is then 8 - 3 = 5.
/// Return the minimum score of any possible pair of edge removals on the 
/// given tree.
/// 
/// Example 1:
/// Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
/// Output: 9
/// Explanation: The diagram above shows a way to make a pair of removals.
/// - The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR 
///   value is 5 ^ 4 ^ 11 = 10.
/// - The 2nd component has node [0] with value [1]. Its XOR value is 
///   1 = 1.
/// - The 3rd component has node [2] with value [5]. Its XOR value 
///   is 5 = 5.
/// The score is the difference between the largest and smallest XOR value 
/// which is 10 - 1 = 9.
/// It can be shown that no other pair of removals will obtain a smaller 
/// score than 9.
///
/// Example 2:
/// Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
/// Output: 0
/// Explanation: The diagram above shows a way to make a pair of removals.
/// - The 1st component has nodes [3,4] with values [4,4]. Its XOR value 
///   is 4 ^ 4 = 0.
/// - The 2nd component has nodes [1,0] with values [5,5]. Its XOR value 
///   is 5 ^ 5 = 0.
/// - The 3rd component has nodes [2,5] with values [2,2]. Its XOR value 
///   is 2 ^ 2 = 0.
/// The score is the difference between the largest and smallest XOR value 
/// which is 0 - 0 = 0.
/// We cannot obtain a smaller score than 0.
/// 
/// Constraints:
/// 1. n == nums.length
/// 2. 3 <= n <= 1000
/// 3. 1 <= nums[i] <= 10^8
/// 4. edges.length == n - 1
/// 5. edges[i].length == 2
/// 6. 0 <= ai, bi < n
/// 7. ai != bi
/// 8. edges represents a valid tree.
/// </summary>
int LeetCodeGraph::minimumScore(vector<int>& nums, vector<vector<int>>& edges)
{
    int n = nums.size();
    vector<int> visited(n), xor_val(n);
    vector<vector<int>> neighbors(n), children(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> queue;
    queue.push(0);
    visited[0] = 1;
    while (!queue.empty())
    {
        int x = queue.front();
        queue.pop();
        for (auto child : neighbors[x])
        {
            if (visited[child] == 1) continue;
            visited[child] = 1;
            children[x].push_back(child);
            queue.push(child);
        }
    }
    vector<unordered_set<int>> allchildren(n);
    minimumScore(0, nums, children, xor_val, allchildren);
    int result = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a, b, c = 0;
            if (allchildren[i].count(j) > 0)
            {
                a = xor_val [0] ^ xor_val[i];
                b = xor_val [i] ^ xor_val[j];
                c = xor_val [j];
                result = min(result, max(max(a, b), c) - min(min(a, b), c));
            }
            else if (allchildren[j].count(i) > 0)
            {
                a = xor_val [0] ^ xor_val[j];
                b = xor_val [i] ^ xor_val[j];
                c = xor_val [i];
                result = min(result, max(max(a, b), c) - min(min(a, b), c));
            }
            else
            {
                a = xor_val [0] ^ xor_val[i] ^ xor_val[j];
                b = xor_val [i];
                c = xor_val [j];
                result = min(result, max(max(a, b), c) - min(min(a, b), c));
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2328. Number of Increasing Paths in a Grid
///                                                           
/// Hard
///
/// You are given an m x n integer matrix grid, where you can move from a 
/// cell to any adjacent cell in all 4 directions.
///
/// Return the number of strictly increasing paths in the grid such that 
/// you can start from any cell and end at any cell. Since the answer may 
/// be very large, return it modulo 10^9 + 7.
/// 
/// Two paths are considered different if they do not have exactly the 
/// same sequence of visited cells.
///
/// Example 1:
/// Input: grid = [[1,1],[3,4]]
/// Output: 8
/// Explanation: The strictly increasing paths are:
/// - Paths with length 1: [1], [1], [3], [4].
/// - Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
/// - Paths with length 3: [1 -> 3 -> 4].
/// The total number of paths is 4 + 3 + 1 = 8.
///
/// Example 2:
/// Input: grid = [[1],[2]]
/// Output: 3
/// Explanation: The strictly increasing paths are:
/// - Paths with length 1: [1], [2].
/// - Paths with length 2: [1 -> 2].
/// The total number of paths is 2 + 1 = 3.
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 1000
/// 4. 1 <= m * n <= 10^5
/// 5. 1 <= grid[i][j] <= 10^5
/// </summary>
int LeetCodeGraph::countPaths(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int M = 1000000007;
    vector<vector<int>> cells;
    vector<vector<int>> dp(m, vector<int>(n));
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cells.push_back({ grid[i][j], i, j });
        }
    }
    sort(cells.begin(), cells.end());
    int result = 0;
    for (size_t i = 0; i < cells.size(); i++)
    {
        int v = cells[i][0];
        int r = cells[i][1];
        int c = cells[i][2];
        dp[r][c] = (dp[r][c] + 1) % M;
        for (size_t d = 0; d < directions.size(); d++)
        {
            int next_r = r + directions[d][0];
            int next_c = c + directions[d][1];
            if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n)
            {
                continue;
            }
            if (grid[next_r][next_c] <= v)
            {
                continue;
            }
            dp[next_r][next_c] = (dp[next_r][next_c] + dp[r][c]) % M;
        }
        result = (result + dp[r][c]) % M;
    }
    return result;
}

/// <summary>
/// Leet Code 2368. Reachable Nodes With Restrictions
///                                                           
/// Medium
///
/// There is an undirected tree with n nodes labeled from 0 to n - 1 and 
/// n - 1 edges.
///
/// You are given a 2D integer array edges of length n - 1 where 
//// edges[i] = [ai, bi] indicates that there is an edge between nodes 
/// ai and bi in the tree. You are also given an integer array restricted 
/// which represents restricted nodes.
///
/// Return the maximum number of nodes you can reach from node 0 without 
/// visiting a restricted node.
///
/// Note that node 0 will not be a restricted node.
///
/// Example 1:
///
/// Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], 
/// restricted = [4,5]
/// Output: 4
/// Explanation: The diagram above shows the tree.
/// We have that [0,1,2,3] are the only nodes that can be reached from 
/// node 0 without visiting a restricted node.
///
/// Example 2:
/// Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], 
/// restricted = [4,2,1]
/// Output: 3
/// Explanation: The diagram above shows the tree.
/// We have that [0,5,6] are the only nodes that can be reached from 
/// node 0 without visiting a restricted node.
///
/// Constraints:
/// 1. 2 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. ai != bi
/// 6. edges represents a valid tree.
/// 7. 1 <= restricted.length < n
/// 8. 1 <= restricted[i] < n
/// 9. All the values of restricted are unique.
/// </summary>
int LeetCodeGraph::reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted)
{
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n);
    for (size_t i = 0; i < restricted.size(); i++) visited[restricted[i]] = 1;
    visited[0] = 1;
    queue<int> queue;
    queue.push(0);
    int result = 0;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        result++;
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next = neighbors[node][i];
            if (visited[next] == 1) continue;
            visited[next] = 1;
            queue.push(next);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2359. Find Closest Node to Given Two Nodes
///                                                  
/// Medium
///
/// You are given a directed graph of n nodes numbered from 0 to n - 1, 
/// where each node has at most one outgoing edge.
/// 
/// The graph is represented with a given 0-indexed array edges of size n, 
/// indicating that there is a directed edge from node i to node edges[i]. 
/// If there is no outgoing edge from i, then edges[i] == -1.
///
/// You are also given two integers node1 and node2.
///
/// Return the index of the node that can be reached from both node1 and 
/// node2, such that the maximum between the distance from node1 to that 
/// node, and from node2 to that node is minimized. If there are multiple 
/// answers, return the node with the smallest index, and if no possible 
/// answer exists, return -1.
///
/// Note that edges may contain cycles.
///
/// Example 1:
/// Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
/// Output: 2
/// Explanation: The distance from node 0 to node 2 is 1, and the 
/// distance from node 1 to node 2 is 1.
/// The maximum of those two distances is 1. It can be proven that we 
/// cannot get a node with a smaller maximum distance than 1, so we 
/// return node 2.
///
/// Example 2:
/// Input: edges = [1,2,-1], node1 = 0, node2 = 2
/// Output: 2
/// Explanation: The distance from node 0 to node 2 is 2, and the 
/// distance from node 2 to itself is 0.
/// The maximum of those two distances is 2. It can be proven that we 
/// cannot get a node with a smaller maximum distance than 2, so we 
/// return node 2.
///
/// Constraints:
/// n == edges.length
/// 2 <= n <= 105
/// -1 <= edges[i] < n
/// edges[i] != i
/// 0 <= node1, node2 < n	
/// </summary>
int LeetCodeGraph::closestMeetingNode(vector<int>& edges, int node1, int node2)
{
    int n = edges.size();
    vector<int> distance1(n, INT_MAX);
    queue<int> queue;
    queue.push(node1);
    int step = 0;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        distance1[node] = step;
        if (edges[node] == -1) continue;
        if (distance1[edges[node]] != INT_MAX) continue;
        queue.push(edges[node]);
        step++;
    }
    vector<int> distance2(n, INT_MAX);
    queue.push(node2);
    step = 0;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        distance2[node] = step;
        if (edges[node] == -1) continue;
        if (distance2[edges[node]] != INT_MAX) continue;
        queue.push(edges[node]);
        step++;
    }
    int result = -1;
    int distance = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (distance1[i] == INT_MAX || distance2[i] == INT_MAX)
        {
            continue;
        }
        if (result == -1 || max(distance1[i], distance2[i]) < distance)
        {
            result = i;
            distance = max(distance1[i], distance2[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2360. Longest Cycle in a Graph
/// </summary>
int LeetCodeGraph::longestCycle(vector<int>& edges, int node, int step, vector<int>& visited,
    vector<int>& path, int& result)
{
    if (node == -1) return result;
    if (path[node] != -1)
    {
        result = max(result, step - path[node]);
        return result;
    }
    else if (visited[node] != 0)
    {
        return result;
    }
    else
    {
        visited[node] = 1;
        path[node] = step;
        longestCycle(edges, edges[node], step + 1, visited, path, result);
        path[node] = -1;
        return result;
    }
}


/// <summary>
/// Leet Code 2360. Longest Cycle in a Graph
///                                                  
/// Hard
///
/// You are given a directed graph of n nodes numbered from 0 to n - 1, 
/// where each node has at most one outgoing edge.
///
/// The graph is represented with a given 0-indexed array edges of size n, 
/// indicating that there is a directed edge from node i to node edges[i]. 
/// If there is no outgoing edge from node i, then edges[i] == -1.
///
/// Return the length of the longest cycle in the graph. If no cycle exists, 
/// return -1.
///
/// A cycle is a path that starts and ends at the same node.
///
/// Example 1:
/// Input: edges = [3,3,4,2,3]
/// Output: 3
/// Explanation: The longest cycle in the graph is the 
/// cycle: 2 -> 4 -> 3 -> 2.
/// The length of this cycle is 3, so 3 is returned.
///
/// Example 2:
/// Input: edges = [2,-1,3,1]
/// Output: -1
/// Explanation: There are no cycles in this graph.
/// 
/// Constraints:
/// 1. n == edges.length
/// 2. 2 <= n <= 10^5
/// 3. -1 <= edges[i] < n
/// 4. edges[i] != i
/// </summary>
int LeetCodeGraph::longestCycle(vector<int>& edges)
{
    int n = edges.size();
    int result = -1;
    vector<int> path(n, -1);
    vector<int> visited(n);
    for (int i = 0; i < n; i++)
    {
        if (path[i] == -1)
        {
            result = max(result, longestCycle(edges, i, 0, visited, path, result));
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2374. Node With Highest Edge Score
///                                                  
/// Medium
///
/// You are given a directed graph with n nodes labeled from 0 to n - 1, 
/// where each node has exactly one outgoing edge.
///
/// The graph is represented by a given 0-indexed integer array edges of 
/// length n, where edges[i] indicates that there is a directed edge from 
/// node i to node edges[i].
///
/// The edge score of a node i is defined as the sum of the labels of all 
/// the nodes that have an edge pointing to i.
///
/// Return the node with the highest edge score. If multiple nodes have 
/// the same edge score, return the node with the smallest index.
///
/// Example 1:
/// Input: edges = [1,0,0,0,0,7,7,5]
/// Output: 7
/// Explanation:
/// - The nodes 1, 2, 3 and 4 have an edge pointing to node 0. The edge 
///   score of node 0 is 1 + 2 + 3 + 4 = 10.
/// - The node 0 has an edge pointing to node 1. The edge score of node 
///   1 is 0.
/// - The node 7 has an edge pointing to node 5. The edge score of 
///   node 5 is 7.
/// - The nodes 5 and 6 have an edge pointing to node 7. The edge score 
///   of node 7 is 5 + 6 = 11.
/// Node 7 has the highest edge score so return 7.
///
/// Example 2:
/// Input: edges = [2,0,0,2]
/// Output: 0
/// Explanation:
/// - The nodes 1 and 2 have an edge pointing to node 0. The edge score 
///  of node 0 is 1 + 2 = 3.
/// - The nodes 0 and 3 have an edge pointing to node 2. The edge score 
///   of node 2 is 0 + 3 = 3.
/// Nodes 0 and 2 both have an edge score of 3. Since node 0 has a 
/// smaller index, we return 0.
/// 
/// Constraints:
/// 1. n == edges.length
/// 2. 2 <= n <= 10^5
/// 3. 0 <= edges[i] < n
/// 4. edges[i] != i
/// </summary>
int LeetCodeGraph::edgeScore(vector<int>& edges)
{
    vector<long long> dp(edges.size());
    for (size_t i = 0; i < edges.size(); i++)
    {
        dp[edges[i]] += (long long)i;
    }
    long long value = 0;
    int result = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (dp[i] > value)
        {
            value = dp[i];
            result = i;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2392. Build a Matrix With Conditions
/// </summary>
vector<int> LeetCodeGraph::buildMatrix(int k, vector<vector<int>>& conditions)
{
    vector<unordered_set<int>> dependencies(k + 1);
    vector<int> degree(k + 1);
    vector<int> position(k + 1, -1);
    for (size_t i = 0; i < conditions.size(); i++)
    {
        if (dependencies[conditions[i][0]].count(conditions[i][1]) > 0)
        {
            continue;
        }
        dependencies[conditions[i][0]].insert(conditions[i][1]);
        degree[conditions[i][1]]++;
    }
    queue<int> q;
    for (int i = 1; i <= k; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
    }
    int row = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        position[node] = row;
        row++;
        for (int next : dependencies[node])
        {
            degree[next]--;
            if (degree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    if (row < k) return vector<int>();
    else return position;
}

/// <summary>
/// Leet Code 2392. Build a Matrix With Conditions
///                                                  
/// Hard
///
/// You are given a positive integer k. You are also given:
///
/// a 2D integer array rowConditions of size n where 
/// rowConditions[i] = [abovei, belowi], and
/// a 2D integer array colConditions of size m where 
/// colConditions[i] = [lefti, righti].
/// The two arrays contain integers from 1 to k.
///
/// You have to build a k x k matrix that contains each of the numbers 
/// from 1 to k exactly once. The remaining cells should have the value 0.
///
/// The matrix should also satisfy the following conditions:
///
/// The number abovei should appear in a row that is strictly above the 
/// row at which the number belowi appears for all i from 0 to n - 1.
/// The number lefti should appear in a column that is strictly left of 
/// the column at which the number righti appears for all i from 0 to 
/// m - 1.
/// Return any matrix that satisfies the conditions. If no answer 
/// exists, return an empty matrix.
/// 
/// Example 1:
/// Input: k = 3, rowConditions = [[1,2],[3,2]], 
/// colConditions = [[2,1],[3,2]]
/// Output: [[3,0,0],[0,0,1],[0,2,0]]
/// Explanation: The diagram above shows a valid example of a matrix 
/// that satisfies all the conditions.
/// The row conditions are the following:
/// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 
///   in the matrix.
/// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 
///   in the matrix.
/// The column conditions are the following:
/// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left 
///   of 1 in the matrix.
/// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left 
///   of 2 in the matrix.
/// Note that there may be multiple correct answers.
///
/// Example 2:
///
/// Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], 
/// colConditions = [[2,1]]
/// Output: []
/// Explanation: From the first two conditions, 3 has to be below 1 but 
/// the third conditions needs 3 to be above 1 to be satisfied.
/// No matrix can satisfy all the conditions, so we return the empty 
/// matrix.
///
/// Constraints:
/// 1. 2 <= k <= 400
/// 2. 1 <= rowConditions.length, colConditions.length <= 10^4
/// 3. rowConditions[i].length == colConditions[i].length == 2
/// 4. 1 <= abovei, belowi, lefti, righti <= k
/// 5. abovei != belowi
/// 6. lefti != righti
/// </summary>
vector<vector<int>> LeetCodeGraph::buildMatrix(int k, vector<vector<int>>& rowConditions,
    vector<vector<int>>& colConditions)
{
    vector<vector<int>> result;
    vector<int> row = buildMatrix(k, rowConditions);
    vector<int> col = buildMatrix(k, colConditions);
    if (row.empty() || col.empty())
    {
        return result;
    }
    result = vector<vector<int>>(k, vector<int>(k));
    for (int i = 1; i <= k; i++)
    {
        result[row[i]][col[i]] = i;
    }
    return result;
}

/// <summary>
/// Leet Code 2421. Number of Good Paths
/// </summary>
int LeetCodeGraph::numberOfGoodPathsMerge(int node, vector<vector<int>>& neighbors, vector<int>& parents, vector<int>& vals)
{
    for (size_t i = 0; i < neighbors[node].size(); i++)
    {
        int a = node;
        int b = neighbors[node][i];
        while (parents[a] != parents[parents[a]]) parents[a] = parents[parents[a]];
        while (parents[b] != parents[parents[b]]) parents[b] = parents[parents[b]];
        if (vals[parents[a]] < vals[parents[b]] || 
            (vals[parents[a]] == vals[parents[b]] && (a < b)))
        {
            parents[parents[b]] = parents[a];
            parents[b] = parents[a];
        }
        else
        {
            parents[parents[a]] = parents[b];
            parents[a] = parents[b];
        }
    }
    return parents[node];
}


/// <summary>
/// Leet Code 2421. Number of Good Paths
///                                                  
/// Hard
///
/// There is a tree (i.e. a connected, undirected graph with no cycles) 
/// consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.
///
/// You are given a 0-indexed integer array vals of length n where vals[i] 
/// denotes the value of the ith node. You are also given a 2D integer 
/// array edges where edges[i] = [ai, bi] denotes that there exists an 
/// undirected edge connecting nodes ai and bi.
/// 
/// A good path is a simple path that satisfies the following conditions:
///
/// The starting node and the ending node have the same value.
/// All nodes between the starting node and the ending node have values 
/// less than or equal to the starting node (i.e. the starting node's 
/// value should be the maximum value along the path).
/// Return the number of distinct good paths.
///
/// Note that a path and its reverse are counted as the same path. For 
/// example, 0 -> 1 is considered to be the same as 1 -> 0. A single node 
/// is also considered as a valid path.
///
/// Example 1:
/// Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
/// Output: 6
/// Explanation: There are 5 good paths consisting of a single node.
/// There is 1 additional good path: 1 -> 0 -> 2 -> 4.
/// (The reverse path 4 -> 2 -> 0 -> 1 is treated as the same 
/// as 1 -> 0 -> 2 -> 4.)
/// Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
///
/// Example 2:
/// Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
/// Output: 7
/// Explanation: There are 5 good paths consisting of a single node.
/// There are 2 additional good paths: 0 -> 1 and 2 -> 3.
///
/// Example 3:
/// Input: vals = [1], edges = []
/// Output: 1
/// Explanation: The tree consists of only one node, so there is one 
/// good path.
/// 
/// Constraints:
/// 1. n == vals.length
/// 2. 1 <= n <= 3 * 10^4
/// 3. 0 <= vals[i] <= 10^5
/// 4. edges.length == n - 1
/// 5. edges[i].length == 2
/// 6. 0 <= ai, bi < n
/// 7. ai != bi
/// 8. edges represents a valid tree.
/// </summary>
int LeetCodeGraph::numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges)
{
    int n = vals.size();
    vector<vector<int>> neighbors(n);
    vector<int> parents(n);
    map<int, set<int>> node_group;
    for (int i = 0; i < n; i++)
    {
        parents[i] = i;
        node_group[vals[i]].insert(i);
    }
    int result = 0;
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (vals[edges[i][1]] <= vals[edges[i][0]])
        {
            neighbors[edges[i][0]].push_back(edges[i][1]);
        }
        else
        {
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }
    }
    for (auto itr : node_group)
    {
        unordered_map<int, int> group;
        for (int node : itr.second)
        {
            int root = numberOfGoodPathsMerge(node, neighbors, parents, vals);
        }
        for (int node : itr.second)
        {
            while (parents[node] != parents[parents[node]]) parents[node] = parents[parents[node]];
            group[parents[node]]++;
        }
        for (auto x : group)
        {
            result += x.second;
            result += x.second * (x.second - 1) / 2;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2467. Most Profitable Path in a Tree
/// 
/// Medium
///	
/// There is an undirected tree with n nodes labeled from 0 to n - 1, 
/// rooted at node 0. You are given a 2D integer array edges of length 
/// n - 1 where edges[i] = [ai, bi] indicates that there is an edge 
/// between nodes ai and bi in the tree.
///
/// At every node i, there is a gate. You are also given an array of 
/// even integers amount, where amount[i] represents:
///
/// the price needed to open the gate at node i, if 
/// amount[i] is negative, or,
/// the cash reward obtained on opening the gate at 
/// node i, otherwise.
/// The game goes on as follows:
/// 
/// Initially, Alice is at node 0 and Bob is at node bob.
/// At every second, Alice and Bob each move to an adjacent node. Alice 
/// moves towards some leaf node, while Bob moves towards node 0.
/// For every node along their path, Alice and Bob either spend money 
/// to open the gate at that node, or accept the reward. Note that:
/// If the gate is already open, no price will be required, nor will 
/// there be any cash reward.
/// If Alice and Bob reach the node simultaneously, they share the 
/// price/reward for opening the gate there. In other words, if the 
/// price to open the gate is c, then both Alice and Bob pay c / 2 each. 
/// Similarly, if the reward at the gate is c, both of them receive 
/// c / 2 each.
/// If Alice reaches a leaf node, she stops moving. Similarly, if Bob 
/// reaches node 0, he stops moving. Note that these events are 
/// independent of each other.
/// Return the maximum net income Alice can have if she travels 
/// towards the optimal leaf node.
///
/// Example 1:
/// Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, 
/// amount = [-2,4,2,-4,6]
/// Output: 6
/// Explanation: 
/// The above diagram represents the given tree. The game goes as follows:
/// - Alice is initially on node 0, Bob on node 3. They open the gates of 
///   their respective nodes.
///  Alice's net income is now -2.
/// - Both Alice and Bob move to node 1. 
///   Since they reach here simultaneously, they open the gate together 
///   and share the reward.
/// Alice's net income becomes -2 + (4 / 2) = 0.
/// - Alice moves on to node 3. Since Bob already opened its gate, Alice's 
///   income remains unchanged.
///  Bob moves on to node 0, and stops moving.
/// - Alice moves on to node 4 and opens the gate there. Her net income 
///   becomes 0 + 6 = 6.
/// Now, neither Alice nor Bob can make any further moves, and the 
/// game ends.
/// It is not possible for Alice to get a higher net income.
///
/// Example 2:
/// 
/// Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
/// Output: -7280
/// Explanation: 
/// Alice follows the path 0->1 whereas Bob follows the path 1->0.
/// Thus, Alice opens the gate at node 0 only. Hence, her net income 
/// is -7280. 
/// 
/// Constraints:
/// 1. 2 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. ai != bi
/// 6. edges represents a valid tree.
/// 7. 1 <= bob < n
/// 8. amount.length == n
/// 9. amount[i] is an even integer in the range [-10^4, 10^4].
/// </summary>
int LeetCodeGraph::mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)
{
    int n = edges.size() + 1;
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>>tree(n);
    vector<int>reverse(n);

    vector<int> visited(n);
    queue<int> queue;
    queue.push(0);
    visited[0] = 1;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next = neighbors[node][i];
            if (visited[next] == 0)
            {
                visited[next] = 1;
                tree[node].push_back(next);
                reverse[next] = node;
                queue.push(next);
            }
        }
    }
    vector<int> bobs(n, -1);
    int b = bob;
    int step = 0;
    while (b != 0)
    {
        bobs[b] = step;
        b = reverse[b];
        step++;
    }
    bobs[b] = step;
    vector<int> alices(n);
    int result = INT_MIN;
    alices[0] = amount[0];
    if (bob == 0) alices[0] = alices[0] / 2;
    queue.push(0);
    step = 0;
    int max_node = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        step++;
        for (int k = 0; k < size; k++)
        {
            int node = queue.front();
            queue.pop();
            for (size_t i = 0; i < tree[node].size(); i++)
            {
                int next = tree[node][i];
                alices[next] += alices[node];
                if (bobs[next] == -1) alices[next] += amount[next];
                else if (bobs[next] > step) alices[next] += amount[next];
                else if (bobs[next] == step) alices[next] += amount[next] / 2;
                else alices[next] += 0;
                queue.push(next);
            }
            if (tree[node].empty())
            {
                if (alices[node] > result) max_node = node;
                result = max(result, alices[node]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2473. Minimum Cost to Buy Apples
/// </summary>
long long LeetCodeGraph::minCost(int start, vector<vector<pair<int, int>>>& neighbors, vector<int>& appleCost, int k)
{
    long long result = LLONG_MAX;
    int distance = 0;
    set<pair<int, int>> pq;
    pq.insert(make_pair(0, start));
    vector<int> visited(neighbors.size());
    while (!pq.empty())
    {
        pair<int, int> pair = *pq.begin();
        pq.erase(pq.begin());
        int distance = pair.first;
        int node = pair.second;
        if (visited[node] == 1) continue;
        visited[node] = 1;
        result = min(result, (long long)appleCost[node-1] + ((long long)1 + (long long)k) * (long long)distance);
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            pq.insert(make_pair(neighbors[node][i].second + distance, neighbors[node][i].first));
        }
    }
    return result;
}


/// <summary>
/// Leet Code 2473. Minimum Cost to Buy Apples
/// 
/// Medium
///	
/// You are given a positive integer n representing n cities numbered 
/// from 1 to n. You are also given a 2D array roads, where 
/// roads[i] = [ai, bi, costi] indicates that there is a bidirectional 
/// road between cities ai and bi with a cost of traveling equal to costi.
///
/// You can buy apples in any city you want, but some cities have 
/// different costs to buy apples. You are given the array appleCost 
/// where appleCost[i] is the cost of buying one apple from city i.
///
/// You start at some city, traverse through various roads, and 
// eventually buy exactly one apple from any city. After you buy that 
/// apple, you have to return back to the city you started at, but 
/// now the cost of all the roads will be multiplied by a given 
/// factor k.
///
/// Given the integer k, return an array answer of size n where 
/// answer[i] is the minimum total cost to buy an apple if you start 
/// at city i.
///
/// Example 1:
/// Input: n = 4, roads = [[1,2,4],[2,3,2],[2,4,5],[3,4,1],[1,3,4]], 
/// appleCost = [56,42,102,301], k = 2
/// Output: [54,42,48,51]
/// Explanation: The minimum cost for each starting city is the following:
/// - Starting at city 1: You take the path 1 -> 2, buy an apple at 
/// city 2, and finally take the path 2 -> 1. The total cost 
/// is 4 + 42 + 4 * 2 = 54.
/// - Starting at city 2: You directly buy an apple at city 2. 
///   The total cost is 42.
/// - Starting at city 3: You take the path 3 -> 2, buy an apple at 
///   city 2, and finally take the path 2 -> 3. The total cost is 
///   2 + 42 + 2 * 2 = 48.
/// - Starting at city 4: You take the path 4 -> 3 -> 2 then you buy at 
///   city 2, and 
///   finally take the path 2 -> 3 -> 4. The total cost is 
///   1 + 2 + 42 + 1 * 2 + 2 * 2 = 51.
///
/// Example 2:
/// Input: n = 3, roads = [[1,2,5],[2,3,1],[3,1,2]], 
/// appleCost = [2,3,1], k = 3
/// Output: [2,3,1]
/// Explanation: It is always optimal to buy the apple in the starting 
/// city.
/// 
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. 1 <= roads.length <= 1000
/// 3. 1 <= ai, bi <= n
/// 4. ai != bi
/// 5. 1 <= costi <= 10^5
/// 6. appleCost.length == n
/// 7. 1 <= appleCost[i] <= 10^5
/// 8. 1 <= k <= 100
/// 9. There are no repeated edges.
/// </summary>
vector<long long> LeetCodeGraph::minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k)
{
    vector<vector<pair<int, int>>> neighbors(n+1);
    for (size_t i = 0; i < roads.size(); i++)
    {
        neighbors[roads[i][0]].push_back(make_pair(roads[i][1], roads[i][2]));
        neighbors[roads[i][1]].push_back(make_pair(roads[i][0], roads[i][2]));
    }
    vector<long long> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = minCost(i + 1, neighbors, appleCost, k);
    }
    return result;
}

/// <summary>
/// Leet Code 2477. Minimum Fuel Cost to Report to the Capital
/// 
/// Medium
///	
/// There is a tree (i.e., a connected, undirected graph with no cycles) 
/// structure country network consisting of n cities numbered from 0 to 
/// n - 1 and exactly n - 1 roads. The capital city is city 0. You are 
/// given a 2D integer array roads where roads[i] = [ai, bi] denotes 
/// that there exists a bidirectional road connecting cities ai and bi.
///
/// There is a meeting for the representatives of each city. The meeting 
/// is in the capital city.
///
/// There is a car in each city. You are given an integer seats that 
/// indicates the number of seats in each car.
///
/// A representative can use the car in their city to travel or change 
/// the car and ride with another representative. The cost of traveling 
/// between two cities is one liter of fuel.
///
/// Return the minimum number of liters of fuel to reach the capital city.
/// 
/// Example 1:
/// Input: roads = [[0,1],[0,2],[0,3]], seats = 5
/// Output: 3
/// Explanation: 
/// - Representative1 goes directly to the capital with 1 liter of fuel.
/// - Representative2 goes directly to the capital with 1 liter of fuel.
/// - Representative3 goes directly to the capital with 1 liter of fuel.
/// It costs 3 liters of fuel at minimum. 
/// It can be proven that 3 is the minimum number of liters of fuel needed.
///
/// Example 2:
/// Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
/// Output: 7
/// Explanation: 
/// - Representative2 goes directly to city 3 with 1 liter of fuel.
/// - Representative2 and representative3 go together to city 1 with 1 
///   liter of fuel.
/// - Representative2 and representative3 go together to the capital 
///   with 1 liter of fuel.
/// - Representative1 goes directly to the capital with 1 liter of fuel.
/// - Representative5 goes directly to the capital with 1 liter of fuel.
/// - Representative6 goes directly to city 4 with 1 liter of fuel.
/// - Representative4 and representative6 go together to the capital with 1 
///   liter of fuel.
/// It costs 7 liters of fuel at minimum. 
/// It can be proven that 7 is the minimum number of liters of fuel needed.
///
/// Example 3:
/// Input: roads = [], seats = 1
/// Output: 0
/// Explanation: No representatives need to travel to the capital city.
///
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. roads.length == n - 1
/// 3. roads[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. ai != bi
/// 6. roads represents a valid tree.
/// 7. 1 <= seats <= 10^5
/// </summary>
long long LeetCodeGraph::minimumFuelCost(vector<vector<int>>& roads, int seats)
{
    int n = 0;
    for (size_t i = 0; i < roads.size(); i++)
    {
        n = max(n, roads[i][0]);
        n = max(n, roads[i][1]);
    }
    n++;
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < roads.size(); i++)
    {
        neighbors[roads[i][0]].push_back(roads[i][1]);
        neighbors[roads[i][1]].push_back(roads[i][0]);
    }
    vector<int> degree(n);
    vector<int> parents(n, -1);
    queue<int> queue;
    queue.push(0);
    parents[0] = 0;
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        for (size_t i = 0; i < neighbors[node].size(); i++)
        {
            int next = neighbors[node][i];
            if (parents[next] != -1) continue;
            parents[next] = node;
            degree[node]++;
            queue.push(next);
        }
    }
    long long result = 0;
    vector<int> people(n, 1);
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 0 && i != 0) queue.push(i);
    }
    while (!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        result = result + ((long long)people[node] + (long long)seats - (long long)1) / (long long)seats;
        int parent = parents[node];
        degree[parent]--;
        people[parent] += people[node];
        if (degree[parent] == 0 && parent != 0) queue.push(parent);
    }
    return result;
}

/// <summary>
/// Leet Code 2492. Minimum Score of a Path Between Two Cities
/// 
/// Medium
///	
/// You are given a positive integer n representing n cities numbered from 
/// 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, 
/// distancei] indicates that there is a bidirectional road between cities 
/// ai and bi with a distance equal to distancei. The cities graph is not 
/// necessarily connected.
///
/// The score of a path between two cities is defined as the minimum 
/// distance of a road in this path.
///
/// Return the minimum possible score of a path between cities 1 and n.
///
/// Note:
/// A path is a sequence of roads between two cities.
/// It is allowed for a path to contain the same road multiple times, and 
/// you can visit cities 1 and n multiple times along the path.
/// The test cases are generated such that there is at least one path 
/// between 1 and n.
/// 
/// Example 1:
/// Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
/// Output: 5
/// Explanation: The path from city 1 to 4 with the minimum score 
/// is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
/// It can be shown that no other path has less score.
///
/// Example 2:
/// Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
/// Output: 2
/// Explanation: The path from city 1 to 4 with the minimum score 
/// is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.
/// Constraints:
/// 1. 2 <= n <= 10^5
/// 2. 1 <= roads.length <= 10^5
/// 3. roads[i].length == 3
/// 4. 1 <= ai, bi <= n
/// 5. ai != bi
/// 6. 1 <= distancei <= 10^4
/// 7. There are no repeated edges.
/// 8. There is at least one path between 1 and n.
/// </summary>
int LeetCodeGraph::minScore(int n, vector<vector<int>>& roads)
{
    set<vector<int>> pq;
    for (size_t i = 0; i < roads.size(); i++)
    {
        pq.insert({ roads[i][2], roads[i][0], roads[i][1] });
    }
    vector<int> parents(n + 1);
    for (int i = 1; i <= n; i++) parents[i] = i;
    vector<int> scores(n + 1, INT_MAX);
    while (!pq.empty())
    {
        vector<int> path = *pq.begin();
        pq.erase(pq.begin());

        int a = path[1];
        int b = path[2];
        while (parents[a] != parents[parents[a]])
        {
            parents[a] = parents[parents[a]];
        }
        while (parents[b] != parents[parents[b]])
        {
            parents[b] = parents[parents[b]];
        }
        a = parents[a];
        b = parents[b];
        parents[b] = a;
        scores[a] = min(scores[a], path[0]);
        scores[a] = min(scores[a], scores[b]);
    }
    while (parents[n] != parents[parents[n]])
    {
        parents[n] = parents[parents[n]];
    }
    return scores[parents[n]];
}


/// <summary>
/// Leet Code 2497. Maximum Star Sum of a Graph
/// 
/// Medium
///	
/// There is an undirected graph consisting of n nodes numbered from 0 
/// to n - 1. You are given a 0-indexed integer array vals of length n 
/// where vals[i] denotes the value of the ith node.
///
/// You are also given a 2D integer array edges where edges[i] = [ai, bi] 
/// denotes that there exists an undirected edge connecting nodes ai 
/// and bi.
///
/// A star graph is a subgraph of the given graph having a center node 
/// containing 0 or more neighbors. In other words, it is a subset of 
/// edges of the given graph such that there exists a common node for 
/// all edges.
///
/// The image below shows star graphs with 3 and 4 neighbors respectively, 
/// centered at the blue node.
///
///
/// The star sum is the sum of the values of all the nodes present in the 
/// star graph.
///
/// Given an integer k, return the maximum star sum of a star graph 
/// containing at most k edges.
///
/// Example 1:
/// Input: vals = [1,2,3,4,10,-10,-20], edges = 
/// [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
/// Output: 16
/// Explanation: The above diagram represents the input graph.
/// The star graph with the maximum star sum is denoted by blue. It is 
/// centered at 3 and includes its neighbors 1 and 4.
/// It can be shown it is not possible to get a star graph with a sum 
/// greater than 16.
///
/// Example 2:
/// 
/// Input: vals = [-5], edges = [], k = 0
/// Output: -5
/// Explanation: There is only one possible star graph, which is node 0 
/// itself.
/// Hence, we return -5.
/// 
/// Constraints:
/// 1. n == vals.length
/// 2. 1 <= n <= 105
/// 3. -104 <= vals[i] <= 104
/// 4. 0 <= edges.length <= min(n * (n - 1) / 2, 105)
/// 5. edges[i].length == 2
/// 6. 0 <= ai, bi <= n - 1
/// 7. ai != bi
/// 8. 0 <= k <= n - 1
/// </summary>
int LeetCodeGraph::maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k)
{
    int n = vals.size();
    vector<priority_queue<int>> pq(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        pq[edges[i][0]].push(vals[edges[i][1]]);
        pq[edges[i][1]].push(vals[edges[i][0]]);
    }
    int result = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = vals[i];
        for (int j = 0; j < k && !pq[i].empty(); j++)
        {
            if (pq[i].top() < 0) break;
            sum += pq[i].top();
            pq[i].pop();
        }
        result = max(result, sum);
    }
    return result;
}

/// <summary>
/// Leet Code 2493. Divide Nodes Into the Maximum Number of Groups
/// 
/// Hard
///	
/// You are given a positive integer n representing the number of nodes 
/// in an undirected graph. The nodes are labeled from 1 to n.
///
/// You are also given a 2D integer array edges, where 
/// edges[i] = [ai, bi] indicates that there is a bidirectional edge 
/// between nodes ai and bi. Notice that the given graph may be 
/// disconnected.
///
/// Divide the nodes of the graph into m groups (1-indexed) such that:
/// Each node in the graph belongs to exactly one group.
/// For every pair of nodes in the graph that are connected by an 
/// edge [ai, bi], if ai belongs to the group with index x, and bi belongs 
/// to the group with index y, then |y - x| = 1.
/// Return the maximum number of groups (i.e., maximum m) into which you 
/// can divide the nodes. Return -1 if it is impossible to group the nodes 
/// with the given conditions.
///
/// Example 1:
/// Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
/// Output: 4
/// Explanation: As shown in the image we:
/// - Add node 5 to the first group.
/// - Add node 1 to the second group.
/// - Add nodes 2 and 4 to the third group.
/// - Add nodes 3 and 6 to the fourth group.
/// We can see that every edge is satisfied.
/// It can be shown that that if we create a fifth group and move any node 
/// from the third or fourth group to it, at least on of the edges will 
/// not be satisfied.
///
/// Example 2:
/// Input: n = 3, edges = [[1,2],[2,3],[3,1]]
/// Output: -1
/// Explanation: If we add node 1 to the first group, node 2 to the second 
/// group, and node 3 to the third group to satisfy the first two edges, 
/// we can see that the third edge will not be satisfied.
/// It can be shown that no grouping is possible.
/// 
/// Constraints:
/// 1. 1 <= n <= 500
/// 2. 1 <= edges.length <= 10^4
/// 3. edges[i].length == 2
/// 4. 1 <= ai, bi <= n
/// 5. ai != bi
/// 6. There is at most one edge between any pair of vertices.
/// </summary>
int LeetCodeGraph::magnificentSets(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> neighbors(n+1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> groups(n + 1);
    vector<int> depths(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int level = 1;
        queue<int>q;
        q.push(i);
        vector<int> levels(n + 1);
        levels[i] = 1;
        while (!q.empty())
        {
            int size = q.size();
            level++;
            for (int j = 0; j < size; j++)
            {
                auto u = q.front();
                q.pop();
                if (groups[u] == 0) groups[u] = i;
                for (int& v : neighbors[u])
                {
                    if (levels[v] == 0)
                    {
                        levels[v] = level;
                        q.push(v);
                    }
                    else
                    {
                        if ((levels[v] % 2) != (level % 2))
                        {
                            return -1;
                        }
                    }
                }
            }
        }
        depths[groups[i]] = max(depths[groups[i]], level - 1);
    }
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result = result + depths[i];
    }
    return result;
}

/// <summary>
/// Leet Code 2503. Maximum Number of Points From Grid Queries
/// 
/// Hard
///	
/// You are given an m x n integer matrix grid and an array queries of 
/// size k.
/// Find an array answer of size k such that for each integer queres[i] 
/// you start in the top left cell of the matrix and repeat the following 
/// process:
///
/// If queries[i] is strictly greater than the value of the current cell 
/// that you are in, then you get one point if it is your first time visiting 
/// this cell, and you can move to any adjacent cell in all 4 directions: 
/// up, down, left, and right.
/// Otherwise, you do not get any points, and you end this process.
/// After the process, answer[i] is the maximum number of points you can get. 
/// Note that for each query you are allowed to visit the same cell multiple 
/// times.
///
/// Return the resulting array answer.
/// 
/// Example 1:
/// Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
/// Output: [5,8,1]
/// Explanation: The diagrams above show which cells we visit to get 
/// points for each query.
///
/// Example 2:
/// Input: grid = [[5,2,1],[1,1,2]], queries = [3]
/// Output: [0]
/// Explanation: We can not get any points because the value of the top 
/// left cell is already greater than or equal to 3.
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 2 <= m, n <= 1000
/// 4. 4 <= m * n <= 10^5
/// 5. k == queries.length
/// 6. 1 <= k <= 10^4
/// 7. 1 <= grid[i][j], queries[i] <= 10^6
/// </summary>
vector<int> LeetCodeGraph::maxPoints(vector<vector<int>>& grid, vector<int>& queries)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> map = grid;
    set<vector<int>> pq;
    vector<vector<int>> visited(m, vector<int>(n));
    pq.insert({ map[0][0], 0, 0 });
    visited[0][0] = 1;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int max_v = 0;
    while (!pq.empty())
    {
        vector<int> pos = *pq.begin();
        max_v = max(max_v, pos[0]);
        pq.erase(pq.begin());
        for (int d = 0; d < (int)directions.size(); d++)
        {
            int next_r = pos[1] + directions[d][0];
            int next_c = pos[2] + directions[d][1];
            if (next_r < 0 || next_r >= m || next_c < 0 || next_c >= n)
            {
                continue;
            }
            if (visited[next_r][next_c] == 1) continue;
            visited[next_r][next_c] = 1;
            map[next_r][next_c] = max(map[next_r][next_c], pos[0]);
            pq.insert({ map[next_r][next_c], next_r, next_c });
        }
    }
    for (size_t i = 0; i < queries.size(); i++)
    {
        max_v = max(max_v, queries[i]);
    }
    vector<int> dp(max_v+1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[map[i][j]]++;
        }
    }
    for (int i = 1; i <= max_v; i++)
    {
        dp[i] = dp[i] + dp[i - 1];
    }
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        result[i] = dp[queries[i] - 1];
    }
    return result;
}

/// <summary>
/// Leet Code 2508. Add Edges to Make Degrees of All Nodes Even
/// 
/// Hard
///	
/// There is an undirected graph consisting of n nodes numbered from 
/// 1 to n. You are given the integer n and a 2D array edges where 
/// edges[i] = [ai, bi] indicates that there is an edge between nodes 
/// ai and bi. The graph can be disconnected.
///
/// You can add at most two additional edges (possibly none) to this 
/// graph so that there are no repeated edges and no self-loops.
///
/// Return true if it is possible to make the degree of each node in 
/// the graph even, otherwise return false.
///
/// The degree of a node is the number of edges connected to it.
/// 
/// Example 1:
/// Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
/// Output: true
/// Explanation: The above diagram shows a valid way of adding an edge.
/// Every node in the resulting graph is connected to an even number of 
/// edges.
///
/// Example 2:
/// Input: n = 4, edges = [[1,2],[3,4]]
/// Output: true
/// Explanation: The above diagram shows a valid way of adding two edges.
///
/// Example 3:
/// Input: n = 4, edges = [[1,2],[1,3],[1,4]]
/// Output: false
/// Explanation: It is not possible to obtain a valid graph with adding 
/// at most 2 edges.
///
/// Constraints:
/// 1. 3 <= n <= 10^5
/// 2. 2 <= edges.length <= 10^5
/// 3. edges[i].length == 2
/// 4. 1 <= ai, bi <= n
/// 5. ai != bi
/// 6. There are no repeated edges.
/// </summary>
bool LeetCodeGraph::isPossible(int n, vector<vector<int>>& edges)
{
    vector<unordered_set<int>> neighbors(n + 1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].insert(edges[i][1]);
        neighbors[edges[i][1]].insert(edges[i][0]);
    }
    vector<int> odds;
    for (int i = 1; i <= n; i++)
    {
        if (neighbors[i].size() % 2 == 1) odds.push_back(i);
    }
    if (odds.empty()) return true;
    if (odds.size() % 2 == 1 || odds.size() > 4) return false;
    if (odds.size() == 2)
    {
        if (neighbors[odds[0]].count(odds[1]) == 0)
        {
            return true;
        }
        for (int i = 1; i <= n; i++)
        {
            if (
                (odds[0] != i) && (odds[1] != i) &&
                (neighbors[odds[0]].count(i) == 0) && 
                (neighbors[odds[1]].count(i) == 0)
                )
            {
                return true;
            }
        }
        return false;
    }
    if (
        (neighbors[odds[0]].count(odds[1]) == 0 &&
         neighbors[odds[2]].count(odds[3]) == 0) ||
        (neighbors[odds[0]].count(odds[2]) == 0 &&
         neighbors[odds[1]].count(odds[3]) == 0) || 
        (neighbors[odds[0]].count(odds[3]) == 0 &&
         neighbors[odds[1]].count(odds[2]) == 0)
        )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet Code 2556. Disconnect Path in a Binary Matrix by at Most One Flip
/// </summary>
bool LeetCodeGraph::isPossibleToCutPath(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c)
{
    if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size())
    {
        return false;
    }
    
    if (grid[r][c] == 0) return false;
    if (visited[r][c] == 1) return false;
    if (r == grid.size() - 1 && c == grid[0].size() - 1)
    {
        return true;
    }
    visited[r][c] = 1;
    bool ret = isPossibleToCutPath(grid, visited, r + 1, c) ||
               isPossibleToCutPath(grid, visited, r, c + 1);
    return ret;
}

/// <summary>
/// Leet Code 2556. Disconnect Path in a Binary Matrix by at Most One Flip
/// 
/// Medium
///	
/// You are given a 0-indexed m x n binary matrix grid. You can move from 
/// a cell (row, col) to any of the cells (row + 1, col) or (row, col + 1) 
/// that has the value 1. The matrix is disconnected if there is no path 
/// from (0, 0) to (m - 1, n - 1).
///
/// You can flip the value of at most one (possibly none) cell. You cannot 
/// flip the cells (0, 0) and (m - 1, n - 1).
///
/// Return true if it is possible to make the matrix disconnect or false 
/// otherwise.
///
/// Note that flipping a cell changes its value from 0 to 1 or from 1 to 0.
///
/// Example 1:
/// Input: grid = [[1,1,1],[1,0,0],[1,1,1]]
/// Output: true
/// Explanation: We can change the cell shown in the diagram above. There 
/// is no path from (0, 0) to (2, 2) in the resulting grid.
///
/// Example 2:
/// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
/// Output: false
/// Explanation: It is not possible to change at most one cell such that 
/// there is not path from (0, 0) to (2, 2).
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 1000
/// 4. 1 <= m * n <= 10^5
/// 5. grid[i][j] is either 0 or 1.
/// 6. grid[0][0] == grid[m - 1][n - 1] == 1
/// </summary>
bool LeetCodeGraph::isPossibleToCutPath(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n));
    if (!isPossibleToCutPath(grid, visited, 0, 0)) return true;
    visited[0][0] = 0;
    visited[m-1][n-1] = 0;
    if (!isPossibleToCutPath(grid, visited, 0, 0)) return true;
    else return false;
}

/// <summary>
/// Leet Code 2577. Minimum Time to Visit a Cell In a Grid
/// 
/// Hard
///	
/// You are given a m x n matrix grid consisting of non-negative integers 
/// where grid[row][col] represents the minimum time required to be able 
/// to visit the cell (row, col), which means you can visit the cell 
/// (row, col) only when the time you visit it is greater than or equal 
/// to grid[row][col].
///
/// You are standing in the top-left cell of the matrix in the 0th second, 
/// and you must move to any adjacent cell in the four directions: up, 
/// down, left, and right. Each move you make takes 1 second.
///
/// Return the minimum time required in which you can visit the 
/// bottom-right cell of the matrix. If you cannot visit the bottom-right 
/// cell, then return -1.
///
/// Example 1:
/// Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
/// Output: 7
/// Explanation: One of the paths that we can take is the following:
/// - at t = 0, we are on the cell (0,0).
/// - at t = 1, we move to the cell (0,1). It is possible because 
///   grid[0][1] <= 1.
/// - at t = 2, we move to the cell (1,1). It is possible because 
///   grid[1][1] <= 2.
/// - at t = 3, we move to the cell (1,2). It is possible because 
///   grid[1][2] <= 3.
/// - at t = 4, we move to the cell (1,1). It is possible because 
///   grid[1][1] <= 4.
/// - at t = 5, we move to the cell (1,2). It is possible because 
///   grid[1][2] <= 5.
/// - at t = 6, we move to the cell (1,3). It is possible because 
///   grid[1][3] <= 6.
/// - at t = 7, we move to the cell (2,3). It is possible because 
///   grid[1][3] <= 7.
/// The final time is 7. It can be shown that it is the minimum time 
/// possible.
///
/// Example 2:
/// Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
/// Output: -1
/// Explanation: There is no path from the top left to the 
/// bottom-right cell.
/// 
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 2 <= m, n <= 1000
/// 4. 4 <= m * n <= 10^5
/// 5. 0 <= grid[i][j] <= 10^5
/// 6. grid[0][0] == 0
/// </summary>
int LeetCodeGraph::minimumTime(vector<vector<int>>& grid)
{
    int m = grid.size(); int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n));
    priority_queue<vector<int>> pq;
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    pq.push({ 0, 0, 0 });
    visited[0][0] = 1;
    while (!pq.empty())
    {
        vector<int> pos = pq.top();
        if (pos[1] == m - 1 && pos[2] == n - 1)
        {
            return -pos[0];
        }
        pq.pop();
        for (size_t d = 0; d < directions.size(); d++)
        {
            vector<int> next = pos;
            next[1] += directions[d][0];
            next[2] += directions[d][1];
            if (next[1] < 0 || next[1] >= m || 
                next[2] < 0 || next[2] >= n)
            {
                continue;
            }
            if (visited[next[1]][next[2]] == 1) continue;
            next[0] = min(pos[0] - 1, -grid[next[1]][next[2]]);
            int diff = pos[0] - 1 + grid[next[1]][next[2]];
            // no space to move
            if (diff > 0 && pos[1] == 0 && pos[2] == 0) continue;

            if (diff > 0 && diff % 2 == 1) next[0]--;
            pq.push(next);
            visited[next[1]][next[2]] = 1;
        }
    }
    return -1;
}

/// <summary>
/// Leet Code 2603. Collect Coins in a Tree
/// 
/// Hard
///	
/// There exists an undirected and unrooted tree with n nodes indexed 
/// from 0 to n - 1. You are given an integer n and a 2D integer array 
/// edges of length n - 1, where edges[i] = [ai, bi] indicates that 
/// there is an edge between nodes ai and bi in the tree. You are also 
/// given an array coins of size n where coins[i] can be either 0 or 1, 
/// where 1 indicates the presence of a coin in the vertex i.
///
/// Initially, you choose to start at any vertex in the tree. Then, you 
/// can perform the following operations any number of times: 
///
/// Collect all the coins that are at a distance of at most 2 from the 
/// current vertex, or
/// Move to any adjacent vertex in the tree.
/// Find the minimum number of edges you need to go through to collect 
/// all the coins and go back to the initial vertex.
///
/// Note that if you pass an edge several times, you need to count it 
/// into the answer several times.
///
/// Example 1:
///
/// Input: coins = [1,0,0,0,0,1], edges = [[0,1],[1,2],[2,3],[3,4],[4,5]]
/// Output: 2
/// Explanation: Start at vertex 2, collect the coin at vertex 0, move to 
/// vertex 3, collect the coin at vertex 5 then move back to vertex 2.
///
/// Example 2:
/// Input: coins = [0,0,0,1,1,0,0,1], edges = [[0,1],[0,2],[1,3],[1,4],
/// [2,5],[5,6],[5,7]]
/// Output: 2
/// Explanation: Start at vertex 0, collect the coins at vertices 4 and 3, 
/// move to vertex 2,  collect the coin at vertex 7, then move back to 
/// vertex 0.
///
/// Constraints:
/// 1. n == coins.length
/// 2. 1 <= n <= 3 * 10^4
/// 3. 0 <= coins[i] <= 1
/// 4. edges.length == n - 1
/// 5. edges[i].length == 2
/// 6. 0 <= ai, bi < n
/// 7. ai != bi
/// 8. edges represents a valid tree.
/// </summary>
int LeetCodeGraph::collectTheCoins(vector<int>& coins, vector<vector<int>>& edges)
{
    int n = coins.size();
    vector<set<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].insert(edges[i][1]);
        neighbors[edges[i][1]].insert(edges[i][0]);
    }
    queue<int> queue;
    for (int i = 0; i < n; i++)
    {
        if (neighbors[i].size() == 1)
        {
            queue.push(i);
        }
    }
    int result = n;
    while (!queue.empty())
    {
        int v = queue.front();
        queue.pop();
        if (neighbors[v].empty()) continue;
        int p = *neighbors[v].begin();
        neighbors[v].erase(p);
        neighbors[p].erase(v);
        if (coins[v] > 0) coins[p] = max(coins[p], coins[v] + 1);
        if (neighbors[p].size() == 1 && coins[p] < 3)
        {
            queue.push(p);
        }
        result--;
    }
    return (max(result, 1) - 1) * 2;
}

/// <summary>
/// Leet Code 2608. Shortest Cycle in a Graph
/// 
/// Hard
///	
/// There is a bi-directional graph with n vertices, where each vertex is 
/// labeled from 0 to n - 1. The edges in the graph are represented by a 
/// given 2D integer array edges, where edges[i] = [ui, vi] denotes an 
/// edge between vertex ui and vertex vi. Every vertex pair is connected 
/// by at most one edge, and no vertex has an edge to itself.
///
/// Return the length of the shortest cycle in the graph. If no cycle 
/// exists, return -1.
///
/// A cycle is a path that starts and ends at the same node, and each edge 
/// in the path is used only once.
/// 
/// Example 1:
/// Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
/// Output: 3
/// Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
///
/// Example 2:
/// Input: n = 4, edges = [[0,1],[0,2]]
/// Output: -1
/// Explanation: There are no cycles in this graph.
///
/// Constraints:
/// 1. 2 <= n <= 1000
/// 2. 1 <= edges.length <= 1000
/// 3. edges[i].length == 2
/// 4. 0 <= ui, vi < n
/// 5. ui != vi
/// 6. There are no repeated edges.
/// </summary>
int LeetCodeGraph::findShortestCycle(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        vector<int> visited(neighbors.size());
        queue<pair<int, int>> queue;
        queue.push(make_pair(-1, i));
        visited[i] = 1;
        while (!queue.empty())
        {
            pair<int, int> v = queue.front();
            queue.pop();
            for (int next :neighbors[v.second])
            {
                if (next == v.first) continue;
                if (visited[next] == 0)
                {
                    visited[next] = visited[v.second] + 1;
                    queue.push(make_pair(v.second, next));
                }
                else
                {
                    result = min(result, visited[v.second] - 1 + visited[next]);
                }
            }
        }
    }
    if (result == INT_MAX) result = -1;
    return result;
}

/// <summary>
/// Leet Code 2617. Minimum Number of Visited Cells in a Grid
/// 
/// Hard
///	
/// You are given a 0-indexed m x n integer matrix grid. Your initial 
/// position is at the top-left cell (0, 0).
///
/// Starting from the cell (i, j), you can move to one of the following 
/// cells:
///
/// Cells (i, k) with j < k <= grid[i][j] + j (rightward movement), or
/// Cells (k, j) with i < k <= grid[i][j] + i (downward movement).
/// Return the minimum number of cells you need to visit to reach the 
/// bottom-right cell (m - 1, n - 1). If there is no valid path, return -1.
///
/// Example 1:
/// Input: grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
/// Output: 4
/// Explanation: The image above shows one of the paths that visits 
/// exactly 4 cells.
///
/// Example 2:
/// Input: grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
/// Output: 3
/// Explanation: The image above shows one of the paths that visits 
/// exactly 3 cells.
///
/// Example 3:
/// Input: grid = [[2,1,0],[1,0,0]]
/// Output: -1
/// Explanation: It can be proven that no path exists.
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 10^5
/// 4. 1 <= m * n <= 10^5
/// 5. 0 <= grid[i][j] < m * n
/// 6. grid[m - 1][n - 1] == 0
/// </summary>
int LeetCodeGraph::minimumVisitedCells(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rows(m, -1), cols(n, -1);

    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    int result = 0;
    while (!queue.empty())
    {
        result++;
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<int, int> pos = queue.front();
            queue.pop();
            int r = pos.first;
            int c = pos.second;
            if (r == m - 1 && c == n - 1) return result;
            int right = min(c + grid[r][c], n - 1);
            int down = min(r + grid[r][c], m - 1);
            for (int k = max(c, rows[r]) + 1; k <= right; k++)
            {
                if (r > cols[k]) queue.push(make_pair(r, k));
            }
            rows[r] = max(rows[r], right);
            for (int k = max(r, cols[c]) + 1; k <= down; k++)
            {
                if (c > rows[k]) queue.push(make_pair(k, c));
            }
            cols[c] = max(cols[c], down);
        }
    }
    return -1;
}

/// <summary>
/// Leet Code 2646. Minimize the Total Price of the Trips
/// </summary>
bool LeetCodeGraph::minimumTotalPrice_FindPath(int prev, int start, int end,
    vector<vector<int>>& neighbors,
    unordered_map<int, int>& node_visited)
{
    if (start == end)
    {
        node_visited[end]++;
        return true;
    }
    for (int next : neighbors[start])
    {
        if (next == prev) continue;
        if (minimumTotalPrice_FindPath(start, next, end, neighbors, node_visited))
        {
            node_visited[start]++;
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet Code 2646. Minimize the Total Price of the Trips
/// </summary>
int LeetCodeGraph::minimumTotalPrice_TotalPrice(
    int prev, int start, bool half,
    vector<vector<int>>& neighbors,
    vector<int>& prices,
    unordered_map<int, int>& node_visited)
{
    int result = 0;
    if (half)
    {
        result += prices[start] / 2 * node_visited[start];
    }
    else
    {
        result += prices[start] * node_visited[start];
    }
    for (int next : neighbors[start])
    {
        if (next == prev) continue;
        int cost = INT_MAX;
        if ((half) || (node_visited[next] == 0))
        {
            cost = minimumTotalPrice_TotalPrice(start, next, false, neighbors,
                prices, node_visited);
        }
        else
        {
            cost = minimumTotalPrice_TotalPrice(start, next, true, neighbors,
                prices, node_visited);
            cost = min(cost, minimumTotalPrice_TotalPrice(start, next, false, 
                neighbors, prices, node_visited));
        }
        result += cost;
    }
    return result;
}

/// <summary>
/// Leet Code 2646. Minimize the Total Price of the Trips
/// 
/// Hard
///	
/// There exists an undirected and unrooted tree with n nodes indexed 
/// from 0 to n - 1. You are given the integer n and a 2D integer array 
/// edges of length n - 1, where edges[i] = [ai, bi] indicates that 
/// there is an edge between nodes ai and bi in the tree.
///
/// Each node has an associated price. You are given an integer array 
/// price, where price[i] is the price of the ith node.
///
/// The price sum of a given path is the sum of the prices of all nodes 
/// lying on that path.
///
/// Additionally, you are given a 2D integer array trips, where 
/// trips[i] = [starti, endi] indicates that you start the ith trip from 
/// the node starti and travel to the node endi by any path you like.
///
/// Before performing your first trip, you can choose some non-adjacent 
/// nodes and halve the prices.
///
/// Return the minimum total price sum to perform all the given trips.
///
/// Example 1:
/// Input: n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], 
/// trips = [[0,3],[2,1],[2,3]]
/// Output: 23
/// Explanation: The diagram above denotes the tree after rooting it 
/// at node 2. The first part shows the initial tree and the second part 
/// shows the tree after choosing nodes 0, 2, and 3, and making their 
/// price half.
/// For the 1st trip, we choose path [0,1,3]. The price sum of that path 
/// is 1 + 2 + 3 = 6.
/// For the 2nd trip, we choose path [2,1]. The price sum of that 
/// path is 2 + 5 = 7.
/// For the 3rd trip, we choose path [2,1,3]. The price sum of that 
/// path is 5 + 2 + 3 = 10.
/// The total price sum of all trips is 6 + 7 + 10 = 23.
/// It can be proven, that 23 is the minimum answer that we can achieve.
///
/// Example 2:
/// Input: n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
/// Output: 1
/// Explanation: The diagram above denotes the tree after rooting it 
/// at node 0. The first part shows the initial tree and the second 
/// part shows the tree after choosing node 0, and making its price half.
/// For the 1st trip, we choose path [0]. The price sum of that path is 1.
/// The total price sum of all trips is 1. It can be proven, that 1 is 
/// the minimum answer that we can achieve.
///
/// Constraints:
/// 1. 1 <= n <= 50
/// 2. edges.length == n - 1
/// 3. 0 <= ai, bi <= n - 1
/// 4. edges represents a valid tree.
/// 5. price.length == n
/// 6. price[i] is an even integer.
/// 7. 1 <= price[i] <= 1000
/// 8. 1 <= trips.length <= 100
/// 9. 0 <= starti, endi <= n - 1
/// </summary>
int LeetCodeGraph::minimumTotalPrice(int n, vector<vector<int>>& edges,
    vector<int>& price, vector<vector<int>>& trips)
{
    unordered_map<int, int> node_visited;
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }

    for (size_t i = 0; i < trips.size(); i++)
    {
        minimumTotalPrice_FindPath(-1, trips[i][0], trips[i][1], neighbors, node_visited);
    }
    int result = minimumTotalPrice_TotalPrice(-1, 0, false, neighbors, price, node_visited);
    result = min(result, minimumTotalPrice_TotalPrice(-1, 0, true, neighbors, price, node_visited));
    return result;
}


/// <summary>
/// Leet Code 2658. Maximum Number of Fish in a Grid
/// 
/// Medium
///	
/// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) 
/// represents:
///
/// A land cell if grid[r][c] = 0, or
/// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
/// A fisher can start at any water cell (r, c) and can do the following 
/// operations any number of times:
/// Catch all the fish at cell (r, c), or
/// Move to any adjacent water cell.
/// Return the maximum number of fish the fisher can catch if he chooses 
/// his starting cell optimally, or 0 if no water cell exists.
///
/// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), 
/// (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
///
/// Example 1:
/// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
/// Output: 7
/// Explanation: The fisher can start at cell (1,3) and collect 3 fish, 
/// then move to cell (2,3) and collect 4 fish.
///
/// Example 2:
/// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
/// Output: 1
/// Explanation: The fisher can start at cells (0,0) or (3,3) and 
/// collect a single fish. 
///
/// Constraints:
/// 1. m == grid.length
/// 2. n == grid[i].length
/// 3. 1 <= m, n <= 10
/// 4. 0 <= grid[i][j] <= 10
/// </summary>
int LeetCodeGraph::findMaxFish(vector<vector<int>>& grid)
{
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> mat = grid;
    int result = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0) continue;
            int sum = mat[i][j];
            mat[i][j] = 0;
            queue<vector<int>> queue;
            queue.push({ i, j });
            while (!queue.empty())
            {
                vector<int> pos = queue.front();
                queue.pop();
                for (size_t k = 0; k < directions.size(); k++)
                {
                    int x = pos[0] + directions[k][0];
                    int y = pos[1] + directions[k][1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (mat[x][y] == 0) continue;
                    if (mat[x][y] > 0)
                    {
                        sum += mat[x][y];
                        mat[x][y] = 0;
                        queue.push({ x, y });
                    }
                }
            }
            result = max(result, sum);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2662. Minimum Cost of a Path With Special Roads
/// 
/// Medium
///	
/// You are given an array start where start = [startX, startY] represents 
/// your initial position (startX, startY) in a 2D space. You are also 
/// given the array target where target = [targetX, targetY] represents 
/// your target position (targetX, targetY).
/// The cost of going from a position (x1, y1) to any other position in 
/// the space (x2, y2) is |x2 - x1| + |y2 - y1|.
/// There are also some special roads. You are given a 2D array 
/// specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] 
/// indicates that the ith special road can take you from (x1i, y1i) to 
/// (x2i, y2i) with a cost equal to costi. You can use each special road 
/// any number of times.
///
/// Return the minimum cost required to go from (startX, startY) to 
/// (targetX, targetY).
///
/// Example 1:
/// Input: start = [1,1], target = [4,5], 
/// specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
/// Output: 5
/// Explanation: The optimal path from (1,1) to (4,5) is the following:
/// - (1,1) -> (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
/// - (1,2) -> (3,3). This move uses the first special edge, the cost is 2.
/// - (3,3) -> (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
/// - (3,4) -> (4,5). This move uses the second special edge, the cost 
///   is 1.
/// So the total cost is 1 + 2 + 1 + 1 = 5.
/// It can be shown that we cannot achieve a smaller total cost than 5.
///
/// Example 2:
/// Input: start = [3,2], target = [5,7], specialRoads = 
/// [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
/// Output: 7
/// Explanation: It is optimal to not use any special edges and go 
/// directly from the starting to the ending position with a 
/// cost |5 - 3| + |7 - 2| = 7.
/// 
/// Constraints:
/// 1. start.length == target.length == 2
/// 2. 1 <= startX <= targetX <= 10^5
/// 3. 1 <= startY <= targetY <= 10^5
/// 4. 1 <= specialRoads.length <= 200
/// 5. specialRoads[i].length == 5
/// 6. startX <= x1i, x2i <= targetX
/// 7. startY <= y1i, y2i <= targetY
/// 8. 1 <= costi <= 10^5
/// </summary>
int LeetCodeGraph::minimumCost(vector<int>& start, vector<int>& target,
    vector<vector<int>>& specialRoads)
{
    unordered_map<int, unordered_map<int, int>> distance;
    distance[start[0]][start[1]] = 0;
    distance[target[0]][target[1]] = 
        abs(start[0] - target[0]) + abs(start[1] - target[1]);
    set<vector<int>> pq;
    pq.insert({ 0, start[0], start[1] });
    pq.insert({ distance[target[0]][target[1]], target[0], target[1] });
    for (size_t i = 0; i < specialRoads.size(); i++)
    {
        int x = specialRoads[i][0];
        int y = specialRoads[i][1];
        distance[x][y] =
            abs(start[0] - x) + abs(start[1] - y);
        pq.insert({ distance[x][y], x, y });
    }
    while (!pq.empty())
    {
        vector<int> pos = *pq.begin();
        pq.erase(pq.begin());
        int d = pos[0];
        int x = pos[1];
        int y = pos[2];
        if (x == target[0] && y == target[1]) return d;
        for (size_t i = 0; i < specialRoads.size(); i++)
        {
            int x1 = specialRoads[i][0];
            int y1 = specialRoads[i][1];
            int x2 = specialRoads[i][2];
            int y2 = specialRoads[i][3];
            int cost = specialRoads[i][4];
            if (x == x1 && y == y1)
            {
                if (distance[x2][y2] == 0)
                {
                    distance[x2][y2] = d + cost;
                    pq.insert({ distance[x2][y2], x2, y2 });
                }
                else if (distance[x2][y2] > d + cost)
                {
                    pq.erase({ distance[x2][y2], x2, y2 });
                    distance[x2][y2] = d + cost;
                    pq.insert({ distance[x2][y2], x2, y2 });
                }
            }
            else 
            {
                int cost = abs(x - x1) + abs(y - y1);
                if (distance[x1][y1] > d + cost)
                {
                    pq.erase({ distance[x1][y1], x1, y1 });
                    distance[x1][y1] = d + cost;
                    pq.insert({ distance[x1][y1], x1, y1 });
                }
            }
        }
        int x1 = target[0];
        int y1 = target[1];
        int cost = abs(x - x1) + abs(y - y1);
        if (distance[x1][y1] > d + cost)
        {
            pq.erase({ distance[x1][y1], x1, y1 });
            distance[x1][y1] = d + cost;
            pq.insert({ distance[x1][y1], x1, y1 });
        }
    }
    return -1;
}

/// <summary>
/// Leet Code 2685. Count the Number of Complete Components
/// 
/// Medium
///	
/// You are given an integer n. There is an undirected graph with n 
/// vertices, numbered from 0 to n - 1. You are given a 2D integer 
/// array edges where edges[i] = [ai, bi] denotes that there exists 
/// an undirected edge connecting vertices ai and bi.
/// 
/// Return the number of complete connected components of the graph.
///
/// A connected component is a subgraph of a graph in which there 
/// exists a path between any two vertices, and no vertex of the 
/// subgraph shares an edge with a vertex outside of the subgraph.
///
/// A connected component is said to be complete if there exists 
/// an edge between every pair of its vertices.
///
/// Example 1:
/// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
/// Output: 3
/// Explanation: From the picture above, one can see that all of 
/// the components of this graph are complete.
///
/// Example 2:
/// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
/// Output: 1
/// Explanation: The component containing vertices 0, 1, and 2 is 
/// complete since there is an edge between every pair of two 
/// vertices. On the other hand, the component containing vertices 3, 4, 
/// and 5 is not complete since there is no edge between vertices 4 
/// and 5. Thus, the number of complete components in this graph is 1.
///
///
/// Constraints:
/// 1. 1 <= n <= 50
/// 2. 0 <= edges.length <= n * (n - 1) / 2
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi <= n - 1
/// 5. ai != bi
/// 6. There are no repeated edges.
/// </summary>
int LeetCodeGraph::countCompleteComponents(int n, vector<vector<int>>& edges)
{
    unordered_map<int, set<int>> neighbors;
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].insert(edges[i][1]);
        neighbors[edges[i][1]].insert(edges[i][0]);
    }
    vector<bool> visited(n, false);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int count = 1;
            visited[i] = true;
            neighbors[i].insert(i);
            for (auto k : neighbors[i])
            {
                if (k == i) continue;
                if (visited[k])
                {
                    count = 0;
                    continue;
                }
                visited[k] = true;
                neighbors[k].insert(k);
                if (neighbors[k] != neighbors[i])
                {
                    count = 0;
                }
            }
            result += count;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2699. Modify Graph Edge Weights
/// </summary>
int LeetCodeGraph::modifiedGraphEdges(vector<unordered_map<int, int>>& neighbors,
    int source, int destination)
{
    // calculate shortest distance from source to destination
    int n = neighbors.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({ 0, source });
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;
    while (!pq.empty())
    {
        int curr_node = pq.top()[1];
        if (curr_node == destination) break;
        int curr_dist = pq.top()[0];
        pq.pop();
        if (distance[curr_node] < curr_dist) continue;
        for (auto itr : neighbors[curr_node])
        {
            int next = itr.first;
            int dist = itr.second;
            if (distance[next] > curr_dist + dist)
            {
                distance[next] = curr_dist + dist;
                pq.push({ distance[next], next });
            }
        }
    }
    return distance[destination];
}

/// <summary>
/// Leet Code 2699. Modify Graph Edge Weights
/// 
/// Hard
///	
/// You are given an undirected weighted connected graph containing n 
/// nodes labeled from 0 to n - 1, and an integer array edges where 
/// edges[i] = [ai, bi, wi] indicates that there is an edge between 
/// nodes ai and bi with weight wi.
///
/// Some edges have a weight of -1 (wi = -1), while others have a 
/// positive weight (wi > 0).
///
/// Your task is to modify all edges with a weight of -1 by assigning 
/// them positive integer values in the range [1, 2 * 109] so that the 
/// shortest distance between the nodes source and destination becomes 
/// equal to an integer target. If there are multiple modifications 
/// that make the shortest distance between source and destination equal 
/// to target, any of them will be considered correct.
///
/// Return an array containing all edges (even unmodified ones) in any 
/// order if it is possible to make the shortest distance from source 
/// to destination equal to target, or an empty array if it's impossible.
///
/// Note: You are not allowed to modify the weights of edges with initial 
/// positive weights.
///
/// Example 1:
/// Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], 
/// source = 0, destination = 1, target = 5
/// Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
/// Explanation: The graph above shows a possible modification to the 
/// edges, making the distance from 0 to 1 equal to 5.
/// 
/// Example 2:
/// Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, 
/// target = 6
/// Output: []
/// Explanation: The graph above contains the initial edges. It is not 
/// possible to make the distance from 0 to 2 equal to 6 by modifying the 
/// edge with weight -1. So, an empty array is returned.
///
/// Example 3:
/// Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, 
/// destination = 2, target = 6
/// Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
/// Explanation: The graph above shows a modified graph having the 
/// shortest distance from 0 to 2 as 6.
///
/// Constraints:
/// 1. 1 <= n <= 100
/// 2. 1 <= edges.length <= n * (n - 1) / 2
/// 3. edges[i].length == 3
/// 4. 0 <= ai, bi < n
/// 5. wi = -1 or 1 <= wi <= 10^7
/// 6. ai != bi
/// 7. 0 <= source, destination < n
/// 8. source != destination
/// 9. 1 <= target <= 10^9
/// 10. The graph is connected, and there are no self-loops or repeated 
///     edges
/// </summary>
vector<vector<int>> LeetCodeGraph::modifiedGraphEdges(int n, 
    vector<vector<int>>& edges,
    int source, int destination, int target)
{
    vector<unordered_map<int, int>> neighbors(n);
    queue<int> blocks;
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (edges[i][2] != -1)
        {
            neighbors[edges[i][0]][edges[i][1]] = edges[i][2];
            neighbors[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        else
        {
            blocks.push(i);
        }
    }
    int distance = modifiedGraphEdges(neighbors, source, destination);
    if (distance < target) return {};
    while (!blocks.empty())
    {
        int index = blocks.front();
        blocks.pop();
        vector<int> edge = edges[index];
        neighbors[edge[0]][edge[1]] = 1;
        neighbors[edge[1]][edge[0]] = 1;
        edges[index][2] = 1;
        distance = modifiedGraphEdges(neighbors, source, destination);
        if (distance <= target)
        {
            edges[index][2] += target - distance;
            break;
        }
    }
    while (!blocks.empty())
    {
        int index = blocks.front();
        blocks.pop();
        vector<int> edge = edges[index];
        edges[index][2] = (int)2e9;
    }
    if (distance > target) return {};
    return edges;
}

/// <summary>
/// Leet Code 2713. Maximum Strictly Increasing Cells in a Matrix
/// 
/// Hard
///
/// Given a 1-indexed m x n integer matrix mat, you can select any cell 
/// in the matrix as your starting cell.
///
/// From the starting cell, you can move to any other cell in the same 
/// row or column, but only if the value of the destination cell is 
/// strictly greater than the value of the current cell. You can repeat 
/// this process as many times as possible, moving from cell to cell 
/// until you can no longer make any moves.
///
/// Your task is to find the maximum number of cells that you can visit 
/// in the matrix by starting from some cell.
///
/// Return an integer denoting the maximum number of cells that can be 
/// visited.
/// 
/// Example 1:
/// Input: mat = [[3,1],[3,4]]
/// Output: 2
/// Explanation: The image shows how we can visit 2 cells starting from 
/// row 1, column 2. It can be shown that we cannot visit more than 2 
/// cells no matter where we start from, so the answer is 2. 
///
/// Example 2:
/// Input: mat = [[1,1],[1,1]]
/// Output: 1
/// Explanation: Since the cells must be strictly increasing, we can 
/// only visit one cell in this example. 
///
/// Example 3:
/// Input: mat = [[3,1,6],[-9,5,7]]
/// Output: 4
/// Explanation: The image above shows how we can visit 4 cells starting 
/// from row 2, column 1. It can be shown that we cannot visit more 
/// than 4 cells no matter where we start from, so the answer is 4. 
/// 
/// Constraints:
/// 1. m == mat.length 
/// 2. n == mat[i].length 
/// 3. 1 <= m, n <= 10^5
/// 4. 1 <= m * n <= 10^5
/// 5. -10^5 <= mat[i][j] <= 10^5
/// </summary>
int LeetCodeGraph::maxIncreasingCells(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<pair<int, int>>> rows(m, vector<pair<int, int>>(2, { INT_MAX, 0 }));
    vector<vector<pair<int, int>>> cols(n, vector<pair<int, int>>(2, { INT_MAX, 0 }));
    map<int, vector<pair<int, int>>> mat_group;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat_group[mat[i][j]].push_back(make_pair(i, j));
        }
    }
    int result = 0;
    for (auto itr : mat_group)
    {
        int v = itr.first;
        for (size_t i = 0; i < itr.second.size(); i++)
        {
            int length = 1;
            int r = itr.second[i].first;
            int c = itr.second[i].second;
            if (rows[r][0].first < v)
            {
                rows[r][1] = rows[r][0];
            }
            length = max(length, rows[r][1].second + 1);
            if (cols[c][0].first < v)
            {
                cols[c][1] = cols[c][0];
            }
            length = max(length, cols[c][1].second + 1);
            rows[r][0].first = v;
            rows[r][0].second = max(rows[r][0].second, length);
            cols[c][0].first = v;
            cols[c][0].second = max(cols[c][0].second, length);
            result = max(result, length);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2709. Greatest Common Divisor Traversal
/// 
/// Hard
///
/// You are given a 0-indexed integer array nums, and you are allowed to 
/// traverse between its indices. You can traverse between index i and 
/// index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where 
/// gcd is the greatest common divisor.
///
/// Your task is to determine if for every pair of indices i and j in 
/// nums, where i < j, there exists a sequence of traversals that can 
/// take us from i to j.
///
/// Return true if it is possible to traverse between all such pairs 
/// of indices, or false otherwise.
///
/// Example 1:
/// Input: nums = [2,3,6]
/// Output: true
/// Explanation: In this example, there are 3 possible pairs of 
/// indices: (0, 1), (0, 2), and (1, 2).
/// To go from index 0 to index 1, we can use the sequence of 
/// traversals 0 -> 2 -> 1, where we move from index 0 to index 2 
/// because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move 
/// from index 2 to index 1 because gcd(nums[2], 
/// nums[1]) = gcd(6, 3) = 3 > 1.
/// To go from index 0 to index 2, we can just go directly because 
/// gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from 
/// index 1 to index 2, we can just go directly because gcd(nums[1], 
/// nums[2]) = gcd(3, 6) = 3 > 1.
///
/// Example 2:
/// Input: nums = [3,9,5]
/// Output: false
/// Explanation: No sequence of traversals can take us from index 0 
/// to index 2 in this example. So, we return false.
///
/// Example 3:
/// Input: nums = [4,3,12,8]
/// Output: true
/// Explanation: There are 6 possible pairs of indices to traverse 
/// between: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), and (2, 3). A 
/// valid sequence of traversals exists for each pair, so we return true.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^5
/// </summary>
bool LeetCodeGraph::canTraverseAllPairs(vector<int>& nums)
{
    vector<int> primes;
    for (int i = 2; i < sqrt(1e5) + 1; i++)
    {
        bool is_prime = true;
        for (size_t j = 0; j < primes.size(); j++)
        {
            if (i % primes[j] == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
    unordered_map<int, int> prime_map;
    vector<int> parent(nums.size());
    unordered_map<int, int> visited;
    for (size_t i = 0; i < nums.size(); i++)
    {
        parent[i] = i;
        int n = nums[i];
        if (visited.count(n) > 0)
        {
            parent[i] = visited[n];
            continue;
        }
        for (size_t j = 0; j < primes.size() && n > 1; j++)
        {
            int d = primes[j];
            if (d * d > n) d = n;
            if (n % d == 0)
            {
                while (n % d == 0) n /= d;
                if (prime_map.count(d) > 0)
                {
                    int p = prime_map[d];
                    while (parent[p] != parent[parent[p]])
                    {
                        parent[p] = parent[parent[p]];
                    }
                    parent[parent[p]] = parent[i];
                    prime_map[d] = i;
                }
                else
                {
                    prime_map[d] = i;
                }
            }
        }
        if (nums[i] > 1) visited[nums[i]] = parent[i];
    }
    unordered_set<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
        while (parent[i] != parent[parent[i]])
        {
            parent[i] = parent[parent[i]];
        }
        result.insert(parent[i]);
    }
    return result.size() == 1;
}

/// <summary>
/// Leet Code 2714. Find Shortest Path with K Hops
/// 
/// Hard
///
/// You are given a positive integer n which is the number of nodes of 
/// a 0-indexed undirected weighted connected graph and a 0-indexed 2D 
/// array edges where edges[i] = [ui, vi, wi] indicates that there is 
/// an edge between nodes ui and vi with weight wi.
///
/// You are also given two nodes s and d, and a positive integer k, 
/// your task is to find the shortest path from s to d, but you can hop 
/// over at most k edges. In other words, make the weight of at most k 
/// edges 0 and then find the shortest path from s to d.
///
/// Return the length of the shortest path from s to d with the given 
/// condition.
///
/// Example 1:
/// Input: n = 4, edges = [[0,1,4],[0,2,2],[2,3,6]], s = 1, d = 3, k = 2
/// Output: 2
/// Explanation: In this example there is only one path from node 1 (the 
/// green node) to node 3 (the red node), which is (1->0->2->3) and the 
/// length of it is 4 + 2 + 6 = 12. Now we can make weight of two edges 0, 
/// we make weight of the blue edges 0, then we have 0 + 2 + 0 = 2. It 
/// can be shown that 2 is the minimum length of a path we can achieve 
/// with the given condition.
///
/// Example 2:
/// Input: n = 7, edges = [[3,1,9],[3,2,4],[4,0,9],[0,5,6],[3,6,2],
/// [6,0,4],[1,2,4]], s = 4, d = 1, k = 2
/// Output: 6
/// Explanation: In this example there are 2 paths from node 4 (the 
/// green node) to node 1 (the red node), which are (4->0->6->3->2->1) 
/// and (4->0->6->3->1). The first one has the 
/// length 9 + 4 + 2 + 4 + 4 = 23, and the second one has the 
/// length 9 + 4 + 2 + 9 = 24. Now if we make weight of the blue edges 0, 
/// we get the shortest path with the length 0 + 4 + 2 + 0 = 6. It can 
/// be shown that 6 is the minimum length of a path we can achieve with 
/// the given condition.
/// 
/// Example 3:
/// Input: n = 5, edges = [[0,4,2],[0,1,3],[0,2,1],[2,1,4],[1,3,4],
/// [3,4,7]], s = 2, d = 3, k = 1
/// Output: 3
/// Explanation: In this example there are 4 paths from node 2 
/// (the green node) to node 3 (the red node), which are (2->1->3), 
/// (2->0->1->3), (2->1->0->4->3) and (2->0->4->3). The first two 
/// have the length 4 + 4 = 1 + 3 + 4 = 8, the third one has the 
/// length 4 + 3 + 2 + 7 = 16 and the last one has the 
/// length 1 + 2 + 7 = 10. Now if we make weight of the blue edge 0, 
/// we get the shortest path with the length 1 + 2 + 0 = 3. It can be 
/// shown that 3 is the minimum length of a path we can achieve with 
/// the given condition.
///
/// Constraints:
/// 1. 2 <= n <= 500
/// 2. n - 1 <= edges.length <= min(10^4, n * (n - 1) / 2)
/// 3. edges[i].length = 3
/// 4. 0 <= edges[i][0], edges[i][1] <= n - 1
/// 5. 1 <= edges[i][2] <= 10^6
/// 6. 0 <= s, d, k <= n - 1
/// 7. s != d
/// 8. The input is generated such that the graph is connected and has 
///    no repeated edges or self-loops
/// </summary>
int LeetCodeGraph::shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k)
{
    vector <vector<pair<int, int>>> neighbors(n);
    int result = INT_MAX;
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
        neighbors[edges[i][1]].push_back({ edges[i][0], edges[i][2] });
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> distance(n, vector<int>(k + 1, INT_MAX));
    pq.push({0, s, 0});
    while (!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();
        if (top[1] == d)
        {
            result = top[0];
            break;
        }
        if (top[0] > distance[top[1]][top[2]]) continue;
        for (size_t i = 0; i < neighbors[top[1]].size(); i++)
        {
            int next = neighbors[top[1]][i].first;
            int dist = top[0] + neighbors[top[1]][i].second;
            if (dist < distance[next][top[2]])
            {
                distance[next][top[2]] = dist;
                pq.push({ dist, next, top[2]});
            }
            dist = top[0];
            if (top[2] < k && dist < distance[next][top[2] + 1])
            {
                distance[next][top[2] + 1] = dist;
                pq.push({ dist, next, top[2] + 1 });
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 	2737. Find the Closest Marked Node
/// 
/// Medium
///
/// You are given a positive integer n which is the number of nodes of 
/// a 0-indexed directed weighted graph and a 0-indexed 2D array edges 
/// where edges[i] = [ui, vi, wi] indicates that there is an edge from 
/// node ui to node vi with weight wi.
///
/// You are also given a node s and a node array marked; your task is 
/// to find the minimum distance from s to any of the nodes in marked.
///
/// Return an integer denoting the minimum distance from s to any node 
/// in marked or -1 if there are no paths from s to any of the marked 
/// nodes.
///
/// Example 1:
/// Input: n = 4, edges = [[0,1,1],[1,2,3],[2,3,2],[0,3,4]], s = 0, 
/// marked = [2,3]
/// Output: 4
/// Explanation: There is one path from node 0 (the green node) to 
/// node 2 (a red node), which is 0->1->2, and has a distance 
/// of 1 + 3 = 4.
/// There are two paths from node 0 to node 3 (a red node), which 
/// are 0->1->2->3 and 0->3, the first one has a distance of 1 + 3 + 2 = 6 
/// and the second one has a distance of 4.
/// The minimum of them is 4.
///
/// Example 2:
/// Input: n = 5, edges = [[0,1,2],[0,2,4],[1,3,1],[2,3,3],[3,4,2]], 
/// s = 1, marked = [0,4]
/// Output: 3
/// Explanation: There are no paths from node 1 (the green node) to 
/// node 0 (a red node).
/// There is one path from node 1 to node 4 (a red node), which 
/// is 1->3->4, and has a distance of 1 + 2 = 3.
/// So the answer is 3.
/// 
/// Example 3:
/// Input: n = 4, edges = [[0,1,1],[1,2,3],[2,3,2]], s = 3, marked = [0,1]
/// Output: -1
/// Explanation: There are no paths from node 3 (the green node) to any of 
/// the marked nodes (the red nodes), so the answer is -1.
/// 
/// Constraints:
/// 1. 2 <= n <= 500
/// 2. 1 <= edges.length <= 10^4
/// 3. edges[i].length = 3
/// 4. 0 <= edges[i][0], edges[i][1] <= n - 1
/// 5. 1 <= edges[i][2] <= 10^6
/// 6. 1 <= marked.length <= n - 1
/// 7. 0 <= s, marked[i] <= n - 1
/// 8. s != marked[i]
/// 9. marked[i] != marked[j] for every i != j
/// 10. The graph might have repeated edges.
/// 11. The graph is generated such that it has no self-loops.
/// </summary>
int LeetCodeGraph::minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked)
{
    vector <vector<pair<int, int>>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back({ edges[i][1], edges[i][2] });
    }
    unordered_set<int> destinations = { marked.begin(), marked.end() };

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> distance(n, INT_MAX);
    pq.push({ 0, s });
    int result = -1;
    while (!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();
        if (destinations.count(top[1]) > 0)
        {
            result = top[0];
            break;
        }
        if (top[0] > distance[top[1]]) continue;
        for (size_t i = 0; i < neighbors[top[1]].size(); i++)
        {
            int next = neighbors[top[1]][i].first;
            int dist = top[0] + neighbors[top[1]][i].second;
            if (dist < distance[next])
            {
                distance[next] = dist;
                pq.push({ dist, next });
            }
        }
    }
    return result;
};

/// <summary>
/// Leet Code 2814. Minimum Time Takes to Reach Destination Without Drowning
/// 
/// Hard
///
/// You are given an n * m 0-indexed grid of string land. Right now, you are 
/// standing at the cell that contains "S", and you want to get to the cell 
/// containing "D". There are three other types of cells in this land:
///  
/// ".": These cells are empty.
/// "X": These cells are stone.
/// "*": These cells are flooded.
/// At each second, you can move to a cell that shares a side with your 
/// current cell (if it exists). Also, at each second, every empty cell that 
/// shares a side with a flooded cell becomes flooded as well.
/// There are two problems ahead of your journey:
///
/// You can't step on stone cells.
/// You can't step on flooded cells since you will drown (also, you can't 
/// step on a cell that will be flooded at the same time as you step on it).
/// Return the minimum time it takes you to reach the destination in seconds, 
/// or -1 if it is impossible.
///
/// Note that the destination will never be flooded.
///
/// 
/// Example 1:
///
/// Input: land = [["D",".","*"],[".",".","."],[".","S","."]]
/// Output: 3
/// Explanation: The picture below shows the simulation of the land second 
/// by second. The blue cells are flooded, and the gray cells are stone.
/// Picture (0) shows the initial state and picture (3) shows the final state 
/// when we reach destination. As you see, it takes us 3 second to reach 
/// destination and the answer would be 3.
/// It can be shown that 3 is the minimum time needed to reach from S to D.
/// 
/// Example 2:
/// Input: land = [["D","X","*"],[".",".","."],[".",".","S"]]
/// Output: -1
/// Explanation: The picture below shows the simulation of the land second 
/// by second. The blue cells are flooded, and the gray cells are stone.
/// Picture (0) shows the initial state. As you see, no matter which paths we 
/// choose, we will drown at the 3rd second. Also the minimum path takes us 4 
/// seconds to reach from S to D.
/// So the answer would be -1.
/// 
/// Example 3:
///
/// Input: land = [["D",".",".",".","*","."],[".","X",".","X",".","."],
/// [".",".",".",".","S","."]]
/// Output: 6
/// Explanation: It can be shown that we can reach destination in 6 seconds. 
/// Also it can be shown that 6 is the minimum seconds one need to reach 
/// from S to D.
///
/// Constraints: 
/// 1. 2 <= n, m <= 100
/// 2. land consists only of "S", "D", ".", "*" and "X".
/// 3. Exactly one of the cells is equal to "S".
/// 4. Exactly one of the cells is equal to "D".
/// </summary>
int LeetCodeGraph::minimumSeconds(vector<vector<string>>& land)
{
    vector<int> s(2);
    queue<vector<int>> queue;

    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> water(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == "S")
            {
                s[0] = i; 
                s[1] = j;
            }
            if (land[i][j] == "*")
            {
                queue.push({ i, j });
                water[i][j] = 0;
            }
        }
    }
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!queue.empty())
    {
        vector<int> p = queue.front();
        queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            vector<int> next_p = p;
            next_p[0] += directions[i][0];
            next_p[1] += directions[i][1];
            if (next_p[0] < 0 || next_p[0] >= n)
            {
                continue;
            }
            if (next_p[1] < 0 || next_p[1] >= m)
            {
                continue;
            }
            if (land[next_p[0]][next_p[1]] == "X" || land[next_p[0]][next_p[1]] == "D")
            {
                continue;
            }
            if (water[next_p[0]][next_p[1]] != INT_MAX)
            {
                continue;
            }
            water[next_p[0]][next_p[1]] = water[p[0]][p[1]] + 1;
            queue.push(next_p);
        }
    }

    vector<vector<int>> step(n, vector<int>(m));
    queue.push(s);
    while (!queue.empty())
    {
        vector<int> p = queue.front();
        queue.pop();
        for (size_t i = 0; i < directions.size(); i++)
        {
            vector<int> next_p = p;
            next_p[0] += directions[i][0];
            next_p[1] += directions[i][1];
            if (next_p[0] < 0 || next_p[0] >= n)
            {
                continue;
            }
            if (next_p[1] < 0 || next_p[1] >= m)
            {
                continue;
            }
            if (land[next_p[0]][next_p[1]] == "X")
            {
                continue;
            }
            if (step[next_p[0]][next_p[1]] > 0)
            {
                continue;
            }
            if (next_p == s)
            {
                continue;
            }
            step[next_p[0]][next_p[1]] = step[p[0]][p[1]] + 1;
            if (land[next_p[0]][next_p[1]] == "D")
            {
                return step[next_p[0]][next_p[1]];
            }
            if (step[next_p[0]][next_p[1]] >= water[next_p[0]][next_p[1]])
            {
                continue;
            }
            queue.push(next_p);
        }
    }
    return -1;
}

/// <summary>
/// Leet 2812. Find the Safest Path in a Grid
/// 
/// Medium
///
/// You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) 
/// represents:
///
/// A cell containing a thief if grid[r][c] = 1
/// An empty cell if grid[r][c] = 0
/// You are initially positioned at cell (0, 0). In one move, you can 
/// move to any adjacent cell in the grid, including cells containing 
/// thieves.
///
/// The safeness factor of a path on the grid is defined as the minimum 
/// manhattan distance from any cell in the path to any thief in the grid.
///
/// Return the maximum safeness factor of all paths leading to cell 
/// (n - 1, n - 1).
///
/// An adjacent cell of cell (r, c), is one of the cells (r, c + 1), 
/// (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
///
/// The Manhattan distance between two cells (a, b) and (x, y) is 
/// equal to |a - x| + |b - y|, where |val| denotes the absolute value 
/// of val.
///
/// Example 1:
/// Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
/// Output: 0
/// Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the 
/// thieves in cells (0, 0) and (n - 1, n - 1).
///
/// Example 2:
/// Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
/// Output: 2
/// Explanation: The path depicted in the picture above has a safeness 
/// factor of 2 since:
/// - The closest cell of the path to the thief at cell (0, 2) is cell 
/// (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
/// It can be shown that there are no other paths with a higher safeness 
/// factor.
///
/// Example 3:
/// Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
/// Output: 2
/// Explanation: The path depicted in the picture above has a safeness 
/// factor of 2 since:
/// - The closest cell of the path to the thief at cell (0, 3) is cell 
///  (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
/// - The closest cell of the path to the thief at cell (3, 0) is cell 
///  (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
/// It can be shown that there are no other paths with a higher safeness 
/// factor.
/// 
/// Constraints:
/// 1. 1 <= grid.length == n <= 400
/// 2. grid[i].length == n
/// 3. grid[i][j] is either 0 or 1.
/// 4. There is at least one thief in the grid.
/// </summary>
int LeetCodeGraph::maximumSafenessFactor(vector<vector<int>>& grid)
{
    queue<pair<int, int>> thiefs;
    int n = grid.size();
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == 1)
            {
                thiefs.push({ i, j });
                distance[i][j] = 0;
            }
        }
    }
    vector<vector<int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    while (!thiefs.empty())
    {
        pair<int, int> pos = thiefs.front();
        thiefs.pop();
        for (size_t d = 0; d < directions.size(); d++)
        {
            pair<int, int> nextpos = pos;
            nextpos.first += directions[d][0];
            nextpos.second += directions[d][1];
            if (nextpos.first < 0 || nextpos.first >= n ||
                nextpos.second < 0 || nextpos.second >= n)
            {
                continue;
            }
            if (distance[nextpos.first][nextpos.second] <= distance[pos.first][pos.second] + 1)
            {
                continue;
            }
            distance[nextpos.first][nextpos.second] = distance[pos.first][pos.second] + 1;
            thiefs.push(nextpos);
        }
    }
    vector<vector<int>> visited(n, vector<int>(n));
    priority_queue<vector<int>> pq;
    pq.push({ distance[0][0], 0, 0 });
    visited[0][0] = 1;
    while (!pq.empty())
    {
        vector<int> pos = pq.top();
        pq.pop();
        for (size_t d = 0; d < directions.size(); d++)
        {
            vector<int> nextpos = pos;
            nextpos[1] += directions[d][0];
            nextpos[2] += directions[d][1];
            if (nextpos[1] < 0 || nextpos[1] >= n ||
                nextpos[2] < 0 || nextpos[2] >= n)
            {
                continue;
            }
            if (visited[nextpos[1]][nextpos[2]] == 1)
            {
                continue;
            }
            if (grid[nextpos[1]][nextpos[2]] == 1)
            {
                continue;
            }
            nextpos[0] = distance[nextpos[1]][nextpos[2]];
            visited[nextpos[1]][nextpos[2]] = 1;
            distance[nextpos[1]][nextpos[2]] = min(distance[pos[1]][pos[2]], distance[nextpos[1]][nextpos[2]]);
            if (nextpos[1] == n - 1 && nextpos[2] == n - 1)
            {
                return distance[n - 1][n - 1];
            }
            pq.push(nextpos);
        }
    }
    return 0;
}

/// <summary>
/// Leet Code 2852. Sum of Remoteness of All Cells
/// 
/// Medium
///
/// You are given a 0-indexed matrix grid of order n * n. Each cell in 
/// this matrix has a value grid[i][j], which is either a positive 
/// integer or -1 representing a blocked cell.
///
/// You can move from a non-blocked cell to any non-blocked cell that 
/// shares an edge.
///
/// For any cell (i, j), we represent its remoteness as R[i][j] which is 
/// defined as the following:
///
/// If the cell (i, j) is a non-blocked cell, R[i][j] is the sum of the 
/// values grid[x][y] such that there is no path from the non-blocked cell 
/// (x, y) to the cell (i, j).
/// For blocked cells, R[i][j] == 0.
/// Return the sum of R[i][j] over all cells.
///
/// Example 1:
/// Input: grid = [[-1,1,-1],[5,-1,4],[-1,3,-1]]
/// Output: 39
/// Explanation: In the picture above, there are four grids. The top-left 
/// grid contains the initial values in the grid. Blocked cells are 
/// colored black, and other cells get their values as it is in the input. 
/// In the top-right grid, you can see the value of R[i][j] for all cells. 
/// So the answer would be the sum of them. That is: 0 + 12 + 0 + 8 + 0 
/// + 9 + 0 + 10 + 0 = 39.
/// Let's jump on the bottom-left grid in the above picture and calculate 
/// R[0][1] (the target cell is colored green). We should sum up the value 
/// of cells that can't be reached by the cell (0, 1). These cells are 
/// colored yellow in this grid. So R[0][1] = 5 + 4 + 3 = 12.
/// Now let's jump on the bottom-right grid in the above picture and 
/// calculate R[1][2] (the target cell is colored green). We should sum up 
/// the value of cells that can't be reached by the cell (1, 2). These 
/// cells are colored yellow in this grid. So R[1][2] = 1 + 5 + 3 = 9.
///
///
/// Example 2:
/// Input: grid = [[-1,3,4],[-1,-1,-1],[3,-1,-1]]
/// Output: 13
/// Explanation: In the picture above, there are four grids. The top-left 
/// grid contains the initial values in the grid. Blocked cells are 
/// colored black, and other cells get their values as it is in the 
/// input. In the top-right grid, you can see the value of R[i][j] for all 
/// cells. So the answer would be the sum of them. That is: 3 + 3 + 0 + 0 
/// + 0 + 0 + 7 + 0 + 0 = 13.
/// Let's jump on the bottom-left grid in the above picture and calculate
/// R[0][2] (the target cell is colored green). We should sum up the value 
/// of cells that can't be reached by the cell (0, 2). This cell is 
/// colored yellow in this grid. So R[0][2] = 3.
/// Now let's jump on the bottom-right grid in the above picture and 
/// calculate R[2][0] (the target cell is colored green). We should sum up 
/// the value of cells that can't be reached by the cell (2, 0). These 
/// cells are colored yellow in this grid. So R[2][0] = 3 + 4 = 7.
///
/// Example 3:
///
/// Input: grid = [[1]]
/// Output: 0
/// Explanation: Since there are no other cells than (0, 0), R[0][0] is 
/// equal to 0. So the sum of R[i][j] over all cells would be 0.
///
/// Constraints:
/// 1. 1 <= n <= 300
/// 2. 1 <= grid[i][j] <= 10^6 or grid[i][j] == -1
/// </summary>
long long LeetCodeGraph::sumRemoteness(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m));
    vector<pair<long long, int>> area_sum;
    queue<pair<int, int>> queue;
    vector<vector<int>> directions= { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == -1) continue;
            if (visited[i][j] != 0) continue;
            queue.push(make_pair(i, j));
            area++;
            visited[i][j] = area;
            long long sum = 0;
            int count = 0;
            while (!queue.empty())
            {
                int r = queue.front().first;
                int c = queue.front().second;
                queue.pop();
                sum += grid[r][c];
                count++;
                for (size_t d = 0; d < directions.size(); d++)
                {
                    int next_r = r + directions[d][0];
                    int next_c = c + directions[d][1];
                    if (next_r < 0 || next_r >= n ||
                        next_c < 0 || next_c >= m)
                    {
                        continue;
                    }
                    if (grid[next_r][next_c] == -1) continue;
                    if (visited[next_r][next_c] != 0) continue;
                    queue.push(make_pair(next_r, next_c));
                    visited[next_r][next_c] = area;
                }
            }
            area_sum.push_back(make_pair(sum, count));
        }
    }
    long long sum = 0;
    for (size_t i = 0; i < area_sum.size(); i++)
    {
        sum += area_sum[i].first;
    }
    long long result = 0;
    for (size_t i = 0; i < area_sum.size(); i++)
    {
        result += (sum - area_sum[i].first) * (long long)area_sum[i].second;
    }
    return result;
}

/// <summary>
/// Leet Code 2858. Minimum Edge Reversals So Every Node Is Reachable
/// </summary>
void LeetCodeGraph::minEdgeReversals(int parent, int node, int count, int depth,
    vector<vector<int>>& neighbors, 
    unordered_map<int, unordered_set<int>>& path,
    vector<pair<int, int>>& reverse, int &sum)
{
    depth++;
    for (size_t i = 0; i < neighbors[node].size(); i++)
    {
        int child = neighbors[node][i];
        if (child == parent) continue;
        if (path[node].count(child) > 0)
        {
            reverse[child] = make_pair(depth, count);
            minEdgeReversals(node, child, count, depth,neighbors, path, reverse, sum);
        }
        else
        {
            reverse[child] = make_pair(depth, count+1); 
            sum++;
            minEdgeReversals(node, child, count+1, depth, neighbors, path, reverse, sum);
        }
    }
}


/// <summary>
/// Leet Code 2858. Minimum Edge Reversals So Every Node Is Reachable
/// 
/// Hard
///
/// There is a simple directed graph with n nodes labeled from 0 to n - 1. 
/// The graph would form a tree if its edges were bi-directional.
///
/// You are given an integer n and a 2D integer array edges, where 
/// edges[i] = [ui, vi] represents a directed edge going from node ui to 
/// node vi.
///
/// An edge reversal changes the direction of an edge, i.e., a directed 
/// edge going from node ui to node vi becomes a directed edge going 
/// from node vi to node ui.
///
/// For every node i in the range [0, n - 1], your task is to 
/// independently calculate the minimum number of edge reversals required 
/// so it is possible to reach any other node starting from node i 
/// through a sequence of directed edges.
///
/// Return an integer array answer, where answer[i] is the minimum number 
/// of edge reversals required so it is possible to reach any other node 
/// starting from node i through a sequence of directed edges.
///
/// Example 1:
/// Input: n = 4, edges = [[2,0],[2,1],[1,3]]
/// Output: [1,1,0,2]
/// Explanation: The image above shows the graph formed by the edges.
/// For node 0: after reversing the edge [2,0], it is possible to reach 
/// any other node starting from node 0.
/// So, answer[0] = 1.
/// For node 1: after reversing the edge [2,1], it is possible to reach 
/// any other node starting from node 1.
/// So, answer[1] = 1.
/// For node 2: it is already possible to reach any other node starting 
/// from node 2.
/// So, answer[2] = 0.
/// For node 3: after reversing the edges [1,3] and [2,1], it is 
/// possible to reach any other node starting from node 3.
/// So, answer[3] = 2.
///
/// Example 2:
/// Input: n = 3, edges = [[1,2],[2,0]]
/// Output: [2,0,1]
/// Explanation: The image above shows the graph formed by the edges.
/// For node 0: after reversing the edges [2,0] and [1,2], it is possible 
/// to reach any other node starting from node 0.
/// So, answer[0] = 2.
/// For node 1: it is already possible to reach any other node starting 
/// from node 1. 
/// So, answer[1] = 0.
/// For node 2: after reversing the edge [1, 2], it is possible to reach 
/// any other node starting from node 2.
/// So, answer[2] = 1.
///
/// Constraints:
/// 1. 2 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= ui == edges[i][0] < n
/// 5. 0 <= vi == edges[i][1] < n
/// 6. ui != vi
/// 7. The input is generated such that if the edges were bi-directional, 
///    the graph would be a tree.
/// </summary>
vector<int> LeetCodeGraph::minEdgeReversals(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> neighbors(n);
    unordered_map<int, unordered_set<int>> path;
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
        path[edges[i][0]].insert(edges[i][1]);
    }
    vector<pair<int, int>> reverse(n);
    int sum = 0;
    minEdgeReversals(0, 0, 0, 0, neighbors, path, reverse, sum);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = sum + reverse[i].first - 2 * reverse[i].second;
    }
    return result;
}

/// <summary>
/// Leet Code 2867. Count Valid Paths in a Tree
/// </summary>
pair<int, int> LeetCodeGraph::countPathsII(int parent, int node,
    vector<vector<int>>& neighbors, vector<int>& prime,
    long long& result)
{
    unordered_map<int, int> children;
    pair<int, int> curr;
    if (prime[node] == 1) curr.second = 1;
    else curr.first = 1;        
    for (size_t i = 0; i < neighbors[node].size(); i++)
    {
        if (neighbors[node][i] == parent) continue;
        pair<int, int> next = countPathsII(node, neighbors[node][i],
            neighbors, prime, result);
        if (prime[node] == 1)
        {
            result += (long long)curr.second * (long)next.first;
            curr.second += next.first;
        }
        else
        {
            result += (long long)curr.second * (long)next.first;
            result += (long long)curr.first * (long)next.second;
            curr.first += next.first;
            curr.second += next.second;
        }
    }
    return curr;
}



/// <summary>
/// Leet Code 2867. Count Valid Paths in a Tree
/// 
/// Hard
/// 
/// There is an undirected tree with n nodes labeled from 1 to n. You are 
/// given the integer n and a 2D integer array edges of length n - 1, 
/// where edges[i] = [ui, vi] indicates that there is an edge between 
/// nodes ui and vi in the tree.
///
/// Return the number of valid paths in the tree.
///
/// A path (a, b) is valid if there exists exactly one prime number 
/// among the node labels in the path from a to b.
///
/// Note that:
/// The path (a, b) is a sequence of distinct nodes starting with node a 
/// and ending with node b such that every two adjacent nodes in the 
/// sequence share an edge in the tree.
/// Path (a, b) and path (b, a) are considered the same and counted only 
/// once.
///
/// Example 1:
/// Input: n = 5, edges = [[1,2],[1,3],[2,4],[2,5]]
/// Output: 4
/// Explanation: The pairs with exactly one prime number on the path 
/// between them are: 
/// - (1, 2) since the path from 1 to 2 contains prime number 2. 
/// - (1, 3) since the path from 1 to 3 contains prime number 3.
/// - (1, 4) since the path from 1 to 4 contains prime number 2.
/// - (2, 4) since the path from 2 to 4 contains prime number 2.
/// It can be shown that there are only 4 valid paths.
///
/// Example 2:
/// Input: n = 6, edges = [[1,2],[1,3],[2,4],[3,5],[3,6]]
/// Output: 6
/// Explanation: The pairs with exactly one prime number on the path 
/// between them are: 
/// - (1, 2) since the path from 1 to 2 contains prime number 2.
/// - (1, 3) since the path from 1 to 3 contains prime number 3.
/// - (1, 4) since the path from 1 to 4 contains prime number 2.
/// - (1, 6) since the path from 1 to 6 contains prime number 3.
/// - (2, 4) since the path from 2 to 4 contains prime number 2.
/// - (3, 6) since the path from 3 to 6 contains prime number 3.
/// It can be shown that there are only 6 valid paths.
///
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 1 <= ui, vi <= n
/// 5. The input is generated such that edges represent a valid tree.
/// </summary>
long long LeetCodeGraph::countPathsII(int n, vector<vector<int>>& edges)
{
    vector<int>  prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i + i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    vector<vector<int>> neighbors(n+1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    long long result = 0;
    countPathsII(-1, 1, neighbors, prime, result);
    return result;
}
#pragma endregion