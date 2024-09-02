#include <stdio.h>
#include <math.h>
// 필요 변수 선언

// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("19.5-1_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    // fscanf(fp, "%d ", &num1);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);

    // 변수 입력 공간
}

int bbq(int *a, int *b)
{
    *a = -1 * (int)pow(10, 10);
    *b = (int)pow(10, 10);
    for (int i = 0; i < 5; i++)
    {
        int num;
        scanf("%d", &num);
        if (num > *a)
        {
            *a = num;
        }
        if (num < *b)
            *b = num;
    }
}

int main()
{
    // input_f();
    // input();
    int a, b;
    bbq(&a, &b);
    printf("a=%d\nb=%d", a, b);
    return 0;
}
