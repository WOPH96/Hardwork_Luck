#include <stdio.h>

void exo(int a) { printf("%s", __FUNCTION__); };

typedef void (*fp_t)(int);

int main()
{

    fp_t fp = exo;
    // fp_t fp = &exo;

    exo(3);

    return 0;
}