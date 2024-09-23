// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
int graph[501][501] = {0};
int dp[501][501] = {0};
// 입력, 테스트 출력
void input();
void print();

void sol()
{
    dp[0][0] = graph[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + graph[i][j]);             // [1][0] = [0][0]+graph[1][0]
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + graph[i][j + 1]); // [1][1] = [0][0]+graph[1][1]
        }
    }
    cout << *max_element(&dp[n - 1][0], &dp[n - 1][0] + n) << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("dynamic_programming-1932_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    // print();

    return 0;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> graph[i][j];
        }
    }
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
