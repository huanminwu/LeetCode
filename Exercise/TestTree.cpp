#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeTree.h"
#include "TestTree.h"

void TestLeetCode1214(void)
{
    Logger::WriteMessage("Test Leet Code 1214");
    LeetCodeTree leetCode;
    string input1 = "[2,1,4]";
    TreeNode* root1 = leetCode.deserialize(input1);
    string input2 = "[1,0,3]";
    TreeNode* root2 = leetCode.deserialize(input2);
    int target = 5;
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    bool result = leetCode.twoSumBSTs(root1, root2, target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[0,-10,10]";
    root1 = leetCode.deserialize(input1);
    input2 = "[5,1,7,0,2]";
    root2 = leetCode.deserialize(input2);
    target = 18;
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    result = leetCode.twoSumBSTs(root1, root2, target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);
}

void TestLeetCode1261(void)
{
    Logger::WriteMessage("Test Leet Code 1261");
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
            LeetCode leetCode;
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
            LeetCode leetCode;
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
            LeetCode leetCode;
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

void TestLeetCode1305(void)
{
    Logger::WriteMessage("Test Leet Code 1305");
    LeetCodeTree leetCode;
    string input1 = "[2,1,4]";
    TreeNode* root1 = leetCode.deserialize(input1);
    string input2 = "[1,0,3]";
    TreeNode* root2 = leetCode.deserialize(input2);
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    vector<int> result = leetCode.getAllElements(root1, root2);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[0,-10,10]";
    root1 = leetCode.deserialize(input1);
    input2 = "[5,1,7,0,2]";
    root2 = leetCode.deserialize(input2);
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    result = leetCode.getAllElements(root1, root2);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[]";
    root1 = leetCode.deserialize(input1);
    input2 = "[5,1,7,0,2]";
    root2 = leetCode.deserialize(input2);
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    result = leetCode.getAllElements(root1, root2);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[0,-10,10]";
    root1 = leetCode.deserialize(input1);
    input2 = "[]";
    root2 = leetCode.deserialize(input2);
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    result = leetCode.getAllElements(root1, root2);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[1,null,8]";
    root1 = leetCode.deserialize(input1);
    input2 = "[8,1]";
    root2 = leetCode.deserialize(input2);
    Logger::WriteMessage(input1);
    Logger::WriteMessage(input2);
    result = leetCode.getAllElements(root1, root2);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);
}

void TestLeetCode1302(void)
{
    Logger::WriteMessage("Test Leet Code 1302");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5,null,6,7,null,null,null,null,8]";
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage(input);
    int result = leetCode.deepestLeavesSum(root);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1315(void)
{
    Logger::WriteMessage("Test Leet Code 1315");
    LeetCodeTree leetCode;
    string input = "[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]";
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage(input);
    int result = leetCode.sumEvenGrandparent(root);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode102(void)
{
    Logger::WriteMessage("Test Leet Code 102");
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.levelOrder(root);
    Logger::WriteMessage("LevelorderTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    
    input = "[1,2,3,4,null,null,5]";
    root = leetCode.deserialize(input);
    result = leetCode.levelOrder(root);
    Logger::WriteMessage("LevelorderTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    
    input = "[2,null,3,null,4,null,5,null,6]";
    root = leetCode.deserialize(input);
    result = leetCode.levelOrder(root);
    Logger::WriteMessage("LevelorderTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[0,2,4,1,null,3,-1,5,1,null,6,null,8]";
    root = leetCode.deserialize(input);
    result = leetCode.levelOrder(root);
    Logger::WriteMessage("LevelorderTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}


void TestLeetCode1325(void)
{
    Logger::WriteMessage("Test Leet Code 1325");
    LeetCodeTree leetCode;
    string input = "[1,2,3,2,null,2,4]";
    int target = 2;
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.removeLeafNodes(root, target);
    string output = leetCode.serialize(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[1,3,3,3,2]";
    target = 3;
    root = leetCode.deserialize(input);
    root = leetCode.removeLeafNodes(root, target);
    output = leetCode.serialize(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[1,2,null,2,null,2]";
    target = 2;
    root = leetCode.deserialize(input);
    root = leetCode.removeLeafNodes(root, target);
    output = leetCode.serialize(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[1,1,1]";
    target = 1;
    root = leetCode.deserialize(input);
    root = leetCode.removeLeafNodes(root, target);
    output = leetCode.serialize(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3]";
    target = 1;
    root = leetCode.deserialize(input);
    root = leetCode.removeLeafNodes(root, target);
    output = leetCode.serialize(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("target = " + to_string(target));
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCodeTree(void)
{
    TestLeetCode1325();
    TestLeetCode102();
    TestLeetCode1315();
    TestLeetCode1302();
    TestLeetCode1305();
    TestLeetCode1261();
    TestLeetCode1214();
}