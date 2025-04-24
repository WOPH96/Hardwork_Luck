#include <stdio.h>
#include <string.h>
#define is_valid(y,x) ((0<=y && y<n && 0<=x && x<n))
#define max(a,b) ((a>b) ? a : b)
int n;
int grid[21][21];

int dy[] = {-1,-1,1,1};
int dx[] = {1,-1,-1,1};

typedef struct
{
    int y,x;
}Pos;

int max_sum = -1;

void dfs(int dir,int sum, int cnt, Pos now, Pos start, int visited[][21])
{
    if(dir==3 && start.y == now.y && start.x == now.x && cnt >=4)
    {
        max_sum = max(max_sum,sum);
        return;
    }
    if(visited[now.y][now.x]) return;
 
    sum += grid[now.y][now.x];
    visited[now.y][now.x] = 1;
    cnt++;
    // if(start.y == 4 &&start.x == 4)
    // {
    //     printf("now[%d,%d] sum = %d, dir = %d\n",now.y,now.x,sum,dir);
    // }
    // 원래 방향으로 쭉 가기
    for(int d = dir; d <4; d++)
    {
        int ny = now.y + dy[d], nx = now.x +dx[d];
        if(is_valid(ny,nx) )//&& visited[ny][nx]==0)
            dfs(d,sum,cnt,(Pos){ny,nx},start,visited);
        // else break;
    }
    // return sum;
}
void init_visited(int visited[][21])
{
    for(int i= 0; i<n;i++)
    {
        memset(visited[i],0,n*sizeof(int));
    }
}
int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
    
    // Please write your code here.
    for(int i=2;i<n;i++)
    {
        for(int j =1; j<n;j++)
        {
            int visited[][21] = {0};
            init_visited(visited);
            dfs(0,0,0,(Pos){i,j},(Pos){i,j},visited);
            // printf("[%d,%d] max_sum = %d\n",i,j,max_sum);
        }
    }
    printf("%d",max_sum);
    return 0;
}