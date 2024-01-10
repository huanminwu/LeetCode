#pragma once
#ifndef LeetcodeDesign_H
#define LeetCodeDesign_H
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
using namespace std;

class NestedInteger
{
private:
    vector<NestedInteger> m_NestedIntegers;
    int m_Integer;
    bool m_IsInteger;
    int m_Size;
public:
    // Constructure on single integter.
    NestedInteger()
    {
        m_NestedIntegers = vector<NestedInteger>();
        m_Size = 0;
        m_Integer = 0;
        m_IsInteger = false;
    }

    // Constructure on single integter.
    NestedInteger(int value)
    {
        m_NestedIntegers = vector<NestedInteger>();
        m_Integer = value;
        m_IsInteger = true;
        m_Size = 1;
    }

    // Constructure on nested integers.
    NestedInteger(vector<NestedInteger> nested_integers)
    {
        m_NestedIntegers = nested_integers;
        m_Integer = 0;
        m_IsInteger = false;
        m_Size = nested_integers.size();
    }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const
    {
        return m_IsInteger;
    };

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const
    {
        return m_Integer;
    };

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value)
    {
        m_Integer = value;
        m_IsInteger = true;
        m_NestedIntegers.clear();
        m_Size = 1;
    };

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger& ni)
    {
        if (m_Size == 1 && isInteger())
        {
            m_NestedIntegers.push_back(m_Integer);
        }
        m_NestedIntegers.push_back((NestedInteger)ni);
        m_IsInteger = false;
        m_Size++;
    };

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const
    {
        return m_NestedIntegers;
    };
};


struct TrieNode
{
    bool is_end;
    vector<TrieNode*> children;

    TrieNode()
    {
        is_end = false;
        children = vector<TrieNode*>(26, nullptr);
    };

    ~TrieNode()
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            if (children[i] != nullptr) delete children[i];
        }
    }

    void insert(string word, int i)
    {
        if (i == word.size())
        {
            is_end = true;
        }
        else
        {
            int k = word[i] - 'a';
            if (children[k] == nullptr)
            {
                children[k] = new TrieNode();
            }
            children[k]->insert(word, i + 1);
        }
    }

    TrieNode* next(char ch)
    {
        int k = ch - 'a';
        return children[k];
    }

    void get_words(string& word, vector<string>& result)
    {
        if (is_end) result.push_back(word);

        for (size_t i = 0; i < children.size(); i++)
        {
            if (children[i] != nullptr)
            {
                word.push_back((char)('a' + i));
                children[i]->get_words(word, result);
                word.pop_back();
            }
        }
    }
};

/// <summary>
/// Leet code #146. LRU Cache
/// 
/// Design and implement a data structure for Least Recently Used (LRU) cache. 
/// It should support the following operations: get and put.
/// get(key) - Get the value (will always be positive) of the key if the key 
/// exists in the cache, otherwise return -1.
/// put(key, value) - Set or insert the value if the key is not already 
/// present. When the cache reached its capacity, it should invalidate the 
/// least recently used item before inserting a new item.
/// The cache is initialized with a positive capacity.
/// Follow up:
/// Could you do both operations in O(1) time complexity?
/// Example:
/// LRUCache cache = new LRUCache( 2 /* capacity */ );
///
/// cache.put(1, 1);
/// cache.put(2, 2);
/// cache.get(1);       // returns 1
/// cache.put(3, 3);    // evicts key 2
/// cache.get(2);       // returns -1 (not found)
/// cache.put(4, 4);    // evicts key 1
/// cache.get(1);       // returns -1 (not found)
/// cache.get(3);       // returns 3
/// cache.get(4);       // returns 4
/// </summary>
class LRUCache
{
private:
    size_t m_Capacity;
    list<pair<int, int>> m_List;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;

public:
    /// <summary>
    /// Constructor an empty LRU cache
    /// </summary>
    /// <param name="capacity">capacity</param>
    /// <returns></returns>
    LRUCache(int capacity)
    {
        m_Capacity = capacity;
    }

    /// <summary>
    /// Destructor of an LRUCache
    /// </summary>
    /// <returns></returns>
    ~LRUCache()
    {
    }

    /// <summary>
    /// Set the key value pair in the LRU cache.
    /// </summary>
    /// <param name="key">The key</param>
    /// <param name="value">The value</param>
    /// <returns></returns>
    void put(int key, int value)
    {
        if (m_map.count(key) == 0)
        {
            m_List.push_front(make_pair(key, value));
            if (m_List.size() > m_Capacity)
            {
                pair<int, int> pair = m_List.back();
                m_map.erase(pair.first);
                m_List.pop_back();
            }
            m_map[key] = m_List.begin();
        }
        else
        {
            // take out old value, insert new one
            m_List.erase(m_map[key]);
            m_List.push_front(make_pair(key, value));
            m_map[key] = m_List.begin();
        }
    }

    /// <summary>
    /// Get the value(will always be positive) of the key if the key exists 
    /// in the cache, otherwise return -1.
    /// </summary>
    /// <returns>the value</returns>
    int get(int key)
    {
        if (m_map.find(key) == m_map.end())
        {
            return -1;
        }
        list<pair<int, int>>::iterator iterator = m_map[key];
        pair<int, int> pair = *iterator;
        m_List.erase(iterator);
        m_List.push_front(pair);
        m_map[key] = m_List.begin();
        return pair.second;
    }
};

/// <summary>
/// Leet code #251. Flatten 2D Vector  
/// 
/// Implement an iterator to flatten a 2d vector.
/// For example,
/// Given 2d vector = 
/// [
///  [1,2],
///  [3],
///  [4,5,6]
/// ]
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1,2,3,4,5,6]. 
/// Hint:
/// 1.How many variables do you need to keep track?
/// 2.Two variables is all you need. Try with x and y.
/// 3.Beware of empty rows. It could be the first few rows.
/// 4.To write correct code, think about the invariant to maintain. What is it?
/// 5.The invariant is x and y must always point to a valid point in the 2d 
///   vector. Should you maintain your invariant ahead of time or right when 
///   you need it?
/// 6.Not sure? Think about how you would implement hasNext(). Which is more 
///   complex?
/// 7.Common logic in two different places should be refactored into a common 
///   method.
///
/// Follow up:
/// As an added challenge, try to code it using only iterators in C++ or 
/// iterators in Java. 
/// </summary>
class Vector2D
{
private:
    size_t m_Row;
    size_t m_Col;
    vector<vector<int>> m_Vector;
public:
    Vector2D(vector<vector<int>>& vec2d)
    {
        m_Vector = vec2d;
        m_Row = 0;
        m_Col = 0;
    }

    int next()
    {
        int result = m_Vector[m_Row][m_Col];
        m_Col++;
        return result;
    }

    bool hasNext()
    {
        while ((m_Row < m_Vector.size()) && (m_Col >= m_Vector[m_Row].size()))
        {
            m_Row++;
            m_Col = 0;
        }
        if (m_Row == m_Vector.size()) return false;
        else return true;
    }
};

/// <summary>
/// Leet code #281. Zigzag Iterator  
/// 
/// Given two 1d vectors, implement an iterator to return their elements 
/// alternately.
/// For example, given two 1d vectors: 
/// v1 = [1, 2]
/// v2 = [3, 4, 5, 6]
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1, 3, 2, 4, 5, 6].
/// Follow up: What if you are given k 1d vectors? How well can your code be 
/// extended to such cases?
/// Clarification for the follow up question - Update (2015-09-18):
/// The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. 
/// If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". 
/// For example, given the following input: 
/// [1,2,3]
/// [4,5,6,7]
/// [8,9]
/// It should return [1,4,8,2,5,9,3,6,7]. 	
/// </summary>
class ZigzagIterator
{
private:
    size_t m_Row;
    size_t m_Col;
    int m_Size;
    int m_Index;
    vector<vector<int>> m_Vector;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        m_Vector.push_back(v1);
        m_Vector.push_back(v2);
        m_Index = 0;
        m_Size = v1.size() + v2.size();
        m_Row = 0;
        m_Col = 0;
    }
    int next()
    {
        int result;
        while (m_Row >= m_Vector.size() || m_Col >= m_Vector[m_Row].size())
        {
            if (m_Row < m_Vector.size())
            {
                m_Row++;
            }
            else
            {
                m_Row = 0;
                m_Col++;
            }
        }
        result = m_Vector[m_Row][m_Col];
        m_Row++;
        m_Index++;
        return result;
    }

    bool hasNext()
    {
        if (m_Index < m_Size) return true;
        else return false;
    }
};

/// <summary>
/// Leet code #284. Peeking Iterator
/// Given an Iterator class interface with methods: next() and hasNext(), design and implement 
/// a PeekingIterator that support the peek() operation -- it essentially peek() at the element that 
/// will be returned by the next call to next().
///
/// Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
/// Call next() gets you 1, the first element in the list.
/// Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
///
/// You call next() the final time and it returns 3, the last element. 
/// Calling hasNext() after that should return false. 
/// Hint:
/// 1.Think of "looking ahead". You want to cache the next element.
/// 2.Is one variable sufficient? Why or why not?
/// 3.Test your design with call order of peek() before next() vs next() before peek().
/// 4.For a clean implementation, check out Google's guava library source code.
/// Follow up: How would you extend your design to be generic and work with all types, not just integer?	
/// </summary>
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
// 2016-12-10, HM: I modify this interface so I can run it in my code 
class Iterator {
private:
    vector<int> m_nums;
    int m_index;
public:
    Iterator(const vector<int>& nums)
    {
        m_nums = nums;
        m_index = 0;
    };
    Iterator(const Iterator& iter)
    {
        m_nums = iter.m_nums;
    }
    virtual ~Iterator()
    {
    };
    // Returns the next element in the iteration.
    int next()
    {
        return m_nums[m_index];
        m_index++;
    };
    // Returns true if the iteration has more elements.
    bool hasNext() const
    {
        return (m_index < (int)m_nums.size());
    };
};


class PeekingIterator : public Iterator
{
private:
    queue<int> m_queue;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        if ((m_queue.empty()) && (Iterator::hasNext()))
        {
            m_queue.push(Iterator::next());
        }
        return m_queue.front();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int value;
        if (!m_queue.empty())
        {
            value = m_queue.front();
            m_queue.pop();
        }
        else
        {
            value = Iterator::next();
        }
        return value;
    }

    bool hasNext() const {
        if (!m_queue.empty())
        {
            return true;
        }
        else
        {
            return Iterator::hasNext();
        }
    }
};

/// <summary>
/// LeetCode #355. Design Twitter
/// Design a simplified version of Twitter where users can post tweets, 
/// follow/unfollow another user and 
/// is able to see the 10 most recent tweets in the user's news feed. 
/// Your design should support the following methods:
/// 1.postTweet(userId, tweetId): Compose a new tweet.
/// 2.getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's 
///   news feed. 
/// Each item in the news feed must be posted by users who the user followed 
/// or by the user herself. 
/// Tweets must be ordered from most recent to least recent.
/// 3.follow(followerId, followeeId): Follower follows a followee.
/// 4.unfollow(followerId, followeeId): Follower unfollows a followee.
/// Example: 
/// Twitter twitter = new Twitter();
/// User 1 posts a new tweet (id = 5).
/// twitter.postTweet(1, 5);
/// User 1's news feed should return a list with 1 tweet id -> [5].
/// twitter.getNewsFeed(1);
/// User 1 follows user 2.
/// twitter.follow(1, 2);
/// User 2 posts a new tweet (id = 6).
/// twitter.postTweet(2, 6);
/// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
/// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
/// twitter.getNewsFeed(1);
///
/// User 1 unfollows user 2.
/// twitter.unfollow(1, 2);
/// User 1's news feed should return a list with 1 tweet id -> [5],
/// since user 1 is no longer following user 2.
/// twitter.getNewsFeed(1);
/// </summary>
class Twitter
{
private:
    long m_TimeTicks;

    unordered_map<int, vector<pair<long, int>>> m_TwitterList;
    unordered_map<int, unordered_set<int>> m_FollowList;

public:
    /// <summary>
    /// Constructor an empty Twitter cache
    /// </summary>
    /// <returns></returns>
    Twitter()
    {
        m_TimeTicks = 0;
    }

    /// <summary>
    /// Destructor of an Twitter
    /// </summary>
    /// <returns></returns>
    ~Twitter()
    {
    }

    /// <summary>
    /// Compose a new tweet
    /// </summary>
    /// <returns></returns>
    void postTweet(int userId, int tweetId)
    {
        m_TimeTicks++;
        long now = m_TimeTicks;

        m_TwitterList[userId].push_back(make_pair(m_TimeTicks, tweetId));
    }

    /// <summary>
    /// Retrieve the 10 most recent tweet ids in the user's news feed. 
    /// Each item in the news feed must be posted by users who the user 
    /// followed or by the user herself. 
    /// Tweets must be ordered from most recent to least recent.
    /// </summary>
    /// <returns></returns>
    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        priority_queue <pair<long, pair<int, int>>> candidate_list;
        if (!m_TwitterList[userId].empty())
        {
            int clock = m_TwitterList[userId].back().first;
            int index = (int)m_TwitterList[userId].size() - 1;
            candidate_list.push(make_pair(clock, make_pair(userId, index)));
        }
        for (int followee : m_FollowList[userId])
        {
            if (!m_TwitterList[followee].empty())
            {
                int clock = m_TwitterList[followee].back().first;
                int index = (int)m_TwitterList[followee].size() - 1;
                candidate_list.push(make_pair(clock, make_pair(followee, index)));
            }
        }

        for (size_t i = 0; i < 10; i++)
        {
            if (candidate_list.empty())
            {
                break;
            }
            pair<long, pair<int, int>> tweet_itr = candidate_list.top();
            candidate_list.pop();
            int user_id = tweet_itr.second.first;
            int index = tweet_itr.second.second;
            int tweet_id = m_TwitterList[user_id][index].second;
            result.push_back(tweet_id);
            // push the next tweet of this user to priority queue
            if (index > 0)
            {
                index--;
                int clock = m_TwitterList[user_id][index].first;
                candidate_list.push(make_pair(clock, make_pair(user_id, index)));
            }
        }

        return result;
    }

    /// <summary>
    /// Follower follows a followee. If the operation is invalid, it should 
    /// be a no-op.
    /// </summary>
    /// <param name="followerId">The follower id</param>
    /// <param name="followeeId">The followee id</param>
    /// <returns></returns>
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            m_FollowList[followerId].insert(followeeId);
        }
    }

    /// <summary>
    /// Follower unfollows a followee. If the operation is invalid, it should 
    /// be a no-op.
    /// </summary>
    /// <param name="followerId">The follower id</param>
    /// <param name="followeeId">The followee id</param>
    /// <returns></returns>
    void unfollow(int followerId, int followeeId)
    {
        m_FollowList[followerId].erase(followeeId);
    }
};

/// <summary>
/// Leet code #352. Data Stream as Disjoint Intervals 
/// 
/// Given a data stream input of non-negative integers a1, a2, ..., an, ..., 
/// summarize the numbers seen so far as a list of disjoint intervals.
/// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., 
/// then the summary will be:
/// [1, 1]
/// [1, 1], [3, 3]
/// [1, 1], [3, 3], [7, 7] 
/// [1, 3], [7, 7]
/// [1, 3], [6, 7]
/// Follow up:
/// What if there are lots of merges and the number of disjoint intervals 
/// are small compared to the data stream's size? 
/// </summary>
class SummaryRanges
{
private:
    map<int, int> m_Intervals;
public:
    /// Initialize your data structure here. ///
    SummaryRanges()
    {
    }

    void addNum(int val)
    {
        map<int, int>::iterator itr = m_Intervals.lower_bound(val);
        int start = val;
        int end = val;
        if (itr != m_Intervals.begin())
        {
            itr--;
            if (val <= itr->second) return;
            else if (itr->second == val - 1)
            {
                start = itr->first;
            }
            itr++;
        }
        if (itr != m_Intervals.end())
        {
            if ((val == itr->first) || (itr->first == val + 1))
            {
                end = itr->second;
                m_Intervals.erase(itr->first);
            }
        }
        m_Intervals[start] = end;
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> result;
        for (map<int, int>::iterator itr = m_Intervals.begin(); itr != m_Intervals.end(); itr++)
        {
            result.push_back({ itr->first, itr->second });
        }
        return result;
    }
};

/// <summary>
/// Leet code #379. Design Phone Directory 
/// 
/// Design a Phone Directory which supports the following operations:
/// 1.get: Provide a number which is not assigned to anyone.
///	2.check: Check if a number is available or not.
/// 3.release: Recycle or release a number.
/// Example: 
/// // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
/// PhoneDirectory directory = new PhoneDirectory(3);
/// // It can return any available phone number. Here we assume it returns 0.
/// directory.get();
/// 
/// // Assume it returns 1.
/// directory.get();
///
/// // The number 2 is available, so return true.
/// directory.check(2);
///
/// // It returns 2, the only number that is left.
/// directory.get();
///
/// // The number 2 is no longer available, so return false.
/// directory.check(2);
///
/// // Release number 2 back to the pool.
/// directory.release(2);
///
/// // Number 2 is available again, return true.
/// directory.check(2);
/// </summary>
class PhoneDirectory
{
    vector<int> m_FreeList;
    vector<bool> m_Allocation;
    int m_Index;
    int m_Size;
public:
    // Initialize your data structure here
    // @param maxNumbers - The maximum numbers that can be stored in the phone directory.
    PhoneDirectory(int maxNumbers)
    {
        m_Index = 0;
        m_Size = maxNumbers;
        m_FreeList = vector<int>(m_Size);
        m_Allocation = vector<bool>(m_Size, false);
        for (int i = 0; i < maxNumbers; i++)
        {
            m_FreeList[i] = i;
        }
    }

    // Provide a number which is not assigned to anyone.
    // @return - Return an available number. Return -1 if none is available.
    int get()
    {
        if (m_Index == m_Size)
        {
            return -1;
        }
        else
        {
            int value = m_FreeList[m_Index];
            m_Index++;
            m_Allocation[value] = true;
            return value;
        }
    }

    // Check if a number is available or not.
    bool check(int number)
    {
        if ((number < 0) || (number >= m_Size))
        {
            return false;
        }
        return (!m_Allocation[number]);
    }

    // Recycle or release a number.
    void release(int number)
    {
        if ((number < 0) || (number >= m_Size) || (m_Allocation[number] == false))
        {
            return;
        }
        m_Index--;
        m_FreeList[m_Index] = number;
        m_Allocation[number] = false;
    }
};

/// <summary>
/// Leet code #341. Flatten Nested List Iterator       
///
/// Given a nested list of integers, implement an iterator to flatten it. 
/// Each element is either an integer, or a list -- whose elements may also 
/// be integers or other lists.
///
/// Example 1:
/// Given the list [[1,1],2,[1,1]],
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1,1,2,1,1]. 
///
/// Example 2:
/// Given the list [1,[4,[6]]],
/// By calling next repeatedly until hasNext returns false, the order of 
/// elements returned by next should be: [1,4,6]. 
///
/// This is the interface that allows for creating nested lists.
/// You should not implement it, or speculate about its implementation
/// Your NestedIterator object will be instantiated and called as such:
/// NestedIterator i(nestedList);
/// while (i.hasNext()) cout << i.next();
/// </summary>
class NestedIterator {
private:
    deque<NestedInteger> m_NestedQueue;
    bool isEmpty(NestedInteger& ni)
    {
        if (ni.isInteger())
        {
            return false;
        }
        else
        {
            vector<NestedInteger> ni_list = ni.getList();
            for (size_t i = 0; i < ni_list.size(); i++)
            {
                if (!isEmpty(ni_list[i])) return false;
            }
            return true;
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList)
    {
        for (size_t i = 0; i < nestedList.size(); i++)
        {
            m_NestedQueue.push_back(nestedList[i]);
        }
    }

    int next()
    {
        int value = 0;
        if (!m_NestedQueue.empty())
        {
            NestedInteger nested_integer = m_NestedQueue.front();
            m_NestedQueue.pop_front();
            if (nested_integer.isInteger())
            {
                value = nested_integer.getInteger();
            }
            else
            {
                vector<NestedInteger> nested_list = nested_integer.getList();
                while (!nested_list.empty())
                {
                    m_NestedQueue.push_front(nested_list.back());
                    nested_list.pop_back();
                }
                value = next();
            }
        }
        return value;
    }

    bool hasNext()
    {
        bool has_next = false;

        while (!m_NestedQueue.empty())
        {
            NestedInteger ni = m_NestedQueue.front();
            if (isEmpty(ni))
            {
                m_NestedQueue.pop_front();
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

/// <summary>
/// Leet code #348. Design Tic-Tac-Toe 
/// 
/// Design a Tic-tac-toe game that is played between two players on a n x n grid. 
/// You may assume the following rules:  
/// 1.A move is guaranteed to be valid and is placed on an empty block.
/// 2.Once a winning condition is reached, no more moves is allowed. 
/// 3.A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
///
/// Example:
/// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
/// TicTacToe toe = new TicTacToe(3); 
/// toe.move(0, 0, 1); -> Returns 0 (no one wins)
/// |X| | |
/// | | | |    // Player 1 makes a move at (0, 0).
/// | | | |
/// 
/// toe.move(0, 2, 2); -> Returns 0 (no one wins)
/// |X| |O|
/// | | | |    // Player 2 makes a move at (0, 2).
/// | | | |
/// 
/// toe.move(2, 2, 1); -> Returns 0 (no one wins)
/// |X| |O|
/// | | | |    // Player 1 makes a move at (2, 2).
/// | | |X|
///
/// toe.move(1, 1, 2); -> Returns 0 (no one wins)
/// |X| |O|
/// | |O| |    // Player 2 makes a move at (1, 1).
/// | | |X|
///
/// toe.move(2, 0, 1); -> Returns 0 (no one wins)
/// |X| |O|
/// | |O| |    // Player 1 makes a move at (2, 0).
/// |X| |X|
///
/// toe.move(1, 0, 2); -> Returns 0 (no one wins)
/// |X| |O|
/// |O|O| |    // Player 2 makes a move at (1, 0).
/// |X| |X|
///
/// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
/// |X| |O|
/// |O|O| |    // Player 1 makes a move at (2, 1).
/// |X|X|X|
/// Follow up:
/// Could you do better than O(n2) per move() operation? 
/// Hint:
/// 1.Could you trade extra space such that move() operation can be done in O(1)?
/// 2.You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
/// </summary>
class TicTacToe
{
    vector<vector<int>> row_map;
    vector<vector<int>> col_map;
    vector<int> diag_map;
    vector<int> anti_map;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n)
    {
        row_map = vector<vector<int>>(n, vector<int>(2));
        col_map = vector<vector<int>>(n, vector<int>(2));
        diag_map = vector<int>(2);
        anti_map = vector<int>(2);
    }

    /** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
    0: No one wins.
    1: Player 1 wins.
    2: Player 2 wins. */
    int move(int row, int col, int player)
    {
        row_map[row][player - 1]++;
        col_map[col][player - 1]++;
        if (row == col)
        {
            diag_map[player - 1]++;
        }
        if (row + col == row_map.size() - 1)
        {
            anti_map[player - 1]++;
        }
        if ((row_map[row][player - 1] == row_map.size()) ||
            (col_map[col][player - 1] == row_map.size()) ||
            (diag_map[player - 1] == row_map.size()) ||
            (anti_map[player - 1] == row_map.size()))
        {
            return player;
        }
        else
        {
            return 0;
        }
    }
};

/// <summary>
/// Leet code #353. Design Snake Game  
/// 
/// Design a Snake game that is played on a device with screen size = width x height. 
/// Play the game online if you are not familiar with the game.
/// The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
/// You are given a list of food's positions in row-column order. When a snake eats the food, 
/// its length and the game's score both increase by 1.
/// Each food appears one by one on the screen. For example, the second food will not appear 
/// until the first food was eaten by the snake. 
/// When a food does appear on the screen, it is guaranteed that it will not appear on a 
/// block occupied by the snake.
/// Example:
/// Given width = 3, height = 2, and food = [[1,2],[0,1]].
/// Snake snake = new Snake(width, height, food);
/// Initially the snake appears at position (0,0) and the food at (1,2).
/// |S| | |
/// | | |F|
/// 
/// snake.move("R"); -> Returns 0
/// | |S| |
/// | | |F|
///
/// snake.move("D"); -> Returns 0
///
/// | | | |
/// | |S|F|
///   
/// snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
///
/// | |F| |
/// | |S|S|
///
/// snake.move("U"); -> Returns 1
///
/// | |F|S|
/// | | |S|
///
/// snake.move("L"); -> Returns 2 (Snake eats the second food)
///
/// | |S|S|
/// | | |S|
///
/// snake.move("U"); -> Returns -1 (Game over because snake collides with border)
/// </summary>
class SnakeGame
{
private:
    list<pair<int, int>> m_snake;
    int m_width;
    int m_height;
    vector<pair<int, int>> m_food;
    int m_foodindex;
    unordered_map<int, unordered_set<int>> m_snakemap;
public:
    /** Initialize your data structure here.
    @param width - screen width
    @param height - screen height
    @param food - A list of food positions
    E.g food = [[1, 1], [1, 0]] means the first food is positioned at[1, 1], the second is at[1, 0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food)
    {
        m_width = width;
        m_height = height;
        m_food = food;
        m_snake.push_front(make_pair(0, 0));
        m_snakemap[0].insert(0);
        m_foodindex = 0;
    }

    /** Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
    @return The game's score after the move. Return -1 if game over.
    Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction)
    {
        pair<int, int> head = m_snake.front();
        if (direction == "U")
        {
            head.first--;
            if (head.first < 0)
            {
                return -1;
            }
        }
        else if (direction == "D")
        {
            head.first++;
            if (head.first == m_height)
            {
                return -1;
            }
        }
        else if (direction == "L")
        {
            head.second--;
            if (head.second < 0)
            {
                return -1;
            }
        }
        else if (direction == "R")
        {
            head.second++;
            if (head.second == m_width)
            {
                return -1;
            }
        }

        m_snake.push_front(head);
        if ((m_foodindex < (int)m_food.size()) && (head == m_food[m_foodindex]) &&
            (m_snakemap[head.first].count(head.second) == 0))
        {
            m_foodindex++;
        }
        else
        {
            pair<int, int> tail = m_snake.back();
            m_snakemap[tail.first].erase(tail.second);
            m_snake.pop_back();
        }
        if (m_snakemap[head.first].count(head.second) > 0)
        {
            return -1;
        }
        m_snakemap[head.first].insert(head.second);
        return m_foodindex;
    }
};

/// <summary>
/// Leet code #631. Design Excel Sum Formula
/// 
/// Your task is to design the basic function of Excel and implement the 
/// function of sum formula. Specifically, you need to implement the 
/// following functions:
/// Excel(int H, char W): This is the constructor. The inputs represents 
/// the height and width of the Excel form. H is a positive integer, range 
/// from 1 to 26. It represents the height. W is a character range from 
/// 'A' to 'Z'. It represents that the width is the number of characters 
/// from 'A' to W. The Excel form content is represented by a height * 
/// width 2D integer array C, it should be initialized to zero. You should 
/// assume that the first row of C starts from 1, and the first column of 
/// C starts from 'A'.
/// 
/// void Set(int row, char column, int val): Change the value at 
/// C(row, column) to be val.
///
/// int Get(int row, char column): Return the value at C(row, column).
///
/// int Sum(int row, char column, List of Strings : numbers): This function 
/// calculate and set the value at C(row, column), where the value should 
/// be the sum of cells represented by numbers. This function return the 
/// sum result at C(row, column). This sum formula should exist until this 
/// cell is overlapped by another value or another sum formula.
/// numbers is a list of strings that each string represent a cell or a 
/// range of cells. If the string represent a single cell, then it has the 
/// following format : ColRow. For example, "F7" represents the cell at 
/// (7, F). 
/// If the string represent a range of cells, then it has the following 
/// format : ColRow1:ColRow2. The range will always be a rectangle, and 
/// ColRow1 represent the position of the top-left cell, and ColRow2 
/// represents the position of the bottom-right cell. 
///
/// Example 1:
/// Excel(3,"C"); 
/// construct a 3*3 2D array with all zero.
///   A B C
/// 1 0 0 0
/// 2 0 0 0
/// 3 0 0 0
///
/// Set(1, "A", 2);
/// set C(1,"A") to be 2.
///   A B C
/// 1 2 0 0
/// 2 0 0 0
/// 3 0 0 0
///
/// Sum(3, "C", ["A1", "A1:B2"]);
/// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of 
/// the rectangle range whose top-left cell is C(1,"A") and bottom-right 
/// cell is C(2,"B"). Return 4. 
///   A B C
/// 1 2 0 0
/// 2 0 0 0
/// 3 0 0 4
///
/// Set(2, "B", 2);
/// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
///   A B C
/// 1 2 0 0
/// 2 0 2 0
/// 3 0 0 6
///
/// Note:
/// You could assume that there won't be any circular sum reference. For 
/// example, A1 = sum(B1) and B1 = sum(A1).
/// The test cases are using double-quotes to represent a character.
/// Please remember to RESET your class variables declared in class Excel, 
/// as static/class variables are persisted across multiple test cases. 
/// Please see here for more details.
/// </summary>
class Excel
{
private:
    unordered_map<int, unordered_map<int, vector<pair<int, int>>>> sum_formula;
    vector<vector<int>> cells;

    int calculate(int row, int col)
    {
        if (sum_formula[row].count(col) == 0)
        {
            return cells[row][col];
        }

        int sum = 0;
        vector<pair<int, int>>& range_list = sum_formula[row][col];
        for (size_t i = 0; i < range_list.size(); i += 2)
        {
            int start_row = range_list[i].first;
            int start_col = range_list[i].second;
            int end_row = range_list[i + 1].first;
            int end_col = range_list[i + 1].second;
            for (int r = start_row; r < end_row; r++)
            {
                for (int c = start_col; c < end_col; c++)
                {
                    sum += calculate(r, c);
                }
            }
        }
        return sum;
    }

    vector<pair<int, int>> parse_range(vector<string> str_list)
    {
        vector<pair<int, int>> result;
        for (size_t i = 0; i < str_list.size(); i++)
        {
            string token;
            string str = str_list[i];
            int row = 0, col = 0;
            for (size_t j = 0; j <= str.size(); j++)
            {
                if (j == str.size())
                {
                    row = stoi(token) - 1;
                    token.clear();

                    // for a single cell
                    if (result.size() % 2 == 0)
                    {
                        result.push_back(make_pair(row, col));
                    }
                    // for end range we make it out of boundary
                    result.push_back(make_pair(row + 1, col + 1));
                }
                else if (str[j] == ':')
                {
                    row = stoi(token) - 1;
                    token.clear();
                    result.push_back(make_pair(row, col));
                }
                else if (isalpha(str[j]))
                {
                    col = str[j] - 'A';
                }
                else if (isdigit(str[j]))
                {
                    token += str[j];
                }
            }
            // if this is a single cell, duplicate it as range
            if (result.size() % 2 == 1)
            {
                result.push_back(make_pair(row, col));
            }
        }
        return result;
    }

public:
    Excel(int H, char W)
    {
        int rows = H;
        int cols = W - 'A' + 1;
        cells = vector<vector<int>>(rows, vector<int>(cols));
    }

    void set(int r, char c, int v)
    {
        int row = r - 1;
        int col = c - 'A';
        // clean up formula
        if (sum_formula[row].count(col) > 0)
        {
            sum_formula[row].erase(col);
        }

        cells[row][col] = v;
    }

    int get(int r, char c)
    {
        int row = r - 1;
        int col = c - 'A';
        return calculate(row, col);
    }

    int sum(int r, char c, vector<string> strs)
    {
        int row = r - 1;
        int col = c - 'A';
        sum_formula[row][col] = parse_range(strs);
        cells[row][col] = 0;
        return calculate(row, col);
    }
};

/// <summary>
/// Leet code #362. Design Hit Counter  
/// 
/// Design a hit counter which counts the number of hits received in the past 5 minutes.
/// Each function accepts a timestamp parameter (in seconds granularity) and you may 
/// assume that calls are being made to the system in chronological order (ie, the 
/// timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.
/// It is possible that several hits arrive roughly at the same time.
/// Example:
/// HitCounter counter = new HitCounter();
/// // hit at timestamp 1.
/// counter.hit(1);
/// // hit at timestamp 2.
/// counter.hit(2);
/// // hit at timestamp 3.
/// counter.hit(3);
/// // get hits at timestamp 4, should return 3.
/// counter.getHits(4);
/// // hit at timestamp 300.
/// counter.hit(300);
/// // get hits at timestamp 300, should return 4.
/// counter.getHits(300);
/// // get hits at timestamp 301, should return 3.
/// counter.getHits(301); 
/// Follow up:
/// What if the number of hits per second could be very large? Does your design scale? 
/// </summary>
class HitCounter
{
private:
    int m_Count;
    map<int, int> m_HitMap;
public:
    // Initialize your data structure here.
    HitCounter()
    {
        m_Count = 0;
    }

    // Record a hit.
    // @param timestamp - The current timestamp (in seconds granularity).
    void hit(int timestamp)
    {
        m_HitMap[timestamp]++;
        m_Count++;
        while (!m_HitMap.empty())
        {
            int first_timestamp = m_HitMap.begin()->first;
            if (first_timestamp + 300 <= timestamp)
            {
                m_Count -= m_HitMap[first_timestamp];
                m_HitMap.erase(first_timestamp);
            }
            else
            {
                return;
            }
        }
    }

    // Return the number of hits in the past 5 minutes.
    // @param timestamp - The current timestamp (in seconds granularity).
    int getHits(int timestamp)
    {
        while (!m_HitMap.empty())
        {
            int first_timestamp = m_HitMap.begin()->first;
            if (first_timestamp + 300 <= timestamp)
            {
                m_Count -= m_HitMap[first_timestamp];
                m_HitMap.erase(first_timestamp);
            }
            else
            {
                break;
            }
        }
        return m_Count;
    }
};

/// <summary>
/// Leet code #346. Moving Average from Data Stream  
/// 
/// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
/// For example,
/// MovingAverage m = new MovingAverage(3);
/// m.next(1) = 1
/// m.next(10) = (1 + 10) / 2
/// m.next(3) = (1 + 10 + 3) / 3
/// m.next(5) = (10 + 3 + 5) / 3
/// </summary>
class MovingAverage
{
private:
    int m_Sum;
    int m_Size;
    queue<int> m_Queue;
public:
    // Initialize your data structure here.
    MovingAverage(int size)
    {
        m_Sum = 0;
        m_Size = size;
    }

    double next(int val)
    {
        m_Sum += val;
        m_Queue.push(val);
        if (m_Queue.size() > (size_t)m_Size)
        {
            m_Sum -= m_Queue.front();
            m_Queue.pop();
        }
        return (double(m_Sum) / m_Queue.size());
    }
};

/// <summary>
/// Leet code #359. Logger Rate Limiter  
/// 
/// Design a logger system that receive stream of messages along with its timestamps, 
/// each message should be printed if and only if it is not printed in the last 10 seconds.
/// Given a message and a timestamp (in seconds granularity), return true if the message 
/// should be printed in the given timestamp, otherwise returns false.
/// It is possible that several messages arrive roughly at the same time.
///
/// Example: 
/// Logger logger = new Logger();
/// // logging string "foo" at timestamp 1
/// logger.shouldPrintMessage(1, "foo"); returns true; 
/// // logging string "bar" at timestamp 2
/// logger.shouldPrintMessage(2,"bar"); returns true;
/// // logging string "foo" at timestamp 3
/// logger.shouldPrintMessage(3,"foo"); returns false;
/// // logging string "bar" at timestamp 8
/// logger.shouldPrintMessage(8,"bar"); returns false;
/// // logging string "foo" at timestamp 10
/// logger.shouldPrintMessage(10,"foo"); returns false;
/// // logging string "foo" at timestamp 11
/// logger.shouldPrintMessage(11,"foo"); returns true;
/// </summary>
class Logger1
{
private:
    unordered_map<string, int> message_map;
public:

    // Returns true if the message should be printed in the given timestamp, otherwise returns false.
    // If this method returns false, the message will not be printed.
    // The timestamp is in seconds granularity.
    bool shouldPrintMessage(int timestamp, string message)
    {
        if (message_map.find(message) == message_map.end())
        {
            message_map[message] = timestamp;
            return true;
        }
        else if (message_map[message] + 10 <= timestamp)
        {
            message_map[message] = timestamp;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/// <summary>
/// Leet code # 55. Min Stack 
/// 
/// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time. 
/// push(x) -- Push element x onto stack. 
/// pop() -- Removes the element on top of the stack. 
/// top() -- Get the top element.
/// getMin() -- Retrieve the minimum element in the stack.
/// Example:
///  MinStack minStack = new MinStack();
///  minStack.push(-2);
///  minStack.push(0);
///  minStack.push(-3);
///  minStack.getMin();   --> Returns -3.
///  minStack.pop();
///  minStack.top();      --> Returns 0.
///  minStack.getMin();   --> Returns -2.
/// </summary>
class MinStack
{
private:
    stack<pair<int, int>> m_Stack;

public:
    /// <summary>
    /// Constructor an empty min stack
    /// </summary>
    MinStack() {};

    /// <summary>
    /// Destructor of a MinStack
    /// </summary>
    /// <returns></returns>
    ~MinStack() {};

    /// <summary>
    /// Push the value.
    /// </summary>
    /// <param name="x">The value</param>
    /// <returns></returns>
    void push(int x)
    {
        if (m_Stack.empty())
        {
            m_Stack.push(make_pair(x, x));
        }
        else
        {
            pair<int, int> pair = m_Stack.top();
            m_Stack.push(make_pair(x, min(pair.second, x)));
        }
    }

    /// <summary>
    /// Pop the value.
    /// </summary>
    /// <returns></returns>
    void pop()
    {
        if (m_Stack.empty())
        {
            return;
        }
        m_Stack.pop();
    }

    /// <summary>
    /// Get the top value in the stack.
    /// </summary>
    /// <returns>value</returns>
    int top()
    {
        if (m_Stack.empty())
        {
            return INT_MIN;
        }
        pair<int, int> pair = m_Stack.top();
        return pair.first;
    }

    /// <summary>
    /// Get the minimum value in the stack.
    /// </summary>
    /// <returns>the minimum value in the stack</returns>
    int getMin()
    {
        if (m_Stack.empty())
        {
            return INT_MIN;
        }
        pair<int, int> pair = m_Stack.top();
        return pair.second;
    }
};

/// <summary>
/// Leet code #716. Max Stack
/// 
/// Design a max stack that supports push, pop, top, peekMax and popMax.
///
/// push(x) -- Push element x onto stack.
/// pop() -- Remove the element on top of the stack and return it.
/// top() -- Get the element on the top.
/// peekMax() -- Retrieve the maximum element in the stack.
/// popMax() -- Retrieve the maximum element in the stack, and remove it. 
/// If you find more than one maximum elements, only remove the top-most 
/// one.
/// Example 1:
/// MaxStack stack = new MaxStack();
/// stack.push(5); 
/// stack.push(1);
/// stack.push(5);
/// stack.top(); -> 5
/// stack.popMax(); -> 5
/// stack.top(); -> 1
/// stack.peekMax(); -> 5
/// stack.pop(); -> 1
/// stack.top(); -> 5
/// Note:
/// 1. -1e7 <= x <= 1e7
/// 2. Number of operations won't exceed 10000.
/// 3. The last four operations won't be called when stack is empty.
/// </summary>
class MaxStack {
private:
    map<int, stack<list<int>::iterator>> m_ValueMap;
    list<int> m_List;
public:
    /// <summary>
    /// Constructor an empty max stack
    /// </summary>
    MaxStack()
    {
    }

    void push(int x)
    {
        // Add to stack stack, last one first
        m_List.push_front(x);

        // Add to value map, biggest first
        m_ValueMap[-x].push(m_List.begin());
    }

    int pop()
    {
        // take first item from m_StackMap, which is the last item based on index
        auto itr = m_List.begin();
        int value = *itr;
        m_List.pop_front();
        // take out the top index from specific value 
        m_ValueMap[-value].pop();
        if (m_ValueMap[-value].empty()) m_ValueMap.erase(-value);
        return value;
    }

    int top()
    {
        // take first item from m_StackMap, which is the last item based on index
        auto itr = m_List.begin();
        int value = *itr;
        return value;
    }

    int peekMax()
    {
        // take first item from m_ValueMap, and the first one in the queue
        auto itr = m_ValueMap.begin();
        int value = -itr->first;
        return value;
    }

    int popMax()
    {
        // take first item from m_ValueMap, and the first one in the queue
        auto itr = m_ValueMap.begin();
        int value = -itr->first;
        auto list_itr = itr->second.top();
        m_List.erase(itr->second.top());
        itr->second.pop();
        if (itr->second.empty()) m_ValueMap.erase(itr->first);
        return value;
    }
};

/// <summary>
/// Leet Code 303. Range Sum Query - Immutable
/// 
/// Easy
///	
/// Given an integer array nums, handle multiple queries of the following 
/// type:
///
/// Calculate the sum of the elements of nums between indices left and 
/// right inclusive where left <= right.
/// Implement the NumArray class:
///
/// NumArray(int[] nums) Initializes the object with the integer array 
/// nums.
/// int sumRange(int left, int right) Returns the sum of the elements 
/// of nums between indices left and right inclusive (i.e. 
/// nums[left] + nums[left + 1] + ... + nums[right]).
///
/// Example 1:
/// Input
/// ["NumArray", "sumRange", "sumRange", "sumRange"]
/// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
/// Output
/// [null, 1, -1, -3]
///
/// Explanation
/// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
/// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
/// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
/// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^4
/// 2. -10^5 <= nums[i] <= 10^5
/// 3. 0 <= left <= right < nums.length
/// 4. At most 10^4 calls will be made to sumRange.
/// </summary>
class NumArray
{
private:
    vector<int> m_sum;
public:
    NumArray(vector<int>& nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            m_sum.push_back(nums.size());
            if (i == 0)
            {
                m_sum[i] = nums[i];
            }
            else
            {
                m_sum[i] = m_sum[i - 1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j)
    {
        if (i > j) std::swap(i, j);
        if (i == 0)
        {
            return m_sum[j];
        }
        else
        {
            return m_sum[j] - m_sum[i - 1];
        }
    }
};

/// <summary>
/// Leet code #307. Range Sum Query - Mutable
/// Given an integer array nums, find the sum of the elements between indices 
/// i and j (i ≤ j), inclusive.
/// The update(i, val) function modifies nums by updating the element at index 
/// i to val. 
/// Example:
/// Given nums = [1, 3, 5]
/// sumRange(0, 2) -> 9
/// update(1, 2)
/// sumRange(0, 2) -> 8
/// Note:
/// 1.The array is only modifiable by the update function.
/// 2.You may assume the number of calls to update and sumRange function is 
/// distributed evenly.
/// </summary>
class NumArrayMutable
{
private:
    vector<int> m_sum;
    int sum(int i)
    {
        int sum = 0;
        int index = i + 1;
        while (index != 0)
        {
            sum += m_sum[index];
            index -= index & -index;
        }
        return sum;
    }

    void add(int i, int value)
    {
        int index = i + 1;
        while (index < (int)m_sum.size())
        {
            m_sum[index] += value;
            index += (index & -index);
        }
    }

public:
    NumArrayMutable(vector<int>& nums)
    {
        m_sum = vector<int>(nums.size() + 1, 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            add(i, nums[i]);
        }
    }

    void update(int i, int value)
    {
        int old_value = sum(i) - sum(i - 1);
        value = value - old_value;
        add(i, value);
    }

    int sumRange(int i, int j)
    {
        return sum(j) - sum(i - 1);
    }
};

/// <summary>
/// 304. Range Sum Query 2D - Immutable
/// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper 
/// left corner (row1, col1) and lower right corner (row2, col2).
///
/// Range Sum Query 2D
/// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8. 
/// Example:
/// Given matrix = [
/// [3, 0, 1, 4, 2],
/// [5, 6, 3, 2, 1],
/// [1, 2, 0, 1, 5],
/// [4, 1, 0, 1, 7],
/// [1, 0, 3, 0, 5]
/// ]
/// sumRegion(2, 1, 4, 3) -> 8
/// sumRegion(1, 1, 2, 2) -> 11
/// sumRegion(1, 2, 2, 4) -> 12
///
/// Note:
/// 1.You may assume that the matrix does not change.
/// 2.There are many calls to sumRegion function.
/// 3.You may assume that row1 ≤ row2 and col1 ≤ col2.
/// </summary>
class NumMatrix
{
private:
    vector<vector<int>> m_matrix;
public:
    NumMatrix(vector<vector<int>>& matrix)
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            m_matrix.push_back(vector<int>(matrix[i].size()));
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (j == 0)
                {
                    m_matrix[i][j] = matrix[i][j];
                }
                else
                {
                    m_matrix[i][j] = matrix[i][j] + m_matrix[i][j - 1];
                }
            }
            if (i > 0)
            {
                for (size_t j = 0; j < matrix[i].size(); j++)
                {
                    m_matrix[i][j] = m_matrix[i][j] + m_matrix[i - 1][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 < 0 || col1 < 0 || row2 >= (int)m_matrix.size() || col2 >= (int)m_matrix[0].size())
        {
            return 0;
        }
        int sum = m_matrix[row2][col2];
        if (row1 > 0) sum -= m_matrix[row1 - 1][col2];
        if (col1 > 0) sum -= m_matrix[row2][col1 - 1];
        if ((row1 > 0) && (col1 > 0))
        {
            sum += m_matrix[row1 - 1][col1 - 1];
        }
        return sum;
    }
};

/// <summary>
/// Leet code #308. Range Sum Query 2D - Mutable    
/// 
/// Given a 2D matrix matrix, find the sum of the elements inside the rectangle 
/// defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
///
/// Range Sum Query 2D
/// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and 
/// (row2, col2) = (4, 3), which contains sum = 8. 
/// Example:
/// Given matrix = 
/// [
///   [3, 0, 1, 4, 2],
///   [5, 6, 3, 2, 1],
///   [1, 2, 0, 1, 5],
///   [4, 1, 0, 1, 7],
///   [1, 0, 3, 0, 5]
/// ]
/// sumRegion(2, 1, 4, 3) -> 8
/// update(3, 2, 2)
/// sumRegion(2, 1, 4, 3) -> 10
/// Note:
/// 1.The matrix is only modifiable by the update function.
/// 2.You may assume the number of calls to update and sumRegion function is distributed evenly.
/// 3.You may assume that row1 ≤ row2 and col1 ≤ col2.
/// </summary>
class NumMatrixMutable
{
private:
    vector<vector<int>> m_matrix;
    int sum(int i, int j)
    {
        int sum = 0;
        int row = i + 1;
        while (row != 0)
        {
            int col = j + 1;
            while (col != 0)
            {
                sum += m_matrix[row][col];
                col -= (col & -col);
            }
            row -= (row & -row);
        }
        return sum;
    }

    void add(int i, int j, int value)
    {
        int row = i + 1;
        while (row < (int)m_matrix.size())
        {
            int col = j + 1;
            while (col < (int)m_matrix[row].size())
            {
                m_matrix[row][col] += value;
                col += (col & -col);
            }
            row += (row & -row);
        }
    }

public:
    NumMatrixMutable(vector<vector<int>> matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return;
        m_matrix = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                add(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val)
    {
        int old_val = sumRegion(row, col, row, col);
        val = val - old_val;
        add(row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 < 0 || col1 < 0 || row2 >= (int)m_matrix.size() || col2 >= (int)m_matrix[0].size())
        {
            return 0;
        }
        int value = sum(row2, col2);
        if (row1 > 0) value -= sum(row1 - 1, col2);
        if (col1 > 0) value -= sum(row2, col1 - 1);
        if ((row1 > 0) && (col1 > 0))
        {
            value += sum(row1 - 1, col1 - 1);
        }
        return value;
    }
};

/// <summary>
/// Leet code #225. Implement Stack using Queues  
/// Implement the following operations of a stack using queues.
/// push(x) -- Push element x onto stack
/// pop() -- Removes the element on top of the stack.
/// top() -- Get the top element. 
/// empty() -- Return whether the stack is empty. 
/// Notes:
/// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
/// Depending on your language, queue may not be supported natively. 
/// You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
/// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack)
/// </summary>
class StackByQueue
{
private:
    queue<int> my_queue;
public:
    /// <summary>
    /// push(x) -- Push element x onto stack. 
    /// </summary>
    void push(int x)
    {
        my_queue.push(x);
    };
    /// <summary>
    ///  pop() -- Removes the element on top of the stack. 
    /// </summary>
    void pop()
    {
        for (size_t i = 0; i < my_queue.size() - 1; i++)
        {
            int x = my_queue.front();
            my_queue.pop();
            my_queue.push(x);
        }
        my_queue.pop();
    };
    /// <summary>
    /// top() -- Get the top element. 
    /// </summary>
    int top()
    {
        int value = 0;
        for (size_t i = 0; i < my_queue.size(); i++)
        {
            value = my_queue.front();
            my_queue.pop();
            my_queue.push(value);
        }
        return value;
    }
    /// <summary>
    /// empty() -- Return whether the stack is empty. 
    /// </summary>
    bool empty()
    {
        return my_queue.empty();
    }
};

/// <summary>
/// Leet Code 232. Implement Queue using Stacks
/// 
/// Easy
///
/// Implement a first in first out (FIFO) queue using only two stacks. 
/// The implemented queue should support all the functions of a normal 
/// queue (push, peek, pop, and empty).
///
/// Implement the MyQueue class:
///
/// void push(int x) Pushes element x to the back of the queue.
/// int pop() Removes the element from the front of the queue and 
/// returns it.
/// int peek() Returns the element at the front of the queue.
/// boolean empty() Returns true if the queue is empty, false otherwise. 
/// Notes:
/// You must use only standard operations of a stack, which means only 
/// push to top, peek/pop from top, size, and is empty operations are 
/// valid.
/// Depending on your language, the stack may not be supported natively. 
/// You may simulate a stack using a list or deque (double-ended queue) 
/// as long as you use only a stack's standard operations.
///
/// Example 1:
/// Input
/// ["MyQueue", "push", "push", "peek", "pop", "empty"]
/// [[], [1], [2], [], [], []]
/// Output
/// [null, null, null, 1, 1, false]
///
/// Explanation
/// MyQueue myQueue = new MyQueue();
/// myQueue.push(1); // queue is: [1]
/// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
/// myQueue.peek(); // return 1
/// myQueue.pop(); // return 1, queue is [2]
/// myQueue.empty(); // return false
///
/// Constraints:
/// 1. 1 <= x <= 9
/// 2. At most 100 calls will be made to push, pop, peek, and empty.
/// 3. All the calls to pop and peek are valid.
///
/// Follow-up: Can you implement the queue such that each operation is 
/// amortized O(1) time complexity? In other words, performing n operations 
/// will take overall O(n) time even if one of those operations may take 
/// longer.
/// </summary>
class QueueByStack
{
private:
    stack<int> in_stack;
    stack<int> out_stack;
public:
    /// <summary>
    /// push(x) -- Push element x to the back of queue. 
    /// </summary>
    void push(int x)
    {
        in_stack.push(x);
    };
    /// <summary>
    ///  pop() -- Removes the element from in front of queue. 
    /// </summary>
    void pop()
    {
        if (out_stack.empty())
        {
            size_t size = in_stack.size();
            for (size_t i = 0; i < size; i++)
            {
                int x = in_stack.top();
                in_stack.pop();
                out_stack.push(x);
            }
        }
        if (!out_stack.empty())
        {
            out_stack.pop();
        }
    };

    /// <summary>
    /// peek() -- Get the front element. 
    /// </summary>
    int peek()
    {
        int val = 0;
        if (out_stack.empty())
        {
            size_t size = in_stack.size();
            for (size_t i = 0; i < size; i++)
            {
                int x = in_stack.top();
                in_stack.pop();
                out_stack.push(x);
            }
        }
        if (!out_stack.empty())
        {
            val = out_stack.top();
        }
        return val;
    }

    /// <summary>
    /// empty() -- Return whether the queue is empty. 
    /// </summary>
    bool empty()
    {
        return (in_stack.empty() && out_stack.empty());
    }
};

/// <summary>
/// Leet code #1095. Find in Mountain Array
/// 
/// You may recall that an array A is a mountain array if and only if:
/// A.length >= 3
/// There exists some i with 0 < i < A.length - 1 such that:
/// A[0] < A[1] < ... A[i-1] < A[i]
/// A[i] > A[i+1] > ... > A[A.length - 1]
/// Given a mountain array mountainArr, return the minimum index such that 
/// mountainArr.get(index) == target.  If such an index doesn't exist, 
/// return -1.
///
/// You can't access the mountain array directly.  You may only access the 
/// array using a MountainArray interface:
///
/// MountainArray.get(k) returns the element of the array at index k 
/// (0-indexed).
/// MountainArray.length() returns the length of the array.
/// Submissions making more than 100 calls to MountainArray.get will be 
/// judged Wrong Answer.  Also, any solutions that attempt to circumvent 
/// the judge will result in disqualification.
///
/// Example 1:
/// 
/// Input: array = [1,2,3,4,5,3,1], target = 3
/// Output: 2
/// Explanation: 3 exists in the array, at index=2 and index=5. Return 
/// the minimum index, which is 2.
/// 
/// Example 2:
///
/// Input: array = [0,1,2,4,2,1], target = 3
/// Output: -1
/// Explanation: 3 does not exist in the array, so we return -1.
/// 
/// Constraints:
/// 1. 3 <= mountain_arr.length() <= 10000
/// 2. 0 <= target <= 10^9
/// 3. 0 <= mountain_arr.get(index) <= 10^9
/// </summary>
class MountainArray
{
private:
    vector<int> m_array;
    int length()
    {
        return m_array.size();
    }
    int get(int k)
    {
        return m_array[k];
    }

public:
    MountainArray()
    {
    }

    MountainArray(vector<int>& a)
    {
        m_array = a;
    }

    int findInMountainArray(int target, MountainArray& mountainArr, int first, int last)
    {
        int result = -1;
        if (first == last)
        {
            if (mountainArr.get(first) == target) result = first;
        }
        else if (first + 1 == last)
        {
            if (mountainArr.get(first) == target) result = first;
            else if (mountainArr.get(last) == target) result = last;
        }
        else
        {
            int mid = first + (last - first) / 2;
            if (mountainArr.get(mid - 1) < mountainArr.get(mid) &&
                mountainArr.get(mid) < mountainArr.get(mid + 1))
            {
                if (target <= mountainArr.get(mid))
                {
                    result = findInMountainArray(target, mountainArr, first, mid);
                }
                if (result == -1)
                {
                    result = findInMountainArray(target, mountainArr, mid + 1, last);
                }
            }
            else if (mountainArr.get(mid - 1) > mountainArr.get(mid) &&
                mountainArr.get(mid) > mountainArr.get(mid + 1))
            {
                result = findInMountainArray(target, mountainArr, first, mid);
                if (result == -1)
                {
                    if (target <= mountainArr.get(mid + 1))
                    {
                        result = findInMountainArray(target, mountainArr, mid + 1, last);
                    }
                }
            }
            else
            {
                if (target <= mountainArr.get(mid))
                {
                    result = findInMountainArray(target, mountainArr, first, mid);
                }
                if (result == -1)
                {
                    if (target <= mountainArr.get(mid + 1))
                    {
                        result = findInMountainArray(target, mountainArr, mid + 1, last);
                    }
                }
            }
        }
        return result;
    }

    int findInMountainArray(int target, MountainArray& mountainArr)
    {
        int first = 0;
        int last = mountainArr.length() - 1;
        int result = findInMountainArray(target, mountainArr, first, last);
        return result;
    }
};

/// <summary>
/// Leet code #901. Online Stock Span 
/// 
/// Write a class StockSpanner which collects daily price quotes for some 
/// stock, and returns the span of that stock's price for the current day.
///
/// The span of the stock's price today is defined as the maximum number of 
/// consecutive days (starting from today and going backwards) for which the 
/// price of the stock was less than or equal to today's price.
///
/// For example, if the price of a stock over the next 7 days were [100, 80, 
/// 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
///
/// Example 1:
///
/// Input: ["StockSpanner","next","next","next","next","next","next","next"], 
/// [[],[100],[80],[60],[70],[60],[75],[85]]
/// Output: [null,1,1,1,2,1,4,6]
/// Explanation: 
/// First, S = StockSpanner() is initialized.  Then:
/// S.next(100) is called and returns 1,
/// S.next(80) is called and returns 1,
/// S.next(60) is called and returns 1,
/// S.next(70) is called and returns 2,
/// S.next(60) is called and returns 1,
/// S.next(75) is called and returns 4,
/// S.next(85) is called and returns 6.
///
/// Note that (for example) S.next(75) returned 4, because the last 4 prices
/// (including today's price of 75) were less than or equal to today's price.
/// 
/// 
/// Note:
///
/// 1. Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
/// 2. There will be at most 10000 calls to StockSpanner.next per test case.
/// 3. There will be at most 150000 calls to StockSpanner.next across all test 
///    cases.
/// 4. The total time limit for this problem has been reduced by 75% for C++, 
///    and 50% for all other languages.
/// </summary>
class StockSpanner
{
private:
    vector<pair<int, int>> m_prices;
public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int result = 1;
        while (!m_prices.empty())
        {
            pair<int, int> previous = m_prices.back();
            if (previous.first > price)
            {
                break;
            }
            m_prices.pop_back();
            result += previous.second;
        }
        m_prices.push_back(make_pair(price, result));

        return result;
    }
};

/// <summary>
/// Leet code #460. LFU Cache
/// Design and implement a data structure for Least Frequently 
/// Used (LFU) cache. It should support the following operations: get and put. 
///
/// get(key) - Get the value (will always be positive) of the key if the key 
///            exists in the cache, otherwise return -1.
/// put(key, value) - Set or insert the value if the key is not already present. 
///                   When the cache reaches its capacity, it should invalidate 
///                   the least frequently used item before inserting a new 
///                   item. For the purpose of this problem, when there is a 
///                   tie (i.e., two or more keys that have the same frequency), 
///                   the least recently used key would be evicted. 
///
/// Follow up:
/// Could you do both operations in O(1) time complexity?
/// Example: 
/// LFUCache cache = new LFUCache( 2 /* capacity */ );
/// cache.put(1, 1);
/// cache.put(2, 2);
/// cache.get(1);       // returns 1
/// cache.put(3, 3);    // evicts key 2
/// cache.get(2);       // returns -1 (not found)
/// cache.get(3);       // returns 3.
/// cache.put(4, 4);    // evicts key 1.
/// cache.get(1);       // returns -1 (not found)
/// cache.get(3);       // returns 3
/// cache.get(4);       // returns 4
/// </summary>
class LFUCache
{
private:
    size_t m_capacity;
    int m_minFreq;
    // map key to the frequency list position
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> m_keyMap;
    // map frequency to the value list
    unordered_map<int, list<pair<int, int>>> m_freqMap;
public:
    LFUCache(int capacity)
    {
        m_capacity = capacity;
        m_minFreq = 0;
    }

    int get(int key)
    {
        if (m_keyMap.count(key) == 0)
        {
            return -1;
        }
        pair<int, list<pair<int, int>>::iterator> freq_itr = m_keyMap[key];
        int frequency = freq_itr.first;
        list<pair<int, int>>::iterator key_val_itr = freq_itr.second;
        pair<int, int> key_val = *key_val_itr;
        // key_val_itr become invalid
        m_freqMap[frequency].erase(key_val_itr);
        if (m_freqMap[frequency].empty())
        {
            m_freqMap.erase(frequency);
            if (m_minFreq == frequency) m_minFreq++;
        }
        frequency++;
        m_freqMap[frequency].push_front(key_val);
        // new key value pair iterator
        key_val_itr = m_freqMap[frequency].begin();
        // assign back to kay map
        m_keyMap[key] = make_pair(frequency, key_val_itr);
        return key_val.second;
    }

    void put(int key, int value)
    {
        if (m_capacity == 0) return;
        list<pair<int, int>>::iterator key_val_itr;
        if (get(key) != -1)
        {
            key_val_itr = m_keyMap[key].second;
            key_val_itr->second = value;
        }
        else
        {
            if (m_keyMap.size() == m_capacity)
            {
                // erase LFU key from frequency map
                pair<int, int> key_val = m_freqMap[m_minFreq].back();
                m_freqMap[m_minFreq].pop_back();
                if (m_freqMap[m_minFreq].empty())
                {
                    m_freqMap.erase(m_minFreq);
                }
                // erase LFU key from key map
                m_keyMap.erase(key_val.first);
            }
            m_minFreq = 1;
            m_freqMap[m_minFreq].push_front(make_pair(key, value));
            // new key value pair iterator
            key_val_itr = m_freqMap[m_minFreq].begin();
            // assign back to kay map
            m_keyMap[key] = make_pair(m_minFreq, key_val_itr);
        }
    }
};

/// <summary>
/// Leet code #900. RLE Iterator 
/// 
/// Write an iterator that iterates through a run-length encoded sequence.
///
/// The iterator is initialized by RLEIterator(int[] A), where A is a 
/// run-length encoding of some sequence.  More specifically, for all even i, 
/// A[i] tells us the number of times that the non-negative integer value 
/// A[i+1] is repeated in the sequence.
///
/// The iterator supports one function: next(int n), which exhausts the next 
/// n elements (n >= 1) and returns the last element exhausted in this way.  
/// If there is no element left to exhaust, next returns -1 instead.
/// 
/// For example, we start with A = [3,8,0,9,2,5], which is a run-length 
/// encoding of the sequence [8,8,8,5,5].  This is because the sequence 
/// can be read as "three eights, zero nines, two fives".
///
/// Example 1:
/// Input: ["RLEIterator","next","next","next","next"], [[[3,8,0,9,2,5]],
///         [2],[1],[1],[2]]
/// Output: [null,8,8,5,-1]
/// Explanation: 
/// RLEIterator is initialized with RLEIterator([3,8,0,9,2,5]).
/// This maps to the sequence [8,8,8,5,5].
/// RLEIterator.next is then called 4 times:
///
/// .next(2) exhausts 2 terms of the sequence, returning 8.  The remaining 
/// sequence is now [8, 5, 5].
/// 
/// .next(1) exhausts 1 term of the sequence, returning 8.  The remaining 
/// sequence is now [5, 5].
///
/// .next(1) exhausts 1 term of the sequence, returning 5.  The remaining 
/// sequence is now [5].
///
/// .next(2) exhausts 2 terms, returning -1.  This is because the first term 
/// exhausted was 5,
/// but the second term did not exist.  Since the last term exhausted does not 
/// exist, we return -1.
///
/// Note:
///
/// 1. 0 <= A.length <= 1000
/// 2. A.length is an even integer.
/// 3. 0 <= A[i] <= 10^9
/// 4. There are at most 1000 calls to RLEIterator.next(int n) per test case.
/// 5. Each call to RLEIterator.next(int n) will have 1 <= n <= 10^9.
/// </summary>
class RLEIterator
{
private:
    int m_index;
    int m_offset;
    vector<pair<int, int>> m_data;
public:
    RLEIterator(vector<int> A)
    {
        m_index = 0;
        m_offset = 0;
        for (size_t i = 0; i < A.size(); i += 2)
        {
            m_data.push_back(make_pair(A[i], A[i + 1]));
        }
    }

    int next(int n)
    {
        int result = 0;
        while (n > 0)
        {
            if (m_index == m_data.size())
            {
                result = -1;
                break;
            }
            else if (m_data[m_index].first - m_offset < n)
            {
                n -= (m_data[m_index].first - m_offset);
                m_offset = 0;
                m_index++;
            }
            else if (m_data[m_index].first - m_offset == n)
            {
                n -= (m_data[m_index].first - m_offset);
                result = m_data[m_index].second;
                m_offset = 0;
                m_index++;
                break;
            }
            else
            {
                m_offset += n;
                result = m_data[m_index].second;
                break;
            }
        }
        return result;
    }
};

/// <summary>
/// Leet code #1146. Snapshot Array
/// 
/// Implement a SnapshotArray that supports the following interface:
///
/// SnapshotArray(int length) initializes an array-like data structure 
/// with the given length.  Initially, each element equals 0.
/// void set(index, val) sets the element at the given index to be equal 
/// to val.
/// int snap() takes a snapshot of the array and returns the snap_id: 
/// the total number of times we called snap() minus 1.
/// int get(index, snap_id) returns the value at the given index, at the 
/// time we took the snapshot with the given snap_id
/// 
///
/// Example 1:
/// Input: ["SnapshotArray","set","snap","set","get"]
/// [[3],[0,5],[],[0,6],[0,0]]
/// Output: [null,null,0,null,5]
/// Explanation: 
/// // set the length to be 3
/// SnapshotArray snapshotArr = new SnapshotArray(3); 
/// snapshotArr.set(0,5);  // Set array[0] = 5
/// snapshotArr.snap();  // Take a snapshot, return snap_id = 0
/// snapshotArr.set(0,6);
/// // Get the value of array[0] with snap_id = 0, return 5
/// snapshotArr.get(0,0);  
/// 
/// Constraints:
/// 1. 1 <= length <= 50000
/// 2. At most 50000 calls will be made to set, snap, and get.
/// 3. 0 <= index < length
/// 4. 0 <= snap_id < (the total number of times we call snap())
/// 5. 0 <= val <= 10^9
/// </summary>
class SnapshotArray 
{
private:
    vector<map<int, int>> m_arr;
    int snapshot_id;
public:
    SnapshotArray(int length) 
    {
        snapshot_id = 0;
        m_arr = vector<map<int, int>>(length);
    }

    void set(int index, int val) 
    {
        m_arr[index][-snapshot_id] = val;
    }

    int snap() 
    {
        int result = snapshot_id;
        snapshot_id++;
        return result;
    }

    int get(int index, int snap_id) 
    {
        auto itr = m_arr[index].lower_bound(-snap_id);

        return itr->second;
    }
};

/// <summary>
/// Leet code #1157. Online Majority Element In Subarray
/// 
/// Implementing the class MajorityChecker, which has the following API:
/// 1. MajorityChecker(int[] arr) constructs an instance of MajorityChecker 
///    with the given array arr;
/// 2. int query(int left, int right, int threshold) has arguments such 
///    that:
///    0 <= left <= right < arr.length representing a subarray of arr;
///    2 * threshold > right - left + 1, ie. the threshold is always a 
///    strict majority of the length of the subarray
/// Each query(...) returns the element in arr[left], arr[left+1], ..., 
/// arr[right] that occurs at least threshold times, or -1 if no such 
/// element exists.
/// 
/// Example:
/// 1. MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
///    majorityChecker.query(0,5,4); // returns 1
///    majorityChecker.query(0,3,3); // returns -1
///    majorityChecker.query(2,3,2); // returns 2
/// 
/// Constraints:
/// 1. 1 <= arr.length <= 20000
/// 2. 1 <= arr[i] <= 20000
/// 3. For each query, 0 <= left <= right < len(arr)
/// 4. For each query, 2 * threshold > right - left + 1
/// 5. The number of queries is at most 10000
/// </summary>
class MajorityChecker 
{
private:
    vector<vector<int>> m_pos;
    vector<int> m_arr;

public:
    MajorityChecker(vector<int>& arr) 
    {
        m_arr = arr;
        m_pos = vector<vector<int>>(20000, vector<int>());
        for (size_t i = 0; i < arr.size(); i++)
        {
            m_pos[arr[i] - 1].push_back(i);
        }
        srand((unsigned int)time(NULL));
    }

    int query(int left, int right, int threshold) 
    {
        for (size_t i = 0; i < 20; i++)
        {
            int index = rand() % (right - left + 1) + left;
            int num = m_arr[index] - 1;
            int count = upper_bound(m_pos[num].begin(), m_pos[num].end(), right) -
                lower_bound(m_pos[num].begin(), m_pos[num].end(), left);
            if (count >= threshold) return num + 1;
        }
        return -1;
    }
};

/// <summary>
/// Leet code #211. Add and Search Word - Data structure design            
/// Design a data structure that supports the following two operations:
/// void addWord(word)
/// bool search(word)
/// </summary>
struct DictNode
{
    string word;
    vector<DictNode*> char_map;

    /// <summary>
    /// Constructor of an empty DictNode
    /// </summary>
    /// <returns></returns>
    DictNode() 
    { 
        char_map = vector<DictNode*>(26);
    };

    /// <summary>
    /// Destructor of an DictNode
    /// </summary>
    /// <returns></returns>
    ~DictNode()
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (char_map[i] != nullptr)
            {
                delete char_map[i];
            }
            char_map[i] = nullptr;
        }
    }

    /// <summary>
    /// add word into the DictNode.
    /// </summary>
    /// <param name="word>The word</param>
    /// <returns></returns>
    void addWord(string word, int i)
    {
        if (i == word.size())
        {
            this->word = word;
            return;
        }
        DictNode* node;
        if (char_map[word[i] - 'a'] == nullptr)
        {
            node = new DictNode();
            char_map[word[i] - 'a'] = node;
        }
        else
        {
            node = char_map[word[i]-'a'];
        }
        node->addWord(word, i + 1);
    }

    /// <summary>
    /// get all the next level nodes
    /// </summary>
    /// <param name="word>The word</param>
    /// <returns></returns>
    vector<DictNode*> getNodes()
    {
        vector<DictNode*> result;
        for (int i = 0; i < 26; i++)
        {
            if (char_map[i] != nullptr)
            {
                result.push_back(char_map[i]);
            }
        }
        return result;
    }

    /// <summary>
    /// search a word in the TrieTree.
    /// </summary>
    /// <param name="word">The word</param>
    /// <returns>true, if found</returns>
    bool search(string word, int i)
    {
        if (i == word.size())
        {
            if (this->word.size() == word.size()) return true;
            else return false;
        }
        if (word[i] != '.')
        {
            if (char_map[word[i] - 'a'] == nullptr)
            {
                return false;
            }
            else
            {
                DictNode* node = char_map[word[i] - 'a'];
                return node->search(word, i + 1);
            }
        }
        else
        {
            vector<DictNode*> node_list = getNodes();
            for (DictNode* node : node_list)
            {
                if (node->search(word, i + 1)) return true;
            }
            return false;
        }
    }
};

/// <summary>
/// Leet code #211. Add and Search Word - Data structure design            
/// Design a data structure that supports the following two operations:
/// void addWord(word)
/// bool search(word)
///
/// search(word) can search a literal word or a regular expression string containing only 
/// letters a-z or .. A . means it can represent any one letter.
///
/// For example:
/// addWord("bad")
/// addWord("dad")
/// addWord("mad")
/// search("pad") -> false
/// search("bad") -> true
/// search(".ad") -> true
/// search("b..") -> true
///
/// Note:
/// You may assume that all words are consist of lowercase letters a-z. 
///
/// click to show hint.
/// You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first. 
/// Your WordDictionary object will be instantiated and called as such:
/// WordDictionary wordDictionary;
/// wordDictionary.addWord("word");
/// wordDictionary.search("pattern");
/// </summary>
class WordDictionary
{
private:
    bool m_end;
    vector<WordDictionary*> m_children;
public:
    /// <summary>
    /// Constructor an empty WordDictionary
    /// </summary>
    /// <returns></returns>
    WordDictionary()
    {
        m_end = false;
        m_children = vector<WordDictionary*>(26, nullptr);
    };

    /// <summary>
    /// Destructor of an WordDictionary
    /// </summary>
    /// <returns></returns>
    ~WordDictionary()
    {
        // Leet code does not like my destructor so it cause TLE.
        //for (int i = 0; i < 26; i++)
        //{
        //    if (m_children[i] == nullptr) delete m_children[i];
        //}
    }

    /// <summary>
    /// Adds a word into the data structure.
    /// </summary>
    /// <param name="word>The word</param>
    /// <returns></returns>
    void addWord(string word, int p = 0)
    {
        if (p == word.size())
        {
            m_end = true;
            return;
        }
        if (m_children[word[p] - 'a'] == nullptr)
        {
            m_children[word[p] - 'a'] = new WordDictionary();
        }
        WordDictionary * next = m_children[word[p] - 'a'];
        next->addWord(word, p + 1);
    }

    /// <summary>
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    /// </summary>
    /// <param name="word">The word</param>
    /// <returns>true, if found</returns>
    bool search(string word, int p = 0)
    {
        if (p == word.size())
        {
            return m_end;
        }
        if (word[p] != '.')
        {
            if (m_children[word[p] - 'a'] == nullptr)
            {
                return false;
            }
            else
            {
                return m_children[word[p] - 'a']->search(word, p + 1);
            }
        }
        else
        {
            bool ret = false;
            for (int i = 0; i < 26; i++)
            {
                if (m_children[i] != nullptr)
                {
                    ret = m_children[i]->search(word, p + 1);
                }
                if (ret == true) break;
            }
            return ret;
        }
    }
};

/// <summary>
/// Leet code #729. My Calendar I      
/// 
/// Implement a MyCalendar class to store your events. A new event can be 
/// added if adding the event will not cause a double booking.
///
/// Your class will have the method, book(int start, int end). Formally, 
/// this represents a booking on the half open interval [start, end), the 
/// range of real numbers x such that start <= x < end.
///
/// A double booking happens when two events have some non-empty 
/// intersection (ie., there is some time that is common to both events.)
///
/// For each call to the method MyCalendar.book, return true if the event 
/// can be added to the calendar successfully without causing a double 
/// booking. Otherwise, return false and do not add the event to the 
/// calendar.
///
/// Your class will be called like this: MyCalendar cal = new MyCalendar(); 
/// MyCalendar.book(start, end)
///
/// Example 1:
/// MyCalendar();
/// MyCalendar.book(10, 20); // returns true
/// MyCalendar.book(15, 25); // returns false
/// MyCalendar.book(20, 30); // returns true
/// Explanation: 
/// The first event can be booked.  The second can't because time 15 is 
/// already booked by another event.
/// The third event can be booked, as the first event takes every time 
/// less than 20, but not including 20.
/// Note:
///
/// 1. The number of calls to MyCalendar.book per test case will be at 
///    most 1000.
/// 2. In calls to MyCalendar.book(start, end), start and end are integers 
///    in the range [0, 10^9].
/// </summary>
class MyCalendar {
private:
    map<int, int> m_TimeMap;
    map<int, int>::iterator getLocation(int time_stamp)
    {
        auto itr = m_TimeMap.lower_bound(time_stamp);
        if (itr == m_TimeMap.end() || time_stamp < itr->first)
        {
            itr--;
        }
        return itr;
    };
public:
    MyCalendar()
    {
        m_TimeMap[0] = 0;
    }

    bool book(int start, int end)
    {
        auto itr = getLocation(start);
        while (itr != m_TimeMap.end() && itr->first < end)
        {
            if (itr->second == 1) return false;
            itr++;
        }

        itr = getLocation(end);
        m_TimeMap[end] = itr->second;

        itr = getLocation(start);
        m_TimeMap[start] = itr->second + 1;


        itr = m_TimeMap.find(start);
        itr++;
        while (itr != m_TimeMap.end() && itr->first < end)
        {
            m_TimeMap.erase(itr++);
        }
        return true;
    }
};

/// <summary>
/// Leet code #731. My Calendar II      
/// 
/// Implement a MyCalendarTwo class to store your events. A new event can 
/// be added if adding the event will not cause a triple booking.
///
/// Your class will have one method, book(int start, int end). Formally, 
/// this represents a booking on the half open interval [start, end), the 
/// range of real numbers x such that start <= x < end.
///
/// A triple booking happens when three events have some non-empty 
/// intersection (ie., there is some time that is common to all 3 events.)
///
/// For each call to the method MyCalendar.book, return true if the event 
/// can be added to the calendar successfully without causing a triple 
/// booking. Otherwise, return false and do not add the event to the 
/// calendar.
///
/// Your class will be called like this: 
/// MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
/// Example 1:
/// MyCalendar();
/// MyCalendar.book(10, 20); // returns true
/// MyCalendar.book(50, 60); // returns true
/// MyCalendar.book(10, 40); // returns true
/// MyCalendar.book(5, 15);  // returns false
/// MyCalendar.book(5, 10);  // returns true
/// MyCalendar.book(25, 55); // returns true
/// Explanation: 
/// The first two events can be booked.  The third event can be double 
/// booked.
/// The fourth event (5, 15) can't be booked, because it would result 
/// in a triple booking.
/// The fifth event (5, 10) can be booked, as it does not use time 10 
/// which is already double booked.
/// The sixth event (25, 55) can be booked, as the time in [25, 40) will 
/// be double booked with the third event;
/// the time [40, 50) will be single booked, and the time [50, 55) will be 
/// double booked with the second event.
/// Note:
///
/// 1. The number of calls to MyCalendar.book per test case will be at most 
/// 1000.
/// 2. In calls to MyCalendar.book(start, end), start and end are integers in 
/// the range [0, 10^9].
/// </summary>
class MyCalendarTwo {
private:
    map<int, int> m_TimeMap;
    // fine the location for the point in space which is less than or equal 
    // to the input point, the input point may start with the existing value 
    map<int, int>::iterator getLocation(int time_stamp)
    {
        auto itr = m_TimeMap.lower_bound(time_stamp);
        if (itr == m_TimeMap.end() || time_stamp < itr->first)
        {
            itr--;
        }
        return itr;
    };
public:
    MyCalendarTwo()
    {
        m_TimeMap[0] = 0;
    }
    bool book(int start, int end)
    {

        auto itr = getLocation(start);
        while (itr != m_TimeMap.end() && itr->first < end)
        {
            if (itr->second == 2) return false;
            itr++;
        }

        itr = getLocation(end);
        m_TimeMap[end] = itr->second;

        itr = getLocation(start);
        m_TimeMap[start] = itr->second + 1;

        itr = m_TimeMap.find(start);
        itr++;
        while (itr != m_TimeMap.end() && itr->first < end)
        {
            itr->second++;
            itr++;
        }
        return true;
    }
};

/// <summary>
/// Leet code #732. My Calendar III
///
/// Implement a MyCalendarThree class to store your events. A new event can
/// always be added.
///
/// Your class will have one method, book(int start, int end). Formally, 
/// this represents a booking on the half open interval [start, end), the 
/// range of real numbers x such that start <= x < end.
///
/// A K-booking happens when K events have some non-empty intersection 
/// (ie., there is some time that is common to all K events.)
/// 
/// For each call to the method MyCalendar.book, return an integer K 
/// representing the largest integer such that there exists a K-booking 
/// in the calendar.
///
/// Your class will be called like this: MyCalendarThree cal = new 
/// MyCalendarThree(); MyCalendarThree.book(start, end)
///
/// Example 1:
/// MyCalendarThree();
/// MyCalendarThree.book(10, 20); // returns 1
/// MyCalendarThree.book(50, 60); // returns 1
/// MyCalendarThree.book(10, 40); // returns 2
/// MyCalendarThree.book(5, 15); // returns 3
/// MyCalendarThree.book(5, 10); // returns 3
/// MyCalendarThree.book(25, 55); // returns 3
/// Explanation: 
/// The first two events can be booked and are disjoint, so the maximum 
/// K-booking is a 1-booking.
/// The third event [10, 40) intersects the first event, and the maximum 
/// K-booking is a 2-booking.
/// The remaining events cause the maximum K-booking to be only a 
/// 3-booking.
/// Note that the last event locally causes a 2-booking, but the answer 
/// is still 3 because eg. [10, 20), [10, 40), and [5, 15) are still 
/// triple booked.
/// Note:
/// 
/// The number of calls to MyCalendarThree.book per test case will be at 
/// most 400.
/// In calls to MyCalendarThree.book(start, end), start and end are 
/// integers in the range [0, 10^9].
/// </summary>
class MyCalendarThree
{
private:
    int m_book;
    map<int, int> m_timemap;
 public:
    MyCalendarThree()
    {
        m_timemap[INT_MAX] = 0;
        m_book = 0;
    }

    int book(int start, int end)
    {
        auto itr = m_timemap.lower_bound(start);
        int prev = itr->second;
        while (itr->first < end)
        {
            // We track the layers before the point, 
            /// so we can not increase start point
            if (itr->first > start) itr->second++;
            m_book = max(m_book, itr->second);
            itr++;
        }
        m_timemap[start] = prev;
        // end point layer is determined by the layer before next point
        m_timemap[end] = itr->second + 1;
        // we can not use itr->second again, since it may already be increased 
        m_book = max(m_book, m_timemap[end]);
        return m_book;
    }
};

/// <summary>
/// Leet code #715. Range Module      
/// 
/// A Range Module is a module that tracks ranges of numbers. Your task is 
/// to design and implement the following interfaces in an efficient 
/// manner.
///
/// addRange(int left, int right) Adds the half-open interval 
/// [left, right), tracking every real number in that interval. Adding 
/// an interval that partially overlaps with currently tracked numbers 
/// should add any numbers in the interval [left, right) that are not 
/// already tracked.
/// queryRange(int left, int right) Returns true if and only if every real 
/// number in the interval [left, right) is currently being tracked.
/// removeRange(int left, int right) Stops tracking every real number 
/// currently being tracked in the interval [left, right).
///
/// Example 1:
/// addRange(10, 20): null
/// removeRange(14, 16): null
/// queryRange(10, 14): true (Every number in [10, 14) is being tracked)
/// queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) 
/// are not being tracked)
/// queryRange(16, 17): true (The number 16 in [16, 17) is still being 
/// tracked, despite the remove operation)
/// Note:
///
/// A half open interval [left, right) denotes all real numbers 
/// left <= x < right.
/// 0 < left < right < 10^9 in all calls to addRange, queryRange, 
/// removeRange.
/// The total number of calls to addRange in a single test case is at most 
/// 1000.
/// The total number of calls to queryRange in a single test case is at 
/// most 5000.
/// The total number of calls to removeRange in a single test case is at 
/// most 1000.
/// </summary>
class RangeModule
{
private:
    map<int, int> m_range;
public:
    RangeModule()
    {
        m_range[INT_MAX] = 0;
    }

    void addRange(int left, int right)
    {
        auto itr = m_range.lower_bound(left);
        int prev = itr->second;
        while (itr->first < right)
        {
            int val = itr->first;
            itr++;
            m_range.erase(val);
        }
        // we do not change start point because 
        // it means the status ahead of the point
        m_range[left] = prev;
        m_range[right] = 1;
    }

    void removeRange(int left, int right)
    {
        auto itr = m_range.lower_bound(left);
        int prev = itr->second;
        while (itr->first < right)
        {
            int val = itr->first;
            itr++;
            m_range.erase(val);
        }
        m_range[left] = prev;
        m_range[right] = 0;
    }

    bool queryRange(int left, int right)
    {
        auto itr = m_range.upper_bound(left);
        while (itr->first < right)
        {
            if (itr->second == 0) return false;
            itr++;
        }
        if (itr->second == 0) return false;
        else return true;
    }
};

/// <summary>
/// Leet code #855. Exam Room
/// 
/// In an exam room, there are N seats in a single row, numbered 
/// 0, 1, 2, ..., N-1.
///
/// When a student enters the room, they must sit in the seat that maximizes 
/// the distance to the closest person.  If there are multiple such seats, 
/// they sit in the seat with the lowest number.  (Also, if no one is in the 
/// room, then the student sits at seat number 0.)
///
/// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() 
/// returning an int representing what seat the student sat in, and 
/// ExamRoom.leave(int p) representing that the student in seat number p now 
/// leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have 
/// a student sitting in seat p.
///
/// Example 1:
/// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], 
/// [[10],[],[],[],[],[4],[]]
/// Output: [null,0,9,4,2,null,5]
/// Explanation:
/// ExamRoom(10) -> null
/// seat() -> 0, no one is in the room, then the student sits at seat number 0.
/// seat() -> 9, the student sits at the last seat number 9.
/// seat() -> 4, the student sits at the last seat number 4.
/// seat() -> 2, the student sits at the last seat number 2.
/// leave(4) -> null
/// seat()-> 5, the student​​​​​​​ sits at the last seat number 5.
/// Note:
/// 1 <= N <= 10^9
/// ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times 
/// across all test cases.
/// Calls to ExamRoom.leave(p) are guaranteed to have a student currently 
/// sitting in seat number p.
/// </summary>
class ExamRoom {
private:
    int m_Size;
    set<vector<int>, greater<vector<int>>> m_SeatSlot;
    set<int> m_StudentPositions;

    void insertSlot(int start, int end)
    {
        // no space
        if (start > end) return;

        vector<int> slot(3);
        if ((start == 0) || (end == m_Size - 1))
        {
            slot[0] = end - start;
        }
        else
        {
            slot[0] = (end - start) / 2;
        }
        slot[1] = 0 - start;
        slot[2] = 0 - end;
        m_SeatSlot.insert(slot);
    }

    void removeSlot(int start, int end)
    {
        // no space
        if (start > end) return;

        vector<int> slot(3);
        if ((start == 0) || (end == m_Size - 1))
        {
            slot[0] = end - start;
        }
        else
        {
            slot[0] = (end - start) / 2;
        }
        slot[1] = 0 - start;
        slot[2] = 0 - end;
        m_SeatSlot.erase(slot);
    }
public:
    ExamRoom(int N)
    {
        m_Size = N;
        insertSlot(0, N - 1);
    }

    int seat()
    {
        vector<int> slot = *m_SeatSlot.begin();
        m_SeatSlot.erase(m_SeatSlot.begin());
        int start = 0 - slot[1];
        int end = 0 - slot[2];
        int result;
        if (start == 0)
        {
            result = 0;
            insertSlot(start + 1, end);
        }
        else if (end == m_Size - 1)
        {
            result = m_Size - 1;
            insertSlot(start, end - 1);
        }
        else
        {
            result = (start + end) / 2;
            insertSlot(start, result - 1);
            insertSlot(result + 1, end);
        }
        m_StudentPositions.insert(result);
        return result;
    }

    void leave(int p)
    {
        auto pos = m_StudentPositions.find(p);
        int prev = 0, next = m_Size - 1;
        if (pos != m_StudentPositions.end())
        {
            if (pos != m_StudentPositions.begin())
            {
                auto prev_pos = pos;
                prev_pos--;
                prev = *prev_pos + 1;
            }

            auto next_pos = pos;
            next_pos++;
            if (next_pos != m_StudentPositions.end())
            {
                next = *next_pos - 1;
            }
        }
        m_StudentPositions.erase(p);
        removeSlot(prev, p - 1);
        removeSlot(p + 1, next);
        insertSlot(prev, next);
    }
};

/// <summary>
/// Leet code #710. Random Pick with Blacklist
/// 
/// Given a blacklist B containing unique integers from [0, N), write a 
/// function to return a uniform random integer from [0, N) which is NOT 
/// in B.
///
/// Optimize it such that it minimizes the call to system’s Math.random().
///
/// Note:
/// 1. 1 <= N <= 1000000000
/// 2. 0 <= B.length < min(100000, N)
/// 3. [0, N) does NOT include N. See interval notation.
///
/// Example 1:
/// Input: 
/// ["Solution","pick","pick","pick"]
/// [[1,[]],[],[],[]]
/// Output: [null,0,0,0]
///
/// Example 2:
/// Input: 
/// ["Solution","pick","pick","pick"]
/// [[2,[]],[],[],[]]
/// Output: [null,1,1,1]
///
/// Example 3:
/// Input: 
/// ["Solution","pick","pick","pick"]
/// [[3,[1]],[],[],[]]
/// Output: [null,0,0,2]
///
/// Example 4:
/// Input: 
/// ["Solution","pick","pick","pick"]
/// [[4,[2]],[],[],[]]
/// Output: [null,1,3,1]
/// Explanation of Input Syntax:
/// The input is two lists: the subroutines called and their arguments. 
/// Solution's constructor has two arguments, N and the blacklist B. pick has 
/// no arguments. Arguments are always wrapped with a list, even if there 
/// aren't any.
/// </summary>
class Solution
{
private:
    vector<pair<int, int>> m_Range;
    vector<int> m_Sum;
    unsigned int m_Size;
public:
    Solution(int N, vector<int> blacklist)
    {
        sort(blacklist.begin(), blacklist.end());
        int sum = 0;
        int first = 0;
        for (size_t i = 0; i <= blacklist.size(); i++)
        {
            int last;
            if (i == blacklist.size())
            {
                last = N;
            }
            else
            {
                last = blacklist[i];
            }
            if (first != last)
            {
                sum += last - first;
                m_Sum.push_back(sum);
                m_Range.push_back(make_pair(first, last));
            }
            first = last + 1;
        }
        m_Size = N - blacklist.size();
        srand((unsigned int)time(NULL));
    }

    int pick()
    {
        int random = rand() % m_Size;
        auto itr = upper_bound(m_Sum.begin(), m_Sum.end(), random);
        if (itr == m_Sum.end()) return -1;
        int index = itr - m_Sum.begin();
        int result = m_Range[index].second - (m_Sum[index] - random);
        return result;
    }
};

class SolutionII
{
private:
    unordered_map<int, int> m_BlackMap;
    unsigned int m_Size;
public:
    SolutionII(int N, vector<int> blacklist)
    {
        sort(blacklist.begin(), blacklist.end());
        for (size_t i = 0; i < blacklist.size(); i++)
        {
            m_BlackMap[blacklist[i]] = blacklist[i];
        }
        m_Size = N - blacklist.size();
        int last = N - 1;
        for (size_t i = 0; i < blacklist.size(); i++)
        {
            while (m_BlackMap.count(last) > 0) last--;
            m_BlackMap[blacklist[i]] = last;
            last--;
        }
        srand((unsigned int)time(NULL));
    }

    int pick()
    {
        int index = rand() % m_Size;
        if (m_BlackMap.count(index) > 0)
        {
            return m_BlackMap[index];
        }
        else
        {
            return index;
        }
    }
};

/// <summary>
/// Leet code #528. Random Pick with Weight
/// 
/// Given an array w of positive integers, where w[i] describes the weight 
/// of index i, write a function pickIndex which randomly picks an index 
/// in proportion to its weight.
///
/// Note:
/// 1. 1 <= w.length <= 10000
/// 2. 1 <= w[i] <= 10^5
/// 3. pickIndex will be called at most 10000 times.
///
/// Example 1:
/// Input: 
/// ["Solution","pickIndex"]
/// [[[1]],[]]
/// Output: [null,0]
///
/// Example 2:
///
/// Input: 
/// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex",
///  "pickIndex"]
/// [[[1,3]],[],[],[],[],[]]
/// Output: [null,0,1,1,1,0]
///
/// Explanation of Input Syntax:
///
/// The input is two lists: the subroutines called and their arguments. 
/// Solution's constructor has one argument, the array w. pickIndex has no 
/// arguments. Arguments are always wrapped with a list, even if there 
/// aren't any.
/// </summary>
class RandomWithWeight
{
private:
    vector<int> sum;
public:
    RandomWithWeight(vector<int> w)
    {
        sum = vector<int>(w.size());

        for (size_t i = 0; i < w.size(); i++)
        {
            sum[i] = (i > 0) ? sum[i - 1] + w[i] : w[i];
        }
        srand((unsigned int)time(0));
    }

    int pickIndex()
    {
        int value = rand() % sum[sum.size() - 1] + 1;
        auto itr = lower_bound(sum.begin(), sum.end(), value);
        int index = itr - sum.begin();
        return index;
    }
};

/// <summary>
/// Leet code #519. Random Flip Matrix
/// 
/// You are given the number of rows n_rows and number of columns n_cols 
/// of a 2D binary matrix where all values are initially 0. Write a 
/// function flip which chooses a 0 value uniformly at random, changes it 
/// to 1, and then returns the position [row.id, col.id] of that value. 
/// Also, write a function reset which sets all values back to 0. Try to 
/// minimize the number of calls to system's Math.random() and optimize 
/// the time and space complexity.
///
/// Note:
///
/// 1. 1 <= n_rows, n_cols <= 10000
/// 2. 0 <= row.id < n_rows and 0 <= col.id < n_cols
/// 3. flip will not be called when the matrix has no 0 values left.
/// 4. the total number of calls to flip and reset will not exceed 1000.
/// Example 1:
/// 
/// Input: 
/// ["Solution","flip","flip","flip","flip"]
/// [[2,3],[],[],[],[]]
/// Output: [null,[0,1],[1,2],[1,0],[1,1]]
///
/// Example 2:
///
/// Input: 
/// ["Solution","flip","flip","reset","flip"]
/// [[1,2],[],[],[],[]]
/// Output: [null,[0,0],[0,1],null,[0,0]]
///  
/// Explanation of Input Syntax:
/// The input is two lists: the subroutines called and their arguments. 
/// Solution's constructor has two arguments, n_rows and n_cols. flip and 
/// reset have no arguments. Arguments are always wrapped with a list, 
/// even if there aren't any.
/// </summary>
class RandomFlipMatrix
{
private:
    int rows;
    int cols;
    int size;
    vector<bitset<10000>> matrix;
    vector<int> row_slots;

public:
    RandomFlipMatrix(int n_rows, int n_cols)
    {
        rows = n_rows;
        cols = n_cols;
        reset();
        srand((unsigned int)time(0));
    }

    vector<int> flip()
    {
        vector<int> result;
        int index = rand() % size;
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            sum += row_slots[i];
            if (index >= sum) continue;
            int remaining = sum - index;
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i].test(j)) continue;
                remaining--;
                if (remaining == 0)
                {
                    result.push_back(i);
                    result.push_back(j);
                    matrix[i].set(j);
                    size--;
                    row_slots[i]--;
                    return result;
                }
            }
        }
        return result;
    }

    void reset()
    {
        matrix = vector<bitset<10000>>(rows);
        row_slots = vector<int>(rows, cols);
        size = rows * cols;
    }
};

/// <summary>
/// Leet code #478. Generate Random Point in a Circle
/// 
/// Given the radius and x-y positions of the center of a circle, write 
/// a function randPoint which generates a uniform random point in the 
/// circle.
///
/// Note:
///
/// 1. input and output values are in floating-point.
/// 2. radius and x-y position of the center of the circle is passed into 
///    the class constructor.
/// 3. a point on the circumference of the circle is considered to be in 
///   the circle.
/// 4. randPoint returns a size 2 array containing x-position and 
///    y-position of the random point, in that order.
///
/// Example 1:
/// Input: 
/// ["Solution","randPoint","randPoint","randPoint"]
/// [[1,0,0],[],[],[]]
/// 
/// Output: [null,[-0.72939,-0.65505],[-0.78502,-0.28626],
/// [-0.83119,-0.19803]]
///
/// Example 2:
/// Input: 
/// ["Solution","randPoint","randPoint","randPoint"]
/// [[10,5,-7.5],[],[],[]]
/// Output: [null,[11.52438,-8.33273],[2.46992,-16.21705],
/// [11.13430,-12.42337]]
/// Explanation of Input Syntax:
/// 
/// The input is two lists: the subroutines called and their arguments. 
/// Solution's constructor has three arguments, the radius, x-position 
/// of the center, and y-position of the center of the circle. randPoint 
/// has no arguments. Arguments are always wrapped with a list, even if 
/// there aren't any.
/// </summary>
class RandomCirclePoint
{
private:
    double m_radius;
    double m_x_center;
    double m_y_center;
    const double pi = 3.1415926;
public:
    RandomCirclePoint(double radius, double x_center, double y_center)
    {
        m_radius = radius;
        m_x_center = x_center;
        m_y_center = y_center;
        srand((unsigned int)time(0));
    }

    vector<double> randPoint()
    {
        double r = m_radius * sqrt(((double)rand() / (double)(RAND_MAX)));
        double angle = 2 * pi * ((double)rand() / (double)(RAND_MAX));
        double x = r * cos(angle) + m_x_center;
        double y = r * sin(angle) + m_y_center;
        return vector<double> {x, y};
    }
};

/// <summary>
/// Leet code #497. Random Point in Non-overlapping Rectangles
/// 
/// Given a list of non-overlapping axis-aligned rectangles rects, write 
/// a function pick which randomly and uniformily picks an integer point 
/// in the space covered by the rectangles.
///
/// Note:
///
/// An integer point is a point that has integer coordinates. 
/// A point on the perimeter of a rectangle is included in the space 
/// covered by the rectangles. 
/// ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the 
/// integer coordinates of the bottom-left corner, and [x2, y2] are the 
/// integer coordinates of the top-right corner.
/// length and width of each rectangle does not exceed 2000.
/// 1 <= rects.length <= 100
/// pick return a point as an array of integer coordinates [p_x, p_y]
/// pick is called at most 10000 times.
/// Example 1:
/// 
/// Input: 
/// ["Solution","pick","pick","pick"]
/// [[[[1,1,5,5]]],[],[],[]]
/// Output: 
/// [null,[4,1],[4,1],[3,3]]
/// Example 2:
///
/// Input: 
/// ["Solution","pick","pick","pick","pick","pick"]
/// [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
/// Output: 
/// [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
/// Explanation of Input Syntax:
/// 
/// The input is two lists: the subroutines called and their arguments. 
/// Solution's constructor has one argument, the array of rectangles 
/// rects. pick has no arguments. Arguments are always wrapped with a 
/// list, even if there aren't any.
/// </summary>
class RandomRectanglePoint
{
private:
    vector<vector<int>> m_rectangles;
    vector<int> m_sum;

public:
    RandomRectanglePoint(vector<vector<int>> rects)
    {
        for (size_t i = 0; i < rects.size(); i++)
        {
            m_rectangles.push_back(rects[i]);
            int area = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            if (m_sum.empty())
            {
                // we start from 0, so it is a point
                m_sum.push_back(area);
            }
            else
            {
                m_sum.push_back(m_sum.back() + area);
            }
        }
        srand((unsigned int)time(0));
    }

    vector<int> pick()
    {
        vector<int> result = { 0, 0 };
        if (m_sum.empty()) return result;
        int rand_num = rand() % m_sum.back() + 1;
        int index = lower_bound(m_sum.begin(), m_sum.end(), rand_num) - m_sum.begin();
        int remaining = (index == 0 ? rand_num : rand_num - m_sum[index - 1]);
        int x = m_rectangles[index][0] + (remaining - 1) % (m_rectangles[index][2] - m_rectangles[index][0] + 1);
        int y = m_rectangles[index][1] + (remaining - 1) / (m_rectangles[index][2] - m_rectangles[index][0] + 1);
        result = { x, y };
        return result;
    }
};

/// <summary>
/// Leet code #1166. Design File System
/// 
/// You are asked to design a file system which provides two functions:
/// create(path, value): Creates a new path and associates a value to it 
/// if possible and returns True. Returns False if the path already exists 
/// or its parent path doesn't exist.
/// get(path): Returns the value associated with a path or returns -1 if 
/// the path doesn't exist.
/// The format of a path is one or more concatenated strings of the 
/// form: / followed by one or more lowercase English letters. For 
/// example, /leetcode and /leetcode/problems are valid paths while an empty
/// string and / are not.
/// Implement the two functions.
/// Please refer to the examples for clarifications.
/// 
/// Example 1:
/// Input: 
/// ["FileSystem","create","get"]
/// [[],["/a",1],["/a"]]
/// Output: 
/// [null,true,1]
/// Explanation: 
/// FileSystem fileSystem = new FileSystem();
///
/// fileSystem.create("/a", 1); // return true
/// fileSystem.get("/a"); // return 1
///
/// Example 2:
/// Input: 
/// ["FileSystem","create","create","get","create","get"]
/// [[],["/leet",1],["/leet/code",2],["/leet/code"],["/c/d",1],["/c"]]
/// Output: 
/// [null,true,true,2,false,-1]
/// Explanation: 
/// FileSystem fileSystem = new FileSystem();
///
/// fileSystem.create("/leet", 1); // return true
/// fileSystem.create("/leet/code", 2); // return true
/// fileSystem.get("/leet/code"); // return 2
/// fileSystem.create("/c/d", 1); // return false because the parent 
/// path "/c" doesn't exist.
/// fileSystem.get("/c"); // return -1 because this path doesn't exist.
///  
/// Constraints:
/// 1. The number of calls to the two functions is less than or equal to 
///    10^4 in total.
/// 2. 2 <= path.length <= 100
/// 3. 1 <= value <= 10^9
/// </summary>
class FileSystemII 
{
private:
    unordered_map<string, int> m_dir;
public:
    FileSystemII() 
    {
    }

    bool create(string path, int value) 
    {
        string dir;
        while (!path.empty())
        {
            size_t pos = path.find("/", 1);
            if (pos == string::npos)
            {
                dir.append(path);
                path.clear();
                if (m_dir.count(dir) > 0) return false;
                m_dir[dir] = value;
                return true;
            }
            else
            {
                dir.append(path.substr(0, pos));
                path = path.substr(pos);
                if (m_dir.count(dir) == 0) return false;
            }
        }
        return false;
    }

    int get(string path) 
    {
        if (m_dir.count(path) == 0) return -1;
        return m_dir[path];
    }
};

/// <summary>
/// Leet code #1172. Dinner Plate Stacks
/// 
/// You have an infinite number of stacks arranged in a row and numbered 
/// (left to right) from 0, each of the stacks has the same maximum capacity.
/// Implement the DinnerPlates class:
/// DinnerPlates(int capacity) Initializes the object with the maximum 
/// capacity of the stacks.
/// void push(int val) pushes the given positive integer val into the 
/// leftmost stack with size less than capacity.
/// int pop() returns the value at the top of the rightmost non-empty 
/// stack and removes it from that stack, and returns -1 if all 
/// stacks are empty.
/// int popAtStack(int index) returns the value at the top of the stack 
/// with the given index and removes it from that stack, and returns -1 
/// if the stack with that given index is empty.
/// Example:
/// Input: 
/// ["DinnerPlates","push","push","push","push","push","popAtStack",
///  "push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
/// [[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
/// Output: 
/// [null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]
///
/// Explanation: 
/// DinnerPlates D = DinnerPlates(2);  // Initialize with capacity = 2
/// D.push(1);
/// D.push(2);
/// D.push(3);
/// D.push(4);
/// D.push(5);         // The stacks are now:  2  4
///                                            1  3  5
/// D.popAtStack(0);   // Returns 2.  The stacks are now:     4
///                                                        1  3  5
/// D.push(20);        // The stacks are now: 20  4
///                                            1  3  5
/// D.push(21);        // The stacks are now: 20  4 21
///                                            1  3  5
/// D.popAtStack(0);   // Returns 20.  The stacks are now:     4 21
///                                                         1  3  5
/// D.popAtStack(2);   // Returns 21.  The stacks are now:     4
///                                                         1  3  5
/// D.pop()            // Returns 5.  The stacks are now:      4
///                                                         1  3 
/// D.pop()            // Returns 4.  The stacks are now:   1  3 
/// D.pop()            // Returns 3.  The stacks are now:   1 
/// D.pop()            // Returns 1.  There are no stacks.
/// D.pop()            // Returns -1.  There are still no stacks.
///  
/// Constraints:
/// 1. 1 <= capacity <= 20000
/// 2. 1 <= val <= 20000
/// 3. 0 <= index <= 100000
/// 4. At most 200000 calls will be made to push, pop, and popAtStack.
/// </summary>
class DinnerPlates {
private:
    int m_capacity;
    set<int> m_free;
    set<int> m_occupy;
    vector<list<int>> m_plate;
public:
    DinnerPlates(int capacity) 
    {
        m_capacity = capacity;
        m_plate = vector<list<int>>(100001);
        m_free.insert(0);
    }

    void push(int val) 
    {
        if (m_free.empty()) return;
        int left = *m_free.begin();
        int right = left + 1;
        m_plate[left].push_back(val);
        if (m_plate[left].size() == m_capacity)
        {
            m_free.erase(left);
            if ((m_plate[right].size() < (size_t)m_capacity) && (m_free.count(right) == 0))
            {
                m_free.insert(right);
                m_free.erase(right + 1);
            }
        }
        if ((m_occupy.count(-left) == 0) && (m_plate[right].size() == 0))
        {
            m_occupy.insert(-left);
        }
        m_occupy.erase(-left + 1);
    }

    int pop() 
    {
        if (m_occupy.empty()) return - 1;
        int index = 0 - *m_occupy.begin();
        return popAtStack(index);
    }

    int popAtStack(int index) 
    {
        if (m_plate[index].empty()) return -1;
        int result = m_plate[index].back();
        m_plate[index].pop_back();
        int left = index - 1;
        if (m_plate[index].empty())
        {
            m_occupy.erase(-index);
            if ((left >= 0) && (m_plate[left].size() > 0) && (m_occupy.count(-left) == 0))
            {
                m_occupy.insert(-left);
                m_occupy.erase(-left+1);
            }
        }
        if ((m_free.count(index) == 0) && ((left < 0) || (m_plate[left].size() == m_capacity)))
        {
            m_free.insert(index);
        }
        m_free.erase(index + 1);
        return result;
    }
};

/// <summary>
/// Leet code #911. Online Election
/// 
/// In an election, the i-th vote was cast for persons[i] at time times[i].
///
/// Now, we would like to implement the following query function: 
/// TopVotedCandidate.q(int t) will return the number of the person that was 
/// leading the election at time t.  
///
/// Votes cast at time t will count towards our query.  In the case of a tie, 
/// the most recent vote (among tied candidates) wins.
///
/// Example 1:
///
/// Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],
/// [0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
/// Output: [null,0,1,1,0,0,1]
/// Explanation: 
/// At time 3, the votes are [0], and 0 is leading.
/// At time 12, the votes are [0,1,1], and 1 is leading.
/// At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to 
/// the most recent vote.)
/// This continues for 3 more queries at time 15, 24, and 8.
///
/// Note:
///
/// 1. 1 <= persons.length = times.length <= 5000
/// 2. 0 <= persons[i] <= persons.length
/// 3. times is a strictly increasing array with all elements in [0, 10^9].
/// 4. TopVotedCandidate.q is called at most 10000 times per test case.
/// 5. TopVotedCandidate.q(int t) is always called with t >= times[0].
/// </summary>
class TopVotedCandidate
{
private:
    unordered_map<int, int> m_persons;
    vector<int> m_timestamp;
    vector<int> m_vote;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times)
    {
        int max_person = -1;
        for (size_t i = 0; i < persons.size(); i++)
        {
            m_persons[persons[i]]++;
            if (max_person == -1)
            {
                max_person = persons[i];
                m_timestamp.push_back(times[i]);
                m_vote.push_back(max_person);
            }
            else if (m_persons[persons[i]] >= m_persons[max_person])
            {
                max_person = persons[i];
                m_timestamp.push_back(times[i]);
                m_vote.push_back(max_person);
            }
        }
    }
    int q(int t)
    {
        auto pos = upper_bound(m_timestamp.begin(), m_timestamp.end(), t);
        pos--;
        return m_vote[pos - m_timestamp.begin()];
    }
};

/// <summary>
/// Leet code #895. Maximum Frequency Stack
/// 
/// Implement FreqStack, a class which simulates the operation of a stack-like
/// data structure.
///
/// FreqStack has two functions:
///
/// push(int x), which pushes an integer x onto the stack.
/// pop(), which removes and returns the most frequent element in the stack.
/// If there is a tie for most frequent element, the element closest to the 
/// top of the stack is removed and returned.
/// 
/// Example 1:
///
/// Input: 
/// [
///   "FreqStack","push","push","push","push","push","push","pop","pop","pop",
///   "pop"
/// ],
/// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
/// Output: [null,null,null,null,null,null,null,5,7,5,4]
///
/// Explanation:
/// After making six .push operations, the stack is [5,7,5,7,4,5] from bottom 
/// to top.  Then:
///
/// pop() -> returns 5, as 5 is the most frequent.
/// The stack becomes [5,7,5,7,4].
///
/// pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to 
/// the top.
/// The stack becomes [5,7,5,4].
///
/// pop() -> returns 5.
/// The stack becomes [5,7,4].
///
/// pop() -> returns 4.
/// The stack becomes [5,7].
/// Note:
/// 1. Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
/// 2. It is guaranteed that FreqStack.pop() won't be called if the stack has 
///    zero elements.
/// 3. The total number of FreqStack.push calls will not exceed 10000 in a 
///    single test case.
/// 4. The total number of FreqStack.pop calls will not exceed 10000 in a 
///    single test case.
/// 5. The total number of FreqStack.push and FreqStack.pop calls will not 
///    exceed 150000 across all test cases.
/// </summary>
class FreqStack
{
private:
    unordered_map<int, int> m_Frequency;
    vector<stack<int>> m_stack;
public:
    FreqStack()
    {
    }

    void push(int x)
    {
        if (m_Frequency.count(x) == 0)
        {
            m_Frequency[x] = 0;
        }
        else
        {
            m_Frequency[x]++;
        }
        if (m_stack.size() == m_Frequency[x])
        {
            m_stack.push_back(stack<int>());
        }
        m_stack[m_Frequency[x]].push(x);
    }

    int pop()
    {
        int result = m_stack[m_stack.size() - 1].top();
        m_stack[m_stack.size() - 1].pop();
        if (m_stack[m_stack.size() - 1].empty())
        {
            m_stack.pop_back();
        }
        m_Frequency[result]--;
        if (m_Frequency[result] == -1)
        {
            m_Frequency.erase(result);
        }
        return result;
    }
};

/// <summary>
/// Leet code #1206. Design Skiplist
/// 
/// Design a Skiplist without using any built-in libraries.
///
/// A Skiplist is a data structure that takes O(log(n)) time to add, erase 
/// and search. Comparing with treap and red-black tree which has the same 
/// function and performance, the code length of Skiplist can be 
/// comparatively short and the idea behind Skiplists are just simple linked 
/// lists.
///
/// For example: we have a Skiplist containing [30,40,50,60,70,90] and we want
/// to add 80 and 45 into it. The Skiplist works this way:
///
/// Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons
///
/// You can see there are many layers in the Skiplist. Each layer is a sorted 
/// linked list. With the help of the top layers, add , erase and search can 
/// be faster than O(n). It can be proven that the average time complexity 
/// for each operation is O(log(n)) and space complexity is O(n).
///
/// To be specific, your design should include these functions:
///
/// bool search(int target) : Return whether the target exists in the Skiplist 
/// or not.
///
/// void add(int num): Insert a value into the SkipList. 
///
/// bool erase(int num): Remove a value in the Skiplist. If num does not exist 
/// in the Skiplist, do nothing and return false. If there exists multiple num 
//// values, removing any one of them is fine.
/// See more about Skiplist : https://en.wikipedia.org/wiki/Skip_list
/// 
/// Note that duplicates may exist in the Skiplist, your code needs to handle 
/// this situation.
///
/// Example:
///
/// Skiplist skiplist = new Skiplist();
///
/// skiplist.add(1);
/// skiplist.add(2);
/// skiplist.add(3);
/// skiplist.search(0);   // return false.
/// skiplist.add(4);
/// skiplist.search(1);   // return true.
/// skiplist.erase(0);    // return false, 0 is not in skiplist.
/// skiplist.erase(1);    // return true.
/// skiplist.search(1);   // return false, 1 has already been erased.
/// 
/// Constraints:
///
/// 1. 0 <= num, target <= 20000
/// 2. At most 50000 calls will be made to search, add, and erase.
/// </summary>
class Skiplist 
{
private:
    struct SkipNode
    {
        int value;
        SkipNode* down;
        SkipNode* prev;
        SkipNode* next;
        SkipNode(int v)
        {
            value = v;
            down = nullptr;
            prev = nullptr;
            next = nullptr;
        }
    };
    vector<SkipNode*> skip_layer;

    SkipNode * search_next(SkipNode* start, int target)
    {
        SkipNode* node = start;
        while (node->next != nullptr && target > node->next->value)
        {
            node = node->next;
        }
        return node;
    }

    SkipNode* search_down(int target, vector<SkipNode *>& layer_nodes)
    {
        SkipNode* node = nullptr;
        for (int i = skip_layer.size() - 1; i >= 0; i--)
        {
            if (i == skip_layer.size() - 1)
            {
                node = skip_layer[i];
            }
            else
            {
                if (node != nullptr) node = node->down;
            }
            node = search_next(node, target);
            layer_nodes.push_back(node);
        }
        return node;
    }
public:
    Skiplist() 
    {
        SkipNode* prev = nullptr;
        srand((unsigned int)time(0));      
        for (size_t i = 0; i < 32; i++)
        {
           
            SkipNode* node = new SkipNode(0);
            skip_layer.push_back(node);
            if (prev != nullptr)
            {
                node->down = prev;
            }
            prev = node;
        }
    }

    ~Skiplist()
    {
        for (size_t i = 0; i < skip_layer.size(); i++)
        {
            SkipNode* node = skip_layer[i];
            while (node != nullptr)
            {
                SkipNode* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }

    bool search(int target) 
    {
        SkipNode* start = nullptr;
        vector<SkipNode *> layer_nodes;
        SkipNode* node = search_down(target, layer_nodes);
        if (node != nullptr && node->next != nullptr && node->next->value == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void add(int num) 
    {
        vector<SkipNode*> layer_nodes;
        SkipNode* node = search_down(num, layer_nodes);
        int n = 1;
        SkipNode* down = nullptr;
        while (!layer_nodes.empty())
        {
            // coin flip negative stop pop up
            if (n == 0) break;

            node = layer_nodes.back();
            layer_nodes.pop_back();
            
            SkipNode* new_node = new SkipNode(num);
            new_node->next = node->next;
            if (node->next != nullptr) node->next->prev = new_node;
            node->next = new_node;
            if (new_node != nullptr) new_node->prev = node;            
            if (new_node != nullptr) new_node->down = down;
            down = new_node;

            n = rand() % 2;
        }
    }

    bool erase(int num) 
    {
        bool result = false;
        vector<SkipNode*> layer_nodes;
        SkipNode* node = search_down(num, layer_nodes);

        while (!layer_nodes.empty())
        {
            node = layer_nodes.back();
            layer_nodes.pop_back();

            if (node != nullptr && node->next != nullptr && node->next->value == num)
            {
                result = true;
                SkipNode* temp = node->next;
                node->next = temp->next;
                if (node->next != nullptr)
                {
                    node->next->prev = node;
                }
                delete temp;
            }
        }
        return result;
    }

    void print()
    {
        printf("#\n");
        for (size_t i = 0; i < skip_layer.size(); i++)
        {
            SkipNode* node = skip_layer[i];
            if (node == nullptr || node->next == nullptr) break;
            node = node->next;
            string message;
            while (node != nullptr)
            {
                if (!message.empty())
                {
                    message.append("->");
                }
                message.append(to_string(node->value));
                node = node->next;
            }
            printf("%s\n", message.c_str());
        }
    }
};

/// <summary>
/// Leet code #1244. Design A Leaderboard
///  
/// Design a Leaderboard class, which has 3 functions:
/// addScore(playerId, score): Update the leaderboard by adding score to the 
/// given player's score. If there is no player with such id in the 
/// leaderboard, add him to the leaderboard with the given score.
/// top(K): Return the score sum of the top K players.
/// reset(playerId): Reset the score of the player with the given id to 0. 
/// It is guaranteed that the player was added to the leaderboard before 
/// calling this function.
///
/// Initially, the leaderboard is empty.
/// 
/// Example 1:
///
/// Input: 
/// ["Leaderboard","addScore","addScore","addScore","addScore","addScore",
///  "top","reset","reset","addScore","top"]
/// [[],[1,73],[2,56],[3,39],[4,51],[5,4],[1],[1],[2],[2,51],[3]]
///
/// Output: 
/// [null,null,null,null,null,null,73,null,null,null,141]
///
/// Explanation: 
/// Leaderboard leaderboard = new Leaderboard ();
/// leaderboard.addScore(1,73);   // [[1,73]];
/// leaderboard.addScore(2,56);   // [[1,73],[2,56]];
/// leaderboard.addScore(3,39);   // [[1,73],[2,56],[3,39]];
/// leaderboard.addScore(4,51);   // [[1,73],[2,56],[3,39],[4,51]];
/// leaderboard.addScore(5,4);    // [[1,73],[2,56],[3,39],[4,51],[5,4]];
/// leaderboard.top(1);           // returns 73;
/// leaderboard.reset(1);         // [[2,56],[3,39],[4,51],[5,4]];
/// leaderboard.reset(2);         // [[3,39],[4,51],[5,4]];
/// leaderboard.addScore(2,51);   // [[2,51],[3,39],[4,51],[5,4]];
/// leaderboard.top(3);           // 141 = 51 + 51 + 39;
///  
/// Constraints:
/// 1. 1 <= playerId, K <= 10000
/// 2. It's guaranteed that K is less than or equal to the current number 
///    of players.
/// 3. 1 <= score <= 100
/// 4. There will be at most 1000 function calls.
/// </summary>
class Leaderboard
{
private:
    unordered_map<int, int> m_player;
    set<pair<int, int>> m_score;
public:
    Leaderboard() 
    {
    }

    void addScore(int playerId, int score) 
    {
        if (m_player.count(playerId) > 0)
        {
            m_score.erase(make_pair(-m_player[playerId], playerId));
            m_player[playerId] += score;
        }
        else
        {
            m_player[playerId] = score;
        }
        m_score.insert(make_pair(-m_player[playerId], playerId));
    }

    int top(int K) 
    {
        int index = 0;
        int result = 0;
        for (auto itr : m_score)
        {
            result += -itr.first;
            index++;
            if (index == K) break;
        }
        return result;
    }

    void reset(int playerId) 
    {
        if (m_player.count(playerId) > 0)
        {
            m_score.erase(make_pair(-m_player[playerId], playerId));
            m_player[playerId] = 0;
        }
        else
        {
            m_player[playerId] = 0;
        }
        m_score.insert(make_pair(0, playerId));
    }
};

/// <summary>
/// Leet code #981. Time Based Key-Value Store
/// 
/// Create a timebased key-value store class TimeMap, that supports two 
/// operations.
/// 1. set(string key, string value, int timestamp)
///    Stores the key and value, along with the given timestamp.
/// 2. get(string key, int timestamp)
///    Returns a value such that set(key, value, timestamp_prev) was called 
///    previously, with timestamp_prev <= timestamp.
/// 3. If there are multiple such values, it returns the one with the largest 
///    timestamp_prev.
/// 4. If there are no values, it returns the empty string ("").
/// 
/// Example 1:
/// Input: 
/// inputs = ["TimeMap","set","get","get","set","get","get"], 
/// inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],
///           ["foo",4],["foo",5]]
/// Output: [null,null,"bar","bar",null,"bar2","bar2"]
/// Explanation:   
/// TimeMap kv;   
/// kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with 
/// timestamp = 1   
/// kv.get("foo", 1);  // output "bar"   
/// kv.get("foo", 3); // output "bar" since there is no value corresponding to 
/// foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 
/// ie "bar"   
/// kv.set("foo", "bar2", 4);   
/// kv.get("foo", 4); // output "bar2"   
/// kv.get("foo", 5); //output "bar2"   
/// 
/// Example 2:
/// Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], 
/// inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],
/// ["love",15],["love",20],["love",25]]
/// Output: [null,null,null,"","high","high","low","low"]
/// 
/// Note:
/// 1. All key/value strings are lowercase.
/// 2. All key/value strings have length in the range [1, 100]
/// 3. The timestamps for all TimeMap.set operations are strictly increasing.
/// 4. 1 <= timestamp <= 10^7
/// 5. TimeMap.set and TimeMap.get functions will be called a total of 120000 
///    times (combined) per test case.
/// </summary>
class TimeMap {
private:
    unordered_map<string, map<int, string>> m_dictionary;
public:
    /** Initialize your data structure here. */
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m_dictionary[key][-timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto itr = m_dictionary[key].lower_bound(-timestamp);
        if (itr == m_dictionary[key].end())
        {
            return "";
        }
        else
        {
            return itr->second;
        }
    }
};

/// <summary>
/// Leet code #380. Insert Delete GetRandom O(1)   
///
/// Design a data structure that supports all following operations in 
/// average O(1) time.
/// 1.insert(val): Inserts an item val to the set if not already present.
/// 2.remove(val): Removes an item val from the set if present.
/// 3.getRandom: Returns a random element from current set of elements. 
///   Each element must have the same probability of being returned.
/// Example:
/// Init an empty set.	
/// RandomizedSet randomSet = new RandomizedSet();
/// Inserts 1 to the set. Returns true as 1 was inserted successfully.
/// randomSet.insert(1);
/// Returns false as 2 does not exist in the set.
/// randomSet.remove(2);
/// Inserts 2 to the set, returns true. Set now contains [1,2].	
/// randomSet.insert(2);
/// getRandom should return either 1 or 2 randomly.
/// randomSet.getRandom();	
/// Removes 1 from the set, returns true. Set now contains [2]. 
/// randomSet.remove(1);
/// 2 was already in the set, so return false.
/// randomSet.insert(2);
/// Since 2 is the only number in the set, getRandom always return 2.
/// randomSet.getRandom();
/// </summary>
class RandomizedSet
{
private:
    unordered_map<int, int> m_Map;
    vector<int> m_Vector;

public:
    /// <summary>
    /// Constructor of an empty randomized set
    /// </summary    
    RandomizedSet()
    {
        srand((unsigned int)time(0));
    }

    /// <summary>
    /// Destructor of a RandomizedSet
    /// </summary>
    /// <returns></returns>
    ~RandomizedSet()
    {
    }

    /// <summary>
    /// Inserts a value to the set. Returns true if the set did not already 
    /// contain the specified element.
    /// </summary>
    /// <returns>true, if value not exists, false if value already exists</returns>
    bool insert(int val)
    {
        if (m_Map.find(val) != m_Map.end())
        {
            return false;
        }
        else
        {
            m_Vector.push_back(val);
            m_Map[val] = m_Vector.size() - 1;
            return true;
        }
    }

    /// <summary>
    /// Removes a value from the set. Returns true if the set contained the specified element. 
    /// </summary>
    /// <returns>true, if value exists, false if value not exists</returns>
    bool remove(int val)
    {
        if (m_Map.find(val) == m_Map.end())
        {
            return false;
        }
        else
        {
            // find the value position
            int index = m_Map[val];
            // move the last value to empty slot (where the value will be removed)
            m_Vector[index] = m_Vector.back();
            // set new postion for the last value
            m_Map[m_Vector.back()] = index;
            // pop out last value in vector
            m_Vector.pop_back();
            // remove old value position map
            m_Map.erase(val);
            return true;
        }
    }

    /// <summary>
    /// Get a random element from the set. 
    /// </summary>
    /// <returns>the random value in the set</returns>
    int getRandom()
    {
        if (m_Vector.size() == 0)
        {
            return -1;
        }
        int index = rand() % m_Vector.size();
        return m_Vector[index];
    }
};

/// <summary>
/// LeetCode #381. Insert Delete GetRandom O(1) - Duplicates allowed   
/// Design a data structure that supports all following operations in 
/// average O(1) time.
/// Note: Duplicate elements are allowed. 
/// 1.insert(val): Inserts an item val to the collection.
/// 2.remove(val): Removes an item val from the collection if present.
/// 3.getRandom: Returns a random element from current collection of elements. 
///              The probability of each element being returned is linearly 
///              related to the number of same value the collection contains.
/// Example: 
/// Init an empty collection.
/// RandomizedCollection collection = new RandomizedCollection();
///
/// Inserts 1 to the collection. Returns true as the collection did not 
/// contain 1.
/// collection.insert(1);
/// Inserts another 1 to the collection. Returns false as the collection 
/// contained 1. 
/// Collection now contains [1,1].
/// collection.insert(1);
/// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
/// collection.insert(2);
/// getRandom should return 1 with the probability 2/3, and returns 2 with the 
/// probability 1/3.
/// collection.getRandom();
/// Removes 1 from the collection, returns true. Collection now contains [1,2].
/// collection.remove(1);
/// getRandom should return 1 and 2 both equally likely.
/// collection.getRandom();
/// </summary>
class RandomizedCollection
{
private:
    unordered_map<int, unordered_set<int>> m_Map;
    vector<int> m_Vector;
public:
    /// <summary>
    /// Constructor of an empty randomized collection
    /// </summary    
    RandomizedCollection()
    {
        srand((unsigned int)time(0));
    }

    /// <summary>
    /// Destructor of a randomized  collection
    /// </summary>
    /// <returns></returns>
    ~RandomizedCollection()
    {
    }

    /// <summary>
    /// Inserts a value to the set. Returns true if the set did not already 
    /// contain the specified element.
    /// </summary>
    /// <returns>true, if value not exists, false if value already exists</returns>
    bool insert(int val)
    {
        bool new_item = false;
        if (m_Map.find(val) == m_Map.end())
        {
            new_item = true;
        }
        m_Vector.push_back(val);
        m_Map[val].insert(m_Vector.size() - 1);
        return new_item;
    }

    /// <summary>
    /// Removes a value from the set. Returns true if the set contained the specified element. 
    /// </summary>
    /// <returns>true, if value exists, false if value not exists</returns>
    bool remove(int val)
    {
        if (m_Map.find(val) == m_Map.end())
        {
            return false;
        }
        else
        {
            // find the value position
            int index = *m_Map[val].begin();
            // should remove old value first because we may add back due to move later
            // remove old value position map
            m_Map[val].erase(index);
            if (m_Map[val].empty())
            {
                m_Map.erase(val);
            }
            if (index != m_Vector.size() - 1)
            {
                int last_val = m_Vector.back();
                // move the last value to empty slot (where the value will be removed)
                m_Vector[index] = last_val;
                // set new postion for the last value
                m_Map[last_val].erase(m_Vector.size() - 1);
                m_Map[last_val].insert(index);
            }
            // pop out last value in vector
            m_Vector.pop_back();
            return true;
        }
    }

    /// <summary>
    /// Get a random element from the set. 
    /// </summary>
    /// <returns>the random value in the set</returns>
    int getRandom()
    {
        if (m_Vector.size() == 0)
        {
            return -1;
        }
        int index = rand() % m_Vector.size();
        return m_Vector[index];
    }
};

/// <summary>
/// Leet code #432. All O`one Data Structure Add to List 
/// Implement a data structure supporting the following operations:
/// Inc(Key) - Inserts a new key with value 1. Or increments an existing key 
/// by 1. Key is guaranteed to be a non-empty string.
/// Dec(Key) - If Key's value is 1, remove it from the data structure. 
///            Otherwise decrements an existing key by 1. 
///            If the key does not exist, this function does nothing. Key is 
///            guaranteed to be a non-empty string.
/// GetMaxKey() - Returns one of the keys with maximal value. If no element 
///               exists, return an empty string "".
/// GetMinKey() - Returns one of the keys with minimal value. If no element 
///               exists, return an empty string "".
/// Challenge: Perform all these in O(1) time complexity. 
/// </summary>
class AllOne {
private:
    unordered_map<string, int> m_KeyMap;
    vector<unordered_set<string>> m_KeyList;

public:
    /** Initialize your data structure here. */
    AllOne()
    {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key)
    {
        if (m_KeyMap.find(key) != m_KeyMap.end())
        {
            m_KeyList[m_KeyMap[key] - 1].erase(key);
        }
        m_KeyMap[key]++;
        while (m_KeyMap[key] > (int)m_KeyList.size())
        {
            m_KeyList.push_back(unordered_set<string>());
        }
        m_KeyList[m_KeyMap[key] - 1].insert(key);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        if (m_KeyMap.find(key) == m_KeyMap.end()) return;
        m_KeyList[m_KeyMap[key] - 1].erase(key);
        m_KeyMap[key]--;
        if (m_KeyMap[key] == 0)
        {
            m_KeyMap.erase(key);
        }
        else
        {
            m_KeyList[m_KeyMap[key] - 1].insert(key);
        }
        while (!m_KeyList.empty() && m_KeyList.back().empty())
        {
            m_KeyList.pop_back();
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        string str;
        if (m_KeyList.empty())
        {
            str = "";
        }
        else
        {
            unordered_set<string> str_set = m_KeyList.back();
            str = *str_set.begin();
        }
        return str;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        string str;
        if (m_KeyList.empty())
        {
            str = "";
        }
        else
        {
            for (size_t i = 0; i < m_KeyList.size(); i++)
            {
                if (!m_KeyList[i].empty())
                {
                    unordered_set<string> str_set = m_KeyList[i];
                    str = *str_set.begin();
                    break;
                }
            }
        }
        return str;
    }
};

/// <summary>
/// Leet code #705. Design HashSet
/// 
/// Design a HashSet without using any built-in hash table libraries.
/// To be specific, your design should include these functions:
///
/// add(value): Insert a value into the HashSet.
///
/// contains(value) : Return whether the value exists in the HashSet 
/// or not.
/// 
/// remove(value): Remove a value in the HashSet. If the value does not 
/// exist in the HashSet, do nothing.
///  
/// Example:
///
/// MyHashSet hashSet = new MyHashSet();
/// hashSet.add(1);         
/// hashSet.add(2);         
/// hashSet.contains(1);    // returns true
/// hashSet.contains(3);    // returns false (not found)
/// hashSet.add(2);          
/// hashSet.contains(2);    // returns true
/// hashSet.remove(2);          
/// hashSet.contains(2);    // returns false (already removed)
///
/// Note:
///
/// 1. All values will be in the range of [0, 1000000].
/// 2. The number of operations will be in the range of [1, 10000].
/// 3. Please do not use the built-in HashSet library.
/// </summary>
class MyHashSet {
private:
    int m_Size = 10000;
    vector<list<int>> m_Data;
public:

    // Initialize your data structure here.
    MyHashSet()
    {
        m_Data = vector<list<int>>(m_Size);
    }

    void add(int key)
    {
        int index = key % m_Size;
        auto itr = m_Data[index].begin();
        while (itr != m_Data[index].end())
        {
            if (*itr == key) return;
            itr++;
        }
        m_Data[index].push_back(key);
    }


    void remove(int key)
    {
        int index = key % m_Size;
        auto itr = m_Data[index].begin();
        while (itr != m_Data[index].end())
        {
            if (*itr == key)
            {
                m_Data[index].erase(itr);
                return;
            }
            itr++;
        }
    }
    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int index = key % m_Size;
        auto itr = m_Data[index].begin();
        while (itr != m_Data[index].end())
        {
            if (*itr == key) return true;
            itr++;
        }
        return false;
    }
};

/// <summary>
/// Leet code #706. Design HashMap
/// 
/// Design a HashMap without using any built-in hash table libraries.
///
/// To be specific, your design should include these functions:
///
/// put(key, value) : Insert a (key, value) pair into the HashMap. If 
/// the value already exists in the HashMap, update the value.
/// get(key): Returns the value to which the specified key is mapped, 
/// or -1 if this map contains no mapping for the key.
/// remove(key) : Remove the mapping for the value key if this map 
/// contains the mapping for the key.
///
/// Example:
///
/// MyHashMap hashMap = new MyHashMap();
/// hashMap.put(1, 1);          
/// hashMap.put(2, 2);         
/// hashMap.get(1);            // returns 1
/// hashMap.get(3);            // returns -1 (not found)
/// hashMap.put(2, 1);          // update the existing value
/// hashMap.get(2);            // returns 1 
/// hashMap.remove(2);          // remove the mapping for 2
/// hashMap.get(2);            // returns -1 (not found) 
///
/// Note:
/// 1. All keys and values will be in the range of [0, 1000000].
/// 2. The number of operations will be in the range of [1, 10000].
/// 3. Please do not use the built-in HashMap library.
/// </summary>
class MyHashMap {
    int m_Size = 10000;
    vector<list<pair<int, int>>> m_Data;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        m_Data = vector<list<pair<int, int>>>(m_Size);
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int index = key % m_Size;
        auto itr = m_Data[index].begin();
        while (itr != m_Data[index].end())
        {
            if (itr->first == key)
            {
                itr->second = value;
                return;
            }
            itr++;
        }
        m_Data[index].push_back(make_pair(key, value));
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int index = key % m_Size;
        auto itr = m_Data[index].begin();
        while (itr != m_Data[index].end())
        {
            if (itr->first == key)
            {
                return itr->second;
            }
            itr++;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int index = key % m_Size;
        auto itr = m_Data[index].begin();
        while (itr != m_Data[index].end())
        {
            if (itr->first == key)
            {
                m_Data[index].erase(itr);
                return;
            }
            itr++;
        }
    }
};

/// <summary>
/// Leet code #707. Design Linked List
/// 
/// Design your implementation of the linked list. You can choose to 
/// use the singly linked list or the doubly linked list. A node in 
/// a singly linked list should have two attributes: val and next.val 
/// is the value of the current node, and next is a pointer/reference 
/// to the next node. If you want to use the doubly linked list, you 
/// will need one more attribute prev to indicate the previous node in 
/// the linked list. Assume all nodes in the linked list are 0-indexed.
///
/// Implement these functions in your linked list class:
///
/// get(index) : Get the value of the index-th node in the linked list. 
/// If the index is invalid, return -1.
/// addAtHead(val) : Add a node of value val before the first element of 
/// the linked list. After the insertion, the new node will be the first 
/// node of the linked list.
/// addAtTail(val) : Append a node of value val to the last element of 
/// the linked list.
/// addAtIndex(index, val) : Add a node of value val before the index-th 
/// node in the linked list. If index equals to the length of linked list,
/// the node will be appended to the end of linked list. If index is 
/// greater than the length, the node will not be inserted.
/// deleteAtIndex(index) : Delete the index-th node in the linked list, 
/// if the index is valid.
/// Example:
///
/// MyLinkedList linkedList = new MyLinkedList();
/// linkedList.addAtHead(1);
/// linkedList.addAtTail(3);
/// linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
/// linkedList.get(1);            // returns 2
/// linkedList.deleteAtIndex(1);  // now the linked list is 1->3
/// linkedList.get(1);            // returns 3
/// Note:
///
/// All values will be in the range of [1, 1000].
/// The number of operations will be in the range of [1, 1000].
/// Please do not use the built-in LinkedList library.
/// </summary>
class MyLinkedList {
private:
    struct LinkedNode
    {
        LinkedNode * prev;
        LinkedNode * next;
        int value;
        LinkedNode(int val)
        {
            prev = nullptr;
            next = nullptr;
            value = val;
        }
    };
    LinkedNode * m_Head;
    LinkedNode * m_Tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
        m_Head = nullptr;
        m_Tail = nullptr;
    }

    /** Initialize your data structure here. */
    ~MyLinkedList()
    {
        LinkedNode * node = m_Head;
        if (node != nullptr)
        {
            LinkedNode * next = node->next;
            delete node;
            node = next;
        }
        m_Head = nullptr;
        m_Tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        LinkedNode * node = m_Head;
        for (int i = 0; i < index; i++)
        {
            if (node == nullptr) return -1;
            node = node->next;
        }
        if (node != nullptr) return node->value;
        else return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        LinkedNode * node = new LinkedNode(val);
        node->next = m_Head;
        if (m_Head != nullptr)
        {
            m_Head->prev = node;
        }
        m_Head = node;
        if (m_Tail == nullptr) m_Tail = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        LinkedNode * node = new LinkedNode(val);
        node->prev = m_Tail;
        if (m_Tail != nullptr)
        {
            m_Tail->next = node;
        }
        m_Tail = node;
        if (m_Head == nullptr) m_Head = node;
    }

    /** Add a node of value val before the index-th node in the linked list.
    /// If index equals to the length of linked list, the node will be appended to the end of linked list.
    /// If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        LinkedNode * node = m_Head;
        for (int i = 0; i < index; i++)
        {
            if (node == nullptr) return;
            node = node->next;
        }
        if (node != nullptr)
        {
            LinkedNode * new_node = new LinkedNode(val);
            LinkedNode * prev_node = node->prev;
            new_node->prev = prev_node;
            new_node->next = node;
            if (prev_node != nullptr) prev_node->next = new_node;
            node->prev = new_node;
            if (node == m_Head) m_Head = new_node;
        }
        else
        {
            addAtTail(val);
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        LinkedNode * node = m_Head;
        for (int i = 0; i < index; i++)
        {
            if (node == nullptr) return;
            node = node->next;
        }
        if (node != nullptr)
        {
            LinkedNode * prev_node = node->prev;
            LinkedNode * next_node = node->next;
            if (prev_node != nullptr) prev_node->next = next_node;
            if (next_node != nullptr) next_node->prev = prev_node;
            if (node == m_Head) m_Head = next_node;
            if (node == m_Tail) m_Tail = prev_node;
            delete node;
        }
    }
};

/// <summary>
/// Leet code #622. Design Circular Queue
/// 
/// Design your implementation of the circular queue. The circular queue 
/// is a linear data structure in which the operations are performed based 
/// on FIFO (First In First Out) principle and the last position is 
/// connected back to the first position to make a circle. It is also 
/// called "Ring Buffer".
///
/// One of the benefits of the circular queue is that we can make use of 
/// the spaces in front of the queue. In a normal queue, once the queue 
/// becomes full, we cannot insert the next element even if there is a 
/// space in front of the queue. But using the circular queue, we can 
/// use the space to store new values.
///
/// Your implementation should support following operations:
///
/// MyCircularQueue(k): Constructor, set the size of the queue to be k.
/// Front: Get the front item from the queue. If the queue is empty, 
/// return -1.
/// Rear: Get the last item from the queue. If the queue is empty, 
/// return -1.
/// enQueue(value): Insert an element into the circular queue. Return 
/// true if the operation is successful.
/// deQueue(): Delete an element from the circular queue. Return true 
/// if the operation is successful.
/// isEmpty(): Checks whether the circular queue is empty or not.
/// isFull(): Checks whether the circular queue is full or not.
///
/// Example:
///
/// MyCircularQueue circularQueue = new MycircularQueue(3); 
/// circularQueue.enQueue(1);  // return true
/// circularQueue.enQueue(2);  // return true
/// circularQueue.enQueue(3);  // return true
/// circularQueue.enQueue(4);  // return false, the queue is full
/// circularQueue.Rear();  // return 3
/// circularQueue.isFull();  // return true
/// circularQueue.deQueue();  // return true
/// circularQueue.enQueue(4);  // return true
/// circularQueue.Rear();  // return 4
/// Note:
/// 
/// All values will be in the range of [0, 1000].
/// The number of operations will be in the range of [1, 1000].
/// Please do not use the built-in Queue library.
/// </summary>
class MyCircularQueue
{
private:
    vector<int>m_Queue;
    int m_First = 0;
    int m_Last = 0;
    int m_Count = 0;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        m_Queue = vector<int>(k);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (m_Count == m_Queue.size()) return false;
        m_Queue[m_Last] = value;
        m_Last = (m_Last + 1) % m_Queue.size();
        m_Count++;
        return true;
    }


    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (m_Count == 0) return false;
        m_First = (m_First + 1) % m_Queue.size();
        m_Count--;
        return true;
    }
    /** Get the front item from the queue. */
    int Front()
    {
        if (m_Count == 0) return -1;
        return m_Queue[m_First];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (m_Count == 0) return -1;
        return m_Queue[(m_Last - 1 + m_Queue.size()) % m_Queue.size()];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return (m_Count == 0);
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return (m_Count == m_Queue.size());
    }
};

/// <summary>
/// Leet code #641. Design Circular Deque
/// 
/// Design your implementation of the circular double-ended queue (deque).
///
/// Your implementation should support following operations:
///
/// MyCircularDeque(k): Constructor, set the size of the deque to be k.
/// insertFront(): Adds an item at the front of Deque. Return true if the 
/// operation is successful.
/// insertLast(): Adds an item at the rear of Deque. Return true if the 
/// operation is successful.
/// deleteFront(): Deletes an item from the front of Deque. Return true 
/// if the operation is successful.
/// deleteLast(): Deletes an item from the rear of Deque. Return true if 
/// the operation is successful.
/// getFront(): Gets the front item from the Deque. If the deque is empty, 
/// return -1.
/// getRear(): Gets the last item from Deque. If the deque is empty, 
/// return -1.
/// isEmpty(): Checks whether Deque is empty or not. 
/// isFull(): Checks whether Deque is full or not.
///
///
/// Example:
///
/// MyCircularDeque circularDeque = new MycircularDeque(3); 
/// circularDeque.insertLast(1);			// return true
/// circularDeque.insertLast(2);			// return true
/// circularDeque.insertFront(3);			// return true
/// circularDeque.insertFront(4);			// return false, if full
/// circularDeque.getRear();  			    // return 2
/// circularDeque.isFull();				    // return true
/// circularDeque.deleteLast();			    // return true
/// circularDeque.insertFront(4);			// return true
/// circularDeque.getFront();			    // return 4
///
/// Note:
///
/// All values will be in the range of [0, 1000].
/// The number of operations will be in the range of [1, 1000].
/// Please do not use the built-in Deque library.
/// </summary>
class MyCircularDeque
{
private:
    vector<int>m_Queue;
    int m_First = 0;
    int m_Last = 0;
    int m_Count = 0;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        m_Queue = vector<int>(k);
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (m_Count == m_Queue.size()) return false;
        m_First = (m_First - 1 + m_Queue.size()) % m_Queue.size();
        m_Queue[m_First] = value;
        m_Count++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (m_Count == m_Queue.size()) return false;
        m_Queue[m_Last] = value;
        m_Last = (m_Last + 1) % m_Queue.size();
        m_Count++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (m_Count == 0) return false;
        m_First = (m_First + 1) % m_Queue.size();
        m_Count--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (m_Count == 0) return false;
        m_Last = (m_Last - 1 + m_Queue.size()) % m_Queue.size();
        m_Count--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (m_Count == 0) return -1;
        return m_Queue[m_First];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (m_Count == 0) return -1;
        return m_Queue[(m_Last - 1 + m_Queue.size()) % m_Queue.size()];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return (m_Count == 0);
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return (m_Count == m_Queue.size());
    }
};

/// <summary>
/// Leet code #1348. Tweet Counts Per Frequency
///
/// Medium
///
/// Implement the class TweetCounts that supports two methods: 
/// 1. recordTweet(string tweetName, int time)
///
/// Stores the tweetName at the recorded time (in seconds).
/// 2. getTweetCountsPerFrequency(string freq, string tweetName, 
///   int startTime, int endTime)
///
/// Returns the total number of occurrences for the given tweetName 
/// per minute, hour, or day (depending on freq) starting from the 
/// startTime (in seconds) and ending at the endTime (in seconds).
/// freq is always minute, hour or day, representing the time interval 
/// to get the total number of occurrences for the given tweetName.
/// 
/// The first time interval always starts from the startTime, so the 
/// time intervals are [startTime, startTime + delta*1>,  [startTime + 
/// delta*1, startTime + delta*2>, [startTime + delta*2, startTime + 
/// delta*3>, ... , [startTime + delta*i, min(startTime + delta*(i+1), 
/// endTime + 1)> for some non-negative number i and delta (which 
/// depends on freq).  
/// 
/// Example:
/// Input
/// ["TweetCounts","recordTweet","recordTweet","recordTweet",
/// "getTweetCountsPerFrequency","getTweetCountsPerFrequency",
/// "recordTweet","getTweetCountsPerFrequency"]
/// [[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],
/// ["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]
///
/// Output
/// [null,null,null,null,[2],[2,1],null,[4]]
/// 
/// Explanation
/// TweetCounts tweetCounts = new TweetCounts();
/// tweetCounts.recordTweet("tweet3", 0);
/// tweetCounts.recordTweet("tweet3", 60);
/// tweetCounts.recordTweet("tweet3", 10);    
/// All tweets correspond to "tweet3" with recorded times at 0, 10 and 60.
/// tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); 
/// return [2]. The frequency is per minute (60 seconds), so there is one 
/// interval of time: 1) [0, 60> - > 2 tweets.
/// tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); 
/// return [2, 1]. The frequency is per minute (60 seconds), so there are 
/// two intervals of time: 1) [0, 60> - > 2 tweets, and 2) [60,61> - > 
/// 1 tweet.
/// tweetCounts.recordTweet("tweet3", 120); 
/// All tweets correspond to "tweet3" with recorded times at 0, 10, 60 
/// and 120.
/// tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  
/// return [4]. The frequency is per hour (3600 seconds), so there is one 
/// interval of time: 1) [0, 211> - > 4 tweets.
///
/// Constraints:
/// 1. There will be at most 10000 operations considering both 
///    recordTweet and getTweetCountsPerFrequency.
/// 2. 0 <= time, startTime, endTime <= 10^9
/// 3. 0 <= endTime - startTime <= 10^4
/// </summary>
class TweetCounts 
{
private:
    unordered_map<string, map<int, int>> m_tweet;
public:
    TweetCounts() 
    {
    }

    void recordTweet(string tweetName, int time) 
    {
        m_tweet[tweetName][time]++;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) 
    {
        int interval = 60;
        if (freq == "hour") interval = 60*60;
        else if (freq == "day") interval = 24 * 60 * 60;
        vector<int> result;
        for (int i = startTime; i <= endTime; i+= interval)
        {
            int start = i;
            int end = min(i + interval - 1, endTime);
            auto start_itr = m_tweet[tweetName].lower_bound(start);
            auto end_itr = m_tweet[tweetName].upper_bound(end);
            int count = 0;
            for (auto itr = start_itr; itr != end_itr; ++itr)
            {
                count += itr->second;
            }
            result.push_back(count);
        }
        return result;
    }
};

/// <summary>
/// Leet code #1352. Product of the Last K Numbers
///
/// Medium
///
/// Implement the class ProductOfNumbers that supports two methods:
///
/// 1. add(int num)
///
/// Adds the number num to the back of the current list of numbers.
///
/// 2. getProduct(int k)
///
/// Returns the product of the last k numbers in the current list.
/// You can assume that always the current list has at least k numbers.
/// At any time, the product of any contiguous sequence of numbers will 
/// fit into a single 32-bit integer without overflowing.
/// 
/// Example:
///
/// Input
/// ["ProductOfNumbers","add","add","add","add","add","getProduct",
///  "getProduct","getProduct","add","getProduct"]
///  [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
///
/// Output
/// [null,null,null,null,null,null,20,40,0,null,32]
///
/// Explanation
/// ProductOfNumbers productOfNumbers = new ProductOfNumbers();
/// productOfNumbers.add(3);        // [3]
/// productOfNumbers.add(0);        // [3,0]
/// productOfNumbers.add(2);        // [3,0,2]
/// productOfNumbers.add(5);        // [3,0,2,5]
/// productOfNumbers.add(4);        // [3,0,2,5,4]
/// productOfNumbers.getProduct(2); // return 20. The product of the 
///                                 // last 2 numbers is 5 * 4 = 20
/// productOfNumbers.getProduct(3); // return 40. The product of the 
///                                 // last 3 numbers is 2 * 5 * 4 = 40
/// productOfNumbers.getProduct(4); // return 0. The product of the last 4 
///                                 // numbers is 0 * 2 * 5 * 4 = 0
/// productOfNumbers.add(8);        // [3,0,2,5,4,8]
/// productOfNumbers.getProduct(2); // return 32. The product of the 
///                                 // last 2 numbers is 4 * 8 = 32 
///
/// Constraints:
/// 1. There will be at most 40000 operations considering both add and 
///    getProduct.
/// 2. 0 <= num <= 100
/// 3.  1 <= k <= 40000
/// </summary>
class ProductOfNumbers
{
private:
    vector<int> m_product;
public:
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
        {
            m_product.clear();
        }
        else
        {
            if (m_product.empty())
            {
                m_product.push_back(num);
            }
            else
            {
                m_product.push_back(m_product.back() * num);
            }
        }
    }

    int getProduct(int k)
    {
        if ((int)m_product.size() < k)
        {
            return 0;
        }
        else if (m_product.size() == k)
        {
            return m_product.back();
        }
        else
        {
            return m_product.back() / m_product[m_product.size() - k - 1];
        }
    }
};

/// <summary>
/// Leet code #933. Number of Recent Calls
/// 
/// Write a class RecentCounter to count recent requests.
///
/// It has only one method: ping(int t), where t represents some time in 
/// milliseconds.
///
/// Return the number of pings that have been made from 3000 milliseconds 
/// ago until now.
///
/// Any ping with time in [t - 3000, t] will count, including the current ping.
///
/// It is guaranteed that every call to ping uses a strictly larger value of 
/// t than before.
///
/// Example 1:
///
/// Input: inputs = ["RecentCounter","ping","ping","ping","ping"], 
/// inputs = [[],[1],[100],[3001],[3002]]
/// Output: [null,1,2,3,3]
///  
/// 
/// Note:
///
/// Each test case will have at most 10000 calls to ping.
/// Each test case will call ping with strictly increasing values of t.
/// Each call to ping will have 1 <= t <= 10^9.
/// </summary>
class RecentCounter {
private:
    map<int, int> m_PingCount;
    int m_Total;

public:
    RecentCounter()
    {
        m_Total = 0;
    }

    int ping(int t)
    {
        m_Total++;
        m_PingCount[t] = m_Total;
        auto itr = m_PingCount.lower_bound(t - 3000);
        int prev = 0;
        if (itr == m_PingCount.begin()) prev = 0;
        else
        {
            itr--;
            prev = itr->second;
        }
        return m_Total - prev;
    }
};

/// <summary>
/// Leet code #677. Map Sum Pairs
/// 
/// Implement a MapSum class with insert, and sum methods.
///
/// For the method insert, you'll be given a pair of (string, integer). 
/// The string represents the key and the integer represents the value. 
/// If the key already existed, then the original key-value pair will be 
/// overridden to the new one.
///
/// For the method sum, you'll be given a string representing the prefix, 
/// and you need to return the sum of all the pairs' value whose key 
/// starts with the prefix.
///
/// Example 1:
/// Input: insert("apple", 3), Output: Null
/// Input: sum("ap"), Output: 3
/// Input: insert("app", 2), Output: Null
/// Input: sum("ap"), Output: 5
/// </summary>
class MapSum
{
private:
    map<string, int> m_MapValue;
public:
    // Initialize your data structure here.
    MapSum()
    {
    }

    // insert a value
    void insert(string key, int val)
    {
        m_MapValue[key] = val;
    }

    // get the sum 
    int sum(string prefix)
    {
        int sum = 0;
        map<string, int>::iterator itr = m_MapValue.lower_bound(prefix);
        while (itr != m_MapValue.end())
        {
            if (itr->first.substr(0, prefix.size()) == prefix)
            {
                sum += itr->second;
            }
            else
            {
                break;
            }
            ++itr;
        }
        return sum;
    }
};

/// <summary>
/// Leet code #1274. Number of Ships in a Rectangle
/// 
/// On the sea represented by a cartesian plane, each ship is located at 
/// an integer point, and each integer point may contain at most 1 ship.
///
/// You have a function Sea.hasShips(topRight, bottomLeft) which takes 
/// two points as arguments and returns true if and only if there is at 
/// least one ship in the rectangle represented by the two points, 
/// including on the boundary.
///
/// Given two points, which are the top right and bottom left corners of 
/// a rectangle, return the number of ships present in that rectangle.  
/// It is guaranteed that there are at most 10 ships in that rectangle.
///
/// Submissions making more than 400 calls to hasShips will be judged 
/// Wrong Answer.  Also, any solutions that attempt to circumvent the 
/// judge will result in disqualification.
/// 
/// 
/// Example :
/// 
/// Input: 
/// ships = [[1,1],[2,2],[3,3],[5,5]], topRight = [4,4], bottomLeft = [0,0]
/// Output: 3
/// Explanation: From [0,0] to [4,4] we can count 3 ships within the range.
///
/// Constraints:
/// 1. On the input ships is only given to initialize the map internally. 
/// 2. You must solve this problem "blindfolded". In other words, you must 
///    find the answer using the given hasShips API, without knowing the 
///	   ships position.
/// 3. 0 <= bottomLeft[0] <= topRight[0] <= 1000
/// 4. 0 <= bottomLeft[1] <= topRight[1] <= 1000
/// </summary>
class Sea
{
private:
    vector<vector<int>> m_ship;

    // Return true if there is ship within rectangle.
    bool hasShips(vector<int>& topRight, vector<int>& bottomLeft)
    {
        for (size_t i = 0; i < m_ship.size(); i++)
        {
            if (m_ship[i][0] >= bottomLeft[0] && m_ship[i][0] <= topRight[0] &&
                m_ship[i][1] >= bottomLeft[1] && m_ship[i][1] <= topRight[1])
            {
                return true;
            }
        }
        return false;
    };
public:
    // Constructure on ships.
    Sea(vector<vector<int>>& ship)
    {
        m_ship = ship;
    };

    // Return true if there is ship within rectangle.
    int countShips(vector<int>& topRight, vector<int>& bottomLeft)
    {
        int result = 0;
        queue<pair<vector<int>, vector<int>>> search;
        search.push(make_pair(topRight, bottomLeft));

        while (!search.empty())
        {
            vector<int> top_right = search.front().first;
            vector<int> bottom_left = search.front().second;
            search.pop();

            if (!hasShips(top_right, bottom_left)) continue;

            if (top_right == bottom_left)
            {
                result++;
            }
            else
            {
                if (top_right[0] != bottom_left[0])
                {
                    vector<int> middle = { (bottom_left[0] + top_right[0]) / 2, top_right[1] };
                    search.push(make_pair(middle, bottom_left));
                    middle = { (bottom_left[0] + top_right[0]) / 2 + 1, bottom_left[1] };
                    search.push(make_pair(top_right, middle));
                }
                else
                {
                    vector<int> middle = { top_right[0], (bottom_left[1] + top_right[1]) / 2 };
                    search.push(make_pair(middle, bottom_left));
                    middle = { bottom_left[0], (bottom_left[1] + top_right[1]) / 2 + 1 };
                    search.push(make_pair(top_right, middle));
                }
            }
        }
        return result;
    };
};

/// <summary>
/// Leet code #208 Implement Trie (Prefix Tree)
///
/// Medium
///
/// Implement a trie with insert, search, and startsWith methods.
///
/// Example:
///
/// Trie trie = new Trie();
///
/// trie.insert("apple");
/// trie.search("apple");   // returns true
/// trie.search("app");     // returns false
/// trie.startsWith("app"); // returns true
/// trie.insert("app");   
/// trie.search("app");     // returns true
/// Note:
///
/// 1. You may assume that all inputs are consist of lowercase letters a-z.
/// 2. All inputs are guaranteed to be non-empty strings.
/// </summary>
class Trie
{
private:
    bool is_end;
    vector<Trie *> children;
public:
    Trie()
    {
        children = vector<Trie *>(26, nullptr);
        is_end = false;
    };

    ~Trie()
    {
        for (size_t i = 0; i < children.size(); i++)
        {
            if (children[i] != nullptr) delete children[i];
        }
    }

    void insert(string word)
    {
        if (word.empty())
        {
            is_end = true;
        }
        else
        {
            int i = word[0] - 'a';
            if (children[i] == nullptr)
            {
                children[i] = new Trie();
            }
            children[i]->insert(word.substr(1));
        }
    };

    bool search(string word)
    {
        if (word.empty())
        {
            return is_end;
        }
        else
        {
            int i = word[0] - 'a';
            if (children[i] == nullptr)
            {
                return false;
            }
            return children[i]->search(word.substr(1));
        }
    }

    bool startsWith(string prefix)
    {
        if (prefix.empty())
        {
            return true;
        }
        else
        {
            int i = prefix[0] - 'a';
            if (children[i] == nullptr)
            {
                return false;
            }
            return children[i]->startsWith(prefix.substr(1));
        }
    };
};

/// <summary>
/// Leet code #745. Prefix and Suffix Search
/// 
/// Given many words, words[i] has weight i.
/// Design a class WordFilter that supports one function, 
/// WordFilter.f(String prefix, String suffix). It will return the word with 
/// given prefix and suffix with maximum weight. If no word exists, return -1.
///
/// Examples:
/// Input:
/// WordFilter(["apple"])
/// WordFilter.f("a", "e") // returns 0
/// WordFilter.f("b", "") // returns -1
/// Note:
/// words has length in range [1, 15000].
/// For each test case, up to words.length queries WordFilter.f may be made.
/// words[i] has length in range [1, 10].
/// prefix, suffix have lengths in range [0, 10].
/// words[i] and prefix, suffix queries consist of lowercase letters only.
/// </summary>
class WordFilter 
{
private:
    unordered_map<string, int> m_WordMap;
public:
    WordFilter(vector<string> words)
    {
        for (size_t k = 0; k < words.size(); k++)
        {
            for (size_t i = 0; i <= 10 && i <= words[k].size(); i++)
            {
                string prefix = words[k].substr(0, i);
                for (size_t j = 0; j <= 10 && j <= words[k].size(); j++)
                {
                    string suffix = words[k].substr(words[k].size() - j, j);
                    m_WordMap[prefix + "#" + suffix] = k;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        if (m_WordMap.count(prefix + "#" + suffix) > 0)
        {
            return m_WordMap[prefix + "#" + suffix];
        }
        else
        {
            return -1;
        }
    }
};

/// <summary>
/// Leet code #642. Design Search Autocomplete System
/// 
/// Design a search autocomplete system for a search engine. Users may 
/// input a sentence (at least one word and end with a special character 
/// '#'). For each character they type except '#', you need to return the 
/// top 3 historical hot sentences that have prefix the same as the part 
/// of sentence already typed. Here are the specific rules:
/// The hot degree for a sentence is defined as the number of times a user 
/// typed the exactly same sentence before. 
/// The returned top 3 hot sentences should be sorted by hot degree (The 
/// first is the hottest one). If several sentences have the same degree 
/// of hot, you need to use ASCII-code order (smaller one appears first). 
/// If less than 3 hot sentences exist, then just return as many as you 
/// can.
/// When the input is a special character, it means the sentence ends, and 
/// in this case, you need to return an empty list.
///
/// Your job is to implement the following functions:
/// The constructor function:
/// AutocompleteSystem(String[] sentences, int[] times): This is the 
/// constructor. The input is historical data. Sentences is a string array 
/// consists of previously typed sentences. Times is the corresponding 
/// times a sentence has been typed. Your system should record these 
/// historical data.
/// Now, the user wants to input a new sentence. The following function 
/// will provide the next character the user types: 
/// List<String> input(char c): The input c is the next character typed by 
/// the user. The character will only be lower-case letters ('a' to 'z'), 
/// blank space (' ') or a special character ('#'). Also, the previously 
/// typed sentence should be recorded in your system. The output will be 
/// the top 3 historical hot sentences that have prefix the same as the 
/// part of sentence already typed.
///
/// Example:
/// Operation: AutocompleteSystem(["i love you", "island","ironman", 
/// "i love leetcode"], [5,3,2,2]) 
/// The system have already tracked down the following sentences and 
/// their corresponding times: 
/// "i love you" : 5 times 
/// "island" : 3 times 
/// "ironman" : 2 times 
/// "i love leetcode" : 2 times 
/// Now, the user begins another search: 
///
/// Operation: input('i') 
/// Output: ["i love you", "island","i love leetcode"] 
/// Explanation: 
/// There are four sentences that have prefix "i". Among them, "ironman" 
/// and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32
/// and 'r' has ASCII code 114, "i love leetcode" should be in front of 
/// "ironman". Also we only need to output top 3 hot sentences, so 
/// "ironman" will be ignored. 
///
/// Operation: input(' ') 
/// Output: ["i love you","i love leetcode"] 
/// Explanation: 
/// There are only two sentences that have prefix "i ". 
/// 
/// Operation: input('a') 
/// Output: [] 
/// Explanation: 
/// There are no sentences that have prefix "i a". 
/// 
/// Operation: input('#') 
/// Output: [] 
/// Explanation: 
/// The user finished the input, the sentence "i a" should be saved as a 
/// historical sentence in system. And the following input will be counted 
/// as a new search. 
///
/// Note:
/// 1. The input sentence will always start with a letter and end with '#',
///    and only one blank space will exist between two words. 
/// 2. The number of complete sentences that to be searched won't exceed 
///    100. 
/// 3. The length of each sentence including those in the historical data 
///    won't exceed 100. 
/// 4. Please use double-quote instead of single-quote when you write test 
///    cases even for a character input.
/// 5. Please remember to RESET your class variables declared in class 
///    AutocompleteSystem, as static/class variables are persisted across 
///    multiple test cases. Please see here for more details.
/// </summary>
class AutocompleteSystem
{
private:
    struct Trie
    {
        set<pair<int, string>> m_hot;
        vector<Trie *> children;

        Trie()
        {
            children = vector<Trie *>(27, nullptr);
        };

        ~Trie()
        {
            for (size_t i = 0; i < children.size(); i++)
            {
                if (children[i] != nullptr) delete children[i];
            }
        }

        void add_sentence(string sentence, int times)
        {
            pair<int, string> prev_str = make_pair(-times + 1, sentence);
            if (m_hot.count(prev_str) > 0)
            {
                m_hot.erase(prev_str);
            }
            m_hot.insert(make_pair(-times, sentence));
            if (m_hot.size() > 3) m_hot.erase(prev(m_hot.end()));
        }

        vector<string> get_hot_sentences()
        {
            vector<string> result;
            for (auto itr : m_hot)
            {
                result.push_back(itr.second);
            }
            return result;
        }

        Trie * next(char ch)
        {
            if (ch == '#') return nullptr;
            int i = ch - 'a';
            if (ch == ' ') i = 26;
            if (children[i] == nullptr)
            {
                children[i] = new Trie();
            }
            return children[i];
        }
    };

    Trie m_root;
    unordered_map<string, int> m_sentence_freq;
    vector<Trie*> m_arr;
    string m_sentence;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times)
    {
        for (size_t i = 0; i < sentences.size(); i++)
        {
            m_sentence_freq[sentences[i]] = times[i];
            for (size_t j = 0; j < sentences[i].size(); j++)
            {
                if (j == 0) m_arr.push_back(m_root.next(sentences[i][j]));
                else
                {
                    m_arr.push_back(m_arr.back()->next(sentences[i][j]));
                }
            }
            for (size_t j = 0; j < m_arr.size(); j++)
            {
                m_arr[j]->add_sentence(sentences[i], times[i]);
            }
            m_arr.clear();
        }
    }

    vector<string> input(char c)
    {
        vector<string> result;
        if (c == '#')
        {
            m_sentence_freq[m_sentence]++;
            for (size_t i = 0; i < m_arr.size(); i++)
            {
                m_arr[i]->add_sentence(m_sentence, m_sentence_freq[m_sentence]);
            }
            m_arr.clear();
            m_sentence.clear();
        }
        else
        {
            if (m_arr.empty())
            {
                m_arr.push_back(m_root.next(c));
            }
            else
            {
                m_arr.push_back(m_arr.back()->next(c));
            }
            m_sentence.push_back(c);
            result = m_arr.back()->get_hot_sentences();
        }
        return result;
    }
};

/// <summary>
/// Leet code #1032. Stream of Characters
/// 
/// Implement the StreamChecker class as follows:
///
/// StreamChecker(words): Constructor, init the data structure with the given 
/// words.
/// query(letter): returns true if and only if for some k >= 1, the last k 
/// characters queried (in order from oldest to newest, including this letter 
/// just queried) spell one of the words in the given list.
/// 
/// Example:
///
/// // init the dictionary.
/// StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); 
/// 
/// streamChecker.query('a'); // return false
/// streamChecker.query('b'); // return false
/// streamChecker.query('c'); // return false
/// streamChecker.query('d'); // return true, because 'cd' is in the wordlist
/// streamChecker.query('e'); // return false
/// streamChecker.query('f'); // return true, because 'f' is in the wordlist
/// streamChecker.query('g'); // return false
/// streamChecker.query('h'); // return false
/// streamChecker.query('i'); // return false
/// streamChecker.query('j'); // return false
/// streamChecker.query('k'); // return false
/// streamChecker.query('l'); // return true, because 'kl' is in the wordlist
///
/// Note:
///
/// 1. 1 <= words.length <= 2000
/// 2. 1 <= words[i].length <= 2000
/// 3. Words will only consist of lowercase English letters.
/// 4. Queries will only consist of lowercase English letters.
/// 5. The number of queries is at most 40000.
/// </summary>
class StreamChecker {
private:
    struct Trie
    {
        bool is_end;
        vector<Trie *> children;

        Trie()
        {
            is_end = false;
            children = vector<Trie *>(26, nullptr);
        };

        ~Trie()
        {
            for (size_t i = 0; i < children.size(); i++)
            {
                if (children[i] != nullptr) delete children[i];
            }
        }

        void insert(string word)
        {
            if (word.empty())
            {
                is_end = true;
            }
            else
            {
                int i = word[0] - 'a';
                if (children[i] == nullptr)
                {
                    children[i] = new Trie();
                }
                children[i]->insert(word.substr(1));
            }
        };

        Trie * next(char ch)
        {
            return children[ch - 'a'];
        }
    };

    Trie m_root;
    size_t m_max_len = 0;
    deque<char> m_buffer;

public:
    StreamChecker(vector<string>& words)
    {
        for (size_t i = 0; i < words.size(); i++)
        {
            string word = words[i];
            std::reverse(word.begin(), word.end());
            m_root.insert(word);
            m_max_len = max(m_max_len, word.size());
        }
    }

    bool query(char letter)
    {
        m_buffer.push_front(letter);
        if (m_buffer.size() > m_max_len) m_buffer.pop_back();
        Trie * trie = nullptr;
        for (size_t i = 0; i < m_buffer.size(); i++)
        {
            if (i == 0) trie = m_root.next(m_buffer[i]);
            else
            {
                trie = trie->next(m_buffer[i]);
            }
            if (trie == nullptr) return false;
            if (trie->is_end) return true;
        }
        return false;
    }
};

/// <summary>
/// Leet code #288. Unique Word Abbreviation    
/// 
/// An abbreviation of a word follows the form <first letter><number><last letter>. 
/// Below are some examples of word abbreviations: 
/// a) it                      --> it    (no abbreviation)
///      1
/// b) d|o|g                   --> d1g
///              1    1  1
///      1---5----0----5--8
/// c) i|nternationalizatio|n  --> i18n
///              1
///      1---5----0
/// d) l|ocalizatio|n          --> l10n
///
/// Assume you have a dictionary and given a word, find whether its 
/// abbreviation is unique in the dictionary. A word's abbreviation is unique 
/// if no other word from the dictionary has the same abbreviation.
/// Example: 
/// Given dictionary = [ "deer", "door", "cake", "card" ]
/// isUnique("dear") -> false
/// isUnique("cart") -> true
/// isUnique("cane") -> false
/// isUnique("make") -> true
/// </summary>
class ValidWordAbbr
{
private:
    unordered_map<string, unordered_set<string>> m_AbbrMap;
public:
    ValidWordAbbr(vector<string> &dictionary)
    {
        for (string word : dictionary)
        {
            string abbr;
            if (word.size() > 0) abbr.push_back(word[0]);
            if (word.size() > 1) abbr.push_back(word[word.size() - 1]);
            if (word.size() > 2) abbr.insert(1, to_string(word.size() - 2));
            m_AbbrMap[abbr].insert(word);
        }
    }
    bool isUnique(string word)
    {
        string abbr;
        if (word.size() > 0) abbr.push_back(word[0]);
        if (word.size() > 1) abbr.push_back(word[word.size() - 1]);
        if (word.size() > 2) abbr.insert(1, to_string(word.size() - 2));

        if ((m_AbbrMap.find(abbr) == m_AbbrMap.end()) ||
            ((m_AbbrMap[abbr].size()) == 1 && (m_AbbrMap[abbr].count(word) == 1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/// <summary>
/// Leet code #271. Encode and Decode Strings  
/// 
/// Design an algorithm to encode a list of strings to a string. The encoded 
/// string is then sent 
/// over the network and is decoded back to the original list of strings.
/// Machine 1 (sender) has the function: 
/// string encode(vector<string> strs) 
/// {
///  // ... your code
///  return encoded_string;
/// }
/// Machine 2 (receiver) has the function: vector<string> decode(string s) {
///   //... your code 
///  return strs;
/// }
/// So Machine 1 does: 
/// string encoded_string = encode(strs);
/// and Machine 2 does: 
/// vector<string> strs2 = decode(encoded_string);
/// strs2 in Machine 2 should be the same as strs in Machine 1. 
/// Implement the encode and decode methods. 
/// Note:
/// The string may contain any possible characters out of 256 valid ascii 
/// characters. Your algorithm should be 
/// generalized enough to work on any possible characters.
/// Do not use class member/global/static variables to store states. 
/// Your encode and decode algorithms should be stateless. 
/// Do not rely on any library method such as eval or serialize methods. 
/// You should implement your own encode/decode algorithm.
/// </summary>
class Codec
{
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs)
    {
        string result;
        for (size_t i = 0; i < strs.size(); i++)
        {
            result.push_back('(');
            result.append(to_string(strs[i].size()));
            result.push_back(')');
            result.append(strs[i]);
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s)
    {
        vector<string> result;
        int count = 0;
        string word;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (count > 0)
            {
                word.push_back(s[i]);
                count--;
                if (count == 0) result.push_back(word);
            }
            else if (s[i] == '(')
            {
                word.clear();
            }
            else if (s[i] == ')')
            {
                count = stoi(word);
                word.clear();
                if (count == 0) result.push_back(word);
            }
            else
            {
                word.push_back(s[i]);
            }
        }
        return result;
    }
};

/// <summary>
/// Leet code #588. Design In-Memory File System
/// 
/// Design an in-memory file system to simulate the following functions:
/// ls: Given a path in string format. If it is a file path, return a list 
/// that only contains this file's name. If it is a directory path, return 
/// the list of file and directory names in this directory. Your output 
/// (file and directory names together) should in lexicographic order.
/// mkdir: Given a directory path that does not exist, you should make a 
/// new directory according to the path. If the middle directories in the 
/// path don't exist either, you should create them as well. This function 
/// has void return type. 
/// addContentToFile: Given a file path and file content in string format. 
/// If the file doesn't exist, you need to create that file containing given 
/// content. If the file already exists, you need to append given content to 
/// original content. This function has void return type.
/// readContentFromFile: Given a file path, return its content in string 
/// format.
/// Example:
/// Input: 
/// ["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
/// [[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
/// Output:
/// [null,[],null,null,["a"],"hello"]
/// Explanation:
/// 
/// Note:
/// 1. You can assume all file or directory paths are absolute paths which 
///    begin with / and do not end with / except that the path is just "/".
/// 2. You can assume that all operations will be passed valid parameters and
///    users will not attempt to retrieve file content or list a directory or 
///    file that does not exist.
/// 3. You can assume that all directory names and file names only contain 
///    lower-case letters, and same names won't exist in the same directory.
/// </summary>
class FileSystem
{
private:
    struct FileInfo
    {
        string path;
        map<string, FileInfo*> directory;
        string content;
        bool is_file;
        FileInfo(string p, bool f = false) : path(p), is_file(f) {}
    };
    FileInfo *root = nullptr;

    vector<string> split_path(string path)
    {
        vector<string> result;
        size_t first = 0;
        size_t last = 0;
        while (last <= path.size())
        {
            if (last == path.size() || path[last] == '/')
            {
                result.push_back(path.substr(first, last - first));
                first = last + 1;
            }
            last++;
        }
        return result;
    }

    FileInfo * get_directory(string &path)
    {
        vector<string> paths = split_path(path);
        FileInfo * ptr = root;
        for (size_t i = 0; i < paths.size(); i++)
        {
            if (!paths[i].empty())
            {
                if (ptr->directory.count(paths[i]) == 0)
                {
                    ptr->directory[paths[i]] = new FileInfo(paths[i]);
                }
                ptr = ptr->directory[paths[i]];
            }
        }
        return ptr;
    }

public:
    FileSystem()
    {
        root = new FileInfo("", false);
    }
    ~FileSystem()
    {
        queue<FileInfo *> process_queue;
        process_queue.push(root);
        while (process_queue.empty())
        {
            FileInfo * ptr = process_queue.front();
            process_queue.pop();
            for (auto itr : ptr->directory)
            {
                process_queue.push(itr.second);
            }
            delete ptr;
        }
        root = nullptr;
    }

    vector<string> ls(string path)
    {
        vector<string> result;
        FileInfo * ptr;
        ptr = get_directory(path);
        if (ptr->is_file)
        {
            result.push_back(ptr->path);
        }
        else
        {
            for (auto itr : ptr->directory)
            {
                result.push_back(itr.first);
            }
        }
        return result;
    }

    void mkdir(string path)
    {
        get_directory(path);
    }

    void addContentToFile(string filePath, string content)
    {
        FileInfo *ptr = get_directory(filePath);
        ptr->is_file = true;
        ptr->content += content;
    }

    string readContentFromFile(string filePath)
    {
        FileInfo * ptr = get_directory(filePath);
        return (string)(ptr->content);
    }
};

/// <summary>
/// Leet code #604. Design Compressed String Iterator
/// 
/// Design and implement a data structure for a compressed string iterator. 
/// It should support the following operations: next and hasNext. 
/// The given compressed string will be in the form of each letter followed 
/// by a positive integer representing the number of this letter existing in 
/// the original uncompressed string. 
/// next() - if the original string still has uncompressed characters, return 
/// the next letter; Otherwise return a white space.
/// hasNext() - Judge whether there is any letter needs to be uncompressed. 
/// Note:
/// Please remember to RESET your class variables declared in StringIterator, 
/// as static/class variables are persisted across multiple test cases. 
/// Please see here for more details. 
/// Example: 
/// StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
/// iterator.next(); // return 'L'
/// iterator.next(); // return 'e'
/// iterator.next(); // return 'e'
/// iterator.next(); // return 't'
/// iterator.next(); // return 'C'
/// iterator.next(); // return 'o'
/// iterator.next(); // return 'd'
/// iterator.hasNext(); // return true
/// iterator.next(); // return 'e'
/// iterator.hasNext(); // return false
/// iterator.next(); // return ' '
/// </summary>
class StringIterator
{
private:
    size_t group_index = 0;
    size_t char_index = 0;
    vector<pair<char, int>> char_list;
public:
    StringIterator(string compressedString)
    {
        char ch;
        int ch_count = 0;
        string token;
        for (size_t i = 0; i < compressedString.size(); i++)
        {
            // if we hit a letter, we need to 
            if (isalpha(compressedString[i]))
            {
                if (!token.empty())
                {
                    ch_count = stoi(token);
                    char_list.push_back(make_pair(ch, ch_count));
                    token.clear();
                }
                ch = compressedString[i];
            }
            else if (isdigit(compressedString[i]))
            {
                token.push_back(compressedString[i]);
            }
        }
        ch_count = stoi(token);
        char_list.push_back(make_pair(ch, ch_count));
    }

    char next()
    {
        char ch;
        if (group_index < char_list.size())
        {
            ch = char_list[group_index].first;
            char_index++;
            if (char_index == (size_t)char_list[group_index].second)
            {
                group_index++;
                char_index = 0;
            }
        }
        else
        {
            ch = ' ';
        }
        return ch;
    }

    bool hasNext()
    {
        if (group_index < char_list.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/// <summary>
/// Leet code #635. Design Log Storage System 
/// 
/// You are given several logs that each log contains a unique id and 
/// timestamp. Timestamp is a string that has the following format: 
/// Year:Month:Day:Hour:Minute:Second, for example, 2017:01:01:23:59:59. 
/// All domains are zero-padded decimal numbers. 
/// Design a log storage system to implement the following functions:
/// void Put(int id, string timestamp): Given a log's unique id and 
/// timestamp, store the log in your storage system.
///
/// int[] Retrieve(String start, String end, String granularity): 
/// Return the id of logs whose timestamps are within the range from start 
/// to end. Start and end all have the same format as timestamp. However, 
/// granularity means the time level for consideration. For example, 
/// start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", 
/// granularity = "Day", it means that we need to find the logs within the 
/// range from Jan. 1st 2017 to Jan. 2nd 2017.
/// Example 1:
/// put(1, "2017:01:01:23:59:59");
/// put(2, "2017:01:01:22:59:59");
/// put(3, "2016:01:01:00:00:00");
/// retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year"); 
/// return [1,2,3], because you need to return all logs within 2016 and 
/// 2017.
/// retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour"); 
/// return [1,2], because you need to return all logs start from 
/// 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.
/// 
/// Note:
/// There will be at most 300 operations of Put or Retrieve.
/// Year ranges from [2000,2017]. Hour ranges from [00,23].
/// Output for Retrieve has no order required.
/// </summary>
class LogSystem
{
private:
    map<string, unordered_set<int>> log_map;

    string get_timestamp(string time, string granularity, bool end = false)
    {
        string result;
        int count = 0;
        string token = "";
        for (size_t i = 0; i <= time.size(); i++)
        {
            if (i == time.size() || (time[i] == ':'))
            {
                if (((count > 0) && (granularity == "Year")) ||
                    ((count > 1) && (granularity == "Month")) ||
                    ((count > 2) && (granularity == "Day")) ||
                    ((count > 3) && (granularity == "Hour")) ||
                    ((count > 4) && (granularity == "Minute")))
                {
                    if (end == false)
                    {
                        result.append(":00");
                    }
                    else
                    {
                        result.append(":99");
                    }
                }
                else
                {
                    if (count > 0) result.push_back(':');
                    result.append(token);
                }
                count++;
                token.clear();
            }
            else
            {
                token.push_back(time[i]);
            }
        }
        return result;
    }

public:
    LogSystem()
    {
    }

    void put(int id, string timestamp)
    {
        log_map[timestamp].insert(id);
    }

    vector<int> retrieve(string s, string e, string gra)
    {
        vector<int> result;
        string start_time = get_timestamp(s, gra);
        string end_time = get_timestamp(e, gra, true);
        map<string, unordered_set<int>>::iterator begin = log_map.lower_bound(start_time);
        map<string, unordered_set<int>>::iterator end = log_map.upper_bound(end_time);
        for (map<string, unordered_set<int>>::iterator itr = begin; itr != end; ++itr)
        {
            for (auto id : itr->second)
                result.push_back(id);
        }
        return result;
    }
};

/// <summary>
/// Leet code #676. Implement Magic Dictionary
/// 
/// Implement a magic directory with buildDict, and search methods.
/// For the method buildDict, you'll be given a list of non-repetitive 
/// words to build a dictionary.
/// 
/// For the method search, you'll be given a word, and judge whether if 
/// you modify exactly one character into another character in this word,
/// the modified word is in the dictionary you just built.
///
/// Example 1:
/// Input: buildDict(["hello", "leetcode"]), Output: Null
/// Input: search("hello"), Output: False
/// Input: search("hhllo"), Output: True
/// Input: search("hell"), Output: False
/// Input: search("leetcoded"), Output: False
/// Note:
/// You may assume that all the inputs are consist of lowercase letters 
/// a-z.
/// For contest purpose, the test data is rather small by now. You could 
/// think about highly efficient algorithm after the contest.
/// Please remember to RESET your class variables declared in class 
/// MagicDictionary, as static/class variables are persisted across 
/// multiple test cases. Please see here for more details.
/// </summary>
class MagicDictionary
{
private:
    unordered_map<int, vector<string>> m_dictionary;

public:
    // Initialize your data structure here.
    MagicDictionary()
    {
    }

    // Build a dictionary through a list of words
    void buildDict(vector<string> dict)
    {
        for (string str : dict)
        {
            m_dictionary[str.size()].push_back(str);
        }
    }

    // Returns if there is any word in the trie that equals to the given
    // word after modifying exactly one character
    bool search(string word)
    {
        for (string str : m_dictionary[word.size()])
        {
            int count = 0;
            for (size_t i = 0; i < word.size(); i++)
            {
                if (word[i] != str[i]) count++;
            }
            if (count == 1) return true;
        }
        return false;
    }
};

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
/// Leet code #170. Two Sum III - Data structure design    
/// 
/// Design and implement a TwoSum class. It should support the following 
/// operations: add and find.
/// add - Add the number to an internal data structure.
/// find - Find if there exists any pair of numbers which sum is equal to the 
/// value. 
/// For example,
/// add(1); add(3); add(5);
/// find(4) -> true
/// find(7) -> false
/// </summary>
class TwoSum
{
private:
    unordered_map<int, int> m_DataMap;
public:
    TwoSum()
    {
    }
    // Add the number to an internal data structure.
    void add(int number)
    {
        m_DataMap[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value)
    {
        for (auto itr : m_DataMap)
        {
            int other = value - itr.first;
            if (other == itr.first)
            {
                if (itr.second > 1) return true;
            }
            else if (m_DataMap.count(other) > 0)
            {
                return true;
            }
        }
        return false;
    }
};

/// <summary>
/// Leet code #535. Encode and Decode TinyURL   
/// 
/// Note: This is a companion problem to the System Design problem: 
/// Design TinyURL.
/// TinyURL is a URL shortening service where you enter a URL such as 
/// https://leetcode.com/problems/design-tinyurl and it returns a 
/// short URL such as http://tinyurl.com/4e9iAk.
///
/// Design the encode and decode methods for the TinyURL service. 
/// There is no restriction on how your encode/decode algorithm 
/// should work. You just need to ensure that a URL can be encoded 
/// to a tiny URL and the tiny URL can be decoded to the original URL.
/// </summary>
class TinyURL
{
private:
    unordered_map<string, string> m_Long2Short;
    unordered_map<string, string> m_Short2Long;

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (m_Long2Short.count(longUrl) == 0)
        {
            string shortUrl = "http://tinyurl.com/" + to_string(m_Long2Short.size());
            m_Long2Short[longUrl] = shortUrl;
            m_Short2Long[shortUrl] = longUrl;
        }
        return m_Long2Short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return m_Short2Long[shortUrl];
    }
};

/// <summary>
/// Leet code #1286. Iterator for Combination
///
/// Medium
///
/// Design an Iterator class, which has:
///
/// A constructor that takes a string characters of sorted distinct 
/// lowercase English letters and a number combinationLength as arguments.
/// A function next() that returns the next combination of length 
/// combinationLength in lexicographical order.
/// A function hasNext() that returns True if and only if there exists a 
/// next combination.
///
/// Example:
/// CombinationIterator iterator = 
///   new CombinationIterator("abc", 2);  // creates the iterator.
///
/// iterator.next(); // returns "ab"
/// iterator.hasNext(); // returns true
/// iterator.next(); // returns "ac"
/// iterator.hasNext(); // returns true
/// iterator.next(); // returns "bc"
/// iterator.hasNext(); // returns false
/// 
/// Constraints:
/// 1. 1 <= combinationLength <= characters.length <= 15
/// 2. There will be at most 10^4 function calls per test.
/// 3. It's guaranteed that all calls of the function next are valid.
/// </summary>
class CombinationIterator
{
private:
    vector<int> m_index;
    string m_string;
    void move_next(void)
    {
        if (hasNext())
        {
            int pos = m_index.size() - 1;
            while (true)
            {
                m_index[pos]++;
                if (m_index[pos] < (int)m_string.size())
                {
                    pos++;
                    if (pos == (int)m_index.size()) break;
                    else
                    {
                        m_index[pos] = m_index[pos - 1];
                    }
                }
                else
                {
                    pos--;
                    if (pos < 0) break;
                }
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength)
    {
        m_string = characters;
        for (int i = 0; i < combinationLength; i++)
        {
            m_index.push_back(i);
        }
    }

    string next()
    {
        string result;
        for (size_t i = 0; i < m_index.size(); i++)
        {
            result.push_back(m_string[m_index[i]]);
        }
        move_next();
        return result;
    }

    bool hasNext()
    {
        if (m_index[0] == m_string.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/// <summary>
/// Leet code #1357. Apply Discount Every n Orders
///
/// Medium
///
/// There is a sale in a supermarket, there will be a discount every n 
/// customer.
/// There are some products in the supermarket where the id of the 
/// i-th product is products[i] and the price per unit of this product 
/// is prices[i].
/// The system will count the number of customers and when the n-th 
/// customer arrive he/she will have a discount on the bill. (i.e if 
/// the cost is x the new cost is x - (discount * x) / 100). Then the 
/// system will start counting customers again.
/// The customer orders a certain amount of each product where product[i] 
/// is the id of the i-th product the customer ordered and amount[i] is 
/// the number of units the customer ordered of that product.
///
/// Implement the Cashier class:
///
/// Cashier(int n, int discount, int[] products, int[] prices) Initializes 
/// the object with n, the discount, the products and their prices.
/// double getBill(int[] product, int[] amount) returns the value of the 
/// bill and apply the discount if needed. Answers within 10^-5 of the 
/// actual value will be accepted as correct.
///
/// Example 1:
/// Input
/// ["Cashier","getBill","getBill","getBill","getBill","getBill",
///  "getBill","getBill"]
/// [[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],
/// [1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],
/// [[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
/// Output
/// [null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
/// Explanation
/// Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],
/// [100,200,300,400,300,200,100]);
/// cashier.getBill([1,2],[1,2]);  
/// // return 500.0, bill = 1 * 100 + 2 * 200 = 500.
/// cashier.getBill([3,7],[10,10]);                      
/// // return 4000.0
/// cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    
/// // return 800.0, The bill was 1600.0 but as this is the third 
/// customer, he has a discount of 50% which means his bill is 
/// only 1600 - 1600 * (50 / 100) = 800.
/// cashier.getBill([4],[10]); 
/// // return 4000.0
/// cashier.getBill([7,3],[10,10]); 
/// // return 4000.0
/// cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]);
/// // return 7350.0, Bill was 14700.0 but as the system counted three 
/// more customers, he will have a 50% discount and the bill becomes 7350.0
/// cashier.getBill([2,3,5],[5,3,2]); 
/// // return 2500.0
///
/// Constraints:
/// 1. 1 <= n <= 10^4
/// 2. 0 <= discount <= 100
/// 3. 1 <= products.length <= 200
/// 4. 1 <= products[i] <= 200
/// 5. There are not repeated elements in the array products.
/// 6. prices.length == products.length
/// 7. 1 <= prices[i] <= 1000
/// 8. 1 <= product.length <= products.length
/// 9. product[i] exists in products.
/// 10. amount.length == product.length
/// 11. 1 <= amount[i] <= 1000
/// 12. At most 1000 calls will be made to getBill.
/// 13. Answers within 10^-5 of the actual value will be accepted as 
///    correct.
/// </summary>
class Cashier 
{
private: 
    double m_discount;
    int m_batchSize;
    int m_count;
    vector<int> m_prices;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        m_discount = (double)(discount) / (double) 100.0;
        m_count = 0;
        m_batchSize = n;
        m_prices = vector<int>(200);
        for (size_t i = 0; i < products.size(); i++)
        {
            m_prices[products[i] - 1] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) 
    {
        double result = 0.0;
        for (size_t i = 0; i < product.size(); i++)
        {
            result += (double)m_prices[product[i] - 1] * (double)amount[i];
        }
        m_count++;
        if (m_count == m_batchSize)
        {
            m_count = 0;
            result = (1 - m_discount) * result;
        }
        return result;
    }
};

/// <summary>
/// Leet code #1381. Design a Stack With Increment Operation 
///
/// Medium
///
/// Design a stack which supports the following operations.
///
/// Implement the CustomStack class:
///
/// CustomStack(int maxSize) Initializes the object with maxSize which is 
/// the maximum number of elements in the stack or do nothing if the stack
/// reached the maxSize.
/// void push(int x) Adds x to the top of the stack if the stack hasn't 
/// reached the maxSize.
/// int pop() Pops and returns the top of stack or -1 if the stack is 
/// empty.
/// void inc(int k, int val) Increments the bottom k elements of the stack 
/// by val. If there are less than k elements in the stack, just increment 
/// all the elements in the stack.
/// 
/// Example 1:
/// Input
/// ["CustomStack","push","push","pop","push","push","push","increment",
///  "increment","pop","pop","pop","pop"]
/// [[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
/// Output
/// [null,null,null,2,null,null,null,null,null,103,202,201,-1]
/// Explanation
/// CustomStack customStack = new CustomStack(3); // Stack is Empty []
/// customStack.push(1);                          // stack becomes [1]
/// customStack.push(2);                          // stack becomes [1, 2]
/// customStack.pop();                            // return 2 
/// customStack.push(2);                          // stack becomes [1, 2]
/// customStack.push(3);                          // stack becomes [1, 2, 3]
/// customStack.push(4);                          // stack still [1, 2, 3], 
/// customStack.increment(5, 100);                // stack becomes [101, 102, 103]
/// customStack.increment(2, 100);                // stack becomes [201, 202, 103]
/// customStack.pop();                            // return 103 
/// customStack.pop();                            // return 202 
/// customStack.pop();                            // return 201 
/// customStack.pop();                            // return -1 
/// 
/// Constraints:
/// 1. 1 <= maxSize <= 1000
/// 2. 1 <= x <= 1000
/// 3. 1 <= k <= 1000
/// 4. 0 <= val <= 100
/// 5.  At most 1000 calls will be made to each method of increment, push 
///    and pop each separately.
/// </summary>
class CustomStack
{
private:
    int m_max_size;
    vector<int> m_stack;
public:
    CustomStack(int maxSize)
    {
        m_max_size = maxSize;
    }

    void push(int x)
    {
        if (m_stack.size() < (size_t)m_max_size)
        {
            m_stack.push_back(x);
        }
    }

    int pop()
    {
        if (m_stack.empty()) return -1;
        else
        {
            int val = m_stack.back();
            m_stack.pop_back();
            return val;
        }
    }

    void increment(int k, int val)
    {
        for (size_t i = 0; i < min((size_t)k, m_stack.size()); i++)
        {
            m_stack[i] += val;
        }
    }
};

/// <summary>
/// Leet code #1396 Design Underground System
/// 
/// Medium
///
/// Implement the class UndergroundSystem that supports three methods:
///
/// 1. checkIn(int id, string stationName, int t)
/// A customer with id card equal to id, gets in the station stationName 
/// at time t.
/// A customer can only be checked into one place at a time.
/// 2. checkOut(int id, string stationName, int t)
/// A customer with id card equal to id, gets out from the station 
/// stationName at time t.
/// 3. getAverageTime(string startStation, string endStation) 
/// Returns the average time to travel between the startStation and the 
/// endStation.
/// The average time is computed from all the previous traveling from 
/// startStation to endStation that happened directly.
/// Call to getAverageTime is always valid.
/// You can assume all calls to checkIn and checkOut methods are consistent. 
/// That is, if a customer gets in at time t1 at some station, then it gets 
/// out at time t2 with t2 > t1. All events happen in chronological order.
///
/// Example 1:
/// Input
/// ["UndergroundSystem","checkIn","checkIn","checkIn","checkOut",
/// "checkOut","checkOut","getAverageTime","getAverageTime","checkIn",
/// "getAverageTime","checkOut","getAverageTime"]
/// [[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],
/// [45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],
/// ["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],
/// ["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]
///
/// Output
/// [null,null,null,null,null,null,null,14.0,11.0,null,11.0,null,12.0]
/// Explanation
/// UndergroundSystem undergroundSystem = new UndergroundSystem();
/// undergroundSystem.checkIn(45, "Leyton", 3);
/// undergroundSystem.checkIn(32, "Paradise", 8);
/// undergroundSystem.checkIn(27, "Leyton", 10);
/// undergroundSystem.checkOut(45, "Waterloo", 15);
/// undergroundSystem.checkOut(27, "Waterloo", 20);
/// undergroundSystem.checkOut(32, "Cambridge", 22);
/// undergroundSystem.getAverageTime("Paradise", "Cambridge"); 
/// return 14.0. There was only one travel from "Paradise" 
/// (at time 8) to "Cambridge" (at time 22)
/// undergroundSystem.getAverageTime("Leyton", "Waterloo"); 
/// return 11.0. There were two travels from "Leyton" to "Waterloo", 
/// a customer with id=45 from time=3 to time=15 and a customer with 
/// id=27 from time=10 to time=20. So the average time is 
/// ((15-3) + (20-10) ) / 2 = 11.0
/// undergroundSystem.checkIn(10, "Leyton", 24);
/// undergroundSystem.getAverageTime("Leyton", "Waterloo");   
/// // return 11.0
/// undergroundSystem.checkOut(10, "Waterloo", 38);
/// undergroundSystem.getAverageTime("Leyton", "Waterloo"); 
/// // return 12.0
/// </summary>
class UndergroundSystem
{
private:
    unordered_map<string, unordered_map<string, pair<double, int>>> m_travel_time;
    unordered_map<int, pair<string, int>> m_person;
public:
    UndergroundSystem() 
    {

    }

    void checkIn(int id, string stationName, int t) 
    {
        m_person[id].first = stationName;
        m_person[id].second = t;
    }

    void checkOut(int id, string stationName, int t) 
    {
        string from = m_person[id].first;
        int t1 = m_person[id].second;
        string to = stationName;
        int t2 = t;
        m_travel_time[from][to].first += (double)t2 - (double)t1;
        m_travel_time[from][to].second++;
    }

    double getAverageTime(string startStation, string endStation) 
    {
        return (double)m_travel_time[startStation][endStation].first /
            m_travel_time[startStation][endStation].second;
    }
};

/// <summary>
/// Leet code #1428. Leftmost Column with at Least a One
/// 
/// Medium
///
/// (This problem is an interactive problem.)
/// A binary matrix means that all elements are 0 or 1. For each 
/// individual row of the matrix, this row is sorted in non-decreasing 
/// order.
///
/// Given a row-sorted binary matrix binaryMatrix, return leftmost 
/// column index(0-indexed) with at least a 1 in it. If such index 
/// doesn't exist, return -1.
///
/// You can't access the Binary Matrix directly.  You may only access 
/// the matrix using a BinaryMatrix interface:
/// BinaryMatrix.get(row, col) returns the element of the matrix at 
/// index (row, col) (0-indexed).
/// BinaryMatrix.dimensions() returns a list of 2 elements [rows, cols], 
/// which means the matrix is rows * cols.
/// Submissions making more than 1000 calls to BinaryMatrix.get will be 
/// judged Wrong Answer.  Also, any solutions that attempt to circumvent 
/// the judge will result in disqualification.
/// 
/// For custom testing purposes you're given the binary matrix mat 
/// as input in the following four examples. You will not have access 
/// the binary matrix directly.
///
/// Example 1:
/// Input: mat = [[0,0],[1,1]]
/// Output: 0
///
/// Example 2:
/// Input: mat = [[0,0],[0,1]]
/// Output: 1
///
/// Example 3:
/// Input: mat = [[0,0],[0,0]]
/// Output: -1
///
/// Example 4:
/// Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
/// Output: 1
///
/// Constraints:
/// 1. rows == mat.length
/// 2. cols == mat[i].length
/// 3. 1 <= rows, cols <= 100
/// 4. mat[i][j] is either 0 or 1.
/// 5. mat[i] is sorted in a non-decreasing way. 
/// </summary>
class BinaryMatrix
{
private:
    vector<vector<int>> m_matrix;
public:
    BinaryMatrix(vector<vector<int>> mat)
    {
        m_matrix = mat;
    }

    vector<int> dimensions(void)
    {
        vector<int> result(2);
        result[0] = m_matrix.size();
        if (!m_matrix.empty()) result[1] = m_matrix[0].size();

        return result;
    }


    int get(int row, int col)
    {
        if (row >= 0 && col >= 0 && row < (int)m_matrix.size() && col < (int)m_matrix[0].size())
        {
            return m_matrix[row][col];
        }
        else
        {
            return -1;
        }
    }

    int leftMostColumnWithOne(BinaryMatrix& binaryMatrix)
    {
        vector<int> dims = dimensions();
        int row = 0;
        int col = dims[1] - 1;
        int result = -1;
        while (row < dims[0] && col >= 0)
        {
            if (get(row, col) == 1)
            {
                result = col;
                col--;
            }
            else row++;
        }
        return result;
    }
};

/// <summary>
/// Leet code #1429. First Unique Number
/// 
/// Medium
///
/// You have a queue of integers, you need to retrieve the first unique 
/// integer in the queue.
/// 
/// Implement the FirstUnique class:
///
/// FirstUnique(int[] nums) Initializes the object with the numbers in the 
/// queue.
/// int showFirstUnique() returns the value of the first unique integer of 
/// the queue, and returns -1 if there is no such integer.
/// void add(int value) insert value to the queue.
///
/// Example 1:
/// Input: 
/// ["FirstUnique","showFirstUnique","add","showFirstUnique","add",
/// "showFirstUnique","add","showFirstUnique"]
/// [[[2,3,5]],[],[5],[],[2],[],[3],[]]
/// Output: 
/// [null,2,null,2,null,3,null,-1]
/// Explanation: 
/// FirstUnique firstUnique = new FirstUnique([2,3,5]);
/// firstUnique.showFirstUnique(); // return 2
/// firstUnique.add(5);            // the queue is now [2,3,5,5]
/// firstUnique.showFirstUnique(); // return 2
/// firstUnique.add(2);            // the queue is now [2,3,5,5,2]
/// firstUnique.showFirstUnique(); // return 3
/// firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
/// firstUnique.showFirstUnique(); // return -1
///
/// Example 2:
/// Input: 
/// ["FirstUnique","showFirstUnique","add","add","add","add","add",
/// "showFirstUnique"]
/// [[[7,7,7,7,7,7]],[],[7],[3],[3],[7],[17],[]]
/// Output: 
/// [null,-1,null,null,null,null,null,17]
/// Explanation: 
/// FirstUnique firstUnique = new FirstUnique([7,7,7,7,7,7]);
/// firstUnique.showFirstUnique(); // return -1
/// firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
/// firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
/// firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
/// firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
/// firstUnique.add(17);           // the queue is [7,7,7,7,7,7,7,3,3,7,17]
/// firstUnique.showFirstUnique(); // return 17
///
/// Example 3:
/// Input: 
/// ["FirstUnique","showFirstUnique","add","showFirstUnique"]
/// [[[809]],[],[809],[]]
/// Output: 
/// [null,809,null,-1]
/// Explanation: 
/// FirstUnique firstUnique = new FirstUnique([809]);
/// firstUnique.showFirstUnique(); // return 809
/// firstUnique.add(809);          // the queue is now [809,809]
/// firstUnique.showFirstUnique(); // return -1
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i] <= 10^8
/// 3. 1 <= value <= 10^8
/// 4. At most 50000 calls will be made to showFirstUnique and add.
/// </summary>
class FirstUnique
{
private:
    unordered_map<int, list<int>::iterator> m_values;
    unordered_set<int> m_duplicates;
    list<int> m_list;

public:
    FirstUnique(vector<int>& nums) 
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }

    int showFirstUnique() 
    {
        if (m_list.empty()) return -1;
        else return m_list.front();
    }

    void add(int value) 
    {
        if (m_values.count(value) > 0)
        {
            m_list.erase(m_values[value]);
            m_values.erase(value);
            m_duplicates.insert(value);
        }
        else
        {
            if (m_duplicates.count(value) == 0)
            {
                m_list.push_back(value);
                m_values[value] = prev(m_list.end());
            }
        }
    }
};

/// <summary>
/// LeetCode #173. Binary Search Tree Iterator  
///
/// Implement an iterator over a binary search tree (BST). Your iterator 
/// will be initialized with the root node of a BST.
/// Calling next() will return the next smallest number in the BST.
/// Note: next() and hasNext() should run in average O(1) time and uses 
/// O(h) memory, where h is the height of the tree.  
///
/// Your BSTIterator will be called like this:
/// BSTIterator i = BSTIterator(root);
/// while (i.hasNext()) cout << i.next();
/// </summary>
class BSTIterator
{
private:
    stack<TreeNode*> m_TreeStack;
public:
    /// <summary>
    /// Constructor, which will lead to the smallest child.
    /// </summary>
    BSTIterator(TreeNode* root)
    {
        TreeNode* node = root;
        while (node != nullptr)
        {
            m_TreeStack.push(node);
            node = node->left;
        }
    }

    /// <summary>
    /// return whether we have a next smallest number
    /// </summary>
    bool hasNext()
    {
        return (!m_TreeStack.empty());
    }

    /// <summary>
    /// return the next smallest number
    /// </summary>
    int next()
    {
        TreeNode* node = m_TreeStack.top();
        int value = node->val;
        m_TreeStack.pop();
        if (node->right != nullptr)
        {
            node = node->right;
            while (node != nullptr)
            {
                m_TreeStack.push(node);
                node = node->left;
            }
        }
        return value;
    }
};

/// <summary>
/// Leet code #919. Complete Binary Tree Inserter
/// 
/// A complete binary tree is a binary tree in which every level, except 
/// possibly the last, is completely filled, and all nodes are as far left 
/// as possible.
///
/// Write a data structure CBTInserter that is initialized with a complete 
/// binary tree and supports the following operations:
///
/// CBTInserter(TreeNode root) initializes the data structure on a given tree 
/// with head node root;
/// CBTInserter.insert(int v) will insert a TreeNode into the tree with value 
/// node.val = v so that the tree remains complete, and returns the value of 
/// the parent of the inserted TreeNode;
/// CBTInserter.get_root() will return the head node of the tree.
/// 
///
/// Example 1:
///
/// Input: inputs = ["CBTInserter","insert","get_root"], inputs = 
/// [[[1]],[2],[]]
/// Output: [null,1,[1,2]]
///
/// Example 2:
///
/// Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = 
/// [[[1,2,3,4,5,6]],[7],[8],[]]
/// Output: [null,3,4,[1,2,3,4,5,6,7,8]]
/// 
///
/// Note:
///
/// The initial given tree is complete and contains between 1 and 1000 nodes.
/// CBTInserter.insert is called at most 10000 times per test case.
/// Every value of a given or inserted node is between 0 and 5000.
/// </summary>
class CBTInserter {
private:
    deque<TreeNode*> m_Parent;
    TreeNode* m_Root;
public:
    CBTInserter(TreeNode* root)
    {
        m_Root = root;

        queue<TreeNode*> search;
        search.push(root);
        while (!search.empty())
        {
            TreeNode* node = search.front();
            search.pop();

            if (node->left != nullptr) search.push(node->left);
            if (node->right != nullptr) search.push(node->right);
            if (node->left == nullptr || node->right == nullptr)
            {
                m_Parent.push_back(node);
            }
        }
    }

    int insert(int v)
    {
        TreeNode* node = new TreeNode(v);
        TreeNode* parent = m_Parent.front();
        if (parent->left == nullptr)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
            m_Parent.pop_front();
        }
        m_Parent.push_back(node);
        return parent->val;
    }

    TreeNode* get_root()
    {
        return m_Root;
    }
};

/// <summary>
/// Leet code #703. Kth Largest Element in a Stream
/// 
/// Design a class to find the kth largest element in a stream. Note that it 
/// is the kth largest element in the sorted order, not the kth distinct 
/// element.
///
/// Your KthLargest class will have a constructor which accepts an integer k 
/// and an integer array nums, which contains initial elements from the 
/// stream. For each call to the method KthLargest.add, return the element 
/// representing the kth largest element in the stream.
///
/// Example:
///
/// int k = 3;
/// int[] arr = [4,5,8,2];
/// KthLargest kthLargest = new KthLargest(3, arr);
/// kthLargest.add(3);   // returns 4
/// kthLargest.add(5);   // returns 5
/// kthLargest.add(10);  // returns 5
/// kthLargest.add(9);   // returns 8
/// kthLargest.add(4);   // returns 8
/// Note: 
/// You may assume that nums' length ≥ k-1 and k ≥ 1.
/// </summary>
class KthLargest
{
private:
    priority_queue<int> heap;
    size_t size;
public:
    KthLargest(int k, vector<int> nums)
    {
        size = k;
        for (size_t i = 0; i < nums.size(); i++)
        {
            heap.push(0 - nums[i]);
            if (heap.size() > size) heap.pop();
        }
    }

    int add(int val)
    {
        heap.push(0 - val);
        if (heap.size() > size) heap.pop();
        return (0 - heap.top());
    }
};

/// <summary>
/// Leet Code 244. Shortest Word Distance II
///                 
/// Medium
///
/// Design a data structure that will be initialized with a string array, and 
/// then it should answer queries of the shortest distance between two 
/// different strings from the array.
///
/// Implement the WordDistance class:
/// WordDistance(String[] wordsDict) initializes the object with the strings 
/// array wordsDict.
///
/// int shortest(String word1, String word2) returns the shortest distance 
/// between word1 and word2 in the array wordsDict.
///
/// Example 1:
/// Input
/// ["WordDistance", "shortest", "shortest"]
/// [[["practice", "makes", "perfect", "coding", "makes"]], 
///  ["coding", "practice"], ["makes", "coding"]]
/// Output
/// [null, 3, 1]
///
/// Explanation
/// WordDistance wordDistance = new WordDistance(["practice", "makes", 
/// "perfect", "coding", "makes"]);
/// wordDistance.shortest("coding", "practice"); // return 3
/// wordDistance.shortest("makes", "coding");    // return 1
/// 
/// Constraints:
/// 1. 1 <= wordsDict.length <= 3 * 10^4
/// 2. 1 <= wordsDict[i].length <= 10
/// 3. wordsDict[i] consists of lowercase English letters.
/// 4. word1 and word2 are in wordsDict.
/// 5. word1 != word2
/// 6. At most 5000 calls will be made to shortest.
/// </summary>
class WordDistance
{
    unordered_map<string, vector<int>> m_StrPos;
    unordered_map<string, unordered_map<string, int>> m_StrDist;

public:
    WordDistance(vector<string>& words)
    {
        for (size_t i = 0; i < words.size(); i++)
        {
            m_StrPos[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2)
    {
        int distance = INT_MAX;
        if ((m_StrDist.count(word1) == 0) || (m_StrDist[word1].count(word2) == 0))
        {
            size_t i = 0, j = 0;
            while (i < m_StrPos[word1].size() && j < m_StrPos[word2].size())
            {
                distance = min(distance, abs(m_StrPos[word1][i] - m_StrPos[word2][j]));
                if (m_StrPos[word1][i] <= m_StrPos[word2][j])
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
            m_StrDist[word1][word2] = distance;
            m_StrDist[word2][word1] = distance;
        }
        else
        {
            distance = m_StrDist[word1][word2];
        }
        return distance;
    }
};

/// <summary>
/// Leet code #1472. Design Browser History
///                
/// Medium
/// 
/// You have a browser of one tab where you start on the homepage and you 
/// can visit another url, get back in the history number of steps or move 
/// forward in the history number of steps.
///
/// Implement the BrowserHistory class:
/// BrowserHistory(string homepage) Initializes the object with the 
/// homepage of the browser.
/// void visit(string url) visits url from the current page. It clears 
/// up all the forward history.
/// string back(int steps) Move steps back in history. If you can only 
/// return x steps in the history and steps > x, you will return only x 
/// steps. Return the current url after moving back in history at most 
/// steps.
/// string forward(int steps) Move steps forward in history. If you can 
/// only forward x steps in the history and steps > x, you will forward 
/// only x steps. Return the current url after forwarding in history at 
/// most steps.
/// 
/// Example:
/// Input:
/// ["BrowserHistory","visit","visit","visit","back","back","forward",
///  "visit","forward","back","back"]
/// [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],
/// [1],[1],[1],["linkedin.com"],[2],[2],[7]]
/// Output:
/// [null,null,null,null,"facebook.com","google.com","facebook.com",null,
/// "linkedin.com","google.com","leetcode.com"]
///
/// Explanation:
/// BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
/// browserHistory.visit("google.com");       
/// // You are in "leetcode.com". Visit "google.com"
/// browserHistory.visit("facebook.com");     
/// // You are in "google.com". Visit "facebook.com"
/// browserHistory.visit("youtube.com");      
/// // You are in "facebook.com". Visit "youtube.com"
/// browserHistory.back(1);                   
/// // You are in "youtube.com", move back to "facebook.com" 
/// // return "facebook.com"
/// browserHistory.back(1);                   
/// // You are in "facebook.com", move back to "google.com" 
/// // return "google.com"
/// browserHistory.forward(1);                
/// // You are in "google.com", move forward to "facebook.com" 
/// // return "facebook.com"
/// browserHistory.visit("linkedin.com");     
/// // You are in "facebook.com". Visit "linkedin.com"
/// browserHistory.forward(2);                
/// // You are in "linkedin.com", you cannot move forward any steps.
/// browserHistory.back(2);                   
/// // You are in "linkedin.com", move back two steps to "facebook.com" 
/// // then to "google.com". return "google.com"
/// browserHistory.back(7);                   
/// // You are in "google.com", you can move back only one step to 
/// // "leetcode.com". return "leetcode.com"
///
/// Constraints:
/// 1. 1 <= homepage.length <= 20
/// 2. 1 <= url.length <= 20
/// 3. 1 <= steps <= 100
/// 4. homepage and url consist of  '.' or lower case English letters.
/// 5. At most 5000 calls will be made to visit, back, and forward.
/// </summary>
class BrowserHistory 
{
private:
    vector<string> m_history;
    int m_index = 0;
public:
    BrowserHistory(string homepage) 
    {
        m_history.push_back(homepage);
        m_index = 0;
    }

    void visit(string url) 
    {
        m_history.resize(m_index + 1);
        m_history.push_back(url);
        m_index++;
    }

    string back(int steps) 
    {
        if (steps > m_index)
        {
            steps = m_index;
        }
        m_index -= steps;
        return m_history[m_index];
    }

    string forward(int steps) 
    {
        if (steps > (int)m_history.size() - 1 - m_index)
        {
            steps = m_history.size() - 1 - m_index;
        }
        m_index += steps;
        return m_history[m_index];
    }
};

/// <summary>
/// Leet code #843. Guess the Word
/// 
/// This problem is an interactive problem new to the LeetCode platform.
///  
/// We are given a word list of unique words, each word is 6 letters long, 
/// and one word in this list is chosen as secret.
/// 
/// You may call master.guess(word) to guess a word.  The guessed word 
/// should have type string and must be from the original list with 6 
/// lowercase letters.
///
/// This function returns an integer type, representing the number of 
/// exact matches (value and position) of your guess to the secret word.  
/// Also, if your guess is not in the given wordlist, it will return -1 
/// instead.
///
/// For each test case, you have 10 guesses to guess the word. At the end 
/// of any number of calls, if you have made 10 or less calls to 
/// master.guess and at least one of these guesses was the secret, you
/// pass the testcase.
///
/// Besides the example test case below, there will be 5 additional test 
/// cases, each with 100 words in the word list.  The letters of each word 
/// in those testcases were chosen independently at random from 'a' to 'z', 
/// such that every word in the given word lists is unique.
///
/// Example 1:
/// Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz",
/// "abcczz"]
/// 
/// Explanation:
/// master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
/// master.guess("acckzz") returns 6, because "acckzz" is secret and has 
/// all 6 matches.
/// master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
/// master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
/// master.guess("abcczz") returns 4, because "abcczz" has 4 matches.
///
/// We made 5 calls to master.guess and one of them was the secret, so we 
/// pass the test case.
/// Note:  Any solutions that attempt to circumvent the judge will 
/// result in disqualification.
/// </summary>
class Master
{
private:
    string secret;

public:
    Master(string str)
    {
        secret = str;
    }
    int guess(string str)
    {
        int result = 0;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == secret[i])
            {
                result++;
            }
        }
        return result;
    }
    /// <summary>
    /// Leet code #843. Guess the Word
    /// </summary>
    int match(string strA, string strB)
    {
        int result = 0;
        for (size_t i = 0; i < strA.size(); i++)
        {
            if (strA[i] == strB[i])
            {
                result++;
            }
        }
        return result;
    }

    string findSecretWord(vector<string>& wordlist, Master& master)
    {
        vector<int> zero_match(wordlist.size());
        for (size_t i = 0; i < wordlist.size(); i++)
        {
            for (size_t j = 0; j < wordlist.size(); j++)
            {
                if (match(wordlist[i], wordlist[j]) == 0)
                {
                    zero_match[i]++;
                }
            }
        }
        int min_match = 0;
        for (size_t i = 0; i < wordlist.size(); i++)
        {
            if (zero_match[i] < zero_match[min_match]) min_match = i;
        }
        int result = master.guess(wordlist[min_match]);
        if (result == 6) return wordlist[min_match];
        vector<string> new_word_list;
        for (size_t i = 0; i < wordlist.size(); i++)
        {
            if (match(wordlist[i], wordlist[min_match]) == result)
            {
                new_word_list.push_back(wordlist[i]);
            }
        }
        return findSecretWord(new_word_list, master);
    }
};

/// <summary>
/// Assume you have a sales organization 
/// Employee,Manager,ItemsSold
/// Alice,,5
/// Bob,Alice,3
/// Carol,Bob,2
/// David,Bob,3
/// Eve,Alice,2
/// Ferris,Eve,1
///
/// Please print it as the following format
/// Alice 16
/// |-Bob 8
/// | |-Carol 2
/// | |-David 3
/// |-Eve 3
/// | |-Ferris 1
/// </summary>
class SalesOrg
{
private:
    map<string, set<string>> m_Team;
    map<string, int> m_SalesAmount;
    map<string, string> m_Manager;

    string print(string& employee, int level)
    {
        string result;
        for (size_t i = 0; i < (size_t)level; i++)
        {
            if (i > 0) result += " ";
            result += "|";
        }
        if (level > 0) result += "-";
        result += employee;
        result += " ";
        result += to_string(m_SalesAmount[employee]);
        return result;
    }

    void print(string& employee, int level, vector<string>& result)
    {
        result.push_back(print(employee, level));
        if (m_Team[employee].empty()) return;
        for (string team_member : m_Team[employee])
        {
            print(team_member, level + 1, result);
        }
    }
public:
    SalesOrg()
    {
    }

    void addSalesRecord(string employee, string manager, int amount)
    {
        m_Manager[employee] = manager;
        while (true)
        {
            m_SalesAmount[employee] += amount;
            manager = m_Manager[employee];
            m_Team[manager].insert(employee);
            employee = manager;
            if (employee == "") break;
        }
    }

    vector<string> print()
    {
        vector<string> result;
        for (string team_member : m_Team[""])
        {
            print(team_member, 0, result);
        }
        return result;
    }
};

/// <summary>
/// Leet code #1476. Subrectangle Queries
///
/// Medium
///
/// Implement the class SubrectangleQueries which receives a rows x cols 
/// rectangle as a matrix of integers in the constructor and supports 
/// two methods:
///
/// 1. updateSubrectangle(int row1, int col1, int row2, int col2, 
///    int newValue)
/// Updates all values with newValue in the subrectangle whose upper left 
/// coordinate is (row1,col1) and bottom right coordinate is (row2,col2).
///
/// 2. getValue(int row, int col)
/// Returns the current value of the coordinate (row,col) from the 
/// rectangle.
///
/// Example 1:
/// Input
/// ["SubrectangleQueries","getValue","updateSubrectangle","getValue",
/// "getValue","updateSubrectangle","getValue","getValue"]
/// [[[[1,2,1],[4,3,4],[3,2,1],[1,1,1]]],[0,2],[0,0,3,2,5],[0,2],[3,1],
/// [3,0,3,2,10],[3,1],[0,2]]
/// Output
/// [null,1,null,5,5,null,10,5]
/// Explanation
/// SubrectangleQueries subrectangleQueries = new SubrectangleQueries
/// ([[1,2,1],[4,3,4],[3,2,1],[1,1,1]]);  
/// // The initial rectangle (4x3) looks like:
/// // 1 2 1
/// // 4 3 4
/// // 3 2 1
/// // 1 1 1
/// subrectangleQueries.getValue(0, 2); // return 1
/// subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
/// // After this update the rectangle looks like:
/// // 5 5 5
/// // 5 5 5
/// // 5 5 5
/// // 5 5 5 
/// subrectangleQueries.getValue(0, 2); // return 5
/// subrectangleQueries.getValue(3, 1); // return 5
/// subrectangleQueries.updateSubrectangle(3, 0, 3, 2, 10);
/// // After this update the rectangle looks like:
/// // 5   5   5
/// // 5   5   5
/// // 5   5   5
/// // 10  10  10 
/// subrectangleQueries.getValue(3, 1); // return 10
/// subrectangleQueries.getValue(0, 2); // return 5
///
/// Example 2:
/// Input
/// ["SubrectangleQueries","getValue","updateSubrectangle",
/// "getValue","getValue","updateSubrectangle","getValue"]
/// [[[[1,1,1],[2,2,2],[3,3,3]]],[0,0],[0,0,2,2,100],[0,0],[2,2],
///  [1,1,2,2,20],[2,2]]
/// Output
/// [null,1,null,100,100,null,20]
/// Explanation
/// SubrectangleQueries subrectangleQueries = new SubrectangleQueries
/// ([[1,1,1],[2,2,2],[3,3,3]]);
/// subrectangleQueries.getValue(0, 0); // return 1
/// subrectangleQueries.updateSubrectangle(0, 0, 2, 2, 100);
/// subrectangleQueries.getValue(0, 0); // return 100
/// subrectangleQueries.getValue(2, 2); // return 100
/// subrectangleQueries.updateSubrectangle(1, 1, 2, 2, 20);
/// subrectangleQueries.getValue(2, 2); // return 20
/// 
/// Constraints:
/// 1. There will be at most 500 operations considering both methods: 
///    updateSubrectangle and getValue.
/// 2. 1 <= rows, cols <= 100
/// 3. rows == rectangle.length
/// 4. cols == rectangle[i].length
/// 5. 0 <= row1 <= row2 < rows
/// 6. 0 <= col1 <= col2 < cols
/// 7. 1 <= newValue, rectangle[i][j] <= 10^9
/// 8. 0 <= row < rows
/// 9. 0 <= col < cols
/// </summary> 
class SubrectangleQueries 
{
private:
    vector<vector<int>> m_rectangle;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) 
    {
        m_rectangle = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) 
    {
        for (int i = row1; i <= row2; i++)
        {
            for (int j = col1; j <= col2; j++)
            {
                m_rectangle[i][j] = newValue;
            }
        }
    }

    int getValue(int row, int col) 
    {
        return m_rectangle[row][col];
    }
};

/// <summary>
/// Leet code #1483. Kth Ancestor of a Tree Node
///
/// Hard
///
/// You are given a tree with n nodes numbered from 0 to n-1 in the form 
/// of a parent array where parent[i] is the parent of node i. The root 
/// of the tree is node 0.
///
/// Implement the function getKthAncestor(int node, int k) to return 
/// the k-th ancestor of the given node. If there is no such ancestor, 
/// return -1.
///
/// The k-th ancestor of a tree node is the k-th node in the path from 
/// that node to the root.
///
/// Example:
/// Input:
/// ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
/// [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
/// Output:
/// [null,1,0,-1]
///
/// Explanation:
/// TreeAncestor treeAncestor = new TreeAncestor(7, [-1,0,0,1,1,2,2]);
/// treeAncestor.getKthAncestor(3, 1);  
/// // returns 1 which is the parent of 3
/// treeAncestor.getKthAncestor(5, 2);  
/// // returns 0 which is the grandparent of 5
/// treeAncestor.getKthAncestor(6, 3);  
/// // returns -1 because there is no such ancestor
///
/// Constraints:
/// 1. 1 <= k <= n <= 5*10^4
/// 2. parent[0] == -1 indicating that 0 is the root node.
/// 3. 0 <= parent[i] < n for all 0 < i < n
/// 4. 0 <= node < n
/// 5. There will be at most 5*10^4 queries.
/// </summary> 
class TreeAncestor 
{
private:
    vector<vector<int>> m_ancestor;
public:
    TreeAncestor(int n, vector<int>& parent) 
    {
        m_ancestor = vector<vector<int>>(n);
        for (int i = 0; i < n; i++)
        {
            m_ancestor[i].push_back(parent[i]);
        }
        bool bContinue = true;
        int level = 0;
        while (bContinue)
        {
            bContinue = false;
            for (int i = 0; i < n; i++)
            {
                int p = m_ancestor[i].back();
                if (p != -1)
                {
                    bContinue = true;
                    int next_p = m_ancestor[p][level];
                    m_ancestor[i].push_back(next_p);
                }
                else
                {
                    m_ancestor[i].push_back(-1);
                }
            }
            level++;
        }
    }

    int getKthAncestor(int node, int k) 
    {
        int bit = 0;
        int parent = -1;
        for (size_t i = 0; i < m_ancestor[node].size(); i++)
        {
            bit = (bit << 1) + 1;
            parent = m_ancestor[node][i];
            if (k <= bit)
            {
                k = k & (bit >> 1);
                break;
            }
        }
        if (k == 0 || parent == -1) return parent;
        else return getKthAncestor(parent, k);
    }
};

/// <summary>
/// Leet code #1500. Design a File Sharing System
///
/// Medium
///
/// We will use a file-sharing system to share a very large file which 
/// consists of m small chunks with IDs from 1 to m.
///
/// When users join the system, the system should assign a unique ID to 
/// them. The unique ID should be used once for each user, but when a user 
/// leaves the system, the ID can be reused again.
///
/// Users can request a certain chunk of the file, the system should return 
/// a list of IDs of all the users who have this chunk. After that, if at 
/// least one other has this chunk, the user who requested the chunk will 
/// get it.
///
/// Implement the FileSharing class:
/// FileSharing(int m) Initializes the object with the number of the chunks 
/// of the file m.
/// int join(int[] ownedChunks): A new user joined the system owning some 
/// chunks of the file, the system should assign an id to the user which is 
/// the smallest positive integer not taken by any other user. Return the 
/// assigned id.
/// void leave(int userID): The user with userID will leave the system, you 
/// cannot take file chunks from them anymore.
/// int[] request(int userID, int chunkID): The user with userID requested 
/// the file chunk with chunkID. Return a list of the IDs of all users that 
/// own this chunk sorted in ascending order.
/// 
///
/// Follow-ups:
/// 1. What happens if the system identifies the user by their IP address 
///    instead of their unique ID and users disconnect and connect from the 
///    system with the same IP?
/// 2. If the users in the system join and leave the system frequently without
///    requesting any chunks, will your solution still be efficient?
/// 3. If all each user join the system one time, request all files and then 
///    leave, will your solution still be efficient?
/// 4. If the system will be used to share n files where the ith file consists 
///    of m[i], what are the changes you have to do?
/// 
/// Example:
///
/// Input:
/// ["FileSharing","join","join","join","request","request","leave",
/// "request","leave","join"]
/// []
/// Output:
/// [null,1,2,3,[2],[1,2],null,[],null,1]
/// Explanation:
/// FileSharing fileSharing = new FileSharing(4); 
/// // We use the system to share a file of 4 chunks.
/// fileSharing.join([1, 2]);    
/// // A user who has chunks [1,2] joined the system, assign id = 1 to 
/// //  them and return 1.
/// fileSharing.join([2, 3]);    
/// // A user who has chunks [2,3] joined the system, assign id = 2 to them 
/// // and return 2.
/// fileSharing.join([4]);       // A user who has chunk [4] joined the 
/// // system, assign id = 3 to them and return 3.
/// fileSharing.request(1, 3);   
/// // The user with id = 1 requested the third file chunk, as only the user
/// // with id = 2 has the file, return [2] . 
/// Notice that user 1 now has chunks [1,2,3].
/// fileSharing.request(2, 2);   
/// // The user with id = 2 requested the second file chunk, users with 
/// // ids [1,2] have this chunk, thus we return [1,2]. We don't care if 
/// // the user has the file and request it, we just return all the users 
/// // that can give them the file.
/// fileSharing.leave(1);        
/// // The user with id = 1 left the system, all the file chunks with them 
/// // are no longer available for other users.
/// fileSharing.request(2, 1);   
/// // The user with id = 2 requested the first file chunk, no one in the 
/// // system has this chunk, we return empty list [].
/// fileSharing.leave(2);        
/// // The user with id = 2 left the system, all the file chunks with 
/// // them are no longer available for other users.
/// fileSharing.join([]);        
/// // A user who doesn't have any chunks joined the system, assign 
/// // id = 1 to them and return 1. Notice that ids 1 and 2 are free and we 
/// // can reuse them.
/// 
/// Constraints:
/// 1. 1 <= m <= 10^5
/// 2. 0 <= ownedChunks.length <= min(100, m)
/// 3. 1 <= ownedChunks[i] <= m
/// 4. Values of ownedChunks are unique.
/// 5. 1 <= chunkID <= m
/// 6. userID is guaranteed to be a user in the system if you assign the 
///   IDs correctly. 
/// 7. At most 10^4 calls will be made to join, leave and request.
/// 8. Each call to leave will have a matching call for join.
/// </summary> 
class FileSharing 
{
private:
    vector<set<int>> chunk_owners;
    unordered_map<int, unordered_set<int>> owning_chunks;
    set<int> reused_ids;
public:
    FileSharing(int m) 
    {
        chunk_owners = vector<set<int>>(m);
    }

    int join(vector<int> ownedChunks) 
    {
        int id = 0;
        if (reused_ids.empty())
        {
            id = owning_chunks.size() + 1;
        }
        else
        {
            id = *(reused_ids.begin());
            reused_ids.erase(id);
        }
        for (size_t i = 0; i < ownedChunks.size(); i++)
        {
            chunk_owners[ownedChunks[i] - 1].insert(id);
        }
        owning_chunks[id].insert(ownedChunks.begin(), ownedChunks.end());
        
        return id;
    }

    void leave(int userID) 
    {
        for (int chunk_id : owning_chunks[userID])
        {
            chunk_owners[chunk_id -1].erase(userID);
        }
        owning_chunks.erase(userID);
        reused_ids.insert(userID);
    }

    vector<int> request(int userID, int chunkID) 
    {
        vector<int> result;
        for (int owner : chunk_owners[chunkID -1])
        {
            result.push_back(owner);
        }
        if (!result.empty())
        {
            chunk_owners[chunkID - 1].insert(userID);
            owning_chunks[userID].insert(chunkID);
        }
        return result;
    }
};

/// <summary>
/// Leet code #1600. Throne Inheritance
/// 
/// Medium
///
/// A kingdom consists of a king, his children, his grandchildren, and so 
/// on. Every once in a while, someone in the family dies or a child is 
/// born.
///
/// The kingdom has a well-defined order of inheritance that consists of 
/// the king as the first member. Let's define the recursive function 
/// Successor(x, curOrder), which given a person x and the inheritance 
/// order so far, returns who should be the next person after x in the 
/// order of inheritance.
///
/// Successor(x, curOrder):
///  if x has no children or all of x's children are in curOrder:
///    if x is the king return null
///    else return Successor(x's parent, curOrder)
///  else return x's oldest child who's not in curOrder
/// For example, assume we have a kingdom that consists of the king, his 
/// children Alice and Bob (Alice is older than Bob), and finally Alice's 
/// son Jack.
///
/// In the beginning, curOrder will be ["king"].
/// Calling Successor(king, curOrder) will return Alice, so we append to 
/// curOrder to get ["king", "Alice"].
/// Calling Successor(Alice, curOrder) will return Jack, so we append to 
/// curOrder to get ["king", "Alice", "Jack"].
/// Calling Successor(Jack, curOrder) will return Bob, so we append to 
/// curOrder to get ["king", "Alice", "Jack", "Bob"].
/// Calling Successor(Bob, curOrder) will return null. Thus the order of 
/// inheritance will be ["king", "Alice", "Jack", "Bob"].
/// Using the above function, we can always obtain a unique order of 
/// inheritance.
///
/// Implement the ThroneInheritance class:
///
/// ThroneInheritance(string kingName) Initializes an object of the 
/// ThroneInheritance class. The name of the king is given as part of the 
/// constructor.
/// void birth(string parentName, string childName) Indicates that 
/// parentName gave birth to childName.
/// void death(string name) Indicates the death of name. The death of 
/// the person doesn't affect the Successor function nor the current 
/// inheritance order. You can treat it as just marking the person as dead.
/// string[] getInheritanceOrder() Returns a list representing the current 
/// order of inheritance excluding dead people.
///
/// Example 1:
/// Input
/// ["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", 
/// "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
/// [["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], 
/// ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], 
/// ["bob"], [null]]
/// Output
/// [null, null, null, null, null, null, null, ["king", "andy", "matthew", 
/// "bob", "alex", "asha", "catherine"], null, ["king", "andy", "matthew", 
/// "alex", "asha", "catherine"]]
///
/// Explanation
/// ThroneInheritance t= new ThroneInheritance("king"); // order: king
/// t.birth("king", "andy"); // order: king > andy
/// t.birth("king", "bob"); // order: king > andy > bob
/// t.birth("king", "catherine"); // order: king > andy > bob > catherine
/// t.birth("andy", "matthew"); // order: king > andy > matthew > bob > catherine
/// t.birth("bob", "alex"); // order: king > andy > matthew > bob > alex > catherine
/// t.birth("bob", "asha"); // order: king > andy > matthew > bob > alex > asha > catherine
/// t.getInheritanceOrder(); // return ["king", "andy", "matthew", "bob", "alex", "asha", "catherine"]
/// t.death("bob"); // order: king > andy > matthew > bob > alex > asha > catherine
/// t.getInheritanceOrder(); // return ["king", "andy", "matthew", "alex", "asha", "catherine"]
///
/// Constraints:
/// 1. 1 <= kingName.length, parentName.length, childName.length, 
///    name.length <= 15
/// 2. kingName, parentName, childName, and name consist of lowercase 
///    English letters only.
/// 3. All arguments childName and kingName are distinct.
/// 4. All name arguments of death will be passed to either the 
///    constructor or as childName to birth first.
/// 5. For each call to birth(parentName, childName), it is guaranteed 
///    that parentName is alive.
/// 6. At most 10^5 calls will be made to birth and death.
/// 7. At most 10 calls will be made to getInheritanceOrder.
/// </summary>
class ThroneInheritance 
{
private:
    unordered_map<string, deque<string>> m_children;
    unordered_set<string> m_dead;
public:
    ThroneInheritance(string kingName) 
    {
        m_children["GOD"].push_back(kingName);
    }

    void birth(string parentName, string childName) 
    {
        m_children[parentName].push_back(childName);
    }

    void death(string name) 
    {
        m_dead.insert(name);
    }

    vector<string> getInheritanceOrder() 
    {
        vector<string> result;
        deque<string> queue = m_children["GOD"];
        while (!queue.empty())
        {
            string person = queue.front();
            queue.pop_front();
            if (m_dead.count(person) == 0) result.push_back(person);
            queue.insert(queue.begin(), m_children[person].begin(), m_children[person].end());
        }
        return result;
    }
};

/// <summary>
/// Leet code #1603. Design Parking System
/// 
/// Easy
///
/// Design a parking system for a parking lot. The parking lot has three 
/// kinds of parking spaces: big, medium, and small, with a fixed number 
/// of slots for each size.
///
/// Implement the ParkingSystem class:
/// ParkingSystem(int big, int medium, int small) Initializes object of 
/// the ParkingSystem class. The number of slots for each parking space 
/// are given as part of the constructor.
/// bool addCar(int carType) Checks whether there is a parking space of 
/// carType for the car that wants to get into the parking lot. carType 
/// can be of three kinds: big, medium, or small, which are represented 
/// by 1, 2, and 3 respectively. A car can only park in a parking space 
/// of its carType. If there is no space available, return false, else 
/// park the car in that size space and return true.
/// 
/// Example 1:
/// Input
/// ["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
/// [[1, 1, 0], [1], [2], [3], [1]]
/// Output
/// [null, true, true, false, false]
/// Explanation
/// ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
/// parkingSystem.addCar(1); // return true because there is 1 available slot for a big car
/// parkingSystem.addCar(2); // return true because there is 1 available slot for a medium car
/// parkingSystem.addCar(3); // return false because there is no available slot for a small car
/// parkingSystem.addCar(1); // return false because there is no available slot for a big car. It is already occupied.
///
/// Constraints:
/// 1. 0 <= big, medium, small <= 1000
/// 2. carType is 1, 2, or 3
/// 3. At most 1000 calls will be made to addCar
/// </summary>
class ParkingSystem
{
private:
    vector<int> m_capacity;
public:
    ParkingSystem(int big, int medium, int small) 
    {
        m_capacity.push_back(big);
        m_capacity.push_back(medium);
        m_capacity.push_back(small);
    }

    bool addCar(int carType) 
    {
        if (m_capacity[carType - 1] == 0)
        {
            return false;
        }
        else
        {
            m_capacity[carType - 1]--;
            return true;
        }
    }
};

/// <summary>
/// Leet code #1586. Binary Search Tree Iterator II
/// 
/// Medium
///
/// Implement the BSTIterator class that represents an iterator over the 
/// in-order traversal of a binary search tree (BST):
//
/// BSTIterator(TreeNode root) Initializes an object of the BSTIterator 
/// class. The root of the BST is given as part of the constructor. The 
/// pointer should be initialized to a non-existent number smaller than 
/// any element in the BST.
/// boolean hasNext() Returns true if there exists a number in the 
/// traversal to the right of the pointer, otherwise returns false.
/// int next() Moves the pointer to the right, then returns the number 
/// at the pointer.
/// boolean hasPrev() Returns true if there exists a number in the 
/// traversal to the left of the pointer, otherwise returns false.
/// int prev() Moves the pointer to the left, then returns the number 
/// at the pointer.
/// Notice that by initializing the pointer to a non-existent smallest 
/// number, the first call to next() will return the smallest element in 
/// the BST.
///
/// You may assume that next() and prev() calls will always be valid. 
/// That is, there will be at least a next/previous number in the in-order 
/// traversal when next()/prev() is called. 
///
/// Follow up: Could you solve the problem without precalculating the 
/// values of the tree?
///
/// Example 1:
/// Input
/// ["BSTIterator", "next", "next", "prev", "next", "hasNext", "next", 
/// "next", "next", "hasNext", "hasPrev", "prev", "prev"]
/// [[[7, 3, 15, null, null, 9, 20]], [null], [null], [null], [null], 
/// [null], [null], [null], [null], [null], [null], [null], [null]]
/// Output
/// [null, 3, 7, 3, 7, true, 9, 15, 20, false, true, 15, 9]
/// Explanation 
/// The underlined element is where the pointer currently is.
/// BSTIterator bSTIterator = new BSTIterator
/// ([7, 3, 15, null, null, 9, 20]); 
/// // state is   [3, 7, 9, 15, 20]
/// bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 3
/// bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 7
/// bSTIterator.prev(); // state becomes [3, 7, 9, 15, 20], return 3
/// bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 7
/// bSTIterator.hasNext(); // return true
/// bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 9
/// bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 15
/// bSTIterator.next(); // state becomes [3, 7, 9, 15, 20], return 20
/// bSTIterator.hasNext(); // return false
/// bSTIterator.hasPrev(); // return true
/// bSTIterator.prev(); // state becomes [3, 7, 9, 15, 20], return 15
/// bSTIterator.prev(); // state becomes [3, 7, 9, 15, 20], return 9
///
/// Constraints:
/// 1. The number of nodes in the tree is in the range [1, 10^5].
/// 2. 0 <= Node.val <= 10^6
/// 3. At most 10^5 calls will be made to hasNext, next, hasPrev, and prev.
/// </summary>
class BSTIteratorII 
{
private:
    vector<TreeNode*> m_parents;
    TreeNode* m_node = nullptr;
public:
    BSTIteratorII(TreeNode* root) 
    {
        while (root != nullptr)
        {
            m_parents.push_back(root);
            root = root->left;
        }
    }

    bool hasNext() 
    {
        if (m_node != nullptr && m_node->right != nullptr)
        {
            return true;
        }
        for (size_t i = 0; i < m_parents.size(); i++)
        {
            if (m_parents[i] != nullptr)
            {
                if (m_node == nullptr || m_parents[i]->val >= m_node->val)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int next() 
    {
        if (m_node != nullptr && m_node->right != nullptr)
        {
            m_parents.push_back(m_node);
            m_node = m_node->right;
            while (m_node != nullptr)
            {
                m_parents.push_back(m_node);
                m_node = m_node->left;
            }
        }
        else
        {
            while (!m_parents.empty() && m_parents.back() != nullptr && 
                    m_node != nullptr && m_parents.back()->val < m_node->val)
            {
                m_parents.pop_back();
            }
        }
        m_node = m_parents.back();
        m_parents.pop_back();
        return m_node->val;
    }

    bool hasPrev() 
    {
        if (m_node != nullptr && m_node->left != nullptr)
        {
            return true;
        }
        for (size_t i = 0; i < m_parents.size(); i++)
        {
            if (m_parents[i] != nullptr && m_node != nullptr)
            {
                if (m_parents[i]->val < m_node->val)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int prev() 
    {
        if (m_node != nullptr && m_node->left != nullptr)
        {
            m_parents.push_back(m_node);
            m_node = m_node->left;
            while (m_node != nullptr)
            {
                m_parents.push_back(m_node);
                m_node = m_node->right;
            }
        }
        else
        {
            while (!m_parents.empty() && m_parents.back() != nullptr && 
                   m_node != nullptr && m_parents.back()->val >= m_node->val)
            {
                m_parents.pop_back();
            }
        }
        m_node = m_parents.back();
        m_parents.pop_back();
        return m_node->val;
    }
};


/// <summary>
/// Leet code #1570. Dot Product of Two Sparse Vectors
/// 
/// Medium
///
/// Given two sparse vectors, compute their dot product.
///
/// Implement class SparseVector:
/// SparseVector(nums) Initializes the object with the vector nums
/// dotProduct(vec) Compute the dot product between the instance of 
/// SparseVector and vec
/// A sparse vector is a vector that has mostly zero values, you should
/// store the sparse vector efficiently and compute the dot product 
/// between two SparseVector.
///
/// Follow up: What if only one of the vectors is sparse?
///
/// Example 1:
/// Input: nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
/// Output: 8
/// Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
/// v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
///
/// Example 2:
/// Input: nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
/// Output: 0
/// Explanation: v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
/// v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
///
/// Example 3:
/// Input: nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
/// Output: 6
/// Constraints:
/// 1. n == nums1.length == nums2.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= nums1[i], nums2[i] <= 100
/// </summary>
class SparseVector 
{
private:
    vector<pair<int, int>> m_values;
public:

    SparseVector(vector<int>& nums) 
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0) m_values.push_back(make_pair(i, nums[i]));
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        int pos1 = 0;
        int pos2 = 0;
        int result = 0;
        while (pos1 < (int)m_values.size() && pos2 < (int)vec.m_values.size())
        {
            if (m_values[pos1].first < vec.m_values[pos2].first)
            {
                pos1++;
            }
            else if (m_values[pos1].first > vec.m_values[pos2].first)
            {
                pos2++;
            }
            else
            {
                result += m_values[pos1].second * vec.m_values[pos2].second;
                pos1++;
                pos2++;
            }
        }
        return result;
    }
};

/// <summary>
/// Leet code #1622. Fancy Sequence
/// 
/// Hard
///
/// Write an API that generates fancy sequences using the append, 
/// addAll, and multAll operations.
/// 
/// Implement the Fancy class:
///  Fancy() Initializes the object with an empty sequence.
/// void append(val) Appends an integer val to the end of the sequence.
/// void addAll(inc) Increments all existing values in the sequence by 
/// an integer inc.
/// void multAll(m) Multiplies all existing values in the sequence by 
/// an integer m.
/// int getIndex(idx) Gets the current value at index idx (0-indexed) 
/// of the sequence modulo 109 + 7. If the index is greater or equal than 
/// the length of the sequence, return -1.
///
/// Example 1:
/// Input
/// ["Fancy", "append", "addAll", "append", "multAll", "getIndex", 
/// "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
/// [[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
/// Output
/// [null, null, null, null, null, 10, null, null, null, 26, 34, 20]
///
/// Explanation
/// Fancy fancy = new Fancy();
/// fancy.append(2);   // fancy sequence: [2]
/// fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
/// fancy.append(7);   // fancy sequence: [5, 7]
/// fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
/// fancy.getIndex(0); // return 10
/// fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
/// fancy.append(10);  // fancy sequence: [13, 17, 10]
/// fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
/// fancy.getIndex(0); // return 26
/// fancy.getIndex(1); // return 34
/// fancy.getIndex(2); // return 20
///
/// Constraints:
/// 1. 1 <= val, inc, m <= 100
/// 2. 0 <= idx <= 10^5
/// 3. At most 10^5 calls total will be made to append, addAll, multAll, 
/// and getIndex.
/// </summary>
class Fancy 
{
private:
    vector<long long> m_vals;
    vector<long long> m_muls;
    vector<long long> m_incs;
    const long long M = 1000000007;
    long long pow(long  long a, long long m, long long M)
    {
        long long result = 1;
        while (m > 0)
        {
            if (m % 2 == 1) result = (result * a) % M;
            m = m / 2;
            a = (a * a) % M;
        }
        return result % M;
    }
public:
    Fancy() 
    {
    }

    void append(int val) 
    {
        m_vals.push_back((long long)val);
        if (m_muls.empty())
        {
            m_muls.push_back(1);
            m_incs.push_back(0);
        }
        else
        {
            m_muls.push_back(m_muls.back());
            m_incs.push_back(m_incs.back());
        }
    }

    void addAll(int inc) 
    {
        if (m_incs.empty()) return;
        m_incs.back() = (m_incs.back() + inc) % M;
    }

    void multAll(int m) 
    {
        if (m_muls.empty()) return;
        m_muls.back() = (int)((long long)m_muls.back() * (long long)m % M);
        m_incs.back() = (int)((long long)m_incs.back() * (long long)m % M);
    }

    int getIndex(int idx) 
    {
        if (idx >= (int)m_vals.size()) return -1;
        long long prev_mul = 1;
        long long prev_inc = 0;
        if (idx > 0)
        {
            prev_mul = m_muls[idx - 1];
            prev_inc = m_incs[idx - 1];
        }
        long long mul = (m_muls.back() * pow(prev_mul, M - 2, M)) % M;
        long long inc = (m_incs.back() - (mul * prev_inc) % M + M) %M;
        int result = (int)(((m_vals[idx] * mul) % M + inc) % M);
        return result;
    }
};

/// <summary>
/// Leet code #1628. Design an Expression Tree With Evaluate Function
/// 
/// Medium
///
/// Given the postfix tokens of an arithmetic expression, build and 
/// return the binary expression tree that represents this expression.
///
/// Postfix notation is a notation for writing arithmetic expressions 
/// in which the operands (numbers) appear before their operators. For 
/// example, the postfix tokens of the expression 4*(5-(2+7)) are 
/// represented in the array postfix = ["4","5","7","2","+","-","*"].
///
/// The class Node is an interface you should use to implement the 
/// binary expression tree. The returned tree will be tested using 
/// the evaluate function, which is supposed to evaluate the tree's 
/// value. You should not remove the Node class; however, you can modify 
/// it as you wish, and you can define other classes to implement it if 
/// needed.
///
/// A binary expression tree is a kind of binary tree used to represent 
/// arithmetic expressions. Each node of a binary expression tree has 
/// either zero or two children. Leaf nodes (nodes with 0 children) 
/// correspond to operands (numbers), and internal nodes (nodes with two 
/// children) correspond to the operators '+' (addition), '-' 
/// (subtraction), '*' (multiplication), and '/' (division).
///
/// It's guaranteed that no subtree will yield a value that exceeds 10^9 
/// in absolute value, and all the operations are valid (i.e., no division 
/// by zero).
///  
/// Follow up: Could you design the expression tree such that it is more 
/// modular? For example, is your design able to support additional 
/// operators without making changes to your existing evaluate 
/// implementation?
///
/// Example 1:
/// Input: s = ["3","4","+","2","*","7","/"]
/// Output: 2
/// Explanation: this expression evaluates to the above binary tree with 
/// expression ((3+4)*2)/7) = 14/7 = 2.
///
/// Example 2:
/// Input: s = ["4","5","7","2","+","-","*"]
/// Output: -16
/// Explanation: this expression evaluates to the above binary tree with 
/// expression 4*(5-(2+7)) = 4*(-4) = -16.
///
/// Example 3:
/// Input: s = ["4","2","+","3","5","1","-","*","+"]
/// Output: 18
///
/// Example 4:
/// Input: s = ["100","200","+","2","/","5","*","7","+"]
/// Output: 757
/// 
/// Constraints:
/// 1. 1 <= s.length < 100
/// 2. s.length is odd.
/// 3. s consists of numbers and the characters '+', '-', '*', and '/'.
/// 4. If s[i] is a number, its integer representation is no more 
///    than 10^5.
/// 5. It is guaranteed that s is a valid expression.
/// 6. The absolute value of the result and intermediate values will not
///    exceed 10^9.
/// 7. It is guaranteed that no expression will include division by zero.
/// </summary>
class BinExpNode 
{
public:
    BinExpNode(char sign, int value, BinExpNode*left = nullptr, BinExpNode* right = nullptr)
    {
        m_sign = sign;
        m_value = value;
        m_left = left;
        m_right = right;
    }
    virtual ~BinExpNode()
    {
        if (m_left != nullptr) delete m_left;
        if (m_right != nullptr) delete m_right;
        m_left = nullptr;
        m_right = nullptr;
    };
    virtual int evaluate()
    {
        return m_value;
    }
protected:
    // define your fields here
    char m_sign;
    int m_value;
    BinExpNode* m_left;
    BinExpNode* m_right;
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    BinExpNode* buildTree(vector<string>& postfix)
    {
        stack<BinExpNode*> stack;
        for (size_t i = 0; i < postfix.size(); i++)
        {
            if (isdigit(postfix[i][0]))
            {
                BinExpNode* node = new BinExpNode('#',atoi(postfix[i].c_str()));
                stack.push(node);
            }
            else
            {
                int sign = postfix[i][0];
                int value = 0;
                BinExpNode* right = stack.top();
                stack.pop();
                BinExpNode* left = stack.top();
                stack.pop();
                if (sign == '+')
                {
                    value = left->evaluate() + right->evaluate();
                }
                else if (sign == '-')
                {
                    value = left->evaluate() - right->evaluate();
                }
                else if (sign == '*')
                {
                    value = left->evaluate() * right->evaluate();
                }
                else if (sign == '/')
                {
                    value = left->evaluate() / right->evaluate();
                }
                BinExpNode* node = new BinExpNode(sign, value, left, right);
                stack.push(node);
            }
        }
        BinExpNode* result = stack.top();
        stack.pop();
        return result;
    }
};

/// <summary>
/// Leet code #1656. Design an Ordered Stream
/// 
/// Easy
///
/// There is a stream of n (id, value) pairs arriving in an arbitrary 
/// order, where id is an integer between 1 and n and value is a string. 
/// No two pairs have the same id.
/// 
/// Design a stream that returns the values in increasing order of their 
/// IDs by returning a chunk (list) of values after each insertion. The 
/// concatenation of all the chunks should result in a list of the sorted 
/// values.
///
/// Implement the OrderedStream class:
///
/// OrderedStream(int n) Constructs the stream to take n values.
/// String[] insert(int id, String value) Inserts the pair (id, value) 
/// into the stream, then returns the largest possible chunk of currently 
/// inserted values that appear next in the order.
///
/// Example:
/// Input
/// ["OrderedStream", "insert", "insert", "insert", "insert", "insert"]
/// [[5], [3, "ccccc"], [1, "aaaaa"], [2, "bbbbb"], [5, "eeeee"], 
/// [4, "ddddd"]]
/// Output
/// [null, [], ["aaaaa"], ["bbbbb", "ccccc"], [], ["ddddd", "eeeee"]]
///
/// Explanation
/// Note that the values ordered by ID is ["aaaaa", "bbbbb", "ccccc", 
///  "ddddd", "eeeee"].
/// OrderedStream os = new OrderedStream(5);
/// os.insert(3, "ccccc"); // Inserts (3, "ccccc"), returns [].
/// os.insert(1, "aaaaa"); // Inserts (1, "aaaaa"), returns ["aaaaa"].
/// os.insert(2, "bbbbb"); // Inserts (2, "bbbbb"), returns 
/// ["bbbbb", "ccccc"].
/// os.insert(5, "eeeee"); // Inserts (5, "eeeee"), returns [].
/// os.insert(4, "ddddd"); // Inserts (4, "ddddd"), 
/// returns ["ddddd", "eeeee"].
/// Concatentating all the chunks returned:
/// [] + ["aaaaa"] + ["bbbbb", "ccccc"] + [] + ["ddddd", "eeeee"] = 
/// ["aaaaa", "bbbbb", "ccccc", "ddddd", "eeeee"]
/// The resulting order is the same as the order above.
///
/// Constraints:
/// 1. 1 <= n <= 1000
/// 2. 1 <= id <= n
/// 3. value.length == 5
/// 4. value consists only of lowercase letters.
/// 5. Each call to insert will have a unique id.
/// 6. Exactly n calls will be made to insert.
/// </summary>
class OrderedStream 
{
private:
    int m_index;
    vector<string> m_arr;
public:
    OrderedStream(int n) 
    {
        m_index = 0;
        m_arr = vector<string>(n);
    }

    vector<string> insert(int id, string value) 
    {
        vector<string> result;
        m_arr[id - 1] = value;
        while (m_index < (int)m_arr.size() && !m_arr[m_index].empty())
        {
            result.push_back(m_arr[m_index]);
            m_index++;
        }
        return result;
    }
};

/// <summary>
/// Leet code #1670. Design Front Middle Back Queue
/// 
/// Medium
/// 
/// Design a queue that supports push and pop operations in the front, middle, 
/// and back.
///
/// Implement the FrontMiddleBack class:
///
/// FrontMiddleBack() Initializes the queue.
/// void pushFront(int val) Adds val to the front of the queue.
/// void pushMiddle(int val) Adds val to the middle of the queue.
/// void pushBack(int val) Adds val to the back of the queue.
/// int popFront() Removes the front element of the queue and returns it. 
/// If the queue is empty, return -1.
/// int popMiddle() Removes the middle element of the queue and returns it. 
/// If the queue is empty, return -1.
/// int popBack() Removes the back element of the queue and returns it. 
/// If the queue is empty, return -1.
/// Notice that when there are two middle position choices, the operation is 
/// performed on the frontmost middle position choice. For example:
///
/// Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
/// Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and 
/// results in [1, 2, 4, 5, 6].
/// 
/// Example 1:
/// Input:
/// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", 
/// "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
/// [[], [1], [2], [3], [4], [], [], [], [], []]
/// Output:
/// [null, null, null, null, null, 1, 3, 4, 2, -1]
///
/// Explanation:
/// FrontMiddleBackQueue q = new FrontMiddleBackQueue();
/// q.pushFront(1);   // [1]
/// q.pushBack(2);    // [1, 2]
/// q.pushMiddle(3);  // [1, 3, 2]
/// q.pushMiddle(4);  // [1, 4, 3, 2]
/// q.popFront();     // return 1 -> [4, 3, 2]
/// q.popMiddle();    // return 3 -> [4, 2]
/// q.popMiddle();    // return 4 -> [2]
/// q.popBack();      // return 2 -> []
/// q.popFront();     // return -1 -> [] (The queue is empty)
/// 
/// Constraints:
/// 1. 1 <= val <= 10^9
/// 2. At most 1000 calls will be made to pushFront, pushMiddle, pushBack, 
/// popFront, popMiddle, and popBack.
/// </summary>
class FrontMiddleBackQueue 
{
private:
    deque<int> m_queue;
public:
    FrontMiddleBackQueue() 
    {
    }

    void pushFront(int val) 
    {
        m_queue.push_front(val);
    }

    void pushMiddle(int val) 
    {
        int middle = m_queue.size();
        if (middle > 0) middle = middle/ 2;
        m_queue.insert(m_queue.begin() + middle, val);
    }

    void pushBack(int val) 
    {
        m_queue.push_back(val);
    }

    int popFront() 
    {
        if (m_queue.empty()) return -1;
        else
        {
            int ret = m_queue.front();
            m_queue.pop_front();
            return ret;
        }
    }

    int popMiddle() 
    {
        if (m_queue.empty()) return -1;
        else
        {
            int middle = m_queue.size();
            if (middle > 0) middle = (middle - 1) / 2;
            int ret = m_queue[middle];
            m_queue.erase(m_queue.begin() + middle);
            return ret;
        }
    }

    int popBack() 
    {
        if (m_queue.empty()) return -1;
        else
        {
            int ret = m_queue.back();
            m_queue.pop_back();
            return ret;
        }
    }
};

/// <summary>
/// Leet code 1756. Design Most Recently Used Queue
/// 
/// Medium
/// 
/// Design a queue-like data structure that moves the most recently used 
/// element to the end of the queue.
///
/// Implement the MRUQueue class:
///
/// MRUQueue(int n) constructs the MRUQueue with n elements: [1,2,3,...,n].
/// fetch(int k) moves the kth element (1-indexed) to the end of the queue 
/// and returns it.
///
/// Example 1:
/// Input:
/// ["MRUQueue", "fetch", "fetch", "fetch", "fetch"]
/// [[8], [3], [5], [2], [8]]
/// Output:
/// [null, 3, 6, 2, 2]
///
/// Explanation:
/// MRUQueue mRUQueue = new MRUQueue(8); 
/// Initializes the queue to [1,2,3,4,5,6,7,8].
/// mRUQueue.fetch(3); 
/// Moves the 3rd element (3) to the end of the queue to 
/// become [1,2,4,5,6,7,8,3] and returns it.
/// mRUQueue.fetch(5); 
/// Moves the 5th element (6) to the end of the queue to 
/// become [1,2,4,5,7,8,3,6] and returns it.
/// mRUQueue.fetch(2); 
/// Moves the 2nd element (2) to the 
/// end of the queue to become [1,4,5,7,8,3,6,2] and returns it.
/// mRUQueue.fetch(8); 
/// The 8th element (2) is already at the end of the queue so 
/// just return it.
/// 
/// Constraints:
/// 1. 1 <= n <= 2000
/// 2. 1 <= k <= n
/// 3. At most 2000 calls will be made to fetch.
/// </summary>
class MRUQueue 
{
private:
    vector<int> m_arr;
public:
    MRUQueue(int n) 
    {
        m_arr = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            m_arr[i] = i + 1;
        }
    }

    int fetch(int k) 
    {
        int num = m_arr[k - 1];
        for (size_t j = k-1; j < m_arr.size() - 1; j++)
        {
            m_arr[j] = m_arr[j + 1];
        }
        m_arr.back() = num;
        return num;
    }
};

/// <summary>
/// Leet code 1724. Checking Existence of Edge Length Limited Paths II
/// 
/// Hard
/// 
/// An undirected graph of n nodes is defined by edgeList, where 
/// edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and 
/// vi with distance disi. Note that there may be multiple edges 
/// between two nodes, and the graph may not be connected.
///
/// Implement the DistanceLimitedPathsExist class:
///
/// DistanceLimitedPathsExist(int n, int[][] edgeList) Initializes 
/// the class with an undirected graph.
/// boolean query(int p, int q, int limit) Returns true if there exists 
/// a path from p to q such that each edge on the path has a distance 
/// strictly less than limit, and otherwise false.
///
/// Example 1:
/// Input
/// ["DistanceLimitedPathsExist", "query", "query", "query", "query"]
/// [[6, [[0, 2, 4], [0, 3, 2], [1, 2, 3], [2, 3, 1], [4, 5, 5]]], 
/// [2, 3, 2], [1, 3, 3], [2, 0, 3], [0, 5, 6]]
/// Output
/// [null, true, false, true, false]
///
/// Explanation
/// DistanceLimitedPathsExist distanceLimitedPathsExist = 
/// new DistanceLimitedPathsExist(6, [[0, 2, 4], [0, 3, 2], [1, 2, 3], 
/// [2, 3, 1], [4, 5, 5]]);
/// distanceLimitedPathsExist.query(2, 3, 2); 
/// return true. There is an edge from 2 to 3 of distance 1, which 
/// is less than 2.
/// distanceLimitedPathsExist.query(1, 3, 3); 
/// return false. There is no way to go from 1 to 3 with 
/// distances strictly less than 3.
/// distanceLimitedPathsExist.query(2, 0, 3); 
/// return true. There is a way to go from 2 to 0 with distance < 3: 
/// travel from 2 to 3 to 0.
/// distanceLimitedPathsExist.query(0, 5, 6); 
/// return false. There are no paths from 0 to 5.
///
/// Constraints:
/// 1. 2 <= n <= 10^4
/// 2. 0 <= edgeList.length <= 10^4
/// 3. edgeList[i].length == 3
/// 4. 0 <= ui, vi, p, q <= n-1
/// 5. ui != vi
/// 6. p != q
/// 7. 1 <= disi, limit <= 10^9
/// 8. At most 10^4 calls will be made to query.
/// </summary>
class DistanceLimitedPathsExist 
{
private:
    vector<int> m_parent;
    vector<int> m_weight;
public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) 
    {
        m_parent = vector<int>(n);
        m_weight = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            m_parent[i] = i;
        }
        sort
        (
            edgeList.begin(), edgeList.end(),
            [](const vector<int>& a, const vector<int>& b) -> bool
            {
                return a[2] < b[2];
            }
        );

        for (size_t i = 0; i < edgeList.size(); i++)
        {
            int a = edgeList[i][0];
            int b = edgeList[i][1];
            while (m_parent[a] != a) a = m_parent[a];
            while (m_parent[b] != b) b = m_parent[b];
            if (a != b)
            {
                m_parent[a] = b;
                m_weight[a] = edgeList[i][2];
            }
        }
    }

    bool query(int p, int q, int limit) 
    {
        while (m_parent[p] != p && m_weight[p] < limit) p = m_parent[p];
        while (m_parent[q] != q && m_weight[q] < limit) q = m_parent[q];
        return p == q;
    }
};

/// <summary>
/// Leet code 1797. Design Authentication Manager
/// 
/// Medium
/// 
/// There is an authentication system that works with authentication 
/// tokens. For each session, the user will receive a new authentication 
/// token that will expire timeToLive seconds after the currentTime. If 
/// the token is renewed, the expiry time will be extended to expire 
/// timeToLive seconds after the (potentially different) currentTime.
///
/// Implement the AuthenticationManager class:
/// 
/// AuthenticationManager(int timeToLive) constructs the 
/// AuthenticationManager and sets the timeToLive.
/// generate(string tokenId, int currentTime) generates a new token with 
/// the given tokenId at the given currentTime in seconds.
/// renew(string tokenId, int currentTime) renews the unexpired token with 
/// the given tokenId at the given currentTime in seconds. If there are no 
/// unexpired tokens with the given tokenId, the request is ignored, and 
/// nothing happens.
/// countUnexpiredTokens(int currentTime) returns the number of unexpired 
/// tokens at the given currentTime.
/// Note that if a token expires at time t, and another action happens on 
/// time t (renew or countUnexpiredTokens), the expiration takes place 
/// before the other actions.
/// 
/// Example 1:
/// Input
/// ["AuthenticationManager", "renew", "generate", "countUnexpiredTokens", 
/// "generate", "renew", "renew", "countUnexpiredTokens"]
/// [[5], ["aaa", 1], ["aaa", 2], [6], ["bbb", 7], ["aaa", 8], 
///  ["bbb", 10], [15]]
/// Output
/// [null, null, null, 1, null, null, null, 0]
///
/// Explanation
/// AuthenticationManager authenticationManager = new AuthenticationManager(5); 
/// Constructs the AuthenticationManager with timeToLive = 5 seconds.
/// authenticationManager.renew("aaa", 1); 
/// No token exists with tokenId "aaa" at time 1, so nothing happens.
/// authenticationManager.generate("aaa", 2); 
/// Generates a new token with tokenId "aaa" at time 2.
/// authenticationManager.countUnexpiredTokens(6); 
/// The token with tokenId "aaa" is the only unexpired one at time 6, 
/// so return 1.
/// authenticationManager.generate("bbb", 7); 
/// Generates a new token with tokenId "bbb" at time 7.
/// authenticationManager.renew("aaa", 8); 
/// The token with tokenId "aaa" expired at time 7, and 8 >= 7, 
/// so at time 8 the renew request is ignored, and nothing happens.
/// authenticationManager.renew("bbb", 10); 
/// The token with tokenId "bbb" is unexpired at time 10, so the renew 
/// request is fulfilled and now the token will expire at time 15.
/// authenticationManager.countUnexpiredTokens(15); 
/// The token with tokenId "bbb" expires at time 15, and the token with 
/// tokenId "aaa" expired at time 7, so currently no token is unexpired, 
/// so return 0.
///
/// Constraints:
/// 1. 1 <= timeToLive <= 10^8
/// 2. 1 <= currentTime <= 10^8
/// 3. 1 <= tokenId.length <= 5
/// 4. tokenId consists only of lowercase letters.
/// 5. All calls to generate will contain unique values of tokenId.
/// 6. The values of currentTime across all the function calls will be 
///   strictly increasing.
/// 7. At most 2000 calls will be made to all functions combined.
/// </summary>
class AuthenticationManager 
{
private:
    set<pair<int, string>> m_tokens;
    unordered_map<string, int> m_token_time;
    int m_timeToLive;
    void clean(int currentTime)
    {
        while (!m_tokens.empty())
        {
            if (m_tokens.begin()->first <= currentTime)
            {
                m_token_time.erase(m_tokens.begin()->second);
                m_tokens.erase(m_tokens.begin());
            }
            else
            {
                break;
            }
        }
    }
    void add(string tokenId, int currentTime)
    {
        if (m_token_time.count(tokenId) > 0)
        {
            m_tokens.erase(make_pair(m_token_time[tokenId], tokenId));
        }
        m_token_time[tokenId] = currentTime + m_timeToLive;
        m_tokens.insert(make_pair(currentTime + m_timeToLive, tokenId));
    }
public:
    AuthenticationManager(int timeToLive) 
    {
        m_timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) 
    {
        clean(currentTime);
        add(tokenId, currentTime);
    }

    void renew(string tokenId, int currentTime) 
    {
        clean(currentTime);
        if (m_token_time.count(tokenId) > 0)
        {
            add(tokenId, currentTime);
        }
    }

    int countUnexpiredTokens(int currentTime) 
    {
        clean(currentTime);
        return (int)m_tokens.size();
    }
};

/// <summary>
/// Leet code 1825. Finding MK Average
/// 
/// Hard
/// 
/// You are given two integers, m and k, and a stream of integers. You are 
/// tasked to implement a data structure that calculates the MKAverage for 
/// the stream.
///
/// The MKAverage can be calculated using these steps:
/// If the number of the elements in the stream is less than m you should 
/// consider the MKAverage to be -1. Otherwise, copy the last m elements 
/// of the stream to a separate container.
/// Remove the smallest k elements and the largest k elements from the 
/// container.
/// Calculate the average value for the rest of the elements rounded down 
/// to the nearest integer.
/// Implement the MKAverage class:
///
/// MKAverage(int m, int k) Initializes the MKAverage object with an empty 
/// stream and the two integers m and k.
/// void addElement(int num) Inserts a new element num into the stream.
/// int calculateMKAverage() Calculates and returns the MKAverage for the 
/// current stream rounded down to the nearest integer.
/// 
/// Example 1:
/// Input
/// ["MKAverage", "addElement", "addElement", "calculateMKAverage", 
/// "addElement", "calculateMKAverage", "addElement", "addElement", 
/// "addElement", "calculateMKAverage"]
/// [[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
/// Output
/// [null, null, null, -1, null, 3, null, null, null, 5]
///
/// Explanation
/// MKAverage obj = new MKAverage(3, 1); 
/// obj.addElement(3);        // current elements are [3]
/// obj.addElement(1);        // current elements are [3,1]
/// obj.calculateMKAverage(); 
/// // return -1, because m = 3 and only 2 elements exist.
/// obj.addElement(10);       // current elements are [3,1,10]
/// obj.calculateMKAverage(); // The last 3 elements are [3,1,10].
/// // After removing smallest and largest 1 element the 
/// // container will be [3].
/// // The average of [3] equals 3/1 = 3, return 3
/// obj.addElement(5);        // current elements are [3,1,10,5]
/// obj.addElement(5);        // current elements are [3,1,10,5,5]
/// obj.addElement(5);        // current elements are [3,1,10,5,5,5]
/// obj.calculateMKAverage(); // The last 3 elements are [5,5,5].
/// // After removing smallest and largest 1 element the 
/// // container will be [5].
/// // The average of [5] equals 5/1 = 5, return 5
///
/// Constraints:
/// 1. 3 <= m <= 10^5
/// 2. 1 <= k*2 < m
/// 3. 1 <= num <= 10^5
/// 4. At most 10^5 calls will be made to addElement and 
///    calculateMKAverage.
/// </summary>
class MKAverage 
{
private:
    size_t _m;
    size_t _k;
    list<pair<int, int>> m_stream;
    int _i;
    long long m_sum;
    set<pair<int, int>> m_prefix;
    set<pair<int, int>> m_body;
    set<pair<int, int>> m_postfix;
public:
    MKAverage(int m, int k) 
    {
        _m = m;
        _k = k;
        _i = 0;
        m_sum = 0;
    }

    void addElement(int num) 
    {
        pair<int, int> data = make_pair(num, _i);
        _i++;
        m_stream.push_back(data);
        if (m_stream.size() > _m)
        {
            pair<int, int> prev = *m_stream.begin();
            m_stream.pop_front();
            if (m_body.count(prev) > 0)
            {
                m_sum -= prev.first;
                m_body.erase(prev);
            }
            else if (m_prefix.count(prev) > 0)
            {
                m_prefix.erase(prev);
            }
            else
            {
                m_postfix.erase(prev);
            }
        }     
        m_body.insert(data);
        m_sum += data.first;
        if (!m_body.empty() && m_prefix.size() < (size_t)_k)
        {
            m_sum -= m_body.begin()->first;
            m_prefix.insert(*m_body.begin());
            m_body.erase(m_body.begin());
        }
        else if (!m_body.empty() && !m_prefix.empty() && m_body.begin()->first < m_prefix.rbegin()->first)
        {
            auto left = *m_body.begin();
            auto right = *m_prefix.rbegin();
            m_sum -= left.first;
            m_sum += right.first;
            m_body.erase(left);
            m_body.insert(right);
            m_prefix.erase(right);
            m_prefix.insert(left);
        }
        
        if (!m_body.empty() && m_postfix.size() < (size_t)_k)
        {
            m_sum -= m_body.rbegin()->first;
            m_postfix.insert(*m_body.rbegin());
            m_body.erase(*m_body.rbegin());
        }
        else if (!m_body.empty() && !m_postfix.empty() && m_body.rbegin()->first > m_postfix.begin()->first)
        {
            auto left = *m_body.rbegin();
            auto right = *m_postfix.begin();
            m_sum -= left.first;
            m_sum += right.first;
            m_body.erase(left);
            m_body.insert(right);
            m_postfix.erase(right);
            m_postfix.insert(left);
        }
    }

    int calculateMKAverage() 
    {
        if (m_stream.size() < (size_t)_m) return -1;
        else return (int)(m_sum / (_m - 2 * _k));  
    }
};

/// <summary>
/// Leet code 1845. Seat Reservation Manager
/// 
/// Medium
/// 
/// Design a system that manages the reservation state of n seats that 
/// are numbered from 1 to n.
///
/// Implement the SeatManager class:
/// SeatManager(int n) Initializes a SeatManager object that will manage n 
/// seats numbered from 1 to n. All seats are initially available.
/// int reserve() Fetches the smallest-numbered unreserved seat, reserves 
/// it, and returns its number.
/// void unreserve(int seatNumber) Unreserves the seat with the given 
/// seatNumber.
///
/// Example 1:
/// Input
/// ["SeatManager", "reserve", "reserve", "unreserve", "reserve", 
///  "reserve", "reserve", "reserve", "unreserve"]
/// [[5], [], [], [2], [], [], [], [], [5]]
/// Output
/// [null, 1, 2, null, 2, 3, 4, 5, null]
/// Explanation
/// SeatManager seatManager = new SeatManager(5); 
/// Initializes a SeatManager with 5 seats.
/// seatManager.reserve();    
/// All seats are available, so return the lowest numbered 
/// seat, which is 1.
/// seatManager.reserve();    
/// The available seats are [2,3,4,5], so return the lowest of them, 
/// which is 2.
/// seatManager.unreserve(2); 
/// Unreserve seat 2, so now the available seats are [2,3,4,5].
/// seatManager.reserve();    
/// The available seats are [2,3,4,5], so return the 
/// lowest of them, which is 2.
/// seatManager.reserve();    
/// The available seats are [3,4,5], so return the lowest 
/// of them, which is 3.
/// seatManager.reserve();    
/// The available seats are [4,5], so return the lowest 
/// of them, which is 4.
/// seatManager.reserve();    
/// The only available seat is seat 5, so return 5.
/// seatManager.unreserve(5); 
/// Unreserve seat 5, so now the available seats are [5].
///
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= seatNumber <= n
/// 3. For each call to reserve, it is guaranteed that there will be at 
///    least one unreserved seat.
/// 4. For each call to unreserve, it is guaranteed that seatNumber will 
///    be reserved.
/// At most 10^5 calls in total will be made to reserve and unreserve.
/// </summary>
class SeatManager
{
private:
    set<pair<int, int>> m_seats;
public:
    SeatManager(int n) 
    {
        m_seats.insert(make_pair(1, n));
    }

    int reserve() 
    {
        pair<int, int> seats = *m_seats.begin();
        m_seats.erase(seats);
        int result = seats.first;
        if (seats.first != seats.second)
        {
            seats.first++;
            m_seats.insert(seats);
        }
        return result;
    }

    void unreserve(int seatNumber) 
    {
        pair<int, int> seat = make_pair(seatNumber, seatNumber);
        auto next = m_seats.lower_bound(make_pair(seatNumber, seatNumber));
        if (next != m_seats.begin())
        {
            auto prev = std::prev(next);
            if (prev->second + 1 == seatNumber)
            {
                seat.first = prev->first;
                m_seats.erase(prev);
            }
        }
        if (next != m_seats.end() && seatNumber + 1 == next->first)
        {
            seat.second = next->second;
            m_seats.erase(next);
        }
        m_seats.insert(seat);
    }
};

/// <summary>
/// Leet code 1865. Finding Pairs With a Certain Sum
///                  
/// Medium
/// 
/// You are given two integer arrays nums1 and nums2. You are tasked to 
/// implement a data structure that supports queries of two types:
///
/// Add a positive integer to an element of a given index in the array 
/// nums2.
/// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a
/// given value (0 <= i < nums1.length and 0 <= j < nums2.length).
/// Implement the FindSumPairs class:
///
/// FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs 
/// object with two integer arrays nums1 and nums2.
/// void add(int index, int val) Adds val to nums2[index], i.e., apply 
/// nums2[index] += val.
/// int count(int tot) Returns the number of pairs (i, j) such that 
/// nums1[i] + nums2[j] == tot.
///
/// Example 1:
/// Input
/// ["FindSumPairs", "count", "add", "count", "count", "add", 
/// "add", "count"]
/// [[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4],
///   [0, 1], [1, 1], [7]]
/// Output
/// [null, 8, null, 2, 1, null, null, 11]
/// Explanation
/// FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], 
/// [1, 4, 5, 2, 5, 4]);
/// findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), 
/// (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
/// findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
/// findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
/// findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
/// findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
/// findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
/// findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), 
/// (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs 
/// (5,3), (5,5) make 3 + 4
///
/// Constraints:
/// 1. 1 <= nums1.length <= 1000
/// 2. 1 <= nums2.length <= 10^5
/// 3. 1 <= nums1[i] <= 10^9
/// 4. 1 <= nums2[i] <= 10^5
/// 5. 0 <= index < nums2.length
/// 6. 1 <= val <= 10^5
/// 7. 1 <= tot <= 10^9
/// 8. At most 1000 calls are made to add and count each.
/// </summary>
class FindSumPairs
{
private: 
    unordered_map<int, int> m_count;
    vector<int> m_nums1;
    vector<int> m_nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        m_nums1 = nums1;
        m_nums2 = nums2;
        for (size_t i = 0; i < nums2.size(); i++)
        {
            m_count[nums2[i]]++;
        }
    }

    void add(int index, int val) 
    {
        m_count[m_nums2[index]]--;
        m_nums2[index] += val;
        m_count[m_nums2[index]]++;
    }

    int count(int tot) 
    {
        int result = 0;
        for (size_t i = 0; i < m_nums1.size(); i++)
        {
            int diff = tot - m_nums1[i];
            if (m_count.count(diff) > 0)
            {
                result += m_count[diff];
            }
        }
        return result;
    }
};

/// <summary>
/// Leet code 1912. Design Movie Rental System
///                                  
/// Hard
/// 
/// You have a movie renting company consisting of n shops. You want to 
/// implement a renting system that supports searching for, booking, and 
/// returning movies. The system should also support generating a report 
/// of the currently rented movies.
///
/// Each movie is given as a 2D integer array entries where 
/// entries[i] = [shopi, moviei, pricei] indicates that there is a copy 
/// of movie moviei at shop shopi with a rental price of pricei. Each 
/// shop carries at most one copy of a movie moviei.
///
/// The system should support the following functions:
/// Search: Finds the cheapest 5 shops that have an unrented copy of 
/// a given movie. The shops should be sorted by price in ascending order, 
/// and in case of a tie, the one with the smaller shopi should appear 
/// first. If there are less than 5 matching shops, then all of them 
/// should be returned. If no shop has an unrented copy, then an 
/// empty list should be returned.
/// Rent: Rents an unrented copy of a given movie from a given shop.
/// Drop: Drops off a previously rented copy of a given movie at a given 
/// shop.
/// Report: Returns the cheapest 5 rented movies (possibly of the same 
/// movie ID) as a 2D list res where res[j] = [shopj, moviej] describes 
/// that the jth cheapest rented movie moviej was rented from the shop 
/// shopj. The movies in res should be sorted by price in ascending 
/// order, and in case of a tie, the one with the smaller shopj should 
/// appear first, and if there is still tie, the one with the smaller 
/// moviej should appear first. If there are fewer than 5 rented 
/// movies, then all of them should be returned. If no movies are 
/// currently being rented, then an empty list should be returned.
/// Implement the MovieRentingSystem class:
///
/// MovieRentingSystem(int n, int[][] entries) Initializes the 
/// MovieRentingSystem object with n shops and the movies in entries.
/// List<Integer> search(int movie) Returns a list of shops that have 
/// an unrented copy of the given movie as described above.
/// void rent(int shop, int movie) Rents the given movie from the given 
/// shop.
/// void drop(int shop, int movie) Drops off a previously rented movie at 
/// the given shop.
/// List<List<Integer>> report() Returns a list of cheapest rented movies 
/// as described above.
/// Note: The test cases will be generated such that rent will only be 
/// called if the shop has an unrented copy of the movie, and drop will 
/// only be called if the shop had previously rented out the movie.
/// 
/// Example 1:
/// Input
/// ["MovieRentingSystem", "search", "rent", "rent", "report", "drop", 
/// "search"]
/// [[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], 
/// [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
/// Output
/// [null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]]
///
/// Explanation
/// MovieRentingSystem movieRentingSystem = new MovieRentingSystem(3, 
/// [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]);
/// movieRentingSystem.search(1);  
/// // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. 
/// // Shop 1 is cheapest; shop 0 and 2 are the same price, so order by 
/// // shop number.
/// movieRentingSystem.rent(0, 1); 
/// // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
/// movieRentingSystem.rent(1, 2); 
/// // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
/// movieRentingSystem.report();   
/// // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed 
/// // by movie 2 from shop 1.
/// movieRentingSystem.drop(1, 2); 
/// // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
/// movieRentingSystem.search(2);  
/// // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. 
/// // Shop 0 is cheapest, followed by shop 1.
/// 
/// Constraints:
/// 1. 1 <= n <= 3 * 10^5
/// 2. 1 <= entries.length <= 10^5
/// 3. 0 <= shopi < n
/// 4. 1 <= moviei, pricei <= 10^4
/// 5. Each shop carries at most one copy of a movie moviei.
/// 6. At most 10^5 calls in total will be made to search, rent, drop and 
///    report.
/// </summary>
class MovieRentingSystem {
private:
    vector<unordered_map<int, int>> m_shops;
    unordered_map<int, set<pair<int, int>>> m_availableMovies;
    set<vector<int>> m_rentedMovies;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
        m_shops = vector<unordered_map<int, int>>(n);
        for (size_t i = 0; i < entries.size(); i++)
        {
            int shop = entries[i][0];
            int movie = entries[i][1];
            int price = entries[i][2];
            m_shops[shop][movie] = price;
            m_availableMovies[movie].insert(make_pair(price, shop));
        }
    }

    vector<int> search(int movie) 
    {
        vector<int> result;
        auto itr = m_availableMovies[movie].begin();
        for (size_t i = 0; i < 5 && itr != m_availableMovies[movie].end(); i++, ++itr)
        {
            result.push_back(itr->second);
        }
        return result;
    }

    void rent(int shop, int movie) 
    {
        int price = m_shops[shop][movie];
        if (m_availableMovies[movie].count(make_pair(price, shop)) > 0)
        {
            m_availableMovies[movie].erase(make_pair(price, shop));
            m_rentedMovies.insert({ price, shop, movie });
        }
    }

    void drop(int shop, int movie) 
    {
        int price = m_shops[shop][movie];
        if (m_rentedMovies.count({ price, shop, movie }) > 0)
        {
            m_availableMovies[movie].insert(make_pair(price, shop));
            m_rentedMovies.erase({ price, shop, movie });
        }
    }

    vector<vector<int>> report() 
    {
        vector<vector<int>> result;
        auto itr = m_rentedMovies.begin();
        for (size_t i = 0; i < 5 && itr != m_rentedMovies.end(); i++, ++itr)
        {
            result.push_back({ (*itr)[1], (*itr)[2] });
        }
        return result;
    }
};

/// <summary>
/// Leet Code 2069. Walking Robot Simulation II
///                                                                 
/// Medium
/// 
/// A width x height grid is on an XY-plane with the bottom-left cell 
/// at (0, 0) and the top-right cell at (width - 1, height - 1). The grid 
/// is aligned with the four cardinal directions ("North", "East", "South",
/// and "West"). A robot is initially at cell (0, 0) facing direction 
/// "East".  
/// The robot can be instructed to move for a specific number of steps. 
/// For each step, it does the following.
///
/// Attempts to move forward one cell in the direction it is facing.
/// If the cell the robot is moving to is out of bounds, the robot instead 
/// turns 90 degrees counterclockwise and retries the step.
/// After the robot finishes moving the number of steps required, it stops 
/// and awaits the next instruction.
///
/// Implement the Robot class:
/// Robot(int width, int height) Initializes the width x height grid with 
/// the robot at (0, 0) facing "East".
/// void step(int num) Instructs the robot to move forward num steps.
/// int[] getPos() Returns the current cell the robot is at, as an array of 
/// length 2, [x, y].
/// String getDir() Returns the current direction of the robot, "North", 
/// "East", "South", or "West".
///
/// Example 1:
/// example-1
/// Input
/// ["Robot", "move", "move", "getPos", "getDir", "move", "move", "move", 
/// "getPos", "getDir"]
/// [[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
/// Output
/// [null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]
/// Explanation
//// Robot robot = new Robot(6, 3); // Initialize the grid and the robot 
/// at (0, 0) facing East.
/// robot.move(2);  // It moves two steps East to (2, 0), and faces East.
/// robot.move(2);  // It moves two steps East to (4, 0), and faces East.
/// robot.getPos(); // return [4, 0]
/// robot.getDir(); // return "East"
/// robot.move(2);  // It moves one step East to (5, 0), and faces East.
///                 // Moving the next step East would be out of bounds, 
///                 // so it turns and faces North.
///                 // Then, it moves one step North to (5, 1), and faces 
///                 // North.
/// robot.move(1);  // It moves one step North to (5, 2), and faces North 
///                 // (not West).
/// robot.move(4);  // Moving the next step North would be out of bounds, 
///                 // so it turns and faces West.
///                 // Then, it moves four steps West to (1, 2), and faces 
///                 // West.
/// robot.getPos(); // return [1, 2]
/// robot.getDir(); // return "West"
/// 
/// Constraints:
/// 1. 2 <= width, height <= 100
/// 2. 1 <= num <= 10^5
/// At most 10^4 calls in total will be made to step, getPos, and getDir.
/// </summary>
class Robot
{
private:
    vector<vector<int>> m_steps = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    vector<string> m_directions = { "East", "North", "West", "South" };
    int m_width;
    int m_height;
    int m_x;
    int m_y;
    int m_pos;
    int m_cycle;
    string m_dir;
public:
    Robot(int width, int height) 
    {
        m_width = width;
        m_height = height;
        m_x = 0;
        m_y = 0;
        m_dir = "East";
        m_pos = 0;
        m_cycle = (m_height + m_width) * 2 - 4;
    }

    void step(int num) 
    {
        m_pos = (m_pos + num) % m_cycle;
        if (m_pos == 0)
        {
            m_x = 0;
            m_y = 0;
            m_dir = "South";
        }
        else if (m_pos > 0 && m_pos < m_width)
        {
            m_x = m_pos;
            m_y = 0;
            m_dir = "East";
        }
        else if (m_pos >= m_width && m_pos < m_width + m_height - 1)
        {
            m_x = m_width - 1;
            m_y = 1 + m_pos - m_width;
            m_dir = "North";
        }
        else if (m_pos >= m_width + m_height - 1 && m_pos <  2 * m_width + m_height - 2)
        {
            m_x = m_width - 2 - (m_pos - (m_width + m_height - 1));
            m_y = m_height - 1;
            m_dir = "West";
        }

        else if (m_pos >= 2 * m_width + m_height - 2 && m_pos < 2 * m_width + 2 * m_height - 4)
        {
            m_x = 0;
            m_y = m_height - 2 - (m_pos - (2 * m_width + m_height - 2));
            m_dir = "South";
        }
    }

    vector<int> getPos() 
    {
        return { m_x, m_y };
    }

    string getDir() 
    {
        return m_dir;
    }
};

/// <summary>
/// Leet Code 2034. Stock Price Fluctuation
///                                                                 
/// Medium
/// 
/// You are given a stream of records about a particular stock. Each 
/// record contains a timestamp and the corresponding price of the 
/// stock at that timestamp.
///
/// Unfortunately due to the volatile nature of the stock market, the 
/// records do not come in order. Even worse, some records may be 
/// incorrect. Another record with the same timestamp may appear later 
/// in the stream correcting the price of the previous wrong record.
///
/// Design an algorithm that:
///
/// Updates the price of the stock at a particular timestamp, correcting 
/// the price from any previous records at the timestamp.
/// Finds the latest price of the stock based on the current records. The 
/// latest price is the price at the latest timestamp recorded.
/// Finds the maximum price the stock has been based on the current records.
/// Finds the minimum price the stock has been based on the current records.
/// Implement the StockPrice class:
///
/// StockPrice() Initializes the object with no price records.
/// void update(int timestamp, int price) Updates the price of the stock at
/// the given timestamp.
/// int current() Returns the latest price of the stock.
/// int maximum() Returns the maximum price of the stock.
/// int minimum() Returns the minimum price of the stock.
///
/// Example 1:
/// Input  
/// ["StockPrice", "update", "update", "current", "maximum", "update", 
///  "maximum", "update", "minimum"]
/// [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
/// Output
/// [null, null, null, 5, 10, null, 5, null, 2]
///
/// Explanation
/// StockPrice stockPrice = new StockPrice();
/// stockPrice.update(1, 10); // Timestamps are [1] with corresponding 
///                           // prices [10].
/// stockPrice.update(2, 5);  // Timestamps are [1,2] with corresponding 
///                           // prices [10,5].
/// stockPrice.current();     // return 5, the latest timestamp is 2 with 
///                           // the price being 5.
/// stockPrice.maximum();     // return 10, the maximum price is 10 at 
///                           // timestamp 1.
/// stockPrice.update(1, 3);  // The previous timestamp 1 had the wrong 
///                           // price, so it is updated to 3.
///                           // Timestamps are [1,2] with corresponding 
///                           // prices [3,5].
/// stockPrice.maximum();     // return 5, the maximum price is 5 after 
///                           // the correction.
/// stockPrice.update(4, 2);  // Timestamps are [1,2,4] with corresponding 
///                           // prices [3,5,2].
/// stockPrice.minimum();     // return 2, the minimum price is 2 at 
///                           // timestamp 4.
/// Constraints:
/// 1. 1 <= timestamp, price <= 10^9
/// 2. At most 105 calls will be made in total to update, current, 
///    maximum, and minimum.
/// 3. current, maximum, and minimum will be called only after update has 
///    been called at least once.
/// </summary>
class StockPrice 
{
private:
    unordered_map<int, int> m_time_prices;
    set<pair<int, int>> m_sorted_prices;
    int m_curr_time;
    int m_curr_price;
public:
    StockPrice() 
    {
        m_curr_time = 0;
        m_curr_price = 0;
    }

    void update(int timestamp, int price) 
    {
        if (m_time_prices.count(timestamp) > 0)
        {
            m_sorted_prices.erase(make_pair(m_time_prices[timestamp], timestamp));
        }
        m_time_prices[timestamp] = price;
        m_sorted_prices.insert(make_pair(m_time_prices[timestamp], timestamp));
        if (timestamp >= m_curr_time)
        {
            m_curr_time = timestamp;
            m_curr_price = price;
        }
    }

    int current() 
    {
        return m_curr_price;
    }

    int maximum() 
    {
        return m_sorted_prices.rbegin()->first;
    }

    int minimum() 
    {
        return m_sorted_prices.begin()->first;
    }
};

/// <summary>
/// Leet Code 2043. Simple Bank System 
///                                                                 
/// Medium
///
/// You have been tasked with writing a program for a popular bank that 
/// will automate all its incoming transactions (transfer, deposit, and 
/// withdraw). The bank has n accounts numbered from 1 to n. The initial 
/// balance of each account is stored in a 0-indexed integer array 
/// balance, with the (i + 1)th account having an initial balance of 
/// balance[i].
///
/// Execute all the valid transactions. A transaction is valid if:
///
/// The given account number(s) are between 1 and n, and
/// The amount of money withdrawn or transferred from is less than or 
/// equal to the balance of the account.
/// Implement the Bank class:
/// Bank(long[] balance) Initializes the object with the 0-indexed integer 
/// array balance.
/// boolean transfer(int account1, int account2, long money) Transfers 
/// money dollars from the account numbered account1 to the account 
/// numbered account2. Return true if the transaction was successful, 
/// false otherwise.
/// boolean deposit(int account, long money) Deposit money dollars into 
/// the account numbered account. Return true if the transaction was 
/// successful, false otherwise.
/// boolean withdraw(int account, long money) Withdraw money dollars from 
/// the account numbered account. Return true if the transaction was 
/// successful, false otherwise.
///
/// Example 1:
/// Input
/// ["Bank", "withdraw", "transfer", "deposit", "transfer", "withdraw"]
/// [[[10, 100, 20, 50, 30]], [3, 10], [5, 1, 20], [5, 20], [3, 4, 15], 
///  [10, 50]]
/// Output
/// [null, true, true, true, false, false]
///
/// Explanation
/// Bank bank = new Bank([10, 100, 20, 50, 30]);
/// bank.withdraw(3, 10);    // return true, account 3 has a balance of 
///                          // $20, so it is valid to withdraw $10.
///                          // Account 3 has $20 - $10 = $10.
/// bank.transfer(5, 1, 20); // return true, account 5 has a balance of 
///                          // $30, so it is valid to transfer $20.
///                          // Account 5 has $30 - $20 = $10, and  
///                          // account 1 has $10 + $20 = $30.
/// bank.deposit(5, 20);     // return true, it is valid to deposit $20 
///                          // to account 5.
///                          // Account 5 has $10 + $20 = $30.
/// bank.transfer(3, 4, 15); // return false, the current balance of 
///                          // account 3 is $10,
///                          // so it is invalid to transfer $15 from it.
/// bank.withdraw(10, 50);   // return false, it is invalid because 
///                          // account 10 does not exist.
/// 
/// Constraints:
/// 1. n == balance.length
/// 2. 1 <= n, account, account1, account2 <= 10^5
/// 3. 0 <= balance[i], money <= 10^12
/// At most 10^4 calls will be made to each function transfer, deposit, 
/// withdraw.
/// </summary>
class Bank
{
private:
    vector<long long> m_account;
public:
    Bank(vector<long long>& balance) 
    {
        m_account = balance;
    }

    bool transfer(int account1, int account2, long long money) 
    {
        if (account1 > (int)m_account.size() || account2 > (int)m_account.size())
        {
            return false;
        }
        if (m_account[account1 - 1] >= money)
        {
            m_account[account1 - 1] -= money;
            m_account[account2 - 1] += money;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool deposit(int account, long long money) 
    {
        if (account > (int)m_account.size())
        {
            return false;
        }
        m_account[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) 
    {
        if (account > (int)m_account.size())
        {
            return false;
        }
        if (m_account[account - 1] >= money)
        {
            m_account[account - 1] -= money;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/// <summary>
/// Leet Code 2013. Detect Squares
///                                                                 
/// Medium
///
/// 
/// You are given a stream of points on the X-Y plane. Design an algorithm 
/// that:
///
/// Adds new points from the stream into a data structure. Duplicate points
/// are allowed and should be treated as different points.
/// Given a query point, counts the number of ways to choose three points 
/// from the data structure such that the three points and the query point 
/// form an axis-aligned square with positive area.
/// An axis-aligned square is a square whose edges are all the same length 
/// and are either parallel or perpendicular to the x-axis and y-axis.
///
/// Implement the DetectSquares class:
/// DetectSquares() Initializes the object with an empty data structure.
/// void add(int[] point) Adds a new point point = [x, y] to the data 
/// structure.
/// int count(int[] point) Counts the number of ways to form axis-aligned 
/// squares with point point = [x, y] as described above.
///
/// Example 1:
/// Input
/// ["DetectSquares", "add", "add", "add", "count", "count", "add", 
///  "count"]
/// [[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], 
/// [[11, 10]]]
/// Output
/// [null, null, null, null, 1, 0, null, 2]
/// 
/// Explanation
/// DetectSquares detectSquares = new DetectSquares();
/// detectSquares.add([3, 10]);
/// detectSquares.add([11, 2]);
/// detectSquares.add([3, 2]);
/// detectSquares.count([11, 10]); // return 1. You can choose:
///                                //   - The first, second, and third points
/// detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
/// detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
/// detectSquares.count([11, 10]); // return 2. You can choose:
///                                //   - The first, second, and third points
///                                //   - The first, third, and fourth points
///
/// Constraints:
/// 1. point.length == 2
/// 2. 0 <= x, y <= 1000
/// 3. At most 3000 calls in total will be made to add and count.
/// </summary>
class DetectSquares 
{
private:
    unordered_map<int, unordered_map<int, int>> m_x_axis;
    unordered_map<int, unordered_map<int, int>> m_y_axis;
    int m_sqare;
public:
    DetectSquares() 
    {
        m_sqare = 0;
    }

    void add(vector<int> point) 
    {
        int x = point[0];
        int y = point[1];
        m_x_axis[x][y]++;
        m_y_axis[y][x]++;
    }

    int count(vector<int> point) 
    {
        int x = point[0];
        int y = point[1];
        int result = 0;
        unordered_map<int, int>& y_points = m_x_axis[x];
        for (auto& itr : y_points)
        {
            int side = std::abs(itr.first - y);
            if (side == 0) continue;
            for (int k = -1; k <= 1; k += 2)
            {
                int x1 = k * side + x;
                if (m_y_axis[y].count(x1) == 0) continue;
                if (m_x_axis[x1].count(itr.first) == 0) continue;
                result += itr.second * m_y_axis[y][x1] * m_x_axis[x1][itr.first];
            }
        }
        return result;
    }
};

/// <summary>
/// Leet Code 1804. Implement Trie II (Prefix Tree)
///                                                                 
/// Medium
///
/// 
/// A trie (pronounced as "try") or prefix tree is a tree data structure 
/// used to efficiently store and retrieve keys in a dataset of strings. 
/// There are various applications of this data structure, such as 
/// autocomplete and spellchecker.
///
/// Implement the Trie class:
/// 
/// Trie() Initializes the trie object.
/// void insert(String word) Inserts the string word into the trie.
/// int countWordsEqualTo(String word) Returns the number of instances 
///                                    of the string word in the trie.
/// int countWordsStartingWith(String prefix) 
/// Returns the number of strings in the trie that have the 
/// string prefix as a prefix.
/// void erase(String word) Erases the string word from the trie.
/// 
/// Example 1:
/// Input
/// ["Trie", "insert", "insert", "countWordsEqualTo", 
/// "countWordsStartingWith", "erase", "countWordsEqualTo", 
/// "countWordsStartingWith", "erase", "countWordsStartingWith"]
/// [[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], 
/// ["app"], ["apple"], ["app"]]
/// Output
/// [null, null, null, 2, 2, null, 1, 1, null, 0]
///
/// Explanation
/// Trie trie = new Trie();
/// trie.insert("apple");               // Inserts "apple".
/// trie.insert("apple");               // Inserts another "apple".
/// trie.countWordsEqualTo("apple");    // There are two instances of 
///                                     // "apple" so return 2.
/// trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" 
///                                     // so return 2.
/// trie.erase("apple");                // Erases one "apple".
/// trie.countWordsEqualTo("apple");    // Now there is only one instance 
///                                     // of "apple" so return 1.
/// trie.countWordsStartingWith("app"); // return 1
/// trie.erase("apple");                // Erases "apple". Now the trie is
///                                     // empty.
/// trie.countWordsStartingWith("app"); // return 0
/// 
/// Constraints:
/// 1. 1 <= word.length, prefix.length <= 2000
/// 2. word and prefix consist only of lowercase English letters.
/// 3. At most 3 * 104 calls in total will be made to insert, 
///    countWordsEqualTo, countWordsStartingWith, and erase.
/// 4. It is guaranteed that for any function call to erase, the string 
///    word will exist in the trie.
/// </summary>
class TrieII
{
private:
    int m_words;
    int m_prefix;
    vector<TrieII*> m_children;
public:
    TrieII() 
    {
        m_words = 0;
        m_prefix = 0;
        m_children = vector<TrieII*>(26);
    }

    void insert(string word, int index = 0) 
    {
        m_prefix++;
        if (index == word.size())
        {
            m_words++;
            return;
        }
        else
        {
            if (m_children[word[index] - 'a'] == nullptr)
            {
                m_children[word[index] - 'a'] = new TrieII();
            }
            m_children[word[index] - 'a']->insert(word, index + 1);
        }
    }

    int countWordsEqualTo(string word, int index = 0) 
    {
        if (index == word.size())
        {
            return m_words;
        }
        else
        {
            if (m_children[word[index] - 'a'] == nullptr)
            {
                return 0;
            }
            else
            {
                return m_children[word[index] - 'a']->countWordsEqualTo(word, index + 1);
            }
        }
    }

    int countWordsStartingWith(string prefix, int index = 0) 
    {
        if (index == prefix.size())
        {
            return m_prefix;
        }
        else
        {
            if (m_children[prefix[index] - 'a'] == nullptr)
            {
                return 0;
            }
            else
            {
                return m_children[prefix[index] - 'a']->countWordsStartingWith(prefix, index + 1);
            }
        }

    }

    void erase(string word, int index = 0) 
    {
        m_prefix--;
        if (index == word.size())
        {
            m_words--;
            return;
        }
        else
        {
            if (m_children[word[index] - 'a'] == nullptr)
            {
                return;
            }
            m_children[word[index] - 'a']->erase(word, index + 1);
        }
    }
};


/// <summary>
/// Leet Code 2102. Sequentially Ordinal Rank Tracker
///                                                                 
/// Hard
///
/// A scenic location is represented by its name and attractiveness score, 
/// where name is a unique string among all locations and score is an 
/// integer. Locations can be ranked from the best to the worst. The 
/// higher the score, the better the location. If the scores of two 
/// locations are equal, then the location with the lexicographically 
/// smaller name is better.
///
/// You are building a system that tracks the ranking of locations with 
/// the system initially starting with no locations. It supports:
///
/// Adding scenic locations, one at a time.
/// Querying the ith best location of all locations already added, where 
/// i is the number of times the system has been queried (including the 
/// current query).
/// For example, when the system is queried for the 4th time, it returns 
/// the 4th best location of all locations already added.
/// Note that the test data are generated so that at any time, the number 
/// of queries does not exceed the number of locations added to the system.
///
/// Implement the SORTracker class:
/// SORTracker() Initializes the tracker system.
/// void add(string name, int score) Adds a scenic location with name and 
/// score to the system.
/// string get() Queries and returns the ith best location, where i is 
/// the number of times this method has been invoked (including this 
/// invocation).
///
/// Example 1:
/// Input
/// ["SORTracker", "add", "add", "get", "add", "get", "add", "get", 
///  "add", "get", "add", "get", "get"]
/// [[], ["bradford", 2], ["branford", 3], [], ["alps", 2], [], 
/// ["orland", 2], [], ["orlando", 3], [], ["alpine", 2], [], []]
/// Output
/// [null, null, null, "branford", null, "alps", null, "bradford", 
/// null, "bradford", null, "bradford", "orland"]
/// 
/// Explanation
/// SORTracker tracker = new SORTracker(); 
/// // Initialize the tracker system.
/// tracker.add("bradford", 2); 
/// // Add location with name="bradford" and score=2 to the system.
/// tracker.add("branford", 3); 
/// // Add location with name="branford" and score=3 to the system.
/// tracker.get();              
/// // The sorted locations, from best to worst, are: branford, bradford.
/// // Note that branford precedes bradford due to its 
/// // higher score (3 > 2).
/// // This is the 1st time get() is called, so return the best 
/// // location: "branford".
/// tracker.add("alps", 2);     
/// // Add location with name="alps" and score=2 to the system.
/// tracker.get();              
/// // Sorted locations: branford, alps, bradford.
/// // Note that alps precedes bradford even though they have the same 
/// // score (2).
/// // This is because "alps" is lexicographically smaller than "bradford".
/// // Return the 2nd best location "alps", as it is the 2nd time get() 
/// // is called.
/// tracker.add("orland", 2);   
/// // Add location with name="orland" and score=2 to the system.
/// tracker.get();              
/// // Sorted locations: branford, alps, bradford, orland.
/// // Return "bradford", as it is the 3rd time get() is called.
/// tracker.add("orlando", 3);  
/// // Add location with name="orlando" and score=3 to the system.
/// tracker.get();              
/// // Sorted locations: branford, orlando, alps, bradford, orland.
/// // Return "bradford".
/// tracker.add("alpine", 2);   
/// // Add location with name="alpine" and score=2 to the system.
/// tracker.get();              
/// // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
/// // Return "bradford".
/// tracker.get();              
/// // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
/// // Return "orland".
/// 
/// Constraints:
/// 1. name consists of lowercase English letters, and is unique among all 
///    locations.
/// 2. 1 <= name.length <= 10
/// 3. 1 <= score <= 10^5
/// 4. At any time, the number of calls to get does not exceed the number 
///    of calls to add.
/// 5. At most 4 * 10^4 calls in total will be made to add and get.
/// </summary>
class SORTracker 
{
private:
    size_t m_count;
    set<pair<int, string>> m_queried;
    set<pair<int, string>> m_added;
public:
    SORTracker() 
    {
        m_count = 0;
    }

    void add(string name, int score) 
    {
        m_queried.insert(make_pair(-score, name));
        if (m_queried.size() > m_count)
        {
            m_added.insert(*m_queried.rbegin());
            m_queried.erase(*m_queried.rbegin());
        }
    }

    string get() 
    {
        string result = m_added.begin()->second;
        m_queried.insert(*m_added.begin());
        m_added.erase(m_added.begin());
        m_count++;
        return result;
    }
};

/// <summary>
/// Leet Code 1993. Operations on Tree
///                                                                 
/// Medium
///
/// You are given a tree with n nodes numbered from 0 to n - 1 in the 
/// form of a parent array parent where parent[i] is the parent of the 
/// ith node. The root of the tree is node 0, so parent[0] = -1 since 
/// it has no parent. You want to design a data structure that allows 
/// users to lock, unlock, and upgrade nodes in the tree.
///
/// The data structure should support the following functions:
///
/// Lock: Locks the given node for the given user and prevents other 
/// users from locking the same node. You may only lock a node using 
/// this function if the node is unlocked.
/// Unlock: Unlocks the given node for the given user. You may only 
/// unlock a node using this function if it is currently locked by 
/// the same user.
/// Upgrade: Locks the given node for the given user and unlocks all 
/// of its descendants regardless of who locked it. You may only 
/// upgrade a node if all 3 conditions are true:
/// The node is unlocked,
/// It has at least one locked descendant (by any user), and
/// It does not have any locked ancestors.
/// Implement the LockingTree class:
///
/// LockingTree(int[] parent) initializes the data structure with the 
///  parent array.
/// lock(int num, int user) returns true if it is possible for the user 
/// with id user to lock the node num, or false otherwise. If it is 
/// possible, the node num will become locked by the user with id user.
/// unlock(int num, int user) returns true if it is possible for the 
/// user with id user to unlock the node num, or false otherwise. If it 
/// is possible, the node num will become unlocked.
/// upgrade(int num, int user) returns true if it is possible for the 
/// user with id user to upgrade the node num, or false otherwise. If 
/// it is possible, the node num will be upgraded.
///
/// Example 1:
/// Input
/// ["LockingTree", "lock", "unlock", "unlock", "lock", "upgrade", "lock"]
/// [[[-1, 0, 0, 1, 1, 2, 2]], [2, 2], [2, 3], [2, 2], [4, 5], [0, 1], 
/// [0, 1]]
/// Output
/// [null, true, false, true, true, true, false]
///
/// Explanation
/// LockingTree lockingTree = new LockingTree([-1, 0, 0, 1, 1, 2, 2]);
/// lockingTree.lock(2, 2);    // return true because node 2 is unlocked.
///                            // Node 2 will now be locked by user 2.
/// lockingTree.unlock(2, 3);  
/// // return false because user 3 cannot unlock a node locked by user 2.
/// lockingTree.unlock(2, 2);  
/// // return true because node 2 was previously locked by user 2.
/// // Node 2 will now be unlocked.
/// lockingTree.lock(4, 5);    
/// // return true because node 4 is unlocked.
/// // Node 4 will now be locked by user 5.
/// lockingTree.upgrade(0, 1); 
/// // return true because node 0 is unlocked and has at least one 
/// // locked descendant (node 4).
/// // Node 0 will now be locked by user 1 and node 4 will now be unlocked.
/// lockingTree.lock(0, 1);    
/// // return false because node 0 is already locked.
/// 
/// Constraints:
/// 1. n == parent.length
/// 2. 2 <= n <= 2000
/// 3. 0 <= parent[i] <= n - 1 for i != 0
/// 4. parent[0] == -1
/// 5. 0 <= num <= n - 1
/// 6. 1 <= user <= 10^4
/// 7. parent represents a valid tree.
/// 8. At most 2000 calls in total will be made to lock, unlock, 
///    and upgrade.
/// </summary>
class LockingTree 
{
    vector<int> m_parent;
    vector<vector<int>> m_children;
    vector<int> m_lock;
public:
    LockingTree(vector<int>& parent) 
    {
        m_parent = parent;
        m_children = vector<vector<int>>(parent.size(), vector<int>());
        for (size_t i = 1; i < parent.size(); i++)
        {
            m_children[parent[i]].push_back(i);
        }
        m_lock = vector<int>(parent.size());
    }

    bool lock(int num, int user) 
    {
        if (m_lock[num] == 0)
        {
            m_lock[num] = user;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool unlock(int num, int user) 
    {
        if (m_lock[num] == user)
        {
            m_lock[num] = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool upgrade(int num, int user) 
    {
        bool locked = false;
        int id = num;
        while (id != -1)
        {
            if (m_lock[id] != 0)
            {
                locked = true;
                break;
            }
            id = m_parent[id];
        }
        if (locked == true) return false;
        queue<int> queue;
        queue.push(num);
        while (!queue.empty())
        {
            int id = queue.front();
            queue.pop();
            if (m_lock[id] != 0)
            {
                locked = true;
                m_lock[id] = 0;
            }
            for (auto child : m_children[id])
            {
                queue.push(child);
            }
        }
        if (locked == true)
        {
            m_lock[num] = user;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/// <summary>
/// Leet Code 2080. Range Frequency Queries
///                                                                 
/// Medium
///
/// Design a data structure to find the frequency of a given value in a 
/// given subarray.
///
/// The frequency of a value in a subarray is the number of occurrences 
/// of that value in the subarray.
///
/// Implement the RangeFreqQuery class:
/// RangeFreqQuery(int[] arr) Constructs an instance of the class with 
/// the given 0-indexed integer array arr.
/// int query(int left, int right, int value) Returns the frequency of 
/// value in the subarray arr[left...right].
/// A subarray is a contiguous sequence of elements within an array. 
/// arr[left...right] denotes the subarray that contains the elements 
/// of nums between indices left and right (inclusive).
///
/// Example 1:
/// Input
/// ["RangeFreqQuery", "query", "query"]
/// [[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], 
/// [0, 11, 33]]
/// Output
/// [null, 1, 2]
/// Explanation
/// RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 
/// 22, 2, 34, 33, 22, 12, 34, 56]);
/// rangeFreqQuery.query(1, 2, 4); 
/// // return 1. The value 4 occurs 1 time in the subarray [33, 4]
/// rangeFreqQuery.query(0, 11, 33); 
/// // return 2. The value 33 occurs 2 times in the whole array.
///
/// Constraints:
/// 1. 1 <= arr.length <= 10^5
/// 2. 1 <= arr[i], value <= 10^4
/// 3. 0 <= left <= right < arr.length
/// 4. At most 10^5 calls will be made to query
/// </summary>
class RangeFreqQuery 
{
private:
    unordered_map<int, vector<int>> m_num;
public:
    RangeFreqQuery(vector<int>& arr) 
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            m_num[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) 
    {
        if (m_num.count(value) == 0) return 0;
        auto first = lower_bound(m_num[value].begin(), m_num[value].end(), left);
        auto last = upper_bound(m_num[value].begin(), m_num[value].end(), right);
        return last - first;
    }
};

/// <summary>
/// Leet Code 2166. Design Bitset
///                                                                 
/// Medium
///
/// A Bitset is a data structure that compactly stores bits.
///
/// Implement the Bitset class:
/// Bitset(int size) Initializes the Bitset with size bits, all of which 
/// are 0.
/// void fix(int idx) Updates the value of the bit at the index idx to 1. 
/// If the value was already 1, no change occurs.
/// void unfix(int idx) Updates the value of the bit at the index idx 
/// to 0. If the value was already 0, no change occurs.
/// void flip() Flips the values of each bit in the Bitset. In other w
/// ords, all bits with value 0 will now have value 1 and vice versa.
/// boolean all() Checks if the value of each bit in the Bitset is 1. 
/// Returns true if it satisfies the condition, false otherwise.
/// boolean one() Checks if there is at least one bit in the Bitset 
/// with value 1. Returns true if it satisfies the condition, false 
/// otherwise.
/// int count() Returns the total number of bits in the Bitset which have 
/// value 1.
/// String toString() Returns the current composition of the Bitset. Note 
/// that in the resultant string, the character at the ith index should 
/// coincide with the value at the ith bit of the Bitset.
///
/// Example 1:
/// Input
/// ["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", 
/// "unfix", "count", "toString"]
/// [[5], [3], [1], [], [], [0], [], [], [0], [], []]
/// Output
/// [null, null, null, null, false, null, null, true, null, 2, "01010"]
///  
/// Explanation
/// Bitset bs = new Bitset(5); // bitset = "00000".
/// bs.fix(3);     // the value at idx = 3 is updated to 1, so 
/// bitset = "00010".
/// bs.fix(1);     // the value at idx = 1 is updated to 1, so 
/// bitset = "01010". 
/// bs.flip();     // the value of each bit is flipped, so 
/// bitset = "10101". 
/// bs.all();      // return False, as not all values of the bitset are 1.
/// bs.unfix(0);   // the value at idx = 0 is updated to 0, so 
/// bitset = "00101".
/// bs.flip();     // the value of each bit is flipped, so 
/// bitset = "11010". 
/// bs.one();      // return True, as there is at least 1 index with 
/// value 1.
/// bs.unfix(0);   // the value at idx = 0 is updated to 0, so 
/// bitset = "01010".
/// bs.count();    // return 2, as there are 2 bits with value 1.
/// bs.toString(); // return "01010", which is the composition of bitset.
/// 
/// Constraints:
/// 1. 1 <= size <= 10^5
/// 2. 0 <= idx <= size - 1
/// 3. At most 10^5 calls will be made in total to fix, unfix, flip, all, 
///    one, count, and toString.
/// 4. At least one call will be made to all, one, count, or toString.
/// 5. At most 5 calls will be made to toString.
/// </summary>
class Bitset 
{
private:
    string m_bits;
    string m_reverse;
    int m_flip;
    size_t m_count;
public:
    Bitset(int size) 
    {
        m_bits = string(size, '0');
        m_reverse = string(size, '1');
        m_count = 0;
        m_flip = 0;
    }

    void fix(int idx) 
    {
        if (m_flip == 0)
        {
            if (m_bits[idx] == '0')
            {
                m_bits[idx] = '1';
                m_reverse[idx] = '0';
                m_count++;
            }
        }
        else
        {
            if (m_reverse[idx] == '0')
            {
                m_reverse[idx] = '1';
                m_bits[idx] = '0';
                m_count--;
            }
        }
    }

    void unfix(int idx) 
    {
        if (m_flip == 0)
        {
            if (m_bits[idx] == '1')
            {
                m_bits[idx] = '0';
                m_reverse[idx] = '1';
                m_count--;
            }
        }
        else
        {
            if (m_reverse[idx] == '1')
            {
                m_reverse[idx] = '0';
                m_bits[idx] = '1';
                m_count++;
            }
        }
    }

    void flip() 
    {
        m_flip = 1 - m_flip;
    }

    bool all() 
    {
        if (m_flip == 0)
        {
            return (m_count == m_bits.size());
        }
        else
        {
            return (m_count == 0);
        }
    }

    bool one() 
    {
        if (m_flip == 0)
        {
            return (m_count > 0);
        }
        else
        {
            return (m_count < m_bits.size());
        }
    }

    int count() 
    {
        if (m_flip == 0)
        {
            return m_count;
        }
        else
        {
            return m_bits.size() - m_count;
        }
    }

    string toString() 
    {
        if (m_flip == 0)
        {
            return m_bits;
        }
        else
        {
            return m_reverse;
        }
    }
};

/// <summary>
/// Leet Code 2241. Design an ATM Machine
///                                                                                   
/// Medium
/// 
/// There is an ATM machine that stores banknotes of 5 denominations: 
/// 20, 50, 100, 200, and 500 dollars. Initially the ATM is empty. 
/// The user can use the machine to deposit or withdraw any amount of 
/// money.
///
/// When withdrawing, the machine prioritizes using banknotes of 
/// larger values.
///
/// For example, if you want to withdraw $300 and there are 2 $50 
/// banknotes, 1 $100 banknote, and 1 $200 banknote, then the machine 
/// will use the $100 and $200 banknotes.
/// However, if you try to withdraw $600 and there are 3 $200 banknotes 
/// and 1 $500 banknote, then the withdraw request will be rejected 
/// because the machine will first try to use the $500 banknote and 
/// then be unable to use banknotes to complete the remaining $100. 
/// Note that the machine is not allowed to use the $200 banknotes 
/// instead of the $500 banknote.
/// Implement the ATM class:
///
/// ATM() Initializes the ATM object.
/// void deposit(int[] banknotesCount) Deposits new banknotes in the 
/// order $20, $50, $100, $200, and $500.
/// int[] withdraw(int amount) Returns an array of length 5 of the 
/// number of banknotes that will be handed to the user in the order 
/// $20, $50, $100, $200, and $500, and update the number of banknotes 
/// in the ATM after withdrawing. Returns [-1] if it is not possible 
/// (do not withdraw any banknotes in this case).
///
/// Example 1:
/// Input
/// ["ATM", "deposit", "withdraw", "deposit", "withdraw", "withdraw"]
/// [[], [[0,0,1,2,1]], [600], [[0,1,0,1,1]], [600], [550]]
/// Output
/// [null, null, [0,0,1,0,1], null, [-1], [0,1,0,0,1]]
/// 
/// Explanation
/// ATM atm = new ATM();
/// atm.deposit([0,0,1,2,1]); // Deposits 1 $100 banknote, 2 $200 
/// banknotes,
///
///                   // and 1 $500 banknote.
/// atm.withdraw(600);        
/// Returns [0,0,1,0,1]. The machine uses 1 $100 banknote
/// and 1 $500 banknote. The banknotes left over in the
/// machine are [0,0,0,2,0].
/// atm.deposit([0,1,0,1,1]); 
/// Deposits 1 $50, $200, and $500 banknote.
/// The banknotes in the machine are now [0,1,0,3,1].
/// atm.withdraw(600);
/// Returns [-1]. The machine will try to use a $500 banknote
/// and then be unable to complete the remaining $100,
/// so the withdraw request will be rejected.
/// Since the request is rejected, the number of banknotes
/// in the machine is not modified.
/// atm.withdraw(550);        
/// Returns [0,1,0,0,1]. The machine uses 1 $50 banknote
/// and 1 $500 banknote.
///
/// Constraints:
/// 1. banknotesCount.length == 5
/// 2. 0 <= banknotesCount[i] <= 10^9
/// 3. 1 <= amount <= 10^9
/// 4. At most 5000 calls in total will be made to withdraw and deposit.
/// 5. At least one call will be made to each function withdraw and 
///    deposit.
/// </summary>
class ATM
{
private:
    vector<long long> m_notes;
    vector<int> m_amount;
public:
    ATM()
    {
        m_notes = vector<long long>(5);
        m_amount = { 20, 50, 100, 200, 500 };
    }

    void deposit(vector<int> banknotesCount)
    {
        for (size_t i = 0; i < banknotesCount.size(); i++)
        {
            m_notes[i] += (long long)banknotesCount[i];
        }
    }
    vector<int> withdraw(int amount)
    {
        vector<int> result(m_notes.size());
        for (int i = m_notes.size() - 1; i >= 0; i--)
        {
            if (m_notes[i] == 0 || m_amount[i] > amount) continue;
            long long count = min(m_notes[i], (long long)(amount / m_amount[i]));
            result[i] += (int)count;
            amount -= (int)count * m_amount[i];
        }
        if (amount == 0)
        {
            for (int i = m_notes.size() - 1; i >= 0; i--)
            {
                m_notes[i] -= (long long)result[i];
            }
            return result;
        }
        else
        {
            return { -1 };
        }
    }
};

/// <summary>
/// Leet Code 2227. Encrypt and Decrypt Strings
///                                                                                      
/// Hard
/// 
/// You are given a character array keys containing unique characters and 
/// a string array values containing strings of length 2. You are also 
/// given another string array dictionary that contains all permitted 
/// original strings after decryption. You should implement a data 
/// structure that can encrypt or decrypt a 0-indexed string.
///
/// A string is encrypted with the following process:
///
/// For each character c in the string, we find the index i satisfying 
/// keys[i] == c in keys.
/// Replace c with values[i] in the string.
/// Note that in case a character of the string is not present in keys, 
/// the encryption process cannot be carried out, and an empty 
/// string "" is returned.
///
/// A string is decrypted with the following process:
///
/// For each substring s of length 2 occurring at an even index in the 
/// string, we find an i such that values[i] == s. If there are multiple 
/// valid i, we choose any one of them. This means a string could have 
/// multiple possible strings it can decrypt to.
/// Replace s with keys[i] in the string.
/// Implement the Encrypter class:
///
/// Encrypter(char[] keys, String[] values, String[] dictionary) 
/// Initializes the Encrypter class with keys, values, and dictionary.
/// String encrypt(String word1) Encrypts word1 with the encryption 
/// process described above and returns the encrypted string.
/// int decrypt(String word2) Returns the number of possible strings word2 
/// could decrypt to that also appear in dictionary.
/// 
/// Example 1:
/// Input
/// ["Encrypter", "encrypt", "decrypt"]
/// [[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", 
/// "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], 
/// ["eizfeiam"]]
/// Output
/// [null, "eizfeiam", 2]
///
/// Explanation
/// Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], 
/// ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", 
/// "cadb", "cbda", "abad"]);
/// encrypter.encrypt("abcd"); // return "eizfeiam". 
///                            // 'a' maps to "ei", 'b' maps to "zf", 'c' 
///                            // maps to "ei", and 'd' maps to "am".
/// encrypter.decrypt("eizfeiam"); // return 2. 
///                                // "ei" can map to 'a' or 'c', "zf" 
///                                // maps to 'b', and "am" maps to 'd'. 
///  // Thus, the possible strings after decryption are "abad", "cbad", 
///  // "abcd", and "cbcd". 
///  // 2 of those strings, "abad" and "abcd", appear in dictionary, so 
///  // the answer is 2.
///
/// Constraints:
/// 1. 1 <= keys.length == values.length <= 26
/// 2. values[i].length == 2
/// 3. 1 <= dictionary.length <= 100
/// 4. 1 <= dictionary[i].length <= 100
/// 5. All keys[i] and dictionary[i] are unique.
/// 6. 1 <= word1.length <= 2000
/// 7. 1 <= word2.length <= 200
/// 8. All word1[i] appear in keys.
/// 9. word2.length is even.
/// 10. keys, values[i], dictionary[i], word1, and word2 only contain 
///     lowercase English letters.
/// 11. At most 200 calls will be made to encrypt and decrypt in total.
/// </summary>
class Encrypter 
{
private:
    unordered_map<char, string> m_map;
    unordered_map<string, unordered_set<string>> m_decodes;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) 
    {
        for (size_t i = 0; i < keys.size(); i++)
        {
            m_map[keys[i]] = values[i];
        }
        for (size_t i = 0; i < dictionary.size(); i++)
        {
            string str;
            for (size_t j = 0; j < dictionary[i].size(); j++)
            {
                if (m_map.count(dictionary[i][j]) == 0)
                {
                    str = "";
                    break;
                }
                else
                {
                    str.append(m_map[dictionary[i][j]]);
                }
            }
            if (!str.empty()) m_decodes[str].insert(dictionary[i]);
        }
    }

    string encrypt(string word1) 
    {
        string str;
        for (size_t j = 0; j < word1.size(); j++)
        {
            if (m_map.count(word1[j]) == 0)
            {
                return "";
            }
            str.append(m_map[word1[j]]);
        }
        return str;
    }

    int decrypt(string word2) 
    {
        return m_decodes[word2].size();
    }
};

/// <summary>
/// Leet Code 2254. Design Video Sharing Platform
///                                                                                      
/// Hard
/// 
/// You have a video sharing platform where users can upload and delete 
/// videos. Each video is a string of digits, where the ith digit of the 
/// string represents the content of the video at minute i. For example, 
/// the first digit represents the content at minute 0 in the video, the 
/// second digit represents the content at minute 1 in the video, and so 
/// on. Viewers of videos can also like and dislike videos. Internally, 
/// the platform keeps track of the number of views, likes, and dislikes 
/// on each video.
///
/// When a video is uploaded, it is associated with the smallest 
/// available integer videoId starting from 0. Once a video is deleted, 
/// the videoId associated with that video can be reused for another video.
///
/// Implement the VideoSharingPlatform class:
///
/// VideoSharingPlatform() Initializes the object.
/// int upload(String video) The user uploads a video. Return the videoId 
/// associated with the video.
/// void remove(int videoId) If there is a video associated with videoId, 
/// remove the video.
/// String watch(int videoId, int startMinute, int endMinute) If there is 
/// a video associated with videoId, increase the number of views on the 
/// video by 1 and return the substring of the video string starting at 
/// startMinute and ending at min(endMinute, video.length - 1) 
/// (inclusive). Otherwise, return "-1".
/// void like(int videoId) Increases the number of likes on the video 
/// associated with videoId by 1 if there is a video associated with 
/// videoId.
/// void dislike(int videoId) Increases the number of dislikes on the 
/// video associated with videoId by 1 if there is a video associated 
/// with videoId.
/// int[] getLikesAndDislikes(int videoId) Return a 0-indexed integer 
/// array values of length 2 where values[0] is the number of likes 
/// and values[1] is the number of dislikes on the video associated 
/// with videoId. If there is no video associated with videoId, 
/// return [-1].
/// int getViews(int videoId) Return the number of views on the 
/// video associated with videoId, if there is no video associated 
/// with videoId, return -1.
///
/// Example 1:
/// Input
/// ["VideoSharingPlatform", "upload", "upload", "remove", "remove", 
/// "upload", "watch", "watch", "like", "dislike", "dislike", 
/// "getLikesAndDislikes", "getViews"]
/// [[], ["123"], ["456"], [4], [0], ["789"], [1, 0, 5], [1, 0, 1], 
/// [1], [1], [1], [1], [1]]
/// Output
/// [null, 0, 1, null, null, 0, "456", "45", null, null, null, [1, 2], 2]
///
/// Explanation
/// VideoSharingPlatform videoSharingPlatform = new VideoSharingPlatform();
/// videoSharingPlatform.upload("123");          // return 0.
/// videoSharingPlatform.upload("456");          // return 1.
/// videoSharingPlatform.remove(4);              // do nothing.
/// videoSharingPlatform.remove(0);              // remove videoId 0.
/// videoSharingPlatform.upload("789");          // return 0,
/// videoSharingPlatform.watch(1, 0, 5);         // return "456".
/// videoSharingPlatform.watch(1, 0, 1);         // so return "45".
/// videoSharingPlatform.like(1);                // like videoId 1.
/// videoSharingPlatform.dislike(1);             // dislike videoId 1.
/// videoSharingPlatform.dislike(1);             // dislike videoId 1.
/// videoSharingPlatform.getLikesAndDislikes(1); // so return [1, 2].
/// videoSharingPlatform.getViews(1);            // so return 2.
///
/// Example 2:
/// Input
/// ["VideoSharingPlatform", "remove", "watch", "like", "dislike", 
///  "getLikesAndDislikes", "getViews"]
/// [[], [0], [0, 0, 1], [0], [0], [0], [0]]
/// Output
/// [null, null, "-1", null, null, [-1], -1]
///
/// Explanation
/// VideoSharingPlatform videoSharingPlatform = new VideoSharingPlatform();
/// videoSharingPlatform.remove(0);              // do nothing.
/// videoSharingPlatform.watch(0, 0, 1);         // so return "-1".
/// videoSharingPlatform.like(0);                // do nothing.
/// videoSharingPlatform.dislike(0);             // do nothing.
/// videoSharingPlatform.getLikesAndDislikes(0); // return [-1].
/// videoSharingPlatform.getViews(0);            // return -1.
///
/// Constraints:
/// 1. 1 <= video.length <= 10^5
/// 2. The sum of video.length over all calls to upload does not exceed 
///    exceed 10^5
/// 3. video consists of digits.
/// 4. 0 <= videoId <= 10^5
/// 5. 0 <= startMinute < endMinute < 10^5
/// 6. startMinute < video.length
/// 7. The sum of endMinute - startMinute over all calls to watch does 
///    not exceed 10^5.
/// 8. At most 105 calls in total will be made to all functions.
/// </summary>
class VideoSharingPlatform 
{
private:
    struct Video
    {
        string content;
        int like;
        int dislike;
        int views;
        Video()
        {
            like = 0;
            dislike = 0;
            views = 0;
        };
        Video(string video)
        {
            content = video;
            like = 0;
            dislike = 0;
            views = 0;
        }
    };
    unordered_map<int, Video> m_videos;
    set<int> m_emptySlots;
public:
    VideoSharingPlatform() 
    {

    }

    int upload(string video) 
    {
        int id = m_videos.size();
        if (!m_emptySlots.empty())
        {
            id = *m_emptySlots.begin();
            m_emptySlots.erase(id);
        }
        Video v(video);
        m_videos[id] = v;
        return id;
    }

    void remove(int videoId) 
    {
        if (m_videos.count(videoId) != 0)
        {
            m_videos.erase(videoId);
            m_emptySlots.insert(videoId);
        }
    }

    string watch(int videoId, int startMinute, int endMinute) 
    {
        string result = "-1";
        if (m_videos.count(videoId) == 0)
        {
            return result;
        }
        result = m_videos[videoId].content.substr(startMinute, endMinute - startMinute + 1);
        m_videos[videoId].views++;
        return result;
    }

    void like(int videoId) 
    {
        if (m_videos.count(videoId) != 0)
        {
            m_videos[videoId].like++;
        }
    }

    void dislike(int videoId) 
    {
        if (m_videos.count(videoId) != 0)
        {
            m_videos[videoId].dislike++;
        }
    }

    vector<int> getLikesAndDislikes(int videoId) 
    {
        vector<int> result;
        if (m_videos.count(videoId) != 0)
        {
            result = { m_videos[videoId].like, m_videos[videoId].dislike };
        }
        else
        {
            result = { -1 };
        }
        return result;
    }

    int getViews(int videoId) 
    {
        if (m_videos.count(videoId) != 0)
        {
            return m_videos[videoId].views;
        }
        else
        {
            return -1;
        }
    }
};

enum TOUCH_EVENT { TOUCHDOWN = 0x81, RELEASE = 0x80 };
typedef struct _TouchContext
{
    TOUCH_EVENT event;
    int x_coord;
    int y_coord;
} TouchContext;
#define PACKET_SIZE 5
#define BUFFER_SIZE 100
#define CONTEXT_SIZE BUFFER_SIZE / PACKET_SIZE
#define PACKET_SIZE 5
#define BUFFER_SIZE 100
#define CONTEXT_SIZE BUFFER_SIZE / PACKET_SIZE

class TouchScreen
{
public:
    unsigned char m_buffer[BUFFER_SIZE + PACKET_SIZE];
    int m_buff_size;

    TouchScreen()
    {
        memset(m_buffer, 0, sizeof(m_buffer));
        m_buff_size = 0;
    };
    /* This is your down stream call you, we expect capacity in number of context*/
    int read_touch_context(TouchContext* context_buff, int capacity)
    {
        TouchContext touch_context;
        int count = 0;
        for (int i = 0; i < m_buff_size; i++)
        {
            if (m_buff_size - i < PACKET_SIZE)
            {
                memcpy(&m_buffer[0], &m_buffer[i], m_buff_size - i);
                m_buff_size = m_buff_size - i;
                break;
            }
            else if (m_buffer[i] != TOUCHDOWN && m_buffer[i] != RELEASE)
            {
                /* ignore garbage*/
                continue;
            }
            else
            {
                touch_context.event = (TOUCH_EVENT)m_buffer[i];
                touch_context.x_coord = m_buffer[i + 1] * 256 + m_buffer[i + 2];
                touch_context.y_coord = m_buffer[i + 3] * 256 + m_buffer[i + 4];
                i += 4;
                context_buff[count] = touch_context;
                count++;
                /* we read more than customer wanted*/
                if (count == capacity)
                {
                    if (m_buff_size - i > 0)
                    {
                        memcpy(&m_buffer[0], &m_buffer[i], m_buff_size - i);
                        m_buff_size = m_buff_size - i;
                    }
                    break;
                }
            }
        }
        return count;
    }

    /* This function is use for read stream from RS232, can also be used for unit test*/
    void read_stream(unsigned char * buffer, int size)
    {
        /* Do not feed me more than I can accetpt*/
        if (size > BUFFER_SIZE - m_buff_size)
        {
            size = BUFFER_SIZE - m_buff_size;
        }
        memcpy(&m_buffer[m_buff_size], buffer, size);
        m_buff_size += size;
    }
};

/// <summary>
/// Leet Code 2276. Count Integers in Intervals
///                                                           
/// Hard
/// 
/// Given an empty set of intervals, implement a data structure that can:
///
/// Add an interval to the set of intervals.
/// Count the number of integers that are present in at least one interval.
/// Implement the CountIntervals class:
///
/// CountIntervals() Initializes the object with an empty set of intervals.
/// void add(int left, int right) Adds the interval [left, right] to the 
/// set of intervals.
/// int count() Returns the number of integers that are present in at least 
/// one interval.
/// Note that an interval [left, right] denotes all the integers x where 
/// left <= x <= right.
/// 
/// Example 1:
/// Input
/// ["CountIntervals", "add", "add", "count", "add", "count"]
/// [[], [2, 3], [7, 10], [], [5, 8], []]
/// Output
/// [null, null, null, 6, null, 8]
/// Explanation
/// CountIntervals countIntervals = new CountIntervals();  
/// countIntervals.add(2, 3);  
/// countIntervals.add(7, 10); 
/// countIntervals.count(); // return 6  
/// the integers 2 and 3 are present in the interval [2, 3].
/// the integers 7, 8, 9, and 10 are present in the interval [7, 10].
/// countIntervals.add(5, 8);  // add [5, 8] to the set of intervals.
/// countIntervals.count();    // return 8
/// the integers 2 and 3 are present in the interval [2, 3].
/// the integers 5 and 6 are present in the interval [5, 8].
/// the integers 7 and 8 are present in the intervals [5, 8] and [7, 10].
/// the integers 9 and 10 are present in the interval [7, 10].
/// 
/// Constraints:
/// 1. 1 <= left <= right <= 10^9
/// 2. At most 10^5 calls in total will be made to add and count.
/// 3. At least one call will be made to count.
/// </summary>
class CountIntervals
{
    map<int, int> m_intervals;
    int m_count;
public:
    CountIntervals() 
    {
        m_count = 0;
        m_intervals[INT_MAX] = 0;
    }

    void add(int left, int right) 
    {
        right++;
        auto itr = m_intervals.lower_bound(left);
        if (itr->first > right && itr->second == 0)
        {
            m_intervals[left] = 0;
            m_intervals[right] = 1;
            m_count += right - left;
        }
        else 
        {
            if (itr->second == 0) m_intervals[left] = 0;
            int prev = left;
            int count = 0;
            while (itr->first <= right)
            {
                if (itr->second == 0)
                {
                    count += itr->first - prev;
                }
                prev = itr->first;
                auto temp = itr;
                itr = next(itr);
                if (temp->second != 0 || temp->first > left) m_intervals.erase(temp);
            }
            if (itr->second == 0)
            {
                m_intervals[right] = 1;
                count += right - prev;
            }
            m_count += count;
        }
    }

    int count() 
    {
        return m_count;
    }
};

/// <summary>
/// Leet Code 2286. Booking Concert Tickets in Groups
///                                                           
/// Hard
/// 
/// A concert hall has n rows numbered from 0 to n - 1, each with m seats, 
/// numbered from 0 to m - 1. You need to design a ticketing system that 
/// can allocate seats in the following cases:
///
/// If a group of k spectators can sit together in a row.
/// If every member of a group of k spectators can get a seat. They may 
/// or may not sit together.
/// Note that the spectators are very picky. Hence:
///
/// They will book seats only if each member of their group can get a 
/// seat with row number less than or equal to maxRow. maxRow can vary 
/// from group to group.
/// In case there are multiple rows to choose from, the row with the 
/// smallest number is chosen. If there are multiple seats to choose in 
/// the same row, the seat with the smallest number is chosen.
/// Implement the BookMyShow class:
///
/// BookMyShow(int n, int m) Initializes the object with n as number of 
/// rows and m as number of seats per row.
/// int[] gather(int k, int maxRow) Returns an array of length 2 denoting 
/// the row and seat number (respectively) of the first seat being 
/// allocated to the k members of the group, who must sit together. In 
/// other words, it returns the smallest possible r and c such that all 
/// [c, c + k - 1] seats are valid and empty in row r, and r <= maxRow. 
/// Returns [] in case it is not possible to allocate seats to the group.
/// boolean scatter(int k, int maxRow) Returns true if all k members of 
/// the group can be allocated seats in rows 0 to maxRow, who may or may 
/// not sit together. If the seats can be allocated, it allocates k seats 
/// to the group with the smallest row numbers, and the smallest possible 
/// seat numbers in each row. Otherwise, returns false.
/// 
/// Example 1:
/// Input
/// ["BookMyShow", "gather", "gather", "scatter", "scatter"]
/// [[2, 5], [4, 0], [2, 0], [5, 1], [5, 1]]
/// Output
/// [null, [0, 0], [], true, false]
/// 
/// Explanation
/// BookMyShow bms = new BookMyShow(2, 5); 
/// There are 2 rows with 5 seats each 
/// bms.gather(4, 0); // return [0, 0]
/// The group books seats [0, 3] of row 0. 
/// bms.gather(2, 0); // return []
/// There is only 1 seat left in row 0,
/// so it is not possible to book 2 consecutive seats. 
/// bms.scatter(5, 1); // return True
/// The group books seat 4 of row 0 and seats [0, 3] of row 1. 
/// bms.scatter(5, 1); // return False
/// There are only 2 seats left in the hall.
///
/// Constraints:
/// 1. 1 <= n <= 5 * 10^4
/// 2. 1 <= m, k <= 10^9
/// 3. 0 <= maxRow <= n - 1
/// 4. At most 5 * 104 calls in total will be made to gather and scatter.  
/// </summary>
class BookMyShow 
{
    int n;
    int m;
    vector<vector<long long>> stree; // segment tree that tracks (max, sum) of each segment
public:
    void build(int i, int p, int q) 
    {
        if (p == q) 
        {
            stree[i] = { m, m };
            return;
        }
        int r = (p + q) / 2;
        stree[i] = { m, (long long)((long long)q - (long long)p + (long long)1) * (long long)m };
        build(2 * i + 1, p, r);
        build(2 * i + 2, r + 1, q);
    }

    vector<int> query_max(int i, int p, int q, int k, int maxRow) 
    {
        if (p > maxRow)
            return {};
        if (stree[i][0] < k)
            return {};
        if (p == q)
            return { p, (int)(m - stree[i][0]) };
        int r = (p + q) / 2;
        vector<int> ret = query_max(2 * i + 1, p, r, k, maxRow);
        if (ret.size())
            return ret;
        return query_max(2 * i + 2, r + 1, q, k, maxRow);
    }

    void update_max(int i, int p, int q, int row, int k) 
    {
        if (p > row || q < row)
            return;
        if (p == q) {
            stree[i][0] -= k;
            stree[i][1] -= k;
            // cout << p << " " << stree[i][0] << endl;
            return;
        }
        int r = (p + q) / 2;
        stree[i][1] -= k;
        update_max(2 * i + 1, p, r, row, k);
        update_max(2 * i + 2, r + 1, q, row, k);
        stree[i][0] = max(stree[2 * i + 1][0], stree[2 * i + 2][0]);
    }

    long long query_sum(int i, int p, int q, int maxRow) 
    {
        if (p > maxRow)
            return 0;
        if (q <= maxRow)
            return stree[i][1];
        int r = (p + q) / 2;
        return query_sum(2 * i + 1, p, r, maxRow) + query_sum(2 * i + 2, r + 1, q, maxRow);
    }

    void update_sum(int i, int p, int q, int k, int maxRow) 
    {
        if (p > maxRow)
            return;
        if (p == q) {
            stree[i][0] -= k;
            stree[i][1] -= k;
            // cout << p << " " << stree[i][0] << endl;
            return;
        }
        int r = (p + q) / 2;
        stree[i][1] -= k;
        if (r + 1 > maxRow || stree[2 * i + 1][1] >= k) {
            update_sum(2 * i + 1, p, r, k, maxRow);
        }
        else {
            k -= (int)stree[2 * i + 1][1];
            update_sum(2 * i + 1, p, r, (int)stree[2 * i + 1][1], maxRow);
            // Be aware: stree[2*i+1][1] updates while updating the left tree
            update_sum(2 * i + 2, r + 1, q, k, maxRow);
        }
        stree[i][0] = max(stree[2 * i + 1][0], stree[2 * i + 2][0]);
    }


    BookMyShow(int n_in, int m_in) {
        n = n_in;
        m = m_in;

        int sz = 1;
        while (sz < n * 2)
            sz <<= 1;
        stree.resize(sz, vector<long long>(2));

        build(0, 0, n - 1);
    }

    vector<int> gather(int k, int maxRow) 
    {
        // cout << "gather " << k << " " << maxRow << endl;
        vector<int> ret = query_max(0, 0, n - 1, k, maxRow);
        if (ret.size())
            update_max(0, 0, n - 1, ret[0], k);
        return ret;
    }

    bool scatter(int k, int maxRow) 
    {
        // cout << "scatter " << k << " " << maxRow << endl;
        long long cnt = query_sum(0, 0, n - 1, maxRow);
        bool ret = cnt >= k;
        if (ret)
            update_sum(0, 0, n - 1, k, maxRow);
        return ret;
    }
};

/// <summary>
/// Leet Code 2296. Design a Text Editor
///                                                           
/// Hard
/// 
/// Design a text editor with a cursor that can do the following:
///
/// Add text to where the cursor is.
/// Delete text from where the cursor is (simulating the backspace key).
/// Move the cursor either left or right.
/// When deleting text, only characters to the left of the cursor will 
/// be deleted. The cursor will also remain within the actual text and 
/// cannot be moved beyond it. More formally, we have that 
/// 0 <= cursor.position <= currentText.length always holds.
///
/// Implement the TextEditor class:
///
/// TextEditor() Initializes the object with empty text.
/// void addText(string text) Appends text to where the cursor is. 
/// The cursor ends to the right of text.
/// int deleteText(int k) Deletes k characters to the left of the cursor. 
/// Returns the number of characters actually deleted.
/// string cursorLeft(int k) Moves the cursor to the left k times. 
/// Returns the last min(10, len) characters to the left of the cursor, 
/// where len is the number of characters to the left of the cursor.
/// string cursorRight(int k) Moves the cursor to the right k times. 
/// Returns the last min(10, len) characters to the left of the cursor, 
/// where len is the number of characters to the left of the cursor.
///
/// Example 1:
/// Input
/// ["TextEditor", "addText", "deleteText", "addText", "cursorRight", 
/// "cursorLeft", "deleteText", "cursorLeft", "cursorRight"]
/// [[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
/// Output
/// [null, null, 4, null, "etpractice", "leet", 4, "", "practi"]
/// 
/// Explanation
/// TextEditor textEditor = new TextEditor(); // The current text 
/// is "|". (The '|' character represents the cursor)
/// textEditor.addText("leetcode"); // The current text is "leetcode|".
/// textEditor.deleteText(4); // return 4
/// // The current text is "leet|". 
/// // 4 characters were deleted.
/// textEditor.addText("practice"); // The current text is "leetpractice|". 
/// textEditor.cursorRight(3); // return "etpractice"
/// // The current text is "leetpractice|". 
/// // The cursor cannot be moved beyond the actual text and thus did 
/// // not move.
/// // "etpractice" is the last 10 characters to the left of the cursor.
/// textEditor.cursorLeft(8); // return "leet"
/// // The current text is "leet|practice".
/// // "leet" is the last min(10, 4) = 4 characters to the left of 
/// // the cursor.
/// textEditor.deleteText(10); // return 4
/// // The current text is "|practice".
/// // Only 4 characters were deleted.
/// textEditor.cursorLeft(2); // return ""
/// // The current text is "|practice".
/// // The cursor cannot be moved beyond the actual text and thus did 
/// // not move. 
/// // "" is the last min(10, 0) = 0 characters to the left of the 
/// // cursor.
/// textEditor.cursorRight(6); // return "practi"
/// // The current text is "practi|ce".
/// // "practi" is the last min(10, 6) = 6 characters to the left 
/// // of the cursor.
/// 
/// Constraints:
/// 1. 1 <= text.length, k <= 40
/// 2. text consists of lowercase English letters.
/// At most 2 * 10^4 calls in total will be made to addText, 
/// deleteText, cursorLeft and cursorRight.
///
/// Follow-up: Could you find a solution with time complexity of O(k) 
/// per call?
/// </summary>
class TextEditor 
{
    deque<char> m_left;
    deque<char> m_right;
public:
    TextEditor() 
    {

    }

    void addText(string text) 
    {
        for (size_t i = 0; i < text.size(); i++)
        {
            m_left.push_back(text[i]);
        }
    }

    int deleteText(int k) 
    {
        int result = min((int)m_left.size(), k);
        for (int i = 0; ((i < k) && (!m_left.empty())); i++)
        {
            m_left.pop_back();
        }
        return result;
    }

    string cursorLeft(int k)
    {
        for (int i = 0; ((i < k) && (!m_left.empty())); i++)
        {
            m_right.push_front(m_left.back());
            m_left.pop_back();
        }
        int start = max(int(m_left.size()) - 10, 0);
        string result;
        result = string(m_left.begin() + start, m_left.end());
        return result;
    }

    string cursorRight(int k) 
    {
        for (int i = 0; ((i < k) && (!m_right.empty())); i++)
        {
            m_left.push_back(m_right.front());
            m_right.pop_front();
        }
        int start = max(int(m_left.size()) - 10, 0);
        string result;
        result = string(m_left.begin() + start, m_left.end());
        return result;
    }
};

/// <summary>
/// Leet Code 2336. Smallest Number in Infinite Set
///                                                           
/// Medium
///
/// You have a set which contains all positive integers 
/// [1, 2, 3, 4, 5, ...].
///
/// Implement the SmallestInfiniteSet class:
/// SmallestInfiniteSet() Initializes the SmallestInfiniteSet object 
/// to contain all positive integers.
/// int popSmallest() Removes and returns the smallest integer 
/// contained in the infinite set.
/// void addBack(int num) Adds a positive integer num back into the 
/// infinite set, if it is not already in the infinite set.
/// 
/// Example 1:
/// Input
/// ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", 
/// "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
/// [[], [2], [], [], [], [1], [], [], []]
/// Output
/// [null, null, 1, 2, 3, null, 1, 4, 5]
///
/// Explanation
/// SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
/// smallestInfiniteSet.addBack(2); // 2 is already in the set.
/// smallestInfiniteSet.popSmallest(); // return 1.
/// smallestInfiniteSet.popSmallest(); // return 2.
/// smallestInfiniteSet.popSmallest(); // return 3.
/// smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
/// smallestInfiniteSet.popSmallest(); // return 1, since 1 was added
/// smallestInfiniteSet.popSmallest(); // return 4, and remove it.
/// smallestInfiniteSet.popSmallest(); // return 5, and remove it from 
/// the set.
/// Constraints:
/// 1. 1 <= num <= 1000
/// 2. At most 1000 calls will be made in total to popSmallest and addBack.
/// </summary>
class SmallestInfiniteSet
{
private:
    int m_max_val;
    set<int> m_data;
public:
    SmallestInfiniteSet() 
    {
        m_max_val = 1;
        m_data.insert(m_max_val);
    }

    int popSmallest() 
    {
        int val = *m_data.begin();
        m_data.erase(m_data.begin());
        if (m_data.empty())
        {
            m_max_val++;
            m_data.insert(m_max_val);
        }
        return val;
    }

    void addBack(int num) 
    {
        if (num > m_max_val) return;
        m_data.insert(num);
    }
};

/// <summary>
/// Leet Code 2353. Design a Food Rating System
///                                                           
/// Medium
///
/// Design a food rating system that can do the following:
///
/// Modify the rating of a food item listed in the system.
/// Return the highest-rated food item for a type of cuisine in the system.
/// Implement the FoodRatings class:
///
/// FoodRatings(String[] foods, String[] cuisines, int[] ratings) 
/// Initializes the system. The food items are described by foods, 
/// cuisines and ratings, all of which have a length of n.
/// foods[i] is the name of the ith food,
/// cuisines[i] is the type of cuisine of the ith food, and
/// ratings[i] is the initial rating of the ith food.
/// void changeRating(String food, int newRating) Changes the rating of 
/// the food item with the name food.
/// String highestRated(String cuisine) Returns the name of the food item 
/// that has the highest rating for the given type of cuisine. If there 
/// is a tie, return the item with the lexicographically smaller name.
/// Note that a string x is lexicographically smaller than string y if x 
/// comes before y in dictionary order, that is, either x is a prefix of 
/// y, or if i is the first position such that x[i] != y[i], then x[i] 
/// comes before y[i] in alphabetic order.
///
/// Example 1:
/// Input ["FoodRatings", "highestRated", "highestRated", "changeRating", 
/// "highestRated", "changeRating", "highestRated"] [[["kimchi", "miso", 
/// "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", 
/// "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], 
/// ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], 
/// ["japanese"]]
///
/// Output
/// [null, "kimchi", "ramen", null, "sushi", null, "ramen"]
/// Explanation
/// FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", 
/// "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", 
/// "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
/// foodRatings.highestRated("korean"); // return "kimchi"
/// "kimchi" is the highest rated korean food with a rating of 9.
/// foodRatings.highestRated("japanese"); // return "ramen"
/// "ramen" is the highest rated japanese food with a rating of 14.
/// foodRatings.changeRating("sushi", 16); 
/// "sushi" now has a rating of 16.
/// foodRatings.highestRated("japanese"); // return "sushi"
/// "sushi" is the highest rated japanese food with a rating of 16. 
/// foodRatings.changeRating("ramen", 16); 
/// "ramen" now has a rating of 16.
/// foodRatings.highestRated("japanese"); // return "ramen"
/// Both "sushi" and "ramen" have a rating of 16.
/// However, "ramen" is lexicographically smaller than "sushi".
/// 
/// Constraints:
/// 1. 1 <= n <= 2 * 10^4
/// 2. n == foods.length == cuisines.length == ratings.length
/// 3. 1 <= foods[i].length, cuisines[i].length <= 10
/// 4. foods[i], cuisines[i] consist of lowercase English letters.
/// 5. 1 <= ratings[i] <= 10^8
/// 6. All the strings in foods are distinct.
/// 7. food will be the name of a food item in the system across all 
///    calls to changeRating.
/// 8. cuisine will be a type of cuisine of at least one food item in 
///    the system across all calls to highestRated.
/// 9. At most 2 * 104 calls in total will be made to changeRating and 
///    highestRated.
/// </summary>
class FoodRatings 
{
private:
    unordered_map<string, pair<string, int>> m_food;
    unordered_map<string, set<pair<int, string>>> m_rating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n = foods.size();
        for (int i = 0; i < n; i++)
        {
            m_food[foods[i]] = make_pair(cuisines[i],  ratings[i]);
            m_rating[cuisines[i]].insert(make_pair(-ratings[i], foods[i]));
        }
    }

    void changeRating(string food, int newRating) 
    {
        pair<string, int> rating = m_food[food];
        m_rating[rating.first].erase(make_pair(-rating.second, food));
        rating.second = newRating;
        m_food[food] = rating;
        m_rating[rating.first].insert(make_pair(-rating.second, food));
    }

    string highestRated(string cuisine) 
    {
        return m_rating[cuisine].begin()->second;
    }
};

/// <summary>
/// Leet Code 2349. Design a Number Container System
///                                                           
/// Medium
///
/// Design a number container system that can do the following:
/// Insert or Replace a number at the given index in the system.
/// Return the smallest index for the given number in the system.
/// Implement the NumberContainers class:
///
/// NumberContainers() Initializes the number container system.
/// void change(int index, int number) Fills the container at index 
/// with the number. If there is already a number at that index, 
/// replace it.
/// int find(int number) Returns the smallest index for the given 
/// number, or -1 if there is no index that is filled by number in 
/// the system.
/// 
/// Example 1:
/// Input ["NumberContainers", "find", "change", "change", "change", 
///        "change", "find", "change", "find"]
/// [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
/// Output
/// [null, -1, null, null, null, null, 1, null, 2]
///
/// Explanation
/// NumberContainers nc = new NumberContainers();
/// nc.find(10); // There is no index that is filled with number 10. 
///              // Therefore, we return -1.
/// nc.change(2, 10); // Your container at index 2 will be filled 
///                   // with number 10.
/// nc.change(1, 10); // Your container at index 1 will be filled 
///                   // with number 10.
/// nc.change(3, 10); // Your container at index 3 will be filled 
///                   // with number 10.
/// nc.change(5, 10); // Your container at index 5 will be filled 
///                   // with number 10.
/// nc.find(10);      // Number 10 is at the indices 1, 2, 3, and 5. 
///                   // Since the smallest index that is filled 
///                   // with 10 is 1, we return 1.
/// nc.change(1, 20); // Your container at index 1 will be filled 
///                   // with number 20. Note that index 1 was filled 
///                   // with 10 and then replaced with 20. 
/// nc.find(10);      // Number 10 is at the indices 2, 3, and 5. The 
///                   // smallest index that is filled with 10 is 2. 
///                   // Therefore, we return 2.
///
/// Constraints:
/// 1. 1 <= index, number <= 10^9
/// 2. At most 10^5 calls will be made in total to change and find.
/// </summary>
class NumberContainers 
{
    unordered_map<int, int> m_container;
    unordered_map<int, set<int>> m_index;
public:
    NumberContainers() 
    {
    }

    void change(int index, int number) 
    {
        if (m_container.count(index) > 0)
        {
            int num = m_container[index];
            m_index[num].erase(index);
            if (m_index[num].empty()) m_index.erase(num);
        }
        m_container[index] = number;
        m_index[number].insert(index);
    }

    int find(int number) 
    {
        if (m_index.count(number) == 0)
        {
            return -1;
        }
        else
        {
            return *(m_index[number].begin());
        }
    }
};

/// <summary>
/// Leet Code 2408. Design SQL
///                                                  
/// Medium
///
/// You are given n tables represented with two arrays names and columns, 
/// where names[i] is the name of the ith table and columns[i] is the 
/// number of columns of the ith table.
///
/// You should be able to perform the following operations:
///
/// Insert a row in a specific table. Each row you insert has an id. The 
/// id is assigned using an auto-increment method where the id of the 
/// first inserted row is 1, and the id of each other row inserted into 
/// the same table is the id of the last inserted row (even if it was 
/// deleted) plus one.
/// Delete a row from a specific table. Note that deleting a row does 
/// not affect the id of the next inserted row.
/// Select a specific cell from any table and return its value.
/// Implement the SQL class:
///
/// SQL(String[] names, int[] columns) Creates the n tables.
/// void insertRow(String name, String[] row) Adds a row to the table 
/// name. It is guaranteed that the table will exist, and the size of 
/// the array row is equal to the number of columns in the table. 
/// void deleteRow(String name, int rowId) Removes the row rowId from 
/// the table name. It is guaranteed that the table and row will exist.
/// String selectCell(String name, int rowId, int columnId) Returns the 
/// value of the cell in the row rowId and the column columnId from the 
/// table name.
///
/// Example 1:
/// Input
/// ["SQL", "insertRow", "selectCell", "insertRow", "deleteRow", 
///  "selectCell"]
/// [[["one", "two", "three"], [2, 3, 1]], ["two", ["first", "second", 
/// "third"]], ["two", 1, 3], ["two", ["fourth", "fifth", "sixth"]],
/// ["two", 1], ["two", 2, 2]]
/// Output
/// [null, null, "third", null, null, "fifth"]
///
/// Explanation
/// SQL sql = new SQL(["one", "two", "three"], [2, 3, 1]); 
/// // creates three tables.
/// sql.insertRow("two", ["first", "second", "third"]); 
/// // adds a row to the table "two". Its id is 1.
/// sql.selectCell("two", 1, 3); 
/// // return "third", finds the value of the third column in the 
/// // row with id 1 of the table "two".
/// sql.insertRow("two", ["fourth", "fifth", "sixth"]); 
/// // adds another row to the table "two". Its id is 2.
/// sql.deleteRow("two", 1); 
/// // deletes the first row of the table "two". Note that the 
/// // second row will still have the id 2.
/// sql.selectCell("two", 2, 2); 
/// // return "fifth", finds the value of the second column in the 
/// // row with id 2 of the table "two".
///
/// Constraints:
/// 1. n == names.length == columns.length
/// 2. 1 <= n <= 104
/// 3. 1 <= names[i].length, row[i].length, name.length <= 20
/// 4. names[i], row[i], and name consist of lowercase English letters.
/// 5. 1 <= columns[i] <= 100
/// 6. All the strings of names are distinct.
/// 7. name exists in the array names.
/// 8. row.length equals the number of columns in the chosen table.
/// 9. rowId and columnId will be valid.
/// 10. At most 250 calls will be made to insertRow and deleteRow.
/// 11. At most 104 calls will be made to selectCell.
/// </summary>
class SQL
{
private:
    unordered_map <string, unordered_map<int, vector<string>>> m_tables;
    unordered_map <string, int> m_row_counts;
public:
    SQL(vector<string>& names, vector<int>& columns) 
    {
        for (size_t i = 0; i < names.size(); i++)
        {
            m_row_counts[names[i]] = 0;
        }
    }

    void insertRow(string name, vector<string> row) 
    {
        m_row_counts[name]++;
        int row_id = m_row_counts[name];
        m_tables[name][row_id] = row;
    }

    void deleteRow(string name, int rowId) 
    {
        if (m_tables[name].count(rowId) > 0)
        {
            m_tables[name].erase(rowId);
        }
    }

    string selectCell(string name, int rowId, int columnId) 
    {
        if (m_tables[name].count(rowId) > 0 &&
            columnId <= (int)m_tables[name][rowId].size())
        {
            return m_tables[name][rowId][columnId - 1];
        }
        else
        {
            return "";
        }
    }
};

/// <summary>
/// Leet Code 2424. Longest Uploaded Prefix
///                                                  
/// Medium
///
/// You are given a stream of n videos, each represented by a distinct 
/// number from 1 to n that you need to "upload" to a server. You need 
/// to implement a data structure that calculates the length of the 
/// longest uploaded prefix at various points in the upload process.
///
/// We consider i to be an uploaded prefix if all videos in the 
/// range 1 to i (inclusive) have been uploaded to the server. The 
/// longest uploaded prefix is the maximum value of i that satisfies 
/// this definition.
///
/// Implement the LUPrefix class:
/// LUPrefix(int n) Initializes the object for a stream of n videos.
/// void upload(int video) Uploads video to the server.
/// int longest() Returns the length of the longest uploaded prefix 
/// defined above.
///
/// Example 1:
/// Input
/// ["LUPrefix", "upload", "longest", "upload", "longest", "upload", 
///  "longest"]
/// [[4], [3], [], [1], [], [2], []]
/// Output
/// [null, null, 0, null, 1, null, 3]
/// Explanation
/// LUPrefix server = new LUPrefix(4);   
/// // Initialize a stream of 4 videos.
/// server.upload(3);                    // Upload video 3.
/// server.longest();                    
/// // Since video 1 has not been uploaded yet, there is no prefix.
/// // So, we return 0.
/// server.upload(1);                    
/// // Upload video 1.
/// server.longest();                    
/// // The prefix [1] is the longest uploaded prefix, so we return 1.
/// server.upload(2);                    
/// // Upload video 2.
/// server.longest();                    
/// // The prefix [1,2,3] is the longest uploaded prefix, so we return 3.
///
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= video <= n
/// 3. All values of video are distinct.
/// 4. At most 2 * 105 calls in total will be made to upload and longest.
/// 5. At least one call will be made to longest.
/// </summary>
class LUPrefix
{
private:
    set<int> m_missing;
public:
    LUPrefix(int n) 
    {
        for (int i = 1; i <= n + 1; i++)
        {
            m_missing.insert(i);
        }
    }

    void upload(int video) 
    {
        m_missing.erase(video);
    }

    int longest() 
    {
        return *m_missing.begin() - 1;
    }
};

/// <summary>
/// Leet Code 2502. Design Memory Allocator
/// 
/// Medium
///	
/// You are given an integer n representing the size of a 0-indexed memory 
/// array. All memory units are initially free.
///
/// You have a memory allocator with the following functionalities:
///
/// Allocate a block of size consecutive free memory units and assign it 
/// the id mID.
/// Free all memory units with the given id mID.
/// Note that:
/// Multiple blocks can be allocated to the same mID.
/// You should free all the memory units with mID, even if they were 
/// allocated in different blocks.
/// Implement the Allocator class:
/// Allocator(int n) Initializes an Allocator object with a memory 
/// array of size n.
/// int allocate(int size, int mID) Find the leftmost block of size 
/// consecutive free memory units and allocate it with the id mID. 
/// Return the block's first index. If such a block does not exist, 
/// return -1.
/// int free(int mID) Free all memory units with the id mID. Return 
/// the number of memory units you have freed.
/// Example 1:
/// Input
/// ["Allocator", "allocate", "allocate", "allocate", "free", 
///   "allocate", "allocate", "allocate", "free", "allocate", "free"]
/// [[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], 
/// [10, 2], [7]]
/// Output
/// [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
/// Explanation
/// Allocator loc = new Allocator(10); // Initialize a memory array 
/// of size 10. All memory units are initially free.
/// loc.allocate(1, 1); // The leftmost block's first index is 0. 
/// The memory array becomes [1,_,_,_,_,_,_,_,_,_]. We return 0.
/// loc.allocate(1, 2); // The leftmost block's first index is 1. The 
/// memory array becomes [1,2,_,_,_,_,_,_,_,_]. We return 1.
/// loc.allocate(1, 3); // The leftmost block's first index is 2. 
/// The memory array becomes [1,2,3,_,_,_,_,_,_,_]. We return 2.
/// loc.free(2); // Free all memory units with mID 2. The memory array 
/// becomes [1,_, 3,_,_,_,_,_,_,_]. We return 1 since there is only 1 
/// unit with mID 2.
/// loc.allocate(3, 4); // The leftmost block's first index is 3. The 
/// memory array becomes [1,_,3,4,4,4,_,_,_,_]. We return 3.
/// loc.allocate(1, 1); // The leftmost block's first index is 1. 
/// The memory array becomes [1,1,3,4,4,4,_,_,_,_]. We return 1.
/// loc.allocate(1, 1); // The leftmost block's first index is 6. 
/// The memory array becomes [1,1,3,4,4,4,1,_,_,_]. We return 6.
/// loc.free(1); // Free all memory units with mID 1. The memory 
/// array becomes [_,_,3,4,4,4,_,_,_,_]. We return 3 since there 
/// are 3 units with mID 1.
/// loc.allocate(10, 2); // We can not find any free block with 10 
/// consecutive free memory units, so we return -1.
/// loc.free(7); // Free all memory units with mID 7. The memory 
/// array remains the same since there is no memory unit with mID 7. 
/// We return 0.
/// </summary>
class Allocator
{
private:
    set<pair<int, int>> m_block;
    set<int> m_endpoints;
    unordered_map<int, vector<pair<int, int>>> m_allocation;
public:
    Allocator(int n) 
    {
        m_endpoints.insert(0);
        m_endpoints.insert(n);
        m_block.insert(make_pair(n, 0));
    }

    int allocate(int size, int mID) 
    {
        auto itr = m_block.lower_bound(make_pair(size, 0));
        if (itr == m_block.end())
        {
            return -1;
        }
        auto selected = itr;
        while (itr != m_block.end())
        {
            if (itr->second < selected->second)
            {
                selected = itr;
            }
            itr++;
        }
        itr = selected;
        int start = itr->second;
        int end = itr->second + size;
        int new_start = itr->second + size;
        int new_end = start + itr->first;
        m_allocation[mID].push_back(make_pair(start, end));
        m_block.erase(itr);
        m_endpoints.erase(start);
        m_endpoints.erase(new_end);
        if (new_start < new_end)
        {
            m_block.insert(make_pair(new_end - new_start, new_start));
            m_endpoints.insert(new_start);
            m_endpoints.insert(new_end);
        }
        return start;
    }

    int free(int mID) 
    {
        int result = 0;
        if (m_allocation.count(mID) == 0) return result;
        for (size_t i = 0; i < m_allocation[mID].size(); i++)
        {
            int start = m_allocation[mID][i].first;
            int end = m_allocation[mID][i].second;
            result += end - start;
            auto itr = m_endpoints.find(start);
            if (itr != m_endpoints.end())
            {
                int prev_end = *itr;
                int prev_start = *prev(itr);
                m_endpoints.erase(prev_start);
                m_endpoints.erase(prev_end);
                m_block.erase(make_pair(prev_end - prev_start, prev_start));
                start = prev_start;
            }
            itr = m_endpoints.find(end);
            if (itr != m_endpoints.end())
            {
                int next_start = *itr;
                int next_end = *next(itr);
                m_endpoints.erase(next_start);
                m_endpoints.erase(next_end);
                m_block.erase(make_pair(next_end - next_start, next_start));
                end = next_end;
            }
            m_endpoints.insert(start);
            m_endpoints.insert(end);
            m_block.insert(make_pair(end - start, start));
        }
        m_allocation.erase(mID);
        return result;
    }
};

/// <summary>
/// Leet Code 2526. Find Consecutive Integers from a Data Stream
/// 
/// Medium
///	
/// For a stream of integers, implement a data structure that checks if 
/// the last k integers parsed in the stream are equal to value.
///
/// Implement the DataStream class:
///
/// DataStream(int value, int k) Initializes the object with an empty 
/// integer stream and the two integers value and k.
/// boolean consec(int num) Adds num to the stream of integers. Returns 
/// true if the last k integers are equal to value, and false otherwise. 
/// If there are less than k integers, the condition does not hold true, 
/// so returns false.
///
/// Example 1:
/// Input
/// ["DataStream", "consec", "consec", "consec", "consec"]
/// [[4, 3], [4], [4], [4], [3]]
/// Output
/// [null, false, false, true, false]
///
/// Explanation
/// DataStream dataStream = new DataStream(4, 3); //value = 4, k = 3 
/// dataStream.consec(4); // Only 1 integer is parsed, so returns False. 
/// dataStream.consec(4); // Only 2 integers are parsed.
///                       // Since 2 is less than k, returns False. 
/// dataStream.consec(4); // The 3 integers parsed are all equal to 
///                       // value, so returns True. 
/// dataStream.consec(3); // The last k integers parsed in the stream 
///                       // are [4,4,3]. Since 3 is not equal to value, 
///                       // it returns False.
///
/// Constraints:
/// 1. 1 <= value, num <= 10^9
/// 2. 1 <= k <= 10^5
/// 3. At most 10^5 calls will be made to consec.
/// </summary>
class DataStream
{
private:
    int m_value;
    int m_threshold;
    int m_count = 0;
public:
    DataStream(int value, int k)
    {
        m_value = value;
        m_threshold = k;
        m_count = 0;
    }

    bool consec(int num)
    {
        if (num == m_value) m_count++;
        else m_count = 0;
        if (m_count >= m_threshold)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/// <summary>
/// Leet Code 2590. Design a Todo List
/// 
/// Medium
///	
/// Design a Todo List Where users can add tasks, mark them as complete, 
/// or get a list of pending tasks. Users can also add tags to tasks and 
/// can filter the tasks by certain tags.
///
/// Implement the TodoList class:
/// TodoList() Initializes the object.
/// int addTask(int userId, String taskDescription, int dueDate, 
/// List<String> tags) Adds a task for the user with the ID userId with a 
/// due date equal to dueDate and a list of tags attached to the task. 
/// The return value is the ID of the task. This ID starts at 1 and is 
/// sequentially increasing. That is, the first task's id should be 1, 
/// the second task's id should be 2, and so on.
/// List<String> getAllTasks(int userId) Returns a list of all the tasks 
/// not marked as complete for the user with ID userId, ordered by the 
/// due date. You should return an empty list if the user has no 
/// uncompleted tasks.
/// List<String> getTasksForTag(int userId, String tag) Returns a list 
/// of all the tasks that are not marked as complete for the user with 
/// the ID userId and have tag as one of their tags, ordered by their 
/// due date. Return an empty list if no such task exists.
/// void completeTask(int userId, int taskId) Marks the task with the 
/// ID taskId as completed only if the task exists and the user with 
/// the ID userId has this task, and it is uncompleted.
/// 
/// Example 1:
/// Input
/// ["TodoList", "addTask", "addTask", "getAllTasks", "getAllTasks", 
///  "addTask", "getTasksForTag", "completeTask", "completeTask", 
///  "getTasksForTag", "getAllTasks"]
/// [[], [1, "Task1", 50, []], [1, "Task2", 100, ["P1"]], [1], [5], 
/// [1, "Task3", 30, ["P1"]], [1, "P1"], [5, 1], [1, 2], [1, "P1"], [1]]
/// Output
/// [null, 1, 2, ["Task1", "Task2"], [], 3, ["Task3", "Task2"], null, 
/// null, ["Task3"], ["Task3", "Task1"]]
///
/// Explanation
/// TodoList todoList = new TodoList();
/// todoList.addTask(1, "Task1", 50, []); return 1. This adds 
/// a new task for the user with id 1.
/// todoList.addTask(1, "Task2", 100, ["P1"]); return 2. This adds 
/// another task for the user with id 1.
/// todoList.getAllTasks(1); return ["Task1", "Task2"]. User 1 has 
/// two uncompleted tasks so far.
/// todoList.getAllTasks(5); return []. User 5 does not have 
/// any tasks so far.
/// todoList.addTask(1, "Task3", 30, ["P1"]); return 3. This adds 
/// another task for the user with id 1.
/// todoList.getTasksForTag(1, "P1"); return ["Task3", "Task2"]. This 
/// returns the uncompleted tasks that have the tag "P1" for the user 
/// with id 1.
/// todoList.completeTask(5, 1); This does nothing, since task 1 does 
/// not belong to user 5.
/// todoList.completeTask(1, 2); // This marks task 2 as completed.
/// todoList.getTasksForTag(1, "P1"); return ["Task3"]. This returns the 
/// uncompleted tasks that have the tag "P1" for the user with id 1.
/// Notice that we did not include "Task2" because it is completed now.
/// todoList.getAllTasks(1); return ["Task3", "Task1"]. User 1 now 
/// has 2 uncompleted tasks.
/// 
/// Constraints:
/// 1. 1 <= userId, taskId, dueDate <= 100
/// 2. 0 <= tags.length <= 100
/// 3. 1 <= taskDescription.length <= 50
/// 4. 1 <= tags[i].length, tag.length <= 20
/// 5. All dueDate values are unique.
/// 6. All the strings consist of lowercase and uppercase English 
/// 7. letters and digits.
/// 8. At most 100 calls will be made for each method.
/// </summary>
class TodoList 
{
    struct Task
    {
        string m_taskDescription;
        int m_dueDate;
        vector<string> m_tags;

        Task(string taskDescription, int dueDate, vector<string> tags)
        {
            m_taskDescription = taskDescription;
            m_dueDate = dueDate;
            m_tags = tags;
        }
    };
    vector<Task *> m_tasks;
    unordered_map<int, set<pair<int, int>>> m_users;
    unordered_map<int, map<string, set<pair<int, int>>>> m_tags;
public:
    TodoList() 
    {
    }

    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) 
    {
        Task* task = new Task(taskDescription, dueDate, tags);
        m_tasks.push_back(task);
        int taskId = m_tasks.size();
        m_users[userId].insert(make_pair(dueDate, taskId-1));
        for (string tag : tags)
        {
            m_tags[userId][tag].insert(make_pair(dueDate, taskId-1));
        }
        return taskId;
    }

    vector<string> getAllTasks(int userId) 
    {
        vector<string> result;
        for (auto itr : m_users[userId])
        {
            result.push_back(m_tasks[itr.second]->m_taskDescription);
        }
        return result;
    }

    vector<string> getTasksForTag(int userId, string tag) 
    {
        vector<string> result;
        for (auto itr : m_tags[userId][tag])
        {
            result.push_back(m_tasks[itr.second]->m_taskDescription);
        }
        return result;
    }

    void completeTask(int userId, int taskId) 
    {
        if (taskId < 1 || taskId >(int)m_tasks.size())  return;
        Task* task = m_tasks[taskId-1];
        m_users[userId].erase(make_pair(task->m_dueDate, taskId - 1));
        for (string tag : task->m_tags)
        {
            m_tags[userId][tag].erase(make_pair(task->m_dueDate, taskId - 1));
        }
    }

    ~TodoList()
    {
        for (size_t i = 0; i < m_tasks.size(); i++)
        {
            if (m_tasks[i] != nullptr) delete m_tasks[i];
        }
    }
};

/// <summary>
/// Leet Code 2642. Design Graph With Shortest Path Calculator
/// 
/// Hard
///	
/// There is a directed weighted graph that consists of n nodes numbered 
/// from 0 to n - 1. The edges of the graph are initially represented by 
/// the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning 
/// that there is an edge from fromi to toi with the cost edgeCosti.
///
/// Implement the Graph class:
///
/// Graph(int n, int[][] edges) initializes the object with n nodes and 
/// the given edges.
/// addEdge(int[] edge) adds an edge to the list of edges where edge = 
/// [from, to, edgeCost]. It is guaranteed that there is no edge between 
/// the two nodes before adding this one.
/// int shortestPath(int node1, int node2) returns the minimum cost of a 
/// path from node1 to node2. If no path exists, return -1. The cost of 
/// a path is the sum of the costs of the edges in the path.
/// 
/// Example 1:
/// Input
/// ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
/// [[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], 
/// [[1, 3, 4]], [0, 3]]
/// Output
/// [null, 6, -1, null, 6]
///
/// Explanation
/// Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
/// g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in 
/// the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 
/// 3 + 2 + 1 = 6.
/// g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
/// g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, 
///                       // and we get the second diagram above.
/// g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now 
///                       // is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.
///
/// Constraints:
/// 1. 1 <= n <= 100
/// 2. 0 <= edges.length <= n * (n - 1)
/// 3. edges[i].length == edge.length == 3
/// 4. 0 <= fromi, toi, from, to, node1, node2 <= n - 1
/// 5. 1 <= edgeCosti, edgeCost <= 106
/// 6. There are no repeated edges and no self-loops in the graph at any 
///    point.
/// 7. At most 100 calls will be made for addEdge.
/// 8. At most 100 calls will be made for shortestPath.
/// </summary>
class Graph 
{
    vector<map<int, int>> m_edges;
public:
    Graph(int n, vector<vector<int>>& edges) 
    {
        m_edges = vector<map<int, int>>(n);
        for (auto edge : edges)
        {
            m_edges[edge[0]][edge[1]] = edge[2];
        }
    }

    void addEdge(vector<int> edge) 
    {
        m_edges[edge[0]][edge[1]] = edge[2];
    }

    int shortestPath(int node1, int node2) 
    {
        vector<int> distance(m_edges.size(), INT_MAX);
        distance[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, node1));
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            if (top.second == node2) return top.first;
            for (auto itr : m_edges[top.second])
            {
                if (distance[itr.first] > top.first + itr.second)
                {
                    distance[itr.first] = top.first + itr.second;
                    pq.push(make_pair(distance[itr.first], itr.first));
                }
            }
        }
        return -1;
    }
};

/// <summary>
/// Leet Code 2671. Frequency Tracker
/// 
/// Medium
///	
/// Design a data structure that keeps track of the values in it and 
/// answers some queries regarding their frequencies.
///
/// Implement the FrequencyTracker class.
///
/// FrequencyTracker(): Initializes the FrequencyTracker object with 
/// an empty array initially.
/// void add(int number): Adds number to the data structure.
/// void deleteOne(int number): Deletes one occurence of number from 
/// the data structure. The data structure may not contain number, 
/// and in this case nothing is deleted.
/// bool hasFrequency(int frequency): Returns true if there is a 
/// number in the data structure that occurs frequency number of times, 
/// otherwise, it returns false.
///
/// Example 1:
/// Input
/// ["FrequencyTracker", "add", "add", "hasFrequency"]
/// [[], [3], [3], [2]]
/// Output
/// [null, null, null, true]
///
/// Explanation
/// FrequencyTracker frequencyTracker = new FrequencyTracker();
/// frequencyTracker.add(3); // The data structure now contains [3]
/// frequencyTracker.add(3); // The data structure now contains [3, 3]
/// frequencyTracker.hasFrequency(2); 
/// // Returns true, because 3 occurs twice
///
/// Example 2:
/// Input
/// ["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
/// [[], [1], [1], [1]]
/// Output
/// [null, null, null, false]
///
/// Explanation
/// FrequencyTracker frequencyTracker = new FrequencyTracker();
/// frequencyTracker.add(1); // The data structure now contains [1]
/// frequencyTracker.deleteOne(1); // The data structure becomes empty []
/// frequencyTracker.hasFrequency(1); 
/// // Returns false, because the data structure is empty
///
/// Example 3:
/// Input
/// ["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
/// [[], [2], [3], [1]]
/// Output
/// [null, false, null, true]
///
/// Explanation
/// FrequencyTracker frequencyTracker = new FrequencyTracker();
/// frequencyTracker.hasFrequency(2); 
/// // Returns false, because the data structure is empty
/// frequencyTracker.add(3); // The data structure now contains [3]
/// frequencyTracker.hasFrequency(1); 
/// // Returns true, because 3 occurs once
/// 
/// Constraints:
/// 1. 1 <= number <= 10^5
/// 2. 1 <= frequency <= 10^5
/// 3. At most, 2 * 10^5 calls will be made to add, deleteOne, 
///    and hasFrequency in total.
/// </summary>
class FrequencyTracker 
{
    unordered_map<int, int> m_num_count;
    unordered_map<int, int> m_frequency;
public:
    FrequencyTracker() 
    {
    }

    void add(int number) 
    {
        if (m_num_count.count(number) > 0)
        {
            m_frequency[m_num_count[number]]--;
            if (m_frequency[m_num_count[number]] == 0)
            {
                m_frequency.erase(m_num_count[number]);
            }
        }
        m_num_count[number]++;
        m_frequency[m_num_count[number]]++;
    }

    void deleteOne(int number) 
    {
        if (m_num_count[number] > 0)
        {
            m_frequency[m_num_count[number]]--;
            if (m_frequency[m_num_count[number]] == 0)
            {
                m_frequency.erase(m_num_count[number]);
            }
            m_num_count[number]--;
            if (m_num_count[number] == 0)
            {
                m_num_count.erase(number);
            }
            else
            {
                m_frequency[m_num_count[number]]++;
            }
        }
    }

    bool hasFrequency(int frequency) 
    {
        if (frequency > 0 && m_frequency[frequency] > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif // LeetcodeDesign_H
