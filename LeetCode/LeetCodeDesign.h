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
/// Leet code #303. Range Sum Query - Immutable          
/// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
/// Example:
/// Given nums = [-2, 0, 3, -5, 2, -1]
/// sumRange(0, 2) -> 1
/// sumRange(2, 5) -> -1
/// sumRange(0, 5) -> -3
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
/// Leet code #232. Implement Queue using Stacks  
/// Implement the following operations of a queue using stacks.
/// push(x) -- Push element x to the back of queue.
/// pop() -- Removes the element from in front of queue.
/// peek() -- Get the front element.
/// empty() -- Return whether the queue is empty. 
/// Notes:
/// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
/// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), 
/// as long as you use only standard operations of a stack. 
/// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
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
    map<const char, DictNode*> char_map;

    /// <summary>
    /// Constructor of an empty DictNode
    /// </summary>
    /// <returns></returns>
    DictNode() {};

    /// <summary>
    /// Destructor of an DictNode
    /// </summary>
    /// <returns></returns>
    ~DictNode()
    {
        map<char, DictNode*>::iterator iterator;
        for (iterator = char_map.begin(); iterator != char_map.end(); ++iterator)
        {
            if (iterator->second != nullptr)
            {
                delete iterator->second;
            }
            char_map[iterator->first] = nullptr;
        }
        char_map.clear();
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
        if (char_map.find(word[i]) == char_map.end())
        {
            node = new DictNode();
            char_map[word[i]] = node;
        }
        else
        {
            node = char_map[word[i]];
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
        map<char, DictNode*>::iterator iterator;
        for (iterator = char_map.begin(); iterator != char_map.end(); ++iterator)
        {
            if (iterator->second != nullptr)
            {
                result.push_back(iterator->second);
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
            if (char_map.find(word[i]) == char_map.end())
            {
                return false;
            }
            else
            {
                DictNode* node = char_map[word[i]];
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
    DictNode* root;
public:
    /// <summary>
    /// Constructor an empty WordDictionary
    /// </summary>
    /// <returns></returns>
    WordDictionary()
    {
        root = new DictNode();
    };

    /// <summary>
    /// Destructor of an WordDictionary
    /// </summary>
    /// <returns></returns>
    ~WordDictionary()
    {
        delete root;
    }

    /// <summary>
    /// Adds a word into the data structure.
    /// </summary>
    /// <param name="word>The word</param>
    /// <returns></returns>
    void addWord(string word)
    {
        root->addWord(word, 0);
    }

    /// <summary>
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    /// </summary>
    /// <param name="word">The word</param>
    /// <returns>true, if found</returns>
    bool search(string word)
    {
        return root->search(word, 0);
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
    int m_Book;
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
    MyCalendarThree()
    {
        m_TimeMap[0] = 0;
        m_Book = 0;
    }

    int book(int start, int end)
    {
        auto itr = getLocation(end);
        m_TimeMap[end] = itr->second;

        itr = getLocation(start);
        m_TimeMap[start] = itr->second + 1;
        m_Book = max(m_Book, m_TimeMap[start]);

        itr = m_TimeMap.find(start);

        // int prev_value = itr->second;
        itr++;
        while (itr != m_TimeMap.end() && itr->first < end)
        {
            auto temp = itr;
            itr->second++;
            m_Book = max(m_Book, itr->second);
            itr++;
            /*  clean up duplication is optional
            if (temp->second == prev_value)
            {
            m_TimeMap.erase(temp);
            }
            else
            {
            prev_value = temp->second;
            }
            */
        }
        return m_Book;
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
    set<pair<int, int>> m_Range;
public:
    RangeModule()
    {
    }

    void addRange(int left, int right)
    {
        pair<int, int> range = make_pair(left, right);
        if (m_Range.empty())
        {
            m_Range.insert(range);
            return;
        }
        auto itr = m_Range.lower_bound(range);
        // the previous range may need to be adjusted.
        if (itr != m_Range.begin()) itr--;
        // loop from small to large range
        while (itr != m_Range.end() && itr->first <= range.second)
        {
            auto temp = itr;
            itr++;
            if (temp->second >= range.first)
            {
                range.first = min(temp->first, range.first);
                range.second = max(temp->second, range.second);
                m_Range.erase(temp);
            }
        }
        m_Range.insert(range);
    }

    bool queryRange(int left, int right)
    {
        pair<int, int> range = make_pair(left, right);
        if (m_Range.empty())
        {
            return false;
        }
        auto itr = m_Range.lower_bound(range);
        // the previous range may need to be adjusted.
        if (itr != m_Range.begin()) itr--;
        // loop from small to large range
        while (itr != m_Range.end() && itr->first < range.second)
        {
            if (itr->second <= range.first)
            {
                itr++;
            }
            else if ((itr->first <= range.first) && (itr->second >= range.second))
            {
                return true;
            }
            // if (itr->first > range.first) || (itr->second < range.second)
            else
            {
                return false;
            }
        }
        return false;
    }

    void removeRange(int left, int right)
    {
        pair<int, int> range = make_pair(left, right);
        if (m_Range.empty())
        {
            return;
        }
        auto itr = m_Range.lower_bound(range);
        // the previous range may need to be adjusted.
        if (itr != m_Range.begin()) itr--;
        // loop from small to large range
        while (itr != m_Range.end() && itr->first < range.second)
        {
            auto temp = itr;
            itr++;
            if (temp->second <= range.first)
            {
                continue;
            }
            else if (temp->first < range.first)
            {
                pair<int, int> prev = make_pair(temp->first, range.first);
                pair<int, int> next = make_pair(range.second, temp->second);
                m_Range.erase(temp);
                m_Range.insert(prev);
                if (next.second > next.first) m_Range.insert(next);
            }
            else if (temp->second <= range.second)
            {
                m_Range.erase(temp);
            }
            // if (temp->first < range.second) && (temp->second > range.second)
            else
            {
                pair<int, int> next = make_pair(range.second, temp->second);
                m_Range.erase(temp);
                m_Range.insert(next);
            }
        }
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

#endif // LeetcodeDesign_H
