// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int from, to;
// 다른 변수 생성
struct Node
{
    int pos;
    int sec;
    int target;

    Node(int p, int s, int t) : pos(p), sec(s), target(t)
    {
    }
};

// 입력, 테스트 출력

void print();

void sol()
{
    queue<Node> q;
    bool visited[500001] = {false};
    q.emplace(from, 0, to);
    visited[from] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.pos == now.target)
        {
            cout << now.sec << endl;
            return;
        }
        if (now.target > 500000)
        {
            cout << -1 << endl;
            return;
        }
        for (auto &next_pos : {now.pos - 1, now.pos + 1, now.pos * 2})
        {
            if (next_pos < 0 || next_pos > 500000)
                continue;
            // cout << next_pos << endl;
            if (!visited[next_pos])
            {
                q.emplace(next_pos, now.sec + 1, now.target + now.sec + 1);
                cout << now.target << endl;
                visited[next_pos] = true;
            }
        }
    }
}

void input()
{
    cin >> from >> to;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("graph_search-17071_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
}
