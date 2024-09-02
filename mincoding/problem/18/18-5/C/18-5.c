#include <stdio.h>

// 필요 변수 선언
char str[8];
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("18-5_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%s", str);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%s", str);

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // printf("%s", str);
    int check[26] = {0};

    for (int i = 0; str[i] != '\0'; i++)
    {
        int idx = str[i] - 65;
        check[idx] += 1;
    }
    int max = -1;
    int max_idx = 0;
    for (int i = 0; i < 26; i++)
    {
        if (check[i] > max)
        {
            max = check[i];
            max_idx = i;
        }
    }
    printf("%c", max_idx + 65);
    return 0;
}
