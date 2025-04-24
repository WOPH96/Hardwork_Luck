#include <stdio.h>

#define max(a,b) ((a>b)?a:b)
#define is_valid(y,x) ((0<=y && y<n && 0<=x && x<n))

int n, m;
int grid[20][20];

typedef enum
{
    EMPTY,
    GOLD
}Info;

typedef struct
{
    int y,x;
}Pos;

int max_gold_count = -1;

void cmp(int k, int gold_count)
{
    int cost = k*k + (k+1)*(k+1);
    int earn = gold_count * m;
    if(earn>cost)
        max_gold_count = max(max_gold_count,gold_count); 
}

void print(int grid[][20])
{
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bfs(Pos start, int k)
{
    int visited[20][20] = {0};
    int gold_count = 0;
    Pos queue[20*20];
    int ip = 0, op = 0;
    int qsize = 0;

    visited[start.y][start.x] = 1;
    queue[ip++] = start;
    qsize ++;
    int dy[] = {0,0,-1,1};
    int dx[] = {1,-1,0,0};
    if(grid[start.y][start.x] == GOLD) gold_count++;

    //k 범위로 탐색 동안 찾은 gold count 체크 
    for(int time = 0; time < k; time++)
    {
        int size = qsize;
        for(int i = 0 ; i <size; i ++)
        {
            Pos now = queue[op++];
            qsize--;
            for(int i = 0 ; i < 4; i++)
            {
                int ny = now.y+dy[i], nx = now.x + dx[i];
                if(is_valid(ny,nx) && !visited[ny][nx])
                {
                    queue[ip++] = (Pos){ny,nx};
                    qsize++;
                    visited[ny][nx] = 1;
                    if(grid[ny][nx] == GOLD) gold_count++;
                }
            }
        }
    }
    // print(visited);
    // if(k==2)
        // printf("[%d,%d] k = %d, gold_count = %d\n",start.y,start.x,k,gold_count);
    cmp(k,gold_count);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    cmp(0,1);
    // Please write your code here.
    for(int i = 0; i <n; i++)
    {
        for(int j = 0; j < n ; j++)
        {
            for(int k = 1;k<=n;k++)
                bfs((Pos){i,j},k);    
        }
    }

    printf("%d",max_gold_count);
    return 0;
}