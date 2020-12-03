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

void TestLeetCode1317(void)
{
    Logger::WriteMessage("Test Leet Code 1317");
    LeetCodeMath leetCode;
    int n = 2;
    vector<int> result = leetCode.getNoZeroIntegers(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 11;
    result = leetCode.getNoZeroIntegers(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 10000;
    result = leetCode.getNoZeroIntegers(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 69;
    result = leetCode.getNoZeroIntegers(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 1010;
    result = leetCode.getNoZeroIntegers(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1318(void)
{
    Logger::WriteMessage("Test Leet Code 1318");
    LeetCodeMath leetCode;
    int a = 2;
    int b = 6;
    int c = 5;
    int result = leetCode.minFlips(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) + 
        "; c = " + to_string(c) + "result = " + to_string(result));

    a = 4;
    b = 2;
    c = 7;
    result = leetCode.minFlips(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) +
        "; c = " + to_string(c) + "result = " + to_string(result));

    a = 1;
    b = 2;
    c = 3;
    result = leetCode.minFlips(a, b, c);
    Logger::WriteMessage("a = " + to_string(a) + "; b = " + to_string(b) +
        "; c = " + to_string(c) + "result = " + to_string(result));
}

void TestLeetCode1323(void)
{
    Logger::WriteMessage("Test Leet Code 1323");
    LeetCodeMath leetCode;
    int num = 9669;
    int result = leetCode.maximum69Number(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 9996;
    result = leetCode.maximum69Number(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 9999;
    result = leetCode.maximum69Number(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode204(void)
{
    Logger::WriteMessage("Test Leet Code 204");
    LeetCodeMath leetCode;
    int n = 100;
    int numPrimes = leetCode.countPrimes(n);
    Logger::WriteMessage("The number of primes within " + to_string(n) + " is " + to_string(numPrimes));
}

void TestLeetCode1342(void)
{
    Logger::WriteMessage("Test Leet Code 1342");
    LeetCodeMath leetCode;
    int num = 14;
    int result = leetCode.numberOfSteps(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 8;
    result = leetCode.numberOfSteps(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 123;
    result = leetCode.numberOfSteps(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode1344(void)
{
    Logger::WriteMessage("Test Leet Code 1344");
    LeetCodeMath leetCode;
    int hour = 12;
    int minutes = 30;
    double result = leetCode.angleClock(hour, minutes);
    Logger::WriteMessage("hour = " + to_string(hour) + "; minutes = " + to_string(minutes) + "; result = " + to_string(result));

    hour = 3;
    minutes = 30;
    result = leetCode.angleClock(hour, minutes);
    Logger::WriteMessage("hour = " + to_string(hour) + "; minutes = " + to_string(minutes) + "; result = " + to_string(result));

    hour = 3;
    minutes = 15;
    result = leetCode.angleClock(hour, minutes);
    Logger::WriteMessage("hour = " + to_string(hour) + "; minutes = " + to_string(minutes) + "; result = " + to_string(result));

    hour = 4;
    minutes = 50;
    result = leetCode.angleClock(hour, minutes);
    Logger::WriteMessage("hour = " + to_string(hour) + "; minutes = " + to_string(minutes) + "; result = " + to_string(result));

    hour = 12;
    minutes = 0;
    result = leetCode.angleClock(hour, minutes);
    Logger::WriteMessage("hour = " + to_string(hour) + "; minutes = " + to_string(minutes) + "; result = " + to_string(result));
}

void TestLeetCode1354(void)
{
    Logger::WriteMessage("Test Leet Code 1354");
    LeetCodeMath leetCode;

    vector<int> target = { 9, 3, 5 };
    bool result = leetCode.isPossible(target);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    target = { 1,1,1,2 };
    result = leetCode.isPossible(target);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    target = { 8,5 };
    result = leetCode.isPossible(target);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1356(void)
{
    Logger::WriteMessage("Test Leet Code 1356");
    LeetCodeMath leetCode;

    vector<int> arr = { 0,1,2,3,4,5,6,7,8 };
    vector<int> result = leetCode.sortByBits(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 1024,512,256,128,64,32,16,8,4,2,1 };
    result = leetCode.sortByBits(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 10000,10000 };
    result = leetCode.sortByBits(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 2,3,5,7,11,13,17,19 };
    result = leetCode.sortByBits(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);

    arr = { 10,100,1000,10000 };
    result = leetCode.sortByBits(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage(result);
}

void TestLeetCode1359(void)
{
    Logger::WriteMessage("Test Leet Code 1359");
    LeetCodeMath leetCode;

    int n = 1;
    int result = leetCode.countOrders(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.countOrders(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    result = leetCode.countOrders(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1360(void)
{
    Logger::WriteMessage("Test Leet Code 1360");
    LeetCodeMath leetCode;

    string date1 = "2019-06-29";
    string date2 = "2019-06-30";
    int result = leetCode.daysBetweenDates(date1, date2);
    Logger::WriteMessage("date1 = " + date1 + "; date2 = " + date2 + "; result = " + to_string(result));

    date1 = "2020-01-15";
    date2 = "2019-12-31";
    result = leetCode.daysBetweenDates(date1, date2);
    Logger::WriteMessage("date1 = " + date1 + "; date2 = " + date2 + "; result = " + to_string(result));

    date1 = "1980-03-15";
    date2 = "2021-07-01";
    result = leetCode.daysBetweenDates(date1, date2);
    Logger::WriteMessage("date1 = " + date1 + "; date2 = " + date2 + "; result = " + to_string(result));
}

void TestLeetCode1363(void)
{
    Logger::WriteMessage("Test Leet Code 1363");
    LeetCodeMath leetCode;
    vector<int> digits = { 8, 1, 9 };
    Logger::WriteMessage(digits);    
    string result = leetCode.largestMultipleOfThree(digits);
    Logger::WriteMessage("result = " + result);

    digits = { 8,6,7,1,0 };
    Logger::WriteMessage(digits);
    result = leetCode.largestMultipleOfThree(digits);
    Logger::WriteMessage("result = " + result);

    digits = { 1 };
    Logger::WriteMessage(digits);
    result = leetCode.largestMultipleOfThree(digits);
    Logger::WriteMessage("result = " + result);

    digits = { 0,0,0,0,0,0 };
    Logger::WriteMessage(digits);
    result = leetCode.largestMultipleOfThree(digits);
    Logger::WriteMessage("result = " + result);

    digits = { 1,3,9,1,0,0 };
    Logger::WriteMessage(digits);
    result = leetCode.largestMultipleOfThree(digits);
    Logger::WriteMessage("result = " + result);

    digits = { 5,8 };
    Logger::WriteMessage(digits);
    result = leetCode.largestMultipleOfThree(digits);
    Logger::WriteMessage("result = " + result);
}

void TestLeetCode1362(void)
{
    Logger::WriteMessage("Test Leet Code 1362");
    LeetCodeMath leetCode;
    int num = 8;
    vector<int> result = leetCode.closestDivisors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 123;
    result = leetCode.closestDivisors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);

    num = 999;
    result = leetCode.closestDivisors(num);
    Logger::WriteMessage("num = " + to_string(num));
    Logger::WriteMessage(result);
}

void TestLeetCode1375(void)
{
    Logger::WriteMessage("Test Leet Code 1375");
    LeetCodeMath leetCode;
    vector<int> light = { 2, 1, 3, 5, 4 };
    int result = leetCode.numTimesAllBlue(light);
    Logger::WriteMessage(light);
    Logger::WriteMessage("result = " + to_string(result));

    light = { 3,2,4,1,5 };
    result = leetCode.numTimesAllBlue(light);
    Logger::WriteMessage(light);
    Logger::WriteMessage("result = " + to_string(result));

    light = { 4,1,2,3 };
    result = leetCode.numTimesAllBlue(light);
    Logger::WriteMessage(light);
    Logger::WriteMessage("result = " + to_string(result));

    light = { 2,1,4,3,6,5 };
    result = leetCode.numTimesAllBlue(light);
    Logger::WriteMessage(light);
    Logger::WriteMessage("result = " + to_string(result));

    light = { 1,2,3,4,5,6 };
    result = leetCode.numTimesAllBlue(light);
    Logger::WriteMessage(light);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1390(void)
{
    Logger::WriteMessage("Test Leet Code 1390");
    LeetCodeMath leetCode;
    vector<int> nums = { 21, 4, 7 };
    int result = leetCode.sumFourDivisors(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1399(void)
{
    Logger::WriteMessage("Test Leet Code 1399");
    LeetCodeMath leetCode;
    int n = 13;
    int result = leetCode.countLargestGroup(n);
    Logger::WriteMessage("n = "+ to_string(n) + "; result = " + to_string(result));

    n = 2;
    result = leetCode.countLargestGroup(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 15;
    result = leetCode.countLargestGroup(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 24;
    result = leetCode.countLargestGroup(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1401(void)
{
    Logger::WriteMessage("Test Leet Code 1401");
    LeetCodeMath leetCode;
    int radius = 1;
    int x_center = 0;
    int y_center = 0;
    int x1 = 1;
    int y1 = -1;
    int x2 = 3;
    int y2 = 1;
    bool result = leetCode.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    Logger::WriteMessage("radius = " + to_string(radius) + 
        "; x_center = " + to_string(x_center) +
        "; y_center = " + to_string(y_center) +
        "; x1 = " + to_string(x1) +
        "; y1 = " + to_string(y1) +
        "; x2 = " + to_string(x2) +
        "; y2 = " + to_string(y2) +
        "; x2 = " + to_string(x2) +
        "; result = " + (result ? "true" : "false")
    );

    radius = 1;
    x_center = 0;
    y_center = 0;
    x1 = -1;
    y1 = 0;
    x2 = 0;
    y2 = 1;
    result = leetCode.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    Logger::WriteMessage("radius = " + to_string(radius) +
        "; x_center = " + to_string(x_center) +
        "; y_center = " + to_string(y_center) +
        "; x1 = " + to_string(x1) +
        "; y1 = " + to_string(y1) +
        "; x2 = " + to_string(x2) +
        "; y2 = " + to_string(y2) +
        "; x2 = " + to_string(x2) +
        "; result = " + (result ? "true" : "false")
    );

    radius = 1; 
    x_center = 1;
    y_center = 1;
    x1 = -3; 
    y1 = -3; 
    x2 = 3; 
    y2 = 3;
    result = leetCode.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    Logger::WriteMessage("radius = " + to_string(radius) +
        "; x_center = " + to_string(x_center) +
        "; y_center = " + to_string(y_center) +
        "; x1 = " + to_string(x1) +
        "; y1 = " + to_string(y1) +
        "; x2 = " + to_string(x2) +
        "; y2 = " + to_string(y2) +
        "; x2 = " + to_string(x2) +
        "; result = " + (result ? "true" : "false")
    );

    radius = 1;
    x_center = 1;
    y_center = 1;
    x1 = 1; 
    y1 = -3; 
    x2 = 2;
    y2 = -1;
    result = leetCode.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    Logger::WriteMessage("radius = " + to_string(radius) +
        "; x_center = " + to_string(x_center) +
        "; y_center = " + to_string(y_center) +
        "; x1 = " + to_string(x1) +
        "; y1 = " + to_string(y1) +
        "; x2 = " + to_string(x2) +
        "; y2 = " + to_string(y2) +
        "; x2 = " + to_string(x2) +
        "; result = " + (result ? "true" : "false")
    );

    
    radius = 18;
    x_center = 11;
    y_center = 19;
    x1 = 7;
    y1 = 12;
    x2 = 10;
    y2 = 20;
    result = leetCode.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    Logger::WriteMessage("radius = " + to_string(radius) +
        "; x_center = " + to_string(x_center) +
        "; y_center = " + to_string(y_center) +
        "; x1 = " + to_string(x1) +
        "; y1 = " + to_string(y1) +
        "; x2 = " + to_string(x2) +
        "; y2 = " + to_string(y2) +
        "; x2 = " + to_string(x2) +
        "; result = " + (result ? "true" : "false")
    );
}

void TestLeetCode1414(void)
{
    Logger::WriteMessage("Test Leet Code 1414");
    LeetCodeMath leetCode;
    int k = 7;
    int result = leetCode.findMinFibonacciNumbers(k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    k = 10;
    result = leetCode.findMinFibonacciNumbers(k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));

    k = 19;
    result = leetCode.findMinFibonacciNumbers(k);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1415(void)
{
    Logger::WriteMessage("Test Leet Code 1415");
    LeetCodeMath leetCode;
    int n = 1;
    int k = 3;
    string result = leetCode.getHappyString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);

    n = 1;
    k = 4;
    result = leetCode.getHappyString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);

    n = 3;
    k = 9;
    result = leetCode.getHappyString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);

    n = 2;
    k = 7;
    result = leetCode.getHappyString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);

    n = 10;
    k = 100;
    result = leetCode.getHappyString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1432(void)
{
    Logger::WriteMessage("Test Leet Code 1432");
    LeetCodeMath leetCode;
    int num = 555;
    int result = leetCode.maxDiff(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 9;
    result = leetCode.maxDiff(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 123456;
    result = leetCode.maxDiff(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 10000;
    result = leetCode.maxDiff(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 9288;
    result = leetCode.maxDiff(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode1447(void)
{
    Logger::WriteMessage("Test Leet Code 1447");
    LeetCodeMath leetCode;
    int n = 2;
    vector<string> result = leetCode.simplifiedFractions(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 3;
    result = leetCode.simplifiedFractions(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 4;
    result = leetCode.simplifiedFractions(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 1;
    result = leetCode.simplifiedFractions(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1453(void)
{
    Logger::WriteMessage("Test Leet Code 1453");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {-2, 0},{2, 0},{0, 2},{0, -2} };
    int r = 2;
    int result = leetCode.numPoints(points, r);
    Logger::WriteMessage(points);
    Logger::WriteMessage("r = " + to_string(r) + "; result = " + to_string(result));

    points = { {-3, 0}, { 3, 0 }, { 2, 6 }, { 5, 4 }, { 0, 9 }, { 7, 8 }};
    r = 5;
    result = leetCode.numPoints(points, r);
    Logger::WriteMessage(points);
    Logger::WriteMessage("r = " + to_string(r) + "; result = " + to_string(result));

    points = { {-2, 0}, { 2, 0 }, { 0, 2 }, { 0, -2 } };
    r = 1;
    result = leetCode.numPoints(points, r);
    Logger::WriteMessage(points);
    Logger::WriteMessage("r = " + to_string(r) + "; result = " + to_string(result));

    points = { {1, 2}, { 3, 5 }, { 1, -1 }, { 2, 3 }, { 4, 1 }, { 1, 3 } };
    r = 2;
    result = leetCode.numPoints(points, r);
    Logger::WriteMessage(points);
    Logger::WriteMessage("r = " + to_string(r) + "; result = " + to_string(result));
   
}

void TestLeetCode970(void)
{
    Logger::WriteMessage("Test Leet Code 970");
    LeetCodeMath leetCode;
    int x = 2;
    int y = 3;
    int bound = 10;
    vector<int> result = leetCode.powerfulIntegers(x, y, bound);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; bound = " + to_string(bound));
    Logger::WriteMessage(result);

    x = 3;
    y = 5;
    bound = 15;
    result = leetCode.powerfulIntegers(x, y, bound);
    Logger::WriteMessage("x = " + to_string(x) + "; y = " + to_string(y) + "; bound = " + to_string(bound));
    Logger::WriteMessage(result);
}

void TestLeetCode1056(void)
{
    Logger::WriteMessage("Test Leet Code 1056");
    LeetCodeMath leetCode;
    int N = 6;
    bool result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 89;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 11;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 25;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));

    N = 689;
    result = leetCode.confusingNumber(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode1006(void)
{
    Logger::WriteMessage("Test Leet Code 1006");
    LeetCodeMath leetCode;
    int N = 4;
    int result = leetCode.clumsy(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 10;
    result = leetCode.clumsy(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode969(void)
{
    Logger::WriteMessage("Test Leet Code 969");
    LeetCodeMath leetCode;
    vector<int> A = { 3,2,4,1 };
    Logger::WriteMessage(A);
    vector<int> result = leetCode.pancakeSort(A);
    Logger::WriteMessage(A);
    Logger::WriteMessage(result);
}

void TestLeetCode910(void)
{
    Logger::WriteMessage("Test Leet Code 910");
    LeetCodeMath leetCode;
    vector<int> A = { 1 };
    int K = 0;
    int result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,10 };
    K = 2;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,3,6 };
    K = 3;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 6, 4, 10 };
    K = 5;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 3, 1, 10 };
    K = 4;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 7, 8, 8 };
    K = 5;
    result = leetCode.smallestRangeII(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode728(void)
{
    LeetCodeMath leetCode;
    int left = 1, right = 22;
    vector<int> result = leetCode.selfDividingNumbers(left, right);
    Logger::WriteMessage("left = " + to_string(left) + "; right = " + to_string(right));
    Logger::WriteMessage(result);
}

void TestLeetCode782(void)
{
    Logger::WriteMessage("Test Leet Code 782");
    LeetCodeMath leetCode;
    vector<vector<int>> board = { {0, 1, 1, 0},{0, 1, 1, 0},{1, 0, 0, 1},{1, 0, 0, 1} };
    int result = leetCode.movesToChessboard(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {0, 1},{1, 0} };
    result = leetCode.movesToChessboard(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));

    board = { {1, 0},{1, 0} };
    result = leetCode.movesToChessboard(board);
    Logger::WriteMessage(board);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode836(void)
{
    Logger::WriteMessage("Test Leet Code 836");
    LeetCodeMath leetCode;
    vector<int> rec1 = { 0, 0, 2, 2 };
    vector<int> rec2 = { 1, 1, 3, 3 };
    Logger::WriteMessage(rec1);
    Logger::WriteMessage(rec2);
    bool result = leetCode.isRectangleOverlap(rec1, rec2);
    Logger::WriteMessage("Overlap = " + (string)(result ? "true" : "false"));

    rec1 = { 0, 0, 1, 1 };
    rec2 = { 1, 0, 2, 1 };
    Logger::WriteMessage(rec1);
    Logger::WriteMessage(rec2);
    result = leetCode.isRectangleOverlap(rec1, rec2);
    Logger::WriteMessage("Overlap = " + (string)(result ? "true" : "false"));
}

void TestLeetCode789(void)
{
    Logger::WriteMessage("Test Leet Code 789");
    LeetCodeMath leetCode;
    vector<vector<int>> ghosts = { { 1, 0 },{ 0, 3 } };
    vector<int> target = { 0, 1 };
    bool result = leetCode.escapeGhosts(ghosts, target);
    Logger::WriteMessage(ghosts);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    ghosts = { { 1, 0 } };
    target = { 2, 0 };
    result = leetCode.escapeGhosts(ghosts, target);
    Logger::WriteMessage(ghosts);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));

    ghosts = { { 2, 0 } };
    target = { 1, 0 };
    result = leetCode.escapeGhosts(ghosts, target);
    Logger::WriteMessage(ghosts);
    Logger::WriteMessage(target);
    Logger::WriteMessage("result = " + (string)(result ? "true" : "false"));
}

void TestLeetCode829(void)
{
    Logger::WriteMessage("Test Leet Code 829");
    LeetCodeMath leetCode;
    int N = 5;
    int result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 9;
    result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 15;
    result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 27;
    result = leetCode.consecutiveNumbersSum(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode932(void)
{
    Logger::WriteMessage("Test Leet Code 932");
    LeetCodeMath leetCode;
    int N = 4;
    vector<int> result = leetCode.beautifulArray(N);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(result);

    N = 5;
    result = leetCode.beautifulArray(N);
    Logger::WriteMessage("N = " + to_string(N));
    Logger::WriteMessage(result);
}

void TestLeetCode12(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 12");
    int num = 20;
    string result = leetCode.intToRoman(num);
    Logger::WriteMessage("Number is " + to_string(num) + "; Roman is " + result);

    num = 999;
    result = leetCode.intToRoman(num);
    Logger::WriteMessage("Number is " + to_string(num) + "; Roman is " + result);
}

void TestLeetCode13(void)
{
    LeetCodeMath leetCode;
    Logger::WriteMessage("Test Leet Code 13");
    string roman = "XX";
    int num = leetCode.romanToInt(roman);
    Logger::WriteMessage("Roman is " + roman + "; Number is " + to_string(num));

    roman = "CMXCIX";
    num = leetCode.romanToInt(roman);
    Logger::WriteMessage("Roman is " + roman + "; Number is " + to_string(num));
}

void TestLeetCode171(void)
{
    Logger::WriteMessage("Test Leet Code 171");
    string column = "AB";
    LeetCodeMath leetCode;
    int number = leetCode.titleToNumber(column);
    Logger::WriteMessage("Column tile = " + column + " number = " + to_string(number));
}

void TestLeetCode263(void)
{
    Logger::WriteMessage("Test Leet Code 263");
    LeetCodeMath leetCode;
    int data = 18;
    bool is_ugly = leetCode.isUgly(data);
    Logger::WriteMessage(to_string(data) + " is " + (is_ugly ? "" : " not ") + "ugly number");
}

void TestLeetCode231(void)
{
    Logger::WriteMessage("Test Leet Code 231");
    LeetCodeMath leetCode;
    int n = 128;
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(leetCode.isPowerOfTwo(n) ? "is power of two" : "is not power of two");
    n = 0;
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(leetCode.isPowerOfTwo(n) ? "is power of two" : "is not power of two");
    n = INT_MIN;
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(leetCode.isPowerOfTwo(n) ? "is power of two" : "is not power of two");
}

void TestLeetCode168(void)
{
    Logger::WriteMessage("Test Leet Code 168");
    int number = 26 * 26;

    LeetCodeMath leetCode;
    string column = leetCode.convertToTitle(number);
    Logger::WriteMessage("Column number = " + to_string(number) + " title = " + column);
}

void TestLeetCode386(void)
{
    Logger::WriteMessage("Test Leet Code 386");
    LeetCodeMath leetCode;
    int n = 220;
    vector<int> result = leetCode.lexicalOrder(n);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode400(void)
{
    Logger::WriteMessage("Test Leet Code 400");
    LeetCodeMath leetCode;
    int n = 1000000000;
    int digit = leetCode.findNthDigit(n);
    Logger::WriteMessage("The " + to_string(n) + "th digit is " + to_string(digit));
}

void TestLeetCode233(void)
{
    Logger::WriteMessage("Test Leet Code 233");
    LeetCodeMath leetCode;
    int n = 824883294;
    int count = leetCode.countDigitOne(n);
    Logger::WriteMessage("Count digit one for " + to_string(n) + "; count = " + to_string(count));

    n = 9;
    count = leetCode.countDigitOne(n);
    Logger::WriteMessage("Count digit one for " + to_string(n) + "; count = " + to_string(count));

    n = 27;
    count = leetCode.countDigitOne(n);
    Logger::WriteMessage("Count digit one for " + to_string(n) + "; count = " + to_string(count));
}

void TestLeetCode1067(void)
{
    Logger::WriteMessage("Test Leet Code 1067");
    LeetCodeMath leetCode;
    int d = 0;
    int low = 1;
    int high = 100;
    int result = leetCode.digitsCount(d, low, high);
    Logger::WriteMessage("d = " + to_string(d) + "; low = " + to_string(low) +
        "; high = " + to_string(high) + "; result = " + to_string(result));

    d = 1;
    low = 1;
    high = 13;
    result = leetCode.digitsCount(d, low, high);
    Logger::WriteMessage("d = " + to_string(d) + "; low = " + to_string(low) +
        "; high = " + to_string(high) + "; result = " + to_string(result));

    d = 3;
    low = 100;
    high = 250;
    result = leetCode.digitsCount(d, low, high);
    Logger::WriteMessage("d = " + to_string(d) + "; low = " + to_string(low) +
        "; high = " + to_string(high) + "; result = " + to_string(result));
}

void TestLeetCode908(void)
{
    Logger::WriteMessage("Test Leet Code 908");
    LeetCodeMath leetCode;
    vector<int> A = { 1 };
    int K = 0;
    int result = leetCode.smallestRangeI(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 0,10 };
    K = 2;
    result = leetCode.smallestRangeI(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));

    A = { 1,3,6 };
    K = 3;
    result = leetCode.smallestRangeI(A, K);
    Logger::WriteMessage(A);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode31(void)
{
    Logger::WriteMessage("Test Leet Code 31");
    vector<int> nums;
    LeetCodeMath leetCode;
    nums = { 1,2,3 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = { 3,2,1 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = { 1,5,1 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = { 1,1,5 };
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
    nums = {};
    Logger::WriteMessage(nums);
    leetCode.nextPermutation(nums);
    Logger::WriteMessage(nums);
}

void TestLeetCode60(void)
{
    Logger::WriteMessage("Test Leet Code 60");
    LeetCodeMath leetCode;
    int n = 9, k = 10000;
    string result = leetCode.getPermutation(n, k);
    Logger::WriteMessage("The " + to_string(k) + "th permutation in " + to_string(n) + "! sequence is " + result);
}

void TestLeetCode357(void)
{
    Logger::WriteMessage("Test Leet Code 357");
    LeetCodeMath leetCode;
    int n = 2;
    int count = leetCode.countNumbersWithUniqueDigits(n);
    Logger::WriteMessage("Count numbers with unique digits with " + to_string(n) + "; count = " + to_string(count));
}

void TestLeetCode398(void)
{
    Logger::WriteMessage("Test Leet Code 398");
    LeetCodeMath leetCode;
    vector<int> nums = { 1,2,3,3,3 };
    int target = 2;
    int index = leetCode.pickRandom(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The random pick " + to_string(target) + " is " + to_string(index));
    target = 1;
    index = leetCode.pickRandom(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The random pick " + to_string(target) + " is " + to_string(index));
    target = 3;
    index = leetCode.pickRandom(nums, target);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("The random pick " + to_string(target) + " is " + to_string(index));
}


void TestLeetCode1012(void)
{
    Logger::WriteMessage("Test Leet Code 1012");
    LeetCodeMath leetCode;
    int N = 210;
    int result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 100;
    result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 1000;
    result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 1010;
    result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 123456789;
    result = leetCode.numDupDigitsAtMostN(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode1000(void)
{
    Logger::WriteMessage("Test Leet Code 1000");
    LeetCodeMath leetCode;
    vector<int> stones = { 3, 2, 4, 1 };
    int K = 2;
    int result = leetCode.mergeStones(stones, K);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    stones = { 3,2,4,1 };
    K = 3;
    result = leetCode.mergeStones(stones, K);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

    stones = { 3, 5, 1, 2, 6 };
    K = 3;
    result = leetCode.mergeStones(stones, K);
    Logger::WriteMessage(stones);
    Logger::WriteMessage("K = " + to_string(K) + "; result = " + to_string(result));

}

void TestLeetCode964(void)
{
    Logger::WriteMessage("Test Leet Code 964");
    LeetCodeMath leetCode;
    int x = 3;
    int target = 19;
    int result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));

    x = 5;
    target = 501;
    result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));

    x = 100;
    target = 100000000;
    result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));

    x = 2;
    target = 125046;
    result = leetCode.leastOpsExpressTarget(x, target);
    Logger::WriteMessage("x = " + to_string(x) + "; target = " + to_string(target) + "; result = " + to_string(result));
}

void TestLeetCode1088(void)
{
    Logger::WriteMessage("Test Leet Code 1088");
    LeetCodeMath leetCode;
    int N = 20;
    int result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 10;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 9;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 99;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 999;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 9999;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));

    N = 1011;
    result = leetCode.confusingNumberII(N);
    Logger::WriteMessage("N = " + to_string(N) + "; result = " + to_string(result));
}

void TestLeetCode517(void)
{
    Logger::WriteMessage("Test Leet Code 517");
    LeetCodeMath leetCode;
    vector<int> nums = { 1,0,5 };
    Logger::WriteMessage(nums);
    int result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));

    nums = { 9, 1, 8, 8, 9 };
    Logger::WriteMessage(nums);
    result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));

    nums = { 0,3,0 };
    Logger::WriteMessage(nums);
    result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));

    nums = { 0,2,0 };
    Logger::WriteMessage(nums);
    result = leetCode.findMinMoves(nums);
    Logger::WriteMessage("Minimum Move =" + to_string(result));
}

void TestLeetCode384(void)
{
    Logger::WriteMessage("Test Leet Code 384");
    LeetCodeMath leetCode;
    vector<int> nums = { 1,2,3 };
    vector<int> result = leetCode.shuffle(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage(result);
}

void TestLeetCode1467(void)
{
    Logger::WriteMessage("Test Leet Code 1467");
    LeetCodeMath leetCode;
    vector<int> balls = { 1, 1 };
    double result = leetCode.getProbability(balls);
    Logger::WriteMessage(balls);
    Logger::WriteMessage("result = " + to_string(result));

    balls = { 2,1,1 };
    result = leetCode.getProbability(balls);
    Logger::WriteMessage(balls);
    Logger::WriteMessage("result = " + to_string(result));

    balls = { 1,2,1,2 };
    result = leetCode.getProbability(balls);
    Logger::WriteMessage(balls);
    Logger::WriteMessage("result = " + to_string(result));

    balls = { 3,2,1 };
    result = leetCode.getProbability(balls);
    Logger::WriteMessage(balls);
    Logger::WriteMessage("result = " + to_string(result));

    balls = { 6,6,6,6,6,6 };
    result = leetCode.getProbability(balls);
    Logger::WriteMessage(balls);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1464(void)
{
    Logger::WriteMessage("Test Leet Code 1464");
    LeetCodeMath leetCode;
    vector<int> nums = { 3, 4, 5, 2 };
    int result = leetCode.maxProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 1,5,4,5 };
    result = leetCode.maxProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,7 };
    result = leetCode.maxProduct(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1465(void)
{
    Logger::WriteMessage("Test Leet Code 1465");
    LeetCodeMath leetCode;
    int h = 5;
    int w = 4;
    vector<int> horizontalCuts = { 1, 2, 4 };
    vector<int> verticalCuts = { 1, 3 };
    int result = leetCode.maxArea(h, w, horizontalCuts, verticalCuts);
    Logger::WriteMessage(horizontalCuts);
    Logger::WriteMessage(verticalCuts);
    Logger::WriteMessage("h = " + to_string(h) + "; w = " + to_string(w) + "; result = " + to_string(result));

    h = 5;
    w = 4;
    horizontalCuts = { 3, 1 };
    verticalCuts = { 1 };
    result = leetCode.maxArea(h, w, horizontalCuts, verticalCuts);
    Logger::WriteMessage(horizontalCuts);
    Logger::WriteMessage(verticalCuts);
    Logger::WriteMessage("h = " + to_string(h) + "; w = " + to_string(w) + "; result = " + to_string(result));

    h = 5;
    w = 4;
    horizontalCuts = { 3 };
    verticalCuts = { 3 };
    result = leetCode.maxArea(h, w, horizontalCuts, verticalCuts);
    Logger::WriteMessage(horizontalCuts);
    Logger::WriteMessage(verticalCuts);
    Logger::WriteMessage("h = " + to_string(h) + "; w = " + to_string(w) + "; result = " + to_string(result));

    h = 6;
    w = 3;
    horizontalCuts = { 5, 4, 1, 2, 3 };
    verticalCuts = { 2, 1 };
    result = leetCode.maxArea(h, w, horizontalCuts, verticalCuts);
    Logger::WriteMessage(horizontalCuts);
    Logger::WriteMessage(verticalCuts);
    Logger::WriteMessage("h = " + to_string(h) + "; w = " + to_string(w) + "; result = " + to_string(result));
}

void TestLeetCode670(void)
{
    LeetCodeMath leetCode;
    int num = 1993;
    int result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 2736;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 9973;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 3203;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 912939;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));

    num = 12939;
    result = leetCode.maximumSwap(num);
    Logger::WriteMessage("num = " + to_string(num) + "; result = " + to_string(result));
}

void TestLeetCode825(void)
{
    Logger::WriteMessage("Test Leet Code 825");
    LeetCodeMath leetCode;
    vector<int> ages = { 16,16 };
    int result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 16,17,18 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 20,30,100,110,120 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 108, 115, 5, 24, 82 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));

    ages = { 73, 106, 39, 6, 26, 15, 30, 100, 71, 35, 46, 112, 6, 60, 110 };
    result = leetCode.numFriendRequests(ages);
    Logger::WriteMessage(ages);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode939(void)
{
    Logger::WriteMessage("Test Leet Code 939");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {1, 1},{1, 3},{3, 1},{3, 3},{2, 2} };
    int result = leetCode.minAreaRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));

    points = { { 1, 1 },{ 1, 3 },{ 3, 1 },{ 3, 3 },{4,1},{4,3} };
    result = leetCode.minAreaRect(points);
    Logger::WriteMessage(points);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1492(void)
{
    Logger::WriteMessage("Test Leet Code 1492");
    LeetCodeMath leetCode;
    int n = 12;
    int k = 3;
    int result = leetCode.kthFactor(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 7;
    k = 2;
    result = leetCode.kthFactor(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 4;
    k = 4;
    result = leetCode.kthFactor(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 1;
    k = 1;
    result = leetCode.kthFactor(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 1000;
    k = 3;
    result = leetCode.kthFactor(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));

    n = 24;
    k = 6;
    result = leetCode.kthFactor(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + to_string(result));
}

void TestLeetCode1503(void)
{
    Logger::WriteMessage("Test Leet Code 1503");
    LeetCodeMath leetCode;
    int n = 4;
    vector<int> left = { 4, 3 };
    vector<int> right = { 0, 1 };
    int result = leetCode.getLastMoment(n, left, right);
    Logger::WriteMessage(left);
    Logger::WriteMessage(right);
    Logger::WriteMessage("result = " + to_string(result));

    n = 7;
    left = { };
    right = { 0,1,2,3,4,5,6,7 };
    result = leetCode.getLastMoment(n, left, right);
    Logger::WriteMessage(left);
    Logger::WriteMessage(right);
    Logger::WriteMessage("result = " + to_string(result));

    n = 7;
    left = { 0,1,2,3,4,5,6,7 };
    right = { };
    result = leetCode.getLastMoment(n, left, right);
    Logger::WriteMessage(left);
    Logger::WriteMessage(right);
    Logger::WriteMessage("result = " + to_string(result));

    n = 9;
    left = { 5 };
    right = { 4 };
    result = leetCode.getLastMoment(n, left, right);
    Logger::WriteMessage(left);
    Logger::WriteMessage(right);
    Logger::WriteMessage("result = " + to_string(result));

    n = 6;
    left = { 6 };
    right = { 0 };
    result = leetCode.getLastMoment(n, left, right);
    Logger::WriteMessage(left);
    Logger::WriteMessage(right);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1515(void)
{
    Logger::WriteMessage("Test Leet Code 1515");
    LeetCodeMath leetCode;
    vector<vector<int>> positions = { {0, 1},{1, 0},{1, 2},{2, 1} };
    double result = leetCode.getMinDistSum(positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    positions = { {1, 1},{3, 3} };
    result = leetCode.getMinDistSum(positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    positions = { {1, 1} };
    result = leetCode.getMinDistSum(positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    positions = { {1, 1},{0, 0},{2, 0} };
    result = leetCode.getMinDistSum(positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));

    positions = { {0, 1},{3, 2},{4, 5},{7, 6},{8, 9},{11, 1},{2, 12} };
    result = leetCode.getMinDistSum(positions);
    Logger::WriteMessage(positions);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1518(void)
{
    Logger::WriteMessage("Test Leet Code 1518");
    LeetCodeMath leetCode;
    int numBottles = 9;
    int numExchange = 3;
    int result = leetCode.numWaterBottles(numBottles, numExchange);
    Logger::WriteMessage("numBottles = " + to_string(numBottles) + "; numExchange = " + to_string(numExchange) + "; result = " + to_string(result));

    numBottles = 15;
    numExchange = 4;
    result = leetCode.numWaterBottles(numBottles, numExchange);
    Logger::WriteMessage("numBottles = " + to_string(numBottles) + "; numExchange = " + to_string(numExchange) + "; result = " + to_string(result));

    numBottles = 5;
    numExchange = 5;
    result = leetCode.numWaterBottles(numBottles, numExchange);
    Logger::WriteMessage("numBottles = " + to_string(numBottles) + "; numExchange = " + to_string(numExchange) + "; result = " + to_string(result));

    numBottles = 2;
    numExchange = 3;
    result = leetCode.numWaterBottles(numBottles, numExchange);
    Logger::WriteMessage("numBottles = " + to_string(numBottles) + "; numExchange = " + to_string(numExchange) + "; result = " + to_string(result));
}

void TestLeetCode1523(void)
{
    Logger::WriteMessage("Test Leet Code 1523");
    LeetCodeMath leetCode;
    int low = 3;
    int high = 7;
    int result = leetCode.countOdds(low, high);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; result = " + to_string(result));

    low = 8;
    high = 10;
    result = leetCode.countOdds(low, high);
    Logger::WriteMessage("low = " + to_string(low) + "; high = " + to_string(high) + "; result = " + to_string(result));
}

void TestLeetCode1551(void)
{
    Logger::WriteMessage("Test Leet Code 1551");
    LeetCodeMath leetCode;
    int n = 3;
    int result = leetCode.minOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 6;
    result = leetCode.minOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1558(void)
{
    Logger::WriteMessage("Test Leet Code 1558");
    LeetCodeMath leetCode;
    vector<int> nums = { 1, 5 };
    int result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2, 2 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 4,2,5 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 3,2,2,4 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));

    nums = { 2,4,8,16 };
    result = leetCode.minOperations(nums);
    Logger::WriteMessage(nums);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1560(void)
{
    Logger::WriteMessage("Test Leet Code 1560");
    LeetCodeMath leetCode;
    int n = 4;
    vector<int> rounds = { 1,3,1,2 };
    vector<int> result = leetCode.mostVisited(n, rounds);
    Logger::WriteMessage(rounds);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 2;
    rounds = { 2,1,2,1,2,1,2,1,2 };
    result = leetCode.mostVisited(n, rounds);
    Logger::WriteMessage(rounds);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);

    n = 7;
    rounds = { 1,3,5,7 };
    result = leetCode.mostVisited(n, rounds);
    Logger::WriteMessage(rounds);
    Logger::WriteMessage("n = " + to_string(n));
    Logger::WriteMessage(result);
}

void TestLeetCode1561(void)
{
    Logger::WriteMessage("Test Leet Code 1561");
    LeetCodeMath leetCode;
    vector<int> piles = { 2, 4, 1, 2, 7, 8 };
    int result = leetCode.maxCoins(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("result = " + to_string(result));

    piles = { 2,4,5 };
    result = leetCode.maxCoins(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("result = " + to_string(result));

    piles = { 9,8,7,6,5,1,2,3,4 };
    result = leetCode.maxCoins(piles);
    Logger::WriteMessage(piles);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1611(void)
{
    Logger::WriteMessage("Test Leet Code 1611");
    LeetCodeMath leetCode;
    int n = 0;
    int result = leetCode.minimumOneBitOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 3;
    result = leetCode.minimumOneBitOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 6;
    result = leetCode.minimumOneBitOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 9;
    result = leetCode.minimumOneBitOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));

    n = 333;
    result = leetCode.minimumOneBitOperations(n);
    Logger::WriteMessage("n = " + to_string(n) + "; result = " + to_string(result));
}

void TestLeetCode1610(void)
{
    Logger::WriteMessage("Test Leet Code 1610");
    LeetCodeMath leetCode;
    vector<vector<int>> points = { {2, 1},{2, 2},{3, 3}, {0, 0} };
    vector<int> location = { 1, 1 };
    int angle = 90;
    int result = leetCode.visiblePoints(points, angle, location);
    Logger::WriteMessage(points);
    Logger::WriteMessage("angle = " + to_string(angle) + "; result = " + to_string(result));

    points = { {2, 1},{2, 2},{3, 4},{1, 1} };
    location = { 1, 1 };
    angle = 90;
    result = leetCode.visiblePoints(points, angle, location);
    Logger::WriteMessage(points);
    Logger::WriteMessage("angle = " + to_string(angle) + "; result = " + to_string(result));

    points = { {1, 0},{2, 1} };
    location = { 1, 1 };
    angle = 90;
    result = leetCode.visiblePoints(points, angle, location);
    Logger::WriteMessage(points);
    Logger::WriteMessage("angle = " + to_string(angle) + "; result = " + to_string(result));

    points = { {1, 1}, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 1, 2 }, { 2, 1 } };
    location = { 1, 1 };
    angle = 0;
    result = leetCode.visiblePoints(points, angle, location);
    Logger::WriteMessage(points);
    Logger::WriteMessage("angle = " + to_string(angle) + "; result = " + to_string(result));
}

void TestLeetCode1619(void)
{
    Logger::WriteMessage("Test Leet Code 1619");
    LeetCodeMath leetCode;
    vector<int> arr = { 1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3 };
    double result = leetCode.trimMean(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0 };
    result = leetCode.trimMean(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0 };
    result = leetCode.trimMean(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4 };
    result = leetCode.trimMean(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3 };
    result = leetCode.trimMean(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));

    arr = { 4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1 };
    result = leetCode.trimMean(arr);
    Logger::WriteMessage(arr);
    Logger::WriteMessage("result = " + to_string(result));
}

void TestLeetCode1620(void)
{
    Logger::WriteMessage("Test Leet Code 1620");
    LeetCodeMath leetCode;
    vector<vector<int>> towers = { {1, 2, 5},{2, 1, 7},{3, 1, 9} };
    int radius = 2;
    vector<int> result = leetCode.bestCoordinate(towers, radius);
    Logger::WriteMessage(towers);
    Logger::WriteMessage(result);

    towers = { {23,11,21} };
    radius = 9;
    result = leetCode.bestCoordinate(towers, radius);
    Logger::WriteMessage(towers);
    Logger::WriteMessage(result);

    towers = { {1, 2, 13}, {2, 1, 7}, {0, 1, 9} };
    radius = 2;
    result = leetCode.bestCoordinate(towers, radius);
    Logger::WriteMessage(towers);
    Logger::WriteMessage(result);

    towers = { {2,1,9}, {0,1,9} };
    radius = 2;
    result = leetCode.bestCoordinate(towers, radius);
    Logger::WriteMessage(towers);
    Logger::WriteMessage(result);
}

void TestLeetCode1643(void)
{
    Logger::WriteMessage("Test Leet Code 1643");
    LeetCodeMath leetCode;
    vector<int> destination = { 2, 3 };
    int k = 1;
    string result = leetCode.kthSmallestPath(destination, k);
    Logger::WriteMessage(destination);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    destination = { 2, 3 };
    k = 2;
    result = leetCode.kthSmallestPath(destination, k);
    Logger::WriteMessage(destination);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);

    destination = { 2, 3 };
    k = 3;
    result = leetCode.kthSmallestPath(destination, k);
    Logger::WriteMessage(destination);
    Logger::WriteMessage("k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1648(void)
{
    Logger::WriteMessage("Test Leet Code 1648");
    LeetCodeMath leetCode;
    vector<int> inventory = { 2, 5 };
    int orders = 4;
    int result = leetCode.maxProfit(inventory, orders);
    Logger::WriteMessage(inventory);
    Logger::WriteMessage("orders = " + to_string(orders) + "; result = " + to_string(result));

    inventory = { 3, 5 };
    orders = 6;
    result = leetCode.maxProfit(inventory, orders);
    Logger::WriteMessage(inventory);
    Logger::WriteMessage("orders = " + to_string(orders) + "; result = " + to_string(result));

    inventory = { 2,8,4,10,6 };
    orders = 20;
    result = leetCode.maxProfit(inventory, orders);
    Logger::WriteMessage(inventory);
    Logger::WriteMessage("orders = " + to_string(orders) + "; result = " + to_string(result));

    inventory = { 1000000000 };
    orders = 1000000000;
    result = leetCode.maxProfit(inventory, orders);
    Logger::WriteMessage(inventory);
    Logger::WriteMessage("orders = " + to_string(orders) + "; result = " + to_string(result));
}

void TestLeetCode1663(void)
{
    Logger::WriteMessage("Test Leet Code 1663");
    LeetCodeMath leetCode;
    int n = 3;
    int k = 27;
    string result = leetCode.getSmallestString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);

    n = 5;
    k = 73;
    result = leetCode.getSmallestString(n, k);
    Logger::WriteMessage("n = " + to_string(n) + "; k = " + to_string(k) + "; result = " + result);
}

void TestLeetCode1674(void)
{
    Logger::WriteMessage("Test Leet Code 1674");
    LeetCodeMath leetCode;
    vector<int> nums = { 1, 2, 4, 3 };
    int limit = 4;
    int result = leetCode.minMoves(nums, limit);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    nums = { 1,2,2,1 };
    limit = 2;
    result = leetCode.minMoves(nums, limit);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));

    nums = { 1,2,1,2 };
    limit = 2;
    result = leetCode.minMoves(nums, 4);
    Logger::WriteMessage("limit = " + to_string(limit) + "; result = " + to_string(result));
}

void TestLeetCodeMath(void)
{
    TestLeetCode1674();
    TestLeetCode1663();
    TestLeetCode1648();
    TestLeetCode1643();
    TestLeetCode1619();
    TestLeetCode1610();
    TestLeetCode1611();
    TestLeetCode1561();
    TestLeetCode1560();
    TestLeetCode1558();
    TestLeetCode1551();
    TestLeetCode1523();
    TestLeetCode1518();
    TestLeetCode1515();
    TestLeetCode1503();
    TestLeetCode1492();
    TestLeetCode825();
    TestLeetCode670();
    TestLeetCode1465();
    TestLeetCode1464();
    TestLeetCode1467();
    TestLeetCode384();
    TestLeetCode517();
    TestLeetCode1088();
    TestLeetCode964();
    TestLeetCode1000();
    TestLeetCode1012();
    TestLeetCode398();
    TestLeetCode357();
    TestLeetCode31();
    TestLeetCode60();
    TestLeetCode908();
    TestLeetCode1067();
    TestLeetCode233();
    TestLeetCode386();
    TestLeetCode400();
    TestLeetCode168();
    TestLeetCode171();
    TestLeetCode263();
    TestLeetCode231();
    TestLeetCode12();
    TestLeetCode13();
    TestLeetCode932();
    TestLeetCode829();
    TestLeetCode789();
    TestLeetCode836();
    TestLeetCode782();
    TestLeetCode728();
    TestLeetCode910();
    TestLeetCode969();
    TestLeetCode1006();
    TestLeetCode1056();
    TestLeetCode970();
    TestLeetCode1453();
    TestLeetCode1447();
    TestLeetCode1432();
    TestLeetCode1415();
    TestLeetCode1414();
    TestLeetCode1401();
    TestLeetCode1399();
    TestLeetCode1390();
    TestLeetCode1375();
    TestLeetCode1362();
    TestLeetCode1363();
    TestLeetCode1360();
    TestLeetCode1359();
    TestLeetCode1356();
    TestLeetCode1354();
    TestLeetCode1344();
    TestLeetCode1342();
    TestLeetCode1323();
    TestLeetCode1318();
    TestLeetCode1317();
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