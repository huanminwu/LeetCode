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
    /// Leet code #56. Merge Intervals
    /// 
    /// Medium
    /// 
    /// Given an array of intervals where intervals[i] = [start[i], end[i]], merge all 
    /// overlapping intervals, and return an array of the non-overlapping intervals
    /// that cover all the intervals in the input.
    ///
    /// Example 1:
    /// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    /// Output: [[1,6],[8,10],[15,18]]
    /// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
    /// Example 2:
    /// Input: intervals = [[1,4],[4,5]]
    /// Output: [[1,5]]
    /// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
    /// Constraints:
    /// 1. 1 <= intervals.length <= 10^4
    /// 2. intervals[i].length == 2
    /// 3. 0 <= starti <= endi <= 10^4
    /// </summary>
    vector<vector<int>> merge(vector<vector<int>>& intervals);

    /// <summary>
    /// Leet code #57. Insert Interval
    /// 
    /// Medium
    /// 
    /// Given a set of non-overlapping intervals, insert a new interval into the 
    /// intervals (merge if necessary).
    ///
    /// You may assume that the intervals were initially sorted according to 
    /// their start times.
    /// 
    /// Example 1:
    /// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    /// Output: [[1,5],[6,9]]
    ///
    /// Example 2:
    /// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
    /// Output: [[1,2],[3,10],[12,16]]
    /// Explanation: Because the new interval [4,8] overlaps with 
    /// [3,5],[6,7],[8,10].
    ///
    /// Example 3:
    /// Input: intervals = [], newInterval = [5,7]
    /// Output: [[5,7]]
    ///
    /// Example 4:
    /// Input: intervals = [[1,5]], newInterval = [2,3]
    /// Output: [[1,5]]
    ///
    /// Example 5:
    /// Input: intervals = [[1,5]], newInterval = [2,7]
    /// Output: [[1,7]]
    /// Constraints:
    /// 1. 0 <= intervals.length <= 10^4
    /// 2. intervals[i].length == 2
    /// 3. 0 <= intervals[i][0] <= intervals[i][1] <= 10^5
    /// 4. intervals is sorted by intervals[i][0] in ascending order.
    /// 5. newInterval.length == 2
    /// 6. 0 <= newInterval[0] <= newInterval[1] <= 10^5
    /// </summary>
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

    /// <summary>
    /// Leet code #163. Missing Ranges
    /// 
    /// Easy
    /// 
    /// You are given an inclusive range [lower, upper] and a sorted unique 
    /// integer array nums, where all elements are in the inclusive range.
    ///
    /// A number x is considered missing if x is in the range [lower, upper] 
    /// and x is not in nums.
    ///
    /// Return the smallest sorted list of ranges that cover every missing 
    /// number exactly. That is, no element of nums is in any of the ranges, 
    /// and each missing number is in one of the ranges.
    ///
    /// Each range [a,b] in the list should be output as:
    ///
    /// "a->b" if a != b
    /// "a" if a == b
    /// 
    /// Example 1:
    /// Input: nums = [0,1,3,50,75], lower = 0, upper = 99
    /// Output: ["2","4->49","51->74","76->99"]
    /// Explanation: The ranges are:
    /// [2,2] --> "2"
    /// [4,49] --> "4->49"
    /// [51,74] --> "51->74"
    /// [76,99] --> "76->99"
    ///
    /// Example 2:
    /// Input: nums = [], lower = 1, upper = 1
    /// Output: ["1"]
    /// Explanation: The only missing range is [1,1], which becomes "1".
    ///
    /// Example 3:
    /// Input: nums = [], lower = -3, upper = -1
    /// Output: ["-3->-1"]
    /// Explanation: The only missing range is [-3,-1], which becomes "-3->-1".
    ///
    /// Example 4:
    /// Input: nums = [-1], lower = -1, upper = -1
    /// Output: []
    /// Explanation: There are no missing ranges since there are no missing 
    /// numbers.
    ///
    /// Example 5:
    /// Input: nums = [-1], lower = -2, upper = -1
    /// Output: ["-2"]
    ///
    /// Constraints:
    /// 1. -10^9 <= lower <= upper <= 10^9
    /// 2. 0 <= nums.length <= 100
    /// 3. lower <= nums[i] <= upper
    /// 4. All the values of nums are unique.
    /// </summary>
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper);

    /// <summary>
    /// Leet code #218. The Skyline Problem
    /// 
    /// Hard
    /// 
    /// A city's skyline is the outer contour of the silhouette formed by all the 
    /// buildings in that city when viewed from a distance. Given the locations 
    /// and heights of all the buildings, return the skyline formed by these 
    /// buildings collectively.
    ///
    /// The geometric information of each building is given in the array buildings 
    /// where buildings[i] = [left[i], right[i], height[i]]:
    ///
    /// left[i] is the x coordinate of the left edge of the ith building.
    /// right[i] is the x coordinate of the right edge of the ith building.
    /// height[i] is the height of the ith building.
    /// You may assume all buildings are perfect rectangles grounded on an 
    /// absolutely flat surface at height 0.
    ///
    /// The skyline should be represented as a list of "key points" sorted by 
    /// their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is 
    /// the left endpoint of some horizontal segment in the skyline except the 
    /// last point in the list, which always has a y-coordinate  0 and is used to 
    /// mark the skyline's termination where the rightmost building ends. Any 
    /// ground between the leftmost and rightmost buildings should be part of the 
    /// skyline's contour.
    ///
    /// Note: There must be no consecutive horizontal lines of equal height in the 
    /// output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is 
    /// not acceptable; the three lines of height 5 should be merged into one in 
    /// the final output as such: [...,[2 3],[4 5],[12 7],...]
    /// 
    /// Example 1:
    /// Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
    /// Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
    /// Explanation:
    /// Figure A shows the buildings of the input.
    /// Figure B shows the skyline formed by those buildings. The red points in 
    /// figure B represent the key points in the output list.
    ///
    /// Example 2:
    /// Input: buildings = [[0,2,3],[2,5,3]]
    /// Output: [[0,3],[5,0]]
    ///
    /// Constraints:
    /// 1. 1 <= buildings.length <= 10^4
    /// 2. 0 <= left[i] < right[i] <= 2^31 - 1
    /// 3. 1 <= height[i] <= 2^31 - 1
    /// 4. buildings is sorted by lefti in non-decreasing order.
    /// </summary>
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings);

    /// <summary>
    /// Leet code #228. Summary Ranges
    /// 
    /// Easy
    /// 
    /// You are given a sorted unique integer array nums.
    ///
    /// Return the smallest sorted list of ranges that cover all the numbers 
    /// in the array exactly. That is, each element of nums is covered by 
    /// exactly one of the ranges, and there is no integer x such that x is 
    /// in one of the ranges but not in nums.
    ///
    /// Each range [a,b] in the list should be output as:
    /// 
    /// "a->b" if a != b
    /// "a" if a == b
    ///  
    /// Example 1:
    /// Input: nums = [0,1,2,4,5,7]
    /// Output: ["0->2","4->5","7"]
    /// Explanation: The ranges are:
    /// [0,2] --> "0->2"
    /// [4,5] --> "4->5"
    /// [7,7] --> "7"
    ///
    /// Example 2:
    /// Input: nums = [0,2,3,4,6,8,9]
    /// Output: ["0","2->4","6","8->9"]
    /// Explanation: The ranges are:
    /// [0,0] --> "0"
    /// [2,4] --> "2->4"
    /// [6,6] --> "6"
    /// [8,9] --> "8->9"
    ///
    /// Example 3:
    /// Input: nums = []
    /// Output: []
    ///
    /// Example 4:
    /// Input: nums = [-1]
    /// Output: ["-1"]
    ///
    /// Example 5:
    /// Input: nums = [0]
    /// Output: ["0"]
    /// Constraints:
    /// 1. 0 <= nums.length <= 20
    /// 2. -2^31 <= nums[i] <= 2^31 - 1
    /// 3. All the values of nums are unique.
    /// 4. nums is sorted in ascending order.
    /// </summary>
    vector<string> summaryRanges(vector<int>& nums);

    /// <summary>
    /// Leet code #252. Meeting Rooms
    /// 
    /// Easy
    /// 
    /// Given an array of meeting time intervals where intervals[i] = 
    /// [start[i], end[i]], determine if a person could attend all meetings.
    /// 
    /// Example 1:
    /// Input: intervals = [[0,30],[5,10],[15,20]]
    /// Output: false
    ///
    /// Example 2:
    /// Input: intervals = [[7,10],[2,4]]
    /// Output: true
    /// 
    /// Constraints:
    /// 1. 0 <= intervals.length <= 10^4
    /// 2. intervals[i].length == 2
    /// 3. 0 <= starti < endi <= 10^6
    /// </summary>
    bool canAttendMeetings(vector<vector<int>>& intervals);

    /// <summary>
    /// Leet code #253. Meeting Rooms II  
    /// 
    /// Given an array of meeting time intervals consisting of start 
    /// and end times [[s1,e1],[s2,e2],...] (si < ei), 
    /// find the minimum number of conference rooms required.
    /// For example,
    /// Given [[0, 30],[5, 10],[15, 20]],
    /// return 2. 
    /// </summary>
    int minMeetingRooms(vector<vector<int>>& intervals);

    /// <summary>
    /// Leet code #330. Patching Array 
    ///
    /// Given a sorted positive integer array nums and an integer n, add/patch 
    /// elements to the array such that any number in range [1, n] inclusive 
    /// can be formed by the sum of some elements in the array. 
    /// Return the minimum number of patches required. 
    ///
    /// Example 1:
    /// nums = [1, 3], n = 6
    /// Return 1.
    /// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
    /// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
    /// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
    /// So we only need 1 patch.
    ///
    /// Example 2:
    /// nums = [1, 5, 10], n = 20
    /// Return 2.
    /// The two patches can be [2, 4].
    ///
    /// Example 3:
    /// nums = [1, 2, 2], n = 5
    /// Return 0.
    /// </summary>
    int minPatches(vector<int>& nums, int n);

    /// <summary>
    /// Leet code #358. Rearrange String k Distance Apart   
    /// 
    /// Given a non-empty string s and an integer k, rearrange the string such 
    /// that the same characters are at least distance k from each other. 
    /// All input strings are given in lowercase letters. If it is not possible 
    /// to rearrange the string, return an empty string "". 
    ///
    /// Example 1:
    /// s = "aabbcc", k = 3
    /// Result: "abcabc"
    /// The same letters are at least distance 3 from each other.
    ///
    /// Example 2:
    /// s = "aaabc", k = 3 
    /// Answer: ""
    /// It is not possible to rearrange the string.
    ///
    /// Example 3:
    /// s = "aaadbbcc", k = 2
    /// Answer: "abacabcd"
    /// Another possible answer is: "abcabcda"
    /// The same letters are at least distance 2 from each other.
    /// </summary>
    string rearrangeString(string s, int k);

    /// <summary>
    /// Leet code #435. Non-overlapping Intervals
    /// 
    /// Medium
    /// 
    /// Given a collection of intervals, find the minimum number of intervals 
    /// you need to remove to make the rest of the intervals non-overlapping.
    /// 
    /// Example 1:
    /// Input: [[1,2],[2,3],[3,4],[1,3]]
    /// Output: 1
    /// Explanation: [1,3] can be removed and the rest of intervals are 
    /// non-overlapping.
    ///
    /// Example 2:
    /// Input: [[1,2],[1,2],[1,2]]
    /// Output: 2
    /// Explanation: You need to remove two [1,2] to make the rest of 
    /// intervals non-overlapping.
    ///
    /// Example 3:
    /// Input: [[1,2],[2,3]]
    /// Output: 0
    /// Explanation: You don't need to remove any of the intervals since 
    /// they're already non-overlapping.
    /// 
    /// Note:
    /// You may assume the interval's end point is always bigger than its start 
    /// point.
    /// Intervals like [1,2] and [2,3] have borders "touching" but they don't 
    /// overlap each other.
    /// </summary>
    int eraseOverlapIntervals(vector<vector<int>>& intervals);

    /// <summary>
    /// Leet code #436. Find Right Interval
    /// 
    /// Given a set of intervals, for each of the interval i, check if there exists an interval j 
    /// whose start point is bigger than or equal to the end point of the interval i, which can 
    /// be called that j is on the "right" of i. 
    ///
    /// For any interval i, you need to store the minimum interval j's index, which 
    /// means that the interval j has the minimum start point to build the "right" 
    /// relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. 
    /// Finally, you need output the stored value of each interval as an array. 
    ///
    /// Note:
    /// 1.You may assume the interval's end point is always bigger than its start point.
    /// 2.You may assume none of these intervals have the same start point.
    ///
    /// Example 1:
    /// Input: [ [1,2] ]
    /// Output: [-1]
    /// Explanation: There is only one interval in the collection, so it outputs -1.
    ///
    /// Example 2:
    /// Input: [ [3,4], [2,3], [1,2] ]
    /// Output: [-1, 0, 1]
    /// Explanation: There is no satisfied "right" interval for [3,4].
    /// For [2,3], the interval [3,4] has minimum-"right" start point;
    /// For [1,2], the interval [2,3] has minimum-"right" start point.
    ///
    /// Example 3:
    /// Input: [ [1,4], [2,3], [3,4] ]
    /// Output: [-1, 2, -1]
    /// Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
    /// For [2,3], the interval [3,4] has minimum-"right" start point.
    /// </summary>
    vector<int> findRightInterval(vector<vector<int>>& intervals);

    /// <summary>
    /// Leet code #452. Minimum Number of Arrows to Burst Balloons
    /// 
    /// Medium
    /// 
    /// There are some spherical balloons spread in two-dimensional space. For 
    /// each balloon, provided input is the start and end coordinates of the 
    /// horizontal diameter. Since it's horizontal, y-coordinates don't matter, 
    /// and hence the x-coordinates of start and end of the diameter suffice. 
    /// The start is always smaller than the end.
    ///
    /// An arrow can be shot up exactly vertically from different points along 
    // the x-axis. A balloon with x.start and x.end bursts by an arrow shot at x 
    /// if x.start ¡Ü x ¡Ü x.end. There is no limit to the number of arrows that 
    /// can be shot. An arrow once shot keeps traveling up infinitely.
    ///
    /// Given an array points where points[i] = [x.start, x.end], return the 
    /// minimum number of arrows that must be shot to burst all balloons.
    /// 
    /// Example 1: 
    /// Input: points = [[10,16],[2,8],[1,6],[7,12]]
    /// Output: 2
    /// Explanation: One way is to shoot one arrow for example at x = 6 (bursting 
    /// the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the 
    /// other two balloons).
    ///
    /// Example 2:
    /// Input: points = [[1,2],[3,4],[5,6],[7,8]]
    /// Output: 4
    ///
    /// Example 3:
    /// Input: points = [[1,2],[2,3],[3,4],[4,5]]
    /// Output: 2
    ///
    /// Example 4:
    /// Input: points = [[1,2]]
    /// Output: 1
    ///
    /// Example 5:
    /// Input: points = [[2,3],[2,3]]
    /// Output: 1
    ///
    /// Constraints:
    /// 1. 0 <= points.length <= 10^4
    /// 2. points[i].length == 2
    /// 3. -2^31 <= x.start < x.end <= 2^31 - 1
    /// </summary>
    int findMinArrowShots(vector<vector<int>>& points);

    /// <summary>
    /// Leet code #826. Most Profit Assigning Work
    /// 
    /// We have jobs: difficulty[i] is the difficulty of the ith job, and 
    /// profit[i] is the profit of the ith job. 
    ///
    /// Now we have some workers. worker[i] is the ability of the ith worker, 
    /// which means that this worker can only complete a job with difficulty 
    /// at most worker[i]. 
    /// 
    /// Every worker can be assigned at most one job, but one job can be 
    /// completed multiple times.
    ///
    /// For example, if 3 people attempt the same job that pays $1, then the 
    /// total profit will be $3.  If a worker cannot complete any job, his 
    /// profit is $0.
    ///
    /// What is the most profit we can make?
    ///
    /// Example 1:
    ///
    /// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], 
    /// worker = [4,5,6,7]
    /// Output: 100 
    /// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and 
    /// they get profit of [20,20,30,30] seperately.
    /// Notes:
    ///
    /// 1. 1 <= difficulty.length = profit.length <= 10000
    /// 2. 1 <= worker.length <= 10000
    /// 3. difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
    /// </summary>
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
        vector<int>& worker);

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

    /// <summary>
    /// Leet code #1405. Longest Happy String
    /// 
    /// Medium
    ///
    /// A string is called happy if it does not have any of the strings 
    /// 'aaa', 'bbb' or 'ccc' as a substring. 
    /// 
    /// Given three integers a, b and c, return any string s, which satisfies 
    /// following conditions:
    ///
    /// s is happy and longest possible.
    /// s contains at most a occurrences of the letter 'a', at most b 
    /// occurrences of the letter 'b' and at most c occurrences of the 
    /// letter 'c'.
    /// s will only contain 'a', 'b' and 'c' letters.
    /// If there is no such string s return the empty string "".
    ///
    /// Example 1:
    /// Input: a = 1, b = 1, c = 7
    /// Output: "ccaccbcc"
    /// Explanation: "ccbccacc" would also be a correct answer.
    ///
    /// Example 2:
    /// Input: a = 2, b = 2, c = 1
    /// Output: "aabbc"
    ///
    /// Example 3:
    /// Input: a = 7, b = 1, c = 0
    /// Output: "aabaa"
    /// Explanation: It's the only correct answer in this case.
    /// 
    /// Constraints:
    /// 1. 0 <= a, b, c <= 100
    /// 2. a + b + c > 0
    /// </summary>
    string longestDiverseString(int a, int b, int c);

    /// <summary>
    /// Leet code #1419. Minimum Number of Frogs Croaking
    /// 
    /// Medium
    ///
    /// Given the string croakOfFrogs, which represents a combination of 
    /// the string "croak" from different frogs, that is, multiple frogs 
    /// can croak at the same time, so multiple ¡°croak¡± are mixed. Return 
    /// the minimum number of different frogs to finish all the croak in 
    /// the given string.
    ///
    /// A valid "croak" means a frog is printing 5 letters 'c', 'r', 'o', 
    /// 'a', 'k' sequentially. The frogs have to print all five letters to 
    /// finish a croak. If the given string is not a combination of valid 
    /// "croak" return -1.
    ///
    /// Example 1:
    /// Input: croakOfFrogs = "croakcroak"
    /// Output: 1 
    /// Explanation: One frog yelling "croak" twice.
    ///
    /// Example 2:
    /// Input: croakOfFrogs = "crcoakroak"
    /// Output: 2 
    /// Explanation: The minimum number of frogs is two. 
    /// The first frog could yell "crcoakroak".
    /// The second frog could yell later "crcoakroak".
    ///
    /// Example 3:
    /// Input: croakOfFrogs = "croakcrook"
    /// Output: -1
    /// Explanation: The given string is an invalid combination of 
    /// "croak" from different frogs.
    ///
    /// Example 4:
    /// Input: croakOfFrogs = "croakcroa"
    /// Output: -1
    ///
    /// Constraints:
    /// 1. 1 <= croakOfFrogs.length <= 10^5
    /// 2. All characters in the string are: 'c', 'r', 'o', 'a' or 'k'.
    /// </summary>
    int minNumberOfFrogs(string croakOfFrogs);

    /// <summary>
    /// Leet code #1520. Maximum Number of Non-Overlapping Substrings
    /// 
    /// Medium
    ///
    /// Given a string s of lowercase letters, you need to find the maximum 
    /// number of non-empty substrings of s that meet the following conditions:
    ///
    /// The substrings do not overlap, that is for any two substrings s[i..j] 
    /// and s[k..l], either j < k or i > l is true.
    /// A substring that contains a certain character c must also contain all 
    /// occurrences of c.
    /// Find the maximum number of substrings that meet the above conditions. 
    /// If there are multiple solutions with the same number of substrings, 
    /// return the one with minimum total length. It can be shown that there 
    /// exists a unique solution of minimum total length.
    ///
    /// Notice that you can return the substrings in any order.
    /// Example 1:
    ///
    /// Input: s = "adefaddaccc"
    /// Output: ["e","f","ccc"]
    /// Explanation: The following are all the possible substrings that meet 
    /// the conditions:
    /// [
    ///    "adefaddaccc"
    ///    "adefadda",
    ///  "ef",
    ///  "e",
    ///  "f",
    ///  "ccc",
    /// ]
    /// If we choose the first string, we cannot choose anything else and we'd 
    /// get only 1. If we choose "adefadda", we are left with "ccc" which is 
    /// the only one that doesn't overlap, thus obtaining 2 substrings. Notice 
    /// also, that it's not optimal to choose "ef" since it can be split into 
    /// two. Therefore, the optimal way is to choose ["e","f","ccc"] which 
    /// gives us 3 substrings. No other solution of the same number of 
    /// substrings exist.
    ///
    /// Example 2:
    /// Input: s = "abbaccd"
    /// Output: ["d","bb","cc"]
    /// Explanation: Notice that while the set of substrings ["d","abba","cc"] 
    /// also has length 3, it's considered incorrect since it has larger 
    /// total length.
    ///
    /// Constraints:
    /// 1. 1 <= s.length <= 10^5
    /// 2. s contains only lowercase English letters.
    /// </summary>
    vector<string> maxNumOfSubstrings(string s);

    /// <summary>
    /// Leet code #1562. Find Latest Group of Size M
    /// 
    /// Medium
    ///
    /// Given an array arr that represents a permutation of numbers from 1 
    /// to n. You have a binary string of size n that initially has all 
    /// its bits set to zero.
    ///
    /// At each step i (assuming both the binary string and arr are 1-indexed) 
    /// from 1 to n, the bit at position arr[i] is set to 1. You are given an 
    /// integer m and you need to find the latest step at which there exists 
    /// a group of ones of length m. A group of ones is a contiguous substring 
    /// of 1s such that it cannot be extended in either direction.
    ///
    /// Return the latest step at which there exists a group of ones of length 
    /// exactly m. If no such group exists, return -1.
    /// 
    /// Example 1:
    /// Input: arr = [3,5,1,2,4], m = 1
    /// Output: 4
    /// Explanation:
    /// Step 1: "00100", groups: ["1"]
    /// Step 2: "00101", groups: ["1", "1"]
    /// Step 3: "10101", groups: ["1", "1", "1"]
    /// Step 4: "11101", groups: ["111", "1"]
    /// Step 5: "11111", groups: ["11111"]
    /// The latest step at which there exists a group of size 1 is step 4.
    ///
    /// Example 2:
    /// Input: arr = [3,1,5,4,2], m = 2
    /// Output: -1
    /// Explanation:
    /// Step 1: "00100", groups: ["1"]
    /// Step 2: "10100", groups: ["1", "1"]
    /// Step 3: "10101", groups: ["1", "1", "1"]
    /// Step 4: "10111", groups: ["1", "111"]
    /// Step 5: "11111", groups: ["11111"]
    /// No group of size 2 exists during any step.
    ///
    /// Example 3:
    /// Input: arr = [1], m = 1
    /// Output: 1
    /// Example 4:
    /// Input: arr = [2,1], m = 2
    /// Output: 2
    ///
    /// Constraints:
    /// 1. n == arr.length
    /// 2. 1 <= n <= 10^5
    /// 3. 1 <= arr[i] <= n
    /// 4. All integers in arr are distinct.
    /// 5. 1 <= m <= arr.length
    /// </summary>
    int findLatestStep(vector<int>& arr, int m);

    /// <summary>
    /// Leet code #1589. Maximum Sum Obtained of Any Permutation 
    /// 
    /// Medium
    ///
    /// We have an array of integers, nums, and an array of requests where 
    /// requests[i] = [starti, endi]. The ith request asks for the sum of 
    /// nums[starti] + nums[start[i] + 1] + ... + nums[end[i] - 1] + 
    /// nums[end[]i]. Both start[i] and end[i] are 0-indexed.
    ///
    /// Return the maximum total sum of all requests among all 
    /// permutations of nums.
    ///
    /// Since the answer may be too large, return it modulo 10^9 + 7.
    /// Example 1:
    //
    /// Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
    /// Output: 19
    /// Explanation: One permutation of nums is [2,1,3,4,5] with the following 
    /// result: 
    /// requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
    /// requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
    /// Total sum: 8 + 3 = 11.
    /// A permutation with a higher total sum is [3,5,4,2,1] with the 
    /// following result:
    /// requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
    /// requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
    /// Total sum: 11 + 8 = 19, which is the best that you can do.
    ///
    /// Example 2:
    /// Input: nums = [1,2,3,4,5,6], requests = [[0,1]]
    /// Output: 11
    /// Explanation: A permutation with the max total sum is [6,5,4,3,2,1] 
    /// with request sums [11].
    ///
    /// Example 3:
    /// Input: nums = [1,2,3,4,5,10], requests = [[0,2],[1,3],[1,1]]
    /// Output: 47
    /// Explanation: A permutation with the max total sum is [4,10,5,3,2,1] 
    /// with request sums [19,18,10].
    ///
    /// Constraints:
    /// 1. n == nums.length
    /// 2. 1 <= n <= 105
    /// 3. 0 <= nums[i] <= 105
    /// 4. 1 <= requests.length <= 105
    /// 5. requests[i].length == 2
    /// 6. 0 <= start[i] <= end[i] < n
    /// </summary>
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests);

    /// <summary>
    /// Leet code #1665. Minimum Initial Energy to Finish Tasks
    /// 
    /// Hard
    ///
    /// You are given an array tasks where tasks[i] = [actual[i], minimum[i]]:
    ///
    /// actual[i] is the actual amount of energy you spend to finish the ith 
    /// task.
    /// minimum[i] is the minimum amount of energy you require to begin the 
    /// ith task.
    /// For example, if the task is [10, 12] and your current energy is 11, 
    /// you cannot start this task. However, if your current energy is 13, 
    /// you can complete this task, and your energy will be 3 after finishing 
    /// it.
    ///
    /// You can finish the tasks in any order you like.
    ///
    /// Return the minimum initial amount of energy you will need to finish 
    /// all the tasks.
    ///
    /// Example 1:
    /// Input: tasks = [[1,2],[2,4],[4,8]]
    /// Output: 8
    /// Explanation:
    /// Starting with 8 energy, we finish the tasks in the following order:
    /// - 3rd task. Now energy = 8 - 4 = 4.
    /// - 2nd task. Now energy = 4 - 2 = 2.
    /// - 1st task. Now energy = 2 - 1 = 1.
    /// Notice that even though we have leftover energy, starting with 7 
    /// energy does not work because we cannot do the 3rd task.
    ///
    /// Example 2:
    /// Input: tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
    /// Output: 32
    /// Explanation:
    /// Starting with 32 energy, we finish the tasks in the following order:
    /// - 1st task. Now energy = 32 - 1 = 31.
    /// - 2nd task. Now energy = 31 - 2 = 29.
    /// - 3rd task. Now energy = 29 - 10 = 19.
    /// - 4th task. Now energy = 19 - 10 = 9.
    /// - 5th task. Now energy = 9 - 8 = 1.
    ///
    /// Example 3:
    /// Input: tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
    /// Output: 27
    /// Explanation:
    /// Starting with 27 energy, we finish the tasks in the following order:
    /// - 5th task. Now energy = 27 - 5 = 22.
    /// - 2nd task. Now energy = 22 - 2 = 20.
    /// - 3rd task. Now energy = 20 - 3 = 17.
    /// - 1st task. Now energy = 17 - 1 = 16.
    /// - 4th task. Now energy = 16 - 4 = 12.
    /// - 6th task. Now energy = 12 - 6 = 6.
    ///
    /// Constraints:
    /// 1. 1 <= tasks.length <= 10^5
    /// 2. 1 <= actual[i] <= minimum[i] <= 10^4
    /// </summary>
    int minimumEffort(vector<vector<int>>& tasks);

    /// <summary>
    /// Leet code #1642. Furthest Building You Can Reach
    /// 
    /// Medium
    ///
    /// You are given an integer array heights representing the heights of 
    /// buildings, some bricks, and some ladders.
    ///
    /// You start your journey from building 0 and move to the next building 
    /// by possibly using bricks or ladders.
    ///
    /// While moving from building i to building i+1 (0-indexed),
    ///
    /// If the current building's height is greater than or equal to the next 
    /// building's height, you do not need a ladder or bricks.
    /// If the current building's height is less than the next building's height, 
    /// you can either use one ladder or (h[i+1] - h[i]) bricks.
    /// Return the furthest building index (0-indexed) you can reach if you use 
    /// the given ladders and bricks optimally.
    /// 
    /// Example 1:
    /// Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
    /// Output: 4
    /// Explanation: Starting at building 0, you can follow these steps:
    /// - Go to building 1 without using ladders nor bricks since 4 >= 2.
    /// - Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
    /// - Go to building 3 without using ladders nor bricks since 7 >= 6.
    /// - Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
    /// It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
    ///
    /// Example 2: 
    /// Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
    /// Output: 7
    ///
    /// Example 3:
    /// Input: heights = [14,3,19,3], bricks = 17, ladders = 0
    /// Output: 3
    /// 
    /// Constraints:
    /// 1. 1 <= heights.length <= 10^5
    /// 2. 1 <= heights[i] <= 10^6
    /// 3. 0 <= bricks <= 10^9
    /// 4. 0 <= ladders <= heights.length
    /// </summary>
    int furthestBuilding(vector<int>& heights, int bricks, int ladders);

#pragma endregion
};
#endif  // LeetCodeGreedy_H
