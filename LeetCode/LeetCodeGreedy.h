#pragma once
#ifndef LeetCodeGreedy_H
#define LeetCodeGreedy_H
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
class LeetCodeGreedy
{
public:
#pragma region Greedy
    /// <summary>
    /// Leet code #1229. Meeting Scheduler
    /// 
    /// Given the availability time slots arrays slots1 and slots2 of two 
    /// people and a meeting duration duration, return the earliest time 
    /// slot that works for both of them and is of duration duration.
    ///
    /// If there is no common time slot that satisfies the requirements, 
    /// return an empty array.
    ///
    /// The format of a time slot is an array of two elements [start, end] 
    /// representing an inclusive time range from start to end.  
    ///
    /// It is guaranteed that no two availability slots of the same person 
    /// intersect with each other. That is, for any two time slots 
    /// [start1, end1] and [start2, end2] of the same person, either 
    /// start1 > end2 or start2 > end1.
    ///
    /// Example 1:
    ///
    /// Input: slots1 = [[10,50],[60,120],[140,210]], 
    /// slots2 = [[0,15],[60,70]], duration = 8
    /// Output: [60,68]
    ///
    /// Example 2:
    ///
    /// Input: slots1 = [[10,50],[60,120],[140,210]], 
    /// slots2 = [[0,15],[60,70]], duration = 12
    /// Output: []
    ///  
    /// Constraints:
    /// 1. 1 <= slots1.length, slots2.length <= 10^4
    /// 2. slots1[i].length, slots2[i].length == 2
    /// 3. slots1[i][0] < slots1[i][1]
    /// 4. slots2[i][0] < slots2[i][1]
    /// 5. 0 <= slots1[i][j], slots2[i][j] <= 10^9
    /// 6. 1 <= duration <= 10^6 
    /// </summary>
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, 
        vector<vector<int>>& slots2, int duration);

    /// <summary>
    /// Leet code #1272. Remove Interval
    /// 
    /// Given a sorted list of disjoint intervals, each interval 
    /// intervals[i] = [a, b] represents the set of real numbers x 
    /// such that a <= x < b.
    ///
    /// We remove the intersections between any interval in 
    /// intervals and the interval toBeRemoved.
    ///
    /// Return a sorted list of intervals after all such removals.
    ///
    /// Example 1:
    /// 
    /// Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
    /// Output: [[0,1],[6,7]]
    ///
    /// Example 2:
    ///
    /// Input: intervals = [[0,5]], toBeRemoved = [2,3]
    /// Output: [[0,2],[3,5]]
    /// 
    /// Constraints:
    /// 1. 1 <= intervals.length <= 10^4
    /// 2. -10^9 <= intervals[i][0] < intervals[i][1] <= 10^9
    /// </summary>
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved);

    /// <summary>
    /// Leet code #1288. Remove Covered Intervals
    ///
    /// Medium
    ///
    /// Given a list of intervals, remove all intervals that are covered by 
    /// another interval in the list. Interval [a,b) is covered by interval 
    /// [c,d) if and only if c <= a and b <= d.
    ///
    /// After doing so, return the number of remaining intervals.
    ///
    /// Example 1:
    /// Input: intervals = [[1,4],[3,6],[2,8]]
    /// Output: 2
    /// Explanation: Interval [3,6] is covered by [2,8], therefore it is 
    /// removed.
    /// 
    /// Constraints:
    /// 1. 1 <= intervals.length <= 1000
    /// 2. 0 <= intervals[i][0] < intervals[i][1] <= 10^5
    /// 3. intervals[i] != intervals[j] for all i != j
    /// </summary>
    int removeCoveredIntervals(vector<vector<int>>& intervals);

#pragma endregion
};
#endif  // LeetCodeGreedy_H
