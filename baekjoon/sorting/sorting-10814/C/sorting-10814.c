#include <stdio.h>
#include <stdlib.h>
// 필요 변수 선언
#define MAX_SIZE 100001
int num;

typedef struct
{
    int age;
    int idx;
    char name[101];
} Person;

Person POOL[MAX_SIZE];

void print_debug();
// typedef struct
// {
//     Person heap[MAX_SIZE];
//     int size;
// } priority_queue;

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

int compare(const void *a, const void *b)
{

    if (((Person *)a)->age == ((Person *)b)->age)
    {
        return ((Person *)a)->idx > ((Person *)b)->idx;
    }
    return ((Person *)a)->age > ((Person *)b)->age;
}
// int compare(const Person *a, const Person *b)
// {
//     if (b->age == a->age)
//     {
//         return a->idx - b->idx;
//     }
//     return b->age - a->age;
// }

// void heapify(priority_queue *pq, int index)
// {
//     int smallest = index;
//     int left = 2 * index + 1;
//     int right = 2 * index + 2;

//     if (left < pq->size &&
//         compare(pq->heap[left], pq->heap[smallest]) < 0)
// }

void sol()
{
    qsort(POOL, num, sizeof(Person), compare);
}

// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("sorting-10814_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    fscanf(fp, "%d", &num);
    for (int i = 0; i < num; i++)
    {
        fscanf(fp, "%d %s", &POOL[i].age, POOL[i].name);
        POOL[i].idx = i;
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %s", &POOL[i].age, POOL[i].name);
        POOL[i].idx = i;
    }

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // print_debug();
    sol();
    print_debug();

    return 0;
}

void print_debug()
{
    for (int i = 0; i < num; i++)
    {
        printf("%d %s\n", POOL[i].age, POOL[i].name);
    }
    printf("\n");
}