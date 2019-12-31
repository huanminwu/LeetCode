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
    ///
    /// Follow-up:
    /// Can you solve it without using extra space?
    /// </summary>
    ListNode* detectCycle(ListNode* head);

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
