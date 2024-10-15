// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n;
// 다른 변수 생성pes[0]
vector<int> lopes;
// 입력, 테스트 출력

void print();

void sol()
{
    sort(lopes.begin(), lopes.end(), greater<int>());
    int max_weight = -1;
    int cnt = 1;
    for (auto &lope : lopes)
    {
        // cout << max_weight << " " << lope << " " << cnt << endl;
        if (max_weight <= lope * cnt)
        {
            max_weight = lope * cnt;
        }
        cnt++;
        // else
        // {
        //     break;
        // }
    }
    cout << max_weight << endl;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int lope;
        cin >> lope;
        lopes.push_back(lope);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-2217_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &elem : lopes)
    {
        cout << elem << endl;
    }
}
