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
    int findPoisonedDuration(vector<int>& timeSeries, int duration);

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
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital);

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
    int leastBricks(vector<vector<int>>& wall);

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
    int maxCount(int m, int n, vector<vector<int>>& ops);

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
    int leastInterval(vector<char>& tasks, int n);

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
    int scheduleCourse(vector<vector<int>>& courses);

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
    int findLongestChain(vector<vector<int>>& pairs);

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
    vector<int> fallingSquares(vector<vector<int>>& positions);

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
    int intersectionSizeTwo(vector<vector<int>>& intervals);

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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule);

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
    int rectangleArea(vector<vector<int>>& rectangles);

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
    int bagOfTokensScore(vector<int>& tokens, int P);

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
    string strWithout3a3b(int A, int B);

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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B);

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
    int videoStitching(vector<vector<int>>& clips, int T);

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
    vector<int> rearrangeBarcodes(vector<int>& barcodes);

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
    bool carPooling(vector<vector<int>>& trips, int capacity);

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
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n);

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
    /// 2. 2 <= n <= 105
    /// 3. 1 <= nums[i] <= limit <= 105
    /// 4. n is even.
    /// </summary>
    int minMoves(vector<int>& nums, int limit);

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
    int arrangeOperations(vector<vector<int>> operations);

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
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents);

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
    int maximumPopulation(vector<vector<int>>& logs);

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
    bool isCovered(vector<vector<int>>& ranges, int left, int right);

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
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments);

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
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength);

#pragma endregion
};
#endif  // LeetCodeGreedy_H
