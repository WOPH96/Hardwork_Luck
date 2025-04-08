// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;

// 다른 변수 생성

// 입력, 테스트 출력

void print(vector<int> &arr);

void sol(vector<int> &arr)
{
    vector<int> mem(n, 1);
    int MAX_data = -1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                mem[i] = max(mem[i], mem[j] + 1);
                MAX_data = max(mem[i], MAX_data);
            }
        }
    }
    printf("%d", MAX_data);
}

void sol2(vector<int> &arr)
{
    vector<int> LIS;
    // int MAX_data = -1;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(LIS.begin(), LIS.end(), arr[i]); // arr[i]보다 크거나 같은 값 찾기

        // 없으면 내가 제일 큰 값이니 추가하고, 있으면 대치
        if (it == LIS.end())
        {
            LIS.push_back(arr[i]);
        }
        else
        {
            *it = arr[i];
        }
        // print(LIS);
    }
    cout << LIS.size();
}

void input()
{

    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sol2(arr);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("dynamic_programming-11053_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print(vector<int> &arr)
{
    for (auto elem : arr)
        printf("%d ", elem);
    cout << endl;
}
