#include <iostream>

template <typename T>
T square(T a)
{
    return a * a;
}

int main()
{

    double r1 = square<int>(4.0);

    std::cout << r1 << std::endl;

    return 0;
}