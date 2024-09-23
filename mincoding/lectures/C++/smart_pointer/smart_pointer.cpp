#include <iostream>

class Book
{
public:
    std::string str;
    Book(std::string str) : str{str}
    {
        std::cout << "생성자 호출" << std::endl;
    }
    ~Book()
    {
        std::cout << "소멸자 호출" << std::endl;
    }
};

template <typename T>
class MySmartPointer
{
    T *ptrT;
    int *ref;

public:
    MySmartPointer(T *ptr = nullptr) : ptrT(ptr), ref{new int(1)} {}
    MySmartPointer(const MySmartPointer &p) : ptrT(p.ptrT)
    {
        this.ref = p.ref;
        ++(*this.ref);
    }
    ~MySmartPointer()
    {
        if (--(*ref) == 0)
        {
            delete ptrT;
            delete ref;
        }
    }

    T *operator->() { return ptrT; }
    T &operatr() { return *ptrT; }
};

int main(void)
{
    // Book* b1 = new Book("abc");
    // delete (b1);
    MySmartPointer<Book> b2 = new Book("def");
    MySmartPointer<Book> b3 = new Book("def");
    b3 = b2;
    std::cout << b2->str << std::endl;
    std::cout << b3->str << std::endl;

    return 0;
}