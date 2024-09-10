#include <iostream>
#include "class.h"
template <typename T>
class Shape
{

public:
    void draw()
    {
        std::cout << "도형을 그립니다." << std::endl;
    }
    virtual ~Shape() {}
    virtual T get_area() = 0;
};

template <typename T>
class Rect : public Shape
{
private:
    Point<T> p1, p2;

public:
    Rect(T x1, T y1, T x2, T y2)
        : p1(x1, y1), p2(x2, y2)
    {
    }
    virtual ~Rect()
    {
    }
    virtual T get_area()
    {
        // T res;
        // res = this->p1 - this->p2;
        return p1.x;
    }
};

int main()
{
    Rect<int> rect(1, 2, 3, 4);
    return 0;
}