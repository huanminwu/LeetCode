#pragma once
#ifndef LeetcodeTwoPointer_H
#define LeetCodeTwoPointer_H
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
/// The class is to implement two pointers  
/// </summary>
class LeetCodeTwoPointer
{
public:
    /// <summary>
    /// Leet code #881. Boats to Save People
    /// 
    /// The i-th person has weight people[i], and each boat can carry a maximum 
    /// weight of limit.
    ///
    /// Each boat carries at most 2 people at the same time, provided the sum of 
    /// the weight of those people is at most limit.
    ///
    /// Return the minimum number of boats to carry every given person.  (It is 
    /// guaranteed each person can be carried by a boat.)
    ///
    /// Example 1:
    ///
    /// Input: people = [1,2], limit = 3
    /// Output: 1
    /// Explanation: 1 boat (1, 2)
    ///
    /// Example 2:
    ///
    /// Input: people = [3,2,2,1], limit = 3
    /// Output: 3
    /// Explanation: 3 boats (1, 2), (2) and (3)
    ///
    /// Example 3:
    /// 
    /// Input: people = [3,5,3,4], limit = 5
    /// Output: 4
    /// Explanation: 4 boats (3), (3), (4), (5)
    /// Note:
    /// 
    /// 1. 1 <= people.length <= 50000
    /// 2. 1 <= people[i] <= limit <= 30000
    /// </summary>
    int numRescueBoats(vector<int>& people, int limit);
};
#endif  // LeetCodeTwoPointer
