
#include <iostream>
#include <memory>
#include <typeinfo>

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
    std::string getTitle()
    {
        return this->str;
    }
};

int main()
{
    auto p1 = std::make_unique<Book>("aaa"); // 소유권이 하나만 생기게끔
    std::cout << p1->getTitle() << std::endl;

    // auto p2 = p1; // (1) 복사 불가능, 소유권이 여러개 생기기 때문이다.

    auto p2 = move(p1); // (2) move로는 가능, p1의 소유권은 사라진다.
    // std::cout << p1->getTitle() << std::endl; // (3) p1 접근 불가!
    std::cout << p2->getTitle() << std::endl;

    return (0);
}