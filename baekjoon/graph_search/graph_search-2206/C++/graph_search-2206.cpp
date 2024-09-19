// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
int graph[1001][1001];
// 다른 변수 생성

enum MAP
{
    ROAD,
    WALL
};

struct Node
{
    int y;
    int x;
    int dist;
    bool hammer;
    Node(int y, int x, int dist, int hammer)
        : y(y), x(x), dist(dist), hammer(hammer) {}
};

// 입력, 테스트 출력
void input();
void print();

// void sol(){
// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("graph_search-2206_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();

    // sol();

    return 0;
}

void input()
{
    cin >> n >> m;
    cin.ignore(true);
    for (int i = 0; i < n; i++)
    {
        string st;
        cin >> st;
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = st[j] - '0';
        }
    }
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
}
