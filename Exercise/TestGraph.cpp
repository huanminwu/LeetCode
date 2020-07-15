#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeGraph.h"
#include "TestGraph.h"
void TestLeetCode133(void)
{
    Logger::WriteMessage("Test Leet Code 133");
    LeetCodeGraph leetCode;
    vector<pair<int, vector<int>>> graph_list;
    UndirectedGraphNode* root, * new_root;

    graph_list = { {-1, {1}}, {1, {}} };
    root = leetCode.generateGraphNode(graph_list);
    Logger::WriteMessage(root);
    new_root = leetCode.cloneGraph(root);
    leetCode.freeGraphNodes(root);
    Logger::WriteMessage(new_root);
    leetCode.freeGraphNodes(new_root);

    graph_list = { {0, { 1, 2 }},{1, { 2 }},{2, { 2 }} };
    root = leetCode.generateGraphNode(graph_list);
    Logger::WriteMessage(root);
    new_root = leetCode.cloneGraph(root);
    leetCode.freeGraphNodes(root);
    Logger::WriteMessage(new_root);
    leetCode.freeGraphNodes(new_root);
}

void TestLeetCode207(void)
{
    Logger::WriteMessage("Test Leet Code 207");
    LeetCodeGraph leetCode;
    vector<pair<int, int>> prerequisites;
    int numCourses;
    bool canFinish;
    numCourses = 2;
    prerequisites = { { 0, 1 } };
    Logger::WriteMessage(prerequisites);
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage("Can finish all course: " + string(canFinish ? "true" : "false"));

    numCourses = 3;
    prerequisites = { { 0, 1 }, {1, 2} };
    Logger::WriteMessage(prerequisites);
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage("Can finish all course: " + string(canFinish ? "true" : "false"));

    numCourses = 3;
    prerequisites = { { 0, 1 },{ 0, 2 } };
    Logger::WriteMessage(prerequisites);
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage("Can finish all course: " + string(canFinish ? "true" : "false"));

    numCourses = 3;
    prerequisites = { { 0, 1 },{ 1, 2 }, {2, 0 } };
    Logger::WriteMessage(prerequisites);
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage("Can finish all course: " + string(canFinish ? "true" : "false"));

    numCourses = 0;
    prerequisites = {};
    Logger::WriteMessage(prerequisites);
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage("Can finish all course: " + string(canFinish ? "true" : "false"));
}

void TestLeetCode210(void)
{
    Logger::WriteMessage("Test Leet Code 210");
    LeetCodeGraph leetCode;
    vector<pair<int, int>> prerequisites;
    vector<int> result;
    int numCourses;
    numCourses = 4;
    prerequisites = { {1, 0},{2, 0},{3, 1},{3, 2} };
    result = leetCode.findOrder(numCourses, prerequisites);
    Logger::WriteMessage(result);
}

void TestLeetCode261(void)
{
    Logger::WriteMessage("Test Leet Code 261");
    LeetCodeGraph leetCode;
    vector<pair<int, int>> edges = { { 0, 1 },{ 0, 2 },{ 2, 3 },{ 2, 4 } };
    int n = 5;
    bool result = leetCode.validTree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "a valid tree.");

    edges = { {0, 1},{0, 2},{0, 3},{1, 4} };
    n = 5;
    result = leetCode.validTree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "a valid tree.");

    edges = { {0, 1}, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 4 } };
    n = 5;
    result = leetCode.validTree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "a valid tree.");

    edges = { {0, 1},{1, 2},{3, 4} };
    n = 5;
    result = leetCode.validTree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "a valid tree.");
}

void TestLeetCode269(void)
{
    Logger::WriteMessage("Test Leet Code 269");
    LeetCodeGraph leetCode;
    vector<string> words = { "wrt", "wrf", "er", "ett", "rftt" };
    string result = leetCode.alienOrder(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("aline order = " + result);

    words = { "wrtkj", "wrt" };
    result = leetCode.alienOrder(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("aline order = " + result);

    words = { "ab", "adc" };
    result = leetCode.alienOrder(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("aline order = " + result);

    words = { "a", "b", "a" };
    result = leetCode.alienOrder(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("aline order = " + result);

    words = { "za", "zb", "ca", "cb" };
    result = leetCode.alienOrder(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("aline order = " + result);
}

void TestLeetCode277(void)
{
    Logger::WriteMessage("Test Leet Code 277");
    LeetCodeGraph leetCode;
    vector<vector<bool>> relation_map = { { true, false, true }, {true, true, true }, { false, false, true} };
    int n = 3;
    int celebrity = leetCode.findCelebrity(n, relation_map);;
    Logger::WriteMessage("celebrity = " + to_string(celebrity));
}

void TestLeetCode286(void)
{
    Logger::WriteMessage("Test Leet Code 286");
    LeetCodeGraph leetCode;
    vector<vector<int>> rooms =
    {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };
    Logger::WriteMessage(rooms);
    leetCode.wallsAndGates(rooms);
    Logger::WriteMessage(rooms);

    rooms =
    {
        { INT_MAX }
    };
    Logger::WriteMessage(rooms);
    leetCode.wallsAndGates(rooms);
    Logger::WriteMessage(rooms);
}

void TestLeetCode296(void)
{
    Logger::WriteMessage("Test Leet Code 296");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        { 1, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
    };

    Logger::WriteMessage(grid);
    int min_distance = leetCode.minTotalDistance(grid);
    Logger::WriteMessage("min_distance = " + to_string(min_distance));
}

void TestLeetCode310(void)
{
    Logger::WriteMessage("Test Leet Code 310");
    LeetCodeGraph leetCode;
    vector<pair<int, int>> edges = { {1, 0},{1, 2},{1, 3} };
    int n = 4;
    vector<int> result = leetCode.findMinHeightTrees(4, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
    edges = { { 0, 3 },{ 1, 3 },{ 2, 3 }, {4, 3}, {5, 4} };
    n = 6;
    result = leetCode.findMinHeightTrees(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { };
    n = 1;
    result = leetCode.findMinHeightTrees(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode317(void)
{
    Logger::WriteMessage("Test Leet Code 317");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        { 1, 0, 2, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
    };

    Logger::WriteMessage(grid);
    int min_distance = leetCode.shortestDistance(grid);
    Logger::WriteMessage("min_distance = " + to_string(min_distance));

    grid =
    {
        { 1, 2, 0 }
    };
    Logger::WriteMessage(grid);
    min_distance = leetCode.shortestDistance(grid);
    Logger::WriteMessage("min_distance = " + to_string(min_distance));
}

void TestLeetCode323(void)
{
    Logger::WriteMessage("Test Leet Code 323");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<pair<int, int>> edges = { {0, 1},{1, 2},{3, 4} };
    Logger::WriteMessage(edges);
    int count = leetCode.countComponents(n, edges);
    Logger::WriteMessage("n = " + to_string(n) + "; count = " + to_string(count));

    n = 5;
    edges = { {0, 1},{1, 2},{2, 3},{3, 4} };
    Logger::WriteMessage(edges);
    count = leetCode.countComponents(n, edges);
    Logger::WriteMessage("n = " + to_string(n) + "; count = " + to_string(count));
}

void TestLeetCode332(void)
{
    Logger::WriteMessage("Test Leet Code 332");
    LeetCodeGraph leetCode;
    vector<pair<string, string>> tickets = { {"MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"} };
    vector<string> result = leetCode.findItinerary(tickets);
    Logger::WriteMessage(tickets);
    Logger::WriteMessage(result);

    tickets = { { "JFK","SFO" },{ "JFK","ATL" },{ "SFO","ATL" },{ "ATL","JFK" },{ "ATL","SFO" } };
    result = leetCode.findItinerary(tickets);
    Logger::WriteMessage(tickets);
    Logger::WriteMessage(result);

    tickets = { { "JFK", "KUL" },{ "JFK", "NRT" },{ "NRT", "JFK" } };
    result = leetCode.findItinerary(tickets);
    Logger::WriteMessage(tickets);
    Logger::WriteMessage(result);
}

void TestLeetCode399(void)
{
    Logger::WriteMessage("Test Leet Code 399");
    LeetCodeGraph leetCode;
    vector<pair<string, string>> equations = { {"a", "b"},{"b", "c"} };
    vector<double> values = { 2.0, 3.0 };
    vector<pair<string, string>> queries =
    { { "a", "a" }, {"a", "c"},{"b", "a"},{"a", "e"},{"x", "x"} };
    Logger::WriteMessage(equations);
    Logger::WriteMessage(values);
    Logger::WriteMessage(queries);
    vector<double> result = leetCode.calcEquation(equations, values, queries);
    Logger::WriteMessage(result);
}

void TestLeetCode444(void)
{
    Logger::WriteMessage("Test Leet Code 444");
    LeetCodeGraph leetCode;
    vector<int> org = { 1, 2, 3 };
    vector<vector<int>> seqs = { { 1, 2 },{ 1, 3 } };
    bool result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 1, 2, 3 };
    seqs = { { 1, 2 } };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 1, 2, 3 };
    seqs = { {1, 2},{1, 3},{2, 3} };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 4,1,5,2,6,3 };
    seqs = { { 5,2,6,3 },{ 4,1,5,2 } };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");


    org = { 1 };
    seqs = { { },{ } };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 1 };
    seqs = { { },{ } };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 1 };
    seqs = { { } };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 1 };
    seqs = { { 1 }, {1 } };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 1, 2, 3 };
    seqs = { { 1, 2 },{ 2, 3 }, {3, 1} };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");

    org = { 5, 3, 2, 4, 1 };
    seqs = { { 5, 3, 2, 4 },{ 4, 1 },{1},{3},{2, 4},{1, 1000000000} };
    result = leetCode.sequenceReconstruction(org, seqs);
    Logger::WriteMessage(org);
    Logger::WriteMessage(seqs);
    Logger::WriteMessage((string)(result ? "Can " : "Can not ") + "reconstruct sequences");
}

void TestLeetCode407(void)
{
    Logger::WriteMessage("Test Leet Code 407");
    LeetCodeGraph leetCode;
    vector<vector<int>> heightMap =
    {
        { 1,4,3,1,3,2 },
        { 3,2,1,3,2,4 },
        { 2,3,3,2,3,1 }
    };
    int result = leetCode.trapRainWater(heightMap);
    Logger::WriteMessage(heightMap);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode568(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> flights = { { 0, 1, 1 },{ 1, 0, 1 },{ 1, 1, 0 } };
    vector<vector<int>> days = { { 1, 3, 1 },{ 6, 0, 3 },{ 3, 3, 3 } };
    int result = leetCode.maxVacationDays(flights, days);
    Logger::WriteMessage(flights);
    Logger::WriteMessage(days);
    Logger::WriteMessage("result = " + to_string(result));

    flights = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };
    days = { { 1, 1, 1 },{ 7, 7, 7 },{ 7, 7, 7 } };
    result = leetCode.maxVacationDays(flights, days);
    Logger::WriteMessage(flights);
    Logger::WriteMessage(days);
    Logger::WriteMessage("result = " + to_string(result));


    flights = { { 0, 1, 1 },{ 1, 0, 1 },{ 1, 1, 0 } };
    days = { { 7, 0, 0 },{ 0, 7, 0 },{ 0, 0, 7 } };
    result = leetCode.maxVacationDays(flights, days);
    Logger::WriteMessage(flights);
    Logger::WriteMessage(days);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode573(void)
{
    LeetCodeGraph leetCode;
    int height = 5;
    int width = 7;
    vector<int> tree = { 2, 2 };
    vector<int> squirrel = { 4, 4 };
    vector<vector<int>> nuts = { {3, 0}, {2, 5} };
    Logger::WriteMessage("height = " + to_string(height) + "; width = " + to_string(width));
    Logger::WriteMessage(tree);
    Logger::WriteMessage(squirrel);
    Logger::WriteMessage(nuts);
    int distance = leetCode.minDistance(height, width, tree, squirrel, nuts);
    Logger::WriteMessage("distance = " + to_string(distance));
}

void TestLeetCode582(void)
{
    LeetCodeGraph leetCode;
    vector<int> pid = { 1, 3, 10, 5 };
    vector<int> ppid = { 3, 0, 5, 3 };
    int kill = 5;
    vector<int> result = leetCode.killProcess(pid, ppid, kill);
    Logger::WriteMessage(pid);
    Logger::WriteMessage(ppid);
    Logger::WriteMessage("kill = " + to_string(kill));
    Logger::WriteMessage(result);
}

void TestLeetCode675(void)
{
    Logger::WriteMessage("Test Leet Code");
    LeetCodeGraph leetCode;
    vector<vector<int>> forest =
    {
        {1,2,3},
        {0,0,4},
        {5,6,7}
    };
    int result = leetCode.cutOffTree(forest);
    Logger::WriteMessage(forest);
    Logger::WriteMessage("result = " + (string)to_string(result));

    forest =
    {
        { 1,2,3 },
        { 0,0,0 },
        { 7,6,5 }
    };
    result = leetCode.cutOffTree(forest);
    Logger::WriteMessage(forest);
    Logger::WriteMessage("result = " + (string)to_string(result));

    forest =
    {
        { 2,3,4 },
        { 0,0,5 },
        { 8,7,6 }
    };
    result = leetCode.cutOffTree(forest);
    Logger::WriteMessage(forest);
    Logger::WriteMessage("result = " + (string)to_string(result));

    forest =
    {
        {0, 0, 0, 3528, 2256, 9394, 3153},
        { 8740, 1758, 6319, 3400, 4502, 7475, 6812 },
        { 0, 0, 3079, 6312, 0, 0, 0 },
        { 6828, 0, 0, 0, 0, 0, 8145 },
        { 6964, 4631, 0, 0, 0, 4811, 0 },
        { 0, 0, 0, 0, 9734, 4696, 4246 },
        { 3413, 8887, 0, 4766, 0, 0, 0 },
        { 7739, 0, 0, 2920, 0, 5321, 2250 },
        { 3032, 0, 3015, 0, 3269, 8582, 0 }
    };
    result = leetCode.cutOffTree(forest);
    Logger::WriteMessage(forest);
    Logger::WriteMessage("result = " + (string)to_string(result));

    forest =
    {
        { 54581641, 64080174, 24346381, 69107959},
        { 86374198, 61363882, 68783324, 79706116},
        { 668150,   92178815, 89819108, 94701471 },
        { 83920491, 22724204, 46281641, 47531096 },
        { 89078499, 18904913, 25462145, 60813308 }
    };
    result = leetCode.cutOffTree(forest);
    Logger::WriteMessage(forest);
    Logger::WriteMessage("result = " + (string)to_string(result));
}

void TestLeetCode684(void)
{
    Logger::WriteMessage("Test Leet Code 684");
    LeetCodeGraph leetCode;
    vector<vector<int>> edges = { {1,2},{1,3},{2,3} };
    vector<int> result = leetCode.findRedundantConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { {1,2},{2,3},{3,4},{1,4},{1,5} };
    result = leetCode.findRedundantConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);


    edges = { {3, 4},{1, 2},{2, 4},{3, 5},{2, 5} };
    result = leetCode.findRedundantConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode685(void)
{
    Logger::WriteMessage("Test Leet Code 684");
    LeetCodeGraph leetCode;
    vector<vector<int>> edges = { { 1,2 },{ 1,3 },{ 2,3 } };
    vector<int> result = leetCode.findRedundantDirectedConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { { 1,2 },{ 2,3 },{ 3,4 },{ 4,1 },{ 1,5 } };
    result = leetCode.findRedundantDirectedConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);


    edges = { { 3, 4 },{ 1, 2 },{ 2, 4 },{ 3, 5 },{ 2, 3 } };
    result = leetCode.findRedundantDirectedConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { { 2, 1 },{ 3, 1 },{ 4, 2 },{ 1, 4 } };
    result = leetCode.findRedundantDirectedConnection(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode694(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        { 1,1,0,1,1 },
        { 1,0,0,0,0 },
        { 0,0,0,0,1 },
        { 1,1,0,1,1 },
    };
    int distinct_islands = leetCode.numDistinctIslands(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("distinct_islands = " + to_string(distinct_islands));

    grid =
    {
        { 1,1,0,0,0 },
        { 1,1,0,0,0 },
        { 0,0,0,1,1 },
        { 0,0,0,1,1 }
    };
    distinct_islands = leetCode.numDistinctIslands(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("distinct_islands = " + to_string(distinct_islands));
}

void TestLeetCode711(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        { 1,1,0,0,0 },
        { 1,0,0,0,0 },
        { 0,0,0,0,1 },
        { 0,0,0,1,1 },
    };
    int distinct_islands = leetCode.numDistinctIslands2(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("distinct_islands = " + to_string(distinct_islands));

    grid =
    {
        { 1,1,1,0,0 },
        { 1,0,0,0,1 },
        { 0,1,0,0,1 },
        { 0,1,1,1,0 }
    };
    distinct_islands = leetCode.numDistinctIslands2(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("distinct_islands = " + to_string(distinct_islands));

    grid =
    {
        { 0, 1, 1 },
        { 1, 1, 1 },
        { 0, 0, 0 },
        { 1, 1, 1 },
        { 1, 1, 0 }

    };
    distinct_islands = leetCode.numDistinctIslands2(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("distinct_islands = " + to_string(distinct_islands));
}

void TestLeetCode749(void)
{
    Logger::WriteMessage("Test Leet Code 749");
    LeetCodeGraph leetCode;
    vector<vector<int>> grids =
    {
        { 1 }
    };
    Logger::WriteMessage(grids);
    int result = leetCode.containVirus(grids);
    Logger::WriteMessage("result = " + to_string(result));

    grids =
    {
        { 0,1,0,0,0,0,0,1 },
        { 0,1,0,0,0,0,0,1 },
        { 0,0,0,0,0,0,0,1 },
        { 0,0,0,0,0,0,0,0 }
    };
    Logger::WriteMessage(grids);
    result = leetCode.containVirus(grids);
    Logger::WriteMessage("result = " + to_string(result));

    grids =
    {
        { 1, 1, 1 },
        { 1, 0, 1 },
        { 1, 1, 1 }
    };
    Logger::WriteMessage(grids);
    result = leetCode.containVirus(grids);
    Logger::WriteMessage("result = " + to_string(result));

    grids =
    {
        { 1, 1, 1, 0, 0, 0, 0, 0, 0 },
        { 1, 0, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 0, 0, 0 }
    };
    Logger::WriteMessage(grids);
    result = leetCode.containVirus(grids);
    Logger::WriteMessage("result = " + to_string(result));

    grids =
    {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    Logger::WriteMessage(grids);

    result = leetCode.containVirus(grids);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode765(void)
{
    Logger::WriteMessage("Test Leet Code 765");
    LeetCodeGraph leetCode;
    vector<int> row = { 0, 2, 1, 3 };
    Logger::WriteMessage(row);
    int result = leetCode.minSwapsCouples(row);
    Logger::WriteMessage("result = " + to_string(result));

    row = { 3, 2, 0, 1 };
    Logger::WriteMessage(row);
    result = leetCode.minSwapsCouples(row);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode778(void)
{
    Logger::WriteMessage("Test Leet Code 778");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = { {3,2},{0,1} };
    int result = leetCode.swimInWater(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1, 2, 3, 4},{24, 23, 22, 21, 5},{12, 13, 14, 15, 16},{11, 17, 18, 19, 20},{10, 9, 8, 7, 6} };
    result = leetCode.swimInWater(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode785(void)
{
    Logger::WriteMessage("Test Leet Code 785");
    LeetCodeGraph leetCode;
    vector<vector<int>> graph = { {1,3},{0,2},{1,3},{0,2} };
    bool result = leetCode.isBipartite(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    graph = { {1, 2, 3},{0, 2},{0, 1, 3},{0, 2} };
    result = leetCode.isBipartite(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode802(void)
{
    Logger::WriteMessage("Test Leet Code 802");
    LeetCodeGraph leetCode;
    vector<vector<int>> graph = { {1, 2},{2, 3},{5},{0},{5},{},{} };
    vector<int> result = leetCode.eventualSafeNodes(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(result);
}

void TestLeetCode815(void)
{
    Logger::WriteMessage("Test Leet Code 815");
    LeetCodeGraph leetCode;
    vector<vector<int>> routes = { {1, 2, 7}, {3, 6, 7} };
    int S = 1;
    int T = 6;
    int result = leetCode.numBusesToDestination(routes, S, T);
    Logger::WriteMessage(routes);
    Logger::WriteMessage("S = " + to_string(S) + "; T = " + to_string(T) + "; result = " + to_string(result));
}

void TestLeetCode841(void)
{
    Logger::WriteMessage("Test Leet Code 841");
    LeetCodeGraph leetCode;
    vector<vector<int>> rooms = { { 1 }, { 2 }, { 3 }, { } };
    bool result = leetCode.canVisitAllRooms(rooms);
    Logger::WriteMessage(rooms);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    rooms = { { 1, 3 },{ 3, 0, 1 },{ 2 }, { 0 } };
    result = leetCode.canVisitAllRooms(rooms);
    Logger::WriteMessage(rooms);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode847(void)
{
    Logger::WriteMessage("Test Leet Code 847");
    LeetCodeGraph leetCode;
    vector<vector<int>> graph = { {1,2,3},{0},{0}, {0} };
    int result = leetCode.shortestPathLength(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage("result = " + to_string(result));

    graph = { {1},{0, 2, 4},{1, 3, 4},{2},{1, 2} };
    result = leetCode.shortestPathLength(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode851(void)
{
    Logger::WriteMessage("Test Leet Code 851");
    LeetCodeGraph leetCode;
    vector<vector<int>> richer = { {1, 0}, {2, 1}, {3, 1},{3, 7},{4, 3},{5, 3},{6, 3} };
    vector<int> quiet = { 3, 2, 5, 4, 6, 1, 7, 0 };
    vector<int> result = leetCode.loudAndRich(richer, quiet);
    Logger::WriteMessage(richer);
    Logger::WriteMessage(quiet);
    Logger::WriteMessage(result);

}
void TestLeetCode871(void)
{
    Logger::WriteMessage("Test Leet Code 871");
    LeetCodeGraph leetCode;
    int target = 1;
    int startFuel = 1;
    vector<vector<int>> stations = {};
    int result = leetCode.minRefuelStops(target, startFuel, stations);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("startFuel = " + to_string(startFuel) + "; target = " + to_string(target) + "; result = " + to_string(result));

    target = 100;
    startFuel = 1;
    stations = { {10, 100} };
    result = leetCode.minRefuelStops(target, startFuel, stations);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("startFuel = " + to_string(startFuel) + "; target = " + to_string(target) + "; result = " + to_string(result));

    target = 100;
    startFuel = 10;
    stations = { {10, 60},{20, 30},{30, 30},{60, 40} };
    result = leetCode.minRefuelStops(target, startFuel, stations);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("startFuel = " + to_string(startFuel) + "; target = " + to_string(target) + "; result = " + to_string(result));

    target = 100;
    startFuel = 25;
    stations = { { 25, 25 },{ 50, 25 },{ 75, 25 } };
    result = leetCode.minRefuelStops(target, startFuel, stations);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("startFuel = " + to_string(startFuel) + "; target = " + to_string(target) + "; result = " + to_string(result));

    target = 1000;
    startFuel = 83;
    stations = { {47, 220},{65, 1},{98, 113},{126, 196},{186, 218},{320, 205},{686, 317},{707, 325},{754, 104},{781, 105} };
    result = leetCode.minRefuelStops(target, startFuel, stations);
    Logger::WriteMessage(stations);
    Logger::WriteMessage("startFuel = " + to_string(startFuel) + "; target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode886(void)
{
    Logger::WriteMessage("Test Leet Code 886");
    LeetCodeGraph leetCode;
    int N = 4;
    vector<vector<int>> dislikes = { {1, 2},{1, 3},{2, 4} };
    bool result = leetCode.possibleBipartition(N, dislikes);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    N = 3;
    dislikes = { {1,2},{1,3},{2,3} };
    result = leetCode.possibleBipartition(N, dislikes);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    N = 5;
    dislikes = { {1, 2},{2, 3},{3, 4},{4, 5},{1, 5} };
    result = leetCode.possibleBipartition(N, dislikes);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode913(void)
{
    Logger::WriteMessage("Test Leet Code 913");
    LeetCodeGraph leetCode;
    vector<vector<int>> graph = { {2, 5},{3},{0, 4, 5},{1, 4, 5},{2, 3},{0, 2, 3} };
    int result = leetCode.catMouseGame(graph);

    Logger::WriteMessage(graph);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode943(void)
{
    Logger::WriteMessage("Test Leet Code 943");
    LeetCodeGraph leetCode;
    vector<string> A = { "alex", "loves", "leetcode" };
    string result = leetCode.shortestSuperstring(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + result);

    A = { "catg","ctaagt","gcta","ttca","atgcatc" };
    result = leetCode.shortestSuperstring(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode959(void)
{
    Logger::WriteMessage("Test Leet Code 959");
    LeetCodeGraph leetCode;
    vector<string> grid = { " /", "/ " };
    Logger::WriteMessage(grid);
    int result = leetCode.regionsBySlashes(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { " /", "  " };
    Logger::WriteMessage(grid);
    result = leetCode.regionsBySlashes(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { "\\/", "/\\" };
    Logger::WriteMessage(grid);
    result = leetCode.regionsBySlashes(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { "/\\", "\\/" };
    Logger::WriteMessage(grid);
    result = leetCode.regionsBySlashes(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { "//", "/ " };
    Logger::WriteMessage(grid);
    result = leetCode.regionsBySlashes(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1057(void)
{
    Logger::WriteMessage("Test Leet Code 1057");
    LeetCodeGraph leetCode;
    vector<vector<int>> workers = { {0,0},{1,1},{2,0} };
    vector<vector<int>> bikes = { {1,0},{2,2},{2,1} };
    vector<int> result = leetCode.assignBikes(workers, bikes);
    Logger::WriteMessage(workers);
    Logger::WriteMessage(bikes);
    Logger::WriteMessage(result);

    workers = { {0, 0},{2, 1} };
    bikes = { {1, 2}, {3, 3} };
    result = leetCode.assignBikes(workers, bikes);
    Logger::WriteMessage(workers);
    Logger::WriteMessage(bikes);
    Logger::WriteMessage(result);

    workers = { {0, 0},{1, 0},{2, 0},{3, 0},{4, 0},{5, 0},{6, 0},{7, 0} };
    bikes = { {0, 999},{1, 999},{2, 999},{3, 999},{4, 999},{5, 999},{6, 999},{7, 999},{8, 999} };
    result = leetCode.assignBikes(workers, bikes);
    Logger::WriteMessage(workers);
    Logger::WriteMessage(bikes);
    Logger::WriteMessage(result);
}

void TestLeetCode1059(void)
{
    Logger::WriteMessage("Test Leet Code 1059");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{0, 2} };
    int source = 0;
    int destination = 2;
    bool result = leetCode.leadsToDestination(n, edges, source, destination);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source) +
        "; destination = " + to_string(destination) +
        "; result = " + (string)(result ? "true" : "false"));

    n = 4;
    edges = { {0, 1},{0, 3},{1, 2},{2, 1} };
    source = 0;
    destination = 3;
    result = leetCode.leadsToDestination(n, edges, source, destination);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source) +
        "; destination = " + to_string(destination) +
        "; result = " + (string)(result ? "true" : "false"));

    n = 4;
    edges = { {0, 1},{0, 2},{1, 3},{2, 3} };
    source = 0;
    destination = 3;
    result = leetCode.leadsToDestination(n, edges, source, destination);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source) +
        "; destination = " + to_string(destination) +
        "; result = " + (string)(result ? "true" : "false"));

    n = 3;
    edges = { {0, 1},{1, 1},{1, 2} };
    source = 0;
    destination = 2;
    result = leetCode.leadsToDestination(n, edges, source, destination);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source) +
        "; destination = " + to_string(destination) +
        "; result = " + (string)(result ? "true" : "false"));

    n = 2;
    edges = { {0, 1},{1, 1} };
    source = 0;
    destination = 1;
    result = leetCode.leadsToDestination(n, edges, source, destination);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source) +
        "; destination = " + to_string(destination) +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1102(void)
{
    Logger::WriteMessage("Test Leet Code 1102");
    LeetCodeGraph leetCode;
    vector<vector<int>> A =
    {
        {5,4,5},{1,2,6},{7,4,6}
    };
    int result = leetCode.maximumMinimumPath(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A =
    {
        {2, 2, 1, 2, 2, 2},{1, 2, 2, 2, 1, 2}
    };
    result = leetCode.maximumMinimumPath(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A =
    {
        {3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}
    };
    result = leetCode.maximumMinimumPath(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A =
    {
        {0, 1, 0, 0, 1},{1, 1, 0, 0, 0},{1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 0, 1}
    };
    result = leetCode.maximumMinimumPath(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1129(void)
{
    Logger::WriteMessage("Test Leet Code 1129");
    LeetCodeGraph leetCode;
    vector<vector<int>> red_edges = { {0,1} ,{1,2} };
    vector<vector<int>> blue_edges = {};
    int n = 3;
    vector<int> result = leetCode.shortestAlternatingPaths(n, red_edges, blue_edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(red_edges);
    Logger::WriteMessage(blue_edges);
    Logger::WriteMessage(result);

    n = 3;
    red_edges = { {0, 1} };
    blue_edges = { {2, 1} };
    result = leetCode.shortestAlternatingPaths(n, red_edges, blue_edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(red_edges);
    Logger::WriteMessage(blue_edges);
    Logger::WriteMessage(result);

    n = 3;
    red_edges = { {1, 0} };
    blue_edges = { {2, 1} };
    result = leetCode.shortestAlternatingPaths(n, red_edges, blue_edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(red_edges);
    Logger::WriteMessage(blue_edges);
    Logger::WriteMessage(result);

    n = 3;
    red_edges = { {0, 1} };
    blue_edges = { {1, 2} };
    result = leetCode.shortestAlternatingPaths(n, red_edges, blue_edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(red_edges);
    Logger::WriteMessage(blue_edges);
    Logger::WriteMessage(result);

    n = 3;
    red_edges = { {0, 1}, {0, 2} };
    blue_edges = { {1, 0} };
    result = leetCode.shortestAlternatingPaths(n, red_edges, blue_edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(red_edges);
    Logger::WriteMessage(blue_edges);
    Logger::WriteMessage(result);

    n = 6;
    red_edges = { {1, 5}, {2, 2}, {5, 5}, {3, 0}, {4, 5}, {2, 4}, {4, 1}, {1, 0}, {1, 2}, {5, 2}, {2, 3}, {0, 1} };
    blue_edges = { {4, 4}, {2, 5}, {1, 1}, {5, 4}, {3, 3} };
    result = leetCode.shortestAlternatingPaths(n, red_edges, blue_edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(red_edges);
    Logger::WriteMessage(blue_edges);
    Logger::WriteMessage(result);
}

void TestLeetCode1135(void)
{
    Logger::WriteMessage("Test Leet Code 1135");
    LeetCodeGraph leetCode;
    int N = 3;
    vector<vector<int>> connections = { {1, 2, 5},{1, 3, 6},{2, 3, 1} };
    int result = leetCode.minimumCost(N, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("result = " + to_string(result));

    N = 4;
    connections = { {1, 2, 3},{3, 4, 4} };
    result = leetCode.minimumCost(N, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1136(void)
{
    Logger::WriteMessage("Test Leet Code 1136");
    LeetCodeGraph leetCode;
    int N = 3;
    vector<vector<int>> relations = { {1, 3},{2, 3} };
    int result = leetCode.minimumSemesters(N, relations);
    Logger::WriteMessage(relations);
    Logger::WriteMessage("result = " + to_string(result));

    N = 3;
    relations = { {1, 2},{2, 3},{3, 1} };
    result = leetCode.minimumSemesters(N, relations);
    Logger::WriteMessage(relations);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1153(void)
{
    Logger::WriteMessage("Test Leet Code 1153");
    LeetCodeGraph leetCode;
    string str1 = "aabcc";
    string str2 = "ccdee";
    bool result = leetCode.canConvert(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + (string)(result ? "true" : "false"));

    str1 = "leetcode";
    str2 = "codeleet";
    result = leetCode.canConvert(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + (string)(result ? "true" : "false"));

    str1 = "abc";
    str2 = "bca";
    result = leetCode.canConvert(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + (string)(result ? "true" : "false"));

    str1 = "abcdefghijklmnopqrstuvwxyz";
    str2 = "bcdefghijklmnopqrstuvwxyza";
    result = leetCode.canConvert(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + (string)(result ? "true" : "false"));

    str1 = "abcdefghijklmnopqrstuvwxyz";
    str2 = "bcdefghijklmnopqrstuvwxyzq";
    result = leetCode.canConvert(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1168(void)
{
    Logger::WriteMessage("Test Leet Code 1168");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<int> wells = { 46012, 72474, 64965, 751, 33304 };
    vector<vector<int>> pipes = { {2, 1, 6719},{3, 2, 75312},{5, 3, 44918} };
    int result = leetCode.minCostToSupplyWater(n, wells, pipes);
    Logger::WriteMessage(wells);
    Logger::WriteMessage(pipes);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    wells = { 1, 2, 2 };
    pipes = { {1, 2, 1},{2, 3, 1} };
    result = leetCode.minCostToSupplyWater(n, wells, pipes);
    Logger::WriteMessage(wells);
    Logger::WriteMessage(pipes);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 10;
    wells = { 22238, 38788, 73611, 22861, 18865, 52721, 85325, 98901, 72035, 74803 };
    pipes = { {2, 1, 82145},{3, 1, 83958},{4, 2, 52824},{5, 4, 60736},{6, 1, 38042},{7, 6, 30343},{9, 3, 34316} };
    result = leetCode.minCostToSupplyWater(n, wells, pipes);
    Logger::WriteMessage(wells);
    Logger::WriteMessage(pipes);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1192(void)
{
    Logger::WriteMessage("Test Leet Code 1192");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> connections = { {0, 1},{1, 2},{2, 0},{1, 3} };
    vector<vector<int>> result = leetCode.criticalConnections(n, connections);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(connections);
    Logger::WriteMessage(result);
}

void TestLeetCode1203(void)
{
    Logger::WriteMessage("Test Leet Code 1203");
    LeetCodeGraph leetCode;
    int n = 8;
    int m = 2;
    vector<int> group = { -1, -1, 1, 0, 0, 1, 0, -1 };
    vector<vector<int>> beforeItems = { {},{6},{5},{6},{3, 6},{},{},{} };
    vector<int> result = leetCode.sortItems(n, m, group, beforeItems);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m));
    Logger::WriteMessage(group);
    Logger::WriteMessage(beforeItems);
    Logger::WriteMessage(result);

    n = 8;
    m = 2;
    group = { -1, -1, 1, 0, 0, 1, 0, -1 };
    beforeItems = { {},{6},{5},{6},{3, 6},{},{4},{} };
    result = leetCode.sortItems(n, m, group, beforeItems);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m));
    Logger::WriteMessage(group);
    Logger::WriteMessage(beforeItems);
    Logger::WriteMessage(result);
}

void TestLeetCode1210(void)
{
    Logger::WriteMessage("Test Leet Code 1210");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        { 0,0,0,0,0,1 },
        { 1,1,0,0,1,0 },
        { 0,0,0,0,1,1 },
        { 0,0,1,0,1,0 },
        { 0,1,1,0,0,0 },
        { 0,1,1,0,0,0 }
    };
    int result = leetCode.minimumMoves(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        { 0,0,1,1,1,1 },
        { 0,0,0,0,1,1 },
        { 1,1,0,0,0,1 },
        { 1,1,1,0,0,1 },
        { 1,1,1,0,0,1 },
        { 1,1,1,0,0,0 }
    };
    result = leetCode.minimumMoves(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode9902(void)
{
    Logger::WriteMessage("Test Leet Code 9902");
    LeetCodeGraph leetCode;
    vector<int> distances = { 0, 1, 1, 1, 1, 1 };
    vector<int> weights = { 1, 2, 4, 3 ,5, 1 };
    Logger::WriteMessage(distances);
    Logger::WriteMessage(weights);
    int result = leetCode.minDeliveryCost(distances, weights);
    Logger::WriteMessage("minmum delivery cost = " + to_string(result));
}

void TestLeetCode174(void)
{
    Logger::WriteMessage("Test Leet Code 174");
    LeetCodeGraph leetCode;
    vector<vector<int>> dungeon;
    int min_hp;
    dungeon = { { -2,-3, 3 }, {-5, -10, 1}, {10, 30, -5} };
    for (size_t i = 0; i < dungeon.size(); i++)
    {
        Logger::WriteMessage(dungeon[i]);
    }
    min_hp = leetCode.calculateMinimumHP(dungeon);
    Logger::WriteMessage("Minimum HP = " + to_string(min_hp));
    dungeon = { { 1, -3, 3 },{ 0, -2, 0 },{ -3, -3, -3 } };
    for (size_t i = 0; i < dungeon.size(); i++)
    {
        Logger::WriteMessage(dungeon[i]);
    }
    min_hp = leetCode.calculateMinimumHP(dungeon);
    Logger::WriteMessage("Minimum HP = " + to_string(min_hp));
}

void TestLeetCode1245(void)
{
    Logger::WriteMessage("Test Leet Code 1245");
    LeetCodeGraph leetCode;
    vector<vector<int>> edges = { { 0, 1 }, {0, 2} };
    int result = leetCode.treeDiameter(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{1, 2},{2, 3},{1, 4},{4, 5} };
    result = leetCode.treeDiameter(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{1, 2},{2, 3} };
    result = leetCode.treeDiameter(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1254(void)
{
    Logger::WriteMessage("Test Leet Code 1254");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    int result = leetCode.closedIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 0}
    };
    result = leetCode.closedIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
    result = leetCode.closedIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        { 0, 0, 1, 1, 0, 1, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
        { 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
        { 0, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 }
    };
    result = leetCode.closedIsland(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode529(void)
{
    Logger::WriteMessage("Test Leet Code 529");
    LeetCodeGraph leetCode;
    vector<vector<char>> board =
    {
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'M', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' },
        { 'E', 'E', 'E', 'E', 'E' }
    };
    vector<int> click = { 3, 0 };
    Logger::WriteMessage(board);
    Logger::WriteMessage(click);
    board = leetCode.updateBoard(board, click);
    Logger::WriteMessage(board);

    board =
    {
        { 'B', '1', 'E', '1', 'B' },
        { 'B', '1', 'M', '1', 'B' },
        { 'B', '1', '1', '1', 'B' },
        { 'B', 'B', 'B', 'B', 'B' }
    };
    click = { 1,2 };
    Logger::WriteMessage(board);
    Logger::WriteMessage(click);
    board = leetCode.updateBoard(board, click);
    Logger::WriteMessage(board);
}

void TestLeetCode1258(void)
{
    Logger::WriteMessage("Test Leet Code 1258");
    LeetCodeGraph leetCode;
    vector<vector<string>> synonyms = { {"happy", "joy"},{"sad", "sorrow"},{"joy", "cheerful"} };
    string text = "I am happy today but was sad yesterday";
    vector<string> result = leetCode.generateSentences(synonyms, text);
    Logger::WriteMessage(synonyms);
    Logger::WriteMessage("text = " + text);
    Logger::WriteMessage(result);
}

void TestLeetCode1263(void)
{
    Logger::WriteMessage("Test Leet Code 1263");
    LeetCodeGraph leetCode;
    vector<vector<char>> grid =
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#' },
        {'#','.','.','.','#','#','#','#','.','#','#','#','#','.','#','#','#','.','#' },
        {'#','.','.','.','.','.','.','.','.','#','T','#','.','.','#','#','#','.','#' },
        {'#','.','.','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.','#' },
        {'#','.','#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','.','#' },
        {'#','.','#','.','#','#','#','#','#','#','#','#','#','.','#','#','#','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','#','#','#','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','#','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','B','.','#','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','#','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        {'#','.','.','.','.','.','.','.','.','.','S','.','.','.','.','#','.','.','#' },
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
    };
    Logger::WriteMessage(grid);
    int result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'#','.','.','#','#','#','#','#'},
        {'#','.','.','T','#','.','.','#'},
        {'#','.','.','.','#','B','.','#'},
        {'#','.','.','.','.','.','.','#'},
        {'#','.','.','.','#','.','S','#'},
        {'#','.','.','#','#','#','#','#'}
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));


    grid =
    {
        {'#','#','#','#','#','#'},
        {'#','T','#','#','#','#'},
        {'#','.','.','B','.','#'},
        {'#','#','#','#','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'}
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'#','#','#','#','#','#'},
        {'#','T','.','.','#','#'},
        {'#','.','#','B','.','#'},
        {'#','.','.','.','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'}
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'#','#','#','#','#','#','#'},
        {'#','S','#','.','B','T','#'},
        {'#','#','#','#','#','#','#'}
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'.','.','#','.','.','.','.','#'},
        { '.','B','.','.','.','.','.','#' },
        { '.','.','S','.','.','.','.','.' },
        { '.','#','.','.','.','.','.','.' },
        { '.','.','.','.','.','.','.','.' },
        { '.','.','.','T','.','.','.','.' },
        { '.','.','.','.','.','.','.','#' },
        { '.','#','.','.','.','.','.','.' }
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        { '#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#' },
        { '#','.','.','.','#','#','.','#','#','#','#','.','#','#','#','.','#','#','T','#' },
        { '#','.','.','.','.','.','.','#','.','#','.','.','#','#','#','.','#','#','.','#' },
        { '#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#' },
        { '#','.','#','.','.','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#' },
        { '#','.','#','.','#','#','#','#','#','#','#','.','#','#','#','.','#','#','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','B','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.','#','.','.','#' },
        { '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' }
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'#','#','#','#','#','#'},
        {'#','T','#','#','#','#'},
        {'#','.','.','B','.','#'},
        {'#','.','#','#','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'}
    };
    Logger::WriteMessage(grid);
    result = leetCode.minPushBox(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode463(void)
{
    Logger::WriteMessage("Test Leet Code 463");
    LeetCodeGraph leetCode;
    vector<vector<int>> nums = { {0,1,0,0 }, {1,1,1,0 }, { 0,1,0,0 }, { 1,1,0,0 } };
    for (size_t i = 0; i < nums.size(); i++)
    {
        Logger::WriteMessage(nums[i]);
    }
    int perimeter = leetCode.islandPerimeter(nums);
    Logger::WriteMessage("The perimeter of island is " + to_string(perimeter));
}

void TestLeetCode1273(void)
{
    Logger::WriteMessage("Test Leet Code 1273");
    LeetCodeGraph leetCode;
    int nodes = 7;
    vector<int> parent = { -1, 0, 0, 1, 2, 2, 2 };
    vector<int> value = { 1,-2,4,0,-2,-1,-1 };
    int result = leetCode.deleteTreeNodes(nodes, parent, value);
    Logger::WriteMessage("nodes = " + to_string(nodes));
    Logger::WriteMessage(parent);
    Logger::WriteMessage(value);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1293(void)
{
    Logger::WriteMessage("Test Leet Code 1293");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {0,0,0},
        {1,1,0},
        {0,0,0},
        {0,1,1},
        {0,0,0}
    };
    int k = 1;
    int result = leetCode.shortestPath(grid, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    grid =
    {
        { 0,1,1 },
        { 1,1,1 },
        { 1,0,0 }
    };
    k = 1;
    result = leetCode.shortestPath(grid, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1298(void)
{
    Logger::WriteMessage("Test Leet Code 1298");
    LeetCodeGraph leetCode;
    vector<int> status = { 1, 0, 1, 0 };
    vector<int> candies = { 7, 5, 4, 100 };
    vector<vector<int>> keys = { {}, {}, {1}, {} };
    vector<vector<int>> containedBoxes = { {1,2}, {3}, {}, {} };
    vector<int> initialBoxes = { 0 };
    int result = leetCode.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    Logger::WriteMessage(status);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(keys);
    Logger::WriteMessage(containedBoxes);
    Logger::WriteMessage(initialBoxes);
    Logger::WriteMessage("result = " + to_string(result));

    status = { 1,0,0,0,0,0 };
    candies = { 1,1,1,1,1,1 };
    keys = { {1,2,3,4,5} ,{},{},{},{},{} };
    containedBoxes = { {1,2,3,4,5} ,{},{},{},{},{} };
    initialBoxes = { 0 };
    result = leetCode.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    Logger::WriteMessage(status);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(keys);
    Logger::WriteMessage(containedBoxes);
    Logger::WriteMessage(initialBoxes);
    Logger::WriteMessage("result = " + to_string(result));

    status = { 1,1,1 };
    candies = { 100,1,100 };
    keys = { {}, {0,2}, {} };
    containedBoxes = { {},{},{} };
    initialBoxes = { 1 };
    result = leetCode.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    Logger::WriteMessage(status);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(keys);
    Logger::WriteMessage(containedBoxes);
    Logger::WriteMessage(initialBoxes);
    Logger::WriteMessage("result = " + to_string(result));

    status = { 1 };
    candies = { 100 };
    keys = { {} };
    containedBoxes = { {} };
    initialBoxes = { };
    result = leetCode.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    Logger::WriteMessage(status);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(keys);
    Logger::WriteMessage(containedBoxes);
    Logger::WriteMessage(initialBoxes);
    Logger::WriteMessage("result = " + to_string(result));

    status = { 1,1,1 };
    candies = { 2,3,2 };
    keys = { {}, {}, {} };
    containedBoxes = { {},{},{} };
    initialBoxes = { 2, 1, 0 };
    result = leetCode.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    Logger::WriteMessage(status);
    Logger::WriteMessage(candies);
    Logger::WriteMessage(keys);
    Logger::WriteMessage(containedBoxes);
    Logger::WriteMessage(initialBoxes);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode505(void)
{
    Logger::WriteMessage("Test Leet Code 505");
    LeetCodeGraph leetCode;
    vector<vector<int>> maze =
    {
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0 }
    };
    vector<int> start = { 0, 0 };
    vector<int> destination = { 8, 6 };
    int result = leetCode.shortestDistance(maze, start, destination);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Shortest Path = " + to_string(result));

    maze =
    {
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 1 },
        { 0, 0, 0, 0, 0 }
    };
    start = { 0, 4 };
    destination = { 4, 4 };
    result = leetCode.shortestDistance(maze, start, destination);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Shortest Path = " + to_string(result));

    maze =
    {
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 1 },
        { 0, 0, 0, 0, 0 }
    };
    start = { 0, 4 };
    destination = { 3, 2 };
    result = leetCode.shortestDistance(maze, start, destination);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Shortest Path = " + to_string(result));
}

void TestLeetCode499(void)
{
    Logger::WriteMessage("Test Leet Code 499");
    LeetCodeGraph leetCode;
    vector<vector<int>> maze =
    {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 1 }
    };
    vector<int> ball = { 0, 4 };
    vector<int> hole = { 3, 5 };
    string result = leetCode.findShortestWay(maze, ball, hole);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Shortest Path = " + result);

    maze =
    {
        { 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 0, 1, 0, 0, 0 }
    };
    ball = { 4, 3 };
    hole = { 0, 1 };
    result = leetCode.findShortestWay(maze, ball, hole);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Shortest Path = " + result);

    maze =
    {
        { 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 0, 1, 0, 0, 0 }
    };
    ball = { 4, 3 };
    hole = { 3, 0 };
    result = leetCode.findShortestWay(maze, ball, hole);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Shortest Path = " + result);
}

void TestLeetCode490(void)
{
    Logger::WriteMessage("Test Leet Code 490");
    LeetCodeGraph leetCode;
    vector<vector<int>> maze =
    {
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0}
    };
    vector<int> start = { 0, 4 };
    vector<int> destination = { 3, 2 };
    bool result = leetCode.hasPath(maze, start, destination);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Has Path = " + (string)(result ? "true" : "false"));

    maze =
    {
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0 },
        { 1, 1, 0, 1, 1 },
        { 0, 0, 0, 0, 0 }
    };
    start = { 0, 4 };
    destination = { 4, 4 };
    result = leetCode.hasPath(maze, start, destination);
    Logger::WriteMessage(maze);
    Logger::WriteMessage("Has Path = " + (string)(result ? "true" : "false"));
}

void TestLeetCode787(void)
{
    Logger::WriteMessage("Test Leet Code 787");
    LeetCodeGraph leetCode;
    vector<vector<int>> flights = { {0,1,100},{1,2,100},{0,2,500} };
    int n = 3;
    int src = 0;
    int dst = 2;
    int k = 1;
    int result = leetCode.findCheapestPrice(n, flights, src, dst, k);
    Logger::WriteMessage(flights);
    Logger::WriteMessage("n = " + to_string(n) + "; src = " + to_string(src) +
        "; dst = " + to_string(dst) + "; k = " + to_string(k) +
        "; result = " + to_string(result));

    n = 3;
    src = 0;
    dst = 2;
    k = 0;
    result = leetCode.findCheapestPrice(n, flights, src, dst, k);
    Logger::WriteMessage(flights);
    Logger::WriteMessage("n = " + to_string(n) + "; src = " + to_string(src) +
        "; dst = " + to_string(dst) + "; k = " + to_string(k) +
        "; result = " + to_string(result));
}

void TestLeetCode1311(void)
{
    Logger::WriteMessage("Test Leet Code 1311");
    LeetCodeGraph leetCode;
    vector<vector<string>> watchedVideos = { {"A", "B"},{"C"},{"B", "C"},{"D"} };
    vector<vector<int>> friends = { {1, 2},{0, 3},{0, 3},{1, 2} };
    int id = 0;
    int level = 1;
    vector<string> result = leetCode.watchedVideosByFriends(watchedVideos, friends, id, level);
    Logger::WriteMessage(watchedVideos);
    Logger::WriteMessage(friends);
    Logger::WriteMessage("id = " + (string)(to_string(id)));
    Logger::WriteMessage(result);

    watchedVideos = { {"A", "B"},{"C"},{"B", "C"},{"D"} };
    friends = { {1, 2},{0, 3},{0, 3},{1, 2} };
    id = 0;
    level = 2;
    result = leetCode.watchedVideosByFriends(watchedVideos, friends, id, level);
    Logger::WriteMessage(watchedVideos);
    Logger::WriteMessage(friends);
    Logger::WriteMessage("id = " + (string)(to_string(id)));
    Logger::WriteMessage(result);
}

void TestLeetCode1340(void)
{
    Logger::WriteMessage("Test Leet Code 1340");
    LeetCodeGraph leetCode;
    vector<int> arr = { 6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12 };
    int d = 2;
    int result = leetCode.maxJumps(arr, d);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("d = " + (string)(to_string(d)) + "; result = " + to_string(result));

    arr = { 3,3,3,3,3 };
    d = 3;
    result = leetCode.maxJumps(arr, d);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("d = " + (string)(to_string(d)) + "; result = " + to_string(result));

    arr = { 7,6,5,4,3,2,1 };
    d = 1;
    result = leetCode.maxJumps(arr, d);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("d = " + (string)(to_string(d)) + "; result = " + to_string(result));

    arr = { 7,1,7,1,7,1 };
    d = 2;
    result = leetCode.maxJumps(arr, d);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("d = " + (string)(to_string(d)) + "; result = " + to_string(result));

    arr = { 66 };
    d = 1;
    result = leetCode.maxJumps(arr, d);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("d = " + (string)(to_string(d)) + "; result = " + to_string(result));
}

void TestLeetCode1345(void)
{
    Logger::WriteMessage("Test Leet Code 1345");
    LeetCodeGraph leetCode;
    vector<int> arr = { 100,-23,-23,404,100,23,23,23,3,404 };
    int result = leetCode.minJumps(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 7 };
    result = leetCode.minJumps(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 7,6,9,6,9,6,9,7 };
    result = leetCode.minJumps(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 6,1,9 };
    result = leetCode.minJumps(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 11,22,7,7,7,7,7,7,7,22,13 };
    result = leetCode.minJumps(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1361(void)
{
    Logger::WriteMessage("Test Leet Code 1361");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<int> leftChild = { 1, -1, 3, -1 };
    vector<int> rightChild = { 2, -1, -1, -1 };
    bool result = leetCode.validateBinaryTreeNodes(n, leftChild, rightChild);
    Logger::WriteMessage(leftChild);
    Logger::WriteMessage(rightChild);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    n = 4;
    leftChild = { 1, -1, 3, -1 };
    rightChild = { 2,3,-1,-1 };
    result = leetCode.validateBinaryTreeNodes(n, leftChild, rightChild);
    Logger::WriteMessage(leftChild);
    Logger::WriteMessage(rightChild);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    n = 2;
    leftChild = { 1, 0 };
    rightChild = { -1,-1 };
    result = leetCode.validateBinaryTreeNodes(n, leftChild, rightChild);
    Logger::WriteMessage(leftChild);
    Logger::WriteMessage(rightChild);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    n = 6;
    leftChild = { 1,-1,-1,4,-1,-1 };
    rightChild = { 2,-1,-1,5,-1,-1 };
    result = leetCode.validateBinaryTreeNodes(n, leftChild, rightChild);
    Logger::WriteMessage(leftChild);
    Logger::WriteMessage(rightChild);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    n = 2;
    leftChild = { 1, -1 };
    rightChild = { -1,-1 };
    result = leetCode.validateBinaryTreeNodes(n, leftChild, rightChild);
    Logger::WriteMessage(leftChild);
    Logger::WriteMessage(rightChild);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1368(void)
{
    Logger::WriteMessage("Test Leet Code 1368");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = { {1, 1, 1, 1},{2, 2, 2, 2},{1, 1, 1, 1},{2, 2, 2, 2} };
    int result = leetCode.minCost(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 1, 3},{3, 2, 2},{1, 1, 4} };
    result = leetCode.minCost(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 2},{34, 3} };
    result = leetCode.minCost(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {2, 2, 2},{2, 2, 2} };
    result = leetCode.minCost(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {4} };
    result = leetCode.minCost(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1376(void)
{
    Logger::WriteMessage("Test Leet Code 1376");
    LeetCodeGraph leetCode;
    int n = 1;
    int headID = 0;
    vector<int> manager = { -1 };
    vector<int> informTime = { 0 };
    int result = leetCode.numOfMinutes(n, headID, manager, informTime);
    Logger::WriteMessage(manager);
    Logger::WriteMessage(informTime);
    Logger::WriteMessage("n = " + to_string(n) + "; headID = " + to_string(headID) + "; result = " + to_string(result));

    n = 6;
    headID = 2;
    manager = { 2, 2, -1, 2, 2, 2 };
    informTime = { 0, 0, 1, 0, 0, 0 };
    result = leetCode.numOfMinutes(n, headID, manager, informTime);
    Logger::WriteMessage(manager);
    Logger::WriteMessage(informTime);
    Logger::WriteMessage("n = " + to_string(n) + "; headID = " + to_string(headID) + "; result = " + to_string(result));

    n = 7;
    headID = 6;
    manager = { 1,2,3,4,5,6,-1 };
    informTime = { 0,6,5,4,3,2,1 };
    result = leetCode.numOfMinutes(n, headID, manager, informTime);
    Logger::WriteMessage(manager);
    Logger::WriteMessage(informTime);
    Logger::WriteMessage("n = " + to_string(n) + "; headID = " + to_string(headID) + "; result = " + to_string(result));

    n = 15;
    headID = 0;
    manager = { -1,0,0,1,1,2,2,3,3,4,4,5,5,6,6 };
    informTime = { 1,1,1,1,1,1,1,0,0,0,0,0,0,0,0 };
    result = leetCode.numOfMinutes(n, headID, manager, informTime);
    Logger::WriteMessage(manager);
    Logger::WriteMessage(informTime);
    Logger::WriteMessage("n = " + to_string(n) + "; headID = " + to_string(headID) + "; result = " + to_string(result));

    n = 4;
    headID = 2;
    manager = { 3,3,-1,2 };
    informTime = { 0,0,162,914 };
    result = leetCode.numOfMinutes(n, headID, manager, informTime);
    Logger::WriteMessage(manager);
    Logger::WriteMessage(informTime);
    Logger::WriteMessage("n = " + to_string(n) + "; headID = " + to_string(headID) + "; result = " + to_string(result));
}

void TestLeetCode1377(void)
{
    Logger::WriteMessage("Test Leet Code 1377");
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> edges = { {1, 2},{1, 3},{1, 7},{2, 4},{2, 6},{3, 5} };
    int t = 2;
    int target = 3;
    double result = leetCode.frogPosition(n, edges, t, target);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; t = " + to_string(t) + "; target = " + to_string(target) + "; result = " + to_string(result));

    n = 7;
    edges = { {1, 2}, { 1, 3 }, { 1, 7 }, { 2, 4 }, { 2, 6 }, { 3, 5 } };
    t = 1;
    target = 7;    
    result = leetCode.frogPosition(n, edges, t, target);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; t = " + to_string(t) + "; target = " + to_string(target) + "; result = " + to_string(result));

    n = 7;
    edges = { {1, 2},{1, 3},{1, 7},{2, 4},{2, 6},{3, 5} };
    t = 20;
    target = 6;
    result = leetCode.frogPosition(n, edges, t, target);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; t = " + to_string(t) + "; target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1436(void)
{
    Logger::WriteMessage("Test Leet Code 1436");
    LeetCodeGraph leetCode;
    vector<vector<string>> paths =
    {
        {"London", "New York"},{"New York", "Lima"},{"Lima", "Sao Paulo"}
    };
    string result = leetCode.destCity(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage("result = " + result);

    paths =
    {
        {"B","C"},{"D","B"},{"C","A"}
    };
    result = leetCode.destCity(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage("result = " + result);

    paths =
    {
        {"A","Z"}
    };
    result = leetCode.destCity(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode1443(void)
{
    Logger::WriteMessage("Test Leet Code 1443");
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> edges = { {0,1} ,{0,2},{1,4},{1,5},{2,3},{2,6} };
    vector<bool> hasApple = { false,false,true,false,true,true,false };
    int result = leetCode.minTime(n, edges, hasApple);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(hasApple);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    edges = { {0,1} ,{0,2},{1,4},{1,5},{2,3},{2,6} };
    hasApple = { false,false,true,false,false,true,false };
    result = leetCode.minTime(n, edges, hasApple);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(hasApple);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    edges = { {0,1} ,{0,2},{1,4},{1,5},{2,3},{2,6} };
    hasApple = { false,false,false,false,false,false,false };
    result = leetCode.minTime(n, edges, hasApple);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(hasApple);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode9903(void)
{
    Logger::WriteMessage("Test Leet Code 9903");
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;

    int m = 3, n = 3;
    vector<vector<int>> positions = { {0, 0},{0, 1},{1, 2},{2, 1} };
    vector<int> result = leetCode.numIslands2(m, n, positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    m = 3, n = 3;
    positions = { { 0, 1 },{ 1, 2 },{ 2, 1 }, {1, 0},{0, 2},{0, 0},{1, 1} };
    result = leetCode.numIslands2(m, n, positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    m = 1, n = 1;
    positions = { { 0, 0 } };
    result = leetCode.numIslands2(m, n, positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);

    m = 3, n = 3;
    positions = { {0, 0},{0, 1},{1, 2},{1, 2} };
    result = leetCode.numIslands2(m, n, positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage(result);
}

void TestLeetCode547(void)
{
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;

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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
    vector<string> A = { "tars", "rats", "arts", "star" };
    int result = leetCode.numSimilarGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode947(void)
{
    Logger::WriteMessage("Test Leet Code 947");
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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
    LeetCodeGraph leetCode;
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

void TestLeetCode1319(void)
{
    Logger::WriteMessage("Test Leet Code 1319");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> connections = { {0, 1},{0, 2},{1, 2} };
    int result = leetCode.makeConnected(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 6;
    connections = { {0, 1},{0, 2},{0, 3},{1, 2},{1, 3} };
    result = leetCode.makeConnected(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 6;
    connections = { {0, 1},{0, 2},{0, 3},{1, 2} };
    result = leetCode.makeConnected(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    connections = { {0, 1},{0, 2},{3, 4},{2, 3} };
    result = leetCode.makeConnected(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1462(void)
{
    Logger::WriteMessage("Test Leet Code 1462");
    LeetCodeGraph leetCode;
    int n = 2;
    vector<vector<int>> prerequisites = { {1, 0} };
    vector<vector<int>> queries = { {0, 1},{1, 0} };
    vector<bool> result = leetCode.checkIfPrerequisite(n, prerequisites, queries);
    Logger::WriteMessage(prerequisites);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 2;
    prerequisites = { };
    queries = { {1, 0}, { 0, 1 } };
    result = leetCode.checkIfPrerequisite(n, prerequisites, queries);
    Logger::WriteMessage(prerequisites);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 3;
    prerequisites = { {1, 2},{1, 0},{2, 0} };
    queries = { {1, 0},{1, 2} };
    result = leetCode.checkIfPrerequisite(n, prerequisites, queries);
    Logger::WriteMessage(prerequisites);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 3;
    prerequisites = { {1, 0},{2, 0} };
    queries = { {0, 1},{2, 0} };
    result = leetCode.checkIfPrerequisite(n, prerequisites, queries);
    Logger::WriteMessage(prerequisites);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 5;
    prerequisites = { {0, 1},{1, 2},{2, 3},{3, 4} };
    queries = { {0, 4},{4, 0},{1, 3},{3, 0} };
    result = leetCode.checkIfPrerequisite(n, prerequisites, queries);
    Logger::WriteMessage(prerequisites);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1466(void)
{
    Logger::WriteMessage("Test Leet Code 1466");
    LeetCodeGraph leetCode;
    int n = 6;
    vector<vector<int>> connections = { {0, 1},{1, 3},{2, 3},{4, 0},{4, 5} };
    int result = leetCode.minReorder(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    connections = { {1, 0},{1, 2},{3, 2},{3, 4} };
    result = leetCode.minReorder(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    connections = { {1, 0},{2, 0} };
    result = leetCode.minReorder(n, connections);
    Logger::WriteMessage(connections);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode997(void)
{
    Logger::WriteMessage("Test Leet Code 997");
    LeetCodeGraph leetCode;
    int N = 2;
    vector<vector<int>> trust = { {1, 2} };
    int result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    trust = { {1, 3},{2, 3} };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    trust = { {1, 3},{2, 3},{3, 1} };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    trust = { {1, 2},{2, 3} };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 4;
    trust = { {1, 3}, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 4, 3 } };
    result = leetCode.findJudge(N, trust);
    Logger::WriteMessage(trust);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1489(void)
{
    Logger::WriteMessage("Test Leet Code 1489");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> edges =
    {
        {0, 1, 1},{1, 2, 1},{2, 3, 2},{0, 3, 2},{0, 4, 3},{3, 4, 3},{1, 4, 6}
    };
    vector<vector<int>> result = leetCode.findCriticalAndPseudoCriticalEdges(n, edges);
    
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 4;
    edges =
    {
        {0,1,1},{1,2,1},{2,3,1},{0,3,1}
    };
    result = leetCode.findCriticalAndPseudoCriticalEdges(n, edges);

    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1494(void)
{
    Logger::WriteMessage("Test Leet Code 1494");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> dependencies = { {2, 1},{3, 1},{1, 4} };
    int k = 2;
    int result = leetCode.minNumberOfSemesters(n, dependencies, k);

    Logger::WriteMessage(dependencies);
    Logger::WriteMessage("n = " + to_string(n) + "; k= " + to_string(k) + "; result = " + to_string(result));


    n = 5;
    dependencies = { {2, 1},{3, 1},{4, 1},{1, 5} };
    k = 2;
    result = leetCode.minNumberOfSemesters(n, dependencies, k);

    Logger::WriteMessage(dependencies);
    Logger::WriteMessage("n = " + to_string(n) + "; k= " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1514(void)
{
    Logger::WriteMessage("Test Leet Code 1514");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{1, 2},{0, 2} };
    vector<double> succProb = { 0.5,0.5,0.2 };
    int start = 0;
    int end = 2;
    double result = leetCode.maxProbability(n, edges, succProb, start, end);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(succProb);
    Logger::WriteMessage("n = " + to_string(n) + "; start= " + to_string(start) + "; end = " + to_string(end) + "; result = " + to_string(result));


    n = 3;
    edges = { {0, 1},{1, 2},{0, 2} };
    succProb = { 0.5,0.5,0.3 };
    start = 0;
    end = 2;
    result = leetCode.maxProbability(n, edges, succProb, start, end);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(succProb);
    Logger::WriteMessage("n = " + to_string(n) + "; start= " + to_string(start) + "; end = " + to_string(end) + "; result = " + to_string(result));

    n = 3;
    edges = { {0, 1} };
    succProb = { 0.5 };
    start = 0;
    end = 2;
    result = leetCode.maxProbability(n, edges, succProb, start, end);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(succProb);
    Logger::WriteMessage("n = " + to_string(n) + "; start= " + to_string(start) + "; end = " + to_string(end) + "; result = " + to_string(result));

    n = 1000;
    edges = 
    { {448, 931}, { 234,889 }, { 214,962 }, { 576,746 }, { 678,734 }, { 214,928 }, { 602,779 }, { 190,968 }, { 227,858 }, { 714,842 }, { 177,345 }, { 705,994 }, { 365,998 }, { 307,336 }, { 123,914 }, { 398,487 }, { 112,234 }, { 44,357 }, { 318,506 }, { 311,926 }, { 559,735 }, { 28,299 }, { 689,723 }, { 29,566 }, { 355,476 }, { 507,813 }, { 799,841 }, { 166,581 }, { 499,522 }, { 155,508 }, { 80,954 }, { 412,564 }, { 502,618 }, { 59,746 }, { 272,400 }, { 75,312 }, { 510,887 }, { 303,524 }, { 646,845 }, { 786,928 }, { 124,151 }, { 109,858 }, { 96,762 }, { 291,798 }, { 69,303 }, { 27,112 }, { 292,774 }, { 257,384 }, { 59,755 }, { 140,245 }, { 431,769 }, { 60,338 }, { 173,403 }, { 95,666 }, { 165,384 }, { 298,894 }, { 963,980 }, { 325,945 }, { 419,440 }, { 338,424 }, { 344,846 }, { 396,449 }, { 76,242 }, { 620,981 }, { 264,433 }, { 580,686 }, { 196,682 }, { 272,926 }, { 223,593 }, { 644,785 }, { 487,924 }, { 289,511 }, { 714,988 }, { 625,987 }, { 50,362 }, { 88,664 }, { 233,352 }, { 32,754 }, { 206,961 }, { 641,810 }, { 301,570 }, { 77,523 }, { 26,109 }, { 482,580 }, { 528,683 }, { 128,228 }, { 436,452 }, { 253,844 }, { 126,877 }, { 462,994 }, { 204,337 }, { 380,625 }, { 179,807 }, { 635,726 }, { 143,748 }, { 594,798 }, { 972,996 }, { 328,780 }, { 267,831 }, { 176,399 }, { 257,600 }, { 495,735 }, { 844,893 }, { 102,803 }, { 62,942 }, { 354,903 }, { 234,301 }, { 306,854 }, { 63,555 }, { 39,179 }, { 125,749 }, { 414,487 }, { 80,291 }, { 416,835 }, { 77,951 }, { 10,384 }, { 637,798 }, { 248,966 }, { 646,879 }, { 210,839 }, { 675,876 }, { 580,990 }, { 187,245 }, { 18,876 }, { 881,933 }, { 422,747 }, { 422,432 }, { 635,742 }, { 813,976 }, { 719,900 }, { 149,672 }, { 518,999 }, { 342,746 }, { 121,262 }, { 457,876 }, { 534,984 }, { 219,524 }, { 192,228 }, { 636,671 }, { 196,835 }, { 323,658 }, { 360,747 }, { 643,969 }, { 95,414 }, { 199,325 }, { 169,471 }, { 50,235 }, { 307,517 }, { 500,927 }, { 226,886 }, { 131,962 }, { 65,313 }, { 470,514 }, { 851,987 }, { 437,665 }, { 284,620 }, { 468,752 }, { 54,781 }, { 266,885 }, { 362,825 }, { 0,90 }, { 14,619 }, { 259,686 }, { 171,180 }, { 249,520 }, { 240,245 }, { 225,264 }, { 128,372 }, { 198,383 }, { 306,422 }, { 46,376 }, { 107,797 }, { 746,961 }, { 401,474 }, { 346,435 }, { 241,355 }, { 109,919 }, { 497,541 }, { 271,871 }, { 329,953 }, { 376,541 }, { 564,626 }, { 91,514 }, { 8,610 }, { 595,865 }, { 888,971 }, { 852,905 }, { 532,974 }, { 211,653 }, { 288,410 }, { 463,501 }, { 258,987 }, { 99,515 }, { 494,780 }, { 562,891 }, { 392,620 }, { 293,409 }, { 161,250 }, { 460,527 }, { 801,939 }, { 275,929 }, { 76,553 }, { 236,555 }, { 192,257 }, { 497,604 }, { 140,931 }, { 224,845 }, { 159,339 }, { 328,902 }, { 63,658 }, { 231,626 }, { 862,947 }, { 305,469 }, { 109,426 }, { 216,499 }, { 156,162 }, { 297,685 }, { 101,719 }, { 524,978 }, { 794,914 }, { 933,950 }, { 859,982 }, { 626,929 }, { 162,685 }, { 252,904 }, { 95,837 }, { 293,705 }, { 117,120 }, { 334,880 }, { 19,937 }, { 304,989 }, { 391,800 }, { 54,80 }, { 266,970 }, { 99,916 }, { 34,819 }, { 163,348 }, { 507,725 }, { 295,826 }, { 99,308 }, { 378,463 }, { 799,833 }, { 389,975 }, { 699,709 }, { 836,967 }, { 38,990 }, { 586,871 }, { 664,958 }, { 840,990 }, { 333,379 }, { 71,282 }, { 487,778 }, { 766,845 }, { 225,732 }, { 446,703 }, { 672,762 }, { 342,512 }, { 693,862 }, { 80,316 }, { 325,836 }, { 118,738 }, { 278,297 }, { 107,205 }, { 442,743 }, { 715,812 }, { 40,660 }, { 138,272 }, { 234,941 }, { 804,812 }, { 459,631 }, { 45,798 }, { 246,556 }, { 396,797 }, { 817,894 }, { 548,603 }, { 233,613 }, { 386,742 }, { 215,974 }, { 102,628 }, { 44,555 }, { 210,281 }, { 191,270 }, { 119,979 }, { 613,995 }, { 794,987 }, { 151,814 }, { 621,719 }, { 322,986 }, { 144,200 }, { 625,653 }, { 574,632 }, { 123,735 }, { 528,612 }, { 344,351 }, { 203,298 }, { 357,763 }, { 303,357 }, { 55,555 }, { 209,916 }, { 97,979 }, { 602,994 }, { 74,104 }, { 94,665 }, { 561,884 }, { 202,843 }, { 849,876 }, { 630,683 }, { 37,315 }, { 335,705 }, { 63,569 }, { 76,594 }, { 377,984 }, { 246,735 }, { 49,328 }, { 29,380 }, { 394,397 }, { 66,158 }, { 270,648 }, { 581,944 }, { 304,480 }, { 161,459 }, { 626,782 }, { 169,403 }, { 19,904 }, { 289,387 }, { 200,402 }, { 276,608 }, { 45,662 }, { 339,569 }, { 103,673 }, { 328,602 }, { 328,905 }, { 438,910 }, { 675,679 }, { 125,313 }, { 383,656 }, { 179,266 }, { 807,968 }, { 176,946 }, { 250,466 }, { 106,295 }, { 409,627 }, { 399,708 }, { 350,812 }, { 54,363 }, { 482,774 }, { 217,411 }, { 58,73 }, { 865,912 }, { 387,554 }, { 21,876 }, { 263,374 }, { 784,969 }, { 391,997 }, { 170,181 }, { 56,163 }, { 510,575 }, { 159,925 }, { 14,532 }, { 605,699 }, { 834,845 }, { 119,835 }, { 522,931 }, { 341,749 }, { 361,469 }, { 187,437 }, { 78,613 }, { 814,950 }, { 443,996 }, { 542,876 }, { 378,694 }, { 170,183 }, { 560,803 }, { 320,486 }, { 50,530 }, { 817,941 }, { 209,521 }, { 258,322 }, { 235,540 }, { 595,950 }, { 191,497 }, { 16,953 }, { 299,436 }, { 236,568 }, { 160,298 }, { 812,874 }, { 173,916 }, { 731,770 }, { 341,768 }, { 76,956 }, { 788,858 }, { 67,639 }, { 331,674 }, { 693,792 }, { 62,188 }, { 555,626 }, { 313,473 }, { 172,470 }, { 245,250 }, { 10,116 }, { 754,976 }, { 665,694 }, { 530,947 }, { 506,785 }, { 752,854 }, { 437,788 }, { 61,731 }, { 361,926 }, { 318,909 }, { 405,470 }, { 331,919 }, { 577,589 }, { 931,976 }, { 288,746 }, { 151,340 }, { 279,654 }, { 397,523 }, { 113,496 }, { 318,807 }, { 84,955 }, { 290,637 }, { 517,966 }, { 687,858 }, { 342,741 }, { 238,554 }, { 809,924 }, { 76,162 }, { 941,975 }, { 109,452 }, { 21,663 }, { 207,583 }, { 670,838 }, { 150,558 }, { 801,874 }, { 318,483 }, { 286,377 }, { 173,216 }, { 111,431 }, { 463,489 }, { 630,884 }, { 623,782 }, { 193,305 }, { 8,690 }, { 476,937 }, { 35,938 }, { 159,317 }, { 96,977 }, { 198,488 }, { 460,461 }, { 537,607 }, { 426,451 }, { 42,90 }, { 488,794 }, { 56,819 }, { 43,66 }, { 96,200 }, { 383,743 }, { 293,299 }, { 119,218 }, { 531,720 }, { 432,582 }, { 338,888 }, { 560,700 }, { 619,747 }, { 400,488 }, { 569,968 }, { 519,569 }, { 284,628 }, { 32,438 }, { 369,706 }, { 282,283 }, { 645,959 }, { 129,381 }, { 667,725 }, { 313,549 }, { 9,66 }, { 495,619 }, { 393,729 }, { 425,888 }, { 26,390 }, { 145,568 }, { 126,288 }, { 318,418 }, { 115,695 }, { 215,449 }, { 521,645 }, { 228,962 }, { 180,838 }, { 53,318 }, { 41,820 }, { 772,801 }, { 292,729 }, { 138,835 }, { 538,557 }, { 588,698 }, { 85,169 }, { 503,883 }, { 499,603 }, { 542,954 }, { 439,727 }, { 514,923 }, { 291,843 }, { 269,875 }, { 645,672 }, { 535,825 }, { 19,279 }, { 121,962 }, { 60,240 }, { 181,902 }, { 110,907 }, { 649,995 }, { 30,687 }, { 481,678 }, { 147,300 }, { 663,810 }, { 392,742 }, { 345,568 }, { 600,848 }, { 732,815 }, { 320,717 }, { 577,994 }, { 454,790 }, { 427,491 }, { 43,983 }, { 83,172 }, { 308,398 }, { 391,817 }, { 575,629 }, { 393,931 }, { 601,797 }, { 485,685 }, { 41,95 }, { 139,463 }, { 507,549 }, { 843,980 }, { 342,652 }, { 111,972 }, { 167,309 }, { 71,834 }, { 386,418 }, { 57,991 }, { 133,715 }, { 692,835 }, { 376,513 }, { 164,308 }, { 851,877 }, { 581,774 }, { 755,849 }, { 608,900 }, { 360,409 }, { 21,507 }, { 128,680 }, { 252,965 }, { 83,936 }, { 572,871 }, { 309,378 }, { 80,232 }, { 714,855 }, { 489,559 }, { 146,996 }, { 533,549 }, { 189,401 }, { 288,312 }, { 196,202 }, { 268,408 }, { 213,522 }, { 486,817 }, { 231,402 }, { 14,804 }, { 825,897 }, { 408,594 }, { 524,618 }, { 10,487 }, { 262,860 }, { 301,862 }, { 246,634 }, { 582,969 }, { 284,976 }, { 271,286 }, { 397,606 }, { 239,422 }, { 432,443 }, { 359,907 }, { 355,826 }, { 268,468 }, { 173,451 }, { 356,854 }, { 546,992 }, { 170,411 }, { 486,758 }, { 84,771 }, { 868,898 }, { 149,735 }, { 767,833 }, { 12,102 }, { 302,509 }, { 414,711 }, { 970,991 }, { 83,771 }, { 97,715 }, { 389,595 }, { 215,374 }, { 182,381 }, { 313,453 }, { 531,835 }, { 461,666 }, { 496,596 }, { 58,241 }, { 334,996 }, { 526,987 }, { 263,567 }, { 200,883 }, { 73,419 }, { 58,293 }, { 553,785 }, { 502,593 }, { 462,475 }, { 606,662 }, { 84,107 }, { 698,720 }, { 99,672 }, { 528,817 }, { 260,582 }, { 563,773 }, { 187,305 }, { 253,752 }, { 152,981 }, { 379,410 }, { 30,515 }, { 248,439 }, { 217,406 }, { 113,127 }, { 332,498 }, { 142,878 }, { 136,396 }, { 228,388 }, { 11,884 }, { 42,255 }, { 4,175 }, { 660,860 }, { 521,863 }, { 69,328 }, { 796,817 }, { 92,464 }, { 142,217 }, { 214,691 }, { 981,989 }, { 354,895 }, { 268,669 }, { 80,524 }, { 703,723 }, { 129,292 }, { 141,216 }, { 634,807 }, { 350,625 }, { 53,151 }, { 106,708 }, { 2,872 }, { 93,723 }, { 35,984 }, { 778,829 }, { 521,583 }, { 95,607 }, { 342,933 }, { 425,983 }, { 71,89 }, { 3,94 }, { 448,676 }, { 362,822 }, { 233,740 }, { 145,786 }, { 2,784 }, { 47,974 }, { 287,981 }, { 565,711 }, { 34,138 }, { 312,605 }, { 566,879 }, { 335,740 }, { 255,878 }, { 657,987 }, { 207,781 }, { 235,865 }, { 435,808 }, { 292,588 }, { 126,196 }, { 834,988 }, { 530,961 }, { 536,709 }, { 461,824 }, { 394,577 }, { 192,832 }, { 525,752 }, { 297,725 }, { 33,35 }, { 257,838 }, { 65,276 }, { 402,876 }, { 478,747 }, { 692,801 }, { 61,809 }, { 466,550 }, { 261,412 }, { 178,608 }, { 134,266 }, { 611,765 }, { 45,740 }, { 6,719 }, { 154,406 }, { 268,662 }, { 46,233 }, { 761,977 }, { 74,370 }, { 151,581 }, { 21,753 }, { 268,995 }, { 25,573 }, { 772,937 }, { 27,181 }, { 275,556 }, { 11,45 }, { 375,915 }, { 649,991 }, { 515,616 }, { 123,987 }, { 522,544 }, { 320,488 }, { 210,370 }, { 101,702 }, { 216,659 }, { 396,812 }, { 657,911 }, { 672,674 }, { 14,540 }, { 140,580 }, { 403,835 }, { 230,608 }, { 120,315 }, { 275,304 }, { 806,973 }, { 49,796 }, { 398,729 }, { 527,772 }, { 113,674 }, { 154,452 }, { 233,971 }, { 362,480 }, { 467,509 }, { 249,797 }, { 33,666 }, { 9,991 }, { 219,576 }, { 136,857 }, { 911,945 }, { 521,791 }, { 98,949 }, { 337,507 }, { 446,522 }, { 589,891 }, { 578,609 }, { 835,987 }, { 99,464 }, { 192,845 }, { 10,731 }, { 479,506 }, { 286,456 }, { 137,677 }, { 211,239 }, { 116,161 }, { 699,752 }, { 20,251 }, { 692,893 }, { 580,957 }, { 636,837 }, { 180,972 }, { 424,546 }, { 317,331 }, { 175,915 }, { 19,187 }, { 360,862 }, { 43,944 }, { 322,849 }, { 614,665 }, { 85,985 }, { 156,337 }, { 401,751 }, { 202,327 }, { 250,836 }, { 557,788 }, { 470,988 }, { 4,282 }, { 683,932 }, { 491,534 }, { 765,888 }, { 19,235 }, { 127,843 }, { 339,677 }, { 108,190 }, { 122,199 }, { 213,886 }, { 383,742 }, { 526,932 }, { 163,678 }, { 167,271 }, { 643,914 }, { 271,644 }, { 187,572 }, { 122,679 }, { 398,985 }, { 290,905 }, { 487,741 }, { 81,493 }, { 639,713 }, { 311,790 }, { 3,47 }, { 150,844 }, { 585,979 }, { 283,316 }, { 232,271 }, { 59,616 }, { 233,858 }, { 143,398 }, { 308,966 }, { 452,879 }, { 467,845 }, { 87,674 }, { 464,604 }, { 101,141 }, { 144,972 }, { 372,650 }, { 796,982 }, { 39,568 }, { 95,294 }, { 327,633 }, { 890,962 }, { 282,407 }, { 281,326 }, { 352,788 }, { 570,902 }, { 757,921 }, { 531,784 }, { 236,284 }, { 445,865 }, { 360,724 }, { 317,761 }, { 66,328 }, { 194,340 }, { 409,562 }, { 362,688 }, { 569,876 }, { 195,953 }, { 855,918 }, { 416,864 }, { 213,273 }, { 269,947 }, { 63,529 }, { 833,916 }, { 28,914 }, { 830,940 }, { 203,303 }, { 159,974 }, { 551,819 }, { 300,618 }, { 290,553 }, { 518,921 }, { 158,455 }, { 835,947 }, { 252,508 }, { 117,260 }, { 305,376 }, { 335,465 }, { 96,445 }, { 210,513 }, { 556,644 }, { 300,547 }, { 72,928 }, { 253,558 }, { 343,585 }, { 93,515 }, { 535,810 }, { 385,741 }, { 392,965 }, { 99,141 }, { 188,535 }, { 19,921 }, { 241,596 }, { 141,300 }, { 321,732 }, { 697,727 }, { 170,925 }, { 151,745 }, { 616,856 }, { 383,465 }, { 311,697 }, { 306,695 }, { 160,856 }, { 22,596 }, { 258,718 }, { 194,906 }, { 632,749 }, { 427,987 }, { 307,356 }, { 23,888 }, { 375,968 }, { 186,313 }, { 135,431 }, { 27,439 }, { 331,931 }, { 444,991 }, { 477,675 }, { 728,740 }, { 596,868 }, { 307,857 }, { 223,463 }, { 214,470 }, { 244,263 }, { 610,711 }, { 198,773 }, { 241,984 }, { 335,940 }, { 12,677 }, { 358,538 }, { 675,761 }, { 560,825 }, { 355,929 }, { 821,983 }, { 83,571 }, { 513,702 }, { 341,476 }, { 475,868 }, { 334,352 }, { 811,956 }, { 233,295 }, { 43,557 }, { 487,817 }, { 519,829 }, { 470,728 }, { 574,754 }, { 54,857 }, { 144,828 }, { 140,254 }, { 556,859 }, { 165,868 }, { 317,909 }, { 43,263 }, { 323,380 }, { 119,239 }, { 356,554 }, { 44,511 }, { 626,915 }, { 205,389 }, { 166,816 }, { 521,899 }, { 98,773 }, { 338,343 }, { 79,355 }, { 260,798 }, { 209,850 }, { 166,176 }, { 804,820 }, { 296,805 }, { 85,338 }, { 406,608 }, { 97,954 }, { 201,775 }, { 681,890 }, { 33,601 }, { 251,834 }, { 776,956 }, { 138,551 }, { 195,924 }, { 112,137 }, { 862,987 }, { 461,806 }, { 19,228 }, { 354,647 }, { 257,984 }, { 499,971 }, { 33,237 }, { 30,541 }, { 151,727 }, { 337,529 }, { 25,386 }, { 47,300 }, { 548,582 }, { 302,312 }, { 7,868 }, { 66,117 }, { 154,622 }, { 462,594 }, { 622,752 }, { 641,710 }, { 527,760 }, { 152,536 }, { 406,879 }, { 200,331 }, { 98,866 }, { 245,503 }, { 285,894 }, { 73,583 }, { 2,323 }, { 62,419 }, { 137,407 }, { 199,461 }, { 771,865 }, { 515,721 }, { 168,243 }, { 629,655 }, { 298,432 }, { 442,562 }, { 688,784 }, { 492,747 }, { 638,831 }, { 86,284 }, { 177,514 }, { 633,894 }, { 180,343 }, { 253,830 }, { 208,604 }, { 884,967 }, { 531,592 }, { 131,644 }, { 6,185 }, { 174,319 }, { 169,266 }, { 11,272 }, { 236,897 }, { 232,484 }, { 442,796 }, { 108,642 }, { 173,514 }, { 133,418 }, { 305,807 }, { 8,858 }, { 420,811 }, { 219,246 }, { 305,648 }, { 443,791 }, { 356,828 }, { 76,353 }, { 19,156 }, { 263,631 }, { 126,377 }, { 208,726 }, { 449,814 }, { 236,792 }, { 7,207 }, { 144,156 }, { 143,532 }, { 181,775 }, { 61,125 }, { 266,568 }, { 469,569 }, { 293,797 }, { 299,665 }, { 357,437 }, { 732,916 }, { 231,736 }, { 635,915 }, { 378,632 }, { 83,790 }, { 450,731 }, { 722,894 }, { 678,795 }, { 386,710 }, { 325,411 }, { 131,491 }, { 840,886 }, { 730,761 }, { 401,938 }, { 71,660 }, { 278,426 }, { 668,770 }, { 522,556 }, { 585,864 }, { 429,597 }, { 18,933 }, { 335,618 }, { 220,934 }, { 676,944 }, { 217,548 }, { 413,764 }, { 271,479 }, { 657,804 }, { 56,510 }, { 354,366 }, { 738,904 }, { 117,796 }, { 555,674 }, { 214,684 }, { 285,996 }, { 105,309 }, { 395,558 }, { 153,388 }, { 656,756 }, { 143,688 }, { 341,587 }, { 810,827 }, { 310,648 }, { 3,992 }, { 334,943 }, { 367,768 }, { 376,711 }, { 385,864 }, { 93,472 }, { 473,706 }, { 597,924 }, { 694,845 }, { 47,522 }, { 155,184 }, { 270,718 }, { 213,525 }, { 896,948 }, { 276,673 }, { 115,874 }, { 485,887 }, { 760,825 }, { 66,95 }, { 691,874 }, { 62,787 }, { 440,594 }, { 79,356 }, { 640,672 }, { 527,840 }, { 44,596 }, { 431,762 }, { 16,455 }, { 682,975 }, { 353,567 }, { 731,748 }, { 242,820 }, { 55,387 }, { 476,562 }, { 516,906 }, { 247,834 }, { 652,989 }, { 656,742 }, { 35,962 }, { 310,610 }, { 431,992 }, { 660,679 }, { 440,915 }, { 190,505 }, { 87,566 }, { 418,483 }, { 581,881 }, { 328,681 }, { 83,366 }, { 30,900 }, { 64,432 }, { 134,710 }, { 200,452 }, { 256,440 }, { 575,893 }, { 530,756 }, { 71,666 }, { 739,900 }, { 289,566 }, { 489,575 }, { 196,985 }, { 191,646 }, { 427,697 }, { 231,500 }, { 185,953 }, { 29,134 }, { 80,236 }, { 28,582 }, { 330,724 }, { 690,886 }, { 198,898 }, { 473,681 }, { 439,790 }, { 95,573 }, { 100,942 }, { 460,615 }, { 182,283 }, { 264,380 }, { 424,606 }, { 115,534 }, { 352,792 }, { 34,655 }, { 644,902 }, { 35,724 }, { 400,934 }, { 377,390 }, { 123,257 }, { 257,735 }, { 447,453 }, { 194,593 }, { 190,256 }, { 362,889 }, { 192,993 }, { 210,508 }, { 8,437 }, { 229,428 }, { 2,124 }, { 73,448 }, { 618,763 }, { 469,717 }, { 487,830 }, { 90,700 }, { 111,878 }, { 562,989 }, { 233,252 }, { 340,687 }, { 143,536 }, { 82,202 }, { 145,749 }, { 808,962 }, { 43,405 }, { 340,726 }, { 526,742 }, { 194,889 }, { 553,656 }, { 173,541 }, { 158,905 }, { 264,781 }, { 223,418 }, { 130,598 }, { 93,442 }, { 420,631 }, { 178,556 }, { 40,158 }, { 415,700 }, { 174,520 }, { 454,981 }, { 795,980 }, { 687,759 }, { 651,715 }, { 325,598 }, { 292,715 }, { 175,987 }, { 85,165 }, { 437,807 }, { 719,949 }, { 184,977 }, { 403,725 }, { 309,771 }, { 284,797 }, { 6,512 }, { 41,929 }, { 524,660 }, { 165,229 }, { 741,756 }, { 3,536 }, { 663,752 }, { 291,567 }, { 482,591 }, { 367,428 }, { 720,721 }, { 448,604 }, { 459,525 }, { 185,254 }, { 380,918 }, { 752,841 }, { 64,544 }, { 595,869 }, { 469,559 }, { 122,672 }, { 271,776 }, { 489,770 }, { 26,786 }, { 270,807 }, { 740,986 }, { 31,825 }, { 247,754 }, { 295,703 }, { 13,467 }, { 18,538 }, { 342,609 }, { 176,238 }, { 298,887 }, { 97,474 }, { 29,568 }, { 313,589 }, { 196,271 }, { 601,855 }, { 379,648 }, { 215,834 }, { 258,983 }, { 227,635 }, { 899,944 }, { 290,949 }, { 551,585 }, { 267,688 }, { 536,762 }, { 208,822 }, { 260,357 }, { 167,800 }, { 650,866 }, { 275,490 }, { 94,563 }, { 773,908 }, { 247,612 }, { 105,894 }, { 311,715 }, { 363,724 }, { 197,553 }, { 4,580 }, { 757,883 }, { 258,885 }, { 42,732 }, { 635,667 }, { 72,618 }, { 123,574 }, { 629,988 }, { 327,662 }, { 67,567 }, { 802,898 }, { 126,413 }, { 7,881 }, { 144,540 }, { 378,644 }, { 65,445 }, { 314,843 }, { 0,277 }, { 317,849 }, { 41,406 }, { 738,915 }, { 48,581 }, { 84,227 }, { 161,803 }, { 641,844 }, { 738,767 }, { 335,652 }, { 48,486 }, { 76,857 }, { 363,790 }, { 223,589 }, { 211,681 }, { 22,397 }, { 683,916 }, { 378,645 }, { 207,455 }, { 513,592 }, { 475,849 }, { 13,441 }, { 336,880 }, { 803,926 }, { 32,564 }, { 820,960 }, { 288,931 }, { 735,933 }, { 295,572 }, { 235,434 }, { 27,300 }, { 60,640 }, { 347,839 }, { 674,879 }, { 160,305 }, { 418,628 }, { 59,414 }, { 46,374 }, { 489,930 }, { 740,827 }, { 89,766 }, { 10,44 }, { 431,603 }, { 317,484 }, { 307,945 }, { 65,71 }, { 295,873 }, { 951,989 }, { 477,537 }, { 321,526 }, { 144,830 }, { 263,283 }, { 319,728 }, { 631,745 }, { 339,643 }, { 255,809 }, { 402,510 }, { 133,565 }, { 251,257 }, { 153,829 }, { 32,574 }, { 8,285 }, { 340,350 }, { 334,898 }, { 467,959 }, { 95,643 }, { 266,788 }, { 163,498 }, { 270,621 }, { 503,744 }, { 639,672 }, { 51,66 }, { 553,980 }, { 12,353 }, { 60,626 }, { 367,654 }, { 673,895 }, { 605,882 }, { 469,739 }, { 60,832 }, { 170,913 }, { 101,195 }, { 117,304 }, { 149,292 }, { 92,773 }, { 32,737 }, { 13,885 }, { 502,940 }, { 147,653 }, { 92,268 }, { 375,628 }, { 474,638 }, { 310,746 }, { 258,388 }, { 253,705 }, { 352,371 }, { 11,563 }, { 68,369 }, { 287,599 }, { 310,984 }, { 250,893 }, { 558,614 }, { 530,608 }, { 507,709 }, { 375,392 }, { 360,609 }, { 53,304 }, { 804,991 }, { 608,612 }, { 205,826 }, { 299,582 }, { 407,979 }, { 539,893 }, { 756,789 }, { 228,556 }, { 212,933 }, { 122,309 }, { 223,934 }, { 461,919 }, { 187,836 }, { 728,760 }, { 556,962 }, { 809,884 }, { 185,907 }, { 770,858 }, { 411,876 }, { 451,794 }, { 285,387 }, { 326,541 }, { 614,985 }, { 105,440 }, { 611,986 }, { 283,701 }, { 507,855 }, { 168,731 }, { 412,518 }, { 132,970 }, { 825,853 }, { 293,357 }, { 528,682 }, { 534,610 }, { 37,278 }, { 536,662 }, { 55,128 }, { 158,184 }, { 52,488 }, { 576,648 }, { 50,343 }, { 242,288 }, { 387,938 }, { 282,905 }, { 25,31 }, { 568,955 }, { 139,260 }, { 709,976 }, { 459,854 }, { 47,970 }, { 345,944 }, { 493,838 }, { 316,455 }, { 280,753 }, { 418,692 }, { 468,691 }, { 834,942 }, { 381,644 }, { 51,366 }, { 423,744 }, { 232,914 }, { 24,510 }, { 282,318 }, { 854,895 }, { 284,570 }, { 650,957 }, { 3,390 }, { 290,723 }, { 508,876 }, { 234,843 }, { 291,801 }, { 23,395 }, { 179,766 }, { 142,837 }, { 528,572 }, { 635,984 }, { 446,783 }, { 332,854 }, { 675,875 }, { 497,933 }, { 86,756 }, { 679,965 }, { 78,140 }, { 360,869 }, { 847,925 }, { 197,223 }, { 215,737 }, { 557,709 }, { 403,595 }, { 22,339 }, { 289,341 }, { 125,848 }, { 225,676 }, { 350,608 }, { 355,874 }, { 584,868 }, { 108,325 }, { 615,634 }, { 565,807 }, { 804,981 }, { 167,558 }, { 98,784 }, { 111,489 }, { 43,174 }, { 46,939 }, { 180,690 }, { 293,916 }, { 3,291 }, { 14,545 }, { 74,880 }, { 397,639 }, { 700,962 }, { 310,598 }, { 333,385 }, { 406,907 }, { 72,348 }, { 95,699 }, { 224,397 }, { 639,681 }, { 205,331 }, { 556,887 }, { 78,173 }, { 61,467 }, { 284,464 }, { 463,771 }, { 114,592 }, { 49,412 }, { 292,888 }, { 790,885 }, { 694,914 }, { 464,737 }, { 535,551 }, { 284,313 }, { 92,994 }, { 495,612 }, { 42,378 }, { 764,934 }, { 716,936 }, { 578,679 }, { 268,520 }, { 558,725 }, { 66,953 }, { 69,340 }, { 7,61 }, { 234,731 }, { 128,637 }, { 603,959 }, { 225,886 }, { 131,299 }, { 74,848 }, { 130,968 }, { 216,360 }, { 291,731 }, { 150,770 }, { 454,905 }, { 208,733 }, { 251,381 }, { 218,245 }, { 203,778 }, { 80,226 }, { 238,419 }, { 388,918 }, { 307,983 }, { 76,524 }, { 738,793 }, { 825,975 }, { 251,737 }, { 23,440 }, { 420,782 }, { 791,878 }, { 67,517 }, { 537,689 }, { 473,973 }, { 597,963 }, { 615,732 }, { 206,670 }, { 95,718 }, { 495,711 }, { 725,738 }, { 23,240 }, { 735,879 }, { 70,950 }, { 100,759 }, { 445,617 }, { 139,279 }, { 219,857 }, { 578,820 }, { 419,789 }, { 209,401 }, { 465,492 }, { 457,996 }, { 391,490 }, { 541,926 }, { 623,648 }, { 130,422 }, { 447,945 }, { 648,780 }, { 569,652 }, { 157,752 }, { 199,570 }, { 79,792 }, { 952,994 }, { 165,271 }, { 353,802 }, { 616,884 }, { 261,902 }, { 548,971 }, { 190,696 }, { 207,890 }, { 299,677 }, { 545,833 }, { 37,97 }, { 668,893 }, { 249,842 }, { 7,280 }, { 658,915 }, { 728,782 }, { 773,840 }, { 512,847 }, { 82,142 }, { 912,937 }, { 129,251 }, { 623,968 }, { 97,135 }, { 540,658 }, { 198,592 }, { 443,667 }, { 371,664 }, { 130,381 }, { 35,188 }, { 100,404 }, { 157,436 }, { 350,830 }, { 238,678 }, { 265,786 }, { 539,602 }, { 114,838 }, { 479,962 }, { 26,659 }, { 114,305 }, { 108,418 }, { 50,665 }, { 178,601 }, { 176,861 }, { 191,496 }, { 146,689 }, { 31,685 }, { 752,915 }, { 418,654 }, { 230,588 }, { 568,791 }, { 511,643 }, { 369,973 }, { 5,207 }, { 503,712 }, { 544,976 }, { 379,595 }, { 162,664 }, { 410,558 }, { 330,986 }, { 214,694 }, { 203,315 }, { 485,995 }, { 595,773 }, { 213,795 }, { 50,503 }, { 385,473 }, { 408,428 }, { 653,834 }, { 2,267 }, { 675,910 }, { 129,697 }, { 195,750 }, { 772,967 }, { 643,964 }, { 564,658 }, { 448,586 }, { 926,962 }, { 701,820 }, { 45,409 }, { 781,923 }, { 11,933 }, { 475,565 }, { 143,755 }, { 197,524 }, { 0,720 }, { 642,936 }, { 178,988 }, { 100,395 }, { 458,466 }, { 590,611 }, { 99,232 }, { 504,688 }, { 973,994 }, { 11,849 }, { 662,741 }, { 121,533 }, { 934,972 }, { 642,696 }, { 229,616 }, { 91,512 }, { 314,352 }, { 78,697 }, { 626,980 }, { 131,219 }, { 356,407 }, { 207,511 }, { 219,788 }, { 522,965 }, { 540,591 }, { 422,701 }, { 69,857 }, { 552,608 }, { 493,808 }, { 803,947 }, { 73,836 }, { 51,568 }, { 51,112 }, { 561,741 }, { 360,598 }, { 334,795 }, { 419,524 }, { 201,682 }, { 746,832 }, { 122,800 }, { 629,636 }, { 258,835 }, { 216,248 }, { 419,913 }, { 315,729 }, { 82,594 }, { 159,953 }, { 16,595 }, { 670,717 }, { 643,744 }, { 547,749 }, { 724,855 }, { 836,911 }, { 334,890 }, { 513,993 }, { 337,940 }, { 249,655 }, { 241,322 }, { 457,810 }, { 335,805 }, { 549,789 }, { 649,984 }, { 705,783 }, { 493,501 }, { 409,485 }, { 329,862 }, { 25,412 }, { 167,407 }, { 543,694 }, { 401,506 }, { 278,613 }, { 337,608 }, { 490,745 }, { 220,517 }, { 505,883 }, { 661,925 }, { 194,819 }, { 760,919 }, { 247,495 }, { 742,972 }, { 760,916 }, { 433,692 }, { 265,942 }, { 324,597 }, { 387,412 }, { 95,126 }, { 55,880 }, { 759,972 }, { 887,892 }, { 482,749 }, { 778,916 }, { 699,756 }, { 465,731 }, { 263,640 }, { 77,362 }, { 798,824 }, { 175,774 }, { 124,400 }, { 501,797 }, { 473,647 }, { 101,621 }, { 561,938 }, { 77,437 }, { 234,536 }, { 244,843 }, { 347,837 }, { 199,299 }, { 478,665 }, { 849,945 }, { 45,413 }, { 782,820 }, { 686,773 }, { 83,116 }, { 517,519 }, { 329,852 }, { 253,810 }, { 406,711 }, { 608,725 }, { 599,963 }, { 172,887 }, { 465,998 }, { 132,626 }, { 142,767 }, { 189,365 }, { 91,452 }, { 242,944 }, { 474,747 }, { 183,522 }, { 344,652 }, { 98,948 }, { 183,684 }, { 112,746 }, { 401,922 }, { 79,274 }, { 445,842 }, { 857,860 }, { 90,854 }, { 164,278 }, { 669,706 }, { 160,407 }, { 711,937 }, { 217,704 }, { 428,677 }, { 30,407 }, { 384,952 }, { 371,492 }, { 410,519 }, { 363,592 }, { 159,518 }, { 557,687 }, { 307,677 }, { 513,767 }, { 811,904 }, { 272,749 }, { 758,863 }, { 799,906 }, { 169,752 }, { 547,797 }, { 522,572 }, { 342,646 }, { 8,595 }, { 428,442 }, { 254,772 }, { 346,778 }, { 67,935 }, { 234,284 }, { 92,778 }, { 274,316 }, { 452,674 }, { 66,150 }, { 253,477 }, { 703,848 }, { 869,900 }, { 845,987 }, { 308,359 }, { 425,545 }, { 780,829 }, { 4,846 }, { 502,842 }, { 120,697 }, { 86,768 }, { 206,451 }, { 520,939 }, { 498,813 }, { 495,871 }, { 49,488 }, { 608,797 }, { 181,610 }, { 33,41 }, { 139,293 }, { 96,514 }, { 839,883 }, { 229,722 }, { 8,71 }, { 42,326 }, { 102,684 }, { 618,796 }, { 577,905 }, { 284,734 }, { 187,333 }, { 310,745 }, { 341,997 }, { 629,630 }, { 861,965 }, { 617,964 }, { 220,845 }, { 173,481 }, { 261,878 }, { 335,934 }, { 110,879 }, { 222,266 }, { 446,454 }, { 119,516 }, { 147,660 }, { 122,771 }, { 540,609 }, { 13,670 }, { 269,727 } }
    ;
    succProb = { 0.88, 0.59, 0.67, 0.93, 0.76, 0.88, 0.9, 0.95, 0.7, 0.95, 0.69, 0.87, 0.7, 0.74, 0.95, 0.89, 0.71, 0.87, 0.83, 0.98, 0.91, 0.75, 0.63, 0.85, 0.9, 0.7, 0.73, 0.58, 0.56, 0.58, 0.88, 0.78, 0.98, 0.58, 0.94, 0.93, 0.91, 0.81, 0.7, 0.71, 0.75, 0.74, 0.78, 0.58, 0.89, 0.68, 0.99, 0.93, 0.63, 0.53, 0.64, 0.57, 0.91, 0.7, 0.99, 0.66, 0.69, 0.89, 0.83, 0.66, 0.77, 0.85, 0.53, 0.96, 0.95, 0.79, 0.86, 0.54, 0.97, 0.61, 0.66, 0.59, 0.67, 0.55, 0.73, 0.68, 0.96, 0.99, 0.59, 0.67, 0.81, 0.61, 0.92, 0.69, 0.93, 0.7, 0.99, 0.76, 0.81, 0.85, 1.0, 0.54, 0.8, 0.55, 0.51, 0.89, 0.83, 0.75, 0.92, 0.75, 0.8, 0.58, 0.88, 0.73, 0.73, 0.93, 0.52, 0.52, 0.61, 0.54, 0.88, 0.55, 0.91, 0.53, 0.63, 0.56, 0.52, 0.92, 0.54, 0.86, 0.8, 0.77, 0.85, 0.66, 0.82, 0.94, 0.84, 0.64, 0.8, 0.52, 0.92, 0.59, 0.97, 0.87, 0.67, 0.71, 0.81, 0.71, 0.93, 0.89, 0.77, 0.59, 0.86, 0.62, 0.64, 0.51, 0.69, 0.93, 0.59, 0.74, 0.99, 0.8, 0.53, 0.85, 0.69, 0.92, 0.62, 0.9, 0.83, 0.74, 0.85, 0.93, 0.87, 0.85, 0.59, 0.93, 0.56, 0.98, 0.59, 0.75, 0.89, 0.64, 0.53, 0.65, 0.72, 0.88, 0.78, 0.76, 0.56, 0.85, 0.71, 0.81, 0.53, 0.77, 0.91, 0.55, 0.7, 0.65, 0.62, 0.67, 0.82, 0.68, 0.72, 0.92, 0.76, 0.67, 0.62, 0.95, 0.64, 0.92, 0.77, 0.93, 0.87, 1.0, 0.92, 0.86, 0.59, 0.62, 0.62, 0.54, 0.65, 0.79, 0.8, 0.93, 0.92, 0.53, 0.88, 0.58, 0.67, 1.0, 0.82, 1.0, 0.7, 0.8, 0.62, 0.68, 0.86, 0.62, 0.69, 0.52, 0.76, 0.53, 0.57, 0.52, 0.55, 0.92, 0.6, 0.98, 0.52, 0.88, 0.89, 0.68, 0.78, 0.87, 0.92, 0.96, 0.82, 0.97, 0.54, 0.92, 0.81, 0.53, 0.92, 0.87, 0.74, 0.68, 0.77, 0.99, 0.89, 0.84, 0.65, 0.88, 0.53, 0.97, 0.66, 0.72, 0.97, 0.56, 0.57, 0.59, 0.76, 0.81, 0.77, 0.95, 0.82, 0.67, 0.61, 0.86, 0.58, 0.83, 0.83, 0.51, 0.65, 0.6, 0.53, 0.61, 0.75, 0.63, 0.8, 0.94, 0.86, 0.75, 0.52, 0.81, 0.91, 0.61, 0.57, 0.78, 0.85, 0.62, 0.56, 0.59, 0.89, 0.56, 0.94, 0.84, 0.88, 0.7, 0.9, 0.72, 0.94, 0.94, 0.91, 0.94, 0.69, 0.98, 0.86, 0.51, 0.69, 0.8, 0.69, 0.89, 0.61, 0.85, 0.55, 0.55, 0.92, 0.85, 0.76, 0.74, 0.91, 0.7, 0.66, 0.54, 0.6, 0.51, 0.55, 0.83, 0.86, 0.66, 0.61, 0.67, 0.67, 0.84, 0.85, 0.68, 0.81, 0.89, 0.73, 0.98, 0.65, 0.96, 0.53, 0.54, 0.7, 0.89, 0.91, 0.82, 0.72, 0.65, 0.93, 1.0, 0.87, 0.92, 0.54, 0.9, 0.71, 0.69, 0.5, 0.75, 0.5, 0.95, 0.98, 0.95, 0.64, 0.84, 0.56, 0.98, 0.9, 0.7, 0.7, 0.51, 0.52, 0.73, 0.9, 0.86, 0.59, 0.69, 0.57, 0.72, 0.87, 0.9, 0.53, 0.79, 0.74, 0.98, 0.83, 0.64, 0.7, 0.78, 0.62, 0.51, 0.85, 0.57, 0.95, 0.54, 0.8, 0.95, 0.97, 0.94, 0.89, 0.53, 0.8, 0.9, 0.81, 0.72, 0.89, 0.69, 0.51, 0.87, 0.54, 0.91, 0.99, 0.67, 0.82, 0.75, 0.84, 0.57, 0.69, 0.69, 0.89, 0.93, 0.51, 0.82, 0.57, 0.73, 0.68, 0.8, 0.62, 0.94, 0.64, 0.6, 0.62, 0.81, 0.52, 0.72, 0.52, 0.92, 0.97, 0.59, 0.86, 0.71, 0.67, 0.75, 0.76, 0.79, 0.88, 0.52, 0.88, 0.88, 0.79, 0.79, 0.83, 0.71, 0.74, 0.62, 0.68, 0.68, 0.7, 0.69, 0.92, 0.98, 0.67, 0.94, 0.7, 0.81, 0.97, 0.63, 0.68, 0.78, 0.92, 0.69, 0.64, 0.52, 0.62, 0.55, 0.51, 0.53, 0.76, 0.71, 0.7, 0.65, 0.61, 0.51, 0.64, 0.85, 0.95, 0.95, 0.61, 0.59, 0.54, 0.81, 0.54, 0.98, 0.7, 0.57, 0.95, 0.85, 0.72, 0.78, 0.98, 0.88, 0.95, 0.86, 0.91, 0.52, 0.79, 0.97, 0.59, 0.69, 0.95, 0.94, 0.54, 0.62, 0.56, 0.51, 0.87, 0.99, 0.52, 0.51, 0.69, 0.9, 0.94, 0.73, 0.79, 1.0, 0.97, 0.5, 0.84, 0.57, 0.55, 0.88, 0.8, 0.96, 0.57, 0.68, 0.82, 0.62, 0.77, 0.73, 0.79, 0.89, 0.54, 0.93, 0.96, 0.77, 0.68, 0.62, 0.66, 0.59, 0.98, 0.57, 0.51, 0.92, 0.59, 0.5, 0.73, 0.62, 0.99, 0.88, 0.68, 0.58, 0.73, 0.59, 0.58, 0.87, 0.93, 0.92, 0.51, 0.88, 0.92, 0.57, 0.55, 0.88, 0.94, 0.95, 0.84, 0.76, 0.87, 0.85, 0.61, 0.7, 0.8, 0.69, 0.59, 0.7, 0.77, 0.91, 0.56, 0.52, 0.85, 0.89, 0.88, 0.55, 0.72, 0.91, 0.7, 0.62, 0.54, 0.94, 0.69, 0.79, 0.64, 0.53, 0.65, 0.73, 0.92, 0.77, 0.77, 0.55, 0.74, 0.96, 0.6, 0.58, 0.88, 0.94, 0.54, 0.58, 0.95, 0.69, 0.9, 0.78, 0.56, 0.51, 0.9, 0.55, 0.58, 0.81, 0.67, 0.82, 0.74, 0.55, 0.8, 0.75, 0.54, 0.7, 0.9, 0.78, 0.8, 0.81, 0.65, 0.93, 0.53, 0.73, 0.6, 0.67, 0.81, 0.62, 0.7, 0.65, 0.72, 0.61, 0.86, 0.99, 0.87, 0.72, 0.53, 0.83, 0.91, 0.81, 0.86, 0.86, 0.78, 0.57, 0.98, 0.56, 0.98, 0.97, 0.56, 0.91, 0.9, 0.6, 0.53, 0.51, 0.87, 0.69, 0.98, 0.52, 0.8, 0.56, 0.57, 0.61, 0.9, 0.73, 0.8, 0.6, 0.9, 0.79, 0.62, 0.57, 0.73, 0.76, 0.97, 0.87, 0.82, 0.76, 0.91, 0.86, 0.88, 0.51, 0.54, 0.77, 0.62, 0.72, 0.51, 0.92, 0.52, 0.82, 0.94, 0.81, 0.59, 0.66, 0.58, 0.67, 0.92, 0.5, 0.91, 0.97, 0.93, 0.81, 0.67, 0.68, 0.9, 0.54, 0.9, 0.84, 0.85, 0.62, 0.95, 0.81, 0.76, 0.54, 0.62, 0.83, 0.75, 0.66, 0.8, 0.74, 0.96, 0.84, 0.6, 0.73, 0.81, 0.55, 0.69, 0.81, 0.84, 0.74, 0.77, 0.87, 0.81, 0.82, 0.82, 0.86, 0.51, 0.64, 0.62, 0.69, 0.53, 0.86, 0.53, 0.56, 0.55, 0.95, 0.59, 0.73, 0.62, 0.97, 0.58, 0.68, 0.87, 0.74, 0.81, 0.54, 0.98, 0.86, 0.75, 0.87, 0.53, 0.55, 0.6, 0.79, 0.75, 0.75, 0.55, 0.88, 0.77, 0.75, 0.53, 0.96, 0.84, 0.63, 0.67, 0.89, 0.63, 0.97, 0.62, 0.56, 0.81, 0.61, 0.69, 0.7, 0.98, 0.65, 0.6, 0.96, 0.82, 0.75, 0.69, 0.74, 0.82, 0.91, 0.86, 0.85, 0.89, 0.51, 0.51, 0.6, 0.81, 0.68, 0.9, 0.74, 1.0, 0.85, 0.53, 0.72, 0.5, 0.74, 0.54, 0.69, 0.75, 0.71, 0.95, 0.77, 0.77, 0.84, 0.55, 0.74, 0.61, 0.54, 0.65, 0.94, 0.67, 0.71, 0.65, 0.91, 1.0, 0.7, 0.62, 0.65, 0.81, 0.78, 0.76, 0.88, 0.7, 0.88, 0.79, 0.67, 0.94, 0.98, 0.67, 0.64, 0.63, 0.56, 0.97, 0.68, 0.89, 0.59, 0.7, 0.52, 0.61, 0.84, 0.87, 0.75, 0.9, 0.61, 0.52, 1.0, 0.88, 0.82, 0.64, 0.72, 0.81, 0.89, 0.98, 0.63, 0.99, 0.63, 0.8, 0.72, 0.91, 0.56, 0.98, 0.7, 0.93, 0.68, 0.7, 0.58, 0.93, 0.66, 0.99, 0.81, 0.89, 0.82, 0.94, 0.81, 0.87, 0.57, 0.52, 0.8, 0.84, 0.5, 0.83, 0.73, 0.84, 0.5, 0.72, 0.74, 0.82, 0.56, 0.74, 0.76, 0.83, 0.74, 0.54, 0.62, 0.96, 0.61, 0.53, 0.59, 0.87, 0.96, 0.6, 0.67, 0.99, 0.72, 0.94, 0.57, 0.88, 0.55, 0.77, 0.89, 0.83, 0.68, 0.86, 0.81, 0.6, 0.58, 0.56, 0.79, 0.65, 0.61, 0.54, 0.66, 0.52, 0.61, 0.64, 0.88, 0.71, 0.52, 0.84, 0.81, 0.92, 0.64, 0.64, 0.95, 0.53, 0.92, 0.69, 0.8, 0.81, 0.54, 0.7, 0.55, 0.81, 0.95, 0.99, 0.59, 0.9, 0.97, 0.67, 0.69, 0.88, 0.58, 0.55, 0.58, 0.91, 0.57, 0.8, 0.59, 0.72, 0.64, 0.95, 0.54, 0.51, 0.63, 0.89, 0.92, 0.78, 0.71, 0.66, 0.73, 0.8, 0.66, 0.95, 0.54, 0.51, 0.78, 0.7, 0.76, 0.86, 0.59, 0.76, 0.64, 0.81, 0.58, 0.62, 0.86, 0.89, 0.6, 0.74, 0.78, 0.9, 0.72, 0.91, 0.63, 0.69, 0.76, 0.58, 0.97, 0.9, 0.77, 0.78, 0.5, 0.78, 0.69, 0.78, 1.0, 0.52, 0.81, 0.9, 0.56, 0.69, 0.58, 0.58, 0.6, 0.68, 0.82, 0.99, 0.52, 0.92, 0.67, 0.61, 0.71, 0.99, 0.56, 0.6, 0.62, 0.85, 0.84, 0.99, 0.59, 0.51, 0.78, 0.85, 0.54, 0.7, 0.9, 0.56, 0.89, 0.91, 0.52, 0.5, 0.63, 0.6, 0.65, 0.94, 0.7, 0.93, 0.92, 0.64, 0.89, 0.74, 0.74, 0.64, 0.86, 0.91, 0.55, 0.9, 0.51, 0.86, 0.84, 0.56, 0.98, 1.0, 0.78, 0.72, 0.71, 0.86, 0.99, 0.64, 0.58, 0.51, 0.96, 0.68, 0.91, 0.52, 0.57, 0.79, 0.81, 0.61, 0.57, 0.86, 0.66, 0.76, 0.61, 0.56, 0.73, 0.75, 0.83, 0.69, 0.57, 0.58, 0.59, 0.53, 0.84, 0.8, 0.79, 0.8, 0.75, 0.97, 0.58, 0.89, 0.88, 0.54, 0.75, 0.71, 0.62, 0.76, 0.85, 0.52, 0.94, 0.71, 0.73, 0.8, 0.67, 0.87, 0.54, 0.72, 0.72, 0.64, 0.71, 0.66, 0.68, 0.53, 0.78, 0.65, 0.77, 0.97, 0.84, 0.57, 0.85, 0.67, 0.87, 0.59, 0.68, 0.9, 0.79, 0.54, 0.5, 0.53, 0.97, 0.74, 0.89, 0.98, 0.96, 0.9, 0.84, 0.8, 0.56, 0.67, 0.87, 0.8, 0.77, 0.62, 0.65, 0.74, 0.93, 0.7, 0.81, 0.77, 0.61, 0.85, 0.9, 0.67, 0.73, 0.87, 0.77, 0.91, 0.87, 0.93, 0.61, 0.85, 0.87, 0.76, 0.63, 0.52, 0.95, 0.84, 0.87, 0.55, 0.87, 0.76, 0.58, 0.7, 0.53, 0.93, 0.76, 0.52, 0.79, 0.68, 0.65, 0.66, 0.53, 0.89, 0.5, 0.77, 0.6, 0.52, 0.61, 0.7, 0.63, 0.88, 0.56, 0.68, 0.85, 0.87, 0.73, 0.84, 0.87, 0.55, 0.99, 0.53, 0.82, 0.91, 0.91, 0.81, 0.85, 0.57, 0.58, 0.84, 0.92, 0.74, 0.52, 0.9, 0.88, 0.75, 0.61, 0.62, 0.55, 0.56, 0.92, 0.62, 0.64, 0.56, 0.64, 0.73, 0.88, 0.98, 0.54, 0.75, 0.8, 0.53, 0.92, 0.75, 0.72, 0.94, 0.93, 0.79, 0.95, 0.61, 0.99, 0.57, 0.74, 0.56, 0.76, 0.53, 0.9, 0.65, 0.94, 0.89, 0.84, 0.87, 0.82, 0.67, 0.7, 0.87, 0.92, 0.57, 0.63, 0.87, 0.66, 0.71, 0.61, 0.7, 0.73, 0.92, 0.9, 0.75, 0.84, 0.96, 0.6, 0.58, 0.57, 0.65, 0.64, 0.63, 0.71, 0.62, 0.83, 0.58, 0.79, 0.68, 0.59, 0.85, 0.7, 0.54, 0.63, 0.91, 0.64, 0.74, 0.66, 0.76, 0.76, 0.97, 0.96, 0.95, 0.94, 0.89, 0.67, 0.69, 0.85, 0.82, 0.55, 0.64, 0.89, 0.64, 0.64, 0.87, 0.53, 0.56, 0.68, 0.55, 0.78, 0.94, 0.63, 0.85, 0.61, 0.83, 0.8, 0.61, 0.84, 0.83, 0.91, 0.76, 0.55, 0.84, 0.52, 0.96, 1.0, 0.6, 0.71, 0.97, 0.62, 0.88, 0.52, 0.69, 0.71, 0.82, 0.66, 0.87, 0.66, 0.73, 0.6, 0.58, 0.61, 0.89, 0.84, 0.53, 0.77, 0.83, 0.8, 0.51, 0.63, 0.75, 0.65, 0.95, 0.51, 0.93, 0.53, 0.51, 0.54, 0.74, 0.82, 0.54, 0.56, 0.62, 0.69, 0.7, 0.64, 0.92, 0.5, 0.54, 0.87, 0.91, 0.63, 0.9, 0.59, 0.55, 0.59, 0.6, 0.8, 0.9, 0.54, 0.89, 0.85, 0.65, 0.69, 0.8, 0.88, 0.83, 0.62, 0.75, 0.71, 0.52, 0.71, 0.89, 0.94, 0.56, 0.93, 0.92, 0.78, 0.55, 0.98, 0.52, 0.77, 0.83, 0.92, 0.78, 0.58, 0.66, 0.76, 0.53, 0.7, 0.91, 0.55, 0.55, 0.56, 0.75, 0.75, 0.81, 0.91, 0.55, 0.98, 0.94, 0.64, 0.77, 0.84, 0.93, 0.75, 0.64, 0.93, 0.87, 0.7, 0.82, 0.93, 0.66, 0.74, 0.51, 0.96, 0.85, 0.63, 0.99, 0.59, 0.9, 0.53, 0.87, 0.74, 0.68, 0.74, 1.0, 0.54, 1.0, 0.93, 0.99, 0.65, 0.71, 0.51, 0.99, 0.76, 0.6, 0.61, 0.91, 0.62, 0.93, 0.6, 0.69, 0.57, 0.82, 0.85, 0.84, 0.77, 0.66, 0.77, 0.66, 0.74, 0.94, 0.72, 0.79, 0.66, 0.94, 0.84, 0.84, 0.75, 0.52, 0.66, 0.58, 0.64, 0.52, 0.52, 0.87, 0.69, 0.75, 0.77, 0.68, 0.82, 0.87, 0.95, 0.94, 0.71, 0.53, 0.8, 0.51, 1.0, 0.93, 0.58, 0.65, 0.66, 0.66, 0.93, 1.0, 0.52, 0.52, 0.56, 0.69, 0.66, 0.52, 0.78, 0.54, 0.56, 0.58, 0.82, 0.74, 0.85, 0.51, 0.51, 0.76, 0.87, 0.81, 0.81, 0.87, 0.9, 0.85, 0.92, 0.85, 0.87, 0.97, 0.58, 0.98, 0.54, 0.81, 0.75, 0.72, 0.7, 0.56, 0.83, 0.81, 0.95, 0.8, 0.88, 0.87, 0.55, 0.95, 0.67, 0.68, 0.93, 0.71, 0.53, 0.74, 0.72, 0.92, 0.97, 0.84, 0.81, 0.86, 0.92, 0.56, 0.59, 0.59, 0.81, 0.61, 0.86, 0.89, 0.53, 0.7, 0.61, 0.57, 0.6, 0.95, 0.62, 0.6, 0.94, 0.68, 0.85, 0.72, 0.64, 0.79, 0.7, 0.82, 0.72, 0.93, 0.59, 0.7, 0.67, 0.86, 0.86, 0.77, 0.95, 0.83, 0.82, 0.93, 0.92, 0.61, 0.53, 0.94, 0.66, 0.67, 0.78, 0.88, 0.68, 0.93, 0.9, 0.82, 0.83, 0.73, 0.74, 0.6, 0.95, 0.8, 0.62, 0.99, 0.9, 0.81, 0.58, 0.6, 0.59, 0.6, 0.74, 0.81, 0.69, 0.76, 0.88, 0.82, 0.5, 0.88, 0.9, 0.86, 0.72, 0.56, 0.9, 0.84, 0.78, 0.88, 0.52, 0.83, 0.74, 0.6, 0.7, 0.99, 0.54, 0.6, 0.94, 0.79, 0.96, 0.64, 0.51, 0.64, 0.55, 0.5, 0.92, 0.57, 0.97, 0.62, 0.57, 0.76, 0.57, 0.81, 0.54, 0.59, 0.75, 0.6, 0.97, 0.68, 0.53, 0.6, 0.64, 0.88, 0.88, 0.97, 0.91, 0.62, 0.7, 0.91, 0.56, 0.61, 0.82, 0.99, 0.7, 0.93, 0.93, 0.71, 0.81, 0.64, 0.87, 0.76, 0.75, 0.97, 0.92, 0.91, 0.53, 0.68, 0.78, 0.95, 0.58, 0.72, 0.88, 0.57, 0.61, 0.86, 0.83, 0.91, 0.6, 0.74, 0.83, 0.59, 0.69, 0.77, 0.73, 0.76, 0.8, 0.69, 0.74, 0.85, 0.82, 0.98, 0.75, 0.67, 0.52, 0.57, 0.72, 0.73, 0.71, 0.79, 0.86, 0.55, 0.99, 0.84, 0.97, 0.74, 0.77, 0.71, 0.8, 0.77, 0.85, 0.73, 0.61, 0.85, 0.56, 0.91, 0.74, 0.54, 0.69, 0.84, 0.91, 0.94, 0.86, 0.53, 0.58, 0.53, 0.6, 0.8, 0.84, 0.95, 0.96, 0.72, 0.65, 0.64, 0.84, 0.93, 0.53, 0.63, 0.76, 0.55, 0.9, 0.63, 0.68, 0.93, 0.54, 0.5, 0.55, 0.66, 0.54, 0.81, 0.57, 0.53, 0.64, 0.69, 0.62, 0.65, 0.51, 0.98, 0.75, 0.59, 0.57, 0.62, 0.63, 0.86, 0.78, 0.56, 0.84, 0.82, 0.68, 0.93, 0.77, 0.98, 0.51, 0.79, 0.77, 0.64, 0.85, 0.78, 0.66, 0.54, 0.62, 0.6, 0.93, 0.9, 0.6, 0.96, 0.93, 0.99, 0.52, 0.82, 0.56, 0.72, 0.87, 0.61, 0.5, 0.94, 0.77, 0.63, 0.8, 0.75, 0.87, 0.56, 0.78, 0.89, 0.86, 0.75, 0.93, 0.82, 0.78, 0.76, 0.92, 0.75, 0.58, 0.75, 0.79, 0.95, 0.74, 0.94, 0.69, 0.51, 0.74, 0.68, 0.58, 0.53, 0.94, 0.65, 0.94, 0.72, 0.89, 0.96, 1.0, 0.67, 0.64, 0.87, 0.89, 0.78, 0.76, 0.51, 0.81, 0.9, 0.63, 0.93 }
    ;
    start = 112;
    end = 493;
    result = leetCode.maxProbability(n, edges, succProb, start, end);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(succProb);
    Logger::WriteMessage("n = " + to_string(n) + "; start= " + to_string(start) + "; end = " + to_string(end) + "; result = " + to_string(result));
}


void TestLeetCodeGraph(void)
{
    TestLeetCode1514();
    TestLeetCode1494();
    TestLeetCode1489();
    TestLeetCode997();
    TestLeetCode1466();
    TestLeetCode1462();
    TestLeetCode305();
    TestLeetCode1319();
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
    TestLeetCode1443();
    TestLeetCode1436();
    TestLeetCode1377();
    TestLeetCode1376();
    TestLeetCode1368();
    TestLeetCode1361();
    TestLeetCode1345();
    TestLeetCode1340();
    TestLeetCode407();
    TestLeetCode675();
    TestLeetCode1311();
    TestLeetCode490();
    TestLeetCode499();
    TestLeetCode505();
    TestLeetCode1298();
    TestLeetCode1293();
    TestLeetCode1273();
    TestLeetCode463();
    TestLeetCode1263();
    TestLeetCode1258();
    TestLeetCode133();
    TestLeetCode174();
    TestLeetCode207();
    TestLeetCode210();
    TestLeetCode261();
    TestLeetCode269();
    TestLeetCode277();
    TestLeetCode286();
    TestLeetCode296();
    TestLeetCode310();
    TestLeetCode317();
    TestLeetCode323();
    TestLeetCode332();
    TestLeetCode399();
    TestLeetCode444();
    TestLeetCode529();
    TestLeetCode568();
    TestLeetCode573();
    TestLeetCode582();
    TestLeetCode684();
    TestLeetCode685();
    TestLeetCode694();
    TestLeetCode711();
    TestLeetCode749();
    TestLeetCode765();
    TestLeetCode778();
    TestLeetCode802();
    TestLeetCode815();
    TestLeetCode841();
    TestLeetCode847();
    TestLeetCode851();
    TestLeetCode871();
    TestLeetCode886();
    TestLeetCode913();
    TestLeetCode943();
    TestLeetCode959();
    TestLeetCode1057();
    TestLeetCode1059();
    TestLeetCode1102();
    TestLeetCode1129();
    TestLeetCode1135();
    TestLeetCode1136();
    TestLeetCode1153();
    TestLeetCode1168();
    TestLeetCode1192();
    TestLeetCode1203();
    TestLeetCode1245();
    TestLeetCode1245();
    TestLeetCode1254();
    TestLeetCode9902();
}
