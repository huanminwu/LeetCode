#pragma once
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
    /// Free list nodes
    /// </summary>
    void freeListNodes(ListNode* head);

    /// <summary>
    /// Find a list node with value
    /// </summary>
    ListNode* findListNode(ListNode* head, int value);

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
    /// Leet code #82. Remove Duplicates from Sorted List II 
    /// Given a sorted linked list, delete all nodes that have duplicate numbers, 
    /// leaving only distinct numbers from the original list. 
    /// For example,
    /// Given 1->2->3->3->4->4->5, return 1->2->5.
    /// Given 1->1->1->2->3, return 2->3. 
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
    /// Leet code #206. Reverse Linked List     
    /// Reverse a singly linked list.
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
    /// LeetCode #160. Intersection of Two Linked Lists    
    /// Write a program to find the node at which the intersection of two singly linked lists begins.
    /// For example, the following two linked lists: 
    /// A:          a1 → a2
    ///                    ↘
    ///                      c1 → c2 → c3
    ///                    ↗      
    /// B:     b1 → b2 → b3
    /// begin to intersect at node c1.
    /// Notes: 
    /// If the two linked lists have no intersection at all, return null.
    /// The linked lists must retain their original structure after the function returns. 
    /// You may assume there are no cycles anywhere in the entire linked structure.
    /// Your code should preferably run in O(n) time and use only O(1) memory.
    /// </summary>
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

    /// <summary>
    /// LeetCode #147. Insertion Sort List   
    /// Sort a linked list using insertion sort. 
    /// </summary>
    ListNode* insertionSortList(ListNode* head);

    /// <summary>
    /// Leet code #234. Palindrome Linked List         
    /// Given a singly linked list, determine if it is a palindrome.
    /// Follow up:
    /// Could you do it in O(n) time and O(1) space?
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

#pragma endregion
};
#endif  // LeetCodeLinkedList
