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
/// The next K lines will each contain the integers 1…N in some order, 
/// indicating the rankings of the cows (cows are identified by the numbers 
/// 1…N). If A appears before B in one of these lines, that means cow A did 
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
                rank[id - 1] = j;
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
int main(int argc, char* argv[])
{
    Gymnastics::process("", "gymnastics");
    return 0;
}