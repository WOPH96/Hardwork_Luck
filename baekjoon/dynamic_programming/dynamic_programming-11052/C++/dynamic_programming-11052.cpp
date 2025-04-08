// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
vector<int> arr;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    vector<long long> mem(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            mem[i] = max(mem[i], mem[i - j] + arr[j]);
        }
    }
    // for (auto &elem : mem)
    // {
    //     cout << elem << " ";
    // }
    cout << mem[n];
}

void input()
{
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("dynamic_programming-11052_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
