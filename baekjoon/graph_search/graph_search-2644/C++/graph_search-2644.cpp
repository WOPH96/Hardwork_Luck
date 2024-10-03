// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, p1, p2, relation;
vector<int> graph[101];
bool visited[101] = {false};
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

void dfs(int depth, const int &person, int &result)
{
    if (person == p2)
    {
        result = depth;
        return;
        // return depth;
    }

    for (auto &relative : graph[person])
    {
        if (visited[relative])
            continue;
        visited[relative] = true;
        // cout << relative << " ";
        dfs(depth + 1, relative, result);
    }
}

void sol()
{
    visited[p1] = true;
    int result = -1;
    dfs(0, p1, result);
    cout << result << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-2644_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void input()
{
    cin >> n >> p1 >> p2 >> relation;
    for (int i = 1; i <= relation; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}
void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << "  ";
        for (auto &person : graph[i])
        {
            cout << person << " ";
        }
        cout << endl;
    }
    cout << endl;
}
