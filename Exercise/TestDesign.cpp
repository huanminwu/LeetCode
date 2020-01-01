#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDesign.h"
#include "TestDesign.h"
void TestLeetCode146(void)
{
    Logger::WriteMessage("Test Leet Code 146");

    vector<string> commands =
    {
        "LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"
    };
    vector<vector<int>> data =
    {
        {2},{1,1},{2, 2},{1},{3,3},{2}, {4,4},{1},{3},{4}
    };
    LRUCache* lruCache = nullptr;
    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "LRUCache")
        {
            lruCache = new LRUCache(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "put")
        {
            lruCache->put(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "get")
        {
            int ret = lruCache->get(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    delete lruCache;
    Logger::WriteMessage(result);
}

void TestLeetCode716(void)
{
    Logger::WriteMessage("Test Leet Code 716");
    vector<string> commands =
    {
        "MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"
    };
    vector<vector<int>> data =
    {
        {},{5},{1},{5},{},{},{},{},{},{}
    };
    vector<string> result;
    MaxStack* maxStack = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MaxStack")
        {
            maxStack = new MaxStack();
            result.push_back("null");
        }
        else if (commands[i] == "push")
        {
            maxStack->push(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "pop")
        {
            int ret = maxStack->pop();
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "top")
        {
            int ret = maxStack->top();
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "peekMax")
        {
            int ret = maxStack->peekMax();
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "popMax")
        {
            int ret = maxStack->popMax();
            result.push_back(to_string(ret));
        }
    }
    delete maxStack;
    Logger::WriteMessage(result);
}

void TestLeetCode895(void)
{
    Logger::WriteMessage("Test Leet Code 895");
    vector<string> commands =
    {
        "FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"
    };
    vector<vector<int>> data =
    {
        {},{5},{7},{5},{7},{4},{5},{},{},{},{}
    };
    vector<string> result;
    FreqStack* freqStack = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FreqStack")
        {
            freqStack = new FreqStack();
            result.push_back("null");
        }
        else if (commands[i] == "push")
        {
            freqStack->push(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "pop")
        {
            int value = freqStack->pop();
            result.push_back(to_string(value));
        }
    }
    delete freqStack;
    Logger::WriteMessage(commands);
    for (size_t i = 0; i < data.size(); i++)
    {
        Logger::WriteMessage(data[i]);
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1146(void)
{
    Logger::WriteMessage("Test Leet Code 1146");
    vector<string> command = { "SnapshotArray","set","snap","set","get" };
    vector<vector<int>> params = { {3}, {0, 5}, {}, {0, 6}, {0,0} };
    vector<string> result;
    class SnapshotArray* snapshotArray = nullptr;
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "SnapshotArray")
        {
            snapshotArray = new SnapshotArray(params[i][0]);
            result.push_back("null");
        }
        else if (command[i] == "set")
        {
            snapshotArray->set(params[i][0], params[i][1]);
            result.push_back("null");
        }
        else if (command[i] == "snap")
        {
            int snapshot_id = snapshotArray->snap();
            result.push_back(to_string(snapshot_id));
        }
        else if (command[i] == "get")
        {
            int value = snapshotArray->get(params[i][0], params[i][1]);
            result.push_back(to_string(value));
        }
    }
    Logger::WriteMessage(result);
    if (snapshotArray != nullptr)
    {
        delete snapshotArray;
        snapshotArray = nullptr;
    }
}

void TestLeetCode460(void)
{
    Logger::WriteMessage("Test Leet Code 460");
    vector<string> actions = { "LFUCache","put","put","get","put","get","get","put","get","get","get" };
    vector<vector<int>> parameters = { {2},{ 1,1 },{ 2,2 },{ 1 },{ 3,3 },{ 2 },{ 3 },{ 4,4 },{ 1 },{ 3 },{ 4 } };
    vector<string> result;
    LFUCache cache(0);
    Logger::WriteMessage(actions);
    Logger::WriteMessage(parameters);
    for (size_t i = 0; i < actions.size(); i++)
    {
        if (actions[i] == "LFUCache")
        {
            cache = LFUCache(parameters[i][0]);
            result.push_back("null");
        }
        else if (actions[i] == "put")
        {
            cache.put(parameters[i][0], parameters[i][1]);
            result.push_back("null");
        }
        else if (actions[i] == "get")
        {
            int value = cache.get(parameters[i][0]);
            result.push_back(to_string(value));
        }
    }
    Logger::WriteMessage(result);


    actions = { "LFUCache","put","put","get","put","put","get" };
    parameters = { { 2 },{ 2, 1 },{ 2, 2 },{ 2 },{ 1, 1 },{ 4, 1 },{ 2 } };
    result.clear();
    Logger::WriteMessage(actions);
    Logger::WriteMessage(parameters);
    for (size_t i = 0; i < actions.size(); i++)
    {
        if (actions[i] == "LFUCache")
        {
            cache = LFUCache(parameters[i][0]);
            result.push_back("null");
        }
        else if (actions[i] == "put")
        {
            cache.put(parameters[i][0], parameters[i][1]);
            result.push_back("null");
        }
        else if (actions[i] == "get")
        {
            int value = cache.get(parameters[i][0]);
            result.push_back(to_string(value));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode900(void)
{
    Logger::WriteMessage("Test Leet Code 900");
    vector<string> commands =
    {
        "RLEIterator","next","next","next","next"
    };
    vector<vector<int>> data =
    {
        { 3,8,0,9,2,5 },{ 2 },{ 1 },{ 1 },{ 2 }
    };
    vector<string> result;
    RLEIterator* rleIterator = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "RLEIterator")
        {
            rleIterator = new RLEIterator(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "next")
        {
            int value = rleIterator->next(data[i][0]);
            result.push_back(to_string(value));
        }
    }
    delete rleIterator;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode1244(void)
{
    Logger::WriteMessage("Test Leet Code 1244");
    vector<string> command = 
    { 
        "Leaderboard","addScore", "addScore", "addScore", "addScore", "addScore", 
        "top","reset","reset","addScore","top"
    };
    vector<vector<int>> params = 
    { 
        {} ,{1,73},{2,56},{3,39},{4,51},{5,4},{1},{1},{2},{2,51},{3} 
    };
    vector<string> result;
    class Leaderboard* leaderboard = nullptr;
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "Leaderboard")
        {
            leaderboard = new Leaderboard();
            result.push_back("null");
        }
        else if (command[i] == "addScore")
        {
            leaderboard->addScore(params[i][0], params[i][1]);
            result.push_back("null");
        }
        else if (command[i] == "top")
        {
            int score = leaderboard->top(params[i][0]);
            result.push_back(to_string(score));
        }
        else if (command[i] == "reset")
        {
            leaderboard->reset(params[i][0]);
            result.push_back("null");
        }
    }
    Logger::WriteMessage(result);
    if (leaderboard != nullptr)
    {
        delete leaderboard;
        leaderboard = nullptr;
    }
}

void TestLeetCode981(void)
{
    Logger::WriteMessage("Test Leet Code 981");
    vector<string> commands = { "TimeMap","set","get","get","set","get","get" };
    vector<vector<string>> data =
    {
        {},{"foo","bar","1"},{"foo","1"},{"foo","3"},{"foo","bar2","4"},
        {"foo","4"}, {"foo","5"}
    };
    vector<string> result;
    TimeMap* timeMap = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TimeMap")
        {
            timeMap = new TimeMap();
            result.push_back("null");
        }
        else if (commands[i] == "set")
        {
            timeMap->set(data[i][0], data[i][1], atoi(data[i][2].c_str()));
            result.push_back("null");
        }
        else if (commands[i] == "get")
        {
            string value = timeMap->get(data[i][0], atoi(data[i][1].c_str()));
            result.push_back(value);
        }
    }
    delete timeMap;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands = { "TimeMap","set","set","get","get","get","get","get" };
    data =
    {
        {},{"love","high","10"},{"love","low","20"},{"love","5"},{"love","10"},{"love","15"},{"love","20"},{"love","25"}
    };
    result.clear();
    timeMap = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TimeMap")
        {
            timeMap = new TimeMap();
            result.push_back("null");
        }
        else if (commands[i] == "set")
        {
            timeMap->set(data[i][0], data[i][1], atoi(data[i][2].c_str()));
            result.push_back("null");
        }
        else if (commands[i] == "get")
        {
            string value = timeMap->get(data[i][0], atoi(data[i][1].c_str()));
            result.push_back(value);
        }
    }
    delete timeMap;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCodeDesign(void)
{
    TestLeetCode1244();
    TestLeetCode146();
    TestLeetCode460();
    TestLeetCode716();
    TestLeetCode895();
    TestLeetCode900();
    TestLeetCode981();
    TestLeetCode1146();
}
