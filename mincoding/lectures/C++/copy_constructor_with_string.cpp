#include <iostream>
#include <string>
// 임베디드 환경에선 string이 없는 컴파일러도 있음
// 즉 char 포인터를 사용해야 한다 !.. 알고 있어야해 !
class Person
{
public:
    int age;
    std::string name;

    Person(std::string _name, int _age)
        : age(_age), name(_name)
    {
        std::cout << "오버로딩 생성자" << std::endl;
    }
    Person(const Person &p)
        : age(p.age), name(p.name)
    {
        std::cout << "카피 생성자" << std::endl;
    }
};

int main()
{

    Person p1{"원필", 29};
    Person p2{p1};

    p2.name{"투필"};
    std::cout << p1.name << p2.name << std::endl;
    return 0;
}