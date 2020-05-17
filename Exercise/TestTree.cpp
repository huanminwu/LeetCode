#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeTree.h"
#include "..\LeetCode\LeetCodeLinkedList.h"
#include "TestTree.h"

void TestLeetCode94(void)
{
    Logger::WriteMessage("Test Leet Code 94");
    LeetCodeTree leetCode;
    string input = "[1,null,2,3]";
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage("InorderTraversal");
    vector<int> result = leetCode.inorderTraversal(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode100(void)
{
    LeetCodeTree leetCode;

    // Test Leet Code #100 
    Logger::WriteMessage("Test Leet Code 100");

    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* tree1 = leetCode.deserialize(input);
    TreeNode* tree2 = leetCode.deserialize(input);
    Logger::WriteMessage("These two trees " + (string)(leetCode.isSameTree(tree1, tree2) ? "are" : "are not") + " same.");
    leetCode.freeTreeNodes(tree1);
    leetCode.freeTreeNodes(tree2);
}

void TestLeetCode144(void)
{
    Logger::WriteMessage("Test Leet Code 144");
    LeetCodeTree leetCode;
    string input = "[1,null,2,3]";
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage("PreorderTraversal");
    vector<int> result = leetCode.preorderTraversal(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode105(void)
{
    LeetCodeTree leetCode;

    // Test Leet Code #105 
    Logger::WriteMessage("Test Leet Code 105");

    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> preorder = leetCode.preorderTraversal(root);
    vector<int> inorder = leetCode.inorderTraversal(root);
    leetCode.freeTreeNodes(root);
    root = leetCode.buildTreeFromPreorderandInorder(preorder, inorder);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("New Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode106(void)
{
    LeetCodeTree leetCode;

    // Test Leet Code #106 
    Logger::WriteMessage("Test Leet Code 106");

    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> inorder = leetCode.inorderTraversal(root);
    vector<int> postorder = leetCode.postorderTraversal(root);
    leetCode.freeTreeNodes(root);
    root = leetCode.buildTreeFromInorderAndPostorder(inorder, postorder);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("New Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode107(void)
{
    Logger::WriteMessage("Test Leet Code 107");
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.levelOrderBottom(root);
    Logger::WriteMessage("LevelorderBottomupTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode114(void)
{
    Logger::WriteMessage("Test Leet Code 114");
    LeetCodeTree leetCode;
    string input = "[1,2,5,3,4,6]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    leetCode.flatten(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("Flatten Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode145(void)
{
    Logger::WriteMessage("Test Leet Code 145");
    LeetCodeTree leetCode;
    string input = "[1,null,2,3]";
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage("PostorderTraversal");
    vector<int> result = leetCode.postorderTraversal(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode116(void)
{
    Logger::WriteMessage("Test Leet Code 116");
    LeetCodeTree leetCode;
    string input;
    TreeLinkNode* root;
    input = "[1,2,3,4,5,6,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserializeLinkTree(input);
    leetCode.connectRight(root);
    Logger::WriteMessage(leetCode.serializeLinkTree(root));
    leetCode.freeLinkTreeNodes(root);
}

void TestLeetCode117(void)
{
    Logger::WriteMessage("Test Leet Code 117");
    LeetCodeTree leetCode;
    string input;
    TreeLinkNode* root;
    input = "[1,2,3,4,5,6,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserializeLinkTree(input);
    leetCode.connectRightII(root);
    Logger::WriteMessage(leetCode.serializeLinkTree(root));
    leetCode.freeLinkTreeNodes(root);
}


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

void TestLeetCode1339(void)
{
    Logger::WriteMessage("Test Leet Code 1339");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5,6]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.maxProduct(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,null,2,3,4,null,null,5,6]";
    root = leetCode.deserialize(input);
    result = leetCode.maxProduct(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[2,3,9,10,7,8,6,5,4,11,1]";
    root = leetCode.deserialize(input);
    result = leetCode.maxProduct(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,1]";
    root = leetCode.deserialize(input);
    result = leetCode.maxProduct(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1367(void)
{
    Logger::WriteMessage("Test Leet Code 1367");
    LeetCodeTree leetCode;
    LeetCodeLinkedList leetCodeLinkedList;
    vector<int> head_arr = { 4, 2, 8 };
    ListNode* head = leetCodeLinkedList.generateListNodes(head_arr);
    string tree_str = "[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]";
    TreeNode *root = leetCode.deserialize(tree_str);
    bool result = leetCode.isSubPath(head, root);
    Logger::WriteMessage(head_arr);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + (string) (result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
    leetCodeLinkedList.freeListNodes(head);

    head_arr = { 1,4,2,6 };
    head = leetCodeLinkedList.generateListNodes(head_arr);
    tree_str = "[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]"; 
    root = leetCode.deserialize(tree_str);
    result = leetCode.isSubPath(head, root);
    Logger::WriteMessage(head_arr);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
    leetCodeLinkedList.freeListNodes(head);

    head_arr = { 1,4,2,6,8 };
    head = leetCodeLinkedList.generateListNodes(head_arr);
    tree_str = "[1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.isSubPath(head, root);
    Logger::WriteMessage(head_arr);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
    leetCodeLinkedList.freeListNodes(head);
}

void TestLeetCode1372(void)
{
    Logger::WriteMessage("Test Leet Code 1372");
    LeetCodeTree leetCode;
    string tree_str = "[1,null,2,3,4,null,null,5,6,null,7,null,null,null,8,null,9]";
    TreeNode *root = leetCode.deserialize(tree_str);
    int result = leetCode.longestZigZag(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree_str = "[1,1,1,null,1,null,null,1,1,null,1]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.longestZigZag(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree_str = "[1]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.longestZigZag(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1373(void)
{
    Logger::WriteMessage("Test Leet Code 1373");
    LeetCodeTree leetCode;
    string tree_str = "[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]";
    TreeNode *root = leetCode.deserialize(tree_str);
    int result = leetCode.maxSumBST(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree_str = "[4,3,null,1,2]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.maxSumBST(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree_str = "[-4,-2,-5]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.maxSumBST(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree_str = "[2,1,3]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.maxSumBST(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree_str = "[5,4,8,3,null,6,3]";
    root = leetCode.deserialize(tree_str);
    result = leetCode.maxSumBST(root);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1379(void)
{
    Logger::WriteMessage("Test Leet Code 1379");
    LeetCodeTree leetCode;
    LeetCode leetTree;
    string tree_str = "[7,4,3,null,null,6,19]";
    TreeNode *original = leetCode.deserialize(tree_str);
    TreeNode *cloned = leetCode.deserialize(tree_str);
    int target_value = 3;
    TreeNode *target = leetTree.findTreeNode(original, target_value);
    TreeNode *result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[7]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 7;
    target = leetTree.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[8,null,6,null,5,null,4,null,3,null,2,null,1]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 4;
    target = leetTree.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[1,2,3,4,5,6,7,8,9,10]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 5;
    target = leetTree.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[1,2,null,3]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 2;
    target = leetTree.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);
}

void TestLeetCode1382(void)
{
    Logger::WriteMessage("Test Leet Code 1382");
    LeetCodeTree leetCode;
    string tree_str = "[1,null,2,null,3,null,4,null,null]";
    TreeNode *root = leetCode.deserialize(tree_str);
    root = leetCode.balanceBST(root);
    Logger::WriteMessage(tree_str);
    string result = leetCode.serialize(root);
    Logger::WriteMessage("input = " + tree_str + "; result = " + result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1430(void)
{
    Logger::WriteMessage("Test Leet Code 1430");
    LeetCodeTree leetCode;
    string tree_str = "[0,1,0,0,1,0,null,null,1,0,0]";
    vector<int> arr = { 0, 1, 0, 1 };
    TreeNode* root = leetCode.deserialize(tree_str);
    bool result = leetCode.isValidSequence(root, arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("tree = " + tree_str + "; result = " + (string) (result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    tree_str = "[0,1,0,0,1,0,null,null,1,0,0]";
    arr = { 0,0,1 };
    root = leetCode.deserialize(tree_str);
    result = leetCode.isValidSequence(root, arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("tree = " + tree_str + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    tree_str = "[0,1,0,0,1,0,null,null,1,0,0]";
    arr = { 0,1,1 };
    root = leetCode.deserialize(tree_str);
    result = leetCode.isValidSequence(root, arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("tree = " + tree_str + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode222(void)
{
    Logger::WriteMessage("Test Leet Code 222");
    LeetCodeTree leetCode;
    string input;
    TreeNode* root;
    input = "[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    Logger::WriteMessage("Count complete tree = " + to_string(leetCode.countCompleteTreeNodes(root)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode109(void)
{
    LeetCodeTree leetCode;
    LeetCodeLinkedList leetCodeLinkedList;

    // Test Leet Code #109 
    Logger::WriteMessage("Test Leet Code 109");
    vector<int> nums = { 0 };
    ListNode* head = leetCodeLinkedList.generateListNodes(nums);
    TreeNode* root = leetCode.sortedListToBST(head);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("The tree is: " + output);
    leetCode.freeTreeNodes(root);

    nums = { 1,2,3,4,5,6,7 };
    head = leetCodeLinkedList.generateListNodes(nums);
    root = leetCode.sortedListToBST(head);
    output = leetCode.serialize(root);
    Logger::WriteMessage("The tree is: " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode108(void)
{
    LeetCodeTree leetCode;

    // Test Leet Code #108 
    Logger::WriteMessage("Test Leet Code 108");
    vector<int> nums = { 1,2,3,4,5,6,7 };
    TreeNode* root = leetCode.sortedArrayToBST(nums);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("The tree is: " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1448(void)
{
    LeetCodeTree leetCode;

    Logger::WriteMessage("Test Leet Code 1448");
    string tree = "[3,1,4,3,null,1,5]";
    TreeNode* root = leetCode.deserialize(tree);
    int result = leetCode.goodNodes(root);
    Logger::WriteMessage("tree = " + tree +"; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree = "[3,3,null,4,2]";
    root = leetCode.deserialize(tree);
    result = leetCode.goodNodes(root);
    Logger::WriteMessage("tree = " + tree + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    tree = "[1]";
    root = leetCode.deserialize(tree);
    result = leetCode.goodNodes(root);
    Logger::WriteMessage("tree = " + tree + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCodeTree(void)
{
    TestLeetCode1448();
    TestLeetCode94();
    TestLeetCode100();
    TestLeetCode107();
    TestLeetCode108();
    TestLeetCode109();
    TestLeetCode114();
    TestLeetCode145();
    TestLeetCode144();
    TestLeetCode105();
    TestLeetCode106();
    TestLeetCode116();
    TestLeetCode117();
    TestLeetCode222();
    TestLeetCode1430();
    TestLeetCode1382();
    TestLeetCode1379();
    TestLeetCode1373();
    TestLeetCode1372();
    TestLeetCode1367();
    TestLeetCode1339();
    TestLeetCode1325();
    TestLeetCode102();
    TestLeetCode1315();
    TestLeetCode1302();
    TestLeetCode1305();
    TestLeetCode1261();
    TestLeetCode1214();
}