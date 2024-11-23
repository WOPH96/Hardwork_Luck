// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int price;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    int moneys[] = {500, 100, 50, 10, 5, 1};
    int charge = 1000 - price;
    int cnt = 0;
    int idx = 0;
    /*
    380
    620
    동전 남은금액 동갯
    500 120    1
    100 20     1
    50 20      0
    10  0      2
     */
    while (charge)
    {
        cnt += charge / moneys[idx];
        charge %= moneys[idx];
        idx++;
    }
    cout << cnt << endl;
}

void input()
{
    cin >> price;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("greedy-5585_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
