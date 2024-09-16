// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
int graph[101][101];
// 입력변수생성
int max_height = -99;
typedef struct
{
    int y;
    int x;
} Pos_t;
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
// 입력, 테스트 출력
void input();
void print();

bool pos_in_grid(const Pos_t &p)
{
    return (0 <= p.y && p.y < n &&
            0 <= p.x && p.x < n);
}

// 안전구역 탐방
bool bfs(const Pos_t &start, int rain, bool (*visited)[101])
{
    // 침수지역이거나 방문했으면
    if (graph[start.y][start.x] <= rain || visited[start.y][start.x])
        return false;
    else
    {
        queue<Pos_t> q;
        q.push(start);
        visited[start.y][start.x] = true;
        while (!q.empty())
        {
            Pos_t now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                Pos_t next = {now.y + dy[i], now.x + dx[i]};
                if (pos_in_grid(next) &&
                    graph[next.y][next.x] > rain &&
                    !visited[next.y][next.x])
                {
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
        }
        return true;
    }
}

void sol()
{
    int max_safe_area = -99;
    for (int rain = 0; rain <= max_height; rain++)
    {
        int cnt = 0;
        bool visited[101][101] = {0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (bfs({i, j}, rain, visited))
                {
                    cnt++;
                }
            }
        }
        max_safe_area = max(max_safe_area, cnt);
    }
    cout << max_safe_area << endl;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-2468_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            max_height = max(max_height, graph[i][j]);
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // cout << max_height;
}
