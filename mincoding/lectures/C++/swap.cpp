#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 3, b = 4;
    double c = 3.14, d = 4.14;

    swap(a, b);
    swap(c, d);

    std::cout << a << " " << b << " ";
    std::cout << c << " " << d << " ";
    return 0;
}