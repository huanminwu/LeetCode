#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeString.h"
#include "TestString.h"
void TestLeetCode28(void)
{
    Logger::WriteMessage("Test Leet Code 28");
    LeetCodeString leetCode;

    Logger::WriteMessage("KMP substring search");
    string haystack = "ABCABCDABABCDABCDABDE";
    string needle = "ABCDABD";
    int result = leetCode.strStr(haystack, needle);
    Logger::WriteMessage("kaystack = " + haystack + "; needle = " + needle + "; result = " + to_string(result));

    haystack = "a";
    needle = "";
    result = leetCode.strStr(haystack, needle);
    Logger::WriteMessage("kaystack = " + haystack + "; needle = " + needle + "; result = " + to_string(result));

    haystack = "AAABCTTHHAAABCDD";
    needle = "AABC";
    result = leetCode.strStr(haystack, needle);
    Logger::WriteMessage("kaystack = " + haystack + "; needle = " + needle + "; result = " + to_string(result));
}

void TestLeetCode1233(void)
{
    Logger::WriteMessage("Test Leet Code 1233");
    LeetCodeString leetCode;
    vector<string> folders = { "/a","/a/b","/c/d","/c/d/e","/c/f" };
    vector<string> result = leetCode.removeSubfolders(folders);
    Logger::WriteMessage(folders);
    Logger::WriteMessage(result);

    folders = { "/a","/a/b/c","/a/b/d" };
    result = leetCode.removeSubfolders(folders);
    Logger::WriteMessage(folders);
    Logger::WriteMessage(result);

    folders = { "/a/b/c","/a/b/ca","/a/b/d" };
    result = leetCode.removeSubfolders(folders);
    Logger::WriteMessage(folders);
    Logger::WriteMessage(result);
}

void TestLeetCode1234(void)
{
    Logger::WriteMessage("Test Leet Code 1234");
    LeetCodeString leetCode;
    string s = "QWER";
    int result = leetCode.balancedString(s);
    Logger::WriteMessage("s = " + s +"; result = " + to_string(result));

    s = "QQWE";
    result = leetCode.balancedString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "QQQW";
    result = leetCode.balancedString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "QQQQ";
    result = leetCode.balancedString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "WWEQERQWQWWRWWERQWEQ";
    result = leetCode.balancedString(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1247(void)
{
    Logger::WriteMessage("Test Leet Code 1247");
    LeetCodeString leetCode;
    string s1 = "xx"; 
    string s2 = "yy";
    int result = leetCode.minimumSwap(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));

    s1 = "xy"; 
    s2 = "yx";
    result = leetCode.minimumSwap(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));

    s1 = "xx";
    s2 = "xy";
    result = leetCode.minimumSwap(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));

    s1 = "xxyyxyxyxx";
    s2 = "xyyxyxxxyx";
    result = leetCode.minimumSwap(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + to_string(result));
}

void TestLeetCode415(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 415");
    string num1 = "9876";
    string num2 = "200";
    string result = leetCode.addStrings(num1, num2);
    Logger::WriteMessage("num1 = " + num1 + "; num2 = " + num2 + "; result = " + result);
}

void TestLeetCode1268(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 1268");
    vector<string> products = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
    string searchWord = "mouse";
    vector<vector<string>> result = leetCode.suggestedProducts(products, searchWord);
    Logger::WriteMessage(products);
    Logger::WriteMessage("searchWord = " + searchWord);
    Logger::WriteMessage(result);

    products = { "havana" };
    searchWord = "havana";
    result = leetCode.suggestedProducts(products, searchWord);
    Logger::WriteMessage(products);
    Logger::WriteMessage("searchWord = " + searchWord);
    Logger::WriteMessage(result);

    products = { "bags","baggage","banner","box","cloths" };
    searchWord = "bags";
    result = leetCode.suggestedProducts(products, searchWord);
    Logger::WriteMessage(products);
    Logger::WriteMessage("searchWord = " + searchWord);
    Logger::WriteMessage(result);

    products = { "havana" };
    searchWord = "tatiana";
    result = leetCode.suggestedProducts(products, searchWord);
    Logger::WriteMessage(products);
    Logger::WriteMessage("searchWord = " + searchWord);
    Logger::WriteMessage(result);
}

void TestLeetCode1297(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 1297");
    string s = "aababcaab"; 
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    int result = leetCode.maxFreq(s, maxLetters, minSize, maxSize);
    Logger::WriteMessage("maxLetters = " + to_string(maxLetters) + 
        "minSize = " + to_string(minSize) + 
        "maxSize = " + to_string(maxSize) +
        "result = " + to_string(result));

    s = "aaaa";
    maxLetters = 1;
    minSize = 3;
    maxSize = 3;
    result = leetCode.maxFreq(s, maxLetters, minSize, maxSize);
    Logger::WriteMessage("maxLetters = " + to_string(maxLetters) +
        "minSize = " + to_string(minSize) +
        "maxSize = " + to_string(maxSize) +
        "result = " + to_string(result));

    s = "aabcabcab";
    maxLetters = 2;
    minSize = 2;
    maxSize = 3;
    result = leetCode.maxFreq(s, maxLetters, minSize, maxSize);
    Logger::WriteMessage("maxLetters = " + to_string(maxLetters) +
        "minSize = " + to_string(minSize) +
        "maxSize = " + to_string(maxSize) +
        "result = " + to_string(result));

    s = "abcde";
    maxLetters = 2;
    minSize = 3;
    maxSize = 3;
    result = leetCode.maxFreq(s, maxLetters, minSize, maxSize);
    Logger::WriteMessage("maxLetters = " + to_string(maxLetters) +
        "minSize = " + to_string(minSize) +
        "maxSize = " + to_string(maxSize) +
        "result = " + to_string(result));
}

void TestLeetCode1309(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 1309");
    string s = "10#11#12";
    string result = leetCode.freqAlphabets(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "1326#";
    result = leetCode.freqAlphabets(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "25#";
    result = leetCode.freqAlphabets(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#";
    result = leetCode.freqAlphabets(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1316(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 1316");
    string text = "abcabcabc";
    int result = leetCode.distinctEchoSubstrings(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "leetcodeleetcode";
    result = leetCode.distinctEchoSubstrings(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "aaaaaaaaaa";
    result = leetCode.distinctEchoSubstrings(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));
}

void TestLeetCode459(void)
{
    Logger::WriteMessage("Test Leet Code 459");
    LeetCodeString leetCode;
    string s;
    bool is_repeat;

    s = "abaababaab";
    Logger::WriteMessage("s = " + s);
    is_repeat = leetCode.repeatedSubstringPattern(s);
    Logger::WriteMessage("repeated substring is " + string((is_repeat ? "true" : "false")));

    s = "aabaaba";
    Logger::WriteMessage("s = " + s);
    is_repeat = leetCode.repeatedSubstringPattern(s);
    Logger::WriteMessage("repeated substring is " + string((is_repeat ? "true" : "false")));

    s = "abcabcabcabc";
    Logger::WriteMessage("s = " + s);
    is_repeat = leetCode.repeatedSubstringPattern(s);
    Logger::WriteMessage("repeated substring is " + string((is_repeat ? "true" : "false")));

    s = "ababababa";
    Logger::WriteMessage("s = " + s);
    is_repeat = leetCode.repeatedSubstringPattern(s);
    Logger::WriteMessage("repeated substring is " + string((is_repeat ? "true" : "false")));
}

void TestLeetCode686(void)
{
    LeetCodeString leetCode;
    string A = "abcd";
    string B = "cdabcdab";
    int repeat = leetCode.repeatedStringMatch(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; Repeat = " + to_string(repeat));

    A = "abcdabab";
    B = "ababc";
    repeat = leetCode.repeatedStringMatch(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; Repeat = " + to_string(repeat));

    A = "abcd";
    B = "cdabcdacdabcda";
    repeat = leetCode.repeatedStringMatch(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; Repeat = " + to_string(repeat));
}

void TestLeetCode796(void)
{
    Logger::WriteMessage("Test Leet Code 796");
    LeetCodeString leetCode;
    string A = "abcde";
    string B = "cdeab";
    bool result = leetCode.rotateString(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (result ? "true" : "false"));

    A = "abcde";
    B = "abced";
    result = leetCode.rotateString(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (result ? "true" : "false"));
}

void TestLeetCode1181(void)
{
    Logger::WriteMessage("Test Leet Code 1181");
    LeetCodeString leetCode;
    vector<string> phrases = { "writing code", "code rocks" };
    vector<string> result = leetCode.beforeAndAfterPuzzles(phrases);
    Logger::WriteMessage(phrases);
    Logger::WriteMessage(result);

    phrases =
    {
        "mission statement",
        "a quick bite to eat",
        "a chip off the old block",
        "chocolate bar",
        "mission impossible",
        "a man on a mission",
        "block party",
        "eat my words",
        "bar of soap"
    };
    result = leetCode.beforeAndAfterPuzzles(phrases);
    Logger::WriteMessage(phrases);
    Logger::WriteMessage(result);

    phrases = { "a","b","a" };
    result = leetCode.beforeAndAfterPuzzles(phrases);
    Logger::WriteMessage(phrases);
    Logger::WriteMessage(result);

    phrases = { "a b c", "c","a b", "b c" };
    result = leetCode.beforeAndAfterPuzzles(phrases);
    Logger::WriteMessage(phrases);
    Logger::WriteMessage(result);

    phrases = { "a", "a e f","a b", "b c" };
    result = leetCode.beforeAndAfterPuzzles(phrases);
    Logger::WriteMessage(phrases);
    Logger::WriteMessage(result);
}

void TestLeetCode1189(void)
{
    Logger::WriteMessage("Test Leet Code 1189");
    LeetCodeString leetCode;
    string text = "nlaebolko";
    int result = leetCode.maxNumberOfBalloons(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "loonbalxballpoon";
    result = leetCode.maxNumberOfBalloons(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));

    text = "leetcode";
    result = leetCode.maxNumberOfBalloons(text);
    Logger::WriteMessage("text = " + text + "; result = " + to_string(result));
}

void TestLeetCode1170(void)
{
    Logger::WriteMessage("Test Leet Code 1170");
    LeetCodeString leetCode;
    vector<string> queries = { "cbd" };
    vector<string> words = { "zaaaz" };
    vector<int> result = leetCode.numSmallerByFrequency(queries, words);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    queries = { "bbb","cc" };
    words = { "a","aa","aaa","aaaa" };
    result = leetCode.numSmallerByFrequency(queries, words);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode1165(void)
{
    Logger::WriteMessage("Test Leet Code 1165");
    LeetCodeString leetCode;
    string keyboard = "abcdefghijklmnopqrstuvwxyz";
    string word = "cba";
    int result = leetCode.calculateTime(keyboard, word);
    Logger::WriteMessage("keyboard = " + keyboard + "; word = " + word + "; result = " + to_string(result));

    keyboard = "pqrstuvwxyzabcdefghijklmno";
    word = "leetcode";
    result = leetCode.calculateTime(keyboard, word);
    Logger::WriteMessage("keyboard = " + keyboard + "; word = " + word + "; result = " + to_string(result));
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

void TestLeetCode830(void)
{
    Logger::WriteMessage("Test Leet Code 830");
    LeetCodeString leetCode;
    string S = "abbxxxxzzy";
    vector<vector<int>> result = leetCode.largeGroupPositions(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "abc";
    result = leetCode.largeGroupPositions(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "abcdddeeeeaabbbcd";
    result = leetCode.largeGroupPositions(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "abcdddeeee";
    result = leetCode.largeGroupPositions(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode58(void)
{
    Logger::WriteMessage("Test Leet Code 58");
    string sentence = "a";
    LeetCodeString leetCode;
    int length = leetCode.lengthOfLastWord(sentence);
    Logger::WriteMessage("The length of last word in " + sentence + " is " + to_string(length));
}

void TestLeetCode165(void)
{
    Logger::WriteMessage("Test Leet Code 165");
    LeetCodeString leetCode;
    string version1 = "1.2.3";
    string version2 = "1.2";
    int result = leetCode.compareVersion(version1, version2);
    Logger::WriteMessage("Verion1 = " + version1 + ", Version2 = " + version2 + "; Result = " + to_string(result));
}

void TestLeetCode71(void)
{
    Logger::WriteMessage("Test Leet Code 71");
    LeetCodeString leetCode;
    string path = "/home/";
    string result = leetCode.simplifyPath(path);
    Logger::WriteMessage("path = " + path + "; result = " + result);

    path = "/../";
    result = leetCode.simplifyPath(path);
    Logger::WriteMessage("path = " + path + "; result = " + result);

    path = "/home//foo/";
    result = leetCode.simplifyPath(path);
    Logger::WriteMessage("path = " + path + "; result = " + result);

    path = "/a/./b/../../c/";
    result = leetCode.simplifyPath(path);
    Logger::WriteMessage("path = " + path + "; result = " + result);

    path = "/a/../../b/../c//.//";
    result = leetCode.simplifyPath(path);
    Logger::WriteMessage("path = " + path + "; result = " + result);

    path = "/a//b////c/d//././/..";
    result = leetCode.simplifyPath(path);
    Logger::WriteMessage("path = " + path + "; result = " + result);
}

void TestLeetCode151(void)
{
    Logger::WriteMessage("Test Leet Code 151");
    LeetCodeString leetCode;
    string s = "the sky is blue";
    string result = leetCode.reverseWords(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "  hello world!  ";
    result = leetCode.reverseWords(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode186(void)
{
    Logger::WriteMessage("Test Leet Code 186");
    LeetCodeString leetCode;
    string s = "the sky is blue";
    Logger::WriteMessage("s = " + s);
    leetCode.reverseWordsII(s);
    Logger::WriteMessage("reverse = " + s);
}

void TestLeetCodeString(void)
{
    TestLeetCode151();
    TestLeetCode186();
    TestLeetCode71();
    TestLeetCode165();
    TestLeetCode58();
    TestLeetCode830();
    TestLeetCode288();
    TestLeetCode1165();
    TestLeetCode1170();
    TestLeetCode1181();
    TestLeetCode1189();
    TestLeetCode796();
    TestLeetCode686();
    TestLeetCode459();
    TestLeetCode1316();
    TestLeetCode28();
    TestLeetCode1309();
    TestLeetCode1297();
    TestLeetCode1268();
    TestLeetCode415();
    TestLeetCode1247();
    TestLeetCode1234();
    TestLeetCode1233();
}
