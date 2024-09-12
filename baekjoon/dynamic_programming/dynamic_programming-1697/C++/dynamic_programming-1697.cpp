// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, k;
// 입력변수생성
// int dp[100002];
int visited[100002] = {0};
// 입력, 테스트 출력
void input();
void print(int);

void sol(int second, int idx)
{
    // 종료 조건
    // 100000 넘어갔으면
    if (idx == k)
    {
        cout << second - 1 << endl;
        exit;
    }
    visited[idx] = second;
    //---
    for (int next : {idx - 1, idx + 1, idx * 2})
    {
        if (!visited[next] && 0 <= next && next <= 100000)
        {
            // print(idx);
            sol(second + 1, next);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("dynamic_programming-1697_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol(1, n);
    // cout << visited[k] - 1 << endl;
    // print();
    return 0;
}

void input()
{
    cin >> n >> k;
    // k+1지점 정도까지만..?
    // fill_n(dp, k + 2, 999999);
}
// void print(int idx)
// {
//     for (int i = 0; i <= idx + 1; i++)
//     {
//         cout << "DP[" << i << "] = " << dp[i] << endl;
//     }
//     cout << endl;
// }
