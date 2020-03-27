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

    /// <summary>
    /// Leet code #1326. Minimum Number of Taps to Open to Water a Garden
    ///
    /// Hard
    ///
    /// There is a one-dimensional garden on the x-axis. The garden starts 
    /// at the point 0 and ends at the point n. (i.e The length of the 
    /// garden is n).
    ///
    /// There are n + 1 taps located at points [0, 1, ..., n] in the garden.
    ///
    /// Given an integer n and an integer array ranges of length n + 1 where 
    /// ranges[i] (0-indexed) means the i-th tap can water the area 
    /// [i - ranges[i], i + ranges[i]] if it was open.
    ///
    /// Return the minimum number of taps that should be open to water the 
    /// whole garden, If the garden cannot be watered return -1.
    /// 
    /// Example 1:
    /// Input: n = 5, ranges = [3,4,1,1,0,0]
    /// Output: 1
    /// Explanation: The tap at point 0 can cover the interval [-3,3]
    /// The tap at point 1 can cover the interval [-3,5]
    /// The tap at point 2 can cover the interval [1,3]
    /// The tap at point 3 can cover the interval [2,4]
    /// The tap at point 4 can cover the interval [4,4]
    /// The tap at point 5 can cover the interval [5,5]
    /// Opening Only the second tap will water the whole garden [0,5]
    ///
    /// Example 2:
    /// Input: n = 3, ranges = [0,0,0,0]
    /// Output: -1
    /// Explanation: Even if you activate all the four taps you cannot water 
    /// the whole garden.
    ///
    /// Example 3:
    /// Input: n = 7, ranges = [1,2,1,0,2,1,0,1]
    /// Output: 3
    ///
    /// Example 4:
    /// Input: n = 8, ranges = [4,0,0,0,0,0,0,0,4]
    /// Output: 2
    ///
    /// Example 5:
    /// Input: n = 8, ranges = [4,0,0,0,4,0,0,0,4]
    /// Output: 1
    /// 
    /// Constraints:
    /// 1. 1 <= n <= 10^4
    /// 2. ranges.length == n + 1
    /// 3. 0 <= ranges[i] <= 100
    /// </summary>
    int minTaps(int n, vector<int>& ranges);

    /// <summary>
    /// Leet code #1353. Maximum Number of Events That Can Be Attended
    ///
    /// Medium
    ///
    /// Given an array of events where events[i] = [startDayi, endDayi]. 
    /// Every event i starts at startDayi and ends at endDayi.
    ///
    /// You can attend an event i at any day d where 
    /// startTimei <= d <= endTimei. Notice that you can only attend one 
    /// event at any time d.
    ///
    /// Return the maximum number of events you can attend.
    /// 
    /// Example 1:
    /// Input: events = [[1,2],[2,3],[3,4]]
    /// Output: 3
    /// Explanation: You can attend all the three events.
    /// One way to attend them all is as shown.
    /// Attend the first event on day 1.
    /// Attend the second event on day 2.
    /// Attend the third event on day 3.
    ///
    /// Example 2:
    /// Input: events= [[1,2],[2,3],[3,4],[1,2]]
    /// Output: 4
    ///
    /// Example 3:
    /// Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
    /// Output: 4
    ///
    /// Example 4:  
    /// Input: events = [[1,100000]]
    /// Output: 1
    /// 
    /// Example 5:
    /// Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
    /// Output: 7
    ///
    /// Constraints:
    /// 1. 1 <= events.length <= 10^5
    /// 2. events[i].length == 2
    /// 3. 1 <= events[i][0] <= events[i][1] <= 10^5
    /// </summary>
    int maxEvents(vector<vector<int>>& events);

    /// <summary>
    /// Leet code #1383. Maximum Performance of a Team
    ///
    /// Hard
    ///
    /// There are n engineers numbered from 1 to n and two arrays: speed 
    /// and efficiency, where speed[i] and efficiency[i] represent the 
    /// speed and efficiency for the i-th engineer respectively. Return 
    /// the maximum performance of a team composed of at most k engineers, 
    /// since the answer can be a huge number, return this modulo 10^9 + 7.
    /// The performance of a team is the sum of their engineers' speeds 
    /// multiplied by the minimum efficiency among their engineers.
    ///
    /// Example 1:
    /// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], 
    /// k = 2
    /// Output: 60
    /// Explanation: 
    /// We have the maximum performance of the team by selecting 
    /// engineer 2 (with speed=10 and efficiency=4) and engineer 5 
    /// (with speed=5 and efficiency=7). That is, performance = 
    /// (10 + 5) * min(4, 7) = 60.
    ///
    /// Example 2:
    /// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], 
    /// k = 3
    /// Output: 68
    /// Explanation:
    /// This is the same example as the first but k = 3. We can select 
    /// engineer 1, engineer 2 and engineer 5 to get the maximum 
    /// performance of the team. That is, performance = 
    /// (2 + 10 + 5) * min(5, 4, 7) = 68.
    ///
    /// Example 3:
    /// Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2],
    /// k = 4
    /// Output: 72
    ///
    /// Constraints:
    /// 1. 1 <= n <= 10^5
    /// 2. speed.length == n
    /// 3. efficiency.length == n
    /// 4. 1 <= speed[i] <= 10^5
    /// 5. 1 <= efficiency[i] <= 10^8
    /// 6. 1 <= k <= n
    /// </summary>
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k);

#pragma endregion
};
#endif  // LeetCodeGreedy_H
