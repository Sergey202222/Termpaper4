#include "thread_pool.hpp"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void test_funck1()
{
    std::cout << "It is a test_func1, Sergey\n";
}

void test_funck2()
{
    std::cout << "It is a test_func2, Sergey\n";
}

int test_funck3()
{
    std::cout << "It is a test_func3, Sergey\n";
    return 0;
}

void test_funck4()
{
    std::cout << "It is a test_func4, Sergey\n";
}

int main()
{
    thread_pool thp;
    std::packaged_task<void()> task1(test_funck1);
    std::packaged_task<void()> task2(test_funck2);
    std::packaged_task<void()> task3(test_funck3);
    std::packaged_task<void()> task4(test_funck4);
    thp.submit(std::move(task1));
    thp.submit(std::move(task2));
    std::this_thread::sleep_for(1s);
    thp.submit(std::move(task3));
    thp.submit(std::move(task4));
    
    return EXIT_SUCCESS;
}