// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
vector<ll> nums;
vector<pair<int, ll>> comp_nums;
// 입력, 테스트 출력

void print();

void sol()
{
    sort(nums.begin(), nums.end());
    sort(comp_nums.begin(), comp_nums.end(),
         [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        while (comp_nums[i].second >= nums[idx])
        {
            if (comp_nums[i].second == nums[idx])
            {
                cout << 1 << "\n";
                flag = true;
                break;
            }
            else
                idx++;
        }
        if (!flag)
        {
            cout << 0 << "\n";
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll data;
        cin >> data;
        nums.push_back(data);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll data;
        cin >> data;
        comp_nums.push_back({i, data});
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
    for (auto &elem : nums)
    {
        cout << elem << " ";
    }
    cout << "\n";

    for (auto &elem : comp_nums)
    {
        cout << elem.second << " ";
    }
    cout << "\n";
}
