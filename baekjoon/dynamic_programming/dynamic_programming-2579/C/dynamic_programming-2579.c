#include <stdio.h>

#define MAX_NUM 301
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef long long ll;
// 필요 변수 선언
int n;

ll dp[MAX_NUM][3];
int stairs[MAX_NUM];
// 필요 변수 선언

void print_debug();

void sol()
{
    // i > 현재 밟고 있는 층
    // j > 이 층을 몇층을 뛰어넘어 밟았는가?
    // init
    dp[1][1] = 0 + stairs[1];         // 바닥층 + 현재층
    dp[1][2] = 0;                     // 지하층은 없다
    dp[2][1] = stairs[1] + stairs[2]; // 한층 한층
    dp[2][2] = 0 + stairs[2];         // 바닥층은 + 현재층

    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][2] + stairs[i];
        dp[i][2] = MAX(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
    }

    ll result = MAX(dp[n][1], dp[n][2]);
    printf("%lld", result);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-2579_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &n);

    for (int i = 1; i <= n; i++)
    {
        fscanf(fp, "%d", &stairs[i]);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d ", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &stairs[i]);
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
