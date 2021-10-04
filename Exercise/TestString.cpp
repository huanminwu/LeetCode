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

void TestLeetCode30(void)
{
    Logger::WriteMessage("Test Leet Code 30");
    LeetCodeString leetCode;
    vector<string> words;
    vector<int> result;
    string s;
    s.assign("wordgoodgoodgoodbestword");
    words = { "word", "good", "best", "good" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);

    s.assign("barfoothefoobarman");
    words = { "foo", "bar" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);

    s.assign("mississippi");
    words = { "mississippis" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);

    s.assign("barfoofoobarthefoobarman");
    words = { "bar", "foo", "the" };
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage("word list ");
    Logger::WriteMessage(words);
    result = leetCode.findSubstring(s, words);
    Logger::WriteMessage(result);
}


void TestLeetCode139(void)
{
    Logger::WriteMessage("Test Leet Code 139");
    LeetCodeString leetCode;
    string s = "leetcode";
    vector<string> wordDict = { "leet", "code" };
    bool result = leetCode.wordBreak(s, wordDict);
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("string = " + s + "result = " + string(result ? "true" : "false"));

    s = "applepenapple";
    wordDict = { "apple", "pen" };
    result = leetCode.wordBreak(s, wordDict);
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("string = " + s + "result = " + string(result ? "true" : "false"));

    s = "catsandog";
    wordDict = { "cats", "dog", "sand", "and", "cat" };
    result = leetCode.wordBreak(s, wordDict);
    Logger::WriteMessage(wordDict);
    Logger::WriteMessage("string = " + s + "result = " + string(result ? "true" : "false"));
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

void TestLeetCode1446(void)
{
    Logger::WriteMessage("Test Leet Code 1446");
    LeetCodeString leetCode;
    string s = "leetcode";
    int result = leetCode.maxPower(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abbcccddddeeeeedcba";
    result = leetCode.maxPower(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "triplepillooooow";
    result = leetCode.maxPower(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "hooraaaaaaaaaaay";
    result = leetCode.maxPower(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "tourist";
    result = leetCode.maxPower(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1451(void)
{
    Logger::WriteMessage("Test Leet Code 1451");
    LeetCodeString leetCode;
    string text = "Leetcode is cool";
    string result = leetCode.arrangeWords(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "Keep calm and code on";
    result = leetCode.arrangeWords(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "To be or not to be";
    result = leetCode.arrangeWords(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);
}

void TestLeetCode1455(void)
{
    Logger::WriteMessage("Test Leet Code 1455");
    LeetCodeString leetCode;
    string sentence = "i love eating burger";
    string searchWord = "burg";
    int result = leetCode.isPrefixOfWord(sentence, searchWord);
    Logger::WriteMessage("sentence = " + sentence + "; searchWord = " + searchWord + "; result = " + to_string(result));

    sentence = "this problem is an easy problem";
    searchWord = "pro";
    result = leetCode.isPrefixOfWord(sentence, searchWord);
    Logger::WriteMessage("sentence = " + sentence + "; searchWord = " + searchWord + "; result = " + to_string(result));

    sentence = "i am tired";
    searchWord = "you";
    result = leetCode.isPrefixOfWord(sentence, searchWord);
    Logger::WriteMessage("sentence = " + sentence + "; searchWord = " + searchWord + "; result = " + to_string(result));

    sentence = "i use triple pillow";
    searchWord = "pill";
    result = leetCode.isPrefixOfWord(sentence, searchWord);
    Logger::WriteMessage("sentence = " + sentence + "; searchWord = " + searchWord + "; result = " + to_string(result));

    sentence = "hello from the other side";
    searchWord = "they";
    result = leetCode.isPrefixOfWord(sentence, searchWord);
    Logger::WriteMessage("sentence = " + sentence + "; searchWord = " + searchWord + "; result = " + to_string(result));
}

void TestLeetCode1456(void)
{
    Logger::WriteMessage("Test Leet Code 1456");
    LeetCodeString leetCode;
    string s = "abciiidef";
    int k = 3;
    int result = leetCode.maxVowels(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "aeiou";
    k = 2;
    result = leetCode.maxVowels(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "leetcode";
    k = 3;
    result = leetCode.maxVowels(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "rhythms";
    k = 4;
    result = leetCode.maxVowels(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "tryhard";
    k = 4;
    result = leetCode.maxVowels(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode471(void)
{
    Logger::WriteMessage("Test Leet Code 471");
    LeetCodeString leetCode;

    string s = "aaaaaaaaaabbbaaaaabbb";
    string result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "abbbabbbcabbbabbbc";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aabcaabcd";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aaaaaaaaaa";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aaa";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);

    s = "aaaaa";
    result = leetCode.encode(s);
    Logger::WriteMessage("s = " + s + "; encode result = " + result);
}

void TestLeetCode466(void)
{
    Logger::WriteMessage("Test Leet Code 466");
    LeetCodeString leetCode;
    string s1 = "acb";
    int n1 = 4;
    string s2 = "ab";
    int n2 = 2;
    int result = leetCode.getMaxRepetitions(s1, n1, s2, n2);
    Logger::WriteMessage("s1 = " + s1 + "; n1 = " + to_string(n1) + "; s2 = " + s2 +
        "; n2 = " + to_string(n2) + "; result = " + to_string(result));
}

void TestLeetCode418(void)
{
    Logger::WriteMessage("Test Leet Code 418");
    LeetCodeString leetCode;
    int rows = 2, cols = 8;
    vector<string> sentence = { "hello", "world" };
    int count = leetCode.wordsTyping(sentence, rows, cols);
    Logger::WriteMessage(sentence);
    Logger::WriteMessage("rows = " + to_string(rows) + "; cols = " + to_string(cols) + 
        "; sentence count = " + to_string(count));

    rows = 3, cols = 6;
    sentence = { "a", "bcd", "e" };
    count = leetCode.wordsTyping(sentence, rows, cols);
    Logger::WriteMessage(sentence);
    Logger::WriteMessage("rows = " + to_string(rows) + "; cols = " + to_string(cols) + 
        "; sentence count = " + to_string(count));

    rows = 4, cols = 5;
    sentence = { "I", "had", "apple", "pie" };
    count = leetCode.wordsTyping(sentence, rows, cols);
    Logger::WriteMessage(sentence);
    Logger::WriteMessage("rows = " + to_string(rows) + "; cols = " + to_string(cols) + 
        "; sentence count = " + to_string(count));
}

void TestLeetCode816(void)
{
    Logger::WriteMessage("Test Leet Code 816");
    LeetCodeString leetCode;
    string S = "(123)";
    vector<string> result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "(00011)";
    result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "(0123)";
    result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "(100)";
    result = leetCode.ambiguousCoordinates(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}


void TestLeetCode936(void)
{
    Logger::WriteMessage("Test Leet Code 936");
    LeetCodeString leetCode;
    string stamp = "abc";
    string target = "ababc";

    vector<int> result = leetCode.movesToStamp(stamp, target);
    Logger::WriteMessage("stamp = " + stamp + "; target = " + target);
    Logger::WriteMessage(result);

    stamp = "abca";
    target = "aabcaca";
    result = leetCode.movesToStamp(stamp, target);
    Logger::WriteMessage("stamp = " + stamp + "; target = " + target);
    Logger::WriteMessage(result);
}

void TestLeetCode420(void)
{
    Logger::WriteMessage("Test Leet Code 420");
    LeetCodeString leetCode;
    string password;
    int change;

    password.assign("aaaaabbbb1234567890ABA");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

    password.assign("aaaaaaaAAAAAA6666bbbbaaaaaaABBC");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

    password.assign("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

    password.assign("aaa111");
    change = leetCode.strongPasswordChecker(password);
    Logger::WriteMessage("pasword = " + password + " change =" + to_string(change));

}

void TestLeetCode306(void)
{
    Logger::WriteMessage("Test Leet Code 306");
    LeetCodeString leetCode;
    string num = "19910011992";
    bool isAdditiveNumber = leetCode.isAdditiveNumber(num);
    Logger::WriteMessage("num = " + num + (string)(isAdditiveNumber ? " is " : " is not ") + "additive number.");
    num = "199100199";
    isAdditiveNumber = leetCode.isAdditiveNumber(num);
    Logger::WriteMessage("num = " + num + (string)(isAdditiveNumber ? " is " : " is not ") + "additive number.");
    num = "112358";
    isAdditiveNumber = leetCode.isAdditiveNumber(num);
    Logger::WriteMessage("num = " + num + (string)(isAdditiveNumber ? " is " : " is not ") + "additive number.");
}

void TestLeetCode266(void)
{
    Logger::WriteMessage("Test Leet Code 266");
    LeetCodeString leetCode;
    string s = "code";
    bool result = leetCode.canPermutePalindrome(s);
    Logger::WriteMessage(s + "->" + (string)(result ? "true" : "false"));
    s = "aab";
    result = leetCode.canPermutePalindrome(s);
    Logger::WriteMessage(s + "->" + (string)(result ? "true" : "false"));
    s = "carerac";
    result = leetCode.canPermutePalindrome(s);
    Logger::WriteMessage(s + "->" + (string)(result ? "true" : "false"));
}

void TestLeetCode246(void)
{
    Logger::WriteMessage("Test Leet Code 246");
    LeetCodeString leetCode;
    string s = "6801089";
    bool result = leetCode.isStrobogrammatic(s);
    Logger::WriteMessage("s=" + s + "; It " + (string)(result ? "is" : "is not") + " strobogrammatic");
    s = "6803089";
    result = leetCode.isStrobogrammatic(s);
    Logger::WriteMessage("s=" + s + "; It " + (string)(result ? "is" : "is not") + " strobogrammatic");
}

void TestLeetCode249(void)
{
    Logger::WriteMessage("Test Leet Code 249");
    LeetCodeString leetCode;
    vector<string> strings = { "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
    Logger::WriteMessage(strings);
    vector<vector<string>> result = leetCode.groupStrings(strings);
    Logger::WriteMessage(result);
}

void TestLeetCode408(void)
{
    Logger::WriteMessage("Test Leet Code 288");
    string word = "internationalization";
    string abbr = "i12iz4n";
    LeetCodeString leetCode;
    bool result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));

    word = "apple";
    abbr = "a2e";
    result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));

    word = "internationalization";
    abbr = "i5a11o1";
    result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));

    word = "hi";
    abbr = "1";
    result = leetCode.validWordAbbreviation(word, abbr);
    Logger::WriteMessage("word = " + word + "; abbr = " + abbr + "; validWordAbbreviation = " + (string)(result ? "true" : "false"));
}

void TestLeetCode481(void)
{
    Logger::WriteMessage("Test Leet Code 481");
    LeetCodeString leetCode;
    int n = 20;
    int result = leetCode.magicalString(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode157(void)
{
    Logger::WriteMessage("Test Leet Code 157");
    LeetCodeString leetCode;
    string s = "abcdefghijklmnopqrstuvwxyz";
    int n = 9;
    char buff[256];
    int n_read = leetCode.readNChars(buff, n, s);
    Logger::WriteMessage("buff = " + (string)buff);
}

void TestLeetCode158(void)
{
    Logger::WriteMessage("Test Leet Code 158");
    LeetCodeString leetCode;
    string s = "abcdefghijklmnopqrstuvwxyz";
    Logger::WriteMessage("s = " + s);
    char buff[256];
    int n = 3;
    int index = 0;
    string m_buffer;
    int n_read = leetCode.readNCharsII(buff, n, s, index, m_buffer);
    Logger::WriteMessage("buff = " + (string)buff);

    n = 1;
    n_read = leetCode.readNCharsII(buff, n, s, index, m_buffer);
    Logger::WriteMessage("buff = " + (string)buff);

    n = 5;
    n_read = leetCode.readNCharsII(buff, n, s, index, m_buffer);
    Logger::WriteMessage("buff = " + (string)buff);
}

void TestLeetCode159(void)
{
    Logger::WriteMessage("Test Leet Code 159");
    LeetCodeString leetCode;
    string s = "eceba";
    int max_length = leetCode.lengthOfLongestSubstringTwoDistinct(s);
    Logger::WriteMessage("s = " + s + "; max_length = " + to_string(max_length));
}

void TestLeetCode340(void)
{
    Logger::WriteMessage("Test Leet Code 340");
    LeetCodeString leetCode;
    string s = "eceba";
    int k = 2;
    int max_length = leetCode.lengthOfLongestSubstringKDistinct(s, k);
    Logger::WriteMessage("s = " + s + "; max_length = " + to_string(max_length));
}


void TestLeetCode524(void)
{
    Logger::WriteMessage("Test Leet Code 524");
    LeetCodeString leetCode;
    string s = "abpcplea";
    vector<string> d = { "ale", "apple", "monkey", "plea" };
    string result = leetCode.findLongestWord(s, d);
    Logger::WriteMessage(d);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode467(void)
{
    Logger::WriteMessage("Test Leet Code 467");
    LeetCodeString leetCode;
    string s = "a";
    int str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "cac";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "zab";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "abcdefghijklmnopqrstuvwxyz";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));

    s = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    str_count = leetCode.findSubstringInWraproundString(s);
    Logger::WriteMessage("s = " + s + "; str_count = " + to_string(str_count));
}

void TestLeetCode521(void)
{
    LeetCodeString leetCode;
    string a = "aba";
    string b = "cdc";
    int result = leetCode.findLUSlength(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + to_string(result));
}

void TestLeetCode522(void)
{
    LeetCodeString leetCode;
    vector<string> strs = { "aba", "cdc", "eae" };
    int result = leetCode.findLUSlength(strs);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("result = " + to_string(result));

    strs = { "abc", "abc", "ac", "d" };
    result = leetCode.findLUSlength(strs);
    Logger::WriteMessage(strs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode392(void)
{
    Logger::WriteMessage("Test Leet Code 392");
    LeetCodeString leetCode;
    string s = "abc", t = "ahbgdc";
    bool isSequence = leetCode.isSubsequence(s, t);
    Logger::WriteMessage("s=" + s + ";" + "t=" + t + (string)(isSequence ? " is " : " is not ") + "sub sequence.");
    s = "axc", t = "ahbgdc";
    isSequence = leetCode.isSubsequence(s, t);
    Logger::WriteMessage("s=" + s + ";" + "t=" + t + (string)(isSequence ? " is " : " is not ") + "sub sequence.");
}

void TestLeetCode541(void)
{
    LeetCodeString leetCode;
    string s = "abcdefg";
    int k = 2;
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k));
    string result = leetCode.reverseStr(s, k);
    Logger::WriteMessage("reverse = " + result);
}

void TestLeetCode527(void)
{
    LeetCodeString leetCode;
    vector<string> dict =
    {
        "like", "god", "internal", "me", "internet",
        "interval", "intension", "face", "intrusion"
    };
    vector<string> result = leetCode.wordsAbbreviation(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage(result);

    dict =
    {
        "aa", "aaa"
    };
    result = leetCode.wordsAbbreviation(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage(result);

    dict =
    {
        "meet", "met"
    };
    result = leetCode.wordsAbbreviation(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage(result);
}

void TestLeetCode551(void)
{
    LeetCodeString leetCode;
    string record = "PPALLP";
    bool reward = leetCode.checkRecord(record);
    Logger::WriteMessage("Record = " + record + "; Reward = " + (string)(reward ? "true" : "false"));

    record = "PPALLL";
    reward = leetCode.checkRecord(record);
    Logger::WriteMessage("Record = " + record + "; Reward = " + (string)(reward ? "true" : "false"));

    record = "LALL";
    reward = leetCode.checkRecord(record);
    Logger::WriteMessage("Record = " + record + "; Reward = " + (string)(reward ? "true" : "false"));
}

void TestLeetCode557(void)
{
    LeetCodeString leetCode;
    string s = "Let's take LeetCode contest";
    string result = leetCode.reverseWordsIII(s);
    Logger::WriteMessage(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode616(void)
{
    LeetCodeString leetCode;
    string s = "abcxyz123";
    vector<string> dict = { "abc", "123" };
    string result = leetCode.addBoldTag(s, dict);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + result);

    s = "aaabbcc";
    dict = { "aaa", "aab", "bc" };
    result = leetCode.addBoldTag(s, dict);
    Logger::WriteMessage("s = " + s);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode567(void)
{
    LeetCodeString leetCode;
    string s1 = "ab", s2 = "eidbaooo";
    bool result = leetCode.checkInclusion(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "ab";
    s2 = "eidboaoo";
    result = leetCode.checkInclusion(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "adc";
    s2 = "dcda";
    result = leetCode.checkInclusion(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode726(void)
{
    LeetCodeString leetCode;

    string formula = "H2O";
    string result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);

    formula = "Mg(OH)2";
    result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);

    formula = "K4(ON(SO3)2)2";
    result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);

    formula = "(Be22)8((Ge4)46)13";
    result = leetCode.countOfAtoms(formula);
    Logger::WriteMessage("formula = " + formula + "; result = " + result);
}

void TestLeetCode609(void)
{
    LeetCodeString leetCode;
    vector<string> paths = { "root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)" };
    Logger::WriteMessage(paths);
    vector<vector<string>> result = leetCode.findDuplicate(paths);
    Logger::WriteMessage(result);
}

void TestLeetCode591(void)
{
    LeetCodeString leetCode;

    Logger::WriteMessage("Valid Examples");
    string code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    bool result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    Logger::WriteMessage("Invalid Examples");
    code = "<A>  <B> </A>   </B>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>  div tag is not closed  <DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>  unmatched <  </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "<DIV>  unmatched start tag <B>  and unmatched end tag </C> </DIV>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    code = "!!!<A>123</A>";
    result = leetCode.isValid(code);
    Logger::WriteMessage(code);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode720(void)
{
    LeetCodeString leetCode;
    vector<string> words = { "w","wo","wor","worl", "world" };
    string longestWord = leetCode.longestWord(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Longest word = " + longestWord);

    words = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
    longestWord = leetCode.longestWord(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("Longest word = " + longestWord);
}

void TestLeetCode722(void)
{
    LeetCodeString leetCode;

    vector<string> source =
    {
        "/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test",
        "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"
    };
    vector<string> result = leetCode.removeComments(source);
    Logger::WriteMessage(source);
    Logger::WriteMessage(result);

    source = { "a/*comment", "line", "more_comment*/b" };
    result = leetCode.removeComments(source);
    Logger::WriteMessage(source);
    Logger::WriteMessage(result);
}

void TestLeetCode648(void)
{
    LeetCodeString leetCode;
    vector<string> dict = { "cat", "bat", "rat" };
    string sentence = "the cattle was rattled by the battery";
    string result = leetCode.replaceWords(dict, sentence);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("sentence = " + sentence + "; result = " + result);
}

void TestLeetCode640(void)
{
    LeetCodeString leetCode;
    string equation = "x+5-3+x=6+x-2";
    string result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "x=x";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "2x=x";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "2x+3x-6x=x+2";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);

    equation = "x=x+2";
    result = leetCode.solveEquation(equation);
    Logger::WriteMessage(equation + " " + result);
}

void TestLeetCode736(void)
{
    LeetCodeString leetCode;
    string expression = "(add 1 2)";
    int expected = 3;
    int result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(mult 3 (add 2 3))";
    expected = 15;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 2 (mult x 5))";
    expected = 10;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    expected = 14;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 3 x 2 x)";
    expected = 2;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 1 y 2 x (add x y) (add x y))";
    expected = 5;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let x 2 (add (let x 3 (let x 4 x)) x))";
    expected = 6;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));

    expression = "(let a1 3 b2 (add a1 1) b2)";
    expected = 4;
    result = leetCode.evaluate(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
    result = leetCode.evaluate_V2(expression);
    Logger::WriteMessage("expression = " + expression + "; expected = " + to_string(expected) + "; result = " + to_string(result));
}

void TestLeetCode751(void)
{
    Logger::WriteMessage("Test Leet Code 752");
    LeetCodeString leetCode;
    string ip = "255.0.0.7";
    int n = 10;
    vector<string> result = leetCode.ipToCIDR(ip, n);
    Logger::WriteMessage("ip = " + ip + "; n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode844(void)
{
    Logger::WriteMessage("Test Leet Code 844");
    LeetCodeString leetCode;
    string S = "ab#c";
    string T = "ad#c";
    bool result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");

    S = "ab##";
    T = "c#d#";
    result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");

    S = "a##c";
    T = "#a#c";
    result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");

    S = "a#c";
    T = "b";
    result = leetCode.backspaceCompare(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T);
    Logger::WriteMessage(result ? "true" : "false");
}

void TestLeetCode758(void)
{
    Logger::WriteMessage("Test Leet Code 758");
    LeetCodeString leetCode;
    vector<string> words = { "ab", "bc" };
    string S = "aabcd";
    string result = leetCode.boldWords(words, S);
    Logger::WriteMessage(words);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode859(void)
{
    Logger::WriteMessage("Test Leet Code 859");
    LeetCodeString leetCode;
    string A = "ab";
    string B = "ba";
    bool result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "ab";
    B = "ab";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "aa";
    B = "aa";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "aaaaaaabc";
    B = "aaaaaaacb";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));

    A = "";
    B = "aa";
    result = leetCode.buddyStrings(A, B);
    Logger::WriteMessage("A = " + A + "; B = " + B + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode777(void)
{
    Logger::WriteMessage("Test Leet Code 777");
    LeetCodeString leetCode;
    string start = "RXXLRXRXL";
    string end = "XRLXXRRLX";
    bool result = leetCode.canTransform(start, end);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + (string)(result ? "true" : "false"));

    start = "RXXLRXRXL";
    end = "XLRXXRRLX";
    result = leetCode.canTransform(start, end);
    Logger::WriteMessage("start = " + start + "; end = " + end + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1002(void)
{
    Logger::WriteMessage("Test Leet Code 1002");
    LeetCodeString leetCode;
    vector<string> A = { "bella", "label", "roller" };
    vector<string> result = leetCode.commonChars(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);

    A = { "cool", "lock", "cook" };
    result = leetCode.commonChars(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode9900(void)
{
    Logger::WriteMessage("Test Leet Code 9900");
    LeetCodeString leetCode;
    string str = "abc";
    int k = 2;
    int result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "aba";
    k = 2;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "aa";
    k = 1;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "abcaaaab";
    k = 3;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));

    str = "abcbaa";
    k = 3;
    result = leetCode.countkDist(str, k);
    Logger::WriteMessage("str = " + str + "; " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode791(void)
{
    Logger::WriteMessage("Test Leet Code 791");
    LeetCodeString leetCode;
    string S = "cba";
    string T = "abcd";
    string result = leetCode.customSortString(S, T);
    Logger::WriteMessage("S = " + S + "; T = " + T + "; result = " + result);
}

void TestLeetCode809(void)
{
    Logger::WriteMessage("Test Leet Code 809");
    LeetCodeString leetCode;
    string S = "heeellooo";
    vector<string> words = { "hello", "hi", "helo" };
    int result = leetCode.expressiveWords(S, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("S = " + S + "; result = " + to_string(result));
}

void TestLeetCode833(void)
{
    Logger::WriteMessage("Test Leet Code 833");
    LeetCodeString leetCode;

    string S = "abcd";
    vector<int> indexes = { 0, 2 };
    vector<string> sources = { "a", "cd" };
    vector<string> targets = { "eee","ffff" };
    string result = leetCode.findReplaceString(S, indexes, sources, targets);
    Logger::WriteMessage(indexes);
    Logger::WriteMessage(sources);
    Logger::WriteMessage(targets);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "abcd";
    indexes = { 0, 2 };
    sources = { "ab","ec" };
    targets = { "eee","ffff" };
    result = leetCode.findReplaceString(S, indexes, sources, targets);
    Logger::WriteMessage(indexes);
    Logger::WriteMessage(sources);
    Logger::WriteMessage(targets);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "vmokgggqzp";
    indexes = { 3, 5, 1 };
    sources = { "kg", "ggq", "mo" };
    targets = { "s", "so", "bfr" };
    result = leetCode.findReplaceString(S, indexes, sources, targets);
    Logger::WriteMessage(indexes);
    Logger::WriteMessage(sources);
    Logger::WriteMessage(targets);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode925(void)
{
    Logger::WriteMessage("Test Leet Code 925");
    LeetCodeString leetCode;
    string name = "alex";
    string typed = "aaleex";
    bool result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));

    name = "saeed";
    typed = "ssaaedd";
    result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));

    name = "leelee";
    typed = "lleeelee";
    result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));

    name = "laiden";
    typed = "laiden";
    result = leetCode.isLongPressedName(name, typed);
    Logger::WriteMessage("name = " + name + "; typed = " + typed + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1163(void)
{
    Logger::WriteMessage("Test Leet Code 1163");
    LeetCodeString leetCode;
    string s = "abab";
    string result = leetCode.lastSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "leetcode";
    result = leetCode.lastSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode761(void)
{
    Logger::WriteMessage("Test Leet Code 761");
    LeetCodeString leetCode;
    string S = "11011000";
    string result = leetCode.makeLargestSpecial(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode831(void)
{
    Logger::WriteMessage("Test Leet Code 831");
    LeetCodeString leetCode;
    string S = "LeetCode@LeetCode.com";
    string result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "AB@qq.com";
    result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "1(234)567-890";
    result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "86-(10)12345678";
    result = leetCode.maskPII(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode820(void)
{
    Logger::WriteMessage("Test Leet Code 820");
    LeetCodeString leetCode;
    vector<string> words = { "time", "me", "bell" };
    int result = leetCode.minimumLengthEncoding(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode819(void)
{
    Logger::WriteMessage("Test Leet Code 819");
    LeetCodeString leetCode;
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned = { "hit" };
    string result = leetCode.mostCommonWord(paragraph, banned);
    Logger::WriteMessage(paragraph);
    Logger::WriteMessage(banned);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode806(void)
{
    Logger::WriteMessage("Test Leet Code 806");
    LeetCodeString leetCode;
    vector<int> widths = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
    string S = "abcdefghijklmnopqrst";
    vector<int> result = leetCode.numberOfLines(widths, S);
    Logger::WriteMessage(widths);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    widths = { 4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,100 };
    S = "bbbcccdddaaa";
    result = leetCode.numberOfLines(widths, S);
    Logger::WriteMessage(widths);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode771(void)
{
    Logger::WriteMessage("Test Leet Code 771");
    LeetCodeString leetCode;
    string J = "aA";
    string S = "aAAbbbb";
    int result = leetCode.numJewelsInStones(J, S);
    Logger::WriteMessage("J = " + J + "; S = " + S + "; result = " + to_string(result));
    J = "z";
    S = "ZZ";
    result = leetCode.numJewelsInStones(J, S);
    Logger::WriteMessage("J = " + J + "; S = " + S + "; result = " + to_string(result));
}

void TestLeetCode893(void)
{
    Logger::WriteMessage("Test Leet Code 893");
    LeetCodeString leetCode;
    vector<string> A = { "a","b","c","a","c","c" };
    int result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "aa","bb","ab","ba" };
    result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "abc","acb","bac","bca","cab","cba" };
    result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { "abcd","cdab","adcb","cbad" };
    result = leetCode.numSpecialEquivGroups(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode929(void)
{
    Logger::WriteMessage("Test Leet Code 929");
    LeetCodeString leetCode;
    vector<string> emails =
    {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };
    int result = leetCode.numUniqueEmails(emails);
    Logger::WriteMessage(emails);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode899(void)
{
    Logger::WriteMessage("Test Leet Code 899");
    LeetCodeString leetCode;
    string S = "cba";
    int K = 1;
    string result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "baaca";
    K = 3;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "abcedaa";
    K = 3;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "v";
    K = 1;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "kuh";
    K = 1;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);

    S = "pplpkohe";
    K = 3;
    result = leetCode.orderlyQueue(S, K);
    Logger::WriteMessage("S = " + S + "; K = " + to_string(K) + "; result = " + result);
}

void TestLeetCode9904(void)
{
    Logger::WriteMessage("Test Leet Code 9904");
    LeetCodeString leetCode;
    vector<string> lines =
    {
        "John,Smith,john.smith@gmail.com,Los Angeles,1",
        "Jane, Roberts, janer@msn.com, \"San Francisco, CA\", 0",
        "Huanmin, Wu,,,",
        "\"Alexandra \"\"Alex\"\"\", Menendez, alex.menendez@gmail.com, Miami, 1",
        "\"\"\"Alexandra Alex\"\"\""
    };
    vector<vector<string>> result = leetCode.parseCSV(lines);
    for (string line : lines)Logger::WriteMessage(line);
    Logger::WriteMessage(result);
}

void TestLeetCode763(void)
{
    Logger::WriteMessage("Test Leet Code 763");
    LeetCodeString leetCode;
    string S = "ababcbacadefegdehijhklij";
    vector<int> result = leetCode.partitionLabels(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode1021(void)
{
    Logger::WriteMessage("Test Leet Code 1021");
    LeetCodeString leetCode;
    string S = "(()())(())";
    string result = leetCode.removeOuterParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "(()())(())(()(()))";
    result = leetCode.removeOuterParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "()()";
    result = leetCode.removeOuterParentheses(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode937(void)
{
    Logger::WriteMessage("Test Leet Code 937");
    LeetCodeString leetCode;
    vector<string> logs =
    {
        "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"
    };
    vector<string> result = leetCode.reorderLogFiles(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage(result);
}

void TestLeetCode767(void)
{
    Logger::WriteMessage("Test Leet Code 767");
    LeetCodeString leetCode;
    string S = "aab";
    string result = leetCode.reorganizeString(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "aaab";
    result = leetCode.reorganizeString(S);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode848(void)
{
    Logger::WriteMessage("Test Leet Code 848");
    LeetCodeString leetCode;
    string S = "abc";
    vector<int> shifts = { 3,5,9 };
    string result = leetCode.shiftingLetters(S, shifts);
    Logger::WriteMessage(shifts);
    Logger::WriteMessage("S = " + S + "; result = " + result);

    S = "mkgfzkkuxownxvfvxasy";
    shifts =
    {
        505870226, 437526072, 266740649, 224336793, 532917782, 311122363, 567754492, 595798950,
        81520022, 684110326, 137742843, 275267355, 856903962, 148291585, 919054234, 467541837,
        622939912, 116899933, 983296461, 536563513
    };
    result = leetCode.shiftingLetters(S, shifts);
    Logger::WriteMessage(shifts);
    Logger::WriteMessage("S = " + S + "; result = " + result);
}

void TestLeetCode842(void)
{
    Logger::WriteMessage("Test Leet Code 842");
    LeetCodeString leetCode;
    string S = "123456579";
    vector<int> result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "11235813";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "112358130";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "0123";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "1101111";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "011";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);

    S = "214748364721474836422147483641";
    result = leetCode.splitIntoFibonacci(S);
    Logger::WriteMessage("S = " + S);
    Logger::WriteMessage(result);
}

void TestLeetCode824(void)
{
    Logger::WriteMessage("Test Leet Code 824");
    LeetCodeString leetCode;
    string S = "I speak Goat Latin";
    string result = leetCode.toGoatLatin(S);
    Logger::WriteMessage("S= " + S + "; result = " + result);

    S = "The quick brown fox jumped over the lazy dog";
    result = leetCode.toGoatLatin(S);
    Logger::WriteMessage("S= " + S + "; result = " + result);
}


void TestLeetCode804(void)
{
    Logger::WriteMessage("Test Leet Code 804");
    LeetCodeString leetCode;
    vector<string> words = { "gin", "zen", "gig", "msg" };
    int result = leetCode.uniqueMorseRepresentations(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode678(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 678");
    string s = "()";
    bool isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));

    s = "(*)";
    isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));

    s = "(*))";
    isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));

    s = "())*";
    isValid = leetCode.checkValidString(s);
    Logger::WriteMessage("s = " + s + "; is valid = " + (string)(isValid ? "true" : "false"));
}

void TestLeetCode1507(void)
{
    LeetCodeString leetCode;
    Logger::WriteMessage("Test Leet Code 1507");
    string date = "20th Oct 2052";
    string result = leetCode.reformatDate(date);
    Logger::WriteMessage("date = " + date + "; result = " + result);

    date = "6th Jun 1933";
    result = leetCode.reformatDate(date);
    Logger::WriteMessage("date = " + date + "; result = " + result);

    date = "26th May 1960";
    result = leetCode.reformatDate(date);
    Logger::WriteMessage("date = " + date + "; result = " + result);
}

void TestLeetCode1531(void)
{
    Logger::WriteMessage("Test Leet Code 1531");
    LeetCodeString leetCode;
    string s = "aaabcccd";
    int k = 2;
    int result = leetCode.getLengthOfOptimalCompression(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "aabbaa";
    k = 2;
    result = leetCode.getLengthOfOptimalCompression(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "aaaaaaaaaaa";
    k = 0;
    result = leetCode.getLengthOfOptimalCompression(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1528(void)
{
    Logger::WriteMessage("Test Leet Code 1528");
    LeetCodeString leetCode;
    string s = "codeleet";
    vector<int> indices = { 4, 5, 6, 7, 0, 2, 1, 3 };
    string result = leetCode.restoreString(s, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "abc";
    indices = { 0,1,2 };
    result = leetCode.restoreString(s, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "aiohn";
    indices = { 3,1,4,2,0 };
    result = leetCode.restoreString(s, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "aaiougrt";
    indices = { 4,0,2,6,7,3,1,5 };
    result = leetCode.restoreString(s, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "art";
    indices = { 1,0,2 };
    result = leetCode.restoreString(s, indices);
    Logger::WriteMessage(indices);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1525(void)
{
    Logger::WriteMessage("Test Leet Code 1525");
    LeetCodeString leetCode;
    string s = "aacaba";
    int result = leetCode.numSplits(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abcd";
    result = leetCode.numSplits(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aaaaa";
    result = leetCode.numSplits(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "acbadbaada";
    result = leetCode.numSplits(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1540(void)
{
    Logger::WriteMessage("Test Leet Code 1540");
    LeetCodeString leetCode;
    string  s = "input";
    string t = "ouput";
    int k = 9;
    bool result = leetCode.canConvertString(s, t, k);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    s = "abc";
    t = "bcd";
    k = 10;
    result = leetCode.canConvertString(s, t, k);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));

    s = "aab";
    t = "bbb";
    k = 27;
    result = leetCode.canConvertString(s, t, k);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; k = " + to_string(k) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1541(void)
{
    Logger::WriteMessage("Test Leet Code 1541");
    LeetCodeString leetCode;
    string s = "(()))";
    int result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "())";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "))())(";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "((((((";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = ")))))))";
    result = leetCode.minInsertions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1542(void)
{
    Logger::WriteMessage("Test Leet Code 1542");
    LeetCodeString leetCode;
    string s = "3242415";
    int result = leetCode.longestAwesome(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "12345678";
    result = leetCode.longestAwesome(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "213123";
    result = leetCode.longestAwesome(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "00";
    result = leetCode.longestAwesome(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1544(void)
{
    Logger::WriteMessage("Test Leet Code 1544");
    LeetCodeString leetCode;
    string s = "leEeetcode";
    string result = leetCode.makeGood(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "abBAcC";
    result = leetCode.makeGood(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "s";
    result = leetCode.makeGood(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1554(void)
{
    Logger::WriteMessage("Test Leet Code 1554");
    LeetCodeString leetCode;
    vector<string> dict = { "abcd", "acbd", "aacd" };
    bool result = leetCode.differByOne(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    dict = { "ab","cd","yz" };
    result = leetCode.differByOne(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    dict = { "abcd","cccc","abyd","abab" };
    result = leetCode.differByOne(dict);
    Logger::WriteMessage(dict);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1556(void)
{
    Logger::WriteMessage("Test Leet Code 1556");
    LeetCodeString leetCode;
    int n = 987;
    string result = leetCode.thousandSeparator(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + result);

    n = 1234;
    result = leetCode.thousandSeparator(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + result);

    n = 123456789;
    result = leetCode.thousandSeparator(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + result);

    n = 0;
    result = leetCode.thousandSeparator(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + result);
}

void TestLeetCode1573(void)
{
    Logger::WriteMessage("Test Leet Code 1573");
    LeetCodeString leetCode;
    string s = "10101";
    int result = leetCode.numWays(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "1001";
    result = leetCode.numWays(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "0000";
    result = leetCode.numWays(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "100100010100110";
    result = leetCode.numWays(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1576(void)
{
    Logger::WriteMessage("Test Leet Code 1576");
    LeetCodeString leetCode;
    string s = "?zs";
    string result = leetCode.modifyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "ubv?w";
    result = leetCode.modifyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "j?qg??b";
    result = leetCode.modifyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "??yw?ipkj?";
    result = leetCode.modifyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1578(void)
{
    Logger::WriteMessage("Test Leet Code 1578");
    LeetCodeString leetCode;
    string s = "abaac";
    vector<int> cost = { 1, 2, 3, 4, 5 };
    int result = leetCode.minCost(s, cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abc";
    cost = { 1, 2, 3};
    result = leetCode.minCost(s, cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aabaa";
    cost = { 1,2,3,4,1 };
    result = leetCode.minCost(s, cost);
    Logger::WriteMessage(cost);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1592(void)
{
    Logger::WriteMessage("Test Leet Code 1592");
    LeetCodeString leetCode;
    string text = "  this   is  a sentence ";
    string result = leetCode.reorderSpaces(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = " practice   makes   perfect";
    result = leetCode.reorderSpaces(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "hello   world";
    result = leetCode.reorderSpaces(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "  walks  udp package   into  bar a";
    result = leetCode.reorderSpaces(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);

    text = "a ";
    result = leetCode.reorderSpaces(text);
    Logger::WriteMessage("text = " + text + "; result = " + result);
}

void TestLeetCode1614(void)
{
    Logger::WriteMessage("Test Leet Code 1614");
    LeetCodeString leetCode;
    string s = "(1+(2*3)+((8)/4))+1";
    int result = leetCode.maxDepth(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "(1)+((2))+(((3)))";
    result = leetCode.maxDepth(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "1+(2*3)/(2-1)";
    result = leetCode.maxDepth(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "1";
    result = leetCode.maxDepth(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1598(void)
{
    Logger::WriteMessage("Test Leet Code 1598");
    LeetCodeString leetCode;
    vector<string> logs = { "d1/","d2/","../","d21/","./" };
    int result = leetCode.minOperations(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage("result = " + to_string(result));

    logs = { "d1/", "d2/", "./", "d3/", "../", "d31/" };
    result = leetCode.minOperations(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage("result = " + to_string(result));

    logs = { "d1/","../","../","../" };
    result = leetCode.minOperations(logs);
    Logger::WriteMessage(logs);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1616(void)
{
    Logger::WriteMessage("Test Leet Code 1616");
    LeetCodeString leetCode;
    string a = "x";
    string b = "y";
    bool result = leetCode.checkPalindromeFormation(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + (string)(result ? "true" : "false"));

    a = "abdef";
    b = "fecab";
    result = leetCode.checkPalindromeFormation(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + (string)(result ? "true" : "false"));

    a = "ulacfd";
    b = "jizalu";
    result = leetCode.checkPalindromeFormation(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + (string)(result ? "true" : "false"));

    a = "xbdef";
    b = "xecab";
    result = leetCode.checkPalindromeFormation(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + (string)(result ? "true" : "false"));

    a = "pvhmupgqeltozftlmfjjde";
    b = "yjgpzbezspnnpszebzmhvp";
    result = leetCode.checkPalindromeFormation(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1618(void)
{
    Logger::WriteMessage("Test Leet Code 1618");
    LeetCodeString leetCode;
    string text = "helloworld";
    int w = 80;
    int h = 20;
    vector <int> fonts = { 6, 8, 10, 12, 14, 16, 18, 24, 36 };
    int result = leetCode.maxFont(text, w, h, fonts);
    Logger::WriteMessage("w = " + to_string(w) + "; h = " + to_string(h) + "; result = " + to_string(result));

    text = "leetcode";
    w = 1000;
    h = 50;
    fonts = { 1,2,4 };
    result = leetCode.maxFont(text, w, h, fonts);
    Logger::WriteMessage("w = " + to_string(w) + "; h = " + to_string(h) + "; result = " + to_string(result));

    text = "easyquestion";
    w = 100;
    h = 100;
    fonts = { 10,15,20,25 };
    result = leetCode.maxFont(text, w, h, fonts);
    Logger::WriteMessage("w = " + to_string(w) + "; h = " + to_string(h) + "; result = " + to_string(result));
}

void TestLeetCode1624(void)
{
    Logger::WriteMessage("Test Leet Code 1624");
    LeetCodeString leetCode;
    string s = "aa";
    int result = leetCode.maxLengthBetweenEqualCharacters(s);
    Logger::WriteMessage("result = " + to_string(result));

    s = "abca";
    result = leetCode.maxLengthBetweenEqualCharacters(s);
    Logger::WriteMessage("result = " + to_string(result));

    s = "cbzxy";
    result = leetCode.maxLengthBetweenEqualCharacters(s);
    Logger::WriteMessage("result = " + to_string(result));

    s = "cabbac";
    result = leetCode.maxLengthBetweenEqualCharacters(s);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1625(void)
{
    Logger::WriteMessage("Test Leet Code 1625");
    LeetCodeString leetCode;
    string s = "5525";
    int a = 9;
    int b = 2;
    string result = leetCode.findLexSmallestString(s, a, b);
    Logger::WriteMessage("a = " + to_string(a) + "b = " + to_string(b) + "; result = " + result);

    s = "74";
    a = 5;
    b = 1;
    result = leetCode.findLexSmallestString(s, a, b);
    Logger::WriteMessage("a = " + to_string(a) + "b = " + to_string(b) + "; result = " + result);

    s = "0011";
    a = 4;
    b = 2;
    result = leetCode.findLexSmallestString(s, a, b);
    Logger::WriteMessage("a = " + to_string(a) + "b = " + to_string(b) + "; result = " + result);

    s = "43987654";
    a = 7;
    b = 3;
    result = leetCode.findLexSmallestString(s, a, b);
    Logger::WriteMessage("a = " + to_string(a) + "b = " + to_string(b) + "; result = " + result);
}

void TestLeetCode1638(void)
{
    Logger::WriteMessage("Test Leet Code 1638");
    LeetCodeString leetCode;
    string s = "aba";
    string t = "baba";
    int result = leetCode.countSubstrings(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "ab";
    t = "bb";
    result = leetCode.countSubstrings(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "a";
    t = "a";
    result = leetCode.countSubstrings(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "abe";
    t = "bbc";
    result = leetCode.countSubstrings(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));

    s = "abbab";
    t = "bbbbb";
    result = leetCode.countSubstrings(s, t);
    Logger::WriteMessage("s = " + s + "; t = " + t + "; result = " + to_string(result));
}

void TestLeetCode1647(void)
{
    Logger::WriteMessage("Test Leet Code 1647");
    LeetCodeString leetCode;
    string s = "aab";
    int result = leetCode.minDeletions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
    
    s = "aaabbbcc";
    result = leetCode.minDeletions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "ceabaacb";
    result = leetCode.minDeletions(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1657(void)
{
    Logger::WriteMessage("Test Leet Code 1657");
    LeetCodeString leetCode;
    string word1 = "abc";
    string word2 = "bca";
    bool result = leetCode.closeStrings(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + (string)(result ? "true" : " false"));

    word1 = "a";
    word2 = "aa";
    result = leetCode.closeStrings(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + (string)(result ? "true" : " false"));

    word1 = "cabbba";
    word2 = "abbccc";
    result = leetCode.closeStrings(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + (string)(result ? "true" : " false"));

    word1 = "cabbba";
    word2 = "aabbss";
    result = leetCode.closeStrings(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + "; result = " + (string)(result ? "true" : " false"));
}

void TestLeetCode1668(void)
{
    Logger::WriteMessage("Test Leet Code 1668");
    LeetCodeString leetCode;
    string sequence = "ababc";
    string word = "ab";
    int result = leetCode.maxRepeating(sequence, word);
    Logger::WriteMessage("sequence = " + sequence + "; word = " + word + "; result = " + to_string(result));

    sequence = "ababac";
    word = "ba";
    result = leetCode.maxRepeating(sequence, word);
    Logger::WriteMessage("sequence = " + sequence + "; word = " + word + "; result = " + to_string(result));

    sequence = "abadbac";
    word = "ba";
    result = leetCode.maxRepeating(sequence, word);
    Logger::WriteMessage("sequence = " + sequence + "; word = " + word + "; result = " + to_string(result));

    sequence = "ababc";
    word = "ac";
    result = leetCode.maxRepeating(sequence, word);
    Logger::WriteMessage("sequence = " + sequence + "; word = " + word + "; result = " + to_string(result));

    sequence = "aaa";
    word = "a";
    result = leetCode.maxRepeating(sequence, word);
    Logger::WriteMessage("sequence = " + sequence + "; word = " + word + "; result = " + to_string(result));
}

void TestLeetCode1678(void)
{
    Logger::WriteMessage("Test Leet Code 1678");
    LeetCodeString leetCode;
    string command = "G()(al)";
    string result = leetCode.interpret(command);
    Logger::WriteMessage("command = " + command + "; result = " + result);

    command = "G()()()()(al)";
    result = leetCode.interpret(command);
    Logger::WriteMessage("command = " + command + "; result = " + result);

    command = "(al)G(al)()()G";
    result = leetCode.interpret(command);
    Logger::WriteMessage("command = " + command + "; result = " + result);
}

void TestLeetCode1684(void)
{
    Logger::WriteMessage("Test Leet Code 1684");
    LeetCodeString leetCode;
    string allowed = "ab";
    vector<string> words = { "ad", "bd", "aaab", "baa", "badab" };
    int result = leetCode.countConsistentStrings(allowed, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("allowed = " + allowed + "; result = " + to_string(result));

    allowed = "abc";
    words = { "a","b","c","ab","ac","bc","abc" };
    result = leetCode.countConsistentStrings(allowed, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("allowed = " + allowed + "; result = " + to_string(result));

    allowed = "cad";
    words = { "cc","acd","b","ba","bac","bad","ac","d" };
    result = leetCode.countConsistentStrings(allowed, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("allowed = " + allowed + "; result = " + to_string(result));
}

void TestLeetCode1694(void)
{
    Logger::WriteMessage("Test Leet Code 1694");
    LeetCodeString leetCode;
    string number = "1-23-45 6";
    string result = leetCode.reformatNumber(number);
    Logger::WriteMessage("number = " + number + "; result = " + result);

    number = "123 4-567";
    result = leetCode.reformatNumber(number);
    Logger::WriteMessage("number = " + number + "; result = " + result);

    number = "123 4-5678";
    result = leetCode.reformatNumber(number);
    Logger::WriteMessage("number = " + number + "; result = " + result);

    number = "12";
    result = leetCode.reformatNumber(number);
    Logger::WriteMessage("number = " + number + "; result = " + result);

    number = "--17-5 229 35-39475 ";
    result = leetCode.reformatNumber(number);
    Logger::WriteMessage("number = " + number + "; result = " + result);
}

void TestLeetCode1698(void)
{
    Logger::WriteMessage("Test Leet Code 1698");
    LeetCodeString leetCode;
    string s = "aabbaba";
    int result = leetCode.countDistinct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "abcdefg";
    result = leetCode.countDistinct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1702(void)
{
    Logger::WriteMessage("Test Leet Code 1702");
    LeetCodeString leetCode;
    string binary = "000110";
    string result = leetCode.maximumBinaryString(binary);
    Logger::WriteMessage("binary = " + binary + "; result = " + result);

    binary = "01";
    result = leetCode.maximumBinaryString(binary);
    Logger::WriteMessage("binary = " + binary + "; result = " + result);
}

void TestLeetCode1704(void)
{
    Logger::WriteMessage("Test Leet Code 1704");
    LeetCodeString leetCode;
    string s = "book";
    bool result = leetCode.halvesAreAlike(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "textbook";
    result = leetCode.halvesAreAlike(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "MerryChristmas";
    result = leetCode.halvesAreAlike(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "AbCdEfGh";
    result = leetCode.halvesAreAlike(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1717(void)
{
    Logger::WriteMessage("Test Leet Code 1717");
    LeetCodeString leetCode;
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    int result = leetCode.maximumGain(s, x, y);
    Logger::WriteMessage("s = " + s + "; x = " + to_string(x) + 
        "; y = " + to_string(y) + "; result = " + to_string(result));

    s = "aabbaaxybbaabb";
    x = 5;
    y = 4;
    result = leetCode.maximumGain(s, x, y);
    Logger::WriteMessage("s = " + s + "; x = " + to_string(x) +
        "; y = " + to_string(y) + "; result = " + to_string(result));
}

void TestLeetCode1736(void)
{
    Logger::WriteMessage("Test Leet Code 1736");
    LeetCodeString leetCode;
    string time = "2?:?0";
    string result = leetCode.maximumTime(time);
    Logger::WriteMessage("time = " + time + "; result = " + result);

    time = "0?:3?";
    result = leetCode.maximumTime(time);
    Logger::WriteMessage("time = " + time + "; result = " + result);

    time = "1?:22";
    result = leetCode.maximumTime(time);
    Logger::WriteMessage("time = " + time + "; result = " + result);
}

void TestLeetCode1737(void)
{
    Logger::WriteMessage("Test Leet Code 1737");
    LeetCodeString leetCode;
    string a = "aba";
    string b = "caa";
    int result = leetCode.minCharacters(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + to_string(result));

    a = "dabadd";
    b = "cda";
    result = leetCode.minCharacters(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + to_string(result));

    a = "a";
    b = "aabzz";
    result = leetCode.minCharacters(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + to_string(result));

    a = "azz";
    b = "zz";
    result = leetCode.minCharacters(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + to_string(result));
}

void TestLeetCode1754(void)
{
    Logger::WriteMessage("Test Leet Code 1754");
    LeetCodeString leetCode;
    string word1 = "cabaa";
    string word2 = "bcaaa";
    string result = leetCode.largestMerge(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 + 
        "; result = " + result);

    word1 = "abcabc";
    word2 = "abdcaba";
    result = leetCode.largestMerge(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 +
        "; result = " + result);

    word1 = "guguuuuuuuuuuuuuuguguuuuguug";
    word2 = "gguggggggguuggguugggggg";
    result = leetCode.largestMerge(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 +
        "; result = " + result);  
}

void TestLeetCode1768(void)
{
    Logger::WriteMessage("Test Leet Code 1768");
    LeetCodeString leetCode;
    string word1 = "abc";
    string word2 = "pqr";
    string result = leetCode.mergeAlternately(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 +
        "; result = " + result);

    word1 = "ab";
    word2 = "pqrs";
    result = leetCode.mergeAlternately(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 +
        "; result = " + result);

    word1 = "abcd";
    word2 = "pq";
    result = leetCode.mergeAlternately(word1, word2);
    Logger::WriteMessage("word1 = " + word1 + "; word2 = " + word2 +
        "; result = " + result);
}

void TestLeetCode1763(void)
{
    Logger::WriteMessage("Test Leet Code 1763");
    LeetCodeString leetCode;
    string s = "YazaAay";
    string result = leetCode.longestNiceSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "Bb";
    result = leetCode.longestNiceSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "c";
    result = leetCode.longestNiceSubstring(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1750(void)
{
    Logger::WriteMessage("Test Leet Code 1760");
    LeetCodeString leetCode;
    string s = "ca";
    int result = leetCode.minimumLength(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "cabaabac";
    result = leetCode.minimumLength(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aabccabba";
    result = leetCode.minimumLength(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1781(void)
{
    Logger::WriteMessage("Test Leet Code 1781");
    LeetCodeString leetCode;
    string s = "aabcb";
    int result = leetCode.beautySum(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aabcbaa";
    result = leetCode.beautySum(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aabccabba";
    result = leetCode.beautySum(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1784(void)
{
    Logger::WriteMessage("Test Leet Code 1784");
    LeetCodeString leetCode;
    string s = "1001";
    bool result = leetCode.checkOnesSegment(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "110";
    result = leetCode.checkOnesSegment(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1790(void)
{
    Logger::WriteMessage("Test Leet Code 1790");
    LeetCodeString leetCode;
    string s1 = "bank";
    string s2 = "kanb";
    bool result = leetCode.areAlmostEqual(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "attack";
    s2 = "defend";
    result = leetCode.areAlmostEqual(s1, s2);
    Logger::WriteMessage("s1 = " + s1  + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "kelb";
    s2 = "kelb";
    result = leetCode.areAlmostEqual(s1, s2);
    Logger::WriteMessage("s1 = " + s1 +"; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));

    s1 = "abcd";
    s2 = "dcba";
    result = leetCode.areAlmostEqual(s1, s2);
    Logger::WriteMessage("s1 = " + s1 + "; s2 = " + s2 + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1796(void)
{
    Logger::WriteMessage("Test Leet Code 1796");
    LeetCodeString leetCode;
    string s = "dfa12321afd";
    int result = leetCode.secondHighest(s);
    Logger::WriteMessage("s = " + s  + "; result = " + to_string(result));

    s = "abc1111";
    result = leetCode.secondHighest(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1805(void)
{
    Logger::WriteMessage("Test Leet Code 1805");
    LeetCodeString leetCode;
    string s = "a123bc34d8ef34";
    int result = leetCode.numDifferentIntegers(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "leet1234code234";
    result = leetCode.numDifferentIntegers(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "a1b01c001";
    result = leetCode.numDifferentIntegers(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "0a0";
    result = leetCode.numDifferentIntegers(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
 
    s = "4r05743a05743n05743yoe";
    result = leetCode.numDifferentIntegers(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1807(void)
{
    Logger::WriteMessage("Test Leet Code 1807");
    LeetCodeString leetCode;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> knowledge = { {"name", "bob"},{"age", "two"} };
    string result = leetCode.evaluate(s, knowledge);
    Logger::WriteMessage(knowledge);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "hi(name)";
    knowledge = { {"a","b"} };
    result = leetCode.evaluate(s, knowledge);
    Logger::WriteMessage(knowledge);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "(a)(a)(a)aaa";
    knowledge = { {"a","yes"} };
    result = leetCode.evaluate(s, knowledge);
    Logger::WriteMessage(knowledge);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "(a)(b)";
    knowledge = { {"a","b"}, {"b","a"} };
    result = leetCode.evaluate(s, knowledge);
    Logger::WriteMessage(knowledge);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1813(void)
{
    Logger::WriteMessage("Test Leet Code 1813");
    LeetCodeString leetCode;
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";
    bool result = leetCode.areSentencesSimilar(sentence1, sentence2);
    Logger::WriteMessage("sentence1 = " + sentence1 + "; sentence2 = " + sentence2 + 
        "; result = " + (string)(result ? "true" : "false"));

    sentence1 = "of";
    sentence2 = "My Haley";
    result = leetCode.areSentencesSimilar(sentence1, sentence2);
    Logger::WriteMessage("sentence1 = " + sentence1 + "; sentence2 = " + sentence2 +
        "; result = " + (string)(result ? "true" : "false"));

    sentence1 = "Eating right now";
    sentence2 = "Eating";
    result = leetCode.areSentencesSimilar(sentence1, sentence2);
    Logger::WriteMessage("sentence1 = " + sentence1 + "; sentence2 = " + sentence2 +
        "; result = " + (string)(result ? "true" : "false"));
    
    sentence1 = "Eating right now";
    sentence2 = "Eating right";
    result = leetCode.areSentencesSimilar(sentence1, sentence2);
    Logger::WriteMessage("sentence1 = " + sentence1 + "; sentence2 = " + sentence2 +
        "; result = " + (string)(result ? "true" : "false"));

    sentence1 = "Luky";
    sentence2 = "Lucccky";
    result = leetCode.areSentencesSimilar(sentence1, sentence2);
    Logger::WriteMessage("sentence1 = " + sentence1 + "; sentence2 = " + sentence2 +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1816(void)
{
    Logger::WriteMessage("Test Leet Code 1816");
    LeetCodeString leetCode;
    string s = "Hello how are you Contestant";
    int k = 4;
    string result = leetCode.truncateSentence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);

    s = "What is the solution to this problem";
    k = 4;
    result = leetCode.truncateSentence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);

    s = "chopper is not a tanuki";
    k = 5;
    result = leetCode.truncateSentence(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1832(void)
{
    Logger::WriteMessage("Test Leet Code 1832");
    LeetCodeString leetCode;
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    bool result = leetCode.checkIfPangram(sentence);
    Logger::WriteMessage("sentence = " + sentence + "; result = " + (string)(result ? "true" : "false"));

    sentence = "leetcode";
    result = leetCode.checkIfPangram(sentence);
    Logger::WriteMessage("sentence = " + sentence + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1794(void)
{
    Logger::WriteMessage("Test Leet Code 1794");
    LeetCodeString leetCode;
    string firstString = "abcd";
    string secondString = "bccda";
    int result = leetCode.countQuadruples(firstString, secondString);
    Logger::WriteMessage("firstString = " + firstString + 
        "; secondString = " + secondString + 
        "; result = " + to_string(result));

    firstString = "ab";
    secondString = "cd";
    result = leetCode.countQuadruples(firstString, secondString);
    Logger::WriteMessage("firstString = " + firstString +
        "; secondString = " + secondString +
        "; result = " + to_string(result));
}

void TestLeetCode1839(void)
{
    Logger::WriteMessage("Test Leet Code 1839");
    LeetCodeString leetCode;
    string word = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
    int result = leetCode.longestBeautifulSubstring(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "aeeeiiiioooauuuaeiou";
    result = leetCode.longestBeautifulSubstring(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "a";
    result = leetCode.longestBeautifulSubstring(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode1844(void)
{
    Logger::WriteMessage("Test Leet Code 1844");
    LeetCodeString leetCode;
    string s = "a1c1e1";
    string result = leetCode.replaceDigits(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "a1b2c3d4e";
    result = leetCode.replaceDigits(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1896(void)
{
    Logger::WriteMessage("Test Leet Code 1896");
    LeetCodeString leetCode;
    string expression = "1&(0|1)";
    int result = leetCode.minOperationsToFlip(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + to_string(result));

    expression = "(0&0)&(0&0&0)";
    result = leetCode.minOperationsToFlip(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + to_string(result));

    expression = "(0|(1|0&1))";
    result = leetCode.minOperationsToFlip(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + to_string(result));
}

void TestLeetCode1859(void)
{
    Logger::WriteMessage("Test Leet Code 1859");
    LeetCodeString leetCode;

    string s = "is2 sentence4 This1 a3";
    string result = leetCode.sortSentence(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "Myself2 Me1 I4 and3";
    result = leetCode.sortSentence(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

}

void TestLeetCode1869(void)
{
    Logger::WriteMessage("Test Leet Code 1869");
    LeetCodeString leetCode;

    string s = "1101";
    bool result = leetCode.checkZeroOnes(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string) (result ? "true" : "false"));

    s = "111000";
    result = leetCode.checkZeroOnes(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "110100010";
    result = leetCode.checkZeroOnes(s);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1876(void)
{
    Logger::WriteMessage("Test Leet Code 1876");
    LeetCodeString leetCode;

    string s = "xyzzaz";
    int result = leetCode.countGoodSubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "aababcabc";
    result = leetCode.countGoodSubstrings(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1880(void)
{
    Logger::WriteMessage("Test Leet Code 1880");
    LeetCodeString leetCode;
    string firstWord = "acb";
    string secondWord = "cba";
    string targetWord = "cdb";
    bool result = leetCode.isSumEqual(firstWord, secondWord, targetWord);
    Logger::WriteMessage("firstWord = " + firstWord +
        "; secondWord = " + secondWord +
        "; targetWord = " + targetWord + 
        "; result = " + (string) (result ? "true" : "false"));

    firstWord = "aaa";
    secondWord = "a";
    targetWord = "aab";
    result = leetCode.isSumEqual(firstWord, secondWord, targetWord);
    Logger::WriteMessage("firstWord = " + firstWord +
        "; secondWord = " + secondWord +
        "; targetWord = " + targetWord +
        "; result = " + (string)(result ? "true" : "false"));

    firstWord = "aaa";
    secondWord = "a";
    targetWord = "aaaa";
    result = leetCode.isSumEqual(firstWord, secondWord, targetWord);
    Logger::WriteMessage("firstWord = " + firstWord +
        "; secondWord = " + secondWord +
        "; targetWord = " + targetWord +
        "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1897(void)
{
    Logger::WriteMessage("Test Leet Code 1897");
    LeetCodeString leetCode;
    vector<string> words = { "abc", "aabc", "bc" };
    bool result = leetCode.makeEqual(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    words = { "ab","a" };
    result = leetCode.makeEqual(words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1903(void)
{
    Logger::WriteMessage("Test Leet Code 1903");
    LeetCodeString leetCode;
    string num = "52";
    string result = leetCode.largestOddNumber(num);
    Logger::WriteMessage("num = " + num +"; result = " + result);

    num = "4206";
    result = leetCode.largestOddNumber(num);
    Logger::WriteMessage("num = " + num + "; result = " + result);

    num = "35427";
    result = leetCode.largestOddNumber(num);
    Logger::WriteMessage("num = " + num + "; result = " + result);
}

void TestLeetCode1935(void)
{
    Logger::WriteMessage("Test Leet Code 1935");
    LeetCodeString leetCode;
    string text = "hello world";
    string brokenLetters = "ad";
    int result = leetCode.canBeTypedWords(text, brokenLetters);
    Logger::WriteMessage("text = " + text + "; brokenLetters = " + brokenLetters
        + "; result = " + to_string(result));

    text = "leet code";
    brokenLetters = "lt";
    result = leetCode.canBeTypedWords(text, brokenLetters);
    Logger::WriteMessage("text = " + text + "; brokenLetters = " + brokenLetters
        + "; result = " + to_string(result));

    text = "leet code";
    brokenLetters = "e";
    result = leetCode.canBeTypedWords(text, brokenLetters);
    Logger::WriteMessage("text = " + text + "; brokenLetters = " + brokenLetters
        + "; result = " + to_string(result));
}

void TestLeetCode1945(void)
{
    Logger::WriteMessage("Test Leet Code 1945");
    LeetCodeString leetCode;
    string s = "zbax";
    int k = 2;
    int result = leetCode.getLucky(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "iiii";
    k = 1;
    result = leetCode.getLucky(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));

    s = "leetcode";
    k = 2;
    result = leetCode.getLucky(s, k);
    Logger::WriteMessage("s = " + s + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1948(void)
{
    Logger::WriteMessage("Test Leet Code 1948");
    LeetCodeString leetCode;
    vector<vector<string>> paths = 
    { 
        {"a"},{"c"},{"d"},{"a", "b"},{"c", "b"},{"d", "a"} 
    };
    vector<vector<string>> result = leetCode.deleteDuplicateFolder(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);

    paths =
    {
        {"a"}, { "c" }, { "a", "b" }, { "c", "b" }, { "a", "b", "x" }, { "a", "b", "x", "y" },
        { "w" }, { "w", "y" }
    };
    result = leetCode.deleteDuplicateFolder(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);


    paths =
    {
        {"a", "b"} ,{"c", "d"},{"c"},{"a"}
    };
    result = leetCode.deleteDuplicateFolder(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);

    paths =
    {
        {"a"} ,{"a","x"},{"a","x","y"},{"a","z"},{"b"},{"b","x"},{"b","x","y"},{"b","z"}
    };
    result = leetCode.deleteDuplicateFolder(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);

    paths =
    {
        {"a"} ,{"a","x"},{"a","x","y"},{"a","z"},{"b"},{"b","x"},{"b","x","y"},{"b","z"},{"b","w"}
    };
    result = leetCode.deleteDuplicateFolder(paths);
    Logger::WriteMessage(paths);
    Logger::WriteMessage(result);
}


void TestLeetCode1960(void)
{
    Logger::WriteMessage("Test Leet Code 1960");
    LeetCodeString leetCode;
    string s = "ababbb";
    long long result = leetCode.maxProduct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));

    s = "zaaaxbbby";
    result = leetCode.maxProduct(s);
    Logger::WriteMessage("s = " + s + "; result = " + to_string(result));
}

void TestLeetCode1957(void)
{
    Logger::WriteMessage("Test Leet Code 1957");
    LeetCodeString leetCode;
    string s = "leeetcode";
    string result = leetCode.makeFancyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "aaabaaaa";
    result = leetCode.makeFancyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);

    s = "aab";
    result = leetCode.makeFancyString(s);
    Logger::WriteMessage("s = " + s + "; result = " + result);
}

void TestLeetCode1961(void)
{
    LeetCodeString leetCode;
    string s = "iloveleetcode";
    vector<string> words = { "i", "love", "leetcode", "apples" };
    bool result = leetCode.isPrefixString(s, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));

    s = "iloveleetcode";
    words = { "apples","i","love","leetcode" };
    result = leetCode.isPrefixString(s, words);
    Logger::WriteMessage(words);
    Logger::WriteMessage("s = " + s + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1967(void)
{
    LeetCodeString leetCode;
    vector<string> patterns = { "a", "abc", "bc", "d" };
    string word = "abc";
    int result = leetCode.numOfStrings(patterns, word);
    Logger::WriteMessage(patterns);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    patterns = { "a","b","c" };
    word = "aaaaabbbbb";
    result = leetCode.numOfStrings(patterns, word);
    Logger::WriteMessage(patterns);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    patterns = { "a","a","a" };
    word = "ab";
    result = leetCode.numOfStrings(patterns, word);
    Logger::WriteMessage(patterns);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode1974(void)
{
    LeetCodeString leetCode;
    string word = "abc";
    int result = leetCode.minTimeToType(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "bza";
    result = leetCode.minTimeToType(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));

    word = "zjpc";
    result = leetCode.minTimeToType(word);
    Logger::WriteMessage("word = " + word + "; result = " + to_string(result));
}

void TestLeetCode1910(void)
{
    LeetCodeString leetCode;
    string s = "daabcbaabcbc";
    string part = "abc";
    string result = leetCode.removeOccurrences(s, part);
    Logger::WriteMessage("s = " + s + "; part = " + part + "; result = " + result);

    s = "axxxxyyyyb";
    part = "xy";
    result = leetCode.removeOccurrences(s, part);
    Logger::WriteMessage("s = " + s + "; part = " + part + "; result = " + result);
}

void TestLeetCodeString(void)
{
    TestLeetCode1910();
    TestLeetCode1974();
    TestLeetCode1967();
    TestLeetCode1961();
    TestLeetCode1957();
    TestLeetCode1960();
    TestLeetCode1948();
    TestLeetCode1935();
    TestLeetCode1945();
    TestLeetCode1903();
    TestLeetCode1897();
    TestLeetCode1880();
    TestLeetCode1876();
    TestLeetCode1869();
    TestLeetCode1859();
    TestLeetCode1896();
    TestLeetCode1844();
    TestLeetCode1839();
    TestLeetCode1794();
    TestLeetCode1832();
    TestLeetCode1816();
    TestLeetCode1813();
    TestLeetCode1807();
    TestLeetCode1805();
    TestLeetCode1796();
    TestLeetCode1790();
    TestLeetCode1784();
    TestLeetCode1781();
    TestLeetCode1750();
    TestLeetCode1763();
    TestLeetCode1768();
    TestLeetCode1754();
    TestLeetCode1737();
    TestLeetCode1736();
    TestLeetCode1717();
    TestLeetCode1704();
    TestLeetCode1702();
    TestLeetCode1698();
    TestLeetCode1694();
    TestLeetCode1684();
    TestLeetCode1678();
    TestLeetCode1668();
    TestLeetCode1657();
    TestLeetCode1647();
    TestLeetCode1638();
    TestLeetCode1625();
    TestLeetCode1624();
    TestLeetCode1616();
    TestLeetCode1614();
    TestLeetCode1598();
    TestLeetCode1592();
    TestLeetCode1578();
    TestLeetCode1576();
    TestLeetCode1573();
    TestLeetCode1556();
    TestLeetCode1554();
    TestLeetCode1544();
    TestLeetCode1542();
    TestLeetCode1541();
    TestLeetCode1540();
    TestLeetCode1525();
    TestLeetCode1528();
    TestLeetCode1531();
    TestLeetCode139();
    TestLeetCode1507();
    TestLeetCode678();
    TestLeetCode804();
    TestLeetCode824();
    TestLeetCode842();
    TestLeetCode848();
    TestLeetCode767();
    TestLeetCode937();
    TestLeetCode1021();
    TestLeetCode763();
    TestLeetCode9904();
    TestLeetCode899();
    TestLeetCode929();
    TestLeetCode893();
    TestLeetCode771();
    TestLeetCode806();
    TestLeetCode820();
    TestLeetCode819();
    TestLeetCode831();
    TestLeetCode761();
    TestLeetCode1163();
    TestLeetCode925();
    TestLeetCode833();
    TestLeetCode809();
    TestLeetCode791();
    TestLeetCode9900();
    TestLeetCode1002();
    TestLeetCode777();
    TestLeetCode859();
    TestLeetCode758();
    TestLeetCode844();
    TestLeetCode751();
    TestLeetCode736();
    TestLeetCode640();
    TestLeetCode648();
    TestLeetCode722();
    TestLeetCode720();
    TestLeetCode591();
    TestLeetCode609();
    TestLeetCode726();
    TestLeetCode567();
    TestLeetCode616();
    TestLeetCode557();
    TestLeetCode551();
    TestLeetCode527();
    TestLeetCode541();
    TestLeetCode392();
    TestLeetCode522();
    TestLeetCode521();
    TestLeetCode467();
    TestLeetCode524();
    TestLeetCode340();
    TestLeetCode159();
    TestLeetCode157();
    TestLeetCode158();
    TestLeetCode481();
    TestLeetCode408();
    TestLeetCode249();
    TestLeetCode246();
    TestLeetCode266();
    TestLeetCode306();
    TestLeetCode420();
    TestLeetCode936();
    TestLeetCode816();
    TestLeetCode418();
    TestLeetCode471();
    TestLeetCode1456();
    TestLeetCode1455();
    TestLeetCode1451();
    TestLeetCode1446();
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
