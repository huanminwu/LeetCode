#pragma once
#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeBFS.h"
#include "TestBFS.h"

void TestLeetCode1197(void)
{
    Logger::WriteMessage("Test Leet Code 1197");
    LeetCodeBFS leetCode;
    int x = 2;
    int y = 1;
    int result = leetCode.minKnightMoves(x, y);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + to_string(result));

    x = 5;
    y = 5;
    result = leetCode.minKnightMoves(x, y);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + to_string(result));

    x = 300;
    y = 0;
    result = leetCode.minKnightMoves(x, y);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + to_string(result));
}

void TestLeetCode1215(void)
{
    Logger::WriteMessage("Test Leet Code 1215");
    LeetCodeBFS leetCode;
    int low = 0;
    int high = 1000;
    vector<int> result = leetCode.countSteppingNumbers(low, high);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high));
    Logger::WriteMessage(result);
}

void TestLeetCode1284(void)
{
    Logger::WriteMessage("Test Leet Code 1284");
    LeetCodeBFS leetCode;
    vector<vector<int>> mat = { {0, 0},{0, 1} };
    int result = leetCode.minFlips(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat =  {{ 0 }};
    result = leetCode.minFlips(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat = { {1, 1, 1},{1, 0, 1},{0, 0, 0} };
    result = leetCode.minFlips(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat = { {1, 0, 0},{1, 0, 0} };
    result = leetCode.minFlips(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat = { {0}, {1}, {1} };
    result = leetCode.minFlips(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1334(void)
{
    Logger::WriteMessage("Test Leet Code 1334");
    LeetCodeBFS leetCode;
    int n = 4;
    vector<vector<int>> edges = { {0, 1, 3},{1, 2, 1},{1, 3, 4},{2, 3, 1} };
    int distanceThreshold = 4;
    int result = leetCode.findTheCity(n, edges, distanceThreshold);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; distanceThreshold = " + to_string(distanceThreshold)
    + "; result = " + to_string(result));

    n = 5;
    edges = { {0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1} };
    distanceThreshold = 2;
    result = leetCode.findTheCity(n, edges, distanceThreshold);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; distanceThreshold = " + to_string(distanceThreshold)
        + "; result = " + to_string(result));
}

void TestLeetCodeBFS(void)
{
    TestLeetCode1334();
    TestLeetCode1284();
    TestLeetCode1215();
    TestLeetCode1197();
}