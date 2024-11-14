// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol(vector<int> &stocks)
{
    // 쌀 대 사서 비쌀 때 팔면 되잖어 ;;
    // 역순으로 고고ㅓ
    int max = -1;
    ll sum = 0;
    // for (auto &elem : stocks)
    // {
    //     cout << elem << " ";
    // }
    // cout << endl;
    for (int i = stocks.size() - 1; i >= 0; i--)
    {

        if (max < stocks[i])
        {
            max = stocks[i];
        }
        else
        {
            sum += max - stocks[i];
        }
        // cout << "sum : " << sum << "\tstocks[i] :" << stocks[i] << "\tMAX : " << max << endl;
    }
    cout << sum << endl;
}

void input()
{
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        vector<int> stocks;
        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            stocks.push_back(data);
        }

        // cout << endl;
        sol(stocks);
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-11501_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print()
{
}
