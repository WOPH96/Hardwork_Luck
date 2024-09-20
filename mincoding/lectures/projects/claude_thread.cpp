#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <atomic>
#include <random>
#include <cstdio>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#endif

#define TASK_COUNT 4
#define ONE_TASK_PERIOD 1000   // ms
#define TWO_TASK_PERIOD 2000   // ms
#define THREE_TASK_PERIOD 3000 // ms

std::mutex cout_mtx;
std::atomic<int> current_time{0};
std::condition_variable cv;
std::mutex cv_mtx;

#ifndef _WIN32
int kbhit()
{
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int getch()
{
    return getchar();
}
#endif

void print_time()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        current_time += 1000;
        {
            std::lock_guard<std::mutex> lock(cout_mtx);
            std::cout << "\n[" << current_time / 1000 << "] :";
            std::cout.flush();
        }
        cv.notify_all();
    }
}

void Task(const std::string &name, int period)
{
    int last_run = 0;
    while (true)
    {
        std::unique_lock<std::mutex> lock(cv_mtx);
        cv.wait(lock, [&]
                { return current_time - last_run >= period; });

        if (current_time - last_run >= period)
        {
            {
                std::lock_guard<std::mutex> cout_lock(cout_mtx);
                std::cout << name << "() ";
                std::cout.flush();
            }
            last_run = current_time;
        }
    }
}

void keyboard_input()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10); // 10% 확률로 키 입력을 처리

    while (true)
    {
        if (kbhit())
        {
            char c = getch();
            if (dis(gen) == 1) // 10% 확률로 키 입력을 처리
            {
                std::lock_guard<std::mutex> cout_lock(cout_mtx);
                std::cout << "pressed " << c << " ";
                std::cout.flush();
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main()
{
    std::vector<std::thread> threads;

    threads.emplace_back(print_time);
    threads.emplace_back(Task, "Task1", ONE_TASK_PERIOD);
    threads.emplace_back(Task, "Task2", TWO_TASK_PERIOD);
    threads.emplace_back(Task, "Task3", THREE_TASK_PERIOD);
    threads.emplace_back(keyboard_input);

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}