#include <stdio.h>

// 필요 변수 선언
char str[8];
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("18-5_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%s", str);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%s", str);

    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    printf("%s", str);
    return 0;
}
