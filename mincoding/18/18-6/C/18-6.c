#include <stdio.h>

// 필요 변수 선언
char black[4];
char town[3][3] = {
    {'C', 'D', 'A'},
    {'B', 'M', 'Z'},
    {'Q', 'P', 'O'}};
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("18-6_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%s", black);

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    scanf("%s", black);

    // 변수 입력 공간
}

int main()
{
    // input_f();
    input();
    // printf("%s", black);
    int blacked_person = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (town[i][j] == black[k])
                {
                    blacked_person++;
                }
            }
        }
    }

    printf("%d명", blacked_person);
    return 0;
}
