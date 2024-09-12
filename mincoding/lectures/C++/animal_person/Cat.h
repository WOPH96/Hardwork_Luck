#ifndef __CAT__H_
#define __CAT__H_
#include "Pet.h"
class Cat : public Pet
{
public:
    Cat(std::string _name) : Pet{_name} {}
    virtual void bark();
};
#endif