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
#include "LeetCodeLinkedList.h"
#pragma region LinkedList

/// <summary>
/// Free a cyclic linked list nodes
/// </summary>
void LeetCodeLinkedList::freeCyclicListNodes(ListNode* head)
{
    ListNode* node = head;
    while (true)
    {
        ListNode* next = node->next;
        delete node;
        node = next;
        if (node == head) break;
    }
}

/// <summary>
/// Output a cyclic linked list nodes
/// </summary>
vector<int> LeetCodeLinkedList::outputCyclicListNodes(ListNode* head)
{
    vector<int> result;
    ListNode* node = head;
    if (head == nullptr) return result;
    while (true)
    {
        result.push_back(node->val);
        node = node->next;
        if (node == head) break;
    }
    return result;
}

/// <summary>
/// Helper function which generate a cyclic linked list of a integers
/// </summary>
ListNode* LeetCodeLinkedList::generateCyclicListNodes(vector<int> integers)
{
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    for (size_t i = 0; i < integers.size(); i++)
    {
        ListNode* node = new ListNode(integers[i]);
        if (head == nullptr)
        {
            head = node;
            prev = node;
        }
        else
        {
            prev->next = node;
            prev = prev->next;
        }
        node->next = head;
    }
    return head;
}

/// <summary>
/// Add a list of list node at the end
/// </summary>
ListNode* LeetCodeLinkedList::addListNodes(ListNode* head, ListNode* tail)
{
    if (head == nullptr)
    {
        head = tail;
    }
    else
    {
        ListNode* prev = head;
        while (prev->next != nullptr)
        {
            prev = prev->next;
        }
        prev->next = tail;
    }
    return head;
}

/// <summary>
/// Find a list node with value
/// </summary>
ListNode* LeetCodeLinkedList::findListNode(ListNode* head, int value)
{
    ListNode* node = head;
    while (node != nullptr)
    {
        if (node->val == value) return node;
        node = node->next;
    }
    return nullptr;
}

/// <summary>
/// Leet code #2. Add Two Numbers
///
/// You are given two linked lists representing two non - negative numbers.
/// The digits are stored in reverse order and each of their nodes contain a single digit.
/// Add the two numbers and return it as a linked list.
///  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
///  Output : 7 -> 0 -> 8
/// </summary>
ListNode* LeetCodeLinkedList::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* first = l1;
    ListNode* second = l2;
    ListNode* start_result = nullptr;
    ListNode* prev_result = nullptr;
    int first_value, second_value, carry = 0, result_value;
    while ((first != nullptr) || (second != nullptr))
    {
        if (first != nullptr)
        {
            first_value = first->val;
        }
        else
        {
            first_value = 0;
        }
        if (second != nullptr)
        {
            second_value = second->val;
        }
        else
        {
            second_value = 0;
        }
        result_value = first_value + second_value + carry;
        ListNode* result = new ListNode(result_value % 10);
        carry = result_value / 10;
        if (start_result == nullptr)
        {
            start_result = result;
            prev_result = result;
        }
        else
        {
            prev_result->next = result;
            prev_result = prev_result->next;
        }
        if (first != nullptr) first = first->next;
        if (second != nullptr) second = second->next;
    }
    if (carry != 0)
    {
        result_value = carry;
        ListNode* result = new ListNode(result_value % 10);
        carry = result_value / 10;
        if (start_result == nullptr)
        {
            start_result = result;
            prev_result = result;
        }
        else
        {
            prev_result->next = result;
            prev_result = prev_result->next;
        }
    }
    return start_result;
}

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
ListNode* LeetCodeLinkedList::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* fake_head = new ListNode(0);
    fake_head->next = head;
    ListNode* first = fake_head;
    ListNode* last = fake_head;
    for (int i = 0; i < n; i++)
    {
        last = last->next;
    }

    while (last->next != nullptr)
    {
        first = first->next;
        last = last->next;
    }
    ListNode * next = first->next;
    if (next != nullptr) first->next = next->next;
    delete next;
    head = fake_head->next;
    delete fake_head;
    return head;
}

/// <summary>
/// Leet code #24. Swap Nodes in Pairs
/// Given a linked list, swap every two adjacent nodes and return its head. 
/// For example,
///   Given 1->2->3->4, you should return the list as 2->1->4->3. 
/// Your algorithm should use only constant space. You may not modify the values in the 
/// list, only nodes itself can be changed. 
/// </summary>
ListNode* LeetCodeLinkedList::swapPairs(ListNode* head)
{
    ListNode* previous = nullptr;

    ListNode* current = head;

    while (current != nullptr)
    {
        ListNode* next = current->next;
        if (next != nullptr)
        {
            current->next = next->next;
            next->next = current;
            if (previous == nullptr)
            {
                head = next;
            }
            else
            {
                previous->next = next;
            }
            previous = current;
            current = current->next;
        }
        else
        {
            break;
        }
    }
    return head;
}

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
ListNode* LeetCodeLinkedList::mergeKLists(vector<ListNode*>& lists)
{
    ListNode * head = nullptr;
    ListNode* curr = nullptr;
    priority_queue<pair<int, ListNode*>> heap;
    for (size_t i = 0; i < lists.size(); i++)
    {
        ListNode* node = lists[i];
        if (node != nullptr)
        {
            heap.push(make_pair(-node->val, node));
        }
    }
    while (!heap.empty())
    {
        pair<int, ListNode*> first = heap.top();
        heap.pop();
        if (first.second != nullptr && first.second->next != nullptr)
        {
            heap.push(make_pair(-first.second->next->val, first.second->next));
        }
        if (head == nullptr)
        {
            head = first.second;
            curr = head;
        }
        else
        {
            curr->next = first.second;
            curr = curr->next;
        }
        if (curr != nullptr) curr->next = nullptr;
    }
    return head;
}


/// <summary>
/// Leet code #61. Rotate List 
/// Given a list, rotate the list to the right by k places, where k is non-negative. 
/// For example:
/// Given 1->2->3->4->5->NULL and k = 2,
/// return 4->5->1->2->3->NULL.
/// </summary>
ListNode* LeetCodeLinkedList::rotateRight(ListNode* head, int k)
{
    if (head == nullptr) return head;
    ListNode* leading = head;
    ListNode* previous = head;

    // This section is to prepare for when k is much bigger than linked list size;
    size_t size = 0;
    while (leading != nullptr)
    {
        leading = leading->next;
        size++;
    }
    k = k % size;

    for (int i = 0; i < k + 1; i++)
    {
        if (leading == nullptr)
        {
            leading = head;
        }
        previous = leading;
        leading = leading->next;
    }
    ListNode* current = head;
    while (leading != nullptr)
    {
        previous = leading;
        leading = leading->next;
        current = current->next;
    }
    previous->next = head;
    head = current->next;
    current->next = nullptr;
    return head;
}

/// <summary>
/// Leet code #83. Remove Duplicates from Sorted List 
/// Given a sorted linked list, delete all duplicates such that each element appear only once. 
/// For example,
/// Given 1->1->2, return 1->2.
/// Given 1->1->2->3->3, return 1->2->3. 
/// </summary>
ListNode* LeetCodeLinkedList::deleteDuplicates(ListNode* head)
{
    ListNode* previous = nullptr;
    ListNode* current = head;
    while (current != nullptr)
    {
        if ((previous != nullptr) && (previous->val == current->val))
        {
            previous->next = current->next;
            delete current;
        }
        else
        {
            previous = current;
        }
        current = previous->next;
    }
    return head;
}

/// <summary>
/// Leet code #82. Remove Duplicates from Sorted List II 
/// Given a sorted linked list, delete all nodes that have duplicate numbers, 
/// leaving only distinct numbers from the original list. 
/// For example,
/// Given 1->2->3->3->4->4->5, return 1->2->5.
/// Given 1->1->1->2->3, return 2->3. 
/// </summary>
ListNode* LeetCodeLinkedList::deleteDuplicatesII(ListNode* head)
{
    ListNode* previous = nullptr;
    ListNode* current = head;
    ListNode * next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        if ((next != nullptr) && (current->val == next->val))
        {
            while ((next != nullptr) && (current->val == next->val))
            {
                delete current;
                current = next;
                next = next->next;
            }
            delete current;
            if (previous == nullptr)
            {
                head = next;
            }
            else
            {
                previous->next = next;
            }
        }
        else
        {
            previous = current;
        }
        current = next;
    }
    return head;
}
/// <summary>
/// Leet code #86. Partition List
/// 
/// Given a linked list and a value x, partition it such that all nodes less than 
/// x come before nodes greater than or equal to x. 
/// 
/// You should preserve the original relative order of the nodes in each of the two partitions.
/// For example,
/// Given 1->4->3->2->5->2 and x = 3, 
///
/// return 1->2->2->4->3->5. 
/// </summary>
ListNode* LeetCodeLinkedList::partitionList(ListNode* head, int x)
{
    ListNode* pre_first = nullptr;
    ListNode* first = head;

    // find the first item which value which is greater or equal to x
    while ((first != nullptr) && (first->val < x))
    {
        pre_first = first;
        first = first->next;
    }

    // no value greater or equal to x, so game over
    if (first == nullptr) return head;

    ListNode* second = first->next;
    ListNode* pre_second = first;
    while (second != nullptr)
    {
        if (second->val >= x)
        {
            pre_second = second;
        }
        else
        {
            if (pre_first == nullptr)
            {
                head = second;
            }
            else
            {
                pre_first->next = second;
            }
            pre_second->next = second->next;
            second->next = first;
            pre_first = second;
        }
        second = pre_second->next;
    }
    return head;
}

/// <summary>
/// Leet code #141. Linked List Cycle 
/// Given a linked list, determine if it has a cycle in it. 
/// Follow up:
/// Can you solve it without using extra space? 
/// </summary>
bool LeetCodeLinkedList::hasCycle(ListNode *head)
{
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            if (slow == fast)
            {
                break;
            }
        }
    }
    if (fast != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/// <summary>
/// Leet code #206. Reverse Linked List     
/// Reverse a singly linked list.
/// </summary>
ListNode* LeetCodeLinkedList::reverseList(ListNode* head)
{
    ListNode *first = head, *last = head;
    while (last != nullptr)
    {
        ListNode *next = last->next;
        // no more next element, complete
        if (next == nullptr) break;
        last->next = next->next;
        next->next = first;
        first = next;
    }
    return first;
}

/// <summary>
/// Leet code #92. Reverse Linked List II     
/// Reverse a linked list from position m to n. Do it in-place and in one-pass.
/// For example:
/// Given 1->2->3->4->5->NULL, m = 2 and n = 4, 
/// return 1->4->3->2->5->NULL. 
/// Note:
/// Given m, n satisfy the following condition:
/// 1 ¡Ü m ¡Ü n ¡Ü length of list.
/// </summary>
ListNode* LeetCodeLinkedList::reverseBetween(ListNode* head, int m, int n)
{
    ListNode * prev = nullptr;
    ListNode * cur = head;
    m--; n--;
    while (m > 0)
    {
        if (cur == nullptr) break;
        prev = cur;
        cur = cur->next;
        m--;
        n--;
    }
    while (n > 0)
    {
        if (cur == nullptr) break;
        ListNode * next = cur->next;
        if (next == nullptr) break;
        cur->next = next->next;
        if (prev == nullptr)
        {
            next->next = head;
            head = next;
        }
        else
        {
            next->next = prev->next;
            prev->next = next;
        }
        n--;
    }
    return head;
}

/// <summary>
/// Leet code #203. Remove Linked List Elements     
/// Remove all elements from a linked list of integers that have value val.
/// Example:
/// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6 
/// Return: 1 --> 2 --> 3 --> 4 --> 5  
/// </summary>
ListNode* LeetCodeLinkedList::removeElements(ListNode* head, int val)
{
    ListNode * prev = nullptr;
    ListNode * cur = head;
    while (cur != nullptr)
    {
        ListNode * next = cur->next;
        if (cur->val == val)
        if (cur->val == val)
        {
            delete cur;
            if (prev == nullptr)
            {
                head = next;;
            }
            else
            {
                prev->next = next;
            }
        }
        else
        {
            prev = cur;
        }
        cur = next;
    }
    return head;
}

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
RandomListNode * LeetCodeLinkedList::copyRandomList(RandomListNode *head)
{
    RandomListNode *node = head;
    // clone the next link
    while (node != nullptr)
    {
        RandomListNode* new_node = new RandomListNode(node->label);
        new_node->next = node->next;
        node->next = new_node;
        node = new_node->next;
    }

    // clone the random link
    node = head;
    while (node != nullptr)
    {
        RandomListNode* new_node = node->next;
        if (node->random != nullptr)
        {
            new_node->random = node->random->next;
        }
        node = new_node->next;
    }

    // separate two link list
    node = head;
    RandomListNode *new_head = nullptr;
    if (head != nullptr)
    {
        new_head = head->next;
    }
    while (node != nullptr)
    {
        RandomListNode* new_node = node->next;
        node->next = new_node->next;
        node = node->next;
        if (node != nullptr)
        {
            new_node->next = node->next;
        }
    }
    return new_head;
}

/// <summary>
/// Leet code #237. Delete Node in a Linked List  
/// Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
/// Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
/// the linked list should become 1 -> 2 -> 4 after calling your function. 
/// </summary>
void LeetCodeLinkedList::deleteNode(ListNode* node)
{
    if ((node != nullptr) && (node->next != nullptr))
    {
        ListNode * next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
}

/// <summary>
/// LeetCode #160. Intersection of Two Linked Lists    
/// Write a program to find the node at which the intersection of two singly linked lists begins.
/// For example, the following two linked lists: 
/// A:          a1 ¡ú a2
///                    ¨K
///                      c1 ¡ú c2 ¡ú c3
///                    ¨J      
/// B:     b1 ¡ú b2 ¡ú b3
/// begin to intersect at node c1.
/// Notes: 
/// If the two linked lists have no intersection at all, return null.
/// The linked lists must retain their original structure after the function returns. 
/// You may assume there are no cycles anywhere in the entire linked structure.
/// Your code should preferably run in O(n) time and use only O(1) memory.
/// </summary>
ListNode * LeetCodeLinkedList::getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if ((headA == nullptr) || (headB == nullptr))
    {
        return nullptr;
    }
    ListNode * pointerA = headA;
    ListNode * pointerB = headB;
    bool hit_null = false;
    while (pointerA != pointerB)
    {
        pointerA = pointerA->next;
        pointerB = pointerB->next;
        if (pointerA == nullptr)
        {
            if (hit_null) return nullptr;
            pointerA = headB;
            hit_null = true;
        }
        if (pointerB == nullptr)
        {
            pointerB = headA;
        }
    }
    return pointerA;
}

/// <summary>
/// LeetCode #147. Insertion Sort List   
/// Sort a linked list using insertion sort. 
/// </summary>
ListNode* LeetCodeLinkedList::insertionSortList(ListNode* head)
{
    ListNode* unordered_head = head;
    head = nullptr;
    while (unordered_head != nullptr)
    {
        ListNode* prev = nullptr;
        ListNode * current = head;
        while (current != nullptr)
        {
            if (current->val < unordered_head->val)
            {
                prev = current;
                current = current->next;
            }
            else
            {
                break;
            }
        }
        ListNode * next = unordered_head->next;
        if (prev == nullptr)
        {
            unordered_head->next = head;
            head = unordered_head;
        }
        else
        {
            prev->next = unordered_head;
            unordered_head->next = current;
        }
        unordered_head = next;
    }
    return head;
}


/// <summary>
/// Leet code #234. Palindrome Linked List         
/// Given a singly linked list, determine if it is a palindrome.
/// Follow up:
/// Could you do it in O(n) time and O(1) space?
/// </summary>
bool LeetCodeLinkedList::isPalindrome(ListNode* head)
{
    if (head == nullptr) return true;
    ListNode *slow = head;
    ListNode *fast = head;
    // check middle point of listnode
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr) fast = fast->next;
        if (fast == nullptr) break;
        slow = slow->next;
    }
    fast = slow->next;
    // reverse check middle point of listnode
    while (fast != nullptr && fast->next != nullptr)
    {
        ListNode * next = fast->next;
        fast->next = fast->next->next;
        next->next = slow->next;
        slow->next = next;
    }
    fast = slow->next;
    slow = head;
    while (slow != nullptr && fast != nullptr)
    {
        if (slow->val != fast->val)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

/// <summary>
/// Leet code #382. Linked List Random Node
///
/// Given a singly linked list, return a random node's value from the linked 
/// list. 
/// Each node must have the same probability of being chosen.
/// Follow up:
/// What if the linked list is extremely large and its length is unknown to 
/// you? Could you solve this efficiently without using extra space? 
///
/// Example: 
/// Init a singly linked list [1,2,3].
/// ListNode head = new ListNode(1);
/// head.next = new ListNode(2);
/// head.next.next = new ListNode(3);
/// Solution solution = new Solution(head);
/// </summary>
int LeetCodeLinkedList::getRandom(ListNode *head)
{
    int count = 0;
    int value = 0;
    while (head != nullptr)
    {
        count++;
        if (count == 1)
        {
            value = head->val;
        }
        else
        {
            if (rand() % count == 0)
            {
                value = head->val;
            }
        }
        head = head->next;
    }
    return value;
}

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
ListNode* LeetCodeLinkedList::oddEvenList(ListNode* head)
{
    ListNode* odd_head = nullptr, *odd_prev = nullptr;
    ListNode* even_head = nullptr, *even_prev = nullptr;
    int count = 0;
    while (head != nullptr)
    {
        ListNode* next = head->next;
        head->next = nullptr;
        count++;
        if (count % 2 == 1)
        {
            if (odd_head == nullptr)
            {
                odd_head = head;
            }
            else
            {
                odd_prev->next = head;
            }
            odd_prev = head;
        }
        else
        {
            if (even_head == nullptr)
            {
                even_head = head;
            }
            else
            {
                even_prev->next = head;
            }
            even_prev = head;
        }
        head = next;
    }
    if (odd_prev != nullptr) odd_prev->next = even_head;
    return odd_head;
}

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
ListNode* LeetCodeLinkedList::addTwoNumbersII(ListNode* l1, ListNode* l2)
{
    ListNode * result = nullptr;
    int value = 0;
    vector<int> d1;
    vector<int> d2;
    while (l1 != nullptr)
    {
        d1.push_back(l1->val);
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        d2.push_back(l2->val);
        l2 = l2->next;
    }
    while ((!d1.empty()) || (!d2.empty()) || (value != 0))
    {
        if (!d1.empty())
        {
            value += d1.back();
            d1.pop_back();
        }
        if (!d2.empty())
        {
            value += d2.back();
            d2.pop_back();
        }
        ListNode * node = new ListNode(value % 10);
        node->next = result;
        result = node;
        value = value / 10;
    }
    return result;
}

/// <summary>
/// Leet code #143. Reorder List      
///
/// Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
/// reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
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
void LeetCodeLinkedList::reorderList(ListNode* head)
{
    if ((head == nullptr) || head->next == nullptr) return;
    ListNode* fake_head = new ListNode(0);
    fake_head->next = head;
    ListNode* slow = fake_head;
    ListNode *fast = fake_head;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        if (fast->next != nullptr) fast = fast->next;        
        slow = slow->next;
    }

    // reverse second half
    fast = slow->next;
    while (fast->next != nullptr)
    {
        ListNode * next = fast->next;
        fast->next = next->next;
        next->next = slow->next;
        slow->next = next;
    }

    // merge the second half
    fast = slow;
    slow = head;
    while (slow != fast)
    {
        ListNode * next = fast->next;
        fast->next = next->next;
        next->next = slow->next;
        slow->next = next;
        slow = next->next;
    }
    delete fake_head;
}

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
ListNode* LeetCodeLinkedList::plusOne(ListNode* head)
{
    head = reverseList(head);
    ListNode * node = head;
    int number = 1;
    ListNode * prev = head;
    while (node != nullptr)
    {
        node->val += number;
        number = node->val / 10;
        node->val %= 10;
        if (number == 0) break;
        prev = node;
        node = node->next;
    }
    if (number != 0)
    {
        node = new ListNode(1);
        if (prev == nullptr)
        {
            head = node;
        }
        else
        {
            prev->next = node;
        }
    }

    head = reverseList(head);
    return head;
}

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
vector<ListNode*> LeetCodeLinkedList::splitListToParts(ListNode* root, int k)
{
    vector<ListNode *> result(k, nullptr);
    size_t size = 0;
    ListNode* head = root;
    while (head != nullptr)
    {
        head = head->next;
        size++;
    }
    int dividend = size / k;
    int reminder = size % k;

    head = root;
    for (size_t i = 0; i < (size_t)k; i++)
    {
        ListNode * ptr = result[i];
        size = dividend;
        if (reminder > 0)
        {
            size++;
            reminder--;
        }
        for (size_t j = 0; j < size; j++)
        {
            if (j == 0)
            {
                result[i] = head;
                ptr = head;
            }
            else
            {
                ptr->next = head;
                ptr = ptr->next;
            }
            if (head == nullptr) break;
            head = head->next;
        }
        if (ptr != nullptr) ptr->next = nullptr;
    }
    return result;
}

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
int LeetCodeLinkedList::numComponents(ListNode* head, vector<int>& G)
{
    int result = 0;
    bool in_subset = false;
    unordered_set<int> sub_set;
    for (int g : G) sub_set.insert(g);

    ListNode* ptr = head;
    while (ptr != nullptr)
    {
        if (sub_set.count(ptr->val) > 0)
        {
            if (in_subset == false) result++;
            in_subset = true;
        }
        else
        {
            in_subset = false;
        }
        ptr = ptr->next;
    }

    return result;
}

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
ListNode* LeetCodeLinkedList::middleNode(ListNode* head)
{
    ListNode * fast = head;
    ListNode * result = head;
    if (result == nullptr) return result;
    while (fast->next != nullptr)
    {
        result = result->next;
        fast = fast->next;
        if (fast->next != nullptr) fast = fast->next;
    }
    return result;
}

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
ListNode* LeetCodeLinkedList::insert(ListNode* head, int insertVal)
{
    ListNode * node = head;
    if (node == nullptr)
    {
        head = new ListNode(insertVal);
        head->next = head;
        return head;
    }
    else
    {
        while (true)
        {
            if ((node->val <= insertVal && node->next->val >= insertVal) ||
                (node->val >= node->next->val && (insertVal <= node->next->val || insertVal >= node->val)))
            {
                ListNode * new_node = new ListNode(insertVal);
                new_node->next = node->next;
                node->next = new_node;
                return head;
            }
            node = node->next;
        }
    }
}

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
DoublyLinkedNode* LeetCodeLinkedList::flatten(DoublyLinkedNode * head)
{
    stack<DoublyLinkedNode *> search;
    search.push(head);
    DoublyLinkedNode * prev = nullptr;
    while (!search.empty())
    {
        DoublyLinkedNode * node = search.top();
        search.pop();
        if (node == nullptr) continue;

        if (prev != nullptr)
        {
            prev->next = node;
        }
        search.push(node->next);
        search.push(node->child);
        node->prev = prev;
        node->next = nullptr;
        node->child = nullptr;
        prev = node;
    }
    return head;
}

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
ListNode* LeetCodeLinkedList::removeZeroSumSublists(ListNode* head)
{
    unordered_map<int, ListNode*> node_sum;
    int sum = 0;
    ListNode* node = new ListNode(0);
    node->next = head;
    node_sum[sum] = node;
    swap(head, node);
    while (node != nullptr)
    {
        sum += node->val;
        if (node_sum.count(sum) > 0)
        {
            ListNode* prev = node_sum[sum];
            int prev_sum = sum;
            while (prev->next != node)
            {
                prev = prev->next;
                prev_sum += prev->val;
                node_sum.erase(prev_sum);
            }
            node_sum[sum]->next = node->next;
        }
        else
        {
            node_sum[sum] = node;
        }
        node = node->next;
    }
    node = head;
    head = node->next;
    delete node;
    return head;
}

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
/// 
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
///
/// Note:
///
/// 1. 1 <= node.val <= 10^9 for each node in the linked list.
/// 2. The given list has length in the range [0, 10000].
/// </summary>
vector<int> LeetCodeLinkedList::nextLargerNodes(ListNode* head)
{
    vector<int>result;
    stack<pair<int, int>> search;
    int index = 0;
    while (head != nullptr)
    {
        while (!search.empty() && search.top().first < head->val)
        {
            result[search.top().second] = head->val;
            search.pop();
        }
        search.push(make_pair(head->val, index));
        result.push_back(0);
        head = head->next;
        index++;
    }
    return result;
}

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
ListNode* LeetCodeLinkedList::reverseKGroup(ListNode* head, int k)
{
    ListNode* fake_head = new ListNode(0);
    fake_head->next = head;
    ListNode* prev = fake_head;
    ListNode* last = head;
    while (last != nullptr && last->next != nullptr)
    {
        // test if we have k nodes
        ListNode* next = prev;
        for (int i = 0; i < k; i++)
        {
            if (next == nullptr) break;
            next = next->next;
        }
        if (next == nullptr) break;

        for (int i = 0; i < k - 1; i++)
        {
            // watch the order of operation.
            next = last->next;
            last->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        prev = last;
        last = last->next;
    }
    head = fake_head->next;
    delete fake_head;
    return head;
}

/// <summary>
/// Helper function which generate a list of random list nodes
/// </summary>
RandomListNode* LeetCodeLinkedList::generateRandomListNodes(vector<int> integers)
{
    RandomListNode* head = nullptr;
    RandomListNode* prev = nullptr;
    for (size_t i = 0; i < integers.size(); i++)
    {
        RandomListNode* node = new RandomListNode(integers[i]);
        if (head == nullptr)
        {
            head = node;
            prev = node;
        }
        else
        {
            if (prev != nullptr) prev->next = node;
            prev = node;
        }
    }
    srand((unsigned int)time(0));
    for (size_t i = 0; i < integers.size(); i++)
    {
        RandomListNode* node = head;
        for (size_t j = 0; j < i; j++)
        {
            if (node != nullptr) node = node->next;
        }
        RandomListNode* random = head;
        size_t index = rand() % integers.size();
        for (size_t j = 0; j < index; j++)
        {
            if (random != nullptr) random = random->next;
        }
        if (node != nullptr) node->random = random;
    }
    return head;
}

/// <summary>
/// Free random list nodes
/// </summary>
void LeetCodeLinkedList::freeRandomListNodes(RandomListNode* head)
{
    while (head != nullptr)
    {
        RandomListNode* node = head;
        head = head->next;
        delete node;
    }
}

/// <summary>
/// Helper function which generate a linked list of a integers
/// </summary>
ListNode* LeetCodeLinkedList::generateListNodes(vector<int> integers)
{
    ListNode* start = nullptr;
    ListNode* prev = nullptr;
    for (size_t i = 0; i < integers.size(); i++)
    {
        ListNode* result = new ListNode(integers[i]);
        if (start == nullptr)
        {
            start = result;
            prev = result;
        }
        else
        {
            prev->next = result;
            prev = prev->next;
        }
    }
    return start;
}

/// <summary>
/// Free list nodes
/// </summary>
void LeetCodeLinkedList::freeListNodes(ListNode* head)
{
    while (head != nullptr)
    {
        ListNode* node = head;
        head = head->next;
        delete node;
    }
}

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
ListNode* LeetCodeLinkedList::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* fake_head = new ListNode(0);
    ListNode* head = nullptr;
    ListNode* prev = fake_head;
    while ((l1 != nullptr) || (l2 != nullptr))
    {
        if (l1 == nullptr)
        {
            prev->next = l2;
            l2 = nullptr;
        }
        else if (l2 == nullptr)
        {
            prev->next = l1;
            l1 = nullptr;
        }
        else if (l1->val < l2->val)
        {
            prev->next = l1;
            l1 = l1->next;
        }
        else
        {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    head = fake_head->next;
    delete fake_head;
    return head;
}

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
ListNode* LeetCodeLinkedList::sortList(ListNode* head)
{
    if ((head == nullptr) || (head->next == nullptr)) return head;
    ListNode* slow = head, * fast = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr) fast = fast->next;
        if (fast == nullptr) break;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = nullptr;
    slow = sortList(head);
    fast = sortList(fast);
    return mergeTwoLists(slow, fast);
}

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
/// Follow-up:
/// Can you solve it without using extra space?
/// </summary>
ListNode* LeetCodeLinkedList::detectCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            if (slow == fast)
            {
                break;
            }
        }
    }
    if (fast == nullptr)
    {
        return nullptr;
    }
    else
    {
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}

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
vector<int> LeetCodeLinkedList::printLinkedListInReverse(ListNode* head)
{
    vector<ListNode*> head_list;

    size_t size = 0;
    ListNode* node = head;
    while (node != nullptr)
    {
        size++;
        node = node->next;
    }
    size_t buff_size = (int)std::sqrt(size);

    node = head;
    for (size_t i = 0; i < size; i++)
    {
        if (i % buff_size == 0) head_list.push_back(node);
        node = node->next;
        if (node == nullptr) break;
    }

    vector<int> result;
    while (!head_list.empty())
    {
        stack<ListNode*> node_stack;
        ListNode* head = head_list.back();
        head_list.pop_back();
        ListNode *node = head;
        for (size_t i = 0; i < buff_size; i++)
        {
            if (node == nullptr) break;
            node_stack.push(node);
            node = node->next;
        }
        while (!node_stack.empty())
        {
            result.push_back(node_stack.top()->val);
            node_stack.pop();
        }
    }
    return result;
}

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
int LeetCodeLinkedList::getDecimalValue(ListNode* head)
{
    int result = 0;
    ListNode* node = head;
    while (node != nullptr)
    {
        result = result * 2 + node->val;
        node = node->next;
    }
    return result;
}


/// <summary>
/// Leet code #427. Construct Quad Tree
/// </summary>
bool LeetCodeLinkedList::isQuadTreeLeaf(vector<vector<int>>& grid, int up, int left, int down, int right)
{
    int value = grid[up][left];
    for (int i = up; i <= down; i++)
    {
        for (int j = left; j <= right; j++)
        {
            if (grid[i][j] != value) return false;
        }
    }
    return true;
}


/// <summary>
/// Leet code #427. Construct Quad Tree
/// </summary>
QuadNode* LeetCodeLinkedList::constructQuadTree(vector<vector<int>>& grid, int up, int left, int down, int right)
{
    QuadNode* result = nullptr;
    if (isQuadTreeLeaf(grid, up, left, down, right))
    {
        result = new QuadNode(grid[up][left] == 1, true, nullptr, nullptr, nullptr, nullptr);
    }
    else
    {
        result = new QuadNode(true, false, nullptr, nullptr, nullptr, nullptr);
        result->topLeft = constructQuadTree(grid, up, left, (up + down) / 2, (left + right) / 2);
        result->topRight = constructQuadTree(grid, up, (left + right) / 2 + 1, (up + down) / 2, right);
        result->bottomLeft = constructQuadTree(grid, (up + down) / 2 + 1, left, down, (left + right) / 2);
        result->bottomRight = constructQuadTree(grid, (up + down) / 2 + 1, (left + right) / 2 + 1, down, right);
    }
    return result;
}

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
QuadNode* LeetCodeLinkedList::constructQuadTree(vector<vector<int>>& grid)
{
    QuadNode* result = nullptr;
    if (grid.empty() || grid[0].empty()) return result;

    return constructQuadTree(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
}

/// <summary>
/// Leet code #558. Quad Tree Intersection
/// </summary>
QuadNode* LeetCodeLinkedList::collapse(QuadNode* quadTree)
{
    if (quadTree == nullptr) return quadTree;
    if (quadTree->topLeft == nullptr || quadTree->topRight == nullptr ||
        quadTree->bottomLeft == nullptr || quadTree->bottomRight == nullptr)
    {
        return quadTree;
    }
    else if ((!quadTree->topLeft->isLeaf) || (!quadTree->topRight->isLeaf) ||
        (!quadTree->bottomLeft->isLeaf) || (!quadTree->bottomRight->isLeaf))
    {
        return quadTree;
    }
    else if ((quadTree->topLeft->val != quadTree->topRight->val) || (quadTree->topLeft->val != quadTree->bottomLeft->val) ||
        (quadTree->topLeft->val != quadTree->bottomRight->val))
    {
        return quadTree;
    }
    else
    {
        quadTree->isLeaf = true;
        quadTree->val = quadTree->topLeft->val;
        delete quadTree->topLeft;
        delete quadTree->topRight;
        delete quadTree->bottomLeft;
        delete quadTree->bottomRight;
        quadTree->topLeft = nullptr;
        quadTree->topRight = nullptr;
        quadTree->bottomLeft = nullptr;
        quadTree->bottomRight = nullptr;
        return quadTree;
    }
}

/// <summary>
/// Leet code #558. Quad Tree Intersection
/// </summary>
QuadNode* LeetCodeLinkedList::clone(QuadNode* quadTree)
{
    QuadNode* result = nullptr;
    if (quadTree == nullptr) return result;
    result = new QuadNode(quadTree->val, quadTree->isLeaf, quadTree->topLeft, quadTree->topRight,
        quadTree->bottomLeft, quadTree->bottomRight);
    quadTree->topLeft = clone(quadTree->topLeft);
    quadTree->topRight = clone(quadTree->topRight);
    quadTree->bottomLeft = clone(quadTree->bottomLeft);
    quadTree->bottomRight = clone(quadTree->bottomRight);
    return result;
}

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
QuadNode* LeetCodeLinkedList::intersect(QuadNode* quadTree1, QuadNode* quadTree2)
{
    QuadNode* result = nullptr;
    if ((quadTree1 == nullptr) && (quadTree2 == nullptr)) return result;
    if (quadTree1 == nullptr)
    {
        result = clone(quadTree2);
    }
    else if (quadTree2 == nullptr)
    {
        result = clone(quadTree1);
    }
    else if (quadTree1->isLeaf == true)
    {
        if (quadTree1->val == true) result = clone(quadTree1);
        else result = clone(quadTree2);
    }
    else if (quadTree2->isLeaf == true)
    {
        if (quadTree2->val == true) result = clone(quadTree2);
        else result = clone(quadTree1);
    }
    else
    {
        result = new QuadNode(true, false, nullptr, nullptr, nullptr, nullptr);
        result->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        result->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        result->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        result->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        collapse(result);
    }
    return result;
}

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
ListNode* LeetCodeLinkedList::deleteNodes(ListNode* head, int m, int n)
{
    ListNode* pre_head = new ListNode(0);
    pre_head->next = head;
    ListNode* node = pre_head;
    while (node != nullptr)
    {
        for (int i = 0; i < m; i++)
        {
            if (node == nullptr) break;
            node = node->next;
        }
        for (int i = 0; i < n; i++)
        {
            if (node == nullptr || node->next == nullptr) break;
            ListNode* next = node->next;
            node->next = next->next;
            delete next;
        }
    }
    ListNode* result = pre_head->next;
    delete pre_head;
    return result;
}

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
PolyNode* LeetCodeLinkedList::addPoly(PolyNode* poly1, PolyNode* poly2)
{
    PolyNode* prev = new PolyNode();
    PolyNode* result = prev;
    while (poly1 != nullptr || poly2 != nullptr)
    {
        int cofficient = 0;
        int power = 0;
        if ((poly1 == nullptr) || (poly2 != nullptr && poly2->power > poly1->power))
        {
            cofficient = poly2->coefficient;
            power = poly2->power;
            poly2 = poly2->next;
        }
        else if ((poly2 == nullptr) || (poly1 != nullptr && poly1->power > poly2->power))
        {
            cofficient = poly1->coefficient;
            power = poly1->power;
            poly1 = poly1->next;
        }
        else if (poly1->power == poly2->power)
        {
            cofficient = poly1->coefficient + poly2->coefficient;
            power = poly1->power;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        if (cofficient != 0)
        {
            PolyNode* poly = new PolyNode(cofficient, power);
            result->next = poly;
            result = result->next;
        }
    }
    result = prev->next;
    delete prev;
    return result;
}

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
ListNode* LeetCodeLinkedList::mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
    ListNode* prev = new ListNode(0);
    prev->next = list1;
    ListNode* left = prev;
    for (int i = 0; i < a; i++)
    {
        left = left->next;
    }
    ListNode* right = left->next;
    for (int i = a; i <= b; i++)
    {
        ListNode* temp = right;
        if (right != nullptr) right = right->next;
        delete temp;
    }
    left->next = list2;
    while (left->next != nullptr) left = left->next;
    left->next = right;
    left = prev->next;
    delete prev;
    return left;
}

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
ListNode* LeetCodeLinkedList::swapNodes(ListNode* head, int k)
{
    ListNode* first = head;
    for (int i = 0; i < k - 1; i++)
    {
        first = first->next;
    }

    ListNode* end = first;
    ListNode* last = head;
    while (end->next != nullptr)
    {
        end = end->next;
        last = last->next;
    }
    swap(first->val, last->val);
    return head;
}


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
ListNode* LeetCodeLinkedList::deleteDuplicatesUnsorted(ListNode* head)
{
    ListNode* prev = new ListNode(0);
    prev->next = head;
    unordered_map<int, int> node_map;
    ListNode* ptr = head;
    while (ptr != nullptr)
    {
        node_map[ptr->val]++;
        ptr = ptr->next;
    }
    ptr = prev;
    while (ptr->next != nullptr)
    {
        if (node_map[ptr->next->val] > 1)
        {
            ptr->next = ptr->next->next;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    ListNode* result = prev->next;
    delete prev;
    return result;
}

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
ListNode* LeetCodeLinkedList::sortLinkedList(ListNode* head)
{
    ListNode* negative_head = nullptr;
    ListNode* negative_tail = nullptr;

    ListNode* positive_head = nullptr;
    ListNode* positive_tail = nullptr;

    ListNode* node = head;
    while (node != nullptr)
    {
        ListNode* next = node->next;
        node->next = nullptr;
        if (node->val >= 0)
        {
            if (positive_tail == nullptr)
            {
                positive_head = node;
            }
            else
            {
                positive_tail->next = node;
            }
            positive_tail = node;
        }
        else
        {
            if (negative_head == nullptr)
            {
                negative_tail = node;
            }
            node->next = negative_head;
            negative_head = node;
        }
        node = next;
    }
    if (negative_head != nullptr)
    {
        head = negative_head;
        negative_tail->next = positive_head;
    }
    else
    {
        head = positive_head;
    }
    return head;
}

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
ListNode* LeetCodeLinkedList::reverseEvenLengthGroups(ListNode* head)
{
    int group = 1;
    ListNode* prev_tail = head;
    ListNode* tail = head;
    int count = 0;
    while (tail != nullptr)
    {
        count++;
        tail = tail->next;
    }
    tail = head;
    int prev_count = 1;
    while (tail != nullptr && tail->next != nullptr)
    {
        group++;
        prev_tail = tail;
        tail = tail->next;
        int size = min(group, count - prev_count);
        if (size % 2 == 0)
        {
            for (int i = 0; i < size - 1; i++)
            {
                if (tail == nullptr || tail->next == nullptr) break;
                ListNode* next = tail->next;
                tail->next = next->next;
                next->next = prev_tail->next;
                prev_tail->next = next;
            }
        }
        else
        {
            for (int i = 0; i < size - 1; i++)
            {
                if (tail == nullptr || tail->next == nullptr) break;
                tail = tail->next;
            }
        }
        prev_count += size;
    }
    return head;
}

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
ListNode* LeetCodeLinkedList::deleteMiddle(ListNode* head)
{
    ListNode* slow = nullptr;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        if (slow == nullptr)
        {
            slow = head;
        }
        else
        {
            slow = slow->next;
        }
        fast = fast->next;
        fast = fast->next;
    }
    if (slow == nullptr) return nullptr;
    else
    {
        slow->next = slow->next->next;
        return head;
    }
}
#pragma endregion
