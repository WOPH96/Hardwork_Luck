#include <stdio.h>

// 필요 변수 선언
int target[3];
int vect[3][3] = {
    {3, 7, 4},
    {2, 2, 4},
    {2, 2, 5}};

// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("17-9_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    for (int i = 0; i < 3; i++)
    {
        fscanf(fp, "%d", &target[i]);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &target[i]);
    }

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%d", target[i]);
    // }
    int dt[10] = {0};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dt[vect[i][j]]++;
        }
    }
    int max = -1;
    int maxidx = 0;
    for (int i = 0; i < 3; i++)
    {
        if (target[i] > max)
        {
            max = target[i];
            maxidx = i;
        }
    }
    printf("%d", maxidx);
    return 0;
}
