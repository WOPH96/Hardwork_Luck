// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 입력변수생성
int n, k;
// 다른 변수 생성
stack<int> coins;
// 입력, 테스트 출력

void print();

void sol()
{
    int nums_coin = 0;
    while (k != 0)
    {
        // 최대금액 나올때까지 pop
        while (coins.top() > k)
            coins.pop();
        int cur_coin = k / coins.top();
        k -= coins.top() * cur_coin;
        nums_coin += cur_coin;
        // cout << cur_coin << " " << k << endl;
        // break;
    }
    cout << nums_coin << endl;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int coin;
        cin >> coin;
        coins.push(coin);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("greedy-11047_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
