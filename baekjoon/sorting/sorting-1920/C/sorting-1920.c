#include <stdio.h>
#include <stdlib.h>
// 필요 변수 선언
#define MAX_SIZE 100001
int n, m;
int A[MAX_SIZE] = {0};
int B[MAX_SIZE] = {0};
// 필요 변수 선언

void print_debug();

int compare(const void *a, const void *b)
{
    int *first = (int *)a;
    int *second = (int *)b;

    return (*first > *second ? 1 : -1);
}

int binary_search(int target)
{
    int mid, left = 0, right = n - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target == A[mid])
            return 1;
        else if (target < A[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}

void sol()
{
    qsort(A, n, sizeof(int), compare);
    // qsort(B, n, sizeof(int), compare);
    for (int i = 0; i < m; i++)
    {
        printf("%d\n", binary_search(B[i]));
    }
}
void input_f()
{
    FILE *fp = fopen("sorting-1920_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &A[i]);
    }
    fscanf(fp, "%d ", &m);
    for (int i = 0; i < m; i++)
    {
        fscanf(fp, "%d", &B[i]);
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    scanf("%d ", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // print_debug();
    sol();
    // print_debug();
    return 0;
}

void print_debug()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
}
