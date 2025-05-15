#include <stdio.h>

int n, k;
int grid[100][100];
int visited[100][100];
int answer[100][100];
typedef enum
{
    EMPTY,
    TANG,
    BAD_TANG
}Info;

typedef struct
{
    int y,x;
    int sec;
}Pos;

Pos bads_q[100*100];
int ip =0, op =0;

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

void bfs()
{
    int dy[] = {0,0,-1,1};
    int dx[] = {1,-1,0,0};

    while(op < ip)
    {
        Pos now = bads_q[op++];

        for(int i = 0 ; i<4; i++)
        {
            int ny= now.y + dy[i], nx = now.x +dx[i];

            if(is_valid(ny,nx) && !visited[ny][nx] &&
                grid[ny][nx] == TANG)
            {
                bads_q[ip++] = (Pos){ny,nx,now.sec+1};
                visited[ny][nx] = 1;
                answer[ny][nx] = now.sec+1;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
            if(grid[i][j]==EMPTY)
                answer[i][j] = -1;
            else if(grid[i][j] == BAD_TANG)
            {
                bads_q[ip++] = (Pos){i,j,0};
                visited[i][j] = 1;
                answer[i][j] = 0;
            }
        
        }
    }
    // Please write your code here.

    bfs();

    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(answer[i][j] == 0  && grid[i][j] == TANG)
                answer[i][j] = -2;
            printf("%d ",answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}