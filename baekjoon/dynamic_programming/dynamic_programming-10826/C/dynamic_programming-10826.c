#include <stdio.h>
#include <string.h>
// 필요 변수 선언

typedef unsigned long long ull;
#define MAX 0xffffffffffffffff
ull n;
// 필요 변수 선언

ull dp[1000001];
void print_debug();

ull fibo(ull n)
{
    if (n <= 1)
        return n;
    if (dp[n] != MAX)
        return dp[n];
    else
    {
        dp[n] = (fibo(n - 1) + fibo(n - 2)) % 1000000007;
        return dp[n];
    }
}

void sol()
{
    // dp[i]가 존재하면 재귀를 하지 않음
    memset(dp, MAX, (n + 1) * sizeof(ull));
    dp[0] = 0;
    dp[1] = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%lld\n", dp[i]);
    // }

    // fibo(n);

    printf("%llu", fibo(n));
    // for (int i = 0; i < n + 1; i++)
    // {
    //     printf("%llu\n", dp[i]);
    // }
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-10826_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%llu ", &n);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%llu ", &n);
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
