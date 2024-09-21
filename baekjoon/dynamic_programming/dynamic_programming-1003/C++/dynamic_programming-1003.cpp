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

struct ZO
{
    int zero;
    int one;
    ZO(int z, int o) : zero(z), one(o) {}
    ZO operator+(const ZO &elem)
    {
        return ZO(zero + elem.zero, one + elem.one);
    }

    friend std::ostream &operator<<(std::ostream &out, const ZO &elem)
    {
        out << elem.zero << " " << elem.one;
        return out;
    }
};

void sol(int n)
{
    vector<ZO> dp(n + 1, ZO(0, 0));
    dp[0] = {ZO(1, 0)};
    dp[1] = {ZO(0, 1)};
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    // freopen("dynamic_programming-1003_input.txt", "r", stdin);
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
        // cout << "Hello";
        t--;
    }
}
void print() {}
