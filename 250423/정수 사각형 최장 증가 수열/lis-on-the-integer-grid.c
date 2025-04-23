#include <stdio.h>

int n;
int grid[501][501];

#define max(a,b) (a>b ? a : b)

typedef struct
{
    int y,x,visit_cnt;
}Pos;

int is_valid(int y,int x)
{
    return (0<=y && y<n &&
             0<=x && x<n);
}

int visited[501][501];

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int dfs(Pos now)
{
    if(visited[now.y][now.x]) return visited[now.y][now.x];
    // now.visit_cnt = 1;
    visited[now.y][now.x] = 1;
    // Pos queue[500*500];
    // int op =0, ip =0;
    // queue[ip++] = now;

    
    // int cnt = 1;
    // printf("In BFS now from %d\n",grid[now.y][now.x]);

    for(int i = 0; i<4;i++)
    {
        int ny = now.y+dy[i], nx = now.x+dx[i];
        if(is_valid(ny,nx) &&
            grid[ny][nx] > grid[now.y][now.x])
        {
            int res = dfs((Pos){ny,nx}) + 1;
            if(visited[now.y][now.x] < res) visited[now.y][now.x] = res;
        }
    }
    return visited[now.y][now.x];

    // return cnt;
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
            // printf("[%d,%d] = %d\n",i,j,grid[i][j]);
            int res = dfs((Pos){i,j});
            // print_visit();
            
            max_res = max(max_res,res);
        }
    }    

    // for(int i =0; i<n;i++)
    // {
    //     for(int j =0; j<n;j++)
    //     {
    //         max_res = max(max_res,visited[i][j]);
    //     }
    // }
    printf("%d",max_res);
        
    // printf("%d\n",max_res);
    return 0;
}