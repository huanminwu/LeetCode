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
    vector<vector<int>> prerequisites;
    int numCourses;
    bool canFinish;
    numCourses = 2;
    prerequisites = { { 1, 0 } };
    Logger::WriteMessage(prerequisites);
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage("Can finish all course: " + string(canFinish ? "true" : "false"));

    numCourses = 2;
    prerequisites = { { 0, 1 }, {1,0} };
    canFinish = leetCode.canFinishCourse(numCourses, prerequisites);
    Logger::WriteMessage(prerequisites);
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
    vector<vector<int>> prerequisites;
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
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> sequences = { { 1, 2 },{ 1, 3 } };
    bool result = leetCode.sequenceReconstruction(nums, sequences);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(sequences);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1, 2, 3 };
    sequences = { { 1, 2 } };
    result = leetCode.sequenceReconstruction(nums, sequences);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(sequences);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1, 2, 3 };
    sequences = { {1, 2},{1, 3},{2, 3} };
    result = leetCode.sequenceReconstruction(nums, sequences);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(sequences);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 4,1,5,2,6,3 };
    sequences = { { 5,2,6,3 },{ 4,1,5,2 } };
    result = leetCode.sequenceReconstruction(nums, sequences);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(sequences);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
   
    nums = { 5, 3, 2, 4, 1 };
    sequences = {{ 5, 3, 2, 4 },{ 4, 1 },{1},{3},{2, 4}};
    result = leetCode.sequenceReconstruction(nums, sequences);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(sequences);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
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

    n = 2;
    flights = { {0,1,2} };
    src = 1;
    dst = 0;
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

}

void TestLeetCode1548(void)
{
    Logger::WriteMessage("Test Leet Code 1548");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> roads = { {0,2}, {0,3},{1,2},{1,3},{1,4},{2,4} };
    vector<string> names = { "ATL","PEK","LAX","DXB","HND" };
    vector<string> targetPath = { "ATL","DXB","HND","LAX" };
    vector<int> result = leetCode.mostSimilar(n, roads, names, targetPath);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(roads);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);

    n = 4;
    roads = { {1, 0},{2, 0},{3, 0},{2, 1},{3, 1},{3, 2} };
    names = { "ATL", "PEK", "LAX", "DXB" };
    targetPath = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX" };
    result = leetCode.mostSimilar(n, roads, names, targetPath);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(roads);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);

    n = 6;
    roads = { {0, 1},{1, 2},{2, 3},{3, 4},{4, 5} };
    names = { "ATL", "PEK", "LAX", "ATL", "DXB", "HND" };
    targetPath = { "ATL", "DXB", "HND", "DXB", "ATL", "LAX", "PEK" };
    result = leetCode.mostSimilar(n, roads, names, targetPath);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(roads);
    Logger::WriteMessage(names);
    Logger::WriteMessage(result);
}

void TestLeetCode1559(void)
{
    Logger::WriteMessage("Test Leet Code 1559");
    LeetCodeGraph leetCode;
    vector<vector<char>> grid =
    {
        {'a', 'a', 'a', 'a' },
        {'a', 'b', 'b', 'a' },
        {'a', 'b', 'b', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    bool result = leetCode.containsCycle(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {'c', 'c', 'c', 'a' },
        {'c', 'd', 'c', 'c' },
        {'c', 'c', 'e', 'c'},
        {'f', 'c', 'c', 'c'}
    };
    result = leetCode.containsCycle(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {'a', 'b', 'b'},
        {'b', 'z', 'b'},
        {'b', 'b', 'a'}
    };
    result = leetCode.containsCycle(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1568(void)
{
    Logger::WriteMessage("Test Leet Code 1568");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = { {0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0} };
    int result = leetCode.minDays(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1,1} };
    result = leetCode.minDays(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1,0,1,0} };
    result = leetCode.minDays(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = 
    { 
        {1,1,0,1,1},
        {1,1,1,1,1},
        {1,1,0,1,1},
        {1,1,0,1,1}
    };
    result = leetCode.minDays(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1}
    };
    result = leetCode.minDays(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1584(void)
{
    Logger::WriteMessage("Test Leet Code 1584");
    LeetCodeGraph leetCode;
    vector<vector<int>> points = { {0, 0},{2, 2},{3, 10},{5, 2},{7, 0} };
    int result = leetCode.minCostConnectPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {3, 12}, { -2, 5 }, { -4, 1 } };
    result = leetCode.minCostConnectPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {0, 0},{1, 1},{1, 0},{-1, 1} };
    result = leetCode.minCostConnectPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {-1000000, -1000000},{1000000, 1000000} };
    result = leetCode.minCostConnectPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {0, 0} };
    result = leetCode.minCostConnectPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1579(void)
{
    Logger::WriteMessage("Test Leet Code 1579");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> edges =
    {
        {3, 1, 2},{3, 2, 3},{1, 1, 3},{1, 2, 4},{1, 1, 2},{2, 3, 4}
    };
    int result = leetCode.maxNumEdgesToRemove(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    edges =
    {
        {3,1,2},{3,2,3},{1,1,4},{2,1,4}
    };
    result = leetCode.maxNumEdgesToRemove(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    edges =
    {
        {3,2,3} ,{1,1,2},{2,3,4}
    };
    result = leetCode.maxNumEdgesToRemove(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1575(void)
{
    Logger::WriteMessage("Test Leet Code 1575");
    LeetCodeGraph leetCode;
    vector<int> locations = { 2, 3, 6, 8, 4 };
    int start = 1;
    int finish = 3;
    int fuel = 5;
    int result = leetCode.countRoutes(locations, start, finish, fuel);
    Logger::WriteMessage(locations);
    Logger::WriteMessage("start = " + to_string(start) + 
                         "; finish = " + to_string(finish) + 
                         "; fuel = " + to_string(fuel) +
                         "; result = " + to_string(result));

    locations = { 4, 3, 1 };
    start = 1;
    finish = 0;
    fuel = 6;
    result = leetCode.countRoutes(locations, start, finish, fuel);
    Logger::WriteMessage(locations);
    Logger::WriteMessage("start = " + to_string(start) +
        "; finish = " + to_string(finish) +
        "; fuel = " + to_string(fuel) +
        "; result = " + to_string(result));

    locations = { 5,2,1 };
    start = 0;
    finish = 2;
    fuel = 3;
    result = leetCode.countRoutes(locations, start, finish, fuel);
    Logger::WriteMessage(locations);
    Logger::WriteMessage("start = " + to_string(start) +
        "; finish = " + to_string(finish) +
        "; fuel = " + to_string(fuel) +
        "; result = " + to_string(result));

    locations = { 2,1,5 };
    start = 0;
    finish = 0;
    fuel = 3;
    result = leetCode.countRoutes(locations, start, finish, fuel);
    Logger::WriteMessage(locations);
    Logger::WriteMessage("start = " + to_string(start) +
        "; finish = " + to_string(finish) +
        "; fuel = " + to_string(fuel) +
        "; result = " + to_string(result));

    locations = { 1,2,3 };
    start = 0;
    finish = 2;
    fuel = 40;
    result = leetCode.countRoutes(locations, start, finish, fuel);
    Logger::WriteMessage(locations);
    Logger::WriteMessage("start = " + to_string(start) +
        "; finish = " + to_string(finish) +
        "; fuel = " + to_string(fuel) +
        "; result = " + to_string(result));
}

void TestLeetCode1591(void)
{
    Logger::WriteMessage("Test Leet Code 1591");
    LeetCodeGraph leetCode;
    vector<vector<int>> targetGrid =
    {
        {1, 1, 1, 1},{1, 2, 2, 1},{1, 2, 2, 1},{1, 1, 1, 1}
    };
    bool result = leetCode.isPrintable(targetGrid);
    Logger::WriteMessage(targetGrid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    targetGrid =
    {
        {1, 1, 1, 1},{1, 1, 3, 3},{1, 1, 3, 4},{5, 5, 1, 4}
    };
    result = leetCode.isPrintable(targetGrid);
    Logger::WriteMessage(targetGrid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    targetGrid =
    {
        {1,2,1},{2,1,2},{1,2,1}
    };
    result = leetCode.isPrintable(targetGrid);
    Logger::WriteMessage(targetGrid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    targetGrid =
    {
        {1,1,1},{3,1,3}
    };
    result = leetCode.isPrintable(targetGrid);
    Logger::WriteMessage(targetGrid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1615(void)
{
    Logger::WriteMessage("Test Leet Code 1615");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> roads = { {0, 1},{0, 3},{1, 2},{1, 3} };
    int result = leetCode.maximalNetworkRank(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    roads = { {0, 1},{0, 3},{1, 2},{1, 3},{2, 3},{2, 4} };
    result = leetCode.maximalNetworkRank(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 8;
    roads = { {0, 1},{1, 2},{2, 3},{2, 4},{5, 6},{5, 7} };
    result = leetCode.maximalNetworkRank(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1617(void)
{
    Logger::WriteMessage("Test Leet Code 1617");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> edges = { {1, 2},{2, 3},{2, 4} };
    vector<int> result = leetCode.countSubgraphsForEachDiameter(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    n = 2;
    edges = { {1, 2} };
    result = leetCode.countSubgraphsForEachDiameter(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    n = 3;
    edges = { {1, 2},{2, 3} };
    result = leetCode.countSubgraphsForEachDiameter(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    n = 7;
    edges = { {1, 4}, { 1, 3 }, { 2, 5 }, { 2, 6 }, { 3, 6 }, { 6, 7 } };
    result = leetCode.countSubgraphsForEachDiameter(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode1627(void)
{
    Logger::WriteMessage("Test Leet Code 1627");
    LeetCodeGraph leetCode;
    int n = 6;
    int threshold = 2;
    vector<vector<int>> queries = { {1, 4},{2, 5},{3, 6} };
    vector<bool> result = leetCode.areConnected(n, threshold, queries);
    Logger::WriteMessage("n = " + to_string(n) + "; threshold = " + to_string(threshold));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 6;
    threshold = 0;
    queries = { {4, 5},{3, 4},{3, 2},{2, 6},{1, 3} };
    result = leetCode.areConnected(n, threshold, queries);
    Logger::WriteMessage("n = " + to_string(n) + "; threshold = " + to_string(threshold));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 6;
    threshold = 1;
    queries = { {4, 5}, {4, 5},{3, 2},{2, 3},{3, 4} };
    result = leetCode.areConnected(n, threshold, queries);
    Logger::WriteMessage("n = " + to_string(n) + "; threshold = " + to_string(threshold));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 633;
    threshold = 70;
    queries = { {375, 288} };
    result = leetCode.areConnected(n, threshold, queries);
    Logger::WriteMessage("n = " + to_string(n) + "; threshold = " + to_string(threshold));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1631(void)
{
    Logger::WriteMessage("Test Leet Code 1631");
    LeetCodeGraph leetCode;
    vector<vector<int>> heights = { {1, 2, 2},{3, 8, 2},{5, 3, 5} };
    int result = leetCode.minimumEffortPath(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("result = " + to_string(result));

    heights = { {1, 2, 3},{3, 8, 4},{5, 3, 5} };
    result = leetCode.minimumEffortPath(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("result = " + to_string(result));

    heights = 
    { 
        {1, 2, 1, 1, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 2, 1, 2, 1},
        {1, 1, 1, 2, 1} 
    };
    result = leetCode.minimumEffortPath(heights);
    Logger::WriteMessage(heights);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1654(void)
{
    Logger::WriteMessage("Test Leet Code 1654");
    LeetCodeGraph leetCode;
    vector<int> forbidden = { 14, 4, 18, 1, 15 };
    int a = 3;
    int b = 15;
    int x = 9;
    int result = leetCode.minimumJumps(forbidden, a, b, x);
    Logger::WriteMessage(forbidden);
    Logger::WriteMessage("a = " + to_string(result) + "; b = " + to_string(b) + "; x = " + to_string(x) + "; result = " + to_string(result));

    forbidden = { 8,3,16,6,12,20 };
    a = 15;
    b = 13;
    x = 11;
    result = leetCode.minimumJumps(forbidden, a, b, x);
    Logger::WriteMessage(forbidden);
    Logger::WriteMessage("a = " + to_string(result) + "; b = " + to_string(b) + "; x = " + to_string(x) + "; result = " + to_string(result));

    forbidden = { 1,6,2,14,5,17,4 };
    a = 16;
    b = 9;
    x = 7;
    result = leetCode.minimumJumps(forbidden, a, b, x);
    Logger::WriteMessage(forbidden);
    Logger::WriteMessage("a = " + to_string(result) + "; b = " + to_string(b) + "; x = " + to_string(x) + "; result = " + to_string(result));
}

void TestLeetCode1697(void)
{
    Logger::WriteMessage("Test Leet Code 1697");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> edgeList = 
    {
        {0, 1, 2},{1, 2, 4},{2, 0, 8},{1, 0, 16} 
    };
    vector<vector<int>> queries =
    {
        {0, 1, 2},{0, 2, 5}
    };
    vector<bool> result = leetCode.distanceLimitedPathsExist(n, edgeList, queries);
    Logger::WriteMessage(edgeList);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 5;
    edgeList =
    {
        {0, 1, 10}, { 1, 2, 5 }, { 2, 3, 9 }, { 3, 4, 13 }
    };
    queries =
    {
        {0, 4, 14},{1, 4, 13}
    };
    result = leetCode.distanceLimitedPathsExist(n, edgeList, queries);
    Logger::WriteMessage(edgeList);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1722(void)
{
    Logger::WriteMessage("Test Leet Code 1722");
    LeetCodeGraph leetCode;
    vector<int> source = { 1, 2, 3, 4 };
    vector<int> target = { 2, 1, 4, 5 };
    vector<vector<int>> allowedSwaps = { {0, 1},{2, 3} };

    int result = leetCode.minimumHammingDistance(source, target, allowedSwaps);
    Logger::WriteMessage(source);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + to_string(result));

    source = { 1, 2, 3, 4 };
    target = { 1,3,2,4 };
    allowedSwaps = {};

    result = leetCode.minimumHammingDistance(source, target, allowedSwaps);
    Logger::WriteMessage(source);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + to_string(result));

    source = { 5,1,2,4,3 };
    target = { 1,5,4,2,3 };
    allowedSwaps = { {0, 4},{4, 2},{1, 3},{1, 4} };

    result = leetCode.minimumHammingDistance(source, target, allowedSwaps);
    Logger::WriteMessage(source);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1719(void)
{
    Logger::WriteMessage("Test Leet Code 1719");
    LeetCodeGraph leetCode;
    vector<vector<int>> pairs = { {1, 2},{2, 3} };
    int result = leetCode.checkWays(pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage("result = " + to_string(result));

    pairs = { {1, 2},{2, 3},{1, 3} };
    result = leetCode.checkWays(pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage("result = " + to_string(result));

    pairs = { {1, 2},{2, 3},{2, 4},{1, 5} };
    result = leetCode.checkWays(pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1730(void)
{
    Logger::WriteMessage("Test Leet Code 1730");
    LeetCodeGraph leetCode;
    vector<vector<char>> grid =
    {
        {'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', '*', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'O', '#', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X', 'X'}
    };
    int result = leetCode.getFood(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', '*', 'X', 'O', 'X'},
        {'X', 'O', 'X', '#', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };
    result = leetCode.getFood(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}, 
        {'X', '*', 'O', 'X', 'O', '#', 'O', 'X'}, 
        {'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'O', 'O', '#', 'O', 'X'}, 
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
    };
    result = leetCode.getFood(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'O', '*'},
        {'#', 'O'}
    };
    result = leetCode.getFood(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {'X','*'},
        {'#','X'}
    };
    result = leetCode.getFood(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1743(void)
{
    Logger::WriteMessage("Test Leet Code 1743");
    LeetCodeGraph leetCode;
    vector<vector<int>> adjacentPairs = { {2, 1},{3, 4},{3, 2} };
    vector<int> result = leetCode.restoreArray(adjacentPairs);
    Logger::WriteMessage(adjacentPairs);
    Logger::WriteMessage(result);

    adjacentPairs = { {4, -2}, { 1, 4 }, { -3, 1 } };    
    result = leetCode.restoreArray(adjacentPairs);
    Logger::WriteMessage(adjacentPairs);
    Logger::WriteMessage(result);

    adjacentPairs = { {100000, -100000} };
    result = leetCode.restoreArray(adjacentPairs);
    Logger::WriteMessage(adjacentPairs);
    Logger::WriteMessage(result);
}

void TestLeetCode1765(void)
{
    Logger::WriteMessage("Test Leet Code 1765");
    LeetCodeGraph leetCode;
    vector<vector<int>> isWater = { {0, 1},{0, 0} };
    vector<vector<int>> result = leetCode.highestPeak(isWater);
    Logger::WriteMessage(isWater);
    Logger::WriteMessage(result);

    isWater = { {0, 0, 1},{1, 0, 0},{0, 0, 0} };
    result = leetCode.highestPeak(isWater);
    Logger::WriteMessage(isWater);
    Logger::WriteMessage(result);
}

void TestLeetCode1786(void)
{
    Logger::WriteMessage("Test Leet Code 1786");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> edges = 
    { 
        {1, 2, 3},{1, 3, 3},{2, 3, 1},{1, 4, 2},
        {5, 2, 2},{3, 5, 1},{5, 4, 10} 
    };
    int result = leetCode.countRestrictedPaths(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    edges =
    {
        {1, 3, 1},{4, 1, 2},{7, 3, 4},{2, 5, 3},
        {5, 6, 1},{6, 7, 2},{7, 5, 3},{2, 6, 4} 
    };
    result = leetCode.countRestrictedPaths(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1782(void)
{
    Logger::WriteMessage("Test Leet Code 1782");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> edges = 
    {
        {1, 2},{2, 4},{1, 3},{2, 3},{2, 1} 
    };
    vector<int> queries = { 2, 3 };
    vector<int> result = leetCode.countPairs(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 5;
    edges =
    {
        {1, 5},{1, 5},{3, 4},{2, 5},{1, 3},{5, 1},{2, 3},{2, 5}
    };
    queries = { 1,2,3,4,5 };
    result = leetCode.countPairs(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode1761(void)
{
    Logger::WriteMessage("Test Leet Code 1761");
    LeetCodeGraph leetCode;
    int n = 6;
    vector<vector<int>> edges =
    {
        {1, 2},{1, 3},{3, 2},{4, 1},{5, 2},{3, 6}
    };
    int result = leetCode.minTrioDegree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7; 
    edges =
    {
        {1, 3},{4, 1},{4, 3},{2, 5},{5, 6},{6, 7},{7, 5},{2, 6}
    };
    result = leetCode.minTrioDegree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    edges =
    {
        {5, 2},{4, 1},{4, 2},{1, 5}
    };
    result = leetCode.minTrioDegree(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));        
}

void TestLeetCode1791(void)
{
    Logger::WriteMessage("Test Leet Code 1791");
    LeetCodeGraph leetCode;
    vector<vector<int>> edges =
    {
        {1,2},{2,3},{4,2}
    };
    int result = leetCode.findCenter(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges =
    {
        {1,2},{5,1},{1,3},{1,4}
    };
    result = leetCode.findCenter(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1820(void)
{
    Logger::WriteMessage("Test Leet Code 1820");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = 
    {
        {1, 1, 1},
        {1, 0, 1},
        {0, 0, 1}
    };
    int result = leetCode.maximumInvitations(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 0},
        {1, 1, 1, 0}
    };
    result = leetCode.maximumInvitations(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1857(void)
{
    Logger::WriteMessage("Test Leet Code 1857");
    LeetCodeGraph leetCode;
    string colors = "abaca";
    vector<vector<int>> edges = { {0, 1},{0, 2},{2, 3},{3, 4} };
    int result = leetCode.largestPathValue(colors, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    colors = "a";
    edges = { {0, 0} };
    result = leetCode.largestPathValue(colors, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1928(void)
{
    Logger::WriteMessage("Test Leet Code 1928");
    LeetCodeGraph leetCode;
    int maxTime = 30;
    vector<vector<int>> edges =
    {
        {0, 1, 10},{1, 2, 10},{2, 5, 10},{0, 3, 1},{3, 4, 10},{4, 5, 15}
    };
    vector<int> passingFees = { 5, 1, 2, 20, 20, 3 };
    int result = leetCode.minCost(maxTime, edges, passingFees);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(passingFees);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));

    maxTime = 29;
    edges =
    {
        {0,1,10} ,{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}
    };
    passingFees = { 5,1,2,20,20,3 };
    result = leetCode.minCost(maxTime, edges, passingFees);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(passingFees);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));

    maxTime = 25;
    edges =
    {
        {0,1,10} ,{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}
    };
    passingFees = { 5,1,2,20,20,3 };
    result = leetCode.minCost(maxTime, edges, passingFees);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(passingFees);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));

    maxTime = 500;
    edges = { {36, 1, 2}, { 8,41,29 }, { 47,7,50 }, { 33,17,6 }, { 47,37,28 }, { 3,38,2 }, { 27,2,4 }, { 11,30,17 }, { 32,35,48 }, { 12,1,32 }, { 7,27,6 }, { 7,4,25 }, { 15,8,11 }, { 2,17,50 }, { 7,45,14 }, { 40,8,48 }, { 4,22,5 }, { 28,23,20 }, { 20,27,49 }, { 26,34,13 }, { 17,47,40 }, { 47,4,32 }, { 0,30,21 }, { 30,29,8 }, { 15,3,38 }, { 4,3,39 }, { 22,16,46 }, { 47,10,13 }, { 42,23,30 }, { 34,0,13 }, { 12,25,11 }, { 5,2,1 }, { 7,36,48 }, { 44,11,7 }, { 20,47,9 }, { 42,37,49 }, { 42,4,46 }, { 1,39,26 }, { 14,5,25 }, { 32,17,16 }, { 22,7,25 }, { 3,22,36 }, { 49,8,46 }, { 16,20,6 }, { 16,21,32 }, { 26,43,35 }, { 43,19,7 }, { 0,2,35 }, { 35,37,25 }, { 25,48,46 }, { 9,4,28 }, { 24,5,21 }, { 37,30,7 }, { 14,16,40 }, { 25,35,26 }, { 49,38,1 }, { 24,13,36 }, { 27,6,8 }, { 10,3,37 }, { 23,13,26 }, { 31,21,19 }, { 28,1,48 }, { 15,21,18 }, { 17,7,40 }, { 33,12,24 }, { 44,28,11 }, { 46,43,37 }, { 1,26,47 }, { 3,46,17 }, { 28,22,20 }, { 8,34,3 }, { 18,6,2 }, { 38,16,30 }, { 17,38,20 }, { 12,10,26 }, { 21,40,18 }, { 19,2,25 }, { 31,28,25 }, { 41,8,5 }, { 9,3,14 }, { 5,0,8 }, { 3,36,25 }, { 32,23,37 }, { 2,1,11 }, { 49,25,18 }, { 33,24,48 }, { 42,28,25 }, { 4,40,47 }, { 37,11,23 }, { 37,46,45 }, { 9,42,35 }, { 34,1,19 }, { 17,2,17 }, { 15,17,13 }, { 33,20,1 }, { 40,34,13 }, { 25,21,40 }, { 40,9,41 }, { 47,15,41 }, { 3,10,20 }, { 33,35,47 }, { 22,8,37 }, { 35,40,34 }, { 29,38,34 }, { 37,15,17 }, { 28,39,43 }, { 24,37,28 }, { 16,24,8 }, { 37,46,10 }, { 4,44,34 }, { 41,17,20 }, { 25,40,45 }, { 15,18,30 }, { 48,25,16 }, { 16,11,7 }, { 16,1,34 }, { 19,44,11 }, { 37,7,14 }, { 11,49,5 }, { 29,32,3 }, { 17,32,7 }, { 39,18,10 }, { 25,14,9 }, { 1,0,36 }, { 7,28,46 }, { 48,13,44 }, { 46,31,27 }, { 11,0,32 }, { 30,32,24 }, { 27,15,33 }, { 20,19,43 }, { 16,8,6 }, { 28,21,43 }, { 13,33,14 }, { 3,2,45 }, { 20,6,27 }, { 35,17,23 }, { 38,46,48 }, { 46,48,5 }, { 45,43,20 }, { 49,24,14 }, { 45,34,28 }, { 10,32,46 }, { 10,37,29 }, { 39,21,46 }, { 34,25,22 }, { 6,11,3 }, { 0,34,19 }, { 6,20,3 }, { 33,0,44 }, { 4,6,15 }, { 35,13,22 }, { 29,41,20 }, { 6,4,33 }, { 45,15,43 }, { 33,46,40 }, { 45,34,23 }, { 19,27,33 }, { 19,2,9 }, { 21,2,29 }, { 14,25,15 }, { 37,44,34 }, { 16,41,41 }, { 18,3,18 }, { 46,32,13 }, { 43,48,47 }, { 28,13,39 }, { 26,47,46 }, { 13,28,46 }, { 26,19,32 }, { 13,11,41 }, { 17,43,13 }, { 39,47,15 }, { 48,13,37 }, { 29,17,27 }, { 35,33,29 }, { 24,37,19 }, { 43,22,49 }, { 40,5,33 }, { 23,24,34 }, { 38,13,12 }, { 8,2,10 }, { 43,16,44 }, { 2,31,46 }, { 48,10,15 }, { 16,31,11 }, { 3,33,9 }, { 33,10,9 }, { 41,18,41 }, { 41,47,46 }, { 10,44,6 }, { 27,38,45 }, { 42,28,2 }, { 19,9,30 }, { 21,32,26 }, { 48,41,10 }, { 28,42,9 }, { 31,7,42 }, { 0,17,41 }, { 1,0,25 }, { 25,20,32 } };
    passingFees =
    { 45, 308, 835, 819, 667, 547, 322, 428, 306, 327, 362, 280, 334, 767, 767, 533, 514, 9, 539, 125, 153, 325, 937, 745, 334, 804, 336, 587, 71, 463, 287, 492, 466, 935, 373, 950, 760, 994, 390, 836, 911, 948, 81, 945, 593, 821, 58, 138, 50, 537 };
    result = leetCode.minCost(maxTime, edges, passingFees);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(passingFees);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));
}

void TestLeetCode1901(void)
{
    Logger::WriteMessage("Test Leet Code 1901");
    LeetCodeGraph leetCode;
    vector<vector<int>> mat = { {1, 4},{3, 2} };
    vector<int> result = leetCode.findPeakGrid(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage(result);

    mat = { {10, 20, 15},{21, 30, 14},{7, 16, 32} };
    result = leetCode.findPeakGrid(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage(result);
}

void TestLeetCode1905(void)
{
    Logger::WriteMessage("Test Leet Code 1905");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid1 =
    {
        {1, 1, 1, 0, 0},{0, 1, 1, 1, 1},{0, 0, 0, 0, 0},{1, 0, 0, 0, 0},{1, 1, 0, 1, 1}
    };
    vector<vector<int>> grid2 =
    {
        {1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}
    };
    int result = leetCode.countSubIslands(grid1, grid2);
    Logger::WriteMessage(grid1);
    Logger::WriteMessage(grid2);
    Logger::WriteMessage("result = " + to_string(result));

    grid1 =
    {
        {1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}
    };
    grid2 =
    {
        {0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}
    };
    result = leetCode.countSubIslands(grid1, grid2);
    Logger::WriteMessage(grid1);
    Logger::WriteMessage(grid2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1926(void)
{
    Logger::WriteMessage("Test Leet Code 1926");
    LeetCodeGraph leetCode;
    vector<vector<char>> maze = { {'+', '+', '.', '+'},{'.', '.', '.', '+'},{'+', '+', '+', '.'} };
    vector<int> entrance = { 1, 2 };
    int result = leetCode.nearestExit(maze, entrance);
    Logger::WriteMessage(maze);
    Logger::WriteMessage(entrance);
    Logger::WriteMessage("result = " + to_string(result));

    maze = { {'+', '+', '+'},{'.', '.', '.'},{'+', '+', '+'} };
    entrance = { 1, 0 };
    result = leetCode.nearestExit(maze, entrance);
    Logger::WriteMessage(maze);
    Logger::WriteMessage(entrance);
    Logger::WriteMessage("result = " + to_string(result));

    maze = { {'.', '+'} };
    entrance = { 0, 0 };
    result = leetCode.nearestExit(maze, entrance);
    Logger::WriteMessage(maze);
    Logger::WriteMessage(entrance);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1970(void)
{
    Logger::WriteMessage("Test Leet Code 1970");
    LeetCodeGraph leetCode;
    int row = 2, col = 2;
    vector<vector<int>> cells = { {1, 1},{2, 1},{1, 2},{2, 2} };
    int result = leetCode.latestDayToCross(row, col, cells);
    Logger::WriteMessage(cells);
    Logger::WriteMessage("row = " + to_string(row) + "; col = " + to_string(col) + "; result = " + to_string(result));

    row = 2; col = 2;
    cells = {{ 1, 1 }, { 1, 2 }, { 2, 1 }, { 2, 2 }};
    result = leetCode.latestDayToCross(row, col, cells);
    Logger::WriteMessage(cells);
    Logger::WriteMessage("row = " + to_string(row) + "; col = " + to_string(col) + "; result = " + to_string(result));

    row = 3; col = 3;
    cells = { {1, 2},{2, 1},{3, 3},{2, 2},{1, 1},{1, 3},{2, 3},{3, 2},{3, 1} };
    result = leetCode.latestDayToCross(row, col, cells);
    Logger::WriteMessage(cells);
    Logger::WriteMessage("row = " + to_string(row) + "; col = " + to_string(col) + "; result = " + to_string(result));

    row = 55; col = 2;
    cells = { {53,1},{25,1},{9,2},{3,1},{54,1},{14,2},{28,1},{4,1},{44,1},{20,2},{28,2},{24,2},{50,1},{47,2},{21,1},{47,1},{22,2},{10,1},{17,1},{13,1},{12,1},{37,2},{46,2},{51,1},{32,1},{51,2},{6,2},{49,2},{13,2},{34,1},{33,1},{38,2},{52,2},{26,2},{46,1},{20,1},{33,2},{23,2},{17,2},{1,2},{3,2},{50,2},{25,2},{19,1},{21,2},{49,1},{29,1},{30,2},{41,1},{16,1},{39,2},{9,1},{48,2},{23,1},{27,1},{43,1},{45,1},{31,1},{40,1},{6,1},{42,1},{8,2},{12,2},{29,2},{36,2},{39,1},{41,2},{10,2},{44,2},{14,1},{35,1},{30,1},{2,2},{34,2},{55,1},{18,1},{32,2},{27,2},{4,2},{37,1},{38,1},{16,2},{26,1},{15,2},{19,2},{5,1},{45,2},{43,2},{55,2},{35,2},{54,2},{42,2},{22,1},{11,1},{48,1},{1,1},{36,1},{24,1},{8,1},{2,1},{7,1},{15,1},{31,2},{18,2},{7,2},{52,1},{40,2},{53,2},{11,2},{5,2} };
    result = leetCode.latestDayToCross(row, col, cells);
    Logger::WriteMessage(cells);
    Logger::WriteMessage("row = " + to_string(row) + "; col = " + to_string(col) + "; result = " + to_string(result));
    
}

void TestLeetCode1998(void)
{
    Logger::WriteMessage("Test Leet Code 1998");
    LeetCodeGraph leetCode;
    vector<int> nums = { 7, 21, 3 };
    bool result = leetCode.gcdSort(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 5,2,6,2 };
    result = leetCode.gcdSort(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 10,5,9,3,15 };
    result = leetCode.gcdSort(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 8, 9, 4, 2, 3 };
    result = leetCode.gcdSort(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 100000, 100000, 100000, 100000, 100000 };
    result = leetCode.gcdSort(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 5, 2, 6, 2 };
    result = leetCode.gcdSort(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1958(void)
{
    Logger::WriteMessage("Test Leet Code 1958");
    LeetCodeGraph leetCode;
    vector<vector<char>> board =
    {
        {'.','.','.','B','.','.','.','.'}, {'.','.','.','W','.','.','.','.'},
        {'.','.','.','W','.','.','.','.'}, {'.','.','.','W','.','.','.','.'},
        {'W','B','B','.','W','W','W','B'}, {'.','.','.','B','.','.','.','.'},
        {'.','.','.','B','.','.','.','.'}, {'.','.','.','W','.','.','.','.'}
    };
    int rMove = 4;
    int cMove = 3;
    char color = 'B';
    bool result = leetCode.checkMove(board, rMove, cMove, color);
    Logger::WriteMessage(board);
    Logger::WriteMessage("rMove = " + to_string(rMove) + "; cMove = " + to_string(cMove) + 
        "; color = " + string(1, color) + "; result = " + (string)(result ? "true" : "false"));

    board =
    {
        {'.', '.', '.', '.', '.', '.', '.', '.'}, { '.','B','.','.','W','.','.','.' },
        { '.','.','W','.','.','.','.','.' }, { '.','.','.','W','B','.','.','.' },
        { '.','.','.','.','.','.','.','.' }, { '.','.','.','.','B','W','.','.' },
        { '.','.','.','.','.','.','W','.' }, { '.','.','.','.','.','.','.','B' }
    }; 
    rMove = 4;
    cMove = 4;
    color = 'W';
    result = leetCode.checkMove(board, rMove, cMove, color);
    Logger::WriteMessage(board);
    Logger::WriteMessage("rMove = " + to_string(rMove) + "; cMove = " + to_string(cMove) +
        "; color = " + string(1, color) + "; result = " + (string)(result ? "true" : "false"));

    board =
    {
        {'W', 'W', '.', 'B', '.', 'B', 'B', '.'}, { 'W','B','.','.','W','B','.','.' },
        { 'B','B','B','B','W','W','B','.' },  { 'W','B','.','.','B','B','B','.' },
        { 'W','W','B','.','W','.','B','B' }, { 'B','.','B','W','.','B','.','.' },
        { '.','B','B','W','B','B','.','.' }, { 'B','B','W','.','.','B','.','.' }
    };
    rMove = 7;
    cMove = 4;
    color = 'B';
    result = leetCode.checkMove(board, rMove, cMove, color);
    Logger::WriteMessage(board);
    Logger::WriteMessage("rMove = " + to_string(rMove) + "; cMove = " + to_string(cMove) +
        "; color = " + string(1, color) + "; result = " + (string)(result ? "true" : "false"));

    board =
    {
        {'B', 'B', '.', '.', 'B', 'W', 'W', '.'}, { '.','W','W','.','B','W','B','B' },
        { '.','W','B','B','W','.','W','.' }, { 'B','.','.','B','W','W','W','.' },
        { 'W','W','W','B','W','.','B','W' }, { '.','.','.','W','.','W','.','B' },
        { 'B','B','W','B','B','W','W','B' }, { 'W','.','W','W','.','B','.','W' }
    };
    rMove = 2;
    cMove = 5;
    color = 'W';
    result = leetCode.checkMove(board, rMove, cMove, color);
    Logger::WriteMessage(board);
    Logger::WriteMessage("rMove = " + to_string(rMove) + "; cMove = " + to_string(cMove) +
        "; color = " + string(1, color) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2045(void)
{
    Logger::WriteMessage("Test Leet Code 2045");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> edges = { {1, 2},{1, 3},{1, 4},{3, 4},{4, 5} };
    int time = 3;
    int change = 5;
    int result = leetCode.secondMinimum(n, edges, time, change);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; time = " + to_string(time) +
        "; change = " + to_string(change) + "; result = " + to_string(result));

    n = 2; 
    edges = { {1, 2} };
    time = 3;
    change = 2;
    result = leetCode.secondMinimum(n, edges, time, change);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; time = " + to_string(time) +
        "; change = " + to_string(change) + "; result = " + to_string(result));
}

void TestLeetCode2065(void)
{
    Logger::WriteMessage("Test Leet Code 2065");
    LeetCodeGraph leetCode;
    vector<int> values = { 0, 32, 10, 43 };
    vector<vector<int>> edges = { {0, 1, 10},{1, 2, 15},{0, 3, 10} };
    int maxTime = 49;
    int result = leetCode.maximalPathQuality(values, edges, maxTime);
    Logger::WriteMessage(values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));

    values = { 5,10,15,20 };
    edges = { {0,1,10} ,{1,2,10},{0,3,10} };
    maxTime = 30;
    result = leetCode.maximalPathQuality(values, edges, maxTime);
    Logger::WriteMessage(values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));

    values = { 1,2,3,4 };
    edges = { {0, 1, 10},{1, 2, 11},{2, 3, 12},{1,3,13} };
    maxTime = 50;
    result = leetCode.maximalPathQuality(values, edges, maxTime);
    Logger::WriteMessage(values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));

    values = { 0,1,2 };
    edges = { {1,2,10} };
    maxTime = 10;
    result = leetCode.maximalPathQuality(values, edges, maxTime);
    Logger::WriteMessage(values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("maxTime = " + to_string(maxTime) + "; result = " + to_string(result));
}

void TestLeetCode2076(void)
{
    Logger::WriteMessage("Test Leet Code 2076");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> restrictions = { {0, 1} };
    vector<vector<int>> requests = { {0, 2},{2, 1} };
    vector<bool> result = leetCode.friendRequests(n, restrictions, requests);
    Logger::WriteMessage(restrictions);
    Logger::WriteMessage(requests);
    Logger::WriteMessage(result);

    n = 3;
    restrictions = { {0, 1} };
    requests = { {1, 2},{0, 2} };
    result = leetCode.friendRequests(n, restrictions, requests);
    Logger::WriteMessage(restrictions);
    Logger::WriteMessage(requests);
    Logger::WriteMessage(result);

    n = 5;
    restrictions = { {0, 1},{1, 2},{2, 3} };
    requests = { {0, 4},{1, 2},{3, 1},{3, 4} };
    result = leetCode.friendRequests(n, restrictions, requests);
    Logger::WriteMessage(restrictions);
    Logger::WriteMessage(requests);
    Logger::WriteMessage(result);
}

void TestLeetCode2050(void)
{
    Logger::WriteMessage("Test Leet Code 2050");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> relations = { {1, 3},{2, 3} };
    vector<int> time = { 3, 2, 5 };
    int result = leetCode.minimumTime(n, relations, time);
    Logger::WriteMessage(relations);
    Logger::WriteMessage(time);
    Logger::WriteMessage("n = " + to_string(n) + "result = " + to_string(result));

    n = 5;
    relations = { {1, 5},{2, 5},{3, 5},{3, 4},{4, 5} };
    time = { 1,2,3,4,5 };
    result = leetCode.minimumTime(n, relations, time);
    Logger::WriteMessage(relations);
    Logger::WriteMessage(time);
    Logger::WriteMessage("n = " + to_string(n) + "result = " + to_string(result));
}

void TestLeetCode1992(void)
{
    Logger::WriteMessage("Test Leet Code 1992");
    LeetCodeGraph leetCode;
    vector<vector<int>> land = { {1, 0, 0},{0, 1, 1},{0, 1, 1} };
    vector<vector<int>> result = leetCode.findFarmland(land);
    Logger::WriteMessage(land);
    Logger::WriteMessage(result);

    land = { {1, 1},{1, 1} };
    result = leetCode.findFarmland(land);
    Logger::WriteMessage(land);
    Logger::WriteMessage(result);
}

void TestLeetCode1956(void)
{
    Logger::WriteMessage("Test Leet Code 1956");
    LeetCodeGraph leetCode;
    vector<vector<int>> points = { {1, 1},{6, 1} };
    int k = 2;
    int result = leetCode.minDayskVariants(points, k);
    Logger::WriteMessage(points);
    Logger::WriteMessage("k = " + to_string(k) + "result = " + to_string(result));

    points = { {3, 3}, {1, 2},{9, 2} };
    k = 2;
    result = leetCode.minDayskVariants(points, k);
    Logger::WriteMessage(points);
    Logger::WriteMessage("k = " + to_string(k) + "result = " + to_string(result));

    points = { {3, 3}, {1, 2},{9, 2} };
    k = 3;
    result = leetCode.minDayskVariants(points, k);
    Logger::WriteMessage(points);
    Logger::WriteMessage("k = " + to_string(k) + "result = " + to_string(result));
}

void TestLeetCode2092(void)
{
    Logger::WriteMessage("Test Leet Code 2092");
    LeetCodeGraph leetCode;
    int n = 6;
    vector<vector<int>> meetings = { {1, 2, 5},{2, 3, 8}, {1, 5, 10} };
    int firstPerson = 1;
    vector<int> result = leetCode.findAllPeople(n, meetings, firstPerson);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("n = " + to_string(n) + "; firstPerson = " + to_string(firstPerson));
    Logger::WriteMessage(result);

    n = 4;
    meetings = { {3, 1, 3 }, { 1, 2, 2 }, { 0, 3, 3 } };
    firstPerson = 3;
    result = leetCode.findAllPeople(n, meetings, firstPerson);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("n = " + to_string(n) + "; firstPerson = " + to_string(firstPerson));
    Logger::WriteMessage(result);

    n = 5;
    meetings = { {3, 4, 2},{1, 2, 1},{2, 3, 1} };
    firstPerson = 1;
    result = leetCode.findAllPeople(n, meetings, firstPerson);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("n = " + to_string(n) + "; firstPerson = " + to_string(firstPerson));
    Logger::WriteMessage(result);

    n = 6;
    meetings = { {0, 2, 1},{1, 3, 1},{4, 5, 1} };
    firstPerson = 1;
    result = leetCode.findAllPeople(n, meetings, firstPerson);
    Logger::WriteMessage(meetings);
    Logger::WriteMessage("n = " + to_string(n) + "; firstPerson = " + to_string(firstPerson));
    Logger::WriteMessage(result);
}

void TestLeetCode1971(void)
{
    Logger::WriteMessage("Test Leet Code 1971");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{1, 2},{2, 0} };
    int start = 0;
    int end = 2;
    int result = leetCode.validPath(n, edges, start, end);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start) +
        "; end = " + to_string(end) + "; result = " + (string)(result ? "true":"false"));

    n = 6; 
    edges = { {0, 1},{0, 2},{3, 5},{5, 4},{4, 3} };
    start = 0;
    end = 5;
    result = leetCode.validPath(n, edges, start, end);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; start = " + to_string(start) +
        "; end = " + to_string(end) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2077(void)
{
    Logger::WriteMessage("Test Leet Code 2077");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> corridors = { {1, 2},{5, 2},{4, 1},{2, 4},{3, 1},{3, 4} };
    int result = leetCode.numberOfPaths(n, corridors);
    Logger::WriteMessage(corridors);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    corridors = { {1, 2},{3, 4} };
    result = leetCode.numberOfPaths(n, corridors);
    Logger::WriteMessage(corridors);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}


void TestLeetCode2061(void)
{
    Logger::WriteMessage("Test Leet Code 2061");
    LeetCodeGraph leetCode;
    vector<vector<int>> room = { {0, 0, 0},{1, 1, 0},{0, 0, 0} };
    int result = leetCode.numberOfCleanRooms(room);
    Logger::WriteMessage(room);
    Logger::WriteMessage("result = " + to_string(result));

    room = { {0, 1, 0},{1, 0, 0},{0, 0, 0} };
    result = leetCode.numberOfCleanRooms(room);
    Logger::WriteMessage(room);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2097(void)
{
    Logger::WriteMessage("Test Leet Code 2097");
    LeetCodeGraph leetCode;
    vector<vector<int>> pairs = { {5, 1},{4, 5},{11, 9},{9, 4} };
    vector<vector<int>> result = leetCode.validArrangement(pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage(result);

    pairs = { {1, 3},{3, 2},{2, 1} };
    result = leetCode.validArrangement(pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage(result);

    pairs = { {1, 2},{1, 3},{2, 1} };
    result = leetCode.validArrangement(pairs);
    Logger::WriteMessage(pairs);
    Logger::WriteMessage(result);

}

void TestLeetCode1976(void)
{
    Logger::WriteMessage("Test Leet Code 1976");
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> roads = 
    { 
        {0, 6, 7}, {0, 1, 2},{1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1},  {6, 5, 1}, 
        {2, 5, 1}, {0, 4, 5}, {4, 6, 2}
    };
    int result = leetCode.countPaths(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    roads =
    {
        {1, 0, 10}
    };
    result = leetCode.countPaths(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2087(void)
{
    Logger::WriteMessage("Test Leet Code 2087");
    LeetCodeGraph leetCode;
    vector<int> startPos = { 1, 0 };
    vector<int> homePos = { 2, 3 };
    vector<int> rowCosts = { 5, 4, 3 };
    vector<int> colCosts = { 8, 2, 6, 7 };
    int result = leetCode.minCost(startPos, homePos, rowCosts, colCosts);
    Logger::WriteMessage(startPos);
    Logger::WriteMessage(homePos);
    Logger::WriteMessage(rowCosts);
    Logger::WriteMessage(colCosts);
    Logger::WriteMessage("result = " + to_string(result));

    startPos = { 0, 0 };
    homePos = { 0, 0 };
    rowCosts = { 5 };
    colCosts = { 26 };
    result = leetCode.minCost(startPos, homePos, rowCosts, colCosts);
    Logger::WriteMessage(startPos);
    Logger::WriteMessage(homePos);
    Logger::WriteMessage(rowCosts);
    Logger::WriteMessage(colCosts);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2039(void)
{
    Logger::WriteMessage("Test Leet Code 2039");
    LeetCodeGraph leetCode;
    vector<vector<int>> edges = { {0, 1},{1, 2} };
    vector<int> patience = { 0, 2, 1 };
    int result = leetCode.networkBecomesIdle(edges, patience);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(patience);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{0, 2},{1, 2} };
    patience = { 0, 10, 10 };
    result = leetCode.networkBecomesIdle(edges, patience);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(patience);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2049(void)
{
    Logger::WriteMessage("Test Leet Code 2049");
    LeetCodeGraph leetCode;
    vector<int> parents = { -1, 2, 0, 2, 0 };
    int result = leetCode.countHighestScoreNodes(parents);
    Logger::WriteMessage(parents);
    Logger::WriteMessage("result = " + to_string(result));

    parents = { -1,2,0 };
    result = leetCode.countHighestScoreNodes(parents);
    Logger::WriteMessage(parents);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2059(void)
{
    Logger::WriteMessage("Test Leet Code 2059");
    LeetCodeGraph leetCode;
    vector<int> nums = { 2, 4, 12 };
    int start = 2;
    int goal = 12;
    int result = leetCode.minimumOperations(nums, start, goal);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("start = " + to_string(start) + "; goal = " + to_string(goal) + "; result = " + to_string(result));

    nums = { 3,5,7 };
    start = 0;
    goal = -4;
    result = leetCode.minimumOperations(nums, start, goal);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("start = " + to_string(start) + "; goal = " + to_string(goal) + "; result = " + to_string(result));

    nums = { 2,8,16 };
    start = 0;
    goal = 1;
    result = leetCode.minimumOperations(nums, start, goal);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("start = " + to_string(start) + "; goal = " + to_string(goal) + "; result = " + to_string(result));
}

void TestLeetCode2115(void)
{
    Logger::WriteMessage("Test Leet Code 2115");
    LeetCodeGraph leetCode;
    vector<string> recipes = { "bread" };
    vector<vector<string>> ingredients = { {"yeast", "flour"} };
    vector<string> supplies = { "yeast", "flour", "corn" };
    vector<string> result = leetCode.findAllRecipes(recipes, ingredients, supplies);
    Logger::WriteMessage(recipes);
    Logger::WriteMessage(ingredients);
    Logger::WriteMessage(supplies);
    Logger::WriteMessage(result);

    recipes = { "bread","sandwich" };
    ingredients = { {"yeast","flour"}, {"bread","meat"},  };
    supplies = { "yeast","flour","meat" };
    result = leetCode.findAllRecipes(recipes, ingredients, supplies);
    Logger::WriteMessage(recipes);
    Logger::WriteMessage(ingredients);
    Logger::WriteMessage(supplies);
    Logger::WriteMessage(result);

    recipes = { "bread","sandwich","burger" };
    ingredients = 
    { 
        {"yeast","flour"}, {"bread","meat"},
        {"sandwich","meat","bread" }
    };
    supplies = { "yeast","flour","meat" };
    result = leetCode.findAllRecipes(recipes, ingredients, supplies);
    Logger::WriteMessage(recipes);
    Logger::WriteMessage(ingredients);
    Logger::WriteMessage(supplies);
    Logger::WriteMessage(result);

    recipes = { "bread","sandwich","burger" };
    ingredients =
    {
        {"yeast","flour"}, {"bread","meat"},
        {"sandwich","meat","bread" }
    };
    supplies = { "yeast","flour","meat" };
    result = leetCode.findAllRecipes(recipes, ingredients, supplies);
    Logger::WriteMessage(recipes);
    Logger::WriteMessage(ingredients);
    Logger::WriteMessage(supplies);
    Logger::WriteMessage(result);
}

void TestLeetCode2101(void)
{
    Logger::WriteMessage("Test Leet Code 2101");
    LeetCodeGraph leetCode;
    vector<vector<int>> bombs = { {2, 1, 3},{6, 1, 4} };
    int result = leetCode.maximumDetonation(bombs);
    Logger::WriteMessage(bombs);
    Logger::WriteMessage("result = " + to_string(result));

    bombs = { {1, 1, 5},{10, 10, 5} };
    result = leetCode.maximumDetonation(bombs);
    Logger::WriteMessage(bombs);
    Logger::WriteMessage("result = " + to_string(result));

    bombs = { {1, 2, 3},{2, 3, 1},{3, 4, 2},{4, 5, 3},{5, 6, 4} };
    result = leetCode.maximumDetonation(bombs);
    Logger::WriteMessage(bombs);
    Logger::WriteMessage("result = " + to_string(result));

    bombs = { {90, 756, 164}, { 565, 776, 5 }, { 464, 154, 271 }, { 278, 609, 82 }, { 202, 927, 219 }, { 542, 865, 377 }, { 330, 402, 270 }, { 720, 199, 10 } };;
    result = leetCode.maximumDetonation(bombs);
    Logger::WriteMessage(bombs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2093(void)
{
    Logger::WriteMessage("Test Leet Code 2093");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> highways =
    {
        {0, 1, 4},{2, 1, 3},{1, 4, 11},{3, 2, 3},{3, 4, 2}
    };
    int discounts = 1;
    int result = leetCode.minimumCost(n, highways, discounts);
    Logger::WriteMessage(highways);
    Logger::WriteMessage("n = " + to_string(n) + "; discounts = " + to_string(discounts) + "; result = " + to_string(result));

    n = 4;
    highways =
    {
        {1,3,17},{1,2,7},{3,2,5},{0,1,6},{3,0,20}
    };
    discounts = 20;
    result = leetCode.minimumCost(n, highways, discounts);
    Logger::WriteMessage(highways);
    Logger::WriteMessage("n = " + to_string(n) + "; discounts = " + to_string(discounts) + "; result = " + to_string(result));

    n = 4;
    highways =
    {
        {0,1,3},{2,3,2}
    };
    discounts = 0;
    result = leetCode.minimumCost(n, highways, discounts);
    Logger::WriteMessage(highways);
    Logger::WriteMessage("n = " + to_string(n) + "; discounts = " + to_string(discounts) + "; result = " + to_string(result));
}

void TestLeetCode743(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> times = { {2, 1, 1},{2, 3, 1},{3, 4, 1} };
    int n = 4;
    int k = 2;
    int result = leetCode.networkDelayTime(times, n, k);
    Logger::WriteMessage(times);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    times = { {1, 2, 1} };
    n = 2;
    k = 1;
    result = leetCode.networkDelayTime(times, n, k);
    Logger::WriteMessage(times);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    times = { {1, 2, 1} };
    n = 2;
    k = 2;
    result = leetCode.networkDelayTime(times, n, k);
    Logger::WriteMessage(times);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    times = { { 1, 2, 1 },{ 2, 3, 2 },{ 1, 3, 4 } };
    n = 3;
    k = 1;
    result = leetCode.networkDelayTime(times, n, k);
    Logger::WriteMessage(times);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 5;
    k = 1;
    times = { {1, 2, 1}, { 2, 3, 1 }, { 3, 4, 1 }, { 4, 5, 1 } };
    result = leetCode.networkDelayTime(times, n, k);
    Logger::WriteMessage(times);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2123(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = { {1, 1, 0},{0, 1, 1},{1, 1, 1} };
    int result = leetCode.minimumOperations(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 0, 0},{0, 0, 0},{0, 0, 0} };
    result = leetCode.minimumOperations(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1},{1, 0} };
    result = leetCode.minimumOperations(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2127(void)
{
    LeetCodeGraph leetCode;
    vector<int> favorite = { 2, 2, 1, 2 };
    int result = leetCode.maximumInvitations(favorite);
    Logger::WriteMessage(favorite);
    Logger::WriteMessage("result = " + to_string(result));

    favorite = { 1,2,0 };
    result = leetCode.maximumInvitations(favorite);
    Logger::WriteMessage(favorite);
    Logger::WriteMessage("result = " + to_string(result));

    favorite = { 3, 0, 1, 4, 1 };
    result = leetCode.maximumInvitations(favorite);
    Logger::WriteMessage(favorite);
    Logger::WriteMessage("result = " + to_string(result));

    favorite = { 1, 0 };
    result = leetCode.maximumInvitations(favorite);
    Logger::WriteMessage(favorite);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2146(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = 
    {
        {1, 2, 0, 1},{1, 3, 0, 1},{0, 2, 5, 1} 
    };
    vector<int> pricing = { 2, 5 };
    vector<int> start = { 0, 0 };
    int k = 3;
    vector<vector<int>> result = leetCode.highestRankedKItems(grid, pricing, start, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(pricing);
    Logger::WriteMessage(start);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    grid =
    {
        {1, 2, 0, 1},{1, 3, 3, 1},{0, 2, 5, 1}
    };
    pricing = { 2, 3 };
    start = { 2, 3 };
    k = 2;
    result = leetCode.highestRankedKItems(grid, pricing, start, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(pricing);
    Logger::WriteMessage(start);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    grid =
    {
        {1, 1, 1},{0, 0, 1},{2, 3, 4}
    };
    pricing = { 2, 3 };
    start = { 0, 0 };
    k = 3;
    result = leetCode.highestRankedKItems(grid, pricing, start, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(pricing);
    Logger::WriteMessage(start);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode2192(void)
{
    LeetCodeGraph leetCode;
    int n = 8;
    vector<vector<int>> edgeList =
    { 
        {0, 3},{0, 4},{1, 3},{2, 4},{2, 7},{3, 5},{3, 6},{3, 7},{4, 6} 
    };
    vector<vector<int>> result = leetCode.getAncestors(n, edgeList);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 5;
    edgeList =
    { 
        {0, 1}, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 3, 4 } 
    };
    result = leetCode.getAncestors(n, edgeList);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode2201(void)
{
    LeetCodeGraph leetCode;
    int n = 2;
    vector<vector<int>> artifacts =
    {
        {0, 0, 0, 0},{0, 1, 1, 1}
    };
    vector<vector<int>> dig = { {0, 0},{0, 1} };
    int result = leetCode.digArtifacts(n, artifacts, dig);
    Logger::WriteMessage(artifacts);
    Logger::WriteMessage(dig);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    artifacts =
    {
        {0, 0, 0, 0},{0, 1, 1, 1}
    };
    dig = { {0, 0} ,{0, 1},{1, 1} };
    result = leetCode.digArtifacts(n, artifacts, dig);
    Logger::WriteMessage(artifacts);
    Logger::WriteMessage(dig);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    artifacts =
    {
        {3,1,4,1},{1,1,2,2},{1,0,2,0},{4,3,4,4},{0,3,1,4},{2,3,3,4}
    };
    dig = { {0,0} ,{2,1},{2,0},{2,3},{4,3},{2,4},{4,1},{0,2},{4,0},{3,1},{1,2},{1,3},{3,2} };
    result = leetCode.digArtifacts(n, artifacts, dig);
    Logger::WriteMessage(artifacts);
    Logger::WriteMessage(dig);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2203(void)
{
    LeetCodeGraph leetCode;
    int n = 6;
    vector<vector<int>> edges =
    {
        {0, 2, 2},{0, 5, 6},{1, 0, 3},{1, 4, 5},{2, 1, 1},{2, 3, 3},{2, 3, 4},{3, 4, 2},{4, 5, 1}
    };
    int src1 = 0, src2 = 1, dest = 5;
    long long result = leetCode.minimumWeight(n, edges, src1, src2, dest);

    Logger::WriteMessage(edges);
    Logger::WriteMessage("src1 = " + to_string(src1) + "; src2 = " + to_string(src2) + "; dest = " + to_string(dest));
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    edges =
    {
        {0,1,1} ,{2,1,1}
    };
    src1 = 0, src2 = 1, dest = 2;
    result = leetCode.minimumWeight(n, edges, src1, src2, dest);

    Logger::WriteMessage(edges);
    Logger::WriteMessage("src1 = " + to_string(src1) + "; src2 = " + to_string(src2) + "; dest = " + to_string(dest));
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 5;
    edges =
    {
        {4, 2, 20} ,{4, 3, 46},{0, 1, 15},{0, 1, 43},{0, 1, 32},{3, 1, 13}
    };
    src1 = 0, src2 = 4, dest = 1;
    result = leetCode.minimumWeight(n, edges, src1, src2, dest);

    Logger::WriteMessage(edges);
    Logger::WriteMessage("src1 = " + to_string(src1) + "; src2 = " + to_string(src2) + "; dest = " + to_string(dest));
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}


void TestLeetCode2204(void)
{
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> edges =
    {
        {1, 2}, {2, 3}, {3, 4}, {4, 1}, {0, 1}, {5, 2}, {6, 5}
    };
    vector<int> result = leetCode.distanceToCycle(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 9;
    edges =
    {
        {0,1},{1,2},{0,2},{2,6},{6,7},{6,8},{1,3},{3,4},{3,5}
    };
    result = leetCode.distanceToCycle(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode2242(void)
{
    LeetCodeGraph leetCode;
    vector<int> scores = { 5, 2, 9, 8, 4 };
    vector<vector<int>> edges = { {0, 1},{1, 2},{2, 3},{0, 2},{1, 3},{2, 4} };
    int result = leetCode.maximumScore(scores, edges);
    Logger::WriteMessage(scores);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    scores = { 9, 20, 6, 4, 11, 12 };
    edges = { {0, 3},{5, 3},{2, 4},{1, 3} };
    result = leetCode.maximumScore(scores, edges);
    Logger::WriteMessage(scores);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2247(void)
{
    LeetCodeGraph leetCode;
    int n = 5; 
    vector<vector<int>> highways = { {0, 1, 4},{2, 1, 3},{1, 4, 11},{3, 2, 3},{3, 4, 2} };
    int k = 3;
    int result = leetCode.maximumCost(n, highways, k);
    Logger::WriteMessage(highways);
    Logger::WriteMessage("n = " + to_string(n) + "k = " + to_string(k) + "; result = " + to_string(result));

    n = 5;
    highways = { {0, 1, 3},{2, 3, 2} };
    k = 2;
    result = leetCode.maximumCost(n, highways, k);
    Logger::WriteMessage(highways);
    Logger::WriteMessage("n = " + to_string(n) + "k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2258(void)
{
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {0, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 2, 2, 1, 0},
        {0, 2, 0, 0, 1, 2, 0},
        {0, 0, 2, 2, 2, 0, 2},
        {0, 0, 0, 0, 0, 0, 0}
    };
    int result = leetCode.maximumMinutes(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {0,0,0,0},{0,1,2,0},{0,2,0,0}
    };
    result = leetCode.maximumMinutes(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {0, 0, 0},{2, 2, 0},{1, 2, 0}
    };
    result = leetCode.maximumMinutes(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2257(void)
{
    Logger::WriteMessage("Test Leet Code 2257");
    LeetCodeGraph leetCode;
    int m = 4;
    int n = 6;
    vector<vector<int>> guards = { {0, 0},{1, 1},{2, 3} };
    vector<vector<int>> walls = { {0, 1},{2, 2},{1, 4} };
    int result = leetCode.countUnguarded(m, n, guards, walls);
    Logger::WriteMessage(guards);
    Logger::WriteMessage(walls);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    m = 3;
    n = 3;
    guards = { {1, 1} };
    walls = { {0, 1},{1, 0},{2, 1}, {1, 2} };
    result = leetCode.countUnguarded(m, n, guards, walls);
    Logger::WriteMessage(guards);
    Logger::WriteMessage(walls);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    m = 8;
    n = 9;
    guards = { {5, 8},{5, 5},{4, 6},{0, 5},{6, 5} };
    walls = { {4, 1} };
    result = leetCode.countUnguarded(m, n, guards, walls);
    Logger::WriteMessage(guards);
    Logger::WriteMessage(walls);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2290(void)
{
    Logger::WriteMessage("Test Leet Code 2290");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = { {0, 1, 1},{1, 1, 0},{1, 1, 0} };
    int result = leetCode.minimumObstacles(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1, 0, 0, 0},{0, 1, 0, 1, 0},{0, 0, 0, 1, 0} };
    result = leetCode.minimumObstacles(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2307(void)
{
    Logger::WriteMessage("Test Leet Code 2307");
    LeetCodeGraph leetCode;
    vector<vector<string>> equations = { {"a", "b"},{"b", "c"},{"a", "c"} };
    vector<double> values = { 3, 0.5, 1.5 };
    bool result = leetCode.checkContradictions(equations, values);
    Logger::WriteMessage(equations);
    Logger::WriteMessage(values);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));

    equations = { {"le", "et"},{"le", "code"},{"code", "et"} };
    values = { 2,5,0.5 };
    result = leetCode.checkContradictions(equations, values);
    Logger::WriteMessage(equations);
    Logger::WriteMessage(values);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2316(void)
{
    Logger::WriteMessage("Test Leet Code 2316");
    LeetCodeGraph leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 2} };
    long long result = leetCode.countPairs(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    edges = { {0, 2},{0, 5},{2, 4},{1, 6},{5, 4} };
    result = leetCode.countPairs(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 16;
    edges = { {0, 15},{1, 14},{2, 11},{4, 3},{5, 15},{8, 2},{14, 12} };
    result = leetCode.countPairs(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2322(void)
{
    Logger::WriteMessage("Test Leet Code 2322");
    LeetCodeGraph leetCode;
    vector<int> nums = { 1, 5, 5, 4, 11 };
    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 3},{3, 4} };
    int result = leetCode.minimumScore(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 5,5,2,4,4,2 };
    edges = { {0,1} ,{1,2},{5,2},{4,3},{1,3} };
    result = leetCode.minimumScore(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2328(void)
{
    Logger::WriteMessage("Test Leet Code 2328");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = { {1, 1}, {3, 4} };
    int result = leetCode.countPaths(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1},{2} };
    result = leetCode.countPaths(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2368(void)
{
    Logger::WriteMessage("Test Leet Code 2368");
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> edges = 
    { 
        {0, 1},{1, 2},{3, 1},{4, 0},{0, 5},{5, 6} 
    };
    vector<int> restricted = { 4, 5 };
    int result = leetCode.reachableNodes(n, edges, restricted);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(restricted);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 7;
    edges =
    {
        {0,1},{0,2},{0,5},{0,4},{3,2},{6,5}
    };
    restricted = { 4, 2, 1 };
    result = leetCode.reachableNodes(n, edges, restricted);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(restricted);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2359(void)
{
    Logger::WriteMessage("Test Leet Code 2359");
    LeetCodeGraph leetCode;
    vector<int> edges = { 2, 2, 3, -1 };
    int node1 = 0, node2 = 1;
    int result = leetCode.closestMeetingNode(edges, node1, node2);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("node1 = " + to_string(node1) + "; node2 = " + to_string(node2) + "; result = " + to_string(result));

    edges = { 1, 2, -1};
    node1 = 0, node2 = 2;
    result = leetCode.closestMeetingNode(edges, node1, node2);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("node1 = " + to_string(node1) + "; node2 = " + to_string(node2) + "; result = " + to_string(result));
}

void TestLeetCode2360(void)
{
    Logger::WriteMessage("Test Leet Code 2360");
    LeetCodeGraph leetCode;
    vector<int> edges = { 3,3,4,2,3 };
    int result = leetCode.longestCycle(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { 2,-1,3,1 };
    result = leetCode.longestCycle(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { -1, 4, -1, 2, 0, 4 };
    result = leetCode.longestCycle(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2374(void)
{
    Logger::WriteMessage("Test Leet Code 2374");
    LeetCodeGraph leetCode;
    vector<int> edges = { 1, 0, 0, 0, 0, 7, 7, 5 };
    int result = leetCode.edgeScore(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { 2,0,0,2 };
    result = leetCode.edgeScore(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2392(void)
{
    Logger::WriteMessage("Test Leet Code 2392");
    LeetCodeGraph leetCode;
    int k = 3;
    vector<vector<int>> rowConditions = { {1, 2},{3, 2} };
    vector<vector<int>> colConditions = { {2, 1},{3, 2} };
    vector<vector<int>> result = leetCode.buildMatrix(k, rowConditions, colConditions);
    Logger::WriteMessage(rowConditions);
    Logger::WriteMessage(colConditions);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    k = 3;
    rowConditions = { {1, 2},{2, 3},{3, 1},{2, 3} };
    colConditions = { {2, 1} };
    result = leetCode.buildMatrix(k, rowConditions, colConditions);
    Logger::WriteMessage(rowConditions);
    Logger::WriteMessage(colConditions);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode2421(void)
{
    Logger::WriteMessage("Test Leet Code 2421");
    LeetCodeGraph leetCode;
    vector<int> vals = { 1, 3, 2, 1, 3 };
    vector<vector<int>> edges = { {0, 1},{0, 2},{2, 3},{2, 4} };
    int result = leetCode.numberOfGoodPaths(vals, edges);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    vals = { 1,1,2,2,3 };
    edges = { {0, 1},{1, 2},{2, 3},{2, 4} };
    result = leetCode.numberOfGoodPaths(vals, edges);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    vals = { 1 };
    edges = { };
    result = leetCode.numberOfGoodPaths(vals, edges);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    vals = { 2, 5, 5, 1, 5, 2, 3, 5, 1, 5 };
    edges = { {0, 1},{2, 1},{3, 2},{3, 4},{3, 5},{5, 6},{1, 7},{8, 4},{9, 7} };
    result = leetCode.numberOfGoodPaths(vals, edges);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2467(void)
{
    Logger::WriteMessage("Test Leet Code 2467");
    LeetCodeGraph leetCode;
    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 3},{3, 4} };
    int bob = 3;
    vector<int> amount = { -2, 4, 2, -4, 6 };
    int result = leetCode.mostProfitablePath(edges, bob, amount);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(amount);
    Logger::WriteMessage("bob = " + to_string(bob) + "; result = " + to_string(result));

    edges = { {0, 1}};
    bob = 1;
    amount = { -7280, 2350 };
    result = leetCode.mostProfitablePath(edges, bob, amount);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(amount);
    Logger::WriteMessage("bob = " + to_string(bob) + "; result = " + to_string(result));

    edges = { {0, 38}, { 0,59 }, { 1,30 }, { 1,62 }, { 1,53 }, { 2,41 }, { 2,37 }, { 3,21 }, { 4,35 }, { 4,54 }, { 5,32 }, { 5,69 }, { 6,26 }, { 6,16 }, { 6,61 }, { 6,52 }, { 7,34 }, { 8,10 }, { 9,11 }, { 9,43 }, { 10,48 }, { 11,29 }, { 12,63 }, { 12,58 }, { 12,13 }, { 13,36 }, { 13,34 }, { 14,65 }, { 14,15 }, { 15,17 }, { 15,49 }, { 16,40 }, { 17,20 }, { 17,24 }, { 18,58 }, { 19,25 }, { 21,34 }, { 22,55 }, { 23,45 }, { 23,59 }, { 25,43 }, { 27,32 }, { 28,49 }, { 28,33 }, { 31,61 }, { 33,39 }, { 33,51 }, { 33,53 }, { 34,68 }, { 34,69 }, { 37,52 }, { 42,52 }, { 43,61 }, { 44,58 }, { 46,49 }, { 47,55 }, { 47,50 }, { 48,56 }, { 48,66 }, { 50,58 }, { 52,66 }, { 52,65 }, { 53,57 }, { 54,63 }, { 55,57 }, { 59,60 }, { 59,67 }, { 59,65 }, { 64,69 } };
    bob = 15;
    amount = { 4664, 5822, -9152, 7258, -5468, 4698, 2568, 9880, -4046, 9884, -3540, -2260, 5264, -7050, -6998, -1688, -6256, -5350, 5136, 7476, -4108, 1288, 1336, -6126, 2940, 698, -2900, -2342, -2310, 858, 572, 640, -9674, 5746, 5068, 7128, 636, 6680, -1840, 3574, 7592, -5882, -1974, -2766, -620, 1088, -8930, 7756, 9966, 380, 8884, -954, -8198, -5862, -3100, 7728, 7090, -4648, 4076, 994, 4232, 9810, -2904, -1106, -4172, -5884, -9582, 5320, -4086, 6346 };
    result = leetCode.mostProfitablePath(edges, bob, amount);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(amount);
    Logger::WriteMessage("bob = " + to_string(bob) + "; result = " + to_string(result));
}

void TestLeetCode2473(void)
{
    Logger::WriteMessage("Test Leet Code 2473");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> roads = 
    {
        {1, 2, 4},{2, 3, 2},{2, 4, 5},{3, 4, 1},{1, 3, 4} 
    };
    vector<int> appleCost = { 56, 42, 102, 301 };
    int k = 2;
    vector<long long> result = leetCode.minCost(n, roads, appleCost, k);
    Logger::WriteMessage(roads);
    Logger::WriteMessage(appleCost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 3;
    roads =
    {
        {1,2,5},{2,3,1},{3,1,2}
    };
    appleCost = { 2, 3, 1 };
    k = 3;
    result = leetCode.minCost(n, roads, appleCost, k);
    Logger::WriteMessage(roads);
    Logger::WriteMessage(appleCost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode2477(void)
{
    Logger::WriteMessage("Test Leet Code 2477");
    LeetCodeGraph leetCode;
    vector<vector<int>> roads = { {0, 1},{0, 2},{0, 3} };
    int seats = 5;
    long long result = leetCode.minimumFuelCost(roads, seats);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("seats = " + to_string(seats) + "; result = " + to_string(result));

    roads = { {3, 1},{3, 2},{1, 0},{0, 4},{0, 5},{4, 6} };
    seats = 2;
    result = leetCode.minimumFuelCost(roads, seats);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("seats = " + to_string(seats) + "; result = " + to_string(result));

    roads = { };
    seats = 1;
    result = leetCode.minimumFuelCost(roads, seats);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("seats = " + to_string(seats) + "; result = " + to_string(result));
}

void TestLeetCode2492(void)
{
    Logger::WriteMessage("Test Leet Code 2492");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> roads = { {1, 2, 9},{2, 3, 6},{2, 4, 5},{1, 4, 7} };
    int result = leetCode.minScore(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    roads = { {1, 2, 2},{1, 3, 4},{3, 4, 7} };
    result = leetCode.minScore(n, roads);
    Logger::WriteMessage(roads);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2497(void)
{
    Logger::WriteMessage("Test Leet Code 2497");
    LeetCodeGraph leetCode;
    vector<int> vals = { 1, 2, 3, 4, 10, -10, -20 };
    vector<vector<int>> edges = 
    { 
        {0, 1},{1, 2},{1, 3},{3, 4},{3, 5},{3, 6} 
    };
    int k = 2;
    int result = leetCode.maxStarSum(vals, edges, k);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    vals = { -5 };
    edges =
    {
    };
    k = 0;
    result = leetCode.maxStarSum(vals, edges, k);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2493(void)
{
    Logger::WriteMessage("Test Leet Code 2493");
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> edges =
    {
        {1, 2},{1, 4},{1, 5},{2, 6},{2, 3},{4, 6}
    };
    int result = leetCode.magnificentSets(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    edges =
    {
        {1,2},{2,3},{3,4},{4,1}
    };
    result = leetCode.magnificentSets(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 92;
    edges =
    {
        {67,29},{13,29},{77,29},{36,29},{82,29},{54,29},{57,29},{53,29},{68,29},{26,29},{21,29},
        {46,29},{41,29},{45,29},{56,29},{88,29},{2,29},{7,29},{5,29},{16,29},{37,29},{50,29},{79,29},
        {91,29},{48,29},{87,29},{25,29},{80,29},{71,29},{9,29},{78,29},{33,29},{4,29},{44,29},{72,29},
        {65,29},{61,29}
    };
    result = leetCode.magnificentSets(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
    
}

void TestLeetCode2503(void)
{
    Logger::WriteMessage("Test Leet Code 2503");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {1,2,3} ,{2,5,7}, {3,5,1}
    };
    vector<int> queries = { 5,6,2 };
    vector<int> result = leetCode.maxPoints(grid, queries);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    grid =
    {
        { 5,2,1 }, { 1,1,2 }
    };
    queries = { 5, 3, 1 };
    result = leetCode.maxPoints(grid, queries);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2508(void)
{
    Logger::WriteMessage("Test Leet Code 2508");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> edges = 
    {
        {1, 2},{2, 3},{3, 4},{4, 2},{1, 4},{2, 5} 
    };
    bool result = leetCode.isPossible(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "result = " + (string)(result ? "true" : "false"));

    n = 4;
    edges =
    {
        {1, 2},{3, 4}
    };
    result = leetCode.isPossible(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "result = " + (string)(result ? "true" : "false"));

    n = 4;
    edges =
    {
        {1, 2},{1, 3}, {1, 4}
    };
    result = leetCode.isPossible(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2556(void)
{
    Logger::WriteMessage("Test Leet Code 2556");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid = 
    { 
        {1, 1, 1},{1, 0, 0},{1, 1, 1} 
    };
    bool result = leetCode.isPossibleToCutPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    grid =
    {
        {1,1,1},{1,0,1},{1,1,1}
    };
    result = leetCode.isPossibleToCutPath(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2577(void)
{
    Logger::WriteMessage("Test Leet Code 2577");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {0,1,3,2}, {5,1,2,5}, {4,3,8,6}
    };
    int result = leetCode.minimumTime(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {0,2,4} ,{3,2,1},{1,0,4}
    };
    result = leetCode.minimumTime(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2603(void)
{
    Logger::WriteMessage("Test Leet Code 2603");
    LeetCodeGraph leetCode;
    vector<int> coins = { 1, 0, 0, 0, 0, 1 };
    vector<vector<int>> edges = { {0, 1},{1, 2},{2, 3},{3, 4},{4, 5} };
    int result = leetCode.collectTheCoins(coins, edges);
    Logger::WriteMessage(coins);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    coins = { 0, 0, 0, 1, 1, 0, 0, 1 };
    edges = { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{5, 6},{5, 7} };
    result = leetCode.collectTheCoins(coins, edges);
    Logger::WriteMessage(coins);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    coins = { 0, 1, 0, 0, 0, 1, 0, 0 };
    edges = { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{5, 6},{5, 7} };
    result = leetCode.collectTheCoins(coins, edges);
    Logger::WriteMessage(coins);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2608(void)
{
    Logger::WriteMessage("Test Leet Code 2608");
    LeetCodeGraph leetCode;
    int n = 7;
    vector<vector<int>> edges =
    {
        {0, 1},{1, 2},{2, 0},{3, 4}, {4, 5 }, { 5, 6 }, { 6, 3 }
    };
    int result = leetCode.findShortestCycle(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    edges = { {0, 1},{0, 2} };
    result = leetCode.findShortestCycle(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 20;
    edges =
    {
        {8, 19}, { 1, 19 }, { 0, 19 }, { 7, 15 }, { 13, 17 }, { 4, 19 },
        { 2, 6 }, { 17, 18 }, { 7, 14 }, { 7, 18 }, { 5, 6 }, { 16, 17 },
        { 1, 12 }, { 9, 16 }, { 6, 15 }, { 2, 14 }, { 4, 17 }, { 2, 10 },
        { 0, 18 }, { 7, 11 }, { 5, 14 }, { 8, 14 }, { 4, 9 },
        { 7, 9 }, { 9, 18 }, { 0, 14 }
    };
    result = leetCode.findShortestCycle(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2617(void)
{
    Logger::WriteMessage("Test Leet Code 2617");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {3, 4, 2, 1},{4, 2, 3, 1},{2, 1, 0, 0},{2, 4, 0, 0}
    };
    int result = leetCode.minimumVisitedCells(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {3,4,2,1},{4,2,1,1},{2,1,1,0},{3,4,1,0 }
    };
    result = leetCode.minimumVisitedCells(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {2,1,0},{1,0,0}
    };
    result = leetCode.minimumVisitedCells(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2646(void)
{
    Logger::WriteMessage("Test Leet Code 2646");
    LeetCodeGraph leetCode;
    int n = 4; 
    vector<vector<int>> edges =
    {
        {0, 1} ,{1, 2},{1, 3}
    };
    vector<int> price = { 2, 2, 10, 6 };
    vector<vector<int>> trips = { {0, 3},{2, 1},{2, 3} };
    int result = leetCode.minimumTotalPrice(n, edges, price, trips);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(price);
    Logger::WriteMessage(trips);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    edges =
    {
        {0, 1}
    };
    price = { 2, 2};
    trips = { {0, 0} };
    result = leetCode.minimumTotalPrice(n, edges, price, trips);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(price);
    Logger::WriteMessage(trips);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2658(void)
{
    Logger::WriteMessage("Test Leet Code 2658");
    LeetCodeGraph leetCode;
    vector<vector<int>> grid =
    {
        {0, 2, 1, 0},{4, 0, 0, 3},{1, 0, 0, 4},{0, 3, 2, 0}
    };
    int result = leetCode.findMaxFish(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}
    };
    result = leetCode.findMaxFish(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2662(void)
{
    Logger::WriteMessage("Test Leet Code 2662");
    LeetCodeGraph leetCode;
    vector<int> start = { 1, 1 }, target = { 4, 5 };
    vector<vector<int>> specialRoads = 
    { 
        {1, 2, 3, 3, 2},{3, 4, 4, 5, 1} 
    };
    int result = leetCode.minimumCost(start, target, specialRoads);
    Logger::WriteMessage(start);
    Logger::WriteMessage(target);
    Logger::WriteMessage(specialRoads);
    Logger::WriteMessage("result = " + to_string(result));

    start = { 3,2 }, target = { 5, 7 };
    specialRoads =
    {
        {3,2,3,4,4} ,{3,3,5,5,5},{3,4,5,6,6}
    };
    result = leetCode.minimumCost(start, target, specialRoads);
    Logger::WriteMessage(start);
    Logger::WriteMessage(target);
    Logger::WriteMessage(specialRoads);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2685(void)
{
    Logger::WriteMessage("Test Leet Code 2685");
    LeetCodeGraph leetCode;
    int n = 6;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 2},{3, 4} };
    int result = leetCode.countCompleteComponents(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 6;
    edges = { {0, 1},{0, 2},{1, 2},{3, 4},{3, 5} };
    result = leetCode.countCompleteComponents(n, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2699(void)
{
    Logger::WriteMessage("Test Leet Code 2699");
    LeetCodeGraph leetCode;
    int n = 5;
    vector<vector<int>> edges =
    { 
        {4, 1, -1},{2, 0, -1},{0, 3, -1},{4, 3, -1} 
    };
    int source = 0, destination = 1, target = 5;
    vector<vector<int>> result = leetCode.modifiedGraphEdges(n, 
        edges, source, destination, target);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source));
    Logger::WriteMessage("destination = " + to_string(destination) + "; target = " + to_string(target));
    Logger::WriteMessage(result);

    n = 3;
    edges =
    {
        {0,1,-1}, {0,2,5}
    };
    source = 0, destination = 2, target = 6;
    result = leetCode.modifiedGraphEdges(n,
        edges, source, destination, target);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source));
    Logger::WriteMessage("destination = " + to_string(destination) + "; target = " + to_string(target));
    Logger::WriteMessage(result);

    n = 4;
    edges = { {1, 0, 4},{1, 2, 3},{2, 3, 5},{0, 3, -1} };
    source = 0, destination = 2, target = 6;
    result = leetCode.modifiedGraphEdges(n,
        edges, source, destination, target);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; source = " + to_string(source));
    Logger::WriteMessage("destination = " + to_string(destination) + "; target = " + to_string(target));
    Logger::WriteMessage(result);
}

void TestLeetCode2713(void)
{
    Logger::WriteMessage("Test Leet Code 2713");
    LeetCodeGraph leetCode;
    vector<vector<int>> mat = 
    { 
        {3, 1},{3, 4} 
    };
    int result = leetCode.maxIncreasingCells(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
    
    mat = { {1, 1},{1, 1} };
    result = leetCode.maxIncreasingCells(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat =
    {
        {3, 1, 6},{-9, 5, 7}
    };
    result = leetCode.maxIncreasingCells(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));

    mat =
    {
        {9, 2, 3},{7, 5, 8},{6, 6, 8},{7, 8, 9}
    };
    result = leetCode.maxIncreasingCells(mat);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2709(void)
{
    Logger::WriteMessage("Test Leet Code 2709");
    LeetCodeGraph leetCode;
    vector<int> nums = { 2, 3, 6 };
    bool result = leetCode.canTraverseAllPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3,9,5 };
    result = leetCode.canTraverseAllPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 4,3,12,8 };
    result = leetCode.canTraverseAllPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 99991, 99991, 99991, 99991, 99991};
    result = leetCode.canTraverseAllPairs(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2714(void)
{
    Logger::WriteMessage("Test Leet Code 2714");
    LeetCodeGraph leetCode;
    int n = 4;
    vector<vector<int>> edges =
    {
        {0, 1, 4},{0, 2, 2},{2, 3, 6}
    }; 
    int s = 1, d = 3, k = 2;
    int result = leetCode.shortestPathWithHops(n, edges, s, d, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("s = " + to_string(s) + "; d = " + to_string(d));
    Logger::WriteMessage("result = " + to_string(result));

    n = 7;
    edges =
    {
        {3, 1, 9},{3, 2, 4},{4, 0, 9},{0, 5, 6},{3, 6, 2},
        {6, 0, 4},{1, 2, 4}
    };
    s = 4, d = 1, k = 2;
    result = leetCode.shortestPathWithHops(n, edges, s, d, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("s = " + to_string(s) + "; d = " + to_string(d));
    Logger::WriteMessage("result = " + to_string(result));

    n = 5; 
    edges =
    {
        {0, 4, 2},{0, 1, 3},{0, 2, 1},{2, 1, 4},{1, 3, 4},{3, 4, 7}
    };
    s = 2, d = 3, k = 1;
    result = leetCode.shortestPathWithHops(n, edges, s, d, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("s = " + to_string(s) + "; d = " + to_string(d));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2737(void)
{
    Logger::WriteMessage("Test Leet Code 2737");
    LeetCodeGraph leetCode;
    int n = 4;
    int s = 0;
    vector<vector<int>> edges =
    {
        {0, 1, 1} ,{1, 2, 3}, {2, 3, 2}, {0, 3, 4}
    };
    vector<int> marked = { 2, 3 };
    int result = leetCode.minimumDistance(n, edges, s, marked);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(marked);
    Logger::WriteMessage("n = " + to_string(n) + "; s = " + to_string(s));
    Logger::WriteMessage("result = " + to_string(result));

    n = 5;
    s = 1;
    edges =
    {
        {0, 1, 2}, {0, 2, 4}, {1, 3, 1}, {2, 3, 3}, {3, 4, 2}
    };
    marked = { 0, 4 };
    result = leetCode.minimumDistance(n, edges, s, marked);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(marked);
    Logger::WriteMessage("n = " + to_string(n) + "; s = " + to_string(s));
    Logger::WriteMessage("result = " + to_string(result));

    n = 4;
    s = 3;
    edges =
    {
        {0,1,1} ,{1,2,3}, {2,3,2}
    };
    marked = { 0, 1 };
    result = leetCode.minimumDistance(n, edges, s, marked);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(marked);
    Logger::WriteMessage("n = " + to_string(n) + "; s = " + to_string(s));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2814(void)
{
    Logger::WriteMessage("Test Leet Code 2814");
    LeetCodeGraph leetCode;
    vector<vector<string>> land =
    {
        {"D", ".", "*"},{".", ".", "."},{".", "S", "."}
    };
    int result = leetCode.minimumSeconds(land);
    Logger::WriteMessage(land);
    Logger::WriteMessage("result = " + to_string(result));

    land =
    {
        {"D","X","*"}, {".",".","."}, {".",".","S"}
    };
    result = leetCode.minimumSeconds(land);
    Logger::WriteMessage(land);
    Logger::WriteMessage("result = " + to_string(result));

    land =
    {
        {"D",".",".",".","*","."},{".","X",".","X",".","."},{".",".",".",".","S","."}
    };
    result = leetCode.minimumSeconds(land);
    Logger::WriteMessage(land);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeGraph(void)
{
    TestLeetCode2814();
    TestLeetCode2737();
    TestLeetCode2714();
    TestLeetCode2709();
    TestLeetCode2713();
    TestLeetCode2699();
    TestLeetCode2685();
    TestLeetCode2662();
    TestLeetCode2658();
    TestLeetCode2646();
    TestLeetCode2617();
    TestLeetCode2608();
    TestLeetCode2603();
    TestLeetCode2577();
    TestLeetCode2556();
    TestLeetCode2508();
    TestLeetCode2503();
    TestLeetCode2493();
    TestLeetCode2497();
    TestLeetCode2492();
    TestLeetCode2477();
    TestLeetCode2473();
    TestLeetCode2467();
    TestLeetCode2421();
    TestLeetCode2392();
    TestLeetCode2374();
    TestLeetCode2360();
    TestLeetCode2359();
    TestLeetCode2368();
    TestLeetCode2328();
    TestLeetCode2322();
    TestLeetCode2316();
    TestLeetCode2307();
    TestLeetCode2290();
    TestLeetCode2257();
    TestLeetCode2258();
    TestLeetCode2247();
    TestLeetCode2242();
    TestLeetCode2204();
    TestLeetCode2203();
    TestLeetCode2201();
    TestLeetCode2192();
    TestLeetCode2146();
    TestLeetCode2127();
    TestLeetCode2123();
    TestLeetCode305();
    TestLeetCode743();
    TestLeetCode444();
    TestLeetCode207();
    TestLeetCode210();
    TestLeetCode2093();
    TestLeetCode2101();
    TestLeetCode2115();
    TestLeetCode2059();
    TestLeetCode2049();
    TestLeetCode2039();
    TestLeetCode2087();
    TestLeetCode1976();
    TestLeetCode2097();
    TestLeetCode2061();
    TestLeetCode2077();
    TestLeetCode1971();
    TestLeetCode2092();
    TestLeetCode1956();
    TestLeetCode1992();
    TestLeetCode2050();
    TestLeetCode2076();
    TestLeetCode2065();
    TestLeetCode2045();
    TestLeetCode1958();
    TestLeetCode1998();
    TestLeetCode1970();
    TestLeetCode1926();
    TestLeetCode1905();
    TestLeetCode1901();
    TestLeetCode1928();
    TestLeetCode1857();
    TestLeetCode1820();
    TestLeetCode1791();
    TestLeetCode1761();
    TestLeetCode1782();
    TestLeetCode1786();
    TestLeetCode1765();
    TestLeetCode1743();
    TestLeetCode1730();
    TestLeetCode1719();
    TestLeetCode1722();
    TestLeetCode1697();
    TestLeetCode1654();
    TestLeetCode1631();
    TestLeetCode1627();
    TestLeetCode1617();
    TestLeetCode1615();
    TestLeetCode1591();
    TestLeetCode1575();
    TestLeetCode1579();
    TestLeetCode1584();
    TestLeetCode1568();
    TestLeetCode787();
    TestLeetCode1559();
    TestLeetCode1548();
    TestLeetCode1514();
    TestLeetCode1494();
    TestLeetCode1489();
    TestLeetCode997();
    TestLeetCode1466();
    TestLeetCode1462();
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
    TestLeetCode778();
    TestLeetCode815();
    TestLeetCode444();
    TestLeetCode269();
    TestLeetCode286();
    TestLeetCode9902();
}
