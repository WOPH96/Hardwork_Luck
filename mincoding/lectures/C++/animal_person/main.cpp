#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Person.h"

int main()
{

    Dog *d1 = new Dog("장군이");
    Cat *c1 = new Cat("첨지");

    Person me{"원필", 29};
    me.play_with_pet(d1);
    me.play_with_pet(c1);

    return 0;
}