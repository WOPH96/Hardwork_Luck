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
bool printed = false;
void print(const char *name, const int &dtime)
{
    static int time_s = 1;
    while (true)
    {
        std::unique_lock<std::mutex> lock(m);
        std::cout << "[" << time_s << "] :";
        printed = true;
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(dtime));
        std::cout << std::endl;
        time_s++;
        printed = false;
    }
}
void Task(const char *name, const int &dtime)
{

    while (true)
    {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, []
                { return printed; });
        std::cout << name << "() ";
        std::this_thread::sleep_for(std::chrono::milliseconds(dtime));
    }
}

int main()
{
    void (*fp_arr[TASK_COUNT])(const char *name, const int &) = {
        print, Task, Task, Task};

    int delay_ms_time[TASK_COUNT] = {
        1000, ONE_TASK_PERIOD, TWO_TASK_PERIOD, THREE_TASK_PERIOD};
    char *names[TASK_COUNT] = {
        " ", "ONE", "TWO", "THREE"};

    std::thread threads[TASK_COUNT];

    for (int i = 0; i < TASK_COUNT; i++)
    {
        threads[i] = std::thread(fp_arr[i], names[i], std::ref(delay_ms_time[i]));
    }
    for (int i = 0; i < TASK_COUNT; i++)
    {
        threads[i].join();
    }

    return 0;
}