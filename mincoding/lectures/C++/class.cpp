#include <iostream>

typedef struct
{
    int x;
    int y;

} point_t;

class Point
{
private:
    int x;
    int y;
    Point *result;

public:
    Point(int x = 0, int y = 0)
        : x(x), y(y)
    {
    }
    ~Point()
    {
        delete result;
    }
    friend std::ostream &operator<<(std::ostream &out, const Point &point)
    {
        out << "(" << point.x << "," << point.y << ")";
        return out;
    }
    Point *operator+(const Point &p2)
    {
        result = new Point(this->x + p2.x, this->y + p2.y);

        return result;
    }
    Point *operator-(const Point &p2)
    {
        result = new Point(this->x - p2.x, this->y - p2.y);

        return result;
    }
    Point *operator*(const Point &p2)
    {
        result = new Point(this->x * p2.x, this->y * p2.y);

        return result;
    }
    Point *operator/(const Point &p2)
    {
        result = new Point(this->x / p2.x, this->y / p2.y);

        return result;
    }
};

int main()
{

    point_t pt1;
    point_t pt2;

    pt1 = {11, 22};
    pt2 = {33, 34};

    std::cout << pt1.x << pt1.y << std::endl;

    Point pt3(1, 2);

    std::cout << pt3;

    std::cout << *(pt3 + pt3) << *(pt3 - pt3) << *(pt3 * pt3) << *(pt3 / pt3);

    return 0;
}