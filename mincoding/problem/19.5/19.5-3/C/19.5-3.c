#include <stdio.h>

// 필요 변수 선언
int nums[4];
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("19.5-3_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    for (int i = 0; i < 4; i++)
    {
        fscanf(fp, "%d ", &nums[i]);
    }
    //

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    for (int i = 0; i < 4; i++)
    {
        scanf("%d ", &nums[i]);
    }

    // 변수 입력 공간
}

int space[4][4] = {0};

void fill_order();

int main()
{
    // input_f();
    input();

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%d ", nums[i]);
    // }

    fill_order();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", space[i][j]);
        printf("\n");
    }

    return 0;
}

void fill_order()
{

    // 3 = 3-1/4, 3%4+3 -1
    // 10 = (10-1)/4 , ((10-1)%4
    int order = 1;
    for (int i = 0; i < 4; i++)
    {
        int y = (int)((nums[i] - 1) / 4);
        int x = (int)((nums[i] - 1) % 4);
        space[y][x] = order++;
    }
}
