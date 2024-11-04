// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m, k;
int graph[1001][1001] = {0};
bool visited[1001][1001][11] = {false};
// 다른 변수 생성

struct Node
{
    int y, x, dist;
    int hammer;

    Node(int y, int x, int d, int h) : y(y), x(x), dist(d), hammer(h) {}
};
// 입력, 테스트 출력
enum MAP
{
    ROAD = 0,
    WALL
};
void print();
bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}
void sol()
{
    queue<Node> q;
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    // start
    q.emplace(0, 0, 1, k);
    visited[0][0][k] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        // 타겟 찾았다면
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
            // 다음것이 벽이고, 망치가 있고, 부순 뒤 방문한적 없다면 뿌숴
            if (graph[ny][nx] == WALL && now.hammer > 0 && !visited[ny][nx][now.hammer - 1])
            {
                q.emplace(ny, nx, now.dist + 1, now.hammer - 1);
                visited[ny][nx][now.hammer - 1] = true;
            }
            // 다음것이 길이고, 방문한적 없다면, 원래 가던 길로 가
            if (graph[ny][nx] == ROAD && !visited[ny][nx][now.hammer])
            {
                q.emplace(ny, nx, now.dist + 1, now.hammer);
                visited[ny][nx][now.hammer] = true;
            }
        }
    }
    // 못도착하고 끝났다면
    cout << -1 << endl;
}

void input()
{
    cin >> n >> m >> k;
    cin.ignore();

    string str;
    for (int i = 0; i < n; i++)
    {
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
    // freopen("graph_search-14442_input.txt", "r", stdin);
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
