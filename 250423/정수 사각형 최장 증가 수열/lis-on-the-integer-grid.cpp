#include <cstdio>
#include <queue>
int n;
int grid[501][501];

#define max(a,b) (a>b ? a : b)

using namespace std;

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

void bfs(Pos start)
{
    if(visited[start.y][start.x]) return;
    // start.visit_cnt = 1;
    visited[start.y][start.x] = 1;
    queue<Pos> q;
    // Pos queue[500*500];
    // int op =0, ip =0;
    // queue[ip++] = start;
    q.push(start);
    int dy[] = {0,0,1,-1};
    int dx[] = {1,-1,0,0};
    
    // int cnt = 1;
    // printf("In BFS start from %d\n",grid[start.y][start.x]);
    // while(ip>op)
    while(!q.empty())
    {
        // Pos now = queue[op++];
        Pos now = q.front();
        q.pop();
        for(int i = 0; i<4;i++)
        {
            int ny = now.y+dy[i], nx = now.x+dx[i];
            if(is_valid(ny,nx) && visited[ny][nx]< now.visit_cnt+1 &&
                grid[ny][nx] > grid[now.y][now.x])
            {
                // printf("[%d,%d] = [%d]\n",ny,nx,grid[ny][nx]);
                visited[ny][nx] = now.visit_cnt+1;
                // queue[ip++] = {ny,nx,now.visit_cnt+1};
                q.push({ny,nx,now.visit_cnt+1});
                // cnt++;
            }
        }
    }
    // return cnt;
}
void print_visit(){
    for(int i = 0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            // max_res = max(max_res,visited[i][j]);
            printf("%d ",visited[i][j]);
            // printf("[%d,%d] = %d\n",i,j,res);
            // max_res = max(max_res,res);
        }
        printf("\n");
        
    }
    printf("\n");
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    // Please write your code here.

    

    for(int i = 0; i<n; i++)
    {
        for (int j =0; j<n; j++)
        {
            // printf("[%d,%d] = %d\n",i,j,grid[i][j]);
            bfs({i,j,1});
            // print_visit();
            
            // max_res = max(max_res,res);
        }
    }    
    int max_res = -1;
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<n;j++)
        {
            max_res = max(max_res,visited[i][j]);
        }
    }
    printf("%d",max_res);
        
    // printf("%d\n",max_res);
    return 0;
}