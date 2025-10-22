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

void TestLeetCode22(void)
{
    Logger::WriteMessage("Test Leet Code 22");
    LeetCodeDFS leetCode;
    int n = 3;
    Logger::WriteMessage("n= " + to_string(n));
    vector<string> result = leetCode.generateParenthesis(n);
    Logger::WriteMessage("Parenthesis combinations are: ");
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

void TestLeetCode131(void)
{
    Logger::WriteMessage("Test Leet Code 131");
    LeetCodeDFS leetCode;
    string s = "aab";
    Logger::WriteMessage(s);
    vector<vector<string>> partitions = leetCode.partition(s);
    Logger::WriteMessage(partitions);

    s = "a";
    Logger::WriteMessage(s);
    partitions = leetCode.partition(s);
    Logger::WriteMessage(partitions);
}

void TestLeetCode140(void)
{
    Logger::WriteMessage("Test Leet Code 140");
    LeetCodeDFS leetCode;
    string s;
    vector<string> wordDict;
    vector<string> result;

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

void TestLeetCode301(void)
{
    Logger::WriteMessage("Test Leet Code 301");
    LeetCodeDFS leetCode;
    string s = "()())()";
    vector<string> result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = "(a)())()";
    result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = ")(";
    result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = "(r(()()(";
    result = leetCode.removeInvalidParentheses(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);
}

void TestLeetCode254(void)
{
    Logger::WriteMessage("Test Leet Code 254");
    LeetCodeDFS leetCode;
    int num = 1;
    vector<vector<int>> result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 37;
    result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 12;
    result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 32;
    result = leetCode.getFactors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);
}

void TestLeetCode267(void)
{
    Logger::WriteMessage("Test Leet Code 267");
    LeetCodeDFS leetCode;
    string s = "aabbbbcz";
    vector<string> result;
    Logger::WriteMessage("s = " + s);
    result = leetCode.generatePalindromes(s);
    Logger::WriteMessage(result);
}

void TestLeetCode294(void)
{
    Logger::WriteMessage("Test Leet Code 294");
    LeetCodeDFS leetCode;
    string s = "++++++";
    Logger::WriteMessage("s = " + s);
    bool result = leetCode.canWin(s);
    Logger::WriteMessage("Can Win = " + (string)(result ? "true" : "false"));
}

void TestLeetCode291(void)
{
    Logger::WriteMessage("Test Leet Code 291");
    LeetCodeDFS leetCode;
    string pattern = "abab", str = "redblueredblue";
    bool match = leetCode.wordPatternMatch(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; match = " + (match ? "true" : "false"));
    pattern = "aaaa", str = "asdasdasdasd";
    match = leetCode.wordPatternMatch(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; match = " + (match ? "true" : "false"));
    pattern = "aabb", str = "xyzabcxzyabc";
    match = leetCode.wordPatternMatch(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; match = " + (match ? "true" : "false"));
}

void TestLeetCode320(void)
{
    Logger::WriteMessage("Test Leet Code 320");
    LeetCodeDFS leetCode;

    string word = "word";
    vector<string> result = leetCode.generateAbbreviations(word);
    Logger::WriteMessage("word = " + word);
    Logger::WriteMessage(result);
}

void TestLeetCode9901(void)
{
    Logger::WriteMessage("Test Leet Code 9901");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1,2,-3, 4, -1 };
    Logger::WriteMessage(nums);
    int result = leetCode.getMaxExprResult(nums);
    Logger::WriteMessage("Maximum Result = " + to_string(result));
}

void TestLeetCode411(void)
{
    Logger::WriteMessage("Test Leet Code 411");
    LeetCodeDFS leetCode;
    string target = "apple";
    vector<string> dictionary = { "blade" };
    string abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);

    target = "apple";
    dictionary = { "plain", "amber", "blade" };
    abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);

    target = "leetcode";
    dictionary = { "lyftcode", "leetcold", "litecode", "lietcode", "leetccod", "lyftcold" };
    abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);

    target = "abcdefghijklmnop";
    dictionary = { };
    abbr = leetCode.minAbbreviation(target, dictionary);
    Logger::WriteMessage("target = " + target);
    Logger::WriteMessage(dictionary);
    Logger::WriteMessage("abbreviation = " + abbr);
}

void TestLeetCode488(void)
{
    Logger::WriteMessage("Test Leet Code 488");
    LeetCodeDFS leetCode;
    string board = "RBBRYRWWYYWRYY";
    string hand = "RYBBR";
    int min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));


    board = "WRRBBW";
    hand = "RB";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

    board = "WWRRBBWW";
    hand = "WRBRW";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

    board = "G";
    hand = "GGGGG";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));

    board = "RBYYBBRRB";
    hand = "YRBGB";
    min_steps = leetCode.findMinStep(board, hand);
    Logger::WriteMessage("board = " + board + "; hand = " + hand + "; min_steps = " + to_string(min_steps));
}

void TestLeetCode465(void)
{
    Logger::WriteMessage("Test Leet Code 465");
    LeetCodeDFS leetCode;
    vector<vector<int>> transactions = { { 2, 0, 5 },{ 3, 4, 4 } };
    int result = leetCode.minTransfers(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("min transfers = " + to_string(result));

    transactions = { { 0,1,10 },{ 2,0,5 } };
    result = leetCode.minTransfers(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("min transfers = " + to_string(result));

    transactions = { {0,1,10},{1,0,1},{1,2,5},{2,0,5} };
    result = leetCode.minTransfers(transactions);
    Logger::WriteMessage(transactions);
    Logger::WriteMessage("min transfers = " + to_string(result));
}

void TestLeetCode472(void)
{
    Logger::WriteMessage("Test Leet Code 472");
    LeetCodeDFS leetCode;
    vector<string> words = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
    vector<string> result = leetCode.findAllConcatenatedWordsInADict(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    words = { "" };
    result = leetCode.findAllConcatenatedWordsInADict(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode351(void)
{
    Logger::WriteMessage("Test Leet Code 351");
    LeetCodeDFS leetCode;
    int m = 1;
    int n = 2;
    int result = leetCode.numberOfPatterns(m, n);
    Logger::WriteMessage("m = " + to_string(m) + ";n = " + to_string(n) + ";result =" + to_string(result));
}

void TestLeetCode546(void)
{
    LeetCodeDFS leetCode;
    vector<int> boxes = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
    int max_score = leetCode.removeBoxes(boxes);
    Logger::WriteMessage(boxes);
    Logger::WriteMessage("Maximum Score = " + to_string(max_score));
}

void TestLeetCode638(void)
{
    LeetCodeDFS leetCode;
    vector<int> prices = { 2, 5 };
    vector<vector<int>> special = { { 3, 0, 5 },{ 1, 2, 10 } };
    vector<int> needs = { 3, 2 };
    Logger::WriteMessage(prices);
    Logger::WriteMessage(special);
    Logger::WriteMessage(needs);
    int min_price = leetCode.shoppingOffers(prices, special, needs);
    Logger::WriteMessage("min_price:" + to_string(min_price));

    prices = { 2, 3, 4 };
    special = { { 1, 1, 0, 4 },{ 2, 2, 1, 9 } };
    needs = { 1, 2, 1 };
    Logger::WriteMessage(prices);
    Logger::WriteMessage(special);
    Logger::WriteMessage(needs);
    min_price = leetCode.shoppingOffers(prices, special, needs);
    Logger::WriteMessage("min_price:" + to_string(min_price));
}

void TestLeetCode698(void)
{
    LeetCodeDFS leetCode;
    vector<int> nums = { 4, 3, 2, 3, 5, 2, 2 };
    int k = 4;
    bool result = leetCode.canPartitionKSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + (string)(result ? "true" : " false"));
}

void TestLeetCode691(void)
{
    LeetCodeDFS leetCode;

    vector<string> stickers = { "old", "center", "shape", "fig", "skin", "come" };
    Logger::WriteMessage(stickers);
    string target = "togethernear";
    Logger::WriteMessage("target = " + target);
    int result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "city", "would", "feel", "effect", "cell", "paint" };
    Logger::WriteMessage(stickers);
    target = "putcat";
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "these", "guess", "about", "garden", "him" };
    Logger::WriteMessage(stickers);
    target = "atomher";
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "with", "example", "science" };
    Logger::WriteMessage(stickers);
    target = "thehat";
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage("result = " + to_string(result));

    stickers = { "notice", "possible" };
    target = "basicbasic";
    Logger::WriteMessage(stickers);
    Logger::WriteMessage("target = " + target);
    result = leetCode.minStickers(stickers, target);
    Logger::WriteMessage(stickers);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode681(void)
{
    LeetCodeDFS leetCode;
    string time = "19:34";
    string next_time = leetCode.nextClosestTime(time);
    Logger::WriteMessage("time = " + time + "; next time = " + next_time);

    time = "23:59";
    next_time = leetCode.nextClosestTime(time);
    Logger::WriteMessage("time = " + time + "; next time = " + next_time);
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

void TestLeetCode2151(void)
{
    Logger::WriteMessage("Test Leet Code 2151");
    LeetCodeDFS leetCode;
    vector<vector<int>> statements =
    {
        {2, 1, 2},{1, 2, 2},{2, 0, 2}
    };
    int result = leetCode.maximumGood(statements);
    Logger::WriteMessage(statements);
    Logger::WriteMessage("result = " + to_string(result));

    statements =
    {
        {2,0},{0,2}
    };
    result = leetCode.maximumGood(statements);
    Logger::WriteMessage(statements);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2172(void)
{
    Logger::WriteMessage("Test Leet Code 2172");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    int numSlots = 3;
    int result = leetCode.maximumANDSum(nums, numSlots);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("numSlots = " + to_string(numSlots) + "; result = " + to_string(result));

    nums = { 1, 3, 10, 4, 7, 1 };
    numSlots = 9;
    result = leetCode.maximumANDSum(nums, numSlots);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("numSlots = " + to_string(numSlots) + "; result = " + to_string(result));
}

void TestLeetCode2174(void)
{
    Logger::WriteMessage("Test Leet Code 2174");
    LeetCodeDFS leetCode;
    vector<vector<int>> grid = { {1, 1, 1},{1, 1, 1},{0, 1, 0} };
    int result = leetCode.removeOnes(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 1, 0},{1, 0, 1},{0, 1, 0} };
    result = leetCode.removeOnes(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {0, 0},{0, 0} };
    result = leetCode.removeOnes(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2189(void)
{
    Logger::WriteMessage("Test Leet Code 2189");
    LeetCodeDFS leetCode;
    int n = 16;
    int result = leetCode.houseOfCards(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.houseOfCards(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4;
    result = leetCode.houseOfCards(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2212(void)
{
    Logger::WriteMessage("Test Leet Code 2212");
    LeetCodeDFS leetCode;
    int numArrows = 9;
    vector<int> aliceArrows = { 1, 1, 0, 1, 0, 0, 2, 1, 0, 1, 2, 0 };
    vector<int> result = leetCode.maximumBobPoints(numArrows, aliceArrows);
    Logger::WriteMessage(aliceArrows);
    Logger::WriteMessage(result);

    numArrows = 3;
    aliceArrows = { 0,0,1,0,0,0,0,0,0,0,0,2 };
    result = leetCode.maximumBobPoints(numArrows, aliceArrows);
    Logger::WriteMessage(aliceArrows);
    Logger::WriteMessage(result);
}

void TestLeetCode2232(void)
{
    Logger::WriteMessage("Test Leet Code 2232");
    LeetCodeDFS leetCode;
    string expression = "247+38";
    string result = leetCode.minimizeResult(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "12+34";
    result = leetCode.minimizeResult(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "999+999";
    result = leetCode.minimizeResult(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);
}

void TestLeetCode2305(void)
{
    Logger::WriteMessage("Test Leet Code 2305");
    LeetCodeDFS leetCode;
    vector<int> cookies = { 8, 15, 10, 20, 8 };
    int k = 2;
    int result = leetCode.distributeCookies(cookies, k);
    Logger::WriteMessage(cookies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    cookies = { 6,1,3,2,2,4,1,2 };
    k = 3;
    result = leetCode.distributeCookies(cookies, k);
    Logger::WriteMessage(cookies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    cookies = { 6,1,3,2,2,4,1,2 };
    k = 8;
    result = leetCode.distributeCookies(cookies, k);
    Logger::WriteMessage(cookies);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2403(void)
{
    Logger::WriteMessage("Test Leet Code 2403");
    LeetCodeDFS leetCode;
    vector<int> power = { 3, 1, 4 };
    long long result = leetCode.minimumTime(power);
    Logger::WriteMessage(power);
    Logger::WriteMessage("result = " + to_string(result));

    power = { 1,1,4 };
    result = leetCode.minimumTime(power);
    Logger::WriteMessage(power);
    Logger::WriteMessage("result = " + to_string(result));

    power = { 1, 2, 4, 9 };
    result = leetCode.minimumTime(power);
    Logger::WriteMessage(power);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode784(void)
{
    Logger::WriteMessage("Test Leet Code 784");
    LeetCodeDFS leetCode;
    string S = "a1b2";
    vector<string> result = leetCode.letterCasePermutation(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "3z4";
    result = leetCode.letterCasePermutation(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "12345";
    result = leetCode.letterCasePermutation(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode282(void)
{
    Logger::WriteMessage("Test Leet Code 282");
    LeetCodeDFS leetCode;

    string num = "232";
    int target = 8;
    vector<string> result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);

    num = "123";
    target = 6;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);


    num = "105";
    target = 5;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);

    num = "00";
    target = 0;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);

    num = "3456237490";
    target = 9191;
    result = leetCode.addOperators(num, target);
    Logger::WriteMessage("num = " + num + "," + to_string(target) + " -> ");
    Logger::WriteMessage(result);
}

void TestLeetCode2572(void)
{
    Logger::WriteMessage("Test Leet Code 2572");
    LeetCodeDFS leetCode;

    vector<int> nums = { 3, 4, 4, 5 };
    int result = leetCode.squareFreeSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1 };
    result = leetCode.squareFreeSubsets(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2597(void)
{
    Logger::WriteMessage("Test Leet Code 2597");
    LeetCodeDFS leetCode;

    vector<int> nums = { 2, 4, 6 };
    int k = 2;
    int result = leetCode.beautifulSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    nums = {1 };
    k = 1;
    result = leetCode.beautifulSubsets(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode2664(void)
{
    Logger::WriteMessage("Test Leet Code 2664");
    LeetCodeDFS leetCode;
    int m = 1, n = 1, r = 0, c = 0;
    vector<vector<int>> result = leetCode.tourOfKnight(m, n, r, c);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; r = " + to_string(r) + "; c = " + to_string(c));
    Logger::WriteMessage(result);

    m = 3, n = 4, r = 0, c = 0;
    result = leetCode.tourOfKnight(m, n, r, c);
    Logger::WriteMessage("m = " + to_string(m) + "; n = " + to_string(n) + "; r = " + to_string(r) + "; c = " + to_string(c));
    Logger::WriteMessage(result);
}

void TestLeetCode2741(void)
{
    Logger::WriteMessage("Test Leet Code 2741");
    LeetCodeDFS leetCode;
    vector<int> nums = { 2, 3, 6 };
    int result = leetCode.specialPerm(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,4,3 };
    result = leetCode.specialPerm(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2787(void)
{
    Logger::WriteMessage("Test Leet Code 2787");
    LeetCodeDFS leetCode;
    int n = 10, x = 2;
    int result = leetCode.numberOfWays(n, x);
    Logger::WriteMessage("n = " + to_string(n) + "; x = " + to_string(x));
    Logger::WriteMessage("result = " + to_string(result));

    n = 4, x = 1;
    result = leetCode.numberOfWays(n, x);
    Logger::WriteMessage("n = " + to_string(n) + "; x = " + to_string(x));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode756(void)
{
    Logger::WriteMessage("Test Leet Code 756");
    LeetCodeDFS leetCode;
    string bottom = "XYZ";
    vector<string> allowed = { "XYD", "YZE", "DEA", "FFF" };
    bool result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));

    bottom = "XXYX";
    allowed = { "XXX", "XXY", "XYX", "XYY", "YXZ" };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));


    bottom = "ABDBACAAAC";
    allowed =
    {
        "ACC", "AAC", "AAB", "BCB", "BAD", "CAC", "CCD", "CAA", "CCB", "DAD", "ACD", "DCB", "ABB", "BDA", "BDC",
        "BDB", "BBD", "BBC", "BBB", "ADB", "ADC", "DDC", "DDB", "CDD", "CBC", "CBA", "CBD", "CDC", "DBC"
    };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));

    bottom = "AABCCBABBB";
    allowed =
    {
        "AAA", "AAB", "BCD", "BCA", "BCB", "BAD", "BAB", "BAA", "CCD", "BDD", "CCA", "CAA", "CAD", "DAD", "DAA", "DAC",
        "DCD", "DCB", "DCA", "CDD", "ABA", "ABB", "BBC", "BBB", "BBA", "ADC", "CBB", "CBA", "CDB", "CDC", "DBC", "DBB"
    };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));

    bottom = "AAAA";
    allowed =
    {
        "AAB", "AAC", "BCD", "BBE", "DEF"
    };
    result = leetCode.pyramidTransition(bottom, allowed);
    Logger::WriteMessage(allowed);
    Logger::WriteMessage("bottom = " + bottom + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode753(void)
{
    Logger::WriteMessage("Test Leet Code 753");
    LeetCodeDFS leetCode;
    int n = 1, k = 2;
    string result = leetCode.crackSafe(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);

    n = 2, k = 2;
    result = leetCode.crackSafe(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode2801(void)
{
    Logger::WriteMessage("Test Leet Code 2801");
    LeetCodeDFS leetCode;
    string low = "1", high = "11";
    int result = leetCode.countSteppingNumbers(low,high);
    Logger::WriteMessage("low = " + low + "; high = " + high);
    Logger::WriteMessage("result = " + to_string(result));

    low = "90", high = "101";
    result = leetCode.countSteppingNumbers(low, high);
    Logger::WriteMessage("low = " + low + "; high = " + high);
    Logger::WriteMessage("result = " + to_string(result));

    low = "1", high = "200";
    result = leetCode.countSteppingNumbers(low, high);
    Logger::WriteMessage("low = " + low + "; high = " + high);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2827(void)
{
    Logger::WriteMessage("Test Leet Code 2827");
    LeetCodeDFS leetCode;
    int low = 10, high = 20, k = 3;
    int result = leetCode.numberOfBeautifulIntegers(low, high, k);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    low = 1, high = 10, k = 1;
    result = leetCode.numberOfBeautifulIntegers(low, high, k);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    low = 5, high = 5, k = 2;
    result = leetCode.numberOfBeautifulIntegers(low, high, k);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2850(void)
{
    Logger::WriteMessage("Test Leet Code 2850");
    LeetCodeDFS leetCode;
    vector<vector<int>> grid = { {1, 1, 0},{1, 1, 1},{1, 2, 1} };
    int result = leetCode.minimumMoves(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));

    grid = { {1, 3, 0},{1, 0, 0},{1, 0, 3} };
    result = leetCode.minimumMoves(grid);
    Logger::WriteMessage(grid);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode2868(void)
{
    Logger::WriteMessage("Test Leet Code 2868");
    LeetCodeDFS leetCode;
    vector<string> a = { "avokado", "dabar" };
    vector<string> b = { "brazil" };
    bool result = leetCode.canAliceWin(a, b);
    Logger::WriteMessage(a);
    Logger::WriteMessage(b);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    a = { "ananas","atlas","banana" };
    b = { "albatros","cikla","nogomet" };
    result = leetCode.canAliceWin(a, b);
    Logger::WriteMessage(a);
    Logger::WriteMessage(b);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
   
    a = { "hrvatska", "zastava" };
    b = { "bijeli", "galeb" };
    result = leetCode.canAliceWin(a, b);
    Logger::WriteMessage(a);
    Logger::WriteMessage(b);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode2992(void)
{
    Logger::WriteMessage("Test Leet Code 2992");
    LeetCodeDFS leetCode;
    int n = 1;
    int result = leetCode.selfDivisiblePermutationCount(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.selfDivisiblePermutationCount(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    result = leetCode.selfDivisiblePermutationCount(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode2999(void)
{
    Logger::WriteMessage("Test Leet Code 2999");
    LeetCodeDFS leetCode;
    long long start = 1, finish = 6000;
    int limit = 4;
    string s = "124";
    long long result = leetCode.numberOfPowerfulInt(start, finish, limit, s);
    Logger::WriteMessage("start = " + to_string(start) + "; finish = " + to_string(finish));
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    start = 15, finish = 215;
    limit = 6;
    s = "10";
    result = leetCode.numberOfPowerfulInt(start, finish, limit, s);
    Logger::WriteMessage("start = " + to_string(start) + "; finish = " + to_string(finish));
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    start = 1000, finish = 2000;
    limit = 4;
    s = "3000";
    result = leetCode.numberOfPowerfulInt(start, finish, limit, s);
    Logger::WriteMessage("start = " + to_string(start) + "; finish = " + to_string(finish));
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));
}

void TestLeetCode139(void)
{
    Logger::WriteMessage("Test Leet Code 139");
    LeetCodeDFS leetCode;
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    bool result = leetCode.wordBreakI(s, wordDict);
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("string = " + s + "; result = " + string(result ? "true" : "false"));

    s = "applepenapple";
    wordDict = { "apple", "pen" };
    result = leetCode.wordBreakI(s, wordDict);
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("string = " + s + "; result = " + string(result ? "true" : "false"));

    s = "catsandog";
    wordDict = { "cats", "dog", "sand", "and", "cat" };
    result = leetCode.wordBreakI(s, wordDict);
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("string = " + s + "; result = " + string(result ? "true" : "false"));
}

void TestLeetCode3040(void)
{
    Logger::WriteMessage("Test Leet Code 3040");
    LeetCodeDFS leetCode;
    vector<int> nums = { 3, 2, 1, 2, 3, 4 };
    int result = leetCode.maxOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,2,6,1,4 };
    result = leetCode.maxOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3149(void)
{
    Logger::WriteMessage("Test Leet Code 3149");
    LeetCodeDFS leetCode;
    vector<int> nums = { 1,0,2 };
    vector<int> result = leetCode.findPermutation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 0,2,1 };
    result = leetCode.findPermutation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);

    nums = { 0, 2, 3, 4, 1 };
    result = leetCode.findPermutation(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode3211(void)
{
    Logger::WriteMessage("Test Leet Code 3211");
    LeetCodeDFS leetCode;
    int n = 3;
    vector<string> result = leetCode.validStrings(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 1;
    result = leetCode.validStrings(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode3272(void)
{
    Logger::WriteMessage("Test Leet Code 3272");
    LeetCodeDFS leetCode;
    int n = 10, k = 5;
    long long result = leetCode.countGoodIntegers(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    n = 1, k = 4;
    result = leetCode.countGoodIntegers(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    n = 5, k = 6;
    result = leetCode.countGoodIntegers(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));

    n = 3, k = 5;
    result = leetCode.countGoodIntegers(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3376(void)
{
    Logger::WriteMessage("Test Leet Code 3376");
    LeetCodeDFS leetCode;
    vector<int> strength = { 3, 4, 1 };
    int K = 1;
    int result = leetCode.findMinimumTime(strength, K);
    Logger::WriteMessage(strength);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    strength = { 2,5,4 };
    K = 2;
    result = leetCode.findMinimumTime(strength, K);
    Logger::WriteMessage(strength);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    strength = { 7, 3, 6, 18, 22, 50 };
    K = 4;
    result = leetCode.findMinimumTime(strength, K);
    Logger::WriteMessage(strength);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode3437(void)
{
    Logger::WriteMessage("Test Leet Code 3437");
    LeetCodeDFS leetCode;
    int n = 4;
    vector<vector<int>> result = leetCode.permuteIII(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 2;
    result = leetCode.permuteIII(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 3;
    result = leetCode.permuteIII(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode3470(void)
{
    Logger::WriteMessage("Test Leet Code 3470");
    LeetCodeDFS leetCode;
    int n = 4;
    long long k = 6;
    vector<int> result = leetCode.permuteIV(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);

    n = 3;
    k = 2;
    result = leetCode.permuteIV(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);

    n = 2;
    k = 3;
    result = leetCode.permuteIV(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode3490(void)
{
    Logger::WriteMessage("Test Leet Code 3490");
    LeetCodeDFS leetCode;
    int l = 10;
    int r = 20;
    int result = leetCode.beautifulNumbers(l, r);
    Logger::WriteMessage("l = " + to_string(l) + "; r = " + to_string(r));
    Logger::WriteMessage("result = " + to_string(result));

    l = 1;
    r = 15;
    result = leetCode.beautifulNumbers(l, r);
    Logger::WriteMessage("l = " + to_string(l) + "; r = " + to_string(r));
    Logger::WriteMessage("result = " + to_string(result));

    l = 1;
    r = 100;
    result = leetCode.beautifulNumbers(l, r);
    Logger::WriteMessage("l = " + to_string(l) + "; r = " + to_string(r));
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3519(void)
{
    Logger::WriteMessage("Test Leet Code 3519");
    LeetCodeDFS leetCode;
    string l = "23", r = "28";
    int b = 8;
    int result = leetCode.countNumbers(l, r, b);
    Logger::WriteMessage("l = " + l + "; r = " + r);
    Logger::WriteMessage("b = " + to_string(b) + "; result = " + to_string(result));

    l = "2", r = "7";
    b = 2;
    result = leetCode.countNumbers(l, r, b);
    Logger::WriteMessage("l = " + l + "; r = " + r);
    Logger::WriteMessage("b = " + to_string(b) + "; result = " + to_string(result));
}

void TestLeetCode3518(void)
{
    Logger::WriteMessage("Test Leet Code 3518");
    LeetCodeDFS leetCode;
    string s = "abba";
    int k = 2;
    string result = leetCode.smallestPalindrome(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);

    s = "aa";
    k = 2;
    result = leetCode.smallestPalindrome(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);

    s = "bacab";
    k = 1;
    result = leetCode.smallestPalindrome(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);

    s = "baaaaaab";
    k = 3;
    result = leetCode.smallestPalindrome(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode3533(void)
{
    Logger::WriteMessage("Test Leet Code 3533");
    LeetCodeDFS leetCode;
    vector<int> nums = { 3, 12, 45 };
    int k = 5;
    vector<int> result = leetCode.concatenatedDivisibility(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums = { 10,5 };
    k = 10;
    result = leetCode.concatenatedDivisibility(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);

    nums = { 1,2,3 };
    k = 5;
    result = leetCode.concatenatedDivisibility(nums, k);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode3538(void)
{
    Logger::WriteMessage("Test Leet Code 3538");
    LeetCodeDFS leetCode;
    int l = 10, n = 4, k = 1;
    vector<int> position = { 0, 3, 8, 10 };
    vector<int> time = { 5, 8, 3, 6 };
    int result = leetCode.minTravelTime(l, n, k, position, time);
    Logger::WriteMessage("l = " + to_string(l) + "; n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(position);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));

    l = 5, n = 5, k = 1;
    position = { 0, 1, 2, 3, 5 };
    time = { 8, 3, 9, 3, 3 };
    result = leetCode.minTravelTime(l, n, k, position, time);
    Logger::WriteMessage("l = " + to_string(l) + "; n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(position);
    Logger::WriteMessage(time);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3565(void)
{
    Logger::WriteMessage("Test Leet Code 3565");
    LeetCodeDFS leetCode;
    vector<vector<int>> grid = { {0, 0, 0},{0, 1, 2} };
    int k = 2;
    vector<vector<int>> result = leetCode.findPath(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(result);

    grid = { { 1, 0, 4 }, { 3, 0, 2 } };
    k = 4;
    result = leetCode.findPath(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(result);

    grid = { {0, 1},{0, 2} };
    k = 2;
    result = leetCode.findPath(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(result);
    
    grid = { {0, 0, 4, 0},{0, 0, 3, 0},{0, 1, 0, 0},{5, 0, 0, 2} };
    k = 5;
    result = leetCode.findPath(grid, k);
    Logger::WriteMessage(grid);
    Logger::WriteMessage(result);
}

void TestLeetCode3594(void)
{
    Logger::WriteMessage("Test Leet Code 3594");
    LeetCodeDFS leetCode;
    int n = 1, k = 1, m = 2;
    vector<int> time = { 5 };
    vector<double> mul = { 1.0, 1.3 };
    double result = leetCode.minTime(n, k, m, time, mul);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; m = " + to_string(m));
    Logger::WriteMessage(time);
    Logger::WriteMessage(mul);
    Logger::WriteMessage("result = " + to_string(result));

    n = 3, k = 2, m = 3;
    time = { 2, 5, 8 };
    mul = { 1.0, 1.5, 0.75 };
    result = leetCode.minTime(n, k, m, time, mul);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; m = " + to_string(m));
    Logger::WriteMessage(time);
    Logger::WriteMessage(mul);
    Logger::WriteMessage("result = " + to_string(result));

    n = 2; k = 1, m = 2;
    time = { 10, 10 };
    mul = { 2.0, 2.0 };
    result = leetCode.minTime(n, k, m, time, mul);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; m = " + to_string(m));
    Logger::WriteMessage(time);
    Logger::WriteMessage(mul);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode3669(void)
{
    Logger::WriteMessage("Test Leet Code 3669");
    LeetCodeDFS leetCode;
    int n = 100, k = 2;
    vector<int> result = leetCode.minDifference(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);

    n = 44, k = 3;
    result = leetCode.minDifference(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k));
    Logger::WriteMessage(result);
}

void TestLeetCode3680(void)
{
    Logger::WriteMessage("Test Leet Code 3680");
    LeetCodeDFS leetCode;
    int n = 3;
    vector<vector<int>> result = leetCode.generateSchedule(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 5;
    result = leetCode.generateSchedule(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode3690(void)
{
    Logger::WriteMessage("Test Leet Code 3690");
    LeetCodeDFS leetCode;
    vector<int> nums1 = { 3, 1, 2 };
    vector<int> nums2 = { 1, 2, 3 };
    int result = leetCode.minSplitMerge(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 1, 1, 2, 3, 4, 5 };
    nums2 = { 5, 4, 3, 2, 1, 1 };
    result = leetCode.minSplitMerge(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));

    nums1 = { 81, 47, 1, 89 };
    nums2 = { 89, 1, 47, 81 };
    result = leetCode.minSplitMerge(nums1, nums2);
    Logger::WriteMessage(nums1);
    Logger::WriteMessage(nums2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCodeDFS(void)
{
    TestLeetCode3690();
    TestLeetCode3680();
    TestLeetCode3669();
    TestLeetCode3594();
    TestLeetCode3565();
    TestLeetCode3538();
    TestLeetCode3533();
    TestLeetCode3518();
    TestLeetCode3519();
    TestLeetCode3490();
    TestLeetCode3470();
    TestLeetCode3437();
    TestLeetCode3376();
    TestLeetCode3272();
    TestLeetCode3211();
    TestLeetCode3149();
    TestLeetCode140();
    TestLeetCode131();
    TestLeetCode1066();
    TestLeetCode3040();
    TestLeetCode139();
    TestLeetCode2999();
    TestLeetCode2992();
    TestLeetCode2868();
    TestLeetCode2850();
    TestLeetCode2801();
    TestLeetCode2827();
    TestLeetCode2787();
    TestLeetCode2741();
    TestLeetCode2664();
    TestLeetCode2597();
    TestLeetCode2572();
    TestLeetCode2403();
    TestLeetCode2305();
    TestLeetCode2232();
    TestLeetCode2212();
    TestLeetCode2189();
    TestLeetCode2174();
    TestLeetCode2172();
    TestLeetCode2151();
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
    TestLeetCode22();
    TestLeetCode784();
    TestLeetCode797();
    TestLeetCode756();
    TestLeetCode753();
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
    TestLeetCode679();
    TestLeetCode1397();
    TestLeetCode425();
    TestLeetCode212();
    TestLeetCode1349();
    TestLeetCode126();
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
    TestLeetCode1240();
    TestLeetCode1799();
    TestLeetCode93();
    TestLeetCode282();
    TestLeetCode216();
    TestLeetCode698();
    TestLeetCode638();
    TestLeetCode681();
    TestLeetCode267();
    TestLeetCode351();
    TestLeetCode472();
    TestLeetCode465();
    TestLeetCode488();
    TestLeetCode411();
    TestLeetCode291();
    TestLeetCode294();
    TestLeetCode9901();
    TestLeetCode320();
    TestLeetCode254();
    TestLeetCode301();
    TestLeetCode691();
    TestLeetCode546();
    TestLeetCode401();
}