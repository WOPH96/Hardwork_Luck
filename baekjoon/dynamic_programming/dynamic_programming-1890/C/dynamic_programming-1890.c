#include <stdio.h>

#define MAX_NUM 101
#define EXIT 0
typedef unsigned long long ull;

// 필요 변수 선언
int n;
int graph[MAX_NUM][MAX_NUM];
ull dp[MAX_NUM][MAX_NUM];
// 필요 변수 선언

void print_debug(); // ull map[][MAX_NUM]);

int dy[] = {1, 0};
int dx[] = {0, 1};

int is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < n);
}

void sol()
{
    // init
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 2; dir++)
            {
                int ny = i + dy[dir] * graph[i][j];
                int nx = j + dx[dir] * graph[i][j];
                if (!is_valid(ny, nx) || graph[i][j] == EXIT)
                    continue;
                else
                {
                    dp[ny][nx] += dp[i][j];
                }
            }
            // print_debug();
        }
    }

    printf("%llu\n", dp[n - 1][n - 1]);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-1890_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
    scanf("%d ", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
    sol();
    // print_debug();

    return 0;
}

void print_debug() // ull map[][MAX_NUM])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%llu ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
