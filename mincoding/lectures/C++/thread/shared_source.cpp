#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void worker(int &counter, std::mutex &m)
{
    for (int i = 0; i < 10000; i++)
    {
        m.lock();
        counter += 1;
        m.unlock();
    }
}

int main()
{
    int counter = 0;
    std::mutex m;

    std::thread w1(worker, std::ref(counter), std::ref(m));
    std::thread w2(worker, std::ref(counter), std::ref(m));
    std::thread w3(worker, std::ref(counter), std::ref(m));

    // std::thread w1(worker, (counter), (m));
    // std::thread w2(worker, (counter), (m));
    // std::thread w3(worker, (counter), (m)); // 오류! 함수 pass by ref 로 쓸땐 ref로 감싸서 보내기

    w1.join();
    w2.join();
    w3.join();

    std::cout << "counter : " << counter << std::endl;
}