#include <stdio.h>

// 필요 변수 선언
int datas[9];
int check[10] = {0};
void input_f()
{
    FILE *fp = fopen("18-2_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        fscanf(fp, "%d", &datas[i]);
        check[datas[i]] += 1;
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    int i = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &datas[i]);
        check[datas[i]] += 1;
    }

    // 변수 입력 공간
}

int main()
{

    // input_f();
    input();

    int i = 0;
    for (i = 1; i < 10; i++)
    {
        if (check[i] == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
