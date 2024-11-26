// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
int graph[101][101] = {0};

struct Mark
{
    int mark, dist;
    Mark() : mark(0), dist(0) {}
    Mark(int m, int d) : mark(m), dist(d) {}
};
struct Pos
{
    int y, x, mark, dist;
    // Mark m_info;
    Pos() : y(0), x(0), mark(0), dist(0) {}
    Pos(int y, int x) : y(y), x(x) {}
    Pos(int y, int x, int m) : y(y), x(x), mark(m) {}
    Pos(int y, int x, int m, int d) : y(y), x(x), mark(m), dist(d) {}
    friend ostream &operator<<(ostream &out, Pos &p)
    {
        out << p.y << "," << p.x << "," << p.mark;
        return out;
    }
};

enum MAP
{
    SEA = 0,
    LAND = 1
};
queue<Pos> land_voyage_q;
Mark visited_voyage[101][101];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
// 입력, 테스트 출력

void print();
void print(int y, int x, int mark);
bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < n);
}
void bfs_make_bridge()
{
    int min_dist = 99999;
    while (!land_voyage_q.empty())
    {
        Pos now = land_voyage_q.front();
        land_voyage_q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            // 방문한적 없고, 내 땅이 아닌곳 (바다,남의 섬만 돌기)
            if (!visited_voyage[ny][nx].dist &&
                graph[ny][nx] != now.mark)
            {

                land_voyage_q.emplace(ny, nx, now.mark, now.dist + 1);
                visited_voyage[ny][nx] = {now.mark, now.dist + 1};
                // print();
                // print(ny, nx, now.mark);
            }
            // 다음 땅이 다른 곳에서 방문한 곳이라면
            //  => 남의 섬에서 온 다리라면..
            if (visited_voyage[ny][nx].dist > 0 &&
                visited_voyage[ny][nx].mark != now.mark)
            {

                min_dist = min(min_dist, now.dist + visited_voyage[ny][nx].dist);

                // return;
            }
        }
    }
    cout << min_dist << endl;
}
bool bfs_mark_land(int y, int x, int marking, bool (*visited_land)[101])
{
    if (visited_land[y][x] || graph[y][x] == SEA)
        return false;

    queue<Pos> q;
    q.emplace(y, x);
    visited_land[y][x] = true;
    graph[y][x] = marking;

    while (!q.empty())
    {
        Pos now = q.front();
        q.pop();
        bool is_find = 0;
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            // 다음
            if (graph[ny][nx] == SEA && !is_find)
            //! visited_voyage[now.y][now.x])
            {
                land_voyage_q.emplace(now.y, now.x, marking);
                // visited_voyage[now.y][now.x] = true;
                is_find = 1;
            }
            if (!visited_land[ny][nx] && graph[ny][nx] == LAND)
            {
                q.emplace(ny, nx);
                visited_land[ny][nx] = true;
                graph[ny][nx] = marking;
            }
        }
    }
    return true;
}
void sol()
{
    int marking = 2;
    bool visited_land[101][101] = {false};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bfs_mark_land(i, j, marking, visited_land))
            {
                marking++;
            }
        }
    }
    bfs_make_bridge();
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

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-2146_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << visited_voyage[i][j].mark << " ";
        }
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << visited_voyage[i][j].dist << " ";
        }
        cout << endl;
    }

    cout << endl;

    // while (!land_voyage_q.empty())
    // {
    //     cout << land_voyage_q.front() << endl;
    //     land_voyage_q.pop();
    // }
}

void print(int y, int x, int mark)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            if (i == y && j == x)
                cout << mark << " ";
            else
                cout << 0 << " ";
        }

        cout << endl;
    }

    cout << endl;
}