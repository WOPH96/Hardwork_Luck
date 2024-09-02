#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    for (; num >= 0; num--)
        printf("%d", num);
    return 0;
}
