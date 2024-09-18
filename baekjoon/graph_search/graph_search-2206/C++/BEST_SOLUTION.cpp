#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
vector<vector<int>> graph;

struct Node
{
    int y, x, dist;
    bool broke_wall;
    Node(int y, int x, int dist, bool broke_wall) : y(y), x(x), dist(dist), broke_wall(broke_wall) {}
};

bool is_valid(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

int bfs()
{
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    queue<Node> q;
    q.push(Node(0, 0, 1, false));
    visited[0][0][0] = true;

    while (!q.empty())
    {
        Node current = q.front();
        q.pop();

        if (current.y == n - 1 && current.x == m - 1)
        {
            return current.dist;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];

            if (!is_valid(ny, nx))
                continue;

            if (graph[ny][nx] == 0 && !visited[ny][nx][current.broke_wall])
            {
                visited[ny][nx][current.broke_wall] = true;
                q.push(Node(ny, nx, current.dist + 1, current.broke_wall));
            }
            else if (graph[ny][nx] == 1 && !current.broke_wall && !visited[ny][nx][1])
            {
                visited[ny][nx][1] = true;
                q.push(Node(ny, nx, current.dist + 1, true));
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("graph_search-2206_input.txt", "r", stdin);
    cin >> n >> m;
    graph.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = row[j] - '0';
        }
    }

    int result = bfs();
    cout << result << endl;

    return 0;
}