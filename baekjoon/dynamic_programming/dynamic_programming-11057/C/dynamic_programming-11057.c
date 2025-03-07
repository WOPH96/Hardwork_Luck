#include <stdio.h>
#define MOD 10007
// 필요 변수 선언
int n;
// 필요 변수 선언

void print_debug();

int dp[1001][10];

void sol()
{
    // init

    for (int j = 0; j < 10; j++)
    {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 0; j < 10; j++)
    {
        result = (result + dp[n][j]) % MOD;
    }
    printf("%d", result);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-11057_input.txt", "r");
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
