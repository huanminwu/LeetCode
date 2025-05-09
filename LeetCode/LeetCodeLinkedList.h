﻿#pragma once
#ifndef LeetCodeLinkedList_H
#define LeetCodeLinkedList_H
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
#include "LeetCodeLinkedList.h"
using namespace std;

struct PolyNode 
{
    int coefficient, power;
    PolyNode* next;
    PolyNode() : coefficient(0), power(0), next(nullptr) {};
    PolyNode(int x, int y) : coefficient(x), power(y), next(nullptr) {};
    PolyNode(int x, int y, PolyNode* next) : coefficient(x), power(y), next(next) {};

    /// <summary>
    /// Helper function which generate a linked list of a integers
    /// </summary>
    static PolyNode* generatePolyNodes(vector<vector<int>> params)
    {
        PolyNode* head = new PolyNode();
        PolyNode* prev = head;
        for (size_t i = 0; i < params.size(); i++)
        {
            PolyNode* node = new PolyNode(params[i][0], params[i][1]);
            prev->next = node;
            prev = prev->next;
        }
        prev = head->next;
        delete head;
        return prev;
    }

    /// <summary>
    /// Free list nodes
    /// </summary>
    static void freeListNodes(PolyNode* head)
    {
        while (head != nullptr)
        {
            PolyNode* node = head;
            head = head->next;
            delete node;
        }
    }

    static string ToString(PolyNode* node)
    {
        std::string message;
        message.push_back('[');
        while (node != nullptr)
        {
            message.push_back('[');
            message.append(to_string(node->coefficient) + "," + to_string(node->power));
            node = node->next;
            message.push_back(']');
        }
        message.push_back(']');
        return message;
    }
};

/// <summary>
/// The class is to implement stack based algorithm  
/// </summary>
class LeetCodeLinkedList
{
public:
    /// <summary>
    /// Helper function which generate a cyclic linked list of a integers
    /// </summary>
    ListNode* generateCyclicListNodes(vector<int> integers);

    /// <summary>
    /// Free a cyclic linked list nodes
    /// </summary>
    void freeCyclicListNodes(ListNode* head);

    /// <summary>
    /// Output a cyclic linked list nodes
    /// </summary>
    vector<int> outputCyclicListNodes(ListNode* head);

    /// <summary>
    /// Add a list of list node at the end
    /// </summary>
    ListNode* addListNodes(ListNode* head, ListNode* tail);


#pragma region LinkedList
    /// <summary>
    /// Helper function which generate a list of random list nodes
    /// </summary>
    RandomListNode* generateRandomListNodes(vector<int> integers);

    /// <summary>
    /// Free random list nodes
    /// </summary>
    void freeRandomListNodes(RandomListNode* head);

    /// <summary>
    /// Helper function which generate a linked list of a integers
    /// </summary>
    ListNode* generateListNodes(vector<int> integers);


    /// <summary>
    /// Helper function which generate a double linked list of a integers
    /// </summary>
    DoublyLinkedNode* generateDoublyLinkedNodes(vector<int> integers);

    /// <summary>
    /// Free list nodes
    /// </summary>
    void freeListNodes(ListNode* head);

    /// <summary>
    /// Find a list node with value
    /// </summary>
    ListNode* findListNode(ListNode* head, int value);

    /// <summary>
    /// Find a double list node with value
    /// </summary>
    DoublyLinkedNode* findListNode(DoublyLinkedNode* head, int value);

    /// <summary>
    /// Leet code #430. Flatten a Multilevel Doubly Linked List
    /// 
    /// You are given a doubly linked list which in addition to the next and 
    /// previous pointers, it could have a child pointer, which may or may 
    /// not point to a separate doubly linked list. These child lists may 
    /// have one or more children of their own, and so on, to produce a 
    /// multilevel data structure, as shown in the example below.
    ///
    /// Flatten the list so that all the nodes appear in a single-level, 
    /// doubly linked list. You are given the head of the first level of the list.
    ///
    /// Example:
    ///
    /// Input:
    /// 1---2---3---4---5---6--NULL
    ///         |
    ///         7---8---9---10--NULL
    ///             |
    ///             11--12--NULL
    ///
    /// Output:
    /// 1-2-3-7-8-11-12-9-10-4-5-6-NULL
    /// </summary>
    DoublyLinkedNode* flatten(DoublyLinkedNode* head);

    /// <summary>
        /// Leet code #427. Construct Quad Tree
        /// </summary>
    bool isQuadTreeLeaf(vector<vector<int>>& grid, int up, int left, int down, int right);

    /// <summary>
    /// Leet code #427. Construct Quad Tree
    /// </summary>
    QuadNode* constructQuadTree(vector<vector<int>>& grid, int up, int left, int down, int right);

    /// <summary>
    /// Leet code #427. Construct Quad Tree
    /// 
    /// We want to use quad trees to store an N x N boolean grid. Each cell in the 
    /// grid can only be true or false. The root node represents the whole grid. 
    /// For each node, it will be subdivided into four children nodes until the 
    /// values in the region it represents are all the same.
    ///
    /// Each node has another two boolean attributes : isLeaf and val. isLeaf is 
    /// true if and only if the node is a leaf node. The val attribute for a leaf 
    /// node contains the value of the region it represents.
    ///
    /// Your task is to use a quad tree to represent a given grid. The following 
    /// example may help you understand the problem better:
    ///
    /// Given the 8 x 8 grid below, we want to construct the corresponding quad 
    /// tree:
    ///
    ///
    /// It can be divided according to the definition above:
    /// The corresponding quad tree should be as following, where each node is 
    /// represented as a (isLeaf, val) pair.
    ///
    /// For the non-leaf nodes, val can be arbitrary, so it is represented as *.
    ///
    /// Note:
    ///
    /// N is less than 1000 and guaranteened to be a power of 2.
    /// </summary>
    QuadNode* constructQuadTree(vector<vector<int>>& grid);

    /// <summary>
    /// Leet code #558. Quad Tree Intersection
    /// </summary>
    QuadNode* collapse(QuadNode* quadTree);

    /// <summary>
    /// Leet code #558. Quad Tree Intersection
    /// </summary>
    QuadNode* clone(QuadNode* quadTree);

    /// <summary>
    /// Leet code #558. Quad Tree Intersection
    /// 
    /// A quadtree is a tree data in which each internal node has exactly four 
    /// children: topLeft, topRight, bottomLeft and bottomRight. Quad trees are 
    /// often used to partition a two-dimensional space by recursively subdividing 
    /// it into four quadrants or regions.
    ///
    /// We want to store True/False information in our quad tree. The quad tree is 
    /// used to represent a N * N boolean grid. For each node, it will be 
    /// subdivided into four children nodes until the values in the region it 
    /// represents are all the same. Each node has another two boolean 
    /// attributes : isLeaf and val. isLeaf is true if and only if the node is a 
    /// leaf node. The val attribute for a leaf node contains the value of the 
    /// region it represents.
    ///
    /// For example, below are two quad trees A and B:
    ///
    /// A:
    /// +-------+-------+   T: true
    /// |       |       |   F: false
    /// |   T   |   T   |
    /// |       |       |
    /// +-------+-------+
    /// |       |       |
    /// |   F   |   F   |
    /// |       |       |
    /// +-------+-------+
    /// topLeft: T
    /// topRight: T
    /// bottomLeft: F
    /// bottomRight: F
    ///
    /// B:               
    /// +-------+---+---+
    /// |       | F | F |
    /// |   T   +---+---+
    /// |       | T | T |
    /// +-------+---+---+
    /// |       |       |
    /// |   T   |   F   |
    /// |       |       |
    /// +-------+-------+
    /// topLeft: T
    /// topRight:
    ///     topLeft: F
    ///     topRight: F
    ///     bottomLeft: T
    ///     bottomRight: T
    /// bottomLeft: T
    /// bottomRight: F
    /// 
    /// Your task is to implement a function that will take two quadtrees and 
    /// return a quadtree that represents the logical OR (or union) of the two 
    /// trees.
    ///
    /// A:                 B:                 C (A or B):
    /// +-------+-------+  +-------+---+---+  +-------+-------+
    /// |       |       |  |       | F | F |  |       |       |
    /// |   T   |   T   |  |   T   +---+---+  |   T   |   T   |
    /// |       |       |  |       | T | T |  |       |       |
    /// +-------+-------+  +-------+---+---+  +-------+-------+
    /// |       |       |  |       |       |  |       |       |
    /// |   F   |   F   |  |   T   |   F   |  |   T   |   F   |
    /// |       |       |  |       |       |  |       |       |
    /// +-------+-------+  +-------+-------+  +-------+-------+
    /// Note:
    /// 
    /// Both A and B represent grids of size N * N.
    /// N is guaranteed to be a power of 2.
    /// If you want to know more about the quad tree, you can refer to its wiki.
    /// The logic OR operation is defined as this: "A or B" is true if A is true, 
    /// or if B is true, or if both A and B are true.
    /// </summary>
    QuadNode* intersect(QuadNode* quadTree1, QuadNode* quadTree2);

    /// <summary>
    /// Leet code #19. Remove Nth Node From End of List 
    /// 
    /// Given a linked list, remove the n-th node from the end of list and return 
    /// its head.
    ///
    /// Example:
    ///
    /// Given linked list: 1->2->3->4->5, and n = 2.
    ///
    /// After removing the second node from the end, the linked list 
    /// becomes 1->2->3->5.
    ///
    /// Note:
    /// 1. Given n will always be valid.
    ///
    /// Follow up:
    /// 
    /// 1. Could you do this in one pass?
    /// </summary>
    ListNode* removeNthFromEnd(ListNode* head, int n);

    /// <summary>
    /// Leet code #138. Copy List with Random Pointer  
    /// 
    /// A linked list is given such that each node contains an additional random 
    /// pointer which could point to any node in the list or null.
    ///
    /// Return a deep copy of the list.
    ///
    /// Example 1:
    ///
    /// Input:
    /// {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},
    ///  "random":{"$ref":"2"},"val":1}
    ///
    /// Explanation:
    /// Node 1's value is 1, both of its next and random pointer points to Node 2.
    /// Node 2's value is 2, its next pointer points to null and its random 
    /// pointer points to itself.
    ///  
    /// Note:
    /// 1. You must return the copy of the given head as a reference to the 
    ///    cloned list.
    /// </summary>
    RandomListNode* copyRandomList(RandomListNode* head);

    /// <summary>
    /// Leet code #23. Merge k Sorted Lists 
    /// 
    /// Merge k sorted linked lists and return it as one sorted list. Analyze and 
    /// describe its complexity.
    ///
    /// Example:
    ///
    /// Input:
    /// [
    ///   1->4->5,
    ///   1->3->4,
    ///   2->6
    /// ]
    /// Output: 1->1->2->3->4->4->5->6
    /// </summary>
    ListNode* mergeKLists(vector<ListNode*>& lists);

    /// <summary>
    /// Leet code #25. Reverse Nodes in k-Group 
    /// 
    /// Given a linked list, reverse the nodes of a linked list k at a time and 
    /// return its modified list.
    ///
    /// k is a positive integer and is less than or equal to the length of the 
    /// linked list. If the number of nodes is not a multiple of k then left-out 
    /// nodes in the end should remain as it is.
    ///
    /// Example:
    ///
    /// Given this linked list: 1->2->3->4->5
    ///
    /// For k = 2, you should return: 2->1->4->3->5
    ///
    /// For k = 3, you should return: 3->2->1->4->5
    ///
    /// Note:
    ///
    /// 1. Only constant extra memory is allowed.
    /// 2. You may not alter the values in the list's nodes, only nodes itself 
    ///    may be changed.
    /// </summary>
    ListNode* reverseKGroup(ListNode* head, int k);

    /// <summary>
    /// Leet code #21. Merge Two Sorted Lists       
    ///
    /// Merge two sorted linked lists and return it as a new list. The new list 
    /// should be made by splicing together the nodes of the first two lists.
    ///
    /// Example: 
    /// Input: 1->2->4, 1->3->4
    /// Output: 1->1->2->3->4->4
    /// </summary>
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    /// <summary>
    /// Leet code #148. Sort List        
    ///
    /// Sort a linked list in O(n log n) time using constant space complexity.
    ///
    /// Example 1:
    /// Input: 4->2->1->3
    /// Output: 1->2->3->4
    ///
    /// Example 2:
    /// Input: -1->5->3->4->0
    /// Output: -1->0->3->4->5
    /// </summary>
    ListNode* sortList(ListNode* head);

    /// <summary>
    /// Leet code #142. Linked List Cycle II      
    ///
    /// Given a linked list, return the node where the cycle begins. If there 
    /// is no cycle, return null.
    ///
    /// To represent a cycle in the given linked list, we use an integer pos 
    /// which represents the position (0-indexed) in the linked list where tail 
    /// connects to. If pos is -1, then there is no cycle in the linked list.
    ///
    /// Note: Do not modify the linked list.
    /// 
    /// Example 1:
    /// Input: head = [3,2,0,-4], pos = 1
    /// Output: tail connects to node index 1
    /// Explanation: There is a cycle in the linked list, where tail connects to 
    /// the second node.
    ///
    ///
    /// Example 2:
    ///
    /// Input: head = [1,2], pos = 0
    /// Output: tail connects to node index 0
    /// Explanation: There is a cycle in the linked list, where tail connects to 
    /// the first node.
    /// 
    /// Example 3:
    ///
    /// Input: head = [1], pos = -1
    /// Output: no cycle
    /// Explanation: There is no cycle in the linked list.
    ///
    /// Follow-up:
    /// Can you solve it without using extra space?
    /// </summary>
    ListNode* detectCycle(ListNode* head);

    /// <summary>
    /// Leet code #2. Add Two Numbers
    /// You are given two linked lists representing two non - negative numbers.
    /// The digits are stored in reverse order and each of their nodes contain a single digit.
    /// Add the two numbers and return it as a linked list.
    ///  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    ///  Output : 7 -> 0 -> 8
    /// </summary>
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    /// <summary>
    /// Leet code #24. Swap Nodes in Pairs
    /// Given a linked list, swap every two adjacent nodes and return its head. 
    /// For example,
    /// Given 1->2->3->4, you should return the list as 2->1->4->3. 
    /// Your algorithm should use only constant space. You may not modify the values in the 
    /// list, only nodes itself can be changed. 
    /// </summary>
    ListNode* swapPairs(ListNode* head);

    /// <summary>
    /// Leet code #61. Rotate List 
    /// Given a list, rotate the list to the right by k places, where k is non-negative. 
    /// For example:
    /// Given 1->2->3->4->5->NULL and k = 2,
    /// return 4->5->1->2->3->NULL.
    /// </summary>
    ListNode* rotateRight(ListNode* head, int k);

    /// <summary>
    /// Leet code #83. Remove Duplicates from Sorted List 
    /// Given a sorted linked list, delete all duplicates such that each element appear only once. 
    /// For example,
    /// Given 1->1->2, return 1->2.
    /// Given 1->1->2->3->3, return 1->2->3. 
    /// </summary>
    ListNode* deleteDuplicates(ListNode* head);

    /// <summary>
    /// Leet Code 82. Remove Duplicates from Sorted List II
    ///
    /// Medium
    /// 
    /// Given the head of a sorted linked list, delete all nodes that have 
    /// duplicate numbers, leaving only distinct numbers from the original 
    /// list. Return the linked list sorted as well.
    ///
    /// Example 1:
    /// Input: head = [1,2,3,3,4,4,5]
    /// Output: [1,2,5]
    ///
    /// Example 2:
    /// Input: head = [1,1,1,2,3]
    /// Output: [2,3]
    /// 
    /// Constraints:
    /// The number of nodes in the list is in the range [0, 300].
    /// 1. -100 <= Node.val <= 100
    /// 2. The list is guaranteed to be sorted in ascending order.
    /// </summary>
    ListNode* deleteDuplicatesII(ListNode* head);

    /// <summary>
    /// Leet code #86. Partition List
    /// 
    /// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. 
    /// 
    /// You should preserve the original relative order of the nodes in each of the two partitions.
    /// For example,
    /// Given 1->4->3->2->5->2 and x = 3, 
    ///
    /// return 1->2->2->4->3->5. 
    /// </summary>
    ListNode* partitionList(ListNode* head, int x);

    /// <summary>
    /// Leet code #141. Linked List Cycle 
    /// Given a linked list, determine if it has a cycle in it. 
    /// Follow up:
    /// Can you solve it without using extra space? 
    /// </summary>
    bool hasCycle(ListNode* head);

    /// <summary>
    /// Leet Code 206. Reverse Linked List
    ///
    /// Easy
    /// 
    /// Given the head of a singly linked list, reverse the list, and return 
    /// the reversed list.
    /// 
    /// Example 1:
    /// Input: head = [1,2,3,4,5]
    /// Output: [5,4,3,2,1]
    ///
    /// Example 2:
    /// Input: head = [1,2]
    /// Output: [2,1]
    ///
    /// Example 3:
    /// Input: head = []
    /// Output: []
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is the range [0, 5000].
    /// 2. -5000 <= Node.val <= 5000
    ///  
    /// Follow up: A linked list can be reversed either iteratively or 
    /// recursively. Could you implement both?
    /// </summary>
    ListNode* reverseList(ListNode* head);


    /// <summary>
    /// Leet code #92. Reverse Linked List II     
    /// Reverse a linked list from position m to n. Do it in-place and in one-pass.
    /// For example:
    /// Given 1->2->3->4->5->NULL, m = 2 and n = 4, 
    /// return 1->4->3->2->5->NULL. 
    /// Note:
    /// Given m, n satisfy the following condition:
    /// 1 ≤ m ≤ n ≤ length of list.
    /// </summary>
    ListNode* reverseBetween(ListNode* head, int m, int n);

    /// <summary>
    /// Leet code #203. Remove Linked List Elements     
    /// Remove all elements from a linked list of integers that have value val.
    /// Example:
    /// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6 
    /// Return: 1 --> 2 --> 3 --> 4 --> 5  
    /// </summary>
    ListNode* removeElements(ListNode* head, int val);

    /// <summary>
    /// Leet code #237. Delete Node in a Linked List  
    /// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
    /// Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
    /// the linked list should become 1 -> 2 -> 4 after calling your function. 
    /// </summary>
    void deleteNode(ListNode* node);

    /// <summary>
    /// Leet Code 160. Intersection of Two Linked Lists
    ///  
    /// Easy
    ///
    /// Given the heads of two singly linked-lists headA and headB, return the 
    /// node at which the two lists intersect. If the two linked lists have no 
    /// intersection at all, return null.
    ///
    /// For example, the following two linked lists begin to intersect at node c1:
    ///
    /// The test cases are generated such that there are no cycles anywhere in the 
    /// entire linked structure.
    ///
    /// Note that the linked lists must retain their original structure after the 
    /// function returns.
    ///
    /// Custom Judge:
    /// The inputs to the judge are given as follows (your program is not given 
    /// these inputs):
    /// intersectVal - The value of the node where the intersection occurs. This 
    /// is 0 if there is no intersected node.
    /// listA - The first linked list.
    /// listB - The second linked list.
    /// skipA - The number of nodes to skip ahead in listA (starting from the head) 
    /// to get to the intersected node.
    /// skipB - The number of nodes to skip ahead in listB (starting from the head) 
    /// to get to the intersected node.
    /// The judge will then create the linked structure based on these inputs and 
    /// pass the two heads, headA and headB to your program. If you correctly 
    /// return the intersected node, then your solution will be accepted.
    ///
    /// Example 1:
    /// Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], 
    /// skipA = 2, skipB = 3
    /// Output: Intersected at '8'
    /// Explanation: The intersected node's value is 8 (note that this must not 
    /// be 0 if the two lists intersect).
    /// From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads 
    /// as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; 
    /// There are 3 nodes before the intersected node in B.
    /// - Note that the intersected node's value is not 1 because the nodes with 
    ///   value 1 in A and B (2nd node in A and 3rd node in B) are different node 
    ///   references. In other words, they point to two different locations in 
    ///   memory, while the nodes with value 8 in A and B (3rd node in A and 4th 
    ///   node in B) point to the same location in memory.
    ///
    /// Example 2:
    /// Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], 
    /// skipA = 3, skipB = 1
    /// Output: Intersected at '2'
    /// Explanation: The intersected node's value is 2 (note that this must 
    /// not be 0 if the two lists intersect).
    /// From the head of A, it reads as [1,9,1,2,4]. From the head of B, it 
    /// reads as [3,2,4]. There are 3 nodes before the intersected node in A; 
    /// There are 1 node before the intersected node in B.
    ///
    /// Example 3:
    //  Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, 
    /// skipB = 2
    /// Output: No intersection
    /// Explanation: From the head of A, it reads as [2,6,4]. From the head of B, 
    /// it reads as [1,5]. Since the two lists do not intersect, intersectVal 
    /// must be 0, while skipA and skipB can be arbitrary values.
    /// Explanation: The two lists do not intersect, so return null.
    ///
    /// Constraints:
    /// 1. The number of nodes of listA is in the m.
    /// 2. The number of nodes of listB is in the n.
    /// 3. 1 <= m, n <= 3 * 10^4
    /// 4. 1 <= Node.val <= 10^5
    /// 5. 0 <= skipA < m
    /// 6. 0 <= skipB < n
    /// 7. intersectVal is 0 if listA and listB do not intersect.
    /// 8. intersectVal == listA[skipA] == listB[skipB] if listA and listB 
    ///    intersect.
    ///
    /// Follow up: Could you write a solution that runs in O(m + n) time and use 
    /// only O(1) memory?
    /// </summary>
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

    /// <summary>
    /// LeetCode #147. Insertion Sort List   
    /// Sort a linked list using insertion sort. 
    /// </summary>
    ListNode* insertionSortList(ListNode* head);

    /// <summary>
    /// Leet Code 234. Palindrome Linked List
    ///
    /// Easy
    /// 
    /// Given the head of a singly linked list, return true if it is a palindrome
    /// or false otherwise.
    ///
    /// Example 1:
    /// Input: head = [1,2,2,1]
    /// Output: true
    ///
    /// Example 2:
    /// Input: head = [1,2]
    /// Output: false
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 10^5].
    /// 2. 0 <= Node.val <= 9
    /// 
    /// Follow up: Could you do it in O(n) time and O(1) space?
    /// </summary>
    bool isPalindrome(ListNode* head);

    /// <summary>
    /// Leet code #382. Linked List Random Node     
    /// Given a singly linked list, return a random node's value from the linked list. 
    /// Each node must have the same probability of being chosen.
    /// Follow up:
    /// What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space? 
    ///
    /// Example: 
    /// Init a singly linked list [1,2,3].
    /// ListNode head = new ListNode(1);
    /// head.next = new ListNode(2);
    /// head.next.next = new ListNode(3);
    /// Solution solution = new Solution(head);
    /// </summary>
    int getRandom(ListNode* head);

    /// <summary>
    /// Leet code #328. Odd Even Linked List      
    /// Given a singly linked list, group all odd nodes together followed by the even nodes. 
    /// Please note here we are talking about the node number and not the value in the nodes.
    /// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
    /// Example:
    /// Given 1->2->3->4->5->NULL,
    /// return 1->3->5->2->4->NULL. 
    /// Note:
    /// The relative order inside both the even and odd groups should remain as it was in the input. 
    /// The first node is considered odd, the second node even and so on ... 
    /// </summary>
    ListNode* oddEvenList(ListNode* head);

    /// <summary>
    /// Leet code #445. Add Two Numbers II  
    /// You are given two linked lists representing two non-negative numbers. 
    /// The most significant digit comes first and each of their nodes contain 
    /// a single digit. Add the two numbers and return it as a linked list.
    ///
    /// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    /// Follow up:
    /// What if you cannot modify the input lists? In other words, reversing the lists is not allowed. 
    ///
    /// Example: 
    /// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    /// Output: 7 -> 8 -> 0 -> 7
    /// </summary>
    ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2);

    /// <summary>
    /// Leet code #143. Reorder List      
    ///
    /// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
    /// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
    ///
    /// You may not modify the values in the list's nodes, only nodes itself 
    /// may be changed.
    ///
    /// Example 1:
    ///
    /// Given 1->2->3->4, reorder it to 1->4->2->3.
    ///
    /// Example 2:
    ///
    /// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
    /// </summary>
    void reorderList(ListNode* head);

    /// <summary>
    /// Leet code #369. Plus One Linked List      
    /// 
    /// Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
    /// You may assume the integer do not contain any leading zero, except the number 0 itself.
    /// The digits are stored such that the most significant digit is at the head of the list.
    /// Example:
    /// Input:
    /// 1->2->3
    /// Output:
    /// 1->2->4
    /// </summary>
    ListNode* plusOne(ListNode* head);

    /// <summary>
    /// Leet code #725. Split Linked List in Parts      
    /// 
    /// Given a (singly) linked list with head node root, write a function 
    /// to split the linked list into k consecutive linked list "parts".
    ///
    /// The length of each part should be as equal as possible: no two parts 
    /// should have a size differing by more than 1. This may lead to some 
    /// parts being null.
    /// 
    /// The parts should be in order of occurrence in the input list, and 
    /// parts occurring earlier should always have a size greater than or 
    /// equal parts occurring later.
    ///
    /// Return a List of ListNode's representing the linked list parts that 
    /// are formed.
    ///
    /// Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], 
    /// null ]
    /// Example 1:
    /// Input: 
    /// root = [1, 2, 3], k = 5
    /// Output: [[1],[2],[3],[],[]]
    /// Explanation:
    /// The input and each element of the output are ListNodes, not arrays. 
    /// For example, the input root has root.val = 1, root.next.val = 2, 
    /// \root.next.next.val = 3, and root.next.next.next = null.
    /// The first element output[0] has output[0].val = 1, output[0].next = 
    /// null.
    /// The last element output[4] is null, but it's string representation as 
    /// a ListNode is [].
    ///
    /// Example 2:
    /// Input: 
    /// root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
    /// Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
    /// Explanation:
    /// The input has been split into consecutive parts with size difference 
    /// at most 1, and earlier parts are a larger size than the later parts.
    /// Note:
    ///
    /// The length of root will be in the range [0, 1000].
    /// Each value of a node in the input will be an integer in the range 
    /// [0, 999].
    /// k will be an integer in the range [1, 50].
    /// </summary>
    vector<ListNode*> splitListToParts(ListNode* root, int k);

    /// <summary>
    /// Leet code #817. Linked List Components
    /// 
    /// We are given head, the head node of a linked list containing unique 
    /// integer values.
    /// 
    /// We are also given the list G, a subset of the values in the linked 
    /// list.
    ///  
    /// Return the number of connected components in G, where two values are 
    /// connected if they appear consecutively in the linked list.
    ///
    /// Example 1:
    ///
    /// Input: 
    /// head: 0->1->2->3
    /// G = [0, 1, 3]
    /// Output: 2
    /// Explanation: 
    /// 0 and 1 are connected, so [0, 1] and [3] are the two connected 
    /// components.
    /// Example 2:
    ///
    /// Input: 
    /// head: 0->1->2->3->4
    /// G = [0, 3, 1, 4]
    /// Output: 2
    /// Explanation: 
    /// 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] 
    /// are the two connected components.
    /// Note:
    ///
    /// 1. If N is the length of the linked list given by head, 
    ///    1 <= N <= 10000.
    /// 2. The value of each node in the linked list will be in the range 
    ///    [0, N - 1].
    /// 3. 1 <= G.length <= 10000.
    /// 4. G is a subset of all values in the linked list.
    /// </summary>
    int numComponents(ListNode* head, vector<int>& G);

    /// <summary>
    /// Leet code #876. Middle of the Linked List
    /// 
    /// Given a non-empty, singly linked list with head node head, return a 
    /// middle node of linked list.
    /// If there are two middle nodes, return the second middle node.
    ///
    /// Example 1:
    /// Input: [1,2,3,4,5]
    /// Output: Node 3 from this list (Serialization: [3,4,5])
    /// The returned node has value 3.  (The judge's serialization of this 
    /// node is [3,4,5]).
    /// Note that we returned a ListNode object ans, such that:
    /// ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and 
    /// ans.next.next.next = NULL.
    ///
    /// Example 2:
    /// Input: [1,2,3,4,5,6]
    /// Output: Node 4 from this list (Serialization: [4,5,6])
    /// Since the list has two middle nodes with values 3 and 4, we return 
    /// the second one.
    ///
    /// Note:
    /// 1. The number of nodes in the given list will be between 1 and 100.
    /// </summary>
    ListNode* middleNode(ListNode* head);

    /// <summary>
    /// Leet code #708. Insert into a Cyclic Sorted List
    /// 
    /// Given a node from a cyclic linked list which is sorted in ascending order, 
    /// write a function to insert a value into the list such that it remains a 
    /// cyclic sorted list. The given node can be a reference to any single node 
    /// in the list, and may not be necessarily the smallest value in the cyclic 
    /// list.
    ///
    /// If there are multiple suitable places for insertion, you may choose any 
    /// place to insert the new value. After the insertion, the cyclic list should 
    /// remain sorted.
    ///
    /// If the list is empty (i.e., given node is null), you should create a new 
    /// single cyclic list and return the reference to that single node. Otherwise, 
    /// you should return the original given node.
    ///
    /// The following example may help you understand the problem better:
    ///
    /// In the figure above, there is a cyclic sorted list of three elements. You 
    /// are given a reference to the node with value 3, and we need to insert 2 
    /// into the list.
    ///
    /// The new node should insert between node 1 and node 3. After the insertion, 
    /// the list should look like this, and we should still return node 3.
    /// </summary>
    ListNode* insert(ListNode* head, int insertVal);

    /// <summary>
    /// Leet code #1019. Next Greater Node In Linked List
    /// 
    /// We are given a linked list with head as the first node.  Let's number 
    /// the nodes in the list: node_1, node_2, node_3, ... etc.
    ///
    /// Each node may have a next larger value: for node_i, next_larger(node_i) 
    /// is the node_j.val such that j > i, node_j.val > node_i.val, and j is the 
    /// smallest possible choice.  If such a j does not exist, the next larger 
    /// value is 0.
    ///
    /// Return an array of integers answer, where answer[i] = next_larger
    /// (node_{i+1}).
    ///
    /// Note that in the example inputs (not outputs) below, arrays such as 
    /// [2,1,5] represent the serialization of a linked list with a head node 
    /// value of 2, second node value of 1, and third node value of 5.
    ///
    /// Example 1:
    ///
    /// Input: [2,1,5]
    /// Output: [5,5,0]
    ///
    /// Example 2:
    ///
    /// Input: [2,7,4,3,5]
    /// Output: [7,0,5,5,0]
    ///
    /// Example 3:
    ///
    /// Input: [1,7,5,1,9,2,5,1]
    /// Output: [7,9,9,9,0,5,0,0]
    ///
    /// Note:
    ///
    /// 1. 1 <= node.val <= 10^9 for each node in the linked list.
    /// 2. The given list has length in the range [0, 10000].
    /// </summary>
    vector<int> nextLargerNodes(ListNode* head);

    /// <summary>
    /// Leet code #1171. Remove Zero Sum Consecutive Nodes from Linked List
    ///
    /// Given the head of a linked list, we repeatedly delete consecutive 
    /// sequences of nodes that sum to 0 until there are no such sequences.
    /// After doing so, return the head of the final linked list.  You may 
    /// return any such answer.
    /// 
    /// (Note that in the examples below, all sequences are serializations 
    /// of ListNode objects.)
    /// Example 1:
    /// Input: head = [1,2,-3,3,1]
    /// Output: [3,1]
    /// Note: The answer [1,2,1] would also be accepted.
    ///
    /// Example 2:
    /// Input: head = [1,2,3,-3,4]
    /// Output: [1,2,4]
    ///
    /// Example 3:
    /// Input: head = [1,2,3,-3,-2]
    /// Output: [1]
    /// 
    /// Constraints:
    /// 1. The given linked list will contain between 1 and 1000 nodes.
    /// 2. Each node in the linked list has -1000 <= node.val <= 1000.
    /// </summary>
    ListNode* removeZeroSumSublists(ListNode* head);

    /// <summary>
    /// Leet code #1265. Print Immutable Linked List in Reverse
    /// 
    /// You are given an immutable linked list, print out all values of each 
    /// node in reverse with the help of the following interface:
    ///
    /// ImmutableListNode: An interface of immutable linked list, you are 
    /// given the head of the list.
    /// You need to use the following functions to access the linked list 
    /// (you can't access the ImmutableListNode directly):
    /// 
    /// ImmutableListNode.printValue(): Print value of the current node.
    /// ImmutableListNode.getNext(): Return the next node.
    /// The input is only given to initialize the linked list internally. 
    /// You must solve this problem without modifying the linked list. In 
    /// other words, you must operate the linked list using only the 
    /// mentioned APIs.
    ///
    /// Follow up:
    ///
    /// Could you solve this problem in:
    ///
    /// Constant space complexity?
    /// Linear time complexity and less than linear space complexity?
    /// 
    ///
    /// Example 1:
    ///
    /// Input: head = [1,2,3,4]
    /// Output: [4,3,2,1]
    ///
    /// Example 2:
    ///
    /// Input: head = [0,-4,-1,3,-5]
    /// Output: [-5,3,-1,-4,0]
    ///
    /// Example 3:
    ///
    /// Input: head = [-2,0,6,4,4,-6]
    /// Output: [-6,4,4,6,0,-2]
    ///
    /// Constraints:
    /// 
    /// 1. The length of the linked list is between [1, 1000].
    /// 2. The value of each node in the linked list is between [-1000, 1000].
    /// </summary>
    vector<int> printLinkedListInReverse(ListNode* head);

    /// <summary>
    /// Leet code #1290. Convert Binary Number in a Linked List to Integer
    /// 
    /// Given head which is a reference node to a singly-linked list. The 
    /// value of each node in the linked list is either 0 or 1. The linked 
    /// list holds the binary representation of a number.
    ///
    /// Return the decimal value of the number in the linked list.
    ///
    /// Example 1:
    /// Input: head = [1,0,1]
    /// Output: 5
    /// Explanation: (101) in base 2 = (5) in base 10
    ///
    /// Example 2:
    /// Input: head = [0]
    /// Output: 0
    ///
    /// Example 3:
    /// Input: head = [1]
    /// Output: 1
    ///
    /// Example 4:
    /// Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
    /// Output: 18880
    ///
    /// Example 5:
    /// Input: head = [0,0]
    /// Output: 0
    /// 
    /// Constraints:
    /// 1. The Linked List is not empty.
    /// 2. Number of nodes will not exceed 30.
    /// 3. Each node's value is either 0 or 1.
    /// </summary>
    int getDecimalValue(ListNode* head);

    /// <summary>
    /// Leet code #1474. Delete N Nodes After M Nodes of a Linked List
    ///
    /// Easy
    ///
    /// Given the head of a linked list and two integers m and n. Traverse 
    /// the linked list and remove some nodes in the following way:
    ///
    /// Start with the head as the current node.
    /// Keep the first m nodes starting with the current node.
    /// Remove the next n nodes
    /// Keep repeating steps 2 and 3 until you reach the end of the list.
    /// Return the head of the modified list after removing the mentioned 
    /// nodes.
    /// 
    /// Follow up question: How can you solve this problem by modifying the 
    /// list in-place?
    /// 
    /// Example 1:
    /// Input: head = [1,2,3,4,5,6,7,8,9,10,11,12,13], m = 2, n = 3
    /// Output: [1,2,6,7,11,12]
    /// Explanation: Keep the first (m = 2) nodes starting from the head of 
    /// the linked List  (1 ->2) show in black nodes.
    /// Delete the next (n = 3) nodes (3 -> 4 -> 5) show in read nodes.
    /// Continue with the same procedure until reaching the tail of the 
    /// Linked List.
    /// Head of linked list after removing nodes is returned.
    ///
    /// Example 2:
    /// Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 1, n = 3
    /// Output: [1,5,9]
    /// Explanation: Head of linked list after removing nodes is returned.
    ///
    /// Example 3:
    /// Input: head = [1,2,3,4,5,6,7,8,9,10,11], m = 3, n = 1
    /// Output: [1,2,3,5,6,7,9,10,11]
    ///
    /// Example 4:
    /// Input: head = [9,3,7,7,9,10,8,2], m = 1, n = 2
    /// Output: [9,7,8]
    ///
    /// Constraints:
    /// 1. The given linked list will contain between 1 and 10^4 nodes.
    /// 2. The value of each node in the linked list will be in the range 
    ///    [1, 10^6].
    /// 3. 1 <= m,n <= 1000
    /// </summary> 
    ListNode* deleteNodes(ListNode* head, int m, int n);

    /// <summary>
    /// Leet code #1634. Add Two Polynomials Represented as Linked Lists
    /// 
    /// Medium
    ///
    /// A polynomial linked list is a special type of linked list where 
    /// every node represents a term in a polynomial expression.
    ///
    /// Each node has three attributes:
    ///
    /// coefficient: an integer representing the number multiplier of the 
    /// term. The coefficient of the term 9x4 is 9.
    /// power: an integer representing the exponent. The power of the 
    /// term 9x4 is 4.
    /// next: a pointer to the next node in the list, or null if it is the 
    /// last node of the list.
    /// For example, the polynomial 5x3 + 4x - 7 is represented by the 
    /// polynomial linked list illustrated below:
    /// 
    /// The polynomial linked list must be in its standard form: the 
    /// polynomial must be in strictly descending order by its power 
    /// value. Also, terms with a coefficient of 0 are omitted.
    /// 
    /// Given two polynomial linked list heads, poly1 and poly2, add the 
    /// polynomials together and return the head of the sum of the polynomials.
    ///
    /// PolyNode format:
    /// The input/output format is as a list of n nodes, where each node is 
    /// represented as its [coefficient, power]. For example, the polynomial 
    /// 5x^3 + 4x - 7 would be represented as: [[5,3],[4,1],[-7,0]].
    ///
    /// Example 1:
    /// Input: poly1 = [[1,1]], poly2 = [[1,0]]
    /// Output: [[1,1],[1,0]]
    /// Explanation: poly1 = x. poly2 = 1. The sum is x + 1.
    ///
    /// Example 2:
    /// Input: poly1 = [[2,2],[4,1],[3,0]], poly2 = [[3,2],[-4,1],[-1,0]]
    /// Output: [[5,2],[2,0]]
    /// Explanation: poly1 = 2x^2 + 4x + 3. poly2 = 3x^2 - 4x - 1. The sum 
    /// is 5x^2 + 2. Notice that we omit the "0x" term.
    ///
    /// Example 3:
    /// Input: poly1 = [[1,2]], poly2 = [[-1,2]]
    /// Output: []
    /// Explanation: The sum is 0. We return an empty list.
    /// 
    /// Constraints:
    /// 1. 0 <= n <= 104
    /// 2. -10^9 <= PolyNode.coefficient <= 10^9
    /// 3. PolyNode.coefficient != 0
    /// 4. 0 <= PolyNode.power <= 10^9
    /// 5. PolyNode.power > PolyNode.next.power
    /// </summary>
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2);

    /// <summary>
    /// Leet code #1669. Merge In Between Linked Lists
    /// 
    /// Medium
    /// 
    /// You are given two linked lists: list1 and list2 of sizes n and m 
    /// respectively.
    /// Remove list1's nodes from the ath node to the bth node, and put list2 
    /// in their place.
    ///
    /// The blue edges and nodes in the following figure incidate the result:
    /// Build the result list and return its head.
    /// 
    /// Example 1:
    /// Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, 
    /// list2 = [1000000,1000001,1000002]
    /// Output: [0,1,2,1000000,1000001,1000002,5]
    /// Explanation: We remove the nodes 3 and 4 and put the entire list2 in 
    /// their place. The blue edges and nodes in the above figure indicate the 
    /// result.
    ///
    /// Example 2:
    /// Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, 
    /// list2 = [1000000,1000001,1000002,1000003,1000004]
    /// Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
    /// Explanation: The blue edges and nodes in the above figure indicate the 
    /// result.
    ///  
    /// Constraints:
    /// 1. 3 <= list1.length <= 10^4
    /// 2. 1 <= a <= b < list1.length - 1
    /// 3. 1 <= list2.length <= 10^4
    /// </summary>
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2);

    /// <summary>
    /// Leet code 1721. Swapping Nodes in a Linked List
    /// 
    /// Medium
    /// 
    /// You are given the head of a linked list, and an integer k.
    ///
    /// Return the head of the linked list after swapping the values of the 
    /// kth node from the beginning and the kth node from the end (the list 
    /// is 1-indexed).
    ///
    /// Example 1:
    /// Input: head = [1,2,3,4,5], k = 2
    /// Output: [1,4,3,2,5]
    ///
    /// Example 2:
    /// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
    /// Output: [7,9,6,6,8,7,3,0,9,5]
    ///
    /// Example 3:
    /// Input: head = [1], k = 1
    /// Output: [1]
    ///
    /// Example 4:
    /// Input: head = [1,2], k = 1
    /// Output: [2,1]
    ///
    /// Example 5:
    /// Input: head = [1,2,3], k = 2
    /// Output: [1,2,3]
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is n.
    /// 2. 1 <= k <= n <= 105
    /// 3. 0 <= Node.val <= 100
    /// </summary>
    ListNode* swapNodes(ListNode* head, int k);

    /// <summary>
    /// Leet code 1836. Remove Duplicates From an Unsorted Linked List
    /// 
    /// Medium
    /// 
    /// Given the head of a linked list, find all the values that appear more 
    /// than once in the list and delete the nodes that have any of those 
    /// values.
    ///
    /// Return the linked list after the deletions.
    /// 
    /// Example 1:
    /// Input: head = [1,2,3,2]
    /// Output: [1,3]
    /// Explanation: 2 appears twice in the linked list, so all 2's should be 
    /// deleted. After deleting all 2's, we are left with [1,3].
    ///
    /// Example 2:
    /// Input: head = [2,1,1,2]
    /// Output: []
    /// Explanation: 2 and 1 both appear twice. All the elements should be 
    /// deleted.
    ///
    /// Example 3:
    /// Input: head = [3,2,2,1,3,2,4]
    /// Output: [1,4]
    /// Explanation: 3 appears twice and 2 appears three times. After 
    /// deleting all 3's and 2's, we are left with [1,4].
    ///
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 10^5]
    /// 2. 1 <= Node.val <= 10^5
    /// </summary>
    ListNode* deleteDuplicatesUnsorted(ListNode* head);

    /// <summary>
    /// Leet Code 2046. Sort Linked List Already Sorted Using Absolute Values
    ///                                                                 
    /// Medium
    ///
    /// Given the head of a singly linked list that is sorted in 
    /// non-decreasing order using the absolute values of its nodes, return 
    /// the list sorted in non-decreasing order using the actual values of 
    /// its nodes.
    /// 
    /// Example 1:
    /// Input: head = [0,2,-5,5,10,-10]
    /// Output: [-10,-5,0,2,5,10]
    /// Explanation:
    /// The list sorted in non-descending order using the absolute values 
    /// of the nodes is [0,2,-5,5,10,-10].
    /// The list sorted in non-descending order using the actual values 
    /// is [-10,-5,0,2,5,10].
    ///
    /// Example 2:
    /// Input: head = [0,1,2]
    /// Output: [0,1,2]
    /// Explanation:
    /// The linked list is already sorted in non-decreasing order.
    /// Example 3:
    /// Input: head = [1]
    /// Output: [1]
    /// Explanation:
    /// The linked list is already sorted in non-decreasing order.
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is the range [1, 10^5].
    /// 2. -5000 <= Node.val <= 5000
    /// 3. head is sorted in non-decreasing order using the absolute value 
    ///    of its nodes.
    /// 
    /// Follow up:
    /// 1. Can you think of a solution with O(n) time complexity?
    /// </summary>
    ListNode* sortLinkedList(ListNode* head);

    /// <summary>
    /// Leet Code 2074. Reverse Nodes in Even Length Groups
    ///                                                                 
    /// Medium
    ///
    /// You are given the head of a linked list.
    ///
    /// The nodes in the linked list are sequentially assigned to non-empty 
    /// groups whose lengths form the sequence of the natural numbers 
    /// (1, 2, 3, 4, ...). The length of a group is the number of nodes 
    /// assigned to it. In other words,
    ///
    /// The 1st node is assigned to the first group.
    /// The 2nd and the 3rd nodes are assigned to the second group.
    /// The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
    /// Note that the length of the last group may be less than or equal to 
    /// 1 + the length of the second to last group.
    ///
    /// Reverse the nodes in each group with an even length, and return the 
    /// head of the modified linked list.
    ///
    /// Example 1:
    /// Input: head = [5,2,6,3,9,1,7,3,8,4]
    /// Output: [5,6,2,3,9,1,4,8,3,7]
    /// Explanation:
    /// - The length of the first group is 1, which is odd, hence no reversal 
    ///   occurs.
    /// - The length of the second group is 2, which is even, hence the nodes 
    ///   are reversed.
    /// - The length of the third group is 3, which is odd, hence no reversal 
    ///   occurs.
    /// - The length of the last group is 4, which is even, hence the nodes 
    ///   are reversed.
    ///
    /// Example 2:
    /// Input: head = [1,1,0,6]
    /// Output: [1,0,1,6]
    /// Explanation:
    /// - The length of the first group is 1. No reversal occurs.
    /// - The length of the second group is 2. The nodes are reversed.
    /// - The length of the last group is 1. No reversal occurs.
    ///
    /// Example 3:
    /// Input: head = [1,1,0,6,5]
    /// Output: [1,0,1,5,6]
    /// Explanation:
    /// - The length of the first group is 1. No reversal occurs.
    /// - The length of the second group is 2. The nodes are reversed.
    /// - The length of the last group is 2. The nodes are reversed.
    ///
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 10^5].
    /// 2. 0 <= Node.val <= 10^5
    /// </summary>
    ListNode* reverseEvenLengthGroups(ListNode* head);

    /// <summary>
    /// Leet Code 2095. Delete the Middle Node of a Linked List
    ///                                                                 
    /// Medium
    ///
    /// You are given the head of a linked list. Delete the middle node, and 
    /// return the head of the modified linked list.
    ///
    /// The middle node of a linked list of size n is the (n / 2)th node from 
    /// the start using 0-based indexing, where ?x? denotes the largest 
    /// integer less than or equal to x.
    ///
    /// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, 
    /// respectively.
    ///
    /// Example 1:
    /// Input: head = [1,3,4,7,1,2,6]
    /// Output: [1,3,4,1,2,6]
    /// Explanation:
    /// The above figure represents the given linked list. The indices of the 
    /// nodes are written below.
    /// Since n = 7, node 3 with value 7 is the middle node, which is marked 
    /// in red.
    /// We return the new list after removing this node. 
    ///
    /// Example 2:
    /// Input: head = [1,2,3,4]
    /// Output: [1,2,4]
    /// Explanation:
    /// The above figure represents the given linked list.
    /// For n = 4, node 2 with value 3 is the middle node, which is marked 
    /// in red.
    ///
    /// Example 3:
    /// Input: head = [2,1]
    /// Output: [2]
    /// Explanation:
    /// The above figure represents the given linked list.
    /// For n = 2, node 1 with value 1 is the middle node, which is marked 
    /// in red.
    /// Node 0 with value 2 is the only node remaining after removing node 1.
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 10^5].
    /// 2. 1 <= Node.val <= 10^5
    /// </summary>
    ListNode* deleteMiddle(ListNode* head);

    /// <summary>
    /// Leet Code 2058. Find the Minimum and Maximum Number of Nodes Between 
    ///                 Critical Points
    ///                                                                 
    /// Medium
    ///
    /// A critical point in a linked list is defined as either a local maxima 
    /// or a local minima.
    ///
    /// A node is a local maxima if the current node has a value strictly 
    /// greater than the previous node and the next node.
    /// 
    /// A node is a local minima if the current node has a value strictly 
    /// smaller than the previous node and the next node.
    /// Note that a node can only be a local maxima/minima if there exists 
    /// both a previous node and a next node.
    ///
    /// Given a linked list head, return an array of length 2 containing 
    /// [minDistance, maxDistance] where minDistance is the minimum distance 
    /// between any two distinct critical points and maxDistance is the 
    /// maximum distance between any two distinct critical points. If there 
    /// are fewer than two critical points, return [-1, -1].
    ///
    /// Example 1:
    /// Input: head = [3,1]
    /// Output: [-1,-1]
    /// Explanation: There are no critical points in [3,1].
    ///
    /// Example 2:
    /// Input: head = [5,3,1,2,5,1,2]
    /// Output: [1,3]
    /// Explanation: There are three critical points:
    /// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less 
    ///   than 3 and 2.
    /// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is 
    ///   greater than 2 and 1.
    /// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less 
    ///   than 5 and 2.
    /// The minimum distance is between the fifth and the sixth node. 
    /// minDistance = 6 - 5 = 1.
    /// The maximum distance is between the third and the sixth node. 
    /// maxDistance = 6 - 3 = 3.
    ///
    /// Example 3:
    /// Input: head = [1,3,2,2,3,2,2,2,7]
    /// Output: [3,3]
    /// Explanation: There are two critical points:
    /// - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 
    ///   is greater than 1 and 2.
    /// - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is 
    ///   greater than 2 and 2.
    /// Both the minimum and maximum distances are between the second and the 
    /// fifth node.
    /// Thus, minDistance and maxDistance is 5 - 2 = 3.
    /// Note that the last node is not considered a local maxima because it 
    /// does not have a next node.
    ///
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [2, 10^5].
    /// 2. 1 <= Node.val <= 10^5
    /// </summary>
    vector<int> nodesBetweenCriticalPoints(ListNode* head);

    /// <summary>
    /// Leet Code 2130. Maximum Twin Sum of a Linked List
    ///                                                                 
    /// Medium
    ///
    /// In a linked list of size n, where n is even, the ith node (0-indexed) 
    /// of the linked list is known as the twin of the (n-1-i)th node, if 
    /// 0 <= i <= (n / 2) - 1.
    ///
    /// For example, if n = 4, then node 0 is the twin of node 3, and node 1 
    /// is the twin of node 2. These are the only nodes with twins for n = 4.
    /// The twin sum is defined as the sum of a node and its twin.
    ///
    /// Given the head of a linked list with even length, return the maximum 
    /// twin sum of the linked list.
    /// 
    /// Example 1:
    /// Input: head = [5,4,2,1]
    /// Output: 6
    /// Explanation:
    /// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have 
    /// twin sum = 6.
    /// There are no other nodes with twins in the linked list.
    /// Thus, the maximum twin sum of the linked list is 6. 
    ///
    /// Example 2:
    /// Input: head = [4,2,2,3]
    /// Output: 7
    /// Explanation:
    /// The nodes with twins present in this linked list are:
    /// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
    /// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
    /// Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
    ///
    /// Example 3:
    /// Input: head = [1,100000]
    /// Output: 100001
    /// Explanation:
    /// There is only one node with a twin in the linked list having twin 
    /// sum of 1 + 100000 = 100001.
    ///
    /// Constraints:
    /// 1. The number of nodes in the list is an even integer in the 
    ///    range [2, 10^5].
    /// 2. 1 <= Node.val <= 10^5
    /// </summary>
    int pairSum(ListNode* head);

    /// <summary>
    /// Leet Code 2181. Merge Nodes in Between Zeros
    ///                                                                                  
    /// Medium
    ///
    /// You are given the head of a linked list, which contains a series of 
    /// integers separated by 0's. The beginning and end of the linked list 
    /// will have Node.val == 0.
    ///
    /// For every two consecutive 0's, merge all the nodes lying in between 
    /// them into a single node whose value is the sum of all the merged 
    /// nodes. The modified list should not contain any 0's.
    ///
    /// Return the head of the modified linked list.
    ///
    /// Example 1:
    /// Input: head = [0,3,1,0,4,5,2,0]
    /// Output: [4,11]
    /// Explanation: 
    /// The above figure represents the given linked list. The modified list 
    /// contains
    /// - The sum of the nodes marked in green: 3 + 1 = 4.
    /// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.
    ///
    /// Example 2:
    /// Input: head = [0,1,0,3,0,2,2,0]
    /// Output: [1,3,4]
    /// Explanation: 
    /// The above figure represents the given linked list. The modified 
    /// list contains
    /// - The sum of the nodes marked in green: 1 = 1.
    /// - The sum of the nodes marked in red: 3 = 3.
    /// - The sum of the nodes marked in yellow: 2 + 2 = 4.
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [3, 2 * 10^5].
    /// 2. 0 <= Node.val <= 1000
    /// 3. There are no two consecutive nodes with Node.val == 0.
    /// 4. The beginning and end of the linked list have Node.val == 0.
    /// </summary>
    ListNode* mergeNodes(ListNode* head);

    /// <summary>
    /// Leet Code 2487. Remove Nodes From Linked List
    /// 
    /// Medium
    ///	
    /// You are given the head of a linked list.
    ///
    /// Remove every node which has a node with a strictly greater value 
    /// anywhere to the right side of it.
    ///
    /// Return the head of the modified linked list.
    /// 
    /// Example 1:
    /// 
    /// Input: head = [5,2,13,3,8]
    /// Output: [13,8]
    /// Explanation: The nodes that should be removed are 5, 2 and 3.
    /// - Node 13 is to the right of node 5.
    /// - Node 13 is to the right of node 2.
    /// - Node 8 is to the right of node 3.
    ///
    /// Example 2:
    /// Input: head = [1,1,1,1]
    /// Output: [1,1,1,1]
    /// Explanation: Every node has value 1, so no nodes are removed.
    ///
    /// Constraints:
    /// 1. The number of the nodes in the given list is in the range [1, 10^5].
    /// 2. 1 <= Node.val <= 10^5
    /// </summary>
    ListNode* removeNodes(ListNode* head);

    /// <summary>
    /// Leet Code 2674. Split a Circular Linked List
    /// 
    /// Medium
    ///	
    /// Given a circular linked list list of positive integers, your task is 
    /// to split it into 2 circular linked lists so that the first one 
    /// contains the first half of the nodes in list (exactly 
    /// ceil(list.length / 2) nodes) in the same order they appeared in list, 
    /// and the second one contains the rest of the nodes in list in the same 
    /// order they appeared in list.
    ///
    /// Return an array answer of length 2 in which the first element is a 
    /// circular linked list representing the first half and the second 
    /// element is a circular linked list representing the second half.
    //
    /// A circular linked list is a normal linked list with the only 
    /// difference being that the last node's next node, is the first node.
    /// 
    /// Example 1:
     /// Input: nums = [1,5,7]
    /// Output: [[1,5],[7]]
    /// Explanation: The initial list has 3 nodes so the first half would 
    /// be the first 2 elements since ceil(3 / 2) = 2 and the rest which 
    /// is 1 node is in the second half.
    ///
    /// Example 2:
    /// Input: nums = [2,6,1,5]
    /// Output: [[2,6],[1,5]]
    /// Explanation: The initial list has 4 nodes so the first half would 
    /// be the first 2 elements since ceil(4 / 2) = 2 and the rest which 
    /// is 2 nodes are in the second half.
    /// 
    /// Constraints:
    /// 1. The number of nodes in list is in the range [2, 10^5]
    /// 2. 0 <= Node.val <= 10^9
    /// 3. LastNode.next = FirstNode where LastNode is the last node of 
    ///    the list and FirstNode is the first one
    /// </summary>
    vector<ListNode*> splitCircularLinkedList(ListNode* list);

    /// <summary>
    /// Leet Code 2807. Insert Greatest Common Divisors in Linked List
    /// 
    /// Medium
    ///
    /// Given the head of a linked list head, in which each node contains an 
    /// integer value.
    ///
    /// Between every pair of adjacent nodes, insert a new node with a value 
    /// equal to the greatest common divisor of them.
    ///
    /// Return the linked list after insertion.
    ///
    /// The greatest common divisor of two numbers is the largest positive 
    /// integer that evenly divides both numbers.
    /// Example 1:
    /// Input: head = [18,6,10,3]
    /// Output: [18,6,6,2,10,1,3]
    /// Explanation: The 1st diagram denotes the initial linked list and the 
    /// 2nd diagram denotes the linked list after inserting the new nodes 
    /// (nodes in blue are the inserted nodes).
    /// - We insert the greatest common divisor of 18 and 6 = 6 between the 
    ///   1st and the 2nd nodes.
    /// - We insert the greatest common divisor of 6 and 10 = 2 between the 
    ///   2nd and the 3rd nodes.
    /// - We insert the greatest common divisor of 10 and 3 = 1 between 
    ///   the 3rd and the 4th nodes.
    /// There are no more adjacent nodes, so we return the linked list.
    ///
    /// Example 2:
    /// Input: head = [7]
    /// Output: [7]
    /// Explanation: The 1st diagram denotes the initial linked list and the 
    /// 2nd diagram denotes the linked list after inserting the new nodes.
    /// There are no pairs of adjacent nodes, so we return the initial linked 
    /// list.
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 5000].
    /// 2. 1 <= Node.val <= 1000
    /// </summary>
    ListNode* insertGreatestCommonDivisors(ListNode* head);

    /// <summary>
    /// Leet 2816. Double a Number Represented as a Linked List
    /// 
    /// Medium
    ///
    /// You are given the head of a non-empty linked list representing a 
    /// non-negative integer without leading zeroes.
    /// 
    /// Return the head of the linked list after doubling it.
    /// 
    /// Example 1:
    /// Input: head = [1,8,9]
    /// Output: [3,7,8]
    /// Explanation: The figure above corresponds to the given linked list 
    /// which represents the number 189. Hence, the returned linked list 
    /// represents the number 189 * 2 = 378.
    ///
    /// Example 2:
    /// Input: head = [9,9,9]
    /// Output: [1,9,9,8]
    /// Explanation: The figure above corresponds to the given linked list 
    /// which represents the number 999. Hence, the returned linked list 
    /// reprersents the number 999 * 2 = 1998. 
    ///
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 10^4]
    /// 2. 0 <= Node.val <= 9
    /// 3. The input is generated such that the list represents a number that
    ///    does not have leading zeros, except the number 0 itself.
    /// </summary>
    ListNode* doubleIt(ListNode* head);

    /// <summary>
    /// Leet Code 3062. Winner of the Linked List Game
    ///
    /// Easy
    ///
    /// You are given the head of a linked list of even length containing 
    /// integers.
    ///
    /// Each odd-indexed node contains an odd integer and each even-indexed 
    /// node contains an even integer.
    ///
    /// We call each even-indexed node and its next node a pair, e.g., the 
    /// nodes with indices 0 and 1 are a pair, the nodes with indices 2 and 3 
    /// are a pair, and so on.
    ///
    /// For every pair, we compare the values of the nodes in the pair:
    ///
    /// If the odd-indexed node is higher, the "Odd" team gets a point.
    /// If the even-indexed node is higher, the "Even" team gets a point.
    /// Return the name of the team with the higher points, if the points are 
    /// equal, return "Tie".
    ///
    /// Example 1:
    /// Input: head = [2,1]
    /// Output: "Even"
    /// Explanation: There is only one pair in this linked list and that 
    /// is (2,1). Since 2 > 1, the Even team gets the point.
    ///
    /// Hence, the answer would be "Even".
    ///
    /// Example 2:
    /// Input: head = [2,5,4,7,20,5]
    //// Output: "Odd"
    /// Explanation: There are 3 pairs in this linked list. Let's investigate 
    /// each pair individually:
    /// (2,5) -> Since 2 < 5, The Odd team gets the point.
    /// (4,7) -> Since 4 < 7, The Odd team gets the point.
    /// (20,5) -> Since 20 > 5, The Even team gets the point.
    ///
    /// The Odd team earned 2 points while the Even team got 1 point and the 
    /// Odd team has the higher points.
    ///
    /// Hence, the answer would be "Odd".
    /// Example 3:
    /// Input: head = [4,5,2,1]
    /// Output: "Tie"
    /// Explanation: There are 2 pairs in this linked list. Let's investigate 
    /// each pair individually:
    /// (4,5) -> Since 4 < 5, the Odd team gets the point.
    /// (2,1) -> Since 2 > 1, the Even team gets the point.
    /// Both teams earned 1 point.
    /// Hence, the answer would be "Tie".
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [2, 100].
    /// 2. The number of nodes in the list is even.
    /// 3. 1 <= Node.val <= 100
    /// 4. The value of each odd-indexed node is odd.
    /// 5. The value of each even-indexed node is even.
    /// </summary>
    string gameResult(ListNode* head);

    /// <summary>
    /// Leet Code 3063. Linked List Frequency
    ///
    /// Medium
    ///
    /// Given the head of a linked list containing k distinct elements, 
    /// return the head to a linked list of length k containing the 
    /// frequency of each distinct element in the given linked list in 
    /// any order.
    ///
    /// Example 1:
    /// Input: head = [1,1,1,2,2,3]
    /// Output: [3,2,1]
    /// Explanation: There are 3 distinct elements in the list. The frequency 
    /// of 1 is 3, the frequency of 2 is 2 and the frequency of 3 is 1. Hence, 
    /// we return 3 -> 2 -> 1.
    ///
    /// Note that 1 -> 2 -> 3, 1 -> 3 -> 2, 2 -> 1 -> 3, 2 -> 3 -> 1, 
    /// and 3 -> 1 -> 2 are also valid answers.
    ///
    /// Example 2:
    /// Input: head = [1,1,2,2,2]
    /// Output: [2,3]
    /// Explanation: There are 2 distinct elements in the list. The frequency 
    /// of 1 is 2 and the frequency of 2 is 3. Hence, we return 2 -> 3.
    ///
    /// Example 3:
    /// Input: head = [6,5,4,3,2,1]
    /// Output: [1,1,1,1,1,1]
    /// Explanation: There are 6 distinct elements in the list. The frequency 
    /// of each of them is 1. Hence, we return 1 -> 1 -> 1 -> 1 -> 1 -> 1.
    /// 
    /// Constraints:
    /// 1. The number of nodes in the list is in the range [1, 10^5].
    /// 2. 1 <= Node.val <= 105
    /// </summary>
    ListNode* frequenciesOfElements(ListNode* head);

    /// <summary>
    /// Leet Code 3217. Delete Nodes From Linked List Present in Array
    ///
    /// Medium
    ///
    /// You are given an array of integers nums and the head of a linked list. 
    /// Return the head of the modified linked list after removing all nodes 
    /// from the linked list that have a value that exists in nums.
    ///
    /// Example 1:
    /// Input: nums = [1,2,3], head = [1,2,3,4,5]
    /// Output: [4,5]
    ///
    /// Explanation:
    /// Remove the nodes with values 1, 2, and 3.
    /// 
    /// Example 2:
    /// Input: nums = [1], head = [1,2,1,2,1,2]
    /// Output: [2,2,2]
    ///
    /// Explanation:
    /// Remove the nodes with value 1.
    ///
    /// Example 3:
    /// Input: nums = [5], head = [1,2,3,4]
    /// Output: [1,2,3,4]
    ///
    /// Explanation:
    /// No node has value 5.
    ///
    /// Constraints:
    /// 1. 1 <= nums.length <= 10^5
    /// 2. 1 <= nums[i] <= 10^5
    /// 3. All elements in nums are unique.
    /// 4. The number of nodes in the given list is in the range [1, 10^5].
    /// 5. 1 <= Node.val <= 10^5
    /// 6. The input is generated such that there is at least one node in the 
    ///    linked list that has a value not present in nums.
    /// </summary>
    ListNode* modifiedList(vector<int>& nums, ListNode* head);

    /// <summary>
    /// Leet Code 3263. Convert Doubly Linked List to Array I
    /// 
    /// Easy
    ///
    /// You are given the head of a doubly linked list, which contains nodes 
    /// that have a next pointer and a previous pointer.
    ///
    /// Return an integer array which contains the elements of the linked list 
    /// in order.
    /// 
    /// Example 1:
    /// Input: head = [1,2,3,4,3,2,1]
    /// Output: [1,2,3,4,3,2,1]
    ///
    /// Example 2:
    /// Input: head = [2,2,2,2,2]
    /// Output: [2,2,2,2,2]
    /// 
    /// Example 3:
    /// Input: head = [3,2,3,2,3,2]
    /// Output: [3,2,3,2,3,2]
    /// 
    /// Constraints:
    /// 1. The number of nodes in the given list is in the range [1, 50].
    /// 2. 1 <= Node.val <= 50
    /// </summary>
    vector<int> toArrayI(ListNode* head);

    /// <summary>
    /// Leet Code 3294. Convert Doubly Linked List to Array II
    /// 
    /// Medium
    ///
    /// You are given an arbitrary node from a doubly linked list, which 
    /// contains nodes that have a next pointer and a previous pointer.
    ///
    /// Return an integer array which contains the elements of the linked 
    /// list in order.
    /// 
    /// Example 1:
    /// Input: head = [1,2,3,4,5], node = 5
    /// Output: [1,2,3,4,5]
    ///
    /// Example 2:
    /// Input: head = [4,5,6,7,8], node = 8
    /// Output: [4,5,6,7,8]
    /// 
    /// Constraints:
    /// 1. The number of nodes in the given list is in the range [1, 500].
    /// 2. 1 <= Node.val <= 1000
    /// 3. All nodes have unique Node.val.
    /// </summary>
    vector<int> toArrayII(DoublyLinkedNode* node);
#pragma endregion
};
#endif  // LeetCodeLinkedList
