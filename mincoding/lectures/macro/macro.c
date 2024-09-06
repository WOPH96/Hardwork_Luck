#include <stdio.h>

void exo()
{
    printf("%s \n", __FUNCTION__);
}

void bts()
{

    printf("%s \n", __FUNCTION__);
}
typedef void (*void_fp)(void);
int main()
{

    void_fp vfp;

    vfp = bts;

    vfp();

    return (0);
}