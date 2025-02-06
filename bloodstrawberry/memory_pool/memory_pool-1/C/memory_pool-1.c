#include <stdio.h>

// 필요 변수 선언
int K, V, E;
typedef struct st
{
    int node;
    struct st *next;
} Node;

Node HEAD[20001];
Node POOL[200001];

int pcnt = 0;

// 필요 변수 선언

void print(int v);
void make(int p, int c)
{
    Node *nd = &POOL[pcnt++];
    nd->node = c;
    nd->next = HEAD[p].next;
    HEAD[p].next = nd;
}

void init()
{
    pcnt = 0;
    for (int i = 1; i <= V; i++)
        HEAD[i].next = 0
}
void input_f()
{
    FILE *fp = fopen("memory_pool-1_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d ", &K);

    while (K)
    {

        fscanf(fp, "%d %d", &V, &E);

        for (register int i = 0; i < E; i++)
        {
            int p, c;
            fscanf(fp, "%d %d", &p, &c);
            make(p, c);
            make(c, p);
        }

        print(V);

        K--;
    }

    // 변수 입력 공간
    fclose(fp);
}

int main()
{
    input_f();
    // input();

    return 0;
}

void print(int v)
{
    for (int i = 1; i <= v; i++)
    {
        printf("%d : ", i);

        for (Node *it = HEAD[i].next; it->next; it = it->next)
        {
            printf("%d ", it->node);
        }
        printf("\n");
    }
}
