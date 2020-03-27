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
/// LeetCode #56. Merge Intervals
/// Given a collection of intervals, merge all overlapping intervals.
/// For example,
/// Given [1,3],[2,6],[8,10],[15,18]
/// return [1,6],[8,10],[15,18]. 
/// </summary>
vector<Interval> LeetCode::mergeIntervals(vector<Interval>& intervals)
{
    vector<Interval> result;
    typedef struct
    {
        bool operator() (Interval a, Interval b)
        {
            return (a.start > b.start);
        }
    } greater_start;
    priority_queue<Interval, vector<Interval>, greater_start> queue;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        queue.push(intervals[i]);
    }
    while (!queue.empty())
    {
        Interval first = queue.top();
        queue.pop();
        if (queue.empty())
        {
            result.push_back(first);
            continue;
        }
        Interval second = queue.top();
        queue.pop();
        if (first.end >= second.start)
        {
            first.end = max(first.end, second.end);
            queue.push(first);
        }
        else
        {
            queue.push(second);
            result.push_back(first);
        }
    }
    return result;
}

/// <summary>
/// Leet code #57. Insert Interval   
/// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
/// You may assume that the intervals were initially sorted according to their start times.
///
/// Example 1:
/// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 
///
/// Example 2:
/// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16]. 
/// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
/// </summary>
vector<Interval> LeetCode::insertInterval(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> result;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        Interval interval = intervals[i];
        if (interval.end < newInterval.start)
        {
            result.push_back(interval);
        }
        else if (newInterval.end < interval.start)
        {
            result.push_back(newInterval);
            newInterval = interval;
        }
        else
        {
            newInterval.start = min(interval.start, newInterval.start);
            newInterval.end = max(interval.end, newInterval.end);
        }
    }
    result.push_back(newInterval);
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
int LeetCode::minPatches(vector<int>& nums, int n)
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
int LeetCode::findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital)
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
int LeetCode::minMeetingRooms(vector<Interval>& intervals)
{
    struct IntervalCompare
    {
        bool operator() (Interval &a, Interval &b)
        {
            if (a.start < b.start) return true;
            else if ((a.start == b.start) && (a.end < b.end)) return true;
            else return false;
        }
    };
    sort(intervals.begin(), intervals.end(), IntervalCompare());
    vector<int> ends;
    int max_rooms = 0;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        int count = 1;
        for (size_t j = 0; j < i; j++)
        {
            if (intervals[i].start < intervals[j].end)
            {
                count++;
            }
        }
        max_rooms = max(max_rooms, count);
    }
    return max_rooms;
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
int LeetCode::minMeetingRoomsII(vector<Interval>& intervals)
{
    map<int, int> time_line;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        time_line[intervals[i].start]++;
        time_line[intervals[i].end]--;
    }
    int max_rooms = 0, rooms = 0;
    for (auto time : time_line)
    {
        rooms += time.second;
        max_rooms = max(max_rooms, rooms);
    }
    return max_rooms;
}

/// <summary>
/// Leet code #435. Non-overlapping Intervals
///
/// Given a collection of intervals, find the minimum number of intervals 
/// you need to remove to make the rest of the intervals non-overlapping. 
/// Note:
/// You may assume the interval's end point is always bigger than its start point.
/// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
///
/// Example 1:
/// Input: [ [1,2], [2,3], [3,4], [1,3] ]
/// Output: 1
/// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
/// Example 2:
/// Input: [ [1,2], [1,2], [1,2] ]
/// Output: 2
/// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
/// Example 3:
/// Input: [ [1,2], [2,3] ]
/// Output: 0
/// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
/// </summary>
int LeetCode::eraseOverlapIntervals(vector<Interval>& intervals)
{
    int count = 0;
    struct IntervalCompare
    {
        bool operator() (const Interval& a, const Interval& b)
        {
            if (a.end < b.end)
            {
                return true;
            }
            else if ((a.end == b.end) && (a.start > b.start))
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
    Interval last;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (i == 0)
        {
            last = intervals[i];
        }
        else
        {
            if (intervals[i].start < last.end) count++;
            else
            {
                last = intervals[i];
            }
        }
    }
    return count;
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
vector<int> LeetCode::findRightInterval(vector<Interval>& intervals)
{
    vector<int> result;
    map<int, int> range_order;
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (range_order.find(intervals[i].start) == range_order.end())
        {
            range_order[intervals[i].start] = i;
        }
    }
    for (size_t i = 0; i < intervals.size(); i++)
    {
        map<int, int>::iterator itr = range_order.lower_bound(intervals[i].end);
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
/// There are a number of spherical balloons spread in two-dimensional space. 
/// For each balloon, provided input is the start and end coordinates of the 
/// horizontal diameter. Since it's horizontal, y-coordinates don't matter 
/// and hence the x-coordinates of start and end of the diameter suffice. 
/// Start is always smaller than end. There will be at most 104 balloons.
///
/// An arrow can be shot up exactly vertically from different points along 
/// the x-axis. A balloon with xstart and xend bursts by an arrow shot at x 
/// if xstart ≤ x ≤ xend. There is no limit to the number of arrows that 
/// can be shot. An arrow once shot keeps travelling up infinitely. 
/// The problem is to find the minimum number of arrows that must be 
/// shot to burst all balloons. 
/// Example: 
/// Input:
/// [[10,16], [2,8], [1,6], [7,12]]
/// Output:
/// 2
/// Explanation:
/// One way is to shoot one arrow for example at x = 6 (bursting the balloons 
/// [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
/// </summary>
int LeetCode::findMinArrowShots(vector<pair<int, int>>& points)
{
    int count = 0;
    set<pair<int, int>> range_set;
    for (pair<int, int> point : points)
    {
        range_set.insert(point);
    }
    while (!range_set.empty())
    {
        set<pair<int, int>>::iterator itr = range_set.begin();
        pair<int, int> curr = *itr;
        itr++;
        if (itr == range_set.end())
        {
            count++;
            range_set.erase(curr);
        }
        else
        {
            pair<int, int> next = *itr;
            if (next.first <= curr.second)
            {
                pair<int, int> intersection = make_pair(max(curr.first, next.first), min(curr.second, next.second));
                range_set.erase(curr);
                range_set.erase(next);
                range_set.insert(intersection);
            }
            else
            {
                count++;
                range_set.erase(curr);
            }
        }
    }
    return count;
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
vector<vector<int>> LeetCode::getSkyline(vector<vector<int>>& buildings)
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
    for (auto edge : edge_map)
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
/// Leet code #252. Meeting Rooms   
/// 
/// Given an array of meeting time intervals consisting of start and end times 
/// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings. 
/// distance between these two words in the list. 
/// For example,
/// Given [[0, 30],[5, 10],[15, 20]]. 
/// return false. 
/// </summary>
bool LeetCode::canAttendMeetings(vector<Interval>& intervals)
{
    struct IntervalCompare
    {
        bool operator() (Interval &a, Interval &b)
        {
            if (a.start < b.start) return true;
            else if ((a.start == b.start) && (a.end < b.end)) return true;
            else return false;
        }
    };
    sort(intervals.begin(), intervals.end(), IntervalCompare());
    for (size_t i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start < intervals[i - 1].end)
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
vector<string> LeetCode::findMissingRanges(vector<int>& nums, int lower, int upper)
{
    vector<string> result;
    long long expect = (long long)lower;
    long long end;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if ((long long)nums[i] > expect)
        {
            end = (long long)nums[i] - 1;
            if (expect == end)
            {
                result.push_back(to_string(expect));
            }
            else if (expect < end)
            {
                result.push_back(to_string(expect) + "->" + to_string(end));
            }
        }
        expect = (long long)nums[i] + 1;
    }
    if (expect <= (long long)upper)
    {
        end = (long long)upper;
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
/// In LLP world, there is a hero called Teemo and his attacking can make his enemy 
/// Ashe be in poisoned condition. Now, given the Teemo's attacking ascending time 
/// series towards Ashe and the poisoning time duration per Teemo's attacking, you 
/// need to output the total time that Ashe is in poisoned condition. 
///
/// You may assume that Teemo attacks at the very beginning of a specific time point, 
/// and makes Ashe be in poisoned condition immediately.
/// 
/// Example 1: 
/// Input: [1,4], 2
/// Output: 4
/// Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned immediately. 
/// This poisoned status will last 2 seconds until the end of time point 2. 
/// And at time point 4, Teemo attacks Ashe again, and causes Ashe to be in poisoned status for another 2 seconds. 
/// So you finally need to output 4.
///
/// Example 2:
/// Input: [1,2], 2
/// Output: 3
/// Explanation: At time point 1, Teemo starts attacking Ashe and makes Ashe be poisoned. 
/// This poisoned status will last 2 seconds until the end of time point 2. 
/// However, at the beginning of time point 2, Teemo attacks Ashe again who is already in poisoned status. 
/// Since the poisoned status won't add up together, though the second poisoning attack will still work at 
/// time point 2, it will stop at the end of time point 3. 
/// So you finally need to output 3.
///
/// Note:
/// 1.You may assume the length of given time series array won't exceed 10000.
/// 2.You may assume the numbers in the Teemo's attacking time series and his 
///   poisoning time duration per attacking are non-negative integers, which 
///   won't exceed 10,000,000.
/// </summary>
int LeetCode::findPoisonedDuration(vector<int>& timeSeries, int duration)
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
int LeetCode::leastBricks(vector<vector<int>>& wall)
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
    for (auto itr : align_map)
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
int LeetCode::maxCount(int m, int n, vector<vector<int>>& ops)
{
    pair<int, int> result = make_pair(m, n);
    for (auto range : ops)
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
int LeetCode::leastInterval(vector<char>& tasks, int n)
{
    int result = 0;
    unordered_map<char, int> task_count;
    priority_queue<pair<int, int>> task_queue;
    for (char task : tasks)  task_count[task]++;

    for (auto itr : task_count)
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
int LeetCode::scheduleCourse(vector<vector<int>>& courses)
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
int LeetCode::findLongestChain(vector<vector<int>>& pairs)
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
/// </summary>
map<int, int>::iterator LeetCode::findLocation(map<int, int>& pos_map, int pos)
{
    auto itr = pos_map.lower_bound(pos);
    if (itr == pos_map.end() || itr->first > pos) itr--;
    return itr;
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
vector<int> LeetCode::fallingSquares(vector<pair<int, int>>& positions)
{
    vector<int> result;
    // remember the start position and height
    map<int, int> pos_map;
    pos_map[0] = 0;
    int max_height = 0;
    for (size_t i = 0; i < positions.size(); i++)
    {
        auto start = findLocation(pos_map, positions[i].first);
        auto end = findLocation(pos_map, positions[i].first + positions[i].second);
        int end_height = end->second;
        int height = 0;
        while (start != pos_map.end() && start->first < positions[i].first + positions[i].second)
        {
            auto temp = start++;
            height = max(height, temp->second);
            if (temp->first >= positions[i].first)
            {
                pos_map.erase(temp);
            }
        }
        // add height on this box
        height += positions[i].second;
        // set start as new height
        pos_map[positions[i].first] = height;
        // set next to end as its original height
        pos_map[positions[i].first + positions[i].second] = end_height;
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
int LeetCode::intersectionSizeTwo(vector<vector<int>>& intervals)
{
    int result = 0;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> no_contain_intervals;
    // remove containers
    for (size_t i = 0; i < intervals.size(); i++)
    {
        if (no_contain_intervals.empty())
        {
            no_contain_intervals.push_back(intervals[i]);
        }
        else
        {
            vector<int> last_interval = no_contain_intervals.back();
            if ((last_interval[0] <= intervals[i][0]) && (last_interval[1] >= intervals[i][1]))
            {
                no_contain_intervals.pop_back();
                i--;
            }
            else if ((last_interval[0] >= intervals[i][0]) && (last_interval[1] <= intervals[i][1]))
            {
                continue;
            }
            else
            {
                no_contain_intervals.push_back(intervals[i]);
            }
        }
    }

    // harvest numbers
    vector<int> last_interval(2);
    for (size_t i = 0; i < no_contain_intervals.size(); i++)
    {
        if (i == 0)
        {
            result += 2;
            last_interval[0] = no_contain_intervals[i][1] - 1;
            last_interval[1] = no_contain_intervals[i][1];
        }
        else
        {
            // no overlap
            if (last_interval[1] < no_contain_intervals[i][0])
            {
                result += 2;
                last_interval[0] = no_contain_intervals[i][1] - 1;
                last_interval[1] = no_contain_intervals[i][1];
            }
            // next overlap current
            else if (last_interval[0] < no_contain_intervals[i][0])
            {
                result += 1;
                last_interval[0] = last_interval[1];
                last_interval[1] = no_contain_intervals[i][1];
            }
        }
    }

    return result;
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
vector<Interval> LeetCode::employeeFreeTime(vector<vector<Interval>>& schedule)
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
    for (auto itr : time_map)
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
int LeetCode::rectangleArea(vector<vector<int>>& rectangles)
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
    for (auto r : rectangles)
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
int LeetCode::bagOfTokensScore(vector<int>& tokens, int P)
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
string LeetCode::strWithout3a3b(int A, int B)
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
vector<Interval> LeetCode::intervalIntersection(vector<Interval>& A, vector<Interval>& B)
{
    int i = 0, j = 0;
    vector<Interval> result;

    while (i < (int)A.size() && j < (int)B.size())
    {
        if (A[i].end < B[j].start)
        {
            i++;
        }
        else if (B[j].end < A[i].start)
        {
            j++;
        }
        else
        {
            Interval intersection = 
            { 
                max(A[i].start, B[j].start), min(A[i].end, B[j].end) 
            };
            result.push_back(intersection);
            if (A[i].end < B[j].end)
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
int LeetCode::videoStitching(vector<vector<int>>& clips, int T)
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
vector<int> LeetCode::rearrangeBarcodes(vector<int>& barcodes)
{
    priority_queue<pair<int, int>> code_heap;
    unordered_map<int, int> code_count;
    for (size_t i = 0; i < barcodes.size(); i++)
    {
        code_count[barcodes[i]]++;
    }
    for (auto itr : code_count)
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
bool LeetCode::carPooling(vector<vector<int>>& trips, int capacity)
{
    map<int, int> stops;
    for (size_t i = 0; i < trips.size(); i++)
    {
        stops[trips[i][1]] += trips[i][0];
        stops[trips[i][2]] -= trips[i][0];
    }
    int result = 0;
    for (auto itr : stops)
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
vector<int> LeetCode::corpFlightBookings(vector<vector<int>>& bookings, int n)
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
string LeetCode::rearrangeString(string s, int k)
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
int LeetCode::arrangeOperations(vector<vector<int>> operations)
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
    for (auto itr : time_line)
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

#pragma endregion
