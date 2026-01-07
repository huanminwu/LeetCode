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
    string tree_str = "[7,4,3,null,null,6,19]";
    TreeNode *original = leetCode.deserialize(tree_str);
    TreeNode *cloned = leetCode.deserialize(tree_str);
    int target_value = 3;
    TreeNode *target = leetCode.findTreeNode(original, target_value);
    TreeNode *result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[7]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 7;
    target = leetCode.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[8,null,6,null,5,null,4,null,3,null,2,null,1]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 4;
    target = leetCode.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[1,2,3,4,5,6,7,8,9,10]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 5;
    target = leetCode.findTreeNode(original, target_value);
    result = leetCode.getTargetCopy(original, cloned, target);
    Logger::WriteMessage(tree_str);
    Logger::WriteMessage("target = " + to_string(target->val) + "; result = " + to_string(result->val));
    leetCode.freeTreeNodes(original);
    leetCode.freeTreeNodes(cloned);

    tree_str = "[1,2,null,3]";
    original = leetCode.deserialize(tree_str);
    cloned = leetCode.deserialize(tree_str);
    target_value = 2;
    target = leetCode.findTreeNode(original, target_value);
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

void TestLeetCode257(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<string> tree_paths = leetCode.binaryTreePaths(root);
    Logger::WriteMessage("Tree Path:");
    Logger::WriteMessage(tree_paths);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode104(void)
{
    Logger::WriteMessage("Test Leet Code 104");
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    int max_level = leetCode.maxDepth(root);
    Logger::WriteMessage("Maximum depth = " + to_string(max_level));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode112(void)
{
    Logger::WriteMessage("Test Leet Code 112");
    LeetCodeTree leetCode;
    string input = "[5,4,8,11,null,13,4,7,2,null, null, null, 1]";

    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = 22;
    Logger::WriteMessage("The tree " + (string)(leetCode.hasPathSum(root, sum) ? "has" : "does not have") + " the sum of " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode226(void)
{
    Logger::WriteMessage("Test Leet Code 226");
    LeetCodeTree leetCode;
    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.invertTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("Invert Tree:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode199(void)
{
    Logger::WriteMessage("Test Leet Code 199");
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,5,null,4]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.rightSideView(root);
    Logger::WriteMessage("Right Side View:");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode110(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,2,3,null,null,3,4,null,null,4]";
    Logger::WriteMessage("Original Path:" + input);

    TreeNode* root = leetCode.deserialize(input);
    bool isBalanced = leetCode.isBalanced(root);
    Logger::WriteMessage("It " + (string)(isBalanced ? "is" : "is not") + " balanced binary tree.");
    leetCode.freeTreeNodes(root);
}

void TestLeetCode101(void)
{
    LeetCodeTree leetCode;

    // Test Leet Code #101 
    Logger::WriteMessage("Test Leet Code 101");
    string input = "[1, 2, 3, 3, null, 2, null]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    bool isSymmetric = leetCode.isSymmetric(root);
    Logger::WriteMessage("The tree " + string(isSymmetric ? "is " : "is not ") + "symmetric.");
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 2, 3, 4, 4, 3]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    isSymmetric = leetCode.isSymmetric(root);
    Logger::WriteMessage("The tree " + string(isSymmetric ? "is " : "is not ") + "symmetric.");
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 2, null, 3, null, 3]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    isSymmetric = leetCode.isSymmetric(root);
    Logger::WriteMessage("The tree " + string(isSymmetric ? "is " : "is not ") + "symmetric.");
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("===========================================================");
}

void TestLeetCode331(void)
{
    Logger::WriteMessage("Test Leet Code 331");
    LeetCodeTree leetCode;
    string input = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidPreorderSerialization(input) ? "is" : "is not") + " valid preorder serialization.");

    input = "1,#";
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidPreorderSerialization(input) ? "is" : "is not") + " valid preorder serialization.");

    input = "9,#,#,1";
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidPreorderSerialization(input) ? "is" : "is not") + " valid preorder serialization.");
}

void TestLeetCode98(void)
{
    Logger::WriteMessage("Test Leet Code 98");
    LeetCodeTree leetCode;
    string input = "[]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage("It " + (string)(leetCode.isValidBST(root) ? "is" : "is not") + " valid BST.");
    leetCode.freeTreeNodes(root);
}

void TestLeetCode236(void)
{
    // Test Leet Code #236
    LeetCodeTree leetCode;
    TreeNode* p;
    TreeNode* q;
    TreeNode* ancestor;
    string input = "[6,2,8,0,4,7,9,null,null,3,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    p = leetCode.findTreeNode(root, 2);
    q = leetCode.findTreeNode(root, 8);
    ancestor = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("The lowest common ancester for " +
        ((p == nullptr) ? "null" : to_string(p->val)) + " and " +
        ((q == nullptr) ? "null" : to_string(q->val)) + " is " +
        ((ancestor == nullptr) ? "null" : to_string(ancestor->val)));

    p = leetCode.findTreeNode(root, 2);
    q = leetCode.findTreeNode(root, 4);
    ancestor = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("The lowest common ancester for " +
        ((p == nullptr) ? "null" : to_string(p->val)) + " and " +
        ((q == nullptr) ? "null" : to_string(q->val)) + " is " +
        ((ancestor == nullptr) ? "null" : to_string(ancestor->val)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode111(void)
{
    Logger::WriteMessage("Test Leet Code 111");
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    int min_level = leetCode.minDepth(root);
    Logger::WriteMessage("Minimum depth = " + to_string(min_level));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode129(void)
{
    Logger::WriteMessage("Test Leet Code 129");
    LeetCodeTree leetCode;
    string input = "[1,2,3]";

    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = leetCode.sumNumbers(root);
    Logger::WriteMessage("Sum number = " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode113(void)
{
    Logger::WriteMessage("Test Leet Code 113");
    LeetCodeTree leetCode;
    string input = "[5,4,8,11,null,13,4,7,2,null, null, 5, 1]";

    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = 22;
    vector<vector<int>> paths = leetCode.pathSum(root, sum);
    Logger::WriteMessage("Paths with sum = " + to_string(sum));
    Logger::WriteMessage(paths);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode655(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,null]";
    Logger::WriteMessage("input = " + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<string>> result = leetCode.printTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,null,4]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    result = leetCode.printTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,5,3,null,null,null,4]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    result = leetCode.printTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode99(void)
{
    LeetCodeTree leetCode;

    Logger::WriteMessage("Test Leet Code 99");
    // Test Leet Code #99
    string input = "[2, null, 1]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    leetCode.recoverTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("After recovered:" + output);
    leetCode.freeTreeNodes(root);

    input = "[0,1]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    leetCode.recoverTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("After recovered:" + output);
    leetCode.freeTreeNodes(root);

    input = "[4,2,3,1,6,5,7]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    leetCode.recoverTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("After recovered:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode103(void)
{
    Logger::WriteMessage("Test Leet Code 103");
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.zigzagLevelOrder(root);
    Logger::WriteMessage("ZigzagLevelOrderTraversal");
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1038(void)
{
    Logger::WriteMessage("Test Leet Code 1038");
    LeetCodeTree leetCode;
    string input = "[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]";
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.bstToGst(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("input = " + input + "; output = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1145(void)
{
    Logger::WriteMessage("Test Leet Code 1145");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5,6,7,8,9,10,11]";
    TreeNode* root = leetCode.deserialize(input);
    int n = 11;
    int x = 3;
    bool result = leetCode.btreeGameWinningMove(root, n, x);
    Logger::WriteMessage("input =" + input + "; n = " + to_string(n) + "; x = " + to_string(x) + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1110(void)
{
    Logger::WriteMessage("Test Leet Code 1110");
    LeetCodeTree leetCode;
    string input = "[1, 2, 3, 4, 5, 6, 7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<int> to_delete = { 3, 5 };
    vector<TreeNode*> result = leetCode.delNodes(root, to_delete);
    vector<string> output;
    for (size_t i = 0; i < result.size(); i++)
    {
        output.push_back(leetCode.serialize(result[i]));
    }
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(to_delete);
    Logger::WriteMessage(output);

    input = "[1, 2, 3, null, null, null, 4]";
    root = leetCode.deserialize(input);
    to_delete = { 2, 1 };
    result = leetCode.delNodes(root, to_delete);
    output.clear();
    for (size_t i = 0; i < result.size(); i++)
    {
        output.push_back(leetCode.serialize(result[i]));
    }
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(to_delete);
    Logger::WriteMessage(output);
}

void TestLeetCode1123(void)
{
    Logger::WriteMessage("Test Leet Code 1123");
    LeetCodeTree leetCode;
    string input = "[0, 6, 5, 3, 2, null, null, null, 4, null, null, null, 1]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* result = leetCode.lcaDeepestLeaves(root);
    string output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);

    input = "[1, 2, 3]";
    root = leetCode.deserialize(input);
    result = leetCode.lcaDeepestLeaves(root);
    output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);

    input = "[1,2,3,4]";
    root = leetCode.deserialize(input);
    result = leetCode.lcaDeepestLeaves(root);
    output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);

    input = "[1,2,3,4,5]";
    root = leetCode.deserialize(input);
    result = leetCode.lcaDeepestLeaves(root);
    output = leetCode.serialize(result);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + output);
}

void TestLeetCode1120(void)
{
    Logger::WriteMessage("Test Leet Code 1120");
    LeetCodeTree leetCode;
    string input = "[0, 6, 5, 3, 2, null, null, null, 4, null, null, null, 1]";
    TreeNode* root = leetCode.deserialize(input);
    double result = leetCode.maximumAverageSubtree(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("tree = " + input + "; result = " + to_string(result));
}

void TestLeetCode1161(void)
{
    Logger::WriteMessage("Test Leet Code 1161");
    LeetCodeTree leetCode;
    string input = "[1,7,0,7,-8,null,null]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.maxLevelSum(root);
    Logger::WriteMessage("input = " + input + "result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1104(void)
{
    Logger::WriteMessage("Test Leet Code 1104");
    LeetCodeTree leetCode;
    int label = 14;
    vector<int> result = leetCode.pathInZigZagTree(label);
    Logger::WriteMessage("label = " + to_string(label));
    Logger::WriteMessage(result);

    label = 26;
    result = leetCode.pathInZigZagTree(label);
    Logger::WriteMessage("label = " + to_string(label));
    Logger::WriteMessage(result);
}

void TestLeetCode1028(void)
{
    Logger::WriteMessage("Test Leet Code 1028");
    LeetCodeTree leetCode;
    string S = "1-2--3--4-5--6--7";
    TreeNode* root = leetCode.recoverFromPreorder(S);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("S = " + S + "; result = " + output);
    leetCode.freeTreeNodes(root);

    S = "1-2--3---4-5--6---7";
    root = leetCode.recoverFromPreorder(S);
    output = leetCode.serialize(root);
    Logger::WriteMessage("S = " + S + "; result = " + output);
    leetCode.freeTreeNodes(root);

    S = "1-401--349---90--88";
    root = leetCode.recoverFromPreorder(S);
    output = leetCode.serialize(root);
    Logger::WriteMessage("S = " + S + "; result = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1080(void)
{
    Logger::WriteMessage("Test Leet Code 1080");
    LeetCodeTree leetCode;
    string input = "[1, 2, 3, 4, -99, -99, 7, 8, 9, -99, -99, 12, 13, -99, 14]";
    int limit = 1;
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.sufficientSubset(root, limit);
    string output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("text = " + input + "; result = " + output);

    input = "[5,4,8,11,null,17,4,7,1,null,null,5,3]";
    limit = 22;
    root = leetCode.deserialize(input);
    root = leetCode.sufficientSubset(root, limit);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("text = " + input + "; result = " + output);

    input = "[10,5,10]";
    limit = 21;
    root = leetCode.deserialize(input);
    root = leetCode.sufficientSubset(root, limit);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("text = " + input + "; result = " + output);
}

void TestLeetCode1026(void)
{
    Logger::WriteMessage("Test Leet Code 1026");
    LeetCodeTree leetCode;
    string input = "[8,3,10,1,6,null,14,null,null,4,7,13]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.maxAncestorDiff(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1022(void)
{
    Logger::WriteMessage("Test Leet Code 1022");
    LeetCodeTree leetCode;
    string input = "[1,0,1,0,1,0,1]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.sumRootToLeaf(root);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1008(void)
{
    Logger::WriteMessage("Test Leet Code 1008");
    LeetCodeTree leetCode;
    vector<int> preorder = { 8,5,1,7,10,12 };
    TreeNode* root = leetCode.bstFromPreorder(preorder);
    string result = leetCode.serialize(root);
    Logger::WriteMessage(preorder);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode314(void)
{
    Logger::WriteMessage("Test Leet Code 314");
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.verticalOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[3, 9, 8, 4, 0, 1, 7]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.verticalOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[3,9,8,4,0,1,7,null,null,null,2,5]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.verticalOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode255(void)
{
    Logger::WriteMessage("Test Leet Code 255");
    LeetCodeTree leetCode;
    vector<int> nums = { 4, 2, 1, 3, 6, 5, 7 };
    bool result = leetCode.verifyPreorder(nums);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "preorder traverse.");
}

void TestLeetCode156(void)
{
    Logger::WriteMessage("Test Leet Code 156");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.upsideDownBinaryTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("Upside Down Path:" + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode285(void)
{
    Logger::WriteMessage("Test Leet Code 285");
    LeetCodeTree leetCode;
    string input = "[4, 2, 6, 1, 3, 5, 7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* node = new TreeNode(3);
    TreeNode* next_node = leetCode.inorderSuccessor(root, node);
    Logger::WriteMessage("Next node of " + to_string(node->val) + " is " + (string)(next_node == nullptr ? "null" : to_string(next_node->val)));
    leetCode.freeTreeNodes(node);

    node = new TreeNode(4);
    next_node = leetCode.inorderSuccessor(root, node);
    Logger::WriteMessage("Next node of " + to_string(node->val) + " is " + (string)(next_node == nullptr ? "null" : to_string(next_node->val)));
    leetCode.freeTreeNodes(node);

    node = new TreeNode(7);
    next_node = leetCode.inorderSuccessor(root, node);
    Logger::WriteMessage("Next node of " + to_string(node->val) + " is " + (string)(next_node == nullptr ? "null" : to_string(next_node->val)));
    leetCode.freeTreeNodes(node);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode250(void)
{
    Logger::WriteMessage("Test Leet Code 250");
    LeetCodeTree leetCode;
    string input = "[5,1,5,5,5,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.countUnivalSubtrees(root);
    Logger::WriteMessage("Count Unique Value Subtrees:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode404(void)
{
    // Test Leet Code #404 
    Logger::WriteMessage("Test Leet Code 404");
    LeetCodeTree leetCode;
    string input = "[3, 9, 20, null, null, 15, 7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = leetCode.sumOfLeftLeaves(root);
    Logger::WriteMessage("The sum of left leaves is: " + to_string(sum));
    leetCode.freeTreeNodes(root);

    input = "[-9, -3, 2, null, 4, 4, 0, -6, null, -5]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    sum = leetCode.sumOfLeftLeaves(root);
    Logger::WriteMessage("The sum of left leaves is: " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode450(void)
{
    Logger::WriteMessage("Test Leet Code 450");
    LeetCodeTree leetCode;

    string input = "[1,null,2]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 2);
    string output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[3,2,4,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 3);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[5,3,6,2,4,null,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 3);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);

    input = "[9,5,13,3,7,11,15,2,4,6,8,10,12,14,16,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    root = leetCode.deleteNode(root, 13);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode366(void)
{
    Logger::WriteMessage("Test Leet Code 366");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.findLeaves(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode536(void)
{
    LeetCodeTree leetCode;
    string s = "4(2(3)(1))(6(5))";
    TreeNode* root = leetCode.str2tree(s);
    string result = leetCode.serialize(root);
    Logger::WriteMessage(s);
    Logger::WriteMessage(result);

    s = "4(2(3)())(6(5))";
    root = leetCode.str2tree(s);
    result = leetCode.serialize(root);
    Logger::WriteMessage(s);
    Logger::WriteMessage(result);

    s = "";
    root = leetCode.str2tree(s);
    result = leetCode.serialize(root);
    Logger::WriteMessage(s);
    Logger::WriteMessage(result);
}

void TestLeetCode337(void)
{
    Logger::WriteMessage("Test Leet Code 337");
    LeetCodeTree leetCode;
    string input = "[3,4,5,1,3,null,1]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = leetCode.robIII(root);
    Logger::WriteMessage("Maximum rob money is " + to_string(sum));
    leetCode.freeTreeNodes(root);

    input = "[3,2,3,null,3, null, 1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    sum = leetCode.robIII(root);
    Logger::WriteMessage("Maximum rob money is " + to_string(sum));
    leetCode.freeTreeNodes(root);

    input = "[4, 1, null, 2, null, 3]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    sum = leetCode.robIII(root);
    Logger::WriteMessage("Maximum rob money is " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode437(void)
{
    Logger::WriteMessage("Test Leet Code 437");
    LeetCodeTree leetCode;
    string input;
    int sum;
    TreeNode* root;
    int total_paths;
    input = "[10,5,-3,3,2,null,11,3,-2,null,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    sum = 8;
    total_paths = leetCode.pathSumIII(root, sum);
    Logger::WriteMessage("The total path to sum " + to_string(sum) + " is " + to_string(total_paths));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode515(void)
{
    Logger::WriteMessage("Test Leet Code 515");
    LeetCodeTree leetCode;
    string input = "[1,3,2,5,3,null,9]";
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.largestValues(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode333(void)
{
    Logger::WriteMessage("Test Leet Code 333");
    LeetCodeTree leetCode;
    string input = "[10,5,15,1,8,null,7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.largestBSTSubtree(root);
    Logger::WriteMessage("Largest BST Subtree = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,3,2,4,null,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.largestBSTSubtree(root);
    Logger::WriteMessage("Largest BST Subtree = " + to_string(result));
    leetCode.freeTreeNodes(root);
    
}

void TestLeetCode530(void)
{
    Logger::WriteMessage("Test Leet Code 530");
    LeetCodeTree leetCode;
    string input = "[1,null,3,2,null]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int min_value = leetCode.getMinimumDifference(root);
    Logger::WriteMessage("min_value = " + to_string(min_value));
}

void TestLeetCode501(void)
{
    Logger::WriteMessage("Test Leet Code 501");
    LeetCodeTree leetCode;
    string input = "[1,null,2,2]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.findMode(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode508(void)
{
    Logger::WriteMessage("Test Leet Code 508");
    LeetCodeTree leetCode;
    string input = "[5,2,-3]";
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.findFrequentTreeSum(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[5,2,-5]";
    root = leetCode.deserialize(input);
    result = leetCode.findFrequentTreeSum(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode513(void)
{
    Logger::WriteMessage("Test Leet Code 513");
    LeetCodeTree leetCode;
    string input = "[2,1,3]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.findBottomLeftValue(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 3, 4, null, 5, 6, null, null, 7]";
    root = leetCode.deserialize(input);
    result = leetCode.findBottomLeftValue(root);
    Logger::WriteMessage("Original Path:" + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode124(void)
{
    Logger::WriteMessage("Test Leet Code 124");
    LeetCodeTree leetCode;
    string input = "[100,-2,1]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int sum = leetCode.maxPathSum(root);
    Logger::WriteMessage("Maximum path sum is " + to_string(sum));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode230(void)
{
    Logger::WriteMessage("Test Leet Code 230");
    LeetCodeTree leetCode;
    string input;
    TreeNode* root;
    input = "[9,5,13,3,7,11,15,2,4,6,8,10,12,14,16,1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    int k = 7;
    Logger::WriteMessage("Kth smallest item = " + to_string(leetCode.kthSmallest(root, k)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode987(void)
{
    Logger::WriteMessage("Test Leet Code 987");
    LeetCodeTree leetCode;
    string input = "[3, 9, 20, null, null, 15, 7]";
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[1,2,3,4,5,6,7]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, 8, 1, null, null, 3, 2, null, 4, 5, null, null, 7, 6]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, 2, 1, 3, null, null, null, 4, 5, null, 7, 6, null, 10, 8, 11, 9]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, 2, 1, 3, null, 5, 22, 9, 4, 12, 25, null, null, 13, 14, 8, 6, null, null, null, null, null, 27, 24, 26, null, 17, 7, null, 28, null, null, null, null, null, 19, null, 11, 10, null, null, null, 23, 16, 15, 20, 18, null, null, null, null, null, 21, null, null, 29]";
    root = leetCode.deserialize(input);
    result = leetCode.verticalTraversal(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);
}

void TestLeetCode426(void)
{
    Logger::WriteMessage("Test Leet Code 426");
    LeetCodeTree leetCode;
    string input = "[4,2,5,1,3]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* head = leetCode.treeToDoublyList(root);
    string output;
    TreeNode* node = head;
    size_t size = 0;
    while (true)
    {
        output.append(to_string(node->val) + " ");
        size++;
        node = node->right;
        if (node == head) break;
    }
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
    node = head;
    for (size_t i = 0; i < size; i++)
    {
        node = head->right;
        delete head;
        head = node;
    }
}

void TestLeetCode988(void)
{
    Logger::WriteMessage("Test Leet Code 988");
    LeetCodeTree leetCode;
    string input = "[0,1,2,3,4,3,4]";
    TreeNode* root = leetCode.deserialize(input);
    string result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[25,1,3,1,3,0,2]";
    root = leetCode.deserialize(input);
    result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[2,2,1,null,1,0,null,0]";
    root = leetCode.deserialize(input);
    result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[0, null, 1]";
    root = leetCode.deserialize(input);
    result = leetCode.smallestFromLeaf(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);
}

void TestLeetCode510(void)
{
    Logger::WriteMessage("Test Leet Code 510");
    LeetCodeTree leetCode;
    string input = "[2,1,3]";
    int n = 1;
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* result = leetCode.inorderSuccessor(leetCode.findTreeNode(root, n));
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result->val));
    leetCode.freeTreeNodes(root);

    input = "[5,3,6,2,4,null,null,1]";
    n = 6;
    root = leetCode.deserialize(input);
    result = leetCode.inorderSuccessor(leetCode.findTreeNode(root, n));
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + (string)((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9,null]";
    n = 15;
    root = leetCode.deserialize(input);
    result = leetCode.inorderSuccessor(leetCode.findTreeNode(root, n));
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result->val));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode938(void)
{
    Logger::WriteMessage("Test Leet Code 938");
    LeetCodeTree leetCode;
    string input = "[10,5,15,3,7,null,18]";
    TreeNode* root = leetCode.deserialize(input);
    int L = 7;
    int R = 15;
    int result = leetCode.rangeSumBST(root, L, R);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[10,5,15,3,7,13,18,1,null,6]";
    root = leetCode.deserialize(input);
    L = 6;
    R = 10;
    result = leetCode.rangeSumBST(root, L, R);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode894(void)
{
    Logger::WriteMessage("Test Leet Code 894");
    LeetCodeTree leetCode;
    int N = 7;
    vector<TreeNode*> result = leetCode.allPossibleFBT(N);
    for (size_t i = 0; i < result.size(); i++)
    {
        string output = leetCode.serialize(result[i]);
        Logger::WriteMessage(output);
        leetCode.freeTreeNodes(result[i]);
    }
}

void TestLeetCode971(void)
{
    Logger::WriteMessage("Test Leet Code 971");
    LeetCodeTree leetCode;
    string input = "[1, 2]";
    TreeNode* root = leetCode.deserialize(input);
    vector<int> voyage = { 2, 1 };
    vector<int> result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3]";
    root = leetCode.deserialize(input);
    voyage = { 1,3,2 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3]";
    root = leetCode.deserialize(input);
    voyage = { 1,2,3 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3, null, null, null, 4, 6, 5]";
    root = leetCode.deserialize(input);
    voyage = { 1, 2, 3, 4, 5, 6 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,3,2, null, null, null, 4, 6, 7]";
    root = leetCode.deserialize(input);
    voyage = { 1, 2, 3, 4, 5, 6 };
    result = leetCode.flipMatchVoyage(root, voyage);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(voyage);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode889(void)
{
    Logger::WriteMessage("Test Leet Code 889");
    LeetCodeTree leetCode;
    vector<int> pre = { 1, 2, 4, 5, 3, 6, 7 };
    vector<int> post = { 4, 5, 2, 6, 7, 3, 1 };
    TreeNode* result = leetCode.constructFromPrePost(pre, post);
    string output = leetCode.serialize(result);
    Logger::WriteMessage(pre);
    Logger::WriteMessage(post);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(result);

    pre = { 1, 2, 4, 5 };
    post = { 4, 5, 2, 1 };
    result = leetCode.constructFromPrePost(pre, post);
    output = leetCode.serialize(result);
    Logger::WriteMessage(pre);
    Logger::WriteMessage(post);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(result);
}

void TestLeetCode958(void)
{
    Logger::WriteMessage("Test Leet Code 958");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5,6]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.isCompleteTree(root);
    Logger::WriteMessage("Result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,4,5,null,7]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    result = leetCode.isCompleteTree(root);
    Logger::WriteMessage("Result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode968(void)
{
    Logger::WriteMessage("Test Leet Code 968");
    LeetCodeTree leetCode;
    string input = "[0,0,null,0,0]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.minCameraCover(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));

    input = "[0,0,null,0,null,0,null,null,0]";
    root = leetCode.deserialize(input);
    result = leetCode.minCameraCover(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
}

void TestLeetCode428(void)
{
    Logger::WriteMessage("Test Leet Code 428");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node* root = treeCodec.deserialize(input);
    string output = treeCodec.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeNodes(root);
}

void TestLeetCode431(void)
{
    Logger::WriteMessage("Test Leet Code 431");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    NaryTreeBinaryCodec b_treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node* root = treeCodec.deserialize(input);
    TreeNode* b_tree = b_treeCodec.encode(root);
    Node* nary_tree = b_treeCodec.decode(b_tree);
    string output = treeCodec.serialize(nary_tree);
    Logger::WriteMessage(output);
    leetCode.freeNodes(root);
    leetCode.freeTreeNodes(b_tree);
    leetCode.freeNodes(nary_tree);
}

void TestLeetCode590(void)
{
    Logger::WriteMessage("Test Leet Code 590");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node* root = treeCodec.deserialize(input);
    vector<int> result = leetCode.postorder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
}

void TestLeetCode559(void)
{
    Logger::WriteMessage("Test Leet Code 559");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node* root = treeCodec.deserialize(input);
    int result = leetCode.maxDepth(root);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeNodes(root);
}

void TestLeetCode979(void)
{
    Logger::WriteMessage("Test Leet Code 979");
    LeetCodeTree leetCode;
    string input = "[3,0,0]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[0,3,0]";
    root = leetCode.deserialize(input);
    result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,0,2]";
    root = leetCode.deserialize(input);
    result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,0,0,null,3]";
    root = leetCode.deserialize(input);
    result = leetCode.distributeCoins(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode429(void)
{
    Logger::WriteMessage("Test Leet Code 429");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node* root = treeCodec.deserialize(input);
    vector<vector<int>> result = leetCode.levelOrder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
}

void TestLeetCode965(void)
{
    Logger::WriteMessage("Test Leet Code 965");
    LeetCodeTree leetCode;
    string input = "[1,1,1,1,1,null,1]";
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.isUnivalTree(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));

    input = "[2,2,2,5,2]";
    root = leetCode.deserialize(input);
    result = leetCode.isUnivalTree(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode993(void)
{
    Logger::WriteMessage("Test Leet Code 993");
    LeetCodeTree leetCode;
    string input = "[1,2,3,4]";
    int x = 4;
    int y = 3;
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.isCousins(root, x, y);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + (string)(result ? "true" : "false"));

    input = "[1,2,3,null,4,null,5]";
    x = 5;
    y = 4;
    root = leetCode.deserialize(input);
    result = leetCode.isCousins(root, x, y);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + (string)(result ? "true" : "false"));

    input = "[1, 2, 3, null, 4]";
    x = 2;
    y = 3;
    root = leetCode.deserialize(input);
    result = leetCode.isCousins(root, x, y);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode998(void)
{
    Logger::WriteMessage("Test Leet Code 998");
    LeetCodeTree leetCode;
    string input = "[4, 1, 3, null, null, 2]";
    TreeNode* root = leetCode.deserialize(input);
    int val = 5;
    root = leetCode.insertIntoMaxTree(root, val);
    string output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("output = " + output);

    input = "[5,2,4,null,1]";
    root = leetCode.deserialize(input);
    val = 3;
    root = leetCode.insertIntoMaxTree(root, val);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("output = " + output);

    input = "[5,2,3,null,1]";
    root = leetCode.deserialize(input);
    val = 4;
    root = leetCode.insertIntoMaxTree(root, val);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("output = " + output);
}

void TestLeetCode298(void)
{
    Logger::WriteMessage("Test Leet Code 298");
    LeetCodeTree leetCode;
    string input = "[1,null,3,2,4,null,null,null,5]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.longestConsecutive(root);
    Logger::WriteMessage("Longest Consecutive Subtrees:" + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[2,null,3,2,null,1,null]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.longestConsecutive(root);
    Logger::WriteMessage("Longest Consecutive Subtrees:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode951(void)
{
    Logger::WriteMessage("Test Leet Code 951");
    LeetCodeTree leetCode;
    string tree1 = "[1, 2, 3, 4, 5, 6, null, null, null, 7, 8]";
    string tree2 = "[1,3,2,null,6,4,5,null,null,null,null,8,7]";
    TreeNode* root1 = leetCode.deserialize(tree1);
    TreeNode* root2 = leetCode.deserialize(tree2);
    bool result = leetCode.flipEquiv(root1, root2);
    Logger::WriteMessage(tree1);
    Logger::WriteMessage(tree2);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);
}

void TestLeetCode701(void)
{
    Logger::WriteMessage("Test Leet Code 701");
    LeetCodeTree leetCode;
    string input = "[4, 2, 7, 1, 3]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int value = 5;
    root = leetCode.insertIntoBST(root, value);
    string output = leetCode.serialize(root);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode897(void)
{
    Logger::WriteMessage("Test Leet Code 897");
    LeetCodeTree leetCode;
    string input = "[5, 3, 6, 2, 4, null, 8, 1, null, null, null, 7, 9]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* new_tree = leetCode.increasingBST(root);
    string output = leetCode.serialize(new_tree);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + output);
    leetCode.freeTreeNodes(new_tree);
}

void TestLeetCode606(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,3,4]";
    TreeNode* root = leetCode.deserialize(input);
    string result = leetCode.tree2str(root);
    Logger::WriteMessage("input = " + input + "; result = " + result);
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,null,4]";
    root = leetCode.deserialize(input);
    result = leetCode.tree2str(root);
    Logger::WriteMessage("input = " + input + "; result = " + result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode662(void)
{
    LeetCodeTree leetCode;
    string input = "[1, 3, 2, 5, 3, null, 9]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);

    input = "[1, 3, null, 5, 3]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);

    input = "[1,3,2,5]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);

    input = "[1,3,2,5,null,null,9,6,null,null,7]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    width = leetCode.widthOfBinaryTree(root);
    Logger::WriteMessage("Tree width = " + to_string(width));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode95(void)
{
    Logger::WriteMessage("Test Leet Code 95");
    LeetCodeTree leetCode;
    int n;
    n = 0;
    vector<TreeNode*> result;
    result = leetCode.generateTrees(n);
    for (size_t i = 0; i < result.size(); i++)
    {
        TreeNode* root = result[i];
        string output = leetCode.serialize(root);
        Logger::WriteMessage(output);
        leetCode.freeTreeNodes(root);
    }
}

void TestLeetCode669(void)
{
    LeetCodeTree leetCode;
    string input = "[1, 0, 2]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* result = leetCode.trimBST(root, 1, 2);
    string output = leetCode.serialize(result);
    Logger::WriteMessage("After Trim:" + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(result);

    input = "[3, 0, 4, null, 2, null, null, 1]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.trimBST(root, 1, 3);
    output = leetCode.serialize(result);
    Logger::WriteMessage("After Trim:" + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(result);

    input = "[1, null, 2]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.trimBST(root, 2, 4);
    output = leetCode.serialize(result);
    Logger::WriteMessage("After Trim:" + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(result);
}

void TestLeetCode671(void)
{
    LeetCodeTree leetCode;
    string input = "[2, 2, 5, null, null, 5, 7]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.findSecondMinimumValue(root);
    Logger::WriteMessage("The second smallest value:" + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[2, 2, 2]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.findSecondMinimumValue(root);
    Logger::WriteMessage("The second smallest value:" + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[5, 8, 5]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.findSecondMinimumValue(root);
    Logger::WriteMessage("The second smallest value:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode865(void)
{
    Logger::WriteMessage("Test Leet Code 865");
    LeetCodeTree leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* result = leetCode.subtreeWithAllDeepest(root);
    string output = leetCode.serialize(result);
    Logger::WriteMessage("input = " + input + "; output = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode538(void)
{
    LeetCodeTree leetCode;
    string input = "[5, 2, 13]";
    Logger::WriteMessage("old tree: " + input);
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* new_root = leetCode.convertBST(root);
    string output = leetCode.serialize(new_root);
    Logger::WriteMessage("new tree: " + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(new_root);

    input = "[2, 0, 3, -4, 1]";
    Logger::WriteMessage("old tree: " + input);
    root = leetCode.deserialize(input);
    new_root = leetCode.convertBST(root);
    output = leetCode.serialize(new_root);
    Logger::WriteMessage("new tree: " + output);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(new_root);
}

void TestLeetCode617(void)
{
    LeetCodeTree leetCode;
    string input = "[1,3,2,5,null]";
    TreeNode* tree1 = leetCode.deserialize(input);
    Logger::WriteMessage("tree1 = " + input);
    input = "[2,1,3,null,4,null,7]";
    TreeNode* tree2 = leetCode.deserialize(input);
    Logger::WriteMessage("tree2 = " + input);
    TreeNode* root = leetCode.mergeTrees(tree1, tree2);
    Logger::WriteMessage("result = " + leetCode.serialize(root));
    leetCode.freeTreeNodes(tree1);
    leetCode.freeTreeNodes(tree2);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode623(void)
{
    LeetCodeTree leetCode;
    string input = "[4,2,null,3,1]";
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.addOneRow(root, 1, 3);
    string output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("original tree = " + input + "; new tree = " + output);

    input = "[4,2,6,3,1,5,null]";
    root = leetCode.deserialize(input);
    root = leetCode.addOneRow(root, 1, 2);
    output = leetCode.serialize(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage("original tree = " + input + "; new tree = " + output);
}

void TestLeetCode776(void)
{
    Logger::WriteMessage("Test Leet Code 776");
    LeetCodeTree leetCode;
    string input = "[4,2,6,1,3,5,7]";
    int V = 2;
    Logger::WriteMessage("input = " + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<TreeNode*> result = leetCode.splitBST(root, V);
    string smallTree = leetCode.serialize(result[0]);
    string largeTree = leetCode.serialize(result[1]);
    Logger::WriteMessage("smallTree = " + smallTree);
    Logger::WriteMessage("largeTree = " + largeTree);
    leetCode.freeTreeNodes(result[0]);
    leetCode.freeTreeNodes(result[1]);
}

void TestLeetCode297(void)
{
    Logger::WriteMessage("Test Leet Code 297");
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,null,4,5]";
    Logger::WriteMessage("Deserialize and Serialize Test:");
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    string output = leetCode.serialize(root);
    if (input == output)
    {
        Logger::WriteMessage("Test Pass");
    }
    else
    {
        Logger::WriteMessage("Test Fail");
    }
    leetCode.freeTreeNodes(root);
}

void TestLeetCode652(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,null,2,4,null,null,4]";
    TreeNode* root = leetCode.deserialize(input);
    vector<TreeNode*> result = leetCode.findDuplicateSubtrees(root);
    Logger::WriteMessage("input = " + input);
    for (TreeNode* node : result)
    {
        string output = leetCode.serialize(node);
        Logger::WriteMessage("subtree = " + output);
    }
    leetCode.freeTreeNodes(root);
}

void TestLeetCode654(void)
{
    LeetCodeTree leetCode;
    vector<int> nums = { 3, 2, 1, 6, 0, 5 };
    Logger::WriteMessage(nums);
    TreeNode* root = leetCode.constructMaximumBinaryTree(nums);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("tree = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode814(void)
{
    Logger::WriteMessage("Test Leet Code 814");
    LeetCodeTree leetCode;
    string input = "[1,null,0,0,1]";
    Logger::WriteMessage("input = " + input);
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.pruneTree(root);
    string output = leetCode.serialize(root);
    Logger::WriteMessage("output = " + output);
    leetCode.freeTreeNodes(root);

    input = "[1,0,1,0,0,0,1]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    root = leetCode.pruneTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("output = " + output);
    leetCode.freeTreeNodes(root);

    input = "[1,1,0,1,1,0,1,0]";
    Logger::WriteMessage("input = " + input);
    root = leetCode.deserialize(input);
    root = leetCode.pruneTree(root);
    output = leetCode.serialize(root);
    Logger::WriteMessage("output = " + output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode700(void)
{
    Logger::WriteMessage("Test Leet Code 700");
    LeetCodeTree leetCode;
    string input = "[4, 2, 7, 1, 3]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int value = 2;
    TreeNode* result = leetCode.searchBST(root, value);
    string output = leetCode.serialize(result);
    Logger::WriteMessage(output);

    value = 5;
    result = leetCode.searchBST(root, value);
    output = leetCode.serialize(result);
    Logger::WriteMessage(output);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode663(void)
{
    LeetCodeTree leetCode;
    string input = "[5, 10, 10, null, null, 2, 3]";
    Logger::WriteMessage("Tree:" + input);
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[1, 2, 10, null, null, 2, 20]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);


    input = "[0]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[0, 0]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[-9, -3, 2, null, 4, 4, 0, -6, null, -5]";
    Logger::WriteMessage("Tree:" + input);
    root = leetCode.deserialize(input);
    result = leetCode.checkEqualTree(root);
    Logger::WriteMessage("Can split into equal tree:" + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode687(void)
{
    LeetCodeTree leetCode;
    string input = "[1, 2, 2, 2, 2, 2, 2, 2]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int max_path = leetCode.longestUnivaluePath(root);
    Logger::WriteMessage("Max Path Length = " + to_string(max_path));
    leetCode.freeTreeNodes(root);

    input = "[5,4,5,1,1,null,5]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    max_path = leetCode.longestUnivaluePath(root);
    Logger::WriteMessage("Max Path Length = " + to_string(max_path));
    leetCode.freeTreeNodes(root);

    input = "[1,4,5,4,4,null,5]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    max_path = leetCode.longestUnivaluePath(root);
    Logger::WriteMessage("Max Path Length = " + to_string(max_path));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode545(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5,6,null,null,null,7,8,9,10]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.boundaryOfBinaryTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1,null, 2, 3, 4]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    result = leetCode.boundaryOfBinaryTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[1]";
    Logger::WriteMessage(input);
    root = leetCode.deserialize(input);
    result = leetCode.boundaryOfBinaryTree(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode543(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,3,4,5]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int diameter = leetCode.diameterOfBinaryTree(root);
    Logger::WriteMessage("diameter = " + to_string(diameter));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode666(void)
{
    LeetCodeTree leetCode;
    vector<int> nums = { 113, 215, 221 };
    Logger::WriteMessage(nums);
    int result = leetCode.pathSumIV(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 113, 221 };
    Logger::WriteMessage(nums);
    result = leetCode.pathSumIV(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode783(void)
{
    Logger::WriteMessage("Test Leet Code 783");
    LeetCodeTree leetCode;
    string input = "[4,2,6,1,3,null,null]";
    Logger::WriteMessage(input);
    TreeNode* root = leetCode.deserialize(input);
    int min_diff = leetCode.minDiffInBST(root);
    Logger::WriteMessage("min_diff = " + to_string(min_diff));
}


void TestLeetCode637(void)
{
    LeetCodeTree leetCode;
    string input = "[3,9,20,null,null,15,7]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    vector<double> result = leetCode.averageOfLevels(root);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode549(void)
{
    LeetCodeTree leetCode;
    string input = "[24,25,25,26,24,26,24,25,27,23,23,25,25,23,23,26,24,26,28,24,22,22,24,26,26,26,26,22,24,22,22,null,27,null,25,null,25,null,27,null,25,null,21,null,23,23,23,null,25,null,25,null,27,27,25,null,23,null,23,null,21,21,21]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));

    input = "[2,1,3]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));

    input = "[3,2,4,1]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));

    input = "[3,2,1,1]";
    Logger::WriteMessage("Original Path:" + input);
    root = leetCode.deserialize(input);
    max_length = leetCode.longestConsecutiveII(root);
    Logger::WriteMessage("Max Length = " + to_string(max_length));
}

void TestLeetCode270(void)
{
    Logger::WriteMessage("Test Leet Code 270");
    LeetCodeTree leetCode;
    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    double target = 100;
    int result = leetCode.closestValue(root, target);
    Logger::WriteMessage("Closet value:" + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode872(void)
{
    Logger::WriteMessage("Test Leet Code 872");
    LeetCodeTree leetCode;
    string input1 = "[1, 2]";
    string input2 = "[2, 2]";
    TreeNode* tree1 = leetCode.deserialize(input1);
    TreeNode* tree2 = leetCode.deserialize(input2);
    bool result = leetCode.leafSimilar(tree1, tree2);
    Logger::WriteMessage("leaf similiar = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(tree1);
    leetCode.freeTreeNodes(tree2);
}

void TestLeetCode572(void)
{
    LeetCodeTree leetCode;
    string input = "[3,4,5,1,2,null,null]";
    Logger::WriteMessage("s = " + input);
    TreeNode* s = leetCode.deserialize(input);
    input = "[4,1,2]";
    Logger::WriteMessage("t = " + input);
    TreeNode* t = leetCode.deserialize(input);
    Logger::WriteMessage("t is subtree of s ? " + (string)(leetCode.isSubtree(s, t) ? "true" : "false"));
    leetCode.freeTreeNodes(s);
    leetCode.freeTreeNodes(t);

    input = "[3,4,5,1,2,null,null, 0, null]";
    Logger::WriteMessage("s = " + input);
    s = leetCode.deserialize(input);
    input = "[4,1,2]";
    Logger::WriteMessage("t = " + input);
    t = leetCode.deserialize(input);
    Logger::WriteMessage("t is subtree of s ? " + (string)(leetCode.isSubtree(s, t) ? "true" : "false"));
    leetCode.freeTreeNodes(s);
    leetCode.freeTreeNodes(t);
}

void TestLeetCode272(void)
{
    Logger::WriteMessage("Test Leet Code 270");
    LeetCodeTree leetCode;
    string input = "[4,2,7,1,3,6,9]";
    Logger::WriteMessage("Original Path:" + input);
    TreeNode* root = leetCode.deserialize(input);
    double target = 3.2;
    int k = 3;
    vector<int> result = leetCode.closestKValues(root, target, k);
    Logger::WriteMessage("target = " + to_string(target) + "; k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode563(void)
{
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,null,4,5]";
    TreeNode* root = leetCode.deserialize(input);
    Logger::WriteMessage(input);
    int tilt = leetCode.findTilt(root);
    Logger::WriteMessage("tilt = " + to_string(tilt));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode863(void)
{
    Logger::WriteMessage("Test Leet Code 863");
    LeetCodeTree leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    int value = 5;
    int K = 2;
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* target = new TreeNode(value);
    vector<int> result = leetCode.distanceK(root, target, K);
    Logger::WriteMessage(input);
    Logger::WriteMessage("value = " + to_string(value) + "; target = " + to_string(target->val) + "; K = " + to_string(K));
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(target);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    value = 1;
    K = 3;
    root = leetCode.deserialize(input);
    target = new TreeNode(value);
    result = leetCode.distanceK(root, target, K);
    Logger::WriteMessage(input);
    Logger::WriteMessage("value = " + to_string(value) + "; target = " + to_string(target->val) + "; K = " + to_string(K));
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
    leetCode.freeTreeNodes(target);
}

void TestLeetCode653(void)
{
    LeetCodeTree leetCode;
    string input = "[5,3,6,2,4,null,7]";
    int k = 9;
    Logger::WriteMessage("input = " + input);
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.findTarget(root, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    k = 28;
    result = leetCode.findTarget(root, k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode742(void)
{
    Logger::WriteMessage("Test Leet Code 742");
    LeetCodeTree leetCode;
    string input = "[1, 2, 3, 4, null, null, 7, 8, 9, null, null, 12, null, null, null, null, 13, null, 14]";
    int k = 8;
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[1, 3, 2]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[1]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[1,2,3,4,null,null,null,5,null,6]";
    k = 2;
    root = leetCode.deserialize(input);
    result = leetCode.findClosestLeaf(root, k);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1457(void)
{
    Logger::WriteMessage("Test Leet Code 1457");
    LeetCodeTree leetCode;
    string input = "[2,3,1,3,1,null,1]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.pseudoPalindromicPaths(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[2,1,1,1,3,null,null,null,null,null,1]";
    root = leetCode.deserialize(input);
    result = leetCode.pseudoPalindromicPaths(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));

    input = "[9]";
    root = leetCode.deserialize(input);
    result = leetCode.pseudoPalindromicPaths(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1469(void)
{
    Logger::WriteMessage("Test Leet Code 1469");
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,4]";
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.getLonelyNodes(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[7,1,4,6,null,5,3,null,null,null,null,null,2]";
    root = leetCode.deserialize(input);
    result = leetCode.getLonelyNodes(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]";
    root = leetCode.deserialize(input);
    result = leetCode.getLonelyNodes(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[197]";
    root = leetCode.deserialize(input);
    result = leetCode.getLonelyNodes(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);

    input = "[31,null,78,null,28]";
    root = leetCode.deserialize(input);
    result = leetCode.getLonelyNodes(root);
    leetCode.freeTreeNodes(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage(result);
}

void TestLeetCode1519(void)
{
    Logger::WriteMessage("Test Leet Code 1519");
    LeetCodeTree leetCode;
    int n = 7;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 4},{1, 5},{2, 3},{2, 6} };
    string labels = "abaedcd";
    vector<int> result = leetCode.countSubTrees(n, edges, labels);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; labels = " + labels);
    Logger::WriteMessage(result);

    n = 4;
    edges = { {0, 1},{1, 2},{0, 3} };
    labels = "bbbb";
    result = leetCode.countSubTrees(n, edges, labels);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; labels = " + labels);
    Logger::WriteMessage(result);

    n = 5;
    edges = { {0, 1},{0, 2},{1, 3},{0, 4} };
    labels = "aabab";
    result = leetCode.countSubTrees(n, edges, labels);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; labels = " + labels);
    Logger::WriteMessage(result);

    n = 6;
    edges = { {0, 1},{0, 2},{1, 3},{3, 4},{4, 5} };
    labels = "cbabaa";
    result = leetCode.countSubTrees(n, edges, labels);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; labels = " + labels);
    Logger::WriteMessage(result);

    n = 7;
    edges = { {0, 1},{1, 2},{2, 3},{3, 4},{4, 5},{5, 6} };
    labels = "aaabaaa";
    result = leetCode.countSubTrees(n, edges, labels);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("n = " + to_string(n) + "; labels = " + labels);
    Logger::WriteMessage(result);
}

void TestLeetCode1530(void)
{
    Logger::WriteMessage("Test Leet Code 1530");
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,4]";
    int distance = 3;
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.countPairs(root, distance);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,4,5,6,7]";
    distance = 3;
    root = leetCode.deserialize(input);
    result = leetCode.countPairs(root, distance);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[7,1,4,6,null,5,3,null,null,null,null,null,2]";
    distance = 3;
    root = leetCode.deserialize(input);
    result = leetCode.countPairs(root, distance);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[100]";
    distance = 1;
    root = leetCode.deserialize(input);
    result = leetCode.countPairs(root, distance);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,1,1]";
    distance = 2;
    root = leetCode.deserialize(input);
    result = leetCode.countPairs(root, distance);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1602(void)
{
    Logger::WriteMessage("Test Leet Code 1602");
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,4,5,6]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* u = new TreeNode(4);
    TreeNode * result = leetCode.findNearestRightNode(root, u);
    Logger::WriteMessage("input = " + input + "; result = " + (string)((result == nullptr) ? "nullptr" : to_string(result->val)));
    leetCode.freeTreeNodes(u);
    leetCode.freeTreeNodes(root);

    input = "[3,null,4,2]";
    root = leetCode.deserialize(input);
    u = new TreeNode(4);
    result = leetCode.findNearestRightNode(root, u);
    Logger::WriteMessage("input = " + input + "; result = " + (string)((result == nullptr) ? "nullptr" :to_string(result->val)));
    leetCode.freeTreeNodes(u);
    leetCode.freeTreeNodes(root);

    input = "[1]";
    root = leetCode.deserialize(input);
    u = new TreeNode(1);
    result = leetCode.findNearestRightNode(root, u);
    Logger::WriteMessage("input = " + input + "; result = " + (string)((result == nullptr) ? "nullptr" : to_string(result->val)));
    leetCode.freeTreeNodes(u);
    leetCode.freeTreeNodes(root);

    input = "[3,4,2,null,null,null,1]";
    root = leetCode.deserialize(input);
    u = new TreeNode(4);
    result = leetCode.findNearestRightNode(root, u);
    Logger::WriteMessage("input = " + input + "; result = " + (string)((result == nullptr) ? "nullptr" : to_string(result->val)));
    leetCode.freeTreeNodes(u);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1609(void)
{
    Logger::WriteMessage("Test Leet Code 1609");
    LeetCodeTree leetCode;
    string input = "[1, 10, 4, 3, null, 7, 9, 12, 8, 6, null, null, 2]";
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.isEvenOddTree(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[5,4,2,3,3,7]";
    root = leetCode.deserialize(input);
    result = leetCode.isEvenOddTree(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[5,9,1,3,5,7]";
    root = leetCode.deserialize(input);
    result = leetCode.isEvenOddTree(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[1]";
    root = leetCode.deserialize(input);
    result = leetCode.isEvenOddTree(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]";
    root = leetCode.deserialize(input);
    result = leetCode.isEvenOddTree(root);
    Logger::WriteMessage("input = " + input + "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1612(void)
{
    Logger::WriteMessage("Test Leet Code 1612");
    LeetCodeTree leetCode;
    string input1 = "[x]";
    string input2 = "[x]";
    TreeNode* root1 = leetCode.deserialize(input1);
    TreeNode* root2 = leetCode.deserialize(input2);
    bool result = leetCode.checkEquivalence(root1, root2);
    Logger::WriteMessage(
        "root1 = " + input1 + 
        "; root2 = " + input2 +
        "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[+,a,+,null,null,b,c]";
    input2 = "[+,+,b,c,a]";
    root1 = leetCode.deserialize(input1);
    root2 = leetCode.deserialize(input2);
    result = leetCode.checkEquivalence(root1, root2);
    Logger::WriteMessage(
        "root1 = " + input1 +
        "; root2 = " + input2 +
        "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);

    input1 = "[+,a,+,null,null,b,c]";
    input2 = "[+,+,b,d,a]";
    root1 = leetCode.deserialize(input1);
    root2 = leetCode.deserialize(input2);
    result = leetCode.checkEquivalence(root1, root2);
    Logger::WriteMessage(
        "root1 = " + input1 +
        "; root2 = " + input2 +
        "; result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root1);
    leetCode.freeTreeNodes(root2);
}

void TestLeetCode1522(void)
{
    Logger::WriteMessage("Test Leet Code 1522");
    LeetCodeTree leetCode;
    string input = "[1[3[5 6] 2 4]]";
    NaryTreeCodec  treeCodec;
    Node* root = treeCodec.deserialize(input);
    int result = leetCode.diameter(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeNodes(root);

    input = "[1[2[3[5] 4[8]]]";
    root = treeCodec.deserialize(input);
    result = leetCode.diameter(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeNodes(root);

    input = "[1[2 3[6 7[11[14]]] 4[8[12]] 5[9[13] 10]]]";
    root = treeCodec.deserialize(input);
    result = leetCode.diameter(root);
    Logger::WriteMessage("input = " + input + "; result = " + to_string(result));
    leetCode.freeNodes(root);
}

void TestLeetCode1516(void)
{
    Logger::WriteMessage("Test Leet Code 1516");
    LeetCodeTree leetCode;
    string input = "[1[2[4[7 8] 5] 3[6]]]";
    NaryTreeCodec  treeCodec;
    Node* root = treeCodec.deserialize(input);
    Node* p = new Node(4, vector<Node*>());
    Node* q = new Node(1, vector<Node*>());
    root = leetCode.moveSubTree(root, p, q);
    Logger::WriteMessage("input = " + input + "; result = " + treeCodec.serialize(root));
    leetCode.freeNodes(root);
    leetCode.freeNodes(p);
    leetCode.freeNodes(q);

    input = "[1[2[4[7 8] 5] 3[6]]]";
    root = treeCodec.deserialize(input);
    p = new Node(7, vector<Node*>());
    q = new Node(4, vector<Node*>());
    root = leetCode.moveSubTree(root, p, q);
    Logger::WriteMessage("input = " + input + "; result = " + treeCodec.serialize(root));
    leetCode.freeNodes(root);
    leetCode.freeNodes(p);
    leetCode.freeNodes(q);

    input = "[1[2[4[7 8] 5] 3[6]]]";
    root = treeCodec.deserialize(input);
    p = new Node(3, vector<Node*>());
    q = new Node(8, vector<Node*>());
    root = leetCode.moveSubTree(root, p, q);
    Logger::WriteMessage("input = " + input + "; result = " + treeCodec.serialize(root));
    leetCode.freeNodes(root);
    leetCode.freeNodes(p);
    leetCode.freeNodes(q);

    input = "[1[2[4[7 8] 5] 3[6]]]";
    root = treeCodec.deserialize(input);
    p = new Node(2, vector<Node*>());
    q = new Node(7, vector<Node*>());
    root = leetCode.moveSubTree(root, p, q);
    Logger::WriteMessage("input = " + input + "; result = " + treeCodec.serialize(root));
    leetCode.freeNodes(root);
    leetCode.freeNodes(p);
    leetCode.freeNodes(q);

    input = "[1[2[4[7 8] 5] 3[6]]]";
    root = treeCodec.deserialize(input);
    p = new Node(1, vector<Node*>());
    q = new Node(2, vector<Node*>());
    root = leetCode.moveSubTree(root, p, q);
    Logger::WriteMessage("input = " + input + "; result = " + treeCodec.serialize(root));
    leetCode.freeNodes(root);
    leetCode.freeNodes(p);
    leetCode.freeNodes(q);
}

void TestLeetCode1597(void)
{
    Logger::WriteMessage("Test Leet Code 1597");
    LeetCodeTree leetCode;
    string s = "2-3/(5*2)+1";
    TreeNode* root = leetCode.expTree(s);
    Logger::WriteMessage("s = " + s + "; result = " + leetCode.serialize(root, true));
    leetCode.freeTreeNodes(root);

    s = "3*4-2*5";
    root = leetCode.expTree(s);
    Logger::WriteMessage("s = " + s + "; result = " + leetCode.serialize(root, true));
    leetCode.freeTreeNodes(root);

    s = "1+2+3+4+5";
    root = leetCode.expTree(s);
    Logger::WriteMessage("s = " + s + "; result = " + leetCode.serialize(root, true));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1666(void)
{
    Logger::WriteMessage("Test Leet Code 1666");
    LeetCodeTree leetCode;
    string input = "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* leaf = leetCode.findTreeNode(root, 7);
    root = leetCode.flipBinaryTree(root, leaf);
    Logger::WriteMessage("input = " + input + "leaf = " + to_string(leaf->val) +"; result = " + leetCode.serialize(root));
    leetCode.freeTreeNodes(root);

    input = "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]";
    root = leetCode.deserialize(input);
    leaf = leetCode.findTreeNode(root, 0);
    root = leetCode.flipBinaryTree(root, leaf);
    Logger::WriteMessage("input = " + input + "leaf = " + to_string(leaf->val) + "; result = " + leetCode.serialize(root));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1740(void)
{
    Logger::WriteMessage("Test Leet Code 1666");
    LeetCodeTree leetCode;
    string input = "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]";
    TreeNode* root = leetCode.deserialize(input);
    int p = 5;
    int q = 0;
    int result = leetCode.findDistance(root, p, q);
    Logger::WriteMessage("input = " + input + "; p = " + to_string(p) + 
        "; q = " + to_string(q) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    root = leetCode.deserialize(input);
    p = 5;
    q = 7;
    result = leetCode.findDistance(root, p, q);
    Logger::WriteMessage("input = " + input + "; p = " + to_string(p) +
        "; q = " + to_string(q) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    root = leetCode.deserialize(input);
    p = 5;
    q = 5;
    result = leetCode.findDistance(root, p, q);
    Logger::WriteMessage("input = " + input + "; p = " + to_string(p) +
        "; q = " + to_string(q) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1932(void)
{
    Logger::WriteMessage("Test Leet Code 1932");
    LeetCodeTree leetCode;
    vector<vector<int>> node_list =
    {
        {2,1},{3,2,5},{5,4}
    };

    vector<TreeNode*> trees = leetCode.buildBSTForest(node_list);
    TreeNode* root = leetCode.canMerge(trees);
    Logger::WriteMessage(node_list);
    string output = leetCode.serialize(root);
    Logger::WriteMessage(output);

    node_list =
    {
        {5,3,8},{3,2,6}
    };
    trees = leetCode.buildBSTForest(node_list);
    root = leetCode.canMerge(trees);
    Logger::WriteMessage(node_list);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);

    node_list =
    {
        {5, 4} ,{3}
    };
    trees = leetCode.buildBSTForest(node_list);
    root = leetCode.canMerge(trees);
    Logger::WriteMessage(node_list);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);

    node_list =
    {
        {2, 1, 3}
    };
    trees = leetCode.buildBSTForest(node_list);
    root = leetCode.canMerge(trees);
    Logger::WriteMessage(node_list);
    output = leetCode.serialize(root);
    Logger::WriteMessage(output);
}

void TestLeetCode1644(void)
{
    Logger::WriteMessage("Test Leet Code 1644");
    LeetCodeTree leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    Logger::WriteMessage("Original Tree:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int p_val = 5;
    int q_val = 1;
    TreeNode* p = leetCode.findTreeNode(root, p_val);
    TreeNode* q = leetCode.findTreeNode(root, q_val);
    TreeNode* result = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("p = " + to_string(p_val) + "; q = " + to_string(q_val));
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    Logger::WriteMessage("Original Tree:" + input);
    root = leetCode.deserialize(input);
    p_val = 5;
    q_val = 4;
    p = leetCode.findTreeNode(root, p_val);
    q = leetCode.findTreeNode(root, q_val);
    result = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("p = " + to_string(p_val) + "; q = " + to_string(q_val));
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    Logger::WriteMessage("Original Tree:" + input);
    root = leetCode.deserialize(input);
    p_val = 5;
    q_val = 10;
    p = leetCode.findTreeNode(root, p_val);
    q = leetCode.findTreeNode(root, q_val);
    result = leetCode.lowestCommonAncestor(root, p, q);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("p = " + to_string(p_val) + "; q = " + to_string(q_val));
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1902(void)
{
    Logger::WriteMessage("Test Leet Code 1902");
    LeetCodeTree leetCode;
    vector<int> order = { 2, 1, 4, 3 };
    Logger::WriteMessage(order);
    int result = leetCode.maxDepthBST(order);
    Logger::WriteMessage("result = " + to_string(result));

    order = { 2,1,3,4 };
    result = leetCode.maxDepthBST(order);
    Logger::WriteMessage(order);
    Logger::WriteMessage("result = " + to_string(result));

    order = { 1,2,3,4 };
    result = leetCode.maxDepthBST(order);
    Logger::WriteMessage(order);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1650(void)
{
    Logger::WriteMessage("Test Leet Code 1650");
    LeetCodeTree leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    Logger::WriteMessage("Original Tree:" + input);
    TreeNode* root = leetCode.deserialize(input);
    int p_val = 5;
    int q_val = 1;
    TreeNode * p = leetCode.findTreeNode(root, p_val);
    TreeNode * q = leetCode.findTreeNode(root, q_val);
    TreeNode* result = leetCode.lowestCommonAncestorIII(p, q);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("p = " + to_string(p_val) + "; q = " + to_string(q_val));
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    Logger::WriteMessage("Original Tree:" + input);
    root = leetCode.deserialize(input);
    p_val = 5;
    q_val = 4;
    p = leetCode.findTreeNode(root, p_val);
    q = leetCode.findTreeNode(root, q_val);
    result = leetCode.lowestCommonAncestorIII(p, q);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("p = " + to_string(p_val) + "; q = " + to_string(q_val));
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[1,2]";
    Logger::WriteMessage("Original Tree:" + input);
    root = leetCode.deserialize(input);
    p_val = 1;
    q_val = 2;
    p = leetCode.findTreeNode(root, 1);
    q = leetCode.findTreeNode(root, 2);
    result = leetCode.lowestCommonAncestorIII(p, q);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("p = " + to_string(p_val) + "; q = " + to_string(q_val));
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode1676(void)
{
    Logger::WriteMessage("Test Leet Code 1650");
    LeetCodeTree leetCode;
    string input = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode* root = leetCode.deserialize(input);
    vector<int> nodes = { 4, 7 };
    vector<TreeNode *> tree_nodes;
    for (size_t i = 0; i < nodes.size(); i++)
    {
        TreeNode* p = leetCode.findTreeNode(root, nodes[i]);
        tree_nodes.push_back(p);
    }
    TreeNode* result = leetCode.lowestCommonAncestorIV(root, tree_nodes);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage(nodes);
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    root = leetCode.deserialize(input);
    nodes = { 1 };
    tree_nodes.clear();
    for (size_t i = 0; i < nodes.size(); i++)
    {
        TreeNode* p = leetCode.findTreeNode(root, nodes[i]);
        tree_nodes.push_back(p);
    }
    result = leetCode.lowestCommonAncestorIV(root, tree_nodes);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage(nodes);
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    root = leetCode.deserialize(input);
    nodes = { 7,6,2,4 };
    tree_nodes.clear();
    for (size_t i = 0; i < nodes.size(); i++)
    {
        TreeNode* p = leetCode.findTreeNode(root, nodes[i]);
        tree_nodes.push_back(p);
    }
    result = leetCode.lowestCommonAncestorIV(root, tree_nodes);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage(nodes);
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);

    input = "[3,5,1,6,2,0,8,null,null,7,4]";
    root = leetCode.deserialize(input);
    nodes = { 0,1,2,3,4,5,6,7,8 };
    tree_nodes.clear();
    for (size_t i = 0; i < nodes.size(); i++)
    {
        TreeNode* p = leetCode.findTreeNode(root, nodes[i]);
        tree_nodes.push_back(p);
    }
    result = leetCode.lowestCommonAncestorIV(root, tree_nodes);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage(nodes);
    Logger::WriteMessage("result = " + ((result == nullptr) ? "null" : to_string(result->val)));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2096(void)
{
    Logger::WriteMessage("Test Leet Code 2096");
    LeetCodeTree leetCode;
    string input = "[5,1,2,3,null,6,4]";
    int startValue = 3;
    int destValue = 6;
    TreeNode* root = leetCode.deserialize(input);
    string result = leetCode.getDirections(root, startValue, destValue);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);

    input = "[2,1]";
    startValue = 2;
    destValue = 1;
    root = leetCode.deserialize(input);
    result = leetCode.getDirections(root, startValue, destValue);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);
}


void TestLeetCode1973(void)
{
    Logger::WriteMessage("Test Leet Code 1973");
    LeetCodeTree leetCode;
    string input = "[10,3,4,2,1]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.equalToDescendants(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[2,3,null,2,null]";
    root = leetCode.deserialize(input);
    result = leetCode.equalToDescendants(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[0]";
    root = leetCode.deserialize(input);
    result = leetCode.equalToDescendants(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2196(void)
{
    Logger::WriteMessage("Test Leet Code 2196");
    LeetCodeTree leetCode;
    vector<vector<int>> descriptions =
    {
        {20, 15, 1},{20, 17, 0},{50, 20, 1},{50, 80, 0},{80, 19, 1}
    };
    TreeNode* root = leetCode.createBinaryTree(descriptions);
    Logger::WriteMessage(descriptions);
    Logger::WriteMessage(leetCode.serialize(root));
    leetCode.freeTreeNodes(root);

    descriptions =
    {
        {1,2,1},{2,3,0},{3,4,1}
    };
    root = leetCode.createBinaryTree(descriptions);
    Logger::WriteMessage(descriptions);
    Logger::WriteMessage(leetCode.serialize(root));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2236(void)
{
    Logger::WriteMessage("Test Leet Code 2236");
    LeetCodeTree leetCode;
    string input = "[10,4,6]";
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.checkTree(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + (string)(result? "true":"false"));
    leetCode.freeTreeNodes(root);

    input = "[5,3,1]";
    root = leetCode.deserialize(input);
    result = leetCode.checkTree(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2246(void)
{
    Logger::WriteMessage("Test Leet Code 2246");
    LeetCodeTree leetCode;
    vector<int> parent = { -1, 0, 0, 1, 1, 2 };
    string s = "abacbe";
    int result = leetCode.longestPath(parent, s);
    Logger::WriteMessage(parent);
    Logger::WriteMessage("s = " + s + ";result = " + to_string(result));

    parent = { -1,0,0,0 };
    s = "aabc";
    result = leetCode.longestPath(parent, s);
    Logger::WriteMessage(parent);
    Logger::WriteMessage("s = " + s + ";result = " + to_string(result));
}

void TestLeetCode2265(void)
{
    Logger::WriteMessage("Test Leet Code 2265");
    LeetCodeTree leetCode;
    string input = "[4,8,5,0,1,null,6]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.averageOfSubtree(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1]";
    root = leetCode.deserialize(input);
    result = leetCode.averageOfSubtree(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2277(void)
{
    Logger::WriteMessage("Test Leet Code 2277");
    LeetCodeTree leetCode;
    int n = 7;
    vector<vector<int>> edges =
    {
        {0, 1},{0, 2},{0, 3},{1, 4},{2, 5},{2, 6}
    };
    vector<vector<int>> query = { {5, 3, 4},{5, 3, 6} };
    vector<int> result = leetCode.closestNode(n, edges, query);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(query);
    Logger::WriteMessage(result);

    n = 3;
    edges =
    {
        {0, 1},{1, 2}
    };
    query = { {0, 1, 2} };
    result = leetCode.closestNode(n, edges, query);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(query);
    Logger::WriteMessage(result);

    n = 3;
    edges =
    {
        {0, 1},{1, 2}
    };
    query = { {0, 0, 0} };
    result = leetCode.closestNode(n, edges, query);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(query);
    Logger::WriteMessage(result);
}

void TestLeetCode2313(void)
{
    Logger::WriteMessage("Test Leet Code 2313");
    LeetCodeTree leetCode;

    string input = "[3,5,4,2,null,1,1,1,0]";
    TreeNode* root = leetCode.deserialize(input);
    bool result = true;
    int flips = leetCode.minimumFlips(root, result);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(flips));
    leetCode.freeTreeNodes(root);

    input = "[0]";
    root = leetCode.deserialize(input);
    result = false;
    flips = leetCode.minimumFlips(root, result);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + to_string(flips));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2331(void)
{
    Logger::WriteMessage("Test Leet Code 2331");
    LeetCodeTree leetCode;

    string input = "[2,1,3,null,null,0,1]";
    TreeNode* root = leetCode.deserialize(input);
    bool result = leetCode.evaluateTree(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);

    input = "[0]";
    root = leetCode.deserialize(input);
    result = leetCode.evaluateTree(root);
    Logger::WriteMessage("Tree = " + input);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2378(void)
{
    Logger::WriteMessage("Test Leet Code 2378");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { { -1, -1 }, {0, 5},{0, 10},{2, 6},{2, 4} };
    long long result = leetCode.maxScore(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {-1, -1},{0, 5},{0, -6},{0, 7} };
    result = leetCode.maxScore(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2385(void)
{
    Logger::WriteMessage("Test Leet Code 2385");
    LeetCodeTree leetCode;
    string input = "[1,5,3,null,4,10,6,9,2]";
    TreeNode * root = leetCode.deserialize(input);
    int start = 3;
    int result = leetCode.amountOfTime(root, start);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("start = " + to_string(start) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1]";
    root = leetCode.deserialize(input);
    start = 1;
    result = leetCode.amountOfTime(root, start);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("start = " + to_string(start) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2415(void)
{
    Logger::WriteMessage("Test Leet Code 2415");
    LeetCodeTree leetCode;
    string input = "[2,3,5,8,13,21,34]";
    TreeNode* root = leetCode.deserialize(input);
    root = leetCode.reverseOddLevels(root);
    string result = leetCode.serialize(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);

    input = "[7,13,11]";
    root = leetCode.deserialize(input);
    root = leetCode.reverseOddLevels(root);
    result = leetCode.serialize(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);

    input = "[0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]";
    root = leetCode.deserialize(input);
    root = leetCode.reverseOddLevels(root);
    result = leetCode.serialize(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2440(void)
{
    Logger::WriteMessage("Test Leet Code 2440");
    LeetCodeTree leetCode;
    vector<int> nums = { 6, 2, 2, 2, 6 };
    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 3},{3, 4} };
    int result = leetCode.componentValue(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2 };
    edges = { };
    result = leetCode.componentValue(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2445(void)
{
    Logger::WriteMessage("Test Leet Code 2445");
    LeetCodeTree leetCode;
    int n = 5;
    vector<int> queries = { 1, 2, 5 };
    int result = leetCode.numberOfNodes(n, queries);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    queries = { 2, 3, 3 };
    result = leetCode.numberOfNodes(n, queries);
    Logger::WriteMessage(queries);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2471(void)
{
    Logger::WriteMessage("Test Leet Code 2471");
    LeetCodeTree leetCode;
    string input = "[1,4,3,7,6,8,5,null,null,null,null,9,null,10]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.minimumOperations(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,3,2,7,6,5,4]";
    root = leetCode.deserialize(input);
    result = leetCode.minimumOperations(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,4,5,6]";
    root = leetCode.deserialize(input);
    result = leetCode.minimumOperations(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2476(void)
{
    Logger::WriteMessage("Test Leet Code 2476");
    LeetCodeTree leetCode;
    string input = "[6,2,13,1,4,9,15,null,null,null,null,null,null,14]";
    vector<int> queries = { 2,5,16 };
    TreeNode* root = leetCode.deserialize(input);
    vector<vector<int>> result = leetCode.closestNodes(root, queries);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[4,null,9]";
    queries = { 3 };
    root = leetCode.deserialize(input);
    result = leetCode.closestNodes(root, queries);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2458(void)
{
    Logger::WriteMessage("Test Leet Code 2458");
    LeetCodeTree leetCode;
    string input = "[1,3,4,2,null,6,5,null,null,null,null,null,7]";
    vector<int> queries = { 4};
    TreeNode* root = leetCode.deserialize(input);
    vector<int> result = leetCode.treeQueries(root, queries);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);

    input = "[5,8,9,2,1,3,7,4,6]";
    queries = { 3,2,4,8 };
    root = leetCode.deserialize(input);
    result = leetCode.treeQueries(root, queries);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2509(void)
{
    Logger::WriteMessage("Test Leet Code 2509");
    LeetCodeTree leetCode;
    int n = 3;
    vector<vector<int>> queries = { {5, 3},{4, 7},{2, 3} };
    vector<int> result = leetCode.cycleLengthQueries(n, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 2;
    queries = { {1, 2} };
    result = leetCode.cycleLengthQueries(n, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2538(void)
{
    Logger::WriteMessage("Test Leet Code 2538");
    LeetCodeTree leetCode;
    int n = 6;
    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 3},{3, 4},{3, 5} };
    vector<int> price = { 9, 8, 7, 6, 10, 5 };
    Logger::WriteMessage(edges);
    Logger::WriteMessage(price);
    long long result = leetCode.maxOutput(n, edges, price);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    edges = { {0, 1},{1, 2} };
    price = { 1, 1, 1 };
    Logger::WriteMessage(edges);
    Logger::WriteMessage(price);
    result = leetCode.maxOutput(n, edges, price);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2583(void)
{
    Logger::WriteMessage("Test Leet Code 2583");
    LeetCodeTree leetCode;
    string input = "[5,8,9,2,1,3,7,4,6]";
    int k = 2;
    TreeNode* root = leetCode.deserialize(input);
    long long result = leetCode.kthLargestLevelSum(root, k);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,null,3]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.kthLargestLevelSum(root, k);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2581(void)
{
    Logger::WriteMessage("Test Leet Code 2581");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 3},{4, 2} };
    vector<vector<int>> guesses = { {1, 3},{0, 1},{1, 0},{2, 4} };
    int k = 3;
    int result = leetCode.rootCount(edges, guesses, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(guesses);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{1, 2},{2, 3},{3, 4} };
    guesses = { {1, 0},{3, 4},{2, 1},{3, 2} };
    k = 1;
    result = leetCode.rootCount(edges, guesses, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(guesses);
    Logger::WriteMessage("result = " + to_string(result));

    edges =
    {
        {0, 1},{2, 0},{0, 3},{4, 2},{3, 5},{6, 0},
        {1, 7},{2, 8},{2, 9},{4, 10},{9, 11},{3, 12},
        {13, 8},{14, 9},{15, 9},{10, 16}
    };
    guesses = { {8,2} ,{12,3},{0,1},{16,10} };
    k = 2;
    result = leetCode.rootCount(edges, guesses, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(guesses);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2641(void)
{
    Logger::WriteMessage("Test Leet Code 2641");
    LeetCodeTree leetCode;
    string input = "[5,4,9,1,10,null,7]";
    TreeNode* root = leetCode.deserialize(input);
    TreeNode* result = leetCode.replaceValueInTree(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + leetCode.serialize(result));
    leetCode.freeTreeNodes(result);

    input = "[3,1,2]";
    root = leetCode.deserialize(input);
    result = leetCode.replaceValueInTree(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + leetCode.serialize(result));
    leetCode.freeTreeNodes(result);
}

void TestLeetCode2673(void)
{
    Logger::WriteMessage("Test Leet Code 2673");
    LeetCodeTree leetCode;
    int n = 7;
    vector<int> cost = { 1, 5, 2, 2, 3, 3, 1 };
    int result = leetCode.minIncrements(n, cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    cost = { 5, 3, 3 };
    result = leetCode.minIncrements(n, cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2764(void)
{
    Logger::WriteMessage("Test Leet Code 2764");
    LeetCodeTree leetCode;
    vector<vector<int>> nodes = 
    { 
        {0, -1},{1, 0},{2, 0},{3, 2},{4, 2} 
    };
    bool result = leetCode.isPreorder(nodes);
    Logger::WriteMessage(nodes);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nodes =
    {
        {0,-1},{1,0},{2,0},{3,1},{4,1}
    };
    result = leetCode.isPreorder(nodes);
    Logger::WriteMessage(nodes);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2773(void)
{
    Logger::WriteMessage("Test Leet Code 2773");
    LeetCodeTree leetCode;
    string input = "[1,2,3,null,null,4,5]";
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.heightOfTree(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2]";
    root = leetCode.deserialize(input);
    result = leetCode.heightOfTree(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,null,null,4,null,5,6]";
    root = leetCode.deserialize(input);
    result = leetCode.heightOfTree(root);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2791(void)
{
    Logger::WriteMessage("Test Leet Code 2791");
    LeetCodeTree leetCode;
    vector<int> parent = { -1, 0, 0, 1, 1, 2 }; 
    string s = "acaabc";
    long long result = leetCode.countPalindromePaths(parent, s);
    Logger::WriteMessage(parent);
    Logger::WriteMessage("result = " + to_string(result));

    s = { -1, 0, 0, 0, 0 };
    s = "aaaaa";
    result = leetCode.countPalindromePaths(parent, s);
    Logger::WriteMessage(parent);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode589(void)
{
    Logger::WriteMessage("Test Leet Code 589");
    LeetCodeTree leetCode;
    NaryTreeCodec  treeCodec;
    string input = "[1 [3[5 6] 2 4]]";
    Logger::WriteMessage(input);
    Node* root = treeCodec.deserialize(input);
    vector<int> result = leetCode.preorder(root);
    Logger::WriteMessage(result);
    leetCode.freeNodes(root);
}

void TestLeetCode2793(void)
{
    Logger::WriteMessage("Test Leet Code 2793");
    LeetCodeTree leetCode;
    string input = "[7,6,5,4,3,2,1]";
    int k = 2;
    TreeNode *root = leetCode.deserialize(input);
    int result = leetCode.countGreatEnoughNodes(root, k);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.countGreatEnoughNodes(root, k);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[3,2,2]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.countGreatEnoughNodes(root, k);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode2846(void)
{
    Logger::WriteMessage("Test Leet Code 2846");
    LeetCodeTree leetCode;
    int n = 7; 
    vector<vector<int>> edges =
    { 
        {0, 1, 1},{1, 2, 1},{2, 3, 1},{3, 4, 2},{4, 5, 2},{5, 6, 2} 
    };
    vector<vector<int>> queries = { {0, 3},{3, 6},{2, 6},{0, 6} };
    vector<int> result = leetCode.minOperationsQueries(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 8;
    edges =
    {
        {1,2,6} ,{1,3,4}, {2,4,6}, {2,5,3}, {3,6,6}, {3,0,8}, {7,0,2}
    };
    queries = { {4,6} ,{0,4},{6,5},{7,4} };
    result = leetCode.minOperationsQueries(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode2920(void)
{
    Logger::WriteMessage("Test Leet Code 2920");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1},{1, 2},{2, 3} };
    vector<int> coins = { 10, 10, 3, 3 };
    int k = 5;
    int result = leetCode.maximumPoints(edges, coins, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    edges = { {0, 1},{0, 2} };
    coins = { 8,4,4 };
    k = 0;
    result = leetCode.maximumPoints(edges, coins, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    edges = { {0, 1}, { 0, 2 }, { 1, 3 }, { 3, 4 }, { 0, 5 }, { 6, 3 }, { 5, 7 }, { 3, 8 }, { 9, 7 } };
    coins = { 0,5,10,5,6,5,0,2,0,0 };
    k = 7;
    result = leetCode.maximumPoints(edges, coins, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(coins);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2925(void)
{
    Logger::WriteMessage("Test Leet Code 2925");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1} ,{0, 2},{0, 3},{2, 4},{4, 5} };
    vector<int> values = { 5, 2, 5, 2, 1, 1 };
    long long result = leetCode.maximumScoreAfterOperations(edges, values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(values);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0,1} ,{0,2},{1,3},{1,4},{2,5},{2,6} };
    values = { 20,10,9,7,4,3,5 };
    result = leetCode.maximumScoreAfterOperations(edges, values);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(values);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3004(void)
{
    Logger::WriteMessage("Test Leet Code 3004");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1},{0, 2},{0, 3} };
    vector<int> colors = { 1, 1, 2, 3 };
    int result = leetCode.maximumSubtreeSize(edges, colors);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(colors);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{0, 2},{0, 3} };
    colors = { 1, 1, 1, 1 };
    result = leetCode.maximumSubtreeSize(edges, colors);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(colors);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{0, 2},{2, 3},{2, 4} };
    colors = { 1, 2, 3, 3, 3 };
    result = leetCode.maximumSubtreeSize(edges, colors);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(colors);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3068(void)
{
    Logger::WriteMessage("Test Leet Code 3068");
    LeetCodeTree leetCode;
    vector<int> nums = { 1, 2, 1 };
    int k = 3; 
    vector<vector<int>> edges = { {0, 1},{0, 2} };
    long long result = leetCode.maximumValueSum(nums, k, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 2, 3 };
    k = 7;
    edges = { {0, 1} };
    result = leetCode.maximumValueSum(nums, k, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 7,7,7,7,7,7 };
    k = 3;
    edges = { {0, 1},{0, 2},{0, 3},{0, 4},{0, 5} };
    result = leetCode.maximumValueSum(nums, k, edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3157(void)
{
    Logger::WriteMessage("Test Leet Code 3157");
    LeetCodeTree leetCode;
    string input = "[50,6,2,30,80,7]";
    TreeNode * root = leetCode.deserialize(input);
    int result = leetCode.minimumSumLevel(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[36,17,10,null,null,24]";
    root = leetCode.deserialize(input);
    result = leetCode.minimumSumLevel(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[5,null,5,null,5]";
    root = leetCode.deserialize(input);
    result = leetCode.minimumSumLevel(root);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode3203(void)
{
    Logger::WriteMessage("Test Leet Code 3203");
    LeetCodeTree leetCode;
    vector<vector<int>> edges1 = { {0, 1},{0, 2},{0, 3} };
    vector<vector<int>> edges2 = { {0, 1} };
    int result = leetCode.minimumDiameterAfterMerge(edges1, edges2);
    Logger::WriteMessage(edges1);
    Logger::WriteMessage(edges2);
    Logger::WriteMessage("result = " + to_string(result));

    edges1 = { {0, 1},{0, 2},{0, 3},{2, 4},{2, 5},{3, 6},{2, 7} };
    edges2 = { {0, 1},{0, 2},{0, 3},{2, 4},{2, 5},{3, 6},{2, 7} };
    result = leetCode.minimumDiameterAfterMerge(edges1, edges2);
    Logger::WriteMessage(edges1);
    Logger::WriteMessage(edges2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3241(void)
{
    Logger::WriteMessage("Test Leet Code 3241");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1},{0, 2} };
    vector<int> result = leetCode.timeTaken(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { {0,1} };
    result = leetCode.timeTaken(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { {2, 4},{0, 1},{2, 3},{0, 2} };
    result = leetCode.timeTaken(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { {1, 0},{2, 1},{3, 1},{4, 3} };
    result = leetCode.timeTaken(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode3249(void)
{
    Logger::WriteMessage("Test Leet Code 3249");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{2, 6} };
    int result = leetCode.countGoodNodes(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{1, 2},{2, 3},{3, 4},{0, 5},{1, 6},{2, 7},{3, 8} };
    result = leetCode.countGoodNodes(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{1, 2},{1, 3},{1, 4},{0, 5},{5, 6},{6, 7},{7, 8},{0, 9},{9, 10},{9, 12},{10, 11} };
    result = leetCode.countGoodNodes(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3313(void)
{
    Logger::WriteMessage("Test Leet Code 3313");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0,1} ,{0,2} };
    vector<int> result = leetCode.lastMarkedNodes(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { {0,1} };
    result = leetCode.lastMarkedNodes(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    edges = { {0, 1},{0, 2},{2, 3},{2, 4} };
    result = leetCode.lastMarkedNodes(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode3319(void)
{
    Logger::WriteMessage("Test Leet Code 3319");
    LeetCodeTree leetCode;
    string input = "[5,3,6,5,2,5,7,1,8,null,null,6,8]";
    int k = 2;
    TreeNode* root = leetCode.deserialize(input);
    int result = leetCode.kthLargestPerfectSubtree(root, k);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,4,5,6,7]";
    k = 1;
    root = leetCode.deserialize(input);
    result = leetCode.kthLargestPerfectSubtree(root, k);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);

    input = "[1,2,3,null,4]";
    k = 3;
    root = leetCode.deserialize(input);
    result = leetCode.kthLargestPerfectSubtree(root, k);
    Logger::WriteMessage(input);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeTreeNodes(root);
}

void TestLeetCode3331(void)
{
    Logger::WriteMessage("Test Leet Code 3331");
    LeetCodeTree leetCode;
    vector<int> parent = { -1, 0, 0, 1, 1, 1 };
    string s = "abaabc";
    vector<int> result = leetCode.findSubtreeSizes(parent, s);
    Logger::WriteMessage(parent);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    parent = { -1,0,4,0,1 };
    s = "abbba";
    result = leetCode.findSubtreeSizes(parent, s);
    Logger::WriteMessage(parent);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);
}

void TestLeetCode3372(void)
{
    Logger::WriteMessage("Test Leet Code 3372");
    LeetCodeTree leetCode;
    vector<vector<int>> edges1 = { {0, 1},{0, 2},{2, 3},{2, 4} };
    vector<vector<int>> edges2 = { {0, 1},{0, 2},{0, 3},{2, 7},{1, 4},{4, 5},{4, 6} };
    int k = 2;
    vector<int> result = leetCode.maxTargetNodesI(edges1, edges2, k);
    Logger::WriteMessage(edges1);
    Logger::WriteMessage(edges2);
    Logger::WriteMessage("k = " + k);
    Logger::WriteMessage(result);

    edges1 = { {0, 1},{0, 2},{0, 3},{0, 4} }; 
    edges2 = { {0, 1},{1, 2},{2, 3} };
    k = 1;
    result = leetCode.maxTargetNodesI(edges1, edges2, k);
    Logger::WriteMessage(edges1);
    Logger::WriteMessage(edges2);
    Logger::WriteMessage("k = " + k);
    Logger::WriteMessage(result);
}

void TestLeetCode3373(void)
{
    Logger::WriteMessage("Test Leet Code 3373");
    LeetCodeTree leetCode;
    vector<vector<int>> edges1 = { {0, 1},{0, 2},{2, 3},{2, 4} };
    vector<vector<int>> edges2 = { {0, 1},{0, 2},{0, 3},{2, 7},{1, 4},{4, 5},{4, 6} };
    vector<int> result = leetCode.maxTargetNodesII(edges1, edges2);
    Logger::WriteMessage(edges1);
    Logger::WriteMessage(edges2);
    Logger::WriteMessage(result);

    edges1 = { {0, 1},{0, 2},{0, 3},{0, 4} };
    edges2 = { {0, 1},{1, 2},{2, 3} };
    result = leetCode.maxTargetNodesII(edges1, edges2);
    Logger::WriteMessage(edges1);
    Logger::WriteMessage(edges2);
    Logger::WriteMessage(result);
}

void TestLeetCode3367(void)
{
    Logger::WriteMessage("Test Leet Code 3367");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1, 4},{0, 2, 2},{2, 3, 12},{2, 4, 6} };
    int k = 2;
    long long result = leetCode.maximizeSumOfWeights(edges, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    edges = { {0, 1, 5},{1, 2, 10},{0, 3, 15},{3, 4, 20},{3, 5, 5},{0, 6, 10} };
    k = 3;
    result = leetCode.maximizeSumOfWeights(edges, k);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode3425(void)
{
    Logger::WriteMessage("Test Leet Code 3425");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1, 2},{1, 2, 3},{1, 3, 5},{1, 4, 4},{2, 5, 6} };
    vector<int> nums = { 2, 1, 2, 1, 3, 1 };
    vector<int> result = leetCode.longestSpecialPath(edges, nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    edges = { {1, 0, 8} };
    nums = { 2, 2 };
    result = leetCode.longestSpecialPath(edges, nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    edges = { {1, 0, 5},{0, 2, 10} };
    nums = { 3,3,5 };
    result = leetCode.longestSpecialPath(edges, nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode3486(void)
{
    Logger::WriteMessage("Test Leet Code 3486");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = 
    { 
        {0, 1, 1},{1, 2, 3},{1, 3, 1},
        {2, 4, 6},{4, 7, 2},{3, 5, 2},
        {3, 6, 5},{6, 8, 3} 
    };
    vector<int> nums = { 1,1,0,3,1,2,1,1,0 };
    vector<int> result = leetCode.longestSpecialPathII(edges, nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    edges = { {1, 0, 3},{0, 2, 4},{0, 3, 5} };
    nums = { 1, 1, 0, 2 };
    result = leetCode.longestSpecialPathII(edges, nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    edges = { {2, 0, 6},{0, 1, 3},{1, 3, 7} };
    nums = { 4, 1, 4, 1 };
    result = leetCode.longestSpecialPathII(edges, nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode3515(void)
{
    Logger::WriteMessage("Test Leet Code 3515");
    LeetCodeTree leetCode;
    int n = 2;
    vector<vector<int>> edges = { {1, 2, 7} };
    vector<vector<int>> queries = { {2, 2},{1, 1, 2, 4},{2, 2} };
    vector<int> result = leetCode.treeQueries(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 3; 
    edges = { {1, 2, 2},{1, 3, 4} };
    queries = { {2, 1},{2, 3},{1, 1, 3, 7},{2, 2},{2, 3} };
    result = leetCode.treeQueries(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 4;
    edges = { {1, 2, 2},{2, 3, 1},{3, 4, 5} };
    queries = { {2, 4},{2, 3},{1, 2, 3, 3},{2, 2},{2, 3} };
    result = leetCode.treeQueries(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 4;
    edges = { {1, 2, 2},{4, 2, 3},{1, 3, 4} };
    queries = { {2, 2},{1, 3, 1, 1},{2, 3} };
    result = leetCode.treeQueries(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3544(void)
{
    Logger::WriteMessage("Test Leet Code 3544");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{2, 6} };
    vector<int> nums = { 4, -8, -6, 3, 7, -2, 5 };
    int k = 2;
    long long result = leetCode.subtreeInversionSum(edges, nums, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{1, 2},{2, 3},{3, 4} };
    nums = { -1,3,-2,4,-5 };
    k = 2;
    result = leetCode.subtreeInversionSum(edges, nums, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {0, 1},{0, 2} };
    nums = { 0,-1,-2 };
    k = 3;
    result = leetCode.subtreeInversionSum(edges, nums, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3553(void)
{
    Logger::WriteMessage("Test Leet Code 3553");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {0, 1, 2},{1, 2, 3},{1, 3, 5},{1, 4, 4},{2, 5, 6} };
    vector<vector<int>> queries = { {2, 3, 4},{0, 2, 5} };
    vector<int> result = leetCode.minimumWeight(edges, queries);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    edges = { {1, 0, 8},{0, 2, 7} };
    queries = { {0, 1, 2} };
    result = leetCode.minimumWeight(edges, queries);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3558(void)
{
    Logger::WriteMessage("Test Leet Code 3558");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {1, 2} };
    int result = leetCode.assignEdgeWeightsI(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));

    edges = { {1, 2},{1, 3},{3, 4},{3, 5} };
    result = leetCode.assignEdgeWeightsI(edges);
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3559(void)
{
    Logger::WriteMessage("Test Leet Code 3559");
    LeetCodeTree leetCode;
    vector<vector<int>> edges = { {1, 2} };
    vector<vector<int>> queries = { {1, 1},{1, 2} };
    vector<int> result = leetCode.assignEdgeWeightsII(edges, queries);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    edges = { {1, 2},{1, 3},{3, 4},{3, 5} };
    queries = { {1, 4},{3, 4},{2, 5} };
    result = leetCode.assignEdgeWeightsII(edges, queries);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3562(void)
{
    Logger::WriteMessage("Test Leet Code 3562");
    LeetCodeTree leetCode;
    int n = 2;
    vector<int> present = { 1, 2 };
    vector<int> future = { 4, 3 };
    vector<vector<int>> hierarchy = { {1, 2} };
    int budget = 3;
    int result = leetCode.maxProfit(n, present, future, hierarchy, budget);
    Logger::WriteMessage("n = " + to_string(n) + "; budget = " + to_string(budget));
    Logger::WriteMessage(present);
    Logger::WriteMessage(future);
    Logger::WriteMessage(hierarchy);
    Logger::WriteMessage("result = " + to_string(result));

    n = 2;
    present = { 3, 4 };
    future = { 5, 8 };
    hierarchy = { {1, 2} };
    budget = 4;
    result = leetCode.maxProfit(n, present, future, hierarchy, budget);
    Logger::WriteMessage("n = " + to_string(n) + "; budget = " + to_string(budget));
    Logger::WriteMessage(present);
    Logger::WriteMessage(future);
    Logger::WriteMessage(hierarchy);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3;
    present = { 4, 6, 8 };
    future = { 7, 9, 11 };
    hierarchy = { {1, 2},{1, 3} };
    budget = 10;
    result = leetCode.maxProfit(n, present, future, hierarchy, budget);
    Logger::WriteMessage("n = " + to_string(n) + "; budget = " + to_string(budget));
    Logger::WriteMessage(present);
    Logger::WriteMessage(future);
    Logger::WriteMessage(hierarchy);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3;
    present = { 5, 2, 3 };
    future = { 8, 5, 6 };
    hierarchy = { {1, 2},{2, 3} };
    budget = 7;
    result = leetCode.maxProfit(n, present, future, hierarchy, budget);
    Logger::WriteMessage("n = " + to_string(n) + "; budget = " + to_string(budget));
    Logger::WriteMessage(present);
    Logger::WriteMessage(future);
    Logger::WriteMessage(hierarchy);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3;
    present = { 6,4,23 };
    future = { 50,48,17 };
    hierarchy = { {1, 3},{1, 2} };
    budget = 28;
    result = leetCode.maxProfit(n, present, future, hierarchy, budget);
    Logger::WriteMessage("n = " + to_string(n) + "; budget = " + to_string(budget));
    Logger::WriteMessage(present);
    Logger::WriteMessage(future);
    Logger::WriteMessage(hierarchy);
    Logger::WriteMessage("result = " + to_string(result));

    n = 7;
    present = { 1, 17, 24, 21, 2, 10, 1 };
    future = { 29,9,45,8,12,50,14 };
    hierarchy = { {1, 3},{1, 7},{3, 4},{3, 2},{3, 6},{3, 5} };
    budget = 11;
    result = leetCode.maxProfit(n, present, future, hierarchy, budget);
    Logger::WriteMessage("n = " + to_string(n) + "; budget = " + to_string(budget));
    Logger::WriteMessage(present);
    Logger::WriteMessage(future);
    Logger::WriteMessage(hierarchy);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3575(void)
{
    Logger::WriteMessage("Test Leet Code 3575");
    LeetCodeTree leetCode;
    vector<int> vals = { 2, 3 };
    vector<int> par = { -1, 0 };
    int result = leetCode.goodSubtreeSum(vals, par);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(par);
    Logger::WriteMessage("result = " + to_string(result));

    vals = { 1,5,2 };
    par = { -1,0,0 };
    result = leetCode.goodSubtreeSum(vals, par);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(par);
    Logger::WriteMessage("result = " + to_string(result));

    vals = { 34,1,2 };
    par = { -1,0,1 };
    result = leetCode.goodSubtreeSum(vals, par);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(par);
    Logger::WriteMessage("result = " + to_string(result));

    vals = { 3, 22, 5 };
    par = { -1,0,1 };
    result = leetCode.goodSubtreeSum(vals, par);
    Logger::WriteMessage(vals);
    Logger::WriteMessage(par);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3585(void)
{
    Logger::WriteMessage("Test Leet Code 3585");
    LeetCodeTree leetCode;
    int n = 2;
    vector<vector<int>> edges = { {0, 1, 7} };
    vector<vector<int>> queries = { {1, 0},{0, 1} };
    vector<int> result = leetCode.findMedian(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 3; 
    edges = { {0, 1, 2},{2, 0, 4} };
    queries = { {0, 1},{2, 0},{1, 2} };
    result = leetCode.findMedian(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 5; 
    edges = { {0, 1, 2},{0, 2, 5},{1, 3, 1},{2, 4, 3} };
    queries = { {3, 4},{1, 2} };
    result = leetCode.findMedian(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 5;
    edges = { {0, 1, 2},{0, 2, 2},{1, 3, 1},{2, 4, 5} };
    queries = { {3, 4},{1, 2} };
    result = leetCode.findMedian(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 2;
    edges = { {0, 1, 1} };
    queries = { {0, 1} };
    result = leetCode.findMedian(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);

    n = 5;
    edges = { {0, 1, 16},{0, 2, 17}, {1, 3, 1 },{3, 4, 2} };
    queries = { {1, 0},{2, 4} };
    result = leetCode.findMedian(n, edges, queries);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode3593(void)
{
    Logger::WriteMessage("Test Leet Code 3593");
    LeetCodeTree leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{0, 2} };
    vector<int> cost = { 2, 1, 3 };
    int result = leetCode.minIncrease(n, edges, cost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3;
    edges = { {0, 1},{1, 2} };
    cost = { 5, 1, 4 };
    result = leetCode.minIncrease(n, edges, cost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 5;
    edges = { {0, 4},{0, 1},{1, 2},{1, 3} };
    cost = { 3, 4, 1, 1, 7 };
    result = leetCode.minIncrease(n, edges, cost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    n = 4;
    edges = { {0, 1}, { 1, 2 }, { 1, 3 } };
    cost = { 13,7,9,4 };
    result = leetCode.minIncrease(n, edges, cost);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3772(void)
{
    Logger::WriteMessage("Test Leet Code 3772");
    LeetCodeTree leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{1, 2} };
    vector<int> good = { 1, 0, 1 };
    vector<int> result = leetCode.maxSubgraphScore(n, edges, good);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(good);
    Logger::WriteMessage(result);

    n = 5;
    edges = { {1, 0},{1, 2},{1, 3},{3, 4} };
    good = { 0, 1, 0, 1, 1 };
    result = leetCode.maxSubgraphScore(n, edges, good);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(good);
    Logger::WriteMessage(result);

    n = 2; 
    edges = { {0, 1} };
    good = { 0, 0 };
    result = leetCode.maxSubgraphScore(n, edges, good);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(good);
    Logger::WriteMessage(result);
}

void TestLeetCode3786(void)
{
    Logger::WriteMessage("Test Leet Code 3786");
    LeetCodeTree leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{1, 2} };
    vector<int> group = { 1, 1, 1 };
    long long result = leetCode.interactionCosts(n, edges, group);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(group);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3;
    edges = { {0, 1},{1, 2} };
    group = { 3, 2, 3 };
    result = leetCode.interactionCosts(n, edges, group);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(group);
    Logger::WriteMessage("result = " + to_string(result));

    n = 4;
    edges = { {0, 1},{0, 2},{0, 3} };
    group = { 1, 1, 4, 4 };
    result = leetCode.interactionCosts(n, edges, group);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(group);
    Logger::WriteMessage("result = " + to_string(result));

    n = 2;
    edges = { {0, 1} };
    group = { 9, 8 };
    result = leetCode.interactionCosts(n, edges, group);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage(group);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3787(void)
{
    Logger::WriteMessage("Test Leet Code 3787");
    LeetCodeTree leetCode;
    int n = 3;
    vector<vector<int>> edges = { {0, 1},{1, 2} };
    string result = leetCode.findSpecialNodes(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + result);

    n = 7;
    edges = { {0, 1},{1, 2},{2, 3},{3, 4},{3, 5},{1, 6} };
    result = leetCode.findSpecialNodes(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + result);

    n = 2; 
    edges = { {0, 1} };
    result = leetCode.findSpecialNodes(n, edges);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(edges);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCodeTree(void)
{
    TestLeetCode3787();
    TestLeetCode3786();
    TestLeetCode3772();
    TestLeetCode3593();
    TestLeetCode3585();
    TestLeetCode3575();
    TestLeetCode3562();
    TestLeetCode3559();
    TestLeetCode3558();
    TestLeetCode3553();
    TestLeetCode3544();
    TestLeetCode3515();
    TestLeetCode3486();
    TestLeetCode3425();
    TestLeetCode3367();
    TestLeetCode3373();
    TestLeetCode3372();
    TestLeetCode3331();
    TestLeetCode3319();
    TestLeetCode3313();
    TestLeetCode3249();
    TestLeetCode3241();
    TestLeetCode3203();
    TestLeetCode3157();
    TestLeetCode3068();
    TestLeetCode3004();
    TestLeetCode2925();
    TestLeetCode2920();
    TestLeetCode2846();
    TestLeetCode2793();
    TestLeetCode2791();
    TestLeetCode2773();
    TestLeetCode2764();
    TestLeetCode2673();
    TestLeetCode2641();
    TestLeetCode2581();
    TestLeetCode2583();
    TestLeetCode2538();
    TestLeetCode2509();
    TestLeetCode2458();
    TestLeetCode2476();
    TestLeetCode2471();
    TestLeetCode2445();
    TestLeetCode2440();
    TestLeetCode2415();
    TestLeetCode2385();
    TestLeetCode2378();
    TestLeetCode2331();
    TestLeetCode2313();
    TestLeetCode2277();
    TestLeetCode2246();
    TestLeetCode2265();
    TestLeetCode2236();
    TestLeetCode2196();
    TestLeetCode1973();
    TestLeetCode2096();
    TestLeetCode1676();
    TestLeetCode1650();
    TestLeetCode1902();
    TestLeetCode1644();
    TestLeetCode333();
    TestLeetCode1597();
    TestLeetCode1932();
    TestLeetCode1740();
    TestLeetCode1666();
    TestLeetCode1516();
    TestLeetCode1522();
    TestLeetCode1602();
    TestLeetCode1612();
    TestLeetCode1609();
    TestLeetCode1530();
    TestLeetCode1519();
    TestLeetCode1469();
    TestLeetCode1457();
    TestLeetCode742();
    TestLeetCode653();
    TestLeetCode863();
    TestLeetCode563();
    TestLeetCode272();
    TestLeetCode572();
    TestLeetCode872();
    TestLeetCode270();
    TestLeetCode549();
    TestLeetCode637();
    TestLeetCode783();
    TestLeetCode666();
    TestLeetCode543();
    TestLeetCode545();
    TestLeetCode687();
    TestLeetCode663();
    TestLeetCode700();
    TestLeetCode814();
    TestLeetCode654();
    TestLeetCode652();
    TestLeetCode589();
    TestLeetCode297();
    TestLeetCode776();
    TestLeetCode623();
    TestLeetCode617();
    TestLeetCode538();
    TestLeetCode865();
    TestLeetCode671();
    TestLeetCode669();
    TestLeetCode95();
    TestLeetCode662();
    TestLeetCode606();
    TestLeetCode998();
    TestLeetCode897();
    TestLeetCode701();
    TestLeetCode951();
    TestLeetCode298();
    TestLeetCode993();
    TestLeetCode965();
    TestLeetCode429();
    TestLeetCode979();
    TestLeetCode559();
    TestLeetCode590();
    TestLeetCode431();
    TestLeetCode428();
    TestLeetCode968();
    TestLeetCode958();
    TestLeetCode889();
    TestLeetCode971();
    TestLeetCode894();
    TestLeetCode938();
    TestLeetCode510();
    TestLeetCode988();
    TestLeetCode426();
    TestLeetCode987();
    TestLeetCode230();
    TestLeetCode124();
    TestLeetCode513();
    TestLeetCode508();
    TestLeetCode501();
    TestLeetCode530();
    TestLeetCode515();
    TestLeetCode437();
    TestLeetCode337();
    TestLeetCode536();
    TestLeetCode366();
    TestLeetCode450();
    TestLeetCode404();
    TestLeetCode250();
    TestLeetCode285();
    TestLeetCode156();
    TestLeetCode255();
    TestLeetCode314();
    TestLeetCode1008();
    TestLeetCode1022();
    TestLeetCode1026();
    TestLeetCode1080();
    TestLeetCode1028();
    TestLeetCode1104();
    TestLeetCode1161();
    TestLeetCode1120();
    TestLeetCode1123();
    TestLeetCode1110();
    TestLeetCode1145();
    TestLeetCode1038();
    TestLeetCode103();
    TestLeetCode655();
    TestLeetCode99();
    TestLeetCode113();
    TestLeetCode129();
    TestLeetCode111();
    TestLeetCode236();
    TestLeetCode98();
    TestLeetCode110();
    TestLeetCode199();
    TestLeetCode226();
    TestLeetCode112();
    TestLeetCode104();
    TestLeetCode257();
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
