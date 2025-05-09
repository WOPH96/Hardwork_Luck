#include <stdio.h>

#define MAX_NUM 50

int n, m;
int grid[MAX_NUM][MAX_NUM];

typedef struct
{
    int y,x;
}Pos;

int mem[MAX_NUM][MAX_NUM];

int dfs(Pos now)
{
    if(mem[now.y][now.x] == 0) return 0;
    if(mem[now.y][now.x] != -1) 
    {
        mem[now.y][now.x];
    }

    int max_jump = 0;
    for(int ny = now.y+1; ny<n; ny++)
    {
        for(int nx = now.x+1; nx<n; nx++)
        {
            // if(ny == now.y && nx == now.x) continue;
            int res =0;
            if(grid[ny][nx] > grid[now.y][now.x])
            {
                res = dfs((Pos){ny,nx}) +1;
            }
            // else
            // {
            //     mem[ny][nx] = 0;
            // }
            if(max_jump < res) max_jump = res;
        }
    }
    mem[now.y][now.x] = max_jump;
    return mem[now.y][now.x];
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &grid[i][j]);
            mem[i][j] = -1;
        }
    }
    

    
    // Please write your code here.

    printf("%d\n",dfs((Pos){0,0})+1);
    
    // for(int i =0 ; i< n; i++)
    // {
    //     for(int j =0; j<n; j++)
    //     {
    //         printf("%d ",mem[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}