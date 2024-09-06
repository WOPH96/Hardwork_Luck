#include <stdio.h>
#define print_func_name (printf("%s%s\r\n", __func__, "()"))

void zero() { print_func_name; }
void one() { print_func_name; }
void two() { print_func_name; }
void three() { print_func_name; }
void four() { print_func_name; }
void five() { print_func_name; }
void six() { print_func_name; }
void seven() { print_func_name; }
void eight() { print_func_name; }
void nine() { print_func_name; }

int main()
{
    char key;
    printf("0~9사이 숫자 입력: ");
    scanf("%c", &key);

    void (*fp_arr[10])() = {
        zero, one, two, three, four, five, six, seven, eight, nine};
    unsigned int index = (unsigned int)(key - 0x30);
    (*fp_arr[index])();
    return 0;
}