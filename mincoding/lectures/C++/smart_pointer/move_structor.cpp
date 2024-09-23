#include <iostream>
#include <string>

class Point
{
public:
    int x;
    int y;

    Point() : x{0}, y{0}
    {
        std::cout << "기본 생성자" << std::endl;
    }

    Point(int x, int y) : x{x}, y{y}
    {
        std::cout << "일반 생성자" << std::endl;
    }

    // Point(const Point& other) : x{ other.x }, y{ other.y } {
    //     std::cout << "복사 생성자" << std::endl;
    // }

    Point(const Point &) = delete;
    Point &operator=(const Point &) = delete;

    Point(const Point &&rhs) noexcept : x{rhs.x}, y{rhs.y}
    {
        std::cout << "이동 생성자" << std::endl;
    }

    ~Point()
    {
        // std::cout << "소멸자" << std::endl;
    }
};

int main(void)
{
    Point pt1;         // (1) 기본 생성자 호출됨
    Point pt2{11, 22}; // (2) 일반 생성자 호출됨

    // Point pt3= pt1; // (3) 복사 생성자 호출됨
    // Point pt4(pt1); // (4) 복사 생성자 호출됨
    Point pt5 = std::move(pt1); // (5) 일반 생성자.. 복사 생성자?
    return (0);
}