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

int main()
{
    Book *book = new Book("aaa");

    std::unique_ptr<Book> pBook1(book);
    std::unique_ptr<Book> pBook2(book);
    std::unique_ptr<Book> pBook3(book);

    std::cout << pBook1->getTitle() << std::endl;
    std::cout << pBook2->getTitle() << std::endl;
    std::cout << pBook3->getTitle() << std::endl;

    return (0);
}