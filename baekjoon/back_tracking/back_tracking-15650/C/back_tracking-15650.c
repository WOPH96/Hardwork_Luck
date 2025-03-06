#include <stdio.h>

// 필요 변수 선언
int n, m;
// 필요 변수 선언

void print_debug();

int comb[9];
void backtrack(int start, int depth)
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

        for (int i = start; i <= n; i++)
        {
            comb[depth] = i;
            backtrack(i + 1, depth + 1);
        }
    }
}

void sol()
{
    backtrack(1, 0);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-15650_input.txt", "r");
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
