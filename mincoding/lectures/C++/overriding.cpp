#include <iostream>
#include <string>

class Animal
{
public:
    std::string name;
    int age;
    Animal(std::string _n, int _age)
        : name(_n), age(_age)
    {
    }
    virtual void cry() = 0;
};

class Dog : public Animal
{

public:
    Dog(std::string _n, int _age) : Animal{_n, _age} {}
    virtual void cry()
    {
        std::cout << "멍멍!" << std::endl;
    }
};

class Cat : public Animal
{

public:
    Cat(std::string _n, int _age) : Animal{_n, _age} {}
    virtual void cry()
    {
        std::cout << "야옹!" << std::endl;
    }
};

int main()
{

    Dog d1{"바둑이", 1};
    d1.cry();

    Cat c1{"나비", 2};
    c1.cry();

    return 0;
}