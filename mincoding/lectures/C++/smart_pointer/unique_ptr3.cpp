#include <iostream>
#include <memory>
#include <typeinfo>

class Book
{
public:
    std::string str;
    Book(std::string str) : str{str}
    {
        // std::cout << "생성자 호출" << std::endl;
    }
    ~Book()
    {
        // std::cout << "소멸자 호출" << std::endl;
    }
    std::string getTitle()
    {
        return this->str;
    }
};

void printBook(Book book)
{ // (1) error! 안돼!
    std::cout << book.getTitle() << std::endl;
}

void printBook(Book &book)
{ // (2) error! 타입이 안맞아!
    std::cout << book.getTitle() << std::endl;
}

void printBook(std::unique_ptr<Book> &book)
{ // ok!
    std::cout << book->getTitle() << std::endl;
}

int main()
{
    auto p1 = std::make_unique<Book>("aaa");
    // std::cout << p1->getTitle() << std::endl;
    printBook(p1);

    return (0);
}