#include <stdio.h>

int n, y, x;
int grid[101][101];

//상하좌우
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

int main() {
    scanf("%d %d %d", &n, &y, &x);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Please write your code here.
    
    int find;
    do
    {
        find = 0;
        for(int i = 0;i<4;i++)
        {
            int ny = y+dy[i], nx = x+dx[i];
            if(is_valid(ny,nx) && grid[ny][nx] > grid[y][x])
            {
                printf("%d ",grid[y][x]);
                y = ny, x =nx;
                
                find = 1;
                break;
            }
        }
        
    }while(find);

    printf("%d",grid[y][x]);

    return 0;
}