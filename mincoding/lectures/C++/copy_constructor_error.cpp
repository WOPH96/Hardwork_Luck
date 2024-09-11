#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class Person
{
public:
    char *name;
    int age;

    Person(const char *n, int a) : age{a}
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Person(const Person &p) : age{p.age}
    {
        // age = p.age;
        // name = p.name;
        name = new char[strlen(p.name) + 1];
        strcpy(name, p.name);
    }

    ~Person()
    {
        delete[] name;
        std::cout << "소멸자 호출" << std::endl;
    }
};

int main()
{
    // brace가 있는 이유는? 없는경우 main 함수가 종료되면서 소멸자가 호출되기 때문에 문제점을 볼수 없는 경우도 있음
    int c{0};
    std::cout << c << std::endl;
    Person p1("david", 30);
    Person p2{p1}; // 삭제가 이미 되었는데, 또 삭제하려고 하기 때문에 얕은 복사의 문제점 발생

    return 0;
}