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
    // Book* pBook1 = new Book("aaa");
    // Book* pBook2 = new Book("bbb");

    std::unique_ptr<Book> pBook1 = std::make_unique<Book>("xxx");
    std::unique_ptr<Book> pBook2 = std::make_unique<Book>("yyy");

    std::cout << pBook1->getTitle() << std::endl;
    std::cout << pBook2->getTitle() << std::endl;

    std::cout << std::hex << std::uppercase << pBook1.get() << std::endl; // (1) 주소 내놔

    pBook1.reset(); // (2) 메모리 해제하면..재할당 할수 있다.
    pBook1 = std::make_unique<Book>("zzz");
    std::cout << pBook1->getTitle() << std::endl;

    Book *nBook = pBook1.release(); // (3) 평범한 포인터로 돌아가랏!
    // pBook1의 소유권은 nbook에게 넘어간다.
    // std::cout << pBook1->getTitle() << std::endl; // error
    std::cout << nBook->getTitle() << std::endl;

    // (4) 교환도 된다.
    std::unique_ptr<Book> pBook3 = std::make_unique<Book>("aaa");
    std::unique_ptr<Book> pBook4 = std::make_unique<Book>("bbb");
    pBook3.swap(pBook4);
    std::cout << pBook3->getTitle() << std::endl;
    std::cout << pBook4->getTitle() << std::endl;

    return (0);
}