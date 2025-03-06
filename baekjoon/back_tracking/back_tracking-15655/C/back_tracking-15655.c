#include <stdio.h>
#include <stdlib.h>
// 필요 변수 선언
int n, m;
// 필요 변수 선언
int arr[8];
int comb[8];

void print_debug();

void backtrack(int start, int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d ", comb[i]);
        printf("\n");
        return;
    }
    else
    {
        for (int i = start; i < n; i++)
        {

            comb[depth] = arr[i];
            backtrack(i + 1, depth + 1);
        }
    }
}

int cmp(const void *a, const void *b)
{
    int *src = (int *)a;
    int *dst = (int *)b;

    return (*src > *dst) - (*src < *dst);
}
void sol()
{
    qsort(arr, n, sizeof(int), cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    backtrack(0, 0);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-15655_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d ", &n, &m);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    print_debug();
    sol();

    return 0;
}

void print_debug()
{
}
