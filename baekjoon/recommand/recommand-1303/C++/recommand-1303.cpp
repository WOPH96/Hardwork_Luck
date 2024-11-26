// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;

char graph[101][101] = {0};
bool visited[101][101] = {0};
// 다른 변수 생성

// 입력, 테스트 출력

void print();
struct Node
{
    int y, x;
    Node(int y, int x) : y(y), x(x) {}
};

bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}
int bfs(Node start, char target)
{
    // 방문했거나 타겟이 아닌경우
    if (visited[start.y][start.x] || graph[start.y][start.x] != target)
    {
        return 0;
    }
    int cnt = 1;
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    queue<Node> q;
    q.push(start);
    visited[start.y][start.x] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            if (graph[ny][nx] == target)
            {
                cnt++;
                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }
    }
    return cnt;
}
void sol()
{
    int w_tot = 0;
    int b_tot = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt_w = 0;
        int cnt_b = 0;
        for (int j = 0; j < m; j++)
        {
            cnt_w = bfs(Node(i, j), 'W');
            cnt_b = bfs(Node(i, j), 'B');
            w_tot += cnt_w * cnt_w;
            b_tot += cnt_b * cnt_b;
            // cout << cnt_w << " " << cnt_b << endl;
        }
    }
    cout << w_tot << " " << b_tot << endl;
}

void input()
{
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("recommand-1303_input.txt", "r", stdin);
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
        cout << "\n";
    }
}
