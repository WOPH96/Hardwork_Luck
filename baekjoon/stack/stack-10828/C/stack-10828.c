#include <stdio.h>

// 필요 변수 선언
int num;
// 필요 변수 선언

int mystrcmp(const char *a, const char *b)
{
    while (*a && (*a == *b))
    {
        ++a;
        ++b;
    }
    return *a - *b;
}

void sol()
{
    printf("%d", num);
}

void input_f()
{
    FILE *fp = fopen("stack-10828_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간
    int stack[10100] = {0};

    fscanf(fp, "%d ", &num);
    int sp = 0; // stack pointer
    for (int i = 0; i < num; i++)
    {
        char input[10];
        fscanf(fp, "%s", input);
        if (mystrcmp(input, "push") == 0)
        {
            int data;
            fscanf(fp, "%d", &data);
            stack[sp++] = data;
        }
        else if (mystrcmp(input, "pop") == 0)
        {
            if (sp > 0)
            {
                printf("%d\n", stack[--sp]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "size") == 0)
        {
            printf("%d\n", sp);
        }
        else if (mystrcmp(input, "empty") == 0)
        {
            int is_empty = (sp == 0);
            printf("%d\n", is_empty);
        }
        else if (mystrcmp(input, "top") == 0)
        {
            if (sp > 0)
            {
                printf("%d\n", stack[sp - 1]);
            }
            else
            {
                printf("-1\n");
            }
        }
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // FILE *fp = fopen("stack-10828_input.txt", "r");
    // if (fp == NULL)
    // {
    //     printf("파일 열기 실패 \n ");
    //     return;
    // }

    // 변수 입력 공간
    int stack[10100] = {0};

    scanf("%d ", &num);
    int sp = 0; // stack pointer
    for (int i = 0; i < num; i++)
    {
        char input[10];
        scanf("%s", input);
        if (mystrcmp(input, "push") == 0)
        {
            int data;
            scanf("%d", &data);
            stack[sp++] = data;
        }
        else if (mystrcmp(input, "pop") == 0)
        {
            if (sp > 0)
            {
                printf("%d\n", stack[--sp]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "size") == 0)
        {
            printf("%d\n", sp);
        }
        else if (mystrcmp(input, "empty") == 0)
        {
            int is_empty = (sp == 0);
            printf("%d\n", is_empty);
        }
        else if (mystrcmp(input, "top") == 0)
        {
            if (sp > 0)
            {
                printf("%d\n", stack[sp - 1]);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
}

int main()
{
    // input_f();
    input();
    // sol();
    return 0;
}
