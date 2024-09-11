#include <iostream>
using namespace std;

class Base
{
    int result;

public:
    virtual void dynamic_binding(int x, int y);
    void static_binding(int x, int y);
};
void Base::dynamic_binding(int x, int y)
{
    result = x + y;
    cout << "Base dynamic bind 결과 : " << result << endl;
}
void Base::static_binding(int x, int y)
{
    result = x + y;
    cout << "Base static bind 결과 : " << result << endl;
}

class Derived : public Base
{
    int result;

public:
    virtual void dynamic_binding(int x, int y);
    void static_binding(int x, int y);
};
void Derived ::dynamic_binding(int x, int y)
{
    result = x - y;
    cout << "Derived dynamic bind 결과 : " << result << endl;
}
void Derived ::static_binding(int x, int y)
{
    result = x - y;
    cout << "Derived static bind 결과 : " << result << endl;
}

int main()
{
    Base *s = new Base();
    Base *d = new Derived();

    s->dynamic_binding(1, 5);
    s->static_binding(2, 7);

    d->dynamic_binding(1, 5);
    d->static_binding(2, 7);

    delete s;
    delete d;
}
