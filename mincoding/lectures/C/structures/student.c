#include <stdio.h>

typedef struct
{
    char name[32];
    // union info
    // {
    //     int total[4];
    //     struct info
    //     {
    //         /* data */
    //     };
    // }
} student_t;

int main()
{
    char name[] = "asdf";
    char *ptr = "asdfqw";
    printf("%s, %s\n", name, ptr);
    return 0;
}