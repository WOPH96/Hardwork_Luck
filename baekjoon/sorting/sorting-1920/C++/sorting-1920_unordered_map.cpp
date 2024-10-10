// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ll long long

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
unordered_map<ll, int> nums;
vector<ll> comp_nums;
// 입력, 테스트 출력

void print();

void sol()
{
    for (auto &elem : comp_nums)
    {
        if (nums[elem] >= 1)
        {
            cout << 1 << "\n";
        }
        else
            cout << 0 << "\n";
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll data;
        cin >> data;
        nums[data]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll data;
        cin >> data;
        comp_nums.push_back(data);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("sorting-1920_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    print();

    return 0;
}

void print()
{
}
