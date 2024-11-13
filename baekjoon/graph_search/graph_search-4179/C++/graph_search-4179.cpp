// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int r, c;
// 다른 변수 생성
char graph[1001][1001] = {0};
int fire_graph[1001][1001] = {0};
bool visited[1001][1001] = {false};
// bool fire_visited[1001][1001] = {false};
// 입력, 테스트 출력

#define WALL '#'
#define ROAD '.'
#define FIRE 'F'
#define JIHOON 'J'
#define INIT_VAL 1000000

struct Pos
{
    int y, x, mins;

    Pos(int y, int x) : y(y), x(x) {}
    Pos(int y, int x, int m) : y(y), x(x), mins(m) {}
};

queue<Pos> q_jh;
queue<Pos> q_fire;

void print();

bool is_valid(int y, int x)
{
    return (0 <= y && y < r &&
            0 <= x && x < c);
}

void sol()
{
    int sy = q_jh.front().y;
    int sx = q_jh.front().x;
    visited[sy][sx] = true;

    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {1, -1, 0, 0};
    while (!q_fire.empty())
    {
        Pos now = q_fire.front();
        q_fire.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            if ((graph[ny][nx] == ROAD || graph[ny][nx] == JIHOON) &&
                fire_graph[ny][nx] == INIT_VAL)
            {
                q_fire.emplace(ny, nx, now.mins + 1);
                fire_graph[ny][nx] = now.mins + 1;
            }
        }
    }
    while (!q_jh.empty())
    {
        Pos now = q_jh.front();
        q_jh.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
            {
                cout << now.mins + 1 << endl;
                return;
            }
            if (!visited[ny][nx] &&
                graph[ny][nx] == ROAD && now.mins + 1 < fire_graph[ny][nx])
            {
                q_jh.emplace(ny, nx, now.mins + 1);
                visited[ny][nx] = true;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

void input()
{
    cin >> r >> c;
    cin.ignore();

    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < c; j++)
        {
            graph[i][j] = str[j];
            fire_graph[i][j] = INIT_VAL;
            if (graph[i][j] == JIHOON)
            {
                q_jh.emplace(i, j, 0);
            }
            else if (graph[i][j] == FIRE)
            {
                q_fire.emplace(i, j, 0);
                fire_graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-4179_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << fire_graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << WALL << ROAD << FIRE << endl;
    cout << q_jh.front().y << q_jh.front().x << endl;
}
