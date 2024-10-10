// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력변수생성
int n;
vector<int> wait;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    sort(wait.begin(), wait.end());
    int tot_time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            tot_time += wait[j];
            // cout << wait[j] << " ";
        }
        // cout << endl;
    }
    cout << tot_time << endl;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int time;
        cin >> time;
        wait.push_back(time);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-11399_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();

    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &elem : wait)
    {
        cout << elem << " ";
    }
    cout << endl;
}
