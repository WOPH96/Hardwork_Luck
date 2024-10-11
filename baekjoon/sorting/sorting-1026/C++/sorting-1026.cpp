// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
vector<int> a, b;

// 입력, 테스트 출력

void print();

void sol()
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    cout << sum << endl;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        a.push_back(data);
    }
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        b.push_back(data);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("sorting-1026_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &elem : a)
    {
        cout << elem << " ";
    }
    cout << "\n";
    for (auto &elem : b)
    {
        cout << elem << " ";
    }
    cout << "\n";
}
