#pragma once
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

/// <summary>
/// Leet code #1261. Find Elements in a Contaminated Binary Tree
/// 
/// Given a binary tree with the following rules:
///
/// root.val == 0
/// If treeNode.val == x and treeNode.left != null, then 
/// treeNode.left.val == 2 * x + 1
/// If treeNode.val == x and treeNode.right != null, then 
/// treeNode.right.val == 2 * x + 2
/// Now the binary tree is contaminated, which means all treeNode.val 
/// have been changed to -1.
///
/// You need to first recover the binary tree and then implement the 
/// FindElements class:
///
/// FindElements(TreeNode* root) Initializes the object with a 
/// contamined binary tree, you need to recover it first.
/// bool find(int target) Return if the target value exists in 
/// the recovered binary tree.
/// 
/// Example 1:
/// 
/// Input 
/// ["FindElements","find","find"]
/// [[[-1,null,-1]],[1],[2]]
/// Output
/// [null,false,true]
/// Explanation
/// FindElements findElements = new FindElements([-1,null,-1]); 
/// findElements.find(1); // return False 
/// findElements.find(2); // return True 
///
/// Example 2:
/// Input
/// ["FindElements","find","find","find"]
/// [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
/// Output
/// [null,true,true,false]
/// Explanation
/// FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
/// findElements.find(1); // return True
/// findElements.find(3); // return True
/// findElements.find(5); // return False
///
/// Example 3:
/// 
/// Input
/// ["FindElements","find","find","find","find"]
/// [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
/// Output
/// [null,true,false,false,true]
/// Explanation
/// FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
/// findElements.find(2); // return True
/// findElements.find(3); // return False
/// findElements.find(4); // return False
/// findElements.find(5); // return True
///
/// Constraints:
/// 1. TreeNode.val == -1
/// 2. The height of the binary tree is less than or equal to 20
/// 3. The total number of nodes is between [1, 10^4]
/// 4. Total calls of find() is between [1, 10^4]
/// 5. 0 <= target <= 10^6
/// </summary>
class FindElements 
{
private:
    TreeNode* m_root;
public:
    FindElements(TreeNode* root) 
    {
        m_root = root;
        queue<TreeNode *> search;
        if (root == nullptr) return;
        root->val = 0;
        search.push(root);
        while (!search.empty())
        {
            TreeNode* node = search.front();
            search.pop();
            if (node->left != nullptr)
            {
                node->left->val = node->val * 2 + 1;
                search.push(node->left);
            }
            if (node->right != nullptr)
            {
                node->right->val = node->val * 2 + 2;
                search.push(node->right);
            }
        }

    }

    bool find(int target) 
    {
        int start = 0;
        int end = 0;
        while (target > end)
        {
            int length = (end - start + 1) * 2;
            start = end + 1;
            end = start + length - 1;
        }

        TreeNode* node = m_root;
        if (node == nullptr) return false;
        while (start < end)
        {
            int middle = start + (end - start) / 2;
            if (target <= middle)
            {
                if (node->left == nullptr) return false;
                node = node->left;
                end = middle;
            }
            else
            {
                if (node->right == nullptr) return false;
                node = node->right;
                start = middle + 1;
            }
        }
        if (node->val == target) return true;
        else return false;
    }
};

/// <summary>
/// The class is to implement array related algorithm  
/// </summary>
class LeetCodeTree
{
public:
#pragma region Tree

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
    string serialize(TreeNode* root);

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
#pragma endregion
};
#endif  // LeetCodeTree_H
