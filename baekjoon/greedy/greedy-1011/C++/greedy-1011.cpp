// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력

void print(ll, ll);

bool is_sqarue_num(ll num)
{
    return (num == pow(static_cast<int>(sqrt(num)), 2));
}
int sol(ll gap)
{
    if (gap == 1)
        return 1;
    else if (gap == 2)
        return 2;

    ll num = 0;
    if (is_sqarue_num(gap))
    {
        /*
        1->1
        2->3
        3->5
        4->7
        time = 2n-1;
        */
        // cout << 2 * static_cast<int>(sqrt(gap)) - 1 << endl;
        return 2 * static_cast<int>(sqrt(gap)) - 1;
    }
    else
    {
        for (num = gap;; num++)
        {
            // 가까운 제곱수 찾기
            if (is_sqarue_num(num))
                break;
        }
        ll mn_val = static_cast<int>(sqrt(num)) - 1;
        ll mx_val = static_cast<int>(sqrt(num));
        ll avg_val = static_cast<int>((pow(mn_val, 2) + pow(mx_val, 2)) / 2);
        if (avg_val > gap)
            return 2 * static_cast<int>(sqrt(mx_val)) - 1;
        else
            return 2 * static_cast<int>(sqrt(mn_val));
    }
    // cout << num << endl;
    return 0;
}

void input()
{
    cin >> t;
    while (t)
    {
        ll start, target;
        cin >> start >> target;

        print(start, target);
        cout << sol(target - start) << endl;
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-1011_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();./

    return 0;
}

void print(ll start, ll target)
{
    cout << start << " " << target << endl;
}
