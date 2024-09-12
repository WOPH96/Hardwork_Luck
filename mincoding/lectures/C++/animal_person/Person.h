#ifndef __PERSON__H_
#define __PERSON__H_
#include "Pet.h"
#include <iostream>
class Person
{
public:
    std::string name;
    int age;

    void play_with_pet(Pet *animal);
    Person(std::string _name, int _age) : name(_name), age(_age)
    {
    }
};

#endif