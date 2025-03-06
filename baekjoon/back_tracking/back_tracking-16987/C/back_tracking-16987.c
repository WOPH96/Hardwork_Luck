#include <stdio.h>

#define MAX_EGG 8
// 필요 변수 선언
int num_of_egg;

typedef struct
{
    int durability;
    int weight;
} Egg;

Egg eggs[MAX_EGG];

// 필요 변수 선언

void print_debug();

int MAX_crashed_egg = -1;
void backtrack(int curr)
{
    if (curr == num_of_egg)
    {
        // MAX값 갱신
        int cnt = 0;
        for (int i = 0; i < num_of_egg; i++)
        {
            if (eggs[i].durability < 0)
                cnt++;
        }

        if (cnt > MAX_crashed_egg)
            MAX_crashed_egg = cnt;
    }
    else
    {
        if (eggs[curr].durability <= 0)
        {
            backtrack(curr + 1);
        }

        int has_hit = 0;

        for (int i = 0; i < num_of_egg; i++)
        {
            // 쥔 달걀, 칠 달걀이 아직 안깨졌을 때 뿌수기 수행
            if (i == curr || eggs[curr].durability <= 0 || eggs[i].durability <= 0)
                continue;
            else
            {
                // 계란 박치기
                eggs[curr].durability -= eggs[i].weight;
                eggs[i].durability -= eggs[curr].weight;
                has_hit = 1;
                // printf("curr : %d , %d %d\n", curr, eggs[curr].durability, eggs[curr].weight);
                // printf("target : %d , %d %d\n", i, eggs[i].durability, eggs[i].weight);
                backtrack(curr + 1);
                // 안쳤다 치기
                eggs[curr].durability += eggs[i].weight;
                eggs[i].durability += eggs[curr].weight;
            }
        }
        // 멀쩡한 달걀로 칠게 없었다면
        if (!has_hit)
        {
            backtrack(curr + 1);
        }
    }
}

void sol()
{
    backtrack(0);
    printf("%d\n", MAX_crashed_egg);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-16987_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    fscanf(fp, "%d", &num_of_egg);
    for (int i = 0; i < num_of_egg; i++)
    {
        fscanf(fp, "%d %d", &eggs[i].durability, &eggs[i].weight);
    }
    // fscanf(fp, "%d ", &num1);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d", &num_of_egg);
    for (int i = 0; i < num_of_egg; i++)
    {
        scanf("%d %d", &eggs[i].durability, &eggs[i].weight);
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
