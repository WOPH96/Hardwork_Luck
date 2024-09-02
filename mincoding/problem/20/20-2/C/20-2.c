#include <stdio.h>

// 필요 변수 선언
int start;
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("20-2_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &start);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d ", &start);

    // 변수 입력 공간
}

void print(int num)
{
    if (num == 0)
    {
        printf("%d ", num);
        return;
    }
    printf("%d ", num);
    print(num - 1);
    printf("%d ", num);
}

int main()
{
    input_f();
    // input();

    // printf("%d", start);

    print(start);

    return 0;
}
