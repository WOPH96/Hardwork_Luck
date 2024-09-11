#include <iostream>

class Person
{
public:
    std::string major;
    std::string name;
    int age;
    // int phone_number;
    Person(std::string _major, std::string _name, int _age)
        : major(_major), name(_name), age(_age)
    {
    }
};

class Student : public Person
{
public:
    int number;
    Student(std::string _major, int _cn, std::string _name, int _age)
        : Person(_major, _name, _age), number(_cn)
    {
    }
};

class Processer : public Person
{
public:
    int grade;
    Processer(std::string _major, int _gr, std::string _name, int _age)
        : Person(_major, _name, _age), grade(_gr) {}
};

int main()
{
    Student s1{"computer", 12, "정상훈", 22};
    Processer p1{"history", 1, "정예림", 33};
    std::cout << s1.major << "," << s1.number << "," << s1.name << "," << s1.age << std::endl;
    std::cout << p1.major << "," << p1.grade << "," << p1.name << "," << p1.age << std::endl;
    return (0);
}