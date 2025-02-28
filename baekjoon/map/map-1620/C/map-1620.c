#include <stdio.h>
#include <math.h>

// 필요 변수 선언
#define TABLE_SIZE 10007
#define MAX_SIZE 100001

int n, m;

typedef struct st
{
    char name[21];
    int value;
    struct st *next;
} Node;

Node POOL[MAX_SIZE];
int pcnt = 0;
Node HASH_TABLE[TABLE_SIZE];
Node ARR[MAX_SIZE];

// 필요 변수 선언

void print_debug();

void sol()
{
}

int mystrlen(const char *a)
{
    int cnt = 0;
    while (*a++)
        cnt++;
    return cnt;
}

void mystrcpy(char *a, const char *b)
{
    while (*a++ = *b++)
        ;
}
int mystrcmp(const char *a, const char *b)
{
    while (*a && (*a == *b))
    {
        a++;
        b++;
    }
    return *a - *b;
}

int hash(char *str)
{
    int hash = 5381;
    int c = 0;
    while (c = *str++)
    {
        hash = ((hash << 5) + hash + c) % TABLE_SIZE;
    }
    return hash % TABLE_SIZE;
}

int find_table(char *str)
{
    int hash_idx = hash(str);
    for (Node *nd = HASH_TABLE[hash_idx].next; nd; nd = nd->next)
    {
        if (mystrcmp(nd->name, str) == 0)
        {
            printf("%d\n", nd->value);
            return 1;
        }
    }
    return 0;
}

void input_f()
{
    FILE *fp = fopen("map-1620_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        fscanf(fp, "%s", ARR[i].name);
        int hash_idx = hash(ARR[i].name);
        // hash_idx에 Node 추가 (name)
        Node *nd = &POOL[pcnt++];
        mystrcpy(nd->name, ARR[i].name); //
        nd->value = i;

        nd->next = HASH_TABLE[hash_idx].next;
        HASH_TABLE[hash_idx].next = nd;
    }

    for (int i = 0; i < m; i++)
    {
        char str[21];
        fscanf(fp, "%s", str);
        if ('0' <= str[0] && str[0] <= '9')
        {
            int size = mystrlen(str);
            // printf("%d", size);
            int num = 0;
            for (int j = 0; j < size; j++)
            {

                num += (str[j] - '0') * pow(10, size - j - 1);
            }
            printf("%s\n", ARR[num].name);
        }
        else
        {
            find_table(str);
        }
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ARR[i].name);
        int hash_idx = hash(ARR[i].name);
        // hash_idx에 Node 추가 (name)
        Node *nd = &POOL[pcnt++];
        mystrcpy(nd->name, ARR[i].name); //
        nd->value = i;

        nd->next = HASH_TABLE[hash_idx].next;
        HASH_TABLE[hash_idx].next = nd;
    }

    for (int i = 0; i < m; i++)
    {
        char str[21];
        scanf("%s", str);
        if ('0' <= str[0] && str[0] <= '9')
        {
            int size = mystrlen(str);
            // printf("%d", size);
            int num = 0;
            for (int j = 0; j < size; j++)
            {

                num += (str[j] - '0') * pow(10, size - j - 1);
            }
            printf("%s\n", ARR[num].name);
        }
        else
        {
            find_table(str);
        }
    }

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    print_debug();
    sol();

    return 0;
}

void print_debug()
{
}
