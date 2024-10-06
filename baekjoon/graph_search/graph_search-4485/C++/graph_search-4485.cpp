// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define INF (999999999)
using namespace std;

// 입력변수생성
int n;

// 다른 변수 생성
struct Node
{
    int y, x, cost;
    Node(int y, int x, int c) : y(y), x(x), cost(c) {}
};

// 입력, 테스트 출력

void print(int (*ary)[126]);

void print_cost(vector<vector<int>> &cost)
{
    for (auto &row : cost)
    {
        for (auto &elem : row)
            cout << elem << " ";
        cout << endl;
    }
}
bool is_valid(int ny, int nx)
{
    return (0 <= ny && ny < n &&
            0 <= nx && nx < n);
}
void sol(int num, int (*ary)[126])
{
    vector<vector<int>> cost(n, vector<int>(n, INF));
    cost[0][0] = ary[0][0];
    // print_cost(cost);

    queue<Node> q;
    q.push(Node(0, 0, cost[0][0]));

    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if (!is_valid(ny, nx))
                continue;
            int nc = now.cost + ary[ny][nx];
            if (cost[ny][nx] > nc)
            {
                cost[ny][nx] = nc;
                q.push(Node(ny, nx, nc));
            }
        }
    }
    printf("Problem %d: %d\n", num, cost[n - 1][n - 1]);
    // cout << "Problem 1: 20" << endl;
    // print_cost(cost);
}

void input()
{
    int t = 0;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        t++;
        int arr[126][126] = {0};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        // print(arr);
        sol(t, arr);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-4485_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    // sol();

    return 0;
}

void print(int (*ary)[126])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ary[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
