// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 입력변수생성
int num1, num2;
// 다른 변수 생성

// 입력, 테스트 출력

void print();

void sol()
{
    int mx = max(num1, num2);
    int mn = min(num1, num2);

    while (mx % mn)
    {
        int temp;
        temp = mn;
        mn = mx % mn;
        mx = temp;
    }
    int gcp, lcp;
    gcp = mn;
    lcp = gcp * (num1 / gcp) * (num2 / gcp);

    cout << gcp << "\n"
         << lcp << endl;
}

void input()
{
    cin >> num1 >> num2;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 제출 시 주석처리
    freopen("recommand-2609_input.txt", "r", stdin);
    // 제출 시 주석처리

    input();
    sol();
    print();

    return 0;
}

void print()
{
}
