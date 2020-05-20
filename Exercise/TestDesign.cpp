#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDesign.h"
#include "..\LeetCode\LeetCodeTree.h"
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

void TestLeetCode355(void)
{
    Logger::WriteMessage("Test Leet Code 355");
    Twitter twitter;
    vector<string> actions =
    {
        "Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"
    };
    vector<vector<int>> parameters =
    {
        {{},{1, 5},{1},{1, 2},{2, 6},{1},{1, 2},{1}}
    };
    vector<string> result;
    for (size_t i = 0; i < actions.size(); i++)
    {
        if (actions[i] == "Twitter")
        {
            twitter = Twitter();
            result.push_back("null");
        }
        else if (actions[i] == "postTweet")
        {
            twitter.postTweet(parameters[i][0], parameters[i][1]);
            result.push_back("null");
        }
        else if (actions[i] == "getNewsFeed")
        {
            vector<int> tweet_list = twitter.getNewsFeed(parameters[i][0]);
            string buffer;
            buffer.push_back('[');
            for (size_t j = 0; j < tweet_list.size(); j++)
            {
                if (j > 0) buffer.push_back(',');
                buffer.append(to_string(tweet_list[j]));
            }
            buffer.push_back(']');
            result.push_back(buffer);
        }
        else if (actions[i] == "follow")
        {
            twitter.follow(parameters[i][0], parameters[i][1]);
            result.push_back("null");
        }
        else if (actions[i] == "unfollow")
        {
            twitter.unfollow(parameters[i][0], parameters[i][1]);
            result.push_back("null");
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode380(void)
{
    Logger::WriteMessage("Test LeetCode 380");
    RandomizedSet randomizedSet;
    Logger::WriteMessage("randomizedSet.insert(0);");
    randomizedSet.insert(0);
    Logger::WriteMessage("randomizedSet.insert(1);");
    randomizedSet.insert(1);
    Logger::WriteMessage("randomizedSet.remove(0);");
    randomizedSet.remove(0);
    Logger::WriteMessage("randomizedSet.insert(2);");
    randomizedSet.insert(2);
    Logger::WriteMessage("randomizedSet.remove(1);");
    randomizedSet.remove(1);
    int random = randomizedSet.getRandom();
    Logger::WriteMessage("randomizedSet.getRandom() = " + to_string(random));
}
void TestLeetCode381(void)
{
    Logger::WriteMessage("Test Leet Code 381");
    RandomizedCollection randomizedCollection;
    bool result;
    int random;
    result = randomizedCollection.insert(1);
    Logger::WriteMessage("randomizedCollection.insert(1):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(1);
    Logger::WriteMessage("randomizedCollection.insert(1):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(2);
    Logger::WriteMessage("randomizedCollection.insert(2):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(1);
    Logger::WriteMessage("randomizedCollection.insert(1):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(2);
    Logger::WriteMessage("randomizedCollection.insert(2):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(2);
    Logger::WriteMessage("randomizedCollection.insert(2):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(1);
    Logger::WriteMessage("randomizedCollection.remove(1):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(2);
    Logger::WriteMessage("randomizedCollection.remove(2):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(2);
    Logger::WriteMessage("randomizedCollection.remove(2):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(2);
    Logger::WriteMessage("randomizedCollection.remove(2):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(1);
    Logger::WriteMessage("randomizedCollection.remove(1):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(1);
    Logger::WriteMessage("randomizedCollection.remove(1):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(0);
    Logger::WriteMessage("randomizedCollection.insert(0):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(0);
    Logger::WriteMessage("randomizedCollection.remove(0):" + string(result ? "true" : "false"));
    result = randomizedCollection.insert(-1);
    Logger::WriteMessage("randomizedCollection.insert(-1):" + string(result ? "true" : "false"));
    result = randomizedCollection.remove(0);
    Logger::WriteMessage("randomizedCollection.remove(0):" + string(result ? "true" : "false"));
    random = randomizedCollection.getRandom();
    Logger::WriteMessage("randomizedCollection.getRandom():" + to_string(random));
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

void TestLeetCode432(void)
{
    Logger::WriteMessage("Test Leet Code 432");
    AllOne allOne;
    allOne.inc("apple");
    allOne.inc("apple");
    allOne.inc("apple");
    allOne.inc("apple");
    allOne.inc("orange");
    allOne.inc("orange");
    allOne.inc("orange");
    allOne.dec("apple");
    allOne.dec("apple");
    allOne.dec("apple");
    allOne.dec("orange");
    Logger::WriteMessage("Minimum Key = " + allOne.getMinKey());
    Logger::WriteMessage("Maximum Key = " + allOne.getMaxKey());
}

void TestLeetCode1348(void)
{
    Logger::WriteMessage("Test Leet Code 1348");
    vector<string> commands = 
    { 
        "TweetCounts","recordTweet","recordTweet","recordTweet", "getTweetCountsPerFrequency",
        "getTweetCountsPerFrequency", "recordTweet","getTweetCountsPerFrequency"
    };

    vector<vector<string>> data =
    {
        {},{"tweet3","0"},{"tweet3","60"},{"tweet3","10"},{"minute","tweet3","0","59"},
        {"minute","tweet3","0","60"}, {"tweet3","120"}, {"hour","tweet3","0","210"}
    };
    vector<vector<string>> result;
    TweetCounts* tweetCounts = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TweetCounts")
        {
            tweetCounts = new TweetCounts();
            result.push_back({ "null" });
        }
        else if (data[i].size() == 2)
        {
            tweetCounts->recordTweet(data[i][0], atoi(data[i][1].c_str()));
            result.push_back({ "null" });
        }
        else if (data[i].size() == 4)
        {
            vector<int> value = 
                tweetCounts->getTweetCountsPerFrequency(
                    data[i][0], data[i][1], atoi(data[i][2].c_str()), atoi(data[i][3].c_str()));
            vector<string> val_str;
            for (size_t i = 0; i < value.size(); i++)
            {
                val_str.push_back(to_string(value[i]));
            };
            result.push_back(val_str);
        }
    }
    delete tweetCounts;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode1352(void)
{
    Logger::WriteMessage("Test Leet Code 1352");

    vector<string> commands =
    {
        "ProductOfNumbers","add","add","add","add","add","getProduct",
        "getProduct","getProduct","add","getProduct"
    };
    vector<vector<int>> data =
    {
        {},{3},{0},{2},{5},{4},{2},{3},{4},{8},{2}
    };
    ProductOfNumbers* productOfNumbers = nullptr;
    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "ProductOfNumbers")
        {
            productOfNumbers = new ProductOfNumbers();
            result.push_back("null");
        }
        else if (commands[i] == "add")
        {
            productOfNumbers->add(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "getProduct")
        {
            int ret = productOfNumbers->getProduct(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    delete productOfNumbers;
    Logger::WriteMessage(result);
}

void TestLeetCode705(void)
{
    Logger::WriteMessage("Test Leet Code 705");
    vector<string> commands =
    {
        "MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"
    };
    vector<int> data =
    {
        0, 1, 2, 1, 3, 2, 2, 2, 2
    };
    vector<string> result;
    MyHashSet * hashSet = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyHashSet")
        {
            hashSet = new MyHashSet();
            result.push_back("null");
        }
        else if (commands[i] == "add")
        {
            hashSet->add(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "remove")
        {
            hashSet->remove(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "contains")
        {
            if (hashSet->contains(data[i]))
            {
                result.push_back("true");
            }
            else
            {
                result.push_back("false");
            }
        }
    }
    delete hashSet;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode706(void)
{
    Logger::WriteMessage("Test Leet Code 706");
    vector<string> commands =
    {
        "MyHashMap", "put", "put", "get", "get", "get", "put", "get", "remove", "get"
    };
    vector<vector<int>> data =
    {
        {}, {1, 1}, {2, 2}, {1}, {2}, {3}, {2, 1}, {2}, {2}, {2}
    };
    vector<string> result;
    MyHashMap * hashMap = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyHashMap")
        {
            hashMap = new MyHashMap();
            result.push_back("null");
        }
        else if (commands[i] == "put")
        {
            hashMap->put(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "remove")
        {
            hashMap->remove(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "get")
        {
            result.push_back(to_string(hashMap->get(data[i][0])));
        }
    }
    delete hashMap;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode251(void)
{
    Logger::WriteMessage("Test Leet Code 251");
    vector<vector<int>> vec2d = { {1,2}, {3}, {4,5,6} };
    vector<int> result;
    Vector2D vector2d(vec2d);
    Logger::WriteMessage(vec2d);
    while (vector2d.hasNext())
    {
        result.push_back(vector2d.next());
    }
    Logger::WriteMessage(result);

    vec2d = { { },{ 3 } };
    result = {};
    vector2d = Vector2D(vec2d);
    Logger::WriteMessage(vec2d);
    while (vector2d.hasNext())
    {
        result.push_back(vector2d.next());
    }
    Logger::WriteMessage(result);

    vec2d = { {1},{} };
    result = {};
    vector2d = Vector2D(vec2d);
    Logger::WriteMessage(vec2d);
    while (vector2d.hasNext())
    {
        result.push_back(vector2d.next());
    }
    Logger::WriteMessage(result);
}

void TestLeetCode707(void)
{
    Logger::WriteMessage("Test Leet Code 707");
    vector<string> commands =
    {
        "MyLinkedList","addAtHead","addAtTail","addAtIndex", "addAtIndex", 
        "addAtIndex", "get","deleteAtIndex","get", "get", "get"
    };
    vector<vector<int>> data =
    {
        {},{1},{3},{1, 2},{ 3, 4 },{ 5, 5 }, {1},{1},{1},{ 2 },{ 3 }
    };
    vector<string> result;
    MyLinkedList* linkedList = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyLinkedList")
        {
            linkedList = new MyLinkedList();
            result.push_back("null");
        }
        else if (commands[i] == "addAtHead")
        {
            linkedList->addAtHead(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "addAtTail")
        {
            linkedList->addAtTail(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "addAtIndex")
        {
            linkedList->addAtIndex(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "get")
        {
            int value = linkedList->get(data[i][0]);
            result.push_back(to_string(value));
        }
        else if (commands[i] == "deleteAtIndex")
        {
            linkedList->deleteAtIndex(data[i][0]);
            result.push_back("null");
        }
    }
    delete linkedList;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode281(void)
{
    Logger::WriteMessage("Test Leet Code 281");
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 4, 5, 6, 7 };
    vector<int> result;
    ZigzagIterator zigzagIterator(v1, v2);
    Logger::WriteMessage(v1);
    Logger::WriteMessage(v2);
    while (zigzagIterator.hasNext())
    {
        result.push_back(zigzagIterator.next());
    }
    Logger::WriteMessage(result);
}

void TestLeetCode379(void)
{
    Logger::WriteMessage("Test Leet Code 379");
    PhoneDirectory directory(3);
    int phone_number = directory.get();
    Logger::WriteMessage("phone number = " + to_string(phone_number));
    phone_number = directory.get();
    Logger::WriteMessage("phone number = " + to_string(phone_number));
    bool isAvailable = directory.check(2);
    Logger::WriteMessage("check(2) = " + (string)(isAvailable ? "available" : "not available"));
    phone_number = directory.get();
    Logger::WriteMessage("phone number = " + to_string(phone_number));
    isAvailable = directory.check(2);
    Logger::WriteMessage("check(2) = " + (string)(isAvailable ? "available" : "not available"));
    directory.release(2);
    Logger::WriteMessage("release(2)");
    isAvailable = directory.check(2);
    Logger::WriteMessage("check(2) = " + (string)(isAvailable ? "available" : "not available"));
}

void TestLeetCode284(void)
{
    Logger::WriteMessage("Test Leet Code 284");
    vector<int> nums = { 1,2,3,4 };
    PeekingIterator peekingIterator(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("Peek() -> " + to_string(peekingIterator.peek()));
    Logger::WriteMessage("Next() -> " + to_string(peekingIterator.next()));
}

void TestLeetCode348(void)
{
    Logger::WriteMessage("Test Leet Code 348");
    TicTacToe toe(2);
    int result = toe.move(0, 1, 2);
    Logger::WriteMessage("toe.move(0, 1, 2) = " + to_string(result));
    result = toe.move(1, 0, 1);
    Logger::WriteMessage("toe.move(1, 0, 1) = " + to_string(result));
    result = toe.move(1, 1, 2);
    Logger::WriteMessage("toe.move(1, 1, 2) = " + to_string(result));
}

void TestLeetCode353(void)
{
    Logger::WriteMessage("Test Leet Code 353");
    vector<pair<int, int>> food = { {1,2}, {0,1} };
    SnakeGame snakeGame = SnakeGame(3, 2, food);
    int result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("D");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("L");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));

    food = { { 1, 1 },{ 0, 1 } };
    snakeGame = SnakeGame(2, 2, food);
    result = snakeGame.move("D");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("L");
    Logger::WriteMessage("result = " + to_string(result));
    food = { { 2, 0 },{ 0, 0 },{ 0, 2 },{ 0, 1 }, { 2, 2 }, { 0, 1 } };
    snakeGame = SnakeGame(3, 3, food);
    result = snakeGame.move("D");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("D");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("L");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("D");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("L");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("L");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("D");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("R");
    Logger::WriteMessage("result = " + to_string(result));
    result = snakeGame.move("U");
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode631(void)
{
    int result;
    Excel excel(3, 'C');
    excel.set(1, 'A', 2);
    result = excel.sum(3, 'C', { "A1", "A1:B2" });
    Logger::WriteMessage("excel.sum(3, 'C', { 'A1', 'A1:B2' }) = " + to_string(result));
    excel.set(2, 'B', 2);
    result = excel.get(3, 'C');
    Logger::WriteMessage("excel.get(3, 'C') = " + to_string(excel.get(3, 'C')));
}

void TestLeetCode933(void)
{
    Logger::WriteMessage("Test Leet Code 933");
    vector<string> commands = { "RecentCounter","ping","ping","ping","ping", "ping", "ping" };
    vector<vector<int>> data = { { } ,{ 1 },{ 100 },{ 3001 },{ 3002 },{ 3100 },{ 3101 } };
    vector<string> result;
    RecentCounter * recentCounter = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "RecentCounter")
        {
            recentCounter = new RecentCounter();
            result.push_back("null");
        }
        else if (commands[i] == "ping")
        {
            int value = recentCounter->ping(data[i][0]);
            result.push_back(to_string(value));
        }
    }
    delete recentCounter;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode677(void)
{
    vector<pair<string, pair<string, int>>> commands =
    {
        { "insert",{ "a", 3 } }, {"insert", {"apple", 3}}, {"sum", {"ap", 0}},
        { "insert",{ "app", 2 } },{ "sum",{ "ap", 0 } }
    };
    MapSum * map_sum = new MapSum();
    for (size_t i = 0; i < commands.size(); i++)
    {
        Logger::WriteMessage(commands[i].first + "-> (" + commands[i].second.first + "," + to_string(commands[i].second.second) + ")");
        if (commands[i].first == "insert")
        {
            map_sum->insert(commands[i].second.first, commands[i].second.second);
            Logger::WriteMessage("result = null");
        }
        else if (commands[i].first == "sum")
        {
            int sum = map_sum->sum(commands[i].second.first);
            Logger::WriteMessage("result = " + to_string(sum));
        }
    }
    delete map_sum;
}

void TestLeetCode1274(void)
{
    Logger::WriteMessage("Test LeetCode 1274");
    vector<vector<int>> ship = { {1, 1},{2, 2},{3, 3},{5, 5} };
    vector<int> topRight = { 4, 4 };
    vector<int> bottomLeft = { 0, 0 };
    Sea sea(ship);
    int result = sea.countShips(topRight, bottomLeft);
    Logger::WriteMessage(ship);
    Logger::WriteMessage(topRight);
    Logger::WriteMessage(bottomLeft);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode208(void)
{
    Logger::WriteMessage("Test Leet Code 208");

    vector<string> commands =
    {
        "Trie", "insert", "search", "search", "startsWith", "insert", "search"
    };
    vector<string> parameters =
    {
        {},{ "apple" },{ "apple" }, { "app" },{ "app" },{ "app" },{ "app" }
    };
    Trie *trie = nullptr;
    vector<string> output;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Trie")
        {
            trie = new Trie();
            output.clear();
            output.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            trie->insert(parameters[i]);
            output.push_back("null");
        }
        else if (commands[i] == "search")
        {
            bool result = trie->search(parameters[i]);
            output.push_back((string)(result ? "true" : "false"));
        }
        else if (commands[i] == "startsWith")
        {
            bool result = trie->startsWith(parameters[i]);
            output.push_back((string)(result ? "true" : "false"));
        }
    }
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(output);
    delete trie;

    trie = nullptr;
    commands =
    {
        "Trie", "insert", "insert", "insert", "insert", "insert",
        "search", "search", "search", "search", "search"
    };
    parameters =
    {
        {},{ "their" },{ "there" }, { "answer" },{ "any" },{ "bye" },
        { "their" },{ "there" }, { "answer" },{ "any" },{ "bye" }
    };
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Trie")
        {
            trie = new Trie();
            output.clear();
            output.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            trie->insert(parameters[i]);
            output.push_back("null");
        }
        else if (commands[i] == "search")
        {
            bool result = trie->search(parameters[i]);
            output.push_back((string)(result ? "true" : "false"));
        }
        else if (commands[i] == "startsWith")
        {
            bool result = trie->startsWith(parameters[i]);
            output.push_back((string)(result ? "true" : "false"));
        }
    }
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(output);
    delete trie;
}

void TestLeetCode745(void)
{
    Logger::WriteMessage("Test Leet Code 745");
    vector<string> words = { "apple" };
    vector<pair<string, string>> prefix = { {"a", "e" } };
    WordFilter wordFilter(words);
    vector<int> result;
    for (size_t i = 0; i < prefix.size(); i++)
    {
        result.push_back(wordFilter.f(prefix[i].first, prefix[i].second));
    }
    Logger::WriteMessage(result);
    words = { "cabaabaaaa", "ccbcababac", "bacaabccba", "bcbbcbacaa", "abcaccbcaa", "accabaccaa", "cabcbbbcca", "ababccabcb", "caccbbcbab", "bccbacbcba" };
    prefix =
    {
        {"bccbacbcba", "a"}, { "ab","abcaccbcaa" }, { "a","aa" }, { "cabaaba","abaaaa" }, { "cacc","accbbcbab" },
        { "ccbcab","bac" }, { "bac","cba" }, { "ac","accabaccaa" }, { "bcbb","aa" }, { "ccbca","cbcababac" }
    };
    wordFilter = WordFilter(words);
    result.clear();
    for (size_t i = 0; i < prefix.size(); i++)
    {
        result.push_back(wordFilter.f(prefix[i].first, prefix[i].second));
    }
    Logger::WriteMessage(result);

    words = { "pop" };
    prefix =
    {
        { "","pop" }
    };
    wordFilter = WordFilter(words);
    result.clear();
    for (size_t i = 0; i < prefix.size(); i++)
    {
        result.push_back(wordFilter.f(prefix[i].first, prefix[i].second));
    }
    Logger::WriteMessage(result);
}

void TestLeetCode642(void)
{
    Logger::WriteMessage("Test Leet Code 642");
    vector<string> commands =
    {
        "AutocompleteSystem", "input", "input", "input", "input"
    };
    vector<vector<string>> parameters =
    {
        {"i love you", "island", "ironman", "i love leetcode"},{ "i" },{ " " }, { "a" },{ "#" }
    };
    vector<int> times =
    {
        5, 3, 2, 2
    };
    AutocompleteSystem * autoCompleteSystem = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "AutocompleteSystem")
        {
            autoCompleteSystem = new AutocompleteSystem(parameters[i], times);
            vector<string> result = { "null" };
            Logger::WriteMessage(commands[i]);
            Logger::WriteMessage(parameters[i]);
            Logger::WriteMessage(times);
            Logger::WriteMessage(result);
        }
        else if (commands[i] == "input")
        {
            vector<string> result = autoCompleteSystem->input(parameters[i][0][0]);
            Logger::WriteMessage(commands[i]);
            Logger::WriteMessage(parameters[i]);
            Logger::WriteMessage(result);
        }
    }
    delete autoCompleteSystem;

    commands =
    {
        "AutocompleteSystem", "input", "input", "input", "input", "input", "input",
        "input", "input","input", "input", "input", "input","input", "input"
    };
    parameters =
    {
        {"abc", "abbc", "a"}, { "b" }, { "c" }, { "#" }, { "b" }, { "c" }, { "#" },
        { "a" }, { "b" }, { "c" }, {"#"},{ "a" }, { "b" }, { "c" }, {"#"}
    };
    times =
    {
        3, 3, 3
    };
    autoCompleteSystem = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "AutocompleteSystem")
        {
            autoCompleteSystem = new AutocompleteSystem(parameters[i], times);
            vector<string> result = { "null" };
            Logger::WriteMessage(commands[i]);
            Logger::WriteMessage(parameters[i]);
            Logger::WriteMessage(times);
            Logger::WriteMessage(result);
        }
        else if (commands[i] == "input")
        {
            vector<string> result = autoCompleteSystem->input(parameters[i][0][0]);
            Logger::WriteMessage(commands[i]);
            Logger::WriteMessage(parameters[i]);
            Logger::WriteMessage(result);
        }
    }
    delete autoCompleteSystem;
}

void TestLeetCode1032(void)
{
    Logger::WriteMessage("Test Leet Code 1032");
    vector<string> commands = { "StreamChecker","query","query","query","query","query","query",
                                "query","query","query","query","query","query" };
    vector<vector<string>> data =
    {
        {"cd","f","kl"},{"a"},{"b"},{"c",},{"d"},{"e"},{"f"},{"g"},{"h"},{"i"},{"j"},{"k"},{"l"}
    };
    vector<string> result;
    StreamChecker * streamChecker = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "StreamChecker")
        {
            streamChecker = new StreamChecker(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "query")
        {
            bool ret = streamChecker->query(data[i][0][0]);
            result.push_back((string)(ret ? "true" : "false"));
        }
    }
    delete streamChecker;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands =
    {
        "StreamChecker", "query", "query", "query", "query", "query", "query",
        "query", "query", "query", "query", "query", "query", "query", "query",
        "query", "query", "query", "query", "query", "query", "query", "query",
        "query", "query", "query", "query", "query", "query", "query", "query"
    };
    data =
    {
        {"ab", "ba", "aaab", "abab", "baa"}, { "a" }, { "a" }, { "a" }, { "a" }, { "a" }, { "b" },
        { "a" }, { "b" }, { "a" }, { "b" }, { "b" }, { "b" }, { "a" }, { "b" }, { "a" }, { "b" },
        { "b" }, { "b" }, { "b" }, { "a" }, { "b" }, { "a" }, { "b" }, { "a" }, { "a" }, { "a" },
        { "b" }, { "a" }, { "a" }, { "a" }
    };

    result.clear();
    streamChecker = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "StreamChecker")
        {
            streamChecker = new StreamChecker(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "query")
        {
            bool ret = streamChecker->query(data[i][0][0]);
            result.push_back((string)(ret ? "true" : "false"));
        }
    }
    delete streamChecker;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode352(void)
{
    Logger::WriteMessage("Test Leet Code 352");
    vector<int> nums = { 1, 3, 7, 2, 6 };
    SummaryRanges summaryRange;
    for (size_t i = 0; i < nums.size(); i++)
    {
        summaryRange.addNum(nums[i]);
    }
    Logger::WriteMessage(nums);
    vector<Interval> intervals = summaryRange.getIntervals();
    Logger::WriteMessage(intervals);
}

void TestLeetCode288(void)
{
    Logger::WriteMessage("Test Leet Code 288");
    vector<string> words = { "deer", "door", "cake", "card" };
    Logger::WriteMessage(words);
    ValidWordAbbr wordAbbr(words);
    vector<string> test = { "dear", "cart", "cane", "make" };
    Logger::WriteMessage(test);
    for (string str : test)
    {
        Logger::WriteMessage(str + "->" + (string)(wordAbbr.isUnique(str) ? "true" : "false"));
    }

    words = { "hello" };
    Logger::WriteMessage(words);
    ValidWordAbbr wordAbbr1(words);
    test = { "hello" };
    Logger::WriteMessage(test);
    for (string str : test)
    {
        Logger::WriteMessage(str + "->" + (string)(wordAbbr1.isUnique(str) ? "true" : "false"));
    }
}

void TestLeetCode604(void)
{
    string str = "L1e2t1C1o1d1e1";
    StringIterator *iterator = new StringIterator("L1e2t1C1o1d1e1");
    string result;
    while (iterator->hasNext())
    {
        result.push_back(iterator->next());
    }
    delete iterator;
    Logger::WriteMessage("str = " + str + "; result = " + result);
}

void TestLeetCode676(void)
{
    vector<string> dict = { "hello", "leetcode" };
    Logger::WriteMessage(dict);
    MagicDictionary * magic_dict = new MagicDictionary();
    magic_dict->buildDict(dict);
    vector<string> words = { "hello", "hhllo", "hell",  "leetcoded" };
    Logger::WriteMessage(words);
    for (string word : words)
    {
        bool result = magic_dict->search(word);
        Logger::WriteMessage((string)(result ? "true" : "false"));
    }
    delete magic_dict;
}

void TestLeetCode271(void)
{
    Logger::WriteMessage("Test Leet Code 271");
    vector<string> str_list = { "Hello", "", "World" };
    Logger::WriteMessage(str_list);
    Codec codec;
    string str = codec.encode(str_list);
    Logger::WriteMessage(str);
    vector<string> result = codec.decode(str);
    Logger::WriteMessage(result);
}

void TestLeetCode588(void)
{
    vector<string> commands =
    {
        "FileSystem", "ls", "mkdir", "addContentToFile", "ls", "readContentFromFile", "addContentToFile", "readContentFromFile"
    };
    vector<vector<string>> parameters =
    {
        {},{ "/" },{ "/a/b/c" }, { "/a/b/c/d", "hello world" },{ "/" },{ "/a/b/c/d" },{"/a/b/c/d", " hello hello world"}, {"/a/b/c/d"}
    };
    FileSystem fileSystem;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);

    vector<string> output;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "ls")
        {
            vector<string> result = fileSystem.ls(parameters[i][0]);
            string output_string;
            for (string str : result)
            {
                if (!output_string.empty()) output_string.push_back(',');
                output_string.append(str);
            }
            output.push_back("[" + output_string + "]");
        }
        else if (commands[i] == "mkdir")
        {
            fileSystem.mkdir(parameters[i][0]);
            output.push_back("null");
        }
        else if (commands[i] == "FileSystem")
        {
            output.push_back("null");
        }
        else if (commands[i] == "addContentToFile")
        {
            fileSystem.addContentToFile(parameters[i][0], parameters[i][1]);
            output.push_back("null");
        }
        else if (commands[i] == "readContentFromFile")
        {
            string output_string;
            output_string = fileSystem.readContentFromFile(parameters[i][0]);
            output.push_back(output_string);
        }
    }
    Logger::WriteMessage(output);
}

void TestLeetCode1261(void)
{
    Logger::WriteMessage("Test Leet Code 1261");
    LeetCodeTree leetCode;

    vector<string> commands =
    {
        "FindElements","find","find"
    };
    vector<string> data =
    {
        {"[-1,null,-1]"},{"1"},{"2"}
    };

    FindElements* findElements = nullptr;
    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FindElements")
        {
            TreeNode* root = leetCode.deserialize(data[i]);
            findElements = new FindElements(root);
            result.push_back("null");
        }
        else if (commands[i] == "find")
        {
            bool ret = findElements->find(atoi(data[i].c_str()));
            result.push_back(ret ? "true" : "false");
        }
    }
    delete findElements;
    Logger::WriteMessage(result);

    commands =
    {
        "FindElements","find","find","find"
    };
    data =
    {
        {"[-1,-1,-1,-1,-1]"},{"1"},{"3"},{"5"}
    };

    findElements = nullptr;
    result.clear();
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FindElements")
        {
            TreeNode* root = leetCode.deserialize(data[i]);
            findElements = new FindElements(root);
            result.push_back("null");
        }
        else if (commands[i] == "find")
        {
            bool ret = findElements->find(atoi(data[i].c_str()));
            result.push_back(ret ? "true" : "false");
        }
    }
    delete findElements;
    Logger::WriteMessage(result);

    commands =
    {
        "FindElements","find","find","find","find"
    };
    data =
    {
        {"[-1,null,-1,-1,null,-1]"},{"2"},{"3"},{"4"},{"5"}
    };

    findElements = nullptr;
    result.clear();
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FindElements")
        {
            TreeNode* root = leetCode.deserialize(data[i]);
            findElements = new FindElements(root);
            result.push_back("null");
        }
        else if (commands[i] == "find")
        {
            bool ret = findElements->find(atoi(data[i].c_str()));
            result.push_back(ret ? "true" : "false");
        }
    }
    delete findElements;
    Logger::WriteMessage(result);
}

void TestLeetCode170(void)
{
    Logger::WriteMessage("Test Leet Code 170");
    vector<string> commands =
    {
        "TwoSum", "add", "add", "add", "add", "add", "find", "find", "find", "find", "find" , "find"
    };
    vector<vector<int>> parameters =
    {
        {},{ 3 }, { 2 }, { 1 }, { 0 }, { 0 }, { 2 },{ 3 }, { 4 }, { 5 }, { 6 }, { 0 }
    };

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        TwoSum * twoSum = nullptr;
        if (commands[i] == "TwoSum")
        {
            TwoSum * twoSum = new TwoSum();
            result.push_back("null");
        }
        else if (commands[i] == "add")
        {
            twoSum->add(parameters[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "find")
        {
            bool ret = twoSum->find(parameters[i][0]);
            Logger::WriteMessage("result = " + (string)(ret ? "true" : "false"));
        }
    }
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode535(void)
{
    Logger::WriteMessage("Test Leet Code 535");
    TinyURL tinyUrl;
    string longUrl = "https://leetcode.com/problems/design-tinyurl";
    string shortUrl = tinyUrl.encode(longUrl);
    Logger::WriteMessage("long url -> short url: " + longUrl + " -> " + shortUrl);
    Logger::WriteMessage("short url -> long url: " + shortUrl + " -> " + longUrl);
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

void TestLeetCode1357(void)
{
    Logger::WriteMessage("Test Leet Code 1357");

    vector<string> commands =
    {
        "Cashier", "getBill", "getBill", "getBill", "getBill", "getBill", "getBill", "getBill"
    };
    
    
    vector<vector<vector<int>>> parameters =
    {
        {{3}, {50}, {1, 2, 3, 4, 5, 6, 7}, {100, 200, 300, 400, 300, 200, 100}},
        {{1, 2},{1, 2}}, {{3, 7},{10, 10}},
        {{1, 2, 3, 4, 5, 6, 7},{1, 1, 1, 1, 1, 1, 1}},
        {{4},{10}},{{7, 3},{10, 10}},
        {{7, 5, 3, 1, 6, 4, 2},{10, 10, 10, 9, 9, 9, 7}},
        {{2, 3, 5},{5, 3, 2}}
    };
    vector<string> result;
    Cashier * cashier = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Cashier")
        {
            cashier = new Cashier(parameters[i][0][0], parameters[i][1][0], parameters[i][2], parameters[i][3]);
            result.push_back("null");
        }
        else if (commands[i] == "getBill")
        {
            double ret = cashier->getBill(parameters[i][0], parameters[i][1]);
            result.push_back(to_string(ret));
        }
    }
    delete cashier;
    for (size_t i = 0; i < commands.size(); i++)
    {
        Logger::WriteMessage(commands[i]);
        Logger::WriteMessage(parameters[i]);
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode1381(void)
{
    Logger::WriteMessage("Test Leet Code 1381");

    vector<string> commands =
    {
        "CustomStack", "push", "push", "pop", 
        "push", "push", "push", "increment",
        "increment","pop", "pop", "pop", "pop"
    };

    vector<vector<int>> parameters =
    {
        {3}, {1}, {2}, {}, {2}, {3}, {4}, {5, 100},
        {2, 100}, {}, {}, {}, {}
    };
    vector<string> result;
    CustomStack * customStack = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "CustomStack")
        {
            customStack = new CustomStack(parameters[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "push")
        {
            customStack->push(parameters[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "pop")
        {
            int ret = customStack->pop();
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "increment")
        {
            customStack->increment(parameters[i][0], parameters[i][1]);
            result.push_back("null");
        }
    }
    delete customStack;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode1396(void)
{
    Logger::WriteMessage("Test Leet Code 1396");

    vector<string> commands =
    {
        "UndergroundSystem", "checkIn", "checkIn", "checkIn",
        "checkOut", "checkOut", "checkOut", "getAverageTime",
        "getAverageTime","checkIn", "getAverageTime", "checkOut", 
        "getAverageTime"
    };

    vector<vector<string>> parameters =
    {
        {"0", "", "0"}, {"45","Leyton", "3"},
        {"32", "Paradise", "8"}, {"27", "Leyton", "10"},
        {"45", "Waterloo", "15"},{"27", "Waterloo", "20"}, 
        {"32", "Cambridge", "22"}, {"Paradise", "Cambridge"},
        {"Leyton", "Waterloo"}, {"10", "Leyton", "24"},
        {"Leyton", "Waterloo"},{"10", "Waterloo", "38"},
        {"Leyton", "Waterloo"}
    };
    vector<string> result;
    UndergroundSystem * undergroundSystem = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "UndergroundSystem")
        {
            undergroundSystem = new UndergroundSystem();
            result.push_back("null");
        }
        else if (commands[i] == "checkIn")
        {
            undergroundSystem->checkIn(
                atoi(parameters[i][0].c_str()), 
                parameters[i][1], 
                atoi(parameters[i][2].c_str()));
            result.push_back("null");
        }
        else if (commands[i] == "checkOut")
        {
            undergroundSystem->checkOut(
                atoi(parameters[i][0].c_str()),
                parameters[i][1],
                atoi(parameters[i][2].c_str()));
            result.push_back("null");
        }
        else if (commands[i] == "getAverageTime")
        {
            double ret = undergroundSystem->getAverageTime(
                parameters[i][0],
                parameters[i][1]);
            result.push_back(to_string(ret));
        }
    }
    delete undergroundSystem;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode1428(void)
{
    Logger::WriteMessage("Test Leet Code 1428");
    vector<vector<int>> mat = { {0, 0},{1, 1} };
    class BinaryMatrix* binaryMatrix = new BinaryMatrix(mat);
    int result = binaryMatrix->leftMostColumnWithOne(*binaryMatrix);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
    delete binaryMatrix;

    mat = { {0, 0},{0, 1} };
    binaryMatrix = new BinaryMatrix(mat);
    result = binaryMatrix->leftMostColumnWithOne(*binaryMatrix);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
    delete binaryMatrix;

    mat = { {0, 0},{0, 0} };
    binaryMatrix = new BinaryMatrix(mat);
    result = binaryMatrix->leftMostColumnWithOne(*binaryMatrix);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
    delete binaryMatrix;

    mat = { {0, 0, 0, 1},{0, 0, 1, 1},{0, 1, 1, 1} };
    binaryMatrix = new BinaryMatrix(mat);
    result = binaryMatrix->leftMostColumnWithOne(*binaryMatrix);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("result = " + to_string(result));
    delete binaryMatrix;
}

void TestLeetCode1429(void)
{
    Logger::WriteMessage("Test Leet Code 1429");
    vector<string> commands =
    {
        "FirstUnique", "showFirstUnique", "add","showFirstUnique","add",
        "showFirstUnique","add","showFirstUnique"
    };
    vector<vector<int>> parameters =
    {
        {2, 3, 5}, {}, {5}, {},{2},{},{3}, {}
    };
    vector<string> result;
    FirstUnique* firstUnique = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FirstUnique")
        {
            firstUnique = new FirstUnique(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "showFirstUnique")
        {
             result.push_back(to_string(firstUnique->showFirstUnique()));
        }
        else if (commands[i] == "add")
        {
            firstUnique->add(parameters[i][0]);
            result.push_back("null");
        }
    }
    delete firstUnique;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);

    commands =
    {
       "FirstUnique", "showFirstUnique","add","add","add","add","add",
        "showFirstUnique"
    };
    parameters =
    {
        {7,7,7,7,7,7},{},{7},{3},{3},{7},{17},{}
    };
    result.clear();
    firstUnique = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FirstUnique")
        {
            firstUnique = new FirstUnique(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "showFirstUnique")
        {
            result.push_back(to_string(firstUnique->showFirstUnique()));
        }
        else if (commands[i] == "add")
        {
            firstUnique->add(parameters[i][0]);
            result.push_back("null");
        }
    }
    delete firstUnique;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);

    commands =
    {
       "FirstUnique", "showFirstUnique", "add", "showFirstUnique"
    };
    parameters =
    {
        {809},{},{809},{}
    };
    result.clear();
    firstUnique = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FirstUnique")
        {
            firstUnique = new FirstUnique(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "showFirstUnique")
        {
            result.push_back(to_string(firstUnique->showFirstUnique()));
        }
        else if (commands[i] == "add")
        {
            firstUnique->add(parameters[i][0]);
            result.push_back("null");
        }
    }
    delete firstUnique;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);

    commands =
    {
       "FirstUnique", "add", "add", "showFirstUnique"
    };
    parameters =
    {
        {1},{1},{1},{}
    };
    result.clear();
    firstUnique = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FirstUnique")
        {
            firstUnique = new FirstUnique(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "showFirstUnique")
        {
            result.push_back(to_string(firstUnique->showFirstUnique()));
        }
        else if (commands[i] == "add")
        {
            firstUnique->add(parameters[i][0]);
            result.push_back("null");
        }
    }
    delete firstUnique;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode173(void)
{
    Logger::WriteMessage("Test Leet Code 173");
    LeetCodeTree leetCode;
    string input = "[4,2,6,1,3,5,7]";
    TreeNode* root = leetCode.deserialize(input);
    BSTIterator iterator(root);
    vector<int> node_list;
    while (iterator.hasNext())
    {
        node_list.push_back(iterator.next());
    }
    Logger::WriteMessage(node_list);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode919(void)
{
    Logger::WriteMessage("Test Leet Code 919");
    LeetCodeTree leetCode;
    vector<string> commands = { "CBTInserter", "insert", "get_root" };
    vector<string> data = { "[1]", "2", "" };
    vector<string> result;
    CBTInserter* cbtInserter = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "CBTInserter")
        {
            TreeNode* root = leetCode.deserialize(data[i]);
            cbtInserter = new CBTInserter(root);
            result.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            int value = cbtInserter->insert(atoi(data[i].c_str()));
            result.push_back(to_string(value));
        }
        else if (commands[i] == "get_root")
        {
            TreeNode* root = cbtInserter->get_root();
            string value = leetCode.serialize(root);
            result.push_back(value);
        }
    }
    TreeNode* root = cbtInserter->get_root();
    leetCode.freeTreeNodes(root);
    delete cbtInserter;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands = { "CBTInserter", "insert", "insert", "get_root" };
    data = { "[1,2,3,4,5,6]", "7", "8", "" };
    result.clear();
    cbtInserter = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "CBTInserter")
        {
            TreeNode* root = leetCode.deserialize(data[i]);
            cbtInserter = new CBTInserter(root);
            result.push_back("null");
        }
        else if (commands[i] == "insert")
        {
            int value = cbtInserter->insert(atoi(data[i].c_str()));
            result.push_back(to_string(value));
        }
        else if (commands[i] == "get_root")
        {
            TreeNode* root = cbtInserter->get_root();
            string value = leetCode.serialize(root);
            result.push_back(value);
        }
    }
    root = cbtInserter->get_root();
    leetCode.freeTreeNodes(root);
    delete cbtInserter;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode703(void)
{
    Logger::WriteMessage("Test Leet Code 703");
    vector<string> commands =
    {
        "KthLargest","add","add","add", "add", "add"
    };
    vector<vector<vector<int>>> data =
    {
        { {3}, {4, 5, 8, 2 }},{ {3} },{ {5} },{ {10} },{ {9} },{{4}}
    };
    vector<string> result;
    KthLargest* kthLargest = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "KthLargest")
        {
            kthLargest = new KthLargest(data[i][0][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "add")
        {
            int value = kthLargest->add(data[i][0][0]);
            result.push_back(to_string(value));
        }
    }
    delete kthLargest;
    Logger::WriteMessage(commands);
    for (size_t i = 0; i < data.size(); i++)
    {
        Logger::WriteMessage(data[i]);
    }
    Logger::WriteMessage(result);
}

void TestLeetCode244(void)
{
    Logger::WriteMessage("Test Leet Code 244");
    vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
    WordDistance wordDistance(words);
    string word1 = "coding";
    string word2 = "practice";
    int distance = wordDistance.shortest(word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));

    word1 = "makes";
    word2 = "coding";
    distance = wordDistance.shortest(word1, word2);
    Logger::WriteMessage("word1 =" + word1 + "; word2 = " + word2 + "; distance = " + to_string(distance));
}

void TestLeetCodeDesign(void)
{
    TestLeetCode244();
    TestLeetCode703();
    TestLeetCode919();
    TestLeetCode173();
    TestLeetCode1429();
    TestLeetCode1428();
    TestLeetCode1396();
    TestLeetCode1381();
    TestLeetCode1357();
    TestLeetCode1286();
    TestLeetCode535();
    TestLeetCode170();
    TestLeetCode1261();
    TestLeetCode588();
    TestLeetCode271();
    TestLeetCode604();
    TestLeetCode676();
    TestLeetCode352();
    TestLeetCode1032();
    TestLeetCode642();
    TestLeetCode745();
    TestLeetCode208();
    TestLeetCode677();
    TestLeetCode284();
    TestLeetCode348();
    TestLeetCode251();
    TestLeetCode281();
    TestLeetCode379();
    TestLeetCode706();
    TestLeetCode705();
    TestLeetCode1352();
    TestLeetCode1348();
    TestLeetCode146();
    TestLeetCode355();
    TestLeetCode380();
    TestLeetCode381();
    TestLeetCode432();
    TestLeetCode460();
    TestLeetCode716();
    TestLeetCode895();
    TestLeetCode900();
    TestLeetCode981();
    TestLeetCode1146();
    TestLeetCode1244();
    TestLeetCode1274();
}
