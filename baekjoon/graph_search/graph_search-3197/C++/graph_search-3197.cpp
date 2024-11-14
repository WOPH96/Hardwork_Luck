// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;
char prev_graph[1501][1501] = {0};
bool visited_sw1[1501][1501] = {false};
bool visited_sw2[1501][1501] = {false};
// char next_graph[1501][1501] = {0};
// char empty_graph[100][1501][1501] = {0};
// 다른 변수 생성
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
struct Pos
{
    int y, x;
    Pos(int y, int x) : y(y), x(x) {}
    friend ostream &operator<<(ostream &out, Pos &p)
    {
        out << "(" << p.y << "," << p.x << ")";
        return out;
    }
};

struct Swans
{
    Pos start;
    Pos target;
    Swans() : start({0, 0}), target({0, 0}) {}
};

Swans sw;

queue<Pos> water_q;

// 입력, 테스트 출력

void print(char (*prev)[1501]); //, char (*next)[1501]);

#define WATER '.'
#define ICE 'X'
#define SWAN 'L'

bool is_valid(int y, int x)
{
    return (y >= 0 && y < n && x >= 0 && x < m);
}

// void melting(char (*prev)[1501], char (*next)[1501])
// {

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             next[i][j] = prev[i][j];
//             if (prev[i][j] == WATER)
//             {
//                 continue;
//             }
//             else
//             {
//                 // cout << i << "," << j << ":" << prev[i][j] << endl;

//                 for (int k = 0; k < 4; k++)
//                 {
//                     int ny = i + dy[k];
//                     int nx = j + dx[k];
//                     if (!is_valid(ny, nx))
//                     {
//                         continue;
//                     }
//                     if (prev[ny][nx] == WATER && next[i][j] == ICE)
//                     {

//                         next[i][j] = WATER;
//                     }
//                 }
//             }
//         }
//     }
// }
void melting(char (*prev)[1501], queue<Pos> &water_queue)
{
    queue<Pos> new_water_queue;
    vector<Pos> postemp;
    while (!water_queue.empty())
    {
        Pos water = water_queue.front();
        water_queue.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = water.y + dy[i];
            int nx = water.x + dx[i];
            if (!is_valid(ny, nx))
                continue;

            if (prev[ny][nx] == ICE)
            {
                // next[ny][nx] = WATER;
                new_water_queue.emplace(ny, nx);
                postemp.emplace_back(ny, nx);
            }
        }
    }
    for (Pos waterpos : postemp)
    {
        prev[waterpos.y][waterpos.x] = WATER;
    }

    swap(water_queue, new_water_queue);
}

bool bfs(char (*ice)[1501])
{

    queue<Pos> q_sw1;
    queue<Pos> q_sw2;

    q_sw1.push(sw.start);
    visited_sw1[sw.start.y][sw.start.x] = true;
    q_sw2.push(sw.target);
    visited_sw2[sw.target.y][sw.target.x] = true;
    while (!q_sw1.empty() || !q_sw2.empty())
    {
        if (!q_sw1.empty())
        {
            Pos now = q_sw1.front();
            q_sw1.pop();
            if (visited_sw2[now.y][now.x])
            {
                // 다른 백조가 간 지점 방문했으면
                // cout << "GOT IT !" << endl;
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];

                if (!is_valid(ny, nx))
                    continue;
                if (!visited_sw1[ny][nx] && ice[ny][nx] != ICE)
                {
                    q_sw1.emplace(ny, nx);
                    visited_sw1[ny][nx] = true;
                }
            }
        }
        if (!q_sw2.empty())
        {
            Pos now = q_sw2.front();
            q_sw2.pop();
            if (visited_sw1[now.y][now.x])
            {
                // 다른 백조가 간 지점 방문했으면
                // cout << "GOT IT !" << endl;
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];

                if (!is_valid(ny, nx))
                    continue;
                if (!visited_sw2[ny][nx] && ice[ny][nx] != ICE)
                {
                    q_sw2.emplace(ny, nx);
                    visited_sw2[ny][nx] = true;
                }
            }
        }
    }
    return false;
}
void sol(char (*prev)[1501]) //, char (*next)[1501])
{
    char(*prev_ice)[1501] = prev;
    // char(*next_ice)[1501] = next;
    char(*temp)[1501];
    int day = 1;
    // bool meet_success = false;
    while (true)
    {
        melting(prev_ice, water_q);
        fill(&visited_sw1[0][0], &visited_sw1[n + 1][m + 1], false);
        fill(&visited_sw2[0][0], &visited_sw2[n + 1][m + 1], false);
        // PREV가 원하는 배열
        // 백조가 만날 수 있다면 break
        if (bfs(prev_ice))
        {
            // meet_success = true;
            break;
        }

        // 빙산 녹이기

        day++;
        // cout << "DAY" << day << endl;
        // print(prev_ice);
    }
    cout << day << endl;
}

void input()
{
    cin >> n >> m;
    cin.ignore();
    int num_swan = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            prev_graph[i][j] = str[j];
            if (prev_graph[i][j] == SWAN)
            {
                if (num_swan == 0)
                    sw.start = {i, j};
                else
                    sw.target = {i, j};
                num_swan++;
                water_q.emplace(i, j);
            }
            else if (prev_graph[i][j] == WATER)
            {
                water_q.emplace(i, j);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-3197_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol(prev_graph); //, next_graph);
    // print();

    return 0;
}

void print(char (*prev)[1501]) //, char (*next)[1501])
{
    // cout << sw.start << " " << sw.target << endl;
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
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << next[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << "================" << endl;
}
