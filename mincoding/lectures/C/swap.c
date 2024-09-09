#include <stdio.h>

typedef enum
{
    int_type,
    double_type

} type_t;

void swap(void *a, void *b, type_t type)
{
    int i_temp;
    double d_temp;

    switch (type)
    {
    case int_type:
        i_temp = *(int *)a;
        *(int *)a = *(int *)b;
        *(int *)b = i_temp;
        break;
    case double_type:
        d_temp = *(double *)a;
        *(double *)a = *(double *)b;
        *(double *)b = i_temp;
        break;
    }
}

int main()
{
    int a = 3, b = 4;
    double c = 3.14, d = 4.14;

    swap(&a, &b, int_type);
    swap(&c, &d, double_type);

    printf("%d %d", a, b);
    printf(" %lf %lf", c, d);
    return 0;
}