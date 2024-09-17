// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;
bool graph[1001][1001];
// 입력변수생성

int max_distance = -99;
// 입력, 테스트 출력
void input();
void print();

typedef enum
{
    ROAD,
    WALL
} MAP;

typedef struct
{
    int y;
    int x;
} Pos_t;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool pos_in_map(const Pos_t &p)
{
    return (0 <= p.y && p.y < n &&
            0 <= p.x && p.x < m);
}

void bfs(const Pos_t &start, bool (*visited)[1001],
         bool (*is_rebuild)[1001], bool hammer)
{
    // 종료

    // 일단ㄱ
    queue<Pos_t> q;
    q.push(start);
    visited[start.y][start.x] = true;

    while (!q.empty())
    {
        Pos_t now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos_t next = {now.y + dy[i], now.x + dx[i]};
            if (pos_in_map(next))
            {
                if (graph[next.y][next.x] == ROAD &&
                    !visited[next.y][next.x])
                {
                    q.push(next);
                    visited[next.y][next.x] = true;
                }
                else if (graph[next.y][next.x] == WALL &&
                         !visited[next.y][next.x] &&
                         !is_rebuild[next.y][next.x] &&
                         hammer)
                {
                    is_rebuild[next.y][next.x] = true;
                    // visited[next.y][next.x] = true;
                    bool copy_visited[1001][1001] = {0};
                    copy(&visited[0][0], &visited[0][0] + n * m, copy_visited);
                    bfs(next, copy_visited, is_rebuild, 0);
                }
            }
        }
    }
    max_distance = max(max_distance, graph[n - 1][m - 1]);
    // 그래프 bool -> int로 변경 후 거리값 덧셈까지 진행.. 복사도 진행..
}

void sol()
{
    bool visited[1001][1001] = {0};
    bool is_rebuild[1001][1001] = {0};
    bfs({0, 0}, visited, 1);
    cout << max_distance << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-2206_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol(); // 여기서 벽 세우기

    return 0;
}

void input()
{
    cin >> n >> m;
    cin.ignore(true);
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = str[j] - '0';
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
