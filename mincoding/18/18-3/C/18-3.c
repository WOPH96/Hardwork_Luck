#include <stdio.h>

// 필요 변수 선언
int num;
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("18-3_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &num);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d ", &num);

    // 변수 입력 공간
}

int main()
{
    input();
    int arr[3][5] = {
        {1, 3, 3, 5, 1},
        {3, 6, 2, 4, 2},
        {1, 9, 2, 6, 5}};
    int check[10] = {0};

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            check[arr[y][x]] += 1;
        }
    }

    for (int i = 1; i < 10; i++)
    {
        // printf("%d ", check[i]);
        if (check[i] == num)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
