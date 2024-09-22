// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int n, m;
int graph[1001][1001] = {0};
bool visited[1001][1001][2] = {false}; // 0번 -> 벽 부순 후, 1번 -> 벽 부수기 전
// 다른 변수 생성

enum MAP
{
    ROAD,
    WALL
};

struct Node
{
    int y;
    int x;
    int dist; // 그래프 복사같은거 할필요도 없어서 좋은듯
    bool hammer;
    Node(int y, int x, int dist, int hammer)
        : y(y), x(x), dist(dist), hammer(hammer) {}
};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

// 입력, 테스트 출력
void input();
void print();

bool is_in_graph(const int &y, const int &x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}
int bfs()
{
    queue<Node> q;
    q.push(Node(0, 0, 1, true)); // 시작칸도 포함하여 세야 함
    visited[0][0][1] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.y == n - 1 && now.x == m - 1)
        {
            return now.dist;
        }
        for (int i = 0; i < 4; i++)
        {
            // next
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_in_graph(ny, nx))
                continue;
            // 이동할 수 있는 길이고, 방문한적 없으면 추가
            if (graph[ny][nx] == ROAD && !visited[ny][nx][now.hammer])
            {
                q.push(Node(ny, nx, now.dist + 1, now.hammer));
                visited[ny][nx][now.hammer] = true;
            }
            else if (graph[ny][nx] == WALL && now.hammer && !visited[ny][nx][0])
            {
                q.push(Node(ny, nx, now.dist + 1, 0));
                visited[ny][nx][0] = true;
            }
        }
    }
    return -1;
}
void sol()
{
    int result = bfs();
    cout << result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-2206_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();

    sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    cin.ignore(true);
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = st[j] - '0';
        }
    }
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
    cout << endl;
}
