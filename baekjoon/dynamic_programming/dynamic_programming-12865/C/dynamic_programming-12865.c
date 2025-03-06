#include <stdio.h>

// 필요 변수 선언

#define MAX_WEIGHT 100001
#define MAX_ITEM 101
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int num_of_item;
int bag;

typedef struct
{
    int weight;
    int value;
} Item;
// 필요 변수 선언

Item items[MAX_ITEM];

int dp[MAX_ITEM][MAX_WEIGHT];

void print_debug();

void sol()
{
    for (int i = 1; i <= num_of_item; i++)
    {
        // printf("%d: ", i);
        for (int w = 1; w <= bag; w++) // 가방이 1일때 경우부터 bag일때 경우까지
        {
            // 물건이 가방보다 무거울 경우
            if (items[i].weight > w)
            {
                // 이전 물건들로 무게 w에서 얻을 수 있는 최대 가치
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                // 이전 물건 가치 vs 현재 물건 넣기 -> 그림으로 정리
                dp[i][w] = MAX(dp[i - 1][w], dp[i - 1][w - items[i].weight] + items[i].value);
            }
            // printf("%d ", dp[i][w]);
        }
        // printf("\n");
    }
    printf("%d", dp[num_of_item][bag]);
}

void input_f()
{
    FILE *fp = fopen("dynamic_programming-12865_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    // fscanf(fp, "%d ", &num1);
    fscanf(fp, "%d %d", &num_of_item, &bag);

    for (int i = 1; i <= num_of_item; i++)
    {
        fscanf(fp, "%d %d", &items[i].weight, &items[i].value);
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d", &num_of_item, &bag);

    for (int i = 1; i <= num_of_item; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    // print_debug();
    sol();

    return 0;
}

void print_debug()
{
    for (int i = 1; i <= num_of_item; i++)
    {
        printf("%d %d\n", items[i].weight, items[i].value);
    }
}
