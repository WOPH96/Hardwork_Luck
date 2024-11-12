// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
int l, r;
// 다른 변수 생성
int graph[51][51] = {0};
// 입력, 테스트 출력

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

struct Pos
{
    int y, x;
    Pos(int y, int x) : y(y), x(x) {}
};

void print();

bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < n);
}

bool bfs(int y, int x, bool (*visited)[51])
{
    if (visited[y][x])
        return false;
    queue<Pos> q;
    vector<Pos> unions;

    q.emplace(y, x);
    unions.emplace_back(y, x);
    visited[y][x] = true;
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
            int gap = abs(graph[ny][nx] - graph[now.y][now.x]);
            // 방문한 적 없고, 차이값이 l과 r 사이라면
            if (!visited[ny][nx] && (l <= gap && gap <= r))
            {
                q.emplace(ny, nx);
                unions.emplace_back(ny, nx);
                visited[ny][nx] = true;
            }
        }
    }
    int union_size = unions.size();
    if (union_size == 1)
        return true;
    int sum = 0;
    int avg = 0;
    for (auto &elem : unions)
    {
        // cout << elem.y << "," << elem.x << endl;
        sum += graph[elem.y][elem.x];
    }
    avg = sum / unions.size();
    // cout << "평균" << avg << endl;

    for (auto &elem : unions)
    {
        graph[elem.y][elem.x] = avg;
    }
    // print();
    return true;
}
void sol()
{
    int day = 0;
    while (true)
    {
        int space = 0;
        bool visited[51][51] = {false};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (bfs(i, j, visited))
                {
                    space++;
                }
            }
        }
        // 모든 나라가 독립적임
        if (space == n * n)
        {
            // cout << "independent ! " << endl;
            break;
        }
        day++;
        // break;
    }
    cout << day << endl;
}

void input()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
    freopen("graph_search-16234_input.txt", "r", stdin);
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
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
