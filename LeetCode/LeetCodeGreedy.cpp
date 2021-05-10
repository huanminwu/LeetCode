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
/// if x.start ≤ x ≤ x.end. There is no limit to the number of arrows that 
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
/// can croak at the same time, so multiple “croak” are mixed. Return 
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
    vector<int> croak_map(26);
    string str = "croak";
    for (size_t i = 0; i < str.size(); i++)
    {
        croak_map[str[i] - 'a'] = i;
    }
    int frog_count = 0;
    int result = 0;
    for (size_t i = 0; i < croakOfFrogs.size(); i++)
    {
        if (croakOfFrogs[i] == 'c')
        {
            frog_count++;
            croak_count[0]++;
            result = max(result, frog_count);
        }
        else
        {
            int ord = croak_map[croakOfFrogs[i] - 'a'];
            if (croak_count[ord - 1] == 0) return -1;
            croak_count[ord - 1]--;
            if (croakOfFrogs[i] == 'k')
            {
                frog_count--;
            }
            else
            {
                croak_count[ord]++;
            }
        }
    }
    for (size_t i = 0; i < 5; i++)
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
#pragma endregion
