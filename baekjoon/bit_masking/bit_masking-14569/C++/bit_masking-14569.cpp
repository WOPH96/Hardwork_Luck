// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int n, m;
vector<int> classes[1001];
vector<int> classes_std[10001];
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
}

void input()
{
    int k, p;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int time;
            cin >> time;
            classes[j].push_back(time);
        }
    }
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            int time;
            cin >> time;
            classes[j].push_back(time);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("bit_masking-14569_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (auto &c : classes[i])
        {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (auto &c : classes_std[i])
        {
            cout << c << " ";
        }
        cout << endl;
    }
}
