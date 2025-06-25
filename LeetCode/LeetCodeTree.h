﻿#pragma once
#ifndef LeetCodeTree_H
#define LeetCodeTree_H
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
struct RopeTreeNode 
{
    int len;
    string val;
    RopeTreeNode* left;
    RopeTreeNode* right;
    RopeTreeNode() 
        : len(0), val(""), left(nullptr), right(nullptr) 
    {
    }
    RopeTreeNode(string s) 
        : len(0), val(std::move(s)), left(nullptr), right(nullptr) 
    {
    }
    RopeTreeNode(int x) 
        : len(x), val(""), left(nullptr), right(nullptr) 
    {
    }
    RopeTreeNode(int x, RopeTreeNode* left, RopeTreeNode* right) 
        : len(x), val(""), left(left), right(right) 
    {
    }
};

/// <summary>
/// The class is to implement binary tree related algorithm  
/// </summary>

/// <summary>
/// Leet code #428. Serialize and Deserialize N-ary Tree
/// 
/// Serialization is the process of converting a data structure or 
/// object into a sequence of bits so that it can be stored in a file 
/// or memory buffer, or transmitted across a network connection link 
/// to be reconstructed later in the same or another computer environment.
/// 
/// Design an algorithm to serialize and deserialize an N-ary tree. An 
/// N-ary tree is a rooted tree in which each node has no more than N 
/// children. There is no restriction on how your serialization /
/// deserialization algorithm should work. You just need to ensure that 
/// an N-ary tree can be serialized to a string and this string can be 
/// deserialized to the original tree structure.
///
/// For example, you may serialize the following 3-ary tree
/// as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, 
/// so please be creative and come up with different approaches yourself.
///
/// Note:
/// 1. N is in the range of [1, 1000]
/// 2. Do not use class member/global/static variables to store states. 
///    Your serialize and deserialize algorithms should be stateless.
/// </summary>
class NaryTreeCodec
{
private:
    // Encodes a tree to a single string.
    string serializeNode(Node* root)
    {
        string result;
        if (root == nullptr) return result;
        result.append(to_string(root->val));
        if (root->children.empty()) return result;
        result.push_back('[');
        for (size_t i = 0; i < root->children.size(); i++)
        {
            if (i > 0) result.append(" ");
            result.append(serializeNode(root->children[i]));
        }
        result.push_back(']');
        return result;
    };

    // Decodes your encoded data to tree.
    void deserializeNode(vector<Node*>& children, string data, size_t& index)
    {
        string token;
        Node* node = nullptr;
        while (index <= data.size())
        {
            if ((index == data.size()) || (isspace(data[index])))
            {
                if (!token.empty() && (node != nullptr))
                {
                    node->val = atoi(token.c_str());
                    token.clear();
                }
                index++;
            }
            else if (isdigit(data[index]))
            {
                if (token.empty())
                {
                    node = new Node();
                    children.push_back(node);
                }
                token.push_back(data[index]);
                index++;
            }
            else if (data[index] == '[')
            {
                if (!token.empty() && (node != nullptr))
                {
                    node->val = atoi(token.c_str());
                    token.clear();
                }
                index++;
                if (node != nullptr)
                {
                    deserializeNode(node->children, data, index);
                }
            }
            else if (data[index] == ']')
            {
                if (!token.empty() && (node != nullptr))
                {
                    node->val = atoi(token.c_str());
                    token.clear();
                }
                index++;
                break;
            }
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(Node* root)
    {
        return "[" + serializeNode(root) + "]";
    };

    // Decodes your encoded data to tree.
    Node* deserialize(string data)
    {
        vector<Node*> nodeList;
        size_t index = 0;
        deserializeNode(nodeList, data, index);
        if (nodeList.empty()) return nullptr;
        else
        {
            Node* result = nodeList[0];
            return result;
        }
    }
};

/// <summary>
/// Leet code #431. Encode N-ary Tree to Binary Tree
/// 
/// Design an algorithm to encode an N-ary tree into a binary tree and decode
/// the binary tree to get the original N-ary tree. An N-ary tree is a rooted
/// tree in which each node has no more than N children. Similarly, a binary 
/// tree is a rooted tree in which each node has no more than 2 children. There
/// is no restriction on how your encode/decode algorithm should work. You just 
/// need to ensure that an N-ary tree can be encoded to a binary tree and this 
/// binary tree can be decoded to the original N-nary tree structure.
///
/// For example, you may encode the following 3-ary tree to a binary tree in 
/// this way:
/// 
/// Note that the above is just an example which might or might not work. You 
/// do not necessarily need to follow this format, so please be creative and 
/// come up with different approaches yourself.
///
/// Note:
///
/// N is in the range of [1, 1000]
/// Do not use class member/global/static variables to store states. Your 
/// encode and decode algorithms should be stateless.
/// or if B is true, or if both A and B are true.
/// </summary>
class NaryTreeBinaryCodec
{
private:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(queue<Node*> sibling_queue)
    {
        TreeNode* result = nullptr;
        if (sibling_queue.empty()) return result;
        Node* node = sibling_queue.front();
        sibling_queue.pop();
        result = new TreeNode(node->val);
        queue<Node*> children_queue;
        for (size_t i = 0; i < node->children.size(); i++)
        {
            children_queue.push(node->children[i]);
        }
        result->left = encode(children_queue);
        result->right = encode(sibling_queue);
        return result;
    }

    // Decodes your binary tree to an n-ary tree.
    void decode(TreeNode* tree_node, vector<Node*>& children_queue)
    {
        if (tree_node == nullptr) return;
        Node* node = new Node();
        node->val = tree_node->val;
        decode(tree_node->left, node->children);
        children_queue.push_back(node);
        decode(tree_node->right, children_queue);
    }

public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root)
    {
        TreeNode* result = nullptr;
        if (root == nullptr) return result;
        queue<Node*> sibling_queue;
        sibling_queue.push(root);
        result = encode(sibling_queue);
        return result;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root)
    {
        Node* result = nullptr;
        if (root == nullptr) return result;
        vector<Node*>children_queue;
        decode(root, children_queue);
        result = children_queue[0];
        return result;
    }
};

class LeetCodeTree
{
public:
#pragma region Tree
    /// <summary>
    /// Free nodes
    /// </summary>
    void freeNodes(Node* root);

    /// <summary>
    /// Free link tree nodes
    /// </summary>
    void freeLinkTreeNodes(TreeLinkNode* root);

    /// <summary>
    /// Find a tree node with value
    /// </summary>
    TreeNode* findTreeNode(TreeNode* root, int value);

    /// <summary>
    /// Build BST Forest
    /// </summary>
    vector<TreeNode*> buildBSTForest(vector<vector<int>> node_list);

    /// <summary>
    /// Encodes a linktree to a single string.
    /// </summary>
    /// <param name="root">the root</param>
    /// <returns>The string</returns>
    string serializeLinkTree(TreeLinkNode* root);

    /// <summary>
    /// Decodes your encoded data to tree.
    /// </summary>
    /// <param name="data">the string data</param>
    /// <returns>The root</returns> 
    TreeLinkNode* deserializeLinkTree(string data);

    /// <summary>
    /// Generate tree based on id list.
    /// </summary>
    vector<TreeNode*> generateTrees(vector<int>& id_list);

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
    vector<TreeNode*> generateTrees(int n);

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
    vector<int> inorderTraversal(TreeNode* root);

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
    bool isSameTree(TreeNode* p, TreeNode* q);

    /// <summary>
    /// Leet code #144. Binary Tree Preorder Traversal
    /// <summary>
    void preorderTraversal(TreeNode* root, vector<int>& output);

    /// <summary>
    /// Leet code #144. Binary Tree Preorder Traversal 
    /// Given a binary tree, return the preorder traversal of its nodes' values.
    ///
    /// For example:
    /// Given binary tree {1,#,2,3},
    ///   1
    ///    \
    ///    2
    ///   /
    ///  3
    ///  return [1,2,3]. 
    ///  Note: Recursive solution is trivial, could you do it iteratively?
    /// <summary>
    vector<int> preorderTraversal(TreeNode* root);

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
    /// </summary>
    vector<int> postorderTraversal(TreeNode* root);

    /// <summary>
    /// Leet code #105. Build binary tree from preoder and inorder travesal
    /// </summary>
    TreeNode* buildTreeFromPreorderandInorder(vector<int>& preorder, vector<int>& inorder,
        size_t start_preorder, size_t start_inorder,
        size_t length);

    /// <summary>
    /// Leet code #105. Construct Binary Tree from Preorder and Inorder Traversal
    /// Given preorder and inorder traversal of a tree, construct the binary tree.  
    /// Note:
    /// You may assume that duplicates do not exist in the tree.              
    /// </summary>
    TreeNode* buildTreeFromPreorderandInorder(vector<int>& preorder, vector<int>& inorder);

    /// <summary>
    /// Leet code #106. Build binary tree from inorder and postorder travesal
    /// </summary>
    TreeNode* buildTreeFromInorderAndPostorder(
        vector<int>& inorder, vector<int>& postorder,
        size_t start_inorder, size_t start_postorder,
        size_t length);

    /// <summary>
    /// Leet code #106. Construct Binary Tree from Inorder and Postorder Traversal
    /// Given inorder and postorder traversal of a tree, construct the binary tree.  
    /// Note:
    /// You may assume that duplicates do not exist in the tree.              
    /// </summary>
    TreeNode* buildTreeFromInorderAndPostorder(vector<int>& inorder, vector<int>& postorder);

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
    void flatten(TreeNode* root);

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
    vector<vector<int>> levelOrderBottom(TreeNode* root);

    /// <summary>
    /// Build Binary Search Tree from sorted array 
    /// </summary>
    TreeNode* buildBSTFromSortedArray(vector<int>& nums, int first, int last);

    /// <summary>
    /// Leet code #108. Convert Sorted Array to Binary Search Tree 
    /// Given an array where elements are sorted in ascending order, convert it to a height 
    /// balanced BST.
    /// </summary>
    TreeNode* sortedArrayToBST(vector<int>& nums);

    /// <summary>
    /// Leet code #109. Convert Sorted List to Binary Search Tree
    /// Given a singly linked list where elements are sorted in ascending order, 
    /// convert it to a height balanced BST.
    /// </summary>
    TreeNode* sortedListToBST(ListNode* head);

    /// <summary>
    /// Append the tree linked node to end
    /// </summary>
    void connectRight(TreeLinkNode*& head, TreeLinkNode*& ptr, TreeLinkNode* node);

    /// <summary>
    /// Leet code #116. Populating Next Right Pointers in Each Node           
    /// Given a binary tree 
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
    TreeLinkNode* connectRight(TreeLinkNode* root);

    /// <summary>
    /// Leet code #117. Populating Next Right Pointers in Each Node II
    /// Given a binary tree 
    /// struct TreeLinkNode {
    ///    int val;
    ///    TreeLinkNode *left, *right, *next;
    ///    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    /// };  
    ///
    /// Follow up for problem "Populating Next Right Pointers in Each Node".
    ///
    /// What if the given tree could be any binary tree? Would your previous solution still work?
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
    TreeLinkNode* connectRightII(TreeLinkNode* root);

    /// <summary>
    /// Leet code #222. Count Complete Tree Nodes               
    /// Given a complete binary tree, count the number of nodes.
    /// Definition of a complete binary tree from Wikipedia:
    /// In a complete binary tree every level, except possibly the last, is completely filled, 
    /// and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes 
    /// inclusive at the last level h. 
    /// </summary>
    int countCompleteTreeNodes(TreeNode* root);

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target);

    /// <summary>
    /// Free tree nodes
    /// </summary>
    void freeTreeNodes(TreeNode* root);

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
    string serialize(TreeNode* root, bool as_char = false);

    /// <summary>
    /// Decodes your encoded data to tree.
    /// </summary>
    /// <param name="data">the string data</param>
    /// <returns>The root</returns> 
    TreeNode* deserialize(string data);

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2);

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
    int deepestLeavesSum(TreeNode* root);

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
    int sumEvenGrandparent(TreeNode* root);

    /// <summary>
    /// Leet code #102. Binary Tree Level Order Traversal 
    ///
    /// Given a binary tree, return the level order traversal of its nodes' 
    /// values. (ie, from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root);

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
    TreeNode* removeLeafNodes(TreeNode* root, int target);

    /// <summary>
    /// Leet code #1343. Maximum Product of Splitted Binary Tree 
    /// </summary>
    long long maxProduct(TreeNode* root, long long sum, long long &result);

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
    int maxProduct(TreeNode* root);

    /// <summary>
    /// Leet code #1367. Linked List in Binary Tree
    /// </summary>
    bool isSubPath(ListNode* head, TreeNode* root, vector<ListNode *> &lead);

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
    bool isSubPath(ListNode* head, TreeNode* root);

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
    int longestZigZag(TreeNode* root);

    /// <summary>
    /// Leet code #1373. Maximum Sum BST in Binary Tree
    /// </summary>
    int maxSumBST(TreeNode* root, int &min_val, int&max_val, bool &is_bst, int &max_sum);

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
    int maxSumBST(TreeNode* root);

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target);

    /// <summary>
    /// Leet code #1382. Balance a Binary Search Tree
    /// </summary>
    void balanceBST(TreeNode* root, vector<TreeNode *> &node_list);

    /// <summary>
    /// Leet code #1382. Balance a Binary Search Tree
    /// </summary>
    TreeNode * balanceBST(vector<TreeNode *> &node_list, int start, int end);

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
    TreeNode* balanceBST(TreeNode* root);

    /// <summary>
    /// Leet code #1430. Check If a String Is a Valid Sequence from Root to 
    ////                 Leaves Path in a Binary Tree
    /// </summary>
    bool isValidSequence(TreeNode* root, vector<int>& arr, int pos);

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
    bool isValidSequence(TreeNode* root, vector<int>& arr);

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
    int goodNodes(TreeNode* root);

    /// <summary>
    /// Leet code #111. Minimum Depth of Binary Tree 
    /// Given a binary tree, find its minimum depth.
    /// The minimum depth is the number of nodes along the shortest path from the 
    /// root node down to the nearest leaf node.
    /// </summary>
    int minDepth(TreeNode* root);

    /// <summary>
    /// Leet code #104. Maximum Depth of Binary Tree 
    /// Given a binary tree, find its maximum depth.
    /// The maximum depth is the number of nodes along the longest path from the 
    /// root node down to the farthest leaf node.
    /// </summary>
    int maxDepth(TreeNode* root);

    /// <summary>
    /// Leet code #257. Binary Tree Paths  
    /// </summary>
    void binaryTreePaths(TreeNode* root, vector<int>& path, vector<string>& result);

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
    vector<string> binaryTreePaths(TreeNode* root);

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
    /// Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.	
    /// </summary>
    TreeNode* invertTree(TreeNode* root);

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
    vector<int> rightSideView(TreeNode* root);

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
    bool isValidBST(TreeNode* root);

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);

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
    bool isValidPreorderSerialization(string preorder);

    /// <summary>
    /// Leet code #110. Balanced Binary Tree
    /// </summary>
    bool isBalanced(TreeNode* root, int& depth);

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
    bool isBalanced(TreeNode* root);

    /// <summary>
    /// Leet code #236. Lowest Common Ancestor of a Binary Tree
    /// </summary>
    int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result);

    /// <summary>
    /// Leet code #236. Lowest Common Ancestor of a Binary Tree
    /// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. 
    /// According to the definition of LCA on Wikipedia: "The lowest common ancestor is defined between two 
    /// nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself)." 
    /// 	    _______3______
    ///        /              \
    ///     ___5__          ___1__
    ///    /      \        /      \
    ///    6       2       0       8
    ///           / \
    ///          7   4
    /// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, 
    ///  since a node can be a descendant of itself according to the LCA definition.
    /// </summary>
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

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
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q);

    /// <summary>
    /// Leet code #112. Path Sum
    /// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. 
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
    bool hasPathSum(TreeNode* root, int sum);

    /// <summary>
    /// Leet code #113. Path Sum II
    /// </summary>
    void pathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result);

    /// <summary>
    /// Leet code #113. Path Sum II
    /// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.  
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
    vector<vector<int>> pathSum(TreeNode* root, int sum);

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
    int sumNumbers(TreeNode* root);

    /// <summary>
    /// Find the two disordered nodes in the binary search tree 
    /// </summary>
    void recoverTree(TreeNode* root, TreeNode*& min_node, TreeNode*& max_node,
        TreeNode*& first, TreeNode*& second);

    /// <summary>
    /// Leet code #99. Recover Binary Search Tree 
    /// Two elements of a binary search tree (BST) are swapped by mistake.
    /// Recover the tree without changing its structure.
    /// Note:
    /// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
    /// </summary>
    void recoverTree(TreeNode* root);

    /// <summary>
    /// Find the two disordered nodes in the binary search tree 
    /// </summary>
    void recoverTreeII(TreeNode* root, TreeNode*& prev,
        TreeNode*& first, TreeNode*& second);

    /// <summary>
    /// Leet code #99. Recover Binary Search Tree 
    /// Two elements of a binary search tree (BST) are swapped by mistake.
    /// Recover the tree without changing its structure.
    /// Note:
    /// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
    /// </summary>
    void recoverTreeII(TreeNode* root);

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
    bool isSymmetric(TreeNode* root);

    /// <summary>
    /// Leet code #655. Print Binary Tree
    /// </summary>
    void printTree(TreeNode* root, vector<vector<string>>& matrix, int row, int col, int window);

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
    vector<vector<string>> printTree(TreeNode* root);
    /// <summary>
     /// Leet code #1008. Construct Binary Search Tree from Preorder Traversal
     /// </summary>
    TreeNode* bstFromPreorder(TreeNode* root, stack<TreeNode*>& left_path, vector<int>& preorder, size_t& index);

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
    TreeNode* bstFromPreorder(vector<int>& preorder);

    /// <summary>
    /// Leet code #1022. Sum of Root To Leaf Binary Numbers
    /// </summary>
    int sumRootToLeaf(TreeNode* root, int value, int& result);

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
    int sumRootToLeaf(TreeNode* root);

    /// <summary>
    /// Leet code #1026. Maximum Difference Between Node and Ancestor
    /// </summary>
    int maxAncestorDiff(TreeNode* root, int min_val, int max_val, int& result);

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
    int maxAncestorDiff(TreeNode* root);

    /// <summary>
    /// Leet code #1028. Recover a Tree From Preorder Traversal
    /// </summary>
    TreeNode* recoverFromPreorder(TreeNode* root, int curr_depth, int& child_depth,
        int& child_val, string S, size_t& index);

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
    TreeNode* recoverFromPreorder(string S);

    /// <summary>
    /// Leet code #1038. Binary Search Tree to Greater Sum Tree
    /// </summary>
    void bstToGst(TreeNode* root, int& sum);

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
    ///
    /// Example 1:
    /// 
    ///
    /// Input: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    /// Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    /// 
    ///
    /// Note:
    ///
    /// 1. The number of nodes in the tree is between 1 and 100.
    /// 2. Each node will have value between 0 and 100.
    /// 3. The given tree is a binary search tree.
    /// </summary>
    TreeNode* bstToGst(TreeNode* root);

    /// <summary>
    /// Leet code #1080. Insufficient Nodes in Root to Leaf Paths
    /// </summary>
    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum);

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
    TreeNode* sufficientSubset(TreeNode* root, int limit);

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
    vector<int> pathInZigZagTree(int label);

    /// <summary>
    /// Leet code #1110. Delete Nodes And Return Forest
    /// </summary>
    TreeNode* delNodes(TreeNode* root, vector<int>& del_bit, vector<TreeNode*>& result);

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete);

    /// <summary>
    /// Leet code #1120. Maximum Average Subtree
    /// </summary>
    double maximumAverageSubtree(TreeNode* root, double& sum, int& count);

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
    double maximumAverageSubtree(TreeNode* root);

    /// <summary>
    /// Leet code #1123. Lowest Common Ancestor of Deepest Leaves
    /// </summary>
    TreeNode* lcaDeepestLeaves(TreeNode* root, int& depth);

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
    TreeNode* lcaDeepestLeaves(TreeNode* root);

    /// <summary>
    /// Leet code #1145. Binary Tree Coloring Game
    /// </summary>
    int btreeGameWinningMove(TreeNode* root, int& curr, int& left, int& right, int x);

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
    bool btreeGameWinningMove(TreeNode* root, int n, int x);

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
    int maxLevelSum(TreeNode* root);

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
    int sumOfLeftLeaves(TreeNode* root);

    /// <summary>
    /// Get the maximum rob value with and without root 
    /// </summary>
    void robIII(TreeNode* root, int& rob_with_root, int& rob_without_root);

    /// <summary>
    /// Leet code #337. House Robber III 
    /// The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
    /// called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart 
    /// thief realized that "all houses in this place forms a binary tree". It will automatically contact the police 
    /// if two directly-linked houses were broken into on the same night. 
    /// Determine the maximum amount of money the thief can rob tonight without alerting the police.
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
    int robIII(TreeNode* root);

    /// <summary>
    /// Preorder traverse with the path passed on the way to check the sum.
    /// </summary>
    int pathSumIII(TreeNode* root, vector<int>& path, int sum);

    /// <summary>
    /// Leet code #437. Path Sum III     
    /// You are given a binary tree in which each node contains an integer value. 
    /// Find the number of paths that sum to a given value.
    /// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
    /// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000. 
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
    int pathSumIII(TreeNode* root, int sum);

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
    TreeNode* deleteNode(TreeNode* root, int key);

    /// <summary>
/// Leet code #366. Find Leaves of Binary Tree      
/// </summary>
    int findLeaves(TreeNode* root, vector<vector<int>>& result);

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
    vector<vector<int>> findLeaves(TreeNode* root);

    /// <summary>
    /// Leet code #156. Binary Tree Upside Down  
    /// 
    /// </summary>
    void upsideDownBinaryTree(TreeNode*& root, TreeNode*& rightLeaf);

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
    TreeNode* upsideDownBinaryTree(TreeNode* root);

    /// <summary>
    /// Leet code #250. Count Univalue Subtrees  
    /// </summary>
    bool countUnivalSubtrees(TreeNode* root, int& value, int& count);

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
    int countUnivalSubtrees(TreeNode* root);

    /// <summary>
    /// Leet code #298. Binary Tree Longest Consecutive Sequence  
    /// </summary>
    int longestConsecutive(TreeNode* root, int& max_length);

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
    int longestConsecutive(TreeNode* root);

    /// <summary>
    /// Leet code #255. Verify Preorder Sequence in Binary Search Tree  
    /// 
    /// Given an array of numbers, verify whether it is the correct preorder traversal 
    /// sequence of a binary search tree.
    /// You may assume each number in the sequence is unique.
    /// Follow up:
    /// Could you do it using only constant space complexity?
    /// </summary>
    bool verifyPreorder(vector<int>& preorder, int start, int end);

    /// <summary>
    /// Leet code #255. Verify Preorder Sequence in Binary Search Tree  
    /// 
    /// Given an array of numbers, verify whether it is the correct preorder traversal 
    /// sequence of a binary search tree.
    /// You may assume each number in the sequence is unique.
    /// Follow up:
    /// Could you do it using only constant space complexity?
    /// </summary>
    bool verifyPreorder(vector<int>& preorder);

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
    vector<vector<int>> verticalOrder(TreeNode* root);

    /// <summary>
    /// Leet code #333. Largest BST Subtree  
    /// </summary>
    bool checkBSTSubtree(TreeNode* root, int& min_val, int& max_val, int& size);

    /// <summary>
    /// Leet code #333. Largest BST Subtree  
    /// 
    /// Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where 
    /// largest means subtree with largest number of nodes in it.
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
    /// 1. You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, 
    /// which will result in O(nlogn) time complexity. 
    /// Follow up:
    /// Can you figure out ways to solve it with O(n) time complexity? 
    /// </summary>
    int largestBSTSubtree(TreeNode* root);

    /// <summary>
    /// Leet code #285. Inorder Successor in BST 
    /// 
    /// Given a binary search tree and a node in it, find the in-order successor of that node in the BST. 
    /// Note: If the given node has no in-order successor in the tree, return null. 
    /// </summary>
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

    /// <summary>
    /// Leet code #501. Find Mode in Binary Search Tree         
    /// </summary>
    void findMode(TreeNode* root, unordered_map<int, int>& node_map, map<int, unordered_set<int>>& frequency);

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
    vector<int> findMode(TreeNode* root);

    /// <summary>
    /// Leet code #508. Most Frequent Subtree Sum          
    /// </summary>
    int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& sum_map, map<int, unordered_set<int>>& frequency);

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
    vector<int> findFrequentTreeSum(TreeNode* root);

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
    vector<int> largestValues(TreeNode* root);

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
    int findBottomLeftValue(TreeNode* root);

    /// <summary>
    /// Leet code #530. Minimum Absolute Difference in BST 
    /// </summary>
    int getMinimumDifference(TreeNode* root, vector<int>& inorderList);

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
    int getMinimumDifference(TreeNode* root);

    /// <summary>
    /// Leet code #536. Construct Binary Tree from String
    /// </summary>
    TreeNode* str2tree(string s, size_t& index);

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
    TreeNode* str2tree(string s);

    /// <summary>
    /// Calculate the maximum path including itself and the one does not
    /// </summary>
    void maxPathSum(TreeNode* root, int& max_path_sum, int& max_path_loop);

    /// <summary>
    /// Leet code #124. Binary Tree Maximum Path Sum  
    /// Given a binary tree, find the maximum path sum. 
    /// For this problem, a path is defined as any sequence of nodes from some starting node to 
    /// any node in the tree along the parent-child connections. The path must contain at least 
    /// one node and does not need to go through the root.
    /// For example:
    /// Given the below binary tree, 
    ///     1
    ///    / \
    ///   2   3
    /// Return 6.
    /// </summary>
    int maxPathSum(TreeNode* root);

    /// <summary>
    /// Return kth smallest node in BST
    /// </summary>
    int findKthSmallest(TreeNode* root, int& k);

    /// <summary>
    /// Leet code #230. Kth Smallest Element in a BST
    /// Given a binary search tree, write a function kthSmallest to find the 
    /// kth smallest element in it.
    /// Note: 
    /// You may assume k is always valid, 1 <= k <= BST's total elements.
    /// Follow up:
    /// What if the BST is modified (insert/delete operations) often and you 
    /// need to find the kth smallest frequently? How would you optimize the 
    /// kthSmallest routine?
    /// Hint:
    /// Try to utilize the property of a BST.
    /// What if you could modify the BST node's structure?
    /// The optimal runtime complexity is O(height of BST).
    /// </summary>
    int kthSmallest(TreeNode* root, int k);

    /// <summary>
    /// Leet code #270. Closest Binary Search Tree Value    
    /// 
    /// Given a non-empty binary search tree and a target value, find the 
    /// value in the BST that is closest to the target. 
    /// Note:
    /// Given target value is a floating point.
    /// You are guaranteed to have only one unique value in the BST that is 
    /// closest to the target.
    /// </summary>
    int closestValue(TreeNode* root, double target);


    /// <summary>
    /// Leet code #272. Closest Binary Search Tree Value II   
    /// </summary>
    vector<int> getPredecessor(stack<TreeNode*> left_stack, int k);

    /// <summary>
    /// Leet code #272. Closest Binary Search Tree Value II   
    /// </summary>
    vector<int> getSuccessor(stack<TreeNode*> right_stack, int k);

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
    vector<int> closestKValues(TreeNode* root, double target, int k);

    /// <summary>
    /// Leet code #545. Boundary of Binary Tree       
    /// </summary>
    void findLeftBoundary(TreeNode* root, vector<int>& leftBoundary);

    /// <summary>
    /// Leet code #545. Boundary of Binary Tree       
    /// </summary>
    void findRightBoundary(TreeNode* root, vector<int>& rightBoundary);

    /// <summary>
    /// Leet code #545. Boundary of Binary Tree       
    /// </summary>
    void findLeaves(TreeNode* root, vector<int>& leaves);

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
    vector<int> boundaryOfBinaryTree(TreeNode* root);

    // <summary>
    /// Leet code #543. Diameter of Binary Tree       
    /// </summary>
    void diameterOfBinaryTree(TreeNode* root, int& max_depth, int& diameter);

    // <summary>
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
    int diameterOfBinaryTree(TreeNode* root);

    // <summary>
    /// Leet code #538. Convert BST to Greater Tree       
    /// </summary>
    TreeNode* convertBST(TreeNode* root, int& sum);

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
    TreeNode* convertBST(TreeNode* root);

    /// <summary>
    /// Leet code #549. Binary Tree Longest Consecutive Sequence II  
    /// </summary>
    int longestConsecutiveII(TreeNode* root, int& asc_size, int& desc_size);

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
    int longestConsecutiveII(TreeNode* root);

    /// <summary>
    /// Leet code #563. Binary Tree Tilt      
    /// </summary>
    int findTilt(TreeNode* root, int& sum);

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
    int findTilt(TreeNode* root);

    /// <summary>
    /// Leet code #572. Subtree of Another Tree       
    /// </summary>
    void preOrderTraversal(TreeNode* root, string& result);

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
    bool isSubtree(TreeNode* s, TreeNode* t);

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
    string tree2str(TreeNode* t);

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);

    /// <summary>
    /// Leet code #623. Add One Row to Tree 
    /// </summary>
    TreeNode* addOneRow(TreeNode* root, int v, int depth, int target_depth);


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
    TreeNode* addOneRow(TreeNode* root, int v, int d);

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
    vector<double> averageOfLevels(TreeNode* root);

    /// <summary>
    /// Leet code #652. Find Duplicate Subtrees
    /// </summary>
    string findDuplicateSubtrees(TreeNode* root, unordered_map<string, vector<TreeNode*>>& cache);

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);

    /// <summary>
    /// Leet code #653. Two Sum IV - Input is a BST
    /// </summary>
    bool findTarget(TreeNode* root, unordered_set<int>& hash_table, int k);

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
    bool findTarget(TreeNode* root, int k);

    /// <summary>
    /// Leet code #654. Maximum Binary Tree
    /// </summary>
    void constructMaximumBinaryTree(TreeNode*& root, int val);

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums);

    /// <summary>
    /// Leet code #663. Equal Tree Partition 
    /// </summary>
    int checkEqualTree(TreeNode* root, unordered_map<int, int>& sub_sum);

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
    bool checkEqualTree(TreeNode* root);

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
    int widthOfBinaryTree(TreeNode* root);

    /// <summary>
    /// Leet code #666. Path Sum IV 
    /// </summary>
    bool pathSumIV(int level, int position, unordered_map<int, unordered_map<int, int>>& node_map, int& subtotal, int& sum);

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
    int pathSumIV(vector<int>& nums);

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
    TreeNode* trimBST(TreeNode* root, int L, int R);

    /// <summary>
    /// Leet code #671. Second Minimum Node In a Binary Tree 
    /// </summary>
    void findSecondMinimumValue(TreeNode* root, set<int, greater<int>>& heap);

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
    int findSecondMinimumValue(TreeNode* root);

    /// <summary>
    /// Leet code #687. Longest Univalue Path
    /// </summary>
    int longestUnivaluePath(TreeNode* root, int& path_length);

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
    int longestUnivaluePath(TreeNode* root);

    /// <summary>
    /// Leet code #742. Closest Leaf in a Binary Tree
    /// </summary>
    void findClosestLeaf(TreeNode* root, int target, int& target_distance, int& leaf_distance, int& value);

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
    int findClosestLeaf(TreeNode* root, int k);

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
    vector<TreeNode*> splitBST(TreeNode* root, int V);

    /// <summary>
    /// Leetcode #783. Minimum Distance Between BST Nodes
    /// </summary>
    void minDiffInBST(TreeNode* node, TreeNode*& prev_node, int& min_diff);

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
    int minDiffInBST(TreeNode* root);

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
    TreeNode* pruneTree(TreeNode* root);

    /// <summary>
    /// Leet code #863. All Nodes Distance K in Binary Tree
    /// </summary>
    int distanceK(TreeNode* root, TreeNode* target, int K, int distance, vector<int>& result);

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K);

    /// <summary>
    /// Leet code #865. Smallest Subtree with all the Deepest Nodes
    /// </summary>
    pair<TreeNode*, int> subtreeWithAllDeepest(TreeNode* root, int depth);

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root);

    /// <summary>
    /// Leet code #872. Leaf-Similar Trees
    /// </summary>
    void getLeaves(TreeNode* root1, vector<int>& leaves);

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2);

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
    TreeNode* searchBST(TreeNode* root, int val);

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
    TreeNode* insertIntoBST(TreeNode* root, int val);

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
    int maxDepth(Node* root);

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
    vector<int> preorder(Node* root);

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
    vector<vector<int>> levelOrder(Node* root);

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
    vector<int> postorder(Node* root);

    /// <summary>
    /// Leet code #426. Convert Binary Search Tree to Sorted Doubly Linked List
    /// </summary>
    void treeToDoublyList(TreeNode* root, TreeNode*& head, TreeNode*& tail);

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
    TreeNode* treeToDoublyList(TreeNode* root);


    /// <summary>
    /// Leet code #889. Construct Binary Tree from Preorder and Postorder Traversal
    /// </summary>
    TreeNode* constructFromPrePost(
        vector<int>::iterator pre_begin,
        vector<int>::iterator pre_end,
        vector<int>::iterator post_begin,
        vector<int>::iterator post_end);

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post);

    /// <summary>
    /// Leet code #894. All Possible Full Binary Trees
    /// </summary>
    TreeNode* clone(TreeNode*);

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
    vector<TreeNode*> allPossibleFBT(int N);

    /// <summary>
    /// Leet code #897. Increasing Order Search Tree 
    /// </summary>
    void increasingBST(TreeNode*& new_root, TreeNode*& new_child, TreeNode* root);

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
    TreeNode* increasingBST(TreeNode* root);

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
    int rangeSumBST(TreeNode* root, int L, int R);

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2);

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
    bool isCompleteTree(TreeNode* root);

    /// <summary>
    /// Leet code #968. Binary Tree Cameras
    /// </summary>
    int minCameraCover(TreeNode* root, int& result);

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
    int minCameraCover(TreeNode* root);

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
    bool isUnivalTree(TreeNode* root);

    /// <summary>
    /// Leet code #971. Flip Binary Tree To Match Preorder Traversal
    /// </summary>
    void flipMatchVoyage(TreeNode* root, vector<int>& voyage, int& index, vector<int>& result);

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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage);

    /// <summary>
    /// Leet code #979. Distribute Coins in Binary Tree
    /// </summary>
    int distributeCoins(TreeNode* root, vector<int>& missingPaths, int& result);

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
    int distributeCoins(TreeNode* root);

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
    vector<vector<int>> verticalTraversal(TreeNode* root);

    /// <summary>
    /// Leet code #988. Smallest String Starting From Leaf
    /// </summary>
    void smallestFromLeaf(TreeNode* root, string& str, string& result);

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
    string smallestFromLeaf(TreeNode* root);

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
    TreeNode* inorderSuccessor(TreeNode* node);

    /// <summary>
    /// Leet code #993. Cousins in Binary Tree
    /// </summary>
    bool isCousins(TreeNode* root, TreeNode*& parent, int& depth, int val);

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
    bool isCousins(TreeNode* root, int x, int y);

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val);

    /// <summary>
    /// Leet code #1457. Pseudo-Palindromic Paths in a Binary Tree
    /// </summary>
    int pseudoPalindromicPaths(TreeNode* root, unordered_map<int, int> &num_map);

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
    int pseudoPalindromicPaths(TreeNode* root);

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
    vector<int> getLonelyNodes(TreeNode* root);

    /// <summary>
    /// Leet code #1485. Clone Binary Tree With Random Pointer
    /// </summary> 
    TreeNode* cloneRandomBinaryTree(TreeNode* root, unordered_map<TreeNode *,TreeNode *> &map);

    /// <summary>
    /// Leet code #1485. Clone Binary Tree With Random Pointer
    /// </summary> 
    TreeNode* setRandomBinaryTree(TreeNode* root, TreeNode * clone, unordered_map<TreeNode*, TreeNode*>& map);

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
    TreeNode* copyRandomBinaryTree(TreeNode* root);

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
    Node* cloneTree(Node* root);

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
    /// The total number of nodes is between [1, 5 * 10^4].
    /// Each node has a unique value.
    /// </summary>
    Node* findRoot(vector<Node*> tree);

    /// <summary>
    /// Leet code #1519. Number of Nodes in the Sub-Tree With the Same Label
    /// </summary>
    void countSubTrees(int node, vector<vector<int>>& links, string& labels, 
        vector<int> &tag, vector<int>& result);

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
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels);

    /// <summary>
    /// Leet code #1530. Number of Good Leaf Nodes Pairs
    /// </summary>
    vector<int> countPairs(TreeNode* root, int depth, int distance, int & result);

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
    int countPairs(TreeNode* root, int distance);

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
    bool isEvenOddTree(TreeNode* root);

    /// <summary>
    /// Leet code #1612. Check If Two Expression Trees are Equivalent
    /// </summary>
    void checkEquivalence(TreeNode* root, vector<int>& arr);

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
    bool checkEquivalence(TreeNode* root1, TreeNode* root2);

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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u);

    /// <summary>
    /// Leet code #1522. Diameter of N-Ary Tree
    /// </summary>
    int diameter(Node* root, int depth, int& max_diameter);

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
    int diameter(Node* root);

    /// <summary>
    /// Leet code #1516. Move Sub-Tree of N-Ary Tree
    /// </summary>
    int is_parent(Node* root, Node* p, Node* q, bool is_p_found);

    /// <summary>
    /// Leet code #1516. Move Sub-Tree of N-Ary Tree
    /// </summary>
    Node* find_parent(Node* node, Node * target, Node* parent);

    /// <summary>
    /// Leet code #1516. Move Sub-Tree of N-Ary Tree
    /// </summary>
    Node* find_node(Node* node, Node* target);

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
    Node* moveSubTree(Node* root, Node* p, Node* q);

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
    TreeNode* expTree(string s);

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
    TreeNode* correctBinaryTree(TreeNode* root);

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
    TreeNode* flipBinaryTree(TreeNode* root, TreeNode* leaf);

    /// <summary>
    /// Leet code 1740. Find Distance in a Binary Tree
    /// </summary>
    void findDistance(TreeNode* root, int p, int q, 
        int& p_depth, int &q_depth, int &result);


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
    int findDistance(TreeNode* root, int p, int q);

    /// <summary>
    /// Leet code 1932. Merge BSTs to Create Single BST 
    /// </summary>
    TreeNode* canMerge(TreeNode* tree_node, unordered_map<int, TreeNode*>&roots);

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
    TreeNode* canMerge(vector<TreeNode*>& trees);

    /// <summary>
    /// Leet code 1644. Lowest Common Ancestor of a Binary Tree
    /// </summary>
    int lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result);

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
    TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q);

    /// <summary>
    /// Leet Code 1902. Depth of BST Given Insertion Order
    /// </summary>
    int maxDepthBST(TreeNode * node, int val, int depth);

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
    int maxDepthBST(vector<int>& order);

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
    TreeNode* lowestCommonAncestorIII(TreeNode* p, TreeNode* q);

    /// <summary>
    /// Leet code #1676. Lowest Common Ancestor of a Binary Tree
    /// </summary>
    int lowestCommonAncestorIV(TreeNode* node, unordered_set<int>& subtree, TreeNode*& result);

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
    TreeNode* lowestCommonAncestorIV(TreeNode* root, vector<TreeNode*>& nodes);

    /// <summary>
    /// Leet Code 2096. Step-By-Step Directions From a Binary Tree Node to 
    ///                 Another
    /// </summary>
    bool getDirections(TreeNode* node, int target, string& path);

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
    string getDirections(TreeNode* root, int startValue, int destValue);

    /// <summary>
    /// Leet Code 1973. Count Nodes Equal to Sum of Descendants 
    /// </summary>
    int equalToDescendants(TreeNode* root, long long &sum);

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
    int equalToDescendants(TreeNode* root);

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions);

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
    bool checkTree(TreeNode* root);

    /// <summary>
    /// Leet Code 2265. Count Nodes Equal to Average of Subtree
    /// </summary>
    int averageOfSubtree(TreeNode* root, int& sum, int &count);

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
    int averageOfSubtree(TreeNode* root);

    /// <summary>
    /// Leet Code 2246. Longest Path With Different Adjacent Characters
    /// </summary>
    int longestPath(int node, vector<vector<int>>& children, string& s, int& result);

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
    int longestPath(vector<int>& parent, string s);

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
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query);

    /// <summary>
    /// Leet Code 2313. Minimum Flips in Binary Tree to Get Result
    /// </summary>
    void minimumFlips(TreeNode* root, int &true_flips, int &false_flips);

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
    int minimumFlips(TreeNode* root, bool result);

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
    bool evaluateTree(TreeNode* root);

    /// <summary>
    /// Leet Code 2378. Choose Edges to Maximize Score in a Tree
    /// </summary>
    pair<long long, long long> maxScore(int node, vector<vector<pair<int, int>>>& neighbors);

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
    long long maxScore(vector<vector<int>>& edges);

    /// <summary>
    /// Leet Code 2385. Amount of Time for Binary Tree to Be Infected
    /// </summary>
    pair<int,int> amountOfTime(TreeNode* node, int start, int& result);

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
    int amountOfTime(TreeNode* root, int start);

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
    TreeNode* reverseOddLevels(TreeNode* root);

    /// <summary>
    /// Leet Code 2440. Create Components With Same Value     
    /// </summary>
    int componentValue(vector<int>& nums, vector<vector<int>>& neighbors, vector<int>&sum, int curr, int target);


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
    int componentValue(vector<int>& nums, vector<vector<int>>& edges);

    /// <summary>
    /// Leet Code 2445. Number of Nodes With Value One   
    /// </summary>
    int numberOfNodes(int n, int curr, vector<int>& flags);

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
    int numberOfNodes(int n, vector<int>& queries);

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
    int minimumOperations(TreeNode* root);

    /// <summary>
    /// Leet Code 2476. Closest Nodes Queries in a Binary Search Tree 
    /// </summary>
    void closestNodesSort(TreeNode* node, vector<int>& sorted);

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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries);

    /// <summary>
    /// Leet Code 2458. Height of Binary Tree After Subtree Removal Queries
    /// </summary>
    int treeQueriesDepth(TreeNode* root, int level, unordered_map<int, int>& levels,
        unordered_map<int, int>& depths, unordered_map<int, int>& depth1,
        unordered_map<int, int>& depth2);


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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries);

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
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2538. Difference Between Maximum and Minimum Price Sum
    /// </summary>
    vector<long long> maxOutput(int prev, int curr,
        vector<vector<int>>& neighbors, vector<int>& price, long long& result);

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
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price);

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
    long long kthLargestLevelSum(TreeNode* root, int k);

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
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k);

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
    TreeNode* replaceValueInTree(TreeNode* root);

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
    int minIncrements(int n, vector<int>& cost);

    /// <summary>
    /// Leet Code 2689. Extract Kth Character From The Rope Tree
    /// </summary>
    string getKthCharacter(RopeTreeNode* node);

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
    char getKthCharacter(RopeTreeNode* root, int k);


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
    bool isPreorder(vector<vector<int>>& nodes);

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
    int heightOfTree(TreeNode* root);

    /// <summary>
    /// Leet Code 2791. Count Paths That Can Form a Palindrome in a Tree
    /// </summary>
    void countPalindromePaths(vector<vector<int>> &children, int node, string& s, 
        int bits, unordered_map<int, int>& count, long long& result);

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
    long long countPalindromePaths(vector<int>& parent, string s);

    /// <summary>
    /// Leet Code 2792. Count Nodes That Are Great Enough
    /// </summary>
    int countGreatEnoughNodes(TreeNode* node, int k, priority_queue<int> &pq);

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
    int countGreatEnoughNodes(TreeNode* root, int k);

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
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, 
        vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 2920. Maximum Points After Collecting Coins From All Nodes
    /// </summary>
    int maximumPoints(vector<vector<int>>& neigbors, int parent, int node, int level, 
        vector<int>& coins, int k, vector<vector<int>>&mem);

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
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k);

    /// <summary>
    /// Leet Code 2925. Maximum Score After Applying Operations on a Tree
    /// </summary>
    pair<long long, long long> maximumScoreAfterOperations(int parrnt, int node, vector<vector<int>>&children, vector<int>& values);

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
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values);

    /// <summary>
    /// Leet Code 3004. Maximum Subtree of the Same Color
    /// </summary>
    bool maximumSubtreeSize(int parent, int node, vector<vector<int>>& neighbors, vector<int>& colors, int &result);

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
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors);

    /// <summary>
    /// Leet 3068. Find the Maximum Sum of Node Values
    /// </summary>
    vector<long long> maximumValueSum(int node, int parent, int k, vector<int>& nums, vector<vector<int>>& neighbors);

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
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges);

    /// <summary>
    /// LeetCode 3157. Find the Level of Tree with Minimum Sum
    /// 
    /// Medium
    /// 
    /// Given the root of a binary tree root where each node has a value, 
    /// return the level of the tree that has the minimum sum of values 
    /// among all the levels (in case of a tie, return the lowest level).
    ///
    /// Note that the root of the tree is at level 1 and the level of any 
    /// other node is its distance from the root + 1.
    ///
    /// Example 1:
    /// Input: root = [50,6,2,30,80,7]
    /// Output: 2
    ///
    /// Example 2:
    /// Input: root = [36,17,10,null,null,24]
    /// Output: 3
    ///
    /// Example 3:
    /// Input: root = [5,null,5,null,5]
    ///
    /// Output: 1
    ///
    /// Constraints:
    /// 1. The number of nodes in the tree is in the range [1, 10^5].
    /// 2. 1 <= Node.val <= 10^9
    /// </summary>
    int minimumSumLevel(TreeNode* root);

    /// <summary>
    /// LeetCode 3203. Find Minimum Diameter After Merging Two Trees
    /// </summary>
    pair<int, int> minimumDiameterAfterMerge(vector<vector<int>>& edges);

    /// <summary>
    /// LeetCode 3203. Find Minimum Diameter After Merging Two Trees
    ///
    /// Hard
    ///
    /// There exist two undirected trees with n and m nodes, numbered from 0 
    /// to n - 1 and from 0 to m - 1, respectively. You are given two 2D 
    /// integer arrays edges1 and edges2 of lengths n - 1 and m - 1, 
    /// respectively, where edges1[i] = [ai, bi] indicates that there is an 
    /// edge between nodes ai and bi in the first tree and 
    /// edges2[i] = [ui, vi] indicates that there is an edge between nodes 
    /// ui and vi in the second tree.
    ///
    /// You must connect one node from the first tree with another node from 
    /// the second tree with an edge.
    ///
    /// Return the minimum possible diameter of the resulting tree.
    ///
    /// The diameter of a tree is the length of the longest path between any 
    /// two nodes in the tree.
    ///
    /// Example 1:
    /// Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
    /// Output: 3
    /// Explanation:
    /// We can obtain a tree of diameter 3 by connecting node 0 from the 
    /// first tree with any node from the second tree.
    ///
    /// Example 2:
    /// Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], 
    /// edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]
    ///
    /// Output: 5
    /// Explanation:
    /// We can obtain a tree of diameter 5 by connecting node 0 from the 
    /// first tree with node 0 from the second tree.
    ///
    ///
    /// Constraints:
    /// 1. 1 <= n, m <= 10^5
    /// 2. edges1.length == n - 1
    /// 3. edges2.length == m - 1
    /// 4. edges1[i].length == edges2[i].length == 2
    /// 5. edges1[i] = [ai, bi]
    /// 6. 0 <= ai, bi < n
    /// 7. edges2[i] = [ui, vi]
    /// 8. 0 <= ui, vi < m
    /// 9. The input is generated such that edges1 and edges2 represent valid 
    ///    trees.
    /// </summary>
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2);

    /// <summary>
    /// Leet Code 3241. Time Taken to Mark All Nodes
    /// </summary>
    int timeTakenDFS(int parent, int node, vector<vector<int>>& neighbors, vector<vector<int>>&treeNodes);

    /// <summary>
    /// Leet Code 3241. Time Taken to Mark All Nodes
    /// 
    /// Hard
    /// 
    /// There exists an undirected tree with n nodes numbered 0 to n - 1. You 
    /// are given a 2D integer array edges of length n - 1, where 
    /// edges[i] = [ui, vi] indicates that there is an edge between nodes ui 
    /// and vi in the tree.
    ///
    /// Initially, all nodes are unmarked. For each node i:
    /// If i is odd, the node will get marked at time x if there is at least 
    /// one node adjacent to it which was marked at time x - 1.
    /// If i is even, the node will get marked at time x if there is at least 
    /// one node adjacent to it which was marked at time x - 2.
    /// Return an array times where times[i] is the time when all nodes get 
    /// marked in the tree, if you mark node i at time t = 0.
    ///
    /// Note that the answer for each times[i] is independent, i.e. when you 
    /// mark node i all other nodes are unmarked.
    ///
    /// Example 1:
    /// Input: edges = [[0,1],[0,2]]
    /// Output: [2,4,3]
    /// Explanation:
    /// For i = 0:
    /// Node 1 is marked at t = 1, and Node 2 at t = 2.
    /// For i = 1:
    /// Node 0 is marked at t = 2, and Node 2 at t = 4.
    /// For i = 2:
    /// Node 0 is marked at t = 2, and Node 1 at t = 3.
    ///
    /// Example 2:
    /// Input: edges = [[0,1]]
    /// Output: [1,2]
    /// Explanation:
    /// For i = 0:
    /// Node 1 is marked at t = 1.
    /// For i = 1:
    /// Node 0 is marked at t = 2.
    ///
    /// Example 3:
    /// Input: edges = [[2,4],[0,1],[2,3],[0,2]]
    /// Output: [4,6,3,5,5]
    /// Explanation:
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i].length == 2
    /// 4. 0 <= edges[i][0], edges[i][1] <= n - 1
    /// 5. The input is generated such that edges represents a valid tree.
    /// </summary>
    vector<int> timeTaken(vector<vector<int>>& edges);

    /// <summary>
    /// Leet Code 3249. Count the Number of Good Nodes
    /// </summary>
    int countGoodNodesDFS(int parent, int node, vector<vector<int>>& neighbors, int &result);

    /// <summary>
    /// Leet Code 3249. Count the Number of Good Nodes
    /// 
    /// Medium
    ///
    /// There is an undirected tree with n nodes labeled from 0 to n - 1, 
    /// and rooted at node 0. You are given a 2D integer array edges of length 
    /// n - 1, where edges[i] = [ai, bi] indicates that there is an edge 
    /// between nodes ai and bi in the tree.
    ///
    /// A node is good if all the subtrees rooted at its children have the 
    /// same size.
    ///
    /// Return the number of good nodes in the given tree.
    /// A subtree of treeName is a tree consisting of a node in treeName and 
    /// all of its descendants.
    ///
    /// Example 1:
    /// Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
    /// Output: 7
    /// Explanation:
    /// All of the nodes of the given tree are good.
    ///
    /// Example 2:
    /// Input: edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]
    /// Output: 6
    /// Explanation:
    /// There are 6 good nodes in the given tree. They are colored in the 
    /// image above.
    ///
    /// Example 3:
    /// Input: edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],
    /// [0,9],[9,10],[9,12],[10,11]]
    /// Output: 12
    /// Explanation:
    /// All nodes except node 9 are good.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i].length == 2
    /// 4. 0 <= ai, bi < n
    /// 5. The input is generated such that edges represents a valid tree.
    /// </summary>
    int countGoodNodes(vector<vector<int>>& edges);

    /// <summary>
    /// Leet Code 3313. Find the Last Marked Nodes in Tree
    /// </summary>
    int lastMarkedNodesBFS(queue<int>&queue, vector<vector<int>>& neighbors, vector<int> &dist);

    /// <summary>
    /// Leet Code 3313. Find the Last Marked Nodes in Tree
    /// 
    /// Hard
    ///
    /// There exists an undirected tree with n nodes numbered 0 to n - 1. 
    /// You are given a 2D integer array edges of length n - 1, where 
    /// edges[i] = [ui, vi] indicates that there is an edge between nodes 
    /// ui and vi in the tree.
    ///
    /// Initially, all nodes are unmarked. After every second, you mark 
    /// all unmarked nodes which have at least one marked node adjacent 
    /// to them.
    //
    /// Return an array nodes where nodes[i] is the last node to get marked 
    /// in the tree, if you mark node i at time t = 0. If nodes[i] has 
    /// multiple answers for any node i, you can choose any one answer.
    ///
    /// Example 1:
    /// Input: edges = [[0,1],[0,2]]
    /// Output: [2,2,1]
    /// Explanation:
    /// 
    /// For i = 0, the nodes are marked in the sequence: [0] -> [0,1,2]. 
    /// Either 1 or 2 can be the answer.
    /// For i = 1, the nodes are marked in the sequence: [1] -> [0,1] -> 
    /// [0,1,2]. Node 2 is marked last.
    /// For i = 2, the nodes are marked in the sequence: [2] -> [0,2] -> 
    /// [0,1,2]. Node 1 is marked last.
    ///
    /// Example 2:
    /// Input: edges = [[0,1]]
    /// Output: [1,0]
    /// Explanation:
    /// For i = 0, the nodes are marked in the sequence: [0] -> [0,1].
    /// For i = 1, the nodes are marked in the sequence: [1] -> [0,1].
    ///
    /// Example 3:
    /// Input: edges = [[0,1],[0,2],[2,3],[2,4]]
    /// Output: [3,3,1,1,1]
    /// Explanation:
    /// For i = 0, the nodes are marked in the sequence: [0] -> [0,1,2] ->
    /// [0,1,2,3,4].
    /// For i = 1, the nodes are marked in the sequence: [1] -> [0,1] -> 
    /// [0,1,2] -> [0,1,2,3,4].
    /// For i = 2, the nodes are marked in the sequence: [2] -> [0,2,3,4] -> 
    /// [0,1,2,3,4].
    /// For i = 3, the nodes are marked in the sequence: [3] -> [2,3] -> 
    /// [0,2,3,4] -> [0,1,2,3,4].
    /// For i = 4, the nodes are marked in the sequence: [4] -> [2,4] -> 
    /// [0,2,3,4] -> [0,1,2,3,4].
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i].length == 2
    /// 4. 0 <= edges[i][0], edges[i][1] <= n - 1
    /// 5. The input is generated such that edges represents a valid tree.
    /// </summary>
    vector<int> lastMarkedNodes(vector<vector<int>>& edges);

    /// <summary>
    /// Leet Code 3319. K-th Largest Perfect Subtree Size in Binary Tree 
    /// </summary>
    pair<int,int> kthLargestPerfectSubtree(TreeNode* node, priority_queue<int>&pq, int k);

    /// <summary>
    /// Leet Code 3319. K-th Largest Perfect Subtree Size in Binary Tree 
    /// 
    /// Medium
    /// You are given the root of a binary tree and an integer k.
    /// Return an integer denoting the size of the kth largest perfect binary 
    /// subtree, or -1 if it doesn't exist.
    ///
    /// A perfect binary tree is a tree where all leaves are on the same 
    /// level, and every parent has two children.
    ///
    /// Example 1:
    /// 
    /// Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
    /// Output: 3
    /// 
    /// Explanation:
    /// The roots of the perfect binary subtrees are highlighted in black. 
    /// Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
    /// The 2nd largest size is 3.
    ///
    /// Example 2:
    ///
    /// Input: root = [1,2,3,4,5,6,7], k = 1
    /// Output: 7
    /// Explanation:
    /// 
    /// The sizes of the perfect binary subtrees in non-increasing order are 
    /// [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree 
    /// is 7.
    ///
    /// Example 3:
    /// Input: root = [1,2,3,null,4], k = 3
    /// Output: -1
    ///
    /// Explanation:
    /// The sizes of the perfect binary subtrees in non-increasing order 
    /// are [1, 1]. There are fewer than 3 perfect binary subtrees.
    ///
    /// Constraints:
    /// 1. The number of nodes in the tree is in the range [1, 2000].
    /// 2. 1 <= Node.val <= 2000
    /// 3. 1 <= k <= 1024
    /// </summary>
    int kthLargestPerfectSubtree(TreeNode* root, int k);

    /// <summary>
    /// Leet Code 3331. Find Subtree Sizes After Changes 
    /// </summary>
    int findSubtreeSizes(int node, vector<vector<int>>& children, vector<int>&parent, string& s, vector<int>& result);

    /// <summary>
    /// Leet Code 3331. Find Subtree Sizes After Changes 
    /// 
    /// Medium
    ///
    /// You are given a tree rooted at node 0 that consists of n nodes 
    /// numbered from 0 to n - 1. The tree is represented by an array parent 
    /// of size n, where parent[i] is the parent of node i. Since node 0 is 
    /// the root, parent[0] == -1.
    ///
    /// You are also given a string s of length n, where s[i] is the character 
    /// assigned to node i.
    ///
    /// We make the following changes on the tree one time simultaneously for 
    /// all nodes x from 1 to n - 1:
    ///
    /// Find the closest node y to node x such that y is an ancestor of x, and 
    /// s[x] == s[y].
    /// If node y does not exist, do nothing.
    /// Otherwise, remove the edge between x and its current parent and make 
    /// node y the new parent of x by adding an edge between them.
    /// Return an array answer of size n where answer[i] is the size of the 
    /// subtree rooted at node i in the final tree.
    ///
    /// A subtree of treeName is a tree consisting of a node in treeName and 
    /// all of its descendants.
    ///
    /// Example 1:
    /// Input: parent = [-1,0,0,1,1,1], s = "abaabc"
    /// Output: [6,3,1,1,1,1]
    /// Explanation:
    /// The parent of node 3 will change from node 1 to node 0.
    ///
    /// Example 2:
    /// Input: parent = [-1,0,4,0,1], s = "abbba"
    /// Output: [5,2,1,1,1]
    /// 
    /// Explanation:
    /// The following changes will happen at the same time:
    /// The parent of node 4 will change from node 1 to node 0.
    /// The parent of node 2 will change from node 4 to node 1.
    ///
    /// Constraints:
    /// 1. n == parent.length == s.length
    /// 2. 1 <= n <= 10^5
    /// 3. 0 <= parent[i] <= n - 1 for all i >= 1.
    /// 4. parent[0] == -1
    /// 5. parent represents a valid tree.
    /// 6. s consists only of lowercase English letters.
    /// </summary>
    vector<int> findSubtreeSizes(vector<int>& parent, string s);

    /// <summary>
    /// Leet Code 3372. Maximize the Number of Target Nodes After Connecting 
    ///                 Trees I
    /// Medium
    /// </summary>
    int maxTargetNodesI(vector<vector<int>>& neighbors, int parent, int node, int k);

    /// <summary>
    /// Leet Code 3372. Maximize the Number of Target Nodes After Connecting 
    ///                 Trees I
    /// 
    /// Medium
    /// 
    /// There exist two undirected trees with n and m nodes, with distinct 
    /// labels in ranges [0, n - 1] and [0, m - 1], respectively.
    ///
    /// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 
    /// and m - 1, respectively, where edges1[i] = [ai, bi] indicates that 
    /// there is an edge between nodes ai and bi in the first tree and 
    /// edges2[i] = [ui, vi] indicates that there is an edge between nodes ui 
    /// and vi in the second tree. You are also given an integer k.
    ///
    /// Node u is target to node v if the number of edges on the path from u 
    /// to v is less than or equal to k. Note that a node is always target 
    /// to itself.
    ///
    /// Return an array of n integers answer, where answer[i] is the maximum 
    /// possible number of nodes target to node i of the first tree if you 
    /// have to connect one node from the first tree to another node in the 
    /// second tree.
    ///
    /// Note that queries are independent from each other. That is, for every 
    /// query you will remove the added edge before proceeding to the next 
    /// query.
    ///
    /// Example 1:
    /// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],
    /// [2,7],[1,4],[4,5],[4,6]], k = 2
    /// Output: [9,7,9,8,8]
    /// 
    /// Explanation:
    /// For i = 0, connect node 0 from the first tree to node 0 from the 
    /// second tree.
    /// For i = 1, connect node 1 from the first tree to node 0 from the 
    /// second tree.
    /// For i = 2, connect node 2 from the first tree to node 4 from the 
    /// second tree.
    /// For i = 3, connect node 3 from the first tree to node 4 from the 
    /// second tree.
    /// For i = 4, connect node 4 from the first tree to node 4 from the 
    /// second tree.
    ///
    /// Example 2:
    /// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], 
    /// edges2 = [[0,1],[1,2],[2,3]], k = 1
    /// Output: [6,3,3,3,3]
    /// Explanation:
    /// For every i, connect node i of the first tree with any node of the 
    /// second tree.
    /// Constraints:
    /// 1. 2 <= n, m <= 1000
    /// 2. edges1.length == n - 1
    /// 3. edges2.length == m - 1
    /// 4. edges1[i].length == edges2[i].length == 2
    /// 5. edges1[i] = [ai, bi]
    /// 6. 0 <= ai, bi < n
    /// 7. edges2[i] = [ui, vi]
    /// 8. 0 <= ui, vi < m
    /// 9. The input is generated such that edges1 and edges2 represent valid 
    ///    trees.
    /// 10. 0 <= k <= 1000
    /// </summary>
    vector<int> maxTargetNodesI(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k);

    /// <summary>
    /// Leet Code 3373. Maximize the Number of Target Nodes After Connecting 
    ///                 Trees II
    /// </summary>
    vector<int> maxTargetNodesII(vector<vector<int>>& neighbors, vector<int>& parity);



    /// <summary>
    /// Leet Code 3373. Maximize the Number of Target Nodes After Connecting 
    ///                 Trees II
    /// 
    /// Hard
    /// 
    /// There exist two undirected trees with n and m nodes, labeled from 
    /// [0, n - 1] and [0, m - 1], respectively.
    ///
    /// You are given two 2D integer arrays edges1 and edges2 of lengths 
    /// n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates 
    /// that there is an edge between nodes ai and bi in the first tree 
    /// and edges2[i] = [ui, vi] indicates that there is an edge between 
    /// nodes ui and vi in the second tree.
    ///
    /// Node u is target to node v if the number of edges on the path from u 
    /// to v is even. Note that a node is always target to itself.
    ///
    /// Return an array of n integers answer, where answer[i] is the maximum 
    /// possible number of nodes that are target to node i of the first tree 
    /// if you had to connect one node from the first tree to another node in 
    /// the second tree.
    ///
    /// Note that queries are independent from each other. That is, for every 
    /// query you will remove the added edge before proceeding to the next 
    /// query.
    ///
    /// Example 1:
    /// Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], 
    /// edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
    /// Output: [8,7,7,8,8]
    /// Explanation:
    /// For i = 0, connect node 0 from the first tree to node 0 from the 
    /// second tree.
    /// For i = 1, connect node 1 from the first tree to node 4 from the 
    /// second tree.
    /// For i = 2, connect node 2 from the first tree to node 7 from the 
    /// second tree.
    /// For i = 3, connect node 3 from the first tree to node 0 from the 
    /// second tree.
    /// For i = 4, connect node 4 from the first tree to node 4 from the 
    /// second tree.
    ///
    /// Example 2:
    /// Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], 
    /// edges2 = [[0,1],[1,2],[2,3]]
    /// Output: [3,6,6,6,6]
    /// Explanation:
    /// For every i, connect node i of the first tree with any node of the 
    /// second tree.
    /// 
    /// Constraints:
    /// 1. 2 <= n, m <= 10^5
    /// 2. edges1.length == n - 1
    /// 3. edges2.length == m - 1
    /// 4. edges1[i].length == edges2[i].length == 2
    /// 5. edges1[i] = [ai, bi]
    /// 6. 0 <= ai, bi < n
    /// 7. edges2[i] = [ui, vi]
    /// 8. 0 <= ui, vi < m
    /// 9. The input is generated such that edges1 and edges2 represent valid 
    ///    trees.
    /// </summary>
    vector<int> maxTargetNodesII(vector<vector<int>>& edges1, vector<vector<int>>& edges2);

    /// <summary>
    /// Leet Code 3367. Maximize Sum of Weights after Edge Removals
    /// </summary>
    pair<long long, long long> maximizeSumOfWeights(vector<vector<pair<int, int>>>& children, int parent, int node, int k);

    /// <summary>
    /// Leet Code 3367. Maximize Sum of Weights after Edge Removals
    /// 
    /// Hard
    ///
    /// There exists an undirected tree with n nodes numbered 0 to n - 1. 
    /// You are given a 2D integer array edges of length n - 1, where 
    /// edges[i] = [ui, vi, wi] indicates that there is an edge between 
    /// nodes ui and vi with weight wi in the tree.
    ///
    /// Your task is to remove zero or more edges such that:
    /// Each node has an edge with at most k other nodes, where k is given.
    /// The sum of the weights of the remaining edges is maximized.
    /// Return the maximum possible sum of weights for the remaining edges 
    /// after making the necessary removals.
    ///
    /// Example 1:
    /// Input: edges = [[0,1,4],[0,2,2],[2,3,12],[2,4,6]], k = 2
    /// Output: 22
    /// Explanation:
    /// 
    /// Node 2 has edges with 3 other nodes. We remove the edge [0, 2, 2], 
    /// ensuring that no node has edges with more than k = 2 nodes.
    /// The sum of weights is 22, and we can't achieve a greater sum. Thus, 
    /// the answer is 22.
    ///
    /// Example 2:
    /// Input: edges = [[0,1,5],[1,2,10],[0,3,15],[3,4,20],[3,5,5],[0,6,10]], 
    /// k = 3
    /// Output: 65
    /// Explanation:
    /// Since no node has edges connecting it to more than k = 3 nodes, we 
    /// don't remove any edges.
    /// The sum of weights is 65. Thus, the answer is 65.
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. 1 <= k <= n - 1
    /// 3. edges.length == n - 1
    /// 4. edges[i].length == 3
    /// 5. 0 <= edges[i][0] <= n - 1
    /// 6. 0 <= edges[i][1] <= n - 1
    /// 7. 1 <= edges[i][2] <= 10^6
    /// 8. The input is generated such that edges form a valid tree.
    /// </summary>
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k);

    /// <summary>
    /// Leet Code 3425. Longest Special Path
    /// </summary>
    void longestSpecialPath(int parent, int node,
        vector<int>& nums,
        vector<vector<pair<int, int>>>& neighbors, 
        vector<int>& prefix_sum, 
        int start_index,
        unordered_map<int, vector<int>>& positions,
        vector<int> &result);

    /// <summary>
    /// Leet Code 3425. Longest Special Path
    ///   
    /// Hard
    ///
    /// You are given an undirected tree rooted at node 0 with n nodes 
    /// numbered from 0 to n - 1, represented by a 2D array edges of length 
    /// n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between 
    /// nodes ui and vi with length lengthi. You are also given an integer 
    /// array nums, where nums[i] represents the value at node i.
    ///
    /// A special path is defined as a downward path from an ancestor node 
    /// to a descendant node such that all the values of the nodes in that 
    /// path are unique.
    ///
    /// Note that a path may start and end at the same node.
    ///
    /// Return an array result of size 2, where result[0] is the length of 
    /// the longest special path, and result[1] is the minimum number of 
    /// nodes in all possible longest special paths.
    ///
    /// Example 1:
    /// Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], 
    /// nums = [2,1,2,1,3,1]
    ///
    /// Output: [6,2]
    /// Explanation:
    /// In the image below, nodes are colored by their corresponding values 
    /// in nums
    /// 
    /// The longest special paths are 2 -> 5 and 0 -> 1 -> 4, both having a 
    /// length of 6. The minimum number of nodes across all longest special 
    /// paths is 2.
    ///
    /// Example 2:
    /// Input: edges = [[1,0,8]], nums = [2,2]
    /// Output: [0,1]
    /// Explanation:
    /// 
    /// The longest special paths are 0 and 1, both having a length of 0. The 
    /// minimum number of nodes across all longest special paths is 1.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 5 * 10^4
    /// 2. edges.length == n - 1
    /// 3. edges[i].length == 3
    /// 4. 0 <= ui, vi < n
    /// 5. 1 <= lengthi <= 10^3
    /// 6. nums.length == n
    /// 7. 0 <= nums[i] <= 5 * 10^4
    /// 8. The input is generated such that edges represents a valid tree.
    /// </summary>
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums);

    /// <summary>
    /// Leet Code 3486. Longest Special Path
    /// </summary>
    void longestSpecialPathII(int parent, int node,
        vector<int>& nums,
        vector<vector<pair<int, int>>>& neighbors,
        vector<int>& prefix_sum,
        int start_index,
        int last_dup,
        unordered_map<int, vector<int>>& positions,
        vector<int>& result);

    /// <summary>
    /// Leet Code 3486. Longest Special Path II
    ///
    /// Hard
    /// 
    /// You are given an undirected tree rooted at node 0, with n nodes numbered 
    /// from 0 to n - 1. This is represented by a 2D array edges of length n - 1, 
    /// where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui 
    /// and vi with length lengthi. You are also given an integer array nums, 
    /// where nums[i] represents the value at node i.
    ///
    /// A special path is defined as a downward path from an ancestor node to a 
    /// descendant node in which all node values are distinct, except for at 
    /// most one value that may appear twice.
    ///
    /// Return an array result of size 2, where result[0] is the length of the 
    /// longest special path, and result[1] is the minimum number of nodes in 
    /// all possible longest special paths.
    ///
    /// Example 1:
    /// 
    /// Input: edges = [[0,1,1],[1,2,3],[1,3,1],[2,4,6],[4,7,2],[3,5,2],[3,6,5],
    /// [6,8,3]], nums = [1,1,0,3,1,2,1,1,0]
    /// Output: [9,3]
    /// Explanation:
    /// In the image below, nodes are colored by their corresponding values in 
    /// nums.
    /// 
    /// The longest special paths are 1 -> 2 -> 4 and 1 -> 3 -> 6 -> 8, both 
    /// having a length of 9. The minimum number of nodes across all longest 
    /// special paths is 3.
    ///
    /// Example 2:
    /// Input: edges = [[1,0,3],[0,2,4],[0,3,5]], nums = [1,1,0,2]
    /// Output: [5,2]
    /// Explanation:
    /// The longest path is 0 -> 3 consisting of 2 nodes with a length of 5.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 5 * 10^4
    /// 2. edges.length == n - 1
    /// 3. edges[i].length == 3
    /// 4. 0 <= ui, vi < n
    /// 5. 1 <= lengthi <= 10^3
    /// 6. nums.length == n
    /// 7. 0 <= nums[i] <= 5 * 10^4
    /// 8. The input is generated such that edges represents a valid tree.
    /// </summary>
    vector<int> longestSpecialPathII(vector<vector<int>>& edges, vector<int>& nums);

    /// <summary>
    /// Leet Code 3515. Shortest Path in a Weighted Tree
    /// </summary>
    int treeQueries(int parent, int node, vector<vector<pair<int, int>>>& neighbors,
        vector<int>& weights, BinaryIndexTree &bit, vector<int> &tin, vector<int>& tout, int index);

    /// <summary>
    /// Leet Code 3515. Shortest Path in a Weighted Tree
    ///
    /// Hard
    ///
    /// You are given an integer n and an undirected, weighted tree rooted at 
    /// node 1 with n nodes numbered from 1 to n. This is represented by a 2D 
    /// array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates 
    /// an undirected edge from node ui to vi with weight wi.
    /// You are also given a 2D integer array queries of length q, 
    /// where each queries[i] is either:
    /// [1, u, v, w'] – Update the weight of the edge between nodes u and v 
    /// to w', where (u, v) is guaranteed to be an edge present in edges.
    /// [2, x] – Compute the shortest path distance from the root node 1 to 
    /// node x.
    /// Return an integer array answer, where answer[i] is the shortest 
    /// path distance from node 1 to x for the ith query of [2, x].
    ///
    /// Example 1:
    /// Input: n = 2, edges = [[1,2,7]], queries = [[2,2],[1,1,2,4],[2,2]]
    /// Output: [7,4]
    /// Explanation:
    /// 
    /// Query [2,2]: The shortest path from root node 1 to node 2 is 7.
    /// Query [1,1,2,4]: The weight of edge (1,2) changes from 7 to 4.
    /// Query [2,2]: The shortest path from root node 1 to node 2 is 4.
    ///
    /// Example 2:
    /// Input: n = 3, edges = [[1,2,2],[1,3,4]], queries = [[2,1],[2,3],
    /// [1,1,3,7],[2,2],[2,3]]
    /// Output: [0,4,2,7]
    /// Explanation:
    /// Query [2,1]: The shortest path from root node 1 to node 1 is 0.
    /// Query [2,3]: The shortest path from root node 1 to node 3 is 4.
    /// Query [1,1,3,7]: The weight of edge (1,3) changes from 4 to 7.
    /// Query [2,2]: The shortest path from root node 1 to node 2 is 2.
    /// Query [2,3]: The shortest path from root node 1 to node 3 is 7.
    ///
    /// Example 3:
    /// Input: n = 4, edges = [[1,2,2],[2,3,1],[3,4,5]], queries = 
    /// [[2,4],[2,3],[1,2,3,3],[2,2],[2,3]]
    /// Output: [8,3,2,5]
    /// Explanation:
    /// Query [2,4]: The shortest path from root node 1 to node 4 consists 
    /// of edges (1,2), (2,3), and (3,4) with weights 2 + 1 + 5 = 8.
    /// Query [2,3]: The shortest path from root node 1 to node 3 consists 
    /// of edges (1,2) and (2,3) with weights 2 + 1 = 3.
    /// Query [1,2,3,3]: The weight of edge (2,3) changes from 1 to 3.
    /// Query [2,2]: The shortest path from root node 1 to node 2 is 2.
    /// Query [2,3]: The shortest path from root node 1 to node 3 consists 
    /// of edges (1,2) and (2,3) with updated weights 2 + 3 = 5.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i] == [ui, vi, wi]
    /// 4. 1 <= ui, vi <= n
    /// 5. 1 <= wi <= 10^4
    /// 6. The input is generated such that edges represents a valid tree.
    /// 7. 1 <= queries.length == q <= 10^5
    /// 8. queries[i].length == 2 or 4
    /// 9. queries[i] == [1, u, v, w'] or,
    /// 10. queries[i] == [2, x]
    /// 11. 1 <= u, v, x <= n
    /// 12. (u, v) is always an edge from edges.
    /// 13. 1 <= w' <= 10^4
    /// </summary>
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 3544. Subtree Inversion Sum
    /// </summary>
    long long subtreeInversionSum(vector<vector<int>>& neighbors, vector<int>& nums, int k, 
        int parent, int node, int parity, int distance, vector<vector<vector<long long>>>& cache);

    /// <summary>
    /// Leet Code 3544. Subtree Inversion Sum
    ///
    /// Hard
    ///
    /// You are given an undirected tree rooted at node 0, with n nodes numbered 
    /// from 0 to n - 1. The tree is represented by a 2D integer array edges of 
    /// length n - 1, where edges[i] = [ui, vi] indicates an edge between nodes ui 
    /// and vi.
    ///
    /// You are also given an integer array nums of length n, where nums[i] 
    /// represents the value at node i, and an integer k.
    ///
    /// You may perform inversion operations on a subset of nodes subject to the 
    /// following rules:
    ///
    /// Subtree Inversion Operation:
    ///
    /// When you invert a node, every value in the subtree rooted at that node is 
    /// multiplied by -1.
    ///
    /// Distance Constraint on Inversions:
    ///
    /// You may only invert a node if it is "sufficiently far" from any other 
    /// inverted node.
    ///
    /// Specifically, if you invert two nodes a and b such that one is an ancestor 
    /// of the other (i.e., if LCA(a, b) = a or LCA(a, b) = b), then the distance 
    /// (the number of edges on the unique path between them) must be at least k.
    ///
    /// Return the maximum possible sum of the tree's node values after applying 
    /// inversion operations.
    ///
    /// Example 1:
    /// Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], 
    /// nums = [4,-8,-6,3,7,-2,5], k = 2
    /// Output: 27
    /// Explanation:
    /// Apply inversion operations at nodes 0, 3, 4 and 6.
    /// The final nums array is [-4, 8, 6, 3, 7, 2, 5], and the total sum is 27.
    ///
    /// Example 2:
    /// Input: edges = [[0,1],[1,2],[2,3],[3,4]], nums = [-1,3,-2,4,-5], k = 2
    /// Output: 9
    /// Explanation:
    /// Apply the inversion operation at node 4.
    /// The final nums array becomes [-1, 3, -2, 4, 5], and the total sum is 9.
    ///
    /// Example 3:
    /// Input: edges = [[0,1],[0,2]], nums = [0,-1,-2], k = 3
    /// Output: 3
    /// Explanation:
    /// Apply inversion operations at nodes 1 and 2.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 5 * 10^4
    /// 2. edges.length == n - 1
    /// 3. edges[i] = [ui, vi]
    /// 4. 0 <= ui, vi < n
    /// 5. nums.length == n
    /// 6. -5 * 10^4 <= nums[i] <= 5 * 10^4
    /// 7. 1 <= k <= 50
    /// 8. The input is generated such that edges represents a valid tree.
    /// </summary>
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k);

    /// <summary>
    /// Leet Code 3553. Minimum Weighted Subgraph With the Required Paths II
    /// </summary>
    void minimumWeight_dfs(int node, int parent, vector<vector<pair<int, int>>>& neighbors, 
        vector<int>& distances, vector<int>& levels, vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3553. Minimum Weighted Subgraph With the Required Paths II
    /// </summary>
    void minimumWeight_skiplist(vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3553. Minimum Weighted Subgraph With the Required Paths II
    /// </summary>
    int minimumWeight_lca(int a, int b, vector<int>& levels, vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3553. Minimum Weighted Subgraph With the Required Paths II
    ///
    /// Hard
    ///
    /// You are given an undirected weighted tree with n nodes, numbered from 0 to 
    /// n - 1. It is represented by a 2D integer array edges of length n - 1, 
    /// where edges[i] = [ui, vi, wi] indicates that there is an edge between 
    /// nodes ui and vi with weight wi.​
    ///
    /// Additionally, you are given a 2D integer array queries, where 
    /// queries[j] = [src1j, src2j, destj].
    ///
    /// Return an array answer of length equal to queries.length, where answer[j] 
    /// is the minimum total weight of a subtree such that it is possible to 
    /// reach destj from both src1j and src2j using edges in this subtree.
    ///
    /// A subtree here is any connected subset of nodes and edges of the original 
    /// tree forming a valid tree.
    /// 
    /// Example 1:
    /// Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], 
    /// queries = [[2,3,4],[0,2,5]]
    /// Output: [12,11]
    /// Explanation:
    /// The blue edges represent one of the subtrees that yield the optimal answer.
    /// answer[0]: The total weight of the selected subtree that ensures a path 
    /// from src1 = 2 and src2 = 3 to dest = 4 is 3 + 5 + 4 = 12.
    /// answer[1]: The total weight of the selected subtree that ensures a path 
    /// from src1 = 0 and src2 = 2 to dest = 5 is 2 + 3 + 6 = 11.
    ///
    /// Example 2:
    /// Input: edges = [[1,0,8],[0,2,7]], queries = [[0,1,2]]
    /// Output: [15]
    /// Explanation:
    /// answer[0]: The total weight of the selected subtree that ensures a path 
    /// from src1 = 0 and src2 = 1 to dest = 2 is 8 + 7 = 15.
    ///
    /// Constraints:
    /// 1. 3 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i].length == 3
    /// 4. 0 <= ui, vi < n
    /// 5. 1 <= wi <= 10^4
    /// 6. 1 <= queries.length <= 10^5
    /// 7. queries[j].length == 3
    /// 8. 0 <= src1j, src2j, destj < n
    /// 9. src1j, src2j, and destj are pairwise distinct.
    /// 10. The input is generated such that edges represents a valid tree.
    /// </summary>
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 3558. Number of Ways to Assign Edge Weights I
    ///
    /// Medium
    ///
    /// There is an undirected tree with n nodes labeled from 1 to n, rooted at 
    /// node 1. The tree is represented by a 2D integer array edges of length 
    /// n - 1, where edges[i] = [ui, vi] indicates that there is an edge between 
    /// nodes ui and vi.
    ///
    /// Initially, all edges have a weight of 0. You must assign each edge a 
    /// weight of either 1 or 2.
    ///
    /// The cost of a path between any two nodes u and v is the total weight 
    /// of all edges in the path connecting them.
    ///
    /// Select any one node x at the maximum depth. Return the number of ways to 
    /// assign edge weights in the path from node 1 to x such that its total cost 
    /// is odd.
    ///
    /// Since the answer may be large, return it modulo 10^9 + 7.
    /// Note: Ignore all edges not in the path from node 1 to x.
    ///
    /// Example 1:
    /// Input: edges = [[1,2]]
    /// Output: 1
    /// Explanation:
    /// The path from Node 1 to Node 2 consists of one edge (1 → 2).
    /// Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the 
    /// number of valid assignments is 1.
    ///
    /// Example 2:
    /// Input: edges = [[1,2],[1,3],[3,4],[3,5]]
    /// Output: 2
    /// Explanation:
    /// The maximum depth is 2, with nodes 4 and 5 at the same depth. Either 
    /// node can be selected for processing.
    /// For example, the path from Node 1 to Node 4 consists of two edges 
    /// (1 → 3 and 3 → 4).
    /// Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the 
    /// number of valid assignments is 2.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i] == [ui, vi]
    /// 4. 1 <= ui, vi <= n
    /// 5. edges represents a valid tree.
    /// </summary>
    int assignEdgeWeightsI(vector<vector<int>>& edges);

    /// <summary>
    /// Leet Code 3559. Number of Ways to Assign Edge Weights II
    /// </summary>
    void assignEdgeWeightsII_dfs(int node, int parent, vector<vector<int>>& neighbors,
        vector<int>& levels, vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3559. Number of Ways to Assign Edge Weights II
    /// </summary>
    void assignEdgeWeightsII_skiplist(vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3559. Number of Ways to Assign Edge Weights II
    /// </summary>
    int assignEdgeWeightsII_lca(int a, int b, vector<int>& levels, vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3559. Number of Ways to Assign Edge Weights II
    ///
    /// Hard
    ///
    /// There is an undirected tree with n nodes labeled from 1 to n, rooted at 
    /// node 1. The tree is represented by a 2D integer array edges of length 
    /// n - 1, where edges[i] = [ui, vi] indicates that there is an edge between 
    /// nodes ui and vi.
    ///
    /// Initially, all edges have a weight of 0. You must assign each edge a 
    /// weight of either 1 or 2.
    ///
    /// The cost of a path between any two nodes u and v is the total weight of 
    /// all edges in the path connecting them.
    ///
    /// You are given a 2D integer array queries. For each queries[i] = [ui, vi], 
    /// determine the number of ways to assign weights to edges in the path such 
    /// that the cost of the path between ui and vi is odd.
    ///
    /// Return an array answer, where answer[i] is the number of valid assignments 
    /// for queries[i].
    ///
    /// Since the answer may be large, apply modulo 10^9 + 7 to each answer[i].
    ///
    /// Note: For each query, disregard all edges not in the path between node ui 
    /// and vi.
    /// 
    /// Example 1:
    /// Input: edges = [[1,2]], queries = [[1,1],[1,2]]
    /// Output: [0,1]
    /// Explanation:
    /// Query [1,1]: The path from Node 1 to itself consists of no edges, so the 
    /// cost is 0. Thus, the number of valid assignments is 0.
    /// Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 -> 2). 
    /// Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the 
    /// number of valid assignments is 1.
    ///
    /// Example 2:
    /// Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]
    /// Output: [2,1,4]
    /// Explanation:
    /// Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 -> 3 
    /// and 3 -> 4). Assigning weights (1,2) or (2,1) results in an odd cost. 
    /// Thus, the number of valid assignments is 2.
    /// Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 -> 4). 
    /// Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the 
    /// number of valid assignments is 1.
    /// Query [2,5]: The path from Node 2 to Node 5 consists of three edges 
    /// (2 -> 1, 1 -> 3, and 3 -> 5). Assigning (1,2,2), (2,1,2), (2,2,1), or 
    /// (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.
    /// 
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i] == [ui, vi]
    /// 4. 1 <= queries.length <= 10^5
    /// 5. queries[i] == [ui, vi]
    /// 6. 1 <= ui, vi <= n
    /// 7. edges represents a valid tree.
    /// </summary>
    vector<int> assignEdgeWeightsII(vector<vector<int>>& edges, vector<vector<int>>& queries);

    /// <summary>
    /// Leet Code 3562. Maximum Profit from Trading Stocks with Discounts
    /// </summary>
    void maxProfit_dfs(int node, int parent, vector<int>&present, vector<int>&future,
        vector<vector<int>>& neighbors, int budget, vector<vector<vector<int>>> &dp);

    /// <summary>
    /// Leet Code 3562. Maximum Profit from Trading Stocks with Discounts
    ///
    /// Hard
    ///
    /// You are given an integer n, representing the number of employees in a 
    /// company. Each employee is assigned a unique ID from 1 to n, and 
    /// employee 1 is the CEO. You are given two 1-based integer arrays, present 
    /// and future, each of length n, where:
    ///
    /// present[i] represents the current price at which the ith employee can 
    /// buy a stock today.
    /// future[i] represents the expected price at which the ith employee can 
    /// sell the stock tomorrow.
    /// The company's hierarchy is represented by a 2D integer array hierarchy, 
    /// where hierarchy[i] = [ui, vi] means that employee ui is the direct boss 
    /// of employee vi.
    ///
    /// Additionally, you have an integer budget representing the total funds 
    /// available for investment.
    ///
    /// However, the company has a discount policy: if an employee's direct boss 
    /// purchases their own stock, then the employee can buy their stock at half 
    /// the original price (floor(present[v] / 2)).
    ///
    /// Return the maximum profit that can be achieved without exceeding the 
    /// given budget.
    /// 
    /// Note:
    /// You may buy each stock at most once.
    /// You cannot use any profit earned from future stock prices to fund 
    /// additional investments and must buy only from budget.
    /// 
    /// Example 1:
    /// Input: n = 2, present = [1,2], future = [4,3], hierarchy = [[1,2]], 
    /// budget = 3
    /// Output: 5
    /// Explanation:
    /// Employee 1 buys the stock at price 1 and earns a profit of 4 - 1 = 3.
    /// Since Employee 1 is the direct boss of Employee 2, Employee 2 gets a 
    /// discounted price of floor(2 / 2) = 1.
    /// Employee 2 buys the stock at price 1 and earns a profit of 3 - 1 = 2.
    /// The total buying cost is 1 + 1 = 2 <= budget. Thus, the maximum total 
    /// profit achieved is 3 + 2 = 5.
    ///
    /// Example 2:
    /// Input: n = 2, present = [3,4], future = [5,8], hierarchy = [[1,2]], 
    /// budget = 4
    /// Output: 4
    /// Explanation:
    /// Employee 2 buys the stock at price 4 and earns a profit of 8 - 4 = 4.
    /// Since both employees cannot buy together, the maximum profit is 4.
    ///
    /// Example 3:
    /// Input: n = 3, present = [4,6,8], future = [7,9,11], 
    /// hierarchy = [[1,2],[1,3]], budget = 10
    /// Output: 10
    /// Explanation:
    /// Employee 1 buys the stock at price 4 and earns a profit of 7 - 4 = 3.
    /// Employee 3 would get a discounted price of floor(8 / 2) = 4 and earns 
    /// a profit of 11 - 4 = 7.
    /// Employee 1 and Employee 3 buy their stocks at a total cost of 
    /// 4 + 4 = 8 <= budget. Thus, the maximum total profit achieved is 3 + 7 = 10.
    ///
    /// Example 4:
    /// Input: n = 3, present = [5,2,3], future = [8,5,6], 
    /// hierarchy = [[1,2],[2,3]], budget = 7
    /// Output: 12
    /// Explanation:
    /// Employee 1 buys the stock at price 5 and earns a profit of 8 - 5 = 3.
    /// Employee 2 would get a discounted price of floor(2 / 2) = 1 and earns a 
    /// profit of 5 - 1 = 4.
    /// Employee 3 would get a discounted price of floor(3 / 2) = 1 and earns a 
    /// profit of 6 - 1 = 5.
    /// The total cost becomes 5 + 1 + 1 = 7 <= budget. Thus, the maximum total 
    /// profit achieved is 3 + 4 + 5 = 12.
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 160
    /// 2. present.length, future.length == n
    /// 3. 1 <= present[i], future[i] <= 50
    /// 4. hierarchy.length == n - 1
    /// 5. hierarchy[i] == [ui, vi]
    /// 6. 1 <= ui, vi <= n
    /// 7. ui != vi
    /// 8. 1 <= budget <= 160
    /// 9. There are no duplicate edges.
    /// 10. Employee 1 is the direct or indirect boss of every employee.
    /// 11. The input graph hierarchy is guaranteed to have no cycles.
    /// </summary>
    int maxProfit(int n, vector<int>& present, vector<int>& future, 
        vector<vector<int>>& hierarchy, int budget);

    /// <summary>
    /// Leet Code 3575. Maximum Good Subtree Score
    /// </summary>
    unordered_map<int, int> goodSubtreeSum_dfs(vector<vector<int>> & neighbors, vector<int>& vals, int node, int parent, int &result);

    /// <summary>
    /// Leet Code 3575. Maximum Good Subtree Score
    ///
    /// Hard
    ///
    /// You are given an undirected tree rooted at node 0 with n nodes numbered 
    /// from 0 to n - 1. Each node i has an integer value vals[i], and its 
    /// parent is given by par[i].
    ///
    /// A subset of nodes within the subtree of a node is called good if every 
    /// digit from 0 to 9 appears at most once in the decimal representation 
    /// of the values of the selected nodes.
    ///
    /// The score of a good subset is the sum of the values of its nodes.
    ///
    /// Define an array maxScore of length n, where maxScore[u] represents 
    /// the maximum possible sum of values of a good subset of nodes that belong 
    /// to the subtree rooted at node u, including u itself and all its 
    /// descendants.
    ///
    /// Return the sum of all values in maxScore.
    /// Since the answer may be large, return it modulo 10^9 + 7.
    ///
    /// Example 1:
    /// Input: vals = [2,3], par = [-1,0]
    /// Output: 8
    /// Explanation:
    /// The subtree rooted at node 0 includes nodes {0, 1}. The subset {2, 3} 
    /// is good as the digits 2 and 3 appear only once. The score of this 
    /// subset is 2 + 3 = 5.
    /// The subtree rooted at node 1 includes only node {1}. The subset {3} is 
    /// good. The score of this subset is 3.
    /// The maxScore array is [5, 3], and the sum of all values in maxScore is 
    /// 5 + 3 = 8. Thus, the answer is 8.
    ///
    /// Example 2:
    /// Input: vals = [1,5,2], par = [-1,0,0]
    /// Output: 15
    /// Explanation:
    /// The subtree rooted at node 0 includes nodes {0, 1, 2}. The subset 
    /// {1, 5, 2} is good as the digits 1, 5 and 2 appear only once. The score 
    /// of this subset is 1 + 5 + 2 = 8.
    /// The subtree rooted at node 1 includes only node {1}. The subset {5} is 
    /// good. The score of this subset is 5.
    /// The subtree rooted at node 2 includes only node {2}. The subset {2} is 
    /// good. The score of this subset is 2.
    /// The maxScore array is [8, 5, 2], and the sum of all values in maxScore 
    /// is 8 + 5 + 2 = 15. Thus, the answer is 15.
    ///
    /// Example 3:
    /// Input: vals = [34,1,2], par = [-1,0,1]
    /// Output: 42
    /// Explanation:
    /// The subtree rooted at node 0 includes nodes {0, 1, 2}. The subset 
    /// {34, 1, 2} is good as the digits 3, 4, 1 and 2 appear only once. The 
    /// score of this subset is 34 + 1 + 2 = 37.
    /// The subtree rooted at node 1 includes node {1, 2}. The subset {1, 2} is 
    /// good as the digits 1 and 2 appear only once. The score of this subset 
    /// is 1 + 2 = 3.
    /// The subtree rooted at node 2 includes only node {2}. The subset {2} is 
    /// good. The score of this subset is 2.
    /// The maxScore array is [37, 3, 2], and the sum of all values in maxScore 
    /// is 37 + 3 + 2 = 42. Thus, the answer is 42.
    ///
    /// Example 4:
    /// Input: vals = [3,22,5], par = [-1,0,1]
    /// Output: 18
    /// Explanation:
    /// The subtree rooted at node 0 includes nodes {0, 1, 2}. The subset 
    /// {3, 22, 5} is not good, as digit 2 appears twice. Therefore, the subset 
    /// {3, 5} is valid. The score of this subset is 3 + 5 = 8.
    /// The subtree rooted at node 1 includes nodes {1, 2}. The subset {22, 5} is 
    /// not good, as digit 2 appears twice. Therefore, the subset {5} is valid. 
    /// The score of this subset is 5.
    /// The subtree rooted at node 2 includes {2}. The subset {5} is good. The 
    /// score of this subset is 5.
    /// The maxScore array is [8, 5, 5], and the sum of all values in maxScore 
    /// is 8 + 5 + 5 = 18. Thus, the answer is 18.
    /// 
    /// Constraints:
    /// 1. 1 <= n == vals.length <= 500
    /// 2. 1 <= vals[i] <= 10^9
    /// 3. par.length == n
    /// 4. par[0] == -1
    /// 5. 0 <= par[i] < n for i in [1, n - 1]
    /// 6. The input is generated such that the parent array par represents a 
    ///    valid tree.
    /// </summary>
    int goodSubtreeSum(vector<int>& vals, vector<int>& par);

    /// <summary>
    /// Leet Code 3585. Find Weighted Median Node in Tree
    /// </summary>
    void findMedian_dfs(int node, int parent, vector<vector<pair<int, int>>>& neighbors,
        vector<long long>& distances, vector<int>& levels, vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3585. Find Weighted Median Node in Tree
    /// </summary>
    void findMedian_skiplist(vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3585. Find Weighted Median Node in Tree
    /// </summary>
    int findMedian_distance(int a, vector<vector<int>>& parents, vector<long long>& distances, double expected, bool is_greater);

    /// <summary>
    /// Leet Code 3585. Find Weighted Median Node in Tree
    /// </summary>
    int findMedian_lca(int a, int b, vector<int>& levels, vector<vector<int>>& parents);

    /// <summary>
    /// Leet Code 3585. Find Weighted Median Node in Tree
    ///
    /// Hard
    ///
    /// You are given an integer n and an undirected, weighted tree rooted at 
    /// node 0 with n nodes numbered from 0 to n - 1. This is represented by a 
    /// 2D array edges of length n - 1, where edges[i] = [ui, vi, wi] indicates 
    /// an edge from node ui to vi with weight wi.
    ///
    /// The weighted median node is defined as the first node x on the path from 
    /// ui to vi such that the sum of edge weights from ui to x is greater than 
    /// or equal to half of the total path weight.
    ///
    /// You are given a 2D integer array queries. For each queries[j] = [uj, vj], 
    /// determine the weighted median node along the path from uj to vj.
    ///
    /// Return an array ans, where ans[j] is the node index of the weighted median 
    /// for queries[j].
    /// 
    /// Example 1:
    /// Input: n = 2, edges = [[0,1,7]], queries = [[1,0],[0,1]]
    /// Output: [0,1]
    /// Explanation:
    /// 
    /// Query   Path    Edge
    /// Weights Total
    /// Path
    /// Weight  Half    Explanation Answer
    /// [1, 0]  1 -> 0   [7] 7   3.5 Sum from 1 -> 0 = 7 >= 3.5, median is node 0. 
    /// 
    /// [0, 1]  0 -> 1   [7] 7   3.5 Sum from 0 -> 1 = 7 >= 3.5, median is node 1. 
    ///
    /// Example 2:
    /// Input: n = 3, edges = [[0,1,2],[2,0,4]], queries = [[0,1],[2,0],[1,2]]
    /// 
    /// Output: [1,0,2]
    /// Explanation:
    /// Query   Path    Edge
    /// Weights Total
    /// Path
    /// Weight  Half    Explanation Answer
    /// [0, 1]  0 -> 1   [2] 2   1   Sum from 0 -> 1 = 2 >= 1, median is node 1. 
    /// [2, 0]  2 -> 0   [4] 4   2   Sum from 2 -> 0 = 4 >= 2, median is node 0.
    /// [1, 2]  1 -> 0 -> 2   [2, 4]  6   3   Sum from 1 -> 0 = 2 < 3.
    /// Sum from 1 -> 2 = 2 + 4 = 6 >= 3, median is node 2.
    ///
    /// Example 3:
    /// Input: n = 5, edges = [[0,1,2],[0,2,5],[1,3,1],[2,4,3]], 
    /// queries = [[3,4],[1,2]]
    /// Output: [2,2]
    /// Explanation:
    /// Query   Path    Edge
    /// Weights Total
    /// Path
    /// Weight  Half    Explanation Answer
    /// [3, 4]  3 -> 1 -> 0 -> 2 -> 4   [1, 2, 5, 3]    11  5.5 Sum 
    /// from 3 -> 1 = 1 < 5.5.
    /// Sum from 3 -> 0 = 1 + 2 = 3 < 5.5.
    /// Sum from 3 -> 2 = 1 + 2 + 5 = 8 >= 5.5, median is node 2. 
    /// [1, 2]  1 -> 0 -> 2   [2, 5]  7   3.5 
    /// Sum from 1 -> 0 = 2 < 3.5.
    /// Sum from 1 -> 2 = 2 + 5 = 7 >= 3.5, median is node 2.
    ///
    /// Constraints:
    /// 1. 2 <= n <= 10^5
    /// 2. edges.length == n - 1
    /// 3. edges[i] == [ui, vi, wi]
    /// 4. 0 <= ui, vi < n
    /// 5. 1 <= wi <= 10^9
    /// 6. 1 <= queries.length <= 10^5
    /// 7. queries[j] == [uj, vj]
    /// 8. 0 <= uj, vj < n
    /// 9. The input is generated such that edges represents a valid tree.
    /// </summary>
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries);
#pragma endregion
};


#endif  // LeetCodeTree_H
