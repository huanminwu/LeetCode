#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeLinkedList.h"
#include "TestLinkedList.h"

void TestLeetCode2(void)
{
    LeetCodeLinkedList leetCode;
    Logger::WriteMessage("Test Leet Code 2");
    int first_data[3] = { 2, 4, 3 };
    vector<int> data_list;
    for (size_t i = 0; i < sizeof(first_data) / sizeof(first_data[0]); i++)
    {
        data_list.push_back(first_data[i]);
    }
    ListNode* first = leetCode.generateListNodes(data_list);
    int second_data[3] = { 9, 8, 7 };
    data_list.clear();
    for (size_t i = 0; i < sizeof(second_data) / sizeof(second_data[0]); i++)
    {
        data_list.push_back(second_data[i]);
    }
    ListNode* second = leetCode.generateListNodes(data_list);
    ListNode* result_list = leetCode.addTwoNumbers(first, second);

    Logger::WriteMessage(first);
    Logger::WriteMessage(second);
    Logger::WriteMessage(result_list);

    leetCode.freeListNodes(first);
    leetCode.freeListNodes(second);
    leetCode.freeListNodes(result_list);
}

void TestLeetCode24(void)
{
    Logger::WriteMessage("Test Leet Code 24");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    ListNode* list = leetCode.generateListNodes(data);
    Logger::WriteMessage(list);
    ListNode* new_list = leetCode.swapPairs(list);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}
void TestLeetCode138(void)
{
    Logger::WriteMessage("Test Leet Code 138");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1,2,3,4,5,6,7 };
    RandomListNode* head = leetCode.generateRandomListNodes(nums);
    Logger::WriteMessage(head);
    RandomListNode* new_head = leetCode.copyRandomList(head);
    Logger::WriteMessage(new_head);
    leetCode.freeRandomListNodes(head);
    leetCode.freeRandomListNodes(new_head);
}

void TestLeetCode23(void)
{
    Logger::WriteMessage("Test Leet Code 23");
    LeetCodeLinkedList leetCode;
  
    vector<vector<int>> test =
    {
        { -1, -1, -1 },{ -2, -2, -1 }
    };
    vector<ListNode*> list;
    for (size_t i = 0; i < test.size(); i++)
    {
        ListNode* start = leetCode.generateListNodes(test[i]);
        list.push_back(start);
    }

    ListNode* result = leetCode.mergeKLists(list);
    Logger::WriteMessage(test);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);

    test =
    {
        { 1, 4, 5 },{ 1, 3, 4 }, {2, 6}
    };

    list.clear();
    for (size_t i = 0; i < test.size(); i++)
    {
        ListNode* start = leetCode.generateListNodes(test[i]);
        list.push_back(start);
    }

    result = leetCode.mergeKLists(list);
    Logger::WriteMessage(test);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);
}

void TestLeetCode25(void)
{
    Logger::WriteMessage("Test Leet Code 25");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data_list = { 1, 2, 3, 4, 5, 6, 7 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* reverse_list = leetCode.reverseKGroup(list, 3);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);

    data_list = { 1,2,3,4,5, 6, 7 };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    reverse_list = leetCode.reverseKGroup(list, 4);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);

    data_list = { 1,2,3,4,5, 6, 7 };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    reverse_list = leetCode.reverseKGroup(list, 1);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);

    data_list = { };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    reverse_list = leetCode.reverseKGroup(list, 2);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);
}

void TestLeetCode19(void)
{
    Logger::WriteMessage("Test Leet Code 19");
    LeetCodeLinkedList leetCode;
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    ListNode* list = leetCode.generateListNodes(data);
    Logger::WriteMessage(list);
    int n = 2;
    Logger::WriteMessage("n = " + to_string(n));
    ListNode* new_list = leetCode.removeNthFromEnd(list, 2);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);

    data = { 1, 2 };
    list = leetCode.generateListNodes(data);
    Logger::WriteMessage(list);
    n = 2;
    Logger::WriteMessage("n = " + to_string(n));
    new_list = leetCode.removeNthFromEnd(list, 2);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}

void TestLeetCode21(void)
{
    Logger::WriteMessage("Test Leet Code 21");
    LeetCodeLinkedList leetCode;
    vector<vector<int>> test =
    {
        { -1, -1, -1 }, { -2, -2, -1 }
    };
    vector<ListNode*> list;
    for (size_t i = 0; i < test.size(); i++)
    {
        ListNode* start = leetCode.generateListNodes(test[i]);
        list.push_back(start);
    }

    ListNode* result = leetCode.mergeTwoLists(list[0], list[1]);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);
}

void TestLeetCode148(void)
{
    Logger::WriteMessage("Test Leet Code 148");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 2, 1, 3, 9, 4, 5, 7, 8, 6, 0 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    head = leetCode.sortList(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);
}

void TestLeetCode1265(void)
{
    Logger::WriteMessage("Test Leet Code 1265");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    vector<int> result = leetCode.printLinkedListInReverse(head);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(head);
}

void TestLeetCode1290(void)
{
    Logger::WriteMessage("Test Leet Code 1290");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1, 0, 1 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    int result = leetCode.getDecimalValue(head);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(head);

    nums = { 0 };
    head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    result = leetCode.getDecimalValue(head);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(head);

    nums = { 1 };
    head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    result = leetCode.getDecimalValue(head);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(head);

    nums = { 1,0,0,1,0,0,1,1,1,0,0,0,0,0,0 };
    head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    result = leetCode.getDecimalValue(head);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(head);

    nums = { 0,0 };
    head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    result = leetCode.getDecimalValue(head);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(head);
}

void TestLeetCode1019(void)
{
    Logger::WriteMessage("Test Leet Code 1019");
    LeetCodeLinkedList leetCode;
    vector<int> data_list = { 2,1,5 };
    ListNode* list = leetCode.generateListNodes(data_list);
    vector<int> result = leetCode.nextLargerNodes(list);
    Logger::WriteMessage(list);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(list);

    data_list = { 2,7,4,3,5 };
    list = leetCode.generateListNodes(data_list);
    result = leetCode.nextLargerNodes(list);
    Logger::WriteMessage(list);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(list);

    data_list = { 1,7,5,1,9,2,5,1 };
    list = leetCode.generateListNodes(data_list);
    result = leetCode.nextLargerNodes(list);
    Logger::WriteMessage(list);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(list);
}

void TestLeetCode1171(void)
{
    Logger::WriteMessage("Test Leet Code 1171");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data_list = { 1,2,-3,3,1 };
    ListNode* head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.removeZeroSumSublists(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    data_list = { 1,2,3,-3,4 };
    head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.removeZeroSumSublists(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    data_list = { 1,2,3,-3,-2 };
    head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.removeZeroSumSublists(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);
}

void TestLeetCode817(void)
{
    Logger::WriteMessage("Test Leet Code 817");
    LeetCodeLinkedList leetCode;
    vector<int> data = { 0, 1, 2, 3 };
    ListNode* list = leetCode.generateListNodes(data);
    vector<int> G = { 0, 1, 3 };
    int result = leetCode.numComponents(list, G);
    Logger::WriteMessage(list);
    Logger::WriteMessage(G);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(list);

    data = { 0, 1, 2, 3, 4 };
    list = leetCode.generateListNodes(data);
    G = { 0, 3, 1, 4 };
    result = leetCode.numComponents(list, G);
    Logger::WriteMessage(list);
    Logger::WriteMessage(G);
    Logger::WriteMessage("result = " + to_string(result));
    leetCode.freeListNodes(list);
}

void TestLeetCode876(void)
{
    Logger::WriteMessage("Test Leet Code 876");
    LeetCodeLinkedList leetCode;
    vector<int> data = { 1,2,3,4,5 };
    ListNode* head = leetCode.generateListNodes(data);
    ListNode* result = leetCode.middleNode(head);
    Logger::WriteMessage(head);
    Logger::WriteMessage("result = " + to_string(result->val));
    leetCode.freeListNodes(head);

    data = { 1,2,3,4,5,6 };
    head = leetCode.generateListNodes(data);
    result = leetCode.middleNode(head);
    Logger::WriteMessage(head);
    Logger::WriteMessage("result = " + to_string(result->val));
    leetCode.freeListNodes(head);
}

void TestLeetCode708(void)
{
    Logger::WriteMessage("Test Leet Code 708");
    LeetCodeLinkedList leetCode;
    vector<int> input = { 3, 5,  2 };
    Logger::WriteMessage(input);
    ListNode* head = leetCode.generateCyclicListNodes(input);
    int value = 6;
    head = leetCode.insert(head, value);
    vector<int> result = leetCode.outputCyclicListNodes(head);
    Logger::WriteMessage(result);

    value = 1;
    head = leetCode.insert(head, value);
    result = leetCode.outputCyclicListNodes(head);
    Logger::WriteMessage(result);
    leetCode.freeCyclicListNodes(head);
}

void TestLeetCode725(void)
{
    LeetCodeLinkedList leetCode;

    vector<int> data_list = { 1, 2, 3 };
    int k = 5;
    ListNode* list = leetCode.generateListNodes(data_list);
    vector<ListNode*> result = leetCode.splitListToParts(list, k);
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
        leetCode.freeListNodes(result[i]);
        result[i] = nullptr;
    }
    data_list = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    k = 3;
    list = leetCode.generateListNodes(data_list);
    result = leetCode.splitListToParts(list, k);
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
        leetCode.freeListNodes(result[i]);
        result[i] = nullptr;
    }
}

void TestLeetCode369(void)
{
    Logger::WriteMessage("Test Leet Code 369");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 9 };
    ListNode* root = leetCode.generateListNodes(nums);
    Logger::WriteMessage(root);
    root = leetCode.plusOne(root);
    Logger::WriteMessage(root);
    leetCode.freeListNodes(root);
}

void TestLeetCode143(void)
{
    Logger::WriteMessage("Test Leet Code 143");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    leetCode.reorderList(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    nums = { 1 };
    head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    leetCode.reorderList(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);
}

void TestLeetCode445(void)
{
    Logger::WriteMessage("Test Leet Code 445");
    LeetCodeLinkedList leetCode;
    vector<int> nums1 = { 7, 2, 4, 3 };
    vector<int> nums2 = { 5, 6, 4 };
    ListNode* l1 = leetCode.generateListNodes(nums1);
    ListNode* l2 = leetCode.generateListNodes(nums2);
    ListNode* sum = leetCode.addTwoNumbersII(l1, l2);
    Logger::WriteMessage(l1);
    Logger::WriteMessage(l2);
    Logger::WriteMessage(sum);
    leetCode.freeListNodes(l1);
    leetCode.freeListNodes(l2);
    leetCode.freeListNodes(sum);
}

void TestLeetCode328(void)
{
    Logger::WriteMessage("Test Leet Code 328");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1,2,3,4,5 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    head = leetCode.oddEvenList(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    nums = { 1 };
    head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    head = leetCode.oddEvenList(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);
}

void TestLeetCode61(void)
{
    Logger::WriteMessage("Test Leet Code 61");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data_list = { 1, 2, 3 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* new_list = leetCode.rotateRight(list, 5);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);

    data_list = {};
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    new_list = leetCode.rotateRight(list, 5);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}

void TestLeetCode82(void)
{
    Logger::WriteMessage("Test Leet Code 82");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data_list = { 1, 1, 2, 3, 3 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* new_list = leetCode.deleteDuplicatesII(list);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);

    data_list = {};
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    new_list = leetCode.deleteDuplicatesII(list);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}

void TestLeetCode83(void)
{
    Logger::WriteMessage("Test Leet Code 83");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data_list = { 1, 2, 2, 3, 3 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* new_list = leetCode.deleteDuplicates(list);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);

    data_list = {};
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    new_list = leetCode.deleteDuplicates(list);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}

void TestLeetCode86(void)
{
    Logger::WriteMessage("Test Leet Code 86");
    LeetCodeLinkedList leetCode;
    string message;
    vector<int> data_list = { 1, 4, 3, 2, 5, 2 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    Logger::WriteMessage("Partition by 3");
    ListNode* new_list = leetCode.partitionList(list, 3);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);

    data_list = { 3, 2, 1 };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    Logger::WriteMessage("Partition by 2");
    new_list = leetCode.partitionList(list, 2);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);

    data_list = { 2, 1 };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    Logger::WriteMessage("Partition by 2");
    new_list = leetCode.partitionList(list, 2);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}

void TestLeetCode206(void)
{
    Logger::WriteMessage("Test Leet Code 206");
    LeetCodeLinkedList leetCode;
    vector<int> data_list = { 1, 2, 3, 4, 5, 6, 7 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* reverse_list = leetCode.reverseList(list);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);
}

void TestLeetCode92(void)
{
    Logger::WriteMessage("Test Leet Code 92");
    LeetCodeLinkedList leetCode;
    vector<int> data_list = { 1, 2, 3, 4, 5, 6, 7 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* reverse_list = leetCode.reverseBetween(list, 1, 3);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);

    data_list = { 1, 2, 3, 4, 5, 6, 7 };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    reverse_list = leetCode.reverseBetween(list, 2, 7);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);

    data_list = {  };
    list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    reverse_list = leetCode.reverseBetween(list, 1, 2);
    Logger::WriteMessage(reverse_list);
    leetCode.freeListNodes(reverse_list);
}

void TestLeetCode203(void)
{
    Logger::WriteMessage("Test Leet Code 203");
    LeetCodeLinkedList leetCode;
    vector<int> data_list = { 1, 2, 3, 4, 5, 6, 7, 7, 7 };
    ListNode* list = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(list);
    ListNode* new_list = leetCode.removeElements(list, 7);
    Logger::WriteMessage(new_list);
    leetCode.freeListNodes(new_list);
}

void TestLeetCode147(void)
{
    Logger::WriteMessage("Test Leet Code 147");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 2, 1, 3, 9, 4, 5, 7, 8, 6, 0 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    head = leetCode.insertionSortList(head);
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);
}

void TestLeetCode160(void)
{
    Logger::WriteMessage("Test Leet Code 160");
    LeetCodeLinkedList leetCode;
    vector<int> nums1 = { 1, 3, 5 };
    vector<int> nums2 = { 2, 4 };
    vector<int> nums3 = { 10, 20 };
    ListNode* headA = leetCode.generateListNodes(nums1);
    ListNode* headB = leetCode.generateListNodes(nums2);
    ListNode* headC = leetCode.generateListNodes(nums3);
    headA = leetCode.addListNodes(headA, headC);
    headB = leetCode.addListNodes(headB, headC);
    Logger::WriteMessage(headA);
    Logger::WriteMessage(headB);
    ListNode* common = leetCode.getIntersectionNode(headA, headB);
    Logger::WriteMessage(common);
}

void TestLeetCode237(void)
{
    Logger::WriteMessage("Test Leet Code 237");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1,2,3,4 };
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    ListNode* node = leetCode.findListNode(head, 1);
    leetCode.deleteNode(node);
    Logger::WriteMessage(head);
}

void TestLeetCode234(void)
{
    Logger::WriteMessage("Test Leet Code 234");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1, 2 };
    ListNode* head = leetCode.generateListNodes(nums);
    bool isPalindrome = leetCode.isPalindrome(head);
    Logger::WriteMessage(head);
    Logger::WriteMessage(isPalindrome ? "is palindrom" : "is not palidrom");
    leetCode.freeListNodes(head);

    nums = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };
    head = leetCode.generateListNodes(nums);
    isPalindrome = leetCode.isPalindrome(head);
    Logger::WriteMessage(head);
    Logger::WriteMessage(isPalindrome ? "is palindrom" : "is not palidrom");
    leetCode.freeListNodes(head);
}

void TestLeetCode382(void)
{
    Logger::WriteMessage("Test Leet Code 382");
    LeetCodeLinkedList leetCode;
    vector<int> nums = { 1, 2, 3 };
    vector<int> result;
    ListNode* head = leetCode.generateListNodes(nums);
    Logger::WriteMessage(head);
    for (size_t i = 0; i < 100; i++)
    {
        result.push_back(leetCode.getRandom(head));
    }
    Logger::WriteMessage(result);
}

void TestLeetCode427(void)
{
    Logger::WriteMessage("Test Leet Code 427");
    LeetCodeLinkedList leetCode;
    vector<vector<int>> grid =
    {
        { 1, 1, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 0, 0 }
    };
    grid = { {0, 0, 1, 1},{0, 0, 1, 1},{1, 1, 0, 0},{1, 1, 0, 0} };
    QuadNode* quadNode = leetCode.constructQuadTree(grid);
}

void TestLeetCode558(void)
{
    Logger::WriteMessage("Test Leet Code 558");
    LeetCodeLinkedList leetCode;
    vector<vector<int>> grid1 =
    {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
    };
    vector<vector<int>> grid2 =
    {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 0, 0, 1, 1 },
        { 0, 0, 1, 1 }
    };
    QuadNode* quadNode1 = leetCode.constructQuadTree(grid1);
    QuadNode* quadNode2 = leetCode.constructQuadTree(grid2);
    QuadNode* result = leetCode.intersect(quadNode1, quadNode2);
}

void TestLeetCode1474(void)
{
    Logger::WriteMessage("Test Leet Code 1474");
    LeetCodeLinkedList leetCode;
    vector<int> data_list = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
    int m = 2;
    int n = 3;
    ListNode* head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.deleteNodes(head, m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    data_list = { 1,2,3,4,5,6,7,8,9,10,11 };
    m = 1;
    n = 3;
    head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.deleteNodes(head, m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    data_list = { 1,2,3,4,5,6,7,8,9,10,11 };
    m = 3;
    n = 1;
    head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.deleteNodes(head, m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);

    data_list = { 9,3,7,7,9,10,8,2 };
    m = 1;
    n = 2;
    head = leetCode.generateListNodes(data_list);
    Logger::WriteMessage(head);
    head = leetCode.deleteNodes(head, m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n));
    Logger::WriteMessage(head);
    leetCode.freeListNodes(head);
}

void TestLeetCode1634(void)
{
    Logger::WriteMessage("Test Leet Code 1634");
    vector<vector<int>> poly1_data = { {1, 1} };
    PolyNode* poly1 = PolyNode::generatePolyNodes(poly1_data);
    vector<vector<int>> poly2_data = { {1,0} };
    PolyNode* poly2 = PolyNode::generatePolyNodes(poly2_data);
    LeetCodeLinkedList leetCode;
    PolyNode* result = leetCode.addPoly(poly1, poly2);
    Logger::WriteMessage(PolyNode::ToString(poly1));
    Logger::WriteMessage(PolyNode::ToString(poly2));
    Logger::WriteMessage(PolyNode::ToString(result));
    PolyNode::freeListNodes(poly1);
    PolyNode::freeListNodes(poly2);
    PolyNode::freeListNodes(result);

    poly1_data = {{2, 2}, { 4, 1 }, { 3, 0 }};
    poly1 = PolyNode::generatePolyNodes(poly1_data);
    poly2_data = { {3, 2}, { -4, 1 }, { -1, 0 } };
    poly2 = PolyNode::generatePolyNodes(poly2_data);
    result = leetCode.addPoly(poly1, poly2);
    Logger::WriteMessage(PolyNode::ToString(poly1));
    Logger::WriteMessage(PolyNode::ToString(poly2));
    Logger::WriteMessage(PolyNode::ToString(result));
    PolyNode::freeListNodes(poly1);
    PolyNode::freeListNodes(poly2);
    PolyNode::freeListNodes(result);

    poly1_data = { {1, 2} };
    poly1 = PolyNode::generatePolyNodes(poly1_data);
    poly2_data = { {-1, 2} };
    poly2 = PolyNode::generatePolyNodes(poly2_data);
    result = leetCode.addPoly(poly1, poly2);
    Logger::WriteMessage(PolyNode::ToString(poly1));
    Logger::WriteMessage(PolyNode::ToString(poly2));
    Logger::WriteMessage(PolyNode::ToString(result));
    PolyNode::freeListNodes(poly1);
    PolyNode::freeListNodes(poly2);
    PolyNode::freeListNodes(result);
}

void TestLeetCode1669(void)
{
    Logger::WriteMessage("Test Leet Code 1669");
    LeetCodeLinkedList leetCode;
    vector<int> data_list1 = { 0,1,2,3,4,5 };
    vector<int> data_list2 = { 1000000,1000001,1000002 };
    int a = 3;
    int b = 4;
    ListNode* list1 = leetCode.generateListNodes(data_list1);
    ListNode* list2 = leetCode.generateListNodes(data_list2);
    ListNode* result = leetCode.mergeInBetween(list1, a, b, list2);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);

    data_list1 = { 0,1,2,3,4,5,6 };
    data_list2 = { 1000000,1000001,1000002,1000003,1000004 };
    a = 2;
    b = 5;
    list1 = leetCode.generateListNodes(data_list1);
    list2 = leetCode.generateListNodes(data_list2);
    result = leetCode.mergeInBetween(list1, a, b, list2);
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);
}

void TestLeetCode1721(void)
{
    Logger::WriteMessage("Test Leet Code 1721");
    LeetCodeLinkedList leetCode;
    vector<int> data_list = { 1,2,3,4,5 };
    int  k = 2;
    ListNode* list = leetCode.generateListNodes(data_list);
    ListNode* result = leetCode.swapNodes(list, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);

    data_list = { 7,9,6,6,7,8,3,0,9,5 };
    k = 5;
    list = leetCode.generateListNodes(data_list);
    result = leetCode.swapNodes(list, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);

    data_list = { 1 };
    k = 1;
    list = leetCode.generateListNodes(data_list);
    result = leetCode.swapNodes(list, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);

    data_list = { 1, 2 };
    k = 1;
    list = leetCode.generateListNodes(data_list);
    result = leetCode.swapNodes(list, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);

    data_list = { 1, 2, 3 };
    k = 2;
    list = leetCode.generateListNodes(data_list);
    result = leetCode.swapNodes(list, k);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
    leetCode.freeListNodes(result);
}


void TestLeetCodeLinkedList(void)
{
    TestLeetCode1721();
    TestLeetCode1669();
    TestLeetCode1634();
    TestLeetCode1474();
    TestLeetCode382();
    TestLeetCode203();
    TestLeetCode92();
    TestLeetCode206();
    TestLeetCode143();
    TestLeetCode369();
    TestLeetCode725();
    TestLeetCode2();
    TestLeetCode24();
    TestLeetCode1171();
    TestLeetCode1019();
    TestLeetCode1290();
    TestLeetCode1265();
    TestLeetCode19();
    TestLeetCode21();
    TestLeetCode23();
    TestLeetCode25();
    TestLeetCode138();
    TestLeetCode148();
}