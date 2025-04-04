#include <stdio.h>
#define MAX_NUM 100001

typedef long long ll;
// 필요 변수 선언

// 필요 변수 선언

void print_debug(int n, int graph[][MAX_NUM]);
int is_valid(int y, int x, int m)
{
    return (1 <= y && y <= 2 &&
            0 <= x && x < m);
}
void sol(int n, int graph[][MAX_NUM])
{   
    int dp[3][MAX_NUM];
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = graph[i][j];
            for (int dir = 0; dir < 4; dir++)
            {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if (is_valid(ny, nx, n))
                {
                    dp[i][j] += graph[ny][nx];
                }
            }
        }
    }
    print_debug(n, dp);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-9465_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    int t;
    fscanf(fp, "%d ", &t);

    while (t)
    {
        int n;
        fscanf(fp, "%d", &n);
        int graph[3][MAX_NUM];
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf(fp, "%d", &graph[i][j]);
            }
        }
        sol(n, graph);
        t--;
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);

    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    // print_debug();
    // sol();

    return 0;
}

void print_debug(int n, int graph[][MAX_NUM])
{
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
