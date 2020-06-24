#pragma once
#ifndef USACO_H
#define USACO_H
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
#include <thread>
#include <mutex>
#include <iostream>
#include <fstream>
using namespace std;
/// <summary>
/// USACO 2013 January Contest, Bronze
/// 
/// Problem 3: Liars and Truth Tellers [Brian Dean, 2013]
///
/// After spending so much time around his cows, Farmer John has started to
/// understand their language.  Moreover, he notices that among his N cows 
/// (2 <= N <= 1000), some always tell the truth while others always lie.
///
/// FJ carefully listens to M statements (1 <= M <= 10,000) from his cows, each
/// of the form "x y T", meaning that "cow x claims cow y always tells the
/// truth" or "x y L", meaning that "cow x claims cow y always tells lies". 
/// Each statement involves a pair of different cows, and the same pair of cows
/// may appear in multiple statements.  
/// 
/// Unfortunately, FJ believes he might have written down some entries in his
/// list incorrectly, so there may not be a valid way to designate each cow as
/// a truth teller or a liar that is consistent with all the M statements on
/// FJ's list.  To help FJ salvage as much of his list as possible, please
/// compute the largest value of A such that there exists a valid way to
/// designate each cow as a truth teller or a liar in a manner that is
/// consistent with the first A entries in FJ's list.
///
/// PROBLEM NAME: truth
///
/// INPUT FORMAT:
///
/// * Line 1: Two space-separated integers, N and M.
///
/// * Lines 2..1+M: Each line is of the form "x y L" or "x y T",
///        describing a statement made by cow x about cow y.
///
/// SAMPLE INPUT (file truth.in):
///
/// 4 3
/// 1 4 L
/// 2 3 T
/// 4 1 T
///
/// INPUT DETAILS:
///
/// There are 4 cows and 3 statements.  Cow 1 says that cow 4 lies, cow 2 says
/// that cow 3 tells the truth, and cow 4 says that cow 1 tells the truth.
///
/// OUTPUT FORMAT:
///
/// * Line 1: The maximum value of A such that the first A entries in FJ's
///        list can be consistent with some assignment of "truth teller"
///        or "liar" to the N cows.
///
/// SAMPLE OUTPUT (file truth.out):
///
/// 2
/// 
/// OUTPUT DETAILS:
///
/// Statements 1 and 3 cannot both be satisfied at the same time, but
/// statements 1 and 2 can be, if we let cows 1..3 tell the truth and cow 4 be
/// a liar.
/// </summary>
class Truth
{
private:
    static int find_root(unordered_map<int, int>& component, int id)
    {
        if (component.count(id) == 0)
        {
            component[id] = id;
            component[-id] = -id;
        }
        else
        {
            while (component[id] != id) id = component[id];
        }
        return id;
    }
    static void merge(unordered_map<int, int>& component, int x, int y)
    {
        component[y] = x;
        component[-y] = -x;
    }
public:
    static void process(string folder)
    {
        ifstream fin(folder + "truth.in");
        int N, M;
        fin >> N >> M;
        vector<pair<pair<int, int>, char>> truths(M);
        for (int i = 0; i < M; i++)
        {
            fin >> truths[i].first.first >> truths[i].first.second >> truths[i].second;
        }
        fin.close();
        int result = 0;
        unordered_map<int, int> component;
        for (int i = 0; i < M; i++)
        {
            int first = truths[i].first.first;
            int second = truths[i].first.second;
            int x = find_root(component, first);
            int y = find_root(component, second);
            if ((truths[i].second == 'T' && x == -y) ||
                (truths[i].second == 'L' && x == y))
            {
                break;
            }
            else if (truths[i].second == 'T')
            {
                merge(component, x, y);
            }
            else
            {
                merge(component, x, -y);
            }
            result++;
        }
        ofstream fout(folder + "truth.out", std::ofstream::out | std::ofstream::trunc);
        fout << to_string(result) << endl;
        fout.close();
    }
};

/// <summary>
/// USACO 2019 December Contest, Bronze
/// 
/// Problem 1. Cow Gymnastics
/// In order to improve their physical fitness, the cows have taken up 
/// gymnastics! Farmer John designates his favorite cow Bessie to coach the N 
/// other cows and to assess their progress as they learn various gymnastic 
/// skills.
/// In each of K practice sessions (1<=K<=10), Bessie ranks the N cows according 
/// to their performance (1<=N<=20). Afterward, she is curious about the 
/// consistency in these rankings. A pair of two distinct cows is consistent 
/// if one cow did better than the other one in every practice session.
///
/// Help Bessie compute the total number of consistent pairs.
///
/// INPUT FORMAT (file gymnastics.in):
/// The first line of the input file contains two positive integers K and N. 
/// The next K lines will each contain the integers 1...N in some order, 
/// indicating the rankings of the cows (cows are identified by the numbers 
/// 1...N). If A appears before B in one of these lines, that means cow A did 
/// better than cow B.
/// OUTPUT FORMAT (file gymnastics.out):
/// Output, on a single line, the number of consistent pairs.
/// SAMPLE INPUT:
/// 3 4
/// 4 1 2 3
/// 4 1 3 2
/// 4 2 1 3
/// SAMPLE OUTPUT:
/// 4
/// The consistent pairs of cows are (1,4), (2,4), (3,4), and (1,3).
/// </summary>
class Gymnastics
{
    
public:
    static void process(string folder, string filename)
    {
        ifstream fin(folder + filename + ".in");
        int N, M;
        fin >> N >> M;
        vector<vector<int>> dp(M, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            vector<int> rank(M);
            for (int j = 0; j < M; j++)
            {
                int id;
                fin >> id;
                rank[id-1] = j;
            }
            for (int j = 0; j < M; j++)
            {
                for (int k = j + 1; k < M; k++)
                {
                    if (rank[j] > rank[k])
                    {
                        if (dp[j][k] == -1) dp[j][k] = 2;
                        else if (dp[j][k] == 0) dp[j][k] = 1;
                    }
                    else
                    {
                        if (dp[j][k] == 1) dp[j][k] = 2;
                        else if (dp[j][k] == 0) dp[j][k] = -1;
                    }
                }
            }
        }
        fin.close();
        int result = 0;
        for (int j = 0; j < M; j++)
        {
            for (int k = j + 1; k < M; k++)
            {
                if (dp[j][k] != 2) result++;
            }
        }
        ofstream fout(folder + filename + ".out", std::ofstream::out | std::ofstream::trunc);
        fout << to_string(result) << endl;
        fout.close();
    }
};

#endif  // USACO_H
