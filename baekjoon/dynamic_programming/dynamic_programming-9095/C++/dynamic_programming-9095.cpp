// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int t;

// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print();

// 가짓수 출력
void sol(int n)
{
    int dp[11] = {0};
    dp[0] = 1; // 귀납적 베이스 정의 dp[1],dp[2],dp[3]을 위해.
    for (int i = 1; i <= n; i++)
    {
        if (i >= 1)
            dp[i] += dp[i - 1]; // 4는 3을 만들 수 있는 경우에 1을 더하면 완성됨 -> 한가지 경우임
        if (i >= 2)
            dp[i] += dp[i - 2]; // 4는 2를 만들 수 있는 경우에 2를 더하면 완성됨
        if (i >= 3)
            dp[i] += dp[i - 3]; // 4는 1을 만들수 있는 경우에 3을 더하면 완성됨.

        // 3개의 경우를 모두 구하면, 4를 만들 수 있는 모든 경우를 구할 수 있음
    }
    cout << dp[n] << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("dynamic_programming-9095_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input()
{
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;

        sol(n);
        t--;
    }
}
void print() {}
