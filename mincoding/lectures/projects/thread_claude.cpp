#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <functional>

#define TASK_COUNT 4
#define ONE_TASK_PERIOD (1000)   // ms
#define TWO_TASK_PERIOD (2000)   // ms
#define THREE_TASK_PERIOD (3000) // ms

std::mutex mtx;
std::condition_variable cv_task; //,cv_timer;
int current_time = 0;
bool time_printed = false;
int tasks_completed = 0;

void timer_thread()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        {
            std::lock_guard<std::mutex> lock(mtx);
            current_time += 1000;
        }
        // cv_timer.notify_all();
    }
}

void print_time()
{
    // int last_print_time = 0;
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(mtx);

            std::cout << "[" << current_time / 1000 << "] :";
            // last_print_time = current_time;
            time_printed = true;
            tasks_completed = 0;
        }
        cv_task.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << std::endl;
        time_printed = false;
    }
}

void task(const std::string &name, int period)
{
    int last_run_time = 0;
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv_task.wait(lock, [&]
                     { return time_printed; });
        if (current_time >= last_run_time + period)
        {
            std::cout << name << "() ";
            last_run_time = current_time;
        }
    }
}

int main()
{
    std::vector<std::thread> threads;

    threads.emplace_back(timer_thread);
    threads.emplace_back(print_time);
    threads.emplace_back(task, "Task1", ONE_TASK_PERIOD);
    threads.emplace_back(task, "Task2", TWO_TASK_PERIOD);
    threads.emplace_back(task, "Task3", THREE_TASK_PERIOD);

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}