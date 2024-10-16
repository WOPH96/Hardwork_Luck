// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
unsigned long long a, b, c;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    unsigned long long Res;
    if (c % 2 == 1)
        Res = a ^ b;
    else
        Res = a;
    cout << Res << endl;
}

void input()
{
    cin >> a >> b >> c;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    // freopen("bit_masking-12833_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
