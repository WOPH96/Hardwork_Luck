// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int t;

// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(vector<int> &datas)
{
    partial_sort(datas.begin(), datas.begin() + 3, datas.end(), greater<int>());
    // for (auto &elem : datas)
    // {
    //     cout << elem << " " << endl;
    // }
    cout << datas[2] << endl;
}

void input()
{
    cin >> t;
    while (t)
    {
        vector<int> datas;
        for (int i = 0; i < 10; i++)
        {
            int data;
            cin >> data;

            datas.push_back(data);
        }
        sol(datas);
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("recommand-2693_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    print();

    return 0;
}

void print()
{
}
