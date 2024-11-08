// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;
int prev_graph[301][301] = {0};
int next_graph[301][301] = {0};
// 다른 변수 생성
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
// 입력, 테스트 출력

void print(int (*prev)[301], int (*next)[301]);

struct Pos
{
    int y, x;
    Pos(int y, int x) : y(y), x(x) {}
};
enum Water
{
    WATER = 0
};

bool is_valid(int y, int x)
{
    return (y >= 0 && y < n && x >= 0 && x < m);
}

void melting(int (*prev)[301], int (*next)[301])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (prev[i][j] == WATER)
            {
                continue;
            }
            else
            {
                // cout << i << "," << j << ":" << prev[i][j] << endl;
                next[i][j] = prev[i][j];
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (!is_valid(ny, nx))
                    {
                        continue;
                    }
                    if (prev[ny][nx] == WATER && next[i][j] != WATER)
                    {

                        next[i][j] -= 1;
                    }
                }
            }
        }
    }
}

bool bfs(int y, int x, int (*ice)[301], bool (*visited)[301])
{
    if (visited[y][x] || ice[y][x] == WATER)
        return false;

    queue<Pos> q;
    q.emplace(y, x);
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
            if (!visited[ny][nx] && ice[ny][nx] != WATER)
            {
                q.emplace(ny, nx);
                visited[ny][nx] = true;
            }
        }
    }
    return true;
}
void sol(int (*prev)[301], int (*next)[301])
{
    int(*prev_ice)[301] = prev;
    int(*next_ice)[301] = next;
    int(*temp)[301];
    int year = 1;
    int cnt_of_land = 0;
    while (true)
    {
        // 빙산 녹이기
        melting(prev_ice, next_ice);
        // print(prev_ice, next_ice);

        // SWAP
        temp = prev_ice;
        prev_ice = next_ice;
        next_ice = temp;

        // PREV가 원하는 배열
        bool visited[301][301] = {false};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (bfs(i, j, prev_ice, visited))
                {
                    cnt_of_land++;
                }
            }
        }
        if (cnt_of_land > 1)
        {
            cout << year << endl;
            return;
        }
        else if (cnt_of_land == 0)
        {
            cout << 0 << endl;
            return;
        }

        // 더 녹여야 한다면,
        // next 초기화
        cnt_of_land = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                next_ice[i][j] = 0;
            }
        }

        year++;
    }
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> prev_graph[i][j];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-2573_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol(prev_graph, next_graph);
    // print();

    return 0;
}

void print(int (*prev)[301], int (*next)[301])
{
    cout << "================" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << prev[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << next[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "================" << endl;
}
