#include <stdio.h>
#include <stdlib.h>
// 필요 변수 선언
int L, C;
// 필요 변수 선언

char chrs[16];

void print_debug();

int cmp_char(const void *a, const void *b)
{
    char *src = (char *)a;
    char *dst = (char *)b;
    return (*src > *dst) - (*src < *dst);
}

char comb[16];
int isvowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u');
}
void backtrack(int start, int depth, int cnt_vowel, int cnt_other)
{
    if (depth == L)
    {
        if (cnt_vowel >= 1 && cnt_other >= 2)
        {
            comb[L] = '\0';
            printf("%s\n", comb);
        }
    }
    else
    {
        for (int i = start; i < C; i++)
        {

            comb[depth] = chrs[i];
            if (isvowel(chrs[i]))
            {
                backtrack(i + 1, depth + 1, cnt_vowel + 1, cnt_other);
            }
            else
            {
                backtrack(i + 1, depth + 1, cnt_vowel, cnt_other + 1);
            }
        }
    }
}

void sol()
{
    qsort(chrs, C, sizeof(char), cmp_char);
    // printf("%s", chrs);
    backtrack(0, 0, 0, 0);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-1759_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    fscanf(fp, "%d %d", &L, &C);
    for (int i = 0; i < C; i++)
    {
        fscanf(fp, " %c", &chrs[i]);
    }
    // fscanf(fp, "%d ", &num1);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++)
    {
        scanf(" %c", &chrs[i]);
    }
    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    print_debug();
    sol();
    print_debug();

    return 0;
}

void print_debug()
{
    // for (int i = 0; i < C; i++)
    // {
    //     printf("%c", chrs[i]);
    // }
    // printf("\n");
}
