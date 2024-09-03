#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 필요 변수 선언
int rows, cols;
int **sizes;
// 필요 변수 선언
void input_f()
{
    FILE *fp = fopen("min_rectangle_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    fscanf(fp, "%d %d\n", &rows, &cols);
    sizes = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        sizes[i] = (int *)malloc(cols * sizeof(int));
    }

    char str[100];
    char *token;
    int i = 0, j = 0;

    // printf("배열을 입력하세요: ");
    fgets(str, 100, fp); // 한 줄 입력

    token = strtok(str, "[,] "); // 첫 번째 토큰 추출
    while (token != NULL)
    {
        sizes[i][j++] = atoi(token);
        if (j == cols)
        {
            i++;
            j = 0;
        }
        token = strtok(NULL, "[,] ");
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);

    // 변수 입력 공간
}
int solution() // int **sizes, size_t sizes_rows, size_t sizes_cols)
{

    int answer = 0;
    // 입력된 배열 출력 (예시)
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         printf("%d ", sizes[i][j]);
    //     }
    //     printf("\n");
    // }
    /*
    아이디어:
    가로/세로

    가로중에 젤긴거 vs 세로중에 젤긴거

    10 1
    5 70
    3 80

    priority queue
    사용하면 쉽게 될듯?


    10 80





    */
    return answer;
}

int main()
{
    input_f();
    solution();
    // input();

    return 0;
}
