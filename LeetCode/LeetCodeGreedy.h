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

#pragma endregion
};
#endif  // LeetCodeGreedy_H
