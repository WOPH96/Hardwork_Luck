#include <iostream>

class IPhone
{
public:
    virtual ~IPhone() {}
    virtual void call() = 0; // (1) 전화기란 전화기는 모두 이 규칙을 따르게 강제 하겠다.
};

class Phone : public IPhone
{ // (2) IPhone 규칙을 지키기만 하면 된다.
public:
    void call()
    {
        std::cout << "전화를 걸다." << std::endl;
    }
};

class MobilePhone : public Phone
{
public:
    void call()
    {
        std::cout << "무선 전화를 걸다." << std::endl;
    }
};

class SmartPhone : public IPhone
{
public:
    void call()
    {
        std::cout << "영상 전화를 걸다." << std::endl;
    }
};

class Person
{
public:
    // void make(Phone* phone) {
    void make(IPhone *phone)
    { // (3) 구체적인 클래스가 아닌 추상 클래스 포인터를 받는다.
        phone->call();
    }
};

int main()
{
    Person person;
    Phone phone;
    person.make(&phone);

    MobilePhone mobile;
    person.make(&mobile);

    SmartPhone smart;
    person.make(&smart);

    return (0);
}