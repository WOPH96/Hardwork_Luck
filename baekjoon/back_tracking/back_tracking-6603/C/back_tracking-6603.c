#include <stdio.h>

// 필요 변수 선언

// 필요 변수 선언

void print_debug();

int comb[6];
void backtrack(int start, int depth, int k, int nums[], int visited[])
{
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%d ", comb[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = start; i < k; i++)
        {
            // if (!visited[i])
            // {
            comb[depth] = nums[i];
            // visited[i] = 1;
            backtrack(i + 1, depth + 1, k, nums, visited);
            // visited[i] = 0;
            // }
        }
    }
}

void sol(int k, int nums[])
{
    // for (int i = 0; i < k; i++)
    // {
    //     printf("%d ", nums[i]);
    // }
    int visited[14] = {0};
    backtrack(0, 0, k, nums, visited);
    printf("\n");
}

void input_f()
{
    FILE *fp = fopen("back_tracking-6603_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    while (1)
    {
        int k;
        int nums[14];
        fscanf(fp, "%d", &k);
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            fscanf(fp, "%d", &nums[i]);
        }
        sol(k, nums);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    while (1)
    {
        int k;
        int nums[14];
        scanf("%d", &k);
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &nums[i]);
        }
        sol(k, nums);
    }

    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    print_debug();
    // sol();

    return 0;
}

void print_debug()
{
}
