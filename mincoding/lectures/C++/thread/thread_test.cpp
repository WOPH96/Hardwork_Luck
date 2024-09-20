#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void add_n(int n, int m, int &counter, std::mutex &mtx)
{
    for (int i = 0; i < m; i++)
    {
        std::lock_guard<std::mutex> lock_guard(mtx);
        counter += n;
    }
}

int main()
{
    int counter = 0;
    std::vector<std::thread> threads;
    std::mutex m;
    threads.emplace_back(add_n, 1, 100, std::ref(counter), std::ref(m));
    threads.emplace_back(add_n, 2, 80, std::ref(counter), std::ref(m));
    threads.emplace_back(add_n, 3, 50, std::ref(counter), std::ref(m));

    for (auto &t : threads)
    {
        t.join();
    }

    std::cout << counter << std::endl;
    return 0;
}