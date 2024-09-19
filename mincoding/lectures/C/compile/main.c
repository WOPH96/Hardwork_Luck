#include <stdio.h>
// #include <stdlib.h>
#include "hive.h"
#include "sm.h"

#define PAI (3.14)

int main(void)
{
    int result = 0;
    int r2 = PAI * PAI;

    result = bts(11);
    printf("%d\r\n", result);

    return (0);
}