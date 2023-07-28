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
