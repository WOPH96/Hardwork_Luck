#include <stdio.h>
#include <math.h>
int n, m, r, c;

int grid[100][100];

typedef enum 
{
    EMPTY,
    BOMB
}Info;

typedef struct
{
    int y,x;
}Pos;

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)
void print()
{
    for(int i = 0; i<n; i++)
    {
        for(int j= 0; j<n; j++)
        {
            
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void bfs(Pos start)
{
    Pos q[100*100];
    int ip = 0, op =0, size = 0;
    q[ip++] = start;
    size++;
    grid[start.y][start.x] = BOMB;
    int dy[] ={0,0,-1,1};
    int dx[] ={1,-1,0,0};
    for(int time = 1; time <= m; time++)
    {// 한 타임 내에서 모든 폭탄에 대해 해야함
        int start_size = size;
        while(start_size--)
        {
            // printf("size = %d\n",size);
            Pos now = q[op++];
            size--;

            for(int i =0; i<4; i++)
            {
                int ny = now.y + dy[i]*pow(2,time-1);
                int nx = now.x + dx[i]*pow(2,time-1);
                
                if(is_valid(ny,nx) && grid[ny][nx] != BOMB)
                {
                    grid[ny][nx] = BOMB;
                    q[ip++] = (Pos){ny,nx};
                    size++;

                }
            }
            q[ip++] = now; // 다시 넣기 
            size++;
            // printf("size = %d\n",size);
        }
        // print();
    }
}



int main() {
    scanf("%d %d %d %d", &n, &m, &r, &c);
    r--,c--;
    // Please write your code here.
    
    bfs((Pos){r,c});

    int bomb_cnt = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j= 0; j<n; j++)
        {
            if(grid[i][j] == BOMB)
                bomb_cnt++;
            // printf("%d ",grid[i][j]);
        }
        // printf("\n");
    }
    printf("%d",bomb_cnt);
    return 0;
}