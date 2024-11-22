// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int l, r, c;

// 다른 변수 생성
struct Node
{
    int z, y, x;
    int dist;
    Node() : z(0), y(0), x(0), dist(0) {}
    Node(int z, int y, int x, int d) : z(z), y(y), x(x), dist(d) {}
    friend ostream &operator<<(ostream &out, Node &n)
    {
        out << "(" << n.z << "," << n.y << "," << n.x << ")";
        return out;
    }
    bool operator==(Node &n)
    {
        return (this->z == n.z &&
                this->y == n.y &&
                this->x == n.x);
    }
};
#define START 'S'
#define EMPTY '.'
#define WALL '#'
#define END 'E'
// 입력, 테스트 출력
struct INFO
{
    Node start;
    Node end;
};

void print(char (*graph)[31][31]);

bool is_valid(int z, int y, int x)
{
    return (0 <= z && z < l &&
            0 <= y && y < r &&
            0 <= x && x < c);
}

void sol(char (*graph)[31][31], INFO &init)
{
    int dz[] = {1, -1, 0, 0, 0, 0}; // 위쪽, 아래쪽
    int dy[] = {0, 0, -1, 1, 0, 0}; // 북쪽, 남쪽
    int dx[] = {0, 0, 0, 0, 1, -1}; // 동쪽, 서쪽
    bool visited[31][31][31] = {false};
    queue<Node> q;
    q.push(init.start);
    visited[init.start.z][init.start.y][init.start.x] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        // 찾았을떄!
        if (now == init.end)
        {
            cout << "Escaped in " << now.dist << " minute(s)." << endl;
            return;
        }
        //====
        for (int i = 0; i < 6; i++)
        {
            int nz = now.z + dz[i];
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(nz, ny, nx))
                continue;
            if (!visited[nz][ny][nx] && graph[nz][ny][nx] != WALL)
            {
                q.emplace(nz, ny, nx, now.dist + 1);
                visited[nz][ny][nx] = true;
            }
        }
    }
    cout << "Trapped!" << endl;
}

void input()
{
    while (true)
    {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;
        char graph[31][31][31] = {0};
        INFO init;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> graph[i][j][k];
                    if (graph[i][j][k] == START)
                    {
                        init.start = {i, j, k, 0};
                    }
                    else if (graph[i][j][k] == END)
                    {
                        init.end = {i, j, k, 0};
                    }
                }
            }
        }
        sol(graph, init);
        // print(graph);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-6593_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print(char (*graph)[31][31])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << graph[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    // cout << init.start << init.end << endl;
}
