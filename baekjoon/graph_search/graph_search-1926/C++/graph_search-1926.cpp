// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;
int graph[501][501] = {0};
bool visited[501][501] = {false};

// 다른 변수 생성

// 입력, 테스트 출력

void print();

struct Pos
{
    int y, x;
    Pos(int y, int x) : y(y), x(x) {}
};

enum Paint
{
    white = 0,
    black
};
bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}
int bfs(int cy, int cx)
{
    if (visited[cy][cx] || graph[cy][cx] == white)
        return 0;
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {1, -1, 0, 0};
    queue<Pos> q;
    q.emplace(cy, cx);
    int area = 1;
    visited[cy][cx] = true;
    while (!q.empty())
    {
        Pos now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            if (graph[ny][nx] == black && !visited[ny][nx])
            {
                area++;
                q.emplace(ny, nx);
                visited[ny][nx] = true;
            }
        }
    }
    return area;
}

void sol()
{
    int cnt = 0;
    int max_area = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int paint_cnt = bfs(i, j);
            max_area = max(max_area, paint_cnt);
            if (paint_cnt)
                cnt++;
        }
    }
    cout << cnt << "\n"
         << max_area << endl;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-1926_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

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
