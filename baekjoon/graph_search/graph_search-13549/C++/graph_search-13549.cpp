// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define not_visited 999999
// 입력변수생성
int start, target;
int MX;
int DP[100001] = {0};
// 다른 변수 생성
priority_queue<int, vector<int>, greater<int>> pq;
// 입력, 테스트 출력

void print();

// void dfs(int now, int second)
// {
//     if (now < 0 || now > MX + 1)
//         return;

//     if (DP[now] != 100000)
//     {
//         return;
//     }
//     else
//     {
//         cout << now << " " << second << endl;

//         DP[now] = second;
//         if (now == target)
//         {
//             cout << second << endl;
//             return;
//         }
//         dfs(now * 2, second);
//         dfs(now + 1, second + 1);
//         dfs(now - 1, second + 1);
//         }
// }

void bfs(int start, int second)
{
    struct Node
    {
        int cur, sec;
        Node(int c, int s) : cur(c), sec(s) {}
    };
    queue<Node> q;
    q.emplace(start, second);
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.cur == target)
        {
            cout << now.sec << endl;
            return;
        }
        for (Node next : {
                 Node(now.cur * 2, now.sec),
                 Node(now.cur - 1, now.sec + 1),
                 Node(now.cur + 1, now.sec + 1)})
        {
            if (next.cur < 0 || next.cur > MX + 1)
                continue;
            if (DP[next.cur] != not_visited)
                continue;

            q.push(next);
            DP[next.cur] = second;
        }
    }
}
void sol()
{
    MX = max(start, target);
    fill_n(DP, 100001, not_visited);
    bfs(start, 0);
    // cout << pq.top() << endl;
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
    // freopen("graph_search-13549_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
