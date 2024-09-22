// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력
void input();
void print(int (*dp)[15], int k, int n);

void sol(int k, int n)
{
    int dp[15][15] = {0};
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    // print(dp, k, n);
    cout << dp[k][n] << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("dynamic_programming-2775_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    // sol();

    return 0;
}

void input()
{
    cin >> t;
    while (t)
    {
        int k, n;
        cin >> k >> n;
        sol(k, n);
        t--;
    }
}
void print(int (*dp)[15], int k, int n)
{
    for (int i = 0; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
