#include <stdio.h>
#include <stdlib.h>
// 필요 변수 선언
int num_of_jew, num_of_bag;

typedef struct
{
    int weight;
    int value;
} Jew;

#define NEG_INF 0xffff0000
#define MAX_NUM 300001

Jew jews[MAX_NUM];
int bags[MAX_NUM];

int maxpq[MAX_NUM];
int pqidx = 0;
// 필요 변수 선언

void print_debug();

int cmp_Jews(const void *a, const void *b)
{
    Jew *src = (Jew *)a;
    Jew *dst = (Jew *)b;

    return (src->weight > dst->weight) - (src->weight < dst->weight);
}

int cmp_Bags(const void *a, const void *b)
{
    int *src = (int *)a;
    int *dst = (int *)b;

    return (*src > *dst) - (*src < *dst);
}

void push(int data)
{
    maxpq[++pqidx] = data; // idx 1부터 삽입

    // 내 부모와 비교해서 내가 더 크면 자리 체인지
    for (register int i = pqidx; i > 1; i /= 2)
    {
        // i == 2라면, pq[2/2(==1)]은 pq[2]보다 커야함. 크거나 같으면 그만
        if (maxpq[i / 2] >= maxpq[i])
            break;
        else
        {
            register int temp;
            // 작다면 내가 상위권 차지
            temp = maxpq[i / 2];
            maxpq[i / 2] = maxpq[i];
            maxpq[i] = temp;
        }
    }
}

void pop()
{
    if (pqidx == 0)
        return;
    maxpq[1] = maxpq[pqidx];
    maxpq[pqidx--] = NEG_INF; // 마지막 자리를 negative inf로 채움

    // maxpq의 규칙을 지킴
    for (register int i = 1; i * 2 <= pqidx;) // 범위 너머까지 참조하지 않도록
    {
        // i가 1이라면, maxpq[1] >= maxpq[2] , maxpq[1] >= maxpq[3] 이어야 함
        // i가 2라면, maxpq[2] >= maxpq[4,5] 여야함
        // 성립하면 그만
        if (maxpq[i] >= maxpq[i * 2] && maxpq[i] >= maxpq[i * 2 + 1])
            break;
        else
        {
            if (maxpq[i * 2] > maxpq[i * 2 + 1]) // 자식 중 왼쪽이 더 큰값이라면
            {
                // 스왑 ㅇㅇ
                register int temp;
                temp = maxpq[i];
                maxpq[i] = maxpq[i * 2];
                maxpq[i * 2] = temp;

                i = i * 2; // 다음 참조는 왼쪽과 진행
            }
            else
            {
                register int temp;
                temp = maxpq[i];
                maxpq[i] = maxpq[i * 2 + 1];
                maxpq[i * 2 + 1] = temp;

                i = i * 2 + 1;
            }
        }
    }
}
int top()
{
    if (pqidx == 0)
        return 0;
    return maxpq[1];
}

int empty()
{
    return (pqidx == 0);
}

void sol()
{
    qsort(jews, num_of_jew, sizeof(Jew), cmp_Jews);
    qsort(bags, num_of_bag, sizeof(int), cmp_Bags);

    int jew_idx = 0;
    long long most_valuable_sum = 0;
    for (int i = 0; i < num_of_bag; i++)
    {
        while (jew_idx < num_of_jew && jews[jew_idx].weight <= bags[i])
        {
            push(jews[jew_idx].value);
            jew_idx++;
        }

        if (!empty())
        {

            most_valuable_sum += top();
            pop();
        }
    }
    printf("%lld", most_valuable_sum);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-1202_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    // fscanf(fp, "%d ", &num1);
    fscanf(fp, "%d %d", &num_of_jew, &num_of_bag);
    for (int i = 0; i < num_of_jew; i++)
    {
        fscanf(fp, "%d %d", &jews[i].weight, &jews[i].value);
    }
    for (int i = 0; i < num_of_bag; i++)
    {
        fscanf(fp, "%d", &bags[i]);
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d", &num_of_jew, &num_of_bag);
    for (int i = 0; i < num_of_jew; i++)
    {
        scanf("%d %d", &jews[i].weight, &jews[i].value);
    }
    for (int i = 0; i < num_of_bag; i++)
    {
        scanf("%d", &bags[i]);
    }
    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // print_debug();
    sol();
    // print_debug();

    return 0;
}

void print_debug()
{
    for (int i = 0; i < num_of_bag + num_of_jew; i++)
    {
        if (i < num_of_jew)
        {
            printf("%d %d \n", jews[i].weight, jews[i].value);
        }
        else
        {
            printf("%d\n", bags[i - num_of_jew]);
        }
    }
    printf("\n");
}
