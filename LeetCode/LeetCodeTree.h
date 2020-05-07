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
#pragma endregion
};
#endif  // LeetCodeTree_H
