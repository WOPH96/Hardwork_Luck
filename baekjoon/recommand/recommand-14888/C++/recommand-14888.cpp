// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n;
vector<int> nums;

struct calculator
{
    int plus, minus, mul, div;
};
calculator cal;

// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        nums.push_back(data);
    }

    cin >> cal.plus >> cal.minus >> cal.mul >> cal.div;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("recommand-14888_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
    cout << cal.plus << cal.minus << cal.mul << cal.div;
}
