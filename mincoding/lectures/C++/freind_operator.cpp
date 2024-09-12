#include <iostream>

class Point
{

private:
    int x;
    int y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point operator+(const Point &other)
    {
        return Point{this->x + other.x, this->y + other.y};
    }
    Point operator-(const Point &other)
    {
        return Point{this->x - other.x, this->y - other.y};
    }
    friend Point operator/(const Point &p1, const Point &p2);
    friend Point operator*(const Point &p1, const Point &p2);

    friend std::ostream &operator<<(std::ostream &out, const Point &p1);
};

Point operator/(const Point &p1, const Point &p2)
{
    return Point{p1.x / p2.x, p1.y / p2.y};
}

Point operator*(const Point &p1, const Point &p2)
{
    return Point{p1.x * p2.x, p1.y * p2.y};
}

std::ostream &operator<<(std::ostream &out, const Point &p1)
{
    out << "Point(" << p1.x << "," << p1.y << ")";
    return out;
}
int main()
{
    Point p1{1, 2};
    Point p2{3, 4};

    std::cout << p1 + p2 << std::endl;
    std::cout << p1 - p2 << std::endl;
    std::cout << p1 / p2 << std::endl;
    std::cout << p1 * p2 << std::endl;

    return 0;
}