#include <stdio.h>

// 필요 변수 선언
int MAP[3][3] = {
    {3, 5, 1},
    {3, 8, 1},
    {1, 1, 5}};

int masking[2][2];
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("19.5-7_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fscanf(fp, "%d ", &masking[i][j]);
        }
    }
    //

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%d ", &masking[i][j]);
        }
    }

    // 변수 입력 공간
}
int masked_sum(int i, int j);
int main()
{
    // input_f();
    input();

    // 마스킹 좌표 의미 - 0,0 = 그대로 0,1 -> 좌표에서 0/ +1
    int max = -999;
    int y, x;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int res = masked_sum(i, j);
            if (res > max)
            {
                max = res;
                y = i;
                x = j;
            }
        }
    }

    printf("(%d,%d)", y, x);

    return 0;
}

int masked_sum(int y, int x)
{
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (masking[i][j] == 1)
            {
                // printf("(%d,%d)", y + i, x + j);
                if (0 <= (y + i) && (y + i) < 3 && 0 <= (x + j) && (x + j) < 3)
                    sum += MAP[y + i][x + j];
            }
        }
    }
    // printf("%d\n", sum);
    return sum;
}