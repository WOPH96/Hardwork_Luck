#ifndef __DOG__H_
#define __DOG__H_
#include "Pet.h"
class Dog : public Pet
{
public:
    Dog(std::string _name) : Pet{_name} {}
    virtual void bark();
};
#endif