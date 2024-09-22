// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성
struct Node
{
    int y;
    int x;
    int move;
    Node(int _y, int _x, int _m) : y(_y), x(_x), move(_m) {}
};
// 입력, 테스트 출력
void input();
void print();

// 기사 무빙
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
bool is_vaild(int L, int y, int x)
{
    return (0 <= y && y < L &&
            0 <= x && x < L);
}

void sol(int L, Node &src, Node &dst)
{
    bool visited[301][301] = {false};

    queue<Node> q;
    q.push(src);
    visited[src.y][src.x] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.y == dst.y && now.x == dst.x)
        {
            cout << now.move << endl;
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_vaild(L, ny, nx))
                continue;
            if (!visited[ny][nx])
            {
                q.push(Node(ny, nx, now.move + 1));
                visited[ny][nx] = true;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-7562_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> t;
    while (t)
    {
        int L;
        cin >> L;
        int sy, sx, dy, dx;
        cin >> sy >> sx >> dy >> dx;
        Node src{sy, sx, 0};
        Node dst{dy, dx, 0};
        sol(L, src, dst);
        t--;
    }
}
void print() {}
