#include <stdio.h>

#define MAX_M 2500

int T;
int n, m;

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

typedef struct
{
    int y,x;
}Pos;

typedef struct
{
    Pos curr_pos;
    Pos dir;
    int alive;
}Marble;

Marble marble[MAX_M];
Pos direction[128];

void init_dir()
{
    direction['U'] = (Pos){-1,0};
    direction['D'] = (Pos){1,0};
    direction['R'] = (Pos){0,1};
    direction['L'] = (Pos){0,-1};
}

void print(int grid[][50])
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

void move(Marble *marble,int visited[][50])
{
    if(!marble->alive) return;

    Pos now = marble->curr_pos;
    int ny = now.y + marble->dir.y, nx = now.x + marble->dir.x;
    if(is_valid(ny,nx))
    {
        visited[now.y][now.x]--;
        visited[ny][nx]++;
        marble->curr_pos = (Pos){ny,nx};
    }
    else
    {
        //방향전환
        marble->dir.y *= -1;
        marble->dir.x *= -1;
    }
}

void check_and_remove(int visited[][50])
{
    for(int i =0 ;i<n; i++)
    {
        for(int j =0; j<n;j++)
        {
            if(visited[i][j] >=2)
            {
                visited[i][j] = 0;
                for(int k = 0; k<m;k++)
                {
                    if(marble[k].curr_pos.y == i && 
                        marble[k].curr_pos.x == j )
                    {
                        marble[k].alive =0;
                        
                    }
                }

            }
        }
    }
}

int main() {
    init_dir();
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int visited[50][50] = {0};
        for (int i = 0; i < m; i++) {
            char c;
            scanf("%d %d %c", &marble[i].curr_pos.y, &marble[i].curr_pos.x, &c);
            marble[i].curr_pos.y--, marble[i].curr_pos.x--;
            marble[i].alive = 1;
            marble[i].dir = direction[c];
            visited[marble[i].curr_pos.y][marble[i].curr_pos.x] = 1;
        }
        // Please write your code here.
        // for (int i = 0; i < m; i++) {
        //     printf("%d번째 curr[%d,%d], dir[%d,%d], alive : %d\n",
        //             i+1,marble[i].curr_pos.y,marble[i].curr_pos.x,
        //             marble[i].dir.y,marble[i].dir.x,marble[i].alive);
        // }
        
        for(int time = 0; time <2*n; time++)
        {
            for(int i = 0; i<m; i++)
            {
                move(&marble[i],visited);
                
            }
            // print(visited);
            check_and_remove(visited);
            // break;
        }

        int cnt = 0;
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(visited[i][j] == 1)
                cnt++;
            }
        }
        printf("%d\n",cnt);


    }
    return 0;
}