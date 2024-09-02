#include <stdio.h>

// 필요 변수 선언
char cards[15];
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("18-4_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%s ", cards);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%s ", cards);

    // 변수 입력 공간
}

int main()
{

    input();

    // printf("%s", cards);

    int check[26] = {0};

    for (int i = 0; cards[i] != '\0'; i++)
    {
        int index = cards[i] - 65;
        // printf("%d ", index);
        check[index] += 1;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (check[i] != 0)
        {
            cnt++;
        }
    }

    printf("%d개", cnt);

    return 0;
}
