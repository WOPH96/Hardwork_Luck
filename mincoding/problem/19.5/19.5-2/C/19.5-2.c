#include <stdio.h>

// 필요 변수 선언
int arr[5][4];
typedef struct
{
    int y;
    int x;
} pos;
pos pos_of_1[20];
int one_count = 0;
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("19.5-2_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fscanf(fp, "%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                pos_of_1[one_count].y = i;
                pos_of_1[one_count++].x = j;
            }
        }
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1)
            {
                pos_of_1[one_count].y = i;
                pos_of_1[one_count++].x = j;
            }
        }
    }

    // 변수 입력 공간
}
int check(int, int);
int main()
{
    // input_f();
    input();

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (check(arr[i][j]))
    //         {
    //             printf("불안정한 상태");
    //             return 0;
    //         }
    //     }
    // }

    for (int i = 0; i < one_count; i++)
    {
        if (check(pos_of_1[i].y, pos_of_1[i].x))

        {
            printf("불안정한 상태");
            return 0;
        }
        // printf("(%d,%d)\n", pos_of_1[i].y, pos_of_1[i].x);
    }
    printf("안정된 상태");

    return 0;
}

int check(int y, int x)
{
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, -1, 1, 1, -1, 1, -1};
    for (int i = 0; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < 5 && 0 <= nx && nx < 4)
        {
            if (arr[ny][nx])
                return 1;
        }
    }
    return 0;
}