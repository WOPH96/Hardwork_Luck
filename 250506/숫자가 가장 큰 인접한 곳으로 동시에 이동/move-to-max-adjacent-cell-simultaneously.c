#include <stdio.h>
#include <string.h>

int n, m, t;
int grid[21][21];
int visited[21][21];

int start[401][2];

typedef struct
{
    int y,x;
}Pos;

Pos bead[401];

void print()
{
    for(int i =0 ; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",visited[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_2(int temp[][21])
{
    for(int i =0 ; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",temp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void copy_arr(int target[][21],int src[][21])
{
    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(src[i][j] >=2)
                target[i][j] = 0;
            else
                target[i][j] = src[i][j];
        }
    }
}

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

void move()
{
    int dy[] = {-1,1,0,0};
    int dx[] = {0,0,-1,1};

    for(int time = 0; time<t; time++)
    {
        int temp_visited[21][21] = {0};
        copy_arr(temp_visited,visited);
        for(int i = 0; i<m; i++)
        {
            Pos now = bead[i];
            for(int dir = 0; dir<4; dir++)
            {
                int ny = now.y + dy[dir], nx = now.x + dx[dir];
                if(is_valid(ny,nx) && grid[ny][nx] > grid[now.y][now.x])
                {
                    temp_visited[ny][nx]++;
                    temp_visited[now.y][now.x]--;
                    bead[i].y =ny, bead[i].x = nx;
                    break;
                }
            }
        }
        // print(),print_2(temp_visited);
        copy_arr(visited,temp_visited);

    }
}
int main() {
    scanf("%d %d %d", &n, &m, &t);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &grid[i][j]);
    
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &bead[i].y, &bead[i].x);
        bead[i].y--,bead[i].x--;
        visited[bead[i].y][bead[i].x] = 1;
    }
    // Please write your code here.
    
    
    move();
    // print();
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(visited[i][j])
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}