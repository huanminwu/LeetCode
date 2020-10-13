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
bool LeetCodeGraph::canFinishCourse(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<int> degree(numCourses);
    vector<unordered_set<int>> dependency(numCourses);
    queue<int> search;

    // remember which course dependes on others and which ones depends on me
    for (pair<int, int> pair : prerequisites)
    {
        if (dependency[pair.second].count(pair.first) == 0)
        {
            degree[pair.first]++;
            dependency[pair.second].insert(pair.first);
        }
    }
    // get all the course not depends on others, this is our starting search scope
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0) search.push(i);
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
            }
        }
    }
    // if number of free courses equals to the total course, we can finish 
    // all courses
    for (size_t i = 0; i < degree.size(); i++)
    {
        if (degree[i] > 0)	return false;
    }
    return true;
}

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
vector<int> LeetCodeGraph::findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
    vector<int> result;
    vector<unordered_set<int>> courseDependency(numCourses);
    vector<unordered_set<int>> whoDependOnMe(numCourses);
    queue<int> search_queue;

    // remember which course dependes on others and which ones depends on me
    for (pair<int, int> pair : prerequisites)
    {
        courseDependency[pair.first].insert(pair.second);
        whoDependOnMe[pair.second].insert(pair.first);
    }
    // get all the course not depends on others, this is our starting search scope
    for (size_t i = 0; i < courseDependency.size(); i++)
    {
        if (courseDependency[i].size() == 0)
        {
            search_queue.push(i);
        }
    }

    // Using queue to manage BFS and get every free course and clear the dependency 
    // with a free course, i.e. you depend on a free course, then such dependency
    // does not matter. If all dependencies are clear, we got a new free course
    while (!search_queue.empty())
    {
        int free_course = search_queue.front();
        result.push_back(free_course);
        search_queue.pop();
        unordered_set<int> course_depend_on_me = whoDependOnMe[free_course];
        for (int dependent_course : course_depend_on_me)
        {
            courseDependency[dependent_course].erase(free_course);
            if (courseDependency[dependent_course].empty())
            {
                search_queue.push(dependent_course);
            }
        }
    }

    // if number of free courses equals to the total course, we can finish all courses
    if (result.size() == numCourses)
    {
        return result;
    }
    else
    {
        result.clear();
        return result;
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
int LeetCodeGraph::countComponents(int n, vector<pair<int, int>>& edges)
{
    unordered_map<int, unordered_set<int>> node_map;
    unordered_set<int> visited;
    queue<int> process_queue;
    int count = 0;

    for (size_t i = 0; i < edges.size(); i++)
    {
        node_map[edges[i].first].insert(edges[i].second);
        node_map[edges[i].second].insert(edges[i].first);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            process_queue.push(i);
            while (!process_queue.empty())
            {
                int current = process_queue.front();
                process_queue.pop();
                visited.insert(current);
                for (int target : node_map[current])
                {
                    if (visited.count(target) == 0)
                    {
                        process_queue.push(target);
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
/// 
/// You are given a m x n 2D grid initialized with these three possible values.  
/// 1.-1 - A wall or an obstacle.
/// 2.0 - A gate.
/// 3.INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent 
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
void LeetCodeGraph::wallsAndGates(vector<vector<int>>& rooms)
{
    if ((rooms.size() == 0) || (rooms[0].size() == 0)) return;
    queue<pair<int, int>> process_queue;
    for (size_t i = 0; i < rooms.size(); i++)
    {
        for (size_t j = 0; j < rooms[i].size(); j++)
        {
            if ((rooms[i][j] == 0) || (rooms[i][j] == -1))
            {
                process_queue.push(make_pair(i, j));
            }
        }
    }
    while (!process_queue.empty())
    {
        pair<int, int> pos = process_queue.front();
        process_queue.pop();
        if (rooms[pos.first][pos.second] != -1)
        {
            int first, second;
            first = pos.first - 1;
            second = pos.second;
            if ((first >= 0) && (rooms[first][second] == INT_MAX))
            {
                rooms[first][second] = rooms[pos.first][pos.second] + 1;
                process_queue.push(make_pair(first, second));
            }
            first = pos.first + 1;
            second = pos.second;
            if ((first < (int)rooms.size()) && (rooms[first][second] == INT_MAX))
            {
                rooms[first][second] = rooms[pos.first][pos.second] + 1;
                process_queue.push(make_pair(first, second));
            }
            first = pos.first;
            second = pos.second - 1;
            if ((second >= 0) && (rooms[first][second] == INT_MAX))
            {
                rooms[first][second] = rooms[pos.first][pos.second] + 1;
                process_queue.push(make_pair(first, second));
            }
            first = pos.first;
            second = pos.second + 1;
            if ((second < (int)rooms[first].size()) && (rooms[first][second] == INT_MAX))
            {
                rooms[first][second] = rooms[pos.first][pos.second] + 1;
                process_queue.push(make_pair(first, second));
            }
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
bool LeetCodeGraph::sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs)
{
    unordered_map<int, unordered_set<int>> prev_set;
    unordered_map<int, unordered_set<int>> next_set;
    unordered_set<int> root_set;

    for (size_t i = 0; i < seqs.size(); i++)
    {
        for (size_t j = 0; j < seqs[i].size(); j++)
        {
            if (j + 1 < seqs[i].size())
            {
                next_set[seqs[i][j]].insert(seqs[i][j + 1]);
                prev_set[seqs[i][j + 1]].insert(seqs[i][j]);
            }
            else
            {
                next_set[seqs[i][j]].insert(0);
            }
        }
    }

    // insert everyone has successor
    for (auto itr : next_set) root_set.insert(itr.first);
    // remove everyone has predecessor
    for (auto itr : prev_set) root_set.erase(itr.first);

    int index = 0;
    while (!root_set.empty())
    {
        if (root_set.size() > 1) return false;
        int prev = *root_set.begin();
        for (int next : next_set[prev])
        {
            // ignore 0
            if (next == 0) continue;

            prev_set[next].erase(prev);
            if (prev_set[next].empty())
            {
                root_set.insert(next);
                prev_set.erase(next);
            }
        }
        root_set.erase(prev);
        next_set.erase(prev);
        if (index >= (int)org.size() || org[index] != prev) return false;
        index++;
    }
    if (next_set.empty() && (index == org.size())) return true;
    else return false;
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
/// Leet code #174. Dungeon Game 
/// The demons had captured the princess (P) and imprisoned her in the 
/// bottom-right corner of a dungeon. The dungeon consists 
/// of M x N rooms laid out in a 2D grid. Our valiant knight (K) was 
/// initially positioned in the top-left room and must fight 
/// his way through the dungeon to rescue the princess. 
///
/// The knight has an initial health point represented by a positive 
/// integer. If at any point his health point drops to 0 
/// or below, he dies immediately. 
/// Some of the rooms are guarded by demons, so the knight loses health 
/// (negative integers) upon entering these rooms; 
/// other rooms are either empty (0's) or contain magic orbs that 
/// increase the knight's health (positive integers).
/// In order to reach the princess as quickly as possible, the 
/// knight decides to move only 
/// rightward or downward in each step. 
/// Write a function to determine the knight's minimum initial health 
/// so that he is able to rescue the princess.
/// For example, given the dungeon below, the initial health of the 
/// knight must be at least 7 if he follows the optimal path 
/// RIGHT-> RIGHT -> DOWN -> DOWN.
/// -2 (K) -3 3 
/// -5 -10 1 
/// 10 30 -5 (P) 
/// Notes: 
/// 1. The knight's health has no upper bound.
/// 2. Any room can contain threats or power-ups, even the first room the knight 
///    enters and the bottom-right room where the princess is imprisoned.
/// </summary>
int LeetCodeGraph::calculateMinimumHP(vector<vector<int>>& dungeon)
{
    vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), INT_MIN));
    dp[0][0] = dungeon[0][0];
    vector<int> pos(3);
    pos = { dungeon[0][0], 0, 0 };
    priority_queue<vector<int>> search;
    search.push(pos);
    vector<vector<int>> directions = { {0, 1}, {1, 0} };
    int result = 1;
    while (!search.empty())
    {
        pos = search.top();
        search.pop();
        result = max(result, 1 - pos[0]);
        if (pos[1] == dungeon.size() - 1 && pos[2] == dungeon[0].size() - 1)
        {
            break;
        }
        for (size_t d = 0; d < directions.size(); d++)
        {
            vector<int> next = pos;
            next[1] = pos[1] + directions[d][0];
            next[2] = pos[2] + directions[d][1];
            if (next[1] >= (int)dungeon.size()) continue;
            if (next[2] >= (int)dungeon[0].size()) continue;

            next[0] = pos[0] + dungeon[next[1]][next[2]];
            if (next[0] > dp[next[1]][next[2]])
            {
                dp[next[1]][next[2]] = next[0];
                search.push(next);
            }
        }
    }
    return result;
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
vector<int> LeetCodeGraph::numIslands2(int m, int n, vector<vector<int>>& positions)
{
    vector<int> result;
    vector<int> island_map(m * n + 1);
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
            island_map[island_id] = 0;
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
                int neigbor = grid_map[next[0]][next[1]];
                // water
                if (neigbor == 0)
                {
                    continue;
                }
                while (island_map[neigbor] != 0) neigbor = island_map[neigbor];
                if (neigbor != island_id)
                {
                    island_map[neigbor] = island_id;
                    count--;
                }
            }
        }
        result.push_back(count);
    }
    return result;
}

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
int LeetCodeGraph::findCircleNum(vector<vector<int>>& M)
{
    vector<int> circle_map(M.size());
    for (size_t i = 0; i < M.size(); i++)
    {
        circle_map[i] = i;
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
                while (circle_map[source] != source) source = circle_map[source];
                while (circle_map[target] != target) target = circle_map[target];
                circle_map[target] = source;
            }
        }
    }

    int count = 0;
    for (size_t i = 0; i < circle_map.size(); i++)
    {
        if (circle_map[i] == i) count++;
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
    vector<int> dp(s.size());
    unordered_map<int, priority_queue<char>> char_set;

    for (size_t i = 0; i < dp.size(); i++) dp[i] = i;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        int a = pairs[i][0];
        int b = pairs[i][1];
        while (dp[a] != a)
        {
            dp[a] = dp[dp[a]];
            a = dp[a];
        }
        while (dp[b] != b)
        {
            dp[b] = dp[dp[b]];
            b = dp[b];
        }
        dp[a] = b;
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        int a = i;
        while (dp[a] != a)
        {
            dp[a] = dp[dp[a]];
            a = dp[a];
        }
        char_set[a].push('z' - s[i]);
    }
    string result;
    for (size_t i = 0; i < s.size(); i++)
    {
        int a = i;
        while (dp[a] != a) a = dp[a];
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

#pragma endregion