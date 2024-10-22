// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
string str;
string p;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    if (str.find(p) == string::npos)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}

void input()
{
    cin >> str;
    cin >> p;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("recommand-16916_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
