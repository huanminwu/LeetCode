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
/// The class is to implement array related algorithm  
/// </summary>
class LeetCodeTree
{
public:
#pragma region Tree
    /// <summary>
    /// Free link tree nodes
    /// </summary>
    void freeLinkTreeNodes(TreeLinkNode* root);

    /// <summary>
    /// Find a tree node with value
    /// </summary>
    TreeNode* findTreeNode(TreeNode* root, int value);

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
    /// Leet code #107. Binary Tree Level Order Traversal II 
    /// Given a binary tree, return the bottom-up level order traversal 
    /// of its nodes' values. (ie, from left to right, level by level 
    /// from leaf to root).
    /// For example:
    /// Given binary tree [3,9,20,null,null,15,7],
    ///    3
    ///   / \
    ///  9  20
    ///    /  \
    ///   15   7
    /// return its bottom-up level order traversal as:
    ///	[
    ///   [15,7],
    ///   [9,20],
    ///   [3]
    /// ]
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
    void connectRight(TreeLinkNode* root);

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
    void connectRightII(TreeLinkNode* root);

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
    /// Leet code #110. Balanced Binary Tree
    /// Given a binary tree, determine if it is height-balanced.
    /// For this problem, a height-balanced binary tree is defined as a binary 
    /// tree in which the depth of the 
    /// two subtrees of every node never differ by more than 1. 
    /// </summary>
    bool isBalanced(TreeNode* root);

    /// <summary>
    /// Leet code #236. Lowest Common Ancestor of a Binary Tree
    /// </summary>
    int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& result);

    /// <summary>
    /// Leet code #236. Lowest Common Ancestor of a Binary Tree
    /// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. 
    /// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
    /// nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).” 
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
    /// Leet code #101. Symmetric Tree 
    /// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). 
    /// For example, this binary tree [1,2,2,3,4,4,3] is symmetric: 
    ///     1
    ///    / \
    ///   2   2
    ///  / \ / \
    /// 3  4 4  3
    /// But the following [1,2,2,null,3,null,3] is not:
    ///    1
    ///   / \
    ///  2   2
    ///   \   \
    ///   3    3
    /// Note:
    /// Bonus points if you could solve it both recursively and iteratively.
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

#pragma endregion
};
#endif  // LeetCodeTree_H
