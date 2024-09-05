#include <stdio.h>
int exo(int a, int b, int c)
{

    return a + b + c;
}
// typedef 삽입 후
typedef int (*exo_t)(int, int, int);

void sum(exo_t a)
{
    printf("%d", a(1, 2, 3));
}
int main()
{
    int (*fp2)(int, int, int);
    fp2 = exo;

    printf("%d", fp2(1, 2, 3));

    // typedef 삽입 후
    // typedef int (*exo_t)(int, int, int);

    exo_t fp3 = exo;

    printf("%d", fp3(1, 2, 3));

    sum(exo);
    return 0;
}