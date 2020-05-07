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

void TestLeetCode344(void)
{
    Logger::WriteMessage("Test Leet Code 344");
    LeetCodeString leetCode;
    string s("Hello");
    string r = leetCode.reverseString(s);
    Logger::WriteMessage("Reverse " + s + " = " + r);
}

void TestLeetCode14(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 14");
    vector<string> wordList = { "abcd", "abcde" };
    Logger::WriteMessage(wordList);
    string message;
    string prefix = leetCode.longestCommonPrefix(wordList);
    message.assign("The longest common prefix string is: " + prefix);
    Logger::WriteMessage(message.c_str());
}

void TestLeetCode68(void)
{
    Logger::WriteMessage("Test Leet Code 68");
    LeetCodeString leetCode;
    vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
    int line_width = 16;
    vector<string> result = leetCode.fullJustify(words, line_width);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Line width = " + to_string(line_width));
    Logger::WriteMessage(result);

    words = { "Listen", "to", "many,", "speak", "to", "a", "few." };
    line_width = 6;
    result = leetCode.fullJustify(words, 6);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Line width = " + to_string(line_width));
    Logger::WriteMessage(result);

    words = { "a", "b", "c", "d", "e" };
    line_width = 3;
    result = leetCode.fullJustify(words, 3);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Line width = " + to_string(line_width));
    Logger::WriteMessage(result);
}

void TestLeetCode76(void)
{
    Logger::WriteMessage("Test Leet Code 76");
    LeetCodeString leetCode;
    string s, t, min_window;
    s = "ADOBECODEBANC";
    t = "ABC";
    min_window = leetCode.minWindow(s, t);
    Logger::WriteMessage("s = " + s + ";t = " + t + ";min_window=" + min_window);
    min_window = leetCode.minWindow(s, t);
    Logger::WriteMessage("s = " + s + ";t = " + t + ";min_window=" + min_window);
    s = "AA";
    t = "AA";
    min_window = leetCode.minWindow(s, t);
    Logger::WriteMessage("s = " + s + ";t = " + t + ";min_window=" + min_window);
    min_window = leetCode.minWindow(s, t);
    Logger::WriteMessage("s = " + s + ";t = " + t + ";min_window=" + min_window);
}

void TestLeetCode242(void)
{
    Logger::WriteMessage("Test Leet Code 242");
    LeetCodeString leetCode;
    string s = "anagram";
    string t = "nagaram";
    string message;
    bool isAnagram = leetCode.isAnagram(s, t);
    message = s + " and " + t + (isAnagram ? " is " : " is not ") + "Anagram";
    Logger::WriteMessage(message);
}

void TestLeetCode3(void)
{
    Logger::WriteMessage("Test Leet Code 3");
    LeetCodeString leetCode;
    string s = "abcabcbb";
    int result = leetCode.lengthOfLongestSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "bbbbb";
    result = leetCode.lengthOfLongestSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "pwwkew";
    result = leetCode.lengthOfLongestSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode383(void)
{
    Logger::WriteMessage("Test Leet Code 383");
    LeetCodeString leetCode;
    string ransomNote = "a"; 
    string magazine = "b";
    bool result = leetCode.canConstruct(ransomNote, magazine);
    Logger::WriteMessage("ransomNote = " + ransomNote + "; magazine = " + magazine + 
        "; result = " + (string)(result ? "true" : "false"));
    
    ransomNote = "aa";
    magazine = "ab";
    result = leetCode.canConstruct(ransomNote, magazine);
    Logger::WriteMessage("ransomNote = " + ransomNote + "; magazine = " + magazine +
        "; result = " + (string)(result ? "true" : "false"));
    
    ransomNote = "aa";
    magazine = "aab";
    result = leetCode.canConstruct(ransomNote, magazine);
    Logger::WriteMessage("ransomNote = " + ransomNote + "; magazine = " + magazine +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode387(void)
{
    Logger::WriteMessage("Test Leet Code 387");
    LeetCodeString leetCode;
    int index;

    string s;
    s = "leetcode";
    index = leetCode.firstUniqChar(s);
    Logger::WriteMessage("The index of first unique character in " + s + " is " + to_string(index));

    s = "loveleetcode";
    index = leetCode.firstUniqChar(s);
    Logger::WriteMessage("The index of first unique character in " + s + " is " + to_string(index));
}

void TestLeetCode423(void)
{
    Logger::WriteMessage("Test Leet Code 423");
    LeetCodeString leetCode;
    string s, result;
    s = "owoztneoer";
    result = leetCode.originalDigits(s);
    Logger::WriteMessage("String = " + s + "; Result = " + result);
    s = "fviefuro";
    result = leetCode.originalDigits(s);
    Logger::WriteMessage("String = " + s + "; Result = " + result);
    s = "nnei";
    result = leetCode.originalDigits(s);
    Logger::WriteMessage("String = " + s + "; Result = " + result);
}

void TestLeetCode434(void)
{
    Logger::WriteMessage("Test Leet Code 434");
    LeetCodeString leetCode;
    string s;
    int result;
    s = "   Hello, my name is John   ";
    result = leetCode.countSegments(s);
    Logger::WriteMessage("String = " + s + "; segments = " + to_string(result));
}

void TestLeetCode438(void)
{
    Logger::WriteMessage("Test Leet Code 438");
    LeetCodeString leetCode;
    string s, p;
    vector<int> result;
    s = "cbaebabacd";
    p = "abc";
    Logger::WriteMessage("s = " + s + " p= " + p);
    result = leetCode.findAnagrams(s, p);
    Logger::WriteMessage(result);
    s = "abab";
    p = "ab";
    Logger::WriteMessage("s = " + s + " p= " + p);
    result = leetCode.findAnagrams(s, p);
    Logger::WriteMessage(result);
}

void TestLeetCode468(void)
{
    Logger::WriteMessage("Test Leet Code 468");
    LeetCodeString leetCode;
    string IP = "172.16.254.1";
    string result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);

    IP = "172.16.254.01";
    result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);

    IP = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);

    IP = "2001:db8:85a3:0:0:8A2E:0370:7334";
    result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);

    IP = "2001:0db8:85a3::8A2E:0370:7334";
    result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);

    IP = "02001:0db8:85a3:0000:0000:8a2e:0370:7334";
    result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);

    IP = "256.256.256.256";
    result = leetCode.validIPAddress(IP);
    Logger::WriteMessage("IP = " + IP + "; Result = " + result);
}

void TestLeetCode520(void)
{
    Logger::WriteMessage("Test Leet Code 520");
    LeetCodeString leetCode;
    string word = "USA";
    bool result = leetCode.detectCapitalUse(word);
    Logger::WriteMessage("word = " + word + "; " + (string)(result ? "true" : "false"));

    word = "FlaG";
    result = leetCode.detectCapitalUse(word);
    Logger::WriteMessage("word = " + word + "; " + (string)(result ? "true" : "false"));
}

void TestLeetCode49(void)
{
    Logger::WriteMessage("Test Leet Code 49");
    LeetCodeString leetCode;
    vector<string> str_list;
    vector<vector<string>> result;
    str_list = { "eat", "tea", "tan", "ate", "nat", "bat" };
    Logger::WriteMessage(str_list);
    result = leetCode.groupAnagrams(str_list);
    for (size_t i = 0; i < result.size(); i++)
    {
        Logger::WriteMessage(result[i]);
    }
}

void TestLeetCode1178(void)
{
    Logger::WriteMessage("Test Leet Code 1178");
    LeetCodeString leetCode;
    vector<string> words = { "aaaa","asas","able","ability","actt","actor","access" };
    vector<string> puzzles = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
    vector<int> result = leetCode.findNumOfValidWords(words, puzzles);
    Logger::WriteMessage(words);
    Logger::WriteMessage(puzzles);
    Logger::WriteMessage(result);
}

void TestLeetCode227(void)
{
    Logger::WriteMessage("Test Leet Code 227");
    LeetCodeString leetCode;
    string expression = "100000000/1/2/3/4/5/6/7/8/9/10";
    int result = leetCode.calculateII(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = "3+2*2";
    result = leetCode.calculateII(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = " 3/2 ";
    result = leetCode.calculateII(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = " 3+5 / 2 ";
    result = leetCode.calculateII(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = "1*2-3/4+5*6";
    result = leetCode.calculateII(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
}

/// <summary>
/// Leet code #224. Basic Calculator    
/// Implement a basic calculator to evaluate a simple expression string.
/// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
/// You may assume that the given expression is always valid. 
/// Some examples:
/// "1 + 1" = 2
/// " 2-1 + 2 " = 3
/// "(1+(4+5+2)-3)+(6+8)" = 23	
/// </summary>
void TestLeetCode224(void)
{
    Logger::WriteMessage("Test Leet Code 224");
    LeetCodeString  leetCode;
    string expression = "1+1";
    int result = leetCode.calculate(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = "2-1+2";
    result = leetCode.calculate(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = "(1+(14+5+2)-3)+(6+8)";
    result = leetCode.calculate(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = "(5-(1+2)+3)";
    result = leetCode.calculate(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
    expression = "(5)+1";
    result = leetCode.calculate(expression);
    Logger::WriteMessage(expression + "=" + to_string(result));
}

void TestLeetCode772(void)
{
    Logger::WriteMessage("Test Leet Code 772");
    LeetCodeString leetCode;
    string s = "1 + 1";
    int result = leetCode.calculateIII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "6-4 / 2 ";
    result = leetCode.calculateIII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "2*(5+5*2)/3+(6/2+8)";
    result = leetCode.calculateIII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "(2+6* 3+5- (3*14/7+2)*5)+3";
    result = leetCode.calculateIII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode770(void)
{
    Logger::WriteMessage("Test Leet Code 770");
    LeetCodeString leetCode;
    string expression = "e + 8 - a + 5";
    vector<string> evalvars = { "e" };
    vector<int> evalints = { 1 };
    vector<string> result = leetCode.basicCalculatorIV(expression, evalvars, evalints);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(evalvars);
    Logger::WriteMessage(evalints);
    Logger::WriteMessage(result);

    expression = "e - 8 + temperature - pressure";
    evalvars = { "e", "temperature" };
    evalints = { 1, 12 };
    result = leetCode.basicCalculatorIV(expression, evalvars, evalints);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(evalvars);
    Logger::WriteMessage(evalints);
    Logger::WriteMessage(result);

    expression = "(e + 8) * (e - 8)";
    evalvars = { };
    evalints = { };
    result = leetCode.basicCalculatorIV(expression, evalvars, evalints);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(evalvars);
    Logger::WriteMessage(evalints);
    Logger::WriteMessage(result);

    expression = "7 - 7";
    evalvars = {};
    evalints = {};
    result = leetCode.basicCalculatorIV(expression, evalvars, evalints);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(evalvars);
    Logger::WriteMessage(evalints);
    Logger::WriteMessage(result);

    expression = "a * b * c + b * a * c * 4";
    evalvars = {};
    evalints = {};
    result = leetCode.basicCalculatorIV(expression, evalvars, evalints);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(evalvars);
    Logger::WriteMessage(evalints);
    Logger::WriteMessage(result);

    expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))";
    evalvars = {};
    evalints = {};
    result = leetCode.basicCalculatorIV(expression, evalvars, evalints);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(evalvars);
    Logger::WriteMessage(evalints);
    Logger::WriteMessage(result);
}

void TestLeetCode388(void)
{
    Logger::WriteMessage("Test Leet Code 388");
    LeetCodeString leetCode;
    string s = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int max_length = leetCode.lengthLongestPath(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("absolute path = " + to_string(max_length));

    s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    max_length = leetCode.lengthLongestPath(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("absolute path = " + to_string(max_length));
}

void TestLeetCode424(void)
{
    Logger::WriteMessage("Test Leet Code 424");
    LeetCodeString leetCode;
    string s = "AABABBA";
    int k = 1;
    int max_length = leetCode.characterReplacement(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + ";max length = " + to_string(max_length));

    s = "ABAB";
    k = 2;
    max_length = leetCode.characterReplacement(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + ";max length = " + to_string(max_length));
}

void TestLeetCode395(void)
{
    Logger::WriteMessage("Test Leet Code 395");
    LeetCodeString leetCode;
    string s = "aaabb";
    int k = 3;
    int result = leetCode.longestSubstring(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "ababbc";
    k = 2;
    result = leetCode.longestSubstring(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1160(void)
{
    Logger::WriteMessage("Test Leet Code 1160");
    LeetCodeString leetCode;
    vector<string> words = { "cat", "bt", "hat", "tree" };
    string chars = "atach";
    int result = leetCode.countCharacters(words, chars);
    Logger::WriteMessage(words);
    Logger::WriteMessage("chars = " + chars + "result = " + to_string(result));

    words = { "hello","world","leetcode" };
    chars = "welldonehoneyr";
    result = leetCode.countCharacters(words, chars);
    Logger::WriteMessage(words);
    Logger::WriteMessage("chars = " + chars + "result = " + to_string(result));
}

void TestLeetCode1119(void)
{
    Logger::WriteMessage("Test Leet Code 1119");
    LeetCodeString leetCode;
    string S = "leetcodeisacommunityforcoders";
    string result = leetCode.removeVowels(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "aeiou";
    result = leetCode.removeVowels(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode1106(void)
{
    Logger::WriteMessage("Test Leet Code 1106");
    LeetCodeString leetCode;
    string expression = "!(f)";
    bool result = leetCode.parseBoolExpr(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + (string)(result ? "true" : "false"));

    expression = "|(f,t)";
    result = leetCode.parseBoolExpr(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + (string)(result ? "true" : "false"));

    expression = "&(t,f)";
    result = leetCode.parseBoolExpr(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + (string)(result ? "true" : "false"));

    expression = "|(&(t,f,t),!(t))";
    result = leetCode.parseBoolExpr(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1108(void)
{
    Logger::WriteMessage("Test Leet Code 1108");
    LeetCodeString leetCode;
    string address = "1.1.1.1";
    string result = leetCode.defangIPaddr(address);
    Logger::WriteMessage("address = " + address + "; result = " + result);

    address = "255.100.50.0";
    result = leetCode.defangIPaddr(address);
    Logger::WriteMessage("address = " + address + "; result = " + result);
}

void TestLeetCode1096(void)
{
    Logger::WriteMessage("Test Leet Code 1096");
    LeetCodeString leetCode;
    string expression = "{a,b}{c{d,e}}";
    vector<string> result = leetCode.braceExpansionII(expression);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(result);

    expression = "{{a,z},a{b,c},{ab,z}}";
    result = leetCode.braceExpansionII(expression);
    Logger::WriteMessage(expression);
    Logger::WriteMessage(result);
}

void TestLeetCode1111(void)
{
    Logger::WriteMessage("Test Leet Code 1111");
    LeetCodeString leetCode;
    string seq = "(()())";
    vector<int> result = leetCode.maxDepthAfterSplit(seq);
    Logger::WriteMessage("seq = " + seq);
    Logger::WriteMessage(result);

    seq = "()(())()";
    result = leetCode.maxDepthAfterSplit(seq);
    Logger::WriteMessage("seq = " + seq);
    Logger::WriteMessage(result);
}

void TestLeetCode1071(void)
{
    Logger::WriteMessage("Test Leet Code 1071");
    LeetCodeString leetCode;
    string str1 = "ABCABC";
    string str2 = "ABC";
    string result = leetCode.gcdOfStrings(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);

    str1 = "ABABAB";
    str2 = "ABAB";
    result = leetCode.gcdOfStrings(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);

    str1 = "ABABABAB";
    str2 = "ABAB";
    result = leetCode.gcdOfStrings(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);

    str1 = "LEET";
    str2 = "CODE";
    result = leetCode.gcdOfStrings(str1, str2);
    Logger::WriteMessage("str1 = " + str1 + "; str2 = " + str2 + "; result = " + result);
}

void TestLeetCode966(void)
{
    Logger::WriteMessage("Test Leet Code 966");
    LeetCodeString leetCode;
    vector<string> wordlist = { "KiTe","kite","hare","Hare" };
    vector<string> queries = { "kite","Kite","KiTe","Hare","HARE","Hear","hear", "keti","keet","keto" };
    vector<string> result = leetCode.spellchecker(wordlist, queries);
    Logger::WriteMessage(wordlist);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode972(void)
{
    Logger::WriteMessage("Test Leet Code 972");
    LeetCodeString leetCode;
    string S = "0.(52)";
    string T = "0.5(25)";
    bool result = leetCode.isRationalEqual(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + (string)(result ? "true" : "false"));

    S = "0.1666(6)";
    T = "0.166(66)";
    result = leetCode.isRationalEqual(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + (string)(result ? "true" : "false"));

    S = "0.9(9)";
    T = "1.";
    result = leetCode.isRationalEqual(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + (string)(result ? "true" : "false"));

    S = ".1(011)";
    T = "0.(101)";
    result = leetCode.isRationalEqual(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + (string)(result ? "true" : "false"));

    S = "1.9(0)";
    T = "1.8(9)";
    result = leetCode.isRationalEqual(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1065(void)
{
    Logger::WriteMessage("Test Leet Code 1065");
    LeetCodeString leetCode;
    string text = "thestoryofleetcodeandme";
    vector<string> words = { "story", "fleet", "leetcode" };
    vector<vector<int>> result = leetCode.indexPairs(text, words);
    Logger::WriteMessage("text = " + text);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    text = "ababa";
    words = { "aba","ab" };
    result = leetCode.indexPairs(text, words);
    Logger::WriteMessage("text = " + text);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    text = "baabaaaaaa";
    words = { "b", "a", "ba", "bb", "aa" };
    result = leetCode.indexPairs(text, words);
    Logger::WriteMessage("text = " + text);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode1078(void)
{
    Logger::WriteMessage("Test Leet Code 1078");
    LeetCodeString leetCode;
    string text = "alice is a good girl she is a good student";
    string first = "a";
    string second = "good";
    vector<string> result = leetCode.findOcurrences(text, first, second);
    Logger::WriteMessage("first = " + first + "; second = " + second);
    Logger::WriteMessage(result);

    text = "we will we will rock you";
    first = "we";
    second = "will";
    result = leetCode.findOcurrences(text, first, second);
    Logger::WriteMessage("first = " + first + "; second = " + second);
    Logger::WriteMessage(result);
}

void TestLeetCode1055(void)
{
    Logger::WriteMessage("Test Leet Code 1055");
    LeetCodeString leetCode;
    string source = "abc";
    string target = "abcbc";
    int result = leetCode.shortestWay(source, target);
    Logger::WriteMessage("source = " + source + "; target = " + target + "; result = " + to_string(result));

    source = "abc";
    target = "acdbc";
    result = leetCode.shortestWay(source, target);
    Logger::WriteMessage("source = " + source + "; target = " + target + "; result = " + to_string(result));

    source = "xyz";
    target = "xzyxz";
    result = leetCode.shortestWay(source, target);
    Logger::WriteMessage("source = " + source + "; target = " + target + "; result = " + to_string(result));
}

void TestLeetCode1044(void)
{
    Logger::WriteMessage("Test Leet Code 1044");
    LeetCodeString leetCode;
    string S = "banana";
    string result = leetCode.longestDupSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "abcd";
    result = leetCode.longestDupSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "aaaaaa";
    result = leetCode.longestDupSubstring(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode1324(void)
{
    Logger::WriteMessage("Test Leet Code 1324");
    LeetCodeString leetCode;
    string s = "HOW ARE YOU";
    vector<string> result = leetCode.printVertically(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = "TO BE OR NOT TO BE";
    result = leetCode.printVertically(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);

    s = "CONTEST IS COMING";
    result = leetCode.printVertically(s);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(result);
}

void TestLeetCode1328(void)
{
    Logger::WriteMessage("Test Leet Code 1328");
    LeetCodeString leetCode;
    string palindrome = "abccba";
    string result = leetCode.breakPalindrome(palindrome);
    Logger::WriteMessage("palindrome = " + palindrome + "; result = " + result);

    palindrome = "a";
    result = leetCode.breakPalindrome(palindrome);
    Logger::WriteMessage("palindrome = " + palindrome + "; result = " + result);

    palindrome = "aba";
    result = leetCode.breakPalindrome(palindrome);
    Logger::WriteMessage("palindrome = " + palindrome + "; result = " + result);

    palindrome = "aaaa";
    result = leetCode.breakPalindrome(palindrome);
    Logger::WriteMessage("palindrome = " + palindrome + "; result = " + result);
}

void TestLeetCode1332(void)
{
    Logger::WriteMessage("Test Leet Code 1332");
    LeetCodeString leetCode;
    string s = "ababa";
    int result = leetCode.removePalindromeSub(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abb";
    result = leetCode.removePalindromeSub(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "baabb";
    result = leetCode.removePalindromeSub(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "";
    result = leetCode.removePalindromeSub(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1347(void)
{
    Logger::WriteMessage("Test Leet Code 1347");
    LeetCodeString leetCode;
    string s = "bab";
    string t = "aba";
    int result = leetCode.minSteps(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t +"; result = " + to_string(result));

    s = "leetcode";
    t = "practice";
    result = leetCode.minSteps(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "anagram";
    t = "mangaar";
    result = leetCode.minSteps(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "xxyyzz";
    t = "xxyyzz";
    result = leetCode.minSteps(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "friend";
    t = "family";
    result = leetCode.minSteps(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));
}

void TestLeetCode1177(void)
{
    Logger::WriteMessage("Test Leet Code 1177");
    LeetCodeString leetCode;
    string s = "abcda";
    vector<vector<int>> queries = { {3, 3, 0},{1, 2, 0},{0, 3, 1},{0, 3, 2},{0, 4, 1} };
    vector<bool> result = leetCode.canMakePaliQueries(s, queries);
    Logger::WriteMessage(queries);
    Logger::WriteMessage(result);
}

void TestLeetCode336(void)
{
    Logger::WriteMessage("Test Leet Code 336");
    LeetCodeString leetCode;
    vector<string> words = { "abcd", "dcba", "lls", "s", "sssll" };
    Logger::WriteMessage(words);
    vector<vector<int>> result = leetCode.palindromePairs(words);
    Logger::WriteMessage(result);

    words = { "bat", "tab", "cat" };
    Logger::WriteMessage(words);
    result = leetCode.palindromePairs(words);
    Logger::WriteMessage(result);

    words = { "a", "b", "c", "ab", "ac", "aa" };
    Logger::WriteMessage(words);
    result = leetCode.palindromePairs(words);
    Logger::WriteMessage(result);

    words = { "a", "", };
    Logger::WriteMessage(words);
    result = leetCode.palindromePairs(words);
    Logger::WriteMessage(result);
}

void TestLeetCode125(void)
{
    Logger::WriteMessage("Test Leet Code 125");
    LeetCodeString leetCode;
    string s;
    bool isPalindrome;
    s = "A man, a plan, a canal: Panama";
    Logger::WriteMessage(s);
    isPalindrome = leetCode.isPalindrome(s);
    Logger::WriteMessage("It " + string(isPalindrome ? "is" : "is not") + " palindrome");

    s = "race a car";
    Logger::WriteMessage(s);
    isPalindrome = leetCode.isPalindrome(s);
    Logger::WriteMessage("It " + string(isPalindrome ? "is" : "is not") + " palindrome");
}

void TestLeetCode409(void)
{
    Logger::WriteMessage("Test Leet Code 409");
    LeetCodeString leetCode;
    string s = "dccaccd";
    int result = leetCode.longestPalindromeII(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode187(void)
{
    Logger::WriteMessage("Test Leet Code 187");
    LeetCodeString leetCode;
    string s;
    vector <string> result;
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Logger::WriteMessage("s = " + s);
    result = leetCode.findRepeatedDnaSequences(s);
    Logger::WriteMessage(result);
}

void TestLeetCode205(void)
{
    Logger::WriteMessage("Test Leet Code 205");
    LeetCodeString leetCode;
    string s, t;
    bool isIsomorphic;
    s = "egg"; t = "add";
    isIsomorphic = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage(s + " and " + t + string(isIsomorphic ? " are " : " are not ") + "isIsomorphic");
    s = "foo"; t = "bar";
    isIsomorphic = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage(s + " and " + t + string(isIsomorphic ? " are " : " are not ") + "isIsomorphic");
    s = "paper"; t = "title";
    isIsomorphic = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage(s + " and " + t + string(isIsomorphic ? " are " : " are not ") + "isIsomorphic");

    s = "ab"; t = "aa";
    isIsomorphic = leetCode.isIsomorphic(s, t);
    Logger::WriteMessage(s + " and " + t + string(isIsomorphic ? " are " : " are not ") + "isIsomorphic");
}

void TestLeetCode290(void)
{
    Logger::WriteMessage("Test Leet Code 290");
    LeetCodeString leetCode;
    string pattern, str;
    bool match;
    pattern = "abba"; str = "dog cat cat dog";
    match = leetCode.wordPattern(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; " + (match ? "match" : "not match"));

    pattern = "abba"; str = "dog cat cat fish";
    match = leetCode.wordPattern(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; " + (match ? "match" : "not match"));

    pattern = "aaaa"; str = "dog cat cat dog";
    match = leetCode.wordPattern(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; " + (match ? "match" : "not match"));

    pattern = "abba"; str = "dog dog dog dog";
    match = leetCode.wordPattern(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; " + (match ? "match" : "not match"));

    pattern = "aaaa"; str = "dog dog dog dog";
    match = leetCode.wordPattern(pattern, str);
    Logger::WriteMessage("pattern = " + pattern + "; str = " + str + "; " + (match ? "match" : "not match"));
}

void TestLeetCode393(void)
{
    Logger::WriteMessage("Test Leet Code 393");
    LeetCodeString leetCode;
    vector<int> nums;
    bool result;
    nums = { 197, 130, 1 };
    Logger::WriteMessage(nums);
    result = leetCode.validUtf8(nums);
    Logger::WriteMessage("It is a " + string(result ? "" : "not") + " valid Utf8");

    nums = { 235, 140, 4 };
    Logger::WriteMessage(nums);
    result = leetCode.validUtf8(nums);
    Logger::WriteMessage("It is a " + string(result ? "" : "not") + " valid Utf8");

    nums = { 255 };
    Logger::WriteMessage(nums);
    result = leetCode.validUtf8(nums);
    Logger::WriteMessage("It is a " + string(result ? "" : "not") + " valid Utf8");
}

void TestLeetCode293(void)
{
    Logger::WriteMessage("Test Leet Code 293");
    LeetCodeString leetCode;
    string s = "++++";
    vector<string> result = leetCode.generatePossibleNextMoves(s);
    Logger::WriteMessage("s=" + s);
    Logger::WriteMessage(result);
}

void TestLeetCode482(void)
{
    Logger::WriteMessage("Test Leet Code 482");
    LeetCodeString leetCode;

    string S = "2-4A0r7-4k";
    int k = 4;
    string result = leetCode.licenseKeyFormatting(S, k);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "2-4A0r7-4k";
    k = 3;
    result = leetCode.licenseKeyFormatting(S, k);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode65(void)
{
    Logger::WriteMessage("Test Leet Code 65");
    string s = "3";
    LeetCodeString leetCode;
    bool result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "3.8";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "-0.5e+10";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "0";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "0.1";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "abc";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "1 a";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = "2e10";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");

    s = ".";
    result = leetCode.isValidNumber(s);
    Logger::WriteMessage(s + " is a " + (result ? "valid" : "invalid") + " number");
}

void TestLeetCode214(void)
{
    Logger::WriteMessage("Test Leet Code 214");
    LeetCodeString leetCode;
    string s = "aacecaaa";
    string result = leetCode.shortestPalindrome(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);

    s = "aaccaaa";
    result = leetCode.shortestPalindrome(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);

    s = "abcd";
    result = leetCode.shortestPalindrome(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);
}


void TestLeetCode1358(void)
{
    Logger::WriteMessage("Test Leet Code 1358");
    LeetCodeString leetCode;
    string s = "abcabc";
    int result = leetCode.numberOfSubstrings(s);
    Logger::WriteMessage("s=" + s + "; result=" + to_string(result));

    s = "aaacb";
    result = leetCode.numberOfSubstrings(s);
    Logger::WriteMessage("s=" + s + "; result=" + to_string(result));

    s = "abc";
    result = leetCode.numberOfSubstrings(s);
    Logger::WriteMessage("s=" + s + "; result=" + to_string(result));
}

void TestLeetCode1370(void)
{
    Logger::WriteMessage("Test Leet Code 1370");
    LeetCodeString leetCode;
    string s = "aaaabbbbcccc";
    string result = leetCode.sortString(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);

    s = "rat";
    result = leetCode.sortString(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);

    s = "leetcode";
    result = leetCode.sortString(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);

    s = "ggggggg";
    result = leetCode.sortString(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);

    s = "spo";
    result = leetCode.sortString(s);
    Logger::WriteMessage("s=" + s + "; result=" + result);
}

void TestLeetCode1371(void)
{
    Logger::WriteMessage("Test Leet Code 1371");
    LeetCodeString leetCode;
    string s = "eleetminicoworoep";
    int result = leetCode.findTheLongestSubstring(s);
    Logger::WriteMessage("s=" + s + "; result=" + to_string(result));

    s = "leetcodeisgreat";
    result = leetCode.findTheLongestSubstring(s);
    Logger::WriteMessage("s=" + s + "; result=" + to_string(result));

    s = "bcbcbc";
    result = leetCode.findTheLongestSubstring(s);
    Logger::WriteMessage("s=" + s + "; result=" + to_string(result));
}

void TestLeetCode1374(void)
{
    Logger::WriteMessage("Test Leet Code 1374");
    LeetCodeString leetCode;
    int n = 4;
    string result  = leetCode.generateTheString(n);
    Logger::WriteMessage("n=" + to_string(n) + "; result=" + result);

    n = 2;
    result = leetCode.generateTheString(n);
    Logger::WriteMessage("n=" + to_string(n) + "; result=" + result);

    n = 7;
    result = leetCode.generateTheString(n);
    Logger::WriteMessage("n=" + to_string(n) + "; result=" + result);
}

void TestLeetCode1392(void)
{
    Logger::WriteMessage("Test Leet Code 1392");
    LeetCodeString leetCode;
    string s = "level";
    string result = leetCode.longestPrefix(s);
    Logger::WriteMessage("s =" + s + "; result=" + result);

    s = "ababab";
    result = leetCode.longestPrefix(s);
    Logger::WriteMessage("s =" + s + "; result=" + result);

    s = "leetcodeleet";
    result = leetCode.longestPrefix(s);
    Logger::WriteMessage("s =" + s + "; result=" + result);

    s = "a";
    result = leetCode.longestPrefix(s);
    Logger::WriteMessage("s =" + s + "; result=" + result);
}

void TestLeetCode1400(void)
{
    Logger::WriteMessage("Test Leet Code 1400");
    LeetCodeString leetCode;
    string s = "annabelle";
    int k = 2;
    bool result = leetCode.canConstruct(s, k);
    Logger::WriteMessage("s =" + s + "; k = " + to_string(k) + "; result=" + (result ? "true" : "false"));

    s = "leetcode";
    k = 3;
    result = leetCode.canConstruct(s, k);
    Logger::WriteMessage("s =" + s + "; k = " + to_string(k) + "; result=" + (result ? "true" : "false"));

    s = "true";
    k = 4;
    result = leetCode.canConstruct(s, k);
    Logger::WriteMessage("s =" + s + "; k = " + to_string(k) + "; result=" + (result ? "true" : "false"));

    s = "yzyzyzyzyzyzyzy";
    k = 2;
    result = leetCode.canConstruct(s, k);
    Logger::WriteMessage("s =" + s + "; k = " + to_string(k) + "; result=" + (result ? "true" : "false"));

    s = "cr";
    k = 7;
    result = leetCode.canConstruct(s, k);
    Logger::WriteMessage("s =" + s + "; k = " + to_string(k) + "; result=" + (result ? "true" : "false"));
}

void TestLeetCode1404(void)
{
    Logger::WriteMessage("Test Leet Code 1404");
    LeetCodeString leetCode;
    string s = "1101";
    int result = leetCode.numSteps(s);
    Logger::WriteMessage("s =" + s + "; result=" + to_string(result));

    s = "10";
    result = leetCode.numSteps(s);
    Logger::WriteMessage("s =" + s + "; result=" + to_string(result));

    s = "1";
    result = leetCode.numSteps(s);
    Logger::WriteMessage("s =" + s + "; result=" + to_string(result));
}

void TestLeetCode1408(void)
{
    Logger::WriteMessage("Test Leet Code 1408");
    LeetCodeString leetCode;
    vector<string> words = { "mass", "as", "hero", "superhero" };
    vector<string> result = leetCode.stringMatching(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    words = { "leetcode","et","code" };
    result = leetCode.stringMatching(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);

    words = { "blue","green","bu" };
    result = leetCode.stringMatching(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage(result);
}

void TestLeetCode1410(void)
{
    Logger::WriteMessage("Test Leet Code 1410");
    LeetCodeString leetCode;
    string text = "&amp; is an HTML entity but &ambassador; is not.";
    string result = leetCode.entityParser(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);
 
    text = "and I quote: &quot;...&quot;";
    result = leetCode.entityParser(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "Stay home! Practice on Leetcode :)";
    result = leetCode.entityParser(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "x &gt; y &amp;&amp; x &lt; y is always false";
    result = leetCode.entityParser(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "leetcode.com&frasl;problemset&frasl;all";
    result = leetCode.entityParser(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);
}

void TestLeetCode1417(void)
{
    Logger::WriteMessage("Test Leet Code 1417");
    LeetCodeString leetCode;
    string s = "a0b1c2";
    string result = leetCode.reformat(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "leetcode";
    result = leetCode.reformat(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "1229857369";
    result = leetCode.reformat(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "covid2019";
    result = leetCode.reformat(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "ab123";
    result = leetCode.reformat(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1422(void)
{
    Logger::WriteMessage("Test Leet Code 1422");
    LeetCodeString leetCode;
    string s = "011101";
    int result = leetCode.maxScore(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "00111";
    result = leetCode.maxScore(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "1111";
    result = leetCode.maxScore(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1433(void)
{
    Logger::WriteMessage("Test Leet Code 1433");
    LeetCodeString leetCode;
    string s1 = "abc";
    string s2 = "xya";
    bool result = leetCode.checkIfCanBreak(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result? "true" : "false"));

    s1 = "abe";
    s2 = "acd";
    result = leetCode.checkIfCanBreak(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "leetcodee";
    s2 = "interview";
    result = leetCode.checkIfCanBreak(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "abc";
    s2 = "acb";
    result = leetCode.checkIfCanBreak(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1427(void)
{
    Logger::WriteMessage("Test Leet Code 1427");
    LeetCodeString leetCode;
    string s = "abc";
    vector<vector<int>> shift = { {0, 1},{1, 2} };
    string result = leetCode.stringShift(s, shift);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "abcdefg";
    shift = { {1, 1},{1, 1},{0, 2},{1, 3} };
    result = leetCode.stringShift(s, shift);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCodeString(void)
{
    TestLeetCode1427();
    TestLeetCode1433();
    TestLeetCode1417();
    TestLeetCode1422();
    TestLeetCode1410();
    TestLeetCode1408();
    TestLeetCode1404();
    TestLeetCode1400();
    TestLeetCode1392();
    TestLeetCode1374();
    TestLeetCode1371();
    TestLeetCode1370();
    TestLeetCode1358();
    TestLeetCode214();
    TestLeetCode65();
    TestLeetCode482();
    TestLeetCode293();
    TestLeetCode393();
    TestLeetCode290();
    TestLeetCode187();
    TestLeetCode205();
    TestLeetCode409();
    TestLeetCode336();
    TestLeetCode125();
    TestLeetCode1032();
    TestLeetCode745();
    TestLeetCode1177();
    TestLeetCode1347();
    TestLeetCode1332();
    TestLeetCode1328();
    TestLeetCode676();
    TestLeetCode271();
    TestLeetCode604();
    TestLeetCode1324();
    TestLeetCode1044();
    TestLeetCode1055();
    TestLeetCode1078();
    TestLeetCode1065();
    TestLeetCode972();
    TestLeetCode966();
    TestLeetCode1071();
    TestLeetCode1096();
    TestLeetCode1111();
    TestLeetCode1108();
    TestLeetCode1106();
    TestLeetCode1119();
    TestLeetCode1160();
    TestLeetCode395();
    TestLeetCode424();
    TestLeetCode770();
    TestLeetCode772();
    TestLeetCode224();
    TestLeetCode227();
    TestLeetCode1178();
    TestLeetCode49();
    TestLeetCode520();
    TestLeetCode468();
    TestLeetCode438();
    TestLeetCode434();
    TestLeetCode387();
    TestLeetCode383();
    TestLeetCode3();
    TestLeetCode242();
    TestLeetCode76();
    TestLeetCode68();
    TestLeetCode14();
    TestLeetCode344();
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
