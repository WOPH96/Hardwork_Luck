#include <stdio.h>

int main()
{
    char *ptr_str = "abcd"; // 상수형 포인터 "abcd"
    char arr_str[] = "exo";
    // *(ptr_str + 1) = 'x';

    printf("str1= %s\n", ptr_str);
    printf("str2= %s\n", arr_str);

    arr_str[0] = 's';
    arr_str[1] = 'e';

    printf("str2= %s\n", arr_str);

    *(ptr_str + 1) = 'x';

    printf("str1= %s\n", ptr_str);
    return (0);
}