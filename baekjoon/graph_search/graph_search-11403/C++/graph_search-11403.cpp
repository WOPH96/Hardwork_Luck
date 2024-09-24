// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;

vector<int> graph[101];
int result[101][101] = {0};
bool visited[101] = {false};
// 다른 변수 생성
enum MAP
{
    WALL,
    ROAD
};
// 입력, 테스트 출력
void input();
void print();

void dfs(int now)
{
    for (int &next : graph[now])
    {
        if (!visited[next])
        {
            result[now][next] = 1;
            visited[next] = true;
            dfs(next);
            visited[next] = false;
        }
    }
}

void sol()
{
    for (int i = 0; i < n; i++)
    {
        // visited[i] = true;
        dfs(i);
        // visited[i] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-11403_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    print();

    return 0;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int connected;
            cin >> connected;

            if (connected == ROAD)
            {
                // cout << i << j << connected << endl;
                graph[i].push_back(j);
            }
        }
    }
}
void print()
{
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << "  ";
    //     for (int &elem : graph[i])
    //     {
    //         cout << elem << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
