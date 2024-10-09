// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// 입력변수생성
int n, m;
int arch[100001];
// 다른 변수 생성
queue<int> q;
// 입력, 테스트 출력

void print();

void sol()
{
    while (m)
    {
        cout << q.front() << " ";
        q.pop();
        m--;
    }
}

void input()
{
    stack<int> temp_qdatas;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arch[i];
    }
    for (int i = 0; i < n; i++)
    {
        int q_data;
        cin >> q_data;
        if (arch[i] == 0)
        {
            temp_qdatas.push(q_data);
        }
    }
    while (!temp_qdatas.empty())
    {
        q.push(temp_qdatas.top());
        temp_qdatas.pop();
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q_data;
        cin >> q_data;
        q.push(q_data);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("queue-24511_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void print()
{
}
