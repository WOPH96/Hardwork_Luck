#include <iostream>

int main()
{

    int *ma = (int *)malloc(sizeof(int));
    *ma = 123;

    int *mb = new int;
    *mb = 456;

    std::cout << *ma << " " << *mb << std::endl;

    free(ma);
    delete mb;

    return 0;
}