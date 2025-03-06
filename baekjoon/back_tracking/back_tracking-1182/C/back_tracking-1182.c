#include <stdio.h>

#define MAX_NUM 21
// 필요 변수 선언
int n, target_sum;
int arr[MAX_NUM];
int cnt = 0;
// 필요 변수 선언

void print_debug();

void backtrack(int idx, int sum)
{
    if (idx == n)
        return;
    else
    {
        // 현재 idx 값 더하기
        sum += arr[idx];

        if (sum == target_sum)
        {
            cnt++;
        }

        // 현재 idx 선택한다음 다음 idx 돌기
        backtrack(idx + 1, sum);
        // 현재 idx 선택하지 않고 다음 idx 돌기
        backtrack(idx + 1, sum - arr[idx]);
    }
}
void sol()
{
    backtrack(0, 0);
    printf("%d", cnt);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-1182_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    fscanf(fp, "%d %d", &n, &target_sum);
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", (arr + i));
    }
    // fscanf(fp, "%d ", &num1);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d", &n, &target_sum);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    // print_debug();
    sol();

    return 0;
}

void print_debug()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
