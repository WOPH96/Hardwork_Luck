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
    auto p1 = std::make_unique<Book>("aaa");
    std::cout << p1->getTitle() << std::endl;
    ;

    auto p2 = std::make_shared<Book>("bbb");
    auto p3 = p2;
    auto p4 = p2;

    std::cout << p2->getTitle() << std::endl;

    std::cout << p3->getTitle() << std::endl;

    std::cout << p4->getTitle() << std::endl;

    std::cout << p4.use_count() << std::endl;

    return (0);
}