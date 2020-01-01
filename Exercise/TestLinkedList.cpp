#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeLinkedList.h"
#include "TestLinkedList.h"
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

void TestLeetCodeLinkedList(void)
{
    TestLeetCode1290();
    TestLeetCode1265();
    TestLeetCode19();
    TestLeetCode21();
    TestLeetCode23();
    TestLeetCode25();
    TestLeetCode138();
    TestLeetCode148();
}