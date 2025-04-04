#include <stdio.h>

#define MAX_NUM 91
typedef long long ll;
// 필요 변수 선언
int n;
// 필요 변수 선언

ll dp[MAX_NUM][2];

void print_debug();

void sol()
{
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    printf("%lld", dp[n][0] + dp[n][1]);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-2193_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &n);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d ", &n);
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
