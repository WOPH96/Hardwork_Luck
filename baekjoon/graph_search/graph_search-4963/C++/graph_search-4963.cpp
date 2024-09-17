// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int w, h;
// 입력변수생성

// 입력, 테스트 출력
void input();
void print(bool (*graph)[51]);

// void sol(){
// }
typedef enum
{
    SEA,
    LAND
} MAP;

typedef struct
{
    int y;
    int x;
} Pos_t;

const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-4963_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    // print();
    // sol();

    return 0;
}

bool in_grid(const Pos_t &p)
{
    return (0 <= p.y && p.y <= h &&
            0 <= p.x && p.x <= w);
}

bool bfs(const Pos_t &start, bool (*graph)[51], bool (*visited)[51])
{
    // 방문했거나 장소가 바다라면 패스
    if (visited[start.y][start.x] || graph[start.y][start.x] == SEA)
        return false;
    else
    {
        queue<Pos_t> q;
        q.push(start);
        visited[start.y][start.x] = true;
        while (!q.empty())
        {
            Pos_t now = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                // 상하좌우 대각선은 전부 이어져있는 곳
                Pos_t next = {now.y + dy[i], now.x + dx[i]};

                // 맵 내부에 있고, 땅이어야하고, 방문한적이 없다면
                if (in_grid(next) &&
                    graph[next.y][next.x] == LAND &&
                    !visited[next.y][next.x])
                {
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
            }
        }
        return true;
    }
}

void sol(bool (*graph)[51], bool (*visited)[51])
{
    int cnt_of_land = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (bfs({i, j}, graph, visited))
                cnt_of_land++;
        }
    }
    cout << cnt_of_land << endl;
}

void input()
{
    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            return;
        bool graph[51][51] = {SEA};
        bool visited[51][51] = {0};
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> graph[i][j];
            }
        }
        sol(graph, visited);
        // print(graph);
    }
}
void print(bool (*graph)[51])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
