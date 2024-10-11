// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 입력변수생성
int n, m;
// 다른 변수 생성
unordered_map<int, int> sang_nums;
vector<int> comp_nums;
// 입력, 테스트 출력

void print();

void sol()
{
    for (auto &num : comp_nums)
    {
        if (sang_nums[num] >= 1)
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        sang_nums[data]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int data;
        cin >> data;
        comp_nums.push_back(data);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-10815_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    print();
    sol();

    return 0;
}

void print()
{
}
