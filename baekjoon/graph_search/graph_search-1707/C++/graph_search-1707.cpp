// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int k;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(int v, int e, vector<int> *graph)
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (auto &elem : graph[i])
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}
void input()
{
    cin >> k;
    while (k)
    {

        int v, e;
        vector<int> graph[20001];

        cin >> v >> e;
        for (int i = 0; i < e; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        sol(v, e, graph);
        cout << endl;
        k--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-1707_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    print();

    return 0;
}

void print()
{
}
