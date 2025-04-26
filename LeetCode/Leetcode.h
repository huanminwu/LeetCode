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
    TreeNode* random;
    TreeNode(int x) : val(x), count(0), left(nullptr), right(nullptr), parent(nullptr), random(nullptr) {}
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
struct BinaryIndexTree
{
    vector<int> m_arr;
    int m_count;
    BinaryIndexTree(int n)
    {
        m_arr = vector<int>(n + 1, 0);
        m_count = n + 1;
    }
    void add(int index, int val)
    {
        if (index == 0) return;
        while (index < m_count)
        {
            m_arr[index] += val;
            index += (index & -index);
        }
    }
    int sum(int index)
    {
        int sum = 0;
        while (index != 0)
        {
            sum += m_arr[index];
            index -= index & -index;
        }
        return sum;
    }
};

struct SegmentTreeMax
{
    vector<int> m_arr;
    string m_type;
    int m_count;
    SegmentTreeMax(int n)
    {
        m_count = n;
        m_arr = vector<int>(4 * n, INT_MIN);
    }

    void set(int index, int start, int end, int pos, int val)
    {
        if (start == end)
        {
            m_arr[index] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (pos <= mid)
        {
            set(2 * index + 1, start, mid, pos, val);
        }
        else
        {
            set(2 * index + 2, mid + 1, end, pos, val);
        }
        m_arr[index] = max(m_arr[2 * index + 1], m_arr[2 * index + 2]);
    }

    int query(int index, int start, int end, int val)
    {
        if (m_arr[index] < val) return -1;
        if (start == end)
        {
            return start;
        }
        int mid = start + (end - start) / 2;
        if (m_arr[2 * index + 1] >= val)
        {
            return query(2 * index + 1, start, mid, val);
        }
        else
        {
            return query(2 * index + 2, mid + 1, end, val);
        }
    }
};

struct SegmentTreeModuloK
{
    struct Node
    {
        // record the all [left, right] prefix product.
        // Example: (left), (left, left+1), ... (left,... right)
    public:
        Node()
        {
            // empty node
            fill(remain, remain + 5, 0);
            prod = 1;
        }
        int remain[5];
        int prod;
    };

    int k, n;
    vector<Node> nodes;
    SegmentTreeModuloK(int n, int k)
    {
        this->k = k;
        this->n = n;
        nodes.resize(4 * n);
    }
    void merge(int cur) 
    {
        // merge the 2*cur+1 and 2*cur+2 node to cur
        int left = 2 * cur + 1;
        int right = 2 * cur + 2;
        nodes[cur].prod = (nodes[left].prod * nodes[right].prod) % k;
        // The part [left ~ mid]'s prefix still include in the [left, right] prefix.
        for (int i = 0; i < k; ++i) nodes[cur].remain[i] = nodes[left].remain[i];
        for (int i = 0; i < k; ++i) 
        {
            int newVal = (i * nodes[left].prod) % k;
            nodes[cur].remain[newVal] += nodes[right].remain[i];
        }
    }
    void build(vector<int>& nums, int cur, int left, int right)
    {
        if (left == right) 
        {
            if (nums[left] % k < 5)
            {
                nodes[cur].remain[nums[left] % k % 5] = 1;
                nodes[cur].prod = nums[left] % k;
            }
            return;
        }
        int mid = (left + right) / 2;
        build(nums, 2 * cur + 1, left, mid);
        build(nums, 2 * cur + 2, mid + 1, right);
        merge(cur);
    }
    void update(int cur, int left, int right, int target, int val) 
    {
        if (left == right) 
        {
            for (int i = 0; i < k; ++i) nodes[cur].remain[i] = 0;
            if (val % k < 5)
            {
                nodes[cur].remain[val % k % 5] = 1;
                nodes[cur].prod = val % k;
            }
            return;
        }
        int mid = (left + right) / 2;
        if (target <= mid)
            update(2 * cur + 1, left, mid, target, val);
        else
            update(2 * cur + 2, mid + 1, right, target, val);
        merge(cur);
    }

    void merge(Node& n1, Node& n2) 
    {
        // merge the n1 and n2 node to n1
        for (int i = 0; i < k; ++i) 
        {
            int newVal = (i * n1.prod) % k;
            n1.remain[newVal] += n2.remain[i];
        }
        n1.prod = (n1.prod * n2.prod) % k;
    }

    Node query(int cur, int qL, int qR, int left, int right) 
    {
        if (qR < left || qL > right) return Node(); // empty
        if (qL <= left && right <= qR) return nodes[cur];
        int mid = (left + right) / 2;
        Node nLeft = query(2 * cur + 1, qL, qR, left, mid);
        Node nRight = query(2 * cur + 2, qL, qR, mid + 1, right);
        merge(nLeft, nRight);
        return nLeft;
    }
};


#pragma endregion 

/// <summary>
/// The class is to implement some string algorithm 
/// </summary>
class LeetCode
{
public:

#pragma region BackTracking



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

    static void WriteMessage(vector<long long>& data)
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

    static void WriteMessage(vector<vector<long long>>& data)
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
        while (current != nullptr)
        {
            message.append(to_string(current->val) + " ");
            current = current->next;
            if (current == data) break;
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
