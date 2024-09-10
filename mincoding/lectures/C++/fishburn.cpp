#include <iostream>

class Fishbun
{

public:
    int cnt1;

    static int total;

    Fishbun() : cnt1{0}
    {
        ++cnt1;
        ++total;
    }
};

int Fishbun::total = 0;

int main()
{
    Fishbun f1;
    std::cout << f1.cnt1 << "," << Fishbun::total << std::endl;

    Fishbun f2;
    std::cout << f1.cnt1 << "," << Fishbun::total << std::endl;

    Fishbun f3;
    std::cout << f1.cnt1 << "," << Fishbun::total << std::endl;

    return (0);
}
