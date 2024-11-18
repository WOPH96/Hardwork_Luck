// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

// 입력변수생성
ll n, try_num;
// 다른 변수 생성
priority_queue<ll, vector<ll>, greater<ll>> pq;
// 입력, 테스트 출력

void print();

void sol()
{
    while (try_num)
    {

        ll min_num1, min_num2;
        min_num1 = pq.top();
        pq.pop();
        min_num2 = pq.top();
        pq.pop();

        for (ll i = 0; i < 2; i++)
        {
            pq.push(min_num1 + min_num2);
        }

        try_num--;
    }
    ll sum = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}

void input()
{
    cin >> n >> try_num;
    for (ll i = 0; i < n; i++)
    {
        ll card;
        cin >> card;
        pq.push(card);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-15903_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    while (!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
