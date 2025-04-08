// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성

// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(int n)
{
    vector<long long> mem = {0, 1, 1, 1, 2, 2, 3};
    mem.resize(n + 1);

    for (int i = 7; i <= n; i++)
    {
        mem[i] = mem[i - 1] + mem[i - 5];
    }

    cout << mem[n] << "\n";
}

void input()
{
    int t;
    cin >> t;

    while (t)
    {
        int n;
        cin >> n;
        sol(n);
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("dynamic_programming-9461_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    print();

    return 0;
}

void print()
{
}
