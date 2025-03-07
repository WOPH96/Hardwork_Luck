#include <stdio.h>

#define MAX_NUM 501

typedef long long dll;

int n, m;
int graph[MAX_NUM][MAX_NUM];
dll dp[MAX_NUM][MAX_NUM]; // dp[y][x]: 해당 지점에서 도착지까지의 경로 개수

// 이동 방향 (동, 서, 남, 북)
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
void print_debug();
// 유효한 좌표인지 확인
int is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}

// DFS + DP (탑다운 메모이제이션)
dll dfs(int y, int x)
{
    // 도착지에 도달하면 경로 1개 완성
    if (y == n - 1 && x == m - 1)
        return 1;

    // 이미 방문한 적이 있으면 계산된 값을 반환 (메모이제이션)
    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0; // 초기화

    // 네 방향으로 탐색
    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 유효한 위치이고, 내리막길인지 확인
        if (is_valid(ny, nx) && graph[ny][nx] < graph[y][x])
        {
            dp[y][x] += dfs(ny, nx);
        }
    }
    print_debug();
    return dp[y][x];
}

void sol()
{
    // dp 배열을 -1로 초기화 (아직 방문하지 않은 상태를 의미)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }
    }
    // print_debug();
    printf("%lld\n", dfs(0, 0)); // 시작점에서 도착점까지의 경로 개수 계산
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-1520_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

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
    sol();
    print_debug();

    return 0;
}

void print_debug() // dll map[][MAX_NUM])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lld ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
