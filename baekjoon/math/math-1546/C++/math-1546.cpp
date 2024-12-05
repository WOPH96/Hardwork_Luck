// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성
vector<int> datas;
// 입력, 테스트 출력

void print();

void sol()
{
    float avg;
    float sum = 0;
    int MX_val = *max_element(datas.begin(), datas.end());
    for (auto &elem : datas)
    {
        sum += ((float)elem / MX_val * 100);
        // cout << sum << " ";
    }
    avg = sum / n;
    cout << avg << endl;
}

void input()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        datas.push_back(data);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("math-1546_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &elem : datas)
    {
        cout << elem << endl;
    }
}
