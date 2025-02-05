#include <stdio.h>

// 필요 변수 선언

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

void input_f()
{
    FILE *fp = fopen("queue-10845_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    int num;
    // 변수 입력 공간

    fscanf(fp, "%d ", &num);
    int queue[10100] = {0};
    int ip = 0, op = 0;
    for (int i = 0; i < num; i++)
    {
        char input[10];
        fscanf(fp, "%s", input);
        // printf("%s\n", input);
        if (mystrcmp(input, "push") == 0)
        {
            int data;
            fscanf(fp, "%d", &data);
            queue[ip++] = data;
        }
        else if (mystrcmp(input, "pop") == 0)
        {
            if (ip > op) // 비어있지 않다면 ip > op임
            {
                printf("%d\n", queue[op++]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "front") == 0)
        {
            if (ip > op)
            {
                printf("%d\n", queue[op]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "back") == 0)
        {
            if (ip > op)
            {
                printf("%d\n", queue[ip - 1]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "empty") == 0)
        {
            printf("%d\n", (ip == op));
        }
        else if (mystrcmp(input, "size") == 0)
        {
            printf("%d\n", ip - op);
        }
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    int num;
    // 변수 입력 공간

    scanf("%d ", &num);
    int queue[10100] = {0};
    int ip = 0, op = 0;
    for (int i = 0; i < num; i++)
    {
        char input[10];
        scanf("%s", input);
        // printf("%s\n", input);
        if (mystrcmp(input, "push") == 0)
        {
            int data;
            scanf("%d", &data);
            queue[ip++] = data;
        }
        else if (mystrcmp(input, "pop") == 0)
        {
            if (ip > op) // 비어있지 않다면 ip > op임
            {
                printf("%d\n", queue[op++]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "front") == 0)
        {
            if (ip > op)
            {
                printf("%d\n", queue[op]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "back") == 0)
        {
            if (ip > op)
            {
                printf("%d\n", queue[ip - 1]);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (mystrcmp(input, "empty") == 0)
        {
            printf("%d\n", (ip == op));
        }
        else if (mystrcmp(input, "size") == 0)
        {
            printf("%d\n", ip - op);
        }
    }
}

int main()
{
    // input_f();
    input();

    return 0;
}
