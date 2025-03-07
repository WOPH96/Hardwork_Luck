#include <stdio.h>

// 필요 변수 선언
int n;
// 필요 변수 선언

void print_debug();
int dp[1001];

int get_total_tile(int n)
{
    if (n <= 2)
    {
        return dp[n];
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    else
    {
        dp[n] = (get_total_tile(n - 1) + 2 * get_total_tile(n - 2)) % 10007;
        return dp[n];
    }
}
void sol()
{
    dp[1] = 1;
    dp[2] = 3;
    // printf("%d", get_total_tile(n));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    }
    printf("%d", dp[n]);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-11727_input.txt", "r");
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

    scanf("%d ", &n);

    // 변수 입력 공간
}

int main()
{
    input_f();
    //  input();
    print_debug();
    sol();

    return 0;
}

void print_debug()
{
}
