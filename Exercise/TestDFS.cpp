#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDFS.h"
#include "TestDFS.h"

void TestLeetCode1219(void)
{
    Logger::WriteMessage("Test Leet Code 1219");
    LeetCodeDFS leetCode;
    vector<vector<int>> grid =
    {
        {0,6,0},
        {5,8,7},
        {0,9,0}
    };
    int result = leetCode.getMaximumGold(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {1,0,7},
        {2,0,6},
        {3,4,5},
        {0,3,0},
        {9,0,20}
    };
    result = leetCode.getMaximumGold(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid =
    {
        {3, 31, 23, 3, 15, 20, 12},
        {0, 8, 11, 25, 0, 31, 20},
        {39, 30, 16, 11, 2, 29, 34},
        {13, 38, 35, 3, 0, 14, 9},
    };
    result = leetCode.getMaximumGold(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1240(void)
{
    Logger::WriteMessage("Test Leet Code 1240");
    LeetCodeDFS leetCode;
    int n = 13;
    int m = 11;
    int result = leetCode.tilingRectangle(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 2;
    m = 3;
    result = leetCode.tilingRectangle(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 5;
    m = 8;
    result = leetCode.tilingRectangle(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode1286(void)
{
    Logger::WriteMessage("Test Leet Code 1286");

    vector<string> commands =
    {
        "CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"
    };
    vector<vector<string>> data =
    {
        {"abc", "2"},{},{},{},{},{},{}
    };
    CombinationIterator* combinationIterator = nullptr;
    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "CombinationIterator")
        {
            combinationIterator = new CombinationIterator(data[i][0], atoi(data[i][1].c_str()));
            result.push_back("null");
        }
        else if (commands[i] == "next")
        {
            string str = combinationIterator->next();
            result.push_back(str);
        }
        else if (commands[i] == "hasNext")
        {
            bool ret = combinationIterator->hasNext();
            result.push_back(to_string(ret));
        }
    }
    delete combinationIterator;
    Logger::WriteMessage(result);
}

void TestLeetCode1307(void)
{
    Logger::WriteMessage("Test Leet Code 1307");
    LeetCodeDFS leetCode;
    vector<string> words = { "SEND", "MORE" };
    string result = "MONEY";
    bool is_solvable = leetCode.isSolvable(words, result);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + result + "; is_solvable = " + (string)(is_solvable ? "true" : "false"));

    words = { "SIX","SEVEN","SEVEN" };
    result = "TWENTY";
    is_solvable = leetCode.isSolvable(words, result);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + result + "; is_solvable = " + (string)(is_solvable ? "true" : "false"));

    words = { "THIS","IS","TOO" };
    result = "FUNNY";
    is_solvable = leetCode.isSolvable(words, result);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + result + "; is_solvable = " + (string)(is_solvable ? "true" : "false"));

    words = { "LEET","CODE" };
    result = "POINT";
    is_solvable = leetCode.isSolvable(words, result);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + result + "; is_solvable = " + (string)(is_solvable ? "true" : "false"));
}

void TestLeetCodeDFS(void)
{
    TestLeetCode1307();
    TestLeetCode1286();
    TestLeetCode1240();
    TestLeetCode1219();
}