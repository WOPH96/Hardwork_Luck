#include <stdio.h>
#define MAX_M 10000
#define STAMP dice[2][1]

char directions[MAX_M];
int grid[100][100] = {0};

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

int dice[5][4] =
{
    {0,1,0,0},
    {0,5,0,0},
    {4,6,3,1},
    {0,2,0,0},
    {0,1,0,0}
};

typedef enum
{
    LEFT,
    RIGHT,
    UP,
    DOWN
}Direct;

//ㅣLRUD
int dy[] = {0,0,-1,1};
int dx[] = {-1,1,0,0};


int get_dir(int idx)
{
    int dir;
    if(directions[idx]=='L')
        dir = LEFT;
    else if(directions[idx]=='R')
        dir = RIGHT;
    else if(directions[idx]=='U')
        dir = UP;
    else
        dir = DOWN;
    return dir;
}

void tumble_dice(Direct dir)
{
    if(dir == LEFT)
    {
        int temp = dice[2][3];
        for(int j = 3 ; j >0;j--)
        {
            dice[2][j] = dice[2][j-1];
        }
        dice[2][0] = temp;
    }

    else if (dir == RIGHT)
    {
        int temp = dice[2][0];
        for(int j=0;j<3;j++)
        {
            dice[2][j] = dice[2][j+1];
        }
        dice[2][3] = temp;
    }

    else if (dir== UP)
    {
        for(int i =4; i>0; i--)
        {
            dice[i][1] = dice[i-1][1];
        }
        dice[0][1] = dice[4][1];
        dice[2][3] = dice[4][1];
    }
    else if (dir ==DOWN)
    {
        for(int i =0; i<4; i++)
        {
            dice[i][1] = dice[i+1][1];
        }
        dice[4][1] = dice[0][1];
        dice[2][3] = dice[0][1];
    }
}

int main() {
    int n, m, r, c;
    scanf("%d %d %d %d", &n, &m, &r, &c);
    for (int i = 0; i < m; i++) {
        scanf(" %c", &directions[i]);
    }
    r--,c--;
    // Please write your code here.
    grid[r][c] = STAMP;
    for(int i =0; i<m;i++)
    {
        Direct dir = get_dir(i);
        int ny = r+dy[dir], nx = c+dx[dir];

        if(!is_valid(ny,nx)) continue;
        
        tumble_dice(dir);
        r = ny, c = nx;
        grid[r][c] = STAMP;

        
    }
    int sum = 0;
    for(int i = 0; i< n; i++)
    {
        for(int j =0; j<n; j++)
        {
            sum += grid[i][j];
            // printf("%d ",grid[i][j]);
        }
        // printf("\n");
    }
    printf("%d",sum);
    return 0;

}