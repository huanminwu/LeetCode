// Exercise.cpp : Defines the entry point for the console application.
//
#include <assert.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>
#include <map>
#include <iostream>
#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDesign.h"
#include "..\LeetCode\LeetCodeDP.h"
#include "..\LeetCode\LeetCodeGraph.h"
#include "..\LeetCode\LeetCodeArray.h"
#include "..\LeetCode\LeetCodeLinkedList.h"
#include "..\LeetCode\LeetCodeTree.h"
#include "..\LeetCode\LeetCodeSort.h"
#include "..\LeetCode\LeetCodeDFS.h"
#include "..\LeetCode\LeetCodeGreedy.h"
#include "..\LeetCode\LeetCodeString.h"
#include "..\LeetCode\LeetCodeBinarySearch.h"
#include "..\LeetCode\LeetCodeBit.h"
#include "..\LeetCode\LeetCodeThread.h"
#include "..\LeetCode\USACO.h"
#include "TestMath.h"
#include "TestDP.h"
#include "TestHashtable.h"
#include "TestStack.h"
#include "TestGraph.h"
#include "TestArray.h"
#include "TestLinkedList.h"
#include "TestTree.h"
#include "TestSort.h"
#include "TestBFS.h"
#include "TestDFS.h"
#include "TestDesign.h"
#include "TestGreedy.h"
#include "TestString.h"
#include "TestBinarySearch.h"
#include "TestBit.h"
#include "TestTwoPointer.h"
#include "TestUSACO.h"

void main(int argc, char* argv[])
{
    TestLeetCodeHashtable();
    TestLeetCodeArray();
    TestLeetCodeTwoPointer();
    TestLeetCodeGraph();
    TestLeetCodeString();
    TestLeetCodeMath();
    TestLeetCodeSort();
    TestLeetCodeDP();
    TestLeetCodeBit();
    TestLeetCodeBinarySearch();
    TestLeetCodeTree();
    TestLeetCodeGreedy();
    TestLeetCodeDFS();
    TestLeetCodeStack();
    TestLeetCodeLinkedList();
    TestLeetCodeDesign();
    TestLeetCodeBFS();
    TestUSACO();
    printf("Please press a key to end");
    int key = _getch();
    return;
}
