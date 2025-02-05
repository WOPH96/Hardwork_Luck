#include <stdio.h>
#include <stdlib.h>

// 필요 변수 선언
char num[12];
// 필요 변수 선언

int compare(const void *a, const void *b)
{
    char *src = (char *)a;
    char *dst = (char *)b;

    return *src < *dst;
}

int mystrlen(const char *a)
{
    int cnt = 0;
    while (*a++)
        cnt++;
    return cnt;
}

void sol()
{
    int len = mystrlen(num);
    qsort(num, len, sizeof(char), compare);
    for (int i = 0; i < len; i++)
    {
        printf("%c", num[i]);
    }
}

void input_f()
{
    FILE *fp = fopen("sorting-1427_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%s", num);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%s", num);

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    sol();

    return 0;
}
