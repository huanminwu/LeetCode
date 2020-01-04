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


  



