// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int n, m;
int map[101][101] = {0};

// 입력변수생성
int visited[101][101] = {0};
typedef struct
{
    int y;
    int x;
} pos_t;
void input()
{
    cin >> n >> m;
    cin.ignore(true);
    for (int i = 0; i < n; i++)
    {
        string st;
        getline(cin, st);
        for (int j = 0; j < m; j++)
        {
            map[i][j] = st[j] - '0';
        }
    }
}
void check()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int bfs(pos_t pos)
{
    queue<pos_t> q;
    q.push(pos);
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty())
    {
        // 큐 맨위의 값 꺼내기
        pos_t now = q.front();
        q.pop();

        // 해당 위치를 방문하지 않았다면 진행
        if (!visited[now.y][now.x])
        {
            // 방문 처리
            visited[now.y][now.x] = 1;
            // 4방향으로 탐색
            for (int i = 0; i < 4; i++)
            {
                // y는 n과 대치, x는 m와 대치
                pos_t next_step;
                next_step.x = now.x + dx[i];
                next_step.y = now.y + dy[i];
                // 이동하고자 하는 방향이 맵 내부인가?
                if (0 <= next_step.y && next_step.y < n &&
                    0 <= next_step.x && next_step.x < m)
                {
                    // 이동할 수 있는 칸인가?, map을 수정할 것이기에, 0이 아닌지 체크
                    if (map[next_step.y][next_step.x] != 0)
                    {
                        // 모든 조건 통과, 큐에 삽입
                        q.push(next_step);
                        // 이동 거리
                        check();
                        map[next_step.y][next_step.x] = map[now.y][now.x] + 1;
                    }
                }
            }
        }
    }
    return map[n - 1][m - 1];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("graph_search-2178_input.txt", "r", stdin);

    input();
    // check();
    pos_t start = {0, 0};
    cout << bfs(start);
    return 0;
}
