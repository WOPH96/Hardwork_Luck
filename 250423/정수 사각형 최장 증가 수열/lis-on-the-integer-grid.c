#include <stdio.h>

int n;
int grid[500][500];

#define max(a,b) (a>b ? a : b)
#define is_valid(y,x) ((0<=y&&y<n && 0<=x && x<n)? 1: 0)
typedef struct
{
    int y,x,visit_cnt;
}Pos;

int visited[500][500];

int bfs(Pos start)
{
    if(visited[start.y][start.x]) return 0;
    start.visit_cnt = 1;
    Pos queue[500*500];
    int op =0, ip =0;
    queue[ip++] = start;
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};
    int cnt = 1;
    while(ip>op)
    {
        Pos now = queue[op++];
        for(int i = 0; i<4;i++)
        {
            int ny = now.y+dy[i], nx = now.x+dx[i];
            if(is_valid(ny,nx) && visited[ny][nx]< now.visit_cnt &&
                grid[ny][nx] > grid[now.y][now.x])
            {
                visited[ny][nx] = now.visit_cnt+1;
                queue[ip++] = (Pos){ny,nx,now.visit_cnt+1};
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Please write your code here.

    int max_res = -1;

    for(int i = 0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            int res = bfs((Pos){i,j,0});
            // printf("[%d,%d] = %d\n",i,j,res);
            max_res = max(max_res,res);
        }
    }    
    printf("%d",max_res);
    return 0;
}