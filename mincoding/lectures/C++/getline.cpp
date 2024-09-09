#include <iostream>
#include <string>

int main()
{

    std::string name;
    std::cout << "이름 입력 :";
    getline(std::cin, name);
    std::cout << name << std::endl;

    return 0;
}