#include <stdio.h>

#define MOD 1000000000
// 필요 변수 선언
int n;
// 필요 변수 선언

void print_debug();

int dp[101][10];
void sol()
{
    // init
    // 0으로 시작하는 수는 계단 수 x
    long long sum = 0;
    dp[1][0] = 0;
    for (int i = 1; i < 10; i++)
    {
        // 1의자리 수는 모두 계단수
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][1];
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][8];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        sum = (sum + dp[n][i]) % MOD;
    }
    printf("%lld", sum);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-10844_input.txt", "r");
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
