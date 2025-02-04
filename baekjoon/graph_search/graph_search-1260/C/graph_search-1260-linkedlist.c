#include <stdio.h>
#include <stdlib.h>

// 필요 변수 선언
#define MAX 1001

int N, M, V;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node POOL[MAX];
Node Head[MAX];
Node Tail[MAX];
int pcnt = 0;

// 필요 변수 선언

void print();

void dfs()
{
}

void bfs()
{
}

void sol()
{
}

void Make(int src, int dst)
{
    Node *nd = &POOL[pcnt++];
    nd->data = dst;

    if (Head[src].next == NULL && Tail[src].next == NULL)
    {                        // Head에 연결된게 아무것도 없으면
        Head[src].next = nd; // Head 뒤에 연결
        Tail[src].next = nd; // 가장 마지막 노드 = 첫번쨰노드
    }
    else
    {
        Tail[src].next->next = nd; // 가장 마지막 노드 뒤에 next 연결
        Tail[src].next = nd;       // 가장 마지막 노드 = nd
    }
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
        Make(from, to);
        Make(to, from);
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
        Make(from, to);
        Make(to, from);
    }
}

int main()
{
    input_f();
    // input();
    // sol();
    print();

    return 0;
}

void print()
{
    for (int i = 1; i <= N; i++)
    {
        for (Node *nd = Head[i].next; nd != NULL; nd = nd->next)
        {
            printf("%d ", nd->data);
        }
        printf("\n");
    }
}