#include <stdio.h>

int n;
int grid[100][100];

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}Direction;

//상하좌우
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

typedef struct
{
    int y,x;
}Pos;

void change_dir(const Pos now, Direction *cur_dir)
{
    //0은 그대로 
    if(grid[now.y][now.x] == 1)
    {
        // 00<-> 11
        // 10<-> 01
        *cur_dir ^= 3; //0b11;
    }
    else if(grid[now.y][now.x] == 2)
    {
        // 00<-> 10
        // 01<-> 11
        *cur_dir ^= 2; //0b10;
    }
}

int max_sec = -1;
#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)
void start(Pos now, Direction cur_dir)
{
    int sec = 1;
    // printf("st[%d,%d], dir[%d] ",st.y,st.x,cur_dir);
    change_dir(now,&cur_dir);
    // printf("%d \n",cur_dir);
    int ny = -1, nx = -1;

    while(1)
    {
        sec++;
        ny = now.y + dy[cur_dir], nx = now.x + dx[cur_dir];
        if(is_valid(ny,nx))
        {
            change_dir((Pos){ny,nx},&cur_dir);
            now.y = ny, now.x = nx;
            
        }
        else
            break;
    }
    // sec++;
    if(sec > max_sec) max_sec = sec;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    // Please write your code here.

    
    for(int j=0;j<n;j++)
    {
        start((Pos){0,j},DOWN);
    }

    for(int j=0;j<n;j++)
    {
        start((Pos){n-1,j},UP);
    }

    for(int i=0;i<n;i++)
    {
        start((Pos){i,0},RIGHT);
    }

    for(int i=0;i<n;i++)
    {
        start((Pos){i,n-1},LEFT);
    }
    
    printf("%d",max_sec);
    return 0;
}