// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;

// 입력변수생성
int n;

// 다른 변수 생성
priority_queue<ll, vector<ll>, greater<ll>> pq;
// 입력, 테스트 출력

void print();

void sol()
{
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll data;
        cin >> data;
        if (data == 0)
        {
            if (pq.empty())
                cout << 0 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(data);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("priority_queue-1927_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void print()
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
