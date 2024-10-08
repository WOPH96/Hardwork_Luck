// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력변수생성
int n, k;

// 다른 변수 생성
struct Item
{
    int w, v;
    Item(int w, int v) : w(w), v(v) {}
    friend ostream &operator<<(ostream &out, Item &i)
    {
        out << "weight: " << i.w << " value: " << i.v << endl;
        return out;
    }
};
vector<Item> items;

int dp[101] = {0};
// 입력, 테스트 출력

void print();

struct value_high
{
    bool operator()(Item &I1, Item &I2)
    {

        return I1.v > I2.v;
    }
};
struct weight_low
{
    bool operator()(Item &I1, Item &I2)
    {

        return I1.w < I2.w;
    }
};

void sol()
{
    sort(items.begin(), items.end(), value_high());
    print();
    cout << endl;
    sort(items.begin(), items.end(), weight_low());
    print();
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        items.emplace_back(weight, value);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 제출 시 주석처리
    freopen("dynamic_programming-12865_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    // print();
    sol();

    return 0;
}

void print()
{
    for (auto &item : items)
    {
        cout << item << endl;
    }
}
