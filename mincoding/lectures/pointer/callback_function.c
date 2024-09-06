#include <stdio.h>
#include <stdlib.h>
typedef void (*sum_fp)(int *, int *);

int sum(int a, int b, sum_fp fp)
{
    int sum = 0;
    if (fp != NULL)
    {
        (*fp)(&a, &b);
        // fp(&a, &b); // 둘다 동일함
    }

    return a + b;
}

void user_defined_sum(int *a, int *b)
{
    *a = abs(*a);
    *b = abs(*b);
}

int main()
{
    int S1 = sum(1, -2, NULL);
    int S2 = sum(1, -2, user_defined_sum);
    // int S2 = sum(1, -2, &user_defined_sum); // 둘다 된다!
    printf("%d, %d \n", S1, S2);
    return 0;
}