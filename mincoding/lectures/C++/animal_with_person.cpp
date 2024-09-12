#include <iostream>

class Pet
{
public:
    std::string name;
    virtual void bark() = 0;
    Pet(std::string _name) : name(_name) {}
};

class Dog : public Pet
{
public:
    Dog(std::string _name) : Pet{_name} {}
    virtual void bark()
    {
        std::cout << this->name << " 왈왈 ! " << std::endl;
    }
};

class Cat : public Pet
{
public:
    Cat(std::string _name) : Pet{_name} {}
    virtual void bark()
    {
        std::cout << this->name << " 야옹 ! " << std::endl;
    }
};

class Person
{
public:
    std::string name;
    int age;

    void play_with_pet(Pet *animal)
    {
        animal->bark();
    }
    Person(std::string _name, int _age) : name(_name), age(_age)
    {
    }
};

int main()
{

    Dog *d1 = new Dog("장군이");
    Cat *c1 = new Cat("첨지");

    Person me{"원필", 29};
    me.play_with_pet(d1);
    me.play_with_pet(c1);

    return 0;
}