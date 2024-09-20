#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#define TASK_COUNT (4)
#define ONE_TASK_PERIOD (1000)   // ms
#define TWO_TASK_PERIOD (2000)   // ms
#define THREE_TASK_PERIOD (3000) // ms

std::mutex m;
std::condition_variable cv;
void print(const int &dtime)
{
    static int time_s = 1;
    while (true)
    {
        std::cout << "[" << time_s << "] :";
        std::this_thread::sleep_for(std::chrono::milliseconds(dtime));

        std::cout << std::endl;
        time_s++;
    }
}
void Task1(const int &dtime)
{

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(dtime));
        std::cout << "Task1() ";
    }
}
void Task2(const int &dtime)
{
    // std::cout << "Task2()" << std::endl;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(dtime));
        std::cout << "Task2() ";
    }
}
void Task3(const int &dtime)
{
    // std::cout << "Task3()" << std::endl;
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(dtime));
        std::cout << "Task3() ";
    }
}

int main()
{
    void (*fp_arr[TASK_COUNT])(const int &) = {
        print, Task1, Task2, Task3};

    int delay_ms_time[TASK_COUNT] = {
        1000, ONE_TASK_PERIOD, TWO_TASK_PERIOD, THREE_TASK_PERIOD};

    std::thread threads[TASK_COUNT];

    for (int i = 0; i < TASK_COUNT; i++)
    {
        threads[i] = std::thread(fp_arr[i], std::ref(delay_ms_time[i]));
    }
    for (int i = 0; i < TASK_COUNT; i++)
    {
        threads[i].join();
    }

    return 0;
}