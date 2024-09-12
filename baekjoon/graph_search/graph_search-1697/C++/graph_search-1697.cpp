// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 입력변수생성
int n, k;
// 입력변수생성
int visited[100001] = {0};
// 입력, 테스트 출력
void input();
void print();

void sol_bfs()
{

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now == k)
        {
            cout << visited[now] - 1 << endl;
            return;
        }
        // 현재값 -1, 현재값 +1, 현재값 *2 순회
        for (int next : {now - 1, now + 1, now * 2})
        {
            // 제일 처음 방문한 게 최솟값임!
            if (0 <= next && next <= 100000 &&
                !visited[next])
            {
                q.push(next);
                visited[next] = visited[now] + 1;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("graph_search-1697_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol_bfs();

    return 0;
}

void input()
{
    cin >> n >> k;
}
void print() {}
