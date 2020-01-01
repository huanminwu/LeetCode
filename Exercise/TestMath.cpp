#include "..\LeetCode\LeetCode.h"
#include "..\LeetCode\LeetCodeMath.h"
#include "TestMath.h"
void TestLeetCode6(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 6");
    Logger::WriteMessage("ZipZap string");
    string message;
    int rows;
    message.assign("AB");
    rows = 1;
    string result = leetCode.convertZigZag(message, rows);
    Logger::WriteMessage(message.append("(").append(to_string(rows)).append(")->").append(result).c_str());
    message.assign("PAYPALISHIRING");
    rows = 3;
    result = leetCode.convertZigZag(message, rows);
    Logger::WriteMessage(message.append("(").append(to_string(rows)).append(")->").append(result).c_str());
}

void TestLeetCode7(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 7");
    int x = 123;
    int result = leetCode.reverse(x);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    x = -123;
    result = leetCode.reverse(x);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));

    x = 120;
    result = leetCode.reverse(x);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + to_string(result));
}

void TestLeetCode8(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 8");
    string str = "42";
    int result = leetCode.myAtoi(str);
    Logger::WriteMessage("str = " + str + "; result = " + to_string(result));

    str = "   -42";
    result = leetCode.myAtoi(str);
    Logger::WriteMessage("str = " + str + "; result = " + to_string(result));

    str = "4193 with words";
    result = leetCode.myAtoi(str);
    Logger::WriteMessage("str = " + str + "; result = " + to_string(result));
        
    str = "words and 987";
    result = leetCode.myAtoi(str);
    Logger::WriteMessage("str = " + str + "; result = " + to_string(result));

    str = "-91283472332";
    result = leetCode.myAtoi(str);
    Logger::WriteMessage("str = " + str + "; result = " + to_string(result));
}

void TestLeetCode9(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 9");
    int x = 1000021;
    bool result = leetCode.isPalindrome(x);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + (string)(result ? "true" : "false"));
    x = 1001;
    result = leetCode.isPalindrome(x);
    Logger::WriteMessage("x = " + to_string(x) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode553(void)
{
    LeetCodeMath leetCode;
    vector<int> nums = { 1000, 100, 10, 2 };
    string expression = leetCode.optimalDivision(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("expression = " + expression);
}

void TestLeetCode592(void)
{
    LeetCodeMath leetCode;
    string expression = "-1/2+1/2";
    string result = leetCode.fractionAddition(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "-1/2+1/2+1/3";
    result = leetCode.fractionAddition(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "1/3-1/2";
    result = leetCode.fractionAddition(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);

    expression = "5/3+1/3";
    result = leetCode.fractionAddition(expression);
    Logger::WriteMessage("expression = " + expression + "; result = " + result);
}

void TestLeetCode878(void)
{
    Logger::WriteMessage("Test Leet Code 878");
    LeetCodeMath leetCode;
    int N = 1;
    int A = 2;
    int B = 3;
    int result = leetCode.nthMagicalNumber(N, A, B);
    Logger::WriteMessage("N = " + to_string(N) + "; A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + to_string(result));

    N = 4;
    A = 2;
    B = 3;
    result = leetCode.nthMagicalNumber(N, A, B);
    Logger::WriteMessage("N = " + to_string(N) + "; A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + to_string(result));

    N = 5;
    A = 2;
    B = 4;
    result = leetCode.nthMagicalNumber(N, A, B);
    Logger::WriteMessage("N = " + to_string(N) + "; A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + to_string(result));

    N = 3;
    A = 6;
    B = 4;
    result = leetCode.nthMagicalNumber(N, A, B);
    Logger::WriteMessage("N = " + to_string(N) + "; A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + to_string(result));

    N = 1000000000;
    A = 40000;
    B = 40000;
    result = leetCode.nthMagicalNumber(N, A, B);
    Logger::WriteMessage("N = " + to_string(N) + "; A = " + to_string(A) + "; B = " + to_string(B) + "; result = " + to_string(result));
}

void TestLeetCode914(void)
{
    Logger::WriteMessage("Test Leet Code 914");
    LeetCodeMath leetCode;
    vector<int> deck = { 1, 2, 3, 4, 4, 3, 2, 1 };
    bool result = leetCode.hasGroupsSizeX(deck);
    Logger::WriteMessage(deck);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    deck = { 1,1,1,2,2,2,3,3 };
    result = leetCode.hasGroupsSizeX(deck);
    Logger::WriteMessage(deck);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    deck = { 1 };
    result = leetCode.hasGroupsSizeX(deck);
    Logger::WriteMessage(deck);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    deck = { 1,1 };
    result = leetCode.hasGroupsSizeX(deck);
    Logger::WriteMessage(deck);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    deck = { 1, 1, 2, 2, 2, 2 };
    result = leetCode.hasGroupsSizeX(deck);
    Logger::WriteMessage(deck);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1118(void)
{
    Logger::WriteMessage("Test Leet Code 1118");
    LeetCodeMath leetCodeMath;
    int Y = 1992;
    int M = 7;
    int result = leetCodeMath.numberOfDays(Y, M);
    Logger::WriteMessage("Y = " + to_string(Y) + "; M = " + to_string(M) + "; result = " + to_string(result));

    Y = 2000;
    M = 2;
    result = leetCodeMath.numberOfDays(Y, M);
    Logger::WriteMessage("Y = " + to_string(Y) + "; M = " + to_string(M) + "; result = " + to_string(result));

    Y = 1900;
    M = 2;
    result = leetCodeMath.numberOfDays(Y, M);
    Logger::WriteMessage("Y = " + to_string(Y) + "; M = " + to_string(M) + "; result = " + to_string(result));
}

void TestLeetCode1131(void)
{
    Logger::WriteMessage("Test Leet Code 1131");
    LeetCodeMath leetCodeMath;
    vector<int> arr1 = { 1, 2, 3, 4 };
    vector<int> arr2 = { -1, 4, 5, 6 };
    int result = leetCodeMath.maxAbsValExpr(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));

    arr1 = { 1, -2, -5, 0, 10 };
    arr2 = { 0, -2, -1, -7, -4 };
    result = leetCodeMath.maxAbsValExpr(arr1, arr2);
    Logger::WriteMessage(arr1);
    Logger::WriteMessage(arr2);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1134(void)
{
    Logger::WriteMessage("Test Leet Code 1134");
    LeetCodeMath leetCode;
    int N = 153;
    bool result = leetCode.isArmstrong(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 123;
    result = leetCode.isArmstrong(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1137(void)
{
    Logger::WriteMessage("Test Leet Code 1137");
    LeetCodeMath leetCode;
    int n = 4;
    int result = leetCode.tribonacci(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 25;
    result = leetCode.tribonacci(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1144(void)
{
    Logger::WriteMessage("Test Leet Code 1144");
    LeetCodeMath leetCode;
    vector<int> nums = { 2,7,10,9,8,9 };
    int result = leetCode.movesToMakeZigzag(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3 };
    result = leetCode.movesToMakeZigzag(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 9,6,1,6,2 };
    result = leetCode.movesToMakeZigzag(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,1,2 };
    result = leetCode.movesToMakeZigzag(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1154(void)
{
    Logger::WriteMessage("Test Leet Code 1154");
    LeetCodeMath leetCode;
    string date = "2019-01-09";
    int result = leetCode.dayOfYear(date);
    Logger::WriteMessage("date = " + date + "; result = " + to_string(result));

    date = "2019-02-10";
    result = leetCode.dayOfYear(date);
    Logger::WriteMessage("date = " + date + "; result = " + to_string(result));

    date = "2003-03-01";
    result = leetCode.dayOfYear(date);
    Logger::WriteMessage("date = " + date + "; result = " + to_string(result));

    date = "2004-03-01";
    result = leetCode.dayOfYear(date);
    Logger::WriteMessage("date = " + date + "; result = " + to_string(result));
}

void TestLeetCode1175(void)
{
    Logger::WriteMessage("Test Leet Code 1175");
    LeetCodeMath leetCode;
    int n = 5;
    int result = leetCode.numPrimeArrangements(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 10;
    result = leetCode.numPrimeArrangements(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 30;
    result = leetCode.numPrimeArrangements(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 100;
    result = leetCode.numPrimeArrangements(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1201(void)
{
    Logger::WriteMessage("Test Leet Code 1201");
    LeetCodeMath leetCode;
    int n = 3;
    int a = 2;
    int b = 3;
    int c = 5;
    int result = leetCode.nthUglyNumber(n, a, b, c);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) +
        "; b = " + to_string(b) + "; c = " + to_string(c) +
        "; result = " + to_string(result));

    n = 4;
    a = 2;
    b = 3;
    c = 4;
    result = leetCode.nthUglyNumber(n, a, b, c);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) +
        "; b = " + to_string(b) + "; c = " + to_string(c) +
        "; result = " + to_string(result));

    n = 5;
    a = 2;
    b = 11;
    c = 13;
    result = leetCode.nthUglyNumber(n, a, b, c);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) +
        "; b = " + to_string(b) + "; c = " + to_string(c) +
        "; result = " + to_string(result));

    n = 1000000000;
    a = 2;
    b = 217983653;
    c = 336916467;
    result = leetCode.nthUglyNumber(n, a, b, c);
    Logger::WriteMessage("n = " + to_string(n) + "; a = " + to_string(a) +
        "; b = " + to_string(b) + "; c = " + to_string(c) +
        "; result = " + to_string(result));
}

void TestLeetCode1217(void)
{
    Logger::WriteMessage("Test Leet Code 1217");
    LeetCodeMath leetCode;
    vector<int> chips = { 1,2,3 };
    int result = leetCode.minCostToMoveChips(chips);
    Logger::WriteMessage(chips);
    Logger::WriteMessage("result = " + to_string(result));

    chips = { 2,2,2,3,3 };
    result = leetCode.minCostToMoveChips(chips);
    Logger::WriteMessage(chips);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1227(void)
{
    Logger::WriteMessage("Test Leet Code 1227");
    LeetCodeMath leetCode;
    int n = 1;
    double result = leetCode.nthPersonGetsNthSeat(n);
    Logger::WriteMessage("n = " + to_string(n) + ";result = " + to_string(result));

    n = 2;
    result = leetCode.nthPersonGetsNthSeat(n);
    Logger::WriteMessage("n = " + to_string(n) + ";result = " + to_string(result));

    n = 100;
    result = leetCode.nthPersonGetsNthSeat(n);
    Logger::WriteMessage("n = " + to_string(n) + ";result = " + to_string(result));
}

void TestLeetCode1232(void)
{
    Logger::WriteMessage("Test Leet Code 1232");
    LeetCodeMath leetCode;
    vector<vector<int>> coordinates = { {1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7} };
    bool result = leetCode.checkStraightLine(coordinates);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    coordinates = { {1, 1}, { 2, 2 }, { 3, 4 }, { 4, 5 }, { 5, 6 }, { 7, 7 } };   
    result = leetCode.checkStraightLine(coordinates);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1250(void)
{
    Logger::WriteMessage("Test Leet Code 1250");
    LeetCodeMath leetCode;
    vector<int> nums = { 12,5,7,23 };
    bool result = leetCode.isGoodArray(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 29,6,10 };
    result = leetCode.isGoodArray(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    nums = { 3,6 };
    result = leetCode.isGoodArray(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1088(void)
{
    Logger::WriteMessage("Test Leet Code 1088");
    LeetCodeMath leetCode;
    int N = 1011;
    int result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 20;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 100;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1093(void)
{
    Logger::WriteMessage("Test Leet Code 1093");
    LeetCodeMath leetCode;
    vector<int> count =
    {
        0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0
    };
    vector<double> result = leetCode.sampleStats(count);
    Logger::WriteMessage(count);
    Logger::WriteMessage(result);

    count =
    {
        0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0
    };
    result = leetCode.sampleStats(count);
    Logger::WriteMessage(count);
    Logger::WriteMessage(result);
}

void TestLeetCode1103(void)
{
    Logger::WriteMessage("Test Leet Code 1103");
    LeetCodeMath leetCode;
    int candies = 40;
    int num_people = 5;
    vector<int> result = leetCode.distributeCandies(candies, num_people);
    Logger::WriteMessage("candies = " + to_string(candies) + "; num_people = " + to_string(num_people));
    Logger::WriteMessage(result);

    candies = 7;
    num_people = 4;
    result = leetCode.distributeCandies(candies, num_people);
    Logger::WriteMessage("candies = " + to_string(candies) + "; num_people = " + to_string(num_people));
    Logger::WriteMessage(result);

    candies = 10;
    num_people = 3;
    result = leetCode.distributeCandies(candies, num_people);
    Logger::WriteMessage("candies = " + to_string(candies) + "; num_people = " + to_string(num_people));
    Logger::WriteMessage(result);
}

void TestLeetCode1085(void)
{
    Logger::WriteMessage("Test Leet Code 1085");
    LeetCodeMath leetCode;
    vector<int> A = { 34, 23, 1, 24, 75, 33, 54, 8 };
    int result = leetCode.sumOfDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 99,77,33,66,55 };
    result = leetCode.sumOfDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 34, 23, 18, 24, 75, 33, 54, 8 };
    result = leetCode.sumOfDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1040(void)
{
    Logger::WriteMessage("Test Leet Code 1040");
    LeetCodeMath leetCode;
    vector<int> stones = { 7,4,9 };
    vector<int> result = leetCode.numMovesStonesII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage(result);

    stones = { 6,5,4,3,10 };
    result = leetCode.numMovesStonesII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage(result);

    stones = { 100,101,104,102,103 };
    result = leetCode.numMovesStonesII(stones);
    Logger::WriteMessage(stones);
    Logger::WriteMessage(result);
}

void TestLeetCode1058(void)
{
    Logger::WriteMessage("Test Leet Code 1058");
    LeetCodeMath leetCode;
    vector<string> prices = { "0.700","2.800","4.900" };
    int target = 8;
    string result = leetCode.minRoundError(prices, target);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    prices = { "1.500","2.500","3.500" };
    target = 10;
    result = leetCode.minRoundError(prices, target);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);

    prices = { "1.500","2.900","3.300" };
    target = 7;
    result = leetCode.minRoundError(prices, target);
    Logger::WriteMessage(prices);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + result);
}

void TestLeetCode1185(void)
{
    Logger::WriteMessage("Test Leet Code 1185");
    LeetCodeMath leetCode;
    int day = 31;
    int month = 8;
    int year = 2019;
    string result = leetCode.dayOfTheWeek(day, month, year);
    Logger::WriteMessage("day = " + to_string(day) + "; month = " + to_string(month) +
        "; year = " + to_string(year) + "; result = " + result);

    day = 18;
    month = 7;
    year = 1999;
    result = leetCode.dayOfTheWeek(day, month, year);
    Logger::WriteMessage("day = " + to_string(day) + "; month = " + to_string(month) +
        "; year = " + to_string(year) + "; result = " + result);

    day = 15;
    month = 8;
    year = 1993;
    result = leetCode.dayOfTheWeek(day, month, year);
    Logger::WriteMessage("day = " + to_string(day) + "; month = " + to_string(month) +
        "; year = " + to_string(year) + "; result = " + result);

    day = 29;
    month = 2;
    year = 2016;
    result = leetCode.dayOfTheWeek(day, month, year);
    Logger::WriteMessage("day = " + to_string(day) + "; month = " + to_string(month) +
        "; year = " + to_string(year) + "; result = " + result);
}

void TestLeetCode66(void)
{
    Logger::WriteMessage("Test Leet Code 66");
    LeetCodeMath leetCode;
    vector<int> digits =
    {
        4, 9, 9
    };
    Logger::WriteMessage(digits);
    vector<int> result = leetCode.plusOne(digits);
    Logger::WriteMessage("After Plus one");
    Logger::WriteMessage(result);
}

void TestLeetCode258(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 258");
    int num = 38;
    int result = leetCode.addDigits(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode335(void)
{
    Logger::WriteMessage("Test Leet Code 335");
    LeetCodeMath leetCode;
    vector<int> route = { 1, 1, 2, 1, 1 };
    Logger::WriteMessage(route);
    bool result = leetCode.isSelfCrossing(route);
    Logger::WriteMessage(result ? "self crossing" : "not self crossing");
}

void TestLeetCode319(void)
{
    Logger::WriteMessage("Test Leet Code 319");
    LeetCodeMath leetCode;
    int n = 99999;
    int result = leetCode.bulbSwitch(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode29(void)
{
    Logger::WriteMessage("Test Leet Code 29");
    int dividend = INT_MIN;
    int divisor = 1;
    LeetCodeMath leetCode;
    int result = leetCode.divide(dividend, divisor);
    Logger::WriteMessage("dividend = " + to_string(dividend) + "; divisor = " + to_string(divisor) + "; result =" + to_string(result));
}

void TestLeetCode149(void)
{
    Logger::WriteMessage("Test Leet Code 149");
    LeetCodeMath leetCode;
    vector<Point> points =
    {
        { 1, 1 },{ 2, 2 },{ 3, 3 },{ 1, 2 },{ 1, 3 },{ 1, 4 },{ 2, 2 },{ 2, 2 },{ 2, 2 }
    };
    int result = leetCode.maxPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode172(void)
{
    Logger::WriteMessage("Test Leet Code 172");
    LeetCodeMath leetCode;
    int n = 100;
    int result = leetCode.trailingZeroes(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode441(void)
{
    Logger::WriteMessage("Test Leet Code 441");
    LeetCodeMath leetCode;
    int n = 6;
    int row = leetCode.arrangeCoins(n);
    Logger::WriteMessage("n = " + to_string(n) + " row = " + to_string(row));

    n = 1804289383;
    row = leetCode.arrangeCoins(n);
    Logger::WriteMessage("n = " + to_string(n) + " row = " + to_string(row));
}

void TestLeetCode1037(void)
{
    Logger::WriteMessage("Test Leet Code 1037");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {1, 1},{2, 3},{3, 2} };
    bool result = leetCode.isBoomerang(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result " + (string)(result ? "true" : "false"));

    points = { {1, 1},{2, 2},{3, 3} };
    result = leetCode.isBoomerang(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result " + (string)(result ? "true" : "false"));
}

void TestLeetCode1033(void)
{
    Logger::WriteMessage("Test Leet Code 1033");
    LeetCodeMath leetCode;
    int a = 1;
    int b = 2;
    int c = 5;
    vector<int> result = leetCode.numMovesStones(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) + "; c = " + to_string(c));
    Logger::WriteMessage(result);

    a = 4;
    b = 3;
    c = 2;
    result = leetCode.numMovesStones(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) + "; c = " + to_string(c));
    Logger::WriteMessage(result);
}

void TestLeetCode1015(void)
{
    Logger::WriteMessage("Test Leet Code 1015");
    LeetCodeMath leetCode;
    int K = 1;
    int result = leetCode.smallestRepunitDivByK(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    K = 2;
    result = leetCode.smallestRepunitDivByK(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    K = 3;
    result = leetCode.smallestRepunitDivByK(K);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));
}

void TestLeetCode1256(void)
{
    Logger::WriteMessage("Test Leet Code 1256");
    LeetCodeMath leetCode;
    int num = 23;
    string result = leetCode.encode(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + result);

    num = 107;
    result = leetCode.encode(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + result);
}

void TestLeetCode1262(void)
{
    Logger::WriteMessage("Test Leet Code 1262");
    LeetCodeMath leetCode;
    vector<int> nums = { 3, 6, 5, 1, 8 };
    int result = leetCode.maxSumDivThree(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4 };
    result = leetCode.maxSumDivThree(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,2,3,4,4 };
    result = leetCode.maxSumDivThree(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode292(void)
{
    Logger::WriteMessage("Test Leet Code 292");
    LeetCodeMath leetCode;
    int n = 4;
    bool result = leetCode.canWinNim(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode273(void)
{
    Logger::WriteMessage("Test Leet Code 273");
    LeetCodeMath leetCode;
    int num;
    string result;
    num = 1234567891;
    result = leetCode.numberToWords(num);
    Logger::WriteMessage("Number = " + to_string(num));
    Logger::WriteMessage("English = " + result);

    num = 20;
    result = leetCode.numberToWords(num);
    Logger::WriteMessage("Number = " + to_string(num));
    Logger::WriteMessage("English = " + result);

    num = 100;
    result = leetCode.numberToWords(num);
    Logger::WriteMessage("Number = " + to_string(num));
    Logger::WriteMessage("English = " + result);

    num = 11;
    result = leetCode.numberToWords(num);
    Logger::WriteMessage("Number = " + to_string(num));
    Logger::WriteMessage("English = " + result);

    num = 0;
    result = leetCode.numberToWords(num);
    Logger::WriteMessage("Number = " + to_string(num));
    Logger::WriteMessage("English = " + result);
}

void TestLeetCode50(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 50");
    string message;
    double x = 1.00000;
    int n = INT_MIN;
    double result = leetCode.myPow(x, n);
    Logger::WriteMessage("x = " + to_string(x) + "; n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode223(void)
{
    Logger::WriteMessage("Test Leet Code 223");
    LeetCodeMath leetCode;
    int A, B, C, D, E, F, G, H, area;

    A = -2; B = -2; C = 2; D = 2; E = -1; F = -1; G = 1; H = 1;
    area = leetCode.computeArea(A, B, C, D, E, F, G, H);
    Logger::WriteMessage("A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D));
    Logger::WriteMessage("E = " + to_string(E) + " F = " + to_string(F) + " G = " + to_string(G) + " H = " + to_string(H));
    Logger::WriteMessage("Area = " + to_string(area));

    A = -3; B = 0; C = 3; D = 4; E = 0; F = -1; G = 9; H = 2;
    area = leetCode.computeArea(A, B, C, D, E, F, G, H);
    Logger::WriteMessage("A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D));
    Logger::WriteMessage("E = " + to_string(E) + " F = " + to_string(F) + " G = " + to_string(G) + " H = " + to_string(H));
    Logger::WriteMessage("Area = " + to_string(area));

    A = -2; B = -2; C = 2; D = 2; E = -3; F = -3; G = 3; H = -1;
    area = leetCode.computeArea(A, B, C, D, E, F, G, H);
    Logger::WriteMessage("A = " + to_string(A) + " B = " + to_string(B) + " C = " + to_string(C) + " D = " + to_string(D));
    Logger::WriteMessage("E = " + to_string(E) + " F = " + to_string(F) + " G = " + to_string(G) + " H = " + to_string(H));
    Logger::WriteMessage("Area = " + to_string(area));
}

void TestLeetCode43(void)
{
    Logger::WriteMessage("Test Leet Code 43");
    LeetCodeMath leetCode;
    string num1, num2, product;
    num1 = "2";
    num2 = "3";
    product = leetCode.multiply(num1, num2);
    Logger::WriteMessage("The product of " + num1 + " and " + num2 + " = " + product);

    num1 = "123";
    num2 = "456";
    product = leetCode.multiply(num1, num2);
    Logger::WriteMessage("The product of " + num1 + " and " + num2 + " = " + product);

    num1 = "456";
    num2 = "789";
    product = leetCode.multiply(num1, num2);
    Logger::WriteMessage("The product of " + num1 + " and " + num2 + " = " + product);

    num1 = "456";
    num2 = "0";
    product = leetCode.multiply(num1, num2);
    Logger::WriteMessage("The product of " + num1 + " and " + num2 + " = " + product);
}

void TestLeetCode365(void)
{
    Logger::WriteMessage("Test Leet Code 365");
    LeetCodeMath leetCode;
    int  x = 3, y = 5, z = 4;
    bool result = leetCode.canMeasureWater(x, y, z);
    Logger::WriteMessage("x=" + to_string(x) + " y=" + to_string(y) + " z=" + to_string(z) +
        ((result) ? " can " : "cannot ") + "measure");
    x = 2, y = 6, z = 5;
    result = leetCode.canMeasureWater(x, y, z);
    Logger::WriteMessage("x=" + to_string(x) + " y=" + to_string(y) + " z=" + to_string(z) +
        ((result) ? " can " : " cannot ") + "measure");
}

void TestLeetCode447(void)
{
    Logger::WriteMessage("Test Leet Code 447");
    LeetCodeMath leetCode;
    vector<pair<int, int>> points = { {0,0},{1,0},{2,0} };
    int sum = leetCode.numberOfBoomerangs(points);
    Logger::WriteMessage("Number of boomerangs are:" + to_string(sum));
}

void TestLeetCode372(void)
{
    Logger::WriteMessage("Test Leet Code 372");
    LeetCodeMath leetCode;
    int a = 2;
    vector<int> nums = { 1, 0 };
    Logger::WriteMessage(nums);
    int super_pow = leetCode.superPow(a, nums);
    Logger::WriteMessage("Super Pow = " + to_string(super_pow));
}

void TestLeetCode356(void)
{
    Logger::WriteMessage("Test Leet Code 356");
    LeetCodeMath leetCode;
    vector<pair<int, int>> points = { { 1, 1 }, { -1, 1 } };
    Logger::WriteMessage(points);
    bool result = leetCode.isReflected(points);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "reflected.");

    points = { { 1, 1 }, { -1, -1 } };
    Logger::WriteMessage(points);
    result = leetCode.isReflected(points);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "reflected.");

    points = { { 0, 0 }, { 1, 0 } };
    Logger::WriteMessage(points);
    result = leetCode.isReflected(points);
    Logger::WriteMessage("It" + (string)(result ? " is " : " is not ") + "reflected.");
}


void TestLeetCode469(void)
{
    Logger::WriteMessage("Test Leet Code 469");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { { 0, 0 },{ 0, 1 },{ 1, 1 },{ 1, 0 } };
    Logger::WriteMessage(points);
    bool isConvex = leetCode.isConvex(points);
    Logger::WriteMessage("It " + (string)(isConvex ? "is" : "is not") + " convex polygon");

    points = { { 0, 0 },{ 0, 10 },{ 10, 10 },{ 10, 0 },{5, 5} };
    Logger::WriteMessage(points);
    isConvex = leetCode.isConvex(points);
    Logger::WriteMessage("It " + (string)(isConvex ? "is" : "is not") + " convex polygon");
}

void TestLeetCode483(void)
{
    Logger::WriteMessage("Test Leet Code 483");
    LeetCodeMath leetCode;
    string s = "4681";
    string base = leetCode.smallestGoodBase(s);
    Logger::WriteMessage("s = " + s + "; base = " + base);

    s = "13";
    base = leetCode.smallestGoodBase(s);
    Logger::WriteMessage("s = " + s + "; base = " + base);

    s = "1000000000000000000";
    base = leetCode.smallestGoodBase(s);
    Logger::WriteMessage("s = " + s + "; base = " + base);
}

void TestLeetCode360(void)
{
    Logger::WriteMessage("Test Leet Code 360");
    LeetCodeMath leetCode;
    vector<int> nums = { -4, -2, 2, 4 };
    int a = 1, b = 3, c = 5;
    vector<int> result = leetCode.sortTransformedArray(nums, a, b, c);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) + "; c= " + to_string(c));
    Logger::WriteMessage(result);

    nums = { -4, -2, 2, 4 };
    a = -1, b = 3, c = 5;
    result = leetCode.sortTransformedArray(nums, a, b, c);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) + "; c= " + to_string(c));
    Logger::WriteMessage(result);
}

void TestLeetCode343(void)
{
    Logger::WriteMessage("Test Leet Code 343");
    LeetCodeMath leetCode;
    int n = 10;
    int product = leetCode.integerBreak(n);
    Logger::WriteMessage("integer break for " + to_string(n) + "; product = " + to_string(product));
}

void TestLeetCode38(void)
{
    Logger::WriteMessage("Test Leet Code 38");
    LeetCodeMath leetCode;
    int n = 12;
    string result = leetCode.countAndSay(n);
    Logger::WriteMessage("The " + to_string(n) + "th sentence is " + result);
}

void TestLeetCode391(void)
{
    Logger::WriteMessage("Test Leet Code 391");
    LeetCodeMath leetCode;
    vector<vector<int>> rectangles = { { 1, 1, 3, 3 },{ 3, 1, 4, 2 },{ 3, 2, 4, 4 },{ 1, 3, 2, 4 },{ 2, 3, 3, 4 } };
    Logger::WriteMessage(rectangles);
    bool result = leetCode.isRectangleCover(rectangles);
    Logger::WriteMessage("It " + (string)(result ? "is" : "is not") + " a rectangle cover.");

    rectangles = { { 1, 1, 2, 3 },{ 1, 3, 2, 4 },{ 3, 1, 4, 2 },{ 3, 2, 4, 4 } };
    Logger::WriteMessage(rectangles);
    result = leetCode.isRectangleCover(rectangles);
    Logger::WriteMessage("It " + (string)(result ? "is" : "is not") + " a rectangle cover.");

    rectangles = { { 1, 1, 3, 3 },{ 3, 1, 4, 2 },{ 1, 3, 2, 4 },{ 3, 2, 4, 4 } };
    Logger::WriteMessage(rectangles);
    result = leetCode.isRectangleCover(rectangles);
    Logger::WriteMessage("It " + (string)(result ? "is" : "is not") + " a rectangle cover.");

    rectangles = { { 1, 1, 3, 3 },{ 3, 1, 4, 2 },{ 1, 3, 2, 4 },{ 2, 2, 4, 4 } };
    Logger::WriteMessage(rectangles);
    result = leetCode.isRectangleCover(rectangles);
    Logger::WriteMessage("It " + (string)(result ? "is" : "is not") + " a rectangle cover.");
}

void TestLeetCode492(void)
{
    Logger::WriteMessage("Test Leet Code 492");
    LeetCodeMath leetCode;
    int area = 6;
    vector<int> result = leetCode.constructRectangle(area);
    Logger::WriteMessage("area = " + to_string(area));
    Logger::WriteMessage(result);
}

void TestLeetCode504(void)
{
    Logger::WriteMessage("Test Leet Code 504");
    LeetCodeMath leetCode;
    int num = 100;
    string base7 = leetCode.convertToBase7(num);
    Logger::WriteMessage("num = " + to_string(num) + "; base7 = " + base7);

    num = -7;
    base7 = leetCode.convertToBase7(num);
    Logger::WriteMessage("num = " + to_string(num) + "; base7 = " + base7);
}

void TestLeetCode976(void)
{
    Logger::WriteMessage("Test Leet Code 976");
    LeetCodeMath leetCode;
    vector<int> A = { 2,1,2 };
    int result = leetCode.largestPerimeter(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,2,1 };
    result = leetCode.largestPerimeter(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,2,3,4 };
    result = leetCode.largestPerimeter(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3,6,2,3 };
    result = leetCode.largestPerimeter(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode991(void)
{
    Logger::WriteMessage("Test Leet Code 991");
    LeetCodeMath leetCode;
    int X = 2, Y = 3;
    int result = leetCode.brokenCalc(X, Y);
    Logger::WriteMessage("X = " + to_string(X) + "; Y = " + to_string(Y) + "; result = " + to_string(result));

    X = 5;
    Y = 8;
    result = leetCode.brokenCalc(X, Y);
    Logger::WriteMessage("X = " + to_string(X) + "; Y = " + to_string(Y) + "; result = " + to_string(result));

    X = 3;
    Y = 10;
    result = leetCode.brokenCalc(X, Y);
    Logger::WriteMessage("X = " + to_string(X) + "; Y = " + to_string(Y) + "; result = " + to_string(result));

    X = 1024;
    Y = 1;
    result = leetCode.brokenCalc(X, Y);
    Logger::WriteMessage("X = " + to_string(X) + "; Y = " + to_string(Y) + "; result = " + to_string(result));

    X = 1;
    Y = 1000000000;
    result = leetCode.brokenCalc(X, Y);
    Logger::WriteMessage("X = " + to_string(X) + "; Y = " + to_string(Y) + "; result = " + to_string(result));
}

void TestLeetCode509(void)
{
    Logger::WriteMessage("Test Leet Code 509");
    LeetCodeMath leetCode;
    int N = 20;
    int result = leetCode.fib(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 2;
    result = leetCode.fib(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 3;
    result = leetCode.fib(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 4;
    result = leetCode.fib(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode949(void)
{
    Logger::WriteMessage("Test Leet Code 949");
    LeetCodeMath leetCode;
    vector<int> A = { 1,2,3,4 };
    string result = leetCode.largestTimeFromDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + result);

    A = { 5,5,5,5 };
    result = leetCode.largestTimeFromDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + result);

    A = { 1,9,9,2 };
    result = leetCode.largestTimeFromDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + result);

    A = { 0,0,0,0 };
    result = leetCode.largestTimeFromDigits(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode963(void)
{
    Logger::WriteMessage("Test Leet Code 963");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {1, 2},{2, 1},{1, 0},{0, 1} };
    double result = leetCode.minAreaFreeRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { { 0,1 },{ 2,1 },{ 1,1 },{ 1,0 },{ 2,0 } };
    result = leetCode.minAreaFreeRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { { 0,3 },{ 1,2 },{ 3,1 },{ 1,3 },{ 2,1 } };
    result = leetCode.minAreaFreeRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { { 3,1 },{ 1,1 },{ 0,1 },{ 2,1 },{ 3,3 },{ 3,2 },{ 0,2 },{ 2,3 } };
    result = leetCode.minAreaFreeRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { { 3, 4 },{ 1, 1 },{ 2, 1 },{ 3, 1 },{ 1, 3 },{ 2, 3 },{ 0, 2 },{ 2, 0 },{ 3, 3 },{ 0, 3 },{ 4, 4 } };
    result = leetCode.minAreaFreeRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode906(void)
{
    Logger::WriteMessage("Test Leet Code 906");
    LeetCodeMath leetCode;
    string L = "4";
    string R = "1000";
    int result = leetCode.superpalindromesInRange(L, R);
    Logger::WriteMessage("L = " + L + "; R = " + R + "; result = " + to_string(result));
}

void TestLeetCode858(void)
{
    Logger::WriteMessage("Test Leet Code 858");
    LeetCodeMath leetCode;
    int p = 2;
    int q = 1;
    int result = leetCode.mirrorReflection(p, q);
    Logger::WriteMessage("p = " + to_string(p) + "; q = " + to_string(q) + "; result = " + to_string(result));
}

void TestLeetCode866(void)
{
    Logger::WriteMessage("Test Leet Code 866");
    LeetCodeMath leetCode;
    int N = 102;
    int result = leetCode.primePalindrome(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 2;
    result = leetCode.primePalindrome(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 6;
    result = leetCode.primePalindrome(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 8;
    result = leetCode.primePalindrome(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 13;
    result = leetCode.primePalindrome(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 798;
    result = leetCode.primePalindrome(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode869(void)
{
    Logger::WriteMessage("Test Leet Code 869");
    LeetCodeMath leetCode;
    int N = 1;
    bool result = leetCode.reorderedPowerOf2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 10;
    result = leetCode.reorderedPowerOf2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 24;
    result = leetCode.reorderedPowerOf2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 46;
    result = leetCode.reorderedPowerOf2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 61;
    result = leetCode.reorderedPowerOf2(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

}

void TestLeetCode812(void)
{
    Logger::WriteMessage("Test Leet Code 812");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {0, 0},{0, 1},{1, 0},{0, 2},{2, 0} };
    double result = leetCode.largestTriangleArea(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode593(void)
{
    LeetCodeMath leetCode;
    vector<int> p1 = { 0, 0 }, p2 = { 1, 1 }, p3 = { 1, 0 }, p4 = { 0, 1 };
    bool result = leetCode.validSquare(p1, p2, p3, p4);
    Logger::WriteMessage(p1);
    Logger::WriteMessage(p2);
    Logger::WriteMessage(p3);
    Logger::WriteMessage(p4);
    Logger::WriteMessage("Is Valid Square = " + (string)(result ? "true" : "false"));

    p1 = { 1, 0 }, p2 = { 0, 1 }, p3 = { -1, 0 }, p4 = { 0, -1 };
    result = leetCode.validSquare(p1, p2, p3, p4);
    Logger::WriteMessage(p1);
    Logger::WriteMessage(p2);
    Logger::WriteMessage(p3);
    Logger::WriteMessage(p4);
    Logger::WriteMessage("Is Valid Square = " + (string)(result ? "true" : "false"));
}

void TestLeetCode587(void)
{
    LeetCodeMath leetCode;
    vector<Point> trees = { { 1, 1 },{ 2, 2 },{ 2, 0 },{ 2, 4 },{ 3, 3 },{ 4, 2 } };
    vector<Point> result = leetCode.outerTrees(trees);
    Logger::WriteMessage(trees);
    Logger::WriteMessage(result);
}


void TestLeetCode611(void)
{
    LeetCodeMath leetCode;
    vector<int> nums = { 2,2,3,4 };
    int result = leetCode.triangleNumber(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1266(void)
{
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {1, 1},{3, 4},{-1, 0} };
    int result = leetCode.minTimeToVisitAllPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { {3, 2},{-2, 2} };
    result = leetCode.minTimeToVisitAllPoints(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode507(void)
{
    LeetCodeMath leetCode;
    int num = 28;
    bool result = leetCode.checkPerfectNumber(num);
    Logger::WriteMessage("num = " + to_string(num) + (string)(result ? " is" : " is not ") + "a perfect number");
}

void TestLeetCode537(void)
{
    LeetCodeMath leetCode;
    string a = "78+-76i";
    string b = "-86+72i";
    string result = leetCode.complexNumberMultiply(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + result);

    a = "1 + 1i";
    b = "1+1i";
    result = leetCode.complexNumberMultiply(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + result);

    a = "1+-1i";
    b = "1+-1i";
    result = leetCode.complexNumberMultiply(a, b);
    Logger::WriteMessage("a = " + a + "; b = " + b + "; result = " + result);
}

void TestLeetCode564(void)
{
    LeetCodeMath leetCode;
    string n = "123";
    string result = leetCode.nearestPalindromic(n);
    Logger::WriteMessage("n = " + n + "; result = " + result);
    n = "721";
    result = leetCode.nearestPalindromic(n);
    Logger::WriteMessage("n = " + n + "; result = " + result);
    n = "10";
    result = leetCode.nearestPalindromic(n);
    Logger::WriteMessage("n = " + n + "; result = " + result);
    n = "100";
    result = leetCode.nearestPalindromic(n);
    Logger::WriteMessage("n = " + n + "; result = " + result);
    n = "1";
    result = leetCode.nearestPalindromic(n);
    Logger::WriteMessage("n = " + n + "; result = " + result);
    n = "2";
    result = leetCode.nearestPalindromic(n);
    Logger::WriteMessage("n = " + n + "; result = " + result);
}

void TestLeetCode455(void)
{
    Logger::WriteMessage("Test Leet Code 455");
    LeetCodeMath leetCode;
    vector<int> g = { 1,2,3 };
    vector<int> s = { 1,1 };
    int sum = leetCode.findContentChildren(g, s);
    Logger::WriteMessage(g);
    Logger::WriteMessage(s);
    Logger::WriteMessage("The maxmimum content children are " + to_string(sum));

    g = { 1, 2 };
    s = { 1, 2, 3 };
    sum = leetCode.findContentChildren(g, s);
    Logger::WriteMessage(g);
    Logger::WriteMessage(s);
    Logger::WriteMessage("The maxmimum content children are " + to_string(sum));
}

void TestLeetCode672(void)
{
    LeetCodeMath leetCode;
    int n = 3;
    int m = 2;
    int result = leetCode.flipLights(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 2;
    m = 1;
    result = leetCode.flipLights(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 3;
    m = 1;
    result = leetCode.flipLights(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 4;
    m = 4;
    result = leetCode.flipLights(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));

    n = 1;
    m = 1;
    result = leetCode.flipLights(n, m);
    Logger::WriteMessage("n = " + to_string(n) + "; m = " + to_string(m) + "; result = " + to_string(result));
}

void TestLeetCode780(void)
{
    Logger::WriteMessage("Test Leet Code 780");
    LeetCodeMath leetCode;
    int sx = 1;
    int sy = 1;
    int tx = 3;
    int ty = 5;
    bool result = leetCode.reachingPoints(sx, sy, tx, ty);
    Logger::WriteMessage("sx =" + to_string(sx) + ", sy = " + to_string(sy) + "; tx = " + to_string(tx) + ", ty = " + to_string(ty));
    Logger::WriteMessage("result =" + (string)(result ? "true" : "false"));
}

void TestLeetCode396(void)
{
    Logger::WriteMessage("Test Leet Code 396");
    LeetCodeMath leetCode;
    vector<int> nums = { 4, 3, 2, 6 };
    Logger::WriteMessage(nums);
    int result = leetCode.maxRotateFunction(nums);
    Logger::WriteMessage("Maximum rotate function = " + to_string(result));
}

void TestLeetCode1271(void)
{
    Logger::WriteMessage("Test Leet Code 1271");
    LeetCodeMath leetCode;
    string num = "257";
    string result = leetCode.toHexspeak(num);
    Logger::WriteMessage("num = " + num + "; result = " + result);

    num = "3";
    result = leetCode.toHexspeak(num);
    Logger::WriteMessage("num = " + num + "; result = " + result);

    num = "160";
    result = leetCode.toHexspeak(num);
    Logger::WriteMessage("num = " + num + "; result = " + result);
}

void TestLeetCode1276(void)
{
    Logger::WriteMessage("Test Leet Code 1276");
    LeetCodeMath leetCode;
    int tomatoSlices = 16;
    int cheeseSlices = 7;
    vector<int> result = leetCode.numOfBurgers(tomatoSlices, cheeseSlices);
    Logger::WriteMessage("tomatoSlices = " + to_string(tomatoSlices) + "; cheeseSlices = " + to_string(cheeseSlices));
    Logger::WriteMessage(result);

    tomatoSlices = 17;
    cheeseSlices = 4;
    result = leetCode.numOfBurgers(tomatoSlices, cheeseSlices);
    Logger::WriteMessage("tomatoSlices = " + to_string(tomatoSlices) + "; cheeseSlices = " + to_string(cheeseSlices));
    Logger::WriteMessage(result);

    tomatoSlices = 4;
    cheeseSlices = 17;
    result = leetCode.numOfBurgers(tomatoSlices, cheeseSlices);
    Logger::WriteMessage("tomatoSlices = " + to_string(tomatoSlices) + "; cheeseSlices = " + to_string(cheeseSlices));
    Logger::WriteMessage(result);

    tomatoSlices = 0;
    cheeseSlices = 0;
    result = leetCode.numOfBurgers(tomatoSlices, cheeseSlices);
    Logger::WriteMessage("tomatoSlices = " + to_string(tomatoSlices) + "; cheeseSlices = " + to_string(cheeseSlices));
    Logger::WriteMessage(result);
  
    tomatoSlices = 2;
    cheeseSlices = 1;
    result = leetCode.numOfBurgers(tomatoSlices, cheeseSlices);
    Logger::WriteMessage("tomatoSlices = " + to_string(tomatoSlices) + "; cheeseSlices = " + to_string(cheeseSlices));
    Logger::WriteMessage(result);
}

void TestLeetCode412(void)
{
    Logger::WriteMessage("Test Leet Code 412");
    int n = 15;

    LeetCodeMath leetCode;
    vector<string> result = leetCode.fizzBuzz(n);
    Logger::WriteMessage(result);
}

void TestLeetCode453(void)
{
    Logger::WriteMessage("Test Leet Code 453");
    LeetCodeMath leetCode;
    vector<int> nums = { 1,2,3 };
    Logger::WriteMessage(nums);
    int result = leetCode.minMoves(nums);
    Logger::WriteMessage("The minimum move is " + to_string(result));
}

void TestLeetCode462(void)
{
    Logger::WriteMessage("Test Leet Code 462");
    LeetCodeMath leetCode;
    vector<int> nums = { 1, 2, 3, 100 };
    Logger::WriteMessage(nums);
    int min_move = leetCode.minMoves2(nums);
    Logger::WriteMessage("Minimum Move = " + to_string(min_move));
}

void TestLeetCode326(void)
{
    Logger::WriteMessage("Test Leet Code 326");
    LeetCodeMath leetCode;
    int n = 81;
    Logger::WriteMessage("N = " + to_string(n));
    string message;
    message.assign("N is ");
    message.append(leetCode.isPowerOfThree(n) ? "" : " not ").append("Power of Three");
    Logger::WriteMessage(message);

    n = 0;
    Logger::WriteMessage("N = " + to_string(n));
    message.assign("N is ");
    message.append(leetCode.isPowerOfThree(n) ? "" : " not ").append("Power of Three");
    Logger::WriteMessage(message);
}

void TestLeetCode625(void)
{
    LeetCodeMath leetCode;
    int a = 48;
    int result = leetCode.smallestFactorization(a);
    Logger::WriteMessage("a = " + to_string(a) + "; result = " + to_string(result));

    a = 15;
    result = leetCode.smallestFactorization(a);
    Logger::WriteMessage("a = " + to_string(a) + "; result = " + to_string(result));
}

void TestLeetCode633(void)
{
    LeetCodeMath leetCode;
    int c = 5;
    bool result = leetCode.judgeSquareSum(c);
    Logger::WriteMessage("c = " + to_string(c) + "; isSquareSum = " + (string)(result ? "true" : "false"));
    c = 3;
    result = leetCode.judgeSquareSum(c);
    Logger::WriteMessage("c = " + to_string(c) + "; isSquareSum = " + (string)(result ? "true" : "false"));
}

void TestLeetCode479(void)
{
    // Test Leet Code #479
    LeetCodeMath leetCode;
    int n = 2;
    int result = leetCode.largestPalindrome(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
    n = 8;
    result = leetCode.largestPalindrome(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode657(void)
{
    LeetCodeMath leetCode;
    string moves = "UD";
    bool result = leetCode.judgeCircle(moves);
    Logger::WriteMessage("moves = " + moves + ";" + (string)(result ? "circle" : "not circle"));

    moves = "LL";
    result = leetCode.judgeCircle(moves);
    Logger::WriteMessage("moves = " + moves + ";" + (string)(result ? "circle" : "not circle"));
}

void TestLeetCode754(void)
{
    Logger::WriteMessage("Test Leet Code 754");
    LeetCodeMath leetCode;
    int target = 3;
    int result = leetCode.reachNumber(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = 2;
    result = leetCode.reachNumber(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));

    target = -1;
    result = leetCode.reachNumber(target);
    Logger::WriteMessage("target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode781(void)
{
    Logger::WriteMessage("Test Leet Code 781");
    LeetCodeMath leetCode;
    vector<int> answers = { 1, 1, 2 };
    int result = leetCode.numRabbits(answers);
    Logger::WriteMessage(answers);
    Logger::WriteMessage("result = " + to_string(result));

    answers = { 10, 10, 10 };
    result = leetCode.numRabbits(answers);
    Logger::WriteMessage(answers);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode794(void)
{
    Logger::WriteMessage("Test Leet Code 794");
    LeetCodeMath leetCode;
    vector<string> board = { "O  ", "   ", "   " };
    bool result = leetCode.validTicTacToe(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    board = { "XOX", " X ", "   " };
    result = leetCode.validTicTacToe(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    board = { "XXX", "   ", "OOO" };
    result = leetCode.validTicTacToe(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    board = { "XOX", "O O", "XOX" };
    result = leetCode.validTicTacToe(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    board = { "XXO","XOX","OXO" };
    result = leetCode.validTicTacToe(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1281(void)
{
    Logger::WriteMessage("Test Leet Code 1281");
    LeetCodeMath leetCode;
    int n = 234;
    int result = leetCode.subtractProductAndSum(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 4421;
    result = leetCode.subtractProductAndSum(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1291(void)
{
    Logger::WriteMessage("Test Leet Code 1291");
    LeetCodeMath leetCode;
    int low = 100;
    int high = 300;
    vector<int> result = leetCode.sequentialDigits(low, high);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high));
    Logger::WriteMessage(result);
    
    low = 1000;
    high = 13000;
    result = leetCode.sequentialDigits(low, high);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high));
    Logger::WriteMessage(result);
}

void TestLeetCode1295(void)
{
    Logger::WriteMessage("Test Leet Code 1295");
    LeetCodeMath leetCode;
    vector<int> nums = { 12,345,2,6,7896 };
    int result = leetCode.findNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 555,901,482,1771 };
    result = leetCode.findNumbers(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode800(void)
{
    Logger::WriteMessage("Test Leet Code 800");
    LeetCodeMath leetCode;
    string color = "#09f166";
    string result = leetCode.similarRGB(color);
    Logger::WriteMessage("color = " + color + "; result = " + result);
}

void TestLeetCode810(void)
{
    Logger::WriteMessage("Test Leet Code 810");
    LeetCodeMath leetCode;
    vector<int> nums = { 1, 2, 3 };
    bool result = leetCode.xorGame(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1304(void)
{
    Logger::WriteMessage("Test Leet Code 1304");
    LeetCodeMath leetCode;
    int n = 5;
    vector<int> result = leetCode.sumZero(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 3;
    result = leetCode.sumZero(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 1;
    result = leetCode.sumZero(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCodeMath(void)
{
    TestLeetCode1304();
    TestLeetCode800();
    TestLeetCode810();
    TestLeetCode1295();
    TestLeetCode1291();
    TestLeetCode1281();
    TestLeetCode794();
    TestLeetCode781();
    TestLeetCode754();
    TestLeetCode657();
    TestLeetCode479();
    TestLeetCode633();
    TestLeetCode625();
    TestLeetCode326();
    TestLeetCode412();
    TestLeetCode462();
    TestLeetCode1276();
    TestLeetCode1271();
    TestLeetCode396();
    TestLeetCode780();
    TestLeetCode672();
    TestLeetCode455();
    TestLeetCode564();
    TestLeetCode537();
    TestLeetCode507();
    TestLeetCode1266();
    TestLeetCode611();
    TestLeetCode587();
    TestLeetCode593();
    TestLeetCode812();
    TestLeetCode869();
    TestLeetCode866();
    TestLeetCode963();
    TestLeetCode906();
    TestLeetCode949();
    TestLeetCode509();
    TestLeetCode991();
    TestLeetCode504();
    TestLeetCode492();
    TestLeetCode38();
    TestLeetCode343();
    TestLeetCode483();
    TestLeetCode469();
    TestLeetCode372();
    TestLeetCode447();
    TestLeetCode365();
    TestLeetCode43();
    TestLeetCode223();
    TestLeetCode292();
    TestLeetCode1262();
    TestLeetCode1256();
    TestLeetCode1033();
    TestLeetCode1037();
    TestLeetCode441();
    TestLeetCode172();
    TestLeetCode29();
    TestLeetCode319();
    TestLeetCode335();
    TestLeetCode66();
    TestLeetCode1040();
    TestLeetCode1058();
    TestLeetCode1085();
    TestLeetCode1093();
    TestLeetCode1088();
    TestLeetCode1185();
    TestLeetCode1250();
    TestLeetCode1232();
    TestLeetCode1227();
    TestLeetCode1217();
    TestLeetCode1201();
    TestLeetCode9();
    TestLeetCode8();
    TestLeetCode7();
    TestLeetCode6();
    TestLeetCode553();
    TestLeetCode592();
    TestLeetCode878();
    TestLeetCode914();
    TestLeetCode1118();
    TestLeetCode1131();
    TestLeetCode1134();
    TestLeetCode1137();
    TestLeetCode1144();
    TestLeetCode1154();
    TestLeetCode1175();
    TestLeetCode258();
}