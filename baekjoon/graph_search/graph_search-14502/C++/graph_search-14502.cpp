// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

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

vector<Pos_t> virus;
vector<Pos_t> empty_space;

// 입력, 테스트 출력
void input();
void print(int (*now_MAP)[9]);
bool is_inmap(const Pos_t &p)
{
    return (0 <= p.y && p.y <= n &&
            0 <= p.x && p.x <= m);
}
void bfs(Pos_t start, int (*now_MAP)[9], bool (*visited)[9])
{
    queue<Pos_t> q;
    q.push(start);
    visited[start.y][start.x] = true;
    int dx[4]{1, -1, 0, 0};
    int dy[4]{0, 0, 1, -1};
    while (!q.empty())
    {
        Pos_t now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos_t next = {now.y + dy[i], now.x + dx[i]};
            if ( // 맵 안에 있어야 하고, 빈공간이어야 하고, 방문한적없어야
                is_inmap(next) &&
                !now_MAP[next.y][next.x] &&
                !visited[next.y][next.x])
            {
                q.push(next);
                visited[next.y][next.x] = true;
                now_MAP[next.y][next.x] = 2;
            }
        }
    }
    print(now_MAP);
}

void sol()
{
    int max_zero_space = -1;

    // 초기 맵 상태 복사하기
    int init_MAP[9][9];
    bool visited[9][9] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            init_MAP[i][j] = MAP[i][j];
        }
    }
    // 벽 세우기

    // 바이러스 퍼뜨리기
    for (auto &virus_pos : virus)
    {
        bfs(virus_pos, init_MAP, visited);
    }

    // 현재 맵에서 0 카운트해서, 최댓값 구하기
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
    sol();

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
                virus.push_back({i, j});
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
