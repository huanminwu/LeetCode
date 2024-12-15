#pragma once
#ifndef LeetcodeThread_H
#define LeetCodeThread_H
#include <stdint.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include <functional>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <thread>
#include <mutex>
using namespace std;

/// <summary>
/// Leet code #1114. Print in Order
/// 
/// Easy
///
/// Suppose we have a class:
///  public class Foo {
///      public void first() { print("first"); }
///      public void second() { print("second"); }
///      public void third() { print("third"); }
/// }
/// The same instance of Foo will be passed to three different threads. 
/// Thread A will call first(), thread B will call second(), and thread 
/// C will call third(). Design a mechanism and modify the program to 
/// ensure that second() is executed after first(), and third() is 
/// executed after second().
/// 
/// Example 1:
///
/// Input: [1,2,3]
/// Output: "firstsecondthird"
/// Explanation: There are three threads being fired asynchronously. 
/// The input [1,2,3] means thread A calls first(), thread B calls 
/// second(), and thread C calls third(). "firstsecondthird" is 
/// the correct output.
/// Example 2:
///
/// Input: [1,3,2]
/// Output: "firstsecondthird"
/// Explanation: The input [1,3,2] means thread A calls first(), 
/// thread B calls third(), and thread C calls second(). 
/// "firstsecondthird" is the correct output.
///
/// Note:
/// We do not know how the threads will be scheduled in the operating 
/// system, even though the numbers in the input seems to imply the 
/// ordering. The input format you see is mainly to ensure our tests' 
/// comprehensiveness.
/// </summary>
class PrintInOrder
{
private:
    int m_flag;
    std::mutex m_mutex;
    std::condition_variable m_var;
public:
    void printFirst(void)
    {
        printf("first");
    }

    void printSecond(void)
    {
        printf("second");
    }

    void printThird(void)
    {
        printf("third");
    }

    PrintInOrder()
    {
        m_flag = 1;
    }

    void first()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_var.wait(lock, [this]() {return m_flag == 1; });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_flag = 2;
        lock.unlock();
        m_var.notify_all();
    }

    void second()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_var.wait(lock, [this]() {return m_flag == 2; });

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_flag = 3;
        lock.unlock();
        m_var.notify_one();
    }

    void third()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_var.wait(lock, [this]() {return m_flag == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m_flag = 1;
        lock.unlock();
        m_var.notify_one();
    }
};

/// <summary>
/// Leet code #1115. Print FooBar Alternately
/// 
/// Medium
///
/// Suppose you are given the following code:
///
/// class FooBar {
///     public void foo() {
///         for (int i = 0; i < n; i++) {
///             print("foo");
///         }
///     }
///
///     public void bar() {
///         for (int i = 0; i < n; i++) {
///             print("bar");
///         }
///     }
/// }
/// The same instance of FooBar will be passed to two different threads. 
/// Thread A will call foo() while thread B will call bar(). Modify 
/// the given program to output "foobar" n times.
///
/// Example 1:
/// Input: n = 1
/// Output: "foobar"
/// Explanation: There are two threads being fired asynchronously. One 
/// of them calls foo(), while the other calls bar(). "foobar" is being 
/// output 1 time.
///
/// Example 2:
/// Input: n = 2
/// Output: "foobarfoobar"
/// Explanation: "foobar" is being output 2 times.
/// </summary>
class FooBar
{
private:
    int m_flag;
    std::mutex m_mutex;
    std::condition_variable m_var;
    int n;
public:
    void printFoo(void)
    {
        printf("foo");
    }

    void printBar(void)
    {
        printf("bar");
    }

    FooBar(int n)
    {
        this->n = n;
        m_flag = 1;
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return m_flag == 1; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            m_flag = 2;
            lock.unlock();
            m_var.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return m_flag == 2; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            m_flag = 1;
            lock.unlock();
            m_var.notify_one();
        }
    }
};


/// <summary>
/// Leet code #1116. Print Zero Even Odd
/// 
/// Medium
///
/// Suppose you are given the following code:
///
/// class ZeroEvenOdd {
///     public ZeroEvenOdd(int n) { ... }      // constructor
///     public void zero(printNumber) { ... }  // only output 0's
///     public void even(printNumber) { ... }  // only output even numbers
///     public void odd(printNumber) { ... }   // only output odd numbers
/// }
/// The same instance of ZeroEvenOdd will be passed to three different threads:
/// Thread A will call zero() which should only output 0's.
/// Thread B will call even() which should only ouput even numbers.
/// Thread C will call odd() which should only output odd numbers.
/// Each of the threads is given a printNumber method to output an integer. 
/// Modify the given program to output the series 010203040506... where the 
/// length of the series must be 2n.
/// 
/// Example 1:
/// Input: n = 2
/// Output: "0102"
/// Explanation: There are three threads being fired asynchronously. One of 
/// them calls zero(), the other calls even(), and the last one calls odd(). 
/// "0102" is the correct output.
///
/// Example 2:
/// Input: n = 5
/// Output: "0102030405"
/// </summary>
class ZeroEvenOdd {
private:
    int n;
    int m_state;
    int m_next;
    std::mutex m_mutex;
    std::condition_variable m_var;
public:

    ZeroEvenOdd(int n)
    {
        this->n = n;
        m_state = 0;
        m_next = 1;
    }


    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return m_state == 0; });
            printNumber(0);
            m_state = 2 - m_next;
            lock.unlock();
            m_var.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return m_state == 2; });
            printNumber(i);
            m_state = 0;
            m_next = 1;
            lock.unlock();
            m_var.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {

        for (int i = 1; i <= n; i += 2)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return m_state == 1; });
            printNumber(i);
            m_state = 0;
            m_next = 0;
            lock.unlock();
            m_var.notify_all();
        }
    }
};

/// <summary>
/// Leet code #1117. Building H2O
/// Medium
///
/// There are two kinds of threads, oxygen and hydrogen. Your goal is to 
/// group these threads to form water molecules. There is a barrier where 
/// each thread has to wait until a complete molecule can be formed. Hydrogen 
/// and oxygen threads will be given releaseHydrogen and releaseOxygen 
/// methods respectively, which will allow them to pass the barrier. These 
/// threads should pass the barrier in groups of three, and they must be able 
/// to immediately bond with each other to form a water molecule. You must 
/// guarantee that all the threads from one molecule bond before any other 
/// threads from the next molecule do.
///
/// In other words:
///
/// If an oxygen thread arrives at the barrier when no hydrogen threads are 
/// present, it has to wait for two hydrogen threads.
/// If a hydrogen thread arrives at the barrier when no other threads are 
/// present, it has to wait for an oxygen thread and another hydrogen thread.
/// We don't have to worry about matching the threads up explicitly; that is, 
/// the threads do not necessarily know which other threads they are paired 
/// up with. The key is just that threads pass the barrier in complete sets; 
/// thus, if we examine the sequence of threads that bond and divide them 
/// into groups of three, each group should contain one oxygen and two 
/// hydrogen threads.
///
/// Write synchronization code for oxygen and hydrogen molecules that 
/// enforces these constraints.
/// Example 1:
/// Input: "HOH"
/// Output: "HHO"
/// Explanation: "HOH" and "OHH" are also valid answers.
///
/// Example 2:
/// Input: "OOHHHH"
/// Output: "HHOHHO"
/// Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", 
/// "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
/// 
/// Constraints:
/// 1. Total length of input string will be 3n, where 1 <= n <= 20.
/// 2. Total number of H will be 2n in the input string.
/// 3. Total number of O will be n in the input string.
/// </summary>
class H2O
{
private:
    int m_hydrogen;
    std::mutex m_mutex;
    std::condition_variable m_var;
public:
    H2O()
    {
        m_hydrogen = 0;
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_var.wait(lock, [this]() {return m_hydrogen < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        m_hydrogen++;
        lock.unlock();
        m_var.notify_all();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_var.wait(lock, [this]() {return m_hydrogen == 2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        m_hydrogen = 0;
        lock.unlock();
        m_var.notify_all();
    }
};

/// <summary>
/// Leet code #1195. Fizz Buzz Multithreaded
/// Medium
///
/// Write a program that outputs the string representation of numbers from 1 
/// to n, however:
/// 
/// If the number is divisible by 3, output "fizz".
/// If the number is divisible by 5, output "buzz".
/// If the number is divisible by both 3 and 5, output "fizzbuzz".
/// For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, 
/// fizz, buzz, 11, fizz, 13, 14, fizzbuzz.
///
/// Suppose you are given the following code:
///
/// class FizzBuzz {
///     public FizzBuzz(int n) { ... }               // constructor
///     public void fizz(printFizz) { ... }          // only output "fizz"
///     public void buzz(printBuzz) { ... }          // only output "buzz"
///     public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
///     public void number(printNumber) { ... }      // only output the numbers
/// }
/// Implement a multithreaded version of FizzBuzz with four threads. The same 
/// instance of FizzBuzz will be passed to four different threads:
/// Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
/// Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
/// Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and 
/// outputs fizzbuzz.
/// Thread D will call number() which should only output the numbers.
/// </summary>
class FizzBuzz
{
private:
    int n;
    std::mutex m_mutex;
    std::condition_variable m_var;
    int m_val;
public:
    FizzBuzz(int n)
    {
        this->n = n;
        m_val = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        while (m_val <= n)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return ((m_val > n) || ((m_val % 3 == 0) && (m_val % 15 != 0))); });
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            if (m_val <= n) printFizz();
            m_val++;
            lock.unlock();
            m_var.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        while (m_val <= n)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return ((m_val > n) || ((m_val % 5 == 0) && (m_val % 15 != 0))); });
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            if (m_val <= n) printBuzz();
            m_val++;
            lock.unlock();
            m_var.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        while (m_val <= n)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return ((m_val > n) || (m_val % 15 == 0)); });
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            if (m_val <= n)	printFizzBuzz();
            m_val++;
            lock.unlock();
            m_var.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        while (m_val <= n)
        {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_var.wait(lock, [this]() {return ((m_val > n) || ((m_val % 3 != 0) && (m_val % 5 != 0))); });
            // releaseHydrogen() outputs "H". Do not change or remove this line.
            if (m_val <= n) printNumber(m_val);
            m_val++;
            lock.unlock();
            m_var.notify_all();
        }
    }
};

/// <summary>
/// Leet code #1226. The Dining Philosophers
/// Medium
///
/// Five silent philosophers sit at a round table with bowls of spaghetti. 
/// Forks are placed between each pair of adjacent philosophers.
///
/// Each philosopher must alternately think and eat. However, a philosopher 
/// can only eat spaghetti when they have both left and right forks. Each 
/// fork can be held by only one philosopher and so a philosopher can use 
/// the fork only if it is not being used by another philosopher. After an 
/// individual philosopher finishes eating, they need to put down both forks 
/// so that the forks become available to others. A philosopher can take 
/// the fork on their right or the one on their left as they become 
/// available, but cannot start eating before getting both forks.
/// Eating is not limited by the remaining amounts of spaghetti or stomach 
/// space; an infinite supply and an infinite demand are assumed.
///
/// Design a discipline of behaviour (a concurrent algorithm) such that no 
/// philosopher will starve; i.e., each can forever continue to alternate 
/// between eating and thinking, assuming that no philosopher can know when 
/// others may want to eat or think.
///
/// The problem statement and the image above are taken from wikipedia.org
///
/// 
/// The philosophers' ids are numbered from 0 to 4 in a clockwise order. 
/// Implement the function void wantsToEat(philosopher, pickLeftFork, 
/// pickRightFork, eat, putLeftFork, putRightFork) where:
///
/// philosopher is the id of the philosopher who wants to eat.
/// pickLeftFork and pickRightFork are functions you can call to pick the 
/// corresponding forks of that philosopher.
/// eat is a function you can call to let the philosopher eat once he has 
/// picked both forks.
/// putLeftFork and putRightFork are functions you can call to put down the 
/// corresponding forks of that philosopher.
/// The philosophers are assumed to be thinking as long as they are not asking 
/// to eat (the function is not being called with their number).
/// Five threads, each representing a philosopher, will simultaneously use one 
/// object of your class to simulate the process. The function may be called 
/// for the same philosopher more than once, even before the last call ends.
/// 
/// Example 1:
///
/// Input: n = 1
/// Output: [[4,2,1],[4,1,1],[0,1,1],[2,2,1],[2,1,1],[2,0,3],[2,1,2],[2,2,2],
/// [4,0,3],[4,1,2],[0,2,1],[4,2,2],[3,2,1],[3,1,1],[0,0,3],[0,1,2],[0,2,2],
/// [1,2,1],[1,1,1],[3,0,3],[3,1,2],[3,2,2],[1,0,3],[1,1,2],[1,2,2]]
/// Explanation:
/// n is the number of times each philosopher will call the function.
/// The output array describes the calls you made to the functions controlling 
/// the forks and the eat function, its format is:
/// output[i] = [a, b, c] (three integers)
/// - a is the id of a philosopher.
/// - b specifies the fork: {1 : left, 2 : right}.
/// - c specifies the operation: {1 : pick, 2 : put, 3 : eat}.
///
/// Constraints:
/// 1. 1 <= n <= 60
/// </summary>
class DiningPhilosophers
{
private:
    std::mutex m_mutex;
    std::condition_variable m_var;
    std::vector<int> m_forks;
public:
    DiningPhilosophers()
    {
        m_forks = std::vector<int>(5, 1);
    }

    void wantsToEat(int philosopher,
        function<void()> pickLeftFork,
        function<void()> pickRightFork,
        function<void()> eat,
        function<void()> putLeftFork,
        function<void()> putRightFork)
    {
        int left = (philosopher - 1 + 5) % 5;
        int right = (philosopher + 1) % 5;
        std::unique_lock<std::mutex> lock(m_mutex);

        if (philosopher % 2 == 0)
        {
            while (m_forks[left] != 1)
            {
                m_var.wait(lock);
            }
            m_forks[left] = 0;
            pickLeftFork();
            while (m_forks[right] != 1)
            {
                m_var.wait(lock);
            }
            m_forks[right] = 0;
            pickRightFork();
        }
        else
        {
            while (m_forks[right] != 1)
            {
                m_var.wait(lock);
            }
            m_forks[right] = 0;
            pickRightFork();
            while (m_forks[left] != 1)
            {
                m_var.wait(lock);
            }
            m_forks[left] = 0;
            pickLeftFork();
        }
        eat();
        putLeftFork();
        putRightFork();
        m_forks[left] = 1;
        m_forks[right] = 1;
        m_var.notify_all();
    }
};

/// <summary>
/// Leet code #1279. Traffic Light Controlled Intersection
///
/// Easy
///
/// There is an intersection of two roads. First road is road A where cars 
/// travel from North to South in direction 1 and from South to North in 
/// direction 2. Second road is road B where cars travel from West to East 
/// in direction 3 and from East to West in direction 4.
/// 
/// There is a traffic light located on each road before the intersection. 
/// A traffic light can either be green or red.
///
/// Green means cars can cross the intersection in both directions of the road.
/// Red means cars in both directions cannot cross the intersection and must 
/// wait until the light turns green.
/// The traffic lights cannot be green on both roads at the same time. That 
/// means when the light is green on road A, it is red on road B and when the 
/// light is green on road B, it is red on road A.
///
/// Initially, the traffic light is green on road A and red on road B. When 
/// the light is green on one road, all cars can cross the intersection in both 
/// directions until the light becomes green on the other road. No two cars 
/// traveling on different roads should cross at the same time.
///
/// Design a deadlock-free traffic light controlled system at this 
/// intersection.
///
/// Implement the function void carArrived(carId, roadId, direction, turnGreen, 
/// crossCar) where:
///
/// carId is the id of the car that arrived.
/// roadId is the id of the road that the car travels on.
/// direction is the direction of the car.
/// turnGreen is a function you can call to turn the traffic light to green on 
/// the current road.
/// crossCar is a function you can call to let the current car cross the 
/// intersection.
/// Your answer is considered correct if it avoids cars deadlock in the 
/// intersection. Turning the light green on a road when it was already green 
/// is considered a wrong answer.
/// 
/// Example 1:
///
/// Input: cars = [1,3,5,2,4], directions = [2,1,2,4,3], 
/// arrivalTimes = [10,20,30,40,50]
/// Output: [
/// "Car 1 Has Passed Road A In Direction 2",    
/// // Traffic light on road A is green, car 1 can cross the intersection.
/// "Car 3 Has Passed Road A In Direction 1",    
/// // Car 3 crosses the intersection as the light is still green.
/// "Car 5 Has Passed Road A In Direction 2",    
/// // Car 5 crosses the intersection as the light is still green.
/// "Traffic Light On Road B Is Green",          
/// // Car 2 requests green light for road B.
/// "Car 2 Has Passed Road B In Direction 4",    
/// // Car 2 crosses as the light is green on road B now.
/// "Car 4 Has Passed Road B In Direction 3"     
/// // Car 4 crosses the intersection as the light is still green.
/// ]
///
/// Example 2:
/// Input: cars = [1,2,3,4,5], directions = [2,4,3,3,1], 
/// arrivalTimes = [10,20,30,40,40]
/// Output: [
/// "Car 1 Has Passed Road A In Direction 2",    
/// // Traffic light on road A is green, car 1 can cross the intersection.
/// "Traffic Light On Road B Is Green",          
/// // Car 2 requests green light for road B.
/// "Car 2 Has Passed Road B In Direction 4",    
/// // Car 2 crosses as the light is green on road B now.
/// "Car 3 Has Passed Road B In Direction 3",    
/// // Car 3 crosses as the light is green on road B now.
/// "Traffic Light On Road A Is Green",          
/// // Car 5 requests green light for road A.
/// "Car 5 Has Passed Road A In Direction 1",    
/// // Car 5 crosses as the light is green on road A now.
/// "Traffic Light On Road B Is Green",          
/// // Car 4 requests green light for road B. Car 4 blocked 
/// // until car 5 crosses and then traffic light is green on road B.
/// "Car 4 Has Passed Road B In Direction 3"     
/// // Car 4 crosses as the light is green on road B now.
/// ]
/// Explanation: This is a dead-lock free scenario. Note that the scenario 
/// when car 4 crosses before turning light into green on road A and 
/// allowing car 5 to pass is also correct and Accepted scenario.
/// Constraints:
/// 1. 1 <= cars.length <= 20
/// 2. cars.length = directions.length
/// 3. cars.length = arrivalTimes.length
/// 4. All values of cars are unique
/// 5. 1 <= directions[i] <= 4
/// 6. arrivalTimes is non-decreasing
/// </summary>
class TrafficLight
{
private:
    std::mutex m_mutex;
    int m_road_green;

public:
    TrafficLight()
    {
        m_road_green = 1;
    }

    void carArrived(
        int carId,                   // ID of the car
        int roadId,                  // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        int direction,               // Direction of the car
        function<void()> turnGreen,  // Use turnGreen() to turn light to green on current road
        function<void()> crossCar    // Use crossCar() to make car cross the intersection
    )
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (roadId != m_road_green)
        {
            turnGreen();
            m_road_green = roadId;
        }
        crossCar();
    }
};

/// <summary>
/// Leet code #1242. Web Crawler Multithreaded
///
/// Medium
///
/// Given a url startUrl and an interface HtmlParser, implement a 
/// Multi-threaded web crawler to crawl all links that are under the 
/// same hostname as startUrl. 
///
/// Return all urls obtained by your web crawler in any order.
///
/// Your crawler should:
/// Start from the page: startUrl
/// Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
/// Do not crawl the same link twice.
/// Explore only the links that are under the same hostname as startUrl.
///
/// As shown in the example url above, the hostname is example.org. For 
/// simplicity sake, you may assume all urls use http protocol without any 
/// port specified. For example, the urls http://leetcode.com/problems and 
/// http://leetcode.com/contest are under the same hostname, while 
/// urls http://example.org/test and http://example.com/abc are not under 
/// the same hostname.
///
/// The HtmlParser interface is defined as such: 
///
/// interface HtmlParser {
///   // Return a list of all urls from a webpage of given url.
///   // This is a blocking call, that means it will do HTTP request and 
///   // return when this request is finished.
///   public List<String> getUrls(String url);
/// }
/// Note that getUrls(String url) simulates performing a HTTP request. You 
/// can treat it as a blocking function call which waits for a HTTP request 
/// to finish. It is guaranteed that getUrls(String url) will return the 
/// urls within 15ms.  Single-threaded solutions will exceed the time limit 
/// so, can your multi-threaded web crawler do better?
///
/// Below are two examples explaining the functionality of the problem, for 
/// custom testing purposes you'll have three variables urls, edges and 
/// startUrl. Notice that you will only have access to startUrl in your code, 
/// while urls and edges are not directly accessible to you in code.
/// 
/// Follow up:
/// Assume we have 10,000 nodes and 1 billion URLs to crawl. We will deploy 
/// the same software onto each node. The software can know about all the 
/// nodes. We have to minimize communication between machines and make sure each
/// node does equal amount of work. How would your web crawler design change?
/// What if one node fails or does not work?
/// How do you know when the crawler is done?
/// 
/// Example 1: 
/// Input:
/// urls = [
///  "http://news.yahoo.com",
///  "http://news.yahoo.com/news",
///  "http://news.yahoo.com/news/topics/",
///  "http://news.google.com",
///  "http://news.yahoo.com/us"
/// ]
/// edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
/// startUrl = "http://news.yahoo.com/news/topics/"
/// Output: [
///   "http://news.yahoo.com",
///   "http://news.yahoo.com/news",
///   "http://news.yahoo.com/news/topics/",
///   "http://news.yahoo.com/us"
/// ]
///
/// Example 2:
/// Input: 
/// urls = [
///   "http://news.yahoo.com",
///   "http://news.yahoo.com/news",
///   "http://news.yahoo.com/news/topics/",
///   "http://news.google.com"
/// ]
/// edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
/// startUrl = "http://news.google.com"
/// Output: ["http://news.google.com"]
/// Explanation: The startUrl links to all other pages that do not share the 
/// same hostname.
/// 
/// Constraints:
/// 1. 1 <= urls.length <= 1000
/// 2. 1 <= urls[i].length <= 300
/// 3. startUrl is one of the urls.
/// Hostname label must be from 1 to 63 characters long, 
/// including the dots, may contain only the ASCII letters from 'a' to 'z', 
/// digits from '0' to '9' and the hyphen-minus character ('-').
/// The hostname may not start or end with the hyphen-minus character ('-'). 
/// See:  https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames
/// You may assume there're no duplicates in url library.
/// </summary>
class HtmlParser {
public:
    vector<string> getUrls(string url)
    {
        return vector<string>();
    };
};
// TODO: leave it for future
vector<string> crawl(string startUrl, HtmlParser htmlParser)
{
    return vector<string>();
};
#endif // LeetcodeThread_H
