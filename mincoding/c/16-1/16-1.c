#include <stdio.h>
#include <string.h>
/*MINCODING
APPLE
SKTOWN*/
int main()
{
    char strs[3][10];
    int i;
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", strs[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%c", strs[i][strlen(strs[i]) - 1]);
    }

    return 0;
}
