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
    int x;
    int y;
};

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

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

bool bfs(Pos start)
{
    queue<Pos> q;
    q.push(start);
    visited[start.y][start.x] = true;
    int cnt = 0;
    while(!q.empty()){
        cnt++;
        Pos now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++){
            Pos next = {now.y + dy[i], now.x + dx[i]};
            if (0 <= next.y && next.y < n &&
                0 <= next.x && next.x < n &&
                graph[next.y][next.x] &&
                !visited[next.y][next.x])
            {
                q.push(next);
                visited[next.y][next.x] = true;
                
                
            }
        }
    }
    if(cnt ==1)
        return false;
    else
        return true;
}

void sol()
{
    int town = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Pos start{i, j};
            cout << "(" << i << "," << j << ")" << endl;
            if (bfs(start))
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
