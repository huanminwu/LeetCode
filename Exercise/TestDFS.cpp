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

void TestLeetCode1397(void)
{
    Logger::WriteMessage("Test Leet Code 1397");
    int n = 2;
    string s1 = "aa";
    string s2 = "da";
    string evil = "b";
    LeetCodeDFS leetCode;
    int result = leetCode.findGoodStrings(n, s1, s2, evil);
    Logger::WriteMessage("s1 =" + s1 + +"; s2 = " + s2 + "; evil = " + evil + "; result=" + to_string(result));

    n = 8;
    s1 = "leetcode";
    s2 = "leetgoes";
    evil = "leet";
    result = leetCode.findGoodStrings(n, s1, s2, evil);
    Logger::WriteMessage("s1 =" + s1 + +"; s2 = " + s2 + "; evil = " + evil + "; result=" + to_string(result));

    n = 2;
    s1 = "gx";
    s2 = "gz";
    evil = "x";
    result = leetCode.findGoodStrings(n, s1, s2, evil);
    Logger::WriteMessage("s1 =" + s1 + +"; s2 = " + s2 + "; evil = " + evil + "; result=" + to_string(result));
}

void TestLeetCode679(void)
{
    LeetCodeDFS leetCode;
    vector<int> nums = { 4, 1, 8, 7 };
    bool result = leetCode.judgePoint24(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1, 2, 1, 2 };
    result = leetCode.judgePoint24(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode422(void)
{
    Logger::WriteMessage("Test Leet Code 422");
    LeetCodeDFS leetCode;
    vector<string> words = { "abcd",  "bnrt", "crmy",  "dtye" };
    bool isWordSquare = leetCode.validWordSquare(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("It is" + (string)(isWordSquare ? " " : " not ") + "a valid word square");

    words = { "abcd",  "bnrt", "crm",  "dt" };
    isWordSquare = leetCode.validWordSquare(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("It is" + (string)(isWordSquare ? " " : " not ") + "a valid word square");

    words = { "ball",  "area", "read",  "lady" };
    isWordSquare = leetCode.validWordSquare(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("It is" + (string)(isWordSquare ? " " : " not ") + "a valid word square");
}

void TestLeetCode87(void)
{
    Logger::WriteMessage("Test Leet Code 87");
    LeetCodeDFS leetCode;
    string s1, s2;
    bool is_scramble;
    s1.assign("great");
    s2.assign("rgeat");
    is_scramble = leetCode.isScramble(s1, s2);
    Logger::WriteMessage(s1 + " and " + s2 + (is_scramble ? " are " : " are not ") + "scramble string");
    s2.assign("rgtae");
    is_scramble = leetCode.isScramble(s1, s2);
    Logger::WriteMessage(s1 + " and " + s2 + (is_scramble ? " are " : " are not ") + "scramble string");
}


void TestLeetCode131(void)
{
    Logger::WriteMessage("Test Leet Code 131");
    LeetCodeDFS leetCode;
    string s = "aab";
    Logger::WriteMessage(s);
    vector<vector<string>> partitions = leetCode.partitionPalindrome(s);
    Logger::WriteMessage(partitions);
}

void TestLeetCode140(void)
{
    Logger::WriteMessage("Test Leet Code 140");
    LeetCodeDFS leetCode;
    string s;
    vector<string> wordDict;
    vector<string> result;

    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
    result = leetCode.wordBreakII(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage(result);

    s = "catsanddog";
    wordDict = { "cat", "cats", "and", "sand", "dog" };
    result = leetCode.wordBreakII(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage(result);

    s = "pineapplepenapple";
    wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
    result = leetCode.wordBreakII(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage(result);

    s = "catsandog";
    wordDict = { "cats", "dog", "sand", "and", "cat" };
    result = leetCode.wordBreakII(s, wordDict);
    Logger::WriteMessage("string = " + s);
    Logger::WriteMessage("Dictionary = ");
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage(result);
}

void TestLeetCode247(void)
{
    Logger::WriteMessage("Test Leet Code 247");
    LeetCodeDFS leetCode;
    int n = 3;
    vector<string> result = leetCode.findStrobogrammatic(n);
    Logger::WriteMessage(result);
}

void TestLeetCode248(void)
{
    Logger::WriteMessage("Test Leet Code 248");
    LeetCodeDFS leetCode;
    string low = "50", high = "100";
    int count = leetCode.strobogrammaticInRange(low, high);
    Logger::WriteMessage("count = " + to_string(count));
}

void TestLeetCode1595(void)
{
    Logger::WriteMessage("Test Leet Code 1595");
    LeetCodeDFS leetCode;
    vector<vector<int>> cost = { {2, 5, 1},{3, 4, 7},{8, 1, 2},{6, 2, 4},{3, 8, 8} }; 
    int result = leetCode.connectTwoGroups(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { {1, 3, 5},{4, 1, 1},{1, 5, 3} };
    result = leetCode.connectTwoGroups(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

    cost = { {15, 96},{36, 2} };
    result = leetCode.connectTwoGroups(cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("result = " + to_string(result));

}


void TestLeetCode1593(void)
{
    Logger::WriteMessage("Test Leet Code 1593");
    LeetCodeDFS leetCode;
    string s = "ababccc";
    int result = leetCode.maxUniqueSplit(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aba";
    result = leetCode.maxUniqueSplit(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aa";
    result = leetCode.maxUniqueSplit(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1601(void)
{
    Logger::WriteMessage("Test Leet Code 1601");
    LeetCodeDFS leetCode;
    int n = 5;
    vector<vector<int>> requests = { {0, 1},{1, 0},{0, 1},{1, 2},{2, 0},{3, 4} };
    int result = leetCode.maximumRequests(n, requests);
    Logger::WriteMessage(requests);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    requests = { {0, 0},{1, 2},{2, 1} };
    result = leetCode.maximumRequests(n, requests);
    Logger::WriteMessage(requests);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    requests = { {0, 3},{3, 1},{1, 2},{2, 0} };
    result = leetCode.maximumRequests(n, requests);
    Logger::WriteMessage(requests);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1655(void)
{
    Logger::WriteMessage("Test Leet Code 1655");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> quantity = { 2 };
    bool result = leetCode.canDistribute(nums, quantity);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(quantity);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,2,2 };
    quantity = { 2, 2 };
    result = leetCode.canDistribute(nums, quantity);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(quantity);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,2,3 };
    quantity = { 2, 2 };
    result = leetCode.canDistribute(nums, quantity);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(quantity);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1,1,1 };
    quantity = { 2, 3 };
    result = leetCode.canDistribute(nums, quantity);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(quantity);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,1,1,2, 2, 2 };
    quantity = { 3, 2, 2 };
    result = leetCode.canDistribute(nums, quantity);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(quantity);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47, 48, 48, 49, 49, 50, 50 };
    quantity = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 };
    result = leetCode.canDistribute(nums, quantity);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(quantity);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1659(void)
{
    Logger::WriteMessage("Test Leet Code 1659");
    LeetCodeDFS leetCode;
    int m = 2;
    int n = 3;
    int introvertsCount = 1;
    int extrovertsCount = 2;
    int result = leetCode.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; introvertsCount = " + to_string(introvertsCount) + 
        "; extrovertsCount = " + to_string(extrovertsCount) +
        "; result = " + to_string(result));

    m = 3;
    n = 1;
    introvertsCount = 2;
    extrovertsCount = 1;
    result = leetCode.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; introvertsCount = " + to_string(introvertsCount) +
        "; extrovertsCount = " + to_string(extrovertsCount) +
        "; result = " + to_string(result));

    m = 2;
    n = 2;
    introvertsCount = 4;
    extrovertsCount = 0;
    result = leetCode.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; introvertsCount = " + to_string(introvertsCount) +
        "; extrovertsCount = " + to_string(extrovertsCount) +
        "; result = " + to_string(result));

    m = 3;
    n = 2;
    introvertsCount = 2;
    extrovertsCount = 1;
    result = leetCode.getMaxGridHappiness(m, n, introvertsCount, extrovertsCount);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) +
        "; introvertsCount = " + to_string(introvertsCount) +
        "; extrovertsCount = " + to_string(extrovertsCount) +
        "; result = " + to_string(result));
}

void TestLeetCode1681(void)
{
    Logger::WriteMessage("Test Leet Code 1681");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1, 2, 1, 4 };
    int k = 2;
    int result = leetCode.minimumIncompatibility(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) +"; result = " + to_string(result));

    nums = { 6, 3, 8, 1, 3, 1, 2, 2 };
    k = 4;
    result = leetCode.minimumIncompatibility(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = { 5,3,3,6,3,3 };
    k = 3;
    result = leetCode.minimumIncompatibility(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode473(void)
{
    Logger::WriteMessage("Test Leet Code 473");
    LeetCodeDFS leetCode;
    vector<int> nums = { 2, 2, 2, 2, 2, 6 };
    bool result = leetCode.makesquare(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 1,1,2,2,2 };
    result = leetCode.makesquare(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3,3,3,3,4 };
    result = leetCode.makesquare(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1140(void)
{
    Logger::WriteMessage("Test Leet Code 1140");
    LeetCodeDFS leetCode;
    vector<int> piles = { 2, 7, 9, 4, 4 };
    int result = leetCode.stoneGameII(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1087(void)
{
    Logger::WriteMessage("Test Leet Code 1087");
    LeetCodeDFS leetCode;
    string S = "{a,b}c{d,e}f";
    vector<string> result = leetCode.expand(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "abcd";
    result = leetCode.expand(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode1079(void)
{
    Logger::WriteMessage("Test Leet Code 1079");
    LeetCodeDFS leetCode;
    string tiles = "AAB";
    int result = leetCode.numTilePossibilities(tiles);
    Logger::WriteMessage("tiles = " + tiles + "; result = " + to_string(result));

    tiles = "AAABBC";
    result = leetCode.numTilePossibilities(tiles);
    Logger::WriteMessage("tiles = " + tiles + "; result = " + to_string(result));
}

void TestLeetCode996(void)
{
    Logger::WriteMessage("Test Leet Code 996");
    LeetCodeDFS leetCode;
    vector<int> A = { 1,17,8 };
    int result = leetCode.numSquarefulPerms(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,2,2 };
    result = leetCode.numSquarefulPerms(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 2,2,2,2,7,7,7 };
    result = leetCode.numSquarefulPerms(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode980(void)
{
    Logger::WriteMessage("Test Leet Code 980");
    LeetCodeDFS leetCode;
    vector<vector<int>> grid = { {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
    int result = leetCode.uniquePathsIII(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 2} };
    result = leetCode.uniquePathsIII(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1},{2, 0} };
    result = leetCode.uniquePathsIII(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode489(void)
{
    Logger::WriteMessage("Test Leet Code 489");
    LeetCodeDFS leetCode;
    vector<vector<int>> room =
    {
        {1,1,1,1,1,0,1,1},
        {1,1,1,1,1,0,1,1},
        {1,0,1,1,1,1,1,1},
        {0,0,0,1,0,0,0,0},
        {1,1,1,1,1,1,1,1}
    };
    int row = 1;
    int col = 3;
    Logger::WriteMessage(room);
    leetCode.cleanRoom(room, row, col);
    Logger::WriteMessage(room);
}

void TestLeetCode856(void)
{
    Logger::WriteMessage("Test Leet Code 856");
    LeetCodeDFS leetCode;
    string S = "()";
    int result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "(())";
    result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "()()";
    result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));

    S = "(()(()))";
    result = leetCode.scoreOfParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode797(void)
{
    Logger::WriteMessage("Test Leet Code 797");
    LeetCodeDFS leetCode;
    vector<vector<int>> graph = { {1, 2},{3},{3},{} };
    vector<vector<int>> result = leetCode.allPathsSourceTarget(graph);
    Logger::WriteMessage(graph);
    Logger::WriteMessage(result);
}

void TestLeetCode1718(void)
{
    Logger::WriteMessage("Test Leet Code 1718");
    LeetCodeDFS leetCode;
    int n = 3;
    vector<int> result = leetCode.constructDistancedSequence(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 5;
    result = leetCode.constructDistancedSequence(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 6;
    result = leetCode.constructDistancedSequence(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 4;
    result = leetCode.constructDistancedSequence(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1723(void)
{
    Logger::WriteMessage("Test Leet Code 1723");
    LeetCodeDFS leetCode;
    vector<int> jobs = { 3, 2, 3 };
    int k = 3;
    int result = leetCode.minimumTimeRequired(jobs, k);
    Logger::WriteMessage(jobs);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    jobs = { 1,2,4,7,8 };
    k = 2;
    result = leetCode.minimumTimeRequired(jobs, k);
    Logger::WriteMessage(jobs);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
};

void TestLeetCode1728(void)
{
    Logger::WriteMessage("Test Leet Code 1728");
    LeetCodeDFS leetCode;

    vector<string> grid = { ".....", "...C.", "...#.", "...#M", "F..#." };
    int catJump = 1;
    int mouseJump = 3;
    bool result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) +
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );

    grid =
    {
        "CM......", "#######.", "........",
        ".#######", "........", "#######.",
        "........", "F#######"
    };
    catJump = 1;
    mouseJump = 1;
    result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) +
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );

    grid = { "####F","#C...","M...." };
    catJump = 1;
    mouseJump = 2;
    result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) + 
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );

    grid = { "M.C...F" };
    catJump = 1;
    mouseJump = 4;
    result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) +
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );
  
    grid = { "M.C...F" };
    catJump = 1;
    mouseJump = 3;
    result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) +
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );

    grid = { "C...#","...#F","....#","M...." };
    catJump = 2;
    mouseJump = 5;
    result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) +
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );

    grid = { ".M...", "..#..", "#..#.", "C#.#.", "...#F" };
    catJump = 3;
    mouseJump = 1;
    result = leetCode.canMouseWin(grid, catJump, mouseJump);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("catJump = " + to_string(catJump) +
        "; mouseJump = " + to_string(mouseJump) +
        "; result = " + (string)(result ? "true" : "false")
    );
};

void TestLeetCode1770(void)
{
    Logger::WriteMessage("Test Leet Code 1770");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1, 2, 3 };
    vector<int> multipliers = { 3, 2, 1 };
    int result = leetCode.maximumScore(nums, multipliers);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(multipliers);
    Logger::WriteMessage("result = " + to_string(result));
    
    nums = {-5,-3,-3,-2,7,1};
    multipliers = { -10,-5,3,4,6 };
    result = leetCode.maximumScore(nums, multipliers);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(multipliers);
    Logger::WriteMessage("result = " + to_string(result));
};

void TestLeetCode1799(void)
{
    Logger::WriteMessage("Test Leet Code 1799");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1,2 };
    int result = leetCode.maxScore(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3, 4, 6, 8 };
    result = leetCode.maxScore(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 2, 3, 4, 5, 6 };
    result = leetCode.maxScore(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
};

void TestLeetCode1766(void)
{
    Logger::WriteMessage("Test Leet Code 1766");
    LeetCodeDFS leetCode;
    vector<int> nums = { 2, 3, 3, 2 };
    vector<vector<int>> edges = { {0, 1},{1, 2},{1, 3} };
    vector<int> result = leetCode.getCoprimes(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    nums = { 5,6,10,2,3,6,15 };
    edges = { {0, 1},{0, 2},{1, 3},{1, 4},{2, 5},{2, 6} };
    result = leetCode.getCoprimes(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    nums = { 1 };
    edges = { };
    result = leetCode.getCoprimes(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);

    nums = { 9, 16, 30, 23, 33, 35, 9, 47, 39, 46, 16, 38, 5, 49, 21, 44, 17, 1, 6, 37, 49, 15, 23, 46, 38, 9, 27, 3, 24, 1, 14, 17, 12, 23, 43, 38, 12, 4, 8, 17, 11, 18, 26, 22, 49, 14, 9 };
    edges = { {17, 0}, { 30,17 }, { 41,30 }, { 10,30 }, { 13,10 }, { 7,13 }, { 6,7 }, { 45,10 }, { 2,10 }, { 14,2 }, { 40,14 }, { 28,40 }, { 29,40 }, { 8,29 }, { 15,29 }, { 26,15 }, { 23,40 }, { 19,23 }, { 34,19 }, { 18,23 }, { 42,18 }, { 5,42 }, { 32,5 }, { 16,32 }, { 35,14 }, { 25,35 }, { 43,25 }, { 3,43 }, { 36,25 }, { 38,36 }, { 27,38 }, { 24,36 }, { 31,24 }, { 11,31 }, { 39,24 }, { 12,39 }, { 20,12 }, { 22,12 }, { 21,39 }, { 1,21 }, { 33,1 }, { 37,1 }, { 44,37 }, { 9,44 }, { 46,2 }, { 4,46 } };
    result = leetCode.getCoprimes(nums, edges);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(edges);
    Logger::WriteMessage(result);
}

void TestLeetCode1815(void)
{
    Logger::WriteMessage("Test Leet Code 1815");
    LeetCodeDFS leetCode;
    int batchSize = 3;
    vector<int> groups = { 1, 2, 3, 4, 5, 6 };
    int result = leetCode.maxHappyGroups(batchSize, groups);
    Logger::WriteMessage("batchSize = " + to_string(batchSize) + "; result = " + to_string(result));

    batchSize = 4;
    groups = { 1,3,2,5,2,2,1,6 };
    result = leetCode.maxHappyGroups(batchSize, groups);
    Logger::WriteMessage("batchSize = " + to_string(batchSize) + "; result = " + to_string(result));

    batchSize = 7;
    groups = { 6,3,6,2,6,6,6,2,6,6,2 };
    result = leetCode.maxHappyGroups(batchSize, groups);
    Logger::WriteMessage("batchSize = " + to_string(batchSize) + "; result = " + to_string(result));
}

void TestLeetCode1849(void)
{
    Logger::WriteMessage("Test Leet Code 1849");
    LeetCodeDFS leetCode;
    string s = "1234";
    bool result = leetCode.splitString(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "050043";
    result = leetCode.splitString(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "9080701";
    result = leetCode.splitString(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "10009998";
    result = leetCode.splitString(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "100009999";
    result = leetCode.splitString(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1879(void)
{
    Logger::WriteMessage("Test Leet Code 1879");
    LeetCodeDFS leetCode;
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 2, 3 };
    int result = leetCode.minimumXORSum(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1,0,3 };
    nums2 = { 5,3,4 };
    result = leetCode.minimumXORSum(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1900(void)
{
    Logger::WriteMessage("Test Leet Code 1900");
    LeetCodeDFS leetCode;
    int n = 11;
    int firstPlayer = 2;
    int secondPlayer = 4;
    vector<int> result = leetCode.earliestAndLatest(n, firstPlayer, secondPlayer);
    Logger::WriteMessage("n = " + to_string(n) +
        "; firstPlayer = " + to_string(firstPlayer) +
        "; secondPlayer = " + to_string(secondPlayer));
    Logger::WriteMessage(result);
 
    n = 5;
    firstPlayer = 1;
    secondPlayer = 5;
    result = leetCode.earliestAndLatest(n, firstPlayer, secondPlayer);
    Logger::WriteMessage("n = " + to_string(n) +
        "; firstPlayer = " + to_string(firstPlayer) +
        "; secondPlayer = " + to_string(secondPlayer));
    Logger::WriteMessage(result);
}

void TestLeetCode1931(void)
{
    Logger::WriteMessage("Test Leet Code 1931");
    LeetCodeDFS leetCode;
    int m = 1;
    int n = 1;
    int result = leetCode.colorTheGrid(m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    m = 1;
    n = 2;
    result = leetCode.colorTheGrid(m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    m = 5;
    n = 5;
    result = leetCode.colorTheGrid(m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));

    m = 5;
    n = 500;
    result = leetCode.colorTheGrid(m, n);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2003(void)
{
    Logger::WriteMessage("Test Leet Code 2003");
    LeetCodeDFS leetCode;
    vector<int> parents = { -1, 0, 0, 2 };
    vector<int> nums = { 1, 2, 3, 4 };
    vector<int> result = leetCode.smallestMissingValueSubtree(parents, nums);
    Logger::WriteMessage(parents);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    parents = { -1,0,1,0,3,3 };
    nums = { 5,4,6,2,1,3 };
    result = leetCode.smallestMissingValueSubtree(parents, nums);
    Logger::WriteMessage(parents);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    parents = { -1,2,3,0,2,4,1 };
    nums = { 2,3,4,5,6,7,8 };
    result = leetCode.smallestMissingValueSubtree(parents, nums);
    Logger::WriteMessage(parents);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode2060(void)
{
    Logger::WriteMessage("Test Leet Code 2060");
    LeetCodeDFS leetCode;
    string s1 = "internationalization";
    string s2 = "i18n";
    bool result = leetCode.possiblyEquals(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "result = " + (string)(result ? "true" : "false"));

    s1 = "l123e";
    s2 = "44";
    result = leetCode.possiblyEquals(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "result = " + (string)(result ? "true" : "false"));

    s1 = "a5b";
    s2 = "c5b";
    result = leetCode.possiblyEquals(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "result = " + (string)(result ? "true" : "false"));

    s1 = "112s";
    s2 = "g841";
    result = leetCode.possiblyEquals(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "result = " + (string)(result ? "true" : "false"));

    s1 = "ab";
    s2 = "a2";
    result = leetCode.possiblyEquals(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1994(void)
{
    Logger::WriteMessage("Test Leet Code 1994");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1, 2, 3, 4 };
    int result = leetCode.numberOfGoodSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1, 1, 2 };
    result = leetCode.numberOfGoodSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,2,3,15 };
    result = leetCode.numberOfGoodSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1981(void)
{
    Logger::WriteMessage("Test Leet Code 1981");
    LeetCodeDFS leetCode;
    vector<vector<int>> mat =
    {
        {1,2,3},{4,5,6},{7,8,9}
    };
    int target = 13;
    int result = leetCode.minimizeTheDifference(mat, target);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    mat =
    { 
        {1},{2},{3} 
    };
    target = 100;
    result = leetCode.minimizeTheDifference(mat, target);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    mat = { {1, 2, 9, 8, 7} };
    target = 6;
    result = leetCode.minimizeTheDifference(mat, target);
    Logger::WriteMessage(mat);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1986(void)
{
    Logger::WriteMessage("Test Leet Code 1986");
    LeetCodeDFS leetCode;
    vector<int> tasks = { 1, 2, 3 };
    int sessionTime = 3;
    int result = leetCode.minSessions(tasks, sessionTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("sessionTime = " + to_string(sessionTime) + "; result = " + to_string(result));

    tasks = { 3,1,3,1,1 };
    sessionTime = 8;
    result = leetCode.minSessions(tasks, sessionTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("sessionTime = " + to_string(sessionTime) + "; result = " + to_string(result));

    tasks = { 1,2,3,4,5 };
    sessionTime = 15;
    result = leetCode.minSessions(tasks, sessionTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("sessionTime = " + to_string(sessionTime) + "; result = " + to_string(result));

    tasks = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    sessionTime = 13;
    result = leetCode.minSessions(tasks, sessionTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("sessionTime = " + to_string(sessionTime) + "; result = " + to_string(result));

    tasks = { 3, 2, 3, 7, 5, 2, 2, 10, 9, 1, 10 };
    sessionTime = 11;
    result = leetCode.minSessions(tasks, sessionTime);
    Logger::WriteMessage(tasks);
    Logger::WriteMessage("sessionTime = " + to_string(sessionTime) + "; result = " + to_string(result));
}

void TestLeetCode1947(void)
{
    Logger::WriteMessage("Test Leet Code 1947");
    LeetCodeDFS leetCode;
    vector<vector<int>> students = { {1, 1, 0},{1, 0, 1},{0, 0, 1} };
    vector<vector<int>> mentors = { {1, 0, 0},{0, 0, 1},{1, 1, 0} };
    int result = leetCode.maxCompatibilitySum(students, mentors);
    Logger::WriteMessage(students);
    Logger::WriteMessage(mentors);
    Logger::WriteMessage("result = " + to_string(result));

    students = { {0, 0},{0, 0},{0, 0} };
    mentors = { {1, 1},{1, 1},{1, 1} };
    result = leetCode.maxCompatibilitySum(students, mentors);
    Logger::WriteMessage(students);
    Logger::WriteMessage(mentors);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2056(void)
{
    Logger::WriteMessage("Test Leet Code 2056");
    LeetCodeDFS leetCode;
    vector<string>pieces = { "rook" };
    vector<vector<int>> positions = { {1, 1} };
    int result = leetCode.countCombinations(pieces, positions);
    Logger::WriteMessage(pieces);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    pieces = { "queen" };
    positions = { {1, 1} };
    result = leetCode.countCombinations(pieces, positions);
    Logger::WriteMessage(pieces);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    pieces = { "bishop" };
    positions = { {4, 3} };
    result = leetCode.countCombinations(pieces, positions);
    Logger::WriteMessage(pieces);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    pieces = { "rook","rook" };
    positions = { {1, 1}, {8, 8} };
    result = leetCode.countCombinations(pieces, positions);
    Logger::WriteMessage(pieces);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    pieces = { "queen", "bishop" };
    positions = { {5, 7},{3, 4} };
    result = leetCode.countCombinations(pieces, positions);
    Logger::WriteMessage(pieces);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    pieces = { "bishop", "rook" };
    positions = { {8, 5},{7, 7} };
    result = leetCode.countCombinations(pieces, positions);
    Logger::WriteMessage(pieces);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2081(void)
{
    Logger::WriteMessage("Test Leet Code 2081");
    LeetCodeDFS leetCode;
    int k = 2;
    int n = 5;
    long long result = leetCode.kMirror(k, n);
    Logger::WriteMessage("k = " + to_string(k) + "; n = " + to_string(n) + "; result = " + to_string(result));

    k = 3;
    n = 7;
    result = leetCode.kMirror(k, n);
    Logger::WriteMessage("k = " + to_string(k) + "; n = " + to_string(n) + "; result = " + to_string(result));

    k = 7;
    n = 17;
    result = leetCode.kMirror(k, n);
    Logger::WriteMessage("k = " + to_string(k) + "; n = " + to_string(n) + "; result = " + to_string(result));

    k = 9;
    n = 30;
    result = leetCode.kMirror(k, n);
    Logger::WriteMessage("k = " + to_string(k) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2002(void)
{
    Logger::WriteMessage("Test Leet Code 2002");
    LeetCodeDFS leetCode;
    string s = "leetcodecom";
    long long result = leetCode.maxProduct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "bb";
    result = leetCode.maxProduct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "accbcaxxcxx";
    result = leetCode.maxProduct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode2094(void)
{
    Logger::WriteMessage("Test Leet Code 2094");
    LeetCodeDFS leetCode;
    vector<int> digits = { 2, 1, 3, 0 };
    vector<int> result = leetCode.findEvenNumbers(digits);
    Logger::WriteMessage(digits);
    Logger::WriteMessage(result);

    digits = { 2,2,8,8,2 };
    result = leetCode.findEvenNumbers(digits);
    Logger::WriteMessage(digits);
    Logger::WriteMessage(result);

    digits = { 3,7,5 };
    result = leetCode.findEvenNumbers(digits);
    Logger::WriteMessage(digits);
    Logger::WriteMessage(result);

    digits = { 0,2,0,0 };
    result = leetCode.findEvenNumbers(digits);
    Logger::WriteMessage(digits);
    Logger::WriteMessage(result);

    digits = { 0,0,0 };
    result = leetCode.findEvenNumbers(digits);
    Logger::WriteMessage(digits);
    Logger::WriteMessage(result);
}

void TestLeetCodeDFS(void)
{
    TestLeetCode2094();
    TestLeetCode2002();
    TestLeetCode2081();
    TestLeetCode2056();
    TestLeetCode1947();
    TestLeetCode1986();
    TestLeetCode1981();
    TestLeetCode1994();
    TestLeetCode2060();
    TestLeetCode2003();
    TestLeetCode1931();
    TestLeetCode1900();
    TestLeetCode1879();
    TestLeetCode1849();
    TestLeetCode1815();
    TestLeetCode1766();
    TestLeetCode1799();
    TestLeetCode1770();
    TestLeetCode1728();
    TestLeetCode1723();
    TestLeetCode1718();
    TestLeetCode797();
    TestLeetCode856();
    TestLeetCode489();
    TestLeetCode980();
    TestLeetCode996();
    TestLeetCode1079();
    TestLeetCode1087();
    TestLeetCode1140();
    TestLeetCode473();
    TestLeetCode1681();
    TestLeetCode1659();
    TestLeetCode1655();
    TestLeetCode1601();
    TestLeetCode1593();
    TestLeetCode1595();
    TestLeetCode248();
    TestLeetCode247();
    TestLeetCode140();
    TestLeetCode131();
    TestLeetCode87();
    TestLeetCode422();
    TestLeetCode679();
    TestLeetCode1397();
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
    TestLeetCode1799();
}