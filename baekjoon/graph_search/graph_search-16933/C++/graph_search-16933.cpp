// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define INIT_DIST 99999
using namespace std;

// 입력변수생성
int n, m, k;
// 다른 변수 생성
int graph[1001][1001] = {0};
bool visited[1001][1001][11] = {false};
// 입력, 테스트 출력

struct Node
{
    int y, x, dist;
    int hammer;
    bool is_afternoon;

    Node(int y, int x, int d, int h, bool day) : y(y), x(x), dist(d), hammer(h), is_afternoon(day) {}
};
enum MAP
{
    ROAD = 0,
    WALL
};

void print(int, int, int, int);
bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}
void sol()
{
    int dy[4] = {0, 0, -1, 1};
    int dx[4] = {1, -1, 0, 0};
    queue<Node> q;
    q.emplace(0, 0, 1, k, true);
    visited[0][0][k] = true;
    int min_dist = INIT_DIST;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.y == n - 1 && now.x == m - 1)
        {
            cout << now.dist << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            // 다음경로가 벽인데, 해머가 있고, 방문한적 없으면

            if (graph[ny][nx] == WALL && now.hammer > 0 && !visited[ny][nx][now.hammer - 1])
            {
                // 낮이라면
                if (now.is_afternoon)
                {
                    // 벽부수고 이동, 밤으로 변환
                    q.emplace(ny, nx, now.dist + 1, now.hammer - 1, false);
                    visited[ny][nx][now.hammer - 1] = true;
                }
                // 밤이라면
                else
                {
                    // 머물렀다가, 낮일때 부수고 이동 -> 밤으로 변환
                    // q.emplace(ny, nx, now.dist + 2, now.hammer - 1, false);
                    q.emplace(now.y, now.x, now.dist + 1, now.hammer, true);
                }

                // print(ny, nx, now.dist, now.hammer);
            }
            // 다음경로가 길이고, 방문한적 없으면
            else if (graph[ny][nx] == ROAD && !visited[ny][nx][now.hammer])
            {

                q.emplace(ny, nx, now.dist + 1, now.hammer, !now.is_afternoon);
                visited[ny][nx][now.hammer] = true;
                // print(ny, nx, now.dist, now.hammer);
            }
        }
    }
    if (min_dist == INIT_DIST)
        cout << -1 << endl;
    else
        cout << min_dist << endl;
}

void input()
{
    cin >> n >> m >> k;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j] - '0';
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-16933_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print(int y, int x, int dist, int hammer)
{
    cout << dist << " " << hammer << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < m; j++)
        {
            if (i == y && j == x)
                cout << "*" << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}
