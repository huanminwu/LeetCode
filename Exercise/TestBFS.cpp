#pragma once
#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeBFS.h"
#include "TestBFS.h"
void TestLeetCode542(void)
{
    LeetCodeBFS leetCode;
    vector<vector<int>> matrix = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    Logger::WriteMessage(matrix);
    vector<vector<int>> result = leetCode.updateMatrix(matrix);
    Logger::WriteMessage(result);

    matrix = { { 0, 0, 0 },{ 0, 1, 0 },{ 1, 1, 1 } };
    Logger::WriteMessage(matrix);
    result = leetCode.updateMatrix(matrix);
    Logger::WriteMessage(result);
}

void TestLeetCode864(void)
{
    Logger::WriteMessage("Test Leet Code 864");
    LeetCodeBFS leetCode;
    vector<string> grid = { "@.a.#","###.#","b.A.B" };
    int result = leetCode.shortestPathAllKeys(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { "@..aA","..B#.","....b" };
    result = leetCode.shortestPathAllKeys(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { ".@aA" };
    result = leetCode.shortestPathAllKeys(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { "@...a", ".###A", "b.BCc" };
    result = leetCode.shortestPathAllKeys(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode882(void)
{
    Logger::WriteMessage("Test Leet Code 882");
    LeetCodeBFS leetCode;
    int M = 6;
    int N = 3;
    vector<vector<int>> edges = { { 0,1,10 },{ 0,2,1 },{ 1,2,2 } };
    int result = leetCode.reachableNodes(edges, M, N);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("M = " + to_string(M) + "; N = " + to_string(N) + "; result = " + to_string(result));

    M = 10;
    N = 4;
    edges = { { 0,1,4 },{ 1,2,6 },{ 0,2,8 }, { 1,3,1 } };
    result = leetCode.reachableNodes(edges, M, N);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("M = " + to_string(M) + "; N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode909(void)
{
    Logger::WriteMessage("Test Leet Code 909");
    LeetCodeBFS leetCode;
    vector<vector<int>> board =
    {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };
    int result = leetCode.snakesAndLadders(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode924(void)
{
    Logger::WriteMessage("Test Leet Code 924");
    LeetCodeBFS leetCode;

    vector<vector<int>> graph = { { 1, 0, 0, 0 },{ 0, 1, 0, 0 },{ 0, 0, 1, 1 }, { 0, 0, 1, 1 } };
    vector<int> initial = { 3, 1 };
    int result = leetCode.minMalwareSpread(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1, 1, 0 },{ 1, 1, 0 },{ 0, 0, 1 } };
    initial = { 0, 1 };
    result = leetCode.minMalwareSpread(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 } };
    initial = { 0, 2 };
    result = leetCode.minMalwareSpread(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1, 1, 1 },{ 1, 1, 1 },{ 1, 1, 1 } };
    initial = { 1, 2 };
    result = leetCode.minMalwareSpread(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode928(void)
{
    Logger::WriteMessage("Test Leet Code 928");
    LeetCodeBFS leetCode;
    vector<vector<int>> graph =
    {
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 }
    }
    ;
    vector<int> initial = { 3, 8 };
    int result = leetCode.minMalwareSpreadII(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1, 1, 0 },{ 1, 1, 0 },{ 0, 0, 1 } };
    initial = { 0, 1 };
    result = leetCode.minMalwareSpreadII(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1, 1, 0 },{ 1, 1, 1 },{ 0, 1, 1 } };
    initial = { 0, 1 };
    result = leetCode.minMalwareSpreadII(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1,1,0,0 },{ 1,1,1,0 },{ 0,1,1,1 }, { 0,0,1,1 } };
    initial = { 0, 1 };
    result = leetCode.minMalwareSpreadII(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { { 1, 1, 1 },{ 1, 1, 1 },{ 1, 1, 1 } };
    initial = { 1, 2 };
    result = leetCode.minMalwareSpreadII(graph, initial);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(initial);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode934(void)
{
    Logger::WriteMessage("Test Leet Code 934");
    LeetCodeBFS leetCode;
    vector<vector<int>> A = { {0, 1},{1, 0} };
    Logger::WriteMessage(A);
    int result = leetCode.shortestBridge(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { {0,1,0},{0,0,0},{0,0,1} };
    Logger::WriteMessage(A);
    result = leetCode.shortestBridge(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { {1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1} };
    Logger::WriteMessage(A);
    result = leetCode.shortestBridge(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode967(void)
{
    Logger::WriteMessage("Test Leet Code 967");
    LeetCodeBFS leetCode;
    int N = 3;
    int K = 7;
    vector<int> result = leetCode.numsSameConsecDiff(N, K);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K));
    Logger::WriteMessage(result);

    N = 2;
    K = 1;
    result = leetCode.numsSameConsecDiff(N, K);
    Logger::WriteMessage("N = " + to_string(N) + "; K = " + to_string(K));
    Logger::WriteMessage(result);
}

void TestLeetCode994(void)
{
    Logger::WriteMessage("Test Leet Code 994");
    LeetCodeBFS leetCode;
    vector<vector<int>> grid = { {2, 1, 1},{1, 1, 0},{0, 1, 1} };
    int result = leetCode.orangesRotting(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {2,1,1},{0,1,1},{1,0,1} };
    result = leetCode.orangesRotting(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0,2} };
    result = leetCode.orangesRotting(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0} };
    result = leetCode.orangesRotting(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1020(void)
{
    Logger::WriteMessage("Test Leet Code 1020");
    LeetCodeBFS leetCode;
    vector<vector<int>> A = { {0, 0, 0, 0},{1, 0, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0} };
    Logger::WriteMessage(A);
    int result = leetCode.numEnclaves(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { {0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0} };
    Logger::WriteMessage(A);
    result = leetCode.numEnclaves(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1030(void)
{
    Logger::WriteMessage("Test Leet Code 1030");
    LeetCodeBFS leetCode;
    int R = 1, C = 2, r0 = 0, c0 = 0;
    vector<vector<int>> result = leetCode.allCellsDistOrder(R, C, r0, c0);
    Logger::WriteMessage("R = " + to_string(R) + "; C = " + to_string(C) +
        "; r0 = " + to_string(r0) + "; c0 = " + to_string(c0));
    Logger::WriteMessage(result);

    R = 2, C = 2, r0 = 0, c0 = 1;
    result = leetCode.allCellsDistOrder(R, C, r0, c0);
    Logger::WriteMessage("R = " + to_string(R) + "; C = " + to_string(C) +
        "; r0 = " + to_string(r0) + "; c0 = " + to_string(c0));
    Logger::WriteMessage(result);

    R = 2, C = 3, r0 = 1, c0 = 2;
    result = leetCode.allCellsDistOrder(R, C, r0, c0);
    Logger::WriteMessage("R = " + to_string(R) + "; C = " + to_string(C) +
        "; r0 = " + to_string(r0) + "; c0 = " + to_string(c0));
    Logger::WriteMessage(result);
}

void TestLeetCode1034(void)
{
    Logger::WriteMessage("Test Leet Code 1034");
    LeetCodeBFS leetCode;
    vector<vector<int>> grid = { {1, 1},{1, 2} };
    int r0 = 0;
    int c0 = 0;
    int color = 3;
    vector<vector<int>> result = leetCode.colorBorder(grid, r0, c0, color);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("r0 = " + to_string(r0) + "; c0 = " + to_string(c0) +
        "; color = " + to_string(color));
    Logger::WriteMessage(result);

    grid = { {1,2,2},{2,3,2} };
    r0 = 0;
    c0 = 1;
    color = 3;
    result = leetCode.colorBorder(grid, r0, c0, color);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("r0 = " + to_string(r0) + "; c0 = " + to_string(c0) +
        "; color = " + to_string(color));
    Logger::WriteMessage(result);

    grid = { {1, 1, 1},{1, 1, 1},{1, 1, 1} };
    r0 = 1;
    c0 = 1;
    color = 2;
    result = leetCode.colorBorder(grid, r0, c0, color);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("r0 = " + to_string(r0) + "; c0 = " + to_string(c0) +
        "; color = " + to_string(color));
    Logger::WriteMessage(result);
}

void TestLeetCode1042(void)
{
    Logger::WriteMessage("Test Leet Code 1042");
    LeetCodeBFS leetCode;
    int N = 3;
    vector<vector<int>> paths = { {1, 2},{2, 3},{3, 1} };
    vector<int> result = leetCode.gardenNoAdj(N, paths);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);

    N = 4;
    paths = { {1, 2},{3, 4} };
    result = leetCode.gardenNoAdj(N, paths);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);

    N = 4;
    paths = { {1, 2},{2, 3},{3, 4},{4, 1},{1, 3},{2, 4} };
    result = leetCode.gardenNoAdj(N, paths);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);

    N = 4;
    paths = { {3, 4},{4, 2},{3, 2},{1, 3} };
    result = leetCode.gardenNoAdj(N, paths);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);
}

void TestLeetCode1091(void)
{
    Logger::WriteMessage("Test Leet Code 1091");
    LeetCodeBFS leetCode;
    vector<vector<int>> grid = { {0, 1},{1, 0} };
    Logger::WriteMessage(grid);
    int result = leetCode.shortestPathBinaryMatrix(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 0, 0},{1, 1, 0},{1, 1, 0} };
    Logger::WriteMessage(grid);
    result = leetCode.shortestPathBinaryMatrix(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1162(void)
{
    Logger::WriteMessage("Test Leet Code 1162");
    LeetCodeBFS leetCode;
    vector<vector<int>> grid = { {1, 0, 1},{0, 0, 0},{1, 0, 1} };
    int result = leetCode.maxLandDistance(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 0, 0},{0, 0, 0},{0, 0, 0} };
    result = leetCode.maxLandDistance(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 0, 0},{0, 0, 0},{0, 0, 0} };
    result = leetCode.maxLandDistance(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 1, 1},{1, 1, 1},{1, 1, 1} };
    result = leetCode.maxLandDistance(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

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

void TestLeetCode818(void)
{
    Logger::WriteMessage("Test Leet Code 818");
    LeetCodeBFS leetCode;
    vector<string> banned = { "hit" };
    int target = 20;
    int result = leetCode.racecar(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = 11;
    result = leetCode.racecar(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = 4;
    result = leetCode.racecar(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = 6;
    result = leetCode.racecar(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode854(void)
{
    Logger::WriteMessage("Test Leet Code 854");
    LeetCodeBFS leetCode;
    string A = "ab";
    string B = "ba";
    int result = leetCode.kSimilarity(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + to_string(result));

    A = "abc";
    B = "bca";
    result = leetCode.kSimilarity(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + to_string(result));

    A = "abac";
    B = "baca";
    result = leetCode.kSimilarity(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + to_string(result));

    A = "aabc";
    B = "abca";
    result = leetCode.kSimilarity(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + to_string(result));
}

void TestLeetCode733(void)
{
    LeetCodeBFS leetCode;
    vector<vector<int>> image = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = leetCode.floodFill(image, sr, sc, newColor);
    Logger::WriteMessage(image);
    Logger::WriteMessage(result);

    image = { { 0, 0, 0 },{ 0, 1, 1 } };
    sr = 1, sc = 1, newColor = 1;
    result = leetCode.floodFill(image, sr, sc, newColor);
    Logger::WriteMessage(image);
    Logger::WriteMessage(result);

    image = { { 0, 0, 1 },{ 0, 1, 1 } };
    sr = 1, sc = 1, newColor = 1;
    result = leetCode.floodFill(image, sr, sc, newColor);
    Logger::WriteMessage(image);
    Logger::WriteMessage(result);
};


void TestLeetCode752(void)
{
    Logger::WriteMessage("Test Leet Code 752");
    LeetCodeBFS leetCode;
    vector<string> deadends = { "0201", "0101", "0102", "1212", "2002" };
    string target = "0202";
    int result = leetCode.openLock(deadends, target);
    Logger::WriteMessage(deadends);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    deadends = { "8888" };
    target = "0009";
    result = leetCode.openLock(deadends, target);
    Logger::WriteMessage(deadends);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    deadends = { "8887","8889","8878","8898","8788","8988","7888", "9888" };
    target = "8888";
    result = leetCode.openLock(deadends, target);
    Logger::WriteMessage(deadends);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));

    deadends = { "0000" };
    target = "8888";
    result = leetCode.openLock(deadends, target);
    Logger::WriteMessage(deadends);
    Logger::WriteMessage("target = " + target + "; result = " + to_string(result));
}

void TestLeetCode773(void)
{
    Logger::WriteMessage("Test Leet Code 773");
    LeetCodeBFS leetCode;
    vector<vector<int>> board = { {1, 2, 3},{4, 0, 5} };
    int result = leetCode.slidingPuzzle(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {1, 2, 3},{5, 4, 0} };
    result = leetCode.slidingPuzzle(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {4, 1, 2},{5, 0, 3} };
    result = leetCode.slidingPuzzle(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {3, 2, 4},{1, 5, 0} };
    result = leetCode.slidingPuzzle(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode690(void)
{
    LeetCodeBFS leetCode;
    vector<Employee> employees_raw = { {1, 5,{2, 3} }, {2, 3,{}}, {3, 3, {}} };
    vector<Employee *> employees;
    for (size_t i = 0; i < employees_raw.size(); i++)
    {
        employees.push_back(&employees_raw[i]);
    }

    int result = leetCode.getImportance(employees, 1);
    Logger::WriteMessage("Result = " + to_string(result));
}

void TestLeetCode433(void)
{
    Logger::WriteMessage("Test Leet Code 433");
    LeetCodeBFS leetCode;
    string start = "AACCGGTT";
    string end = "AACCGGTA";
    vector<string> bank = { "AACCGGTA" };
    int result = leetCode.minMutation(start, end, bank);
    Logger::WriteMessage(bank);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + to_string(result));

    start = "AACCGGTT";
    end = "AAACGGTA";
    bank = { "AACCGGTA", "AACCGCTA", "AAACGGTA" };
    result = leetCode.minMutation(start, end, bank);
    Logger::WriteMessage(bank);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + to_string(result));

    start = "AAAAACCC";
    end = "AACCCCCC";
    bank = { "AAAACCCC", "AAACCCCC", "AACCCCCC" };
    result = leetCode.minMutation(start, end, bank);
    Logger::WriteMessage(bank);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + to_string(result));
}

void TestLeetCode200(void)
{
    Logger::WriteMessage("Test Leet Code 200");
    LeetCodeBFS leetCode;
    vector<string> map = { "1111111","0000001","1111101","1000101","1010101","1011101","1111111" };

    vector<vector<char>> grid;
    Logger::WriteMessage("The grid is:");
    for (size_t i = 0; i < map.size(); i++)
    {
        Logger::WriteMessage(map[i].c_str());
        grid.push_back(vector<char>());
        for (size_t j = 0; j < map[i].size(); j++)
        {
            grid[i].push_back(map[i][j]);
        }
    }
    int numIslands = leetCode.numIslands(grid);
    std::string message;
    message.assign("The number of island is ");
    message.append(std::to_string(numIslands));
    Logger::WriteMessage(message.c_str());

    string test2[4] = { "11000", "11000", "00100", "00011" };
    grid.clear();
    Logger::WriteMessage("The grid is:");
    for (size_t i = 0; i < sizeof(test2) / sizeof(test2[0]); i++)
    {
        Logger::WriteMessage(test2[i].c_str());
        grid.push_back(vector<char>());
        for (size_t j = 0; j < test2[i].size(); j++)
        {
            grid[i].push_back(test2[i][j]);
        }
    }
    numIslands = leetCode.numIslands(grid);
    message.assign("The number of island is ");
    message.append(std::to_string(numIslands));
    Logger::WriteMessage(message.c_str());

    string test3[20] = {
        "11111110111111111111",
        "11111101110101011111",
        "11111111111000111100",
        "10101111010101101111",
        "10111111011001110111",
        "01111101101001110111",
        "11111111011101011111",
        "11111011111010101011",
        "01111111010110111001",
        "01000111111011101010",
        "01111111110000111111",
        "10110111111111110101",
        "11111101011010111111",
        "11111111111011111110",
        "11010111011111111111",
        "11111101110111011001",
        "10111111111100111111",
        "10011100110111001111",
        "11101100010011110011",
        "11111111011111110101"
    };
    grid.clear();
    Logger::WriteMessage("The grid is:");
    for (size_t i = 0; i < sizeof(test3) / sizeof(test3[0]); i++)
    {
        Logger::WriteMessage(test3[i].c_str());
        grid.push_back(vector<char>());
        for (size_t j = 0; j < test3[i].size(); j++)
        {
            grid[i].push_back(test3[i][j]);
        }
    }
    numIslands = leetCode.numIslands(grid);
    message.assign("The number of island is ");
    message.append(std::to_string(numIslands));
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode302(void)
{
    Logger::WriteMessage("Test Leet Code 302");
    LeetCodeBFS leetCode;
    vector<vector<char>> image =
    {
        { '0', '0', '1', '0' },
        { '0', '1', '1', '0' },
        { '0' ,'1', '0', '0' },
    };
    Logger::WriteMessage(image);
    int min_area = leetCode.minArea(image, 0, 2);
    Logger::WriteMessage("min_area = " + to_string(min_area));
}

void TestLeetCode130(void)
{
    Logger::WriteMessage("Test Leet Code 130");
    LeetCodeBFS leetCode;
    vector<vector<char>> board =
    {
        {'X', 'X', 'X', 'X' },
        {'X', 'O', 'O', 'X' },
        {'X', 'X', 'O', 'X' },
        {'X', 'O', 'X', 'X' }
    };
    leetCode.solveSurrounding(board);
    Logger::WriteMessage(board);
}

void TestLeetCode127(void)
{
    Logger::WriteMessage("Test Leet Code 127");
    LeetCodeBFS leetCode;

    unordered_set<string> wordList = { "hot","dot","dog","lot","log" };
    vector<string> words;
    for (string x : wordList) words.push_back(x);
    Logger::WriteMessage(words);
    string beginWord;
    string endWord;
    int step;
    beginWord = "hit";
    endWord = "cog";
    step = leetCode.wordLadderLength(beginWord, endWord, wordList);
    Logger::WriteMessage("The step from " + beginWord + " to " + endWord + " is " + to_string(step));
}

void TestLeetCode417(void)
{
    Logger::WriteMessage("Test Leet Code 417");
    LeetCodeBFS leetCode;
    vector<vector<int>> matrix =
    {
        { 1, 2, 2, 3, 5 },
        { 3, 2, 3, 4, 4 },
        { 2, 4, 5, 3, 1 },
        { 6, 7, 1, 4, 5 },
        { 5, 1, 1, 2, 4 }
    };
    vector<pair<int, int>> result = leetCode.pacificAtlantic(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);

    matrix =
    {
        { 1, 2, 3 },
        { 8, 9, 4 },
        { 7, 6, 5 }
    };

    result = leetCode.pacificAtlantic(matrix);
    Logger::WriteMessage(matrix);
    Logger::WriteMessage(result);
}

void TestLeetCode1391(void)
{
    Logger::WriteMessage("Test Leet Code 1391");
    LeetCodeBFS leetCode;
    vector<vector<int>> grid =
    {
        {2,4,3},{6,5,2}
    };
    bool result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    grid =
    {
        {1,2,1},{1,2,1}
    };
    result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {1,1,2}
    };
    result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {1,1,1,1,1,1,3}
    };
    result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {2},{2},{2},{2},{2},{2},{6}
    };
    result = leetCode.hasValidPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1871(void)
{
    Logger::WriteMessage("Test Leet Code 1871");
    LeetCodeBFS leetCode;
    string s = "011010";
    int minJump = 2;
    int maxJump = 3;
    bool result = leetCode.canReach(s, minJump, maxJump);
    Logger::WriteMessage("s = " + s +
        "; minJump = " + to_string(minJump) +
        "; maxJump = " + to_string(maxJump) +
        "; result = " + (string)(result ? "true" : "false"));

    s = "01101110";
    minJump = 2;
    maxJump = 3;
    result = leetCode.canReach(s, minJump, maxJump);
    Logger::WriteMessage("s = " + s +
        "; minJump = " + to_string(minJump) +
        "; maxJump = " + to_string(maxJump) +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2014(void)
{
    Logger::WriteMessage("Test Leet Code 2014");
    LeetCodeBFS leetCode;
    string s = "letsleetcode";
    int k = 2;
    string result = leetCode.longestSubsequenceRepeatedK(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);

    s = "bb";
    k = 2;
    result = leetCode.longestSubsequenceRepeatedK(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);

    s = "ab";
    k = 2;
    result = leetCode.longestSubsequenceRepeatedK(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);
 
    s = "bbabbabbbbabaababab";
    k = 3;
    result = leetCode.longestSubsequenceRepeatedK(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);
}

void TestLeetCodeBFS(void)
{
    TestLeetCode773();
    TestLeetCode2014();
    TestLeetCode1871();
    TestLeetCode1391();
    TestLeetCode127();
    TestLeetCode130();
    TestLeetCode200();
    TestLeetCode302();
    TestLeetCode417();
    TestLeetCode433();
    TestLeetCode542();
    TestLeetCode690();
    TestLeetCode733();
    TestLeetCode743();
    TestLeetCode752();
    TestLeetCode864();
    TestLeetCode882();
    TestLeetCode909();
    TestLeetCode924();
    TestLeetCode928();
    TestLeetCode934();
    TestLeetCode967();
    TestLeetCode994();
    TestLeetCode1020();
    TestLeetCode1030();
    TestLeetCode1034();
    TestLeetCode1042();
    TestLeetCode1091();
    TestLeetCode1162();
    TestLeetCode1334();
    TestLeetCode1284();
    TestLeetCode1215();
    TestLeetCode1197();
}