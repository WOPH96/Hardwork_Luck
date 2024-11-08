// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, m, k, x;
vector<int> graph[300001];
priority_queue<int, vector<int>, greater<int>> pq;
bool visited[300001] = {false};
// 다른 변수 생성

// 입력, 테스트 출력

void print();

struct Node
{
    int city, dist;
    Node(int c, int d) : city(c), dist(d) {}
};
void print_answer()
{
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
void sol()
{
    queue<Node> q;
    q.emplace(x, 0);
    visited[x] = true;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.dist == k)
        {
            pq.push(now.city);
        }
        for (int &next : graph[now.city])
        {
            if (!visited[next])
            {
                q.emplace(next, now.dist + 1);
                visited[next] = true;
            }
        }
    }
    if (pq.empty())
        cout << -1 << endl;
    else
        print_answer();
}

void input()
{
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("graph_search-18352_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (auto &elem : graph[i])
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}
