// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력변수생성
int start, target;
int visited[100001] = {0};
// 다른 변수 생성
priority_queue<int, vector<int>, greater<int>> pq;
// 입력, 테스트 출력

void print();

void dfs(int now, int second)
{
    if (now < 0 || now > target + 1)
        return;

    if (second >= visited[now])
        return;
    visited[now] = second;
    // cout << now << "," << second << endl;
    if (now == target)
    {
        // cout << second << endl;
        pq.push(second);
        return;
    }

    dfs(now * 2, second);
    dfs(now - 1, second + 1);
    dfs(now + 1, second + 1);
}

void sol()
{
    fill_n(visited, target + 1, 99999);
    dfs(start, 0);
    cout << pq.top() << endl;
}

void input()
{
    cin >> start >> target;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-13549_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
