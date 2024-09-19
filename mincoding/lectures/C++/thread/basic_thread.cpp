#include <iostream>
#include <thread>

void bts()
{
    for (int i = 0; i < 100; i++)
        std::cout << "bts  :" << std::endl;
}
void exo()
{
    for (int i = 0; i < 100; i++)
        std::cout << "exo  :" << std::endl;
}

int main()
{

    std::cout << "thread started" << std::endl;
    std::thread th1(bts); // or &bts 펑션 주소 보내기
    std::thread th2(exo); // or &exo
    th1.join();           // thread 스탑
    th2.join();
    // thread 실행 순서를 예측할 수 없다
    std::cout << "thread teminated" << std::endl;

    // atomic operation이 안되어서 그럼..?

    return 0;
}