#include <stdio.h>

// 필요 변수 선언
int n, m;

typedef struct Node
{

    int data;
    struct Node *next;

} Node;

Node Head[101] = {0};
Node POOL[101] = {0};
int pcnt = 0;

// 필요 변수 선언

void print_debug();

void add_edge(int src, int dst)
{
    Node *nd = &POOL[pcnt++];
    nd->data = dst;

    nd->next = Head[src].next;
    Head[src].next = nd;
}

void input_f()
{
    FILE *fp = fopen("graph_search-2606_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int from, to;
        fscanf(fp, "%d %d", &from, &to);
        add_edge(from, to);
        add_edge(to, from);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        add_edge(from, to);
        add_edge(to, from);
    }

    // 변수 입력 공간
}

int bfs()
{
    int queue[101 * 101] = {0};
    int ip = 0, op = 0;
    int visited[101] = {0};
    queue[ip++] = 1;
    visited[1] = 1;

    int result = 0;
    while (ip > op)
    {
        int now = queue[op++];

        for (Node *p = Head[now].next; p; p = p->next)
        {
            if (!visited[p->data])
            {
                queue[ip++] = p->data;
                visited[p->data] = 1;
                result++;
            }
        }
    }
    return result;
}

int main()
{
    input_f();
    // input();
    printf("%d\n", bfs());
    // print_debug();

    return 0;
}

void print_debug()
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d :", i);
        for (Node *p = Head[i].next; p; p = p->next)
        {
            printf("%d ", p->data);
        }
        printf("\n");
    }
}