// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int test_case;
int m, n, k;

// 입력변수생성

class Pos
{
public:
    int y;
    int x;
};

// 입력, 테스트 출력
void input();
void print(int (*MAP)[51]);

void visiting(const Pos &p, int (*visited)[51])
{
    visited[p.y][p.x] = true;
}

bool search_bfs(const Pos &start, int (*graph)[51], int (*visited)[51])
{
    // 배추가 없거나, 방문한 곳이면 false
    if (!graph[start.y][start.x] || visited[start.y][start.x])
        return false;
    // 배추 주변 전부 탐색하여, 방문한 곳으로 만들기
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<Pos> q;
    q.push(start);
    visiting(start, visited);
    while (!q.empty())
    {
        Pos now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            // 다음 위치가
            Pos next = {now.y + dy[i], now.x + dx[i]};
            // 맵 범위 안에 있고, 배추가 있고, 방문을 안했으면
            if (0 <= next.y && next.y < n &&
                0 <= next.x && next.x < m &&
                graph[next.y][next.x] &&
                !visited[next.y][next.x])
            {
                q.push(next);
                visiting(next, visited);
            }
        }
    }
    // 조건 만족한 순간 이미 true
    return true;
}

void sol(int (*graph)[51], int (*visited)[51])
{
    int cnt = 0;
    // print(graph);
    // print(visited);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 배추단지를 찾으면
            if (search_bfs(Pos{i, j}, graph, visited))
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-1012_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    // sol();

    return 0;
}

void input()
{
    cin >> test_case;
    while (test_case)
    {
        cin >> m >> n >> k;
        int graph[51][51]{0};
        int visited[51][51]{0};
        Pos cabbage;
        for (int i = 0; i < k; i++)
        {
            cin >> cabbage.x >> cabbage.y;
            graph[cabbage.y][cabbage.x] = 1;
        }

        sol(graph, visited);
        test_case--;
    }
}
void print(int (*MAP)[51])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
