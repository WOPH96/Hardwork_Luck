#include <stdio.h>

int n, m;
int grid[21][21];

typedef struct
{
    int y,x;
}Pos;

Pos num_pos[401];

void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(const Pos a, const Pos b, const int a_val, const int b_val)
{
    num_pos[b_val] = a;
    num_pos[a_val] = b;
    grid[a.y][a.x] = b_val;
    grid[b.y][b.x] = a_val;
}

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)
void move()
{
    int dy[] ={0,0,1,-1,1,1,-1,-1};
    int dx[] ={1,-1,0,0,-1,1,-1,1};
    for(int i =1; i<=n*n;i++)
    {
        Pos now = num_pos[i];
        int max_val = -1;
        Pos max_pos;
        for(int dir = 0; dir<8; dir++)
        {
            int ny = now.y+dy[dir], nx = now.x +dx[dir];
            if(is_valid(ny,nx) && grid[ny][nx] > max_val)
            {
                max_pos = (Pos){ny,nx};
                max_val = grid[ny][nx];
            }
        }
        swap(now,max_pos,i,max_val);
        
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
            num_pos[grid[i][j]] = (Pos){i,j};
        }
    }
    // Please write your code here.

    // for(int i =1; i<=n*n; i++)
    // {
    //     printf("%d Position [%d,%d]\n",i,num_pos[i].y,num_pos[i].x);
    // }

    for(int i=0; i<m;i++)
    {
        move();
        
    }
    print();
    
    return 0;
}