// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int r, c;
char graph[21][21] = {0};
// 다른 변수 생성
int max_dist = -1;
bool visited[26] = {false};

struct Node
{
    int y;
    int x;
    int dist;
    Node(int y, int x, int d) : y(y), x(x), dist(d) {}
};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
// 입력, 테스트 출력

void input();
void print();
bool is_in_graph(int y, int x)
{
    return (0 <= y && y < r &&
            0 <= x && x < c);
}
bool is_visited(const char &alpha)
{
    return visited[alpha - 'A'];
}

void dfs(Node now)
{
    max_dist = max(max_dist, now.dist);
    for (int i = 0; i < 4; i++)
    {
        int ny = now.y + dy[i];
        int nx = now.x + dx[i];
        if (!is_in_graph(ny, nx))
            continue;
        if (!is_visited(graph[ny][nx]))
        {
            visited[graph[ny][nx] - 'A'] = true;
            dfs(Node(ny, nx, now.dist + 1));
            visited[graph[ny][nx] - 'A'] = false;
        }
    }
}
void sol()
{
    visited[graph[0][0] - 'A'] = true;
    dfs(Node(0, 0, 1));
    cout << max_dist << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-1987_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> graph[i][j];
        }
    }
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
}
