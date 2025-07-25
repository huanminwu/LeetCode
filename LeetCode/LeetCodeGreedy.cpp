﻿#pragma once
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
#include "LeetCodeGreedy.h"
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
/// 3. 0 <= start[i] <= end[i] <= 10^4
/// </summary>
vector<vector<int>> LeetCodeGreedy::merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (result.empty()) result.push_back(intervals[i]);
        else
        {
            if (result.back()[1] < intervals[i][0])
            {
                result.push_back(intervals[i]);
            }
            else
            {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeGreedy::insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<int> temp = newInterval;
    vector<vector<int>> result;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (temp[1] < intervals[i][0])
        {
            result.push_back(temp);
            temp = intervals[i];
        }
        else if (intervals[i][1] < temp[0])
        {
            result.push_back(intervals[i]);
        }
        else
        {
            temp[0] = min(temp[0], intervals[i][0]);
            temp[1] = max(temp[1], intervals[i][1]);
        }
    }
    result.push_back(temp);
    return result;
}

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
int LeetCodeGreedy::minPatches(vector<int>& nums, int n)
{
    int result = 0;
    unsigned long long sum = 0;
    size_t index = 0;
    while (sum < (unsigned long long)n)
    {
        if (index < nums.size() && (unsigned long long) nums[index] <= sum + 1)
        {
            sum += nums[index];
            index++;
        }
        else
        {
            result++;
            sum += sum + 1;
        }
    }
    return result;
}

/// <summary>
/// Leet code # 502. IPO  
///
/// Suppose LeetCode will start its IPO soon. In order to sell a good price 
/// of its shares to Venture Capital, LeetCode would like to work on some 
/// projects to increase its capital before the IPO. Since it has limited 
/// resources, it can only finish at most k distinct projects before the IPO. 
/// Help LeetCode design the best way to maximize its total capital after 
/// finishing at most k distinct projects. 
///
/// You are given several projects. For each project i, it has a pure profit 
/// Pi and a minimum capital of Ci is needed to start the corresponding project. 
/// Initially, you have W capital. When you finish a project, you will obtain 
/// its pure profit and the profit will be added to your total capital. 
/// 
/// To sum up, pick a list of at most k distinct projects from given projects 
/// to maximize your final capital, and output your final maximized capital. 
///
/// Example 1:
///
/// Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
///
/// Output: 4
/// Explanation: Since your initial capital is 0, you can only start the project 
/// indexed 0.
/// After finishing it you will obtain profit 1 and your capital becomes 1.
/// With capital 1, you can either start the project indexed 1 or the project indexed 2.
/// Since you can choose at most 2 projects, you need to finish the project indexed 2 
/// to get the maximum capital.
/// Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
/// Note:
/// 1.You may assume all numbers in the input are non-negative integers.
/// 2.The length of Profits array and Capital array will not exceed 50,000.
/// 3.The answer is guaranteed to fit in a 32-bit signed integer.
/// </summary>
int LeetCodeGreedy::findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital)
{
    priority_queue<pair<int, int>> capital_map;
    priority_queue<int> profit_map;

    for (size_t i = 0; i < Capital.size(); i++)
    {
        capital_map.push(make_pair(-Capital[i], Profits[i]));
    }

    for (int i = 0; i < k; i++)
    {
        while (!capital_map.empty() && -capital_map.top().first <= W)
        {
            profit_map.push(capital_map.top().second);
            capital_map.pop();
        }
        if (profit_map.empty())
        {
            break;
        }
        W += profit_map.top();
        profit_map.pop();
    }
    return W;
}

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
int LeetCodeGreedy::minMeetingRooms(vector<vector<int>>& intervals)
{
    map<int, int> time_line;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        time_line[intervals[i][0]]++;
        time_line[intervals[i][1]]--;
    }
    int max_rooms = 0, rooms = 0;
    for (auto &time : time_line)
    {
        rooms += time.second;
        max_rooms = max(max_rooms, rooms);
    }
    return max_rooms;
}

/// <summary>
/// Leet code #370. Range Addition      
/// 
/// Assume you have an array of length n initialized with all 0's and are given k update operations.
/// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each 
/// element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
/// 
/// Return the modified array after all k operations were executed.
/// Example: 
/// Given:
/// length = 5,
/// updates = [
///    [1,  3,  2],
///    [2,  4,  3],
///    [0,  2, -2]
/// ]
///
/// Output:
/// [-2, 0, 3, 5, 3]
/// Explanation: 
/// Initial state:
/// [ 0, 0, 0, 0, 0 ]
/// After applying operation [1, 3, 2]:
/// [ 0, 2, 2, 2, 0 ]
/// After applying operation [2, 4, 3]:
/// [ 0, 2, 5, 5, 3 ]
/// After applying operation [0, 2, -2]:
/// [-2, 0, 3, 5, 3 ]
/// Hint:
/// 1.Thinking of using advanced data structures? You are thinking it too complicated.
/// 2.For each update operation, do you really need to update all elements between i and j?
/// 3.Update only the first and end element is sufficient.
/// 4.The optimal time complexity is O(k + n) and uses O(1) extra space.
/// </summary>
vector<int> LeetCodeGreedy::getModifiedArray(int length, vector<vector<int>>& updates)
{
    vector<int> result(length);
    for (size_t i = 0; i < updates.size(); i++)
    {
        result[updates[i][0]] += updates[i][2];
        if (updates[i][1] + 1 < length)
        {
            result[updates[i][1] + 1] -= updates[i][2];
        }
    }
    for (int i = 1; i < length; i++)
    {
        result[i] += result[i - 1];
    }
    return result;
}

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
int LeetCodeGreedy::eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    int result = 0;
    struct IntervalCompare
    {
        bool operator() (const vector<int>& a, const vector<int>& b)
        {
            if (a[1] < b[1])
            {
                return true;
            }
            else if ((a[1] == b[1]) && (a[0] > b[0]))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };

    sort(intervals.begin(), intervals.end(), IntervalCompare());
    vector<int> last;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (i == 0)
        {
            last = intervals[i];
        }
        else
        {
            if (intervals[i][0] < last[1]) result++;
            else
            {
                last = intervals[i];
            }
        }
    }
    return result;
}

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
vector<int> LeetCodeGreedy::findRightInterval(vector<vector<int>>& intervals)
{
    vector<int> result;
    map<int, int> range_order;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        range_order[intervals[i][0]] = i;
    }
    for (size_t i = 0; i < intervals.size(); i++)
    {
        map<int, int>::iterator itr = range_order.lower_bound(intervals[i][1]);
        if (itr == range_order.end())
        {
            result.push_back(-1);
        }
        else
        {
            result.push_back(itr->second);
        }
    }
    return result;
}

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
/// the x-axis. A balloon with x.start and x.end bursts by an arrow shot at x 
/// if x.start <= x <= x.end. There is no limit to the number of arrows that 
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
int LeetCodeGreedy::findMinArrowShots(vector<vector<int>>& points)
{
    int result = 0;
    vector<vector<int>> temp = points;
    for (size_t i = 0; i < temp.size(); i++)
    {
        swap(temp[i][0], temp[i][1]);
    }
    sort(temp.begin(), temp.end());
    int prev = -1;
    for (size_t i = 0; i < temp.size(); i++)
    {
        if (i == 0) prev = 0;
        else
        {
            if (temp[i][1] <= temp[prev][0]) result++;
            else prev = i;
        }
    }
    return points.size() - result;
}

/// <summary>
/// Leet code #218. The Skyline Problem    
/// 
/// A city's skyline is the outer contour of the silhouette formed 
/// by all the buildings in that city when viewed from a distance. 
/// Now suppose you are given the locations and height of all the buildings 
/// as shown on a cityscape photo (Figure A), write a program to output 
/// the skyline formed by these buildings collectively (Figure B).
///
/// Buildings   Skyline Contour    
/// The geometric information of each building is represented by a triplet of 
/// integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left 
/// and right edge of the ith building, respectively, and Hi is its height. 
/// It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, 
/// and Ri - Li > 0. 
/// You may assume all buildings are perfect rectangles grounded on an 
/// absolutely flat surface at height 0.
///
/// For instance, the dimensions of all buildings in Figure A are recorded as: 
/// [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
/// The output is a list of "key points" (red dots in Figure B) in the format of 
/// [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key 
/// point is the left endpoint of a horizontal line segment. Note that the last 
/// key point, where the rightmost building ends, is merely used to mark the 
/// termination of the skyline, and always has zero height. Also, the ground in 
/// between any two adjacent buildings should be considered part of the skyline 
/// contour. 
/// For instance, the skyline in Figure B should be represented as:
/// [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
/// Notes: 
/// 1. The number of buildings in any input list is guaranteed to be in the 
///    range [0, 10000].
/// 2. The input list is already sorted in ascending order by the left x 
///    position Li. 
/// 3. The output list must be sorted by the x position. 
/// 4. There must be no consecutive horizontal lines of equal height in the 
///    output skyline. 
/// 5. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not 
///    acceptable; 
/// 6. the three lines of height 5 should be merged into one in the final 
///    output as such: [...[2 3], [4 5], [12 7], ...]
/// </summary>
vector<vector<int>> LeetCodeGreedy::getSkyline(vector<vector<int>>& buildings)
{
    vector<vector<int>> result;
    map<int, vector<int>> edge_map;
    for (size_t i = 0; i < buildings.size(); i++)
    {
        // left side
        edge_map[buildings[i][0]].push_back(buildings[i][2]);
        // right side
        edge_map[buildings[i][1]].push_back(-buildings[i][2]);
    }
    // we may have multiple building with same height
    map<int, int> skylines;
    for (auto &edge : edge_map)
    {
        for (auto height : edge.second)
        {
            if (height > 0)
            {
                skylines[height]++;
            }
            else
            {
                skylines[-height]--;
                if (skylines[-height] == 0) skylines.erase(-height);
            }
        }
        int skyline = 0;
        // skyline is heightest building
        if (!skylines.empty())
        {
            skyline = skylines.rbegin()->first;
        }
        // push to result if not same height
        if (result.empty() || result.back()[1] != skyline)
        {
            result.push_back({ edge.first, skyline });
        }
    }
    return result;
}

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
vector<string> LeetCodeGreedy::summaryRanges(vector<int>& nums)
{
    vector<string> result;
    size_t first = 0, last = 0, next = 1;
    while (last < nums.size())
    {
        if (next == nums.size() || nums[last] + 1 < nums[next])
        {
            if (first == last)
            {
                result.push_back(to_string(nums[first]));
            }
            else
            {
                result.push_back(to_string(nums[first]) + "->" + to_string(nums[last]));
            }
            first = next;
            last = next;
        }
        else
        {
            last++;
        }
        next++;
    }
    return result;
}

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
bool LeetCodeGreedy::canAttendMeetings(vector<vector<int>>& intervals)
{

    sort(intervals.begin(), intervals.end());
    for (size_t i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < intervals[i - 1][1])
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet code #163. Missing Ranges 
/// 
/// Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], 
/// return its missing ranges.
/// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"]. 
/// </summary>
vector<string> LeetCodeGreedy::findMissingRanges(vector<int>& nums, int lower, int upper)
{
    vector<string> result;
    int expect = lower;
    int end;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > expect)
        {
            end = nums[i] - 1;
            if (expect == end)
            {
                result.push_back(to_string(expect));
            }
            else if (expect < end)
            {
                result.push_back(to_string(expect) + "->" + to_string(end));
            }
        }
        expect = nums[i] + 1;
    }
    if (expect <= upper)
    {
        end = upper;
        if (expect == end)
        {
            result.push_back(to_string(expect));
        }
        else if (expect < end)
        {
            result.push_back(to_string(expect) + "->" + to_string(end));
        }
    }
    return result;
}

/// <summary>
/// Leet code #495. Teemo Attacking
/// 
/// Medium
/// 
/// In LOL world, there is a hero called Teemo and his attacking can make 
/// his enemy Ashe be in poisoned condition. Now, given the Teemo's 
/// attacking ascending time series towards Ashe and the poisoning time 
/// duration per Teemo's attacking, you need to output the total time 
/// that Ashe is in poisoned condition.
///
/// You may assume that Teemo attacks at the very beginning of a specific 
/// time point, and makes Ashe be in poisoned condition immediately.
///
/// Example 1:
/// Input: [1,4], 2
/// Output: 4
/// Explanation: At time point 1, Teemo starts attacking Ashe and makes 
/// Ashe be poisoned immediately. 
/// This poisoned status will last 2 seconds until the end of time point 2. 
/// And at time point 4, Teemo attacks Ashe again, and causes Ashe to be 
/// in poisoned status for another 2 seconds. 
/// So you finally need to output 4.
///
/// Example 2:
/// Input: [1,2], 2
/// Output: 3
/// Explanation: At time point 1, Teemo starts attacking Ashe and makes 
/// Ashe be poisoned. 
/// This poisoned status will last 2 seconds until the end of time point 2. 
/// However, at the beginning of time point 2, Teemo attacks Ashe again 
/// who is already in poisoned status. 
/// Since the poisoned status won't add up together, though the second 
/// poisoning attack will still work at time point 2, it will stop at the 
/// end of time point 3. 
/// So you finally need to output 3.
/// 
/// Note:
/// 1. You may assume the length of given time series array won't 
///    exceed 10000.
/// You may assume the numbers in the Teemo's attacking time series and 
/// his poisoning time duration per attacking are non-negative integers, 
/// which won't exceed 10,000,000.
/// </summary>
int LeetCodeGreedy::findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    int result = 0;
    int last_end = -1;
    for (size_t i = 0; i < timeSeries.size(); i++)
    {
        int next_end = timeSeries[i] + duration;
        result += min(duration, next_end - last_end);
        last_end = next_end;
    }
    return result;
}

/// <summary>
/// Leet code #554. Brick Wall  
/// 
/// There is a brick wall in front of you. The wall is rectangular and has 
/// several rows of bricks. The bricks have the same height but different 
/// width. You want to draw a vertical line from the top to the bottom and 
/// cross the least bricks. 
/// The brick wall is represented by a list of rows. Each row is a list of 
/// integers representing the width of each brick in this row from left to 
/// right. 
/// If your line go through the edge of a brick, then the brick is not 
/// considered as crossed. You need to find out how to draw the line to 
/// cross the least bricks and return the number of crossed bricks. 
/// You cannot draw a line just along one of the two vertical edges of the
///    wall, in which case the line will obviously cross no bricks. 
/// Example:
/// Input: 
/// [[1,2,2,1],
/// [3,1,2],
/// [1,3,2],
/// [2,4],
/// [3,1,2],
/// [1,3,1,1]]
/// Output: 2
/// Explanation: 
/// Note:
/// The width sum of bricks in different rows are the same and won't exceed 
/// INT_MAX. 
/// The number of bricks in each row is in range [1,10,000]. The height of 
/// wall is in range [1,10,000]. Total number of bricks of the wall won't 
/// exceed 20,000. 
/// </summary>
int LeetCodeGreedy::leastBricks(vector<vector<int>>& wall)
{
    unordered_map<int, int> align_map;
    for (size_t i = 0; i < wall.size(); i++)
    {
        int distance = 0;
        for (size_t j = 0; j < wall[i].size() - 1; j++)
        {
            distance += wall[i][j];
            align_map[distance]++;
        }
    }

    int min_bricks = wall.size();
    for (auto &itr : align_map)
    {
        min_bricks = min(min_bricks, (int)wall.size() - itr.second);
    }
    return min_bricks;
}

/// <summary>
/// Leet code #598. Range Addition II   
/// 
/// Given an m * n matrix M initialized with all 0's and several update 
/// operations.
/// Operations are represented by a 2D array, and each operation is 
/// represented by an array with two positive integers a and b, which 
/// means M[i][j] should be added by one for all 0 <= i < a and 0 <= j < b.
/// You need to count and return the number of maximum integers in the 
/// matrix after performing all the operations.
/// Example 1:
/// Input: 
/// m = 3, n = 3
/// operations = [[2,2],[3,3]]
/// Output: 4
/// Explanation: 
/// Initially, M = 
/// [
///   [0, 0, 0],
///   [0, 0, 0],
///   [0, 0, 0]
/// ]
/// After performing [2,2], M = 
/// [
///   [1, 1, 0],
///   [1, 1, 0],
///   [0, 0, 0]
/// ]
/// After performing [3,3], M = 
/// [
///   [2, 2, 1],
///   [2, 2, 1],
///   [1, 1, 1]
/// ]
/// So the maximum integer in M is 2, and there are four of it in M. So 
/// return 4.
/// Note:
/// The range of m and n is [1,40000].
/// The range of a is [1,m], and the range of b is [1,n].
/// The range of operations size won't exceed 10,000.
/// </summary>
int LeetCodeGreedy::maxCount(int m, int n, vector<vector<int>>& ops)
{
    pair<int, int> result = make_pair(m, n);
    for (auto &range : ops)
    {
        result.first = min(range[0], result.first);
        result.second = min(range[1], result.second);
    }
    return result.first * result.second;
}

/// <summary>
/// Leet code #621. Task Scheduler
/// 
/// Given a char array representing tasks CPU need to do. It contains 
/// capital letters A to Z where different letters represent different 
/// tasks. Tasks could be done without original order. Each task could 
/// be done in one interval. For each interval, CPU could finish one 
/// task or just be idle.    
/// However, there is a non-negative cooling interval n that means 
/// between two same tasks, there must be at least n intervals that 
/// CPU are doing different tasks or just be idle. 
/// You need to return the least number of intervals the CPU will take 
/// to finish all the given tasks.
///
/// Example 1:
/// Input: tasks = ['A','A','A','B','B','B'], n = 2
/// Output: 8
/// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
///
/// Note:
/// 1.The number of tasks is in the range [1, 10000].
/// 2.The integer n is in the range [0, 100].
/// </summary>
int LeetCodeGreedy::leastInterval(vector<char>& tasks, int n)
{
    int result = 0;
    unordered_map<char, int> task_count;
    priority_queue<pair<int, int>> task_queue;
    for (char task : tasks)  task_count[task]++;

    for (auto &itr : task_count)
    {
        task_queue.push(make_pair(0, itr.second));
    }

    while (!task_queue.empty())
    {
        result++;
        // get top task;
        pair<int, int> task = task_queue.top();

        // if closed task still not ready to schedule, we push a idle;
        if (-task.first < result)
        {
            task_queue.pop();
            task.second--;
            if (task.second != 0)
            {
                task_queue.push(make_pair(task.first - n - 1, task.second));
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #630. Course Schedule III
/// 
/// There are n different online courses numbered from 1 to n. Each course 
/// has some duration(course length) t and closed on dth day. A course 
/// should be taken continuously for t days and must be finished before or 
/// on the dth day. You will start at the 1st day. 
///
/// Given n online courses represented by pairs (t,d), your task is to 
/// find the maximal number of courses that can be taken. 
/// Example:
/// Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
/// Output: 3
/// Explanation: 
/// There're totally 4 courses, but you can take 3 courses at most:
/// First, take the 1st course, it costs 100 days so you will finish it on 
/// the 100th day, and ready to take the next course on the 101st day.
/// Second, take the 3rd course, it costs 1000 days so you will finish it 
/// on the 1100th day, and ready to take the next course on the 1101st day. 
/// Third, take the 2nd course, it costs 200 days so you will finish it on 
/// the 1300th day. 
/// The 4th course cannot be taken now, since you will finish it on the 
/// 3300th day, which exceeds the closed date.
/// Note:
/// The integer 1 <= d, t, n <= 10,000. 
/// You can't take two courses simultaneously.
/// </summary>
int LeetCodeGreedy::scheduleCourse(vector<vector<int>>& courses)
{
    struct dead_line_compare
    {
        bool operator() (vector<int>& a, vector<int>&b)
        {
            if (a[1] == b[1]) return (a[0] < b[0]);
            else return(a[1] < b[1]);
        }
    };

    sort(courses.begin(), courses.end(), dead_line_compare());

    int time = 0;
    priority_queue<int> course_duration;
    for (size_t i = 0; i < courses.size(); i++)
    {
        pair<int, int> schedule = make_pair(courses[i][0], courses[i][1]);

        // if start time later than now, we are greedy
        if (schedule.second >= time + schedule.first)
        {
            course_duration.push(schedule.first);
            time += schedule.first;
        }
        // if we can not make it, we replace the longest course
        else
        {
            if ((!course_duration.empty()) && (course_duration.top() > schedule.first))
            {
                time -= (course_duration.top() - schedule.first);
                course_duration.pop();
                course_duration.push(schedule.first);
            }
        }
    }

    return course_duration.size();
}

/// <summary>
/// Leet code #646. Maximum Length of Pair Chain
/// 
/// You are given n pairs of numbers. In every pair, the first number is 
/// always smaller than the second number.
/// Now, we define a pair (c, d) can follow another pair (a, b) if and 
/// only if b < c. Chain of pairs can be formed in this fashion.
///
/// Given a set of pairs, find the length longest chain which can be 
/// formed. You needn't use up all the given pairs. You can select pairs 
/// in any order.
///
/// Example 1:
/// Input: [[1,2], [2,3], [3,4]]
/// Output: 2
/// Explanation: The longest chain is [1,2] -> [3,4]
/// Note:
/// The number of given pairs will be in the range [1, 1000].
/// </summary>
int LeetCodeGreedy::findLongestChain(vector<vector<int>>& pairs)
{
    map<int, vector<int>> schedule_map;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if ((schedule_map.count(pairs[i][1]) == 0) ||
            (schedule_map[pairs[i][1]][0] < pairs[i][0]))
        {
            schedule_map[pairs[i][1]] = pairs[i];
        }
    }
    int count = 0, last = 0;
    for (map<int, vector<int>>::iterator itr = schedule_map.begin(); itr != schedule_map.end(); itr++)
    {
        if (count == 0 || itr->second[0] > last)
        {
            count++;
            last = itr->second[1];
        }
    }
    return count;
}

/// <summary>
/// Leet code #699. Falling Squares      
/// 
/// On an infinite number line (x-axis), we drop given squares in the order 
/// they are given.
///
/// The i-th square dropped (positions[i] = (left, side_length)) is a 
/// square with the left-most point being positions[i][0] and sidelength 
/// positions[i][1].
///
/// The square is dropped with the bottom edge parallel to the number line, 
/// and from a higher height than all currently landed squares. We wait for 
/// each square to stick before dropping the next.
///
/// The squares are infinitely sticky on their bottom edge, and will remain 
/// fixed to any positive length surface they touch (either the number line 
/// or another square). Squares dropped adjacent to each other will not 
/// stick together prematurely.
///
/// Return a list ans of heights. Each height ans[i] represents the current 
/// highest height of any square we have dropped, after dropping squares 
/// represented by positions[0], positions[1], ..., positions[i].
///
/// Example 1:
/// Input: [[1, 2], [2, 3], [6, 1]]
/// Output: [2, 5, 5]
/// Explanation:
///
/// After the first drop of 
/// positions[0] = [1, 2]:
/// _aa
/// _aa
/// -------
/// The maximum height of any square is 2.
///
/// After the second drop of 
/// positions[1] = [2, 3]:
/// __aaa
/// __aaa
/// __aaa
/// _aa__
/// _aa__
/// --------------
/// The maximum height of any square is 5.  
/// The larger square stays on top of the smaller square despite where its 
/// center of gravity is, because squares are infinitely sticky on their 
/// bottom edge.
///
/// After the third drop of 
/// positions[1] = [6, 1]:
/// __aaa
/// __aaa
/// __aaa
/// _aa
/// _aa___a
/// --------------
/// The maximum height of any square is still 5.
///
/// Thus, we return an answer of 
/// [2, 5, 5]
///
/// Example 2:
/// Input: [[100, 100], [200, 100]]
/// Output: [100, 100]
/// Explanation: Adjacent squares don't get stuck prematurely - only their 
/// bottom edge can stick to surfaces.
/// 
/// Note:
/// 1 <= positions.length <= 1000.
/// 1 <= positions[i][0] <= 10^8.
/// 1 <= positions[i][1] <= 10^6.
/// </summary>
vector<int> LeetCodeGreedy::fallingSquares(vector<vector<int>>& positions)
{
    vector<int> result;
    // remember the start position and height
    map<int, int> pos_map;
    pos_map[INT_MAX] = 0;
    int max_height = 0;
    for (size_t i = 0; i < positions.size(); i++)
    {
        auto itr = pos_map.lower_bound(positions[i][0]);
        int prev = itr->second;
        int height = 0;
        while (itr->first < positions[i][0] + positions[i][1])
        {
            auto temp = itr;
            if (itr->first > positions[i][0])
            {
                height = max(height, itr->second);
            }
            itr++;
            pos_map.erase(temp);
        }
        height = max(height, itr->second);
        height += positions[i][1];
        // set start as prev height
        pos_map[positions[i][0]] = prev;
        // set end as maximum height in range
        pos_map[positions[i][0] + positions[i][1]] = height;
        // calculate max height 
        max_height = max(max_height, height);
        result.push_back(max_height);
    }
    return result;
}

/// <summary>
/// Leet code #757. Set Intersection Size At Least Two
///
/// An integer interval [a, b] (for integers a < b) is a set of all 
/// consecutive integers from a to b, including a and b.
///
/// Find the minimum size of a set S such that for every integer interval 
/// A in intervals, the intersection of S with A has size at least 2.
///
/// Example 1:
/// Input: intervals = [[1, 3], [1, 4], [2, 5], [3, 5]]
/// Output: 3
/// Explanation:
/// Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 
/// elements from S in the interval.
/// Also, there isn't a smaller size set that fulfills the above condition.
/// Thus, we output the size of this set, which is 3.
///
/// Example 2:
/// Input: intervals = [[1, 2], [2, 3], [2, 4], [4, 5]]
/// Output: 5
/// Explanation:
/// An example of a minimum sized set is {1, 2, 3, 4, 5}.
/// Note:
/// 1. intervals will have length in range [1, 3000].
/// 2. intervals[i] will have length 2, representing some integer interval.
/// 3. intervals[i][j] will be an integer in [0, 10^8].
/// </summary>
int LeetCodeGreedy::intersectionSizeTwo(vector<vector<int>>& intervals)
{
    for (size_t i = 0; i < intervals.size(); i++)
    {
        swap(intervals[i][0], intervals[i][1]);
        intervals[i][1] = 0 - intervals[i][1];
    }
    sort(intervals.begin(), intervals.end());
    for (size_t i = 0; i < intervals.size(); i++)
    {
        intervals[i][1] = 0 - intervals[i][1];
        swap(intervals[i][0], intervals[i][1]);
    }
    vector<int> points;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (points.empty())
        {
            points.push_back(intervals[i][1] - 1);
            points.push_back(intervals[i][1]);
        }
        else
        {
            if (intervals[i][0] <= points[points.size() - 2])
            {
                continue;
            }
            else if (intervals[i][0] <= points[points.size() - 1])
            {
                points.push_back(intervals[i][1]);
            }
            else
            {
                points.push_back(intervals[i][1] - 1);
                points.push_back(intervals[i][1]);
            }
        }
    }
    return points.size();
}


/// <summary>
/// Leet code #759. Employee Free Time    
///
/// We are given a list schedule of employees, which represents the working 
/// time for each employee.
///
/// Each employee has a list of non-overlapping Intervals, and these 
/// intervals are in sorted order.
///
/// Return the list of finite intervals representing common, positive-length 
/// free time for all employees, also in sorted order.
/// 
/// Example 1:
/// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
/// Output: [[3,4]]
/// Explanation:
/// There are a total of three employees, and all common
/// free time intervals would be [-inf, 1], [3, 4], [10, inf].
/// We discard any intervals that contain inf as they aren't finite.
/// Example 2:
/// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
/// Output: [[5,6],[7,9]]
/// (Even though we are representing Intervals in the form [x, y], the objects
/// inside are Intervals, not lists or arrays. For example, 
/// schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] 
/// is not defined.)
/// 
/// Also, we wouldn't include intervals like [5, 5] in our answer, as they 
/// have zero length.
/// 
/// Note:
/// 1. schedule and schedule[i] are lists with lengths in range [1, 50].
/// 2. 0 <= schedule[i].start < schedule[i].end <= 10^8.
/// </summary>
vector<Interval> LeetCodeGreedy::employeeFreeTime(vector<vector<Interval>>& schedule)
{
    vector<Interval> result;
    map<int, int> time_map;
    for (size_t i = 0; i < schedule.size(); i++)
    {
        for (size_t j = 0; j < schedule[i].size(); j++)
        {
            time_map[schedule[i][j].start]++;
            time_map[schedule[i][j].end]--;
        }
    }
    Interval interval = { -1, -1 };
    int count = 0;
    for (auto &itr : time_map)
    {
        count += itr.second;
        if (count == 0) interval.start = itr.first;
        else if (interval.start != -1)
        {
            interval.end = itr.first;
            result.push_back(interval);
            interval.start = -1;
        }
    }
    return result;
}

/// <summary>
/// Leet code #850. Rectangle Area II
/// 
/// We are given a list of (axis-aligned) rectangles.  Each rectangle[i] = 
/// [x1, y1, x2, y2] , where (x1, y1) are the coordinates of the bottom-left 
/// corner, and (x2, y2) are the coordinates of the top-right corner of the ith 
/// rectangle.
///
/// Find the total area covered by all rectangles in the plane.  Since the 
/// answer may be too large, return it modulo 10^9 + 7.
///
/// Example 1:
///
/// Input: [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
/// Output: 6
/// Explanation: As illustrated in the picture.
///
/// Example 2:
///
/// Input: [[0,0,1000000000,1000000000]]
/// Output: 49
/// Explanation: The answer is 10^18 modulo (10^9 + 7), 
/// which is (10^9)^2 = (-7)^2 = 49.
/// Note:
///
/// 1 <= rectangles.length <= 200
/// rectanges[i].length = 4
/// 0 <= rectangles[i][j] <= 10^9
/// The total area covered by all rectangles will never exceed 2^63 - 1 and 
/// thus will fit in a 64-bit signed integer.
/// </summary>
int LeetCodeGreedy::rectangleArea(vector<vector<int>>& rectangles)
{
    int mod = 1000000007;
    unsigned long long result = 0;
    set<int> sx, sy;
    for (size_t i = 0; i < rectangles.size(); i++)
    {
        sx.insert(rectangles[i][0]);
        sy.insert(rectangles[i][1]);
        sx.insert(rectangles[i][2]);
        sy.insert(rectangles[i][3]);
    }
    vector<int> vx(sx.begin(), sx.end()), vy(sy.begin(), sy.end());
    vector<vector<int>> visited(vx.size(), vector<int>(vy.size()));
    for (auto &r : rectangles)
    {
        for (auto x = lower_bound(vx.begin(), vx.end(), r[0]) - vx.begin(); vx[x] != r[2]; x++)
        {
            for (auto y = lower_bound(vy.begin(), vy.end(), r[1]) - vy.begin(); vy[y] != r[3]; y++)
            {
                if ((x == vx.size() - 1) || (y == vy.size() - 1)) break;
                if (visited[x][y]  == 0)
                {
                    visited[x][y] = 1;
                    result += ((long long)vx[x + 1] - (long long)vx[x]) * 
                              ((long long)vy[y + 1] - (long long)vy[y]) % mod;
                    result %= mod;
                }
            }
        }
    }
    return (int)(result % mod);
}

/// <summary>
/// Leet code #948. Bag of Tokens
/// 
/// You have an initial power P, an initial score of 0 points, and a bag 
/// of tokens.
/// 
/// Each token can be used at most once, has a value token[i], and has 
/// potentially two ways to use it.
///
/// If we have at least token[i] power, we may play the token face up, 
/// losing token[i] power, and gaining 1 point.
/// If we have at least 1 point, we may play the token face down, gaining 
/// token[i] power, and losing 1 point.
/// Return the largest number of points we can have after playing any 
/// number of tokens.
///
/// Example 1:
///
/// Input: tokens = [100], P = 50
/// Output: 0
///
/// Example 2:
///
/// Input: tokens = [100,200], P = 150
/// Output: 1
///
/// Example 3:
///
/// Input: tokens = [100,200,300,400], P = 200
/// Output: 2
/// Note:
///
/// 1. tokens.length <= 1000
/// 2. 0 <= tokens[i] < 10000
/// 3. 0 <= P < 10000
/// </summary>
int LeetCodeGreedy::bagOfTokensScore(vector<int>& tokens, int P)
{
    int result = 0;
    int points = 0;
    int power = P;
    sort(tokens.begin(), tokens.end());
    int first = 0;
    int last = tokens.size() - 1;
    while (first <= last)
    {
        if (power >= tokens[first])
        {
            power -= tokens[first];
            points++;
            result = max(result, points);
            first++;
        }
        else if (points > 0)
        {
            power += tokens[last];
            points--;
            last--;
        }
        else
        {
            break;
        }
    }
    return result;
}

/// <summary>
/// Leet code #984. String Without AAA or BBB
/// 
/// Given two integers A and B, return any string S such that:
/// S has length A + B and contains exactly A 'a' letters, and exactly 
/// B 'b' letters;
/// The substring 'aaa' does not occur in S;
/// The substring 'bbb' does not occur in S.
/// 
/// Example 1:
/// Input: A = 1, B = 2
/// Output: "abb"
/// Explanation: "abb", "bab" and "bba" are all correct answers.
///
/// Example 2:
/// Input: A = 4, B = 1
/// Output: "aabaa"
/// 
/// Note:
/// 1. 0 <= A <= 100
/// 2. 0 <= B <= 100
/// 3. It is guaranteed such an S exists for the given A and B.
/// </summary>
string LeetCodeGreedy::strWithout3a3b(int A, int B)
{
    int state = A > B ? 0 : 1;
    string result;
    while (A > 0 || B > 0)
    {
        if (state == 0)
        {
            if (A > B && A > 1)
            {
                result.append("aa");
                A -= 2;
            }
            else if (A > 0)
            {
                result.append("a");
                A -= 1;
            }
        }
        else // state == 1
        {
            if (B > A && B > 1)
            {
                result.append("bb");
                B -= 2;
            }
            else if (B > 0)
            {
                result.append("b");
                B -= 1;
            }
        }
        state = 1 - state;
    }
    return result;
}

/// <summary>
/// Leet code #986. Interval List Intersections
/// 
/// Given two lists of closed intervals, each list of intervals is 
/// pairwise disjoint and in sorted order.
///
/// Return the intersection of these two interval lists.
///
/// (Formally, a closed interval [a, b] (with a <= b) denotes the 
/// set of real numbers x with a <= x <= b.  The intersection of two 
/// closed intervals is a set of real numbers that is either empty, or 
/// can be represented as a closed interval.  For example, the 
/// intersection of [1, 3] and [2, 4] is [2, 3].)
///
/// Example 1:
/// Input: A = [[0,2],[5,10],[13,23],[24,25]],
/// B = [[1,5],[8,12],[15,24],[25,26]]
/// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
/// Reminder: The inputs and the desired output are lists of Interval 
/// objects, and not arrays or lists.
///
/// Note:
/// 1. 0 <= A.length < 1000
/// 2. 0 <= B.length < 1000
/// 3. 0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
/// </summary>
vector<vector<int>> LeetCodeGreedy::intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
{
    int i = 0, j = 0;
    vector<vector<int>> result;

    while (i < (int)A.size() && j < (int)B.size())
    {
        if (A[i][1] < B[j][0])
        {
            i++;
        }
        else if (B[j][1] < A[i][0])
        {
            j++;
        }
        else
        {
            vector<int> intersection = 
            { 
                max(A[i][0], B[j][0]), min(A[i][1], B[j][1]) 
            };
            result.push_back(intersection);
            if (A[i][1] < B[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}

/// <summary>
/// Leet code #1024. Video Stitching
/// 
/// You are given a series of video clips from a sporting event that lasted T 
/// seconds.  These video clips can be overlapping with each other and have 
/// varied lengths.
///
/// Each video clip clips[i] is an interval: it starts at time clips[i][0] and 
/// ends at time clips[i][1].  We can cut these clips into segments freely: 
/// for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + 
/// [3, 7].
///
/// Return the minimum number of clips needed so that we can cut the clips into
/// segments that cover the entire sporting event ([0, T]).  If the task is 
/// impossible, return -1.
///
/// Example 1:
///
/// Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
/// Output: 3
/// Explanation: 
/// We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
/// Then, we can reconstruct the sporting event as follows:
/// We cut [1,9] into segments [1,2] + [2,8] + [8,9].
/// Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event
/// [0, 10].
///
/// Example 2:
///
/// Input: clips = [[0,1],[1,2]], T = 5
/// Output: -1
/// Explanation: 
/// We can't cover [0,5] with only [0,1] and [0,2].
///
/// Example 3:
///
/// Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],
/// [1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
/// Output: 3
/// Explanation: 
/// We can take clips [0,4], [4,7], and [6,9].
///
/// Example 4:
///
/// Input: clips = [[0,4],[2,8]], T = 5
/// Output: 2
/// Explanation: 
/// Notice you can have extra video after the event ends.
/// 
/// 
/// Note:
/// 1. 1 <= clips.length <= 100
/// 2. 0 <= clips[i][0], clips[i][1] <= 100
/// 3. 0 <= T <= 100
/// </summary>
int LeetCodeGreedy::videoStitching(vector<vector<int>>& clips, int T)
{
    int result = 0;
    pair<int, int> all_clip = { 0, 0 };
    int next_end = all_clip.second;
    std::sort(clips.begin(), clips.end());
    size_t index = 0;
    while (index < clips.size() && all_clip.second - all_clip.first < T)
    {
        if (clips[index][0] > all_clip.second)
        {
            if (next_end > all_clip.second)
            {
                result++;
                all_clip.second = next_end;
            }
            else
            {
                break;
            }
        }
        else
        {
            next_end = max(clips[index][1], next_end);
            index++;
            if (index == clips.size())
            {
                if (next_end > all_clip.second)
                {
                    result++;
                    all_clip.second = next_end;
                }
            }
        }
    }
    if (all_clip.second - all_clip.first >= T)
    {
        return result;
    }
    else
    {
        return -1;
    }
}

/// <summary>
/// Leet code #1054. Distant Barcodes
/// 
/// In a warehouse, there is a row of barcodes, where the i-th barcode is 
/// barcodes[i].
///
/// Rearrange the barcodes so that no two adjacent barcodes are equal.  You 
/// may return any answer, and it is guaranteed an answer exists.
///
/// Example 1:
///
/// Input: [1,1,1,2,2,2]
/// Output: [2,1,2,1,2,1]
///
/// Example 2:
///
/// Input: [1,1,1,1,2,2,3,3]
/// Output: [1,3,1,3,2,1,2,1]
/// Note:
///
/// 1. 1 <= barcodes.length <= 10000
/// 2. 1 <= barcodes[i] <= 10000
/// </summary>
vector<int> LeetCodeGreedy::rearrangeBarcodes(vector<int>& barcodes)
{
    priority_queue<pair<int, int>> code_heap;
    unordered_map<int, int> code_count;
    for (size_t i = 0; i < barcodes.size(); i++)
    {
        code_count[barcodes[i]]++;
    }
    for (auto &itr : code_count)
    {
        code_heap.push(make_pair(itr.second, itr.first));
    }

    vector<int> result;
    while (!code_heap.empty())
    {
        pair<int, int> code, next;
        code = code_heap.top();
        code_heap.pop();
        if (result.empty() || result.back() != code.second)
        {
            result.push_back(code.second);
            code.first--;
            if (code.first > 0) code_heap.push(code);
        }
        else
        {
            next = code_heap.top();
            code_heap.pop();
            result.push_back(next.second);
            next.first--;
            if (next.first > 0) code_heap.push(next);
            if (code.first > 0) code_heap.push(code);
        }
    }
    return result;
}

/// <summary>
/// Leet code #1094. Car Pooling
/// 
/// You are driving a vehicle that has capacity empty seats initially 
/// available for passengers.  The vehicle only drives east (ie. it 
/// cannot turn around and drive west.)
///
/// Given a list of trips, trip[i] = [num_passengers, start_location, 
/// end_location] contains information about the i-th trip: the number 
/// of passengers that must be picked up, and the locations to pick them 
/// up and drop them off.  The locations are given as the number of 
/// kilometers due east from your vehicle's initial location.
///
/// Return true if and only if it is possible to pick up and drop off all 
/// passengers for all the given trips. 
/// 
/// Example 1:
/// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
/// Output: false
///
/// Example 2:
/// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
/// Output: true
///
/// Example 3:
/// Input: trips = [[2,1,5],[3,5,7]], capacity = 3
/// Output: true
///
/// Example 4:
/// Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
/// Output: true
/// 
/// Constraints:
/// 1. trips.length <= 1000
/// 2. trips[i].length == 3
/// 3. 1 <= trips[i][0] <= 100
/// 4. 0 <= trips[i][1] < trips[i][2] <= 1000
/// 5. 1 <= capacity <= 100000
/// </summary>
bool LeetCodeGreedy::carPooling(vector<vector<int>>& trips, int capacity)
{
    map<int, int> stops;
    for (size_t i = 0; i < trips.size(); i++)
    {
        stops[trips[i][1]] += trips[i][0];
        stops[trips[i][2]] -= trips[i][0];
    }
    int result = 0;
    for (auto &itr : stops)
    {
        result += itr.second;
        if (result > capacity) return false;
    }
    return true;
}

/// <summary>
/// Leet code #1109. Corporate Flight Bookings
/// 
/// There are n flights, and they are labeled from 1 to n.
/// We have a list of flight bookings.  The i-th booking 
/// bookings[i] = [i, j, k] means that we booked k seats from flights 
/// labeled i to j inclusive.
///
/// Return an array answer of length n, representing the number of seats 
/// booked on each flight in order of their label.
///
/// Example 1:
///
/// Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
/// Output: [10,55,45,25,25]
///  
/// Constraints:
/// 1. 1 <= bookings.length <= 20000
/// 2. 1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
/// 3. 1 <= bookings[i][2] <= 10000
/// </summary>
vector<int> LeetCodeGreedy::corpFlightBookings(vector<vector<int>>& bookings, int n)
{
    vector<int> result(n);
    for (size_t i = 0; i < bookings.size(); i++)
    {
        result[bookings[i][0] - 1] += bookings[i][2];
        if (bookings[i][1] < n)
        {
            result[bookings[i][1]] -= bookings[i][2];
        }
    }
    for (size_t i = 0; i < result.size(); i++)
    {
        if (i > 0) result[i] += result[i - 1];
    }
    return result;
}

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
string LeetCodeGreedy::rearrangeString(string s, int k)
{
    vector<pair<int, int>> char_map(26, { 0, -1 });
    string result(s.size(), 0);

    for (char ch : s)
    {
        char_map[ch - 'a'].first++;
    }

    for (size_t i = 0; i < s.size(); i++)
    {
        pair<int, int> max_pos = make_pair(0, -1);
        for (int j = 0; j < 26; j++)
        {
            if (char_map[j].first > max_pos.first && char_map[j].second <= (int)i)
            {
                max_pos = make_pair(char_map[j].first, j);
            }
        }
        if (max_pos.second == -1) return "";
        result[i] = max_pos.second + 'a';
        char_map[max_pos.second].first--;
        char_map[max_pos.second].second = i + k;
    }
    return result;
}

/// <summary>
/// Leet code #9906. Arrange operations      
///
/// Assume we have N operations should be arrange in a certain time range. 
/// Each operation will use some resources, each resource is exclusive, 
/// which means one resource is used by a operation at any time it will
/// not be used by another operation in that time frame. If two operations
/// do not have any conflict resources, they can be done in parallel.
///
/// Please work out the shortest time we can complete all the operations
/// 
/// Notes
/// 1. The input is given as a list of array as O, in each O[i], the first 
///    element is the time how long the operation will complete, the remaining
///    k elements indidicate whether the operation will require a specific 
///    resource R[i-1], 0 means it does not require resource R[i-1], 
///    1 means it requires resource R[i-1].
/// 2. Each resource will be used during the whole period of the operation.
/// 3. To simplify the problem we assume we start as time 0 and time is an 
///    integer.
/// </summary>
/// <analysis>
/// This is a schedule problem which is similar to leetcode 358. The only       
/// difference is that we now have multiple resources, instead only one in 
/// leetcode 358.
/// We can do in the following steps.
/// 1. We accumulate total utilization for each resource, each resource will
///    have a available time, which is 0 and the total requested time.
/// 2. For any operation, the earliest time to start this operation is the 
///    maximum available time it utilized.
/// 3. We scan on all the unvisited operation, pick the earliest time to start.
///    if both operations start at the same time, we will pick the one utilized
///    the busiest resource.
/// 4. After we finally select an operation, we adjust the available time
///    and the request time for all the resources utilized in this operation.
/// 5. Repeat #3 and #4 until all the operations have been completed.
/// </analysis>
/// <followup>
/// If the requirement is to generate a job list, just output the last job
/// index by sequence.        
/// </followup>
int LeetCodeGreedy::arrangeOperations(vector<vector<int>> operations)
{
    int result = 0;
    vector<pair<int, int>> resources(operations[0].size() - 1, {0, 0});
    vector<int> visited(operations.size());
    
    // calculate resource usage
    for (size_t i = 0; i < operations.size(); i++)
    {
        for (size_t j = 1; j < operations[i].size(); j++)
        {
            if (operations[i][j] == 1)
            {
                // add to resource usage time
                resources[j - 1].second += operations[i][0];
            }
        }
    }

    // we do n iteration, every time we select a job
    for (size_t i = 0; i < operations.size(); i++)
    {
        int last_busiest = -1;
        int last_start = INT_MAX;
        int last_job = 0;
        // scan every job
        for (size_t j = 0; j < operations.size(); j++)
        {
            // we already completed this operation.
            if (visited[j] == 1) continue;
            int curr_busiest = 0;
            int curr_start = 0;

            for (size_t k = 1; k < operations[j].size(); k++)
            {
                // we do not use this resource;
                if (operations[j][k] == 0) continue;
                
                // calculate current start time
                curr_start = max(resources[k].first, curr_start);
                curr_busiest = max(curr_busiest, resources[k].second);
            }
            // current job start time is ealier, select it.
            if (curr_start < last_start) 
            {
                last_job = j;
                last_start = curr_start;
                last_busiest = curr_busiest;
            }
            // start time same
            else if ((curr_start == last_start) && (last_busiest < curr_busiest))
            {
                last_job = j;
                last_start = curr_start;
                last_busiest = curr_busiest;
            }
        }
        for (size_t j = 1; j < operations[last_job].size(); j++)
        {
            if (operations[last_job][j] == 1)
            {
                // adjust resource usage time
                resources[j - 1].first += operations[last_job][0];
                resources[j - 1].second -= operations[last_job][0];
            }
        }
        result = max(result, last_start + operations[last_job][0]);
    }
    return result;
}

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
vector<int> LeetCodeGreedy::minAvailableDuration(vector<vector<int>>& slots1,
    vector<vector<int>>& slots2, int duration)
{
    vector<int> result;
    int prev = -1;

    map<int, int> time_line;
    for (size_t i = 0; i < slots1.size(); i++)
    {
        time_line[slots1[i][0]]++;
        time_line[slots1[i][1]]--;
    }
    for (size_t i = 0; i < slots2.size(); i++)
    {
        time_line[slots2[i][0]]++;
        time_line[slots2[i][1]]--;
    }
    int count = 0;
    for (auto &itr : time_line)
    {
        count += itr.second;
        if (count == 2)
        {
            prev = itr.first;
        }
        else
        {
            if (prev != -1)
            {
                int time = itr.first - prev;
                if (time >= duration)
                {
                    result.push_back(prev);
                    result.push_back(prev + duration);
                    break;
                }
            }
            prev = -1;
        }
    }
    return result;
}

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
vector<vector<int>> LeetCodeGreedy::removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved)
{
    vector<vector<int>> result;

    for (size_t i = 0; i < intervals.size(); i++)
    {
        vector<int> interval = intervals[i];
        vector<vector<int>> temp;
        if (interval[0] < toBeRemoved[1] && interval[1] > toBeRemoved[0])
        {
            int first = min(interval[0], toBeRemoved[0]);
            int second = min(interval[1], toBeRemoved[0]);
            if (first != second)
            {
                temp.push_back({ first, second });
            }
            first = max(interval[0], toBeRemoved[1]);
            second = max(interval[1], toBeRemoved[1]);
            if (first != second)
            {
                temp.push_back({ first, second });
            }
        }
        else
        {
            temp.push_back(interval);
        }

        for (size_t j = 0; j < temp.size(); j++)
        {
            vector<int> tmp = temp[j];
            if (result.empty()) result.push_back(tmp);
            else
            {
                vector<int> back = result.back();
                back[1] = min(back[1], tmp[0]);
                result.pop_back();
                result.push_back(back);
                tmp[0] = max(tmp[0], back[1]);
                result.push_back(tmp);
            }
        }
    }
    return result;
}

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
int LeetCodeGreedy::removeCoveredIntervals(vector<vector<int>>& intervals)
{
    int result = 0;
    sort(intervals.begin(), intervals.end());
    vector<int> last;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (last.empty())
        {
            last = intervals[i];
            result++;
        }
        else if (intervals[i][0] == last[0] && intervals[i][1] >= last[1])
        {
            last = intervals[i];
        }
        else if (intervals[i][1] > last[1])
        {
            last = intervals[i];
            result++;
        }       
    }
    return result;
}

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
int LeetCodeGreedy::minTaps(int n, vector<int>& ranges)
{
    vector<pair<int, int>> schedule;
    for (int i = 0; i < (int)ranges.size(); i++)
    {
        int first = max(0, i - ranges[i]);
        int last = min(n, i + ranges[i]);
        schedule.push_back({ last, first });
    }
    sort(schedule.begin(), schedule.end());
    
    vector<pair<int, int>> dp;
    dp.push_back({ 0, 0 });
    for (size_t i = 0; i < schedule.size(); i++)
    {
        int first = schedule[i].second;
        int last = schedule[i].first;


        auto itr = lower_bound(dp.begin(), dp.end(), make_pair(first, 0));
        // not able to cover
        if (itr == dp.end()) continue;
        int k = itr->second + 1;
        // no benefit
        if (dp.rbegin()->first == last) continue;
        while (dp.rbegin()->second >= k)
        {
            dp.pop_back();
        }
        dp.push_back({ last, k });
    }
    if (!dp.empty() && dp.rbegin()->first == n)
    {
        return dp.rbegin()->second;
    }
    else
    {
        return -1;
    }
}

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
int LeetCodeGreedy::maxEvents(vector<vector<int>>& events)
{
    priority_queue<pair<int, int>> pq;
    for (size_t i = 0; i < events.size(); i++)
    {
        pq.push({ -events[i][0], -events[i][1] });
    }
    int start_day = 0;
    int result = 0;
    while (!pq.empty())
    {
        pair<int, int> e = pq.top();
        pq.pop();
        if (-e.first == start_day)
        {
            e.first--;
            if (e.first >= e.second) pq.push(e);
        }
        else
        {
            result++;
            start_day = -e.first;
        }
    }
    return result;
}

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
int LeetCodeGreedy::maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
{
    vector<pair<int, int>> workers;
    for (size_t i = 0; i < speed.size(); i++)
    {
        workers.push_back({ -efficiency[i], -speed[i] });
    }
    sort(workers.begin(), workers.end());
    long long result = 0;
    long long sum = 0;
    unsigned long long M = 1000000007;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (pq.size() >= (size_t)k)
        {
            if (workers[i].second > pq.top().first) continue;
            sum -= pq.top().first;
            pq.pop();
        }
        sum += workers[i].second;
        pq.push(make_pair(workers[i].second, workers[i].first));
        result = max(result, sum * workers[i].first);
    }
    return (int)(result % M);
}

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
string LeetCodeGreedy::longestDiverseString(int a, int b, int c)
{
    vector<int> char_count = { a, b, c };
    string result;
    bool dup = false;
    for (int i = 0; i < a + b + c; i++)
    {
        int index = -1;
        for (size_t j = 0; j < 3; j++)
        {
            if (char_count[j] == 0) continue;
            if ((index == -1) || (char_count[j] > char_count[index]))
            {
                if (result.empty() || (result.back() != 'a' + j) || (!dup))
                {
                    index = j;
                }
            }
        }
        if (index == -1) break;
        char ch = 'a' + index;
        if (!result.empty() && result.back() == ch) dup = true;
        else  dup = false;
        char_count[ch - 'a']--;
        result.push_back(ch);
    }
    return result;
}

/// <summary>
/// Leet code #1419. Minimum Number of Frogs Croaking
/// 
/// Medium
///
/// Given the string croakOfFrogs, which represents a combination of 
/// the string "croak" from different frogs, that is, multiple frogs 
/// can croak at the same time, so multiple "croak" are mixed. Return 
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
int LeetCodeGreedy::minNumberOfFrogs(string croakOfFrogs)
{
    vector<int> croak_count(5);
    unordered_map<char, int> croak_map;
    string str = "croak";
    for (size_t i = 0; i < str.size(); i++)
    {
        croak_map[str[i]] = i;
    }
    int frog_count = 0;
    int result = 0;
    for (size_t i = 0; i < croakOfFrogs.size(); i++)
    {
        int ord = croak_map[croakOfFrogs[i]];
        croak_count[ord]++;
        if (ord == 0)
        {
            frog_count++;
        }
        else if (croak_count[ord - 1] == 0)
        {
            return -1;
        }
        else
        {
            croak_count[ord - 1]--;
        }
        result = max(result, frog_count);
        if (ord == 4)
        {
            croak_count[ord]--;
            frog_count--;
        }
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (croak_count[i] != 0) return -1;
    }
    return result;
}

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
int LeetCodeGreedy::maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
    vector<int>& worker)
{
    map<int, int> tasks;
    for (size_t i = 0; i < difficulty.size(); i++)
    {
        tasks[difficulty[i]] = max(tasks[difficulty[i]], profit[i]);
    }
    sort(worker.begin(), worker.end());
    int result = 0;
    auto itr = tasks.begin();
    int max_profit = 0;
    for (size_t i = 0; i < worker.size(); i++)
    {
        while ((itr != tasks.end()) && (itr->first <= worker[i]))
        {
            max_profit = std::max(max_profit, itr->second);
            ++itr;
        }
        result += max_profit;
    }
    return result;
}

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
vector<string> LeetCodeGreedy::maxNumOfSubstrings(string s)
{
    vector<vector<int>> positions(26, vector<int>(2, -1));
    
    for (size_t i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (positions[k][0] == -1) positions[k][0] = i;
        positions[k][1] = i;
    }
    set<vector<int>> pq_char;
    for (size_t i = 0; i < positions.size(); i++)
    {
        if (positions[i][0] != -1) pq_char.insert(positions[i]);
    }
    set<vector<int>> pq_str;
    while (!pq_char.empty())
    {
        vector<int> char_range = *pq_char.begin();
        pq_char.erase(pq_char.begin());
        int l = char_range[0];
        int r = char_range[1];
        for (int i = l; i <= r; i++)
        {
            int k = s[i] - 'a';
            // already covered.
            if (positions[k][0] < l)
            {
                l = -1;
                r = -1;
                break;
            }
            else
            {
                r = max(r, positions[k][1]);
            }
        }
        if (l != -1)
        {
            pq_str.insert({ l, r });
        }
    }
    vector<string> result;
    vector<int> first = *pq_str.begin();
    pq_str.erase(pq_str.begin());
    while (!pq_str.empty())
    {
        vector<int> second = *pq_str.begin();
        pq_str.erase(pq_str.begin());
        if (first[1] < second[0])
        {
            result.push_back(s.substr(first[0], first[1] - first[0] + 1));
        }
        first = second;
    }
    result.push_back(s.substr(first[0], first[1] - first[0] + 1));
    return result;
}

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
int LeetCodeGreedy::findLatestStep(vector<int>& arr, int m)
{
    int n = arr.size();
    vector<int> length(n + 2);
    vector<int> count(n + 1);
    int result = -1;
    for (size_t i = 0; i < arr.size(); i++)
    {
        int index = arr[i];
        int left = index - length[index - 1];
        int right = index + length[index + 1];
        count[length[left]]--;
        count[length[right]]--;
        length[left] = right - left + 1;
        length[right] = right - left + 1;
        count[right - left + 1]++;
        if (count[m] > 0) result = i + 1;
    }
    return result;
}

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
/// 2. 1 <= n <= 10^5
/// 3. 0 <= nums[i] <= 10^5
/// 4. 1 <= requests.length <= 10^5
/// 5. requests[i].length == 2
/// 6. 0 <= start[i] <= end[i] < n
/// </summary>
int LeetCodeGreedy::maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests)
{
    int n = nums.size();
    vector<int> dp(n);
    priority_queue<pair<int, int>> positions;

    for (size_t i = 0; i < requests.size(); i++)
    {
        int start = requests[i][0];
        int end = requests[i][1];
        dp[start]++;
        if (end + 1 < n)
        {
            dp[end + 1] --;
        }
    }
    for (size_t i = 1; i < dp.size(); i++)
    {
        dp[i] = dp[i - 1] + dp[i];
        if (dp[i] != dp[i - 1] && dp[i] > 0)
        {
            positions.push(make_pair(dp[i], i));
        }
    }
    if (dp[0] != 0) positions.push(make_pair(dp[0], 0));

    sort(nums.begin(), nums.end());
    int M = 1000000007;
    int result = 0;
    int index = n - 1;
    while (!positions.empty())
    {
        pair<int, int> pos = positions.top();
        positions.pop();
        for (int i = pos.second; i < n; i++)
        {
            if (dp[i] == pos.first)
            {
                result = (result + nums[index] * pos.first) % M;
                index--;
            }
            else
            {
                break;
            }
        }
    }
    return result;
}

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
/// 2. 1 <= actual​[i] <= minimum[i] <= 10^4
/// </summary>
int LeetCodeGreedy::minimumEffort(vector<vector<int>>& tasks)
{
    priority_queue<pair<int, int>> task_pq;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        task_pq.push(make_pair(tasks[i][0] - tasks[i][1], i));
    }
    int result = 0;
    while (!task_pq.empty())
    {
        pair<int, int> task = task_pq.top();
        task_pq.pop();
        int point = 0 - task.first;

        if (point > result) result = tasks[task.second][1];
        else result = result + tasks[task.second][0];
    }
    return result;
}

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
/// - Go to building 2 using 5 bricks. You must use either bricks or 
///   ladders because 2 < 7.
/// - Go to building 3 without using ladders nor bricks since 7 >= 6.
/// - Go to building 4 using your only ladder. You must use either bricks or 
///   ladders because 6 < 9.
/// It is impossible to go beyond building 4 because you do not have any 
/// more bricks or ladders.
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
int LeetCodeGreedy::furthestBuilding(vector<int>& heights, int bricks, int ladders)
{
    priority_queue<int> pq;
    int result = 0;
    while (result < (int)heights.size() -1)
    {
        int next = result + 1;
        if (heights[next] <= heights[result])
        {
            result++;
        }
        else
        {
            int gap = heights[result] - heights[next];
            pq.push(gap);
            if ((int)pq.size() > ladders)
            {
                bricks += pq.top();
                pq.pop();
                if (bricks < 0) break;
            }
            result++;
        }
    }
    return result;
}

/// <summary>
/// Leet code #1674. Minimum Moves to Make Array Complementary
/// 
/// Medium
/// 
/// You are given an integer array nums of even length n and an integer 
/// limit. In one move, you can replace any integer from nums with another 
/// integer between 1 and limit, inclusive.
///
/// The array nums is complementary if for all indices i (0-indexed), 
/// nums[i] + nums[n - 1 - i] equals the same number. For example, the 
/// array [1,2,3,4] is complementary because for all indices i, nums[i] + 
/// nums[n - 1 - i] = 5.
///
/// Return the minimum number of moves required to make nums complementary.
///
/// Example 1:
/// Input: nums = [1,2,4,3], limit = 4
/// Output: 1
/// Explanation: In 1 move, you can change nums to [1,2,2,3] (underlined 
/// elements are changed).
/// nums[0] + nums[3] = 1 + 3 = 4.
/// nums[1] + nums[2] = 2 + 2 = 4.
/// nums[2] + nums[1] = 2 + 2 = 4.
/// nums[3] + nums[0] = 3 + 1 = 4.
/// Therefore, nums[i] + nums[n-1-i] = 4 for every i, so nums is complementary.
///
/// Example 2:
/// Input: nums = [1,2,2,1], limit = 2
/// Output: 2
/// Explanation: In 2 moves, you can change nums to [2,2,2,2]. You cannot 
/// change any number to 3 since 3 > limit.
///
/// Example 3:
/// Input: nums = [1,2,1,2], limit = 2
/// Output: 0
/// Explanation: nums is already complementary.
/// Constraints:
/// 1. n == nums.length
/// 2. 2 <= n <= 10^5
/// 3. 1 <= nums[i] <= limit <= 10^5
/// 4. n is even.
/// </summary>
int LeetCodeGreedy::minMoves(vector<int>& nums, int limit)
{
    int n = nums.size();
    map<int, int> sweep;

    for (int i = 0; i < n / 2; i++)
    {
        sweep[2] += 2;
        int min_val = min(nums[i], nums[n - i - 1]);
        int max_val = max(nums[i], nums[n - i - 1]);
        sweep[min_val + 1]--;
        sweep[min_val + max_val]--;
        sweep[min_val + max_val + 1]++;
        sweep[max_val + limit + 1]++;
    }
    int result = INT_MAX;
    int sum = 0;
    for (auto itr : sweep)
    {
        sum += itr.second;
        result = min(result, sum);
    }
    return result;
}

/// <summary>
/// Leet code 1792. Maximum Average Pass Ratio
/// 
/// Medium
/// 
/// There is a school that has classes of students and each class will 
/// be having a final exam. You are given a 2D integer array classes, 
/// where classes[i] = [passi, totali]. You know beforehand that in 
/// the ith class, there are totali total students, but only passi 
/// number of students will pass the exam.
///
/// You are also given an integer extraStudents. There are another 
/// extraStudents brilliant students that are guaranteed to pass the 
/// exam of any class they are assigned to. You want to assign each 
/// of the extraStudents students to a class in a way that maximizes 
/// the average pass ratio across all the classes.
///
/// The pass ratio of a class is equal to the number of students of 
/// the class that will pass the exam divided by the total number of 
/// students of the class. The average pass ratio is the sum of pass 
/// ratios of all the classes divided by the number of the classes.
///
/// Return the maximum possible average pass ratio after assigning 
/// the extraStudents students. Answers within 10-5 of the actual 
/// answer will be accepted.
/// 
/// Example 1:
/// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
/// Output: 0.78333
/// Explanation: You can assign the two extra students to the first class. 
/// The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 
/// 0.78333.
///
/// Example 2:
/// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
/// Output: 0.53485
///
/// Constraints:
/// 1. 1 <= classes.length <= 10^5
/// 2. classes[i].length == 2
/// 3. 1 <= passi <= totali <= 10^5
/// 4. 1 <= extraStudents <= 10^5
/// </summary>
double LeetCodeGreedy::maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
{
    priority_queue<pair<double, pair<double, double>>> heap;
    for (size_t i = 0; i < classes.size(); i++)
    {
        pair<double, pair<double, double>> score;
        score.second.first = classes[i][0];
        score.second.second = classes[i][1];
        score.first = (score.second.first + (double)1) / ((double)score.second.second + (double)1) -
            score.second.first / score.second.second;
        heap.push(score);
    }
    for (int i = 0; i < extraStudents; i++)
    {
        pair<double, pair<double, double>> score = heap.top();
        heap.pop();
        score.second.first++;
        score.second.second++;
        score.first = (score.second.first + (double)1) / (score.second.second + (double)1) -
            score.second.first / score.second.second;
        heap.push(score);
    }
    double sum = 0;
    double count = 0;
    while (!heap.empty())
    {
        pair<double, pair<double, double>> score = heap.top();
        heap.pop();
        sum += score.second.first / score.second.second;
        count++;
    }
    return sum / count;
}


/// <summary>
/// Leet code 1854. Maximum Population Year
/// 
/// Easy
/// 
/// You are given a 2D integer array logs where each logs[i] = 
/// [birthi, deathi] indicates the birth and death years of the ith person.
/// 
/// The population of some year x is the number of people alive during 
/// that year. The ith person is counted in year x's population if x is in 
/// the inclusive range [birthi, deathi - 1]. Note that the person is not 
/// counted in the year that they die.
///
/// Return the earliest year with the maximum population.
/// 
/// Example 1:
/// 
/// Input: logs = [[1993,1999],[2000,2010]]
/// Output: 1993
/// Explanation: The maximum population is 1, and 1993 is the earliest 
/// year with this population.
///
/// Example 2:
/// Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
/// Output: 1960
/// Explanation: 
/// The maximum population is 2, and it had happened in years 1960 and 
/// 1970.
/// The earlier year between them is 1960.
/// 
/// Constraints:
/// 1. 1 <= logs.length <= 100
/// 2. 1950 <= birthi < deathi <= 2050
/// </summary>
int LeetCodeGreedy::maximumPopulation(vector<vector<int>>& logs)
{
    vector<int> arr(102);
    for (size_t i = 0; i < logs.size(); i++)
    {
        arr[logs[i][0] - 1950]++;
        arr[logs[i][1] - 1950]--;
    }
    int max_population = 0;
    int result = 0;
    int population = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        population += arr[i];
        if (population > max_population)
        {
            max_population = population;
            result = i + 1950;
        }
    }
    return result;
}

/// <summary>
/// Leet code 1893. Check if All the Integers in a Range Are Covered
/// 
/// Easy
/// 
/// You are given a 2D integer array ranges and two integers left and 
/// right. Each ranges[i] = [starti, endi] represents an inclusive 
/// interval between starti and endi.
///
/// Return true if each integer in the inclusive range [left, right] 
/// is covered by at least one interval in ranges. Return false otherwise.
///
/// An integer x is covered by an interval ranges[i] = [starti, endi] 
/// if starti <= x <= endi.
///
/// 
/// Example 1:
///
/// Input: ranges = [[1,2],[3,4],[5,6]], left = 2, right = 5
/// Output: true
/// Explanation: Every integer between 2 and 5 is covered:
/// - 2 is covered by the first range.
/// - 3 and 4 are covered by the second range.
/// - 5 is covered by the third range.
///
/// Example 2:
/// Input: ranges = [[1,10],[10,20]], left = 21, right = 21
/// Output: false
/// Explanation: 21 is not covered by any range.
/// Constraints:
/// 1. 1 <= ranges.length <= 50
/// 2. 1 <= starti <= endi <= 50
/// 3. 1 <= left <= right <= 50
/// </summary>
bool LeetCodeGreedy::isCovered(vector<vector<int>>& ranges, int left, int right)
{
    map<int, int> sweep;
    for (size_t i = 0; i < ranges.size(); i++)
    {
        sweep[ranges[i][0]]++;
        sweep[ranges[i][1] + 1]--;
    }

    if (sweep.begin()->first > left || sweep.rbegin()->first < right)
    {
        return false;
    }

    int result = 0;
    for (auto itr : sweep)
    {
        result += itr.second;
        if (result == 0 && itr.first >= left && itr.first <= right)
        {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Leet 1943. Describe the Painting
///                                                                 
/// Medium
/// 
/// There is a long and thin painting that can be represented by a number 
/// line. The painting was painted with multiple overlapping segments 
/// where each segment was painted with a unique color. You are given a 2D 
/// integer array segments, where segments[i] = [starti, endi, colori] 
/// represents the half-closed segment [starti, endi) with colori as the 
/// color.
///
/// The colors in the overlapping segments of the painting were mixed when 
/// it was painted. When two or more colors mix, they form a new color 
/// that can be represented as a set of mixed colors.
///
/// For example, if colors 2, 4, and 6 are mixed, then the resulting mixed 
/// color is {2,4,6}.
/// For the sake of simplicity, you should only output the sum of the 
/// elements in the set rather than the full set.
///
/// You want to describe the painting with the minimum number of 
/// non-overlapping half-closed segments of these mixed colors. These 
/// segments can be represented by the 2D array painting where 
/// painting[j] = [leftj, rightj, mixj] describes a half-closed segment 
/// [leftj, rightj) with the mixed color sum of mixj.
///
/// For example, the painting created with segments = [[1,4,5],[1,7,7]] 
/// can be described by painting = [[1,4,12],[4,7,7]] because:
/// [1,4) is colored {5,7} (with a sum of 12) from both the first and 
/// second segments.
/// [4,7) is colored {7} from only the second segment.
/// Return the 2D array painting describing the finished painting 
/// (excluding any parts that are not painted). You may return the 
/// segments in any order.
///
/// A half-closed segment [a, b) is the section of the number line between 
/// points a and b including point a and not including point b.
/// 
/// Example 1:
/// Input: segments = [[1,4,5],[4,7,7],[1,7,9]]
/// Output: [[1,4,14],[4,7,16]]
/// Explanation: The painting can be described as follows:
/// - [1,4) is colored {5,9} (with a sum of 14) from the first and third 
///   segments.
/// - [4,7) is colored {7,9} (with a sum of 16) from the second and third 
///   segments.
///	
/// Example 2:
/// Input: segments = [[1,7,9],[6,8,15],[8,10,7]]
/// Output: [[1,6,9],[6,7,24],[7,8,15],[8,10,7]]
/// Explanation: The painting can be described as follows:
/// - [1,6) is colored 9 from the first segment.
/// - [6,7) is colored {9,15} (with a sum of 24) from the first and second 
///   segments.
/// - [7,8) is colored 15 from the second segment.
/// - [8,10) is colored 7 from the third segment.
///
/// Example 3:
/// Input: segments = [[1,4,5],[1,4,7],[4,7,1],[4,7,11]]
/// Output: [[1,4,12],[4,7,12]]
/// Explanation: The painting can be described as follows:
/// - [1,4) is colored {5,7} (with a sum of 12) from the first and second 
///   segments.
/// - [4,7) is colored {1,11} (with a sum of 12) from the third and fourth 
///   segments.
/// Note that returning a single segment [1,7) is incorrect because the 
/// mixed color sets are different.
/// 
/// Constraints:
/// 1. 1 <= segments.length <= 2 * 10^4
/// 2. segments[i].length == 3
/// 3. 1 <= starti < endi <= 10^5
/// 4. 1 <= colori <= 10^9
/// 5. Each colori is distinct.
/// </summary>
vector<vector<long long>> LeetCodeGreedy::splitPainting(vector<vector<int>>& segments)
{
    map<long long, long long> colors;
    for (size_t i = 0; i < segments.size(); i++)
    {
        colors[segments[i][0]] += segments[i][2];
        colors[segments[i][1]] -= segments[i][2];
    }

    vector<vector<long long>> result;
    vector<pair<long long, long long>> paints;
    for (auto itr = colors.begin(); itr != colors.end(); ++itr)
    {
        auto next_itr = next(itr);
        if (next_itr == colors.end()) break;
        next_itr->second += itr->second;
        if (itr->second == 0) continue;
        result.push_back({ itr->first, next_itr->first, itr->second });
    }
    return result;
}

/// <summary>
/// Leet Code 2071. Maximum Number of Tasks You Can Assign
///                                                                 
/// Hard
/// 
/// You have n tasks and m workers. Each task has a strength requirement 
/// stored in a 0-indexed integer array tasks, with the ith task requiring 
// tasks[i] strength to complete. The strength of each worker is stored in 
/// a 0-indexed integer array workers, with the jth worker having 
/// workers[j] strength. Each worker can only be assigned to a single task 
/// and must have a strength greater than or equal to the task's strength 
/// requirement (i.e., workers[j] >= tasks[i]).
/// Additionally, you have pills magical pills that will increase a 
/// worker's strength by strength. You can decide which workers receive 
/// the magical pills, however, you may only give each worker at most one 
/// magical pill.
///
/// Given the 0-indexed integer arrays tasks and workers and the integers 
/// pills and strength, return the maximum number of tasks that can be 
/// completed.
///
/// Example 1:
/// Input: tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
/// Output: 3
/// Explanation:
/// We can assign the magical pill and tasks as follows:
/// - Give the magical pill to worker 0.
/// - Assign worker 0 to task 2 (0 + 1 >= 1)
/// - Assign worker 1 to task 1 (3 >= 2)
/// - Assign worker 2 to task 0 (3 >= 3)
/// Example 2:
/// Input: tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
/// Output: 1
/// Explanation:
/// We can assign the magical pill and tasks as follows:
/// - Give the magical pill to worker 0.
/// - Assign worker 0 to task 0 (0 + 5 >= 5)
///
/// Example 3:
/// Input: tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, 
/// strength = 10
/// Output: 2
/// Explanation:
/// We can assign the magical pills and tasks as follows:
/// - Give the magical pill to worker 0 and worker 1.
/// - Assign worker 0 to task 0 (0 + 10 >= 10)
/// - Assign worker 1 to task 1 (10 + 10 >= 15)
///
/// Example 4:
/// Input: tasks = [5,9,8,5,9], workers = [1,6,4,2,6], pills = 1, 
/// strength = 5
/// Output: 3
/// Explanation:
/// We can assign the magical pill and tasks as follows:
/// - Give the magical pill to worker 2.
/// - Assign worker 1 to task 0 (6 >= 5)
/// - Assign worker 2 to task 2 (4 + 5 >= 8)
/// - Assign worker 4 to task 3 (6 >= 5)
/// 
/// Constraints:
/// 1. n == tasks.length
/// 2. m == workers.length
/// 3. 1 <= n, m <= 5 * 10^4
/// 4. 0 <= pills <= m
/// 5. 0 <= tasks[i], workers[j], strength <= 10^9
/// </summary>
int LeetCodeGreedy::maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
{
    int result = 0;
    int first = 0;
    int last = min(tasks.size() - 1, workers.size() - 1);
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    while (first <= last)
    {
        int curr_pills = pills;
        int middle = first + (last - first) / 2;
        bool b_complete = true;
        set<pair<int, int>> sorted_workers;
        for (int i = workers.size() - 1; i >= (int)workers.size() - middle - 1; i--)
        {
            sorted_workers.insert(make_pair(workers[i], i));
        }
        for (int i = middle; i >= 0; i--)
        {
            int task = tasks[i];
            auto itr = sorted_workers.lower_bound(make_pair(task, 0));
            if (itr != sorted_workers.end())
            {
                sorted_workers.erase(itr);
            }
            else if (curr_pills > 0)
            {
                itr = sorted_workers.lower_bound(make_pair(task - strength, 0));
                if (itr != sorted_workers.end())
                {
                    sorted_workers.erase(itr);
                    curr_pills--;
                }
                else
                {
                    b_complete = false;
                    break;
                }
            }
            else
            {
                b_complete = false;
                break;
            }
        }
        if (b_complete)
        {
            result = middle + 1;
            first = middle + 1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2021. Brightest Position on Street
///                                                                 
/// Medium
/// 
/// A perfectly straight street is represented by a number line. The 
/// street has street lamp(s) on it and is represented by a 2D integer 
/// array lights. Each lights[i] = [positioni, rangei] indicates that 
/// there is a street lamp at position positioni that lights up the 
/// area from [positioni - rangei, positioni + rangei] (inclusive).
///
/// The brightness of a position p is defined as the number of street 
/// lamp that light up the position p.
///
/// Given lights, return the brightest position on the street. If 
/// there are multiple brightest positions, return the smallest one.
///
/// Example 1:
/// Input: lights = [[-3,2],[1,2],[3,3]]
/// Output: -1
/// Explanation:
/// The first street lamp lights up the area from 
/// [(-3) - 2, (-3) + 2] = [-5, -1].
/// The second street lamp lights up the area from 
/// [1 - 2, 1 + 2] = [-1, 3].
/// The third street lamp lights up the area from 
/// [3 - 3, 3 + 3] = [0, 6].
///
/// Position -1 has a brightness of 2, illuminated by the first and second 
/// street light.
/// Positions 0, 1, 2, and 3 have a brightness of 2, illuminated by the 
/// second and third street light.
/// Out of all these positions, -1 is the smallest, so return it.
///
/// Example 2:
/// Input: lights = [[1,0],[0,1]]
/// Output: 1
/// Explanation:
/// The first street lamp lights up the area from [1 - 0, 1 + 0] = [1, 1].
/// The second street lamp lights up the area from 
/// [0 - 1, 0 + 1] = [-1, 1].
/// 
/// Position 1 has a brightness of 2, illuminated by the first and second 
/// street light.
/// Return 1 because it is the brightest position on the street.
///
/// Example 3:
/// Input: lights = [[1,2]]
/// Output: -1
/// Explanation:
/// The first street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].
///
/// Positions -1, 0, 1, 2, and 3 have a brightness of 1, illuminated by 
/// the first street light.
/// Out of all these positions, -1 is the smallest, so return it.
///
/// Constraints:
/// 1. 1 <= lights.length <= 10^5
/// 2. lights[i].length == 2
/// 3. -10^8 <= positioni <= 10^8
/// 4. 0 <= rangei <= 10^8
/// </summary>
int LeetCodeGreedy::brightestPosition(vector<vector<int>>& lights)
{
    map<int, int> street;
    for (size_t i = 0; i < lights.size(); i++)
    {
        int left = lights[i][0] - lights[i][1];
        int right = lights[i][0] + lights[i][1] + 1;
        street[left]++;
        street[right]--;
    }
    int result = street.begin()->first;
    int prev = street.begin()->second;
    int sum = 0;
    for (auto& itr : street)
    {
        sum += itr.second;
        if (sum > prev)
        {
            result = itr.first;
            prev = sum;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 1989. Maximum Number of People That Can Be Caught in Tag 
///                                                                 
/// Medium
///
/// You are playing a game of tag with your friends. In tag, people are 
/// divided into two teams: people who are "it", and people who are not 
/// "it". The people who are "it" want to catch as many people as 
/// possible who are not "it".
///
/// You are given a 0-indexed integer array team containing only zeros 
/// (denoting people who are not "it") and ones (denoting people who are 
/// "it"), and an integer dist. A person who is "it" at index i can catch 
/// any one person whose index is in the range [i - dist, i + dist] 
/// (inclusive) and is not "it".
///
/// Return the maximum number of people that the people who are "it" can 
/// catch.
///
/// Example 1:
/// Input: team = [0,1,0,1,0], dist = 3
/// Output: 2
/// Explanation:
/// The person who is "it" at index 1 can catch people in the range 
/// [i-dist, i+dist] = [1-3, 1+3] = [-2, 4].
/// They can catch the person who is not "it" at index 2.
/// The person who is "it" at index 3 can catch people in the range 
/// [i-dist, i+dist] = [3-3, 3+3] = [0, 6].
/// They can catch the person who is not "it" at index 0.
/// The person who is not "it" at index 4 will not be caught because the 
/// people at indices 1 and 3 are already catching one person.
///
/// Example 2:
/// Input: team = [1], dist = 1
/// Output: 0
/// Explanation:
/// There are no people who are not "it" to catch.
///
/// Example 3:
/// Input: team = [0], dist = 1
/// Output: 0
/// Explanation:
/// There are no people who are "it" to catch people.
/// 
/// Constraints:
/// 1. 1 <= team.length <= 10^5
/// 2. 0 <= team[i] <= 1
/// 3. 1 <= dist <= team.length
/// </summary>
int LeetCodeGreedy::catchMaximumAmountofPeople(vector<int>& team, int dist)
{
    int result = 0;
    vector<queue<int>> queue(2);
    for (int i = 0; i < (int)team.size(); i++)
    {
        while (!queue[1 - team[i]].empty() && i - queue[1 - team[i]].front() > dist)
        {
            queue[1 - team[i]].pop();
        }
        if (!queue[1 - team[i]].empty())
        {
            queue[1 - team[i]].pop();
            result++;
            continue;
        }
        else
        {
            queue[team[i]].push(i);
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2015. Average Height of Buildings in Each Segment
///                                                                 
/// Medium
///
/// A perfectly straight street is represented by a number line. The 
/// street has building(s) on it and is represented by a 2D integer 
/// array buildings, where buildings[i] = [starti, endi, heighti]. 
/// This means that there is a building with heighti in the 
/// half-closed segment [starti, endi).
///
/// You want to describe the heights of the buildings on the street with 
/// the minimum number of non-overlapping segments. The street can be 
/// represented by the 2D integer array street where street[j] = 
/// [leftj, rightj, averagej] describes a half-closed segment [leftj, 
/// rightj) of the road where the average heights of the buildings in 
/// the segment is averagej.
///
/// For example, if buildings = [[1,5,2],[3,10,4]], the street could be 
/// represented by street = [[1,3,2],[3,5,3],[5,10,4]] because:
/// From 1 to 3, there is only the first building with an average height 
/// of 2 / 1 = 2.
/// From 3 to 5, both the first and the second building are there with 
/// an average height of (2+4) / 2 = 3.
/// From 5 to 10, there is only the second building with an average 
/// height of 4 / 1 = 4.
/// Given buildings, return the 2D integer array street as described above 
/// (excluding any areas of the street where there are no buldings). You 
/// may return the array in any order.
///
/// The average of n elements is the sum of the n elements divided (integer 
/// division) by n.
///
/// A half-closed segment [a, b) is the section of the number line between 
/// points a and b including point a and not including point b.
///
/// Example 1:
/// Input: buildings = [[1,4,2],[3,9,4]]
/// Output: [[1,3,2],[3,4,3],[4,9,4]]
/// Explanation:
/// From 1 to 3, there is only the first building with an average height 
/// of 2 / 1 = 2.
/// From 3 to 4, both the first and the second building are there with an 
/// average height of (2+4) / 2 = 3.
/// From 4 to 9, there is only the second building with an average height 
/// of 4 / 1 = 4.
///
/// Example 2:
/// Input: buildings = [[1,3,2],[2,5,3],[2,8,3]]
/// Output: [[1,3,2],[3,8,3]]
/// Explanation:
/// From 1 to 2, there is only the first building with an average 
/// height of 2 / 1 = 2.
/// From 2 to 3, all three buildings are there with an average height of 
/// (2+3+3) / 3 = 2.
/// From 3 to 5, both the second and the third building are there with an 
/// average height of (3+3) / 2 = 3.
/// From 5 to 8, there is only the last building with an average height 
/// of 3 / 1 = 3.
/// The average height from 1 to 3 is the same so we can group them into 
/// one segment.
/// The average height from 3 to 8 is the same so we can group them into 
/// one segment.
///
/// Example 3:
/// Input: buildings = [[1,2,1],[5,6,1]]
/// Output: [[1,2,1],[5,6,1]]
/// Explanation:
/// From 1 to 2, there is only the first building with an average 
/// height of 1 / 1 = 1.
/// From 2 to 5, there are no buildings, so it is not included in the 
/// output.
/// From 5 to 6, there is only the second building with an average 
/// height of 1 / 1 = 1.
/// We cannot group the segments together because an empty space with 
/// no buildings seperates the segments.
///
/// Constraints:
/// 1. 1 <= buildings.length <= 10^5
/// 2. buildings[i].length == 3
/// 3. 0 <= starti < endi <= 10^8
/// 4. 1 <= heighti <= 10^5
/// </summary>
vector<vector<int>> LeetCodeGreedy::averageHeightOfBuildings(vector<vector<int>>& buildings)
{
    map<int, pair<int, int>> building_map;
    for (size_t i = 0; i < buildings.size(); i++)
    {
        building_map[buildings[i][0]].first += buildings[i][2];
        building_map[buildings[i][0]].second++;
        building_map[buildings[i][1]].first -= buildings[i][2];
        building_map[buildings[i][1]].second--;
    }
    int prev_height = 0;
    int sum = 0;
    int count = 0;
    vector<vector<int>> result;
    for (auto itr : building_map)
    {
        sum += itr.second.first;
        count += itr.second.second;
        int height = 0; 
        if (count > 0) height = sum / count;
        if (result.empty() || prev_height == 0)
        {
            result.push_back({ itr.first, -1, height });
        }
        else if (height == 0)
        {
            result.back()[1] = itr.first;
        }
        else if (height != prev_height)
        {
            result.back()[1] = itr.first;
            result.push_back({ itr.first, -1, height });
        }
        prev_height = height;
    }
    return result;
}

/// <summary>
/// Leet Code 2158. Amount of New Area Painted Each Day
///                                                                 
/// Hard
///
/// There is a long and thin painting that can be represented by a number 
/// line. You are given a 0-indexed 2D integer array paint of length n, 
/// where paint[i] = [starti, endi]. This means that on the ith day you 
/// need to paint the area between starti and endi.
///
/// Painting the same area multiple times will create an uneven painting 
/// so you only want to paint each area of the painting at most once.
///
/// Return an integer array worklog of length n, where worklog[i] is the 
/// amount of new area that you painted on the ith day.
/// 
/// Example 1:
/// Input: paint = [[1,4],[4,7],[5,8]]
/// Output: [3,3,1]
/// Explanation:
/// On day 0, paint everything between 1 and 4.
/// The amount of new area painted on day 0 is 4 - 1 = 3.
/// On day 1, paint everything between 4 and 7.
/// The amount of new area painted on day 1 is 7 - 4 = 3.
/// On day 2, paint everything between 7 and 8.
/// Everything between 5 and 7 was already painted on day 1.
/// The amount of new area painted on day 2 is 8 - 7 = 1. 
///
/// Example 2:
/// Input: paint = [[1,4],[5,8],[4,7]]
/// Output: [3,3,1]
/// Explanation:
/// On day 0, paint everything between 1 and 4.
/// The amount of new area painted on day 0 is 4 - 1 = 3.
/// On day 1, paint everything between 5 and 8.
/// The amount of new area painted on day 1 is 8 - 5 = 3.
/// On day 2, paint everything between 4 and 5.
/// Everything between 5 and 7 was already painted on day 1.
/// The amount of new area painted on day 2 is 5 - 4 = 1. 
///
/// Example 3:
/// Input: paint = [[1,5],[2,4]]
/// Output: [4,0]
/// Explanation:
/// On day 0, paint everything between 1 and 5.
/// The amount of new area painted on day 0 is 5 - 1 = 4.
/// On day 1, paint nothing because everything between 2 and 4 was already 
/// painted on day 0.
/// The amount of new area painted on day 1 is 0.
/// 
/// Constraints:
/// 1. 1 <= paint.length <= 10^5
/// 2. paint[i].length == 2
/// 3. 0 <= starti < endi <= 5 * 10^4
/// </summary>
vector<int> LeetCodeGreedy::amountPainted(vector<vector<int>>& paint)
{
    map<int, int> painted;
    painted[INT_MAX] = 0;
    vector<int> result(paint.size());
    for (size_t i = 0; i < paint.size(); i++)
    {
        int length = 0;
        int prev = paint[i][0];
        auto itr = painted.lower_bound(paint[i][0]);
        int start = itr->second;
        while (itr->first <= paint[i][1])
        {
            if (itr->second == 0)
            {
                length += itr->first - prev;
            }
            prev = itr->first;
            auto next_itr = next(itr);
            painted.erase(itr);
            itr = next_itr;
        }
        if (itr->second == 0)
        {
            length += paint[i][1] - prev;
            painted[paint[i][1]] = 1;
        }
        if (start == 0)
        {
            painted[paint[i][0]] = 0;
        }
        result[i] = length;
    }
    return result;
}

/// <summary>
/// Leet Code 2182. Construct String With Repeat Limit
///                                                                                  
/// Medium
///
/// You are given a string s and an integer repeatLimit. Construct a new 
/// string repeatLimitedString using the characters of s such that no 
/// letter appears more than repeatLimit times in a row. You do not have 
/// to use all characters from s.
///
/// Return the lexicographically largest repeatLimitedString possible.
///
/// A string a is lexicographically larger than a string b if in the first 
/// position where a and b differ, string a has a letter that appears 
/// later in the alphabet than the corresponding letter in b. If the first 
/// min(a.length, b.length) characters do not differ, then the longer 
/// string is the lexicographically larger one.
///
/// Example 1:
/// Input: s = "cczazcc", repeatLimit = 3
/// Output: "zzcccac"
/// Explanation: We use all of the characters from s to construct the 
/// repeatLimitedString "zzcccac".
/// The letter 'a' appears at most 1 time in a row.
/// The letter 'c' appears at most 3 times in a row.
/// The letter 'z' appears at most 2 times in a row.
/// Hence, no letter appears more than repeatLimit times in a row and 
/// the string is a valid repeatLimitedString.
/// The string is the lexicographically largest repeatLimitedString 
/// possible so we return "zzcccac".
/// Note that the string "zzcccca" is lexicographically larger but 
/// the letter 'c' appears more than 3 times in a row, so it is not a 
/// valid repeatLimitedString.
///
/// Example 2:
/// Input: s = "aababab", repeatLimit = 2
/// Output: "bbabaa"
/// Explanation: We use only some of the characters from s to construct 
/// the repeatLimitedString "bbabaa". 
/// The letter 'a' appears at most 2 times in a row.
/// The letter 'b' appears at most 2 times in a row.
/// Hence, no letter appears more than repeatLimit times in a row and the 
/// string is a valid repeatLimitedString.
/// The string is the lexicographically largest repeatLimitedString 
/// possible so we return "bbabaa".
/// Note that the string "bbabaaa" is lexicographically larger but the 
/// letter 'a' appears more than 2 times in a row, so it is not a valid 
/// repeatLimitedString.
///
/// Constraints:
/// 1. 1 <= repeatLimit <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// </summary>
string LeetCodeGreedy::repeatLimitedString(string s, int repeatLimit)
{
    vector<int> char_count(26);
    for (char ch : s) char_count[ch - 'a']++;
    string result;
    int count = 0;
    int prev = -1;
    for (size_t i = 0; i < s.size(); i++)
    {
        bool b_found = false;
        for (int i = 25; i >= 0; i--)
        {
            if ((char_count[i] == 0) || (prev == i && count == repeatLimit))
            {
                continue;
            }
            else
            {
                char_count[i]--;
                result.push_back('a' + i);
                b_found = true;
                if (prev == i) count++;
                else count = 1;
                prev = i;
                break;
            }
        }
        if (b_found == false) break;
    }
    return result;
}

/// <summary>
/// Leet Code 2213. Longest Substring of One Repeating Character
///                                                                                   
/// Hard
///
/// You are given a 0-indexed string s. You are also given a 0-indexed 
/// string queryCharacters of length k and a 0-indexed array of integer 
/// indices queryIndices of length k, both of which are used to describe 
/// k queries.
///
/// The ith query updates the character in s at index queryIndices[i] to 
/// the character queryCharacters[i].
///
/// Return an array lengths of length k where lengths[i] is the length 
/// of the longest substring of s consisting of only one repeating 
/// character after the ith query is performed.
///
/// Example 1:
/// Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
/// Output: [3,3,4]
/// Explanation: 
/// - 1st query updates s = "bbbacc". The longest substring consisting of 
/// one repeating character is "bbb" with length 3.
/// - 2nd query updates s = "bbbccc". 
///  The longest substring consisting of one repeating character can be 
/// "bbb" or "ccc" with length 3.
/// - 3rd query updates s = "bbbbcc". The longest substring consisting of 
/// one repeating character is "bbbb" with length 4.
/// Thus, we return [3,3,4].
///
/// Example 2:
/// Input: s = "abyzz", queryCharacters = "aa", queryIndices = [2,1]
/// Output: [2,3]
/// Explanation:
/// - 1st query updates s = "abazz". The longest substring consisting of 
/// one repeating character is "zz" with length 2.
/// - 2nd query updates s = "aaazz". The longest substring consisting of 
/// one repeating character is "aaa" with length 3.
/// Thus, we return [2,3].
///
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s consists of lowercase English letters.
/// 3. k == queryCharacters.length == queryIndices.length
/// 4. 1 <= k <= 105
/// 5. queryCharacters consists of lowercase English letters.
/// 6. 0 <= queryIndices[i] < s.length
/// </summary>
vector<int> LeetCodeGreedy::longestRepeating(string s, string queryCharacters, vector<int>& queryIndices)
{
    set<int> points;
    set<pair<int, int>> segments;

    points.insert(0);
    int last = 0;
    for (int i = 1; i <= (int)s.size(); i++)
    {
        if (i == s.size() || s[i] != s[i - 1])
        {
            points.insert(i);
            segments.insert(make_pair(i - last, last));
            last = i;
        }
    }
    string str = s;
    vector<int> result(queryIndices.size());
    for (size_t i = 0; i < queryIndices.size(); i++)
    {
        int curr = queryIndices[i];
        str[curr] = queryCharacters[i];
        auto pos = points.lower_bound(curr);
        auto prev = pos;
        auto next = pos;
        if (*pos == queryIndices[i])
        {
            next = std::next(next);
        }
        else
        {
            prev = std::prev(prev);
        }
        segments.erase(make_pair(*next - *prev, *prev));
        points.insert(curr);
        if (curr != *prev)
        {
            segments.insert(make_pair(curr - *prev, *prev));
        }
        points.insert(curr+1);
        segments.insert(make_pair(1, curr));
        if (*next != curr + 1)
        {
            segments.insert(make_pair(*next - (curr + 1), curr + 1));
        }
        
        curr = queryIndices[i];
        pos = points.lower_bound(curr);
        prev = pos;
        if (curr != 0) prev = std::prev(pos);
        else pos = std::next(pos);
        if (*next != str.size()) next = std::next(next);
        int index = *prev;
        while (*pos < *next)
        {
            if (str[*prev] == str[*pos])
            {
                segments.erase(make_pair(*pos - index, index));
                index = *pos;
                auto temp = pos;
                pos = std::next(pos);
                points.erase(temp);
            }
            else
            {
                segments.erase(make_pair(*pos - index, index));
                segments.insert(make_pair(*pos - *prev, *prev));
                index = *pos;
                prev = pos;
                pos = std::next(pos);
            }
        }
        segments.erase(make_pair(*pos - index, index));
        segments.insert(make_pair(*next - *prev, *prev));
        result[i] = segments.rbegin()->first;
    }
    return result;
}

/// <summary>
/// Leet Code 2237. Count Positions on Street With Required Brightness
///                                                                                      
/// Medium
/// 
/// You are given an integer n. A perfectly straight street is represented 
/// by a number line ranging from 0 to n - 1. You are given a 2D integer 
/// array lights representing the street lamp(s) on the street. Each 
/// lights[i] = [positioni, rangei] indicates that there is a street lamp 
/// at position positioni that lights up the area from 
/// [max(0, positioni - rangei), min(n - 1, positioni + rangei)] 
/// (inclusive).
///
/// The brightness of a position p is defined as the number of street 
/// lamps that light up the position p. You are given a 0-indexed integer 
/// array requirement of size n where requirement[i] is the minimum 
/// brightness of the ith position on the street.
///
/// Return the number of positions i on the street between 0 and n - 1 
/// that have a brightness of at least requirement[i].
///
/// Example 1:
/// Input: n = 5, lights = [[0,1],[2,1],[3,2]], requirement = [0,2,1,4,1]
/// Output: 4
/// Explanation:
/// - The first street lamp lights up the area from [max(0, 0 - 1), 
///   min(n - 1, 0 + 1)] = [0, 1] (inclusive).
/// - The second street lamp lights up the area from [max(0, 2 - 1), 
///   min(n - 1, 2 + 1)] = [1, 3] (inclusive).
/// - The third street lamp lights up the area from [max(0, 3 - 2), 
///   min(n - 1, 3 + 2)] = [1, 4] (inclusive).
/// 
/// - Position 0 is covered by the first street lamp. It is covered by 1 
///   street lamp which is greater than requirement[0].
/// - Position 1 is covered by the first, second, and third street lamps. 
///   It is covered by 3 street lamps which is greater than requirement[1].
/// - Position 2 is covered by the second and third street lamps. It is 
///   covered by 2 street lamps which is greater than requirement[2].
/// - Position 3 is covered by the second and third street lamps. It is 
///   covered by 2 street lamps which is less than requirement[3].
/// - Position 4 is covered by the third street lamp. It is covered by 1 
///   street lamp which is equal to requirement[4].
///
/// Positions 0, 1, 2, and 4 meet the requirement so we return 4.
///
/// Example 2:
/// Input: n = 1, lights = [[0,1]], requirement = [2]
/// Output: 0
/// Explanation:
/// - The first street lamp lights up the area from [max(0, 0 - 1), 
///   min(n - 1, 0 + 1)] = [0, 0] (inclusive).
/// - Position 0 is covered by the first street lamp. It is covered by 1 
///   street lamp which is less than requirement[0].
/// - We return 0 because no position meets their brightness requirement.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= lights.length <= 10^5
/// 3. 0 <= positioni < n
/// 4. 0 <= rangei <= 10^5
/// 5. requirement.length == n
/// 6. 0 <= requirement[i] <= 10^5
/// </summary>
int LeetCodeGreedy::meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement)
{
    vector<int> dp(n);
    for (size_t i = 0; i < lights.size(); i++)
    {
        int start = max(0, lights[i][0] - lights[i][1]);
        int end = lights[i][0] + lights[i][1] + 1;
        dp[start]++;
        if (end < n) dp[end]--;
    }
    int result = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dp[i];
        if (sum >= requirement[i]) result++;
    }
    return result;
}

/// <summary>
/// Leet Code 2234. Maximum Total Beauty of the Gardens
///                                                                                      
/// Hard
/// 
/// Alice is a caretaker of n gardens and she wants to plant flowers to 
/// maximize the total beauty of all her gardens.
///
/// You are given a 0-indexed integer array flowers of size n, where 
/// flowers[i] is the number of flowers already planted in the ith garden. 
/// Flowers that are already planted cannot be removed. You are then given 
/// another integer newFlowers, which is the maximum number of flowers 
/// that Alice can additionally plant. You are also given the integers 
/// target, full, and partial.
/// A garden is considered complete if it has at least target flowers. 
/// The total beauty of the gardens is then determined as the sum of 
/// the following:
///
/// The number of complete gardens multiplied by full.
/// The minimum number of flowers in any of the incomplete gardens 
/// multiplied by partial. If there are no incomplete gardens, then 
/// this value will be 0.
/// Return the maximum total beauty that Alice can obtain after 
/// planting at most newFlowers flowers.
///
/// Example 1:
/// Input: flowers = [1,3,1,1], newFlowers = 7, target = 6, 
/// full = 12, partial = 1
/// Output: 14
/// Explanation: Alice can plant
/// - 2 flowers in the 0th garden
/// - 3 flowers in the 1st garden
/// - 1 flower in the 2nd garden
/// - 1 flower in the 3rd garden
/// The gardens will then be [3,6,2,2]. She planted a total of 
/// 2 + 3 + 1 + 1 = 7 flowers.
/// There is 1 garden that is complete.
/// The minimum number of flowers in the incomplete gardens is 2.
/// Thus, the total beauty is 1 * 12 + 2 * 1 = 12 + 2 = 14.
/// No other way of planting flowers can obtain a total beauty higher 
/// than 14.
///
/// Example 2:
/// Input: flowers = [2,4,5,3], newFlowers = 10, target = 5, 
/// full = 2, partial = 6
/// Output: 30
/// Explanation: Alice can plant
/// - 3 flowers in the 0th garden
/// - 0 flowers in the 1st garden
/// - 0 flowers in the 2nd garden
/// - 2 flowers in the 3rd garden
/// The gardens will then be [5,4,5,5]. She planted a total of 
/// 3 + 0 + 0 + 2 = 5 flowers.
/// There are 3 gardens that are complete.
/// The minimum number of flowers in the incomplete gardens is 4.
/// Thus, the total beauty is 3 * 2 + 4 * 6 = 6 + 24 = 30.
/// No other way of planting flowers can obtain a total beauty higher 
/// than 30.
/// Note that Alice could make all the gardens complete but in this case, 
/// she would obtain a lower total beauty.
///
/// Constraints:
/// 1. 1 <= flowers.length <= 10^5
/// 2. 1 <= flowers[i], target <= 10^5
/// 3. 1 <= newFlowers <= 10^10
/// 4. 1 <= full, partial <= 10^5
/// </summary>
long long LeetCodeGreedy::maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial)
{
    sort(flowers.begin(), flowers.end());
    long long last = flowers.size();
    long long result = 0;
    vector <long long> sum(flowers.size());
    for (int i = flowers.size() - 1; i >= 0; i--)
    {
        if (flowers[i] >= target)
        {
            last = i;
        }
        else
        {
            break;
        }
    }
    for (size_t i = 1; i < flowers.size(); i++)
    {
        sum[i] = sum[i - 1];
        if (flowers[i - 1] < target)
        {
            sum[i] = sum[i - 1] + ((long long)flowers[i] - (long long)flowers[i - 1]) * i;
        }
    }
    while (last >= 0)
    {
        long long low = 0;
        if (last > 0)
        {
            int fill = lower_bound(sum.begin(), sum.end(), newFlowers) - sum.begin() - 1;
            fill = min(fill, (int)(last - 1));
            long long remainingFlowers = newFlowers - sum[fill];
            low = (long long)flowers[fill] + remainingFlowers / ((long long)fill + 1);
            low = min((long long)target - 1, low);
        }
        result = max(result, low * (long long)partial + ((long long)flowers.size() - last) * (long long)full);
        last--;
        if (last >= 0)
        {
            newFlowers -= (long long)target - (long long)flowers[(int)last];
        }
        if (newFlowers < 0) break;
    }
    return result;
}

/// <summary>
/// Leet Code 2274. Maximum Consecutive Floors Without Special Floors
///                                                           
/// Medium
/// 
/// Alice manages a company and has rented some floors of a building as 
/// office space. Alice has decided some of these floors should be special 
/// floors, used for relaxation only.
///
/// You are given two integers bottom and top, which denote that Alice has 
/// rented all the floors from bottom to top (inclusive). You are also 
/// given the integer array special, where special[i] denotes a special 
/// floor that Alice has designated for relaxation.
///
/// Return the maximum number of consecutive floors without a special 
/// floor.
/// 
/// Example 1:
/// Input: bottom = 2, top = 9, special = [4,6]
/// Output: 3
/// Explanation: The following are the ranges (inclusive) of consecutive 
/// floors without a special floor:
/// - (2, 3) with a total amount of 2 floors.
/// - (5, 5) with a total amount of 1 floor.
/// - (7, 9) with a total amount of 3 floors.
/// Therefore, we return the maximum number which is 3 floors.
///
/// Example 2:
/// Input: bottom = 6, top = 8, special = [7,6,8]
/// Output: 0
/// Explanation: Every floor rented is a special floor, so we return 0.
///
/// Constraints:
/// 1. 1 <= special.length <= 10^5
/// 2. 1 <= bottom <= special[i] <= top <= 10^9
/// 3. All the values of special are unique.
/// </summary>
int LeetCodeGreedy::maxConsecutive(int bottom, int top, vector<int>& special)
{
    sort(special.begin(), special.end());
    int result = 0;
    int left = bottom;
    for (size_t i = 0; i < special.size(); i++)
    {
        result = max(result, special[i] - left);
        left = special[i] + 1;
    }
    result = max(result, top - special.back());
    return result;
}

/// <summary>
/// Leet Code 2251. Number of Flowers in Full Bloom
///                                                           
/// Hard
/// 
/// You are given a 0-indexed 2D integer array flowers, where flowers[i] 
/// = [starti, endi] means the ith flower will be in full bloom from 
/// starti to endi (inclusive). You are also given a 0-indexed integer 
/// array persons of size n, where persons[i] is the time that the ith 
/// person will arrive to see the flowers.
///
/// Return an integer array answer of size n, where answer[i] is the 
/// number of flowers that are in full bloom when the ith person arrives.
///
/// Example 1:
/// Input: flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
/// Output: [1,2,2,2]
/// Explanation: The figure above shows the times when the flowers are 
/// in full bloom and when the people arrive.
/// For each person, we return the number of flowers in full bloom 
/// during their arrival.
///
/// Example 2:
/// Input: flowers = [[1,10],[3,3]], persons = [3,3,2]
/// Output: [2,2,1]
/// Explanation: The figure above shows the times when the flowers are 
/// in full bloom and when the people arrive.
/// For each person, we return the number of flowers in full bloom during 
/// their arrival.
///
/// Constraints:
/// 1. 1 <= flowers.length <= 5 * 10^4
/// 2. flowers[i].length == 2
/// 3. 1 <= starti <= endi <= 10^9
/// 4. 1 <= persons.length <= 5 * 10^4
/// 5. 1 <= persons[i] <= 10^9
/// </summary>
vector<int> LeetCodeGreedy::fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons)
{
    map<int, int> bloom_days;
    unordered_map<int, int> person_days;
    for (size_t i = 0; i < flowers.size(); i++)
    {
        bloom_days[flowers[i][0]] ++;
        bloom_days[flowers[i][1] + 1] --;
    }
    for (size_t i = 0; i < persons.size(); i++)
    {
        bloom_days[persons[i]] += 0;
        person_days[persons[i]] = 0;
    }
    int count = 0;
    for (auto itr : bloom_days)
    {
        count += itr.second;
        if (person_days.count(itr.first) > 0)
        {
            person_days[itr.first] = count;
        }
    }
    vector<int> result(persons.size());
    for (size_t i = 0; i < persons.size(); i++)
    {
        result[i] = person_days[persons[i]];
    }
    return result;
}

/// <summary>
/// Leet Code 2271. Maximum White Tiles Covered by a Carpet
///                                                           
/// Medium
/// 
/// You are given a 2D integer array tiles where tiles[i] = [li, ri] 
/// represents that every tile j in the range li <= j <= ri is colored 
/// white.
/// 
/// You are also given an integer carpetLen, the length of a single carpet 
/// that can be placed anywhere.
/// 
/// Return the maximum number of white tiles that can be covered by the 
/// carpet.
///
/// Example 1:
/// Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
/// Output: 9
/// Explanation: Place the carpet starting on tile 10. 
/// It covers 9 white tiles, so we return 9.
/// Note that there may be other places where the carpet covers 9 white 
/// tiles.
/// It can be shown that the carpet cannot cover more than 9 white tiles.
///
/// Example 2:
/// Input: tiles = [[10,11],[1,1]], carpetLen = 2
/// Output: 2
/// Explanation: Place the carpet starting on tile 10. 
/// It covers 2 white tiles, so we return 2.
/// 
/// Constraints:
/// 1. 1 <= tiles.length <= 5 * 10^4
/// 2. tiles[i].length == 2
/// 3. 1 <= li <= ri <= 10^9
/// 4. 1 <= carpetLen <= 10^9
/// 5. The tiles are non-overlapping.
/// </summary>
int LeetCodeGreedy::maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen)
{
    sort(tiles.begin(), tiles.end());
    int result = 0, length = 0;

    deque<vector<int>> deque;
    for (size_t i = 0; i < tiles.size(); i++)
    {
        deque.push_back(tiles[i]);
        length += tiles[i][1] - tiles[i][0] + 1;
        int left = tiles[i][1] - carpetLen + 1;
        while (deque.front()[0] < left)
        {
            vector<int> tile = deque.front();
            deque.pop_front();
            if (tile[1] < left)
            {
                length -= (tile[1] - tile[0] + 1);
            }
            else
            {
                length -= left - tile[0];
                tile[0] = left;
                deque.push_front(tile);
            }
        }
        result = max(result, length);
    }
    return result;
}

/// <summary>
/// Leet Code 2381. Shifting Letters II
///                                                           
/// Medium
///
/// You are given a string s of lowercase English letters and a 2D 
/// integer array shifts where shifts[i] = [starti, endi, directioni]. 
/// For every i, shift the characters in s from the index starti to 
/// the index endi (inclusive) forward if directioni = 1, or shift 
/// the characters backward if directioni = 0.
///
/// Shifting a character forward means replacing it with the next 
/// letter in the alphabet (wrapping around so that 'z' becomes 'a'). 
/// Similarly, shifting a character backward means replacing it with 
/// the previous letter in the alphabet (wrapping around so that 'a' 
/// becomes 'z').
///
/// Return the final string after all such shifts to s are applied.
/// 
/// Example 1:
/// Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
/// Output: "ace"
/// Explanation: Firstly, shift the characters from index 0 to index 1 
/// backward. Now s = "zac".
/// Secondly, shift the characters from index 1 to index 2 forward. 
/// Now s = "zbd".
/// Finally, shift the characters from index 0 to index 2 forward. 
/// Now s = "ace".
///
/// Example 2:
/// Input: s = "dztz", shifts = [[0,0,0],[1,1,1]]
/// Output: "catz"
/// Explanation: Firstly, shift the characters from index 0 to 
/// index 0 backward. Now s = "cztz".
/// Finally, shift the characters from index 1 to index 1 forward. 
/// Now s = "catz".
/// Constraints:
///
/// 1. 1 <= s.length, shifts.length <= 5 * 10^4
/// 2. shifts[i].length == 3
/// 3. 0 <= starti <= endi < s.length
/// 4. 0 <= directioni <= 1
/// 5. s consists of lowercase English letters.
/// </summary>
string LeetCodeGreedy::shiftingLetters(string s, vector<vector<int>>& shifts)
{
    vector<int> dp(s.size());
    for (size_t i = 0; i < shifts.size(); i++)
    {
        int start = shifts[i][0];
        int end = shifts[i][1] + 1;
        int delta = shifts[i][2] == 1 ? 1 : -1;
        dp[start] += delta;
        if (end < (int)s.size())
        {
            dp[end] -= delta;
        }
    }

    string result = s;
    int delta = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        delta = (delta + dp[i]) % 26;
        char ch = s[i] - 'a';
        ch = (ch + delta + 26) % 26 + 'a';
        result[i] = ch;
    }
    return result;
}

/// <summary>
/// Leet Code 2365. Task Scheduler II
///                                                  
/// Medium
///
/// You are given a 0-indexed array of positive integers tasks, 
/// representing tasks that need to be completed in order, where 
/// tasks[i] represents the type of the ith task.
///
/// You are also given a positive integer space, which represents 
/// the minimum number of days that must pass after the completion 
/// of a task before another task of the same type can be performed.
///
/// Each day, until all tasks have been completed, you must either:
///
/// Complete the next task from tasks, or
/// Take a break.
/// Return the minimum number of days needed to complete all tasks.
///
/// Example 1:
/// Input: tasks = [1,2,1,2,3,1], space = 3
/// Output: 9
/// Explanation:
/// One way to complete all tasks in 9 days is as follows:
/// Day 1: Complete the 0th task.
/// Day 2: Complete the 1st task.
/// Day 3: Take a break.
/// Day 4: Take a break.
/// Day 5: Complete the 2nd task.
/// Day 6: Complete the 3rd task.
/// Day 7: Take a break.
/// Day 8: Complete the 4th task.
/// Day 9: Complete the 5th task.
/// It can be shown that the tasks cannot be completed in less 
/// than 9 days.
///
/// Example 2:
/// Input: tasks = [5,8,8,5], space = 2
/// Output: 6
/// Explanation:
/// One way to complete all tasks in 6 days is as follows:
/// Day 1: Complete the 0th task.
/// Day 2: Complete the 1st task.
/// Day 3: Take a break.
/// Day 4: Take a break.
/// Day 5: Complete the 2nd task.
/// Day 6: Complete the 3rd task.
/// It can be shown that the tasks cannot be completed in less than 6 
/// days.
/// 
/// Constraints:
/// 1. 1 <= tasks.length <= 10^5
/// 2. 1 <= tasks[i] <= 10^9
/// 3. 1 <= space <= tasks.length
/// </summary>
long long LeetCodeGreedy::taskSchedulerII(vector<int>& tasks, int space)
{
    long long break_days = 0;
    unordered_map<int, long long> task_date;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        int t = tasks[i];
        if (task_date.count(t) != 0 && 
            ((long long)i + break_days) - (long long)space - 1 < task_date[t])
        {
            break_days = task_date[t] + (long long)space - (long long)i + 1;
        }
        task_date[t] = (long long)i + break_days;
    }
    return (long long)tasks.size() + break_days;
}


/// <summary>
/// Leet Code 2382. Maximum Segment Sum After Removals
///                                                  
/// Hard
///
/// You are given two 0-indexed integer arrays nums and removeQueries, 
/// both of length n. For the ith query, the element in nums at the 
/// index removeQueries[i] is removed, splitting nums into different 
/// segments.
///
/// A segment is a contiguous sequence of positive integers in nums. 
/// A segment sum is the sum of every element in a segment.
///
/// Return an integer array answer, of length n, where answer[i] is 
/// the maximum segment sum after applying the ith removal.
///
/// Note: The same index will not be removed more than once.
/// Example 1:
/// Input: nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
/// Output: [14,7,2,2,0]
/// Explanation: Using 0 to indicate a removed element, the answer is 
/// as follows:
/// Query 1: Remove the 0th element, nums becomes [0,2,5,6,1] and the 
/// maximum segment sum is 14 for segment [2,5,6,1].
/// Query 2: Remove the 3rd element, nums becomes [0,2,5,0,1] and the 
/// maximum segment sum is 7 for segment [2,5].
/// Query 3: Remove the 2nd element, nums becomes [0,2,0,0,1] and the 
/// maximum segment sum is 2 for segment [2]. 
/// Query 4: Remove the 4th element, nums becomes [0,2,0,0,0] and the 
/// maximum segment sum is 2 for segment [2]. 
/// Query 5: Remove the 1st element, nums becomes [0,0,0,0,0] and the 
/// maximum segment sum is 0, since there are no segments.
/// Finally, we return [14,7,2,2,0].
///
/// Example 2:
/// Input: nums = [3,2,11,1], removeQueries = [3,2,1,0]
/// Output: [16,5,3,0]
/// Explanation: Using 0 to indicate a removed element, the answer is 
/// as follows:
/// Query 1: Remove the 3rd element, nums becomes [3,2,11,0] and the 
/// maximum segment sum is 16 for segment [3,2,11].
/// Query 2: Remove the 2nd element, nums becomes [3,2,0,0] and the 
/// maximum segment sum is 5 for segment [3,2].
/// Query 3: Remove the 1st element, nums becomes [3,0,0,0] and the 
/// maximum segment sum is 3 for segment [3].
/// Query 4: Remove the 0th element, nums becomes [0,0,0,0] and the 
/// maximum segment sum is 0, since there are no segments.
/// Finally, we return [16,5,3,0].
///
/// Constraints:
/// 1. n == nums.length == removeQueries.length
/// 2. 1 <= n <= 10^5
/// 3. 1 <= nums[i] <= 10^9
/// 4. 0 <= removeQueries[i] < n
/// 5. All the values of removeQueries are unique.
/// </summary>
vector<long long> LeetCodeGreedy::maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries)
{
    set<pair<int, long long>> segments;
    set<pair<long long, int>> heap;
    vector<int> removed(nums.size());
    vector<long long> sum(nums.size());
    for (size_t i = 0; i < nums.size(); i++)
    {
        sum[i] = nums[i];
        if (i > 0) sum[i] += sum[i - 1];
    }
    segments.insert(make_pair(nums.size() - 1, sum[nums.size() - 1]));
    heap.insert(make_pair(sum[nums.size() - 1], nums.size() - 1));
    vector<long long> result(removeQueries.size());
    for (size_t i = 0; i < removeQueries.size(); i++)
    {
        auto itr = segments.lower_bound(make_pair(removeQueries[i], 0));
        int right_index = itr->first;
        long long right_sum = sum[itr->first] - sum[removeQueries[i]];
        long long left_sum = itr->second - right_sum - (long long)nums[removeQueries[i]];
        if (right_sum > 0)
        {
            segments.insert(make_pair(itr->first, right_sum));
            heap.insert(make_pair(right_sum, itr->first));
        }
        if (left_sum > 0)
        {
            segments.insert(make_pair(removeQueries[i] - 1, left_sum));
            heap.insert(make_pair(left_sum, removeQueries[i] - 1));
        }
        heap.erase(make_pair(itr->second, itr->first));
        segments.erase(make_pair(itr->first, itr->second));
        if (heap.empty())
        {
            result[i] = 0;
        }
        else
        {
            result[i] = heap.rbegin()->first;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2407. Longest Increasing Subsequence II
/// </summary>
void LeetCodeGreedy::lengthOfLISUpdate(vector<int>& segTree, int index, int val,
    int x, int lx, int rx)
{
    if (lx == rx)
    {
        segTree[x] = max(segTree[x], val);
        return;
    }
    int middle = lx + (rx - lx) / 2;
    if (index <= middle)
    {
        lengthOfLISUpdate(segTree, index, val, 2 * x + 1, lx, middle);
    }
    else
    {
        lengthOfLISUpdate(segTree, index, val, 2 * x + 2, middle + 1, rx);
    }
    segTree[x] = max(segTree[2 * x + 1], segTree[2 * x + 2]);
}

/// <summary>
/// Leet Code 2407. Longest Increasing Subsequence II
/// </summary>
int LeetCodeGreedy::lengthOfLISQuery(vector<int>& segTree, int l, int r, int x, int lx, int rx)
{
    if (lx > r || rx < l) return 0;
    if (lx >= l && rx <= r) return segTree[x];
    int mid = lx + (rx - lx) / 2;
    int left = lengthOfLISQuery(segTree, l, r, 2 * x + 1, lx, mid);
    int right = lengthOfLISQuery(segTree, l, r, 2 * x + 2, mid + 1, rx);
    return max(left, right);
}

/// <summary>
/// Leet Code 2407. Longest Increasing Subsequence II
///                                                  
/// Hard
///
/// You are given an integer array nums and an integer k.
///
/// Find the longest subsequence of nums that meets the following 
/// requirements:
///
/// The subsequence is strictly increasing and
/// The difference between adjacent elements in the subsequence is 
/// at most k. 
/// Return the length of the longest subsequence that meets the 
/// requirements.
///
/// A subsequence is an array that can be derived from another 
/// array by deleting some or no elements without changing the 
/// order of the remaining elements.
/// 
/// Example 1:
/// Input: nums = [4,2,1,4,3,4,5,8,15], k = 3
/// Output: 5
/// Explanation:
/// The longest subsequence that meets the requirements is [1,3,4,5,8].
/// The subsequence has a length of 5, so we return 5.
/// Note that the subsequence [1,3,4,5,8,15] does not meet the requirements
/// because 15 - 8 = 7 is larger than 3.
///
/// Example 2:
/// Input: nums = [7,4,5,1,8,12,4,7], k = 5
/// Output: 4
/// Explanation:
/// The longest subsequence that meets the requirements is [4,5,8,12].
/// The subsequence has a length of 4, so we return 4.
///
/// Example 3:
/// Input: nums = [1,5], k = 1
/// Output: 1
/// Explanation:
/// The longest subsequence that meets the requirements is [1].
/// The subsequence has a length of 1, so we return 1.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 1 <= nums[i], k <= 10^5
/// </summary>
int LeetCodeGreedy::lengthOfLIS(vector<int>& nums, int k)
{
    int n = 1, s = 1;
    int max_val = 0; 
    for (size_t i = 0; i < nums.size(); i++) max_val = max(max_val, nums[i]);
    while (n <= max_val)
    {
        n = n * 2;
    }
    int result = 0;
    vector<int> segTree(n * 2);
    for (size_t i = 0; i < nums.size(); i++)
    {
        int q = lengthOfLISQuery(segTree, max(0, nums[i] - k),
            nums[i] - 1, 0, 0, n - 1);
        q++;
        lengthOfLISUpdate(segTree, nums[i], q, 0, 0, n - 1);
        result = max(result, q);
    }
    return result;
}

/// <summary>
/// Leet Code 2412. Minimum Money Required Before Transactions 
///                                                  
/// Hard
///
/// You are given a 0-indexed 2D integer array transactions, where 
/// transactions[i] = [costi, cashbacki].
///
/// The array describes transactions, where each transaction must be 
/// completed exactly once in some order. At any given moment, you have 
/// a certain amount of money. In order to complete transaction i, 
/// money >= costi must hold true. After performing a transaction, 
/// money becomes money - costi + cashbacki.
/// Return the minimum amount of money required before any transaction 
/// so that all of the transactions can be completed regardless of the 
/// order of the transactions.
///
/// Example 1:
/// Input: transactions = [[2,1],[5,0],[4,2]]
/// Output: 10
/// Explanation:
/// Starting with money = 10, the transactions can be performed in any 
/// order.
/// It can be shown that starting with money < 10 will fail to complete 
/// all transactions in some order.
///
/// Example 2:
/// Input: transactions = [[3,0],[0,3]]
/// Output: 3
/// Explanation:
/// - If transactions are in the order [[3,0],[0,3]], the minimum money 
///   required to complete the transactions is 3.
/// - If transactions are in the order [[0,3],[3,0]], the minimum money 
///   required to complete the transactions is 0.
/// Thus, starting with money = 3, the transactions can be performed in 
/// any order.
/// 
/// Constraints:
/// 1. 1 <= transactions.length <= 10^5
/// 2. transactions[i].length == 2
/// 3. 0 <= costi, cashbacki <= 10^9
/// </summary>
long long LeetCodeGreedy::minimumMoney(vector<vector<int>>& transactions)
{
    long long sum = 0;
    for (size_t i = 0; i < transactions.size(); i++)
    {
        sum += max((long long)0, (long long)transactions[i][0] - (long long)transactions[i][1]);
    }
    long long result = 0;
    for (size_t i = 0; i < transactions.size(); i++)
    {
        long long diff = max((long long)0, ((long long)transactions[i][0] - (long long)transactions[i][1]));
        result = max(result, sum - diff + (long long)transactions[i][0]);
    }
    return result;
}

/// <summary>
/// Leet Code 2410. Maximum Matching of Players With Trainers 
///                                                  
/// Medium
///
/// You are given a 0-indexed integer array players, where players[i] 
/// represents the ability of the ith player. You are also given a 
/// 0-indexed integer array trainers, where trainers[j] represents the 
/// training capacity of the jth trainer.
///
/// The ith player can match with the jth trainer if the player's ability 
/// is less than or equal to the trainer's training capacity. 
/// Additionally, the ith player can be matched with at most one trainer, 
/// and the jth trainer can be matched with at most one player.
///
/// Return the maximum number of matchings between players and trainers 
/// that satisfy these conditions.
///
/// Example 1:
/// Input: players = [4,7,9], trainers = [8,2,5,8]
/// Output: 2
/// Explanation:
/// One of the ways we can form two matchings is as follows:
/// - players[0] can be matched with trainers[0] since 4 <= 8.
/// - players[1] can be matched with trainers[3] since 7 <= 8.
/// It can be proven that 2 is the maximum number of matchings that can 
/// be formed.
///
/// Example 2:
/// Input: players = [1,1,1], trainers = [10]
/// Output: 1
/// Explanation:
/// The trainer can be matched with any of the 3 players.
/// Each player can only be matched with one trainer, so the maximum 
/// answer is 1.
/// 
/// Constraints:
/// 1. 1 <= players.length, trainers.length <= 10^5
/// 2. 1 <= players[i], trainers[j] <= 10^9
/// </summary>
int LeetCodeGreedy::matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
{
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());
    int p = 0;
    int t = 0;
    int result = 0;
    while (p < (int)players.size() && t < (int)trainers.size())
    {
        if (players[p] <= trainers[t])
        {
            p++;
            t++;
            result++;
        }
        else
        {
            t++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2406. Divide Intervals Into Minimum Number of Groups
///                                                  
/// Medium
///
/// You are given a 2D integer array intervals where intervals[i] = 
/// [lefti, righti] represents the inclusive interval [lefti, righti].
///
/// You have to divide the intervals into one or more groups such that 
/// each interval is in exactly one group, and no two intervals that 
/// are in the same group intersect each other.
///
/// Return the minimum number of groups you need to make.
///
/// Two intervals intersect if there is at least one common number 
/// between them. For example, the intervals [1, 5] and [5, 8] intersect.
///
/// Example 1:
/// Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
/// Output: 3
/// Explanation: We can divide the intervals into the following groups:
/// - Group 1: [1, 5], [6, 8].
/// - Group 2: [2, 3], [5, 10].
/// - Group 3: [1, 10].
/// It can be proven that it is not possible to divide the intervals 
/// into fewer than 3 groups.
///
/// Example 2:
/// Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
/// Output: 1
/// Explanation: None of the intervals overlap, so we can put all of 
/// them in one group.
/// 
/// Constraints:
/// 1. 1 <= intervals.length <= 10^5
/// 2. intervals[i].length == 2
/// 3. 1 <= lefti <= righti <= 10^6
/// </summary>
int LeetCodeGreedy::minGroups(vector<vector<int>>& intervals)
{
    map<int, int> scan_line;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        scan_line[intervals[i][0]]++;
        scan_line[intervals[i][1] + 1]--;
    }
    int count = 0;
    int result = 0;
    for (auto itr : scan_line)
    {
        count += itr.second;
        result = max(result, count);
    }
    return result;
}

/// <summary>
/// Leet Code 2402. Meeting Rooms III
///                                                  
/// Hard
///
/// You are given an integer n. There are n rooms numbered from 0 to n - 1.
///
/// You are given a 2D integer array meetings where 
/// meetings[i] = [starti, endi] means that a meeting will be held during 
/// the half-closed time interval [starti, endi). All the values of starti 
/// are unique.
///
/// Meetings are allocated to rooms in the following manner:
///
/// Each meeting will take place in the unused room with the lowest number.
/// If there are no available rooms, the meeting will be delayed until a 
/// room becomes free. The delayed meeting should have the same duration 
/// as the original meeting.
/// When a room becomes unused, meetings that have an earlier original 
/// start time should be given the room.
/// Return the number of the room that held the most meetings. If there 
/// are multiple rooms, return the room with the lowest number.
///
/// A half-closed interval [a, b) is the interval between a and b 
/// including a and not including b.
///
/// Example 1:
///
/// Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
/// Output: 0
/// Explanation:
/// - At time 0, both rooms are not being used. The first meeting 
///   starts in room 0.
/// - At time 1, only room 1 is not being used. The second meeting 
///   starts in room 1.
/// - At time 2, both rooms are being used. The third meeting is 
///   delayed.
/// - At time 3, both rooms are being used. The fourth meeting is delayed.
/// - At time 5, the meeting in room 1 finishes. The third meeting starts 
///   in room 1 for the time period [5,10).
/// - At time 10, the meetings in both rooms finish. The fourth meeting 
///   starts in room 0 for the time period [10,11).
/// Both rooms 0 and 1 held 2 meetings, so we return 0. 
///
/// Example 2:
/// Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
/// Output: 1
/// Explanation:
/// - At time 1, all three rooms are not being used. The first meeting 
///   starts in room 0.
/// - At time 2, rooms 1 and 2 are not being used. The second meeting 
///   starts in room 1.
/// - At time 3, only room 2 is not being used. The third meeting starts 
///   in room 2.
/// - At time 4, all three rooms are being used. The fourth meeting is 
///   delayed.
/// - At time 5, the meeting in room 2 finishes. The fourth meeting 
///   starts in room 2 for the time period [5,10).
/// - At time 6, all three rooms are being used. The fifth meeting 
///   is delayed.
/// - At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting 
///   starts in room 1 for the time period [10,12).
/// Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so 
///  we return 1. 
/// 
/// Constraints:
/// 1. 1 <= n <= 100
/// 2. 1 <= meetings.length <= 10^5
/// 3. meetings[i].length == 2
/// 4. 0 <= starti < endi <= 5 * 10^5
/// 5. All the values of starti are unique.
/// </summary>
int LeetCodeGreedy::mostBooked(int n, vector<vector<int>>& meetings)
{
    sort(meetings.begin(), meetings.end());
    set<pair<long long, int>> pq;
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++)
    {
        pq.insert(make_pair(meetings[0][0], i));
    }
    long long delta = 0;
    for (size_t i = 0; i < meetings.size(); i++)
    {
        while (pq.begin()->first < (long long)meetings[i][0])
        {
            long long start = meetings[i][0];
            int room = pq.begin()->second;
            pq.erase(pq.begin());
            pq.insert(make_pair(start, room));
        }
        long long start = pq.begin()->first;
        int room = pq.begin()->second;
        count[room]++;
        pq.erase(pq.begin());
        pq.insert(make_pair(start + (long long)meetings[i][1] - (long long)meetings[i][0], room));
    }
    int max_val = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (count[i] > max_val)
        {
            max_val = count[i];
            result = i;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 2532. Time to Cross a Bridge
/// 
/// Hard
///	
/// There are k workers who want to move n boxes from an old warehouse to 
/// a new one. You are given the two integers n and k, and a 2D integer 
/// array time of size k x 4 where time[i] = [leftToRighti, pickOldi, 
/// rightToLefti, putNewi].
///
/// The warehouses are separated by a river and connected by a bridge. 
/// The old warehouse is on the right bank of the river, and the new 
/// warehouse is on the left bank of the river. Initially, all k 
/// workers are waiting on the left side of the bridge. To move 
/// the boxes, the ith worker (0-indexed) can :
///
/// Cross the bridge from the left bank (new warehouse) to the right 
/// bank (old warehouse) in leftToRighti minutes.
/// Pick a box from the old warehouse and return to the bridge in 
/// pickOldi minutes. Different workers can pick up their boxes 
/// simultaneously.
/// Cross the bridge from the right bank (old warehouse) to the left 
/// bank (new warehouse) in rightToLefti minutes.
/// Put the box in the new warehouse and return to the bridge in putNewi 
/// minutes. Different workers can put their boxes simultaneously.
///
/// A worker i is less efficient than a worker j if either condition is 
/// met:
///
/// leftToRighti + rightToLefti > leftToRightj + rightToLeftj
/// leftToRighti + rightToLefti == leftToRightj + rightToLeftj and i > j
/// The following rules regulate the movement of the workers through the 
/// bridge :
///
/// If a worker x reaches the bridge while another worker y is crossing 
/// the bridge, x waits at their side of the bridge.
/// If the bridge is free, the worker waiting on the right side of the 
/// bridge gets to cross the bridge. If more than one worker is waiting 
/// on the right side, the one with the lowest efficiency crosses first.
/// If the bridge is free and no worker is waiting on the right side, 
/// and at least one box remains at the old warehouse, the worker on the 
/// left side of the river gets to cross the bridge. If more than one 
/// worker is waiting on the left side, the one with the lowest 
/// efficiency crosses first.
/// Return the instance of time at which the last worker reaches the 
/// left bank of the river after all n boxes have been put in the 
/// new warehouse.
/// 
/// Example 1:
/// Input: n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
/// Output: 6
/// Explanation: 
/// From 0 to 1: worker 2 crosses the bridge from the left bank to the 
/// right bank.
/// From 1 to 2: worker 2 picks up a box from the old warehouse.
/// From 2 to 6: worker 2 crosses the bridge from the right bank to the 
/// left bank.
/// From 6 to 7: worker 2 puts a box at the new warehouse.
/// The whole process ends after 7 minutes. We return 6 because the 
/// problem asks for the instance of time at which the last worker reaches 
/// the left bank.
///
/// Example 2:
/// Input: n = 3, k = 2, time = [[1,9,1,8],[10,10,10,10]]
/// Output: 50
/// Explanation: 
/// From 0  to 10: worker 1 crosses the bridge from the left bank to the 
/// right bank.
/// From 10 to 20: worker 1 picks up a box from the old warehouse.
/// From 10 to 11: worker 0 crosses the bridge from the left bank to the 
/// right bank.
/// From 11 to 20: worker 0 picks up a box from the old warehouse.
/// From 20 to 30: worker 1 crosses the bridge from the right bank to 
/// the left bank.
/// From 30 to 40: worker 1 puts a box at the new warehouse.
/// From 30 to 31: worker 0 crosses the bridge from the right bank 
/// to the left bank.
/// From 31 to 39: worker 0 puts a box at the new warehouse.
/// From 39 to 40: worker 0 crosses the bridge from the left bank to 
/// the right bank.
/// From 40 to 49: worker 0 picks up a box from the old warehouse.
/// From 49 to 50: worker 0 crosses the bridge from the right bank 
/// to the left bank.
/// From 50 to 58: worker 0 puts a box at the new warehouse.
/// The whole process ends after 58 minutes. We return 50 because the 
/// problem asks for the instance of time at which the last worker 
/// reaches the left bank.
///
/// Constraints:
/// 1. 1 <= n, k <= 10^4
/// 2. time.length == k
/// 3. time[i].length == 4
/// 4. 1 <= leftToRighti, pickOldi, rightToLefti, putNewi <= 1000
/// </summary>
int LeetCodeGreedy::findCrossingTime(int n, int k, vector<vector<int>>& time)
{
    priority_queue<pair<int, int>> left_bridge, right_bridge;
    set<pair<int, int>> left_warehouse, right_warehouse;
    for (size_t i = 0; i < time.size(); i++)
    {
        left_bridge.push(make_pair(time[i][0] + time[i][2], i));
    }

    int time_stamp = 0;
    while (n > 0 || !right_bridge.empty() || !left_warehouse.empty() || !right_warehouse.empty())
    {
        while ((!right_warehouse.empty()) && (right_warehouse.begin()->first <= time_stamp))
        {
            int worker = right_warehouse.begin()->second;
            right_bridge.push(make_pair(time[worker][0] + time[worker][2], worker));
            right_warehouse.erase(right_warehouse.begin());
        }
        while ((!left_warehouse.empty()) && (left_warehouse.begin()->first <= time_stamp))
        {
            int worker = left_warehouse.begin()->second;
            left_bridge.push(make_pair(time[worker][0] + time[worker][2], worker));
            left_warehouse.erase(left_warehouse.begin());
        }
        // clear left bridge if no more packages
        if (n == 0)
        {
            while (!left_bridge.empty()) left_bridge.pop();
        }

        if (left_bridge.empty() && right_bridge.empty())
        {
            int left_time = INT_MAX;
            if (!left_warehouse.empty()) left_time = left_warehouse.begin()->first;
            int right_time = INT_MAX;
            if (!right_warehouse.empty()) right_time = right_warehouse.begin()->first;
            if (left_time != INT_MAX || right_time != INT_MAX)
            {
                time_stamp = min(left_time, right_time);
            }
            continue;
        }

        if (!right_bridge.empty())
        {
            int worker = right_bridge.top().second;
            right_bridge.pop();
            time_stamp += time[worker][2];
            if (n > 0)
            {
                int next_time = time_stamp + time[worker][3];
                left_warehouse.insert(make_pair(next_time, worker));
            }
        }
        else if (!left_bridge.empty() && n > 0)
        {
            int worker = left_bridge.top().second;
            left_bridge.pop();
            time_stamp += time[worker][0];
            int next_time = time_stamp + time[worker][1];
            right_warehouse.insert(make_pair(next_time, worker));
            n--;
        }
    }
    return time_stamp;
}

/// <summary>
/// Leet Code 2534. Time Taken to Cross the Door
/// 
/// Hard
///	
/// There are n persons numbered from 0 to n - 1 and a door. Each person 
/// can enter or exit through the door once, taking one second.
///
/// You are given a non-decreasing integer array arrival of size n, where 
/// arrival[i] is the arrival time of the ith person at the door. You are 
/// also given an array state of size n, where state[i] is 0 if person i 
/// wants to enter through the door or 1 if they want to exit through the 
/// door.
///
/// If two or more persons want to use the door at the same time, they 
/// follow the following rules:
///
/// If the door was not used in the previous second, then the person who 
/// wants to exit goes first.
/// If the door was used in the previous second for entering, the person 
/// who wants to enter goes first.
/// If the door was used in the previous second for exiting, the person 
/// who wants to exit goes first.
/// If multiple persons want to go in the same direction, the person with 
/// the smallest index goes first.
/// Return an array answer of size n where answer[i] is the second at 
/// which the ith person crosses the door.
///
/// Note that:
///
/// Only one person can cross the door at each second.
/// A person may arrive at the door and wait without entering or exiting 
/// to follow the mentioned rules.
/// 
/// Example 1:
/// Input: arrival = [0,1,1,2,4], state = [0,1,0,0,1]
/// Output: [0,3,1,2,4]
/// Explanation: At each second we have the following:
/// - At t = 0: Person 0 is the only one who wants to enter, so they just 
///   enter through the door.
/// - At t = 1: Person 1 wants to exit, and person 2 wants to enter. Since 
///   the door was used the previous second for entering, person 2 enters.
/// - At t = 2: Person 1 still wants to exit, and person 3 wants to enter. 
///   Since the door was used the previous second for entering, person 3 
///   enters.
/// - At t = 3: Person 1 is the only one who wants to exit, so they just 
///   exit through the door.
/// - At t = 4: Person 4 is the only one who wants to exit, so they just 
///   exit through the door.
///
/// Example 2:
/// Input: arrival = [0,0,0], state = [1,0,1]
/// Output: [0,2,1]
/// Explanation: At each second we have the following:
/// - At t = 0: Person 1 wants to enter while persons 0 and 2 want to 
///   exit. Since the door was not used in the previous second, the 
///   persons who want to exit get to go first. Since person 0 has a 
///   smaller index, they exit first.
/// - At t = 1: Person 1 wants to enter, and person 2 wants to exit. Since 
///   the door was used in the previous second for exiting, person 2 exits.
/// - At t = 2: Person 1 is the only one who wants to enter, so they just 
///   enter through the door.
/// 
/// Constraints:
/// 1. n == arrival.length == state.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= arrival[i] <= n
/// 4. arrival is sorted in non-decreasing order.
/// 5. state[i] is either 0 or 1.
/// </summary>
vector<int> LeetCodeGreedy::timeTaken(vector<int>& arrival, vector<int>& state)
{
    vector<queue<int>> queue(2);
    vector<int> result(arrival.size());
    int prev = 1;
    size_t index = 0;
    int time = 0;
    while (!queue[0].empty() || !queue[1].empty() || index < arrival.size())
    {
        while (index < arrival.size() && arrival[index] <= time)
        {
            queue[state[index]].push(index);
            index++;
        }
        if (!queue[prev].empty())
        {
            int next = queue[prev].front();
            queue[prev].pop();
            result[next] = time;
        }
        else if (!queue[1 - prev].empty())
        {
            int next = queue[1-prev].front();
            queue[1-prev].pop();
            result[next] = time;
            prev = 1 - prev;
        }
        else
        {
            prev = 1;
        }
        time++;
    }
    return result;
}

/// <summary>
/// Leet Code 2542. Maximum Subsequence Score
/// 
/// Medium
///	
/// You are given two 0-indexed integer arrays nums1 and nums2 of equal 
/// length n and a positive integer k. You must choose a subsequence of 
/// indices from nums1 of length k.
///
/// For chosen indices i0, i1, ..., ik - 1, your score is defined as:
///
/// The sum of the selected elements from nums1 multiplied with the 
/// minimum of the selected elements from nums2.
/// It can defined simply as: (nums1[i0] + nums1[i1] +...+ 
/// nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
/// Return the maximum possible score.
///
/// A subsequence of indices of an array is a set that can be derived from 
/// the set {0, 1, ..., n-1} by deleting some or no elements.
///
/// Example 1:
/// Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
/// Output: 12
/// Explanation: 
/// The four possible subsequence scores are:
/// - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3)
///   = 7.
/// - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4)
///   = 6. 
/// - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) 
///   = 12. 
/// - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) 
///   = 8.
/// Therefore, we return the max score, which is 12.
///
/// Example 2:
/// Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
/// Output: 30
/// Explanation: 
/// Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
///
/// Constraints:
/// 1. n == nums1.length == nums2.length
/// 2. 1 <= n <= 10^5
/// 3. 0 <= nums1[i], nums2[j] <= 10^5
/// 4. 1 <= k <= n
/// </summary>
long long LeetCodeGreedy::maxScore(vector<int>& nums1, vector<int>& nums2, int k)
{
    int n = nums1.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].first = nums2[i];
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    long long result = 0;
    long long sum = 0;
    priority_queue<int> pq;
    for (int i = n - 1; i >= n - k; i--)
    {
        sum += nums1[arr[i].second];
        pq.push(-nums1[arr[i].second]);
    }
    result = sum * (long long)nums2[arr[n - k].second];

    for (int i = n - 1 - k; i >= 0; i--)
    {
        sum += pq.top();
        pq.pop();
        sum += nums1[arr[i].second];
        pq.push(-nums1[arr[i].second]);
        result = max(result, sum * (long long)nums2[arr[i].second]);
    }
    return result;
}

/// <summary>
/// Leet Code 2580. Count Ways to Group Overlapping Ranges
/// 
/// Medium
///	
/// You are given a 2D integer array ranges where ranges[i] = 
/// [starti, endi] denotes that all integers between starti and endi 
/// (both inclusive) are contained in the ith range.
///
/// You are to split ranges into two (possibly empty) groups such that:
///
/// Each range belongs to exactly one group.
/// Any two overlapping ranges must belong to the same group.
/// Two ranges are said to be overlapping if there exists at least one 
/// integer that is present in both ranges.
///
/// For example, [1, 3] and [2, 5] are overlapping because 2 and 3 occur 
/// in both ranges.
/// Return the total number of ways to split ranges into two groups. Since 
/// the answer may be very large, return it modulo 109 + 7.
///
/// Example 1:
/// Input: ranges = [[6,10],[5,15]]
/// Output: 2
/// Explanation: 
/// The two ranges are overlapping, so they must be in the same group.
/// Thus, there are two possible ways:
/// - Put both the ranges together in group 1.
/// - Put both the ranges together in group 2.
///
/// Example 2:
/// Input: ranges = [[1,3],[10,20],[2,5],[4,8]]
/// Output: 4
/// Explanation: 
/// Ranges [1,3], and [2,5] are overlapping. So, they must be in the same 
/// group.
/// Again, ranges [2,5] and [4,8] are also overlapping. So, they must also 
/// be in the same group. 
/// Thus, there are four possible ways to group them:
/// - All the ranges in group 1.
/// - All the ranges in group 2.
/// - Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
/// - Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.
///
/// Constraints:
/// 1. 1 <= ranges.length <= 10^5
/// 2. ranges[i].length == 2
/// 3. 0 <= starti <= endi <= 10^9
/// </summary>
int LeetCodeGreedy::countWays(vector<vector<int>>& ranges)
{
    int count = 0;
    int prev_end = -1;
    sort(ranges.begin(), ranges.end());
    for (size_t i = 0; i < ranges.size(); i++)
    {
        if (ranges[i][0] > prev_end)
        {
            count++;
        }
        prev_end = max(prev_end, ranges[i][1]);
    }
    long long M = 1000000007;
    long long result = 1;
    for (int i = 0; i < count; i++)
    {
        result = result * 2 % M;
    }
    return (int)result;
}

/// <summary>
/// Leet Code 2589. Minimum Time to Complete All Tasks
/// 
/// Hard
///	
/// There is a computer that can run an unlimited number of tasks at the 
/// same time. You are given a 2D integer array tasks where 
/// tasks[i] = [starti, endi, durationi] indicates that the ith task 
/// should run for a total of durationi seconds (not necessarily 
/// continuous) within the inclusive time range [starti, endi].
///
/// You may turn on the computer only when it needs to run a task. You 
/// can also turn it off if it is idle.
///
/// Return the minimum time during which the computer should be turned 
/// on to complete all tasks.
/// 
/// Example 1:
/// Input: tasks = [[2,3,1],[4,5,1],[1,5,2]]
/// Output: 2
/// Explanation: 
/// - The first task can be run in the inclusive time range [2, 2].
/// - The second task can be run in the inclusive time range [5, 5].
/// - The third task can be run in the two inclusive time 
///   ranges [2, 2] and [5, 5].
/// The computer will be on for a total of 2 seconds.
///
/// Example 2:
/// Input: tasks = [[1,3,2],[2,5,3],[5,6,2]]
/// Output: 4
/// Explanation: 
/// - The first task can be run in the inclusive time range [2, 3].
/// - The second task can be run in the inclusive time ranges 
///   [2, 3] and [5, 5].
/// - The third task can be run in the two inclusive time range [5, 6].
/// The computer will be on for a total of 4 seconds.
///
/// Constraints:
/// 1. 1 <= tasks.length <= 2000
/// 2. tasks[i].length == 3
/// 3. 1 <= starti, endi <= 2000
/// 4. 1 <= durationi <= endi - starti + 1 
/// </summary>
int LeetCodeGreedy::findMinimumTime(vector<vector<int>>& tasks)
{
    set<pair<int, int>> task_list;
    for (size_t i = 0; i < tasks.size(); i++)
    {
        task_list.insert(make_pair(tasks[i][1], i));
    }
    vector<int> dp(task_list.rbegin()->first + 1);
    while (!task_list.empty())
    {
        vector<int> task = tasks[task_list.begin()->second];
        task_list.erase(task_list.begin());

        int overlap = std::count(dp.begin() + task[0], dp.begin() + task[1] + 1, 1);
        int remaining = task[2] - overlap;
        for (int i = task[1]; (i >= task[0]) && (remaining > 0); i--)
        {
            if (dp[i] == 0)
            {
                dp[i] = 1;
                remaining--;
            }
        }
    }
    int result = std::count(dp.begin(), dp.end(), 1);
    return result;
}

/// <summary>
/// Leet Code 2655. Find Maximal Uncovered Ranges
/// 
/// Medium
///	
/// You are given an integer n which is the length of a 0-indexed array 
/// nums, and a 0-indexed 2D-array ranges, which is a list of sub-ranges 
/// of nums (sub-ranges may overlap).
///
/// Each row ranges[i] has exactly 2 cells:
///
/// ranges[i][0], which shows the start of the ith range (inclusive)
/// ranges[i][1], which shows the end of the ith range (inclusive)
/// These ranges cover some cells of nums and leave some cells uncovered. 
/// Your task is to find all of the uncovered ranges with maximal length.
///
/// Return a 2D-array answer of the uncovered ranges, sorted by the 
/// starting point in ascending order.
///
/// By all of the uncovered ranges with maximal length, we mean satisfying 
/// two conditions:
/// 
/// Each uncovered cell should belong to exactly one sub-range
/// There should not exist two ranges (l1, r1) and (l2, r2) such 
/// that r1 + 1 = l2
///
/// Example 1:
/// Input: n = 10, ranges = [[3,5],[7,8]]
/// Output: [[0,2],[6,6],[9,9]]
/// Explanation: The ranges (3, 5) and (7, 8) are covered, so if we 
/// simplify the array nums to a binary array where 0 shows an uncovered 
/// cell and 1 shows a covered cell, the array becomes 
/// [0,0,0,1,1,1,0,1,1,0] in which we can observe that the ranges (0, 2), 
/// (6, 6) and (9, 9) aren't covered.
///
/// Example 2:
/// Input: n = 3, ranges = [[0,2]]
/// Output: []
/// Explanation: In this example, the whole of the array nums is covered 
/// and there are no uncovered cells so the output is an empty array.
///
/// Example 3:
/// Input: n = 7, ranges = [[2,4],[0,3]]
/// Output: [[5,6]]
/// Explanation: The ranges (0, 3) and (2, 4) are covered, so if we 
/// simplify the array nums to a binary array where 0 shows an uncovered 
/// cell and 1 shows a covered cell, the array becomes [1,1,1,1,1,0,0] 
/// in which we can observe that the range (5, 6) is uncovered.
///
/// Constraints:
/// 1. 1 <= n <= 10^9
/// 2. 0 <= ranges.length <= 10^6
/// 3. ranges[i].length = 2
/// 4. 0 <= ranges[i][j] <= n - 1
/// 5. ranges[i][0] <= ranges[i][1]
/// </summary>
vector<vector<int>> LeetCodeGreedy::findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges)
{
    vector<vector<int>> result;
    int start = 0;
    sort(ranges.begin(), ranges.end());
    for (size_t i = 0; i < ranges.size(); i++)
    {
        if (ranges[i][0] > start)
        {
            result.push_back({ start, ranges[i][0] - 1 });
        }
        start = max(start, ranges[i][1] + 1);
    }
    if (start < n)
    {
        result.push_back({ start, n - 1 });
    }
    return result;
}

/// <summary>
/// Leet Code 2672. Number of Adjacent Elements With the Same Color
/// 
/// Medium
///	
/// There is a 0-indexed array nums of length n. Initially, all elements 
/// are uncolored (has a value of 0).
/// You are given a 2D integer array queries where 
/// queries[i] = [indexi, colori].
///
/// For each query, you color the index indexi with the color colori in 
/// the array nums.
///
/// Return an array answer of the same length as queries where answer[i] 
/// is the number of adjacent elements with the same color after the 
/// ith query.
///
/// More formally, answer[i] is the number of indices j, such 
/// that 0 <= j < n - 1 and nums[j] == nums[j + 1] and nums[j] != 0 after 
/// the ith query.
///
/// Example 1:
/// Input: n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
/// Output: [0,1,1,0,2]
/// Explanation: Initially array nums = [0,0,0,0], where 0 denotes 
/// uncolored elements of the array.
/// - After the 1st query nums = [2,0,0,0]. The count of adjacent elements
///   with the same color is 0.
/// - After the 2nd query nums = [2,2,0,0]. The count of adjacent elements 
///   with the same color is 1.
/// - After the 3rd query nums = [2,2,0,1]. The count of adjacent elements 
///   with the same color is 1.
/// - After the 4th query nums = [2,1,0,1]. The count of adjacent elements 
///   with the same color is 0.
/// - After the 5th query nums = [2,1,1,1]. The count of adjacent elements 
///   with the same color is 2.
///
/// Example 2:
/// Input: n = 1, queries = [[0,100000]]
/// Output: [0]
/// Explanation: Initially array nums = [0], where 0 denotes uncolored 
/// elements of the array.
/// - After the 1st query nums = [100000]. The count of adjacent elements 
///   with the same color is 0.
/// 
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= queries.length <= 10^5
/// 3. queries[i].length == 2
/// 4. 0 <= indexi <= n - 1
/// 5. 1 <=  colori <= 10^5
/// </summary>
vector<int> LeetCodeGreedy::colorTheArray(int n, vector<vector<int>>& queries)
{
    vector<int> colors(n);
    vector<int> result;
    int count = 0;
    for (size_t i = 0; i < queries.size(); i++)
    {
        int index = queries[i][0];
        int new_color = queries[i][1];
        int old_color = colors[index];
        colors[index] = new_color;
        int decrease = 0;
        if (old_color != 0)
        {
            if (index > 0 && colors[index - 1] == old_color)
            {
                decrease++;
            }
            if (index < n - 1 && colors[index + 1] == old_color)
            {
                decrease++;
            }
        }

        int increase = 0;
        if (index > 0 && colors[index - 1] == new_color)
        {
            increase++;
        }
        if (index < n - 1 && colors[index + 1] == new_color)
        {
            increase++;
        }
        count += increase - decrease;
        result.push_back(count);
    }
    return result;
}

/// <summary>
/// Leet Code 2747. Count Zero Request Servers
/// 
/// Medium
///
/// You are given an integer n denoting the total number of servers and 
/// a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] 
/// denotes that the server with id server_id received a request at time 
/// time.
///
/// You are also given an integer x and a 0-indexed integer array queries.
/// Return a 0-indexed integer array arr of length queries.length where 
/// arr[i] represents the number of servers that did not receive any 
/// requests during the time interval [queries[i] - x, queries[i]].
///
/// Note that the time intervals are inclusive.
/// Example 1:
/// Input: n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
/// Output: [1,2]
/// Explanation: 
/// For queries[0]: The servers with ids 1 and 2 get requests in the 
/// duration of [5, 10]. Hence, only server 3 gets zero requests.
/// For queries[1]: Only the server with id 2 gets a request in duration 
/// of [6,11]. Hence, the servers with ids 1 and 3 are the only servers 
/// that do not receive any requests during that time period.
///
/// Example 2:
/// Input: n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]
/// Output: [0,1]
/// Explanation: 
/// For queries[0]: All servers get at least one request in the 
/// duration of [1, 3].
/// For queries[1]: Only server with id 3 gets no request in the 
/// duration [2,4].
/// 
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= logs.length <= 10^5
/// 3. 1 <= queries.length <= 10^5
/// 4. logs[i].length == 2
/// 5. 1 <= logs[i][0] <= n
/// 6. 1 <= logs[i][1] <= 10^6
/// 7. 1 <= x <= 10^5
/// 8. x < queries[i] <= 10^6
/// </summary>
vector<int> LeetCodeGreedy::countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries)
{
    vector<pair<int, int>>request;
    for (size_t i = 0; i < logs.size(); i++)
    {
        request.push_back(make_pair(logs[i][1], logs[i][0]));
    }
    unordered_map<int, int> server_count;
    sort(request.begin(), request.end());
    vector<pair<int, int>>query_ids;
    for (size_t i = 0; i < queries.size(); i++)
    {
        query_ids.push_back(make_pair(queries[i], i));
    }
    sort(query_ids.begin(), query_ids.end());
    int left = 0;
    int right = 0;
    vector<int> result(queries.size());
    for (size_t i = 0; i < query_ids.size(); i++)
    {
        int end = query_ids[i].first;
        int start = end - x;
        int query_id = query_ids[i].second;
        while (right < (int)request.size() && request[right].first <= end)
        {
            server_count[request[right].second]++;
            right++;
        }
        while (left < (int)request.size() && request[left].first < start)
        {
            server_count[request[left].second]--;
            if (server_count[request[left].second] == 0)
            {
                server_count.erase(request[left].second);
            }
            left++;
        }
        result[query_id] = n - server_count.size();
    }
    return result;
}

/// <summary>
/// Leet 2813. Maximum Elegance of a K-Length Subsequence
/// 
/// Hard
///
/// You are given a 0-indexed 2D integer array items of length n and an 
/// integer k.
///
/// items[i] = [profiti, categoryi], where profiti and categoryi denote 
/// the profit and category of the ith item respectively.
///
/// Let's define the elegance of a subsequence of items as total_profit + 
/// distinct_categories^2, where total_profit is the sum of all profits 
/// in the subsequence, and distinct_categories is the number of distinct 
/// categories from all the categories in the selected subsequence.
///
/// Your task is to find the maximum elegance from all subsequences of 
/// size k in items.
///
/// Return an integer denoting the maximum elegance of a subsequence of 
/// items with size exactly k.
///
/// Note: A subsequence of an array is a new array generated from the 
/// original array by deleting some elements (possibly none) without 
/// changing the remaining elements' relative order.
/// 
/// Example 1:
/// Input: items = [[3,2],[5,1],[10,1]], k = 2
/// Output: 17
/// Explanation: In this example, we have to select a subsequence of 
/// size 2.
/// We can select items[0] = [3,2] and items[2] = [10,1].
/// The total profit in this subsequence is 3 + 10 = 13, and the 
/// subsequence contains 2 distinct categories [2,1].
/// Hence, the elegance is 13 + 22 = 17, and we can show that it is 
/// the maximum achievable elegance. 
///
/// Example 2:
/// Input: items = [[3,1],[3,1],[2,2],[5,3]], k = 3
/// Output: 19
/// Explanation: In this example, we have to select a subsequence of 
/// size 3. 
/// We can select items[0] = [3,1], items[2] = [2,2], and 
/// items[3] = [5,3]. 
/// The total profit in this subsequence is 3 + 2 + 5 = 10, and the 
/// subsequence contains 3 distinct categories [1,2,3]. 
/// Hence, the elegance is 10 + 32 = 19, and we can show that it is the 
/// maximum achievable elegance.
///
/// Example 3:
/// Input: items = [[1,1],[2,1],[3,1]], k = 3
/// Output: 7
/// Explanation: In this example, we have to select a subsequence of 
/// size 3. 
/// We should select all the items. 
/// The total profit will be 1 + 2 + 3 = 6, and the subsequence 
/// contains 1 distinct category [1]. 
/// Hence, the maximum elegance is 6 + 12 = 7.  
///
/// Constraints:
/// 1. 1 <= items.length == n <= 10^5
/// 2. items[i].length == 2
/// 3. items[i][0] == profiti
/// 4. items[i][1] == categoryi
/// 5. 1 <= profiti <= 10^9
/// 6. 1 <= categoryi <= n 
/// 7. 1 <= k <= n
/// </summary>
long long LeetCodeGreedy::findMaximumElegance(vector<vector<int>>& items, int k)
{
    unordered_set<int> categories;
    set<pair<int, int>> profits;
    sort(items.begin(), items.end());
    int n = items.size();
    long long sum = 0;
    long long result = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (n - i <= k)
        {
            sum += items[i][0];
            if (categories.count(items[i][1]) > 0)
            {
                profits.insert(make_pair(items[i][0], i));
            }
            else
            {
                categories.insert(items[i][1]);
            }
        }
        else
        {
            if (categories.count(items[i][1]) > 0)
            {
                continue;
            }
            else if (profits.empty())
            {
                break;
            }
            else
            {
                sum = sum - (long long)profits.begin()->first + (long long)items[i][0];
                categories.insert(items[i][1]);
                profits.erase(profits.begin());
            }
        }
        result = max(result, sum + (long long)categories.size() * (long long)categories.size());
    }
    return result;
}

/// <summary>
/// Leet Code 2830. Maximize the Profit as the Salesman
/// 
/// Medium
///
/// You are given an integer n representing the number of houses on a 
/// number line, numbered from 0 to n - 1.
///
/// Additionally, you are given a 2D integer array offers where 
/// offers[i] = [starti, endi, goldi], indicating that ith buyer wants 
/// to buy all the houses from starti to endi for goldi amount of gold.
///
/// As a salesman, your goal is to maximize your earnings by 
/// strategically selecting and selling houses to buyers.
///
/// Return the maximum amount of gold you can earn.
///
/// Note that different buyers can't buy the same house, and some 
/// houses may remain unsold.
///
/// Example 1:
/// Input: n = 5, offers = [[0,0,1],[0,2,2],[1,3,2]]
/// Output: 3
/// Explanation: There are 5 houses numbered from 0 to 4 and there 
/// are 3 purchase offers.
/// We sell houses in the range [0,0] to 1st buyer for 1 gold and houses 
/// in the range [1,3] to 3rd buyer for 2 golds.
/// It can be proven that 3 is the maximum amount of gold we can achieve.
///
/// Example 2:
///
/// Input: n = 5, offers = [[0,0,1],[0,2,10],[1,3,2]]
/// Output: 10
/// Explanation: There are 5 houses numbered from 0 to 4 and there are 3 
/// purchase offers.
/// We sell houses in the range [0,2] to 2nd buyer for 10 golds.
/// It can be proven that 10 is the maximum amount of gold we can achieve.
///
/// Constraints:
/// 1. 1 <= n <= 10^5
/// 2. 1 <= offers.length <= 10^5
/// 3. offers[i].length == 3
/// 4. 0 <= starti <= endi <= n - 1
/// 5. 1 <= goldi <= 10^3
/// </summary>
int LeetCodeGreedy::maximizeTheProfit(int n, vector<vector<int>>& offers)
{
    map<int, int> sales;
    vector<pair<int, int>> positions(offers.size());
    for (size_t i = 0; i < offers.size(); i++)
    {
        positions[i].first = offers[i][1];
        positions[i].second = i;
    }
    sort(positions.begin(), positions.end());
    for (size_t i = 0; i < positions.size(); i++)
    {
        int x = positions[i].second;
        int before_value = 0;
        auto itr = sales.lower_bound(offers[x][0]);
        if (itr != sales.begin())
        {
            before_value = std::prev(itr)->second;
        }
        itr = sales.upper_bound(offers[x][1]);
        int past_value = 0;
        if (itr != sales.begin())
        {
            past_value = std::prev(itr)->second;
        }
        int value = before_value + offers[x][2];
        value = max(value, past_value);
        sales[offers[x][1]] = value;
    }
    return sales.rbegin()->second;
}

/// <summary>
/// Leet Code 2848. Points That Intersect With Cars
/// 
/// Easy
///
/// You are given a 0-indexed 2D integer array nums representing the 
/// coordinates of the cars parking on a number line. For any index i, 
/// nums[i] = [starti, endi] where starti is the starting point of the 
/// ith car and endi is the ending point of the ith car.
///
/// Return the number of integer points on the line that are covered 
/// with any part of a car.
/// 
/// Example 1:
/// Input: nums = [[3,6],[1,5],[4,7]]
/// Output: 7
/// Explanation: All the points from 1 to 7 intersect at least one car, 
/// therefore the answer would be 7.
/// Example 2:
/// Input: nums = [[1,3],[5,8]]
/// Output: 7
/// Explanation: Points intersecting at least one car are 1, 2, 3, 5, 
/// 6, 7, 8. There are a total of 7 points, therefore the answer 
/// would be 7.
///
/// Constraints:
/// 1. 1 <= nums.length <= 100
/// 2. nums[i].length == 2
/// 3. 1 <= starti <= endi <= 100
/// </summary>
int LeetCodeGreedy::numberOfPoints(vector<vector<int>>& nums)
{
    sort(nums.begin(), nums.end());
    int prev = -1;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i][0] > prev)
        {
            result += nums[i][1] - nums[i][0] + 1;
            prev = nums[i][1];
        }
        else if (nums[i][1] > prev)
        {
            result += nums[i][1] - prev;
            prev = nums[i][1];
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3009. Maximum Number of Intersections on the Chart
///                 
/// Hard
///
/// There is a line chart consisting of n points connected by line segments. 
/// You are given a 1-indexed integer array y. The kth point has coordinates 
/// (k, y[k]). There are no horizontal lines; that is, no two consecutive 
/// points have the same y-coordinate.
///
/// We can draw an infinitely long horizontal line. Return the maximum number 
/// of points of intersection of the line with the chart.
///
/// Example 1:
/// Input: y = [1,2,1,2,1,3,2]
/// Output: 5
/// Explanation: As you can see in the image above, the line y = 1.5 has 5 
/// intersections with the chart (in red crosses). You can also see the line 
/// y = 2 which intersects the chart in 4 points (in red crosses). It can be 
/// shown that there is no horizontal line intersecting the chart at more 
/// than 5 points. So the answer would be 5.
///
/// Example 2:
/// Input: y = [2,1,3,4,5]
/// Output: 2
/// Explanation: As you can see in the image above, the line y = 1.5 has 2 
/// intersections with the chart (in red crosses). You can also see the line 
/// y = 2 which intersects the chart in 2 points (in red crosses). It can be 
/// shown that there is no horizontal line intersecting the chart at more 
/// than 2 points. So the answer would be 2.
/// 
/// Constraints:
/// 1. 2 <= y.length <= 10^5
/// 2. 1 <= y[i] <= 10^9
/// 3. y[i] != y[i + 1] for i in range [1, n - 1]
/// </summary>
int LeetCodeGreedy::maxIntersectionCount(vector<int>& y)
{
    map<int, pair<int, int>> positions;
    for (size_t i = 1; i < y.size(); i++)
    {
        int begin = min(y[i - 1], y[i]);
        int end = max(y[i - 1], y[i]);
        positions[begin].first++;
        positions[end].second++;
    }
    int result = 0;
    int accumulate = 0; 
    for (auto &itr : positions)
    {
        int points = itr.second.first + itr.second.second;
        points =  points - points / 2;
        if (itr.first == y[0] && itr.first == y[y.size() - 1])
        {
            points++;
        }
        result = max(result, accumulate - itr.second.second + points);
        accumulate += itr.second.first - itr.second.second;
        result = max(result, accumulate);
    }
    return result;
}

/// <summary>
/// Leet 3081. Replace Question Marks in String to Minimize Its Value
///
/// Medium
///
/// You are given a string s. s[i] is either a lowercase English letter 
/// or '?'.
/// 
/// For a string t having length m containing only lowercase English 
/// letters, we define the function cost(i) for an index i as the number 
/// of characters equal to t[i] that appeared before it, i.e. in the 
/// range [0, i - 1].
/// 
/// The value of t is the sum of cost(i) for all indices i.
/// For example, for the string t = "aab":
/// cost(0) = 0
/// cost(1) = 1
/// cost(2) = 0
/// Hence, the value of "aab" is 0 + 1 + 0 = 1.
/// Your task is to replace all occurrences of '?' in s with any lowercase 
/// English letter so that the value of s is minimized.
///
/// Return a string denoting the modified string with replaced occurrences 
/// of '?'. If there are multiple strings resulting in the minimum value, 
/// return the lexicographically smallest one.
/// 
/// Example 1:
/// Input:  s = "???" 
/// Output:  "abc" 
/// Explanation: In this example, we can replace the occurrences of '?' to 
/// make s equal to "abc".
/// 
/// For "abc", cost(0) = 0, cost(1) = 0, and cost(2) = 0.
/// The value of "abc" is 0.
/// Some other modifications of s that have a value of 0 are "cba", "abz", 
/// and, "hey".
/// Among all of them, we choose the lexicographically smallest.
///
/// Example 2:
/// Input: s = "a?a?"
/// Output: "abac"
/// Explanation: In this example, the occurrences of '?' can be replaced 
/// to make s equal to "abac".
///
/// For "abac", cost(0) = 0, cost(1) = 0, cost(2) = 1, and cost(3) = 0.
/// The value of "abac" is 1.
/// 
/// Constraints:
/// 1. 1 <= s.length <= 10^5
/// 2. s[i] is either a lowercase English letter or '?'.
/// </summary>
string LeetCodeGreedy::minimizeStringValue(string s)
{
    int question = 0;
    vector<int> char_count(26);
    // count character frequency
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '?') question++;
        else char_count[s[i] - 'a']++;
    }
    // build priority queue
    set<pair<int, char>> pq;
    for (int i = 0; i < 26; i++) pq.insert(make_pair(char_count[i], 'a' + i));
    string str;
    // replace '?'
    for (int i = 0; i < question; i++)
    {
        pair<int, char> top = *pq.begin();
        pq.erase(pq.begin());
        str.push_back(top.second);
        top.first++;
        pq.insert(top);
    }
    // need to sorting to get lexicographically smallest
    sort(str.begin(), str.end());
    string result = s;
    int p = 0;
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] == '?')
        {
            result[i] = str[p];
            p++;
        }
    }
    return result;
}


/// <summary>
/// Leet 3088. Make String Anti-palindrome
///
/// Hard
///
/// We call a string s of even length n an anti-palindrome if for each 
/// index 0 <= i < n, s[i] != s[n - i - 1].
///
/// Given a string s, your task is to make s an anti-palindrome by doing 
/// any number of operations (including zero).
///
/// In one operation, you can select two characters from s and swap them.
///
/// Return the resulting string. If multiple strings meet the conditions, 
/// return the lexicographically smallest one. If it can't be made into an 
/// anti-palindrome, return "-1".
///
/// 
/// Example 1:
/// Input: s = "abca"
/// Output: "aabc"
///
/// Explanation:
/// "aabc" is an anti-palindrome string since s[0] != s[3] and 
/// s[1] != s[2]. Also, it is a rearrangement of "abca".
///
/// Example 2:
/// Input: s = "abba"
/// Output: "aabb"
///
/// Explanation:
/// "aabb" is an anti-palindrome string since s[0] != s[3] and 
/// s[1] != s[2]. Also, it is a rearrangement of "abba".
///
/// Example 3:
/// Input: s = "cccd"
/// Output: "-1"
/// Explanation:
/// You can see that no matter how you rearrange the characters of "cccd", 
/// either s[0] == s[3] or s[1] == s[2]. So it can not form an 
/// anti-palindrome string.
///
/// Constraints:
/// 1. 2 <= s.length <= 10^5
/// 2. s.length % 2 == 0
/// 3. s consists only of lowercase English letters.
/// </summary>
string LeetCodeGreedy::makeAntiPalindrome(string s)
{
    string result = string(s.size(), '#');
    vector<int> char_count(26);
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char_count[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < 26; j++)
        {
            if (char_count[j] == 0) continue;
            if (result[n - 1 - i] == 'a' + j) continue;
            result[i] = 'a' + j;
            char_count[j]--;
            found = true;
            break;
        }
        if (found == false) return "-1";
    }
    return result;
}

/// <summary>
/// LeetCode 3168. Minimum Number of Chairs in a Waiting Room
/// 
/// Easy
/// 
/// You are given a string s. Simulate events at each second i:
/// If s[i] == 'E', a person enters the waiting room and takes one of the 
/// chairs in it.
/// If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
/// Return the minimum number of chairs needed so that a chair is 
/// available for every person who enters the waiting room given that it 
/// is initially empty.
///
/// Example 1:
/// Input: s = "EEEEEEE"
/// Output: 7
/// Explanation:
/// After each second, a person enters the waiting room and no person 
/// leaves it. Therefore, a minimum of 7 chairs is needed.
///
/// Example 2:
/// Input: s = "ELELEEL"
/// Output: 2
/// Explanation:
/// Let's consider that there are 2 chairs in the waiting room. The table 
/// below shows the state of the waiting room at each second.
///
/// Second Event People in the Waiting Room Available Chairs
/// 0   Enter   1   1
/// 1   Leave   0   2
/// 2   Enter   1   1
/// 3   Leave   0   2
/// 4   Enter   1   1
/// 5   Enter   2   0
/// 6   Leave   1   1
///
/// Example 3:
/// Input: s = "ELEELEELLL"
/// Output: 3
///
/// Explanation:
/// Let's consider that there are 3 chairs in the waiting room. The table 
/// below shows the state of the waiting room at each second.
///
/// Second  Event   People in the Waiting Room  Available Chairs
/// 0   Enter   1   2
/// 1   Leave   0   3
/// 2   Enter   1   2
/// 3   Enter   2   1
/// 4   Leave   1   2
/// 5   Enter   2   1
/// 6   Enter   3   0
/// 7   Leave   2   1
/// 8   Leave   1   2
/// 9   Leave   0   3
///
/// Constraints:
/// 1. 1 <= s.length <= 50
/// 2. s consists only of the letters 'E' and 'L'.
/// 3. s represents a valid sequence of entries and exits.
/// </summary>
int LeetCodeGreedy::minimumChairs(string s)
{
    int result = 0, count = 0;
    for (char c : s)
    {
        if (c == 'E')
        {
            count++;
            result = max(result, count);
        }
        else
        {
            count--;
        }
    }
    return result;
}

/// <summary>
/// LeetCode 3169. Count Days Without Meetings
/// 
/// Medium
/// 
/// You are given a positive integer days representing the total number of 
/// days an employee is available for work (starting from day 1). You are 
/// also given a 2D array meetings of size n where, meetings[i] = 
/// [start_i, end_i] represents the starting and ending days of meeting i 
/// (inclusive).
///
/// Return the count of days when the employee is available for work but 
/// no meetings are scheduled.
///
/// Note: The meetings may overlap.
/// Example 1:
/// Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
/// Output: 2
/// Explanation:
/// There is no meeting scheduled on the 4th and 8th days.
///  
/// Example 2:
/// Input: days = 5, meetings = [[2,4],[1,3]]
/// Output: 1
/// Explanation:
/// There is no meeting scheduled on the 5th day.
///
/// Example 3:
/// Input: days = 6, meetings = [[1,6]]
/// Output: 0
/// Explanation:
/// Meetings are scheduled for all working days.
/// 
/// Constraints:
/// 1. 1 <= days <= 10^9
/// 2. 1 <= meetings.length <= 10^5
/// 3. meetings[i].length == 2
/// 4. 1 <= meetings[i][0] <= meetings[i][1] <= days
/// </summary>
int LeetCodeGreedy::countDays(int days, vector<vector<int>>& meetings)
{
    map<int, int> scan_line;
    for (size_t i = 0; i < meetings.size(); i++)
    {
        scan_line[meetings[i][0]]++;
        scan_line[meetings[i][1] + 1]--;
    }
    int result = 0;
    int prev = 1;
    long long sum = 0;
    for (auto itr : scan_line)
    {
        sum += itr.second;
        if (sum != 0)
        {
            if (prev != -1)
            {
                result += itr.first - prev;
                prev = -1;
            }
        }
        else
        {
            if (prev == -1) prev = itr.first;
        }
    }
    result += days + 1 - prev;
    return result;
}

/// <summary>
/// Leet Code 3273. Minimum Amount of Damage Dealt to Bob
/// 
/// Hard
///
/// You are given an integer power and two integer arrays damage and 
/// health, both having length n.
///
/// Bob has n enemies, where enemy i will deal Bob damage[i] points of 
/// damage per second while they are alive (i.e. health[i] > 0).
///
/// Every second, after the enemies deal damage to Bob, he chooses one 
/// of the enemies that is still alive and deals power points of damage 
/// to them.
///
/// Determine the minimum total amount of damage points that will be 
/// dealt to Bob before all n enemies are dead.
///
/// Example 1:
/// Input: power = 4, damage = [1,2,3,4], health = [4,5,6,8]
/// Output: 39
/// Explanation:
/// Attack enemy 3 in the first two seconds, after which enemy 3 will 
/// go down, the number of damage points dealt to Bob is 10 + 10 = 20 
/// points.
/// Attack enemy 2 in the next two seconds, after which enemy 2 will 
/// go down, the number of damage points dealt to Bob is 6 + 6 = 12 
/// points.
/// Attack enemy 0 in the next second, after which enemy 0 will go 
/// down, the number of damage points dealt to Bob is 3 points.
/// Attack enemy 1 in the next two seconds, after which enemy 1 will 
/// go down, the number of damage points dealt to Bob is 2 + 2 = 4 
/// points.
///
/// Example 2:
/// Input: power = 1, damage = [1,1,1,1], health = [1,2,3,4]
/// Output: 20
/// Explanation:
/// Attack enemy 0 in the first second, after which enemy 0 will go down, 
/// the number of damage points dealt to Bob is 4 points.
/// Attack enemy 1 in the next two seconds, after which enemy 1 will go 
/// down, the number of damage points dealt to Bob is 3 + 3 = 6 points.
/// Attack enemy 2 in the next three seconds, after which enemy 2 will 
/// go down, the number of damage points dealt to Bob is 2 + 2 + 2 = 6 
/// points.
/// Attack enemy 3 in the next four seconds, after which enemy 3 will 
/// go down, the number of damage points dealt to Bob is 
/// 1 + 1 + 1 + 1 = 4 points.
///
/// Example 3:
/// Input: power = 8, damage = [40], health = [59]
/// Output: 320
/// 
/// Constraints:
/// 1. 1 <= power <= 10^4
/// 2. 1 <= n == damage.length == health.length <= 10^5
/// 3. 1 <= damage[i], health[i] <= 10^4
/// </summary>
long long LeetCodeGreedy::minDamage(int power, vector<int>& damage, vector<int>& health)
{
    vector<int> time(health.size());
    long long result = 0;
    long long sum = 0;
    for (size_t i = 0; i < health.size(); i++)
    {
        time[i] = (health[i] + (power - 1)) / power;
        sum += damage[i];
    }
    set<pair<double, int>> pq;
    for (size_t i = 0; i < health.size(); i++)
    {
        pq.insert(make_pair((double)time[i] / damage[i], i));
    }
    while (!pq.empty())
    {
        pair<double, int> enemy = *pq.begin();
        pq.erase(pq.begin());
        result += sum * time[enemy.second];
        sum -= damage[enemy.second];
    }
    return result;
}

/// <summary>
/// Leet Code 3323. Minimize Connected Groups by Inserting Interval 
/// 
/// Medium
///
/// You are given a 2D array intervals, where intervals[i] = [starti, 
/// endi] represents the start and the end of interval i. You are also 
/// given an integer k.
///
/// You must add exactly one new interval [startnew, endnew] to the array 
/// such that:
///
/// The length of the new interval, endnew - startnew, is at most k.
/// After adding, the number of connected groups in intervals is minimized.
///
/// A connected group of intervals is a maximal collection of intervals 
/// that, when considered together, cover a continuous range from the 
/// smallest point to the largest point with no gaps between them. Here 
/// are some examples:
///
/// A group of intervals [[1, 2], [2, 5], [3, 3]] is connected because 
/// together they cover the range from 1 to 5 without any gaps.
/// However, a group of intervals [[1, 2], [3, 4]] is not connected 
/// because the segment (2, 3) is not covered.
/// Return the minimum number of connected groups after adding exactly 
/// one new interval to the array.
///
/// Example 1:
/// Input: intervals = [[1,3],[5,6],[8,10]], k = 3
/// Output: 2
/// Explanation:
/// After adding the interval [3, 5], we have two connected groups: 
/// [[1, 3], [3, 5], [5, 6]] and [[8, 10]].
///
/// Example 2:
/// Input: intervals = [[5,10],[1,1],[3,3]], k = 1
/// Output: 3
/// Explanation:
/// After adding the interval [1, 1], we have three connected groups: 
/// [[1, 1], [1, 1]], [[3, 3]], and [[5, 10]].
///
/// Constraints:
/// 1. 1 <= intervals.length <= 10^5
/// 2. intervals[i] == [starti, endi]
/// 3. 1 <= starti <= endi <= 10^9
/// 4. 1 <= k <= 10^9
/// </summary>
int LeetCodeGreedy::minConnectedGroups(vector<vector<int>>& intervals, int k)
{
    sort(intervals.begin(), intervals.end());
    deque<int> deque;
    int result = 0;
    int connections = 0;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (deque.empty())
        {
            deque.push_back(intervals[i][1]);
            result++;
        }
        else
        {
            int end = deque.back();
            if (end >= intervals[i][0])
            {
                deque.pop_back();
                deque.push_back(max(end, intervals[i][1]));
            }
            else
            {
                while (!deque.empty() && deque.front() < intervals[i][0] - k)
                {
                    deque.pop_front();
                }
                connections = max(connections, (int)deque.size());
                deque.push_back(intervals[i][1]);
                result++;
            }
        }
    }
    return result - connections;
}

/// <summary>
/// Leet Code 3355. Zero Array Transformation I
/// 
/// Medium
///
/// You are given an integer array nums of length n and a 2D array 
/// queries, where queries[i] = [li, ri].
///
/// For each queries[i]:
///
/// Select a subset of indices within the range [li, ri] in nums.
/// Decrement the values at the selected indices by 1.
/// A Zero Array is an array where all elements are equal to 0.
///
/// Return true if it is possible to transform nums into a Zero Array 
/// after processing all the queries sequentially, otherwise return false.
///
/// A subset of an array is a selection of elements (possibly none) of the 
/// array.
/// 
/// Example 1:
/// Input: nums = [1,0,1], queries = [[0,2]]
/// Output: true
/// Explanation:
/// For i = 0:
/// Select the subset of indices as [0, 2] and decrement the values at 
/// these indices by 1.
/// The array will become [0, 0, 0], which is a Zero Array.
///
/// Example 2:
/// Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]
/// Output: false
/// Explanation:
/// For i = 0:
/// Select the subset of indices as [1, 2, 3] and decrement the values 
/// at these indices by 1.
/// The array will become [4, 2, 1, 0].
/// For i = 1:
/// Select the subset of indices as [0, 1, 2] and decrement the values 
/// at these indices by 1.
/// The array will become [3, 1, 0, 0], which is not a Zero Array.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^5
/// 3. 1 <= queries.length <= 10^5
/// 4. queries[i].length == 2
/// 5. 0 <= li <= ri < nums.length
/// </summary>
bool LeetCodeGreedy::isZeroArrayI(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();
    vector<int> dp(n+1);
    for (size_t i = 0; i < queries.size(); i++)
    {
        dp[queries[i][0]]++;
        dp[queries[i][1] + 1]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0) dp[i] += dp[i - 1];
        if (nums[i] > dp[i]) return false;
    }
    return true;
}

/// <summary>
/// Leet Code 3356. Zero Array Transformation II
/// 
/// Medium
///
/// You are given an integer array nums of length n and a 2D array queries 
/// where queries[i] = [li, ri, vali].
///
/// Each queries[i] represents the following action on nums:
///
/// Decrement the value at each index in the range [li, ri] in nums by at 
/// most vali.
/// The amount by which each value is decremented can be chosen 
/// independently for each index.
/// A Zero Array is an array with all its elements equal to 0.
///
/// Return the minimum possible non-negative value of k, such that after 
/// processing the first k queries in sequence, nums becomes a Zero Array. 
/// If no such k exists, return -1.
///
/// Example 1:
/// Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
/// Output: 2
/// Explanation:
/// For i = 0 (l = 0, r = 2, val = 1):
/// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
/// The array will become [1, 0, 1].
/// For i = 1 (l = 0, r = 2, val = 1):
/// Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
/// The array will become [0, 0, 0], which is a Zero Array. Therefore, the 
/// minimum value of k is 2.
///
/// Example 2:
/// Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
/// Output: -1
/// Explanation:
/// For i = 0 (l = 1, r = 3, val = 2):
/// Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
/// The array will become [4, 1, 0, 0].
/// For i = 1 (l = 0, r = 2, val = 1):
/// Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
/// The array will become [3, 0, 0, 0], which is not a Zero Array.
///
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 5 * 10^5
/// 3. 1 <= queries.length <= 10^5
/// 4. queries[i].length == 3
/// 5. 0 <= li <= ri < nums.length
/// 6. 1 <= vali <= 5
/// </summary>
int LeetCodeGreedy::isZeroArrayII(vector<int>& nums, vector<vector<int>>& queries)
{
    int n = nums.size();
    vector<int> dp(n + 1);
    int p = 0;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        while (nums[i] > dp[i] && p < (int)queries.size())
        {
            if (queries[p][1] >= i)
            {
                int start = max(queries[p][0], i);
                int end = queries[p][1] + 1;
                dp[start] += queries[p][2];
                dp[end] -= queries[p][2];
            }
            p++;
        }
        if (nums[i] > dp[i] && p >= (int)queries.size())
        {
            return -1;
        }
        else
        {
            dp[i + 1] += dp[i];
        }
    }
    return p;
}


/// <summary>
/// Leet Code 3362. Zero Array Transformation III 
/// 
/// Medium
/// 
/// You are given an integer array nums of length n and a 2D array queries 
/// where queries[i] = [li, ri].
///
/// Each queries[i] represents the following action on nums:
///
/// Decrement the value at each index in the range [li, ri] in nums by at 
/// most 1.
/// The amount by which the value is decremented can be chosen 
/// independently for each index.
/// A Zero Array is an array with all its elements equal to 0.
///
/// Return the maximum number of elements that can be removed from 
/// queries, such that nums can still be converted to a zero array using 
/// the remaining queries. If it is not possible to convert nums to a 
/// zero array, return -1.
///
/// Example 1:
/// Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
/// Output: 1
///
/// Explanation:
/// After removing queries[2], nums can still be converted to a zero array.
///
/// Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
/// Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
///
/// Example 2:
/// Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
/// Output: 2
/// Explanation:
/// We can remove queries[2] and queries[3].
/// 
/// Example 3:
/// Input: nums = [1,2,3,4], queries = [[0,3]]
/// Output: -1
/// Explanation:
/// nums cannot be converted to a zero array even after using all the 
/// queries.
/// 
/// Constraints:
/// 1. 1 <= nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^5
/// 3. 1 <= queries.length <= 10^5
/// 4. queries[i].length == 2
/// 5. 0 <= li <= ri < nums.length
/// </summary>
int LeetCodeGreedy::maxRemoval(vector<int>& nums, vector<vector<int>>& queries)
{
    set<pair<int, int>> query_set;
    for (size_t i = 0; i < queries.size(); i++)
    {
        query_set.insert(make_pair(queries[i][0], i));
    }
    int n = nums.size();
    vector<int> dp(n + 1);
    int result = 0;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        while(nums[i] > dp[i]) 
        {
            while (!query_set.empty() && query_set.begin()->first <= i)
            {
                pair<int, int> pair = *query_set.begin();
                query_set.erase(*query_set.begin());
                if (queries[pair.second][1] < i)
                {
                    result++;
                }
                else
                {
                    pq.push(make_pair(queries[pair.second][1], pair.second));
                }
            }
            if (!pq.empty())
            {
                pair<int, int> pair = pq.top();
                pq.pop();
                if (queries[pair.second][1] < i) result++;
                else
                {
                    int start = max(queries[pair.second][0], i);
                    int end = queries[pair.second][1] + 1;
                    dp[start] += 1;
                    dp[end] -= 1;
                }
            }
            else
            {
                return -1;
            }
        }
        dp[i + 1] += dp[i];
    }
    result += pq.size() + query_set.size();
    return result;
}

/// <summary>
/// Leet Code 3394. Check if Grid can be Cut into Sections
///   
/// Medium
/// 
/// You are given an integer n representing the dimensions of an n x n 
/// grid, with the origin at the bottom-left corner of the grid. You 
/// are also given a 2D array of coordinates rectangles, where 
/// rectangles[i] is in the form [startx, starty, endx, endy], 
/// representing a rectangle on the grid. Each rectangle is defined 
/// as follows:
///
/// (startx, starty): The bottom-left corner of the rectangle.
/// (endx, endy): The top-right corner of the rectangle.
/// Note that the rectangles do not overlap. Your task is to determine 
/// if it is possible to make either two horizontal or two vertical cuts 
/// on the grid such that:
///
/// Each of the three resulting sections formed by the cuts contains at 
/// least one rectangle.
/// Every rectangle belongs to exactly one section.
/// Return true if such cuts can be made; otherwise, return false.
/// 
/// Example 1:
/// Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
/// Output: true
/// Explanation:
/// The grid is shown in the diagram. We can make horizontal cuts at 
/// y = 2 and y = 4. Hence, output is true.
///
/// Example 2:
/// Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
/// Output: true
/// Explanation:
/// We can make vertical cuts at x = 2 and x = 3. Hence, output is true.
///
/// Example 3:
/// Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],
/// [3,2,4,4]]
/// Output: false
/// Explanation:
/// We cannot make two horizontal or two vertical cuts that satisfy the 
/// conditions. Hence, output is false.
/// 
/// Constraints:
/// 1. 3 <= n <= 10^9
/// 2. 3 <= rectangles.length <= 10^5
/// 3. 0 <= rectangles[i][0] < rectangles[i][2] <= n
/// 4. 0 <= rectangles[i][1] < rectangles[i][3] <= n
/// 5. No two rectangles overlap.
/// </summary>
bool LeetCodeGreedy::checkValidCuts(int n, vector<vector<int>>& rectangles)
{
    vector<set<pair<int, int>>> line(2);
    for (size_t i = 0; i < rectangles.size(); i++)
    {
        line[0].insert(make_pair(rectangles[i][0], rectangles[i][2]));
        line[1].insert(make_pair(rectangles[i][1], rectangles[i][3]));
    }
    for (int i = 0; i < 2; i++)
    {
        int result = 0;
        pair<int, int> pair = { -1, -1 };
        for (auto itr : line[i])
        {
            if (pair.first == -1 || pair.second <= itr.first)
            {
                result++;
                pair = itr;
            }
            else
            {
                pair.second = max(itr.second, pair.second);
            }
        }
        if (result >= 3) return true;
    }
    return false;
}

/// <summary>
/// Leet Code 3413. Maximum Coins From K Consecutive Bags
///   
/// Medium
///
/// There are an infinite amount of bags on a number line, one bag for 
/// each coordinate. Some of these bags contain coins.
///
/// You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes 
/// that every bag from li to ri contains ci coins.
///
/// The segments that coins contain are non-overlapping.
///
/// You are also given an integer k.
///
/// Return the maximum amount of coins you can obtain by collecting k 
/// consecutive bags.
/// 
/// Example 1:
/// Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
/// Output: 10
///
/// Explanation:
/// Selecting bags at positions [3, 4, 5, 6] gives the maximum number of 
/// coins: 2 + 0 + 4 + 4 = 10.
///
/// Example 2:
/// Input: coins = [[1,10,3]], k = 2
/// Output: 6
/// Explanation:
/// Selecting bags at positions [1, 2] gives the maximum number of 
/// coins: 3 + 3 = 6.
/// 
/// Constraints:
/// 1. 1 <= coins.length <= 10^5
/// 2. 1 <= k <= 10^9
/// 3. coins[i] == [li, ri, ci]
/// 4. 1 <= li <= ri <= 10^9
/// 5. 1 <= ci <= 1000
/// 6. The given segments are non-overlapping.
/// </summary>
long long LeetCodeGreedy::maximumCoins(vector<vector<int>>& coins, int k)
{
    map<int, long long> dp;
    for (size_t i = 0; i < coins.size(); i++)
    {
        dp[coins[i][0]] += coins[i][2];
        dp[coins[i][1]+1] -= coins[i][2];
        dp[coins[i][0] + k] += 0;
        dp[coins[i][1] + 1 - k] += 0;
    }
    int prev = dp.begin()->first;
    long long amount = 0, sum = 0, result = 0;
    for (auto& itr : dp)
    {
        sum += amount * (itr.first - prev);
        if (dp.count(itr.first - k) > 0)
        {
            result = max(result, sum - dp[itr.first - k]);
        }
        amount += itr.second;
        prev = itr.first;
        dp[itr.first] = sum;
    }
    return result;
}

/// <summary>
/// Leet Code 3439. Reschedule Meetings for Maximum Free Time I
///   
/// Medium
/// 
/// You are given an integer eventTime denoting the duration of an event, 
/// where the event occurs from time t = 0 to time t = eventTime.
///
/// You are also given two integer arrays startTime and endTime, each of 
/// length n. These represent the start and end time of n non-overlapping 
/// meetings, where the ith meeting occurs during the time [startTime[i], 
/// endTime[i]].
///
/// You can reschedule at most k meetings by moving their start time while 
/// maintaining the same duration, to maximize the longest continuous period 
/// of free time during the event.
///
/// The relative order of all the meetings should stay the same and they 
/// should remain non-overlapping.
///
/// Return the maximum amount of free time possible after rearranging the 
/// meetings.
///
/// Note that the meetings can not be rescheduled to a time outside the event.
/// 
/// Example 1:
/// Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
/// Output: 2
/// Explanation:
/// Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the 
/// time [0, 2].
///
/// Example 2:
/// Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
/// Output: 6
/// Explanation:
/// Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during 
/// the time [3, 9].
///
/// Example 3:
/// Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
/// Output: 0
/// Explanation:
/// There is no time during the event not occupied by meetings.
/// Constraints:
/// 1. 1 <= eventTime <= 10^9
/// 2. n == startTime.length == endTime.length
/// 3. 2 <= n <= 10^5
/// 4. 1 <= k <= n
/// 5. 0 <= startTime[i] < endTime[i] <= eventTime
/// 6. endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].
/// </summary>
int LeetCodeGreedy::maxFreeTimeI(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
{
    vector<int> timeslot;
    for (size_t i = 0; i <= startTime.size(); i++)
    {
        if (i == 0)
        {
            timeslot.push_back(startTime[i] - 0);
        }
        else if (i == startTime.size())
        {
            timeslot.push_back(eventTime - endTime[i - 1]);
        }
        else
        {
            timeslot.push_back(startTime[i] - endTime[i - 1]);
        }
    }
    int n = timeslot.size();
    int first = 0;
    int result = 0, total_time = 0;
    for (int last = 0; last < n; last++)
    {
        total_time += timeslot[last];
        result = max(result, total_time);
        if (last - first == k)
        {
            total_time -= timeslot[first];
            first++;
        }
    }
    return result;
}

/// <summary>
/// Leet Code 3440. Reschedule Meetings for Maximum Free Time II
///   
/// Medium
/// 
/// You are given an integer eventTime denoting the duration of an event. You 
/// are also given two integer arrays startTime and endTime, each of length n.
///
/// These represent the start and end times of n non-overlapping meetings that 
/// occur during the event between time t = 0 and time t = eventTime, where 
/// the ith meeting occurs during the time [startTime[i], endTime[i]].
///
/// You can reschedule at most one meeting by moving its start time while 
/// maintaining the same duration, such that the meetings remain '
/// non-overlapping, to maximize the longest continuous period of free time 
/// during the event.
///
/// Return the maximum amount of free time possible after rearranging the 
/// meetings.
///
/// Note that the meetings can not be rescheduled to a time outside the event 
/// and they should remain non-overlapping.
///
/// Note: In this version, it is valid for the relative ordering of the 
/// meetings to change after rescheduling one meeting.
/// 
/// Example 1:
/// Input: eventTime = 5, startTime = [1,3], endTime = [2,5]
/// Output: 2
/// Explanation:
/// Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during 
/// the time [0, 2].
///
/// Example 2:
/// Input: eventTime = 10, startTime = [0,7,9], endTime = [1,8,10]
/// Output: 7
/// Explanation:
/// Reschedule the meeting at [0, 1] to [8, 9], leaving no meetings during 
/// the time [0, 7].
///
/// Example 3:
/// Input: eventTime = 10, startTime = [0,3,7,9], endTime = [1,4,8,10]
/// Output: 6
/// Explanation:
/// Reschedule the meeting at [3, 4] to [8, 9], leaving no meetings during 
/// the time [1, 7].
///
/// Example 4:
/// Input: eventTime = 5, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
/// Output: 0
/// Explanation:
/// There is no time during the event not occupied by meetings.
/// 
/// Constraints:
/// 1. 1 <= eventTime <= 10^9
/// 2. n == startTime.length == endTime.length
/// 3. 2 <= n <= 10^5
/// 4. 0 <= startTime[i] < endTime[i] <= eventTime
/// 5. endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].
/// </summary>
int LeetCodeGreedy::maxFreeTimeII(int eventTime, vector<int>& startTime, vector<int>& endTime)
{
    vector<int> timeslot;
    for (size_t i = 0; i <= startTime.size(); i++)
    {
        if (i == 0)
        {
            timeslot.push_back(startTime[i] - 0);
        }
        else if (i == startTime.size())
        {
            timeslot.push_back(eventTime - endTime[i - 1]);
        }
        else
        {
            timeslot.push_back(startTime[i] - endTime[i - 1]);
        }
    }
    set<pair<int, int>> free_time;
    int n = timeslot.size();
    for (int i = 0; i < n; i++) free_time.insert(make_pair(timeslot[i], i));
    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        free_time.erase(make_pair(timeslot[i], i));
        free_time.erase(make_pair(timeslot[i+1], i+1));
        auto itr = free_time.lower_bound(make_pair(endTime[i] - startTime[i], 0));
        if (itr == free_time.end())
        {
            result = max(result, timeslot[i] + timeslot[i + 1]);
        }
        else
        {
            result = max(result, timeslot[i] + timeslot[i + 1] + endTime[i] - startTime[i]);
        }
        free_time.insert(make_pair(timeslot[i], i));
        free_time.insert(make_pair(timeslot[i + 1], i + 1));
    }
    return result;
}

/// <summary>
/// Leet Code 3468. Find the Number of Copy Arrays
///
/// Medium
/// 
/// You are given an array original of length n and a 2D array bounds of 
/// length n x 2, where bounds[i] = [ui, vi].
///
/// You need to find the number of possible arrays copy of length n such that:
///
/// (copy[i] - copy[i - 1]) == (original[i] - original[i - 1]) for 
/// 1 <= i <= n - 1.
/// ui <= copy[i] <= vi for 0 <= i <= n - 1.
/// Return the number of such arrays.
///
/// Example 1:
/// Input: original = [1,2,3,4], bounds = [[1,2],[2,3],[3,4],[4,5]]
/// Output: 2
/// Explanation:
/// The possible arrays are:
/// [1, 2, 3, 4]
/// [2, 3, 4, 5]
///
/// Example 2:
/// Input: original = [1,2,3,4], bounds = [[1,10],[2,9],[3,8],[4,7]]
/// Output: 4
/// Explanation:
/// The possible arrays are:
/// [1, 2, 3, 4]
/// [2, 3, 4, 5]
/// [3, 4, 5, 6]
/// [4, 5, 6, 7]
///
/// Example 3:
/// Input: original = [1,2,1,2], bounds = [[1,1],[2,3],[3,3],[2,3]]
/// Output: 0
/// Explanation:
/// No array is possible.
/// 
/// Constraints:
/// 1. 2 <= n == original.length <= 10^5
/// 2. 1 <= original[i] <= 10^9
/// 3. bounds.length == n
/// 4. bounds[i].length == 2
/// 5. 1 <= bounds[i][0] <= bounds[i][1] <= 10^9
/// </summary>
int LeetCodeGreedy::countArrays(vector<int>& original, vector<vector<int>>& bounds)
{
    int start = 0, end = 0;
    for (size_t i = 0; i < bounds.size(); i++)
    {
        if (i == 0)
        {
            start = bounds[i][0];
            end = bounds[i][1];
        }
        else
        {
            start += original[i] - original[i - 1];
            end += original[i] - original[i - 1];
            start = max(start, bounds[i][0]);
            end = min(end, bounds[i][1]);
        }
    }
    return max(0, (end - start + 1));
}

/// <summary>
/// Leet Code 3542. Minimum Operations to Convert All Elements to Zero
///
/// Medium
///
/// You are given an array nums of size n, consisting of non-negative 
/// integers. Your task is to apply some (possibly zero) operations on the 
/// array so that all elements become 0.
///
/// In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) 
/// and set all occurrences of the minimum non-negative integer in that 
/// subarray to 0.
///
/// Return the minimum number of operations required to make all elements in 
/// the array 0.
/// 
/// Example 1:
/// Input: nums = [0,2]
/// Output: 1
/// Explanation:
/// Select the subarray [1,1] (which is [2]), where the minimum non-negative 
/// integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
/// Thus, the minimum number of operations required is 1.
///
/// Example 2:
/// Input: nums = [3,1,2,1]
/// Output: 3
/// Explanation:
/// Select subarray [1,3] (which is [1,2,1]), where the minimum non-negative 
/// integer is 1. Setting all occurrences of 1 to 0 results in [3,0,2,0].
/// Select subarray [2,2] (which is [2]), where the minimum non-negative 
/// integer is 2. Setting all occurrences of 2 to 0 results in [3,0,0,0].
/// Select subarray [0,0] (which is [3]), where the minimum non-negative 
/// integer is 3. Setting all occurrences of 3 to 0 results in [0,0,0,0].
/// Thus, the minimum number of operations required is 3.
///
/// Example 3:
/// Input: nums = [1,2,1,2,1,2]
/// Output: 4
/// Explanation:
/// Select subarray [0,5] (which is [1,2,1,2,1,2]), where the minimum non-
/// negative integer is 1. Setting all occurrences of 1 to 0 results in 
/// [0,2,0,2,0,2].
/// Select subarray [1,1] (which is [2]), where the minimum non-negative 
/// integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,2,0,2].
/// Select subarray [3,3] (which is [2]), where the minimum non-negative 
/// integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,2].
/// Select subarray [5,5] (which is [2]), where the minimum non-negative 
/// integer is 2. Setting all occurrences of 2 to 0 results in [0,0,0,0,0,0].
/// Thus, the minimum number of operations required is 4.
/// 
/// Constraints:
/// 1. 1 <= n == nums.length <= 10^5
/// 2. 0 <= nums[i] <= 10^5
/// </summary>
int LeetCodeGreedy::minOperations(vector<int>& nums)
{
    vector<pair<int, int>> sorted_nums;
    for (size_t i = 0; i < nums.size(); i++)
    {
        sorted_nums.push_back({ nums[i], i });
    }
    sort(sorted_nums.begin(), sorted_nums.end());

    set<pair<int, int>> ranges;
    ranges.insert({ 0, nums.size() - 1 });
    int result = 0;
    for (size_t i = 0; i < sorted_nums.size(); i++)
    {
        int pos = sorted_nums[i].second;
        auto itr = ranges.lower_bound({ pos, 0 });
        if (itr == ranges.end() || itr->first > pos)
        {
            itr = prev(itr);
        }
        vector<pair<int, int>> split;
        int prev = itr->first;
        size_t j = i;
        while (j < sorted_nums.size())
        {
            int pos = sorted_nums[j].second;
            if (prev < pos)
            {
                split.push_back({ prev, pos - 1 });
            }
            prev = pos + 1;
            j++;
            if (j >= sorted_nums.size() || 
                sorted_nums[j].first != sorted_nums[j - 1].first ||
                sorted_nums[j].second > itr->second)
            {
                break;
            }
        }
        i = j - 1;
        if (prev <= itr->second)
        {
            split.push_back({ prev, itr->second });
        }
        ranges.erase(itr);
        ranges.insert(split.begin(), split.end());
        if (sorted_nums[i].first > 0)
        {
            result++;
        }
    }
    
    return result;
}
#pragma endregion
