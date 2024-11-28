// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// 입력변수생성
int from, to;
// 다른 변수 생성
struct Node
{
    int pos;
    int sec;

    Node(int p, int s) : pos(p), sec(s)
    {
    }
};
vector<int> visited(100001, -1);
// 입력, 테스트 출력

void print();

void sol()
{
    queue<Node> q;

    q.emplace(from, 0);
    visited[from] = from;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.pos == to)
        {
            cout << now.sec << endl;
            stack<int> history;
            for (int cur = to; cur != from; cur = visited[cur])
            {
                history.push(cur);
            }
            history.push(from);
            while (!history.empty())
            {
                cout << history.top() << " ";
                history.pop();
            }
            cout << endl;
            return;
        }
        for (auto &next_pos : {now.pos - 1, now.pos + 1, now.pos * 2})
        {
            if (next_pos < 0 || next_pos > max(to, from) + 1)
                continue;
            // cout << next_pos << endl;
            if (visited[next_pos] == -1)
            {
                q.emplace(next_pos, now.sec + 1);
                visited[next_pos] = now.pos;
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
    freopen("graph_search-13913_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 0; i < max(from, to) + 1; i++)
    {
        cout << visited[i] << " ";
    }
    cout << endl;
}
