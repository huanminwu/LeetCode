#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeUnionFind.h"
#include "TestUnionFind.h"
void TestLeetCode9903(void)
{
    Logger::WriteMessage("Test Leet Code 9903");
    LeetCodeUnionFind leetCode;
    vector<vector<double>> radar = { { 1,1,1 },{ 1.5, 3, 1.2 } ,{ 10, 1, 2 } };
    Logger::WriteMessage(radar);
    bool result = leetCode.canAvoidRadar(4, radar);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " Avoid Radar.");
    radar = { { 1,1,1 },{ 2, 3, 1.2 } ,{ 10, 1, 2 } };
    Logger::WriteMessage(radar);
    result = leetCode.canAvoidRadar(4, radar);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " Avoid Radar.");
}

void TestLeetCode305(void)
{
    Logger::WriteMessage("Test Leet Code 305");
    LeetCodeUnionFind leetCode;

    int m = 3, n = 3;
    vector<pair<int, int>> positions = { {0, 0},{0, 1},{1, 2},{2, 1} };
    vector<int> result = leetCode.numIslands2(m, n, positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    m = 3, n = 3;
    positions = { { 0, 1 },{ 1, 2 },{ 2, 1 }, {1, 0},{0, 2},{0, 0},{1, 1} };
    result = leetCode.numIslands2(m, n, positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);
}

void TestLeetCode547(void)
{
    LeetCodeUnionFind leetCode;
    vector<vector<int>> relation = { { 1, 1, 0 },{ 1, 1, 0 },{ 0, 0, 1 } };
    int num_circles = leetCode.findCircleNum(relation);
    Logger::WriteMessage(relation);
    Logger::WriteMessage("Number of Circles = " + to_string(num_circles));

    relation = { { 1, 1, 0 },{ 1, 1, 1 },{ 0, 1, 1 } };
    num_circles = leetCode.findCircleNum(relation);
    Logger::WriteMessage(relation);
    Logger::WriteMessage("Number of Circles = " + to_string(num_circles));
}

void TestLeetCode695(void)
{
    LeetCodeUnionFind leetCode;
    vector<vector<int>> grid =
    {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    int max_area = leetCode.maxAreaOfIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("area = " + to_string(max_area));

    grid =
    {
        {0,0,0,0,0,0,0,0},
    };
    max_area = leetCode.maxAreaOfIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("area = " + to_string(max_area));
}

void TestLeetCode721(void)
{
    LeetCodeUnionFind leetCode;

    vector<vector<string>> accounts =
    {
        { "John", "johnsmith@mail.com", "john00@mail.com" },
        { "John", "johnnybravo@mail.com" },
        { "John", "johnsmith@mail.com",	"john_newyork@mail.com" },
        { "Mary", "mary@mail.com" }
    };

    vector<vector<string>> result = leetCode.accountsMergeII(accounts);
    Logger::WriteMessage(accounts);
    Logger::WriteMessage(result);

    accounts =
    {
        { "David", "David0@m.co", "David1@m.co" },
        { "David", "David3@m.co", "David4@m.co" },
        { "David", "David4@m.co", "David5@m.co" },
        { "David", "David2@m.co", "David3@m.co" },
        { "David", "David1@m.co", "David2@m.co" }
    };

    result = leetCode.accountsMergeII(accounts);
    Logger::WriteMessage(accounts);
    Logger::WriteMessage(result);

    accounts =
    {
        {"David", "David4@m.co", "David2@m.co", "David4@m.co"},
        {"John", "John7@m.co", "John5@m.co", "John3@m.co"},
        {"Fern", "Fern6@m.co", "Fern4@m.co", "Fern5@m.co"},
        {"Celine", "Celine0@m.co", "Celine7@m.co", "Celine7@m.co"},
        {"Gabe", "Gabe8@m.co", "Gabe8@m.co", "Gabe1@m.co"},
        {"Ethan", "Ethan1@m.co", "Ethan6@m.co", "Ethan6@m.co"},
        {"Celine", "Celine4@m.co", "Celine8@m.co", "Celine6@m.co"},
        {"Celine", "Celine0@m.co", "Celine0@m.co", "Celine4@m.co"}
    };
    result = leetCode.accountsMergeII(accounts);
    Logger::WriteMessage(accounts);
    Logger::WriteMessage(result);
}

void TestLeetCode827(void)
{
    Logger::WriteMessage("Test Leet Code 827");
    LeetCodeUnionFind leetCode;
    vector<vector<int>> grid = { {1, 0}, {0, 1} };
    int result = leetCode.largestIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 1},{1, 0} };
    result = leetCode.largestIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 1, 1 },{ 1, 1 } };
    result = leetCode.largestIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { { 0, 1 },{ 0, 0 } };
    result = leetCode.largestIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode803(void)
{
    Logger::WriteMessage("Test Leet Code 803");
    LeetCodeUnionFind leetCode;
    vector<vector<int>> grid = { { 1, 0, 0, 0 },{ 1, 1, 1, 0 } };
    vector<vector<int>> hits = { { 1,0 } };
    vector<int> result = leetCode.hitBricks(grid, hits);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(hits);
    Logger::WriteMessage(result);

    grid = { { 1, 0, 1 },{ 1, 1, 1 } };
    hits = { { 0, 0 },{ 0, 2 }, { 1, 1 } };
    result = leetCode.hitBricks(grid, hits);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(hits);
    Logger::WriteMessage(result);
}

void TestLeetCode737(void)
{
    LeetCodeUnionFind leetCode;
    vector<string> word1 = { "great", "acting", "skills" };
    vector<string> word2 = { "fine", "drama", "talent" };
    vector<pair<string, string>> pairs = { { "great", "good" },{ "fine", "good" },{ "acting", "drama" },{ "skills","talent" } };

    bool result = leetCode.areSentencesSimilarTwo(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar" : "not similar"));

    word1 = { "great" };
    word2 = { "great" };
    pairs = {};
    result = leetCode.areSentencesSimilarTwo(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar" : "not similar"));

    word1 = { "great" };
    word2 = { "doubleplus","good" };
    pairs = {};
    result = leetCode.areSentencesSimilarTwo(word1, word2, pairs);
    Logger::WriteMessage(word1);
    Logger::WriteMessage(word2);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage((string)(result ? "similar" : "not similar"));
};

void TestLeetCode839(void)
{
    Logger::WriteMessage("Test Leet Code 839");
    LeetCodeUnionFind leetCode;
    vector<string> A = { "tars", "rats", "arts", "star" };
    int result = leetCode.numSimilarGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode947(void)
{
    Logger::WriteMessage("Test Leet Code 947");
    LeetCodeUnionFind leetCode;
    vector<vector<int>> stones =
    {
        {5, 9},{9, 0},{0, 0},{7, 0},{4, 3},{8, 5},{5, 8},{1, 1},{0, 6},{7, 5},
        {1, 6},{1, 9},{9, 4},{2, 8},{1, 3},{4, 2},{2, 5},{4, 1},{0, 2},{6, 5}
    };
    int result = leetCode.removeStones(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { { 0,0 },{ 0,1 },{ 1,0 },{ 1,2 },{ 2,1 },{ 2,2 } };
    result = leetCode.removeStones(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { {0,0},{0,2},{1,1},{2,0},{2,2} };
    result = leetCode.removeStones(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));

    stones = { { 0,0 } };
    result = leetCode.removeStones(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));


    stones = { {0, 1},{1, 2},{1, 3},{3, 3},{2, 3 }, { 0, 2 } };
    result = leetCode.removeStones(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode952(void)
{
    Logger::WriteMessage("Test Leet Code 952");
    LeetCodeUnionFind leetCode;
    vector<int> A = { 4,6,15,35 };
    int result = leetCode.largestComponentSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 20,50,9,63 };
    result = leetCode.largestComponentSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,3,6,7,4,12,21,39 };
    result = leetCode.largestComponentSize(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode990(void)
{
    Logger::WriteMessage("Test Leet Code 990");
    LeetCodeUnionFind leetCode;
    vector<string> equations = { "a==b","b!=a" };
    bool result = leetCode.equationsPossible(equations);
    Logger::WriteMessage(equations);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    equations = { "b==a","a==b" };
    result = leetCode.equationsPossible(equations);
    Logger::WriteMessage(equations);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    equations = { "a==b", "b==c", "a==c" };
    result = leetCode.equationsPossible(equations);
    Logger::WriteMessage(equations);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    equations = { "a==b","b!=c","c==a" };
    result = leetCode.equationsPossible(equations);
    Logger::WriteMessage(equations);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    equations = { "c==c","b==d","x!=z" };
    result = leetCode.equationsPossible(equations);
    Logger::WriteMessage(equations);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1061(void)
{
    Logger::WriteMessage("Test Leet Code 1061");
    LeetCodeUnionFind leetCode;
    string A = "parker";
    string B = "morris";
    string S = "parser";
    string result = leetCode.smallestEquivalentString(A, B, S);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; S = " + S + "; result = " + result);

    A = "hello";
    B = "world";
    S = "hold";
    result = leetCode.smallestEquivalentString(A, B, S);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; S = " + S + "; result = " + result);

    A = "leetcode";
    B = "programs";
    S = "sourcecode";
    result = leetCode.smallestEquivalentString(A, B, S);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; S = " + S + "; result = " + result);
}

void TestLeetCode1101(void)
{
    Logger::WriteMessage("Test Leet Code 1101");
    LeetCodeUnionFind leetCode;
    vector<vector<int>> logs =
    {
        {20190101, 0, 1},{20190104, 3, 4},{20190107, 2, 3},{20190211, 1, 5},
        {20190224, 2, 4},{20190301, 0, 3},{20190312, 1, 2},{20190322, 4, 5}
    };
    int N = 6;
    int result = leetCode.earliestAcq(logs, N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    logs =
    {
        {20190101, 0, 1},{20190104, 3, 4},{20190107, 2, 3},{20190211, 1, 5},
        {20190224, 2, 4}
    };
    N = 6;
    result = leetCode.earliestAcq(logs, N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1202(void)
{
    Logger::WriteMessage("Test Leet Code 1202");
    LeetCodeUnionFind leetCode;
    string s = "dcab";
    vector<vector<int>> pairs = { {0, 3},{ 1, 2} };
    string result = leetCode.smallestStringWithSwaps(s, pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "dcab";
    pairs = { {0, 3},{1, 2},{0, 2} };
    result = leetCode.smallestStringWithSwaps(s, pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "cba";
    pairs = { {0, 1},{1, 2} };
    result = leetCode.smallestStringWithSwaps(s, pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCodeUnionFind(void)
{
    TestLeetCode305();
    TestLeetCode547();
    TestLeetCode695();
    TestLeetCode721();
    TestLeetCode737();
    TestLeetCode803();
    TestLeetCode827();
    TestLeetCode839();
    TestLeetCode947();
    TestLeetCode952();
    TestLeetCode990();
    TestLeetCode1061();
    TestLeetCode1101();
    TestLeetCode9903();
}


