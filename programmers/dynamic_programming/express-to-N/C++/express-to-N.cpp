// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <cstdio>

using namespace std;

// 입력변수생성

// 다른 변수 생성

// 입력, 테스트 출력

void print();

int sol(int n, int number)
{
    int answer = 0;

    vector<set<int>> dp(9);

    int num = 0;
    for (int i = 1; i <= 8; i++)
    {
        num = num * 10 + n;

        dp[i].insert(num);

        // 2일땐 1,1이어함
        // 1일떈 그냥 안해야됨..
        for (int j = 1; j < i; j++)
        {
            for (int a : dp[j])
            {
                for (int b : dp[i - j])
                {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0)
                        dp[i].insert(a / b);
                }
            }
        }
        for (int data : dp[i])
        {
            printf(" %d ", data);
        }
        printf("\n");
        if (dp[i].count(number))
            return i;
    }

    return -1;
}

// void input() {

// }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("express-to-N_input.txt", "r", stdin);
    // 제출 시 주석처리

    // input();
    cout << sol(5, 12);
    print();

    return 0;
}

void print()
{
}
