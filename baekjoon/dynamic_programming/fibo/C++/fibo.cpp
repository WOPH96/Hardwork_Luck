// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성

// 다른 변수 생성
int answer;

// 입력, 테스트 출력
void input();
void print();

int dp[100] = {0};
int sol(int x)
{
    if (x == 0 || x == 1)
    {
        dp[x] = x;
        return x;
    }

    if (dp[x] != 0)
        return dp[x];

    dp[x] = sol(x - 1) + sol(x - 2);
    return dp[x];
}
int main()
{
    answer = sol(99);
    return 0;
}

int dp[100] = {0};
int sol(int x)
{
    dp[0] = 0;
    dp[1]
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("fibo_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    // sol();

    return 0;
}

void input() {}
void print() {}
