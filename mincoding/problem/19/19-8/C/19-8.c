#include <stdio.h>

// 필요 변수 선언
int images[4][4];
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("19-8_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fscanf(fp, "%d ", &images[i][j]);
        }
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d ", &images[i][j]);
        }
    }

    // 변수 입력 공간
}
int rectsum(int y, int x);
int main()
{
    // input_f();
    input();
    // check

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ", images[i][j]);
    //     }
    //     printf("\n");
    // }
    int max = -999;
    int find_x, find_y;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int res = rectsum(i, j);
            if (res > max)
            {
                max = res;
                find_y = i;
                find_x = j;
            }
        }
    }
    printf("(%d,%d)", find_y, find_x);
    return 0;
}

int rectsum(int y, int x)
{
    int sum = 0;
    for (int i = y; i < y + 2; i++)
    {
        for (int j = x; j < x + 3; j++)
        {
            if (0 <= i && i < 4 && 0 <= j && j < 4)
            {
                sum += images[i][j];
            }
        }
    }
    return sum;
}