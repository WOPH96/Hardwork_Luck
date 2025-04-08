// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define MOD 10007
// 입력변수생성
int n;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    vector<int> dp(1001, 0);
    // cout << dp[1000] << endl;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    cout << dp[n];
}

void input()
{
    cin >> n;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("dynamic_programming-11726_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
