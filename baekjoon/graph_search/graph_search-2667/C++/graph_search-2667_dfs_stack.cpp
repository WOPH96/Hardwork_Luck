// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
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

int dfs(Pos start)
{
    // 초기부터 해당없는 놈 거르기
    if (graph[start.y][start.x] == 0 || visited[start.y][start.x])
        return 0;

    stack<Pos> st;
    st.push(start);
    // 큐에 넣는다 = 방문처리
    visiting(start);
    int house = 0;
    while (!st.empty())
    {
        // print_visited();
        Pos now = st.top();
        st.pop();
        house++;
        for (int i = 0; i < 4; i++)
        {
            Pos next = {now.y + dy[i], now.x + dx[i]};
            // cout << "next -> (" << next.y << "," << next.x << ")" << endl;
            if (
                0 <= next.y && next.y < n &&
                0 <= next.x && next.x < n &&
                graph[next.y][next.x] &&
                !visited[next.y][next.x])
            {

                st.push(next);
                visiting(next);
            }
        }
    }

    // 단지 수 반환
    return house;
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
            // cout << "(" << i << "," << j << ")" << endl;
            house = dfs(start);
            if (house)
            {
                town++;
                houses.push(house);
                // cout << "단지탐색완료" << endl;
            }
        }
    }
    cout << town << endl;
    while (!houses.empty())
    {
        cout << houses.top() << endl;
        houses.pop();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-2667_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
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
