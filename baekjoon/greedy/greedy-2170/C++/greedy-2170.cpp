// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
// 입력변수생성
int n;

// 다른 변수 생성
struct QueuePair
{
    priority_queue<int> max_queue;
    priority_queue<int, vector<int>, greater<int>> min_queue;
};
// 입력, 테스트 출력

void print();

void sol(vector<QueuePair> &pq)
{
    for (auto &elem : pq)
    {
        if (!elem.max_queue.empty())
        {
            cout << elem.max_queue.top() << endl;
            cout << elem.min_queue.top() << endl;
        }
    }
}

void input()
{
    cin >> n;
    vector<QueuePair> pq(n);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int from, to;
        cin >> from >> to;
        if (pq[0].max_queue.empty())
        {
            pq[0].min_queue.push(from);
            pq[0].max_queue.push(to);
        }
        else
        {
            int smallest = pq[idx].min_queue.top();
            int biggest = pq[idx].max_queue.top();
            if ((to <= smallest && smallest <= from) &&
                (to <= biggest && biggest <= from))
            {
                        }
        }
    }
    sol(pq);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-2170_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print()
{
}
