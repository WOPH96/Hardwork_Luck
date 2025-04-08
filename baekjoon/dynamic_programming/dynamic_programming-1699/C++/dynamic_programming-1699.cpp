// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include <cmath>

using namespace std;
#define MAX_VAL 0x7FFF0000
// 입력변수생성
int n;

// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    vector<long long> mem(n + 1, MAX_VAL);
    // mem.resize(n + 1);
    // long long temp;
    mem[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            mem[i] = min(mem[i], mem[i - j * j] + 1);
        }
    }
    // cout << pow(static_cast<long long>(sqrt(n)), 2) << endl;

    // for (auto &elem : mem)
    // {
    //     cout << elem << " ";
    // }
    cout << mem[n];
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
    freopen("dynamic_programming-1699_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
