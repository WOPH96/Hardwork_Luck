// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int n;
char graph[101][101] = {0};
// 입력변수생성

typedef struct
{
    int y;
    int x;
} Pos_t;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 입력, 테스트 출력
void input();
void print();

bool is_in_grid(const Pos_t &p)
{
    return (0 <= p.y && p.y < n &&
            0 <= p.x && p.x < n);
}
const typedef enum {
    CANNOT_SEPERATE,
    CAN_SEPERATE
} seperate;

bool bfs(Pos_t start, bool can_seperate, bool (*visited)[101])
{
    // 방문한 곳이면 측정했던 곳임. false
    if (visited[start.y][start.x])
        return false;

    queue<Pos_t> q;
    q.push(start);
    visited[start.y][start.x] = true;
    char same_color = graph[start.y][start.x];
    char similar_color = 0;

    switch (same_color)
    {
    case 'R':
        similar_color = 'G';
        break;
    case 'G':
        similar_color = 'R';
        break;
    default:
        break;
    }

    while (!q.empty())
    {
        Pos_t now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Pos_t next = {now.y + dy[i], now.x + dx[i]};
            if (is_in_grid(next) && !visited[next.y][next.x] &&
                (graph[next.y][next.x] == same_color ||
                 (can_seperate == CANNOT_SEPERATE && graph[next.y][next.x] == similar_color))) // 여기서부터!
            {
                q.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }

    return true;
}

void sol()
{
    int cnt_normal = 0;
    int cnt_divided = 0;
    bool visited1[101][101] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bfs({i, j}, CAN_SEPERATE, visited1))
            {
                cnt_normal++;
            }
        }
    }
    bool visited2[101][101] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bfs({i, j}, CANNOT_SEPERATE, visited2))
            {
                cnt_divided++;
            }
        }
    }
    cout << cnt_normal << " " << cnt_divided << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-10026_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
