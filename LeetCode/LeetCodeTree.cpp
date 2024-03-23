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
#include "Leetcode.h"
#include "LeetCodeTree.h"

#pragma region BinaryTree

/// <summary>
/// Free nodes
/// </summary>
void LeetCodeTree::freeNodes(Node* root)
{
    queue<Node*> search;
    search.push(root);
    while (!search.empty())
    {
        Node* node = search.front();
        search.pop();
        if (node == nullptr) break;
        for (auto child : node->children)
        {
            if (child == nullptr) search.push(child);
        }
        delete node;
    }
}

/// <summary>
/// Find a tree node with value
/// </summary>
TreeNode* LeetCodeTree::findTreeNode(TreeNode* root, int value)
{
    vector<TreeNode*> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeNode* node = stack.back();
        if (node->val == value) return node;
        stack.pop_back();

        if (node != NULL)
        {
            if (node->left != NULL)
            {
                stack.push_back(node->left);
            }
            if (node->right != NULL)
            {
                stack.push_back(node->right);
            }
        }
    }
    return nullptr;
}

/// <summary>
/// Free tree nodes
/// </summary>
void LeetCodeTree::freeTreeNodes(TreeNode* root)
{
    vector<TreeNode*> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeNode* node = stack.back();
        stack.pop_back();

        if (node != NULL)
        {
            if (node->left != NULL)
            {
                stack.push_back(node->left);
            }
            if (node->right != NULL)
            {
                stack.push_back(node->right);
            }

            delete node;
        }
    }
}

/// <summary>
/// Free link tree nodes
/// </summary>
void LeetCodeTree::freeLinkTreeNodes(TreeLinkNode* root)
{
    vector<TreeLinkNode*> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeLinkNode* node = stack.back();
        stack.pop_back();

        if (node != NULL)
        {
            if (node->left != NULL)
            {
                stack.push_back(node->left);
            }
            if (node->right != NULL)
            {
                stack.push_back(node->right);
            }

            delete node;
        }
    }
}

/// <summary>
/// Build BST Forest
/// </summary>
vector<TreeNode*> LeetCodeTree::buildBSTForest(vector<vector<int>> node_list)
{
    vector<TreeNode*> trees;
    for (size_t i = 0; i < node_list.size(); i++)
    {
        TreeNode* node = new TreeNode(node_list[i][0]);
        if (node_list[i].size() > 1)
        {
            if (node_list[i][1] > node_list[i][0])
            {
                node->right = new TreeNode(node_list[i][1]);
            }
            else
            {
                node->left = new TreeNode(node_list[i][1]);
            }
        }
        if (node_list[i].size() > 2)
        {
            node->right = new TreeNode(node_list[i][2]);
        }
        trees.push_back(node);
    }
    return trees;
}

/// <summary>
/// Leet code 297. Serialize and Deserialize Binary Tree
/// Serialization is the process of converting a data structure or object 
/// into a sequence of bits so that it can be stored in a file or memory 
/// buffer, or transmitted across a network connection link to be 
/// reconstructed later in the same or another computer environment. 
///
/// Design an algorithm to serialize and deserialize a binary tree. There 
/// is no restriction on how your serialization/deserialization algorithm 
/// should work. You just need to ensure that a binary tree can be 
/// serialized to a string and this string can be deserialized to the 
/// original tree structure.
///
/// For example, you may serialize the following tree 
///    1
///   / \
///  2   3
///     / \
///    4   5
///
/// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes
/// a binary tree. 
/// You do not necessarily need to follow this format, so please be 
/// creative and come up with different approaches yourself. 
/// Note: Do not use class member/global/static variables to store states. 
/// Your serialize and deserialize algorithms should be stateless. 
/// </summary>
/// <summary>
/// Encodes a tree to a single string.
/// </summary>
/// <param name="root">the root</param>
/// <returns>The string</returns>
string LeetCodeTree::serialize(TreeNode* root, bool as_char)
{
    string result = "";
    queue<TreeNode *> queue;
    if (root != nullptr) queue.push(root);
    while (!queue.empty())
    {
        TreeNode * node = queue.front();
        queue.pop();
        if (!result.empty()) { result.push_back(','); }
        if (node == nullptr)
        {
            result.append("null");
        }
        else
        {
            if (as_char)
            {
                result.push_back((char)node->val);
            }
            else
            {
                result.append(std::to_string(node->val));
            }
            queue.push(node->left);
            queue.push(node->right);
        }
    }
    while (true)
    {
        if ((result.size() > 4) && (result.substr(result.size() - 4) == "null"))
        {
            result.erase(result.size() - 4);
        }
        else if ((result.size() > 1) && (result.substr(result.size() - 1) == ","))
        {
            result.erase(result.size() - 1);
        }
        else
        {
            break;
        }
    }
    return "[" + result + "]";
}


/// <summary>
/// Encodes a linktree to a single string.
/// </summary>
/// <param name="root">the root</param>
/// <returns>The string</returns>
string LeetCodeTree::serializeLinkTree(TreeLinkNode* root)
{
    string result;
    queue<TreeLinkNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeLinkNode * node = queue.front();
        queue.pop();
        if (!result.empty()) { result.push_back(','); }
        if (node == nullptr)
        {
            result.append("null");
        }
        else
        {
            result.append(std::to_string(node->val));
            queue.push(node->left);
            queue.push(node->right);
        }
    }
    while (true)
    {
        if ((result.size() > 4) && (result.substr(result.size() - 4) == "null"))
        {
            result.erase(result.size() - 4);
        }
        else if ((result.size() > 1) && (result.substr(result.size() - 1) == ","))
        {
            result.erase(result.size() - 1);
        }
        else
        {
            break;
        }
    }
    return "[" + result + "]";
}

/// <summary>
/// Decodes your encoded data to tree.
/// </summary>
/// <param name="data">the string data</param>
/// <returns>The root</returns> 
TreeLinkNode* LeetCodeTree::deserializeLinkTree(string data)
{
    queue<TreeLinkNode *> input_queue;
    queue<TreeLinkNode *> output_queue;
    string number;
    for (size_t i = 0; i < data.size(); i++)
    {
        if ((data[i] == '[') || (data[i] == ',') || data[i] == ']' || isspace(data[i]))
        {
            if (number.size() != 0)
            {
                if (number == "null")
                {
                    input_queue.push(nullptr);
                }
                else
                {
                    input_queue.push(new TreeLinkNode(std::stoi(number)));
                }
                number.clear();
            }
        }
        else
        {
            number.push_back(data[i]);
        }
    }
    TreeLinkNode *root = nullptr;
    TreeLinkNode *node = nullptr;
    while (!input_queue.empty())
    {
        if (output_queue.empty())
        {
            root = input_queue.front();
            input_queue.pop();
            node = root;
            output_queue.push(node);
        }
        else
        {
            node = output_queue.front();
            output_queue.pop();
            if (node != nullptr)
            {
                if (!input_queue.empty())
                {
                    node->left = input_queue.front();
                    input_queue.pop();
                }
                if (!input_queue.empty())
                {
                    node->right = input_queue.front();
                    input_queue.pop();
                }
                output_queue.push(node->left);
                output_queue.push(node->right);
            }
        }
    }
    return root;
}

/// <summary>
/// Leet code #144. Binary Tree Preorder Traversal 
/// <summary>
void LeetCodeTree::preorderTraversal(TreeNode* root, vector<int>& output)
{
    if (root == nullptr) return;
    output.push_back(root->val);
    preorderTraversal(root->left, output);
    preorderTraversal(root->right, output);
}

/// <summary>
/// Leet code #144. Binary Tree Preorder Traversal 
/// Given a binary tree, return the preorder traversal of its nodes' values.
///
/// For example:
/// Given binary tree {1,#,2,3},
///   1
///    \
///     2
///    /
///   3
///  return [1,2,3]. 
///  Note: Recursive solution is trivial, could you do it iteratively?
/// <summary>
vector<int> LeetCodeTree::preorderTraversal(TreeNode* root)
{
    stack<TreeNode *> stack;
    vector<int> result;
    stack.push(root);
    while (!stack.empty())
    {
        TreeNode * node = stack.top();
        stack.pop();
        if (node != nullptr)
        {
            result.push_back(node->val);
            stack.push(node->right);
            stack.push(node->left);
        }
    }
    return result;
}

/// <summary>
/// Leet code #94. Binary Tree Inorder Traversal
/// 
/// Given a binary tree, return the inorder traversal of its nodes' values. 
/// For example: 
/// Given binary tree [1,null,2,3], 
/// 1
///  \
///   2
///  /
/// 3
/// return [1,3,2].
/// Note: Recursive solution is trivial, could you do it iteratively?
/// </summary>
std::vector<int> LeetCodeTree::inorderTraversal(TreeNode* root)
{
    std::vector<int> outputList;
    std::stack<TreeNode *> stack;
    TreeNode * iterator = root;

    while (true)
    {
        if (iterator != nullptr)
        {
            stack.push(iterator);
            iterator = iterator->left;
        }
        else
        {
            if (stack.empty())
            {
                break;
            }
            iterator = stack.top();
            stack.pop();
            outputList.push_back(iterator->val);
            iterator = iterator->right;
        }
    }
    return outputList;
}

/// <summary>
/// Generate tree based on id list.
/// </summary>
vector<TreeNode*> LeetCodeTree::generateTrees(vector<int>& id_list)
{
    vector<TreeNode*> result;
    if (id_list.size() == 0)
    {
        result.push_back(nullptr);
        return result;
    }
    if (id_list.size() == 1)
    {
        result.push_back(new TreeNode(id_list[0]));
        return result;
    }
    for (size_t i = 0; i < id_list.size(); i++)
    {
        vector<int> left;
        vector<int> right;
        for (size_t j = 0; j < i; j++)
        {
            left.push_back(id_list[j]);
        }
        for (size_t j = i + 1; j < id_list.size(); j++)
        {
            right.push_back(id_list[j]);
        }
        vector<TreeNode*> left_list = generateTrees(left);
        vector<TreeNode*> right_list = generateTrees(right);
        for (size_t l = 0; l < left_list.size(); l++)
        {
            for (size_t r = 0; r < right_list.size(); r++)
            {
                TreeNode* root = new TreeNode(id_list[i]);
                root->left = left_list[l];
                root->right = right_list[r];
                result.push_back(root);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #95. Unique Binary Search Trees II     
/// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.  
/// For example,
/// Given n = 3, there are a total of 5 unique BST's.
///   1         3     3      2      1
///    \       /     /      / \      \
///     3     2     1      1   3      2
///    /     /       \                 \
///   2     1         2                 3
/// </summary>
vector<TreeNode*> LeetCodeTree::generateTrees(int n)
{
    vector<TreeNode*> result;
    if (n > 0)
    {
        vector<int> id_list;
        for (int i = 0; i < n; i++)
        {
            id_list.push_back(i + 1);
        }
        result = generateTrees(id_list);
    }
    return result;
}

/// <summary>
/// Leet code #145. Binary Tree Postorder Traversal
/// 
/// Given a binary tree, return the postorder traversal of its nodes' values. 
/// For example: 
/// Given binary tree {1,#,2,3},
/// 1
///  \
///   2
///  /
/// 3
/// return [3,2,1]. 
/// Note: Recursive solution is trivial, could you do it iteratively?
vector<int> LeetCodeTree::postorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    std::stack<pair<int, TreeNode *>> node_stack;
    node_stack.push(make_pair(0, root));
    // When we start the stack is empty
    while (!node_stack.empty())
    {
        pair<int, TreeNode*> p = node_stack.top();
        node_stack.pop();
        if (p.second == nullptr) continue;
        if (p.first == 0)
        {
            node_stack.push(make_pair(1, p.second));
            node_stack.push(make_pair(0, p.second->right));
            node_stack.push(make_pair(0, p.second->left));
        }
        else
        {
            result.push_back(p.second->val);
        }
    }

    return result;
}

/// <summary>
/// Leet code #102. Binary Tree Level Order Traversal 
/// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
/// For example:
/// Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
/// return its level order traversal as:
/// [
///   [3],
///   [9,20],
///   [15,7]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::levelOrder(TreeNode* root)
{
    vector<int> level;
    vector<vector<int>> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            level.push_back(node->val);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        result.push_back(level);
    }
    return result;
}

/// <summary>
/// Leet code #103. Binary Tree Zigzag Level Order Traversal   
/// Given a binary tree, return the zigzag level order traversal of its nodes' values. 
/// (ie, from left to right, then right to left for the next level and alternate between).
///
/// For example:
/// Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
///
/// return its zigzag level order traversal as:
/// [
///   [3],
///   [20,9],
///   [15,7]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::zigzagLevelOrder(TreeNode* root)
{
    deque<int> level;
    vector<vector<int>> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    int index = 0;
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if (index % 2 == 0)
            {
                level.push_back(node->val);
            }
            else
            {
                level.push_front(node->val);
            }
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        vector<int> one_level;
        for (size_t i = 0; i < level.size(); i++)
        {
            one_level.push_back(level[i]);
        }
        result.push_back(one_level);
        index++;
    }
    return result;
}


/// <summary>
/// Leet Code 107. Binary Tree Level Order Traversal II
///                                                                 
/// Medium
/// 
/// Given the root of a binary tree, return the bottom-up level order 
/// traversal of its nodes' values. (i.e., from left to right, level 
/// by level from leaf to root).
/// 
/// Example 1:
/// Input: root = [3,9,20,null,null,15,7]
/// Output: [[15,7],[9,20],[3]]
///
/// Example 2:
/// Input: root = [1]
/// Output: [[1]]
///
/// Example 3:
/// Input: root = []
/// Output: []
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [0, 2000].
/// 2. -1000 <= Node.val <= 1000
/// </summary>
vector<vector<int>> LeetCodeTree::levelOrderBottom(TreeNode* root)
{
    vector<int> level;
    stack<vector<int>> tree_stack;
    vector<vector<int>> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            level.push_back(node->val);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        tree_stack.push(level);
    }
    while (!tree_stack.empty())
    {
        result.push_back(tree_stack.top());
        tree_stack.pop();
    }
    return result;
}

/// <summary>
/// Leet code #111. Minimum Depth of Binary Tree 
/// Given a binary tree, find its minimum depth.
/// The minimum depth is the number of nodes along the shortest path from the 
/// root node down to the nearest leaf node.
/// </summary>
int LeetCodeTree::minDepth(TreeNode* root)
{
    int level = 0;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level++;;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if ((node->left == nullptr) && (node->right == nullptr))
            {
                return level;
            }
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return level;
}

/// <summary>
/// Leet code #104. Maximum Depth of Binary Tree 
/// Given a binary tree, find its maximum depth.
/// The maximum depth is the number of nodes along the longest path from the 
/// root node down to the farthest leaf node.
/// </summary>
int LeetCodeTree::maxDepth(TreeNode* root)
{
    int level = 0;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        level++;;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return level;
}

/// <summary>
/// Leet code #257. Binary Tree Paths  
/// </summary>
void LeetCodeTree::binaryTreePaths(TreeNode* root, vector<int>&path, vector<string>&result)
{
    if (root == nullptr)
    {
        return;
    }
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        string str = "";
        for (size_t i = 0; i < path.size(); i++)
        {
            str.append(to_string(path[i]) + "->");
        }
        str.append(to_string(root->val));
        result.push_back(str);
    }
    path.push_back(root->val);
    binaryTreePaths(root->left, path, result);
    binaryTreePaths(root->right, path, result);
    path.pop_back();
}

/// <summary>
/// Leet code #257. Binary Tree Paths  
/// Given a binary tree, return all root-to-leaf paths.
/// For example, given the following binary tree: 
///     1
///   /   \
///  2     3
///   \
///    5
/// All root-to-leaf paths are: 
/// ["1->2->5", "1->3"]
/// </summary>
vector<string> LeetCodeTree::binaryTreePaths(TreeNode* root)
{
    vector<string> result;
    vector<int> path;
    binaryTreePaths(root, path, result);
    return result;
}

/// <summary>
/// Leet code #226. Invert Binary Tree   
/// Invert a binary tree. 
///      4
///    /   \
///   2     7
///  / \   / \
/// 1   3 6   9
/// to 
///      4
///    /   \
///   7     2
///  / \   / \
/// 9   6 3   1
/// Trivia:
/// This problem was inspired by this original tweet by Max Howell: 
/// Google: 90% of our engineers use the software you wrote (Homebrew), 
/// but you can’t invert a binary tree on a whiteboard so fuck off.	
/// </summary>
TreeNode* LeetCodeTree::invertTree(TreeNode* root)
{
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            swap(node->left, node->right);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return root;
}

/// <summary>
/// Leet code #199. Binary Tree Right Side View 
/// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom. 
/// For example:
/// Given the following binary tree,
///     1            <---
///   /   \
///  2     3         <---
///   \     \
///    5     4       <---
/// You should return [1, 3, 4]. 
/// </summary> 
vector<int> LeetCodeTree::rightSideView(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode*> tree_queue;
    if (root != nullptr) tree_queue.push(root);
    while (!tree_queue.empty())
    {
        int last_int;
        size_t size = tree_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* tree_node = tree_queue.front();
            tree_queue.pop();
            if (tree_node->left != nullptr)
            {
                tree_queue.push(tree_node->left);
            }
            if (tree_node->right != nullptr)
            {
                tree_queue.push(tree_node->right);
            }
            last_int = tree_node->val;
        }
        result.push_back(last_int);
    }
    return result;
}

/// <summary>
/// Leet code #98. Validate Binary Search Tree
/// Given a binary tree, determine if it is a valid binary search tree (BST).
/// Assume a BST is defined as follows: 
/// The left subtree of a node contains only nodes with keys less than the node's key.
/// The right subtree of a node contains only nodes with keys greater than the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// Example 1:
///    2
///   / \
///  1   3
/// Binary tree [2,1,3], return true. 
/// Example 2:
///    1
///   / \
///  2   3
/// Binary tree [1,2,3], return false. 
/// </summary> 
bool LeetCodeTree::isValidBST(TreeNode* root)
{
    vector<int> value_list;
    stack<TreeNode *> search_stack;
    TreeNode * node = root;

    while (true)
    {
        if (node != nullptr)
        {
            search_stack.push(node);
            node = node->left;
            continue;
        }
        if (search_stack.empty())
        {
            break;
        }
        node = search_stack.top();
        value_list.push_back(node->val);
        search_stack.pop();
        node = node->right;
    }

    for (size_t i = 1; i < value_list.size(); i++)
    {
        if (value_list[i - 1] >= value_list[i])
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #331. Verify Preorder Serialization of a Binary Tree
/// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, 
/// we record the node's value. If it is a null node, we record using a sentinel value such as #.
///       _9_
///      /   \
///     3     2
///    / \   / \
///   4   1  #  6
///  / \ / \   / \
///  # # # #   # #	
/// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node. 
/// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. 
/// Find an algorithm without reconstructing the tree.
/// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
/// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
/// Example 1:
/// "9,3,4,#,#,1,#,#,2,#,6,#,#"
/// Return true
/// Example 2:
/// "1,#"
/// Return false
/// Example 3:
/// "9,#,#,1"
/// Return false
/// </summary>
bool LeetCodeTree::isValidPreorderSerialization(string preorder)
{
    vector<string> tree_stack;
    string node;
    for (size_t i = 0; i <= preorder.size(); i++)
    {
        if ((i == preorder.size()) || (preorder[i] == ','))
        {
            if (!node.empty()) tree_stack.push_back(node);
            while ((tree_stack.size() > 2) &&
                (tree_stack[tree_stack.size() - 1] == "#") &&
                (tree_stack[tree_stack.size() - 2] == "#") &&
                (tree_stack[tree_stack.size() - 3] != "#"))
            {
                tree_stack.pop_back();
                tree_stack.pop_back();
                tree_stack.pop_back();
                tree_stack.push_back("#");
            }
            node.clear();
        }
        else
        {
            node.push_back(preorder[i]);
        }
    }
    if (tree_stack.size() == 1 && tree_stack.back() == "#") return true;
    else return false;
}

/// <summary>
/// Leet code #110. Balanced Binary Tree
/// </summary>
bool LeetCodeTree::isBalanced(TreeNode* root, int& depth)
{
    if (root == nullptr)
    {
        depth = 0;
        return true;
    }
    else
    {
        int left_depth = 0;
        int right_depth = 0;

        if (!isBalanced(root->left, left_depth) || 
            !isBalanced(root->right, right_depth))
        {
            depth = max(left_depth, right_depth) + 1;
            return false;
        }
        else
        {
            depth = max(left_depth, right_depth) + 1;
            if (abs(left_depth - right_depth) <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

/// <summary>
/// Leet Code 110. Balanced Binary Tree
///                                                                 
/// Easy
///
/// Given a binary tree, determine if it is height-balanced.
/// 
/// For this problem, a height-balanced binary tree is defined as:
/// a binary tree in which the left and right subtrees of every node 
/// differ in height by no more than 1.
/// 
/// Example 1:
/// Input: root = [3,9,20,null,null,15,7]
/// Output: true
///
/// Example 2:
/// Input: root = [1,2,2,3,3,null,null,4,4]
/// Output: false
///
/// Example 3:
/// Input: root = []
/// Output: true
///  
/// Constraints:
/// 1. The number of nodes in the tree is in the range [0, 5000].
/// -10^4 <= Node.val <= 10^4
/// </summary>
bool LeetCodeTree::isBalanced(TreeNode* root)
{
    int depth;
    return isBalanced(root, depth);
}

/// <summary>
/// Leet code #236. Lowest Common Ancestor of a Binary Tree
/// </summary>
int LeetCodeTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, 
    TreeNode* &result)
{
    int count = 0;
    if (root == nullptr) return 0;

    if (root == p || root == q) count = 1;

    count += lowestCommonAncestor(root->left, p, q, result);
    if (count < 2)
    {
        count += lowestCommonAncestor(root->right, p, q, result);
    }
    // if first time we see 2 node found, this is the answer.
    if (count == 2 && result == nullptr) result = root;

    return count;
}
/// <summary>
/// Leet Code 236. Lowest Common Ancestor of a Binary Tree
///                                                                 
/// Medium
///
/// Given a binary tree, find the lowest common ancestor (LCA) of two 
/// given nodes in the tree.
/// 	    _______3______
///        /              \
///     ___5__          ___1__
///    /      \        /      \
///    6       2       0       8
///           / \
///          7   4
/// According to the definition of LCA on Wikipedia: “The lowest common 
/// ancestor is defined between two nodes p and q as the lowest node 
/// in T that has both p and q as descendants (where we allow a node 
/// to be a descendant of itself).”
/// 
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
/// Output: 3
 /// Explanation: The LCA of nodes 5 and 1 is 3.
///
/// Example 2:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
/// Output: 5
/// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be 
/// a descendant of itself according to the LCA definition.
///
/// Example 3:
/// Input: root = [1,2], p = 1, q = 2
/// Output: 1
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [2, 10^5].
/// 2. -10^9 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. p != q
/// 5. p and q will exist in the tree.
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode * result = nullptr;
    int count = lowestCommonAncestor(root, p, q, result);
    
    return result;
}

/// <summary>
/// Leet code #235. Lowest Common Ancestor of a Binary Search Tree
/// Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST. 
/// According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two nodes 
/// v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)." 
///        _______6______
///       /              \
///    ___2__          ___8__
///   /      \        /      \
///   0       4      7        9
///          / \
///         3   5
/// For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
/// since a node can be a descendant of itself according to the LCA definition.
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* node = root;
    while (true)
    {
        if ((node == nullptr) || (p == nullptr) || (q == nullptr))
        {
            return nullptr;
        }
        if ((node->val > p->val) && (node->val > q->val))
        {
            node = node->left;
        }
        else if ((node->val < p->val) && (node->val < q->val))
        {
            node = node->right;
        }
        else
        {
            return node;
        }
    }
}

/// <summary>
/// Leet code #114. Flatten Binary Tree to Linked List
/// Given a binary tree, flatten it to a linked list in-place. 
/// For example,
/// Given 
///     1
///    / \
///   2   5
///  / \   \
/// 3   4   6
/// The flattened tree should look like:
///    1
///     \
///      2
///       \
///        3
///         \
///          4
///           \
///            5
///             \
///              6
/// </summary>
void LeetCodeTree::flatten(TreeNode* root)
{
    TreeNode * tree_first = nullptr;
    TreeNode * tree_last = nullptr;
    stack<TreeNode*> tree_stack;
    if (root != nullptr)
    {
        tree_stack.push(root);
    }
    while (!tree_stack.empty())
    {
        TreeNode * treeNode = tree_stack.top();
        tree_stack.pop();
        if (treeNode->right != nullptr)
        {
            tree_stack.push(treeNode->right);
        }
        if (treeNode->left != nullptr)
        {
            tree_stack.push(treeNode->left);
        }
        if (tree_first == nullptr)
        {
            tree_first = treeNode;
            tree_last = treeNode;
        }
        else
        {
            tree_last->right = treeNode;
            tree_last = treeNode;
        }
        if (treeNode != nullptr) treeNode->left = nullptr;
        if (treeNode != nullptr) treeNode->right = nullptr;
    }
}

/// <summary>
/// Leet code #112. Path Sum
/// Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
/// such that adding up all the values along the path equals the given sum. 
/// For example:
/// Given the below binary tree and sum = 22,               
///          5
///         / \
///        4   8
///       /   / \
///      11  13  4
///     /  \      \
///    7    2      1
/// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
/// </summary>
bool LeetCodeTree::hasPathSum(TreeNode* root, int sum)
{
    if (root == nullptr) return false;
    if (root != nullptr)
    {
        if ((root->left == nullptr) && (root->right == nullptr) && (root->val == sum))
        {
            return true;
        }
        if ((root->left != nullptr) && hasPathSum(root->left, sum - root->val))
        {
            return true;
        }
        if ((root->right != nullptr) && hasPathSum(root->right, sum - root->val))
        {
            return true;
        }
    }
    return false;
}

/// <summary>
/// Leet code #113. Path Sum II
/// </summary>
void LeetCodeTree::pathSum(TreeNode* root, int sum, vector<int>&path, vector<vector<int>> &result)
{
    if (root == nullptr)
    {
        return;
    }
    path.push_back(root->val);
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        if (root->val == sum) result.push_back(path);
    }
    else
    {
        if (root->left != nullptr) pathSum(root->left, sum - root->val, path, result);
        if (root->right != nullptr) pathSum(root->right, sum - root->val, path, result);
    }
    path.pop_back();
}

/// <summary>
/// Leet code #113. Path Sum II
/// Given a binary tree and a sum, find all root-to-leaf paths where each 
/// path's sum equals the given sum.  
/// For example:
/// Given the below binary tree and sum = 22,              
///          5
///         / \
///        4   8
///       /   / \
///      11  13  4
///     /  \    / \
///    7    2  5   1
/// return
/// [
///   [5,4,11,2],
///   [5,8,4,5]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::pathSum(TreeNode* root, int sum)
{
    vector<int>path;
    vector<vector<int>> result;
    pathSum(root, sum, path, result);
    return result;
}

/// <summary>
/// Preorder traverse with the path passed on the way to check the sum.
/// </summary>
int LeetCodeTree::pathSumIII(TreeNode* root, vector<int>& path, int sum)
{
    int count = 0;
    if (root == nullptr) return 0;
    path.push_back(root->val);
    int total = 0;
    // from bottom to search up is to make sure we do not
    // have duplicate
    for (int i = (int)path.size() - 1; i >= 0; i--)
    {
        total += path[i];
        if (total == sum) count++;
    }
    count += pathSumIII(root->left, path, sum);
    count += pathSumIII(root->right, path, sum);
    path.pop_back();
    return count;
}

/// <summary>
/// Leet code #437. Path Sum III     
/// You are given a binary tree in which each node contains an integer value. 
/// Find the number of paths that sum to a given value.
/// The path does not need to start or end at the root or a leaf, 
/// but it must go downwards (traveling only from parent nodes to child nodes).
/// The tree has no more than 1,000 nodes and the values are in the range 
/// -1,000,000 to 1,000,000. 
/// Example: 
/// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
///        10
///       /  \
///      5   -3
///     / \    \
///    3   2   11
///   / \   \
///  3  -2   1
///
/// Return 3. The paths that sum to 8 are:
///
/// 1.  5 -> 3
/// 2.  5 -> 2 -> 1
/// 3. -3 -> 11
/// </summary>
int LeetCodeTree::pathSumIII(TreeNode* root, int sum)
{
    vector<int> path;
    return pathSumIII(root, path, sum);
}

/// <summary>
/// Leet code #129. Sum Root to Leaf Numbers    
/// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.  
/// An example is the root-to-leaf path 1->2->3 which represents the number 123.
/// Find the total sum of all root-to-leaf numbers.
/// For example, 
///   1
///  / \
/// 2   3
/// The root-to-leaf path 1->2 represents the number 12.
/// The root-to-leaf path 1->3 represents the number 13.
/// Return the sum = 12 + 13 = 25.
/// </summary>
int LeetCodeTree::sumNumbers(TreeNode* root)
{
    int result = 0;
    vector<pair<TreeNode *, int>> tree_list;
    if (root != nullptr)
    {
        tree_list.push_back(make_pair(root, 0));
    }

    while (!tree_list.empty())
    {
        pair<TreeNode *, int> pair = tree_list.back();
        if (pair.second == 0)
        {
            TreeNode * left = pair.first->left;
            if (left == nullptr)
            {
                tree_list[tree_list.size() - 1].second++;
            }
            else
            {
                tree_list.push_back(make_pair(left, 0));
            }
        }
        else if (pair.second == 1)
        {
            TreeNode * right = pair.first->right;
            if (right == nullptr)
            {
                tree_list[tree_list.size() - 1].second++;
            }
            else
            {
                tree_list.push_back(make_pair(right, 0));
            }
        }
        else
        {
            if ((pair.first->left == nullptr) && (pair.first->right == nullptr))
            {
                int path_sum = 0;
                for (size_t i = 0; i < tree_list.size(); i++)
                {
                    path_sum *= 10;
                    path_sum += tree_list[i].first->val;
                }
                result += path_sum;
            }
            tree_list.pop_back();
            if (tree_list.empty()) continue;
            tree_list[tree_list.size() - 1].second++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #105. Build binary tree from preoder and inorder travesal
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromPreorderandInorder(
    vector<int>& preorder, vector<int>& inorder,
    size_t start_preorder, size_t start_inorder,
    size_t length)
{
    if (length == 0)
    {
        return nullptr;
    }
    TreeNode *root;
    root = new TreeNode(preorder[start_preorder]);
    size_t index;
    for (index = 0; index < length; index++)
    {
        if (inorder[start_inorder + index] == preorder[start_preorder])
        {
            break;
        }
    }
    TreeNode *left = buildTreeFromPreorderandInorder(preorder, inorder, start_preorder + 1,
        start_inorder, index);
    TreeNode *right = buildTreeFromPreorderandInorder(preorder, inorder,
        start_preorder + 1 + index, start_inorder + index + 1, length - index - 1);
    root->left = left;
    root->right = right;
    return root;
}

/// <summary>
/// Leet code #105. Construct Binary Tree from Preorder and Inorder Traversal
///
/// Medium
///
/// Given preorder and inorder traversal of a tree, construct the binary tree.
///
/// Note:
/// You may assume that duplicates do not exist in the tree.
///
/// For example, given
///
/// preorder = [3,9,20,15,7]
/// inorder = [9,3,15,20,7]
/// Return the following binary tree:
///
///    3
///   / \
///  9  20
///    /  \
///   15   7    
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromPreorderandInorder(vector<int>& preorder, vector<int>& inorder)
{
    if ((preorder.size() == 0) || (inorder.size() == 0))
    {
        return nullptr;
    }
    TreeNode *root = 
        buildTreeFromPreorderandInorder(preorder, inorder, 0, 0, preorder.size());
    return root;
}

/// <summary>
/// Leet code #106. Construct Binary Tree from Inorder and Postorder Traversal
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromInorderAndPostorder(
    vector<int>& inorder, vector<int>& postorder,
    size_t start_inorder, size_t start_postorder,
    size_t length)
{
    if (length == 0)
    {
        return nullptr;
    }
    TreeNode *root;
    root = new TreeNode(postorder[start_postorder + length - 1]);
    size_t index;
    for (index = 0; index < length; index++)
    {
        if (inorder[start_inorder + index] == postorder[start_postorder + length - 1])
        {
            break;
        }
    }
    TreeNode *left = buildTreeFromInorderAndPostorder(inorder, postorder,
        start_inorder, start_postorder, index);
    TreeNode *right = buildTreeFromInorderAndPostorder(inorder, postorder,
        start_inorder + index + 1, start_postorder + index, length - index - 1);
    root->left = left;
    root->right = right;
    return root;
}

/// <summary>
/// Leet code #106. Construct Binary Tree from Inorder and Postorder Traversal
///
/// Medium
///
/// Given inorder and postorder traversal of a tree, construct the binary tree.
///
/// Note:
/// You may assume that duplicates do not exist in the tree.
///
/// For example, given
///
/// preorder = [3,9,20,15,7]
/// postorder = [9,15,7,20,3]
/// Return the following binary tree:
///
///    3
///   / \
///  9  20
///    /  \
///   15   7    
/// </summary>
TreeNode* LeetCodeTree::buildTreeFromInorderAndPostorder(vector<int>& inorder, vector<int>& postorder)
{
    if ((inorder.size() == 0) || (postorder.size() == 0))
    {
        return nullptr;
    }
    TreeNode *root = 
        buildTreeFromInorderAndPostorder(inorder, postorder, 0, 0, inorder.size());
    return root;
}

/// <summary>
/// Leet code #100. Same Tree
///
/// Easy
///
/// Given two binary trees, write a function to check if they are the same 
/// or not.
///
/// Two binary trees are considered the same if they are structurally 
/// identical and the nodes have the same value.
///
/// Example 1:
///
/// Input:     1         1
///           / \       / \
    ///          2   3     2   3
    ///
    ///        [1,2,3],   [1,2,3]
    ///
    /// Output: true
    /// Example 2:
    ///
    /// Input:     1         1
    ///           /           \
    ///          2             2
    ///
    ///        [1,2],     [1,null,2]
    ///
    /// Output: false
    /// Example 3:
    ///
    /// Input:     1         1
    ///           / \       / \
    ///          2   1     1   2
    ///
    ///        [1,2,1],   [1,1,2]
    ///
    /// Output: false
    /// </summary>
bool LeetCodeTree::isSameTree(TreeNode* p, TreeNode* q)
{
    if ((p == nullptr) && (q == nullptr))
    {
        return true;
    }
    else if (((p == nullptr) && (q != nullptr)) || ((p != nullptr) && (q == nullptr)))
    {
        return false;
    }
    else
    {
        if (p->val != q->val) return false;
        if (!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Find the two disordered nodes in the binary search tree 
/// </summary>
void LeetCodeTree::recoverTree(TreeNode* root, TreeNode* &min_node, TreeNode* &max_node,
    TreeNode* &first, TreeNode* &second)
{
    if (root == nullptr) return;
    TreeNode* left_min = root;
    TreeNode* left_max = root;
    TreeNode* right_min = root;
    TreeNode* right_max = root;
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        min_node = root;
        max_node = root;
        return;
    }
    if (root->left != nullptr)
    {
        recoverTree(root->left, left_min, left_max, first, second);
    }
    if (root->right != nullptr)
    {
        recoverTree(root->right, right_min, right_max, first, second);
    }

    if (left_max->val > root->val)
    {
        first = left_max;
        second = root;
    }
    if (root->val > right_min->val)
    {
        if (left_max->val <= root->val) first = root;
        second = right_min;
    }

    min_node = left_min;
    if (root->val < min_node->val) min_node = root;
    if (right_min->val < min_node->val) min_node = right_min;

    max_node = left_max;
    if (root->val > max_node->val) max_node = root;
    if (right_max->val > max_node->val) max_node = right_max;
}

/// <summary>
/// Leet code #99. Recover Binary Search Tree 
/// Two elements of a binary search tree (BST) are swapped by mistake.
/// Recover the tree without changing its structure.
/// Note:
/// A solution using O(n) space is pretty straight forward. Could you devise 
/// a constant space solution?
/// </summary>
void LeetCodeTree::recoverTree(TreeNode* root)
{
    TreeNode *min_node = nullptr, *max_node = nullptr;
    TreeNode *first = nullptr, *second = nullptr;
    recoverTree(root, min_node, max_node, first, second);
    if ((first != nullptr) && (second != nullptr))
    {
        swap(first->val, second->val);
    }
}

/// <summary>
/// Find the two disordered nodes in the binary search tree 
/// </summary>
void LeetCodeTree::recoverTreeII(TreeNode* root, TreeNode* &prev,
    TreeNode* &first, TreeNode* &second)
{
    if (root == nullptr) return;
    if (root->left != nullptr)
    {
        recoverTreeII(root->left, prev, first, second);
    }
    if ((prev != nullptr) && (prev->val > root->val))
    {
        if (first == nullptr)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    if (root->right != nullptr)
    {
        recoverTreeII(root->right, prev, first, second);
    }
}

/// <summary>
/// Leet code #99. Recover Binary Search Tree 
/// Two elements of a binary search tree (BST) are swapped by mistake.
/// Recover the tree without changing its structure.
/// Note:
/// A solution using O(n) space is pretty straight forward. 
/// Could you devise a constant space solution?
/// </summary>
void LeetCodeTree::recoverTreeII(TreeNode* root)
{
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    recoverTreeII(root, prev, first, second);
    if ((first != nullptr) && (second != nullptr))
    {
        swap(first->val, second->val);
    }
}

/// <summary>
/// Leet Code 101. Symmetric Tree
///                                                                 
/// Easy
/// 
/// Given the root of a binary tree, check whether it is a mirror of 
/// itself (i.e., symmetric around its center).
///  
/// Example 1:
/// Input: root = [1,2,2,3,4,4,3]
/// Output: true
///
/// Example 2:
/// Input: root = [1,2,2,null,3,null,3]
/// Output: false
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 1000].
/// 2. -100 <= Node.val <= 100
///  
/// Follow up: Could you solve it both recursively and iteratively?
/// </summary>
bool LeetCodeTree::isSymmetric(TreeNode* root)
{
    vector<TreeNode*> tree_list;
    queue<TreeNode*> tree_queue;
    TreeNode * node = root;
    tree_queue.push(root);

    while (!tree_queue.empty())
    {
        size_t size = tree_queue.size();
        tree_list.clear();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = tree_queue.front();
            tree_list.push_back(node);
            tree_queue.pop();
            if (node != nullptr)
            {
                tree_queue.push(node->left);
                tree_queue.push(node->right);
            }
        }
        int first = 0, last = tree_list.size() - 1;
        while (first < last)
        {
            if (((tree_list[first] == nullptr) && (tree_list[last] != nullptr)) ||
                ((tree_list[first] != nullptr) && (tree_list[last] == nullptr)))
            {
                return false;
            }
            if ((tree_list[first] != nullptr) && (tree_list[last] != nullptr) &&
                (tree_list[first]->val != tree_list[last]->val))
            {
                return false;
            }
            first++; last--;
        }
    }
    return true;
}

/// <summary>
/// Build Binary Search Tree from sorted array 
/// </summary>
TreeNode* LeetCodeTree::buildBSTFromSortedArray(vector<int>& nums, int first, int last)
{
    int middle = first + (last - first) / 2;
    TreeNode * root = new TreeNode(nums[middle]);
    if (first != middle)
    {
        root->left = buildBSTFromSortedArray(nums, first, middle - 1);
    }
    if (last != middle)
    {
        root->right = buildBSTFromSortedArray(nums, middle + 1, last);
    }
    return root;
}

/// <summary>
/// Leet code #108. Convert Sorted Array to Binary Search Tree 
/// Given an array where elements are sorted in ascending order, convert it to a height 
/// balanced BST.
/// </summary>
TreeNode* LeetCodeTree::sortedArrayToBST(vector<int>& nums)
{
    if (nums.empty()) return nullptr;
    return buildBSTFromSortedArray(nums, 0, nums.size() - 1);
}

/// <summary>
/// Leet code #109. Convert Sorted List to Binary Search Tree
/// Given a singly linked list where elements are sorted in ascending order, 
/// convert it to a height balanced BST.
/// </summary>
TreeNode* LeetCodeTree::sortedListToBST(ListNode* head)
{
    if (head == nullptr) return nullptr;
    ListNode *head_new = nullptr, *prev = nullptr;

    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        ListNode * node = new ListNode(ptr->val);
        if (head_new == nullptr)
        {
            head_new = node;
            prev = node;
        }
        else
        {
            prev->next = node;
            prev = prev->next;
        }
        ptr = ptr->next;
    }

    head = head_new;
    ListNode *slow = head, *fast = head;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast == nullptr) break;
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    TreeNode * root = new TreeNode(slow->val);
    if (prev != slow)
    {
        prev->next = nullptr;
        root->left = sortedListToBST(head);
    }
    if (slow->next != nullptr)
    {
        root->right = sortedListToBST(slow->next);
    }
    // Please remove this line when you submit to LeetCode, because it will delete list 
    delete slow;
    return root;
}

/// <summary>
/// Leet code #404. Sum of Left Leaves 
/// Find the sum of all left leaves in a given binary tree.
/// Example: 
///     3
///    / \
///   9  20
///     /  \
///    15   7 
/// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
/// </summary>
int LeetCodeTree::sumOfLeftLeaves(TreeNode* root)
{
    queue<TreeNode*> tree_queue;
    tree_queue.push(root);
    int sum = 0;
    while (!tree_queue.empty())
    {
        TreeNode * tree_node = tree_queue.front();
        tree_queue.pop();
        if (tree_node == nullptr) continue;

        TreeNode * left = tree_node->left;
        tree_queue.push(left);
        // if the node is leaf, sum the value, it must be left leaf
        if ((left != nullptr) && (left->left == nullptr) && (left->right == nullptr))
        {
            sum += left->val;
        }
        TreeNode * right = tree_node->right;
        tree_queue.push(right);
    }
    return sum;
}

/// <summary>
/// Leet code #124. Binary Tree Maximum Path Sum
/// </summary>
void LeetCodeTree::maxPathSum(TreeNode* root, int &max_path_sum, int&max_path_loop)
{
    if (root == nullptr)
    {
        max_path_sum = 0;
        max_path_loop = INT_MIN;
    }
    else
    {
        int max_path_sum_left, max_path_loop_left;
        maxPathSum(root->left, max_path_sum_left, max_path_loop_left);
        int max_path_sum_right, max_path_loop_right;
        maxPathSum(root->right, max_path_sum_right, max_path_loop_right);

        max_path_sum = max(max_path_sum_left + root->val, max_path_sum_right + root->val);
        max_path_sum = max(max_path_sum, root->val);
        max_path_loop = max(max_path_loop_left, max_path_loop_right);
        max_path_loop = max(max_path_loop, root->val + max_path_sum_left + max_path_sum_right);
        max_path_loop = max(max_path_loop, max_path_sum);
    }
}

/// <summary>
/// Leet code #124. Binary Tree Maximum Path Sum 
///
/// Given a binary tree, find the maximum path sum. 
/// For this problem, a path is defined as any sequence of nodes from some 
/// starting node to any node in the tree along the parent-child connections. 
/// The path must contain at least 
/// one node and does not need to go through the root.
/// For example:
/// Given the below binary tree, 
///     1
///    / \
///   2   3
/// Return 6.
/// Explanation:
/// The max_path must come from the left direct path + self, the right direct 
/// path + self and the maximum left loop path and maximum right loop path. 
/// </summary>
int LeetCodeTree::maxPathSum(TreeNode* root)
{
    int max_path_loop = 0;
    int max_path_sum = 0;
    maxPathSum(root, max_path_sum, max_path_loop);
    return max_path_loop;
}

/// <summary>
/// Leet code #337. House Robber III 
/// </summary>
void LeetCodeTree::robIII(TreeNode* root, int& rob_with_root, int& rob_without_root)
{
    rob_with_root = 0;
    rob_without_root = 0;
    if (root != nullptr)
    {
        int left_rob_with_root = 0, left_rob_without_root = 0;
        robIII(root->left, left_rob_with_root, left_rob_without_root);
        int right_rob_with_root = 0, right_rob_without_root = 0;
        robIII(root->right, right_rob_with_root, right_rob_without_root);
        rob_with_root = root->val + left_rob_without_root + right_rob_without_root;
        rob_without_root = left_rob_with_root + right_rob_with_root;
        rob_with_root = max(rob_with_root, rob_without_root);
    }
}

/// <summary>
/// Leet code #337. House Robber III 
/// The thief has found himself a new place for his thievery again. 
/// There is only one entrance to this area, 
/// called the "root." Besides the root, each house has one and only 
/// one parent house. After a tour, the smart 
/// thief realized that "all houses in this place forms a binary tree". 
/// It will automatically contact the police 
/// if two directly-linked houses were broken into on the same night. 
/// Determine the maximum amount of money the thief can rob tonight 
/// without alerting the police.
/// Example 1:	
///     3
///    / \
///   2   3
///    \   \ 
///     3   1
/// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
/// Example 2:
///	     3
///     / \
///    4   5
///   / \   \ 
///  1   3   1
/// Maximum amount of money the thief can rob = 4 + 5 = 9. 
/// </summary>
int LeetCodeTree::robIII(TreeNode* root)
{
    int rob_with_root = 0;
    int rob_without_root = 0;
    robIII(root, rob_with_root, rob_without_root);
    return rob_with_root;
}

/// <summary>
/// Append the tree linked node to end
/// </summary>
void LeetCodeTree::connectRight(TreeLinkNode *&head, TreeLinkNode *&ptr, TreeLinkNode * node)
{
    if (node == nullptr) return;
    node->next = nullptr;
    if (head == nullptr)
    {
        head = node;
    }
    else
    {
        ptr->next = node;
    }
    ptr = node;
}

/// <summary>
/// Leet code #116. Populating Next Right Pointers in Each Node           
/// struct TreeLinkNode {
///    int val;
///    TreeLinkNode *left, *right, *next;
///    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
/// };  
/// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
///
/// Initially, all next pointers are set to NULL.
///
/// Note: 
/// You may only use constant extra space.
/// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
///
/// For example,
/// Given the following perfect binary tree,
///         1
///       /   \
///      2     3
///     / \   / \
///    4   5 6   7
/// After calling your function, the tree should look like:
/// 
///         1 -> NULL
///       /   \
///      2 ->  3 -> NULL
///     / \   / \
///    4-> 5->6 ->7 -> NULL
/// </summary>
TreeLinkNode* LeetCodeTree::connectRight(TreeLinkNode *root)
{
    TreeLinkNode* prev_head = nullptr, *prev_ptr = nullptr;
    TreeLinkNode* curr_head, *curr_ptr;
    prev_head = root;
    while (prev_head)
    {
        prev_ptr = prev_head;
        curr_head = nullptr;
        curr_ptr = nullptr;
        while (prev_ptr != nullptr)
        {
            connectRight(curr_head, curr_ptr, prev_ptr->left);
            connectRight(curr_head, curr_ptr, prev_ptr->right);
            prev_ptr = prev_ptr->next;
        }
        prev_head = curr_head;
    }
    return root;
}

/// <summary>
/// Leet code #117. Populating Next Right Pointers in Each Node II           
///
/// Given a binary tree 
/// struct TreeLinkNode {
///    int val;
///    TreeLinkNode *left, *right, *next;
///    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
/// };  
///
/// Follow up for problem "Populating Next Right Pointers in Each Node".
///
/// What if the given tree could be any binary tree? Would your previous 
/// solution still work?
///
/// Note: 
/// You may only use constant extra space.
///
/// For example,
/// Given the following binary tree,
///
///         1
///       /  \
///      2    3
///     / \    \
///    4   5    7
/// After calling your function, the tree should look like:
///
///         1 -> NULL
///       /  \
///      2 -> 3 -> NULL
///     / \    \
///    4-> 5 -> 7 -> NULL
/// </summary>
TreeLinkNode* LeetCodeTree::connectRightII(TreeLinkNode *root)
{
    TreeLinkNode* prev_head = nullptr, *prev_ptr = nullptr;
    TreeLinkNode* curr_head, *curr_ptr;
    prev_head = root;
    while (prev_head)
    {
        prev_ptr = prev_head;
        curr_head = nullptr;
        curr_ptr = nullptr;
        while (prev_ptr != nullptr)
        {
            connectRight(curr_head, curr_ptr, prev_ptr->left);
            connectRight(curr_head, curr_ptr, prev_ptr->right);
            prev_ptr = prev_ptr->next;
        }
        prev_head = curr_head;
    }
    return root;
}

/// <summary>
/// Leet code #222. Count Complete Tree Nodes               
/// Given a complete binary tree, count the number of nodes.
/// Definition of a complete binary tree from Wikipedia:
/// In a complete binary tree every level, except possibly the last, is completely filled, 
/// and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes 
/// inclusive at the last level h. 
/// </summary>
int LeetCodeTree::countCompleteTreeNodes(TreeNode* root)
{
    int left_height = 0, right_height = 0;
    TreeNode * node = root;
    while (node != nullptr)
    {
        left_height += 1;
        node = node->left;
    }
    node = root;
    while (node != nullptr)
    {
        right_height += 1;
        node = node->right;
    }

    int count = 0;
    if (left_height == right_height)
    {
        count = (1 << left_height) - 1;
    }
    else
    {
        count = 1;
        count += countCompleteTreeNodes(root->left);
        count += countCompleteTreeNodes(root->right);
    }

    return count;
}

/// <summary>
/// Return kth smallest node in BST
/// </summary>
int LeetCodeTree::findKthSmallest(TreeNode* root, int &k)
{
    if (root == nullptr) return 0;
    int value = findKthSmallest(root->left, k);
    if (k == 0) return value;
    k--;
    if (k == 0) return root->val;
    value = findKthSmallest(root->right, k);
    return value;
}

/// <summary>
/// Leet Code 230. Kth Smallest Element in a BST
///                                                                 
/// Medium
/// 
/// Given the root of a binary search tree, and an integer k, return the 
/// kth smallest value (1-indexed) of all the values of the nodes in the 
/// tree.
/// 
/// Example 1:
/// Input: root = [3,1,4,null,2], k = 1
/// Output: 1
///
/// Example 2:
/// Input: root = [5,3,6,2,4,null,null,1], k = 3
/// Output: 3
///
/// Constraints:
/// 1. The number of nodes in the tree is n.
/// 2. 1 <= k <= n <= 10^4
/// 3. 0 <= Node.val <= 10^4
///
/// Follow up: If the BST is modified often (i.e., we can do insert and 
/// delete operations) and you need to find the kth smallest frequently, 
/// how would you optimize?
/// </summary>
int LeetCodeTree::kthSmallest(TreeNode* root, int k)
{
    return findKthSmallest(root, k);
}

/// <summary>
/// Leet code #450. Delete Node in a BST 
/// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
/// Return the root node reference (possibly updated) of the BST.
///
/// Basically, the deletion can be divided into two stages: 
/// 1.Search for a node to remove.
/// 2.If the node is found, delete the node.
///
/// Note: Time complexity should be O(height of tree).
/// Example: 
/// root = [5,3,6,2,4,null,7]
/// key = 3
///     5
///    / \
///   3   6
///  / \   \
/// 2   4   7
/// Given key to delete is 3. So we find the node with value 3 and delete it.
/// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
///     5
///    / \
///   4   6
///  /     \
/// 2       7
/// Another valid answer is [5,2,6,null,4,null,7].
///     5
///    / \
///   2   6
///    \   \
///     4   7
/// </summary>
TreeNode* LeetCodeTree::deleteNode(TreeNode* root, int key)
{
    if (root == nullptr) return nullptr;
    if (root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            TreeNode* node = root->right;
            delete root;
            return node;
        }
        else if (root->right == nullptr)
        {
            TreeNode* node = root->left;
            delete root;
            return node;
        }
        else
        {
            TreeNode * child = root->left;
            while (child->right != nullptr)
            {
                child = child->right;
            }
            root->val = child->val;
            root->left = deleteNode(root->left, child->val);
        }
    }
    return root;
}

/// <summary>
/// Leet code #366. Find Leaves of Binary Tree      
/// </summary>
int LeetCodeTree::findLeaves(TreeNode* root, vector<vector<int>> &result)
{
    if (root == nullptr) return 0;
    int left_depth = 0;
    int right_depth = 0;
    if (root->left != nullptr)
    {
        left_depth = findLeaves(root->left, result);
    }
    if (root->right != nullptr)
    {
        right_depth = findLeaves(root->right, result);
    }
    int depth = max(left_depth, right_depth) + 1;
    if (depth > (int)result.size())
    {
        result.push_back(vector<int>());
    }
    result[depth - 1].push_back(root->val);
    return depth;
}

/// <summary>
/// Leet code #366. Find Leaves of Binary Tree      
/// 
/// Given a binary tree, collect a tree's nodes as if you were doing this: 
/// Collect and remove all leaves, repeat until the tree is empty.
/// Example:
/// Given binary tree 
///          1
///         / \
///        2   3
///       / \     
///      4   5    
///
/// Returns [4, 5, 3], [2], [1]. 
/// Explanation:
/// 1. Removing the leaves [4, 5, 3] would result in this tree: 
///          1
///         / 
///        2          
///
/// 2. Now removing the leaf [2] would result in this tree: 
///          1          
/// 3. Now removing the leaf [1] would result in the empty tree: 
///          []         
///
/// Returns [4, 5, 3], [2], [1]. 
/// </summary>
vector<vector<int>> LeetCodeTree::findLeaves(TreeNode* root)
{
    vector<vector<int>> result;
    findLeaves(root, result);
    return result;
}

/// <summary>
/// Leet code #156. Binary Tree Upside Down  
/// </summary>
void LeetCodeTree::upsideDownBinaryTree(TreeNode* &root, TreeNode* &right)
{
    if (root == nullptr) return;
    if (root->left == nullptr)
    {
        right = root;
        return;
    }
    else
    {
        TreeNode * left = root->left;
        upsideDownBinaryTree(left, right);
        right->left = root->right;
        right->right = root;
        root->left = nullptr;
        root->right = nullptr;
        right = root;
        root = left;
    }
}

/// <summary>
/// Leet code #156. Binary Tree Upside Down  
/// 
/// Given a binary tree where all the right nodes are either leaf nodes with a sibling 
/// (a left node that shares the same parent node) or empty, flip it upside down and 
/// turn it into a tree where the original right nodes turned into left leaf nodes. 
/// Return the new root. 
/// For example:
/// Given a binary tree {1,2,3,4,5},
///     1
///    / \
///   2   3
///  / \
/// 4   5
/// return the root of the binary tree [4,5,2,#,#,3,1].
///     4
///    / \
///   5   2
///      / \
///     3   1  
/// </summary>
TreeNode* LeetCodeTree::upsideDownBinaryTree(TreeNode* root)
{
    TreeNode * right;
    upsideDownBinaryTree(root, right);
    return root;
}

/// <summary>
/// Leet code #250. Count Univalue Subtrees  
/// </summary>
bool LeetCodeTree::countUnivalSubtrees(TreeNode* root, int& value, int& count)
{
    if (root == nullptr) return true;
    int left_value = 0, left_count = 0;
    bool left_unival = true;
    if (root->left != nullptr)
    {
        left_unival = countUnivalSubtrees(root->left, left_value, left_count);
        if (root->val != left_value)
        {
            left_unival = false;
        }
    }

    int right_value = 0, right_count = 0;
    bool right_unival = true;
    if (root->right != nullptr)
    {
        right_unival = countUnivalSubtrees(root->right, right_value, right_count);
        if (root->val != right_value)
        {
            right_unival = false;
        }
    }
    count = left_count + right_count;
    value = root->val;
    if (left_unival && right_unival)
    {
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #250. Count Univalue Subtrees  
/// 
/// Given a binary tree, count the number of uni-value subtrees.
/// A Uni-value subtree means all nodes of the subtree have the same value.
///
/// For example:
/// Given binary tree,
///              5
///             / \
///            1   5
///           / \   \
///          5   5   5
///
/// return 4. 
/// </summary>
int LeetCodeTree::countUnivalSubtrees(TreeNode* root)
{
    int value = 0;
    int count = 0;
    countUnivalSubtrees(root, value, count);
    return count;
}

/// <summary>
/// Leet code #298. Binary Tree Longest Consecutive Sequence  
/// </summary>
int LeetCodeTree::longestConsecutive(TreeNode* root, int& max_length)
{
    if (root == nullptr)
    {
        max_length = max(0, max_length);
        return 0;
    }
    else if ((root->left == nullptr) && (root->right == nullptr))
    {
        max_length = max(1, max_length);
        return 1;
    }
    int left_count = 0, right_count = 0;
    if (root->left != nullptr)
    {
        left_count = longestConsecutive(root->left, max_length);
        if (root->val + 1 == root->left->val)
        {
            left_count = left_count + 1;
            max_length = max(max_length, left_count);
        }
        else
        {
            left_count = 1;
        }
    }
    if (root->right != nullptr)
    {
        right_count = longestConsecutive(root->right, max_length);
        if (root->val + 1 == root->right->val)
        {
            right_count = right_count + 1;
            max_length = max(max_length, right_count);
        }
        else
        {
            right_count = 1;
        }
    }
    return max(left_count, right_count);
}

/// <summary>
/// Leet code #298. Binary Tree Longest Consecutive Sequence  
/// 
/// Given a binary tree, find the length of the longest consecutive sequence path. 
/// The path refers to any sequence of nodes from some starting node to any node in the tree 
/// along the parent-child connections. The longest consecutive path need to be from parent to 
/// child (cannot be the reverse).  
/// For example,
///    1
///     \
///      3
///     / \
///    2   4
///         \
///          5
///
/// Longest consecutive sequence path is 3-4-5, so return 3.    
///    2
///     \
///      3
///     / 
///    2    
///   / 
///  1
///
/// Longest consecutive sequence path is 2-3,not3-2-1, so return 2. 
/// </summary>
int LeetCodeTree::longestConsecutive(TreeNode* root)
{
    int max_length = 0;
    longestConsecutive(root, max_length);
    return max_length;
}

/// <summary>
/// Leet code #255. Verify Preorder Sequence in Binary Search Tree  
/// 
/// Given an array of numbers, verify whether it is the correct preorder traversal 
/// sequence of a binary search tree.
/// You may assume each number in the sequence is unique.
/// Follow up:
/// Could you do it using only constant space complexity?
/// </summary>
bool LeetCodeTree::verifyPreorder(vector<int>& preorder, int start, int end)
{
    if (start >= end) return true;
    int root_value = preorder[start];
    int index = start;
    for (index = start + 1; index < end; index++)
    {
        if (preorder[index] > root_value) break;
    }
    if (start + 1 < index)
    {
        if (!verifyPreorder(preorder, start + 1, index))
        {
            return false;
        }
    }
    start = index;
    for (index = start; index < end; index++)
    {
        if (preorder[index] < root_value) return false;
    }
    if (start < end)
    {
        if (!verifyPreorder(preorder, start, end))
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #255. Verify Preorder Sequence in Binary Search Tree  
/// 
/// Given an array of numbers, verify whether it is the correct preorder traversal 
/// sequence of a binary search tree.
/// You may assume each number in the sequence is unique.
/// Follow up:
/// Could you do it using only constant space complexity?
/// </summary>
bool LeetCodeTree::verifyPreorder(vector<int>& preorder)
{
    return verifyPreorder(preorder, 0, preorder.size());
}

/// <summary>
/// Leet code #314. Binary Tree Vertical Order Traversal  
/// 
/// Given a binary tree, return the vertical order traversal of its nodes' values. 
/// (ie, from top to bottom, column by column).
/// If two nodes are in the same row and column, the order should be from left to right.
/// Examples:
/// 1.Given binary tree [3,9,20,null,null,15,7],
///    3
///   / \
///  9  20
///    /  \
///   15   7
/// return its vertical order traversal as:
///
/// [
///   [9],
///   [3,15],
///   [20],
///   [7]
/// ]
///
/// 2.Given binary tree [3,9,8,4,0,1,7],
///     3
///    / \
///   9   8
///  / \ / \
/// 4  01   7
/// return its vertical order traversal as:
/// [
///  [4],
///  [9],
///  [3,0,1],
///  [8],
///  [7]
/// ]
///
/// 3.Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
///     3
///    / \
///   9   8
///  / \ / \
/// 4   01  7
///    / \
///   5   2
/// return its vertical order traversal as:
/// [
///  [4],
///  [9,5],
///  [3,0,1],
///  [8,2],
///  [7]
/// ]
/// </summary>
vector<vector<int>> LeetCodeTree::verticalOrder(TreeNode* root)
{
    vector<vector<int>> result;
    // since index can be negative, use map to remember it
    map<int, vector<int>> node_map;
    queue<pair<TreeNode*, int>> process_queue;
    process_queue.push(make_pair(root, 0));

    // BFS to traverse tree
    while (!process_queue.empty())
    {
        pair<TreeNode*, int> node_info = process_queue.front();
        process_queue.pop();
        TreeNode * node = node_info.first;
        int index = node_info.second;
        if (node == nullptr) continue;
        else node_map[index].push_back(node->val);
        process_queue.push(make_pair(node->left, index - 1));
        process_queue.push(make_pair(node->right, index + 1));
    }
    for (map<int, vector<int>>::iterator itr = node_map.begin(); itr != node_map.end(); ++itr)
    {
        result.push_back(itr->second);
    }
    return result;
}

/// <summary>
/// Leet code #333. Largest BST Subtree  
/// </summary>
bool LeetCodeTree::checkBSTSubtree(TreeNode* root, int& min_val, int& max_val, int& size)
{
    if (root == nullptr)
    {
        size = 0;
        return true;
    }
    bool isBST = true;
    // we need to initial new variable to avoid poplue carried in variable, if you use tuple 
    // or structure to return values, no such issue
    int left_min = root->val, left_max = root->val, left_size = 0;
    if (root->left != nullptr)
    {
        // check should go first to make sure subtree is searched
        bool ret = checkBSTSubtree(root->left, left_min, left_max, left_size);
        isBST = ret && isBST;
        isBST = isBST && (left_max < root->val);
    }
    int right_min = root->val, right_max = root->val, right_size = 0;
    if (root->right != nullptr)
    {
        // check should go first to make sure subtree is searched
        bool ret = checkBSTSubtree(root->right, right_min, right_max, right_size);
        isBST = ret && isBST;
        isBST = isBST && (right_min > root->val);
    }
    min_val = min(left_min, right_min); max_val = max(right_min, right_max);
    if (isBST)
    {
        size = 1 + left_size + right_size;
        return true;
    }
    else
    {
        size = max(left_size, right_size);
        return false;
    }
}

/// <summary>
/// Leet code #333. Largest BST Subtree  
/// 
/// Given a binary tree, find the largest subtree which is a Binary Search Tree 
/// (BST), where largest means subtree with largest number of nodes in it.
/// Note:
/// A subtree must include all of its descendants.
/// Here's an example:
///
///     10
///    /  \
///   5   15
///  / \    \ 
/// 1   8    7
/// The Largest BST Subtree in this case is the highlighted one. 
/// The return value is the subtree's size, which is 3. 
/// Hint:
/// 1. You can recursively use algorithm similar to 98. Validate Binary 
/// Search Tree at each node of the tree, 
/// which will result in O(nlogn) time complexity. 
/// Follow up:
/// Can you figure out ways to solve it with O(n) time complexity? 
/// </summary>
int LeetCodeTree::largestBSTSubtree(TreeNode* root)
{
    int min_val, max_val, size;
    checkBSTSubtree(root, min_val, max_val, size);
    return size;
}

/// <summary>
/// Leet code #285. Inorder Successor in BST 
/// 
/// Given a binary search tree and a node in it, find the in-order successor of that node in the BST. 
/// Note: If the given node has no in-order successor in the tree, return null. 
/// </summary>
TreeNode* LeetCodeTree::inorderSuccessor(TreeNode* root, TreeNode* p)
{
    stack<TreeNode*> process_stack;
    TreeNode *node = root;
    while (node != nullptr && node->val != p->val)
    {
        if (p->val < node->val)
        {
            process_stack.push(node);
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    if (node == nullptr) return nullptr;
    node = node->right;
    while (node != nullptr)
    {
        process_stack.push(node);
        node = node->left;
    }
    TreeNode* result = nullptr;
    if (!process_stack.empty())
    {
        result = process_stack.top();
    }
    return result;
}

/// <summary>
/// Leet code #501. Find Mode in Binary Search Tree         
/// </summary>
void LeetCodeTree::findMode(TreeNode* root, unordered_map<int, int>& node_map, map<int, unordered_set<int>> &frequency)
{
    if (root == nullptr) return;
    if (node_map.count(root->val) > 0)
    {
        frequency[node_map[root->val]].erase(root->val);
    }
    node_map[root->val]++;
    frequency[node_map[root->val]].insert(root->val);
    findMode(root->left, node_map, frequency);
    findMode(root->right, node_map, frequency);
}

/// <summary>
/// Leet code #501. Find Mode in Binary Search Tree         
/// 
/// Given a binary search tree (BST) with duplicates, find all the mode(s) 
/// (the most frequently occurred element) in the given BST.
///
/// Assume a BST is defined as follows:
/// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
/// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// For example:
/// Given BST [1,null,2,2],
///
///   1
///    \
///     2
///    /
///   2
/// return [2]. 
/// Note: If a tree has more than one mode, you can return them in any order. 
/// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space 
/// incurred due to recursion does not count). 
/// </summary>
vector<int> LeetCodeTree::findMode(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr) return result;

    unordered_map<int, int> node_map;
    map<int, unordered_set<int>> frequency;
    findMode(root, node_map, frequency);

    map<int, unordered_set<int>>::reverse_iterator itr = frequency.rbegin();
    for (auto value : itr->second)
    {
        result.push_back(value);
    }
    return result;
}

/// <summary>
/// Leet code #508. Most Frequent Subtree Sum          
/// </summary>
int LeetCodeTree::findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& sum_map, map<int, unordered_set<int>> &frequency)
{
    int sum = root->val;
    if (root->left != nullptr)
    {
        sum += findFrequentTreeSum(root->left, sum_map, frequency);
    }
    if (root->right != nullptr)
    {
        sum += findFrequentTreeSum(root->right, sum_map, frequency);
    }
    if (sum_map.count(sum) > 0)
    {
        frequency[sum_map[sum]].erase(sum);
    }
    sum_map[sum]++;
    frequency[sum_map[sum]].insert(sum);
    return sum;
}

/// <summary>
/// Leet code #508. Most Frequent Subtree Sum          
/// 
/// Given the root of a tree, you are asked to find the most frequent subtree sum. 
/// The subtree sum of a node is defined as the sum of all the node values formed 
/// by the subtree rooted at that node (including the node itself). So what is 
/// the most frequent subtree sum value? If there is a tie, return all the 
/// values with the highest frequency in any order. 
///
/// Examples 1
/// Input: 
///   5
///  /  \
/// 2   -3
/// return [2, -3, 4], since all the values happen only once, return all of them in any order. 
///
/// Examples 2
/// Input: 
///   5
///  /  \
/// 2   -5
/// return [2], since 2 happens twice, however -5 only occur once. 
/// Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer. 
/// </summary>
vector<int> LeetCodeTree::findFrequentTreeSum(TreeNode* root)
{
    vector<int> result;
    if (root == nullptr) return result;

    unordered_map<int, int> sum_map;
    map<int, unordered_set<int>> frequency;
    findFrequentTreeSum(root, sum_map, frequency);
    map<int, unordered_set<int>>::reverse_iterator itr = frequency.rbegin();
    for (auto value : itr->second)
    {
        result.push_back(value);
    }
    return result;
}

/// <summary>
/// Leet code #515. Find Largest Value in Each Tree Row         
/// 
/// You need to find the largest value in each row of a binary tree. 
/// Example:
///
/// Input: 
///
///          1
///         / \
///        3   2
///       / \   \  
///      5   3   9 
///
/// Output: [1, 3, 9]
/// </summary>
vector<int> LeetCodeTree::largestValues(TreeNode* root)
{
    vector<int> result;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        int max_value = INT_MIN;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            max_value = max(max_value, node->val);
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
        result.push_back(max_value);
    }
    return result;
}

/// <summary>
/// Leet code #513. Find Bottom Left Tree Value         
/// 
/// Given a binary tree, find the leftmost value in the last row of the tree. 
/// Example 1:
///
/// Input: 
///    2
///   / \
///  1   3
///
/// Output:
/// 1
///
/// Example 2: 
/// Input:
///
///        1
///       / \
///      2   3
///     /   / \
///    4   5   6
///       /
///      7
///
/// Output:
/// 7
/// Note: You may assume the tree (i.e., the given root node) is not NULL. 
/// </summary>
int LeetCodeTree::findBottomLeftValue(TreeNode* root)
{
    int result = 0;
    queue<TreeNode *> node_queue;
    if (root != nullptr)
    {
        node_queue.push(root);
    }
    while (!node_queue.empty())
    {
        size_t size = node_queue.size();
        bool first = true;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = node_queue.front();
            node_queue.pop();
            if (first == true)
            {
                first = false;
                result = node->val;
            }
            if (node->left != nullptr)
            {
                node_queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                node_queue.push(node->right);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #270. Closest Binary Search Tree Value    
/// 
/// Given a non-empty binary search tree and a target value, find the 
/// value in the BST that is closest to the target. 
/// Note:
/// Given target value is a floating point.
/// You are guaranteed to have only one unique value in the BST that is closest to the target.
/// </summary>
int LeetCodeTree::closestValue(TreeNode* root, double target)
{
    TreeNode * left = nullptr, *right = nullptr;
    TreeNode * node = root;
    while (node != nullptr)
    {
        if (target < node->val)
        {
            right = node;
            node = node->left;
        }
        else if (target > node->val)
        {
            left = node;
            node = node->right;
        }
        else
        {
            return node->val;
        }
    }

    int result = 0;
    if (left == nullptr && right == nullptr)
    {
        return result;
    }

    if (left == nullptr && right != nullptr)
    {
        result = right->val;
    }
    else if (right == nullptr && left != nullptr)
    {
        result = left->val;
    }
    else if (target - left->val < right->val - target)
    {
        result = left->val;
    }
    else
    {
        result = right->val;
    }
    return result;
}

/// <summary>
/// Leet code #272. Closest Binary Search Tree Value II   
/// </summary>
vector<int> LeetCodeTree::getPredecessor(stack<TreeNode*> left_stack, int k)
{
    vector<int> result;
    while (!left_stack.empty())
    {
        TreeNode * node = left_stack.top();
        left_stack.pop();
        result.push_back(node->val);

        if (result.size() == k) break;
        node = node->left;
        while (node != nullptr)
        {
            left_stack.push(node);
            node = node->right;
        }
    }
    return result;
}

/// <summary>
/// Leet code #272. Closest Binary Search Tree Value II   
/// </summary>
vector<int> LeetCodeTree::getSuccessor(stack<TreeNode*> right_stack, int k)
{
    vector<int> result;
    while (!right_stack.empty())
    {
        TreeNode * node = right_stack.top();
        right_stack.pop();
        result.push_back(node->val);

        if (result.size() == k) break;
        node = node->right;
        while (node != nullptr)
        {
            right_stack.push(node);
            node = node->left;
        }
    }
    return result;
}

/// <summary>
/// Leet code #272. Closest Binary Search Tree Value II   
/// 
/// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target. 
/// Note:
/// Given target value is a floating point.
/// You may assume k is always valid, that is: k ≤ total nodes.
/// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
/// Follow up:
/// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)? 
/// Hint:
/// 1.Consider implement these two helper functions: 
/// i.getPredecessor(N), which returns the next smaller node to N.
/// ii.getSuccessor(N), which returns the next larger node to N.
/// 2.Try to assume that each node has a parent pointer, it makes the problem much easier.
/// 3.Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
/// 4.You would need two stacks to track the path in finding predecessor and successor node separately.
/// </summary>
vector<int> LeetCodeTree::closestKValues(TreeNode* root, double target, int k)
{
    vector<int> result;
    stack<TreeNode*> left_stack;
    stack<TreeNode*> right_stack;
    TreeNode *node = root;
    while (node != nullptr)
    {
        if (target <= node->val)
        {
            right_stack.push(node);
            node = node->left;
        }
        else if (target > node->val)
        {
            left_stack.push(node);
            node = node->right;
        }
    }
    vector<int> left_values = getPredecessor(left_stack, k);
    vector<int> right_values = getSuccessor(right_stack, k);
    int left_index = 0, right_index = 0;
    while (left_index < (int)left_values.size() || right_index < (int)right_values.size())
    {
        if (result.size() == k) break;
        if (left_index == left_values.size())
        {
            result.push_back(right_values[right_index]);
            right_index++;
        }
        else if (right_index == right_values.size())
        {
            result.push_back(left_values[left_index]);
            left_index++;
        }
        else if (abs(left_values[left_index] - target) < abs(right_values[right_index] - target))
        {
            result.push_back(left_values[left_index]);
            left_index++;
        }
        else
        {
            result.push_back(right_values[right_index]);
            right_index++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #530. Minimum Absolute Difference in BST 
/// </summary>
int LeetCodeTree::getMinimumDifference(TreeNode* root, vector<int>& inorderList)
{
    int min_absolute = INT_MAX;
    if (root == nullptr) return min_absolute;
    vector<int> nodeList;
    if (root->left != nullptr)
    {
        min_absolute = min(min_absolute, getMinimumDifference(root->left, inorderList));
        min_absolute = min(min_absolute, root->val - inorderList.back());
    }
    inorderList.push_back(root->val);
    int size = inorderList.size();
    if (root->right != nullptr)
    {
        min_absolute = min(min_absolute, getMinimumDifference(root->right, inorderList));
        min_absolute = min(min_absolute, inorderList[size] - root->val);
    }
    return min_absolute;
}

/// <summary>
/// Leet code #530. Minimum Absolute Difference in BST 
///
/// Given a binary search tree with non-negative values, find the 
/// minimum absolute difference between values of any two nodes.
/// 
/// Example:
///
/// Input:
///
///   1
///    \
///     3
///    /
///   2
///
/// Output:
/// 1
///
/// Explanation:
/// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
/// Note: There are at least two nodes in this BST.
/// </summary>
int LeetCodeTree::getMinimumDifference(TreeNode* root)
{
    vector<int> inorderList;
    return getMinimumDifference(root, inorderList);
}

/// <summary>
/// Leet code #536. Construct Binary Tree from String
/// </summary>
TreeNode* LeetCodeTree::str2tree(string s, size_t& index)
{
    TreeNode * root = nullptr;
    string str;
    while (index < s.size() && ((s[index] == '-') || isdigit(s[index])))
    {
        str.push_back(s[index]);
        index++;
    }
    if (!str.empty())
    {
        root = new TreeNode(atoi(str.c_str()));
        str.clear();
    }
    if (root != nullptr)
    {
        if (index < s.size() && s[index] == '(')
        {
            index++;
            root->left = str2tree(s, index);
        }
        if (index < s.size() && s[index] == '(')
        {
            index++;
            root->right = str2tree(s, index);
        }
    }
    if (index < s.size() && s[index] == ')')
    {
        index++;
    }
    return root;
}

/// <summary>
/// Leet code #536. Construct Binary Tree from String
///
/// You need to construct a binary tree from a string consisting 
/// of parenthesis and integers.
/// The whole input represents a binary tree. It contains an 
/// integer followed by zero, one or two pairs of parenthesis. 
/// The integer represents the root's value and a pair of parenthesis 
/// contains a child binary tree with the same structure.
/// 
/// You always start to construct the left child node of the parent 
/// first if it exists.
///
/// Example:
/// Input: "4(2(3)(1))(6(5))"
/// Output: return the tree root node representing the following tree:
///       4
///     /   \
///    2     6
///   / \   / 
///  3   1 5   
/// Note:
/// There will only be '(', ')', '-' and '0' ~ '9' in the input string.
/// An empty tree is represented by "" instead of "()".
/// </summary>
TreeNode* LeetCodeTree::str2tree(string s)
{
    size_t index = 0;
    return str2tree(s, index);
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// </summary>
void LeetCodeTree::findLeftBoundary(TreeNode* root, vector<int> &leftBoundary)
{
    if (root == nullptr) return;
    leftBoundary.push_back(root->val);
    if (root->left != nullptr)
    {
        findLeftBoundary(root->left, leftBoundary);
    }
    else if (root->right != nullptr)
    {
        findLeftBoundary(root->right, leftBoundary);
    }
    return;
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// </summary>
void LeetCodeTree::findRightBoundary(TreeNode* root, vector<int> &rightBoundary)
{
    if (root == nullptr) return;
    rightBoundary.push_back(root->val);
    if (root->right != nullptr)
    {
        findRightBoundary(root->right, rightBoundary);
    }
    else if (root->left != nullptr)
    {
        findRightBoundary(root->left, rightBoundary);
    }
    return;
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// </summary>
void LeetCodeTree::findLeaves(TreeNode* root, vector<int> &leaves)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        leaves.push_back(root->val);
    }
    if (root->left != nullptr)
    {
        findLeaves(root->left, leaves);
    }
    if (root->right != nullptr)
    {
        findLeaves(root->right, leaves);
    }
    return;
}

/// <summary>
/// Leet code #545. Boundary of Binary Tree       
/// 
/// Given a binary tree, return the values of its boundary in 
/// anti-clockwise direction starting from root. Boundary includes left 
/// boundary, leaves, and right boundary in order without duplicate nodes.
/// Left boundary is defined as the path from root to the left-most node. 
/// Right boundary is defined as the path from root to the right-most 
/// node. If the root doesn't have left subtree or right subtree, then 
/// the root itself is left boundary or right boundary. 
/// Note this definition only applies to the input binary tree, 
/// and not applies to any subtrees.
/// The left-most node is defined as a leaf node you could reach when you 
/// always firstly travel to the left subtree if exists. If not, travel to 
/// the right subtree. Repeat until you reach a leaf node.
///
/// The right-most node is also defined by the same way with left and right exchanged.
/// 
/// Example 1
/// Input:
///  1
///   \
///    2 
///   / \
///  3   4
///
/// Ouput:
/// [1, 3, 4, 2]
///
/// Explanation:
/// The root doesn't have left subtree, so the root itself is left boundary.
/// The leaves are node 3 and 4.
/// The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
/// So order them in anti-clockwise without duplicates and we have [1,3,4,2].
/// Example 2
/// Input:
///     ____1_____
///    /          \
///   2            3
///  / \          / 
/// 4   5        6   
///    / \      / \
///   7   8    9  10  
/// Ouput:
/// [1,2,4,7,8,9,10,6,3]
///
/// Explanation:
/// The left boundary are node 1,2,4. (4 is the left-most node according to definition)
/// The leaves are node 4,7,8,9,10.
/// The right boundary are node 1,3,6,10. (10 is the right-most node).
/// So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
/// </summary>
vector<int> LeetCodeTree::boundaryOfBinaryTree(TreeNode* root)
{
    vector<int> leftBoundary;
    vector<int> rightBoundary;
    vector<int> leaves;
    vector<int> result;
    if (root == nullptr) return result;
    if (root->left != nullptr)
    {
        findLeftBoundary(root->left, leftBoundary);
    }
    if (root->right != nullptr)
    {
        findRightBoundary(root->right, rightBoundary);
    }
    findLeaves(root, leaves);
    if (root->left != nullptr || root->right != nullptr) result.push_back(root->val);
    for (int i = 0; i < (int)leftBoundary.size() - 1; i++)
    {
        result.push_back(leftBoundary[i]);
    }
    // skip left most and right most leaves
    for (int i = 0; i < (int)leaves.size(); i++)
    {
        result.push_back(leaves[i]);
    }
    for (int i = rightBoundary.size() - 2; i >= 0; i--)
    {
        result.push_back(rightBoundary[i]);
    }
    return result;
}

/// <summary>
/// Leet code #543. Diameter of Binary Tree       
/// </summary>
void LeetCodeTree::diameterOfBinaryTree(TreeNode* root, int &max_depth, int &diameter)
{
    max_depth = 0;
    diameter = 0;
    if (root != nullptr)
    {
        int left_max_depth = 0, left_diameter = 0;
        if (root->left != nullptr)
        {
            diameterOfBinaryTree(root->left, left_max_depth, left_diameter);
            left_max_depth++;

        }
        int right_max_depth = 0, right_diameter = 0;
        if (root->right != nullptr)
        {
            diameterOfBinaryTree(root->right, right_max_depth, right_diameter);
            right_max_depth++;
        }
        max_depth = max(left_max_depth, right_max_depth);
        diameter = max(left_diameter, right_diameter);
        diameter = max(diameter, left_max_depth + right_max_depth);
    }
}

/// <summary>
/// Leet code #543. Diameter of Binary Tree       
/// 
/// Given a binary tree, you need to compute the length of the diameter of 
/// the tree. The diameter of a binary tree is the length of the longest 
/// path between any two nodes in a tree. This path may or may not pass 
/// through the root.
/// Example:
/// Given a binary tree 
///      1
///     / \
///    2   3
///   / \     
///  4   5    
/// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
/// Note: The length of path between two nodes is represented by the 
/// number of edges between them.
/// </summary>
int LeetCodeTree::diameterOfBinaryTree(TreeNode* root)
{
    int max_depth, diameter;
    diameterOfBinaryTree(root, max_depth, diameter);
    return diameter;
}

/// <summary>
/// Leet code #538. Convert BST to Greater Tree       
/// </summary>
TreeNode* LeetCodeTree::convertBST(TreeNode* root, int &sum)
{
    if (root == nullptr) return root;
    TreeNode * new_root = new TreeNode(0);
    if (root->left == nullptr && root->right == nullptr)
    {
        new_root->val = root->val + sum;
        sum = new_root->val;
        return new_root;
    }
    if (root->right != nullptr)
    {
        new_root->right = convertBST(root->right, sum);
    }
    new_root->val = root->val + sum;
    sum = new_root->val;
    if (root->left != nullptr)
    {
        new_root->left = convertBST(root->left, sum);
    }
    return new_root;
}

/// <summary>
/// Leet code #538. Convert BST to Greater Tree       
/// 
/// Given a Binary Search Tree (BST), convert it to a Greater Tree such 
/// that every key of the original BST is changed to the original key plus
/// sum of all keys greater than the original key in BST.
/// 
/// Example:
/// Input: The root of a Binary Search Tree like this:
///          5
///        /   \
///       2     13
/// Output: The root of a Greater Tree like this:
///         18
///        /  \
///      20    13
/// </summary>
TreeNode* LeetCodeTree::convertBST(TreeNode* root)
{
    int sum = 0;
    return convertBST(root, sum);
}

/// <summary>
/// Leet code #549. Binary Tree Longest Consecutive Sequence II  
/// </summary>
int LeetCodeTree::longestConsecutiveII(TreeNode* root, int& asc_size, int& desc_size)
{
    if (root == nullptr)
    {
        asc_size = 0;
        desc_size = 0;
        return 0;
    }

    // parse left sub stree
    int left_asc_size, left_desc_size;
    int left_max_size = longestConsecutiveII(root->left, left_asc_size, left_desc_size);
    // if value is decreasing
    if (root->left == nullptr)
    {
        left_asc_size = 1;
        left_desc_size = 1;
    }
    else if (root->val == root->left->val - 1)
    {
        left_asc_size = 1;
        left_desc_size++;
    }
    // if value is increasing
    else if (root->val == root->left->val + 1)
    {
        left_desc_size = 1;
        left_asc_size++;
    }
    else
    {
        left_asc_size = 1;
        left_desc_size = 1;
    }

    // parse right sub stree
    int right_asc_size, right_desc_size;
    int right_max_size = longestConsecutiveII(root->right, right_asc_size, right_desc_size);
    if (root->right == nullptr)
    {
        right_asc_size = 1;
        right_desc_size = 1;
    }
    else if (root->val == root->right->val - 1)
    {
        right_asc_size = 1;
        right_desc_size++;
    }
    else if (root->val == root->right->val + 1)
    {
        right_desc_size = 1;
        right_asc_size++;
    }
    else
    {
        right_asc_size = 1;
        right_desc_size = 1;
    }
    asc_size = max(left_asc_size, right_asc_size);
    desc_size = max(left_desc_size, right_desc_size);
    int max_path_size = max(left_max_size, right_max_size);
    max_path_size = max(max_path_size, (left_asc_size + right_desc_size - 1));
    max_path_size = max(max_path_size, (right_asc_size + left_desc_size - 1));
    return max_path_size;
}

/// <summary>
/// Leet code #549. Binary Tree Longest Consecutive Sequence II  
/// 
/// Given a binary tree, you need to find the length of Longest 
/// Consecutive Path in Binary Tree. 
/// Especially, this path can be either increasing or decreasing. 
/// For example, [1,2,3,4] and [4,3,2,1] are both considered valid, 
/// but the path [1,2,4,3] is not valid. On the other hand, the path 
/// can be in the child-Parent-child order, where not necessarily be 
/// parent-child order.
/// Example 1:
/// Input:
///        1
///       / \
///      2   3
/// Output: 2
/// Explanation: The longest consecutive path is [1, 2] or [2, 1].
/// Example 2:
/// Input:
///        2
///       / \
///      1   3
/// Output: 3
/// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
/// </summary>
int LeetCodeTree::longestConsecutiveII(TreeNode* root)
{
    int asc_size, desc_size;
    return longestConsecutiveII(root, asc_size, desc_size);
}

/// <summary>
/// Leet code #563. Binary Tree Tilt      
/// </summary>
int LeetCodeTree::findTilt(TreeNode* root, int& sum)
{
    int tilt = 0;
    if (root == nullptr)
    {
        sum = 0;
        return 0;
    }

    int left_sum;
    tilt += findTilt(root->left, left_sum);

    int right_sum;
    tilt += findTilt(root->right, right_sum);

    sum = root->val + left_sum + right_sum;
    tilt += abs(left_sum - right_sum);
    return tilt;
}

/// <summary>
/// Leet code #563. Binary Tree Tilt      
/// 
/// Given a binary tree, return the tilt of the whole tree. 
/// The tilt of a tree node is defined as the absolute difference 
/// between the sum of all left subtree node values and the sum of 
/// all right subtree node values. Null node has tilt 0.
///
/// The tilt of the whole tree is defined as the sum of all nodes' tilt.
///
/// Example:
/// Input: 
///         1
///       /   \
///      2     3
/// Output: 1
/// Explanation: 
/// Tilt of node 2 : 0
/// Tilt of node 3 : 0
/// Tilt of node 1 : |2-3| = 1
/// Tilt of binary tree : 0 + 0 + 1 = 1
/// Note:
/// The sum of node values in any subtree won't exceed the range of 
/// 32-bit integer.
/// All the tilt values won't exceed the range of 32-bit integer.
/// </summary>
int LeetCodeTree::findTilt(TreeNode* root)
{
    int sum;
    return findTilt(root, sum);
}

/// <summary>
/// Leet code #572. Subtree of Another Tree       
/// </summary>
void LeetCodeTree::preOrderTraversal(TreeNode* root, string &result)
{
    result.push_back(',');
    if (root == nullptr)
    {
        result.append("null");
    }
    else
    {
        result.append(to_string(root->val));
        preOrderTraversal(root->left, result);
        preOrderTraversal(root->right, result);
    }
}

/// <summary>
/// Leet code #572. Subtree of Another Tree       
/// 
/// Given two non-empty binary trees s and t, check whether tree t has 
/// exactly the same structure and node values with a subtree of s. 
/// A subtree of s is a tree consists of a node in s and all of this 
/// node's descendants. The tree s could also be considered as a subtree 
/// of itself.
/// Example 1:
/// Given tree s:
///      3
///     / \
///    4   5
///   / \
///  1   2
/// Given tree t:
///    4 
///   / \
///  1   2
/// Return true, because t has the same structure and node values with a subtree of s.
/// Example 2:
/// Given tree s:
///     3
///    / \
///   4   5
///  / \
/// 1   2
///    /
///   0
/// Given tree t:
///   4
///  / \
/// 1   2
/// Return false.
/// </summary>
bool LeetCodeTree::isSubtree(TreeNode* s, TreeNode* t)
{
    string str_s, str_t;
    preOrderTraversal(s, str_s);
    preOrderTraversal(t, str_t);
    if (strstr(str_s.c_str(), str_t.c_str()) == nullptr) return false;

    return true;
}

/// <summary>
/// Leet code #606. Construct String from Binary Tree
/// 
/// You need to construct a string consists of parenthesis and integers 
/// from a binary tree with the preorder traversing way.
/// The null node needs to be represented by empty parenthesis pair "()". 
/// And you need to omit all the empty parenthesis pairs that don't affect 
/// the one-to-one mapping relationship between the string and the original 
/// binary tree.
///
/// Example 1:
/// Input: Binary tree: [1,2,3,4]
///       1
///     /   \
///    2     3
///   /    
///  4     
/// Output: "1(2(4))(3)"
/// Explanation: Originallay it needs to be "1(2(4)())(3()())", 
/// but you need to omit all the unnecessary empty parenthesis pairs. 
/// And it will be "1(2(4))(3)".
///
/// Example 2:
/// Input: Binary tree: [1,2,3,null,4]
///       1
///     /   \
///    2     3
///     \  
///      4 
/// Output: "1(2()(4))(3)"
/// Explanation: Almost the same as the first example, except we can't 
/// omit the first parenthesis pair to break the one-to-one mapping 
/// relationship between the input and the output.
/// </summary>
string LeetCodeTree::tree2str(TreeNode* t)
{
    string result;
    if (t == nullptr)
    {
        return result;
    }
    result = to_string(t->val);
    if (t->left != nullptr)
    {
        result += "(" + tree2str(t->left) + ")";
    }
    else if (t->right != nullptr)
    {
        result += "()";
    }

    if (t->right != nullptr)
    {
        result += "(" + tree2str(t->right) + ")";
    }
    return result;
}

/// <summary>
/// Leet code 617. Merge Two Binary Trees
/// 
/// Given two binary trees and imagine that when you put one of them to 
/// cover the other, some nodes of the two trees are overlapped while the 
/// others are not. 
/// You need to merge them into a new binary tree. The merge rule is that 
/// if two nodes overlap, then sum node values up as the new value of the 
/// merged node. Otherwise, the NOT null node will be used as the node of 
/// new tree. 
/// Example 1:
/// Input: 
///	Tree 1                    Tree 2                  
///          1                         2                             
///         / \                       / \                            
///        3   2                     1   3                        
///       /                           \   \                      
///      5                             4   7                  
/// Output: 
/// Merged tree:
///      3
///     / \
///    4   5
///   / \   \ 
///  5   4   7
///
/// Note: The merging process must start from the root nodes of both trees.
/// </summary>
TreeNode* LeetCodeTree::mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if ((t1 == nullptr) && (t2 == nullptr))
    {
        return nullptr;
    }

    int value = 0;
    TreeNode *left_t1 = nullptr, *left_t2 = nullptr;
    TreeNode *right_t1 = nullptr, *right_t2 = nullptr;

    if (t1 != nullptr)
    {
        value += t1->val;
        left_t1 = t1->left;
        right_t1 = t1->right;
    }
    if (t2 != nullptr)
    {
        value += t2->val;
        left_t2 = t2->left;
        right_t2 = t2->right;
    }

    TreeNode * node = new TreeNode(value);
    node->left = mergeTrees(left_t1, left_t2);
    node->right = mergeTrees(right_t1, right_t2);

    return node;
}

/// <summary>
/// Leet code #623. Add One Row to Tree 
/// </summary>
TreeNode* LeetCodeTree::addOneRow(TreeNode* node, int v, int depth, int target_depth)
{
    if (target_depth == depth)
    {
        TreeNode * root = new TreeNode(v);
        root->left = node;
        return root;
    }
    else if (node == nullptr)
    {
        return node;
    }
    else if (depth == target_depth - 1)
    {
        TreeNode * left_node = new TreeNode(v);
        left_node->left = node->left;
        node->left = left_node;

        TreeNode * right_node = new TreeNode(v);
        right_node->right = node->right;
        node->right = right_node;
        return node;
    }
    else
    {
        addOneRow(node->left, v, depth + 1, target_depth);
        addOneRow(node->right, v, depth + 1, target_depth);
        return node;
    }
}

/// <summary>
/// Leet code #623. Add One Row to Tree 
/// 
/// Given the root of a binary tree, then value v and depth d, you need to 
/// add a row of nodes with value v at the given depth d. The root node is 
/// at depth 1. 
///
/// The adding rule is: given a positive integer depth d, for each NOT null 
/// tree nodes N in depth d-1, create two tree nodes with value v as N's 
/// left subtree root and right subtree root. And N's original left subtree 
/// should be the left subtree of the new left subtree root, its original 
/// right subtree should be the right subtree of the new right subtree 
/// root. If depth d is 1 that means there is no depth d-1 at all, then 
/// create a tree node with value v as the new root of the whole original 
/// tree, and the original tree is the new root's left subtree.
///
/// Example 1:
/// Input: 
/// A binary tree as following:
///       4
///     /   \
///    2     6
///   / \   / 
///  3   1 5   
///
/// v = 1
/// d = 2
///
/// Output: 
///       4
///      / \
///     1   1
///    /     \
///   2       6
///  / \     / 
/// 3   1   5   
///
/// Example 2:
/// Input: 
/// A binary tree as following:
///      4
///     /   
///    2    
///   / \   
///  3   1    
///
/// v = 1
/// d = 3
///
/// Output: 
///       4
///      /   
///     2
///    / \    
///   1   1
///  /     \  
/// 3       1
///
///
///
/// Note:
///
/// 1.The given d is in range [1, maximum depth of the given tree + 1].
/// 2.The given binary tree has at least one tree node.
/// </summary>
TreeNode* LeetCodeTree::addOneRow(TreeNode* root, int v, int d)
{
    return addOneRow(root, v, 1, d);
}

/// <summary>
/// Leet code #637. Average of Levels in Binary Tree 
/// 
/// Given a non-empty binary tree, return the average value of the nodes on 
/// each level in the form of an array. 
/// Example 1:
/// Input:
///     3
///    / \
///   9  20
///     /  \
///    15   7
/// Output: [3, 14.5, 11]
/// Explanation:
/// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on 
/// level 2 is 11. Hence return [3, 14.5, 11].
/// 
/// Note:
/// The range of node's value is in the range of 32-bit signed integer.
/// </summary>
vector<double> LeetCodeTree::averageOfLevels(TreeNode* root)
{
    vector<double> result;
    queue<TreeNode *> process_queue;
    if (root != nullptr) process_queue.push(root);

    while (!process_queue.empty())
    {
        double sum = 0;
        size_t size = process_queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = process_queue.front();
            process_queue.pop();
            sum += node->val;
            if (node->left != nullptr) process_queue.push(node->left);
            if (node->right != nullptr) process_queue.push(node->right);
        }
        result.push_back(sum / size);
    }

    return result;
}

/// <summary>
/// Leet code #652. Find Duplicate Subtrees
/// </summary>
string LeetCodeTree::findDuplicateSubtrees(TreeNode* root, unordered_map<string, vector<TreeNode*>> &cache)
{
    // The starting , is to avoid partial match, for example [8, null, null] mapping to [18, null, null]
    string traverse = ",";
    if (root == nullptr)
    {
        traverse.append("null");
        return traverse;
    }
    traverse.append(to_string(root->val));
    string sub_tree = findDuplicateSubtrees(root->left, cache);
    traverse.append(sub_tree);
    sub_tree = findDuplicateSubtrees(root->right, cache);
    traverse.append(sub_tree);
    cache[traverse].push_back(root);
    return traverse;
}

/// <summary>
/// Leet code #652. Find Duplicate Subtrees
/// 
/// Given a binary tree, return all duplicate subtrees. For each kind of 
/// duplicate subtrees, you only need to return the root node of any one 
/// of them.
///
/// Two trees are duplicate if they have the same structure with same node 
/// values.
///
/// Example 1: 
///        1
///       / \
///      2   3
///     /   / \
///    4   2   4
///       /
///      4
/// The following are two duplicate subtrees:
///      2
///     /
///    4
/// and
///    4
/// Therefore, you need to return above trees' root in the form of a list.
/// </summary>
vector<TreeNode*> LeetCodeTree::findDuplicateSubtrees(TreeNode* root)
{
    vector<TreeNode*> result;
    unordered_map<string, vector<TreeNode*>> cache;
    string subTree = findDuplicateSubtrees(root, cache);
    for (auto subtree : cache)
    {
        if (subtree.second.size() > 1)
        {
            result.push_back(subtree.second[0]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #653. Two Sum IV - Input is a BST
/// </summary>
bool LeetCodeTree::findTarget(TreeNode* root, unordered_set<int> &hash_table, int k)
{
    if (root == nullptr) return false;
    if (hash_table.count(k - root->val) > 0) return true;
    hash_table.insert(root->val);
    if (findTarget(root->left, hash_table, k)) return true;
    return  (findTarget(root->right, hash_table, k));
}

/// <summary>
/// Leet code #653. Two Sum IV - Input is a BST
/// 
/// Given a Binary Search Tree and a target number, return true if there 
/// exist two elements in the BST such that their sum is equal to the given 
/// target.
///
/// Example 1:
/// Input: 
///     5
///    / \
///   3   6
///  / \   \
/// 2   4   7
/// 
///
/// Target = 9
///
/// Output: True
///
/// Example 2:
/// Input: 
///     5
///    / \
///   3   6
///  / \   \
/// 2   4   7
///
/// Target = 28
///
/// Output: False
/// </summary>
bool LeetCodeTree::findTarget(TreeNode* root, int k)
{
    unordered_set<int> hash_table;
    return findTarget(root, hash_table, k);
}

/// <summary>
/// Leet code #654. Maximum Binary Tree
/// </summary>
void LeetCodeTree::constructMaximumBinaryTree(TreeNode* &root, int val)
{
    if (root == nullptr || root->val < val)
    {
        TreeNode* left = root;
        root = new TreeNode(val);
        root->left = left;
    }
    else if (root->val > val)
    {
        constructMaximumBinaryTree(root->right, val);
    }
}


/// <summary>
/// Leet code #654. Maximum Binary Tree
/// 
/// Given an integer array with no duplicates. A maximum tree building on 
/// this array is defined as follow:
///
/// The root is the maximum number in the array.
/// The left subtree is the maximum tree constructed from left part 
/// subarray divided by the maximum number.
/// The right subtree is the maximum tree constructed from right part 
/// subarray divided by the maximum number.
/// Construct the maximum tree by the given array and output the root node 
/// of this tree.
///
/// Example 1:
/// Input: [3,2,1,6,0,5]
/// Output: return the tree root node representing the following tree:
///
///      6
///    /   \
///   3     5
///    \    /  
///     2  0   
///      \
///       1
/// Note:
/// 1. The size of the given array will be in the range [1,1000].
/// </summary>
TreeNode* LeetCodeTree::constructMaximumBinaryTree(vector<int>& nums)
{
    TreeNode * root = nullptr;
    for (int val : nums)
    {
        constructMaximumBinaryTree(root, val);
    }
    return root;
}

/// <summary>
/// Leet code #655. Print Binary Tree
/// </summary>
void LeetCodeTree::printTree(TreeNode* root, vector<vector<string>> &matrix, 
    int row, int col, int window)
{
    if (root == nullptr) return;
    matrix[row][col] = to_string(root->val);
    window = (window - 1) / 2;
    if (window >= 0)
    {
        printTree(root->left, matrix, row + 1, col - window - 1, window);
        printTree(root->right, matrix, row + 1, col + window + 1, window);
    }
}

/// <summary>
/// Leet code #655. Print Binary Tree
/// 
/// Print a binary tree in an m*n 2D string array following these rules: 
/// The row number m should be equal to the height of the given binary 
/// tree.
/// The column number n should always be an odd number.
/// The root node's value (in string format) should be put in the exactly 
/// middle of the first row it can be put. The column and the row where 
/// the root node belongs will separate the rest space into two parts 
/// (left-bottom part and right-bottom part). You should print the left 
/// subtree in the left-bottom part and print the right subtree in the 
/// right-bottom part. The left-bottom part and the right-bottom part 
/// should have the same size. Even if one subtree is none while the other 
/// is not, you don't need to print anything for the none subtree but 
/// still need to leave the space as large as that for the other subtree. 
/// However, if two subtrees are none, then you don't need to leave space 
/// for both of them.
/// Each unused space should contain an empty string "". 
/// Print the subtrees following the same rules.
/// Example 1:
/// Input:
///     1
///    /
///   2
/// Output:
/// [["", "1", ""],
/// ["2", "", ""]]
///
/// Example 2:
/// Input:
///     1
///    / \
///   2   3
///    \
///     4
/// Output:
/// [["", "", "", "1", "", "", ""],
/// ["", "2", "", "", "", "3", ""],
/// ["", "", "4", "", "", "", ""]]
///
/// Example 3:
/// Input:
///       1
///      / \
///     2   5
///    / 
///   3 
///  / 
/// 4 
/// Output:
///
/// [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
/// ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
/// ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
/// ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
/// 1. Note: The height of binary tree is in the range of [1, 10].
/// </summary>
vector<vector<string>> LeetCodeTree::printTree(TreeNode* root)
{
    int rows = maxDepth(root);
    int columns = (int)pow(2, rows) - 1;
    vector<vector<string>> result(rows, vector<string>(columns, ""));

    printTree(root, result, 0, 0 + columns / 2, columns / 2);
    return result;
}

/// <summary>
/// Leet code #663. Equal Tree Partition 
/// </summary>
int LeetCodeTree::checkEqualTree(TreeNode* root, unordered_map<int, int> &sub_sum)
{
    if (root == nullptr) return 0;
    int sum = 0;
    sum += checkEqualTree(root->left, sub_sum);
    sum += checkEqualTree(root->right, sub_sum);
    sum += root->val;
    sub_sum[sum]++;
    return sum;
}

/// <summary>
/// Leet code #663. Equal Tree Partition 
/// 
/// Given a binary tree with n nodes, your task is to check if it's 
/// possible to partition the tree to two trees which have the equal sum 
/// of values after removing exactly one edge on the original tree. 
/// Example 1:
/// Input:     
///    5
///   / \
///  10 10
///    /  \
///   2    3
///
/// Output: True    
/// Explanation: 
///    5
///   / 
///  10
///      
/// Sum: 15
///
///   10
///  /  \
/// 2    3
///
/// Sum: 15
///
/// Example 2:
/// Input:     
///    1
///   / \
///  2  10
///    /  \
///   2   20
///
/// Output: False
/// Explanation: You can't split the tree into two trees with equal sum 
/// after removing exactly one edge on the tree.
///
/// Note:
/// 1. The range of tree node value is in the range of [-100000, 100000].
/// 2. 1 <= n <= 10000
/// </summary>
bool LeetCodeTree::checkEqualTree(TreeNode* root)
{
    unordered_map<int, int> sub_sum;
    int sum = checkEqualTree(root, sub_sum);
    if (sum % 2 != 0) return false;
    if (sum == 0 && sub_sum[sum] == 1) return false;
    if (sub_sum.count(sum / 2) == 0) return false;
    return true;
}

/// <summary>
/// Leet code #662. Maximum Width of Binary Tree 
/// 
/// Given a binary tree, write a function to get the maximum width of the 
/// given tree. The width of a tree is the maximum width among all levels. 
/// The binary tree has the same structure as a full binary tree, but some 
/// nodes are null. 
/// The width of one level is defined as the length between the end-nodes 
/// (the leftmost and right most non-null nodes in the level, where the 
/// null nodes between the end-nodes are also counted into the length 
/// calculation.
/// Example 1:
/// Input: 
///
///           1
///         /   \
///        3     2
///       / \     \  
///      5   3     9 
///
/// Output: 4
/// Explanation: The maximum width existing in the third level with the 
/// length 4 (5,3,null,9).
/// Example 2:
/// Input: 
///
///          1
///         /  
///        3    
///       / \       
///      5   3     
///
/// Output: 2
/// Explanation: The maximum width existing in the third level with the 
/// length 2 (5,3).
/// Example 3:
/// Input: 
///
///          1
///         / \
///        3   2 
///       /        
///      5      
///
/// Output: 2
/// Explanation: The maximum width existing in the second level with the 
/// length 2 (3,2).
/// Example 4:
/// Input: 
///
///          1
///         / \
///        3   2
///       /     \  
///      5       9 
///     /         \
///    6           7
/// Output: 8
/// Explanation:The maximum width existing in the fourth level with the 
/// length 8 (6,null,null,null,null,null,null,7).
///
/// Note: Answer will in the range of 32-bit signed integer. 
/// </summary>
int LeetCodeTree::widthOfBinaryTree(TreeNode* root)
{
    if (root == nullptr) return 0;
    queue<pair<TreeNode *, int>> process_queue;
    int width = 0;
    process_queue.push(make_pair(root, 0));
    while (!process_queue.empty())
    {
        size_t size = process_queue.size();
        int left = INT_MAX, right = INT_MIN;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode * node = process_queue.front().first;
            int pos = process_queue.front().second;
            process_queue.pop();
            left = min(left, pos);
            right = max(right, pos);
            if (node->left != nullptr)
            {
                process_queue.push(make_pair(node->left, 2 * pos));
            }
            if (node->right != nullptr)
            {
                process_queue.push(make_pair(node->right, 2 * pos + 1));
            }
        }
        width = max(width, right - left + 1);
    }
    return width;
}

/// <summary>
/// Leet code #666. Path Sum IV 
/// </summary>
bool LeetCodeTree::pathSumIV(int level, int position, unordered_map<int, unordered_map<int, int>>& node_map, int &subtotal, int &sum)
{
    if (node_map.count(level) == 0 || node_map[level].count(position) == 0) return false;
    // add the current node;
    subtotal += node_map[level][position];
    // check if this is leaf
    bool left_child = pathSumIV(level + 1, 2 * position, node_map, subtotal, sum);
    bool right_child = pathSumIV(level + 1, 2 * position + 1, node_map, subtotal, sum);
    if (left_child == false && right_child == false)
    {
        sum += subtotal;
    }

    // rollback the current node
    subtotal -= node_map[level][position];
    return true;
}

/// <summary>
/// Leet code #666. Path Sum IV 
/// 
/// If the depth of a tree is smaller than 5, then this tree can be 
/// represented by a list of three-digits integers. 
/// For each integer in this list:
/// The hundreds digit represents the depth D of this node, 1 <= D <= 4.
/// The tens digit represents the position P of this node in the level it 
/// belongs to, 1 <= P <= 8. The position is the same as that in a full 
/// binary tree. 
/// The units digit represents the value V of this node, 0 <= V <= 9.
///
/// Given a list of ascending three-digits integers representing a binary 
/// with the depth smaller than 5. You need to return the sum of all paths 
/// from the root towards the leaves. 
/// Example 1:
/// Input: [113, 215, 221]
/// Output: 12
/// Explanation: 
/// The tree that the list represents is:
///    3
///   / \
///  5   1
///
/// The path sum is (3 + 5) + (3 + 1) = 12.
///
/// Example 2:
/// Input: [113, 221]
/// Output: 4
/// Explanation: 
/// The tree that the list represents is: 
///    3
///     \
///      1
///
/// The path sum is (3 + 1) = 4.
/// </summary>
int LeetCodeTree::pathSumIV(vector<int>& nums)
{
    unordered_map<int, unordered_map<int, int>> node_map;
    for (size_t i = 0; i < nums.size(); i++)
    {
        node_map[nums[i] / 100 - 1][(nums[i] % 100) / 10 - 1] = nums[i] % 10;
    }
    int subtotal = 0, sum = 0;
    pathSumIV(0, 0, node_map, subtotal, sum);
    return sum;
}

/// <summary>
/// Leet code #669. Trim a Binary Search Tree 
/// 
/// Given a binary search tree and the lowest and highest boundaries as L 
/// and R, trim the tree so that all its elements lies in [L, R] (R >= L). 
/// You might need to change the root of the tree, so the result should 
/// return the new root of the trimmed binary search tree.
///
/// Example 1:
/// Input: 
///    1
///   / \
///  0   2
///
///  L = 1
///  R = 2
///
/// Output: 
///    1
///      \
///       2
///
/// Example 2:
/// Input: 
///    3
///   / \
///  0   4
///   \
///    2
///   /
///  1
///
///  L = 1
///  R = 3
///
/// Output: 
///      3
///     / 
///   2   
///  /
/// 1
/// </summary>
TreeNode* LeetCodeTree::trimBST(TreeNode* root, int L, int R)
{
    TreeNode *result = nullptr;
    if (root == nullptr) return result;

    if (root->val < L)
    {
        result = trimBST(root->right, L, R);
    }
    else if (root->val > R)
    {
        result = trimBST(root->left, L, R);
    }
    else
    {
        result = new TreeNode(root->val);
        result->left = trimBST(root->left, L, R);
        result->right = trimBST(root->right, L, R);
    }
    return result;
}

/// <summary>
/// Leet code #671. Second Minimum Node In a Binary Tree 
/// </summary>
void LeetCodeTree::findSecondMinimumValue(TreeNode* root, set<int, greater<int>>&heap)
{
    if (root == nullptr) return;
    heap.insert(root->val);
    if (heap.size() > 2)
    {
        heap.erase(heap.begin());
    }
    findSecondMinimumValue(root->left, heap);
    findSecondMinimumValue(root->right, heap);
    return;
}

/// <summary>
/// Leet code #671. Second Minimum Node In a Binary Tree 
/// 
/// Given a non-empty special binary tree consisting of nodes with the 
/// non-negative value, where each node in this tree has exactly two or 
/// zero sub-node. If the node has two sub-nodes, then this node's value 
/// is the smaller value among its two sub-nodes.
/// 
/// Given such a binary tree, you need to output the second minimum value 
/// in the set made of all the nodes' value in the whole tree.
///
/// If no such second minimum value exists, output -1 instead.
///
/// Example 1:
/// Input: 
///    2
///   / \
///  2   5
///     / \
///    5   7
///
/// Output: 5
/// Explanation: The smallest value is 2, the second smallest value is 5.
/// Example 2:
/// Input: 
///    2
///   / \
///  2   2
///
/// Output: -1
/// Explanation: The smallest value is 2, but there isn't any second 
/// smallest value.
/// </summary>
int LeetCodeTree::findSecondMinimumValue(TreeNode* root)
{
    set<int, greater<int>> heap;
    findSecondMinimumValue(root, heap);
    if (heap.size() == 2) return (*heap.begin());
    else return -1;
}


/// <summary>
/// Leet code #687. Longest Univalue Path
/// </summary>
int LeetCodeTree::longestUnivaluePath(TreeNode* root, int &path_length)
{
    int result = 0;
    if (root == nullptr)
    {
        return 0;
    }
    path_length = 0;
    int max_left_path_size = 0;
    int left_path_size = 0;
    if (root->left != nullptr)
    {
        max_left_path_size = longestUnivaluePath(root->left, left_path_size);
    }
    int max_right_path_size = 0;
    int right_path_size = 0;
    if (root->right != nullptr)
    {
        max_right_path_size = longestUnivaluePath(root->right, right_path_size);
    }
    result = 0;
    if (root->left != nullptr && root->val == root->left->val)
    {
        path_length = max(path_length, 1 + left_path_size);
        result += 1 + left_path_size;
    }
    if (root->right != nullptr && root->val == root->right->val)
    {
        path_length = max(path_length, 1 + right_path_size);
        result += 1 + right_path_size;
    }
    result = max(max_left_path_size, result);
    result = max(max_right_path_size, result);
    return result;
}

/// <summary>
/// Leet code #687. Longest Univalue Path
/// 
/// Given a binary tree, find the length of the longest path where each 
/// node in the path has the same value. This path may or may not pass 
/// through the root.
///
/// Note: The length of path between two nodes is represented by 
/// the number of edges between them.
///
/// Example 1:
///
/// Input:
///
///              5
///             / \
///            4   5
///           / \   \
///          1   1   5
/// Output: 2
///
/// Example 2:
///
/// Input:
///
///              1
///             / \
///            4   5
///           / \   \
///          4   4   5
/// Output: 2
/// Note: The given binary tree has not more than 10000 nodes. The height 
/// of the tree is not more than 1000.
/// </summary>
int LeetCodeTree::longestUnivaluePath(TreeNode* root)
{
    int path_length;
    return longestUnivaluePath(root, path_length);
}

/// <summary>
/// Leet code #742. Closest Leaf in a Binary Tree
/// </summary>
void LeetCodeTree::findClosestLeaf(TreeNode* root, int target, int &target_distance, int &leaf_distance, int &value)
{
    if (root == nullptr) return;
    if (root->val == target) target_distance = 0;
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        leaf_distance = 0;
        value = root->val;
    }
    else
    {
        int left_target_distance = -1;
        int left_leaf_distance = -1;
        int right_target_distance = -1;
        int right_leaf_distance = -1;
        int left_value = -1;
        int right_value = -1;
        findClosestLeaf(root->left, target, left_target_distance, left_leaf_distance, left_value);
        findClosestLeaf(root->right, target, right_target_distance, right_leaf_distance, right_value);
        if (left_target_distance != -1)
        {
            leaf_distance = left_leaf_distance;
            value = left_value;
            if ((root->right != nullptr) && (left_leaf_distance > left_target_distance + 1 + right_leaf_distance + 1))
            {
                leaf_distance = (left_target_distance + 1 + right_leaf_distance + 1);
                value = right_value;
            }
            target_distance = left_target_distance + 1;
        }
        else if (right_target_distance != -1)
        {
            leaf_distance = right_leaf_distance;
            value = right_value;
            if ((root->left != nullptr) && (right_leaf_distance > right_target_distance + 1 + left_leaf_distance + 1))
            {
                leaf_distance = (right_target_distance + 1 + left_leaf_distance + 1);
                value = left_value;
            }
            target_distance = right_target_distance + 1;
        }
        else
        {
            if (root->left != nullptr)
            {
                leaf_distance = left_leaf_distance;
                value = left_value;
            }
            else
            {
                leaf_distance = right_leaf_distance;
                value = right_value;
            }
            if ((root->right != nullptr) && (left_leaf_distance > right_leaf_distance))
            {
                leaf_distance = right_leaf_distance;
                value = right_value;
            }
            leaf_distance += 1;
        }
    }
}

/// <summary>
/// Leet code #742. Closest Leaf in a Binary Tree
///
/// Given a binary tree where every node has a unique value, and a target 
/// key k, find the value of the closest leaf node to target k in the tree.
///
/// Here, closest to a leaf means the least number of edges travelled on 
/// the binary tree to reach any leaf of the tree. Also, a node is called 
/// a leaf if it has no children.
///
/// In the following examples, the input tree is represented in flattened 
/// form row by row. The actual root tree given will be a TreeNode object.
///
/// Example 1:
///
/// Input:
/// root = [1, 3, 2], k = 1
/// Diagram of binary tree:
///      1
///     / \
///    3   2
///
/// Output: 2 (or 3)
///
/// Explanation: Either 2 or 3 is the closest leaf node to the target of 1.
/// Example 2:
/// 
/// Input:
/// root = [1], k = 1
/// Output: 1
///
/// Explanation: The closest leaf node is the root node itself.
/// Example 3:
///
/// Input:
/// root = [1,2,3,4,null,null,null,5,null,6], k = 2
/// Diagram of binary tree:
///         1
///        / \
///       2   3
///      /
///     4
///    /
///   5
///  /
/// 6
///
/// Output: 3
/// Explanation: The leaf node with value 3 (and not the leaf node with 
/// value 6) is closest to the node with value 2.
/// Note:
/// root represents a binary tree with at least 1 node and at most 1000 
/// nodes.
/// Every node has a unique node.val in range [1, 1000].
/// There exists some node in the given binary tree for which 
/// node.val == k. 
/// </summary>
int LeetCodeTree::findClosestLeaf(TreeNode* root, int k)
{
    int target_distance = -1, leaf_distance = -1, value = -1;
    findClosestLeaf(root, k, target_distance, leaf_distance, value);
    return value;
}

/// <summary>
/// Leetcode #776. Split BST
///
/// Given a Binary Search Tree (BST) with root node root, and a target 
/// value V, split the tree into two subtrees where one subtree has 
/// nodes that are all smaller or equal to the target value, while the 
/// other subtree has all nodes that are greater than the target value.  
/// It's not necessarily the case that the tree contains a node with 
/// value V.
///
/// Additionally, most of the structure of the original tree should 
/// remain.  Formally, for any child C with parent P in the original 
/// tree, if they are both in the same subtree after the split, then 
/// node C should still have the parent P.
///
/// You should output the root TreeNode of both subtrees after splitting, 
/// in any order.
///
/// Example 1:
///
/// Input: root = [4,2,6,1,3,5,7], V = 2
/// Output: [[2,1],[4,3,6,null,null,5,7]]
/// Explanation:
/// Note that root, output[0], and output[1] are TreeNode objects, not 
/// arrays.
/// 
/// The given tree [4,2,6,1,3,5,7] is represented by the following diagram:
///
///      4
///    /    \
///   2      6
///  / \    / \
/// 1   3  5   7
///
/// while the diagrams for the outputs are:
///
///       4
///      /  \
///     3    6      and    2
///         / \           /
///        5   7         1
/// Note:
/// 1. The size of the BST will not exceed 50.
/// 2. The BST is always valid and each node's value is different.
/// </summary>
vector<TreeNode*> LeetCodeTree::splitBST(TreeNode* root, int V)
{
    vector<TreeNode *> result;
    if (root == nullptr)
    {
        result.push_back(nullptr);
        result.push_back(nullptr);
    }
    else if (root->val <= V)
    {
        vector<TreeNode *> children = splitBST(root->right, V);
        root->right = children[0];
        result.push_back(root);
        result.push_back(children[1]);
    }
    else
    {
        vector<TreeNode *> children = splitBST(root->left, V);
        root->left = children[1];
        result.push_back(children[0]);
        result.push_back(root);
    }
    return result;
}

/// <summary>
/// Leetcode #783. Minimum Distance Between BST Nodes
/// </summary>
void LeetCodeTree::minDiffInBST(TreeNode* node, TreeNode* &prev_node, int &min_diff)
{
    if (node == nullptr) return;
    minDiffInBST(node->left, prev_node, min_diff);
    if (prev_node != nullptr)
    {
        if (min_diff >= 0) min_diff = min(node->val - prev_node->val, min_diff);
        else min_diff = node->val - prev_node->val;
    }
    prev_node = node;
    minDiffInBST(node->right, prev_node, min_diff);
}

/// <summary>
/// Leetcode #783. Minimum Distance Between BST Nodes
///
/// Given a Binary Search Tree (BST) with the root node root, return the 
/// minimum difference between the values of any two different nodes in 
/// the tree.
/// 
/// Example :
///
/// Input: root = [4,2,6,1,3,null,null]
/// Output: 1
/// Explanation:
/// Note that root is a TreeNode object, not an array.
///
/// The given tree [4,2,6,1,3,null,null] is represented by the following 
/// diagram:
///         4
///        /  \
///       2    6
///      / \    
///     1   3  
/// while the minimum difference in this tree is 1, it occurs between 
/// node 1 and node 2, also between node 3 and node 2.
/// Note:
///
/// 1. The size of the BST will be between 2 and 100.
/// 2. The BST is always valid, each node's value is an integer, and each 
///    node's value is different.
/// </summary>
int LeetCodeTree::minDiffInBST(TreeNode* root)
{
    TreeNode * prev_node = nullptr;
    int min_diff = -1;
    minDiffInBST(root, prev_node, min_diff);
    return min_diff;
}

/// <summary>
/// Leet code #814. Binary Tree Pruning
/// 
/// We are given the head node root of a binary tree, where additionally 
/// every node's value is either a 0 or a 1. 
/// 
/// Return the same tree where every subtree (of the given tree) not 
/// containing a 1 has been removed.
///
/// (Recall that the subtree of a node X is X, plus every node that is a 
/// descendant of X.)
/// 
/// Example 1:
/// Input: [1,null,0,0,1]
/// Output: [1,null,0,null,1]
///  1               1
///   \               \ 
///    0      =>       0
///   / \               \
///  0   1               1
/// Explanation: 
/// Only the red nodes satisfy the property "every subtree not containing 
/// a 1".
/// The diagram on the right represents the answer.
///
/// Example 2:
/// Input: [1,0,1,0,0,0,1]
/// Output: [1,null,1,null,1]
///      1               1
///    /   \              \ 
///   0     1      =>      1
///  / \   / \              \
/// 0   0 0   1              1
/// 
/// Example 3:
/// Input: [1,1,0,1,1,0,1,0]
/// Output: [1,1,0,1,1,null,1]
///        1                 1
///      /   \             /   \ 
///     1     0    =>     1     0
///    / \   / \         / \     \
///   1   1 0   1       1   1     1 
///  /
/// 0
/// 
/// Note:
///
/// 1. The binary tree will have at most 100 nodes.
/// 2. The value of each node will only be 0 or 1.
/// </summary>
TreeNode* LeetCodeTree::pruneTree(TreeNode* root)
{
    if (root == nullptr) return root;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->left == nullptr && root->right == nullptr && root->val == 0)
    {
        return nullptr;
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #863. All Nodes Distance K in Binary Tree
/// </summary>
int LeetCodeTree::distanceK(TreeNode* root, TreeNode* target, int K, int distance, vector<int>& result)
{
    if (root == nullptr) return distance;
    if (root->val == target->val) distance = 0;
    if (distance >= 0)
    {
        distanceK(root->left, target, K, distance + 1, result);
        distanceK(root->right, target, K, distance + 1, result);
    }
    else
    {
        int left_distance = distanceK(root->left, target, K, distance, result);
        if (left_distance >= 0)
        {
            distance = left_distance + 1;
            distanceK(root->right, target, K, distance + 1, result);
        }
        else
        {
            int right_distance = distanceK(root->right, target, K, distance, result);
            if (left_distance < 0 && right_distance >= 0)
            {
                distance = right_distance + 1;
                distanceK(root->left, target, K, distance + 1, result);
            }
        }
    }

    if (distance == K) result.push_back(root->val);
    return distance;
}

/// <summary>
/// Leet code #863. All Nodes Distance K in Binary Tree
/// 
/// We are given a binary tree (with root node root), a target node, and an 
/// integer value `K`.
///
/// Return a list of the values of all nodes that have a distance K from the 
/// target node.  The answer can be returned in any order.
///
/// 
///
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
/// Output: [7,4,1]
/// Explanation: 
/// The nodes that are a distance 2 from the target node (with value 5)
/// have values 7, 4, and 1.
///
/// Note that the inputs "root" and "target" are actually TreeNodes.
/// The descriptions of the inputs above are just serializations of these objects.
///
/// Note:
///
/// 1. The given tree is non-empty.
/// 2. Each node in the tree has unique values 0 <= node.val <= 500.
/// 3. The target node is a node in the tree.
/// 4. 0 <= K <= 1000.
/// </summary>
vector<int> LeetCodeTree::distanceK(TreeNode* root, TreeNode* target, int K)
{
    vector<int> result;
    distanceK(root, target, K, -1, result);

    return result;
}

/// <summary>
/// Leet code #865. Smallest Subtree with all the Deepest Nodes
/// </summary>
pair<TreeNode*, int> LeetCodeTree::subtreeWithAllDeepest(TreeNode* root, int depth)
{
    pair<TreeNode *, int> result;
    if (root == nullptr)
    {
        result = make_pair(root, 0);
    }
    else
    {
        pair<TreeNode *, int> left_result = subtreeWithAllDeepest(root->left, depth + 1);
        pair<TreeNode *, int> right_result = subtreeWithAllDeepest(root->right, depth + 1);
        if (left_result.second == right_result.second)
        {
            if (left_result.first == nullptr)
            {
                result = make_pair(root, depth);
            }
            else
            {
                result = make_pair(root, left_result.second);
            }
        }
        else if (left_result.second > right_result.second)
        {
            result = left_result;
        }
        else
        {
            result = right_result;
        }
    }
    return result;
}

/// <summary>
/// Leet code #865. Smallest Subtree with all the Deepest Nodes
/// 
/// Given a binary tree rooted at root, the depth of each node is the 
/// shortest distance to the root.
///
/// A node is deepest if it has the largest depth possible among any node 
/// in the entire tree. 
/// 
/// The subtree of a node is that node, plus the set of all descendants of 
/// that node.
///
/// Return the node with the largest depth such that it contains all the 
/// deepest nodes in it's subtree.
///
/// 
///
/// Example 1:
///
/// Input: [3,5,1,6,2,0,8,null,null,7,4]
/// Output: [2,7,4]
///
/// Explanation:
/// 
/// We return the node with value 2, colored in yellow in the diagram.
/// The nodes colored in blue are the deepest nodes of the tree.
/// The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization 
/// of the given tree.
/// The output "[2, 7, 4]" is a serialization of the subtree rooted at the 
/// node with value 2.
/// Both the input and output have TreeNode type.
/// 
/// Note:
/// 1. The number of nodes in the tree will be between 1 and 500.
/// 2. The values of each node are unique.
/// </summary>
TreeNode* LeetCodeTree::subtreeWithAllDeepest(TreeNode* root)
{
    pair<TreeNode *, int> result = subtreeWithAllDeepest(root, 1);
    return result.first;
}

/// <summary>
/// Leet code #872. Leaf-Similar Trees
/// </summary>
void LeetCodeTree::getLeaves(TreeNode* root, vector<int> &leaves)
{
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr)
    {
        leaves.push_back(root->val);
    }
    else
    {
        getLeaves(root->left, leaves);
        getLeaves(root->right, leaves);
    }
}

/// <summary>
/// Leet code #872. Leaf-Similar Trees
/// 
/// Consider all the leaves of a binary tree.  From left to right order, 
/// the values of those leaves form a leaf value sequence.
///
/// For example, in the given tree above, the leaf value sequence is 
/// (6, 7, 4, 9, 8).
///
/// Two binary trees are considered leaf-similar if their leaf value 
/// sequence is the same.
///
/// Return true if and only if the two given trees with head nodes root1 
/// and root2 are leaf-similar.
///
/// Note:
/// 1. Both of the given trees will have between 1 and 100 nodes.
/// </summary>
bool LeetCodeTree::leafSimilar(TreeNode* root1, TreeNode* root2)
{
    vector<int> leaves1, leaves2;
    getLeaves(root1, leaves1);
    getLeaves(root2, leaves2);
    return (leaves1 == leaves2);
}

/// <summary>
/// Leet code #700. Search in a Binary Search Tree
/// 
/// Given the root node of a binary search tree (BST) and a value. You 
/// need to find the node in the BST that the node's value equals the 
/// given value. Return the subtree rooted with that node. If such node 
/// doesn't exist, you should return NULL.
///
/// For example, 
///
/// Given the tree:
///        4
///       / \
///      2   7
///     / \
///    1   3
///
/// And the value to search: 2
/// You should return this subtree:
///
///      2     
///     / \   
///    1   3
/// In the example above, if we want to search the value 5, since there 
/// is no node with value 5, we should return NULL.
///
/// Note that an empty tree is represented by NULL, therefore you would 
/// see the expected output (serialized tree format) as [], not null.
/// </summary>
TreeNode* LeetCodeTree::searchBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (root->val > val)
    {
        return searchBST(root->left, val);
    }
    else if (root->val < val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #701. Insert into a Binary Search Tree
/// 
/// Given the root node of a binary search tree (BST) and a value to be 
/// inserted into the tree, insert the value into the BST. Return the 
/// root node of the BST after the insertion. It is guaranteed that the 
/// new value does not exist in the original BST.
///
/// Note that there may exist multiple valid ways for the insertion, as 
/// long as the tree remains a BST after insertion. You can return any of 
/// them.
///
/// For example, 
///
/// Given the tree:
///        4
///       / \
///      2   7
///     / \
///    1   3
/// And the value to insert: 5
/// You can return this binary search tree:
///
///         4
///       /   \
///      2     7
///     / \   /
///    1   3 5
/// This tree is also valid:
///
///         5
///       /   \
///      2     7
///     / \   
///    1   3
///         \
///          4
/// </summary>
TreeNode* LeetCodeTree::insertIntoBST(TreeNode* root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
    }
    else if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

/// <summary>
/// Leet code #559. Maximum Depth of N-ary Tree
/// 
/// Given a n-ary tree, find its maximum depth.
///
/// The maximum depth is the number of nodes along the longest path from 
/// the root node down to the farthest leaf node.
///
/// For example, given a 3-ary tree:
///  
/// We should return its max depth, which is 3.
/// 
/// Note:
/// 
/// The depth of the tree is at most 1000.
/// The total number of nodes is at most 5000.
/// </summary>
int LeetCodeTree::maxDepth(Node* root)
{
    int result = 0;
    queue<Node *> search;
    search.push(root);
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            Node* node = search.front();
            search.pop();
            if (node == nullptr) return result;
            for (auto child : node->children)
            {
                if (child != nullptr) search.push(child);
            }
        }
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #589. N-ary Tree Preorder Traversal
/// 
/// Given an n-ary tree, return the preorder traversal of its 
/// nodes' values.
///
/// For example, given a 3-ary tree:
///   
/// Return its preorder traversal as: [1,3,5,6,2,4].
///
/// Note: Recursive solution is trivial, could you do it iteratively?
/// </summary>
vector<int> LeetCodeTree::preorder(Node* root)
{
    vector<int> result;

    stack<Node *> search;
    search.push(root);
    while (!search.empty())
    {
        Node * node = search.top();
        search.pop();
        if (node == nullptr) continue;
        result.push_back(node->val);
        for (int i = node->children.size() - 1; i >= 0; i--)
        {
            search.push(node->children[i]);
        }
    }
    return result;
}

/// <summary>
/// Leet code #429. N-ary Tree Level Order Traversal
/// 
/// Given an n-ary tree, return the level order traversal of its 
/// nodes' values. (ie, from left to right, level by level).
///
/// For example, given a 3-ary tree:
/// We should return its level order traversal:
/// [
///   [1],
///   [3,2,4],
///   [5,6]
/// ]
/// Note:
/// The depth of the tree is at most 1000.
/// The total number of nodes is at most 5000.
/// </summary>
vector<vector<int>> LeetCodeTree::levelOrder(Node* root)
{
    vector<vector<int>> result;
    queue<Node *> search;
    search.push(root);
    while (!search.empty())
    {
        size_t size = search.size();
        vector<int> level;
        for (size_t i = 0; i < size; i++)
        {
            Node* node = search.front();
            search.pop();
            if (node == nullptr) return result;
            for (auto child : node->children)
            {
                if (child != nullptr) search.push(child);
            }
            level.push_back(node->val);
        }
        result.push_back(level);
    }
    return result;
}

/// <summary>
/// Leet code #590. N-ary Tree Postorder Traversal
/// 
/// Given an n-ary tree, return the postorder traversal of its 
/// nodes' values.
/// 
/// For example, given a 3-ary tree:
/// 
/// Return its postorder traversal as: [5,6,3,2,4,1].
///
/// Note: Recursive solution is trivial, could you do it iteratively?
/// </summary>
vector<int> LeetCodeTree::postorder(Node* root)
{
    vector<int> result;

    stack<Node *> search;
    unordered_set<Node *> visited;
    search.push(root);
    while (!search.empty())
    {
        Node * node = search.top();
        search.pop();
        if (node == nullptr) continue;
        if (visited.count(node) > 0)
        {
            result.push_back(node->val);
        }
        else
        {
            visited.insert(node);
            search.push(node);
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                search.push(node->children[i]);
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #426. Convert Binary Search Tree to Sorted Doubly Linked List
/// </summary>
void LeetCodeTree::treeToDoublyList(TreeNode* root, TreeNode*& head, TreeNode *&tail)
{
    if (root == nullptr) return;

    treeToDoublyList(root->right, head, tail);
    if (head == nullptr)
    {
        head = new TreeNode(root->val);
        head->left = head;
        head->right = head;
        tail = head;
    }
    else
    {
        TreeNode * node = new TreeNode(root->val);
        node->right = head;
        node->left = tail;
        head->left = node;
        tail->right = node;
        head = node;
    }
    treeToDoublyList(root->left, head, tail);
}

/// <summary>
/// Leet code #426. Convert Binary Search Tree to Sorted Doubly Linked List
/// 
/// Convert a BST to a sorted circular doubly-linked list in-place. Think of 
/// the left and right pointers as synonymous to the previous and next 
/// pointers in a doubly-linked list.
///
/// Let's take the following BST as an example, it may help you understand 
/// the problem better:
///
/// We want to transform this BST into a circular doubly linked list. Each 
/// node in a doubly linked list has a predecessor and successor. For a 
/// circular doubly linked list, the predecessor of the first element is the 
/// last element, and the successor of the last element is the first element.
///
/// The figure below shows the circular doubly linked list for the BST above. 
/// The "head" symbol means the node it points to is the smallest element of 
/// the linked list.
///
/// Specifically, we want to do the transformation in place. After the 
/// transformation, the left pointer of the tree node should point to its 
/// predecessor, and the right pointer should point to its successor. We 
/// should return the pointer to the first element of the linked list.
///
/// The figure below shows the transformed BST. The solid line indicates the 
/// successor relationship, while the dashed line means the predecessor 
/// relationship.
/// </summary>
TreeNode* LeetCodeTree::treeToDoublyList(TreeNode* root)
{
    TreeNode * head = nullptr;
    TreeNode * tail = nullptr;
    treeToDoublyList(root, head, tail);
    return head;
}

/// <summary>
/// Leet code #889. Construct Binary Tree from Preorder and Postorder Traversal
/// </summary>
TreeNode* LeetCodeTree::constructFromPrePost(
    vector<int>::iterator pre_begin, 
    vector<int>::iterator pre_end,
    vector<int>::iterator post_begin, 
    vector<int>::iterator post_end)
{
    TreeNode * result = nullptr;
    
    if (pre_begin == pre_end) return result;
    int val = *pre_begin;
    result = new TreeNode(val);
    pre_begin++;
    post_end--;
    if (pre_begin == pre_end) return result;
    int left_child = *pre_begin;
    vector<int>::iterator post_itr = find(post_begin, post_end, left_child);
    post_itr++;
    int left_len = post_itr - post_begin;
    int right_len = post_end - post_itr;
    result->left = constructFromPrePost(pre_begin, pre_begin + left_len, post_begin, post_begin + left_len);
    result->right = constructFromPrePost(pre_begin + left_len, pre_end, post_begin + left_len, post_end);
    return result;
}

/// <summary>
/// Leet code #889. Construct Binary Tree from Preorder and Postorder Traversal
/// 
/// Return any binary tree that matches the given preorder and postorder 
/// traversals.
///
/// Values in the traversals pre and post are distinct positive integers.
///
/// Example 1:
/// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
/// Output: [1,2,3,4,5,6,7]
/// 
/// Note:
/// 1 <= pre.length == post.length <= 30
/// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
/// It is guaranteed an answer exists. If there exists multiple answers, 
/// you can return any of them.
/// </summary>
TreeNode* LeetCodeTree::constructFromPrePost(vector<int>& pre, vector<int>& post)
{
    return constructFromPrePost(pre.begin(), pre.end(), post.begin(), post.end());
}

/// <summary>
/// Leet code #894. All Possible Full Binary Trees
/// </summary>
TreeNode* LeetCodeTree::clone(TreeNode * root)
{
    TreeNode * result = nullptr;
    if (root == nullptr) return result;
   
    result = new TreeNode(root->val);
    result->left = clone(root->left);
    result->right = clone(root->right);
    
    return result;
}

/// <summary>
/// Leet code #894. All Possible Full Binary Trees
/// 
/// A full binary tree is a binary tree where each node has exactly 0 or 2 
/// children.
///
/// Return a list of all possible full binary trees with N nodes.  Each 
/// element of the answer is the root node of one possible tree.
///
/// Each node of each tree in the answer must have node.val = 0.
///
/// You may return the final list of trees in any order.
///
/// Example 1:
///
/// Input: 7
/// Output: 
/// [
///  [0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],
///  [0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]
/// ]
/// Explanation:
/// 
/// Note:
/// 1 <= N <= 20
/// </summary>
vector<TreeNode*> LeetCodeTree::allPossibleFBT(int N)
{
    vector<TreeNode *> result;
    if (N == 0) return result;	
    if (N == 1)
    {
        result.push_back(new TreeNode(0));
        return result;
    }
    N--;
    for (int left = 1; left < N; left += 2)
    {
        vector<TreeNode *> left_array = allPossibleFBT(left);
        vector<TreeNode *> right_array = allPossibleFBT(N - left);

        for (auto left_tree : left_array)
        {
            for (auto right_tree : right_array)
            {
                TreeNode * root = new TreeNode(0);
                root->left = clone(left_tree);
                root->right = clone(right_tree);
                result.push_back(root);
            }
        }

        for (auto tree : left_array) freeTreeNodes(tree);
        for (auto tree : right_array) freeTreeNodes(tree);
    }

    return result;
}

/// <summary>
/// Leet code #897. Increasing Order Search Tree 
/// </summary>
void LeetCodeTree::increasingBST(TreeNode *& new_root, TreeNode *&new_child, TreeNode* root)
{
    if (root == nullptr) return;
    increasingBST(new_root, new_child, root->left);
    if (new_root == nullptr)
    {
        new_root = root;
        root->left = nullptr;
    }
    else
    {
        new_child->right = root;
        root->left = nullptr;
    }
    new_child = root;
    increasingBST(new_root, new_child, root->right);
}

/// <summary>
/// Leet code #897. Increasing Order Search Tree 
/// 
/// Given a tree, rearrange the tree in in-order so that the leftmost node in 
/// the tree is now the root of the tree, and every node has no left child 
/// and only 1 right child.
///
/// Example 1:
/// Input: [5,3,6,2,4,null,8,1,null,null,null,7,9]
///
///       5
///      / \
///     3   6
///    / \   \
///   2   4   8
///  /       / \ 
/// 1       7   9
///
/// Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
///
/// 1
///  \
///   2
///    \
///     3
///      \
///       4
///        \
///         5
///          \
///           6
///            \
///             7
///              \
///               8
///                \
///                 9  
/// Note:
///
/// 1. The number of nodes in the given tree will be between 1 and 100.
/// 2. Each node will have a unique integer value from 0 to 1000.
/// </summary>
TreeNode* LeetCodeTree::increasingBST(TreeNode* root)
{
    TreeNode * new_root = nullptr;
    TreeNode * new_child = nullptr;
    increasingBST(new_root, new_child, root);
    return new_root;
}

/// <summary>
/// Leet code #938. Range Sum of BST
/// 
/// Given the root node of a binary search tree, return the sum of values of 
/// all nodes with value between L and R (inclusive).
///
/// The binary search tree is guaranteed to have unique values.
///
/// Example 1:
///
/// Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
/// Output: 32
/// Example 2:
///
/// Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
/// Output: 23
///  
///
/// Note:
///
/// The number of nodes in the tree is at most 10000.
/// The final answer is guaranteed to be less than 2^31.
///
/// </summary>
int LeetCodeTree::rangeSumBST(TreeNode* root, int L, int R)
{
    int result = 0;
    if (root == nullptr) return result;
    if (root->val >= L && root->val <= R)
    {
        result = root->val;
        result += rangeSumBST(root->left, L, R);
        result += rangeSumBST(root->right, L, R);
    }
    else if (root->val < L)
    {
        result += rangeSumBST(root->right, L, R);
    }
    else if (root->val > R)
    {
        result += rangeSumBST(root->left, L, R);
    }
    return result;
}

/// <summary>
/// Leet code #951. Flip Equivalent Binary Trees
/// 
/// For a binary tree T, we can define a flip operation as follows: choose 
/// any node, and swap the left and right child subtrees.
/// 
/// A binary tree X is flip equivalent to a binary tree Y if and only if 
/// we can make X equal to Y after some number of flip operations.
///
/// Write a function that determines whether two binary trees are flip 
/// equivalent.  The trees are given by root nodes root1 and root2.
/// 
/// 
/// Example 1:
///
/// Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], 
///        root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
/// Output: true
/// Explanation: We flipped at nodes with values 1, 3, and 5.
/// Flipped Trees Diagram
/// 
/// Note:
/// 
/// 1. Each tree will have at most 100 nodes.
/// 2. Each value in each tree will be a unique integer in the range 
/// [0, 99].
/// </summary>
bool LeetCodeTree::flipEquiv(TreeNode* root1, TreeNode* root2)
{
    if (root1 == root2) return true;
    if ((root1 == nullptr) || (root2 == nullptr)) return false;
 
    if (root1 != nullptr && root2 != nullptr && root1->val != root2->val) return false;
    if (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
    {
        return true;
    }
    else if (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #958. Check Completeness of a Binary Tree
/// 
/// Given a binary tree, determine if it is a complete binary tree.
///
/// Definition of a complete binary tree from Wikipedia:
/// In a complete binary tree every level, except possibly the last, is 
/// completely filled, and all nodes in the last level are as far left as 
/// possible. It can have between 1 and 2h nodes inclusive at the last level h.
///
/// 
///
/// Example 1:
///
/// Input: [1,2,3,4,5,6]
/// Output: true
/// Explanation: Every level before the last is full (ie. levels with 
/// node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) 
/// are as far left as possible.
///
/// Example 2:
///
/// Input: [1,2,3,4,5,null,7]
/// Output: false
/// Explanation: The node with value 7 isn't as far left as possible.
/// 
/// Note:
///
/// 1. The tree will have between 1 and 100 nodes.
/// </summary>
bool LeetCodeTree::isCompleteTree(TreeNode* root)
{
    bool meetNull = false;
    queue<TreeNode*> search;
    search.push(root);

    while (!search.empty())
    {
        TreeNode * node = search.front();
        search.pop();
        if (node == nullptr)
        {
            meetNull = true;
        }
        else
        {
            if (meetNull) return false;
            search.push(node->left);
            search.push(node->right);
        }
    }
    return true;
}

/// <summary>
/// Leet code #968. Binary Tree Cameras
/// </summary>
int LeetCodeTree::minCameraCover(TreeNode* root, int &result)
{
    // the child is null or covered
    if (root == nullptr) return 1;
    int left = minCameraCover(root->left, result);
    int right = minCameraCover(root->right, result);

    // if left and right are all covered, but no camera, return 0 
    // means myself not covered.
    if (left == 1 && right == 1) return 0;
    // either left or right not covered, we need a camera here
    if (left == 0 || right == 0)
    {
        result++;
        return 2;
    }
    else // either left or right contains a camera
    {
        return 1;
    }
}

/// <summary>
/// Leet code #968. Binary Tree Cameras
/// 
/// Given a binary tree, we install cameras on the nodes of the tree. 
///
/// Each camera at a node can monitor its parent, itself, and its immediate 
/// children.
///
/// Calculate the minimum number of cameras needed to monitor all nodes of 
/// the tree.
///
/// Example 1:
/// Input: [0,0,null,0,0]
/// Output: 1
/// Explanation: One camera is enough to monitor all nodes if placed as shown.
///
/// Example 2:
/// Input: [0,0,null,0,null,0,null,null,0]
/// Output: 2
/// Explanation: At least two cameras are needed to monitor all nodes of the 
/// tree. The above image shows one of the valid configurations of camera 
/// placement.
///
/// Note:
/// 
/// 1. The number of nodes in the given tree will be in the range [1, 1000].
/// 2. Every node has value 0.
/// </summary>
int LeetCodeTree::minCameraCover(TreeNode* root)
{
    int result = 0;
    if (minCameraCover(root, result) == 0)
    {
        result++;
    }
    return result;
}

/// <summary>
/// Leet code #965. Univalued Binary Tree
/// 
/// A binary tree is univalued if every node in the tree has the same value.
///
/// Return true if and only if the given tree is univalued.
///
/// Example 1:
/// Input: [1,1,1,1,1,null,1]
/// Output: true
///
/// Example 2:
/// Input: [2,2,2,5,2]
/// Output: false
/// 
/// Note:
/// 
/// 1. The number of nodes in the given tree will be in the range [1, 100].
/// 2. Each node's value will be an integer in the range [0, 99].
/// </summary>
bool LeetCodeTree::isUnivalTree(TreeNode* root)
{
    int prev_val = -1;
    queue<TreeNode *> search;
    search.push(root);

    while (!search.empty())
    {
        TreeNode * node = search.front();
        search.pop();
        if (prev_val == -1)
        {
            prev_val = node->val;
        }
        else if (prev_val != node->val)
        {
            return false;
        }
        if (node->left != nullptr)
        {
            search.push(node->left);
        }
        if (node->right != nullptr)
        {
            search.push(node->right);
        }
    }
    return true;
}

/// <summary>
/// Leet code #971. Flip Binary Tree To Match Preorder Traversal
/// </summary>
void LeetCodeTree::flipMatchVoyage(TreeNode* root, vector<int>& voyage, int& index, vector<int>& result)
{
    // fail to match
    if (root->val != voyage[index])
    {
        result.clear();
        result.push_back(-1);
        return;
    }
    
    // failed already
    if (!result.empty() && result[0] == -1)
    {
        return;
    }
    index++;
    if (root->left != nullptr && root->right != nullptr)
    {
        if (root->left->val != voyage[index])
        {
            std::swap(root->left, root->right);
            result.push_back(root->val);
        }
        flipMatchVoyage(root->left, voyage, index, result);
        flipMatchVoyage(root->right, voyage, index, result);
    }
    else if (root->left != nullptr)
    {
        flipMatchVoyage(root->left, voyage, index, result);
    }
    else if (root->right != nullptr)
    {
        flipMatchVoyage(root->right, voyage, index, result);
    }
    return;
}

/// <summary>
/// Leet code #971. Flip Binary Tree To Match Preorder Traversal
/// 
/// Given a binary tree with N nodes, each node has a different value from 
/// {1, ..., N}.
///
/// A node in this binary tree can be flipped by swapping the left child 
/// and the right child of that node.
///
/// Consider the sequence of N values reported by a preorder traversal starting 
/// from the root.  Call such a sequence of N values the voyage of the tree.
///
/// (Recall that a preorder traversal of a node means we report the current 
/// node's value, then preorder-traverse the left child, then preorder-traverse
/// the right child.)
///
/// Our goal is to flip the least number of nodes in the tree so that the 
/// voyage of the tree matches the voyage we are given.
///
/// If we can do so, then return a list of the values of all nodes flipped.  
/// You may return the answer in any order.
///
/// If we cannot do so, then return the list [-1].
///
/// 
/// Example 1:
/// Input: root = [1,2], voyage = [2,1]
/// Output: [-1]
///
/// Example 2:
/// Input: root = [1,2,3], voyage = [1,3,2]
/// Output: [1]
///
/// Example 3:
/// Input: root = [1,2,3], voyage = [1,2,3]
/// Output: []
///  
/// Note:
/// 
/// 1. 1 <= N <= 100
/// </summary>
vector<int> LeetCodeTree::flipMatchVoyage(TreeNode* root, vector<int>& voyage)
{
    vector<int> result;
    int index = 0;
    flipMatchVoyage(root, voyage, index, result);
    return result;
}

/// <summary>
/// Leet code #979. Distribute Coins in Binary Tree
/// </summary>
int LeetCodeTree::distributeCoins(TreeNode* root, vector<int>& missingPaths, int &result)
{
    if (root == nullptr)
    {
        return 0;
    }
    vector<int> leftMissingPaths, rightMissingPaths;
    root->val += distributeCoins(root->left, leftMissingPaths, result);
    root->val += distributeCoins(root->right, rightMissingPaths, result);

    for (auto path : leftMissingPaths) missingPaths.push_back(path);
    for (auto path : rightMissingPaths) missingPaths.push_back(path);
    while (root->val > 0 && !missingPaths.empty())
    {
        result += missingPaths.back();
        root->val--;
        missingPaths.pop_back();
    }
    if (root->val == 0)
    {
        missingPaths.push_back(0);
    }
    for (size_t i = 0; i < missingPaths.size(); i++)
    {
        missingPaths[i]++;
    }
    if (root->val > 1)
    {
        result += root->val - 1;
        return root->val - 1;
    }
    else
    {
        return 0;
    }
}

/// <summary>
/// Leet code #979. Distribute Coins in Binary Tree
/// 
/// Given the root of a binary tree with N nodes, each node in the tree 
/// has node.val coins, and there are N coins total.
/// In one move, we may choose two adjacent nodes and move one coin from 
/// one node to another.  (The move may be from parent to child, or from 
/// child to parent.)
/// Return the number of moves required to make every node have exactly 
/// one coin.
///
/// Example 1:
///
/// Input: [3,0,0]
/// Output: 2
/// Explanation: From the root of the tree, we move one coin to its left 
/// child, and one coin to its right child.
///   
/// Example 2:
/// 
/// Input: [0,3,0]
/// Output: 3
/// Explanation: From the left child of the root, we move two coins to 
/// the root [taking two moves].  Then, we move one coin from the root of 
/// the tree to the right child.
///
/// Example 3:
///
/// Input: [1,0,2]
/// Output: 2
///
/// Example 4:
///
/// Input: [1,0,0,null,3]
/// Output: 4
///
/// Note:
/// 1. 1<= N <= 100
/// 2. 0 <= node.val <= N
/// </summary>
int LeetCodeTree::distributeCoins(TreeNode* root)
{
    int result = 0;
    vector<int> missingPaths;
    distributeCoins(root, missingPaths, result);
    return result;
}

/// <summary>
/// Leet code #987. Vertical Order Traversal of a Binary Tree
/// 
/// Given a binary tree, return the vertical order traversal of its nodes 
/// values.
/// For each node at position (X, Y), its left and right children 
/// respectively will be at positions (X-1, Y-1) and (X+1, Y-1).
/// 
/// Running a vertical line from X = -infinity to X = +infinity, whenever 
/// the vertical line touches some nodes, we report the values of the 
/// nodes in order from top to bottom (decreasing Y coordinates).
///
/// If two nodes have the same position, then the value of the node that 
/// is reported first is the value that is smaller.
///
/// Return an list of non-empty reports in order of X coordinate.  Every 
/// report will have a list of values of nodes.
///
/// Example 1:
/// 
/// Input: [3,9,20,null,null,15,7]
/// Output: [[9],[3,15],[20],[7]]
/// Explanation: 
/// Without loss of generality, we can assume the root node is at 
/// position (0, 0):
/// Then, the node with value 9 occurs at position (-1, -1);
/// The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
/// The node with value 20 occurs at position (1, -1);
/// The node with value 7 occurs at position (2, -2).
///
/// Example 2:
/// 
/// Input: [1,2,3,4,5,6,7]
/// Output: [[4],[2],[1,5,6],[3],[7]]
/// Explanation: 
/// The node with value 5 and the node with value 6 have the same position 
/// according to the given scheme.
/// However, in the report "[1,5,6]", the node value of 5 comes first since
/// 5 is smaller than 6.
/// 
///
/// Note:
///
/// 1. The tree will have between 1 and 1000 nodes.
/// 2. Each node's value will be between 0 and 1000.
/// </summary>
vector<vector<int>> LeetCodeTree::verticalTraversal(TreeNode* root)
{
    vector<vector<int>> result;
    map<int, map<int, set<int>>> node_map;
    int position = 0;
    queue<pair<TreeNode *, vector<int>>> search;
    vector<int> pos = vector<int>(2);
    search.push(make_pair(root, pos));
    int level = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        for (size_t i = 0; i < size; i++)
        {
            pair<TreeNode *, vector<int>> node = search.front();
            search.pop();
            if (node.first == nullptr) continue;
            node_map[node.second[0]][node.second[1]].insert(node.first->val);
            vector<int> pos = node.second;
            pos[0] = node.second[0] - 1;
            pos[1] = level;
            search.push(make_pair(node.first->left, pos));
            pos[0] = node.second[0] + 1;
            pos[1] = level;
            search.push(make_pair(node.first->right, pos));
        }
        level++;
    }
    for (auto itr = node_map.begin(); itr != node_map.end(); ++itr)
    {
        result.push_back(vector<int>());
        for (auto itr1 = itr->second.begin(); itr1 != itr->second.end(); ++itr1)
        {
            result.back().insert(result.back().end(), itr1->second.begin(), itr1->second.end());
        }
    }
    return result;
}

/// <summary>
/// Leet code #988. Smallest String Starting From Leaf
/// </summary>
void LeetCodeTree::smallestFromLeaf(TreeNode* root, string& str, string &result)
{
    str.push_back(root->val + 'a');
    if (root->left == nullptr && root->right == nullptr)
    {
        string rev_str = str;
        std::reverse(rev_str.begin(), rev_str.end());
        if (result.empty()) result = rev_str;
        else result = min(rev_str, result);
    }
    else
    {
        if (root->left != nullptr)
        {
            smallestFromLeaf(root->left, str, result);
        }
        if (root->right != nullptr)
        {
            smallestFromLeaf(root->right, str, result);
        }
    }
    str.pop_back();
}

/// <summary>
/// Leet code #988. Smallest String Starting From Leaf
/// 
/// Given the root of a binary tree, each node has a value from 0 to 25 
/// representing the letters 'a' to 'z': a value of 0 represents 'a', 
/// a value of 1 represents 'b', and so on.
///
/// Find the lexicographically smallest string that starts at a leaf of 
/// this tree and ends at the root.
///
/// (As a reminder, any shorter prefix of a string is lexicographically 
/// smaller: for example, "ab" is lexicographically smaller than "aba".  
/// A leaf of a node is a node that has no children.)
///
/// Example 1:
/// Input: [0,1,2,3,4,3,4]
/// Output: "dba"
///
/// Example 2:
/// Input: [25,1,3,1,3,0,2]
/// Output: "adz"
///
/// Example 3:
/// Input: [2,2,1,null,1,0,null,0]
/// Output: "abc"
///
/// Note:
/// 1. The number of nodes in the given tree will be between 1 and 1000.
/// 2. Each node in the tree will have a value between 0 and 25.
/// </summary>
string LeetCodeTree::smallestFromLeaf(TreeNode* root)
{
    string str, result;
    smallestFromLeaf(root, str, result);
    return result;
}

/// <summary>
/// Leet code #510. Inorder Successor in BST II
/// 
/// Given a binary search tree and a node in it, find the in-order 
/// successor of that node in the BST.
///
/// The successor of a node p is the node with the smallest key greater 
/// than p.val.
///
/// You will have direct access to the node but not to the root of the 
/// tree. Each node will have a reference to its parent node.
///
///
///
/// Example 1:
/// Input: 
/// root = {"$id":"1","left":{"$id":"2","left":null,"parent":{"$ref":"1"},
/// "right":null,"val":1}, "parent":null,"right": {"$id":"3","left":null,
/// "parent":{"$ref":"1"}, "right":null,"val":3},"val":2}
/// p = 1
/// Output: 2
/// Explanation: 1's in-order successor node is 2. Note that both p and 
/// the return value is of Node type.
///
/// Example 2:
///
/// Input:
/// root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":
/// "4","left":null,"parent":{"$ref":"3"},"right":null,"val":1},"parent":
/// {"$ref":"2"},"right":null,"val":2},"parent":{"$ref":"1"},"right":
/// {"$id":"5","left":null,"parent":{"$ref":"2"},"right":null,"val":4},
/// "val":3},"parent":null,"right":{"$id":"6","left":null,"parent":
/// {"$ref":"1"},"right":null,"val":6},"val":5}
/// p = 6
/// Output: null
/// Explanation: There is no in-order successor of the current node, so 
/// the answer is null.
///
/// Example 3:
/// Input: 
/// root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":
/// {"$id":"4","left":null,"parent":{"$ref":"3"},"right":null,"val":2},
/// "parent":{"$ref":"2"},"right":{"$id":"5","left":null,"parent":
/// {"$ref":"3"},"right":null,"val":4},"val":3},"parent":{"$ref":"1"},
/// "right":{"$id":"6","left":null,"parent":{"$ref":"2"},"right":
/// {"$id":"7","left":{"$id":"8","left":null,"parent":{"$ref":"7"},
/// "right":null,"val":9},"parent":{"$ref":"6"},"right":null,"val":13},
/// "val":7},"val":6},"parent":null,"right":{"$id":"9","left":
/// {"$id":"10","left":null,"parent":{"$ref":"9"},"right":null,
/// "val":17},"parent":{"$ref":"1"},"right":{"$id":"11","left":null,
/// "parent":{"$ref":"9"},"right":null,"val":20},"val":18},"val":15}
/// p = 15
/// Output: 17
///
/// Example 4:
/// Input: 
/// root = {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":{"$id":
/// "4","left":null,"parent":{"$ref":"3"},"right":null,"val":2},"parent":
/// {"$ref":"2"},"right":{"$id":"5","left":null,"parent":{"$ref":"3"},
///	"right":null,"val":4},"val":3},"parent":{"$ref":"1"},"right":
/// {"$id":"6","left":null,"parent":{"$ref":"2"},"right":{"$id":"7","left":
/// {"$id":"8","left":null,"parent":{"$ref":"7"},"right":null,"val":9},
/// "parent":{"$ref":"6"},"right":null,"val":13},"val":7},"val":6},
/// "parent":null,"right":{"$id":"9","left":{"$id":"10","left":null,
/// "parent":{"$ref":"9"},"right":null,"val":17},"parent":{"$ref":"1"},
/// "right":{"$id":"11","left":null,"parent":{"$ref":"9"},"right":null,
/// "val":20},"val":18},"val":15}
/// p = 13
/// Output: 15
/// Note:
/// If the given node has no in-order successor in the tree, return null.
/// It's guaranteed that the values of the tree are unique.
/// Remember that we are using the Node type instead of TreeNode type so 
/// their string representation are different.
/// </summary>
TreeNode* LeetCodeTree::inorderSuccessor(TreeNode* node)
{
    TreeNode * result = nullptr;

    if (node->right != nullptr)
    {
        result = node->right;
        while (result->left != nullptr) result = result->left;
    }
    else
    {
        while (node->parent != nullptr)
        {
            TreeNode * parent = node->parent;
            if (parent->left == node)
            {
                result = parent;
                break;
            }
            else
            {
                node = parent;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #993. Cousins in Binary Tree
/// </summary>
bool LeetCodeTree::isCousins(TreeNode* root, TreeNode*& parent, int& depth, int val)
{
    if (root == nullptr) return false;
    if (root->val == val) return true;
    int new_depth = depth + 1;
    TreeNode* new_parent = root;
    if (isCousins(root->left, new_parent, new_depth, val))
    {
        parent = new_parent;
        depth = new_depth;
        return true;
    }
    new_parent = root;
    new_depth = depth + 1;
    if (isCousins(root->right, new_parent, new_depth, val))
    {
        parent = new_parent;
        depth = new_depth;
        return true;
    }
    return false;
}

/// <summary>
/// Leet code #993. Cousins in Binary Tree
/// 
/// In a binary tree, the root node is at depth 0, and children of each depth 
/// k node are at depth k+1.
///
/// Two nodes of a binary tree are cousins if they have the same depth, but 
/// have different parents.
///
/// We are given the root of a binary tree with unique values, and the values 
/// x and y of two different nodes in the tree.
///
/// Return true if and only if the nodes corresponding to the values x and y 
/// are cousins.
///
/// 
/// Example 1:
///
///
/// Input: root = [1,2,3,4], x = 4, y = 3
/// Output: false
///
/// Example 2:
///
/// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
/// Output: true
///
/// Example 3:
///
/// Input: root = [1,2,3,null,4], x = 2, y = 3
/// Output: false
/// 
/// Note:
/// 
/// 1. The number of nodes in the tree will be between 2 and 100.
/// 2. Each node has a unique integer value from 1 to 100.
/// </summary>
bool LeetCodeTree::isCousins(TreeNode* root, int x, int y)
{
    TreeNode * x_parent = root;
    int x_depth = 0;
    TreeNode * y_parent = root;
    int y_depth = 0;

    isCousins(root, x_parent, x_depth, x);
    isCousins(root, y_parent, y_depth, y);

    if ((x_parent != y_parent) && (x_depth == y_depth))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #998. Maximum Binary Tree II
/// 
/// We are given the root node of a maximum tree: a tree where every node 
/// has a value greater than any other value in its subtree.
///
/// Just as in the previous problem, the given tree was constructed from 
/// an list A (root = Construct(A)) recursively with the following 
/// Construct(A) routine:
///
/// If A is empty, return null.
/// Otherwise, let A[i] be the largest element of A.  Create a root node 
/// with value A[i].
/// The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
/// The right child of root will be Construct([A[i+1], A[i+2], ..., 
/// A[A.length - 1]])
/// Return root.
/// Note that we were not given A directly, only a root node 
/// root = Construct(A).
///
/// Suppose B is a copy of A with the value val appended to it.  It is 
/// guaranteed that B has unique values.
///
/// Return Construct(B).
/// 
/// Example 1:
/// Input: root = [4,1,3,null,null,2], val = 5
/// Output: [5,4,null,1,3,null,null,2]
/// Explanation: A = [1,4,2,3], B = [1,4,2,3,5]
///
/// Example 2:
/// Input: root = [5,2,4,null,1], val = 3
/// Output: [5,2,4,null,1,null,3]
/// Explanation: A = [2,1,5,4], B = [2,1,5,4,3]
///
/// Example 3:
/// Input: root = [5,2,3,null,1], val = 4
/// Output: [5,2,4,null,1,3]
/// Explanation: A = [2,1,5,3], B = [2,1,5,3,4]
/// 
/// Note:
/// 1. 1 <= B.length <= 100
/// </summary>
TreeNode* LeetCodeTree::insertIntoMaxTree(TreeNode* root, int val)
{
    if (root == nullptr || val > root->val)
    {
        TreeNode * node = new TreeNode(val);
        node->left = root;
        root = node;
    }
    else if (root->right == nullptr || val > root->right->val)
    {
        TreeNode * node = new TreeNode(val);
        node->left = root->right;
        root->right = node;
    }
    else
    {
        insertIntoMaxTree(root->right, val);
    }

    return root;
}

/// <summary>
/// Leet code #1008. Construct Binary Search Tree from Preorder Traversal
/// </summary>
TreeNode* LeetCodeTree::bstFromPreorder(TreeNode *root, stack<TreeNode*> &left_path, 
    vector<int>& preorder, size_t& index)
{
    if (index >= preorder.size()) return root;
    if (root == nullptr)
    {
        root = new TreeNode(preorder[index]);
        index++;
        bstFromPreorder(root, left_path, preorder, index);
    }
    else
    {
        if (root->val > preorder[index])
        {
            root->left = new TreeNode(preorder[index]);
            index++;
            left_path.push(root);
            bstFromPreorder(root->left, left_path, preorder, index);
        }
        else
        {
            TreeNode * parent = nullptr;
            while (!left_path.empty())
            {
                parent = left_path.top();
                if (parent->val > preorder[index]) break;
                root = parent;
                left_path.pop();
            }
            root->right = new TreeNode(preorder[index]);
            index++;
            bstFromPreorder(root->right, left_path, preorder, index);
        }
    }
    return root;
}

/// <summary>
/// Leet code #1008. Construct Binary Search Tree from Preorder Traversal
/// 
/// Return the root node of a binary search tree that matches the given 
/// preorder traversal.
///
/// (Recall that a binary search tree is a binary tree where for every 
/// node, any descendant of node.left has a value < node.val, and any 
/// descendant of node.right has a value > node.val.  Also recall that a 
/// preorder traversal displays the value of the node first, then 
/// traverses node.left, then traverses node.right.)
///
/// Example 1:
///
/// Input: [8,5,1,7,10,12]
/// Output: [8,5,10,1,7,null,12]
///
/// Note: 
///
/// 1. 1 <= preorder.length <= 100
/// 2. The values of preorder are distinct.
/// </summary>
TreeNode* LeetCodeTree::bstFromPreorder(vector<int>& preorder)
{
    stack<TreeNode *> left_path;
    TreeNode * root = nullptr;
    size_t index = 0;
    root = bstFromPreorder(root, left_path, preorder, index);
    return root;
}

/// <summary>
/// Leet code #1022. Sum of Root To Leaf Binary Numbers
/// </summary>
int LeetCodeTree::sumRootToLeaf(TreeNode* root, int value, int &result)
{
    if (root == nullptr) return result;
    if (root->left == nullptr && root->right == nullptr)
    {
        result += value * 2 + root->val;
        return result;
    }
    else
    {
        if (root->left != nullptr)
        {
            sumRootToLeaf(root->left, value * 2 + root->val, result);
        }
        if (root->right != nullptr)
        {
            sumRootToLeaf(root->right, value * 2 + root->val, result);
        }
        return result;
    }
}

/// <summary>
/// Leet code #1022. Sum of Root To Leaf Binary Numbers
/// 
/// Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path 
/// represents a binary number starting with the most significant bit.  For 
/// example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 
/// 01101 in binary, which is 13.
///
/// For all leaves in the tree, consider the numbers represented by the path 
/// from the root to that leaf.
///
/// Return the sum of these numbers.
///
/// 
/// Example 1:
///
/// Input: [1,0,1,0,1,0,1]
/// Output: 22
/// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
/// 
///
/// Note:
///
/// 1. The number of nodes in the tree is between 1 and 1000.
/// 2. node.val is 0 or 1.
/// 3. The answer will not exceed 2^31 - 1.
/// </summary>
int LeetCodeTree::sumRootToLeaf(TreeNode* root)
{
    int value = 0;
    int result = 0;
    sumRootToLeaf(root, value, result);
    return result;
}

/// <summary>
/// Leet code #1026. Maximum Difference Between Node and Ancestor
/// </summary>
int LeetCodeTree::maxAncestorDiff(TreeNode* root, int min_val, int max_val, int& result)
{
    if (root == nullptr) return result;
    result = max(result, abs(root->val - min_val));
    result = max(result, abs(root->val - max_val));
    maxAncestorDiff(root->left, min(root->val, min_val), max(root->val, max_val), result);
    maxAncestorDiff(root->right, min(root->val, min_val), max(root->val, max_val), result);
    
    return result;
}

/// <summary>
/// Leet code #1026. Maximum Difference Between Node and Ancestor
/// 
/// Given the root of a binary tree, find the maximum value V for which there 
/// exists different nodes A and B where V = |A.val - B.val| and A is an 
/// ancestor of B.
///
/// (A node A is an ancestor of B if either: any child of A is equal to B, or 
/// any child of A is an ancestor of B.)
///
/// Example 1:
/// 
/// Input: [8,3,10,1,6,null,14,null,null,4,7,13]
/// Output: 7
/// Explanation: 
/// We have various ancestor-node differences, some of which are given below :
/// |8 - 3| = 5
/// |3 - 7| = 4
/// |8 - 1| = 7
/// |10 - 13| = 3
/// Among all possible differences, the maximum value of 7 is obtained by 
/// |8 - 1| = 7.
/// 
/// Note:
///
/// 1. The number of nodes in the tree is between 2 and 5000.
/// 2. Each node will have value between 0 and 100000.
/// </summary>
int LeetCodeTree::maxAncestorDiff(TreeNode* root)
{
    int result = 0;
    maxAncestorDiff(root, root->val, root->val, result);
    
    return result;
}

/// <summary>
/// Leet code #1028. Recover a Tree From Preorder Traversal
/// </summary>
TreeNode* LeetCodeTree::recoverFromPreorder(TreeNode * root, int curr_depth, int& child_depth,
    int& child_val, string S, size_t &index)
{
    while (true)
    {
        if (index >= S.size() && child_depth == -1) break;
        if (child_depth == -1)
        {
            child_depth = 0;
            while (S[index] == '-')
            {
                child_depth++;
                index++;
            }
            string str_num;
            while (isdigit(S[index]))
            {
                str_num.push_back(S[index]);
                index++;
            }
            child_val = atoi(str_num.c_str());
        }
        if (root == nullptr)
        {
            root = new TreeNode(child_val);
            child_depth = -1;
            recoverFromPreorder(root, 0, child_depth, child_val, S, index);
            break;
        }
        if (child_depth <= curr_depth)
        {
            break;
        }
        if (root->left == nullptr)
        {
            root->left = new TreeNode(child_val);
            child_depth = -1;
            recoverFromPreorder(root->left, curr_depth + 1, child_depth, child_val, S, index);
        }
        else if (root->right == nullptr)
        {
            root->right = new TreeNode(child_val);
            child_depth = -1;
            recoverFromPreorder(root->right, curr_depth + 1, child_depth, child_val, S, index);
        }
        else
        {
            break;
        }
    }
    return root;
}

/// <summary>
/// Leet code #1028. Recover a Tree From Preorder Traversal
/// 
/// We run a preorder depth first search on the root of a binary tree.
///
/// At each node in this traversal, we output D dashes (where D is the depth 
/// of this node), then we output the value of this node.  (If the depth of 
/// a node is D, the depth of its immediate child is D+1.  The depth of the 
/// root node is 0.)
///
/// If a node has only one child, that child is guaranteed to be the left 
/// child.
///
/// Given the output S of this traversal, recover the tree and return its root.
///
/// Example 1:
/// 
/// Input: "1-2--3--4-5--6--7"
/// Output: [1,2,5,3,4,6,7]
///
/// Example 2:
/// 
/// Input: "1-2--3---4-5--6---7"
/// Output: [1,2,5,3,null,6,null,4,null,7]
/// 
/// Example 3:
/// 
/// Input: "1-401--349---90--88"
/// Output: [1,401,null,349,88,90]
/// 
/// Note:
/// 
/// 1. The number of nodes in the original tree is between 1 and 1000. 
/// 2. Each node will have a value between 1 and 10^9.
/// </summary>
TreeNode* LeetCodeTree::recoverFromPreorder(string S)
{
    TreeNode * root = nullptr;
    int child_depth = -1;
    int cur_depth = -1;
    int child_val = 0;
    size_t index = 0;
    return recoverFromPreorder(root, cur_depth, child_depth, child_val, S, index);
}

/// <summary>
/// Leet code #1038. Binary Search Tree to Greater Sum Tree
/// </summary>
void LeetCodeTree::bstToGst(TreeNode* root, int &sum)
{
    if (root == nullptr) return;
    bstToGst(root->right, sum);
    root->val += sum;
    sum = root->val;
    bstToGst(root->left, sum);
}

/// <summary>
/// Leet code #1038. Binary Search Tree to Greater Sum Tree
/// 
/// Given the root of a binary search tree with distinct values, modify it so 
/// that every node has a new value equal to the sum of the values of the 
/// original tree that are greater than or equal to node.val.
///
/// As a reminder, a binary search tree is a tree that satisfies these 
/// constraints:
///
/// The left subtree of a node contains only nodes with keys less than the 
/// node's key.
/// The right subtree of a node contains only nodes with keys greater than 
/// the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// 
/// Example 1:
/// 
///
/// Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
/// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
/// 
/// Note:
///
/// 1. The number of nodes in the tree is between 1 and 100.
/// 2. Each node will have value between 0 and 100.
/// 3. The given tree is a binary search tree.
/// </summary>
TreeNode* LeetCodeTree::bstToGst(TreeNode* root)
{
    int sum = 0;
    bstToGst(root, sum);
    return root;
}

/// <summary>
/// Leet code #1080. Insufficient Nodes in Root to Leaf Paths
/// </summary>
TreeNode* LeetCodeTree::sufficientSubset(TreeNode* root, int limit, int sum)
{
    if (root == nullptr) return root;
    sum += root->val;
    if (root->left == nullptr && root->right == nullptr)
    {
        if (sum < limit)
        {
            freeTreeNodes(root);
            return nullptr;
        }
        else return root;
    }
    root->left = sufficientSubset(root->left, limit, sum);
    root->right = sufficientSubset(root->right, limit, sum);
    if (root->left == nullptr && root->right == nullptr)
    {
        freeTreeNodes(root);
        return nullptr;
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #1080. Insufficient Nodes in Root to Leaf Paths
/// 
/// Given the root of a binary tree, consider all root to leaf paths: paths 
/// from the root to any leaf.  (A leaf is a node with no children.)
///
/// A node is insufficient if every such root to leaf path intersecting this 
/// node has sum strictly less than limit.
///
/// Delete all insufficient nodes simultaneously, and return the root of the 
/// resulting binary tree.
///
/// 
/// Example 1:
///
/// Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
///
/// Output: [1,2,3,4,null,null,7,8,9,null,14]
///
/// Example 2:
///
/// Input: root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
///
/// Output: [5,4,8,11,null,17,4,7,null,null,null,5]
///
/// Note:
///
/// 1. The given tree will have between 1 and 5000 nodes.
/// 2. -10^5 <= node.val <= 10^5
/// 3. -10^9 <= limit <= 10^9
/// </summary>
TreeNode* LeetCodeTree::sufficientSubset(TreeNode* root, int limit)
{
    int sum = 0;
    root = sufficientSubset(root, limit, sum);
    return root;
}

/// <summary>
/// Leet code #1104. Path In Zigzag Labelled Binary Tree
/// 
/// In an infinite binary tree where every node has two children, the nodes 
/// are labelled in row order.
///
/// In the odd numbered rows (ie., the first, third, fifth,...), the labelling 
/// is left to right, while in the even numbered rows (second, fourth, 
/// sixth,...), the labelling is right to left.
/// 
/// Given the label of a node in this tree, return the labels in the path from 
/// the root of the tree to the node with that label.
///
/// Example 1:
/// Input: label = 14
/// Output: [1,3,4,14]
///
/// Example 2:
/// Input: label = 26
/// Output: [1,2,6,10,26]
///
/// Constraints:
///
/// 1. 1 <= label <= 10^6
/// </summary>
vector<int> LeetCodeTree::pathInZigZagTree(int label)
{
    int sum = 1;
    int level = 1;
    int start = 1;
    while (label > sum)
    {
        level++;
        sum = 2 * sum + 1;
        start *= 2;
    }

    vector<int> result;

    int index = 0;
    if (level % 2 == 1) index = label;
    else index = start * 2 - 1 - (label - start);
    while (level > 0)
    {
        if (level % 2 == 1) label = index;
        else label = start * 2 - 1 - (index - start);
        result.push_back(label);

        level--;
        start /= 2;
        index /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leet code #1110. Delete Nodes And Return Forest
/// </summary>
TreeNode* LeetCodeTree::delNodes(TreeNode* root, vector<int>& del_bit, vector<TreeNode*> &result)
{
    if (root == nullptr) return root;
    root->left = delNodes(root->left, del_bit, result);
    root->right = delNodes(root->right, del_bit, result);
    if (del_bit[root->val] == 1)
    {
        if (root->left != nullptr) result.push_back(root->left);
        if (root->right != nullptr) result.push_back(root->right);
        delete root;
        return nullptr;
    }
    else
    {
        return root;
    }
}

/// <summary>
/// Leet code #1110. Delete Nodes And Return Forest
/// 
/// Given the root of a binary tree, each node in the tree has a distinct 
/// value.
///
/// After deleting all nodes with a value in to_delete, we are left with a 
/// forest (a disjoint union of trees).
///
/// Return the roots of the trees in the remaining forest.  You may return 
/// the result in any order.
/// 
/// Example 1:
///
/// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
/// Output: [[1,2,null,4],[6],[7]]
/// 
/// Constraints:
/// 1. The number of nodes in the given tree is at most 1000.
/// 2. Each node has a distinct value between 1 and 1000.
/// 3. to_delete.length <= 1000
/// 4. to_delete contains distinct values between 1 and 1000.
/// </summary>
vector<TreeNode*> LeetCodeTree::delNodes(TreeNode* root, vector<int>& to_delete)
{
    vector<int> del_bit(1001);
    for (size_t i = 0; i < to_delete.size(); i++)
    {
        del_bit[to_delete[i]] = 1;
    }
    vector<TreeNode*> result;
    root = delNodes(root, del_bit, result);
    if (root != nullptr) result.push_back(root);

    return result;
}

/// <summary>
/// Leet code #1120. Maximum Average Subtree
/// </summary>
double LeetCodeTree::maximumAverageSubtree(TreeNode* root, double& sum, int& count)
{
    if (root == nullptr)
    {
        return (double)0.0;
    }
    else
    {
        double result = 0.0;
        double left_sum = 0, right_sum = 0;
        int left_count = 0, right_count = 0;
        result = max(result, maximumAverageSubtree(root->left, left_sum, left_count));
        result = max(result, maximumAverageSubtree(root->right, right_sum, right_count));
        sum = left_sum + right_sum + root->val;
        count = left_count + right_count + 1;
        result = max(result, sum / count);
        
        return result;
    }
}

/// <summary>
/// Leet code #1120. Maximum Average Subtree
/// 
/// Given the root of a binary tree, find the maximum average value of any 
/// subtree of that tree.
/// (A subtree of a tree is any node of that tree plus all its descendants. 
/// The average value of a tree is the sum of its values, divided by the 
/// number of nodes.)
/// 
/// Example 1:
/// Input: [5,6,1]
/// Output: 6.00000
/// Explanation: 
/// For the node with value = 5 we have and average of (5 + 6 + 1) / 3 = 4.
/// For the node with value = 6 we have and average of 6 / 1 = 6.
/// For the node with value = 1 we have and average of 1 / 1 = 1.
/// So the answer is 6 which is the maximum.
/// 
/// Note:
/// 1. The number of nodes in the tree is between 1 and 5000.
/// 2. Each node will have a value between 0 and 100000.
/// 3. Answers will be accepted as correct if they are within 10^-5 of the 
///    correct answer.
/// </summary>
double LeetCodeTree::maximumAverageSubtree(TreeNode* root)
{
    double sum = 0.0;
    int count = 0;
    double result = maximumAverageSubtree(root, sum, count);
    return result;
}

/// <summary>
/// Leet code #1123. Lowest Common Ancestor of Deepest Leaves
/// </summary>
TreeNode* LeetCodeTree::lcaDeepestLeaves(TreeNode* root, int& depth)
{
    if (root == nullptr) return root;
    depth++;
    int left_depth = depth;
    TreeNode* left_ancestor = lcaDeepestLeaves(root->left, left_depth);
    int right_depth = depth;
    TreeNode* right_ancestor = lcaDeepestLeaves(root->right, right_depth);

    if (left_depth == right_depth)
    {
        depth = left_depth;
        return root;
    }
    else if (left_depth > right_depth)
    {
        depth = left_depth;
        return left_ancestor;
    }
    else
    {
        depth = right_depth;
        return right_ancestor;
    }
}

/// <summary>
/// Leet code #1123. Lowest Common Ancestor of Deepest Leaves
/// 
/// Given a rooted binary tree, return the lowest common ancestor of its 
/// deepest leaves.
/// Recall that:
/// The node of a binary tree is a leaf if and only if it has no children
/// The depth of the root of the tree is 0, and if the depth of a node is 
/// d, the depth of each of its children is d+1.
/// The lowest common ancestor of a set S of nodes is the node A with the 
/// largest depth such that every node in S is in the subtree with root A.
/// 
/// Example 1:
/// Input: root = [1,2,3]
/// Output: [1,2,3]
/// Explanation: 
/// The deepest leaves are the nodes with values 2 and 3.
/// The lowest common ancestor of these leaves is the node with value 1.
/// The answer returned is a TreeNode object (not an array) with 
/// serialization "[1,2,3]".
///
/// Example 2:
/// Input: root = [1,2,3,4]
/// Output: [4]
///
/// Example 3:
/// Input: root = [1,2,3,4,5]
/// Output: [2,4,5]
/// 
/// Constraints:
/// 1. The given tree will have between 1 and 1000 nodes.
/// 2. Each node of the tree will have a distinct value between 1 and 1000.
/// </summary>
TreeNode* LeetCodeTree::lcaDeepestLeaves(TreeNode* root)
{
    int depth = 0;
    return lcaDeepestLeaves(root, depth);
}

/// <summary>
/// Leet code #1145. Binary Tree Coloring Game
/// </summary>
int LeetCodeTree::btreeGameWinningMove(TreeNode* root, int &curr, int &left, int &right, int x)
{
    if (root == nullptr) return 0;

    int left_sum = btreeGameWinningMove(root->left, curr, left, right, x);
    int right_sum = btreeGameWinningMove(root->right, curr, left, right, x);
    int sum = 1;
    sum += left_sum + right_sum;
    if (root->val == x)
    {
        left = left_sum;
        right = right_sum;
        curr = sum;
    }
    return sum;
}

/// <summary>
/// Leet code #1145. Binary Tree Coloring Game
/// 
/// Two players play a turn based game on a binary tree.  We are given the 
/// root of this binary tree, and the number of nodes n in the tree.  n is 
/// odd, and each node has a distinct value from 1 to n.
///
/// Initially, the first player names a value x with 1 <= x <= n, and the 
/// second player names a value y with 1 <= y <= n and y != x.  The first 
/// player colors the node with value x red, and the second player colors 
/// the node with value y blue.
///
/// Then, the players take turns starting with the first player.  In each 
/// turn, that player chooses a node of their color (red if player 1, blue 
/// if player 2) and colors an uncolored neighbor of the chosen node 
/// (either the left child, right child, or parent of the chosen node.)
///
/// If (and only if) a player cannot choose such a node in this way, they 
/// must pass their turn.  If both players pass their turn, the game ends, 
/// and the winner is the player that colored more nodes.
///
/// You are the second player.  If it is possible to choose such a y to 
/// ensure you win the game, return true.  If it is not possible, return 
/// false.
///
/// Example 1:
/// 
/// Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
/// Output: true
/// Explanation: The second player can choose the node with value 2.
/// 
///
/// Constraints:
/// 
/// 1. root is the root of a binary tree with n nodes and distinct node 
///    values from 1 to n.
/// 2. n is odd.
/// 3. 1 <= x <= n <= 100
/// </summary>
bool LeetCodeTree::btreeGameWinningMove(TreeNode* root, int n, int x)
{
    int curr = 0;
    int left = 0;
    int right = 0;
    btreeGameWinningMove(root, curr, left, right, x);
    if (left > n - left || right > n - right || n - curr > curr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #1161. Maximum Level Sum of a Binary Tree
/// 
/// Given the root of a binary tree, the level of its root is 1, the level 
/// of its children is 2, and so on.
/// Return the smallest level X such that the sum of all the values of nodes 
/// at level X is maximal.
/// 
/// Example 1:
///
/// Input: [1,7,0,7,-8,null,null]
/// Output: 2
/// Explanation: 
/// Level 1 sum = 1.
/// Level 2 sum = 7 + 0 = 7.
/// Level 3 sum = 7 + -8 = -1.
/// So we return the level with the maximum sum which is level 2.
/// 
/// Note:
/// 1. The number of nodes in the given tree is between 1 and 10^4.
/// 2. -10^5 <= node.val <= 10^5
/// </summary>
int LeetCodeTree::maxLevelSum(TreeNode* root)
{
    int max_sum = INT_MIN;
    queue<TreeNode*> search;
    search.push(root);
    int level = 0;
    int result = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        level++;
        int sum = 0;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = search.front();
            search.pop();
            if (node == nullptr) continue;
            sum += node->val;
            search.push(node->left);
            search.push(node->right);
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            result = level;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1214. Two Sum BSTs      
///
/// Given two binary search trees, return True if and only if there is a 
/// node in the first tree and a node in the second tree whose values 
/// sum up to a given integer target.
/// 
/// Example 1:
///
/// Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
/// Output: true
/// Explanation: 2 and 3 sum up to 5.
///
/// Example 2:
///
/// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
/// Output: false
/// 
/// Constraints:
/// 1. Each tree has at most 5000 nodes.
/// 2. -10^9 <= target, node.val <= 10^9
/// </summary>
bool LeetCodeTree::twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
{
    int result = false;
    queue<TreeNode*> search;
    search.push(root1);

    while (!search.empty())
    {
        TreeNode* node = search.front();
        search.pop();
        if (node == nullptr) continue;
        search.push(node->left);
        search.push(node->right);

        int num = target - node->val;

        node = root2;
        while (node != nullptr)
        {
            if (node->val == num) return true;
            else if (node->val < num)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }
    return false;
}

/// <summary>
/// Decodes your encoded data to tree.
/// </summary>
/// <param name="data">the string data</param>
/// <returns>The root</returns>
TreeNode* LeetCodeTree::deserialize(string data)
{
    queue<TreeNode*> input_queue;
    queue<TreeNode*> output_queue;
    string number;
    for (size_t i = 0; i < data.size(); i++)
    {
        if ((data[i] == '[') || (data[i] == ',') || data[i] == ']' ||
            isspace(data[i]))
        {
            if (number.size() != 0)
            {
                if (number == "null")
                {
                    input_queue.push(nullptr);
                }
                else if ((number[0] >= 'a' && number[0] <= 'z') ||
                         (number[0] == '+' || number[0] == '-'))
                {
                    input_queue.push(new TreeNode(number[0]));
                }
                else
                {
                    input_queue.push(new TreeNode(std::stoi(number)));
                }
                number.clear();
            }
        }
        else
        {
            number.push_back(data[i]);
        }
    }
    TreeNode* root = nullptr;
    TreeNode* node = nullptr;
    while (!input_queue.empty())
    {
        if (output_queue.empty())
        {
            root = input_queue.front();
            input_queue.pop();
            node = root;
            output_queue.push(node);
        }
        else
        {
            node = output_queue.front();
            output_queue.pop();
            if (node != nullptr)
            {
                if (!input_queue.empty())
                {
                    node->left = input_queue.front();
                    if (node->left != nullptr) node->left->parent = node;
                    input_queue.pop();
                }
                if (!input_queue.empty())
                {
                    node->right = input_queue.front();
                    if (node->right != nullptr) node->right->parent = node;
                    input_queue.pop();
                }
                output_queue.push(node->left);
                output_queue.push(node->right);
            }
        }
    }
    return root;
}

/// <summary>
/// Leetcode #1305. All Elements in Two Binary Search Trees
///
/// Medium
///
/// Given two binary search trees root1 and root2.
/// Return a list containing all the integers from both trees sorted in 
/// ascending order.
/// 
/// Example 1:
/// Input: root1 = [2,1,4], root2 = [1,0,3]
/// Output: [0,1,1,2,3,4]
///
/// Example 2:
/// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
/// Output: [-10,0,0,1,2,5,7,10]
///
/// Example 3:
/// Input: root1 = [], root2 = [5,1,7,0,2]
/// Output: [0,1,2,5,7]
///
/// Example 4:
/// Input: root1 = [0,-10,10], root2 = []
/// Output: [-10,0,10]
///
/// Example 5:
/// Input: root1 = [1,null,8], root2 = [8,1]
/// Output: [1,1,8,8]
///
/// Constraints:
/// 1. Each tree has at most 5000 nodes.
/// 2. Each node's value is between [-10^5, 10^5].
/// </summary>
vector<int> LeetCodeTree::getAllElements(TreeNode* root1, TreeNode* root2)
{
    vector<int> result;
    queue<TreeNode*> search;
    search.push(root1);
    while (!search.empty())
    {
        TreeNode* node = search.front();
        search.pop();
        if (node == nullptr) continue;
        result.push_back(node->val);
        search.push(node->left);
        search.push(node->right);
    }
    search.push(root2);
    while (!search.empty())
    {
        TreeNode* node = search.front();
        search.pop();
        if (node == nullptr) continue;
        result.push_back(node->val);
        search.push(node->left);
        search.push(node->right);
    }
    sort(result.begin(), result.end());
    return result;
}

/// <summary>
/// Leetcode #1302. Deepest Leaves Sum
///
/// Medium
///
/// Given a binary tree, return the sum of values of its deepest leaves.
/// 
/// Example 1:
///
/// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
/// Output: 15
/// 
/// Constraints:
/// 1. The number of nodes in the tree is between 1 and 10^4.
/// 2. The value of nodes is between 1 and 100.
/// </summary>
int LeetCodeTree::deepestLeavesSum(TreeNode* root)
{
    queue<TreeNode*> search;
    search.push(root);
    int result = 0;

    while (!search.empty())
    {
        size_t size = search.size();
        result = 0;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = search.front();
            search.pop();
            result += node->val;
            if (node->left != nullptr) search.push(node->left);
            if (node->right != nullptr) search.push(node->right);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1315. Sum of Nodes with Even-Valued Grandparent
///
/// Medium
///
/// Given a binary tree, return the sum of values of nodes with 
/// even-valued grandparent.  (A grandparent of a node is the parent 
/// of its parent, if it exists.)
/// If there are no nodes with an even-valued grandparent, return 0.
/// 
/// Example 1:
///
/// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
/// Output: 18
/// Explanation: The red nodes are the nodes with even-value grandparent 
/// while the blue nodes are the even-value grandparents.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is between 1 and 10^4.
/// 2. The value of nodes is between 1 and 100.
/// </summary>
int LeetCodeTree::sumEvenGrandparent(TreeNode* root)
{
    queue<vector<TreeNode*>> search;
    vector<TreeNode*> node = { nullptr, nullptr, root };
    search.push(node);
    
    int result = 0;
    while (!search.empty())
    {
        node = search.front();
        search.pop();

        if ((node[0] != nullptr) && (node[0]->val % 2 == 0))
        {
            result += node[2]->val;
        }

        node[0] = node[1];
        node[1] = node[2];
        node[2] = node[1]->left;
        if (node[2] != nullptr)
        {
            search.push(node);
        }
        node[2] = node[1]->right;
        if (node[2] != nullptr)
        {
            search.push(node);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1325. Delete Leaves With a Given Value
///
/// Medium
///
/// Given a binary tree root and an integer target, delete all the leaf 
/// nodes with value target.
///
/// Note that once you delete a leaf node with value target, if it's 
/// parent node becomes a leaf node and has the value target, it should 
/// also be deleted (you need to continue doing that until you can't).
/// 
/// Example 1:
/// Input: root = [1,2,3,2,null,2,4], target = 2
/// Output: [1,null,3,null,4]
/// Explanation: Leaf nodes in green with value (target = 2) are removed 
/// (Picture in left). 
/// After removing, new nodes become leaf nodes with value (target = 2) 
/// (Picture in center).
///
/// Example 2:
/// Input: root = [1,3,3,3,2], target = 3
/// Output: [1,3,null,null,2]
///
/// Example 3:
/// Input: root = [1,2,null,2,null,2], target = 2
/// Output: [1]
/// Explanation: Leaf nodes in green with value (target = 2) are removed 
/// at each step.
/// 
/// Example 4:
/// Input: root = [1,1,1], target = 1
/// Output: []
///
/// Example 5:
/// Input: root = [1,2,3], target = 1
/// Output: [1,2,3]
/// 
/// Constraints:
/// 1. 1 <= target <= 1000
/// 2. Each tree has at most 3000 nodes.
/// 3. Each node's value is between [1, 1000].
/// </summary>
TreeNode* LeetCodeTree::removeLeafNodes(TreeNode* root, int target)
{
    if (root == nullptr) return root;
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->val == target)
        {
            return nullptr;
        }
    }
    return root;
}

/// <summary>
/// Leet code #1343. Maximum Product of Splitted Binary Tree 
/// </summary>
long long LeetCodeTree::maxProduct(TreeNode* root, long long sum, long long &result)
{
    if (root == nullptr) return 0;
    long long left = maxProduct(root->left, sum, result);
    result = max(left * (sum - left), result);
    long long right = maxProduct(root->right, sum, result);
    result = max(right * (sum - right), result);
    return left + right + root->val;
}

/// <summary>
/// Leet code #1339. Maximum Product of Splitted Binary Tree 
/// 
/// Medium
///
/// Given a binary tree root. Split the binary tree into two subtrees by 
/// removing 1 edge such that the product of the sums of the subtrees are 
/// maximized.
///
/// Since the answer may be too large, return it modulo 10^9 + 7.
///
/// Example 1:
/// Input: root = [1,2,3,4,5,6]
/// Output: 110
/// Explanation: Remove the red edge and get 2 binary trees with sum 11 
/// and 10. Their product is 110 (11*10)
///
/// Example 2:
/// Input: root = [1,null,2,3,4,null,null,5,6]
/// Output: 90
/// Explanation:  Remove the red edge and get 2 binary trees with sum 15 
/// and 6.Their product is 90 (15*6)
/// 
/// Example 3:
/// Input: root = [2,3,9,10,7,8,6,5,4,11,1]
/// Output: 1025
///
/// Example 4:
/// Input: root = [1,1]
/// Output: 1
/// 
/// Constraints:
/// 1. Each tree has at most 50000 nodes and at least 2 nodes.
/// 2. Each node's value is between [1, 10000].
/// </summary>
int LeetCodeTree::maxProduct(TreeNode* root)
{
    long long sum = 0;
    queue<TreeNode *> q;
    q.push(root);
    
    while (!q.empty())
    {
        TreeNode * node = q.front();
        q.pop();
        sum += node->val;
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }

    long long M = 1000000007;
    long long result = 0;
    maxProduct(root, sum, result);
    
    return (int)(result % M);
}

/// <summary>
/// Leet code #1367. Linked List in Binary Tree
/// </summary>
bool LeetCodeTree::isSubPath(ListNode* head, TreeNode* root, vector<ListNode *> &lead)
{
    if (root == nullptr) return false;
    if (lead.empty()) return false;
    vector<ListNode *> next;
    for (size_t i = 0; i < lead.size(); i++)
    {
        if (lead[i]->val == root->val)
        {
            if (lead[i]->next == nullptr)
            {
                return true;
            }
            else
            {
                next.push_back(lead[i]->next);
            }
        }
    }
    next.push_back(head);
    return isSubPath(head, root->left, next) || isSubPath(head, root->right, next);
}

/// <summary>
/// Leet code #1367. Linked List in Binary Tree
///
/// Medium
///
/// Given a binary tree root and a linked list with head as the first node.
///	
/// Return True if all the elements in the linked list starting from the 
/// head correspond to some downward path connected in the binary tree 
/// otherwise return False.
///
/// In this context downward path means a path that starts at some node 
/// and goes downwards.
///
/// Example 1:
/// Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,
/// null,null,null,1,3]
/// Output: true
/// Explanation: Nodes in blue form a subpath in the binary Tree.  
///
/// Example 2:
/// Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,
/// null,null,null,null,1,3]
/// Output: true
///
/// Example 3:
/// Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,
/// null,null,null,null,1,3]
/// Output: false
/// Explanation: There is no path in the binary tree that contains all 
/// the elements of the linked list from head.
///
/// Constraints:
/// 1. 1 <= node.val <= 100 for each node in the linked list and binary 
///    tree.
/// 2. The given linked list will contain between 1 and 100 nodes.
/// 3. The given binary tree will contain between 1 and 2500 nodes.
/// </summary>
bool LeetCodeTree::isSubPath(ListNode* head, TreeNode* root)
{
    vector<ListNode*> next;
    next.push_back(head);
    return isSubPath(head, root, next);
}

/// <summary>
/// Leet code #1372. Longest ZigZag Path in a Binary Tree
///  
/// Medium
///
/// Given a binary tree root, a ZigZag path for a binary tree is defined 
/// as follow:
///
/// Choose any node in the binary tree and a direction (right or left).
/// If the current direction is right then move to the right child of the 
/// current node otherwise move to the left child.
/// Change the direction from right to left or right to left.
/// Repeat the second and third step until you can't move in the tree.
/// Zigzag length is defined as the number of nodes visited - 1. 
/// (A single node has a length of 0).
///
/// Return the longest ZigZag path contained in that tree.
///
/// Example 1:
/// Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,
/// 1,null,1]
/// Output: 3
/// Explanation: Longest ZigZag path in blue nodes 
/// (right -> left -> right).
/// 
/// Example 2:
/// Input: root = [1,1,1,null,1,null,null,1,1,null,1]
/// Output: 4
/// Explanation: Longest ZigZag path in blue nodes (left -> right -> 
/// left -> right).
///
/// Example 3:
/// Input: root = [1]
/// Output: 0
/// 
/// Constraints:
/// 1. Each tree has at most 50000 nodes..
/// 2. Each node's value is between [1, 100].
/// </summary>
int LeetCodeTree::longestZigZag(TreeNode* root)
{
    queue<pair<TreeNode *, pair<int, int>>> queue;
    queue.push(make_pair(root, make_pair( -1, 0 )));

    int result = 0;
    while (!queue.empty())
    {
        pair<TreeNode *, pair<int, int>> node = queue.front();
        queue.pop();
        result = max(result, node.second.second);
        TreeNode * left = node.first->left;
        if (left != nullptr)
        {
            if (node.second.first == 0)
            {
                queue.push(make_pair(left, make_pair(0, 1)));
            }
            else
            {
                queue.push(make_pair(left, make_pair(0, node.second.second + 1)));
            }
        }
        TreeNode * right = node.first->right;
        if (right != nullptr)
        {
            if (node.second.first == 1)
            {
                queue.push(make_pair(right, make_pair(1, 1)));
            }
            else
            {
                queue.push(make_pair(right, make_pair(1, node.second.second + 1)));
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1373. Maximum Sum BST in Binary Tree
/// </summary>
int LeetCodeTree::maxSumBST(TreeNode* root, int &min_val, int&max_val, bool &is_bst, int &max_sum)
{
    int sum = 0;

    if (root == nullptr)
    {
        max_sum = 0;
        return sum;
    }
    if (root->left != nullptr)
    {
        int left_min = INT_MAX;
        int left_max = INT_MIN;
        bool left_is_bst = true;
        int left_max_sum = 0;
        int left_sum = maxSumBST(root->left, left_min, left_max, left_is_bst, left_max_sum);
        is_bst = is_bst && left_is_bst && (left_max < root->val);
        max_sum = max(max_sum, left_max_sum);
        min_val = min(min_val, left_min);
        max_val = max(max_val, left_max);
        sum += left_sum;
    }
    if (root->right != nullptr)
    {
        int right_min = INT_MAX;
        int right_max = INT_MIN;
        bool right_is_bst = true;
        int right_max_sum = 0;
        int right_sum = maxSumBST(root->right, right_min, right_max, right_is_bst, right_max_sum);
        is_bst = is_bst && right_is_bst && (right_min > root->val);
        max_sum = max(max_sum, right_max_sum);
        min_val = min(min_val, right_min);
        max_val = max(max_val, right_max);
        sum += right_sum;
    }
    sum += root->val;
    min_val = min(min_val, root->val);
    max_val = max(max_val, root->val);
    if (is_bst)
    {
        max_sum = max(max_sum, sum);
    }
    return sum;
}

/// <summary>
/// Leet code #1373. Maximum Sum BST in Binary Tree
///  
/// Hard
///
/// Given a binary tree root, the task is to return the maximum sum 
/// of all keys of any sub-tree which is also a Binary Search Tree (BST).
///
/// Assume a BST is defined as follows:
/// 
/// The left subtree of a node contains only nodes with keys less than 
/// the node's key.
/// The right subtree of a node contains only nodes with keys greater 
/// than the node's key.
/// Both the left and right subtrees must also be binary search trees.
///
/// Example 1:
/// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
/// Output: 20
/// Explanation: Maximum sum in a valid Binary search tree is obtained 
/// in root node with key equal to 3.
///
/// Example 2:
/// Input: root = [4,3,null,1,2]
/// Output: 2
/// Explanation: Maximum sum in a valid Binary search tree is obtained 
/// in a single root node with key equal to 2.
///
/// Example 3:
/// Input: root = [-4,-2,-5]
/// Output: 0
/// Explanation: All values are negatives. Return an empty BST.
///
/// Example 4:
/// Input: root = [2,1,3]
/// Output: 6
///
/// Example 5:
///
/// Input: root = [5,4,8,3,null,6,3]
/// Output: 7
/// Constraints:
/// 1. Each tree has at most 40000 nodes..
/// 2. Each node's value is between [-4 * 10^4 , 4 * 10^4].
/// </summary>
int LeetCodeTree::maxSumBST(TreeNode* root)
{
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    bool is_bst = true;
    int max_sum = 0;
    maxSumBST(root, min_val, max_val, is_bst, max_sum);
    return max_sum;
}

/// <summary>
/// Leet code #1379. Find a Corresponding Node of a Binary Tree in a 
///                  Clone of That Tree
///
/// Medium
///
/// Given two binary trees original and cloned and given a reference to a 
/// node target in the original tree.
///
/// The cloned tree is a copy of the original tree.
///
/// Return a reference to the same node in the cloned tree.
/// 
/// Note that you are not allowed to change any of the two trees or the 
/// target node and the answer must be a reference to a node in the cloned 
/// tree.
///
/// Follow up: Solve the problem if repeated values on the tree are 
/// allowed.
/// 
/// Example 1:
/// Input: tree = [7,4,3,null,null,6,19], target = 3
/// Output: 3
/// Explanation: In all examples the original and cloned trees are shown. 
/// The target node is a green node from the original tree. The answer is 
/// the yellow node from the cloned tree.
///
/// Example 2:
/// Input: tree = [7], target =  7
/// Output: 7
///
/// Example 3:
/// Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
/// Output: 4
///
/// Example 4:
/// Input: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
/// Output: 5
///
/// Example 5:
/// Input: tree = [1,2,null,3], target = 2
/// Output: 2
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^4].
/// 2. The values of the nodes of the tree are unique.
/// 3. target node is a node from the original tree and is not null.
/// </summary>
TreeNode* LeetCodeTree::getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
{
    queue<TreeNode*> queue;
    queue.push(original);
    queue.push(cloned);
    while (!queue.empty())
    {
        TreeNode * node = queue.front();
        queue.pop();
        TreeNode * result = queue.front();
        queue.pop();
        if (node == target) return result;
        if (node->left != nullptr)
        {
            queue.push(node->left);
            queue.push(result->left);
        }
        if (node->right != nullptr)
        {
            queue.push(node->right);
            queue.push(result->right);
        }
    }
    return nullptr;
}

/// <summary>
/// Leet code #1382. Balance a Binary Search Tree
/// </summary>
void LeetCodeTree::balanceBST(TreeNode* root, vector<TreeNode *> &node_list)
{
    if (root == nullptr) return;
    balanceBST(root->left, node_list);
    node_list.push_back(root);
    balanceBST(root->right, node_list);
}

/// <summary>
/// Leet code #1382. Balance a Binary Search Tree
/// </summary>
TreeNode * LeetCodeTree::balanceBST(vector<TreeNode *> &node_list, int start, int end)
{
    if (start > end) return nullptr;
    int middle = start + (end - start) / 2;
    TreeNode * root = node_list[middle];
    root->left = balanceBST(node_list, start, middle - 1);
    root->right = balanceBST(node_list, middle + 1, end);
    return root;
}

/// <summary>
/// Leet code #1382. Balance a Binary Search Tree
///
/// Medium
///
/// Given a binary search tree, return a balanced binary search tree with 
/// the same node values.
///
/// A binary search tree is balanced if and only if the depth of the two 
/// subtrees of every node never differ by more than 1.
///
/// If there is more than one answer, return any of them.
/// 
/// Example 1:
/// Input: root = [1,null,2,null,3,null,4,null,null]
/// Output: [2,1,3,null,null,null,4]
/// Explanation: This is not the only correct answer, 
/// [3,1,4,null,2,null,null] is also correct.
///
/// 
/// Constraints:
/// 1. The number of nodes in the tree is between 1 and 10^4.
/// 2. The tree nodes will have distinct values between 1 and 10^5.
/// </summary>
TreeNode* LeetCodeTree::balanceBST(TreeNode* root)
{
    vector<TreeNode *> node_list;
    balanceBST(root, node_list);
    return balanceBST(node_list, 0, node_list.size() - 1);
}

/// <summary>
/// Leet code #1430. Check If a String Is a Valid Sequence from Root to 
////                 Leaves Path in a Binary Tree
/// </summary>
bool LeetCodeTree::isValidSequence(TreeNode* root, vector<int>& arr, int pos)
{
    if (root == nullptr) return false;
    if (pos == arr.size()) return false;

    if (root->val != arr[pos]) return false;
    if (pos == arr.size() - 1)
    {
        return (root->left == nullptr && root->right == nullptr);
    }
    return (isValidSequence(root->left, arr, pos + 1) || isValidSequence(root->right, arr, pos + 1));
}

/// <summary>
/// Leet code #1430. Check If a String Is a Valid Sequence from Root to 
///                  Leaves Path in a Binary Tree
/// 
/// Medium
///
/// Given a binary tree where each path going from the root to any leaf 
/// form a valid sequence, check if a given string is a valid sequence 
/// in such binary tree. 
///
/// We get the given string from the concatenation of an array of integers 
/// arr and the concatenation of all values of the nodes along a path 
/// results in a sequence in the given binary tree.
///
/// Example 1:
/// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
/// Output: true
/// Explanation: 
/// The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the 
/// figure). 
/// Other valid sequences are: 
/// 0 -> 1 -> 1 -> 0 
/// 0 -> 0 -> 0
///
/// Example 2:
/// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,0,1]
/// Output: false 
/// Explanation: The path 0 -> 0 -> 1 does not exist, therefore it is not 
/// even a sequence.
///
/// Example 3:
/// Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,1]
/// Output: false
/// Explanation: The path 0 -> 1 -> 1 is a sequence, but it is not a 
/// valid sequence.
///
/// Constraints:
/// 1. 1 <= arr.length <= 5000
/// 2. 0 <= arr[i] <= 9
/// 3. Each node's value is between [0 - 9].
/// </summary>
bool LeetCodeTree::isValidSequence(TreeNode* root, vector<int>& arr)
{
    return isValidSequence(root, arr, 0);
}

/// <summary>
/// Leet code #1448. Count Good Nodes in Binary Tree
///
/// Medium
///
/// Given a binary tree root, a node X in the tree is named good if in 
/// the path from root to X there are no nodes with a value greater 
/// than X.
///
/// Return the number of good nodes in the binary tree.
///
/// Example 1:
/// Input: root = [3,1,4,3,null,1,5]
/// Output: 4
/// Explanation: Nodes in blue are good.
/// Root Node (3) is always a good node.
/// Node 4 -> (3,4) is the maximum value in the path starting from 
///                 the root.
/// Node 5 -> (3,4,5) is the maximum value in the path
/// Node 3 -> (3,1,3) is the maximum value in the path.
///
/// Example 2:
/// Input: root = [3,3,null,4,2]
/// Output: 3
/// Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher 
/// than it.
///
/// Example 3:
/// Input: root = [1]
/// Output: 1
/// Explanation: Root is considered as good.
/// Constraints:
/// 1. The number of nodes in the binary tree is in the range [1, 10^5].
/// 2. Each node's value is between [-10^4, 10^4].
/// </summary>
int LeetCodeTree::goodNodes(TreeNode* root)
{
    int result = 0;
    queue<pair<int, TreeNode*>> search;
    search.push(make_pair(root->val, root));
    while (!search.empty())
    {
        pair<int, TreeNode*> pos = search.front();
        search.pop();
        int max_val = pos.first;
        TreeNode* node = pos.second;
        if (max_val <= node->val) result++;
        if (node->left != nullptr)
        {
            search.push(make_pair(max(node->left->val, max_val), node->left));
        }
        if (node->right != nullptr)
        {
            search.push(make_pair(max(node->right->val, max_val), node->right));
        }
    }
    return result;
}

/// <summary>
/// Leet code #1457. Pseudo-Palindromic Paths in a Binary Tree
/// </summary>
int LeetCodeTree::pseudoPalindromicPaths(TreeNode* root, unordered_map<int, int>& num_map)
{
    int result = 0;
    if (root == nullptr) return result;
    num_map[root->val]++;
    if (root->left == nullptr && root->right == nullptr)
    {
        int odd = 0;
        int even = 0;
        for (auto itr : num_map)
        {
            if (itr.second % 2 == 0) even++;
            else odd++;
        }
        if (odd <= 1) result++;
    }
    
    if (root->left != nullptr)
    {
        result += pseudoPalindromicPaths(root->left, num_map);
    }
    if (root->right != nullptr)
    {
        result += pseudoPalindromicPaths(root->right, num_map);
    }
    num_map[root->val]--;
    
    if (num_map[root->val] == 0) num_map.erase(root->val);

    return result;
}

/// <summary>
/// Leet code #1457. Pseudo-Palindromic Paths in a Binary Tree
///                
/// Medium
/// 
/// Given a binary tree where node values are digits from 1 to 9. A 
/// path in the binary tree is said to be pseudo-palindromic if at 
/// least one permutation of the node values in the path is a palindrome.
/// Return the number of pseudo-palindromic paths going from the root 
/// node to leaf nodes.
///
/// Example 1:
/// Input: root = [2,3,1,3,1,null,1]
/// Output: 2 
/// Explanation: The figure above represents the given binary tree. 
/// There are three paths going from the root node to leaf nodes: 
/// the red path [2,3,3], the green path [2,1,1], and the 
/// path [2,3,1]. Among these paths only red path and green path 
/// are pseudo-palindromic paths since the red path [2,3,3] can be 
/// rearranged in [3,2,3] (palindrome) and the green path [2,1,1] 
/// can be rearranged in [1,2,1] (palindrome).
///
/// Example 2:
/// Input: root = [2,1,1,1,3,null,null,null,null,null,1]
/// Output: 1 
/// Explanation: The figure above represents the given binary tree. 
/// There are three paths going from the root node to leaf nodes: 
/// the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. 
/// Among these paths only the green path is pseudo-palindromic 
/// since [2,1,1] can be rearranged in [1,2,1] (palindrome).
///
/// Example 3:
/// Input: root = [9]
/// Output: 1
///
/// Constraints:
/// 1. The given binary tree will have between 1 and 10^5 nodes.
/// 2. Node values are digits from 1 to 9.
/// </summary>
int LeetCodeTree::pseudoPalindromicPaths(TreeNode* root)
{
    unordered_map<int, int> num_map;
    return pseudoPalindromicPaths(root, num_map);
}

/// <summary>
/// Leet code #1469. Find All the Lonely Nodes
///                
/// Easy
/// 
/// In a binary tree, a lonely node is a node that is the only child 
/// of its parent node. The root of the tree is not lonely because 
/// it does not have a parent node.
///
/// Given the root of a binary tree, return an array containing the 
/// values of all lonely nodes in the tree. Return the list in any order.
///
/// Example 1:
/// Input: root = [1,2,3,null,4]
/// Output: [4]
/// Explanation: Light blue node is the only lonely node.
/// Node 1 is the root and is not lonely.
/// Nodes 2 and 3 have the same parent and are not lonely.
///
/// Example 2:
/// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2]
/// Output: [6,2]
/// Explanation: Light blue nodes are lonely nodes.
/// Please remember that order doesn't matter, [2,6] is also an 
/// acceptable answer.
///
/// Example 3:
/// Input: root = [11,99,88,77,null,null,66,55,null,null,44,33,null,
///                null,22]
/// Output: [77,55,33,66,44,22]
/// Explanation: Nodes 99 and 88 share the same parent. Node 11 is the 
/// root.
/// All other nodes are lonely.
///
/// Example 4:
/// Input: root = [197]
/// Output: []
///
/// Example 5:
/// Input: root = [31,null,78,null,28]
/// Output: [78,28]
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 1000].
/// 2. Each node's value is between [1, 10^6].
/// </summary>
vector<int> LeetCodeTree::getLonelyNodes(TreeNode* root)
{
    vector<int> result;
    queue<pair<TreeNode*, int>> search;
    search.push(make_pair(root, 0));

    while (!search.empty())
    {
        TreeNode* node = search.front().first;
        int state = search.front().second;
        search.pop();
        if (node == nullptr) continue;
        if (state == 1) result.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            continue;
        }
        else if (node->left == nullptr)
        {
            search.push(make_pair(node->right, 1));
        }
        else if (node->right == nullptr)
        {
            search.push(make_pair(node->left, 1));
        }
        else if (node->left != nullptr && node->right != nullptr)
        {
            search.push(make_pair(node->left, 2));
            search.push(make_pair(node->right, 2));
        }
    }
    return result;
}

/// <summary>
/// Leet code #1485. Clone Binary Tree With Random Pointer
/// </summary> 
TreeNode* LeetCodeTree::cloneRandomBinaryTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map)
{
    if (root == nullptr) return nullptr;
    
    TreeNode* node = new TreeNode(root->val);
    map[root] = node;
    node->left = cloneRandomBinaryTree(root->left, map);
    node->right = cloneRandomBinaryTree(root->right, map);
    return node;
}

/// <summary>
/// Leet code #1485. Clone Binary Tree With Random Pointer
/// </summary> 
TreeNode* LeetCodeTree::setRandomBinaryTree(TreeNode* root, TreeNode* clone, unordered_map<TreeNode*, TreeNode*>& map)
{
    if (clone == nullptr) return clone;
    if (root->random != nullptr) clone->random = map[root->random];
    setRandomBinaryTree(root->left, clone->left, map);
    setRandomBinaryTree(root->right, clone->right, map);
    return clone;
}

/// <summary>
/// Leet code #1485. Clone Binary Tree With Random Pointer
///
/// Medium
///
/// A binary tree is given such that each node contains an additional 
/// random pointer which could point to any node in the tree or null.
///
/// Return a deep copy of the tree.
///
/// The tree is represented in the same input/output way as normal 
/// binary trees where each node is represented as a pair of 
/// [val, random_index] where:
///
/// val: an integer representing Node.val
/// random_index: the index of the node (in the input) where the 
/// random pointer points to, or null if it does not point to any node.
/// You will be given the tree in class Node and you should return the 
/// cloned tree in class NodeCopy. NodeCopy class is just a clone of 
/// Node class with the same attributes and constructors.
/// 
/// Example 1:
/// Input: root = [[1,null],null,[4,3],[7,0]]
/// Output: [[1,null],null,[4,3],[7,0]]
/// Explanation: The original binary tree is [1,null,4,7].
/// The random pointer of node one is null, so it is represented 
/// as [1, null].
/// The random pointer of node 4 is node 7, so it is represented as [4, 3] 
/// where 3 is the index of node 7 in the array representing the tree.
/// The random pointer of node 7 is node 1, so it is represented as [7, 0] 
/// where 0 is the index of node 1 in the array representing the tree.
///
/// Example 2:
/// Input: root = [[1,4],null,[1,0],null,[1,5],[1,5]]
/// Output: [[1,4],null,[1,0],null,[1,5],[1,5]]
/// Explanation: The random pointer of a node can be the node itself.
///
/// Example 3:
/// Input: root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
/// Output: [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
///
/// Example 4:
/// Input: root = []
/// Output: []
///
/// Example 5:
/// Input: root = [[1,null],null,[2,null],null,[1,null]]
/// Output: [[1,null],null,[2,null],null,[1,null]]
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [0, 1000].
/// 2. Each node's value is between [1, 10^6].
/// </summary> 
TreeNode* LeetCodeTree::copyRandomBinaryTree(TreeNode* root)
{
    unordered_map<TreeNode*, TreeNode*> map;
    TreeNode * result = cloneRandomBinaryTree(root, map);
    setRandomBinaryTree(root, result, map);
    return result;
}

/// <summary>
/// Leet code #1490. Clone N-ary Tree
/// 
/// Medium
///
/// Given a root of an N-ary tree, return a deep copy (clone) of the tree.
///
/// Each node in the n-ary tree contains a val (int) and a list (List[Node]) 
/// of its children.
///
/// class Node {
///     public int val;
///     public List<Node> children;
/// }
/// Nary-Tree input serialization is represented in their level order 
/// traversal, each group of children is separated by the null value 
/// (See examples).
///
/// Follow up: Can your solution work for the graph problem?
/// 
/// Example 1:
/// Input: root = [1,null,3,2,4,null,5,6]
/// Output: [1,null,3,2,4,null,5,6]
/// Example 2:
/// 
/// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,
///  null,null,11,null,12,null,13,null,null,14]
/// Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,
/// 11,null,12,null,13,null,null,14]
/// 
/// Constraints:
/// 1. The depth of the n-ary tree is less than or equal to 1000.
/// 2. The total number of nodes is between [0, 10^4].
/// </summary>
Node* LeetCodeTree::cloneTree(Node* root)
{
    if (root == nullptr) return nullptr;
    Node* node = new Node();
    node->val = root->val;
    for (size_t i = 0; i < root->children.size(); i++)
    {
        node->children.push_back(cloneTree(root->children[i]));
    }
    return node;
}

/// <summary>
/// Leet code #1506. Find Root of N-Ary Tree
/// 
/// Medium
///
/// Given all the nodes of an N-ary tree as an array  Node[] tree where 
/// each node has a unique value.
///
/// Find and return the root of the N-ary tree.
/// 
/// Follow up:
/// Could you solve this problem in constant space complexity with a 
/// linear time algorithm?
///
/// Nary-Tree input serialization is represented in their level order 
/// traversal, each group of children is separated by the null value 
/// (See examples).
/// 
/// For example, the above tree is serialized as [1,null,2,3,4,5,null,
/// null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].
///
/// Custom testing:
/// 1. You should provide the serialization of the input tree.
/// 2. The Driver code then extracts the nodes from the tree and 
///    shuffles them. You shouldn't care how the extracted nodes are 
///    shuffled.
/// 3. The driver code will provide you with an array of the extracted 
///    nodes in random order and you need to find the root of the tree 
///    out of these nodes.
///
/// Example 1:
/// Input: tree = [1,null,3,2,4,null,5,6]
/// Output: [1,null,3,2,4,null,5,6]
/// Explanation: The input tree is shown above. The driver code first 
/// extracts the nodes so we now have an array of all tree nodes 
/// [Node(1),Node(3),Node(2),Node(4),Node(5),Node(6)], then the array 
/// is randomly shuffled, thus the actual input is [Node(5),Node(4),
/// Node(3),Node(6),Node(2),Node(1)].
/// The root of the tree is Node(1) and the output is the 
/// serialization of the node you return.
///
/// Example 2:
/// Input: tree = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,
///   null,null,11,null,12,null,13,null,null,14]
/// Output: [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,
/// null,12,null,13,null,null,14]
///
/// Constraints:
/// 1. The total number of nodes is between [1, 5 * 10^4].
/// 2. Each node has a unique value.
/// </summary>
Node* LeetCodeTree::findRoot(vector<Node*> tree)
{
    long long sum = 0;
    for (size_t i = 0; i < tree.size(); i++)
    {
        sum += tree[i]->val;
    }
    for (size_t i = 0; i < tree.size(); i++)
    {
        for (size_t j = 0; j < tree[i]->children.size(); j++)
        {
            sum -= tree[i]->children[j]->val;
        }
    }
    Node* root = nullptr;
    for (size_t i = 0; i < tree.size(); i++)
    {
        if (sum == tree[i]->val)
        {
            root = tree[i];
            break;
        }
    }
    return root;
}

/// <summary>
/// Leet code #1519. Number of Nodes in the Sub-Tree With the Same Label
/// </summary>
void LeetCodeTree::countSubTrees(int node, vector<vector<int>>& links, string& labels,
    vector<int>& tag, vector<int>& result)
{
    result[node] = 0;
    for (size_t i = 0; i < links[node].size(); i++)
    {
        int child = links[node][i];
        // this must be parent;
        if (result[child] == 0) continue;
        vector<int> child_tag(26);
        countSubTrees(links[node][i], links, labels, child_tag, result);
        for (size_t j = 0; j < 26; j++)
        {
            tag[j] += child_tag[j];
        }
    }
    tag[labels[node] - 'a']++;
    result[node] = tag[labels[node] - 'a'];
}

/// <summary>
/// Leet code #1519. Number of Nodes in the Sub-Tree With the Same Label
/// 
/// Medium
///
/// Given a tree (i.e. a connected, undirected graph that has no cycles) 
/// consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 
/// edges. The root of the tree is the node 0, and each node of the tree 
/// has a label which is a lower-case character given in the string 
/// labels (i.e. The node with the number i has the label labels[i]).
///
/// The edges array is given on the form edges[i] = [ai, bi], which means 
/// there is an edge between nodes ai and bi in the tree.
///
/// Return an array of size n where ans[i] is the number of nodes in the 
/// subtree of the ith node which have the same label as node i.
///
/// A subtree of a tree T is the tree consisting of a node in T and all 
/// of its descendant nodes.
/// 
/// Example 1:
/// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], 
/// labels = "abaedcd"
/// Output: [2,1,1,1,1,1,1]
/// Explanation: Node 0 has label 'a' and its sub-tree has node 2 with 
/// label 'a' as well, thus the answer is 2. Notice that any node is 
/// part of its sub-tree.
/// Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 
/// and 5, as nodes 4 and 5 have different labels than node 1, the 
/// answer is just 1 (the node itself).
///
/// Example 2:
/// Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
/// Output: [4,2,1,1]
/// Explanation: The sub-tree of node 2 contains only node 2, so the 
/// answer is 1.
/// The sub-tree of node 3 contains only node 3, so the answer is 1.
/// The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', 
/// thus the answer is 2.
/// The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 
/// 'b', thus the answer is 4.
///
/// Example 3:
/// Input: n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
/// Output: [3,2,1,1,1]
///
/// Example 4:
/// Input: n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], 
/// labels = "cbabaa"
/// Output: [1,2,1,1,2,1]
///
/// Example 5:
/// Input: n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]],
/// labels = "aaabaaa"
/// Output: [6,5,4,1,3,2,1]
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. ai != bi
/// 6. labels.length == n
/// 7. labels is consisting of only of lower-case English letters.
/// </summary>
vector<int> LeetCodeTree::countSubTrees(int n, vector<vector<int>>& edges, string labels)
{
    vector<vector<int>> links(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        links[edges[i][0]].push_back(edges[i][1]);
        links[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> tag(26);
    vector<int> result(n, -1);
    countSubTrees(0, links, labels, tag, result);
    return result;
}

/// <summary>
/// Leet code #1530. Number of Good Leaf Nodes Pairs
/// </summary>
vector<int> LeetCodeTree::countPairs(TreeNode* root, int depth, int distance, int& result)
{
    vector<int> children;
    if (root == nullptr) return children;
    if (root->left == nullptr && root->right == nullptr)
    {
        children.push_back(depth);
    }
    else if (root->left == nullptr)
    {
        children = countPairs(root->right, depth + 1, distance, result);
    }
    else if (root->right == nullptr)
    {
        children = countPairs(root->left, depth + 1, distance, result);
    }
    else
    {
        vector<int> left_children = countPairs(root->left, depth + 1, distance, result);
        vector<int> right_children = countPairs(root->right, depth + 1, distance, result);
        for (size_t i = 0; i < left_children.size(); i++)
        {
            for (size_t j = 0; j < right_children.size(); j++)
            {
                if (left_children[i] + right_children[j] - 2 * depth <= distance)
                {
                    result++;
                }
            }
        }
        children.insert(children.end(), left_children.begin(), left_children.end());
        children.insert(children.end(), right_children.begin(), right_children.end());
    }
    return children;
}

/// <summary>
/// Leet code #1530. Number of Good Leaf Nodes Pairs
/// 
/// Medium
///
/// Given the root of a binary tree and an integer distance. A pair of two 
/// different leaf nodes of a binary tree is said to be good if the length 
/// of the shortest path between them is less than or equal to distance.
///
/// Return the number of good leaf node pairs in the tree.
///
/// Example 1: 
/// Input: root = [1,2,3,null,4], distance = 3
/// Output: 1
/// Explanation: The leaf nodes of the tree are 3 and 4 and the length 
/// of the shortest path between them is 3. This is the only good pair.
///
/// Example 2:
/// Input: root = [1,2,3,4,5,6,7], distance = 3
/// Output: 2
/// Explanation: The good pairs are [4,5] and [6,7] with shortest 
/// path = 2. The pair [4,6] is not good because the length of ther 
/// shortest path between them is 4.
///
/// Example 3:
/// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], 
/// distance = 3
/// Output: 1
/// Explanation: The only good pair is [2,5].
///
/// Example 4:
/// Input: root = [100], distance = 1
/// Output: 0
///
/// Example 5:
/// Input: root = [1,1,1], distance = 2
/// Output: 1
///  
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 2^10].
/// 2. Each node's value is between [1, 100].
/// 3. 1 <= distance <= 10
/// </summary>
int LeetCodeTree::countPairs(TreeNode* root, int distance)
{
    int result = 0;
    countPairs(root, 0, distance, result);
    return result;
}

/// <summary>
/// Leet code #1609. Even Odd Tree
/// 
/// Medium
///
/// A binary tree is named Even-Odd if it meets the following conditions:
///
/// The root of the binary tree is at level index 0, its children are at 
/// level index 1, their children are at level index 2, etc.
/// For every even-indexed level, all nodes at the level have odd integer 
/// values in strictly increasing order (from left to right).
/// For every odd-indexed level, all nodes at the level have even integer 
/// values in strictly decreasing order (from left to right).
/// Given the root of a binary tree, return true if the binary tree is 
/// Even-Odd, otherwise return false.
/// 
/// Example 1:
/// Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
/// Output: true
/// Explanation: The node values on each level are:
/// Level 0: [1]
/// Level 1: [10,4]
/// Level 2: [3,7,9]
/// Level 3: [12,8,6,2]
/// Since levels 0 and 2 are all odd and increasing, and 
/// levels 1 and 3 are all even and decreasing, the tree is 
/// Even-Odd.
///
/// Example 2:
/// Input: root = [5,4,2,3,3,7]
/// Output: false
/// Explanation: The node values on each level are:
/// Level 0: [5]
/// Level 1: [4,2]
/// Level 2: [3,3,7]
/// Node values in the level 2 must be in strictly increasing 
/// order, so the tree is not Even-Odd.
///
/// Example 3:
/// Input: root = [5,9,1,3,5,7]
/// Output: false
/// Explanation: Node values in the level 1 should be even integers.
///
/// Example 4:
/// Input: root = [1]
/// Output: true
///
/// Example 5:
/// Input: root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
/// Output: true
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 1 <= Node.val <= 10^6
/// </summary>
bool LeetCodeTree::isEvenOddTree(TreeNode* root)
{
    queue<TreeNode*> search;
    search.push(root);
    int level = 0;
    while (!search.empty())
    {
        size_t size = search.size();
        TreeNode* last = nullptr;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = search.front();
            search.pop();
            if (level % 2 == 0)
            {
                if (node->val % 2 == 0) return false;
                if (i > 0 && node->val <= last->val) return false;
            }
            else
            {
                if (node->val % 2 == 1) return false;
                if (i > 0 && node->val >= last->val) return false;
            }
            last = node;
            if (node->left != nullptr) search.push(node->left);
            if (node->right != nullptr) search.push(node->right);
        }
        level++;
    }
    return true;
}

/// <summary>
/// Leet code #1612. Check If Two Expression Trees are Equivalent
/// </summary>
void LeetCodeTree::checkEquivalence(TreeNode * root, vector<int>& arr)
{
    if (root->val >= 'a' && root->val <= 'z')
    {
        arr[root->val - 'a']++;
    }
    else
    {
        vector<int> left(26);
        checkEquivalence(root->left, left);
        vector<int> right(26);
        checkEquivalence(root->right, right);
        for (int i = 0; i < 26; i++)
        {
            arr[i] += left[i];
            if (root->val == '+') arr[i] += right[i];
            else arr[i] -= right[i];
        }
    }
    return;
}

/// <summary>
/// Leet code #1612. Check If Two Expression Trees are Equivalent
/// 
/// Medium
///
/// A binary expression tree is a kind of binary tree used to represent 
/// arithmetic expressions. Each node of a binary expression tree has 
/// either zero or two children. Leaf nodes (nodes with 0 children) 
/// correspond to operands (variables), and internal nodes (nodes with two 
/// children) correspond to the operators. In this problem, we only 
/// consider the '+' operator (i.e. addition).
///
/// You are given the roots of two binary expression trees, root1 and 
/// root2. Return true if the two binary expression trees are equivalent. 
/// Otherwise, return false.
///
/// Two binary expression trees are equivalent if they evaluate to the 
/// same value regardless of what the variables are set to.
///
/// Follow up: What will you change in your solution if the tree also 
/// supports the '-' operator (i.e. subtraction)?
/// 
/// Example 1:
/// Input: root1 = [x], root2 = [x]
/// Output: true
///
/// Example 2:
/// Input: root1 = [+,a,+,null,null,b,c], root2 = [+,+,b,c,a]
/// Output: true
/// Explaination: a + (b + c) == (b + c) + a
///
/// Example 3:
/// Input: root1 = [+,a,+,null,null,b,c], root2 = [+,+,b,d,a]
/// Output: false
/// Explaination: a + (b + c) != (b + d) + a
///
/// Constraints:
/// 1. The number of nodes in both trees are equal, odd and, in the 
///    range [1, 4999].
/// 2. Node.val is '+' or a lower-case English letter.
/// 3. It's guaranteed that the tree given is a valid binary expression 
///    tree.
/// </summary>
bool LeetCodeTree::checkEquivalence(TreeNode* root1, TreeNode* root2)
{
    vector<int> arr1(26);
    vector<int> arr2(26);
    checkEquivalence(root1, arr1);
    checkEquivalence(root2, arr2);
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}


/// <summary>
/// Leet code #1602. Find Nearest Right Node in Binary Tree
/// 
/// Medium
///
/// Given the root of a binary tree and a node u in the tree, return the 
/// nearest node on the same level that is to the right of u, or return 
/// null if u is the rightmost node in its level.
/// 
/// Example 1:
/// Input: root = [1,2,3,null,4,5,6], u = 4
/// Output: 5
/// Explanation: The nearest node on the same level to the right of 
/// node 4 is node 5.
///
/// Example 2:
/// Input: root = [3,null,4,2], u = 2
/// Output: null
/// Explanation: There are no nodes to the right of 2.
///
/// Example 3:
/// Input: root = [1], u = 1
/// Output: null
///
/// Example 4:
/// Input: root = [3,4,2,null,null,null,1], u = 4
/// Output: 2
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 1 <= Node.val <= 10^5
/// 3. All values in the tree are distinct.
/// 4. u is a node in the binary tree rooted at root.
/// </summary>
TreeNode* LeetCodeTree::findNearestRightNode(TreeNode* root, TreeNode* u)
{
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        size_t size = queue.size();
        TreeNode* last = nullptr;
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();

            if (last != nullptr) return node;
            if (node != nullptr && u != nullptr)
            {
                if (node->val == u->val) last = u;
                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }
        }
        if (last != nullptr) return nullptr;
    }
    return nullptr;
}

/// <summary>
/// Leet code #1522. Diameter of N-Ary Tree
/// </summary>
int LeetCodeTree::diameter(Node* root, int depth, int & max_diameter)
{
    int max_depth = 0;
    for (size_t i = 0; i < root->children.size(); i++)
    {
        int curr_depth = diameter(root->children[i], depth + 1, max_diameter);
        max_diameter = max(max_diameter, max_depth + curr_depth);
        max_depth = max(max_depth, curr_depth);
    }
    return max_depth + 1;
}

/// <summary>
/// Leet code #1522. Diameter of N-Ary Tree
/// 
/// Medium
///
/// Given a root of an N-ary tree, you need to compute the length of the 
/// diameter of the tree.
///
/// The diameter of an N-ary tree is the length of the longest path 
/// between any two nodes in the tree. This path may or may not pass 
/// through the root.
///
/// (Nary-Tree input serialization is represented in their level order 
/// traversal, each group of children is separated by the null value.)
///
/// Example 1:
/// Input: root = [1,null,3,2,4,null,5,6]
/// Output: 3
/// Explanation: Diameter is shown in red color.
///
/// Example 2:
/// Input: root = [1,null,2,null,3,4,null,5,null,6]
/// Output: 4
///
/// Example 3:
/// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,
///                null,11,null,12,null,13,null,null,14]
/// Output: 7
///
/// Constraints:
/// 1. The depth of the n-ary tree is less than or equal to 1000.
/// 2. The total number of nodes is between [0, 10^4].
/// </summary>
int LeetCodeTree::diameter(Node* root)
{
    int result = 0;
    diameter(root, 0, result);
    return result;
}

/// <summary>
/// Leet code #1516. Move Sub-Tree of N-Ary Tree
/// </summary>
int LeetCodeTree::is_parent(Node* node, Node* p, Node* q, bool is_p_found)
{
    if (node->val == p->val)
    {
        is_p_found = true;
    }
    else if (node->val == q->val)
    {
        if (is_p_found) return 1;
        else return 0;
    }

    for (size_t i = 0; i < node->children.size(); i++)
    {
        int ret = is_parent(node->children[i], p, q, is_p_found);
        if (ret >= 0)
        {
            return ret;
        }
    }
    return -1;
}

/// <summary>
/// Leet code #1516. Move Sub-Tree of N-Ary Tree
/// </summary>
Node* LeetCodeTree::find_parent(Node* node, Node* target, Node* parent)
{
    Node* result = nullptr;
    if (node->val == target->val) return parent;
    for (size_t i = 0; i < node->children.size(); i++)
    {
        result = find_parent(node->children[i], target, node);
        if (result != nullptr)
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1516. Move Sub-Tree of N-Ary Tree
/// </summary>
Node* LeetCodeTree::find_node(Node* node, Node* target)
{
    Node* result = nullptr;
    if (node->val == target->val) return node;
    for (size_t i = 0; i < node->children.size(); i++)
    {
        result = find_node(node->children[i], target);
        if (result != nullptr)
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1516. Move Sub-Tree of N-Ary Tree
/// 
/// Hard
///
/// Given the root of an N-ary tree of unique values, and two nodes of 
/// the tree p and q.
///
/// You should move the subtree of the node p to become a direct child 
/// of node q. If p is already a direct child of q, don't change anything. 
/// Node p must be the last child in the children list of node q.
///
/// Return the root of the tree after adjusting it.
/// 
/// There are 3 cases for nodes p and q:
/// Node q is in the sub-tree of node p.
/// Node p is in the sub-tree of node q.
/// Neither node p is in the sub-tree of node q nor node q is in the 
/// sub-tree of node p.
/// In cases 2 and 3, you just need to move p (with its sub-tree) to be a 
/// child of q, but in case 1 the tree may be disconnected, thus you need 
/// to reconnect the tree again. Please read the examples carefully before 
/// solving this problem.
/// 
/// Nary-Tree input serialization is represented in their level order 
/// traversal, each group of children is separated by the null value 
/// (See examples).
/// 
///
/// For example, the above tree is serialized as [1,null,2,3,4,5,null,null,
/// 6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].
///
/// Example 1:
/// Input: root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 4, q = 1
/// Output: [1,null,2,3,4,null,5,null,6,null,7,8]
/// Explanation: This example follows the second case as node p is in the 
/// sub-tree of node q. We move node p with its sub-tree to be a direct 
/// child of node q.
/// Notice that node 4 is the last child of node 1.
///
/// Example 2:
/// Input: root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 7, q = 4
/// Output: [1,null,2,3,null,4,5,null,6,null,7,8]
/// Explanation: Node 7 is already a direct child of node 4. We don't 
/// change anything.
///
/// Example 3:
/// Input: root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 3, q = 8
/// Output: [1,null,2,null,4,5,null,7,8,null,null,null,3,null,6]
/// Explanation: This example follows case 3 because node p is not in 
/// the sub-tree of node q and vice-versa. We can move node 3 with its 
/// sub-tree and make it as node 8's child.
///
/// Example 4:
/// Input: root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 2, q = 7
/// Output: [1,null,7,3,null,2,null,6,null,4,5,null,null,8]
/// Explanation: Node q is in the sub-tree of node p, so this is case 1.
/// The first step, we move node p (with all of its sub-tree except for 
/// node q) and add it as a child to node q.
/// Then we will see that the tree is disconnected, you need to reconnect 
/// node q to replace node p as shown.
///
/// Example 5:
/// Input: root = [1,null,2,3,null,4,5,null,6,null,7,8], p = 1, q = 2
/// Output: [2,null,4,5,1,null,7,8,null,null,3,null,null,null,6]
/// Explanation: Node q is in the sub-tree of node p, so this is case 1.
/// The first step, we move node p (with all of its sub-tree except for 
/// node q) and add it as a child to node q.
/// As node p was the root of the tree, node q replaces it and becomes 
/// the root of the tree.
///
/// Constraints:
/// 1. The total number of nodes is between [2, 1000].
/// 2. Each node has a unique value.
/// 3. p != null
/// 4. q != null
/// 5. p and q are two different nodes (i.e. p != q).
/// </summary>
Node* LeetCodeTree::moveSubTree(Node* root, Node* p, Node* q)
{
    p = find_node(root, p);
    q = find_node(root, q);
    int is_p_parent = is_parent(root, p, q, false);
    Node* p_parent = find_parent(root, p, nullptr);
    Node* q_parent = find_parent(root, q, nullptr);

    if (is_p_parent)
    {
        if (q_parent != nullptr)
        {
            for (auto itr = q_parent->children.begin(); itr != q_parent->children.end(); itr++)
            {
                if ((*itr)->val == q->val)
                {
                    q_parent->children.erase(itr);
                    break;
                }
            }
        }
    }
    if (p_parent != nullptr)
    {
        if (q != nullptr && p_parent->val != q->val)
        {
            for (size_t i = 0; i < p_parent->children.size(); i++)
            {
                if (p_parent->children[i]->val == p->val)
                {
                    if (is_p_parent == 1) p_parent->children[i] = q;
                    else p_parent->children.erase(p_parent->children.begin() + i);
                    break;
                }
            }
            if (q != nullptr) q->children.push_back(p);
        }
    }
    else
    {
        if (q != nullptr) q->children.push_back(p);
        root = q;
    }
    return root;
}


/// <summary>
/// Leet code #1597. Build Binary Expression Tree From Infix Expression
/// 
/// Hard
///
/// A binary expression tree is a kind of binary tree used to represent 
/// arithmetic expressions. Each node of a binary expression tree has 
/// either zero or two children. Leaf nodes (nodes with 0 children) 
/// correspond to operands (numbers), and internal nodes 
/// (nodes with 2 children) correspond to the operators '+' (addition), 
/// '-' (subtraction), '*' (multiplication), and '/' (division).
///
/// For each internal node with operator o, the infix expression that it 
/// represents is (A o B), where A is the expression the left subtree 
/// represents and B is the expression the right subtree represents.
///
/// You are given a string s, an infix expression containing operands, 
/// the operators described above, and parentheses '(' and ')'.
///
/// Return any valid binary expression tree, which its in-order traversal 
/// reproduces s after omitting the parenthesis from it (see examples 
/// below).
/// Please note that order of operations applies in s. That is, 
/// expressions in parentheses are evaluated first, and multiplication 
/// and division happen before addition and subtraction.
/// Operands must also appear in the same order in both s and the 
/// in-order traversal of the tree.
/// 
/// Example 1:
/// Input: s = "2-3/(5*2)+1"
/// Output: [+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]
/// Explanation: The inorder traversal of the tree above is 2-3/5*2+1 
/// which is the same as s without the parenthesis. The tree also produces 
/// the correct result and its operands are in the same order as they 
/// appear in s.
/// The tree below is also a valid binary expression tree with the same 
/// inorder traversal as s:
///
/// The third tree below however is not valid. Although it produces the 
/// same result and is equivalent to the above trees, its inorder traversal 
/// doesn't produce s and its operands are not in the same order as s.
///
/// Example 2:
/// Input: s = "3*4-2*5"
/// Output: [-,*,*,3,4,2,5]
/// Explanation: The tree above is the only valid tree whose inorder 
/// traversal produces s.
///
/// Example 3:
/// Input: s = "1+2+3+4+5"
/// Output: [+,+,5,+,4,null,null,+,3,null,null,1,2]
/// Explanation: The tree [+,+,5,+,+,null,null,1,2,3,4] is also one of 
/// many other valid trees.
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of digits and the characters '+', '-', '*', '/', '(', 
///    and ')'.
/// 3. Operands in s are exactly 1 digit.
/// 4. It is guaranteed that s is a valid expression.
/// </summary>
TreeNode* LeetCodeTree::expTree(string s)
{
    vector<char> operators;
    vector<TreeNode*> nodes;
    TreeNode* result = nullptr;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            nodes.push_back(new TreeNode(s[i]));
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            while (!operators.empty() &&
                operators.back() != '(')
            {
                TreeNode* node = new TreeNode(operators.back());
                operators.pop_back();
                node->right = nodes.back();
                nodes.pop_back();
                node->left = nodes.back();
                nodes.pop_back();
                nodes.push_back(node);
            }
            operators.push_back(s[i]);
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            while (!operators.empty() &&
                operators.back() != '(' &&
                operators.back() != '+' &&
                operators.back() != '-')
            {
                TreeNode* node = new TreeNode(operators.back());
                operators.pop_back();
                node->right = nodes.back();
                nodes.pop_back();
                node->left = nodes.back();
                nodes.pop_back();
                nodes.push_back(node);
            }
            operators.push_back(s[i]);
        }
        else if (s[i] == '(')
        {
            operators.push_back(s[i]);
        }
        else if (s[i] == ')')
        {
            while (operators.back() != '(')
            {
                TreeNode* node = new TreeNode(operators.back());
                operators.pop_back();
                node->right = nodes.back();
                nodes.pop_back();
                node->left = nodes.back();
                nodes.pop_back();
                nodes.push_back(node);
            }
            operators.pop_back();
        }
    }
    while (!operators.empty())
    {
        TreeNode* node = new TreeNode(operators.back());
        operators.pop_back();
        node->right = nodes.back();
        nodes.pop_back();
        node->left = nodes.back();
        nodes.pop_back();
        nodes.push_back(node);
    }
    result = nodes[0];
    return result;
}

/// <summary>
/// Leet code #1660. Correct a Binary Tree
/// 
/// Medium
///
/// You have a binary tree with a small defect. There is exactly one 
/// invalid node where its right child incorrectly points to another 
/// node at the same depth but to the invalid node's right.
///
/// Given the root of the binary tree with this defect, root, return 
/// the root of the binary tree after removing this invalid node and 
/// every node underneath it (minus the node it incorrectly points to).
///
/// Custom testing:
/// The test input is read as 3 lines:
///
/// TreeNode root
/// int fromNode (not available to correctBinaryTree)
/// int toNode (not available to correctBinaryTree)
/// After the binary tree rooted at root is parsed, the TreeNode with 
/// value of fromNode will have its right child pointer pointing to the 
/// TreeNode with a value of toNode. Then, root is passed to 
/// correctBinaryTree.
/// 
/// Example 1:
/// Input: root = [1,2,3], fromNode = 2, toNode = 3
/// Output: [1,null,3]
/// Explanation: The node with value 2 is invalid, so remove it.
///
/// Example 2:
/// Input: root = [8,3,1,7,null,9,4,2,null,null,null,5,6], 
/// fromNode = 7, toNode = 4
/// Output: [8,3,1,null,null,9,4,null,null,5,6]
/// Explanation: The node with value 7 is invalid, so remove it and the 
/// node underneath it, node 2.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [3, 104].
/// 2. -10^9 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. fromNode != toNode
/// 5. fromNode and toNode will exist in the tree and will be on the same 
///    depth.
/// 6. toNode is to the right of fromNode.
/// 7. fromNode.right is null in the initial tree from the test data.
/// </summary>
TreeNode* LeetCodeTree::correctBinaryTree(TreeNode* root)
{
    unordered_set<TreeNode*> node_map;
    queue<pair<TreeNode*, TreeNode*>> queue;
    node_map.insert(root);
    queue.push(make_pair(nullptr, root));
    while (!queue.empty())
    {
        pair<TreeNode*, TreeNode*> pair = queue.front();
        queue.pop();
        
        TreeNode* parent = pair.first;
        TreeNode* node = pair.second;
        if (node == nullptr) continue;
        if (node->right != nullptr && node_map.count(node->right) > 0)
        {
            if (parent != nullptr)
            {
                if (parent->left == node)
                {
                    parent->left = nullptr;
                }
                else
                {
                    parent->right = nullptr;
                }
            }
        }
        else
        {
            if (node->left != nullptr)
            {
                node_map.insert(node->left);
                queue.push(make_pair(node, node->left));
            }
            if (node->right != nullptr)
            {
                node_map.insert(node->right);
                queue.push(make_pair(node, node->right));
            }
        }
    }
    return root;
}

/// <summary>
/// Leet code #1666. Change the Root of a Binary Tree
/// 
/// Given the root of a binary tree and a leaf node, reroot the tree 
/// so that the leaf is the new root.
///
/// You can reroot the tree with the following steps for each node cur 
/// on the path starting from the leaf up to the root excluding the root:
///
/// If cur has a left child, then that child becomes cur's right child. 
/// Note that it is guaranteed that cur will have at most one child.
/// cur's original parent becomes cur's left child.
/// Return the new root of the rerooted tree.
///
/// Note: Ensure that your solution sets the Node.parent pointers correctly 
/// after rerooting or you will receive "Wrong Answer".
///
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 7
/// Output: [7,2,null,5,4,3,6,null,null,null,1,null,null,0,8]
///
/// Example 2:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], leaf = 0
/// Output: [0,1,null,3,8,5,null,null,null,6,2,null,null,7,4]
///
/// Constraints:
/// 1.  The number of nodes in the tree is in the range [2, 100].
/// 2. -10^9 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. leaf exist in the tree.
/// </summary>
TreeNode* LeetCodeTree::flipBinaryTree(TreeNode* root, TreeNode* leaf)
{
    TreeNode* node = leaf;
    while (leaf->parent != nullptr)
    {
        TreeNode* parent = leaf->parent;
        if (node->left != nullptr) node->right = node->left;
        node->left = parent;
        if (parent->left == node) parent->left = nullptr;
        else parent->right = nullptr;
        leaf->parent = parent->parent;
        parent->parent = node;
        node = parent;
    }
    return leaf;
}

/// <summary>
/// Leet code 1740. Find Distance in a Binary Tree
/// </summary>
void LeetCodeTree::findDistance(TreeNode* root, int p, int q, 
    int& p_depth, int& q_depth, int &result)
{
    if (root == nullptr) return;
    if (result >= 0) return;
    int next_p_depth = -1;
    int next_q_depth = -1;

    findDistance(root->left, p, q, next_p_depth, next_q_depth, result);
    if (next_p_depth != -1) p_depth = next_p_depth;
    if (next_q_depth != -1) q_depth = next_q_depth;
    next_p_depth = -1;
    next_q_depth = -1;
    findDistance(root->right, p, q, next_p_depth, next_q_depth, result);
    if (next_p_depth != -1) p_depth = next_p_depth;
    if (next_q_depth != -1) q_depth = next_q_depth;

    if (root->val == p) p_depth = 0;
    if (root->val == q) q_depth = 0;

    if (p_depth >= 0 && q_depth >= 0)
    {
        result = p_depth + q_depth;
        return;
    }

    if (p_depth >= 0) p_depth++;
    if (q_depth >= 0) q_depth++;
}

/// <summary>
/// Leet code 1740. Find Distance in a Binary Tree
/// 
/// Medium
/// 
/// Given the root of a binary tree and two integers p and q, return the 
/// distance between the nodes of value p and value q in the tree.
///
/// The distance between two nodes is the number of edges on the path from 
/// one to the other.
/// 
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
/// Output: 3
/// Explanation: There are 3 edges between 5 and 0: 5-3-1-0.
///
/// Example 2:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
/// Output: 2
/// Explanation: There are 2 edges between 5 and 7: 5-2-7.
///
/// Example 3:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
/// Output: 0
/// Explanation: The distance between a node and itself is 0.
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^4].
/// 2. 0 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. p and q are values in the tree.
/// </summary>
int LeetCodeTree::findDistance(TreeNode* root, int p, int q)
{
    int p_depth = -1;
    int q_depth = -1;
    int result = -1;
    findDistance(root, p, q, p_depth, q_depth, result);
    return result;
}

/// <summary>
/// Leet code 1932. Merge BSTs to Create Single BST 
/// </summary>
TreeNode* LeetCodeTree::canMerge(TreeNode* tree_node, unordered_map<int, TreeNode*>& roots)
{
    if (tree_node->left != nullptr)
    {
        int val = tree_node->left->val;
        if (roots.count(val) > 0)
        {
            tree_node->left = roots[val];
            roots.erase(val);
            canMerge(tree_node->left, roots);
        }
    }
    if (tree_node->right != nullptr)
    {
        int val = tree_node->right->val;
        if (roots.count(val) > 0)
        {
            tree_node->right = roots[val];
            roots.erase(val);
            canMerge(tree_node->right, roots);
        }
    }
    return tree_node;
}

/// <summary>
/// Leet code 1932. Merge BSTs to Create Single BST 
///                                  
/// Hard
/// 
/// You are given n BST (binary search tree) root nodes for n separate BSTs
/// stored in an array trees (0-indexed). Each BST in trees has at most 3 
/// nodes, and no two roots have the same value. In one operation, you can:
///
/// Select two distinct indices i and j such that the value stored at one 
/// of the leaves of trees[i] is equal to the root value of trees[j].
/// Replace the leaf node in trees[i] with trees[j].
/// Remove trees[j] from trees.
/// Return the root of the resulting BST if it is possible to form a valid 
/// BST after performing n - 1 operations, or null if it is impossible to 
/// create a valid BST.
///
/// A BST (binary search tree) is a binary tree where each node satisfies 
/// the following property:
/// 
/// Every node in the node's left subtree has a value strictly less than 
/// the node's value.
/// Every node in the node's right subtree has a value strictly greater 
/// than the node's value.
/// A leaf is a node that has no children.
/// 
/// Example 1:
/// Input: trees = [[2,1],[3,2,5],[5,4]]
/// Output: [3,2,5,1,null,4]
/// Explanation:
/// In the first operation, pick i=1 and j=0, and merge trees[0] into 
/// trees[1].
/// Delete trees[0], so trees = [[3,2,5,1],[5,4]].
/// In the second operation, pick i=0 and j=1, and merge trees[1] 
/// into trees[0].
/// Delete trees[1], so trees = [[3,2,5,1,null,4]].
///
/// The resulting tree, shown above, is a valid BST, so return its root.
///
/// Example 2:
/// Input: trees = [[5,3,8],[3,2,6]]
/// Output: []
/// Explanation:
/// Pick i=0 and j=1 and merge trees[1] into trees[0].
/// Delete trees[1], so trees = [[5,3,8,2,6]].
///
/// The resulting tree is shown above. This is the only valid operation 
/// that can be performed, but the resulting tree is not a valid BST, 
/// so return null.
///
/// Example 3:
/// Input: trees = [[5,4],[3]]
/// Output: []
/// Explanation: It is impossible to perform any operations.
///
/// Example 4:
/// 
/// Input: trees = [[2,1,3]]
/// Output: [2,1,3]
/// Explanation: There is only one tree, and it is already a valid 
/// BST, so return its root.
/// 
/// Constraints:
/// 1. n == trees.length
/// 2. 1 <= n <= 5 * 10^4
/// 3. The number of nodes in each tree is in the range [1, 3].
/// 4. Each node in the input may have children but no grandchildren.
/// 5. No two roots of trees have the same value.
/// 6. All the trees in the input are valid BSTs.
/// 7. 1 <= TreeNode.val <= 5 * 10^4.
/// </summary>
TreeNode* LeetCodeTree::canMerge(vector<TreeNode*>& trees)
{
    unordered_map<int, TreeNode*>  roots;
    for (size_t i = 0; i < trees.size(); i++)
    {
        roots[trees[i]->val] = trees[i];
    }
    for (size_t i = 0; i < trees.size(); i++)
    { 
        if (roots.count(trees[i]->val) > 0)
        {
            roots.erase(trees[i]->val);
            TreeNode * root = canMerge(trees[i], roots);
            roots[trees[i]->val] = trees[i];
        }
    }
    if (roots.size() == 1)
    {
        if (isValidBST(roots.begin()->second))
        {
            return roots.begin()->second;
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        return nullptr;
    }
}

/// <summary>
/// Leet code 1644. Lowest Common Ancestor of a Binary Tree
/// </summary>
int LeetCodeTree::lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result)
{
    int count = 0;
    if (root == nullptr) return 0;

    if (root == p || root == q) count = 1;

    count += lowestCommonAncestorII(root->left, p, q, result);
    if (count < 2)
    {
        count += lowestCommonAncestorII(root->right, p, q, result);
    }
    // if first time we see 2 node found, this is the answer.
    if (count == 2 && result == nullptr) result = root;

    return count;
}

/// <summary>
/// Leet Code 1644. Lowest Common Ancestor of a Binary Tree II
///                                                                 
/// Medium
/// 
/// Given the root of a binary tree, return the lowest common ancestor 
/// (LCA) of two given nodes, p and q. If either node p or q does not 
/// exist in the tree, return null. All values of the nodes in the 
/// tree are unique.
///
/// According to the definition of LCA on Wikipedia: "The lowest 
/// common ancestor of two nodes p and q in a binary tree T is the 
/// lowest node that has both p and q as descendants (where we allow 
/// a node to be a descendant of itself)". A descendant of a node 
/// x is a node y that is on the path from node x to some leaf node.
///
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1  
/// Output: 3
/// Explanation: The LCA of nodes 5 and 1 is 3.
///
/// Example 2:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
/// Output: 5
/// Explanation: The LCA of nodes 5 and 4 is 5. A node can be a 
/// descendant of itself according to the definition of LCA.
///
/// Example 3:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
/// Output: null
/// Explanation: Node 10 does not exist in the tree, so return null.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^4].
/// 2. -10^9 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. p != q
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode* result = nullptr;
    int count = lowestCommonAncestorII(root, p, q, result);

    return result;
}

/// <summary>
/// Leet Code 1902. Depth of BST Given Insertion Order
///                                                                 
/// Medium
///
/// You are given a 0-indexed integer array order of length n, a 
/// permutation of integers from 1 to n representing the order of 
/// insertion into a binary search tree.
///
/// A binary search tree is defined as follows:
///
/// The left subtree of a node contains only nodes with keys less than 
/// the node's key.
/// The right subtree of a node contains only nodes with keys greater than 
/// the node's key.
/// Both the left and right subtrees must also be binary search trees.
/// The binary search tree is constructed as follows:
/// 
/// order[0] will be the root of the binary search tree.
/// All subsequent elements are inserted as the child of any existing node 
/// such that the binary search tree properties hold.
/// Return the depth of the binary search tree.
/// 
/// A binary tree's depth is the number of nodes along the longest path 
/// from the root node down to the farthest leaf node.
///
/// Example 1:
/// Input: order = [2,1,4,3]
/// Output: 3
/// Explanation: The binary search tree has a depth of 3 with path 2->3->4.
///
/// Example 2:
/// Input: order = [2,1,3,4]
/// Output: 3
/// Explanation: The binary search tree has a depth of 3 with path 2->3->4.
///
/// Example 3:
/// Input: order = [1,2,3,4]
/// Output: 4
/// Explanation: The binary search tree has a depth of 4 with 
/// path 1->2->3->4.
///
/// Constraints:
/// 1. n == order.length
/// 2. 1 <= n <= 10^5
/// 3. order is a permutation of integers between 1 and n.
/// </summary>
int LeetCodeTree::maxDepthBST(vector<int>& order)
{
    int result = 0;
    map<int, int> tree_map;
    int n = order.size();
    tree_map[n + 1] = 0;
    for (size_t i = 0; i < order.size(); i++)
    {
        auto itr = tree_map.lower_bound(order[i]);
        itr->second++;
        result = max(result, itr->second);
        tree_map[order[i]] = itr->second;
    }
    return result;
}

/// <summary>
/// Leet Code 1650. Lowest Common Ancestor of a Binary Tree III
///                                                                 
/// Medium
///
/// Given two nodes of a binary tree p and q, return their lowest common 
/// ancestor (LCA).
///
/// Each node will have a reference to its parent node. The definition 
/// for Node is below:
///
/// class Node {
///     public int val;
///     public Node left;
///     public Node right;
///     public Node parent;
/// }
/// According to the definition of LCA on Wikipedia: "The lowest common 
/// ancestor of two nodes p and q in a tree T is the lowest node that has 
/// both p and q as descendants (where we allow a node to be a descendant 
/// of itself)."
/// 
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
/// Output: 3
/// Explanation: The LCA of nodes 5 and 1 is 3.
///
/// Example 2:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
/// Output: 5
/// Explanation: The LCA of nodes 5 and 4 is 5 since a node can be a 
/// descendant of itself according to the LCA definition.
///
/// Example 3:
/// Input: root = [1,2], p = 1, q = 2
/// Output: 1
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [2, 10^5].
/// 2. -10^9 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. p != q
/// 5. p and q exist in the tree.
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestorIII(TreeNode* p, TreeNode* q)
{
    unordered_set<int> parents;
    while (p != nullptr)
    {
        parents.insert(p->val);
        p = p->parent;
    }
    while (q != nullptr)
    {
        if (parents.count(q->val) > 0)
        {
            return q;
        }
        else
        {
            q = q->parent;
        }
    }
    return nullptr;
}

/// <summary>
/// Leet code #1676. Lowest Common Ancestor of a Binary Tree
/// </summary>
int LeetCodeTree::lowestCommonAncestorIV(TreeNode* node, unordered_set<int>& subtree, TreeNode*& result)
{
    int count = 0;
    if (node == nullptr) return 0;

    if (subtree.count(node->val) > 0)
    {
        count++;
    }
    count += lowestCommonAncestorIV(node->left, subtree, result);
    if (count < (int)subtree.size())
    {
        count += lowestCommonAncestorIV(node->right, subtree, result);
    }
    // if first time we see all node found, this is the answer.
    if (count == subtree.size() && result == nullptr) result = node;

    return count;
}

/// <summary>
/// Leet Code 1676. Lowest Common Ancestor of a Binary Tree IV
///                                                                 
/// Medium
///
/// Given the root of a binary tree and an array of TreeNode objects 
/// nodes, return the lowest common ancestor (LCA) of all the nodes 
/// in nodes. All the nodes will exist in the tree, and all values 
/// of the tree's nodes are unique.
///
/// Extending the definition of LCA on Wikipedia: "The lowest common 
/// ancestor of n nodes p1, p2, ..., pn in a binary tree T is the 
/// lowest node that has every pi as a descendant (where we allow a 
/// node to be a descendant of itself) for every valid i". A descendant 
/// of a node x is a node y that is on the path from node x to some leaf 
/// node.
///
/// Example 1:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [4,7]
/// Output: 2
/// Explanation: The lowest common ancestor of nodes 4 and 7 is node 2.
///
/// Example 2:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [1]
/// Output: 1
/// Explanation: The lowest common ancestor of a single node is the node 
/// itself.
///
/// Example 3:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], nodes = [7,6,2,4]
/// Output: 5
/// Explanation: The lowest common ancestor of the nodes 7, 6, 2, and 4 
/// is node 5.
///
/// Example 4:
/// Input: root = [3,5,1,6,2,0,8,null,null,7,4], 
/// nodes = [0,1,2,3,4,5,6,7,8]
/// Output: 3
/// Explanation: The lowest common ancestor of all the nodes is the 
/// root node.
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^4].
/// 2. -10^9 <= Node.val <= 10^9
/// 3. All Node.val are unique.
/// 4. All nodes[i] will exist in the tree.
/// 5. All nodes[i] are distinct.
/// </summary>
TreeNode* LeetCodeTree::lowestCommonAncestorIV(TreeNode* root, vector<TreeNode*>& nodes)
{
    unordered_set<int> subtree;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        subtree.insert(nodes[i]->val);
    }
    TreeNode* result = nullptr;
    lowestCommonAncestorIV(root, subtree, result);

    return result;
}

/// <summary>
/// Leet Code 2096. Step-By-Step Directions From a Binary Tree Node to 
///                 Another
/// </summary>
bool LeetCodeTree::getDirections(TreeNode* node, int target, string& path)
{
    if (node == nullptr) return false;
    if (node->val == target) return true;
    if (getDirections(node->left, target, path))
    {
        path.push_back('L');
        return true;
    }
    else if (getDirections(node->right, target, path))
    {
        path.push_back('R');
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet Code 2096. Step-By-Step Directions From a Binary Tree Node to 
///                 Another
///                                                                 
/// Medium
///
/// You are given the root of a binary tree with n nodes. Each node is 
/// uniquely assigned a value from 1 to n. You are also given an integer 
/// startValue representing the value of the start node s, and a 
/// different integer destValue representing the value of the destination 
/// node t.
/// Find the shortest path starting from node s and ending at node t. 
/// Generate step-by-step directions of such path as a string consisting 
/// of only the uppercase letters 'L', 'R', and 'U'. Each letter 
/// indicates a specific direction:
///
/// 'L' means to go from a node to its left child node.
/// 'R' means to go from a node to its right child node.
/// 'U' means to go from a node to its parent node.
/// Return the step-by-step directions of the shortest path from node 
/// s to node t.
/// 
/// Example 1:
/// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
/// Output: "UURL"
/// Explanation: The shortest path is: 3 -> 1 -> 5 -> 2 -> 6.
///
/// Example 2:
/// Input: root = [2,1], startValue = 2, destValue = 1
/// Output: "L"
/// Explanation: The shortest path is: 2 -> 1.
///
/// Constraints:
/// The number of nodes in the tree is n.
/// 1. 2 <= n <= 10^5
/// 2. 1 <= Node.val <= n
/// 3. All the values in the tree are unique.
/// 4. 1 <= startValue, destValue <= n
/// 5. startValue != destValue
/// </summary>
string LeetCodeTree::getDirections(TreeNode* root, int startValue, int destValue)
{
    string startPath, destPath, result;
    getDirections(root, startValue, startPath);
    getDirections(root, destValue, destPath);
    while (!startPath.empty() && !destPath.empty())
    {
        if (startPath.back() == destPath.back())
        {
            startPath.pop_back();
            destPath.pop_back();
        }
        else
        {
            break;
        }
    }
    while (!startPath.empty())
    {
        result.push_back('U');
        startPath.pop_back();
    }
    while (!destPath.empty())
    {
        result.push_back(destPath.back());
        destPath.pop_back();
    }
    return result;
}

/// <summary>
/// Leet Code 1973. Count Nodes Equal to Sum of Descendants 
/// </summary>
int LeetCodeTree::equalToDescendants(TreeNode* node, long long& sum)
{
    if (node == nullptr)
    {
        sum = 0;
        return 0;
    }
    int result = 0;
    long long left_sum = 0;
    result += equalToDescendants(node->left, left_sum);
    long long right_sum = 0;
    result += equalToDescendants(node->right, right_sum);
    if (left_sum + right_sum == node->val)
    {
        result++;
    }
    sum = left_sum + right_sum + node->val;
    return result;
}

/// <summary>
/// Leet Code 1973. Count Nodes Equal to Sum of Descendants 
///                                                                 
/// Medium
///
/// Given the root of a binary tree, return the number of nodes where the
/// value of the node is equal to the sum of the values of its descendants.
///
/// A descendant of a node x is any node that is on the path from node x 
/// to some leaf node. The sum is considered to be 0 if the node has no 
/// descendants.
/// 
/// Example 1:
/// Input: root = [10,3,4,2,1]
/// Output: 2
/// Explanation:
/// For the node with value 10: The sum of its descendants is 3+4+2+1 = 10.
/// For the node with value 3: The sum of its descendants is 2+1 = 3.
///
/// Example 2:
/// Input: root = [2,3,null,2,null]
/// Output: 0
/// Explanation:
/// No node has a value that is equal to the sum of its descendants.
///
/// Example 3:
/// Input: root = [0]
/// Output: 1
/// For the node with value 0: The sum of its descendants is 0 since it 
/// has no descendants.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 0 <= Node.val <= 10^5
/// </summary>
int LeetCodeTree::equalToDescendants(TreeNode* root)
{
    long long sum = 0;
    return equalToDescendants(root, sum);
}

/// <summary>
/// Leet Code 2196. Create Binary Tree From Descriptions
///                                                                                   
/// Medium
///
/// You are given a 2D integer array descriptions where 
/// descriptions[i] = [parenti, childi, isLefti] indicates that parenti 
/// is the parent of childi in a binary tree of unique values. Furthermore,
///
/// If isLefti == 1, then childi is the left child of parenti.
/// If isLefti == 0, then childi is the right child of parenti.
/// Construct the binary tree described by descriptions and return its 
/// root.
///
/// The test cases will be generated such that the binary tree is valid.
/// 
/// Example 1:
/// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],
/// [80,19,1]]
/// Output: [50,20,80,15,17,19]
/// Explanation: The root node is the node with value 50 since it has no 
/// parent.
/// The resulting binary tree is shown in the diagram.
///
/// Example 2:
/// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
/// Output: [1,2,null,null,3,4]
/// Explanation: The root node is the node with value 1 since it has no 
/// parent.
/// The resulting binary tree is shown in the diagram.
/// 
/// Constraints:
/// 1 <= descriptions.length <= 10^4
/// 2. descriptions[i].length == 3
/// 3. 1 <= parenti, childi <= 10^5
/// 4. 0 <= isLefti <= 1
/// 5. The binary tree described by descriptions is valid.
/// </summary>
TreeNode* LeetCodeTree::createBinaryTree(vector<vector<int>>& descriptions)
{
    unordered_map<int, TreeNode*> treeNodes;
    unordered_map<int, int> degree;
    for (size_t i = 0; i < descriptions.size(); i++)
    {
        TreeNode* parent = nullptr;
        if (treeNodes[descriptions[i][0]] == nullptr)
        {
            parent = new TreeNode(descriptions[i][0]);
            treeNodes[descriptions[i][0]] = parent;
        }
        parent = treeNodes[descriptions[i][0]];
        TreeNode* child = nullptr;
        if (treeNodes[descriptions[i][1]] == nullptr)
        {
            child = new TreeNode(descriptions[i][1]);
            treeNodes[descriptions[i][1]] = child;
        }
        child = treeNodes[descriptions[i][1]];
        if (descriptions[i][2] == 1)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        degree[descriptions[i][0]]+=0;
        degree[descriptions[i][1]]++;
    }

    for (auto itr : degree)
    {
        if (itr.second == 0) return treeNodes[itr.first];
    }
    return nullptr;
}

/// <summary>
/// Leet Code 2236. Root Equals Sum of Children
///                                                                                   
/// Easy
/// 
/// You are given the root of a binary tree that consists of exactly 3 
/// nodes: the root, its left child, and its right child.
///
/// Return true if the value of the root is equal to the sum of the 
/// values of its two children, or false otherwise.
///
/// Example 1:
/// Input: root = [10,4,6]
/// Output: true
/// Explanation: The values of the root, its left child, and its right 
/// child are 10, 4, and 6, respectively.
/// 10 is equal to 4 + 6, so we return true.
///
/// Example 2:
/// Input: root = [5,3,1]
/// Output: false
/// Explanation: The values of the root, its left child, and its right 
/// child are 5, 3, and 1, respectively.
/// 5 is not equal to 3 + 1, so we return false.
///
/// Constraints:
/// 1. The tree consists only of the root, its left child, and its right 
///    child.
/// 2. -100 <= Node.val <= 100
/// </summary>
bool LeetCodeTree::checkTree(TreeNode* root)
{
    return (root->val == (root->left->val + root->right->val));
}

/// <summary>
/// Leet Code 2265. Count Nodes Equal to Average of Subtree
/// </summary>
int LeetCodeTree::averageOfSubtree(TreeNode* root, int& sum, int& count)
{
    if (root == nullptr) return 0;
    int left_sum = 0;
    int left_count = 0;
    int right_sum = 0;
    int right_count = 0;
    int result = 0;
    result += averageOfSubtree(root->left, left_sum, left_count);
    sum += left_sum;
    count += left_count;
    result += averageOfSubtree(root->right, right_sum, right_count);
    sum += right_sum;
    count += right_count;
    sum += root->val;
    count++;
    if (root->val == sum / count)
    {
        result++;
    }
    return result;
}

/// <summary>
/// Leet Code 2265. Count Nodes Equal to Average of Subtree
///                                                                                      
/// Medium
/// 
/// Given the root of a binary tree, return the number of nodes where the 
/// value of the node is equal to the average of the values in its subtree.
///
/// Note:
/// The average of n elements is the sum of the n elements divided by n 
/// and rounded down to the nearest integer.
/// A subtree of root is a tree consisting of root and all of its 
/// descendants.
///
/// Example 1:
/// Input: root = [4,8,5,0,1,null,6]
/// Output: 5
/// Explanation: 
/// For the node with value 4: The average of its subtree is 
/// (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
/// For the node with value 5: The average of its subtree is 
/// (5 + 6) / 2 = 11 / 2 = 5.
/// For the node with value 0: The average of its subtree is 
/// 0 / 1 = 0.
/// For the node with value 1: The average of its subtree is 
/// 1 / 1 = 1.
/// For the node with value 6: The average of its subtree is 
/// 6 / 1 = 6.
///
/// Example 2:
/// Input: root = [1]
/// Output: 1
/// Explanation: For the node with value 1: The average of its subtree is 
/// 1 / 1 = 1.
/// 
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 1000].
/// 2. 0 <= Node.val <= 1000
/// </summary>
int LeetCodeTree::averageOfSubtree(TreeNode* root)
{
    int sum = 0;
    int count = 0;
    return averageOfSubtree(root, sum, count);
}

/// <summary>
/// Leet Code 2246. Longest Path With Different Adjacent Characters
/// </summary>
int LeetCodeTree::longestPath(int node, vector<vector<int>>& children, string& s, int& result)
{
    int max_length = 0;
    for (size_t i = 0; i < children[node].size(); i++)
    {
        int child = children[node][i];
        int length = longestPath(child, children, s, result);
        if (s[node] == s[child]) length = 0;
        result = max(result, max_length + length + 1);
        max_length = max(max_length, length);
    }
    result = max(result, max_length + 1);
    return max_length + 1;
}


/// <summary>
/// Leet Code 2246. Longest Path With Different Adjacent Characters
///                                                                                      
/// Hard
/// 
/// You are given a tree (i.e. a connected, undirected graph that has no 
/// cycles) rooted at node 0 consisting of n nodes numbered from 0 to 
/// n - 1. The tree is represented by a 0-indexed array parent of size n, 
/// where parent[i] is the parent of node i. Since node 0 is the root, 
/// parent[0] == -1.
///
/// You are also given a string s of length n, where s[i] is the character 
/// assigned to node i.
///
/// Return the length of the longest path in the tree such that no pair 
/// of adjacent nodes on the path have the same character assigned to them.
/// 
/// Example 1:
/// 
/// Input: parent = [-1,0,0,1,1,2], s = "abacbe"
/// Output: 3
/// Explanation: The longest path where each two adjacent nodes have 
/// different characters in the tree is the path: 0 -> 1 -> 3. The 
/// length of this path is 3, so 3 is returned.
/// It can be proven that there is no longer path that satisfies the 
/// conditions. 
///
/// Example 2:
/// Input: parent = [-1,0,0,0], s = "aabc"
/// Output: 3
/// Explanation: The longest path where each two adjacent nodes have 
/// different characters is the path: 2 -> 0 -> 3. The length of this 
/// path is 3, so 3 is returned.
///  
/// Constraints:
/// 1. n == parent.length == s.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= parent[i] <= n - 1 for all i >= 1
/// 4. parent[0] == -1
/// 5. parent represents a valid tree.
/// 6. s consists of only lowercase English letters.
/// </summary>
int LeetCodeTree::longestPath(vector<int>& parent, string s)
{
    vector<vector<int>> children(s.size());
    int result = 0;

    for (size_t i = 0; i < parent.size(); i++)
    {
        if (parent[i] == -1) continue;
        children[parent[i]].push_back(i);
    }
    longestPath(0, children, s, result);
    return result;
}

/// <summary>
/// Leet Code 2277. Closest Node to Path in Tree
///                                                           
/// Hard
/// 
/// You are given a positive integer n representing the number of nodes in 
/// a tree, numbered from 0 to n - 1 (inclusive). You are also given a 2D 
/// integer array edges of length n - 1, where edges[i] = [node1i, node2i] 
/// denotes that there is a bidirectional edge connecting node1i and 
/// node2i in the tree.
///
/// You are given a 0-indexed integer array query of length m where 
/// query[i] = [starti, endi, nodei] means that for the ith query, you are 
/// tasked with finding the node on the path from starti to endi that is 
/// closest to nodei.
///
/// Return an integer array answer of length m, where answer[i] is the 
/// answer to the ith query.
///
/// Example 1:
/// Input: n = 7, edges = [[0,1],[0,2],[0,3],[1,4],[2,5],[2,6]], 
/// query = [[5,3,4],[5,3,6]]
/// Output: [0,2]
/// Explanation:
/// The path from node 5 to node 3 consists of the nodes 5, 2, 0, and 3.
/// The distance between node 4 and node 0 is 2.
/// Node 0 is the node on the path closest to node 4, so the answer to 
/// the first query is 0.
/// The distance between node 6 and node 2 is 1.
/// Node 2 is the node on the path closest to node 6, so the answer 
/// to the second query is 2.
///
/// Example 2:
/// Input: n = 3, edges = [[0,1],[1,2]], query = [[0,1,2]]
/// Output: [1]
/// Explanation:
/// The path from node 0 to node 1 consists of the nodes 0, 1.
/// The distance between node 2 and node 1 is 1.
/// Node 1 is the node on the path closest to node 2, so the 
/// answer to the first query is 1.
///
/// Example 3:
/// Input: n = 3, edges = [[0,1],[1,2]], query = [[0,0,0]]
/// Output: [0]
/// Explanation:
/// The path from node 0 to node 0 consists of the node 0.
/// Since 0 is the only node on the path, the answer to the first 
/// query is 0.
///
/// Constraints:
/// 1. 1 <= n <= 1000
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= node1i, node2i <= n - 1
/// 5. node1i != node2i
/// 6. 1 <= query.length <= 1000
/// 7. query[i].length == 3
/// 8. 0 <= starti, endi, nodei <= n - 1
/// 9. The graph is a tree.
/// </summary>
vector<int> LeetCodeTree::closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query)
{
    vector<int> parent(n, -1), level(n, -1);
    vector<vector<int>> neighbors(n);

    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> queue;
    queue.push(0);
    int step = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            int node = queue.front();
            queue.pop();
            level[node] = step;
            for (size_t i = 0; i < neighbors[node].size(); i++)
            {
                int child = neighbors[node][i];
                if (level[child] == -1)
                {
                    parent[child] = node;
                    queue.push(child);
                }
            }
        }
        step++;
    }
    vector<int> result(query.size(), -1);
    for (size_t i = 0; i < query.size(); i++)
    {
        unordered_set<int> hash;
        priority_queue<pair<int, int>> pq;
        for (size_t j = 0; j < query[i].size(); j++)
        {
            int node = query[i][j];
            pq.push(make_pair(level[node], node));
            if (hash.count(node) > 0)
            {
                result[i] = node;
                while (!pq.empty()) pq.pop();
                break;
            }
            hash.insert(node);
        }
        while (result[i] == -1 && !pq.empty())
        {
            pair<int, int> node = pq.top();
            pq.pop();
            hash.erase(node.second);
            int p = parent[node.second];
            if (p == -1) continue;
            if (hash.count(p) > 0)
            {
                result[i] = p;
                break;
            }
            pq.push(make_pair(level[p], p));
            hash.insert(p);
        }
    }
    return result;
}


/// <summary>
/// Leet Code 2313. Minimum Flips in Binary Tree to Get Result
/// </summary>
void LeetCodeTree::minimumFlips(TreeNode* root, int& true_flips, int& false_flips)
{
    if (root == nullptr)
    {
        true_flips = 0;
        false_flips = 0;
    }
    else if (root->val == 0)
    {
        true_flips = 1;
        false_flips = 0;
    }
    else if (root->val == 1)
    {
        true_flips = 0;
        false_flips = 1;
    }
    else 
    {
        int left_true;
        int left_false;
        int right_true;
        int right_false;
        minimumFlips(root->left, left_true, left_false);
        minimumFlips(root->right, right_true, right_false);
        if (root->val == 2)
        {
            true_flips = min(left_true, right_true);
            false_flips = left_false + right_false;
        }
        else if (root->val == 3)
        {
            true_flips = left_true + right_true;
            false_flips = min(left_false, right_false);
        }
        else if (root->val == 4)
        {
            true_flips = min(left_true + right_false, left_false + right_true);
            false_flips = min(left_false + right_false, left_true + right_true);
        }
        else if (root->val == 5)
        {
            true_flips = left_false + right_false;
            false_flips = left_true + right_true;
        }
    }
}


/// <summary>
/// Leet Code 2313. Minimum Flips in Binary Tree to Get Result
///                                                           
/// Hard
///
/// You are given the root of a binary tree with the following properties:
///
/// Leaf nodes have either the value 0 or 1, representing false and true 
/// respectively.
/// Non-leaf nodes have either the value 2, 3, 4, or 5, representing the 
/// boolean operations OR, AND, XOR, and NOT, respectively.
/// You are also given a boolean result, which is the desired result of 
/// the evaluation of the root node.
///
/// The evaluation of a node is as follows:
///
/// If the node is a leaf node, the evaluation is the value of the node, 
/// i.e. true or false.
/// Otherwise, evaluate the node's children and apply the boolean 
/// operation of its value with the children's evaluations.
/// In one operation, you can flip a leaf node, which causes a false node 
/// to become true, and a true node to become false.
///
/// Return the minimum number of operations that need to be performed such 
/// that the evaluation of root yields result. It can be shown that there 
/// is always a way to achieve result.
///
/// A leaf node is a node that has zero children.
///
/// Note: NOT nodes have either a left child or a right child, but other 
/// non-leaf nodes have both a left child and a right child.
///
/// Example 1:
/// Input: root = [3,5,4,2,null,1,1,1,0], result = true
/// Output: 2
/// Explanation:
/// It can be shown that a minimum of 2 nodes have to be flipped to make 
/// the root of the tree evaluate to true. One way to achieve this is 
/// shown in the diagram above.
///
/// Example 2:
/// Input: root = [0], result = false
/// Output: 0
/// Explanation:
/// The root of the tree already evaluates to false, so 0 nodes have to be 
/// flipped.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 0 <= Node.val <= 5
/// 3. OR, AND, and XOR nodes have 2 children.
/// 4. NOT nodes have 1 child.
/// 5. Leaf nodes have a value of 0 or 1.
/// 6. Non-leaf nodes have a value of 2, 3, 4, or 5.
/// </summary>
int LeetCodeTree::minimumFlips(TreeNode* root, bool result)
{
    int true_flips;
    int false_flips;
    minimumFlips(root, true_flips, false_flips);
    if (result)
    {
        return true_flips;
    }
    else
    {
        return false_flips;
    }
}

/// <summary>
/// Leet Code 2331. Evaluate Boolean Binary Tree
///                                                           
/// Easy
///
/// You are given the root of a full binary tree with the following 
/// properties:
///
/// Leaf nodes have either the value 0 or 1, where 0 represents False 
/// and 1 represents True.
/// Non-leaf nodes have either the value 2 or 3, where 2 represents the 
/// boolean OR and 3 represents the boolean AND.
/// The evaluation of a node is as follows:
///
/// If the node is a leaf node, the evaluation is the value of the node, 
/// i.e. True or False.
/// Otherwise, evaluate the node's two children and apply the boolean 
/// operation of its value with the children's evaluations.
/// Return the boolean result of evaluating the root node.
///
/// A full binary tree is a binary tree where each node has 
/// either 0 or 2 children.
///
/// A leaf node is a node that has zero children.
/// 
/// Example 1:
///
/// Input: root = [2,1,3,null,null,0,1]
/// Output: true
/// Explanation: The above diagram illustrates the evaluation process.
/// The AND node evaluates to False AND True = False.
/// The OR node evaluates to True OR False = True.
/// The root node evaluates to True, so we return true.
///
/// Example 2:
/// Input: root = [0]
/// Output: false
/// Explanation: The root node is a leaf node and it evaluates to false, 
/// so we return false.
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 1000].
/// 2. 0 <= Node.val <= 3
/// 3. Every node has either 0 or 2 children.
/// 4. Leaf nodes have a value of 0 or 1.
/// 5. Non-leaf nodes have a value of 2 or 3.
/// </summary>
bool LeetCodeTree::evaluateTree(TreeNode* root)
{
    if (root->val < 2)
    {
        return root->val == 1 ? true : false;
    }
    else if (root->val == 2)
    {
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return (left || right);
    }
    else
    {
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        return (left && right);
    }
}

/// <summary>
/// Leet Code 2378. Choose Edges to Maximize Score in a Tree
/// </summary>
pair<long long, long long> LeetCodeTree::maxScore(int node, vector<vector<pair<int, int>>>& neighbors)
{
    pair<long long, long long> result;
    vector<pair<long long, long long>> children;
    for (size_t i = 0; i < neighbors[node].size(); i++)
    {
        children.push_back(maxScore(neighbors[node][i].first, neighbors));
    }
    long long sum_with_children = 0;
    for (size_t i = 0; i < children.size(); i++)
    {
        sum_with_children += children[i].first;
    }
    long long with = 0; long long without = 0;
    for (size_t i = 0; i < children.size(); i++)
    {
        with = max(with, 
            max((long long)0, (long long)neighbors[node][i].second) +
            sum_with_children - children[i].first + children[i].second);
        without = without + children[i].first;
    }
    result.first = max(with, without);
    result.second = without;
    return result;
}


/// <summary>
/// Leet Code 2378. Choose Edges to Maximize Score in a Tree
///                                                  
/// Medium
///
/// You are given a weighted tree consisting of n nodes numbered from 0 
/// to n - 1.
///
/// The tree is rooted at node 0 and represented with a 2D array edges of 
/// size n where edges[i] = [pari, weighti] indicates that node pari is 
/// the parent of node i, and the edge between them has a weight equal to 
/// weighti. Since the root does not have a parent, you have 
/// edges[0] = [-1, -1].
///
/// Choose some edges from the tree such that no two chosen edges are 
/// adjacent and the sum of the weights of the chosen edges is maximized.
///
/// Return the maximum sum of the chosen edges.
///
/// Note:
/// You are allowed to not choose any edges in the tree, the sum of 
/// weights in this case will be 0.
/// Two edges Edge1 and Edge2 in the tree are adjacent if they have a 
/// common node.
/// In other words, they are adjacent if Edge1 connects nodes a and b and 
/// Edge2 connects nodes b and c.
///
/// Example 1:
/// Input: edges = [[-1,-1],[0,5],[0,10],[2,6],[2,4]]
/// Output: 11
/// Explanation: The above diagram shows the edges that we have to choose 
/// colored in red.
/// The total score is 5 + 6 = 11.
/// It can be shown that no better score can be obtained.
///
/// Example 2:
/// Input: edges = [[-1,-1],[0,5],[0,-6],[0,7]]
/// Output: 7
/// Explanation: We choose the edge with weight 7.
/// Note that we cannot choose more than one edge because all edges are 
/// adjacent to each other.
///
/// Constraints:
/// 1. n == edges.length
/// 2. 1 <= n <= 10^5
/// 3. edges[i].length == 2
/// 4. par0 == weight0 == -1
/// 5. 0 <= pari <= n - 1 for all i >= 1.
/// 6. pari != i
/// 7. -10^6 <= weighti <= 10^6 for all i >= 1.
/// 8. edges represents a valid tree.
/// </summary>
long long LeetCodeTree::maxScore(vector<vector<int>>& edges)
{
    vector<vector<pair<int, int>>> neighbors(edges.size());
    for (size_t i = 0; i < edges.size(); i++)
    {
        if (edges[i][0] == -1) continue;
        neighbors[edges[i][0]].push_back(make_pair(i, edges[i][1]));
    }
    pair<long long, long long> result = maxScore(0, neighbors);
    return max(result.first, result.second);
}

/// <summary>
/// Leet Code 2385. Amount of Time for Binary Tree to Be Infected
/// </summary>
pair<int, int> LeetCodeTree::amountOfTime(TreeNode* node, int start, int& result)
{
    if (node == nullptr) return make_pair(0, -1);
    pair<int, int> left = amountOfTime(node->left, start, result);
    pair<int, int> right = amountOfTime(node->right, start, result);
    pair<int, int> ret;
    ret.second = -1;
    ret.first = max(left.first, right.first) + 1;
    if (node->val == start)
    {
        ret.second = 0;
        result = max(left.first, right.first);
    }
    else if (left.second != -1)
    {
        ret.second = left.second + 1;
        result = max(result, right.first + ret.second);
    }
    else if (right.second != -1)
    {
        ret.second = right.second + 1;
        result = max(result, left.first + ret.second);
    }
    return ret;
}

/// <summary>
/// Leet Code 2385. Amount of Time for Binary Tree to Be Infected
///                                                  
/// Medium
///
/// You are given the root of a binary tree with unique values, and an 
/// integer start. At minute 0, an infection starts from the node with 
/// value start.
///
/// Each minute, a node becomes infected if:
///
/// The node is currently uninfected.
/// The node is adjacent to an infected node.
/// Return the number of minutes needed for the 
/// entire tree to be infected.
///
/// Example 1:
/// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
/// Output: 4
/// Explanation: The following nodes are infected during:
/// - Minute 0: Node 3
/// - Minute 1: Nodes 1, 10 and 6
/// - Minute 2: Node 5
/// - Minute 3: Node 4
/// - Minute 4: Nodes 9 and 2
/// It takes 4 minutes for the whole tree to be infected so we return 4.
///
/// Example 2:
/// Input: root = [1], start = 1
/// Output: 0
/// Explanation: At minute 0, the only node in the tree is infected so we 
/// return 0.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 1 <= Node.val <= 10^5
/// 3. Each node has a unique value.
/// 4. A node with a value of start exists in the tree.
/// </summary>
int LeetCodeTree::amountOfTime(TreeNode* root, int start)
{
    int result = 0;
    amountOfTime(root, start, result);
    return result;
}

/// <summary>
/// Leet Code 2415. Reverse Odd Levels of Binary Tree
///                                                  
/// Medium
///
/// Given the root of a perfect binary tree, reverse the node values at 
/// each odd level of the tree.
///
/// For example, suppose the node values at level 3 are 
/// [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
/// Return the root of the reversed tree.
///
/// A binary tree is perfect if all parent nodes have two children and 
/// all leaves are on the same level.
///
/// The level of a node is the number of edges along the path between 
/// it and the root node.
/// 
/// Example 1:
/// Input: root = [2,3,5,8,13,21,34]
/// Output: [2,5,3,8,13,21,34]
/// Explanation: 
/// The tree has only one odd level.
/// The nodes at level 1 are 3, 5 respectively, which are reversed and 
/// become 5, 3.
///
/// Example 2:
/// Input: root = [7,13,11]
/// Output: [7,11,13]
/// Explanation: 
/// The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
///
/// Example 3:
/// Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
/// Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
/// Explanation: 
/// The odd levels have non-zero values.
/// The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
/// The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 
/// 2, 1, 1, 1, 1 after the reversal.
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 2^14].
/// 2. 0 <= Node.val <= 10^5
/// 3. root is a perfect binary tree.
/// </summary>
TreeNode* LeetCodeTree::reverseOddLevels(TreeNode* root)
{
    int level = 0;
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int size = queue.size();
        vector<TreeNode*> list;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();
            list.push_back(node);
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
        }
        if (level % 2 == 1)
        {
            vector<int> reverse_list;
            for (size_t i = 0; i < list.size(); i++)
            {
                reverse_list.push_back(list[i]->val);
            }
            std::reverse(reverse_list.begin(), reverse_list.end());
            for (size_t i = 0; i < list.size(); i++)
            {
                list[i]->val = reverse_list[i];
            }
        }
        level++;
    }
    return root;
}

/// <summary>
/// Leet Code 2440. Create Components With Same Value     
/// </summary>
int LeetCodeTree::componentValue(vector<int>& nums, vector<vector<int>>& neighbors, vector<int>& sum, int curr, int target)
{
    sum[curr] = nums[curr];
    for (size_t i = 0; i < neighbors[curr].size(); i++)
    {
        int next = neighbors[curr][i];
        if (sum[next] != 0) continue;
        int subtree = componentValue(nums, neighbors, sum, next, target);
        if (subtree == -1)
        {
            return -1;
        }
        else
        {
            sum[curr] += subtree;
            if (sum[curr] > target) return -1;
        }
    }
    if (sum[curr] == target) return 0;
    else return sum[curr];
}

/// <summary>
/// Leet Code 2440. Create Components With Same Value     
///                                                  
/// Hard
///
/// There is an undirected tree with n nodes labeled from 0 to n - 1.
///
/// You are given a 0-indexed integer array nums of length n where nums[i] 
/// represents the value of the ith node. You are also given a 2D integer 
/// array edges of length n - 1 where edges[i] = [ai, bi] indicates that 
/// there is an edge between nodes ai and bi in the tree.
///
/// You are allowed to delete some edges, splitting the tree into multiple 
/// connected components. Let the value of a component be the sum of all 
/// nums[i] for which node i is in the component.
///
/// Return the maximum number of edges you can delete, such that every 
/// connected component in the tree has the same value.
///  
/// Example 1:
/// Input: nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]] 
/// Output: 2 
/// Explanation: The above figure shows how we can delete the edges [0,1] 
/// and [3,4]. The created components are nodes [0], [1,2,3] and [4]. 
/// The sum of the values in each component equals 6. It can be proven 
/// that no better deletion exists, so the answer is 2.
///
/// Example 2:
///
/// Input: nums = [2], edges = []
/// Output: 0
/// Explanation: There are no edges to be deleted.
///  
/// Constraints:
/// 1. 1 <= n <= 2 * 10^4
/// 2. nums.length == n
/// 3. 1 <= nums[i] <= 50
/// 4. edges.length == n - 1
/// 5. edges[i].length == 2
/// 6. 0 <= edges[i][0], edges[i][1] <= n - 1
/// 7. edges represents a valid tree.
/// </summary>
int LeetCodeTree::componentValue(vector<int>& nums, vector<vector<int>>& edges)
{
    int n = nums.size();
    vector<vector<int>> neighbors(n);
    vector<int> degree(n);
    int total = 0;
    for (size_t i = 0; i < nums.size(); i++) total += nums[i];
    for (size_t i = 0; i < edges.size(); i++)
    {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    int root = 0;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
        {
            root = i;
            break;
        }
    }
    for (int i = n; i > 0; i--)
    {
        if (total % i != 0) continue;
        int target = total / i;
        vector<int> sum(n);
        if (componentValue(nums, neighbors, sum, root, target) == 0)
        {
            return i - 1;
        }
    }
    return 0;
}

/// <summary>
/// Leet Code 2445. Number of Nodes With Value One   
/// </summary>
int LeetCodeTree::numberOfNodes(int n, int curr, vector<int>& flags)
{
    int result = 0;
    if (flags[curr] == 1) result++;
    int left = curr * 2;
    int right = curr * 2 + 1;
    if (left <= n)
    {
        flags[left] = (flags[left] + flags[curr]) % 2;
        result += numberOfNodes(n, left, flags);
    }
    if (right <= n)
    {
        flags[right] = (flags[right] + flags[curr]) % 2;
        result += numberOfNodes(n, right, flags);
    }
    return result;
}

/// <summary>
/// Leet Code 2445. Number of Nodes With Value One   
///                                                  
/// Medium
///
/// There is an undirected connected tree with n nodes labeled from 1 to n 
/// and n - 1 edges. You are given the integer n. The parent node of a 
/// node with a label v is the node with the label floor (v / 2). The root 
/// of the tree is the node with the label 1.
///
/// For example, if n = 7, then the node with the label 3 has the node 
/// with the label floor(3 / 2) = 1 as its parent, and the node with the 
/// label 7 has the node with the label floor(7 / 2) = 3 as its parent.
/// You are also given an integer array queries. Initially, every node 
/// has a value 0 on it. For each query queries[i], you should flip all 
/// values in the subtree of the node with the label queries[i].
///
/// Return the total number of nodes with the value 1 after processing all 
/// the queries.
///
/// Note that:
/// Flipping the value of a node means that the node with the value 0 
/// becomes 1 and vice versa.
/// floor(x) is equivalent to rounding x down to the nearest integer.
///
/// Example 1:
/// Input: n = 5 , queries = [1,2,5]
/// Output: 3
/// Explanation: The diagram above shows the tree structure and its status 
/// after performing the queries. The blue node represents the value 0, 
/// and the red node represents the value 1.
/// After processing the queries, there are three red nodes (nodes with 
/// value 1): 1, 3, and 5.
///
/// Example 2:
/// Input: n = 3, queries = [2,3,3]
/// Output: 1
/// Explanation: The diagram above shows the tree structure and its 
/// status after performing the queries. The blue node represents the 
/// value 0, and the red node represents the value 1.
/// After processing the queries, there are one red node (node with 
/// value 1): 2.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= queries.length <= 10^5
/// 3. 1 <= queries[i] <= n
/// </summary>
int LeetCodeTree::numberOfNodes(int n, vector<int>& queries)
{
    vector<int> flags(n + 1);
    for (size_t i = 0; i < queries.size(); i++)
    {
        flags[queries[i]] = (flags[queries[i]] + 1) % 2;
    }
    return numberOfNodes(n, 1, flags);
}


/// <summary>
/// Leet Code 2471. Minimum Number of Operations to Sort a Binary Tree 
///                 by Level
/// 
/// Medium
///	
/// You are given the root of a binary tree with unique values.
///
/// In one operation, you can choose any two nodes at the same level 
/// and swap their values.
///
/// Return the minimum number of operations needed to make the values 
/// at each level sorted in a strictly increasing order.
///
/// The level of a node is the number of edges along the path between 
/// it and the root node.
///
/// Example 1:
/// Input: root = [1,4,3,7,6,8,5,null,null,null,null,9,null,10]
/// Output: 3
/// Explanation:
/// - Swap 4 and 3. The 2nd level becomes [3,4].
/// - Swap 7 and 5. The 3rd level becomes [5,6,8,7].
/// - Swap 8 and 7. The 3rd level becomes [5,6,7,8].
/// We used 3 operations so return 3.
/// It can be proven that 3 is the minimum number of operations needed.
///
/// Example 2:
/// Input: root = [1,3,2,7,6,5,4]
/// Output: 3
/// Explanation:
/// - Swap 3 and 2. The 2nd level becomes [2,3].
/// - Swap 7 and 4. The 3rd level becomes [4,6,5,7].
/// - Swap 6 and 5. The 3rd level becomes [4,5,6,7].
/// We used 3 operations so return 3.
/// It can be proven that 3 is the minimum number of operations needed.
///
/// Example 3:
/// Input: root = [1,2,3,4,5,6]
/// Output: 0
/// Explanation: Each level is already sorted in increasing order so 
/// return 0.
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 1 <= Node.val <= 105
/// 3. All the values of the tree are unique.
/// </summary>
int LeetCodeTree::minimumOperations(TreeNode* root)
{
    queue<TreeNode*> queue;
    queue.push(root);
    int result = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        vector<int> arr;
        set<pair<int, int>> pq;
        for (int i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
            arr.push_back(node->val);
            pq.insert(make_pair(node->val, arr.size() - 1));
        }
        for (size_t i = 0; i < arr.size(); i++)
        {
            pair<int, int> pair = *pq.begin();
            pq.erase(pq.begin());
            if (arr[i] == pair.first) continue;
            else
            {
                pq.erase(make_pair(arr[i], i));
                pq.insert(make_pair(arr[i], pair.second));
                swap(arr[i], arr[pair.second]);
                result++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2476. Closest Nodes Queries in a Binary Search Tree 
/// </summary>
void LeetCodeTree::closestNodesSort(TreeNode* node, vector<int>& sorted)
{
    if (node->left != nullptr)
    {
        closestNodesSort(node->left, sorted);
    }
    sorted.push_back(node->val);
    if (node->right != nullptr)
    {
        closestNodesSort(node->right, sorted);
    }
}

/// <summary>
/// Leet Code 2476. Closest Nodes Queries in a Binary Search Tree 
/// 
/// Medium
///	
/// You are given the root of a binary search tree and an array queries of 
/// size n consisting of positive integers.
///
/// Find a 2D array answer of size n where answer[i] = [mini, maxi]:
///
/// mini is the largest value in the tree that is smaller than or equal to 
/// queries[i]. If a such value does not exist, add -1 instead.
/// maxi is the smallest value in the tree that is greater than or equal to
/// queries[i]. If a such value does not exist, add -1 instead.
/// Return the array answer.
///
/// Example 1:
/// Input: root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], 
/// queries = [2,5,16]
/// Output: [[2,2],[4,6],[15,-1]]
/// Explanation: We answer the queries in the following way:
/// - The largest number that is smaller or equal than 2 in the tree 
///   is 2, and the smallest number that is greater or equal than 2 
///   is still 2. So the answer for the first query is [2,2].
/// - The largest number that is smaller or equal than 5 in the tree is 4, 
/// and the smallest number that is greater or equal than 5 is 6. So the 
/// answer for the second query is [4,6].
/// - The largest number that is smaller or equal than 16 in the tree 
///   is 15, and the smallest number that is greater or equal than 16 
///   does not exist. So the answer for the third query is [15,-1].
///
/// Example 2:
/// Input: root = [4,null,9], queries = [3]
/// Output: [[-1,4]]
/// Explanation: The largest number that is smaller or equal to 3 in 
/// the tree does not exist, and the smallest number that is greater or 
/// equal to 3 is 4. So the answer for the query is [-1,4].
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [2, 10^5].
/// 2. 1 <= Node.val <= 10^6
/// 3. n == queries.length
/// 4. 1 <= n <= 10^5
/// 5. 1 <= queries[i] <= 10^6
/// </summary>
vector<vector<int>> LeetCodeTree::closestNodes(TreeNode* root, vector<int>& queries)
{
    vector<int> sorted;
    closestNodesSort(root, sorted);
    int n = queries.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].first = queries[i];
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> result(n, vector<int>(2, -1));
    int index = 0;
    int val = -1;
    for (int i = 0; i < n; i++)
    {
        while (index < (int)sorted.size())
        {
            if (sorted[index] <= arr[i].first)
            {
                val = sorted[index];
                index++;
            }
            else break;
        }
        result[arr[i].second][0] = val;
    }
    index = sorted.size() - 1;
    val = -1;
    for (int i = n-1; i >= 0; i--)
    {
        while (index >= 0)
        {
            if (sorted[index] >= arr[i].first)
            {
                val = sorted[index];
                index--;
            }
            else break;
        }
        result[arr[i].second][1] = val;
    }
    return result;
}

/// <summary>
/// Leet Code 2458. Height of Binary Tree After Subtree Removal Queries
/// </summary>
int LeetCodeTree::treeQueriesDepth(TreeNode* root, int level, unordered_map<int, int>& levels, 
    unordered_map<int, int>& depths, unordered_map<int, int>& depth1, 
    unordered_map<int, int>& depth2)
{
    int left = -1;
    int right = -1;
    levels[root->val] = level;
    if (root->left != nullptr)
    {
        left = treeQueriesDepth(root->left, level + 1, levels, depths, depth1, depth2);
    }
    if (root->right != nullptr)
    {
        right = treeQueriesDepth(root->right, level + 1, levels, depths, depth1, depth2);
    }
    int depth = max(left, right) + 1;
    if (depth1.count(level) == 0) depth1[level] = -1;
    if (depth2.count(level) == 0) depth2[level] = -1;
    if (depth1[level] < depth)
    {
        depth2[level] = depth1[level];
        depth1[level] = depth;
    }
    else if (depth2[level] < depth)
    {
        depth2[level] = depth;
    }
    depths[root->val] = depth;
    return depth;
}

/// <summary>
/// Leet Code 2458. Height of Binary Tree After Subtree Removal Queries
/// 
/// Medium
///
/// You are given the root of a binary tree with n nodes. Each node is 
/// assigned a unique value from 1 to n. You are also given an array 
/// queries of size m.
///
/// You have to perform m independent queries on the tree where in 
/// the ith query you do the following:
///
/// Remove the subtree rooted at the node with the value queries[i] from 
/// the tree. It is guaranteed that queries[i] will not be equal to the 
/// value of the root.
/// Return an array answer of size m where answer[i] is the height of the 
/// tree after performing the ith query.
///
/// Note:
///
/// The queries are independent, so the tree returns to its initial 
/// state after each query.
/// The height of a tree is the number of edges in the longest simple 
/// path from the root to some node in the tree.
/// 
/// Example 1:
/// Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], 
///        queries = [4]
/// Output: [2]
/// Explanation: The diagram above shows the tree after removing the 
/// subtree rooted at node with value 4.
/// The height of the tree is 2 (The path 1 -> 3 -> 2).
///
/// Example 2:
/// Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
/// Output: [3,2,3,2]
/// Explanation: We have the following queries:
/// - Removing the subtree rooted at node with value 3. The height of the tree 
///   becomes 3 (The path 5 -> 8 -> 2 -> 4).
/// - Removing the subtree rooted at node with value 2. 
///   The height of the tree becomes 2 (The path 5 -> 8 -> 1).
/// - Removing the subtree rooted at node with value 4. 
///   The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
/// - Removing the subtree rooted at node with value 8. The height 
///   of the tree becomes 2 (The path 5 -> 9 -> 3).
///
/// Constraints:
/// 1. The number of nodes in the tree is n.
/// 2. 2 <= n <= 10^5
/// 3. 1 <= Node.val <= n
/// 4. All the values in the tree are unique.
/// 5. m == queries.length
/// 6. 1 <= m <= min(n, 10^4)
/// 7. 1 <= queries[i] <= n
/// 8. queries[i] != root.val
/// </summary>
vector<int> LeetCodeTree::treeQueries(TreeNode* root, vector<int>& queries)
{
    unordered_map<int, int> levels;
    unordered_map<int, int> depths;
    unordered_map<int, int> depth1;
    unordered_map<int, int> depth2;

    treeQueriesDepth(root, 0, levels, depths, depth1, depth2);
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        int node = queries[i];
        int level = levels[node];
        int depth = depths[node];
        if (depth1[level] == depth)
        {
            result[i] = level + depth2[level];
        }
        else
        {
            result[i] = level + depth1[level];
        }

    }
    return result;
}

/// <summary>
/// Leet Code 2509. Cycle Length Queries in a Tree
/// 
/// Hard
///	
/// You are given an integer n. There is a complete binary tree with 
/// 2n - 1 nodes. The root of that tree is the node with the value 1, 
/// and every node with a value val in the range [1, 2n - 1 - 1] has 
/// two children where:
///
/// The left node has the value 2 * val, and
/// The right node has the value 2 * val + 1.
/// You are also given a 2D integer array queries of length m, where 
/// queries[i] = [ai, bi]. For each query, solve the following 
/// problem:
///
/// Add an edge between the nodes with values ai and bi.
/// Find the length of the cycle in the graph.
/// Remove the added edge between nodes with values ai and bi.
/// Note that:
/// A cycle is a path that starts and ends at the same node, and each 
/// edge in the path is visited only once.
/// The length of a cycle is the number of edges visited in the cycle.
/// There could be multiple edges between two nodes in the tree after 
/// adding the edge of the query.
/// Return an array answer of length m where answer[i] is the answer 
/// to the ith query.
/// 
/// Example 1:
/// 1. Input: n = 3, queries = [[5,3],[4,7],[2,3]]
/// 2. Output: [4,5,3]
/// Explanation: The diagrams above show the tree of 2^3 - 1 nodes. 
/// Nodes colored in red describe the nodes in the cycle after adding 
/// the edge.
/// - After adding the edge between nodes 3 and 5, the graph contains 
///   a cycle of nodes [5,2,1,3]. Thus answer to the first query is 4. 
///   We delete the added edge and process the next query.
/// - After adding the edge between nodes 4 and 7, the graph contains 
///   a cycle of nodes [4,2,1,3,7]. Thus answer to the second query is 5. 
///   We delete the added edge and process the next query.
/// - After adding the edge between nodes 2 and 3, the graph contains 
///   a cycle of nodes [2,1,3]. Thus answer to the third query is 3. 
///   We delete the added edge.
///
/// Example 2:
/// Input: n = 2, queries = [[1,2]]
/// Output: [2]
/// Explanation: The diagram above shows the tree of 22 - 1 nodes. Nodes 
/// colored in red describe the nodes in the cycle after adding the edge.
/// - After adding the edge between nodes 1 and 2, the graph contains a 
///   cycle of nodes [2,1]. Thus answer for the first query is 2. We 
///   delete the added edge.
/// 
/// Constraints:
/// 1. 2 <= n <= 30
/// 2. m == queries.length
/// 3. 1 <= m <= 10^5
/// 4. queries[i].length == 2
/// 5. 1 <= ai, bi <= 2n - 1
/// 6. ai != bi
/// </summary>
vector<int> LeetCodeTree::cycleLengthQueries(int n, vector<vector<int>>& queries)
{
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        string str_a, str_b;
        while (a != 0)
        {
            str_a.push_back('0' + a % 2);
            a /= 2;
        }
        while (b != 0)
        {
            str_b.push_back('0' + b % 2);
            b /= 2;
        }
        while (!str_a.empty() && !str_b.empty() && str_a.back() == str_b.back())
        {
            str_a.pop_back();
            str_b.pop_back();
        }
        result[i] = str_a.size() + str_b.size() + 1;
    }
    return result;
}

/// <summary>
/// Leet Code 2538. Difference Between Maximum and Minimum Price Sum
/// </summary>
vector<long long> LeetCodeTree::maxOutput(int prev, int curr, 
    vector<vector<int>>& neighbors, 
    vector<int>& price,
    long long& result) 
{
    vector<long long> paths(2);
    paths[0] = price[curr];
    paths[1] = 0;
    for (size_t i = 0; i < neighbors[curr].size(); i++)
    {
        int next = neighbors[curr][i];
        if (next == prev) continue;
        vector<long long > sub = maxOutput(curr, next, neighbors, price, result);
        result = max(result, paths[0] + sub[1]);
        result = max(result, paths[1] + sub[0]);
        paths[0] = max(paths[0], (long long)price[curr] + sub[0]);
        paths[1] = max(paths[1], (long long)price[curr] + sub[1]);
    }
    return paths;
}

/// <summary>
/// Leet Code 2538. Difference Between Maximum and Minimum Price Sum
/// 
/// Hard
///	
/// There exists an undirected and initially unrooted tree with n nodes 
/// indexed from 0 to n - 1. You are given the integer n and a 2D integer 
/// array edges of length n - 1, where edges[i] = [ai, bi] indicates that 
/// there is an edge between nodes ai and bi in the tree.
///  
/// Each node has an associated price. You are given an integer array 
/// price, where price[i] is the price of the ith node.
///  
/// The price sum of a given path is the sum of the prices of all nodes 
/// lying on that path.
///
/// The tree can be rooted at any node root of your choice. The incurred 
/// cost after choosing root is the difference between the maximum and 
/// minimum price sum amongst all paths starting at root.
///
/// Return the maximum possible cost amongst all possible root choices.
/// 
/// Example 1:
/// Input: n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], 
/// price = [9,8,7,6,10,5]
/// Output: 24
/// Explanation: The diagram above denotes the tree after rooting it at 
/// node 2. The first part (colored in red) shows the path with the 
/// maximum price sum. The second part (colored in blue) shows the path 
/// with the minimum price sum.
/// - The first path contains nodes [2,1,3,4]: the prices are [7,8,6,10], 
///   and the sum of the prices is 31.
/// - The second path contains the node [2] with the price [7].
/// The difference between the maximum and minimum price sum is 24. It 
/// can be proved that 24 is the maximum cost.
///
/// Example 2:
/// Input: n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
/// Output: 2
/// Explanation: The diagram above denotes the tree after rooting it at 
/// node 0. The first part (colored in red) shows the path with the 
/// maximum price sum. The second part (colored in blue) shows the path 
/// with the minimum price sum.
/// - The first path contains nodes [0,1,2]: the prices are [1,1,1], and 
///   the sum of the prices is 3.
/// - The second path contains node [0] with a price [1].
/// The difference between the maximum and minimum price sum is 2. It can 
/// be proved that 2 is the maximum cost.
///
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. edges.length == n - 1
/// 3. 0 <= ai, bi <= n - 1
/// 4. edges represents a valid tree.
/// 5. price.length == n
/// 6. 1 <= price[i] <= 10^5
/// </summary>
long long LeetCodeTree::maxOutput(int n, vector<vector<int>>& edges, vector<int>& price)
{
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    long long result = 0;
    maxOutput(-1, 0, neighbors, price, result);
    return result;
}

/// <summary>
/// Leet Code 2583. Kth Largest Sum in a Binary Tree
/// 
/// Medium
///	
/// You are given the root of a binary tree and a positive integer k.
/// The level sum in the tree is the sum of the values of the nodes that 
/// are on the same level.
///
/// Return the kth largest level sum in the tree (not necessarily 
/// distinct). If there are fewer than k levels in the tree, return -1.
///
/// Note that two nodes are on the same level if they have the same 
/// distance from the root.
///
/// Example 1:
/// Input: root = [5,8,9,2,1,3,7,4,6], k = 2
/// Output: 13
/// Explanation: The level sums are the following:
/// - Level 1: 5.
/// - Level 2: 8 + 9 = 17.
/// - Level 3: 2 + 1 + 3 + 7 = 13.
/// - Level 4: 4 + 6 = 10.
/// The 2nd largest level sum is 13.
///
/// Example 2:
/// Input: root = [1,2,null,3], k = 1
/// Output: 3
/// Explanation: The largest level sum is 3.
///
/// Constraints:
/// 1. The number of nodes in the tree is n.
/// 2. 2 <= n <= 10^5
/// 3. 1 <= Node.val <= 10^6
/// 4. 1 <= k <= n
/// </summary>
long long LeetCodeTree::kthLargestLevelSum(TreeNode* root, int k)
{
    priority_queue<long long> level_sums;
    queue<TreeNode*> queue;
    queue.push(root);
    int level = 0;
    while (!queue.empty())
    {
        long long sum = 0;
        level++;
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();
            sum += node->val;
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);
        }
        level_sums.push(sum);
    }
    if (level_sums.size() < (size_t)k) return -1;
    long long result = 0;
    while (k > 0)
    {
        result = level_sums.top();
        level_sums.pop();
        k--;
    }
    return result;
}

/// <summary>
/// Leet Code 2581. Count Number of Possible Root Nodes
/// 
/// Hard
///	
/// Alice has an undirected tree with n nodes labeled from 0 to n - 1. 
/// The tree is represented as a 2D integer array edges of length n - 1 
/// where edges[i] = [ai, bi] indicates that there is an edge between 
/// nodes ai and bi in the tree.
///
/// Alice wants Bob to find the root of the tree. She allows Bob to make 
/// several guesses about her tree. In one guess, he does the following:
///
/// Chooses two distinct integers u and v such that there exists an 
/// edge [u, v] in the tree.
/// He tells Alice that u is the parent of v in the tree.
/// Bob's guesses are represented by a 2D integer array guesses where 
/// guesses[j] = [uj, vj] indicates Bob guessed uj to be the parent of vj.
/// 
/// Alice being lazy, does not reply to each of Bob's guesses, but just 
/// says that at least k of his guesses are true.
/// 
/// Given the 2D integer arrays edges, guesses and the integer k, return 
/// the number of possible nodes that can be the root of Alice's tree. 
/// If there is no such tree, return 0.
/// 
/// Example 1:
/// Input: edges = [[0,1],[1,2],[1,3],[4,2]], 
/// guesses = [[1,3],[0,1],[1,0],[2,4]], k = 3
/// Output: 3
/// Explanation: 
/// Root = 0, correct guesses = [1,3], [0,1], [2,4]
/// Root = 1, correct guesses = [1,3], [1,0], [2,4]
/// Root = 2, correct guesses = [1,3], [1,0], [2,4]
/// Root = 3, correct guesses = [1,0], [2,4]
/// Root = 4, correct guesses = [1,3], [1,0]
/// Considering 0, 1, or 2 as root node leads to 3 correct guesses.
///
/// Example 2:
/// Input: edges = [[0,1],[1,2],[2,3],[3,4]], 
/// guesses = [[1,0],[3,4],[2,1],[3,2]], k = 1
/// Output: 5
/// Explanation: 
/// Root = 0, correct guesses = [3,4]
/// Root = 1, correct guesses = [1,0], [3,4]
/// Root = 2, correct guesses = [1,0], [2,1], [3,4]
/// Root = 3, correct guesses = [1,0], [2,1], [3,2], [3,4]
/// Root = 4, correct guesses = [1,0], [2,1], [3,2]
/// Considering any node as root will give at least 1 correct guess. 
///
/// Constraints:
/// 1. edges.length == n - 1
/// 2. 2 <= n <= 10^5
/// 3. 1 <= guesses.length <= 10^5
/// 4. 0 <= ai, bi, uj, vj <= n - 1
/// 5. ai != bi
/// 6. uj != vj
/// 7. edges represents a valid tree.
/// 8. guesses[j] is an edge of the tree.
/// 9. guesses is unique.
/// 10. 0 <= k <= guesses.length
/// </summary>
int LeetCodeTree::rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k)
{
    int n = edges.size() + 1;
    vector<vector<int>> edge(n);
    vector<unordered_set<int>> guess(n);
    vector<int> visited(n), root(n);
    for (size_t i = 0; i < guesses.size(); i++)
    {
        guess[guesses[i][0]].insert(guesses[i][1]);
    }
    for (size_t i = 0; i < edges.size(); i++)
    {
        edge[edges[i][0]].push_back(edges[i][1]);
        edge[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> q1;
    q1.push(0);
    visited[0] = 1;
    int count = 0;
    int result = 0;
    while (!q1.empty())
    {
        int node = q1.front();
        q1.pop();
        for (size_t i = 0; i < edge[node].size(); i++)
        {
            int child = edge[node][i];
            if (visited[child] == 1) continue;
            visited[child] = 1;
            if (guess[node].count(child) > 0) count++;
            q1.push(child);
        }
    }
    if (count >= k) result++;

    queue<pair<int, int>> q2;
    q2.push(make_pair(0, count));
    root[0] = 1;
    while (!q2.empty())
    {
        pair<int, int> pair = q2.front();
        q2.pop();
        int r = pair.first;
        for (size_t i = 0; i < edge[r].size(); i++)
        {
            int count = pair.second;
            int child = edge[r][i];
            if (root[child] == 1) continue;
            root[child] = 1;
            if (guess[r].count(child) > 0) count--;
            if (guess[child].count(r) > 0) count++;
            if (count >= k) result++;
            q2.push(make_pair(child, count));
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2641. Cousins in Binary Tree II
/// 
/// Medium
///	
/// Given the root of a binary tree, replace the value of each node in 
/// the tree with the sum of all its cousins' values.
///
/// Two nodes of a binary tree are cousins if they have the same depth 
/// with different parents.
/// 
/// Return the root of the modified tree.
///
/// Note that the depth of a node is the number of edges in the path 
/// from the root node to it.
/// 
/// Example 1:
/// Input: root = [5,4,9,1,10,null,7]
/// Output: [0,0,0,7,7,null,11]
/// Explanation: The diagram above shows the initial binary tree and 
/// the binary tree after changing the value of each node.
/// - Node with value 5 does not have any cousins so its sum is 0.
/// - Node with value 4 does not have any cousins so its sum is 0.
/// - Node with value 9 does not have any cousins so its sum is 0.
/// - Node with value 1 has a cousin with value 7 so its sum is 7.
/// - Node with value 10 has a cousin with value 7 so its sum is 7.
/// - Node with value 7 has cousins with values 1 and 10 so its sum is 11.
///
/// Example 2:
/// Input: root = [3,1,2]
/// Output: [0,0,0]
/// Explanation: The diagram above shows the initial binary tree and the 
/// binary tree after changing the value of each node.
/// - Node with value 3 does not have any cousins so its sum is 0.
/// - Node with value 1 does not have any cousins so its sum is 0.
/// - Node with value 2 does not have any cousins so its sum is 0.
/// 
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 1 <= Node.val <= 10^4
/// </summary>
TreeNode* LeetCodeTree::replaceValueInTree(TreeNode* root)
{
    queue<TreeNode*> queue;
    queue.push(root);
    unordered_map<TreeNode*, TreeNode*> parent_map;
    unordered_map<TreeNode*, int> parent_sum;
    int prev_sum = 0;
    parent_map[nullptr] = root;
    parent_sum[nullptr] = 0;
    while (!queue.empty())
    {
        int sum = 0;
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode* node = queue.front();
            TreeNode* parent_node = parent_map[node];
            node->val = prev_sum - parent_sum[parent_node];
            queue.pop();
            if (node->left != nullptr)
            {
                parent_map[node->left] = node;
                parent_sum[node] += node->left->val;
                sum += node->left->val;
                queue.push(node->left);
            }
            if (node->right != nullptr)
            {
                parent_map[node->right] = node;
                parent_sum[node] += node->right->val;
                sum += node->right->val;
                queue.push(node->right);
            }
        }
        prev_sum = sum;
    }
    return root;
}

/// <summary>
/// Leet Code 2673. Make Costs of Paths Equal in a Binary Tree
/// 
/// Medium
///	
/// You are given a 0-indexed array nums of length n.
///
/// You are given an integer n representing the number of nodes in a 
/// perfect binary tree consisting of nodes numbered from 1 to n. The 
/// root of the tree is node 1 and each node i in the tree has two 
/// children where the left child is the node 2 * i and the right 
/// child is 2 * i + 1.
///
/// Each node in the tree also has a cost represented by a given 
/// 0-indexed integer array cost of size n where cost[i] is the 
/// cost of node i + 1. You are allowed to increment the cost of any 
/// node by 1 any number of times.
///
/// Return the minimum number of increments you need to make the cost 
/// of paths from the root to each leaf node equal.
///
/// Note:
/// A perfect binary tree is a tree where each node, except the leaf 
/// nodes, has exactly 2 children.
/// The cost of a path is the sum of costs of nodes in the path.
///
/// Example 1:
/// Input: n = 7, cost = [1,5,2,2,3,3,1]
/// Output: 6
/// Explanation: We can do the following increments:
/// - Increase the cost of node 4 one time.
/// - Increase the cost of node 3 three times.
/// - Increase the cost of node 7 two times.
/// Each path from the root to a leaf will have a total cost of 9.
/// The total increments we did is 1 + 3 + 2 = 6.
/// It can be shown that this is the minimum answer we can achieve.
///
/// Example 2:
/// Input: n = 3, cost = [5,3,3]
/// Output: 0
/// Explanation: The two paths already have equal total costs, so 
/// no increments are needed.
///
/// Constraints:
/// 1. 3 <= n <= 10^5
/// 2. n + 1 is a power of 2
/// 3. cost.length == n
/// 4. 1 <= cost[i] <= 10^4
/// </summary>
int LeetCodeTree::minIncrements(int n, vector<int>& cost)
{
    vector<int> sum(cost.size()), max_val(cost.size()), increment(cost.size());
    int result = 0;
    int max_sum = 0;
    for (size_t i = 0; i < cost.size(); i++)
    {
        sum[i] = cost[i];
        if (i > 0) sum[i] += sum[(i - 1) / 2];
        max_sum = max(max_sum, sum[i]);
    }
    for (int i = cost.size() - 1; i > 0; i--)
    {
        max_val[i] = max(max_val[i], sum[i]);
        max_val[(i - 1) / 2] = max(max_val[(i - 1) / 2], max_val[i]);
    }
    for (int i = 1; i < (int)cost.size(); i++)
    {
        increment[i] += increment[(i - 1) / 2];
        if (max_val[i] + increment[i] < max_sum)
        {
            result += max_sum - max_val[i] - increment[i];
            increment[i] += max_sum - max_val[i] - increment[i];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2689. Extract Kth Character From The Rope Tree
/// </summary>
string LeetCodeTree::getKthCharacter(RopeTreeNode* node)
{
    string result;
    if (node == nullptr) return result;
    if (node->len == 0)
    {
        result = node->val;
    }
    else
    {
        result = getKthCharacter(node->left) + getKthCharacter(node->right);
    }
    return result;
}


/// <summary>
/// Leet Code 2689. Extract Kth Character From The Rope Tree
/// 
/// Easy
///	
/// You are given the root of a binary tree and an integer k. Besides the 
/// left and right children, every node of this tree has two other 
/// properties, a string node.val containing only lowercase English 
/// letters (possibly empty) and a non-negative integer node.len. There 
/// are two types of nodes in this tree:
///
/// Leaf: These nodes have no children, node.len = 0, and node.val is some 
/// non-empty string.
/// Internal: These nodes have at least one child (also at most two 
/// children), node.len > 0, and node.val is an empty string.
/// The tree described above is called a Rope binary tree. Now we define 
/// S[node] recursively as follows:
///
/// If node is some leaf node, S[node] = node.val,
/// Otherwise if node is some internal node, S[node] = 
/// concat(S[node.left], S[node.right]).
/// Return k-th character of the string S[root].
/// Note: If s and p are two strings, concat(s, p) is a string obtained 
/// by concatenating p to s. For example, concat("ab", "zz") = "abzz".
///
/// Example 1:
/// Input: root = [10,4,"abcpoe","g","rta"], k = 6
/// Output: "b"
/// Explanation: In the picture below, we put an integer on internal 
/// nodes that represents node.len, and a string on leaf nodes that 
/// represents node.val.
/// You can see that S[root] = concat(concat("g", "rta"), "abcpoe") = 
/// "grtaabcpoe". So S[root][5], which represents 6th character of it, 
/// is equal to "b".
///
/// Example 2:
/// Input: root = [12,6,6,"abc","efg","hij","klm"], k = 3
/// Output: "c"
/// Explanation: In the picture below, we put an integer on internal 
/// nodes that represents node.len, and a string on leaf nodes that 
/// represents node.val.
/// You can see that S[root] = concat(concat("abc", "efg"), 
/// concat("hij", "klm")) = "abcefghijklm". So S[root][2], which 
/// represents the 3rd character of it, is equal to "c".
///
/// Example 3:
/// Input: root = ["ropetree"], k = 8
/// Output: "e"
/// Explanation: In the picture below, we put an integer on 
/// internal nodes that represents node.len, and a string on 
/// leaf nodes that represents node.val.
/// You can see that S[root] = "ropetree". So S[root][7], which 
/// represents 8th character of it, is equal to "e".
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^3]
/// 2. node.val contains only lowercase English letters
/// 3. 0 <= node.val.length <= 50
/// 4. 0 <= node.len <= 10^4
/// 5. for leaf nodes, node.len = 0 and node.val is non-empty
/// 6. for internal nodes, node.len > 0 and node.val is empty
/// 7. 1 <= k <= S[root].length
/// </summary>
char LeetCodeTree::getKthCharacter(RopeTreeNode* root, int k)
{
    string result = getKthCharacter(root);
    return result[k - 1];
}

/// <summary>
/// Leet Code 2764. is Array a Preorder of Some Binary Tree
/// 
/// Medium
///
/// Given a 0-indexed integer 2D array nodes, your task is to determine if 
/// the given array represents the preorder traversal of some binary tree.
///
/// For each index i, nodes[i] = [id, parentId], where id is the id of the 
/// node at the index i and parentId is the id of its parent in the tree 
/// (if the node has no parent, then parentId = -1).
///
/// Return true if the given array represents the preorder traversal of 
/// some tree, and false otherwise.
/// 
/// Note: the preorder traversal of a tree is a recursive way to traverse 
/// a tree in which we first visit the current node, then we do the 
/// preorder traversal for the left child, and finally, we do it for the 
/// right child.
/// 
/// Example 1:
/// Input: nodes = [[0,-1],[1,0],[2,0],[3,2],[4,2]]
/// Output: true
/// Explanation: The given nodes make the tree in the picture below.
/// We can show that this is the preorder traversal of the tree, first we 
/// visit node 0, then we do the preorder traversal of the right child 
/// which is [1], then we do the preorder traversal of the left child 
/// which is [2,3,4].
/// 
/// Example 2:
/// Input: nodes = [[0,-1],[1,0],[2,0],[3,1],[4,1]]
/// Output: false
/// Explanation: The given nodes make the tree in the picture below.
/// For the preorder traversal, first we visit node 0, then we do the 
/// preorder traversal of the right child which is [1,3,4], but we can 
/// see that in the given order, 2 comes between 1 and 3, so, it's not 
/// the preorder traversal of the tree.
/// 
/// Constraints:
/// 1. 1 <= nodes.length <= 10^5
/// 2. nodes[i].length == 2
/// 3. 0 <= nodes[i][0] <= 10^5
/// 4. -1 <= nodes[i][1] <= 10^5
/// 5. The input is generated such that nodes make a binary tree.
/// </summary>
bool LeetCodeTree::isPreorder(vector<vector<int>>& nodes)
{
    stack<TreeNode*> stack;
    TreeNode * root = nullptr;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i][1] == -1)
        {
            if (root != nullptr) return false;
            root = new TreeNode(nodes[i][0]);
        }
        else
        {
            while (root != nullptr && root->val != nodes[i][1])
            {
                stack.pop();
                if (stack.empty()) root = nullptr;
                else root = stack.top();
            }
            if (root == nullptr)
            {
                return false;
            }
            if (root->left == nullptr)
            {
                root->left = new TreeNode(nodes[i][0]);
                root = root->left;
            }
            else if (root->right == nullptr)
            {
                root->right = new TreeNode(nodes[i][0]);
                root = root->right;
            }
            else
            {
                return false;
            }
        }
        stack.push(root);
    }
    return true;
}

/// <summary>
/// Leet Code 2773. Height of Special Binary Tree
/// 
/// Medium
///
/// You are given a root which is the root of a binary tree with n nodes. 
/// The nodes of the binary tree are numbered from 1 to n. Suppose the 
/// tree has k leaves in the following order: b1 < b2 < ... < bk.
///
/// The leaves of this tree have a special property! That is, for every 
/// leaf bi, the following conditions hold:
///
/// The right child of bi is bi + 1 if i < k, and b1 otherwise.
/// The left child of bi is bi - 1 if i > 1, and bk otherwise.
/// Return the height of the given tree.
///
/// Note: The height of a binary tree is the length of the longest path 
/// from the root to any other node.
/// 
/// Example 1:
/// Input: root = [1,2,3,null,null,4,5]
/// Output: 2
/// Explanation: The given tree is shown in the following picture. Each 
/// leaf's left child is the leaf to its left (shown with the blue edges). 
/// Each leaf's right child is the leaf to its right (shown with the red 
/// edges). We can see that the graph has a height of 2.
///
/// Example 2:
/// Input: root = [1,2]
/// Output: 1
/// Explanation: The given tree is shown in the following picture. There 
/// is only one leaf, so it doesn't have any left or right child. We 
/// can see that the graph has a height of 1.
/// 
/// Example 3:
/// Input: root = [1,2,3,null,null,4,null,5,6]
/// Output: 3
/// Explanation: The given tree is shown in the following picture. Each 
/// leaf's left child is the leaf to its left (shown with the blue edges). 
/// Each leaf's right child is the leaf to its right (shown with the 
/// red edges). We can see that the graph has a height of 3.
/// 
/// Constraints:
/// 1. n == number of nodes in the tree
/// 2. 2 <= n <= 10^4
/// 3. 1 <= node.val <= n
/// 4. The input is generated such that each node.val is unique.
/// </summary>
int LeetCodeTree::heightOfTree(TreeNode* root)
{
    if (root->left != nullptr && root->left->right == root &&
        root->right != nullptr && root->right->left == root)
    {
        return 0;
    }
    int result = 0;
    if (root->left != nullptr)
    {
        result = max(result, 1 + heightOfTree(root->left));
    }
    if (root->right != nullptr)
    {
        result = max(result, 1 + heightOfTree(root->right));
    }
    return result;
}

/// <summary>
/// Leet Code 2791. Count Paths That Can Form a Palindrome in a Tree
/// </summary>
void LeetCodeTree::countPalindromePaths(vector<vector<int>>& children, int node, string& s,
    int bits, unordered_map<int, int>& count, long long &result)
{
    bits ^= 1 << (s[node] - 'a');
    result += count[bits];
    count[bits]++;
    for (int i = 0; i < 26; i++)
    {
        int new_bits = bits ^ (1 << i);
        if (count.count(new_bits) > 0)
        {
            result += count[new_bits];
        }
    }
    for (size_t i = 0; i < children[node].size(); i++)
    {
        countPalindromePaths(children, children[node][i], s, bits, count, result);
    }
}

/// <summary>
/// Leet Code 2791. Count Paths That Can Form a Palindrome in a Tree
/// 
/// Hard
///
/// You are given a tree (i.e. a connected, undirected graph that has no 
/// cycles) rooted at node 0 consisting of n nodes numbered from 0 to 
/// n - 1. The tree is represented by a 0-indexed array parent of size n, 
/// where parent[i] is the parent of node i. Since node 0 is the root, 
/// parent[0] == -1.
///
/// You are also given a string s of length n, where s[i] is the character 
/// assigned to the edge between i and parent[i]. s[0] can be ignored.
///
/// Return the number of pairs of nodes (u, v) such that u < v and the 
/// characters assigned to edges on the path from u to v can be rearranged 
/// to form a palindrome.
///
/// A string is a palindrome when it reads the same backwards as forwards.
///
/// Example 1:
/// Input: parent = [-1,0,0,1,1,2], s = "acaabc"
/// Output: 8
/// Explanation: The valid pairs are:
/// - All the pairs (0,1), (0,2), (1,3), (1,4) and (2,5) result in one 
///   character which is always a palindrome.
/// - The pair (2,3) result in the string "aca" which is a palindrome.
/// - The pair (1,5) result in the string "cac" which is a palindrome.
/// - The pair (3,5) result in the string "acac" which can be rearranged 
///   into the palindrome "acca".
///
/// Example 2:
/// Input: parent = [-1,0,0,0,0], s = "aaaaa"
/// Output: 10
/// Explanation: Any pair of nodes (u,v) where u < v is valid.
///  
/// Constraints:
/// 1. n == parent.length == s.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= parent[i] <= n - 1 for all i >= 1
/// 4. parent[0] == -1
/// 5. parent represents a valid tree.
/// 6. s consists of only lowercase English letters.
/// </summary>
long long LeetCodeTree::countPalindromePaths(vector<int>& parent, string s)
{
    int n = parent.size();
    vector<vector<int>> children(n);
    for (size_t i = 1; i < parent.size(); i++)
    {
        children[parent[i]].push_back(i);
    }
    unordered_map<int, int> count;
    count[0] = 1;
    long long result = 0;
    int bits = 0;
    for (size_t i = 0; i < children[0].size(); i++)
    {
        countPalindromePaths(children, children[0][i], s,
            0, count, result);
    }
    return result;
}

/// <summary>
/// Leet Code 2792. Count Nodes That Are Great Enough
/// </summary>
int LeetCodeTree::countGreatEnoughNodes(TreeNode* node, int k, priority_queue<int>& pq)
{
    if (node == nullptr)
    {
        return 0;
    }
    priority_queue<int> pq_left;
    int result = countGreatEnoughNodes(node->left, k, pq_left);
    priority_queue<int> pq_right;
    result += countGreatEnoughNodes(node->right, k, pq_right);
    while (!pq_left.empty())
    {
        pq.push(pq_left.top());
        pq_left.pop();
    }
    while (!pq_right.empty())
    {
        pq.push(pq_right.top());
        pq_right.pop();
    }
    while ((int)pq.size() > k) pq.pop();
    if (pq.empty() || node->val <= pq.top() || (int)pq.size() < k)
    {
        pq.push(node->val);
        if ((int)pq.size() > k) pq.pop();
    }
    else
    {
        result++;
    }
    return result;
}

/// <summary>
/// Leet Code 2792. Count Nodes That Are Great Enough
/// 
/// Hard
///
/// You are given a root to a binary tree and an integer k. A node of 
/// this tree is called great enough if the followings hold:
///
/// Its subtree has at least k nodes.
/// Its value is greater than the value of at least k nodes in its subtree.
///
/// Return the number of nodes in this tree that are great enough.
///
/// The node u is in the subtree of the node v, if u == v or v is an 
/// ancestor of u.
///
/// Example 1:
/// Input: root = [7,6,5,4,3,2,1], k = 2
/// Output: 3
/// Explanation: Number the nodes from 1 to 7.
/// The values in the subtree of node 1: {1,2,3,4,5,6,7}. Since 
/// node.val == 7, there are 6 nodes having a smaller value than its 
/// value. So it's great enough.
/// The values in the subtree of node 2: {3,4,6}. Since node.val == 6, 
/// there are 2 nodes having a smaller value than its value. So it's 
/// great enough.
/// The values in the subtree of node 3: {1,2,5}. Since node.val == 5, 
/// there are 2 nodes having a smaller value than its value. So it's 
/// great enough.
/// It can be shown that other nodes are not great enough.
/// See the picture below for a better understanding.
/// 
/// Example 2:
/// Input: root = [1,2,3], k = 1
/// Output: 0
/// Explanation: Number the nodes from 1 to 3.
/// The values in the subtree of node 1: {1,2,3}. Since node.val == 1, 
/// there are no nodes having a smaller value than its value. So it's 
/// not great enough.
/// The values in the subtree of node 2: {2}. Since node.val == 2, there 
/// are no nodes having a smaller value than its value. So it's not great 
/// enough.
/// The values in the subtree of node 3: {3}. Since node.val == 3, there 
/// are no nodes having a smaller value than its value. So it's not great 
/// enough.
/// See the picture below for a better understanding.
///
/// Example 3:
/// Input: root = [3,2,2], k = 2
/// Output: 1
/// Explanation: Number the nodes from 1 to 3.
/// The values in the subtree of node 1: {2,2,3}. Since node.val == 3, 
/// there are 2 nodes having a smaller value than its value. So it's great 
/// enough.
/// The values in the subtree of node 2: {2}. Since node.val == 2, there 
/// are no nodes having a smaller value than its value. So it's not great 
/// enough.
/// The values in the subtree of node 3: {2}. Since node.val == 2, there 
/// are no nodes having a smaller value than its value. So it's not great 
/// enough.
/// See the picture below for a better understanding.
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^4].
/// 2. 1 <= Node.val <= 10^4
/// 3. 1 <= k <= 10
/// </summary>
int LeetCodeTree::countGreatEnoughNodes(TreeNode* root, int k)
{
    priority_queue<int> pq;
    int result = countGreatEnoughNodes(root, k, pq);
    return result;
}

/// <summary>
/// Leet Code 2846. Minimum Edge Weight Equilibrium Queries in a Tree
/// 
/// Hard
///
/// There is an undirected tree with n nodes labeled from 0 to n - 1. You 
/// are given the integer n and a 2D integer array edges of length n - 1, 
/// where edges[i] = [ui, vi, wi] indicates that there is an edge between 
/// nodes ui and vi with weight wi in the tree.
///
/// You are also given a 2D integer array queries of length m, where 
/// queries[i] = [ai, bi]. For each query, find the minimum number of 
/// operations required to make the weight of every edge on the path from 
/// ai to bi equal. In one operation, you can choose any edge of the tree 
/// and change its weight to any value.
///
/// Note that:
///
/// Queries are independent of each other, meaning that the tree returns 
/// to its initial state on each new query.
/// The path from ai to bi is a sequence of distinct nodes starting with 
/// node ai and ending with node bi such that every two adjacent nodes in 
/// the sequence share an edge in the tree.
/// Return an array answer of length m where answer[i] is the answer to 
/// the ith query.
///
/// Example 1:
/// Input: n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],
/// [5,6,2]], queries = [[0,3],[3,6],[2,6],[0,6]]
/// Output: [0,0,1,3]
/// Explanation: In the first query, all the edges in the path from 0 to 3 
/// have a weight of 1. Hence, the answer is 0.
/// In the second query, all the edges in the path from 3 to 6 have a 
/// weight of 2. Hence, the answer is 0.
/// In the third query, we change the weight of edge [2,3] to 2. After 
/// this operation, all the edges in the path from 2 to 6 have a weight 
/// of 2. Hence, the answer is 1.
/// In the fourth query, we change the weights of edges [0,1], [1,2] and 
/// [2,3] to 2. After these operations, all the edges in the path from 0 
/// to 6 have a weight of 2. Hence, the answer is 3.
/// For each queries[i], it can be shown that answer[i] is the minimum 
/// number of operations needed to equalize all the edge weights in the 
/// path from ai to bi.
///
/// Example 2:
/// Input: n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],
/// [3,0,8],[7,0,2]], queries = [[4,6],[0,4],[6,5],[7,4]]
/// Output: [1,2,2,3]
/// Explanation: In the first query, we change the weight of edge [1,3] 
/// to 6. After this operation, all the edges in the path from 4 to 6 
/// have a weight of 6. Hence, the answer is 1.
/// In the second query, we change the weight of edges [0,3] and [3,1] 
/// to 6. After these operations, all the edges in the path from 0 to 4 
/// have a weight of 6. Hence, the answer is 2.
/// In the third query, we change the weight of edges [1,3] and [5,2] 
/// to 6. After these operations, all the edges in the path from 6 to 5 
/// have a weight of 6. Hence, the answer is 2.
/// In the fourth query, we change the weights of edges [0,7], [0,3] 
/// and [1,3] to 6. After these operations, all the edges in the path 
/// from 7 to 4 have a weight of 6. Hence, the answer is 3.
/// For each queries[i], it can be shown that answer[i] is the minimum 
/// number of operations needed to equalize all the edge weights in the 
/// path from ai to bi.
///
/// Constraints:
/// 1. 1 <= n <= 10^4
/// 2. edges.length == n - 1 
/// 3. edges[i].length == 3
/// 4. 0 <= ui, vi < n
/// 5. 1 <= wi <= 26
/// 6. The input is generated such that edges represents a valid tree.
/// 7. 1 <= queries.length == m <= 2 * 10^4
/// 8. queries[i].length == 2
/// 9. 0 <= ai, bi < n
/// </summary>
vector<int> LeetCodeTree::minOperationsQueries(int n, vector<vector<int>>& edges,
    vector<vector<int>>& queries)
{
    vector<vector<pair<int, int>>> children(n);
    int m = 0; while ((1 << m) < n) m++;
    vector<vector<int>> parents(n, vector<int>(m));
    vector<vector<int>> edge_count(n, vector<int>(27));
    vector<int> depths(n, -1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        children[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        children[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    queue<int> queue;
    queue.push(0);
    depths[0] = 0;
    int step = 0;
    while (!queue.empty())
    {
        size_t size = queue.size();
        step++;
        for (size_t i = 0; i < size; i++)
        {
            int parent = queue.front();
            queue.pop();
            for (size_t i = 0; i < children[parent].size(); i++)
            {
                int child = children[parent][i].first;
                int edge = children[parent][i].second;
                if (depths[child] != -1) continue;
                depths[child] = step;
                queue.push(child);
                edge_count[child] = edge_count[parent];
                edge_count[child][edge]++;
                parents[child][0] = parent;
                for (int j = 1; j < m; j++)
                {
                    parents[child][j] = parents[parents[child][j - 1]][j - 1];
                }
            }
        }
    }
    vector<int> result(queries.size());
    for (size_t i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];
        if (depths[a] > depths[b]) swap(a, b);
        // adjust x and y to the same depth:
        for (int p = 0; (1 << p) <= depths[b] - depths[a]; ++p)
        {
            if ((1 << p) & (depths[b] - depths[a])) b = parents[b][p];
        }
        for (int p = m - 1; p >= 0; p--)
        {
            if (parents[a][p] != parents[b][p])
            {
                a = parents[a][p];
                b = parents[b][p];
            }
        }
        int lca = a;
        if (a != b) lca = parents[a][0];
        int max_val = 0;
        int sum = 0;
        a = queries[i][0];
        b = queries[i][1];
        for (int j = 1; j < 27; j++)
        {
            int count = edge_count[a][j] + edge_count[b][j] - 2 * edge_count[lca][j];
            sum += count;
            max_val = max(max_val, count);
        }
        result[i] = sum - max_val;
    }
    return result;
}

/// <summary>
/// Leet Code 2920. Maximum Points After Collecting Coins From All Nodes
/// </summary>
int LeetCodeTree::maximumPoints(vector<vector<int>>& neigbors, int parent, int node, int level,
    vector<int>& coins, int k, vector<vector<int>>& mem)
{
    if (level > 13) return 0;
    if (mem[node][level] != -1) return mem[node][level];
    int coin = coins[node] >> level;
    int op1 = coin - k;
    int op2 = coin / 2;
    for (size_t i = 0; i < neigbors[node].size(); i++)
    {
        if (neigbors[node][i] == parent)
        {
            continue;
        }
        op1 += maximumPoints(neigbors, node, neigbors[node][i], level, coins, k, mem);
        op2 += maximumPoints(neigbors, node, neigbors[node][i], level + 1, coins, k, mem);
    }
    mem[node][level] = max(op1, op2);
    return mem[node][level];
}

/// <summary>
/// Leet Code 2920. Maximum Points After Collecting Coins From All Nodes
/// 
/// Hard
///
/// There exists an undirected tree rooted at node 0 with n nodes labeled 
/// from 0 to n - 1. You are given a 2D integer array edges of length 
/// n - 1, where edges[i] = [ai, bi] indicates that there is an edge 
/// between nodes ai and bi in the tree. You are also given a 0-indexed 
/// array coins of size n where coins[i] indicates the number of coins in 
/// the vertex i, and an integer k.
/// Starting from the root, you have to collect all the coins such that 
/// the coins at a node can only be collected if the coins of its 
/// ancestors have been already collected.
///
/// Coins at nodei can be collected in one of the following ways:
///
/// Collect all the coins, but you will get coins[i] - k points. If 
/// coins[i] - k is negative then you will lose abs(coins[i] - k) points.
/// Collect all the coins, but you will get floor(coins[i] / 2) points. 
/// If this way is used, then for all the nodej present in the subtree of 
/// nodei, coins[j] will get reduced to floor(coins[j] / 2).
/// Return the maximum points you can get after collecting the coins from 
/// all the tree nodes.
///
/// Example 1:
/// Input: edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
/// Output: 11                        
/// Explanation: 
/// Collect all the coins from node 0 using the first way. Total 
/// points = 10 - 5 = 5.
/// Collect all the coins from node 1 using the first way. Total 
/// points = 5 + (10 - 5) = 10.
/// Collect all the coins from node 2 using the second way so coins left 
/// at node 3 will be floor(3 / 2) = 1. 
/// Total points = 10 + floor(3 / 2) = 11.
/// Collect all the coins from node 3 using the second way. Total 
/// points = 11 + floor(1 / 2) = 11.
/// It can be shown that the maximum points we can get after collecting 
/// coins from all the nodes is 11. 
///
/// Example 2:
/// Input: edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
/// Output: 16
/// Explanation: 
/// Coins will be collected from all the nodes using the first way. 
/// Therefore, total points = (8 - 0) + (4 - 0) + (4 - 0) = 16.
/// 
/// Constraints:
/// 1. n == coins.length
/// 2. 2 <= n <= 10^5
/// 3. 0 <= coins[i] <= 10^4
/// 4. edges.length == n - 1
/// 5. 0 <= edges[i][0], edges[i][1] < n
/// 6. 0 <= k <= 10^4
/// </summary>
int LeetCodeTree::maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k)
{
    int n = coins.size();
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    vector<vector<int>> mem(n, vector<int>(14, -1));
    int result = maximumPoints(neighbors, -1, 0, 0, coins, k, mem);
    return result;
}

/// <summary>
/// Leet Code 2925. Maximum Score After Applying Operations on a Tree
/// </summary>
pair<long long, long long> LeetCodeTree::maximumScoreAfterOperations(int parent, int node, vector<vector<int>>& children, vector<int>& values)
{
    long long full = 0;
    long long partial = 0;
    for (size_t i = 0; i < children[node].size(); i++)
    {
        int child = children[node][i];
        if (child == parent) continue;
        pair<long long, long long> pair = maximumScoreAfterOperations(node, child, children, values);
        full += pair.first;
        partial += pair.second;
    }
    partial = max(full, full == 0 ? 0 : partial + values[node]);
    full += values[node];
    pair<long long, long long> result = { full, partial };
    return result;
}

/// <summary>
/// Leet Code 2925. Maximum Score After Applying Operations on a Tree
///  
/// Medium
///
/// There is an undirected tree with n nodes labeled from 0 to n - 1, 
/// and rooted at node 0. You are given a 2D integer array edges of length 
/// n - 1, where edges[i] = [ai, bi] indicates that there is an edge 
/// between nodes ai and bi in the tree.
///
/// You are also given a 0-indexed integer array values of length n, where 
/// values[i] is the value associated with the ith node.
///
/// You start with a score of 0. In one operation, you can:
/// Pick any node i.
/// Add values[i] to your score.
/// Set values[i] to 0.
/// A tree is healthy if the sum of values on the path from the root to 
/// any leaf node is different than zero.
///
/// Return the maximum score you can obtain after performing these 
/// operations on the tree any number of times so that it remains healthy.
///
/// Example 1:
/// Input: edges = [[0,1],[0,2],[0,3],[2,4],[4,5]], values = [5,2,5,2,1,1]
/// Output: 11
/// Explanation: We can choose nodes 1, 2, 3, 4, and 5. The value of the 
/// root is non-zero. Hence, the sum of values on the path from the root 
/// to any leaf is different than zero. Therefore, the tree is healthy and 
/// the score is values[1] + values[2] + values[3] + values[4] + 
/// values[5] = 11.
/// It can be shown that 11 is the maximum score obtainable after any 
/// number of operations on the tree.
///
/// Example 2:
/// Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], 
/// values = [20,10,9,7,4,3,5]
/// Output: 40
/// Explanation: We can choose nodes 0, 2, 3, and 4.
/// - The sum of values on the path from 0 to 4 is equal to 10.
/// - The sum of values on the path from 0 to 3 is equal to 10.
/// - The sum of values on the path from 0 to 5 is equal to 3.
/// - The sum of values on the path from 0 to 6 is equal to 5.
/// Therefore, the tree is healthy and the score is values[0] + 
/// values[2] + values[3] + values[4] = 40.
/// It can be shown that 40 is the maximum score obtainable after any 
/// number of operations on the tree.
///
/// Constraints:
/// 1. 2 <= n <= 2 * 10^4
/// 2. edges.length == n - 1
/// 3. edges[i].length == 2
/// 4. 0 <= ai, bi < n
/// 5. values.length == n
/// 6. 1 <= values[i] <= 10^9
/// 7. The input is generated such that edges represents a valid tree.
/// </summary>
long long LeetCodeTree::maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values)
{
    vector<vector<int>> children(edges.size() + 1);
    for (size_t i = 0; i < edges.size(); i++)
    {
        children[edges[i][0]].push_back(edges[i][1]);
        children[edges[i][1]].push_back(edges[i][0]);
    }
    pair<long long, long long> result = maximumScoreAfterOperations(-1, 0, children, values);
    return result.second;
}

/// <summary>
/// Leet Code 3004. Maximum Subtree of the Same Color
/// </summary>
bool LeetCodeTree::maximumSubtreeSize(int parent, int node, vector<vector<int>>& neighbors, vector<int>& colors, int& result)
{
    bool same = true;
    int max_val = 0;
    int sum_val = 1;
    for (size_t i = 0; i < neighbors[node].size(); i++)
    {
        int child = neighbors[node][i];
        if (child == parent) continue;
        if (colors[child] != colors[node]) same = false;
        int count = 0;
        bool child_same = maximumSubtreeSize(node, child, neighbors, colors, count);
        max_val = max(max_val, count);
        sum_val = sum_val + count;
        same = same && child_same;
    }
    if (same == true) result = sum_val;
    else result = max_val;
    return same;
}


/// <summary>
/// Leet Code 3004. Maximum Subtree of the Same Color
///                 
/// Medium
///
/// You are given a 2D integer array edges representing a tree with n nodes, 
/// numbered from 0 to n - 1, rooted at node 0, where edges[i] = [ui, vi] 
/// means there is an edge between the nodes vi and ui.
///
/// You are also given a 0-indexed integer array colors of size n, where 
/// colors[i] is the color assigned to node i.
/// We want to find a node v such that every node in the 
/// subtree of v has the same color.
///
/// Return the size of such subtree with the maximum number of nodes possible.
/// 
/// Example 1:
///
/// Input: edges = [[0,1],[0,2],[0,3]], colors = [1,1,2,3]
/// Output: 1
/// Explanation: Each color is represented as: 1 -> Red, 2 -> Green, 
/// 3 -> Blue. We can see that the subtree rooted at node 0 has children with 
/// different colors. Any other subtree is of the same color and has a size 
/// of 1. Hence, we return 1.
///
/// Example 2:
/// 
/// Input: edges = [[0,1],[0,2],[0,3]], colors = [1,1,1,1]
/// Output: 4
/// Explanation: The whole tree has the same color, and the subtree rooted at 
/// node 0 has the most number of nodes which is 4. Hence, we return 4.
///
/// Example 3:
/// 
/// Input: edges = [[0,1],[0,2],[2,3],[2,4]], colors = [1,2,3,3,3]
/// Output: 3
/// Explanation: Each color is represented as: 1 -> Red, 2 -> Green, 
/// 3 -> Blue. We can see that the subtree rooted at node 0 has children with 
/// different colors. Any other subtree is of the same color, but the subtree 
/// rooted at node 2 has a size of 3 which is the maximum. Hence, we return 3.
/// 
/// Constraints:
/// 1. n == edges.length + 1
/// 2. 1 <= n <= 5 * 10^4
/// 3. edges[i] == [ui, vi]
/// 4. 0 <= ui, vi < n
/// 5. colors.length == n
/// 6. 1 <= colors[i] <= 10^5
/// 7. The input is generated such that the graph represented by edges is a 
///    tree.
/// </summary>
int LeetCodeTree::maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors)
{
    int n = colors.size();
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    int result = 0;
    maximumSubtreeSize(-1, 0, neighbors, colors, result);
    return result;
}

/// <summary>
/// Leet 3068. Find the Maximum Sum of Node Values
/// </summary>
vector<long long> LeetCodeTree::maximumValueSum(int node, int parent, int k, vector<int>& nums, vector<vector<int>>& neighbors)
{
    vector<long long> result(2);
    result[0] = nums[node];
    result[1] = nums[node] ^ k;
    for (size_t i = 0; i < neighbors[node].size(); i++)
    {
        int child = neighbors[node][i];
        if (neighbors[node][i] == parent) continue;
        vector<long long> sub = maximumValueSum(neighbors[node][i], node, k, nums, neighbors);
        long long even = max(result[0] + sub[0], result[1] + sub[1]);
        long long odd = max(result[1] + sub[0], result[0] + sub[1]);
        result[0] = even;
        result[1] = odd;
    }
    return result;
}

/// <summary>
/// Leet 3068. Find the Maximum Sum of Node Values
///
/// Hard
///
/// There exists an undirected tree with n nodes numbered 0 to n - 1. You 
/// are given a 0-indexed 2D integer array edges of length n - 1, where 
/// edges[i] = [ui, vi] indicates that there is an edge between nodes ui 
/// and vi in the tree. You are also given a positive integer k, and 
/// a 0-indexed array of non-negative integers nums of length n, where 
/// nums[i] represents the value of the node numbered i.
///
/// Alice wants the sum of values of tree nodes to be maximum, for which 
/// Alice can perform the following operation any number of times 
/// (including zero) on the tree:
///
/// Choose any edge [u, v] connecting the nodes u and v, and update their 
/// values as follows:
/// nums[u] = nums[u] XOR k
/// nums[v] = nums[v] XOR k
/// Return the maximum possible sum of the values Alice can achieve by 
/// performing the operation any number of times.
///
/// Example 1:
/// Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
/// Output: 6
/// Explanation: Alice can achieve the maximum sum of 6 using a single 
/// operation:
/// - Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, 
///   and the array nums becomes: [1,2,1] -> [2,2,2].
/// The total sum of values is 2 + 2 + 2 = 6.
/// It can be shown that 6 is the maximum achievable sum of values.
///
/// Example 2:
/// Input: nums = [2,3], k = 7, edges = [[0,1]]
/// Output: 9
/// Explanation: Alice can achieve the maximum sum of 9 using a 
/// single operation:
/// - Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] 
///   become: 3 XOR 7 = 4, and the array nums becomes: [2,3] -> [5,4].
/// The total sum of values is 5 + 4 = 9.
/// It can be shown that 9 is the maximum achievable sum of values.
///
/// Example 3:
/// Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],
/// [0,4],[0,5]]
/// Output: 42
/// Explanation: The maximum achievable sum is 42 which can be 
/// achieved by Alice performing no operations.
///
/// Constraints:
/// 1. 2 <= n == nums.length <= 2 * 10^4
/// 2. 1 <= k <= 10^9
/// 3. 0 <= nums[i] <= 109
/// 4. edges.length == n - 1
/// 5. edges[i].length == 2
/// 6. 0 <= edges[i][0], edges[i][1] <= n - 1
/// 7. The input is generated such that edges represent a valid tree.
/// </summary>
long long LeetCodeTree::maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
{
    int n = nums.size();
    vector<vector<int>> neighbors(n);
    for (size_t i = 0; i < edges.size(); i++)
    {
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
    vector<long long> result = maximumValueSum(0, -1, k, nums, neighbors);
    return result[0];
}
#pragma endregion
