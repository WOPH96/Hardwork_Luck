#include <stdio.h>

int main()
{

    // int num;
    // scanf("%d", &num);

    int vect[7] = {1, 6, 5, 98, 3, 1, 5};
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        sum += vect[i];
    }

    printf("%d ", sum);

    return 0;
}
