// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int cash;
int prices[14];

// 다른 변수 생성
int end_price;
// 입력, 테스트 출력

void print();
int bnp()
{
    int bnp_cash = cash;
    int stocks = 0;

    for (auto &price : prices)
    {
        if (bnp_cash >= price)
        {
            stocks += bnp_cash / price;
            bnp_cash %= price;
        }
        // cout << bnp_cash << " " << stocks << endl;
    }
    // cout << bnp_cash + stocks * end_price << endl;
    return bnp_cash + stocks * end_price;
}
int timing()
{
    int timing_cash = cash;
    int going_up = 0;
    int going_down = 0;
    int stocks = 0;
    for (int i = 1; i < 14; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            going_up++;
            going_down = 0;
        }
        else if (prices[i] < prices[i - 1])
        {
            going_down++;
            going_up = 0;
        }
        else
        {
            going_down = 0;
            going_up = 0;
        }
        if (going_up >= 3)
        {
            // 전량 매도
            timing_cash += stocks * prices[i];
            stocks = 0;
            // going_up = 0;
        }
        else if (going_down >= 3 && timing_cash > prices[i])
        {
            // 전량 매수
            stocks += timing_cash / prices[i];
            timing_cash %= prices[i];
            // going_down = 0;
        }
        // cout << prices[i] << " gd " << going_down << "gu" << going_up << endl;
        // cout << timing_cash << " " << stocks << endl;
    }
    // cout << timing_cash + stocks * end_price << endl;
    return timing_cash + stocks * end_price;
}
void sol()
{
    end_price = prices[13];
    int asset_bnp = bnp();
    int asset_timing = timing();

    if (asset_bnp > asset_timing)
    {
        cout << "BNP" << endl;
    }
    else if (asset_bnp < asset_timing)
    {
        cout << "TIMING" << endl;
    }
    else
    {
        cout << "SAMESAME" << endl;
    }
}

void input()
{
    cin >> cash;
    for (int i = 0; i < 14; i++)
    {
        cin >> prices[i];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("simulation-20546_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    // print();

    return 0;
}

void print()
{
    for (auto &elem : prices)
    {
        cout << elem << endl;
    }
}
