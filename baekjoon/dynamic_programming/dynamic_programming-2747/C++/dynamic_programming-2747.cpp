// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
int dp[46] = {0};
// 입력, 테스트 출력
void input();
void print();

void sol()
{
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            dp[i] = 0;
        }
        else if (i == 1)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
    }
    cout << dp[n];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("dynamic_programming-2747_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void input()
{
    cin >> n;
}
void print() {}
