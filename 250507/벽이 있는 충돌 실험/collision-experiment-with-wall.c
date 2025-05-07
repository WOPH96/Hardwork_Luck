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

void move(Marble *marble)
{
    if(!marble->alive) return;

    Pos now = marble->curr_pos;
    int ny = now.y + marble->dir.y, nx = now.x + marble->dir.x;

    if(is_valid(ny,nx))
    {
        marble->curr_pos = (Pos){ny,nx};
    }
    else
    {
        // 방향 전환
        marble->dir.y *= -1;
        marble->dir.x *= -1;
    }
}

// 여기부터 개선된 check_and_remove!
void check_and_remove_fast()
{
    int cell_cnt[50][50] = {0}; // 각 칸에 구슬이 몇 개 있는지 카운트

    // 1. 살아있는 구슬들 위치 카운트
    for(int i = 0; i < m; i++)
    {
        if(marble[i].alive) {
            int y = marble[i].curr_pos.y;
            int x = marble[i].curr_pos.x;
            cell_cnt[y][x]++;
        }
    }
    // 2. 겹치는 칸의 구슬 모두 죽이기
    for(int i = 0; i < m; i++)
    {
        if(marble[i].alive) {
            int y = marble[i].curr_pos.y;
            int x = marble[i].curr_pos.x;
            if(cell_cnt[y][x] >= 2)
                marble[i].alive = 0;
        }
    }
}


int main() {
    init_dir();
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
            char c;
            scanf("%d %d %c", &marble[i].curr_pos.y, &marble[i].curr_pos.x, &c);
            marble[i].curr_pos.y--, marble[i].curr_pos.x--;
            marble[i].alive = 1;
            marble[i].dir = direction[c];
        }

        for(int time = 0; time < 2 * n; time++)
        {
            // 모든 구슬 이동
            for(int i = 0; i < m; i++)
                move(&marble[i]);
            // 겹치는 구슬 제거 (성능 개선 버전 사용)
            check_and_remove_fast();
        }

        // 살아있는 구슬 count
        int cnt = 0;
        for (int i = 0; i < m; i++)
            if (marble[i].alive) cnt++;

        printf("%d\n", cnt);
    }
    return 0;
}
