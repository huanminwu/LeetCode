#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeDFS.h"
#include "TestDFS.h"

void TestLeetCode17(void)
{
    Logger::WriteMessage("Test Leet Code 17");
    LeetCodeDFS leetCode;
    string digits = "23";
    Logger::WriteMessage("Digits = " + digits);
    vector<string> result = leetCode.letterCombinations(digits);
    Logger::WriteMessage("Letter combinations are: ");
    Logger::WriteMessage(result);

    digits = "";
    result = leetCode.letterCombinations(digits);
    Logger::WriteMessage("Digits = " + digits);
    Logger::WriteMessage("Letter combinations are: ");
    Logger::WriteMessage(result);
}


void TestLeetCode37(void)
{
    Logger::WriteMessage("Test Leet Code 37");
    LeetCodeDFS leetCode;

    vector<vector<char>> board =
    {
        { '5','3','.','.','7','.','.','.','.' },{ '6','.','.','1','9','5','.','.','.' },
        { '.','9','8','.','.','.','.','6','.' },{ '8','.','.','.','6','.','.','.','3' },
        { '4','.','.','8','.','3','.','.','1' },{ '7','.','.','.','2','.','.','.','6' },
        { '.','6','.','.','.','.','2','8','.' },{ '.','.','.','4','1','9','.','.','5' },
        { '.','.','.','.','8','.','.','7','9' }
    };
    Logger::WriteMessage(board);

    leetCode.solveSudoku(board);
    Logger::WriteMessage(board);
}

void TestLeetCode39(void)
{
    Logger::WriteMessage("Test Leet Code 39");
    LeetCodeDFS leetCode;
    vector<int> candidates = { 2, 3, 6, 7 };
    size_t target = 7;
    Logger::WriteMessage(candidates);
    Logger::WriteMessage("Target = " + to_string(target));
    vector<vector<int>> result = leetCode.combinationSum(candidates, target);
    Logger::WriteMessage(result);
}

void TestLeetCode51(void)
{
    LeetCodeDFS leetCode;
    Logger::WriteMessage("Test Leet Code 51");
    int n = 4;
    vector<vector<string>> result = leetCode.solveNQueens(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode40(void)
{
    Logger::WriteMessage("Test Leet Code 40");
    LeetCodeDFS leetCode;
    vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
    size_t target = 8;
    Logger::WriteMessage("Candidates = ");
    Logger::WriteMessage(candidates);
    Logger::WriteMessage("Target = ");
    Logger::WriteMessage(to_string(target));
    vector<vector<int>> result = leetCode.combinationSum2(candidates, target);
    Logger::WriteMessage("Result = ");
    Logger::WriteMessage(result);
}

void TestLeetCode52(void)
{
    LeetCodeDFS leetCode;
    Logger::WriteMessage("Test Leet Code 52");
    int n = 4;
    int result = leetCode.totalNQueens(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode46(void)
{
    Logger::WriteMessage("Test Leet Code 46");
    LeetCodeDFS leetCode;
    Logger::WriteMessage("Numbers");
    vector<int> nums = { 1, 2, 3 };
    Logger::WriteMessage(nums);
    vector<vector<int>> result = leetCode.permute(nums);
    Logger::WriteMessage("Permute = ");
    Logger::WriteMessage(result);
}

void TestLeetCode47(void)
{
    Logger::WriteMessage("Test Leet Code 47");
    LeetCodeDFS leetCode;
    Logger::WriteMessage("Numbers");
    vector<int> nums = { 1, 1, 2 };
    Logger::WriteMessage(nums);
    vector<vector<int>> result = leetCode.permuteUnique(nums);
    Logger::WriteMessage("Permute = ");
    Logger::WriteMessage(result);
}

void TestLeetCode77(void)
{
    Logger::WriteMessage("Test Leet Code 77");
    LeetCodeDFS leetCode;
    int n = 4, k = 2;
    Logger::WriteMessage("n = " + to_string(n) + ";" + "k = " + to_string(k));
    vector<vector<int>> result = leetCode.combine(n, k);
    Logger::WriteMessage("Result = ");
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode78(void)
{
    Logger::WriteMessage("Test Leet Code 78");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1,2,3 };
    vector<vector<int>> result = leetCode.subsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
    nums = { 4, 4, 4, 1, 4 };
    result = leetCode.subsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode90(void)
{
    Logger::WriteMessage("Test Leet Code 90");
    vector<int> nums;
    vector<vector<int>> result;
    LeetCodeDFS leetCode;
    nums = { 1,2,2 };
    Logger::WriteMessage(nums);
    result = leetCode.subsetsWithDup(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode79(void)
{
    Logger::WriteMessage("Test Leet Code 79");
    LeetCodeDFS leetCode;
    vector<vector<char>> board =
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";
    bool exist = leetCode.wordSearch(board, word);
    Logger::WriteMessage(word + "->" + (exist ? "true" : "false"));

    board =
    {
        { 'A','A'},
    };

    word = "AAA";
    exist = leetCode.wordSearch(board, word);
    Logger::WriteMessage(word + "->" + (exist ? "true" : "false"));
}

void TestLeetCode93(void)
{
    Logger::WriteMessage("Test Leet Code 93");
    LeetCodeDFS leetCode;
    string s;
    vector<string> result;
    s = "010010";
    Logger::WriteMessage(s);
    result = leetCode.restoreIpAddresses(s);
    Logger::WriteMessage(result);

    s = "0000";
    Logger::WriteMessage(s);
    result = leetCode.restoreIpAddresses(s);
    Logger::WriteMessage(result);

    s = "25525511135";
    Logger::WriteMessage(s);
    result = leetCode.restoreIpAddresses(s);
    Logger::WriteMessage(result);
}

void TestLeetCode216(void)
{
    Logger::WriteMessage("Test Leet Code 216");
    LeetCodeDFS leetCode;

    int k = 3;
    int n = 7;
    vector<vector<int>> result = leetCode.combinationSum3(k, n);
    Logger::WriteMessage("k = " + to_string(k) + "," + "n = " + to_string(n) + " -> ");
    Logger::WriteMessage(result);

    k = 3;
    n = 9;
    result = leetCode.combinationSum3(k, n);
    Logger::WriteMessage("k = " + to_string(k) + "," + "n = " + to_string(n) + " -> ");
    Logger::WriteMessage(result);
}

void TestLeetCode241(void)
{
    Logger::WriteMessage("Test Leet Code 241");
    LeetCodeDFS leetCode;
    string input = "2-1-1";
    vector<int> result = leetCode.diffWaysToCompute(input);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(result);

    input = "2*3-4*5";
    result = leetCode.diffWaysToCompute(input);
    Logger::WriteMessage("input = " + input);
    Logger::WriteMessage(result);
}

void TestLeetCode329(void)
{
    Logger::WriteMessage("Test Leet Code 329");
    LeetCodeDFS leetCode;
    vector<vector<int>> matrix = { {9,9,4}, {6,6,8}, {2,1,1} };
    int max_path;
    Logger::WriteMessage(matrix);
    max_path = leetCode.longestIncreasingPath(matrix);
    Logger::WriteMessage("The longest path is " + to_string(max_path));
    matrix = { { 3, 4, 5 }, { 3, 2, 6 },{ 2, 2, 1 } };
    Logger::WriteMessage(matrix);
    max_path = leetCode.longestIncreasingPath(matrix);
    Logger::WriteMessage("The longest path is " + to_string(max_path));
}

void TestLeetCode126(void)
{
    Logger::WriteMessage("Test Leet Code 126");
    LeetCodeDFS leetCode;
    unordered_set<string> wordList = { "hot","dot","dog","lot","log" };
    vector<string> words;
    for (string x : wordList) words.push_back(x);
    Logger::WriteMessage(words);
    string beginWord;
    string endWord;
    vector<vector<string>> result;
    beginWord = "hit";
    endWord = "cog";
    result = leetCode.findLadders(beginWord, endWord, wordList);
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode401(void)
{
    Logger::WriteMessage("Test Leet Code 401");
    LeetCodeDFS leetCode;
    int num;
    vector<string> result;
    num = 2;
    Logger::WriteMessage("The number of LEDs on: " + to_string(num));
    result = leetCode.readBinaryWatch(num);
    Logger::WriteMessage("Possible time: ");
    Logger::WriteMessage(result);
}

void TestLeetCode464(void)
{
    Logger::WriteMessage("Test Leet Code 464");
    LeetCodeDFS leetCode;
    int maxChoosableInteger = 10;
    int desiredTotal = 11;
    bool result = leetCode.canIWin(maxChoosableInteger, desiredTotal);
    Logger::WriteMessage("MaxChoosableInteger = " + to_string(maxChoosableInteger) + "; DesiredTotal = " + to_string(desiredTotal));
    Logger::WriteMessage("Can " + (string)(result == true ? "Win" : "Not Win"));

    maxChoosableInteger = 4;
    desiredTotal = 6;
    result = leetCode.canIWin(maxChoosableInteger, desiredTotal);
    Logger::WriteMessage("MaxChoosableInteger = " + to_string(maxChoosableInteger) + "; DesiredTotal = " + to_string(desiredTotal));
    Logger::WriteMessage("Can " + (string)(result == true ? "Win" : "Not Win"));
}

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

void TestLeetCode1066(void)
{
    Logger::WriteMessage("Test Leet Code 1066");
    LeetCodeDFS leetCode;
    vector<vector<int>> workers = { {0,0},{1,1},{2,0} };
    vector<vector<int>> bikes = { {1,0},{2,2},{2,1} };
    int result = leetCode.assignBikesII(workers, bikes);
    Logger::WriteMessage(workers);
    Logger::WriteMessage(bikes);
    Logger::WriteMessage("result = " + to_string(result));

    workers = { {0, 0},{2, 1} };
    bikes = { {1, 2}, {3, 3} };
    result = leetCode.assignBikesII(workers, bikes);
    Logger::WriteMessage(workers);
    Logger::WriteMessage(bikes);
    Logger::WriteMessage("result = " + to_string(result));

    workers = { {0, 0},{1, 0},{2, 0},{3, 0},{4, 0},{5, 0},{6, 0},{7, 0} };
    bikes = { {0, 999},{1, 999},{2, 999},{3, 999},{4, 999},{5, 999},{6, 999},{7, 999},{8, 999} };
    result = leetCode.assignBikesII(workers, bikes);
    Logger::WriteMessage(workers);
    Logger::WriteMessage(bikes);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode526(void)
{
    Logger::WriteMessage("Test Leet Code 526");
    LeetCodeDFS leetCode;
    int N = 2;
    int result = leetCode.countArrangement(N);
    Logger::WriteMessage("N = " + to_string(N) + "; count Arrangement = " + to_string(result));

    N = 4;
    result = leetCode.countArrangement(N);
    Logger::WriteMessage("N = " + to_string(N) + "; count Arrangement = " + to_string(result));
}

void TestLeetCode416(void)
{
    Logger::WriteMessage("Test Leet Code 416");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1, 5, 11, 5 };
    bool result = leetCode.canPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " partition into equal subset.");

    nums = { 1, 2, 3, 5 };
    result = leetCode.canPartition(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage((string)(result ? "Can" : "Can not") + " partition into equal subset.");
}

void TestLeetCode491(void)
{
    Logger::WriteMessage("Test Leet Code 491");
    LeetCodeDFS leetCode;
    vector<int> nums = { 4, 6, 7, 7 };
    Logger::WriteMessage(nums);
    vector<vector<int>> result = leetCode.findSubsequences(nums);
    Logger::WriteMessage(result);

    nums = { 4, 3, 2, 1 };
    Logger::WriteMessage(nums);
    result = leetCode.findSubsequences(nums);
    Logger::WriteMessage(result);

    nums = { 1, 8, 9, 1, 1, 1, 1, 1 };
    Logger::WriteMessage(nums);
    result = leetCode.findSubsequences(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1349(void)
{
    Logger::WriteMessage("Test Leet Code 1349");
    LeetCodeDFS leetCode;
    vector<vector<char>> seats =
    {
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.'},
    };
    int result = leetCode.maxStudents(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));

    seats =
    {
        {'#', '.', '#', '#', '.', '#'},
        {'.', '#', '#', '#', '#', '.'},
        {'#', '.', '#', '#', '.', '#'}
    };
    result = leetCode.maxStudents(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));

    seats =
    {
        {'.', '#'},
        {'#', '#'},
        {'#', '.'},
        {'#', '#'},
        {'.', '#'},
    };
    result = leetCode.maxStudents(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));

    seats =
    {
        {'#', '.', '.', '.', '#'},
        {'.', '#', '.', '#', '.'},
        {'.', '.', '#', '.', '.'},
        {'.', '#', '.', '#', '.'},
        {'#', '.', '.', '.', '#'}
    };
    result = leetCode.maxStudents(seats);
    Logger::WriteMessage(seats);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode212(void)
{
    Logger::WriteMessage("Test Leet Code 212");
    LeetCodeDFS leetCode;
    vector<vector<char>> board =
    {
        { 'a', 'b'}, {'c', 'd' }
    };

    vector<string> words = { "ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb" };
    vector<string> result = leetCode.wordSearchII(board, words);
    Logger::WriteMessage(board);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    board =
    {
        { 'o', 'a', 'a', 'n' }, { 'e', 't', 'a', 'e' },
        { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v' }
    };
    words = { "oath", "pea", "eat", "rain" };
    result = leetCode.wordSearchII(board, words);
    Logger::WriteMessage(board);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    board =
    {
        { 'a' }
    };
    words = { "a" };
    result = leetCode.wordSearchII(board, words);
    Logger::WriteMessage(board);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode425(void)
{
    Logger::WriteMessage("Test Leet Code 425");
    LeetCodeDFS leetCode;
    vector<string> words = { "area","lead","wall","lady","ball" };
    vector<vector<string>> result = leetCode.wordSquares(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    words = { "abat", "baba", "atan", "atal" };
    result = leetCode.wordSquares(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCodeDFS(void)
{
    TestLeetCode425();
    TestLeetCode212();
    TestLeetCode1349();
    TestLeetCode126();
    TestLeetCode416();
    TestLeetCode329();
    TestLeetCode17();
    TestLeetCode37();
    TestLeetCode39();
    TestLeetCode40();
    TestLeetCode51();
    TestLeetCode52();
    TestLeetCode46();
    TestLeetCode47();
    TestLeetCode77();
    TestLeetCode78();
    TestLeetCode79();
    TestLeetCode90();
    TestLeetCode464();
    TestLeetCode526();
    TestLeetCode1307();
    TestLeetCode1066();
    TestLeetCode1240();
    TestLeetCode1219();
}