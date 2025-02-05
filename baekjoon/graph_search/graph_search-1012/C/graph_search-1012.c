#include <stdio.h>

// 필요 변수 선언
#define MAX_SIZE 2525
#define SIZE 51
typedef struct
{
    int y, x;
} Pos;

typedef enum
{
    EMPTY,
    CAB
} Info;
// 필요 변수 선언

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void print_debug(int (*graph)[SIZE], int n, int m);

int is_valid(int y, int x, int n, int m)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}

int bfs(const Pos start, int (*graph)[SIZE], int (*visited)[SIZE], int n, int m)
{
    if (visited[start.y][start.x])
        return 0;

    Pos q[MAX_SIZE] = {0};
    int ip = 0, op = 0;

    q[ip++] = start;
    visited[start.y][start.x] = 1;

    while (ip > op)
    {
        Pos now = q[op++];
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (!is_valid(ny, nx, n, m))
                continue;
            if (graph[ny][nx] == CAB && !visited[ny][nx])
            {
                q[ip++] = (Pos){ny, nx};
                visited[ny][nx] = 1;
            }
        }
    }
    return 1;
}

void input_f()
{
    FILE *fp = fopen("graph_search-1012_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    int tc;
    // 변수 입력 공간

    fscanf(fp, "%d", &tc);

    while (tc)
    {
        Pos cab_pos[MAX_SIZE];
        int graph[SIZE][SIZE] = {0};
        int visited[SIZE][SIZE] = {0};
        int m, n, k;
        fscanf(fp, "%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            fscanf(fp, "%d %d", &x, &y);
            graph[y][x] = 1;
            cab_pos[i].y = y;
            cab_pos[i].x = x;
        }

        // print_debug(graph, n, m);
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            if (bfs(cab_pos[i], graph, visited, n, m))
            {
                res++;
            }
        }

        printf("%d\n", res);

        tc--;
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    int tc;
    // 변수 입력 공간

    scanf("%d", &tc);

    while (tc)
    {
        Pos cab_pos[MAX_SIZE];
        int graph[SIZE][SIZE] = {0};
        int visited[SIZE][SIZE] = {0};
        int m, n, k;
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            graph[y][x] = 1;
            cab_pos[i].y = y;
            cab_pos[i].x = x;
        }

        // print_debug(graph, n, m);
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            if (bfs(cab_pos[i], graph, visited, n, m))
            {
                res++;
            }
        }

        printf("%d\n", res);

        tc--;
    }

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();

    return 0;
}

void print_debug(int (*graph)[SIZE], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}