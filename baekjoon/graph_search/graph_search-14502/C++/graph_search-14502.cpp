// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 입력변수생성
int n, m;
int MAP[9][9] = {0};
// 입력변수생성

typedef struct
{
    int y;
    int x;
} Pos_t;

queue<Pos_t> virus;
vector<Pos_t> empty_space;

int max_zero = -1;
// 입력, 테스트 출력
void input();
void print(int (*now_MAP)[9]);
bool is_inmap(const Pos_t &p)
{
    return (0 <= p.y && p.y <= n &&
            0 <= p.x && p.x <= m);
}

void copy_map(int (*now_MAP)[9])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            now_MAP[i][j] = MAP[i][j];
        }
    }
}
int get_zero_space(int (*now_MAP)[9])
{
    int total_count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (now_MAP[i][j] == 0)
            {
                total_count++;
            }
        }
    }
    return total_count;
}
void bfs() //, bool (*visited)[9])
{
    // 바이러스 좌표 깊은복사
    queue<Pos_t> q = virus;
    // q.push(start);
    // visited[start.y][start.x] = true;

    // 벽 세운 현재 맵 복사
    int now_MAP[9][9];
    copy_map(now_MAP);

    // 좌표 이동
    int dx[4]{1, -1, 0, 0};
    int dy[4]{0, 0, 1, -1};
    while (!q.empty())
    {
        Pos_t now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos_t next = {now.y + dy[i], now.x + dx[i]};
            if ( // 맵 안에 있어야 하고, 빈공간이면
                is_inmap(next) &&
                !now_MAP[next.y][next.x])
            // !visited[next.y][next.x])
            {
                q.push(next);
                // visited[next.y][next.x] = true;
                now_MAP[next.y][next.x] = 2;
            }
        }
    }
    // if (get_zero_space(now_MAP) > 25)
    //     print(now_MAP);
    max_zero = max(max_zero, get_zero_space(now_MAP));
}

void make_wall(int cnt)
{
    // 바이러스 퍼뜨리기
    if (cnt == 3)
    {
        bfs();
        return;
    }
    for (auto &empty_pos : empty_space)
    {
        if (MAP[empty_pos.y][empty_pos.x] == 0)
        {
            MAP[empty_pos.y][empty_pos.x] = 1;
            make_wall(cnt + 1);
            MAP[empty_pos.y][empty_pos.x] = 0;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-14502_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print(MAP);
    make_wall(0);
    cout << max_zero << endl;
    return 0;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 2)
                virus.push({i, j});
            else if (MAP[i][j] == 0)
                empty_space.push_back({i, j});
        }
    }
}
void print(int (*now_MAP)[9])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << now_MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // cout << "virus position" << endl;
    // for (auto &elem : virus)
    // {
    //     cout << "(" << elem.y << "," << elem.x << ")" << "  ";
    // }
    // cout << endl;

    // cout << "zero empty position" << endl;
    // for (auto &elem : empty_space)
    // {
    //     cout << "(" << elem.y << "," << elem.x << ")" << "  ";
    // }
    // cout << endl;
}
