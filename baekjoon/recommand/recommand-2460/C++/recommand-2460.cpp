// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
struct person
{
    int out, in;
    person(int o, int i) : in(i), out(o) {}
};
vector<person> train;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    int person_on_train = 0;
    int mx = -1;
    for (auto &p : train)
    {
        person_on_train -= p.out;
        person_on_train += p.in;
        mx = max(mx, person_on_train);
    }
    cout << mx << endl;
}

void input()
{
    for (int i = 0; i < 10; i++)
    {
        int in, out;
        cin >> in >> out;
        train.emplace_back(in, out);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("recommand-2460_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
