#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 독립점 찾기

typedef struct
{
    int node1, node2, index, cnt;
} Node;

Node POOL[100001];

Node Sorted[100001];

int n, m;
// 필요 변수 선언

void print_debug(Node *arr);

int compare(const void *a, const void *b)
{
    Node *first = (Node *)a;
    Node *second = (Node *)b;

    return (first->cnt > second->cnt) -
           (first->cnt < second->cnt);
}
void sol()
{
    memcpy(Sorted, &POOL[1], (n) * sizeof(Node));
    qsort(Sorted, n, sizeof(Node), compare);

    int visited[100001] = {0};
    int result = 0;
    for (int i = 0; i < n; i++)
    {

        int idx = Sorted[i].index;
        if (!visited[idx])
        {
            printf("idx : %d\n", idx);
            visited[idx] = 1;
            visited[POOL[idx].node1] = 1;
            visited[POOL[idx].node2] = 1;
            result++;
        }
    }
    printf("%d\n", result);
    // print_debug(Sorted);
}

void insert(int src, int dst)
{
    if (!POOL[src].node1)
    {
        POOL[src].node1 = dst;
    }
    else
    {
        POOL[src].node2 = dst;
    }
    POOL[src].cnt++;
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        POOL[i].index = i;
    }
}
void input_f()
{
    FILE *fp = fopen("review-1_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
        int u, v;
        fscanf(fp, "%d %d", &u, &v);
        insert(u, v);
        insert(v, u);
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
    // print_debug(POOL);
    // printf("\n");
    sol();

    return 0;
}

void print_debug(Node *arr)
{
    for (int i = 0; i <= n; i++)
    {
        printf("index - %d :  %d %d , %d\n", arr[i].index, arr[i].node1, arr[i].node2, arr[i].cnt);
    }
}
