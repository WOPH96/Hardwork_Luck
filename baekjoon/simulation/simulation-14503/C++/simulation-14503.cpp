// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// 입력변수생성
int n, m;
int r, c, d;
int MAP[51][51] = {0};
int debug[51][51] = {0};
// bool cleaned[51][51] = {false};
// 다른 변수 생성
//          북  동 남  서
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

enum DIRECT
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};
enum ROOM
{
    DIRTY,
    WALL,
    CLEANED
};

struct Node
{
    int y;
    int x;
    int d;
    Node(int y, int x, int d) : y(y), x(x), d(d) {}
};

// 입력, 테스트 출력
void input();
void print();
Node go_back(Node &now)
{
    int nd;
    if (now.d % 2 == 0)
        nd = now.d ^ 2;
    else
        nd = now.d ^ 1;
    int ny = now.y + dy[nd];
    int nx = now.x + dx[nd];
    // 후진방향 유지
    return Node(ny, nx, now.d);
}
void sol()
{
    // 시작지점 클리닝
    MAP[r][c] = CLEANED;
    int clean_cnt = 1;

    queue<Node> q;
    q.push(Node(r, c, d));

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        // 4지점 반시계 방향으로 회전, 청소되지 않은 빈칸을 찾을때까지
        bool cleaned_flag = false;
        int turn_cnt = 0;
        while (turn_cnt <= 4)
        {
            // 회전
            turn_cnt++;
            int nd = now.d - turn_cnt;
            if (nd < 0)
                nd = 4 + nd;
            // 회전
            // 이동
            int ny = now.y + dy[nd];
            int nx = now.x + dx[nd];
            // 청소되지 않은 곳인지 확인
            if (MAP[ny][nx] == DIRTY)
            {
                // 다음 방문은 이걸로 한다! (전진,청소, 전진항 방향도 넘김)
                q.push(Node(ny, nx, nd));

                MAP[ny][nx] = CLEANED;

                clean_cnt++;
                // 다음 거로 바로 하도록
                cleaned_flag = true;
                debug[ny][nx] = 1;
                print();
                debug[ny][nx] = 0;
                break;
            }
        }
        // 청소 했으면 2번 하지말고 다시 이동
        if (cleaned_flag)
            continue;

        // 4지점 전부 청소가 된 경우, 후진 좌표 구하기
        Node back_node = go_back(now);
        // 벽이라면 종료
        if (MAP[back_node.y][back_node.x] == WALL)
        {
            break;
        }
        // 벽이 아니라면 후진 가능 (DIRTY건 EMPTY건)
        else
        {
            q.push(back_node);
            debug[back_node.y][back_node.x] = 1;
            print();
            cout << direct[back_node.d] << endl;
            debug[back_node.y][back_node.x] = 0;
            if (MAP[back_node.y][back_node.x] == DIRTY)
            {
                MAP[back_node.y][back_node.x] = CLEANED;

                clean_cnt++;
            }
        }
    }

    cout << clean_cnt << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("simulation-14503_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

void input()
{
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
void print()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << MAP[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < m; j++)
        {
            cout << debug[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
