// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#define INF (999999999)

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
int way[101][101] = {0};

struct Node
{
    int to, cost;
    Node(int t, int c) : to(t), cost(c) {}
    bool operator<(const Node &n) const
    {
        return this->cost > n.cost;
    }
};
priority_queue<Node> pq_all_node[101];
// 입력, 테스트 출력
void print();

void djikstra(int from)
{
    priority_queue<Node> &pq = pq_all_node[from];
    while (!pq.empty())
    {
        cout << pq.top().to << "," << pq.top().cost << endl;
        pq.pop();
    }
}
void sol_djikstra()
{
    for (int i = 1; i <= n; i++)
    {
        djikstra(i);
        break;
    }
}
void way_init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                way[i][j] = 0;
            else
                way[i][j] = INF;
        }
    }
}
void input()
{
    cin >> n >> m;

    way_init();
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        // way[from][to] = min(way[from][to], cost);
        pq_all_node[from].push(Node(to, cost));
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 제출 시 주석처리
    freopen("graph_search-11404_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol_djikstra();
    print();

    return 0;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (way[i][j] == INF)
                cout << "INF ";
            else
                cout << std::setw(3) << way[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
    for (int i = 1; i <= n; i++)
    {
        while (!pq_all_node[i].empty())
        {
            cout << pq_all_node[i].top().to << "," << pq_all_node[i].top().cost << endl;
            pq_all_node[i].pop();
        }
        // break;
    }
}

// void print()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (way[i][j] == INF)
//                 cout << "0 ";
//             else
//                 cout << way[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }