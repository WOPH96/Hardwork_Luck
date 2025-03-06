#include <stdio.h>

// 필요 변수 선언
int n, m;
// 필요 변수 선언

void print_debug();

// visited 대신에, 대소비교
int comb[8];
void backtrack(int depth)
{
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", comb[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (depth == 0 || comb[depth - 1] <= i)
            {
                comb[depth] = i;
                backtrack(depth + 1);
            }
        }
    }
}

void sol()
{
    backtrack(0);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-15652_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d", &n, &m);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d", &n, &m);

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
