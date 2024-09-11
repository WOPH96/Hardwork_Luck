// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n;
vector<int> graph[26];
// 입력변수생성

// 입력, 테스트 출력
void input();
void print();

bool visited[26][26]{0};

class Pos
{
public:
    int y;
    int x;
};
//       우   좌  하  상
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void print_visited()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void visiting(const Pos &p)
{
    visited[p.y][p.x] = true;
}

bool dfs(Pos start)
{
    // 종료 조건
    // 방문했거나 아파트가 없으면
    if (visited[start.y][start.x] || graph[start.y][start.x] == 0)
        return 0;

    Pos next;
    visited[start.y][start.x] = true;
    print_visited();
    for (int i = 0; i < 4; i++)
    {
        next = {start.y + dy[i], start.x + dx[i]};
        // next.y = start.y + dy[i];
        // next.x = start.x + dx[i];

        // 그래프 내부에 있고,
        // 아파트가 있으며
        // 방문하지 않은 곳이면
        if (0 <= next.y && next.y < n &&
            0 <= next.x && next.x < n &&
            graph[next.y][next.x] &&
            !visited[next.y][next.x])
        {

            // 다음 곳으로 가자
            dfs(next);
            // 한번이라도 찾았으면 최종적으로 true 반환
            return true;
        }
    }
    // 한번도 못찾았으면 최종적으로 false 반환
    return false;
}

void sol()
{
    int town = 0;
    int house;
    priority_queue<int, vector<int>, greater<int>> houses;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Pos start{i, j};
            cout << "(" << i << "," << j << ")" << endl;
            if (dfs(start))
            {
                town++;
                cout << "단지탐색완료" << endl;
            }
        }
    }
    cout << town;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-2667_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void input()
{
    cin >> n;
    cin.ignore(true);

    for (int i = 0; i < n; i++)
    {
        string row;
        getline(cin, row);
        for (auto &elem : row)
        {
            graph[i].push_back(elem - '0');
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (auto &elem : graph[i])
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}
