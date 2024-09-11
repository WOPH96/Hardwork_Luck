#include <iostream>
#include <string>
#include <vector>

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

    Animal *a1 = &d1; // 업캐스팅 ! 부모의 참조는 하위객체를 참조할 수 있다.

    a1->cry();

    a1 = &c1;
    a1->cry();

    std::vector<Animal *> animal_vect;
    animal_vect.push_back(&d1);
    animal_vect.push_back(&c1);
    for (int i = 0; i < animal_vect.size(); i++)
    {
        animal_vect[i]->cry();
    }
    Animal *a3;
    static_cast<Dog *>(a3)->cry();
    return 0;
}