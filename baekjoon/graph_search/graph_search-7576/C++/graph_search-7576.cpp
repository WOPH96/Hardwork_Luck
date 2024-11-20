// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int m, n;
int graph[1001][1001] = {0};
bool visited[1001][1001] = {false};
// 다른 변수 생성
struct Pos
{
    int y, x;
    Pos(int y, int x) : y(y), x(x) {}
};

enum info
{
    WALL = -1,
    TOMATO = 0,
    RIPE_TOMATO = 1
};

queue<Pos> tmt_q;

// 입력, 테스트 출력

void print();
bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}
void sol()
{
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {1, -1, 0, 0};
    while (!tmt_q.empty())
    {
        Pos now = tmt_q.front();
        tmt_q.pop();
        // 찾는조건없이 다돌아
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            if (!visited[ny][nx] && graph[ny][nx] == TOMATO)
            {
                tmt_q.emplace(ny, nx);
                visited[ny][nx] = true;
                graph[ny][nx] = graph[now.y][now.x] + 1;
            }
        }
    }
    int MX_val = -999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                cout << -1 << endl;
                return;
            }
            if (graph[i][j] > MX_val)
            {
                MX_val = graph[i][j];
            }
        }
    }
    cout << MX_val - 1 << endl;
}

void input()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == RIPE_TOMATO)
            {
                tmt_q.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-7576_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}