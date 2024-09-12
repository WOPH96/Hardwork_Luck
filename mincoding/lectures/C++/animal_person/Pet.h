#ifndef __PET__H_
#define __PET__H_
#include <iostream>
class Pet
{
public:
    std::string name;
    virtual void bark() = 0;
    Pet(std::string _name) : name(_name) {}
};
#endif