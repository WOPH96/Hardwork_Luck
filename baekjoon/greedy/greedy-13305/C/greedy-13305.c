#include <stdio.h>

#define MAX_NUM 100001
// 필요 변수 선언
int num_of_city;
long long sum = 0;
// 필요 변수 선언

int bridge[MAX_NUM];
int city_oil[MAX_NUM];

void print_debug();

void sol()
{
    int min_price = city_oil[0];

    for (int i = 0; i < num_of_city; i++)
    {
        if (city_oil[i] < min_price)
            min_price = city_oil[i];
        sum += (long long)min_price * bridge[i];
    }
    printf("%lld\n", sum);
}

void input_f()
{
    FILE *fp = fopen("greedy-13305_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d", &num_of_city);
    for (int i = 0; i < num_of_city - 1; i++)
    {
        fscanf(fp, "%d", &bridge[i]);
    }

    for (int i = 0; i < num_of_city; i++)
    {
        fscanf(fp, "%d", &city_oil[i]);
    }
    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d", &num_of_city);
    for (int i = 0; i < num_of_city - 1; i++)
    {
        scanf("%d", &bridge[i]);
    }

    for (int i = 0; i < num_of_city; i++)
    {
        scanf("%d", &city_oil[i]);
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    print_debug();
    sol();

    return 0;
}

void print_debug()
{
}
