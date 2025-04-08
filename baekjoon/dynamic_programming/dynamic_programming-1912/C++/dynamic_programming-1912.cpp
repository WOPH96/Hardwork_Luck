// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
// #define NINF ((-1) * (0x7FFF0000))
// 입력변수생성
int n;
// 다른 변수 생성
vector<long long> arr;
// 입력, 테스트 출력

void print();

void sol()
{

    vector<long long> mem(n + 1);
    mem[0] = arr[0];
    long long max_val = mem[0];
    for (int i = 1; i < n; i++)
    {
        mem[i] = max(arr[i], mem[i - 1] + arr[i]);
        max_val = max(max_val, mem[i]);
    }
    cout << max_val << "\n";
    for (auto elem : mem)
    {
        cout << elem << " ";
    }
}

void input()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("dynamic_programming-1912_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
