// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>
#define INF (999999999)
using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
int way[101][101] = {0};
// 입력, 테스트 출력
void print();

void sol()
{
    // 맨위에 k가 오는 것이 중요함..
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                way[i][j] = min(way[i][k] + way[k][j], way[i][j]);
            }
        }
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
        way[from][to] = min(way[from][to], cost);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 제출 시 주석처리
    // freopen("graph_search-11404_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    print();

    return 0;
}

// void print()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (way[i][j] == INF)
//                 cout << "INF ";
//             else
//                 cout << std::setw(3) << way[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (way[i][j] == INF)
                cout << "0 ";
            else
                cout << way[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}