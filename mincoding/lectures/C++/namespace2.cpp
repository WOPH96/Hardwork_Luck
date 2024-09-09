#include <iostream>

int main()
{

    using integer = int;
    integer asdf = 15;
    std::cout << asdf << std::endl;
    std::cout << "16진수 출력" << std::hex << asdf << std::endl;
    std::cout << asdf << std::endl;
    std::cout << std::dec << asdf << std::endl;

    return 0;
}