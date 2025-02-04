#include <stdio.h>
#include <stdlib.h>

// 필요 변수 선언
#define MAX 1001
int graph[MAX][MAX] = {0};
int N, M, V;

// 필요 변수 선언

void print();

void dfs(int *visited, int now)
{
    visited[now] = 1;
    printf("%d ", now);
    for (int i = 1; i <= N; i++)
    {
        if (graph[now][i] && !visited[i])
        {
            dfs(visited, i);
        }
    }
}

void bfs()
{
    int q[MAX] = {0};
    int visited[MAX] = {0};
    int ip = 0, op = 0; // input pointer, output pointer

    q[ip++] = V; // q.push(V);
    visited[V] = 1;
    while (ip > op) // !q.empty();
    {
        int now = q[op++]; // now = q.front(),q.pop();
        printf("%d ", now);

        for (int i = 1; i <= N; i++)
        {
            if (graph[now][i] && !visited[i])
            {
                visited[i] = 1;
                q[ip++] = i;
            }
        }
    }
}

void sol()
{
    int visited[MAX] = {0};
    dfs(visited, V);
    printf("\n");
    bfs();
    printf("\n");
}

void input_f()
{
    FILE *fp = fopen("graph_search-1260_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++)
    {
        int from, to;
        fscanf(fp, "%d %d", &from, &to);
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from][to] = 1;
        graph[to][from] = 1;
    }
}

int main()
{
    // input_f();
    input();
    sol();
    // print();

    return 0;
}

void print()
{

    for (int i = 1; i <= N; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j])
                printf("%d ", j);
        }
        printf("\n");
    }
}