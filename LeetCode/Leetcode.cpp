#pragma once
/// <summary>
/// The class is to implement some string algorithm 
/// </summary>
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

#pragma region HelperFunction
/// <summary>
/// Helper function which generate a linked list of a integers
/// </summary>
ListNode* LeetCode::generateListNodes(vector<int> integers)
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
/// Helper function which generate a cyclic linked list of a integers
/// </summary>
ListNode* LeetCode::generateCyclicListNodes(vector<int> integers)
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
/// Free list nodes
/// </summary>
void LeetCode::freeListNodes(ListNode * head)
{
    while (head != nullptr)
    {
        ListNode * node = head;
        head = head->next;
        delete node;
    }
}

/// <summary>
/// Free a cyclic linked list nodes
/// </summary>
void LeetCode::freeCyclicListNodes(ListNode * head)
{
	ListNode * node = head;
	while (true)
	{
		ListNode * next = node->next;
		delete node;
		node = next;
		if (node == head) break;
	}
}

/// <summary>
/// Free link tree nodes
/// </summary>
void LeetCode::freeLinkTreeNodes(TreeLinkNode * root)
{
    vector<TreeLinkNode *> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeLinkNode * node = stack.back();
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
/// Free nodes
/// </summary>
void LeetCode::freeNodes(Node * root)
{
	queue<Node *> search;
	search.push(root);
	while (!search.empty())
	{
		Node * node = search.front();
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
/// Find a list node with value
/// </summary>
ListNode* LeetCode::findListNode(ListNode *head, int value)
{
    ListNode * node = head;
    while (node != nullptr)
    {
        if (node->val == value) return node;
        node = node->next;
    }
    return nullptr;
}

/// <summary>
/// Find a tree node with value
/// </summary>
TreeNode* LeetCode::findTreeNode(TreeNode * root, int value)
{
    vector<TreeNode *> stack;
    // push the root first
    if (root != nullptr)
    {
        stack.push_back(root);
    }
    while (!stack.empty())
    {
        TreeNode * node = stack.back();
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
/// Add a list of list node at the end
/// </summary>
ListNode* LeetCode::addListNodes(ListNode * head, ListNode *tail)
{
    if (head == nullptr)
    {
        head = tail;
    }
    else
    {
        ListNode * prev = head;
        while (prev->next != nullptr)
        {
            prev = prev->next;
        }
        prev->next = tail;
    }
    return head;
}

/// <summary>
/// Output a cyclic linked list nodes
/// </summary>
vector<int> LeetCode::outputCyclicListNodes(ListNode * head)
{
	vector<int> result;
	ListNode * node = head;
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
/// Free tree nodes
/// </summary>
void LeetCode::freeTreeNodes(TreeNode* root)
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

#pragma endregion


  



