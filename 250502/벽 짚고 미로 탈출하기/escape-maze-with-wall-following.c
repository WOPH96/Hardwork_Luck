#include <stdio.h>

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

int n, curr_x, curr_y;
char maze[101][101];
int visited[101][101];

#define WALL '#'
#define EMPTY '.'

int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};

int sec = 0;

void check_right_wall(int *y, int *x,int *curr_dir)
{
    int right_dir = (*curr_dir+3)%4;
    int ny = *y+dy[right_dir], nx = *x+dx[right_dir];

    if(maze[ny][nx] == EMPTY)
    {
        *curr_dir = right_dir;
        *x = nx;
        *y = ny;
        visited[ny][nx] = 1;
        sec++;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d %d", &curr_y, &curr_x);
    for (int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
    }
    
    // Please write your code here.
    curr_x--,curr_y--;

    int ny = -1, nx =-1;

    int curr_dir = 0;
    
    // int debug_count = 0;
    while(1)
    {
        // debug_count++;
        // 오른쪽에 벽이없으면 벽방향으로 이동
        check_right_wall(&curr_y,&curr_x,&curr_dir); 
        
        // 진행방향으로 이동 
        ny = curr_y + dy[curr_dir], nx = curr_x + dx[curr_dir];
        // printf("curr[%d,%d,%c],next[%d,%d,%c]\n",
        //         curr_y,curr_x,maze[curr_y][curr_x],
        //         ny,nx,maze[ny][nx]);
        if(!is_valid(ny,nx))
        { // 격자 벗어났다면 
            sec++;
            break;
        } 
        if(maze[ny][nx] == EMPTY)
        { // 진행방향이 비어있다면 그대로 이동 
            if(visited[ny][nx])
            {
                printf("-1");
                return 0;
            }
            curr_y = ny, curr_x = nx;
            visited[ny][nx] = 1;
            sec++;
        }
        else if(maze[ny][nx] == WALL)
        {// 진행방향이 벽이라면 왼쪽으로 회전만 하기
            // printf("ger",curr_y,curr_x,ny,nx);
            curr_dir = (curr_dir+1)%4;

        }
        // if(debug_count >10) break;
    }
    printf("%d",sec);
    return 0;
}