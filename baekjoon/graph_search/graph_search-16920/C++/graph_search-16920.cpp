// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m;
int p;
int S[10] = {0};
char graph[1001][1001] = {0};

// 다른 변수 생성
struct Pos
{
    int y, x;
    Pos() : y(0), x(0) {}
    Pos(int y, int x) : y(y), x(x) {}
    friend ostream &operator<<(ostream &out, Pos &p)
    {
        out << p.y << "," << p.x;
        return out;
    }
};

queue<Pos> cattles[10];
// bool visited[1001][1001] = {false};
#define EMPTY '.'
#define WALL '#'

// 입력, 테스트 출력

void print();

bool is_valid(int y, int x)
{
    return (0 <= y && y < n &&
            0 <= x && x < m);
}

void extend_game()
{
    int dy[] = {0, 0, -1, 1};
    int dx[] = {1, -1, 0, 0};
    bool go_flag = true;
    while (go_flag)
    {
        go_flag = false;
        // 1부터 턴제 진행
        for (int i = 1; i <= p; i++)
        {
            // 1부터, 갖고있는 길이확장권만큼 영토확장 진행
            // my code
            // if (cattles[i].empty())
            //     continue;
            // for (int j = 0; j < S[i]; j++)
            // {
            //     if (cattles[i].empty())
            //         break;

            // gpt recommend ==
            int move_limit = S[i];
            int curr_turn = 0;
            while (curr_turn < move_limit && !cattles[i].empty())
            {
                // gpt recommend ==
                int size = cattles[i].size();
                // 모든 성의 위치에서 턴 쓰기
                for (int j = 0; j < size; j++)
                {
                    Pos now = cattles[i].front();
                    cattles[i].pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = now.y + dy[k];
                        int nx = now.x + dx[k];

                        if (!is_valid(ny, nx))
                            continue;
                        if (graph[ny][nx] == EMPTY)
                        {
                            cattles[i].emplace(ny, nx);
                            // 확장하면, 영토에 성 세우기
                            graph[ny][nx] = i + '0';
                            go_flag = true;
                        }
                    }
                }
                // gpt recommend
                curr_turn++;
                // gpt recommend end==
                //  print();
            }
        }
    }
}
void check_result()
{
    int game_result[10] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cattle_info = graph[i][j] - '0';
            if (cattle_info > 0 && cattle_info < 10)
            {
                game_result[cattle_info]++;
            }
        }
    }
    for (int i = 1; i <= p; i++)
    {
        cout << game_result[i] << " ";
    }
    cout << endl;
}
void sol()
{
    extend_game();
    check_result();
}

void input()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            int cattle_idx = graph[i][j] - '0';
            if (cattle_idx > 0 && cattle_idx < 10)
            {
                cattles[cattle_idx].emplace(i, j);
                // visited[i][j] = true;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-16920_input.txt", "r", stdin);
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
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // for (int i = 1; i <= p; i++)
    // {
    //     cout << "Player " << i << " 의 성 위치 : ";
    //     while (!cattles[i].empty())
    //     {

    //         cout << cattles[i].front() << " ";
    //         cattles[i].pop();
    //     }
    //     cout << endl;
    // }
}
