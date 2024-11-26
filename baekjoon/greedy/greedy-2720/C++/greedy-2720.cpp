// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int t;
// 다른 변수 생성

// 입력, 테스트 출력

void print(int *);

void sol(int money)
{
    int coins[] = {25, 10, 5, 1};
    int cnt_of_coins[4] = {0};
    int idx = 0;
    for (auto &coin : coins)
    {
        cnt_of_coins[idx] = money / coin;
        money %= coin;
        idx++;
    }
    print(cnt_of_coins);
}

void input()
{
    cin >> t;
    while (t)
    {
        int money;
        cin >> money;
        sol(money);
        t--;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-2720_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // sol();
    // print();

    return 0;
}

void print(int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
