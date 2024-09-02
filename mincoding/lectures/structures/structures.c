#include <stdio.h>

typedef struct
{
    int a;
    int b;
} sw;
void bbq(int a, int b)
{

    printf("%d %d", a, b);
}

void bbq_sw(sw test)
{
    printf("%d %d\n", test.a, test.b);
}

void swap(sw *test)
{
    int temp;
    temp = test->a;
    test->a = test->b;
    test->b = temp;
}
int main()
{

    sw test;
    test.a = 3;
    test.b = 5;

    // bbq(test.a, test.b);
    bbq_sw(test);
    swap(&test);
    bbq_sw(test);

    return 0;
}