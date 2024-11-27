// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int k;
int w, h;
// 다른 변수 생성
int graph[201][201] = {0};
bool visited[201][201][31] = {0};

int monkey_dy[] = {0, 0, -1, 1};
int monkey_dx[] = {1, -1, 0, 0};
int horse_dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int horse_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};

enum MAP
{
    ROAD = 0,
    WALL
};

struct Node
{
    int y, x, act, horse;
    Node(int y, int x, int a) : y(y), x(x), act(a), horse(k) {}
Node(int y, int x, int a,int h) : y(y), x(x), act(a), horse(h) {}
};

// 입력, 테스트 출력

void print();
bool is_valid(int y, int x){
    return (y >= 0 && y < h && x >= 0 && x < w);
}
void sol()
{
    queue<Node> q;
    q.emplace(0, 0, 0,k);
    visited[0][0][k] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if(now.y == h - 1 && now.x == w - 1){
            cout << now.act << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + monkey_dy[i];
            int nx = now.x + monkey_dx[i];

            if(!is_valid(ny, nx)) continue;

            if(graph[ny][nx] == ROAD && 
                !visited[ny][nx][now.horse]){
                q.emplace(ny, nx, now.act+1,now.horse);
                visited[ny][nx][now.horse] = true;
            }
            
        }

        if (now.horse > 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int ny = now.y + horse_dy[i];
                int nx = now.x + horse_dx[i];
                if(!is_valid(ny, nx)) continue;
                if(graph[ny][nx] == ROAD &&
                    !visited[ny][nx][now.horse-1]){
                    q.emplace(ny, nx, now.act+1,now.horse-1);
                    visited[ny][nx][now.horse-1] = true;
                    
                }
            }
        }
    }
    cout << -1 << endl;
}

void input()
{
    cin >> k;
    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
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
    freopen("graph_search-1600_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
