#include <stdio.h>

#define SOM 'S'
#define YEON 'Y'

#define NUM_PRINCESS 7

// 필요 변수 선언
char seat[5][6];
// 필요 변수 선언

typedef struct
{
    int y;
    int x;
} Pos;

void print_debug();

Pos comb[NUM_PRINCESS];
int result = 0;

int isconnected()
{
    int visited[5][5] = {0};
    Pos q[26 * 26] = {0};
    int ip = 0, op = 0;

    // 첫번째 학생
    q[ip++] = comb[0];
    visited[comb[0].y][comb[0].x] = 1;

    int cnt = 1;
    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};

    while (ip > op)
    {
        Pos now = q[op++];
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            for (int i = 0; i < NUM_PRINCESS; i++)
            {
                // 다음 이동자리에 comb중 하나가 있고, 방문하지 않았는가 ?
                if (comb[i].y == ny && comb[i].x == nx && !visited[ny][nx])
                {
                    Pos temp = {ny, nx};
                    q[ip++] = temp;
                    visited[ny][nx] = 1;
                    cnt++;
                }
            }
        }
    }

    return (cnt == NUM_PRINCESS);
}

void backtrack(int start, int depth, int s_cnt)
{
    if (depth == NUM_PRINCESS) // && s_cnt >= 4)
    {
        if (s_cnt >= 4 && isconnected())
        {
            result++;
            return;
        }
    }
    else
    {
        for (int i = start; i < 25; i++)
        {
            // 3 -> i=0, j=3
            // 9 -> i=1, j=4
            Pos temp = {i / 5, i % 5};
            // printf("%d %d\n", temp.y, temp.x);
            comb[depth] = temp;

            backtrack(i + 1, depth + 1, s_cnt + (seat[temp.y][temp.x] == SOM));
        }
    }
}

void sol()
{
    // 0~24에서 NUM_PRINCESS개 조합 뽑기
    backtrack(0, 0, 0);
    printf("%d", result);
}

void input_f()
{
    FILE *fp = fopen("back_tracking-1941_input.txt", "r");
    if (fp == NULL)
    {
        printf("파일 열기 실패 \n ");
        return;
    }

    // 변수 입력 공간

    // fscanf(fp, "%d ", &num1);
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s", seat[i]);
    }

    // 변수 입력 공간
    fclose(fp);
}

void input()
{
    // 변수 입력 공간

    // scanf( "%d ",  &num2);
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", seat[i]);
    }

    // 변수 입력 공간
}

int main()
{
    input_f();
    // input();
    // print_debug();
    sol();

    return 0;
}

void print_debug()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", seat[i]);
    }
}
