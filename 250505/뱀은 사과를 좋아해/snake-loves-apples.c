#include <stdio.h>

int n, m, K;
int grid[101][101];
char cmdDir[1001];
int cmdNum[1001];

typedef enum
{
    EMPTY,
    BODY,
    HEAD,
    APPLE
}Map;

typedef struct
{
    int y,x;
}Pos;

typedef struct
{
    Pos head;
    Pos tail;
    int has_tail;
}Snake;

Pos dr[128];
Snake snake ={
    {0,0},
    {-1,-1},
    0
};

void init_dir()
{
    dr['R'] = (Pos){0,1};
    dr['L'] = (Pos){0,-1};
    dr['D'] = (Pos){1,0};
    dr['U'] = (Pos){-1,0};
}


void print(){

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

int sec = 0;

#define is_valid(y,x) (0<=y && y<n && 0<=x && x<n)

Pos path_q[100*100];
int ip=0, op =0;

int move_snake(char dir, int p)
{
    for(int i =0 ; i <p ; i++)
    {
        int ny = snake.head.y + dr[dir].y,
            nx = snake.head.x + dr[dir].x;
            
        sec++;
        if(!is_valid(ny,nx)) return 1;
        if(grid[ny][nx] == BODY) return 1;

        if (grid[ny][nx] == APPLE)
        {
            
            if(!snake.has_tail) // 꼬리는 사과 먹었을때만 생김
                snake.tail = path_q[op++]; // 꼬리 업데이트는 빈칸에서만 
            snake.has_tail++;
            grid[snake.head.y][snake.head.x] = BODY;
            grid[ny][nx] = HEAD;
            snake.head.y = ny, snake.head.x = nx;
            path_q[ip++] = snake.head; // 경로는 꼬리 있을때 의미있음
            
        }
        else if(grid[ny][nx] == EMPTY)
        {
            if(snake.has_tail) // 꼬리 있을때만 tail업데이트 
            {
                grid[snake.tail.y][snake.tail.x] = EMPTY;
                grid[snake.head.y][snake.head.x] = BODY;
                snake.tail = path_q[op++];
            }
            
            else
            {
                grid[snake.head.y][snake.head.x] = EMPTY;
            
            }
            grid[ny][nx] = HEAD;
            snake.head.y = ny, snake.head.x = nx;

            if(snake.has_tail)
                path_q[ip++] = snake.head;
        }

        // printf("%c %d\n",dir,p);
        // for(int i = op; i < ip; i++)
        // {
        //     printf("tail[%d,%d], path_q[%d,%d]\n",snake.tail.y,snake.tail.x,
        //                                         path_q[i].y, path_q[i].x);
        // }
        // printf("\n");

        
    }
    return 0;
    
}

int main(void) {
    scanf("%d %d %d", &n, &m, &K);
    
    for (int i = 0; i < m; i++) {
        int c, r;
        scanf("%d %d", &r, &c);
        r--,c--;
        grid[r][c] = APPLE;
    }
    

    init_dir();
    grid[snake.head.y][snake.head.x] = HEAD;
    path_q[ip++] = snake.head;
    // print();
    int game_over = 0;
    for (int i = 0; i < K; i++) {
        char d;
        int p;
        scanf(" %c %d", &d, &p);
        game_over = move_snake(d,p);
        // print();
        if(game_over){
            printf("%d",sec);
            return 0;
        }
    }
    printf("%d",sec);
    
    // Please write your code here.
    
    return 0;
}