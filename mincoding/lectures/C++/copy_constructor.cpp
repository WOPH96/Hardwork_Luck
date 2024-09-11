#include <iostream>

class Point
{
public:
    int x;
    int y;

    Point() : x{0}, y{0}
    { // (a)
        std::cout << "(a) 사용자가 오버로딩한 기본 생성자: Point()" << std::endl;
    }

    Point(int x, int y) // (b)
        : x{x}, y{y}
    {
        std::cout << "(b) 사용자가 오버로딩한 생성자: Pint(int, int)" << std::endl;
    }

    Point(const Point &p) : x{p.x}, y{p.x} // (c)
    {
        std::cout << "(c) 복사 생성자" << std::endl;
    }
};

void bts(Point p)
{ // (2)
    std::cout << "**********" << std::endl;
}

void exo(const Point &p)
{
    std::cout << "@@@@@@@@@@" << std::endl;
}

Point aoa(Point &p)
{
    return p;
}

Point &xyz(Point &p)
{
    return p; // 참조를 반환하면 리턴용 임시 객체가 생성되지 않는다.
}

int main()
{
    Point p1;
    std::cout << "----------" << std::endl;
    bts(p1); // call by value로 전달하기 때문에, 복사 생성자가 호출된다.
    std::cout << "----------" << std::endl;

    exo(p1);
    // ses(p1);

    // hot(p1);
    aoa(p1);
    xyz(p1);
    return 0;
}