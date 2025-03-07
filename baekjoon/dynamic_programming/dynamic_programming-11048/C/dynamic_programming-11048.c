#include <stdio.h>

#define MAX_NUM 1001

// 필요 변수 선언
int n, m;
// 필요 변수 선언
int graph[MAX_NUM][MAX_NUM];
int dy[] = {-1, 0, -1};
int dx[] = {0, -1, -1};

int dp[MAX_NUM][MAX_NUM];

void print_debug();

int is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}

void sol()
{
    // init
    // dp[0][0] = graph[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = graph[i][j];
            int max = 0;
            for (int dir = 0; dir < 3; dir++)
            {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if (is_valid(ny, nx))
                {

                    max = max > dp[ny][nx] ? max : dp[ny][nx];
                }
            }
            dp[i][j] += max;
        }
    }
    printf("%d", dp[n - 1][m - 1]);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-11048_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    // fscanf(fp, "%d ", &num1);
    fscanf(fp, "%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    // print_debug();
    sol();
    // print_debug();

    return 0;
}

void print_debug()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
