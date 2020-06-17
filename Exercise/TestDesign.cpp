#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDesign.h"
#include "..\LeetCode\LeetCodeTree.h"
#include "TestDesign.h"

void TestLeetCode155(void)
{
    MinStack minStack;
    Logger::WriteMessage("minStack.push(-2)");
    minStack.push(-2);
    Logger::WriteMessage("minStack.push(0)");
    minStack.push(0);
    Logger::WriteMessage("minStack.push(-3)");
    minStack.push(-3);
    Logger::WriteMessage(("minStack.getMin()" + to_string(minStack.getMin())).c_str());
    minStack.getMin();
    Logger::WriteMessage("minStack.pop()");
    minStack.pop();
    Logger::WriteMessage(("minStack.top()" + to_string(minStack.getMin())).c_str());
    minStack.top();
    Logger::WriteMessage(("minStack.getMin()" + to_string(minStack.getMin())).c_str());
    minStack.getMin();
}

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
    TwoSum* twoSum = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TwoSum")
        {
            twoSum = new TwoSum();
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

void TestLeetCode1206(void)
{
    Logger::WriteMessage("Test Leet Code 1206");
    vector<string> commands =
    {
        "Skiplist", "add", "add", "add", "add", "add", "add", "add","add",
        "add", "add", "add", "add", "add", "add", "add","add",
        "search", "add", "search", "erase","erase","search","erase", "erase"
    };

    vector<int> data =
    {
        -1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 4, 1, 0, 1, 1, 8, 12
    };

    Skiplist* skipList = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Skiplist")
        {
            skipList = new Skiplist();
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "add")
        {
            skipList->add(data[i]);
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "search")
        {
            bool ret = skipList->search(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "erase")
        {
            bool ret = skipList->erase(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
    }
    Logger::WriteMessage(result);

    commands =
    {
        "Skiplist", "add", "add", "add", "add", "add", "add",  "add", "add", "add", "erase",
        "search", "add", "erase", "erase", "erase", "add", "search", "search", "search",
        "erase", "search", "add", "add", "add", "erase", "search", "add", "search", "erase",
        "search", "search", "erase", "erase", "add", "erase", "search", "erase", "erase",
        "search", "add", "add", "erase", "erase", "erase", "add", "erase", "add",
        "erase", "erase", "add", "add", "add", "search", "search", "add", "erase",
        "search", "add", "add", "search", "add", "search", "erase", "erase", "search",
        "search", "erase", "search", "add", "erase", "search", "erase", "search", "erase",
        "erase", "search", "search", "add", "add", "add", "add", "search", "search", "search",
        "search", "search", "search", "search", "search", "search"
    };

    data =
    {
        -1,16,5,14,13,0,3,12,9,12,3,6,7,0,1,10,5,12,7,16,7,0,9,
        16,3,2,17,2,17,0,9,14,1,6,1,16,9,10,9,2,3,16,15,12,7,4,3,2,
        1,14,13,12,3,6,17,2,3,14,11,0,13,2,1,10,17,0,5,8,9,8,11,
        10,11,10,9,8,15,14,1,6,17,16,13,4,5,4,17,16,7,14,1
    };

    result.clear();
    for (size_t i = 0; i < commands.size(); i++)
    {
        Logger::WriteMessage("command = " + commands[i] + ";data = " + to_string(data[i]));
        if (commands[i] == "Skiplist")
        {
            skipList = new Skiplist();
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "add")
        {
            skipList->add(data[i]);
            result.push_back("null");
            skipList->print();
        }
        else if (commands[i] == "search")
        {
            bool ret = skipList->search(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "erase")
        {
            bool ret = skipList->erase(data[i]);
            skipList->print();
            result.push_back((string)(ret ? "true" : "false"));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1172(void)
{
    Logger::WriteMessage("Test Leet Code 1172");
    vector<string> commands =
    {
        "DinnerPlates", "push", "push", "push", "push", "push", "popAtStack",
        "push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"
    };

    vector<vector<int>> data =
    {
        {2} ,{1},{2},{3},{4},{5},{0},{20},{21},{0},{2},{},{},{},{},{}
    };

    DinnerPlates* dinnerPlates = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "DinnerPlates")
        {
            dinnerPlates = new DinnerPlates(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "push")
        {
            dinnerPlates->push(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "pop")
        {
            int ret = dinnerPlates->pop();
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "popAtStack")
        {
            int ret = dinnerPlates->popAtStack(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode855(void)
{
    Logger::WriteMessage("Test Leet Code 855");
    vector<string> commands = { "ExamRoom","seat","seat","seat","seat","leave","seat" };
    vector<int> parameters = { 10, -1, -1, -1, -1, 4, -1 };
    vector<int> result(commands.size());
    ExamRoom* exam_room = nullptr;

    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "ExamRoom")
        {
            exam_room = new ExamRoom(parameters[0]);
            result[i] = -1;
        }
        else if (commands[i] == "seat")
        {
            result[i] = exam_room->seat();
        }
        else
        {
            exam_room->leave(parameters[i]);
            result[i] = -1;
        }
    }
    if (exam_room != nullptr) delete exam_room;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode710(void)
{
    Logger::WriteMessage("Test Leet Code 710");
    Solution* solution;
    vector<string> command = { "Solution","pick","pick","pick" };
    int N = 1;
    vector<int> blacklist = {};
    vector<int> result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution","pick","pick","pick" };
    N = 2;
    blacklist = {};
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution","pick","pick","pick" };
    N = 3;
    blacklist = { 1 };
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution","pick","pick","pick","pick","pick","pick" };
    N = 4;
    blacklist = { 2 };
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);

    command = { "Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick", "pick" };
    N = 4;
    blacklist = { 2, 1 };
    result = {};
    solution = new Solution(N, blacklist);
    result.push_back(-1);
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "pick")
        {
            result.push_back(solution->pick());
        }
    }
    delete solution;
    Logger::WriteMessage(command);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(blacklist);
    Logger::WriteMessage(result);
}

void TestLeetCode528(void)
{
    Logger::WriteMessage("Test Leet Code 528");
    vector<string> commands =
    {
        "Solution","pickIndex","pickIndex","pickIndex","pickIndex", "pickIndex","pickIndex","pickIndex","pickIndex","pickIndex", "pickIndex"
    };
    vector<vector<int>> data =
    {
        {3, 14, 1, 7},{},{},{},{},{}
    };
    vector<string> result;
    RandomWithWeight* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            vector<int> parameter;
            for (size_t j = 0; j < data[i].size(); j++)
            {
                parameter.push_back(data[i][j]);
            }
            solution = new RandomWithWeight(parameter);
            result.push_back("null");
        }
        else if (commands[i] == "pickIndex")
        {
            solution->pickIndex();
            result.push_back(to_string(solution->pickIndex()));
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode519(void)
{
    Logger::WriteMessage("Test Leet Code 519");
    vector<string> commands =
    {
        "Solution","flip","flip","flip","flip"
    };
    vector<vector<int>> data =
    {
        { 2,3 },{},{},{},{}
    };
    vector<string> result;
    RandomFlipMatrix* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomFlipMatrix(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "flip")
        {
            vector<int> position = solution->flip();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
        else if (commands[i] == "reset")
        {
            solution->reset();
            result.push_back("null");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands =
    {
        "Solution","flip","flip","reset","flip"
    };
    data =
    {
        { 1,2 },{},{},{},{}
    };
    result.clear();
    solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomFlipMatrix(data[i][0], data[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "flip")
        {
            vector<int> position = solution->flip();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
        else if (commands[i] == "reset")
        {
            solution->reset();
            result.push_back("null");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode478(void)
{
    Logger::WriteMessage("Test Leet Code 478");
    vector<string> commands =
    {
        "Solution","randPoint","randPoint","randPoint"
    };
    vector<vector<double>> data =
    {
        { 1, 0, 0 },{},{},{}
    };
    vector<string> result;
    RandomCirclePoint* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomCirclePoint(data[i][0], data[i][1], data[i][2]);
            result.push_back("null");
        }
        else if (commands[i] == "randPoint")
        {
            vector<double> position = solution->randPoint();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);

    commands =
    {
        "Solution","randPoint","randPoint","randPoint"
    };
    data =
    {
        { 10, 5, -7.5 },{},{},{}
    };
    result.clear();
    solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomCirclePoint(data[i][0], data[i][1], data[i][2]);
            result.push_back("null");
        }
        else if (commands[i] == "randPoint")
        {
            vector<double> position = solution->randPoint();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}


void TestLeetCode497(void)
{
    Logger::WriteMessage("Test Leet Code 497");
    vector<string> commands =
    {
        "Solution","pick","pick","pick", "pick","pick","pick","pick","pick","pick", "pick","pick","pick"
    };
    vector<vector<vector<int>>> data =
    {
        {{ 1, 1, 5, 5 }}, {}, {}, {},{}, {}, {},{},{},{},{},{},{}
    };
    vector<string> result;
    RandomRectanglePoint* solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomRectanglePoint(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "pick")
        {
            vector<int> position = solution->pick();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data[0]);
    Logger::WriteMessage(result);

    commands =
    {
        "Solution","pick","pick","pick","pick","pick"
    };
    data =
    {
        {{-2,-2,-1,-1},{1,0,3,0}}, {}, {}, {}, {}, {}
    };
    result.clear();
    solution = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "Solution")
        {
            solution = new RandomRectanglePoint(data[i]);
            result.push_back("null");
        }
        else if (commands[i] == "pick")
        {
            vector<int> position = solution->pick();
            result.push_back("[" + to_string(position[0]) + "," + to_string(position[1]) + "]");
        }
    }
    delete solution;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data[0]);
    Logger::WriteMessage(result);
}

void TestLeetCode622(void)
{
    Logger::WriteMessage("Test Leet Code 622");
    vector<string> commands =
    {
        "MyCircularQueue","enQueue","enQueue","enQueue", "enQueue", "Rear", "isFull","deQueue","enQueue", "Rear","deQueue","deQueue","deQueue","deQueue","isEmpty"
    };
    vector<vector<int>> data =
    {
        {3},{ 1 },{ 2 },{ 3 },{ 4 },{ },{ },{ },{ 4 },{}, {}, {}, {}, {}, {}
    };
    vector<string> result;
    MyCircularQueue* queue = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyCircularQueue")
        {
            queue = new MyCircularQueue(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "enQueue")
        {
            bool success = queue->enQueue(data[i][0]);
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "Rear")
        {
            int value = queue->Rear();
            result.push_back(to_string(value));
        }
        else if (commands[i] == "deQueue")
        {
            bool success = queue->deQueue();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isFull")
        {
            bool success = queue->isFull();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isEmpty")
        {
            bool success = queue->isEmpty();
            result.push_back(success ? "true" : "false");
        }
    }
    delete queue;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode641(void)
{
    Logger::WriteMessage("Test Leet Code 641");
    vector<string> commands =
    {
        "MyCircularDeque","insertLast","insertLast","insertFront", "insertFront", "getRear", "isFull","deleteLast","insertFront", "getFront","deleteFront","deleteFront","deleteFront","deleteFront","isEmpty"
    };
    vector<vector<int>> data =
    {
        { 3 },{ 1 },{ 2 },{ 3 },{ 4 },{},{},{},{ 4 },{},{},{},{},{},{}
    };
    vector<string> result;
    MyCircularDeque* deque = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "MyCircularDeque")
        {
            deque = new MyCircularDeque(data[i][0]);
            result.push_back("null");
        }
        else if (commands[i] == "insertFront")
        {
            bool success = deque->insertFront(data[i][0]);
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "insertLast")
        {
            bool success = deque->insertLast(data[i][0]);
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "getFront")
        {
            int value = deque->getFront();
            result.push_back(to_string(value));
        }
        else if (commands[i] == "getRear")
        {
            int value = deque->getRear();
            result.push_back(to_string(value));
        }
        else if (commands[i] == "deleteFront")
        {
            bool success = deque->deleteFront();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "deleteLast")
        {
            bool success = deque->deleteLast();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isFull")
        {
            bool success = deque->isFull();
            result.push_back(success ? "true" : "false");
        }
        else if (commands[i] == "isEmpty")
        {
            bool success = deque->isEmpty();
            result.push_back(success ? "true" : "false");
        }
    }
    delete deque;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode901(void)
{
    Logger::WriteMessage("Test Leet Code 901");
    vector<string> commands =
    {
        "StockSpanner","next","next","next","next","next","next","next"
    };
    vector<vector<int>> data =
    {
        { },{ 100 },{ 80 },{ 60 },{ 70 },{ 60 },{ 75 },{ 85 }
    };
    vector<string> result;
    StockSpanner* stockSpanner = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "StockSpanner")
        {
            stockSpanner = new StockSpanner();
            result.push_back("null");
        }
        else if (commands[i] == "next")
        {
            int value = stockSpanner->next(data[i][0]);
            result.push_back(to_string(value));
        }
    }
    delete stockSpanner;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode911(void)
{
    Logger::WriteMessage("Test Leet Code 911");
    vector<string> commands = { "TopVotedCandidate","q","q","q","q","q","q" };
    vector<vector<int>> data = { {0,1,1,0,0,1,0, 0, 5,10,15,20,25,30} , { 3 }, { 12 }, { 25 }, { 15 }, { 24 }, { 8 } };
    vector<string> result;
    TopVotedCandidate* topVotedCandidate = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TopVotedCandidate")
        {
            vector<int> persons;
            vector<int> times;
            for (size_t j = 0; j < data[i].size() / 2; j++)
            {
                persons.push_back(data[i][j]);
                times.push_back(data[i][j + data[i].size() / 2]);
            }

            topVotedCandidate = new TopVotedCandidate(persons, times);
            result.push_back("null");
        }
        else if (commands[i] == "q")
        {
            int value = topVotedCandidate->q(data[i][0]);
            result.push_back(to_string(value));
        }
    }
    delete topVotedCandidate;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(data);
    Logger::WriteMessage(result);
}

void TestLeetCode1157(void)
{
    Logger::WriteMessage("Test Leet Code 1157");
    vector<string> command = { "MajorityChecker","query","query","query" };
    vector<vector<int>> params = { {1,1,2,2,1,1}, {0,5,4}, {0,3,3}, {2,3,2} };
    vector<string> result;
    class MajorityChecker* majorityChecker = nullptr;
    for (size_t i = 0; i < command.size(); i++)
    {
        if (command[i] == "MajorityChecker")
        {
            majorityChecker = new MajorityChecker(params[i]);
            result.push_back("null");
        }
        else if (command[i] == "query")
        {
            int value = majorityChecker->query(params[i][0], params[i][1], params[i][2]);
            result.push_back(to_string(value));
        }
    }
    Logger::WriteMessage(result);
    if (majorityChecker != nullptr)
    {
        delete majorityChecker;
        majorityChecker = nullptr;
    }
}

void TestLeetCode1166(void)
{
    Logger::WriteMessage("Test Leet Code 1166");
    vector<string> commands =
    {
        "FileSystem","create","get"
    };
    vector<vector<string>> data =
    {
        {}, {"/a", "1"}, {"/a"}
    };

    FileSystemII* fileSystemII = nullptr;

    vector<string> result;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FileSystem")
        {
            fileSystemII = new FileSystemII();
            result.push_back("null");
        }
        else if (commands[i] == "create")
        {
            bool ret = fileSystemII->create(data[i][0], atoi(data[i][1].c_str()));
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "get")
        {
            int ret = fileSystemII->get(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    Logger::WriteMessage(result);

    commands =
    {
       "FileSystem","create","create","get","create","get"
    };
    data =
    {
        {} ,{"/leet","1"},{"/leet/code","2"},{"/leet/code"},{"/c/d","1"},{"/c"}
    };

    fileSystemII = nullptr;

    result.clear();
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "FileSystem")
        {
            fileSystemII = new FileSystemII();
            result.push_back("null");
        }
        else if (commands[i] == "create")
        {
            bool ret = fileSystemII->create(data[i][0], atoi(data[i][1].c_str()));
            result.push_back((string)(ret ? "true" : "false"));
        }
        else if (commands[i] == "get")
        {
            int ret = fileSystemII->get(data[i][0]);
            result.push_back(to_string(ret));
        }
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1472(void)
{
    Logger::WriteMessage("Test Leet Code 1472");
    vector<string> commands =
    {
        "BrowserHistory", "visit", "visit", "visit", "back", "back", 
        "forward", "visit", "forward", "back", "back"
    };
    vector<string> parameters =
    {
        {"leetcode.com"}, {"google.com"}, {"facebook.com"}, {"youtube.com"},
        {"1"}, {"1"}, {"1"}, {"linkedin.com"}, {"2"}, {"2"}, {"7"}
    };
    vector<string> result;
    BrowserHistory* browserHistory = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "BrowserHistory")
        {
            browserHistory = new BrowserHistory(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "visit")
        {
            browserHistory->visit(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "back")
        {
            string url = browserHistory->back(atoi(parameters[i].c_str()));
            result.push_back(url);
        }
        else if (commands[i] == "forward")
        {
            string url = browserHistory->forward(atoi(parameters[i].c_str()));
            result.push_back(url);
        }
    }
    delete browserHistory;
    Logger::WriteMessage(commands);
    Logger::WriteMessage(parameters);
    Logger::WriteMessage(result);
}

void TestLeetCode843(void)
{
    Logger::WriteMessage("Test Leet Code 843");
    Master master("acckzz");
    vector<string> wordlist = { "acckzz", "ccbazz", "eiowzz", "abcczz" };
    string result = master.findSecretWord(wordlist, master);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode1476(void)
{
    Logger::WriteMessage("Test Leet Code 1476");
    vector<string> commands =
    {
       "SubrectangleQueries", "getValue", "updateSubrectangle", "getValue",
       "getValue", "updateSubrectangle", "getValue", "getValue"
    };
    vector<vector<vector<int>>> parameters =
    {
        {{1, 2, 1},{4, 3, 4},{3, 2, 1},{1, 1, 1}},
        {{0, 2}},
        {{0, 0, 3, 2, 5}},
        {{0, 2}},
        {{3, 1}},
        {{3, 0, 3, 2, 10}},
        {{3, 1}},
        {{0, 2}}
    };

    vector<string> result;
    SubrectangleQueries* subrectangleQueries = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "SubrectangleQueries")
        {
            subrectangleQueries = new SubrectangleQueries(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "getValue")
        {
            int ret = subrectangleQueries->getValue(parameters[i][0][0], parameters[i][0][1]);
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "updateSubrectangle")
        {
            subrectangleQueries->updateSubrectangle(parameters[i][0][0], parameters[i][0][1], parameters[i][0][2], parameters[i][0][3], parameters[i][0][4]);
            result.push_back("null");
        }
    }
    delete subrectangleQueries;
    Logger::WriteMessage(commands);
    for (size_t i = 0; i < parameters.size(); i++)
    {
        Logger::WriteMessage(parameters[i]);
    }
    Logger::WriteMessage(result);

    commands =
    {
       "SubrectangleQueries", "getValue", "updateSubrectangle", "getValue", 
       "getValue", "updateSubrectangle", "getValue"
    };

    parameters =
    {
        {{1, 1, 1},{2, 2, 2},{3, 3, 3}},
        {{0, 0}},
        {{0, 0, 2, 2, 100}},
        {{0, 0}},
        {{2, 2}},
        {{1, 1, 2, 2, 20}},
        {{2, 2}},
    };

    result.clear();
    subrectangleQueries = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "SubrectangleQueries")
        {
            subrectangleQueries = new SubrectangleQueries(parameters[i]);
            result.push_back("null");
        }
        else if (commands[i] == "getValue")
        {
            int ret = subrectangleQueries->getValue(parameters[i][0][0], parameters[i][0][1]);
            result.push_back(to_string(ret));
        }
        else if (commands[i] == "updateSubrectangle")
        {
            subrectangleQueries->updateSubrectangle(parameters[i][0][0], parameters[i][0][1], parameters[i][0][2], parameters[i][0][3], parameters[i][0][4]);
            result.push_back("null");
        }
    }
    delete subrectangleQueries;
    Logger::WriteMessage(commands);
    for (size_t i = 0; i < parameters.size(); i++)
    {
        Logger::WriteMessage(parameters[i]);
    }
    Logger::WriteMessage(result);
}

void TestLeetCode1483(void)
{
    Logger::WriteMessage("Test Leet Code 1483");
    vector<string> commands =
    {
       "TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"
    };
    vector<vector<vector<int>>> parameters =
    {
        {{7},{-1,0,0,1,1,2,2}},
        {{3,1}},
        {{5,2}},
        {{6,3}}
    };

    vector<string> result;
    TreeAncestor* treeAncestor = nullptr;
    for (size_t i = 0; i < commands.size(); i++)
    {
        if (commands[i] == "TreeAncestor")
        {
            treeAncestor = new TreeAncestor(parameters[i][0][0], parameters[i][1]);
            result.push_back("null");
        }
        else if (commands[i] == "getKthAncestor")
        {
            int ret = treeAncestor->getKthAncestor(parameters[i][0][0], parameters[i][0][1]);
            result.push_back(to_string(ret));
        }
    }
    delete treeAncestor;
    Logger::WriteMessage(commands);
    for (size_t i = 0; i < parameters.size(); i++)
    {
        Logger::WriteMessage(parameters[i]);
    }
    Logger::WriteMessage(result);
}

void TestLeetCodeDesign(void)
{
    TestLeetCode1483();
    TestLeetCode1476();
    TestLeetCode843();
    TestLeetCode1472();
    TestLeetCode1166();
    TestLeetCode1157();
    TestLeetCode911();
    TestLeetCode901();
    TestLeetCode641();
    TestLeetCode622();
    TestLeetCode497();
    TestLeetCode478();
    TestLeetCode519();
    TestLeetCode528();
    TestLeetCode710();
    TestLeetCode855();
    TestLeetCode1172();
    TestLeetCode155();
    TestLeetCode1206();
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
