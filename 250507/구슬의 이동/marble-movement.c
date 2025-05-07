#include <stdio.h>
#include <stdlib.h>
#define MAX_M 2501


int n, m,t,k;

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
    int speed;
    int id;
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

void move(Marble *marble)
{
    if(!marble->alive) return;

    Pos now = marble->curr_pos;
    int repeat = marble->speed;
    // 1초에 가는 스피드
    for(int v = 0; v<repeat; v++)
    {
        int ny = now.y + marble->dir.y, nx = now.x + marble->dir.x;

        if(is_valid(ny,nx))
        {
            marble->curr_pos = (Pos){ny,nx};
            now.y = ny, now.x = nx;
        }
        else
        {
            // 방향 전환
            repeat++; // 1초 지연 없이 바로 한번 더 
            marble->dir.y *= -1;
            marble->dir.x *= -1;
        }
    }
}

typedef struct
{
    int size;
    Marble arr[MAX_M];
}Vector;

void init_vector(Vector arr[][50])
{
    for(int i =0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            arr[i][j].size = 0; 
        }
    }
}

void push(Vector *v, Marble m)
{
    v->arr[v->size++] = m;
}

int cmp(const void *a, const void *b)
{
    Marble *src = (Marble*)a;
    Marble *dst = (Marble*)b;
    
    if(src->speed == dst->speed)
        return (src->id < dst->id);
    return (src->speed < dst->speed);

}

//
void check_and_remove()
{
    int cell_cnt[50][50] = {0}; // 각 칸에 구슬이 몇 개 있는지 카운트
    Vector destory[50][50];
    init_vector(destory);
    // 1. 살아있는 구슬들 위치 카운트
    for(int i = 0; i < m; i++)
    {
        if(marble[i].alive) {
            int y = marble[i].curr_pos.y;
            int x = marble[i].curr_pos.x;
            cell_cnt[y][x]++;
        }
    }

    // 2. k개 초과하여 겹치는 칸들 저장 
    for(int i = 0; i < m; i++)
    {
        if(marble[i].alive) {
            int y = marble[i].curr_pos.y;
            int x = marble[i].curr_pos.x;
            if(cell_cnt[y][x] > k)
            {
                // marble[i].alive = 0;
                push(&destory[y][x],marble[i]);
            }
                
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(marble[i].alive) {
            int y = marble[i].curr_pos.y;
            int x = marble[i].curr_pos.x;
            if(cell_cnt[y][x] > k)
            {
                // marble[i].alive = 0;
                qsort(&destory[y][x].arr,destory[y][x].size,sizeof(Marble),cmp);
                for(int j = k; j<m; j++)
                {
                    int reomve_idx = destory[y][x].arr[j].id;
                    marble[reomve_idx].alive = 0;
                }
                cell_cnt[y][x] = k;
            }
                
        }
    }
    //정렬 후 k번쨰부터 사망처리 
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j=0;j<n; j++)
    //     {
    //         printf("%d ",cell_cnt[i][j]);
    //     }
    //     printf("\n");
    // }
}


int main() {
    init_dir();
    scanf("%d %d %d %d", &n, &m, &t, &k);

    for (int i = 0; i < m; i++) {
        char c;
        scanf("%d %d %c %d", &marble[i].curr_pos.y, &marble[i].curr_pos.x, &c, &marble[i].speed );
        marble[i].curr_pos.y--, marble[i].curr_pos.x--;
        marble[i].alive = 1;
        marble[i].dir = direction[c];
        marble[i].id = i;
    }

    for(int time = 0; time < t; time++)
    {
        // 모든 구슬 이동
        for(int i = 0; i < m; i++)
            move(&marble[i]);
        // 겹치는 구슬 제거
        check_and_remove();
        // break;
    }

    // 살아있는 구슬 count
    int cnt = 0;
    for (int i = 0; i < m; i++)
        if (marble[i].alive) cnt++;

    printf("%d\n", cnt);



    return 0;
}
